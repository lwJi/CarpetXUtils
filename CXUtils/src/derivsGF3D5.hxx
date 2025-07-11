/* derivsGF3D5.hxx */
/* Produced with Generato */

#ifndef DERIVSGF3D5_HXX
#define DERIVSGF3D5_HXX

#include <loop_device.hxx>

#include <array>
#include <cmath>

#include "derivsinline.hxx"

namespace CXUtils {
using namespace Loop;
using namespace std;

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs1st(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<GF3D5<T>, 3> &dgf,
               const GF3D2layout &layout2,
               const T *gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  switch (deriv_order) {
  case 2: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o2<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o2<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o2<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 4: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o4<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o4<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o4<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 6: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o6<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o6<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o6<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 8: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o8<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o8<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o8<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
default:
  assert(0);
}
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs1st(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<array<GF3D5<T>, 3>, 3> &dgf,
               const GF3D2layout &layout2,
               const array<const T *, 3> &gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  for (int a = 0; a < 3; ++a)
    calc_derivs1st<CI, CJ, CK>(grid, layout5, dgf[a], layout2, gf_[a],
                               invDxyz, deriv_order);
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs1st(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<array<GF3D5<T>, 3>, 6> &dgf,
               const GF3D2layout &layout2,
               const array<const T *, 6> &gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  for (int a = 0; a < 6; ++a)
    calc_derivs1st<CI, CJ, CK>(grid, layout5, dgf[a], layout2, gf_[a],
                               invDxyz, deriv_order);
}


template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs2nd(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<GF3D5<T>, 3> &dgf,
               const array<GF3D5<T>, 6> &ddgf,
               const GF3D2layout &layout2,
               const T *gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  switch (deriv_order) {
  case 2: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o2<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o2<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o2<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[0].ptr[ijk5] = fd_2_o2<1, 1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[1].ptr[ijk5] = fd_2_o2<1, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[2].ptr[ijk5] = fd_2_o2<1, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[3].ptr[ijk5] = fd_2_o2<2, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[4].ptr[ijk5] = fd_2_o2<2, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[5].ptr[ijk5] = fd_2_o2<3, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 4: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o4<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o4<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o4<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[0].ptr[ijk5] = fd_2_o4<1, 1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[1].ptr[ijk5] = fd_2_o4<1, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[2].ptr[ijk5] = fd_2_o4<1, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[3].ptr[ijk5] = fd_2_o4<2, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[4].ptr[ijk5] = fd_2_o4<2, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[5].ptr[ijk5] = fd_2_o4<3, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 6: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o6<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o6<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o6<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[0].ptr[ijk5] = fd_2_o6<1, 1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[1].ptr[ijk5] = fd_2_o6<1, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[2].ptr[ijk5] = fd_2_o6<1, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[3].ptr[ijk5] = fd_2_o6<2, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[4].ptr[ijk5] = fd_2_o6<2, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[5].ptr[ijk5] = fd_2_o6<3, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
  case 8: {
    grid.loop_int_device<CI, CJ, CK>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const int ijk5 = layout5.linear(p.i, p.j, p.k);
        dgf[0].ptr[ijk5] = fd_1_o8<1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[1].ptr[ijk5] = fd_1_o8<2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        dgf[2].ptr[ijk5] = fd_1_o8<3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[0].ptr[ijk5] = fd_2_o8<1, 1>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[1].ptr[ijk5] = fd_2_o8<1, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[2].ptr[ijk5] = fd_2_o8<1, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[3].ptr[ijk5] = fd_2_o8<2, 2>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[4].ptr[ijk5] = fd_2_o8<2, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
        ddgf[5].ptr[ijk5] = fd_2_o8<3, 3>(layout2, gf_, p.i, p.j, p.k, invDxyz);
      });
    break;
  }
default:
  assert(0);
}
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs2nd(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<array<GF3D5<T>, 3>, 3> &dgf,
               const array<array<GF3D5<T>, 6>, 3> &ddgf,
               const GF3D2layout &layout2,
               const array<const T *, 3> &gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  for (int a = 0; a < 3; ++a)
    calc_derivs2nd<CI, CJ, CK>(grid, layout5, dgf[a], ddgf[a],
                               layout2, gf_[a], invDxyz, deriv_order);
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_derivs2nd(const GridDescBaseDevice &grid,
               const GF3D5layout &layout5,
               const array<array<GF3D5<T>, 3>, 6> &dgf,
               const array<array<GF3D5<T>, 6>, 6> &ddgf,
               const GF3D2layout &layout2,
               const array<const T *, 6> &gf_,
               const array<T, 3> &invDxyz,
               const int deriv_order) {
  for (int a = 0; a < 6; ++a)
    calc_derivs2nd<CI, CJ, CK>(grid, layout5, dgf[a], ddgf[a],
                               layout2, gf_[a], invDxyz, deriv_order);
}


template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_copy(const GridDescBaseDevice &grid,
          const GF3D5layout &layout5,
          const GF3D5<T> &gf,
          const GF3D2layout &layout2,
          const T *gf_) {
  grid.loop_int_device<CI, CJ, CK>(
    grid.nghostzones,
    [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
      const int ijk2 = layout2.linear(p.i, p.j, p.k);
      const int ijk5 = layout5.linear(p.i, p.j, p.k);
      gf.ptr[ijk5] = gf_[ijk2];
    });
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_copy(const GridDescBaseDevice &grid,
          const GF3D5layout &layout5,
          const array<GF3D5<T>, 3> &gf,
          const GF3D2layout &layout2,
          const array<const T *, 3> &gf_) {
  for (int a = 0; a < 3; ++a)
    calc_copy<CI, CJ, CK>(grid, layout5, gf[a], layout2, gf_[a]);
}

template <int CI, int CJ, int CK, typename T>
CCTK_ATTRIBUTE_NOINLINE void
calc_copy(const GridDescBaseDevice &grid,
          const GF3D5layout &layout5,
          const array<GF3D5<T>, 6> &gf,
          const GF3D2layout &layout2,
          const array<const T *, 6> &gf_) {
  for (int a = 0; a < 6; ++a)
    calc_copy<CI, CJ, CK>(grid, layout5, gf[a], layout2, gf_[a]);
}


} // namespace CXUtils

#endif // #ifndef DERIVSGF3D5_HXX

/* derivsGF3D5.hxx */
