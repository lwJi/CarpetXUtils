#include <loop_device.hxx>

#include <defs.hxx>

#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>

#include <cx_derivsGF3D5.hxx>
#include <cx_dissinline.hxx>
#include <cx_powerinline.hxx>
#include <cx_utils.hxx>

namespace TestCXUtils {
using namespace Loop;
using namespace CXUtils;

template <typename T>
constexpr T poly(const T kxx, const T kxy, const T kxz, const T kyy,
                 const T kyz, const T kzz, const T x, const T y, const T z) {
  const T cosx = cos(x);
  const T siny = sin(y);
  const T sinz = sin(z);
  return kxx * cosx * cosx + kxy * cosx * siny + kxz * cosx * sinz +
         kyy * siny * siny + kyz * siny * sinz + kzz * sinz * sinz;
}

template <typename T>
constexpr void poly_derivs(const T kxx, const T kxy, const T kxz, const T kyy,
                           const T kyz, const T kzz, const T x, const T y,
                           const T z, std::array<T, 3> &du,
                           std::array<T, 6> &ddu) {
  using std::sin, std::cos, std::sqrt;
  const T sinx = sin(x);
  const T siny = sin(y);
  const T sinz = sin(z);
  const T cosx = cos(x);
  const T cosy = cos(y);
  const T cosz = cos(z);
  du[0] = -2 * kxx * cosx * sinx - kxy * sinx * siny - kxz * sinx * sinz;
  du[1] = kxy * cosx * cosy + 2 * kyy * cosy * siny + kyz * cosy * sinz;
  du[2] = kxz * cosx * cosz + kyz * cosz * siny + 2 * kzz * cosz * sinz;
  ddu[0] = -2 * kxx * cosx * cosx + 2 * kxx * sinx * sinx - kxy * cosx * siny -
           kxz * cosx * sinz;
  ddu[1] = -kxy * cosy * sinx;
  ddu[2] = -kxz * cosz * sinx;
  ddu[3] = -kxy * cosx * siny + 2 * kyy * (cosy * cosy - siny * siny) -
           kyz * siny * sinz;
  ddu[4] = kyz * cosy * cosz;
  ddu[5] = -kxz * cosx * sinz - kyz * siny * sinz +
           2 * kzz * (cosz * cosz - sinz * sinz);
}

template <typename T>
constexpr T poly_diss(const T kxx, const T kxy, const T kxz, const T kyy,
                      const T kyz, const T kzz, const T x, const T y, const T z,
                      const int diss_order, const Arith::vect<T, dim> &dx) {
  using std::sin, std::cos, std::fabs;
  const T sinx = sin(x);
  const T siny = sin(y);
  const T sinz = sin(z);
  const T cosx = cos(x);
  const T cosy = cos(y);
  const T cosz = cos(z);
  int coeff = 0;

  switch (diss_order) {
  case 4:
    coeff = 8;
    break;
  case 6:
    coeff = -32;
    break;
  case 8:
    coeff = 128;
    break;
  case 10:
    coeff = -512;
    break;
  default:
    assert(0);
  }

  const int abc = fabs(coeff);
  const int sig = (abc == coeff) ? 1 : -1;
  return sig * ((abc * kxx * (cosx * cosx - sinx * sinx) + kxy * cosx * siny +
                 kxz * cosx * sinz) /
                    dx[0] +
                (-abc * kyy * (cosy * cosy - siny * siny) + kxy * cosx * siny +
                 kyz * siny * sinz) /
                    dx[1] +
                (-abc * kzz * (cosz * cosz - sinz * sinz) + kxz * cosx * sinz +
                 kyz * siny * sinz) /
                    dx[2]);
}

extern "C" void TestCXUtils_SetError(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_TestCXUtils_SetError;
  DECLARE_CCTK_PARAMETERS;

  loop_int<1, 1, 1>(cctkGH, [&](const PointDesc &p) {
    if (fabs(p.x) <= refined_radius && fabs(p.y) <= refined_radius &&
        fabs(p.z) <= refined_radius) {
      regrid_error(p.I) = 1;
    } else {
      regrid_error(p.I) = 0;
    }
  });
}

extern "C" void TestCXUtils_Set(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_TestCXUtils_Set;
  DECLARE_CCTK_PARAMETERS;

  using std::sin, std::cos;
  grid.loop_int_device<0, 0, 0>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const auto x0 = p.x + 0.1;
        const auto y0 = p.y + 0.1;
        const auto z0 = p.z + 0.1;
        chi(p.I) = poly(kxx, kxy, kxz, kyy, kyz, kzz, x0, y0, z0);
      });
}

extern "C" void TestCXUtils_Sync(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_TestCXUtils_Sync;
  // do nothing
}

extern "C" void TestCXUtils_CalcDerivs(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTS_TestCXUtils_CalcDerivs;
  DECLARE_CCTK_PARAMETERS;

  for (int d = 0; d < 3; ++d)
    if (cctk_nghostzones[d] < deriv_order / 2)
      CCTK_VERROR("Need at least %d ghost zones", deriv_order / 2);

  const array<CCTK_REAL, 3> invDxyz{1. / CCTK_DELTA_SPACE(0),
                                    1. / CCTK_DELTA_SPACE(1),
                                    1. / CCTK_DELTA_SPACE(2)};

  const GF3D2layout layout2(cctkGH, {0, 0, 0});

  const CCTK_REAL *gf_chi = chi;

  /* Define temp tail vars */
  constexpr int nvars = 9;
  int ivar = 0;
  const GF3D5layout layout5 = get_GF3D5layout<0, 0, 0>(cctkGH);
  GF3D5Factory<CCTK_REAL> fct(layout5, nvars, ivar);
  const auto tl_dchi = fct.make_vec_gf();
  const auto tl_ddchi = fct.make_smat_gf();
  if (ivar != nvars)
    CCTK_VERROR("Wrong number of temporary variables: nvars=%d ivar=%d", nvars,
                ivar);
  ivar = -1;

  const GridDescBaseDevice grid(cctkGH);

  // Define derivs lambdas
  const auto calcderivs2nd = [&](const auto &dgf, const auto &ddgf,
                                 const auto &gf_) {
    calc_derivs2nd<0, 0, 0>(grid, layout5, dgf, ddgf, layout2, gf_, invDxyz,
                            deriv_order);
  };

  calcderivs2nd(tl_dchi, tl_ddchi, gf_chi);

  grid.loop_int_device<0, 0, 0>(
      grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {
        const int ijk = layout2.linear(p.i, p.j, p.k);
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dxchi[ijk] = tl_dchi[0].ptr[ijk5];
        dychi[ijk] = tl_dchi[1].ptr[ijk5];
        dzchi[ijk] = tl_dchi[2].ptr[ijk5];
        dxxchi[ijk] = tl_ddchi[0].ptr[ijk5];
        dxychi[ijk] = tl_ddchi[1].ptr[ijk5];
        dxzchi[ijk] = tl_ddchi[2].ptr[ijk5];
        dyychi[ijk] = tl_ddchi[3].ptr[ijk5];
        dyzchi[ijk] = tl_ddchi[4].ptr[ijk5];
        dzzchi[ijk] = tl_ddchi[5].ptr[ijk5];
      });
}

extern "C" void TestCXUtils_CalcDiss(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTS_TestCXUtils_CalcDiss;
  DECLARE_CCTK_PARAMETERS;

  for (int d = 0; d < 3; ++d)
    if (cctk_nghostzones[d] < deriv_order / 2)
      CCTK_VERROR("Need at least %d ghost zones", deriv_order / 2);

  const array<CCTK_REAL, 3> invDxyz{1. / CCTK_DELTA_SPACE(0),
                                    1. / CCTK_DELTA_SPACE(1),
                                    1. / CCTK_DELTA_SPACE(2)};

  const GF3D2layout layout2(cctkGH, {0, 0, 0});

  const GridDescBaseDevice grid(cctkGH);

  const int diss_order = deriv_order + 2;

  const auto calcdiss = [&](const CCTK_REAL *gf_, CCTK_REAL *gf_rhs_) {
    switch (diss_order) {
    case 4: {
      grid.loop_int_device<0, 0, 0>(
          grid.nghostzones,
          [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
            const int ijk = layout2.linear(p.i, p.j, p.k);
            gf_rhs_[ijk] = calc_diss<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
          });
      break;
    }
    case 6: {
      grid.loop_int_device<0, 0, 0>(
          grid.nghostzones,
          [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
            const int ijk = layout2.linear(p.i, p.j, p.k);
            gf_rhs_[ijk] = calc_diss<4>(layout2, gf_, p.i, p.j, p.k, invDxyz);
          });
      break;
    }
    case 8: {
      grid.loop_int_device<0, 0, 0>(
          grid.nghostzones,
          [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
            const int ijk = layout2.linear(p.i, p.j, p.k);
            gf_rhs_[ijk] = calc_diss<6>(layout2, gf_, p.i, p.j, p.k, invDxyz);
          });
      break;
    }
    case 10: {
      grid.loop_int_device<0, 0, 0>(
          grid.nghostzones,
          [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
            const int ijk = layout2.linear(p.i, p.j, p.k);
            gf_rhs_[ijk] = calc_diss<8>(layout2, gf_, p.i, p.j, p.k, invDxyz);
          });
      break;
    }
    default:
      assert(0);
    }
  };

  calcdiss(chi, chi_diss);
}

extern "C" void TestCXUtils_CalcError(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_TestCXUtils_CalcError;
  DECLARE_CCTK_PARAMETERS;

  const Arith::vect<CCTK_REAL, dim> dx(std::array<CCTK_REAL, dim>{
      CCTK_DELTA_SPACE(0),
      CCTK_DELTA_SPACE(1),
      CCTK_DELTA_SPACE(2),
  });

  grid.loop_int_device<0, 0, 0>(
      grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {
        const auto x0 = p.x + 0.1;
        const auto y0 = p.y + 0.1;
        const auto z0 = p.z + 0.1;

        // errors in derivs
        std::array<CCTK_REAL, 3> dchi;
        std::array<CCTK_REAL, 6> ddchi;
        poly_derivs(kxx, kxy, kxz, kyy, kyz, kzz, x0, y0, z0, dchi, ddchi);

        dxchi_error(p.I) = dxchi(p.I) - dchi[0];
        dychi_error(p.I) = dychi(p.I) - dchi[1];
        dzchi_error(p.I) = dzchi(p.I) - dchi[2];
        dxxchi_error(p.I) = dxxchi(p.I) - ddchi[0];
        dxychi_error(p.I) = dxychi(p.I) - ddchi[1];
        dxzchi_error(p.I) = dxzchi(p.I) - ddchi[2];
        dyychi_error(p.I) = dyychi(p.I) - ddchi[3];
        dyzchi_error(p.I) = dyzchi(p.I) - ddchi[4];
        dzzchi_error(p.I) = dzzchi(p.I) - ddchi[5];

        // errors in diss
        const int diss_order = deriv_order + 2;
        const CCTK_REAL diss =
            Power(-1, diss_order / 2 - 1) / Power(2, diss_order) *
            poly_diss(kxx, kxy, kxz, kyy, kyz, kzz, x0, y0, z0, diss_order, dx);
        chi_diss_error(p.I) = diss - chi_diss(p.I);
      });
}

} // namespace TestCXUtils
