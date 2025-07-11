/* derivsinline.hxx */
/* Produced with Generato */

#ifndef DERIVSINLINE_HXX
#define DERIVSINLINE_HXX

#include <loop_device.hxx>

#include <array>
#include <cmath>

#include "powerinline.hxx"

namespace CXUtils {
using namespace Loop;

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_1_o2(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  return
    (invDx[D]*(-gf[m1] + gf[p1]))/2.;
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_1_o4(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  return
    (invDx[D]*(-8*gf[m1] + gf[m2] + 8*gf[p1] - gf[p2]))/12.;
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_1_o6(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  return
    (invDx[D]*(-45*gf[m1] + 9*gf[m2] - gf[m3] + 45*gf[p1] - 9*gf[p2] + gf[p3]))/60.;
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_1_o8(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m4 = layout.linear(i + (D == 0 ? -4 : 0), j + (D == 1 ? -4 : 0), k + (D == 2 ? -4 : 0));
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  const int p4 = layout.linear(i + (D == 0 ? 4 : 0), j + (D == 1 ? 4 : 0), k + (D == 2 ? 4 : 0));
  return
    (invDx[D]*(-672*gf[m1] + 168*gf[m2] - 32*gf[m3] + 3*gf[m4] + 672*gf[p1] - 168*gf[p2] + 32*gf[p3] - 3*gf[p4]))/840.;
}

template <int DI, int DJ, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_2_o2(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  if constexpr (DI == DJ) {
  constexpr int D = DI - 1;
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
    return
    Power(invDx[D],2)*(-2*gf[c0] + gf[m1] + gf[p1]);
  } else {
  constexpr int D1 = DI - 1;
  constexpr int D2 = DJ - 1;
  const int m1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -1), j + (D1 != 1 && D2 != 1 ? 0 : -1), k + (D1 != 2 && D2 != 2 ? 0 : -1));
  const int m1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 1)));
  const int p1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -1)));
  const int p1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 1), j + (D1 != 1 && D2 != 1 ? 0 : 1), k + (D1 != 2 && D2 != 2 ? 0 : 1));
    return
    (invDx[D1]*invDx[D2]*(gf[m1m1] - gf[m1p1] - gf[p1m1] + gf[p1p1]))/4.;
  }
}

template <int DI, int DJ, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_2_o4(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  if constexpr (DI == DJ) {
  constexpr int D = DI - 1;
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
    return
    (Power(invDx[D],2)*(-30*gf[c0] + 16*gf[m1] - gf[m2] + 16*gf[p1] - gf[p2]))/12.;
  } else {
  constexpr int D1 = DI - 1;
  constexpr int D2 = DJ - 1;
  const int m2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -2), j + (D1 != 1 && D2 != 1 ? 0 : -2), k + (D1 != 2 && D2 != 2 ? 0 : -2));
  const int m2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -1)));
  const int m2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 1)));
  const int m2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 2)));
  const int m1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -2)));
  const int m1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -1), j + (D1 != 1 && D2 != 1 ? 0 : -1), k + (D1 != 2 && D2 != 2 ? 0 : -1));
  const int m1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 1)));
  const int m1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 2)));
  const int p1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -2)));
  const int p1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -1)));
  const int p1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 1), j + (D1 != 1 && D2 != 1 ? 0 : 1), k + (D1 != 2 && D2 != 2 ? 0 : 1));
  const int p1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 2)));
  const int p2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -2)));
  const int p2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -1)));
  const int p2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 1)));
  const int p2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 2), j + (D1 != 1 && D2 != 1 ? 0 : 2), k + (D1 != 2 && D2 != 2 ? 0 : 2));
    return
    (invDx[D1]*invDx[D2]*(64*gf[m1m1] - 8*gf[m1m2] - 64*gf[m1p1] + 8*gf[m1p2] - 8*gf[m2m1] + gf[m2m2] + 8*gf[m2p1] - gf[m2p2] - 64*gf[p1m1] + 8*gf[p1m2] + 64*gf[p1p1] - 8*gf[p1p2] + 8*gf[p2m1] - gf[p2m2] - 8*gf[p2p1] + gf[p2p2]))/144.;
  }
}

template <int DI, int DJ, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_2_o6(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  if constexpr (DI == DJ) {
  constexpr int D = DI - 1;
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
    return
    (Power(invDx[D],2)*(-490*gf[c0] + 270*gf[m1] - 27*gf[m2] + 2*gf[m3] + 270*gf[p1] - 27*gf[p2] + 2*gf[p3]))/180.;
  } else {
  constexpr int D1 = DI - 1;
  constexpr int D2 = DJ - 1;
  const int m3m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -3), j + (D1 != 1 && D2 != 1 ? 0 : -3), k + (D1 != 2 && D2 != 2 ? 0 : -3));
  const int m3m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : -2)));
  const int m3m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : -1)));
  const int m3p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 1)));
  const int m3p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 2)));
  const int m3p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 3)));
  const int m2m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -3)));
  const int m2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -2), j + (D1 != 1 && D2 != 1 ? 0 : -2), k + (D1 != 2 && D2 != 2 ? 0 : -2));
  const int m2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -1)));
  const int m2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 1)));
  const int m2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 2)));
  const int m2p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 3)));
  const int m1m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -3)));
  const int m1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -2)));
  const int m1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -1), j + (D1 != 1 && D2 != 1 ? 0 : -1), k + (D1 != 2 && D2 != 2 ? 0 : -1));
  const int m1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 1)));
  const int m1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 2)));
  const int m1p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 3)));
  const int p1m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -3)));
  const int p1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -2)));
  const int p1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -1)));
  const int p1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 1), j + (D1 != 1 && D2 != 1 ? 0 : 1), k + (D1 != 2 && D2 != 2 ? 0 : 1));
  const int p1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 2)));
  const int p1p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 3)));
  const int p2m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -3)));
  const int p2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -2)));
  const int p2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -1)));
  const int p2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 1)));
  const int p2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 2), j + (D1 != 1 && D2 != 1 ? 0 : 2), k + (D1 != 2 && D2 != 2 ? 0 : 2));
  const int p2p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 3)));
  const int p3m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -3)));
  const int p3m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -2)));
  const int p3m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -1)));
  const int p3p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : 1)));
  const int p3p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : 2)));
  const int p3p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 3), j + (D1 != 1 && D2 != 1 ? 0 : 3), k + (D1 != 2 && D2 != 2 ? 0 : 3));
    return
    (invDx[D1]*invDx[D2]*(2025*gf[m1m1] - 405*gf[m1m2] + 45*gf[m1m3] - 2025*gf[m1p1] + 405*gf[m1p2] - 45*gf[m1p3] - 405*gf[m2m1] + 81*gf[m2m2] - 9*gf[m2m3] + 405*gf[m2p1] - 81*gf[m2p2] + 9*gf[m2p3] + 45*gf[m3m1] - 9*gf[m3m2] + gf[m3m3] - 45*gf[m3p1] + 9*gf[m3p2] - gf[m3p3] - 2025*gf[p1m1] + 405*gf[p1m2] - 45*gf[p1m3] + 2025*gf[p1p1] - 405*gf[p1p2] + 45*gf[p1p3] + 405*gf[p2m1] - 81*gf[p2m2] + 9*gf[p2m3] - 405*gf[p2p1] + 81*gf[p2p2] - 9*gf[p2p3] - 45*gf[p3m1] + 9*gf[p3m2] - gf[p3m3] + 45*gf[p3p1] - 9*gf[p3p2] + gf[p3p3]))/3600.;
  }
}

template <int DI, int DJ, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
fd_2_o8(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  if constexpr (DI == DJ) {
  constexpr int D = DI - 1;
  const int m4 = layout.linear(i + (D == 0 ? -4 : 0), j + (D == 1 ? -4 : 0), k + (D == 2 ? -4 : 0));
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  const int p4 = layout.linear(i + (D == 0 ? 4 : 0), j + (D == 1 ? 4 : 0), k + (D == 2 ? 4 : 0));
    return
    (Power(invDx[D],2)*(-14350*gf[c0] + 8064*gf[m1] - 1008*gf[m2] + 128*gf[m3] - 9*gf[m4] + 8064*gf[p1] - 1008*gf[p2] + 128*gf[p3] - 9*gf[p4]))/5040.;
  } else {
  constexpr int D1 = DI - 1;
  constexpr int D2 = DJ - 1;
  const int m4m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -4), j + (D1 != 1 && D2 != 1 ? 0 : -4), k + (D1 != 2 && D2 != 2 ? 0 : -4));
  const int m4m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : -3)));
  const int m4m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : -2)));
  const int m4m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : -1)));
  const int m4p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : 1)));
  const int m4p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : 2)));
  const int m4p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : 3)));
  const int m4p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -4 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -4 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -4 : 4)));
  const int m3m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : -4)));
  const int m3m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -3), j + (D1 != 1 && D2 != 1 ? 0 : -3), k + (D1 != 2 && D2 != 2 ? 0 : -3));
  const int m3m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : -2)));
  const int m3m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : -1)));
  const int m3p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 1)));
  const int m3p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 2)));
  const int m3p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 3)));
  const int m3p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -3 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -3 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -3 : 4)));
  const int m2m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -4)));
  const int m2m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -3)));
  const int m2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -2), j + (D1 != 1 && D2 != 1 ? 0 : -2), k + (D1 != 2 && D2 != 2 ? 0 : -2));
  const int m2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : -1)));
  const int m2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 1)));
  const int m2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 2)));
  const int m2p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 3)));
  const int m2p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -2 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -2 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -2 : 4)));
  const int m1m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -4)));
  const int m1m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -3)));
  const int m1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : -2)));
  const int m1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : -1), j + (D1 != 1 && D2 != 1 ? 0 : -1), k + (D1 != 2 && D2 != 2 ? 0 : -1));
  const int m1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 1)));
  const int m1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 2)));
  const int m1p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 3)));
  const int m1p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? -1 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? -1 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? -1 : 4)));
  const int p1m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -4)));
  const int p1m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -3)));
  const int p1m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -2)));
  const int p1m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : -1)));
  const int p1p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 1), j + (D1 != 1 && D2 != 1 ? 0 : 1), k + (D1 != 2 && D2 != 2 ? 0 : 1));
  const int p1p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 2)));
  const int p1p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 3)));
  const int p1p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 1 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 1 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 1 : 4)));
  const int p2m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -4)));
  const int p2m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -3)));
  const int p2m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -2)));
  const int p2m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : -1)));
  const int p2p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 1)));
  const int p2p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 2), j + (D1 != 1 && D2 != 1 ? 0 : 2), k + (D1 != 2 && D2 != 2 ? 0 : 2));
  const int p2p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 3)));
  const int p2p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 2 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 2 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 2 : 4)));
  const int p3m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -4)));
  const int p3m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -3)));
  const int p3m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -2)));
  const int p3m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : -1)));
  const int p3p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : 1)));
  const int p3p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : 2)));
  const int p3p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 3), j + (D1 != 1 && D2 != 1 ? 0 : 3), k + (D1 != 2 && D2 != 2 ? 0 : 3));
  const int p3p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 3 : 4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 3 : 4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 3 : 4)));
  const int p4m4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : -4)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : -4)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : -4)));
  const int p4m3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : -3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : -3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : -3)));
  const int p4m2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : -2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : -2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : -2)));
  const int p4m1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : -1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : -1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : -1)));
  const int p4p1 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : 1)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : 1)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : 1)));
  const int p4p2 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : 2)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : 2)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : 2)));
  const int p4p3 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : (D1 == 0 ? 4 : 3)), j + (D1 != 1 && D2 != 1 ? 0 : (D1 == 1 ? 4 : 3)), k + (D1 != 2 && D2 != 2 ? 0 : (D1 == 2 ? 4 : 3)));
  const int p4p4 = layout.linear(i + (D1 != 0 && D2 != 0 ? 0 : 4), j + (D1 != 1 && D2 != 1 ? 0 : 4), k + (D1 != 2 && D2 != 2 ? 0 : 4));
    return
    (invDx[D1]*invDx[D2]*(451584*gf[m1m1] - 112896*gf[m1m2] + 21504*gf[m1m3] - 2016*gf[m1m4] - 451584*gf[m1p1] + 112896*gf[m1p2] - 21504*gf[m1p3] + 2016*gf[m1p4] - 112896*gf[m2m1] + 28224*gf[m2m2] - 5376*gf[m2m3] + 504*gf[m2m4] + 112896*gf[m2p1] - 28224*gf[m2p2] + 5376*gf[m2p3] - 504*gf[m2p4] + 21504*gf[m3m1] - 5376*gf[m3m2] + 1024*gf[m3m3] - 96*gf[m3m4] - 21504*gf[m3p1] + 5376*gf[m3p2] - 1024*gf[m3p3] + 96*gf[m3p4] - 2016*gf[m4m1] + 504*gf[m4m2] - 96*gf[m4m3] + 9*gf[m4m4] + 2016*gf[m4p1] - 504*gf[m4p2] + 96*gf[m4p3] - 9*gf[m4p4] - 451584*gf[p1m1] + 112896*gf[p1m2] - 21504*gf[p1m3] + 2016*gf[p1m4] + 451584*gf[p1p1] - 112896*gf[p1p2] + 21504*gf[p1p3] - 2016*gf[p1p4] + 112896*gf[p2m1] - 28224*gf[p2m2] + 5376*gf[p2m3] - 504*gf[p2m4] - 112896*gf[p2p1] + 28224*gf[p2p2] - 5376*gf[p2p3] + 504*gf[p2p4] - 21504*gf[p3m1] + 5376*gf[p3m2] - 1024*gf[p3m3] + 96*gf[p3m4] + 21504*gf[p3p1] - 5376*gf[p3p2] + 1024*gf[p3p3] - 96*gf[p3p4] + 2016*gf[p4m1] - 504*gf[p4m2] + 96*gf[p4m3] - 9*gf[p4m4] - 2016*gf[p4p1] + 504*gf[p4p2] - 96*gf[p4p3] + 9*gf[p4p4]))/705600.;
  }
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
diss_4_o4(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  return
    invDx[D]*(6*gf[c0] - 4*gf[m1] + gf[m2] - 4*gf[p1] + gf[p2]);
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
diss_6_o6(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  return
    invDx[D]*(-20*gf[c0] + 15*gf[m1] - 6*gf[m2] + gf[m3] + 15*gf[p1] - 6*gf[p2] + gf[p3]);
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
diss_8_o8(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m4 = layout.linear(i + (D == 0 ? -4 : 0), j + (D == 1 ? -4 : 0), k + (D == 2 ? -4 : 0));
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  const int p4 = layout.linear(i + (D == 0 ? 4 : 0), j + (D == 1 ? 4 : 0), k + (D == 2 ? 4 : 0));
  return
    invDx[D]*(70*gf[c0] - 56*gf[m1] + 28*gf[m2] - 8*gf[m3] + gf[m4] - 56*gf[p1] + 28*gf[p2] - 8*gf[p3] + gf[p4]);
}

template <int DI, typename T>
CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T
diss_10_o10(const GF3D2layout &layout, const T *gf, int i, int j, int k, const std::array<T, 3> &invDx) {
  constexpr int D = DI - 1;
  const int m5 = layout.linear(i + (D == 0 ? -5 : 0), j + (D == 1 ? -5 : 0), k + (D == 2 ? -5 : 0));
  const int m4 = layout.linear(i + (D == 0 ? -4 : 0), j + (D == 1 ? -4 : 0), k + (D == 2 ? -4 : 0));
  const int m3 = layout.linear(i + (D == 0 ? -3 : 0), j + (D == 1 ? -3 : 0), k + (D == 2 ? -3 : 0));
  const int m2 = layout.linear(i + (D == 0 ? -2 : 0), j + (D == 1 ? -2 : 0), k + (D == 2 ? -2 : 0));
  const int m1 = layout.linear(i + (D == 0 ? -1 : 0), j + (D == 1 ? -1 : 0), k + (D == 2 ? -1 : 0));
  const int c0 = layout.linear(i, j, k);
  const int p1 = layout.linear(i + (D == 0 ? 1 : 0), j + (D == 1 ? 1 : 0), k + (D == 2 ? 1 : 0));
  const int p2 = layout.linear(i + (D == 0 ? 2 : 0), j + (D == 1 ? 2 : 0), k + (D == 2 ? 2 : 0));
  const int p3 = layout.linear(i + (D == 0 ? 3 : 0), j + (D == 1 ? 3 : 0), k + (D == 2 ? 3 : 0));
  const int p4 = layout.linear(i + (D == 0 ? 4 : 0), j + (D == 1 ? 4 : 0), k + (D == 2 ? 4 : 0));
  const int p5 = layout.linear(i + (D == 0 ? 5 : 0), j + (D == 1 ? 5 : 0), k + (D == 2 ? 5 : 0));
  return
    invDx[D]*(-252*gf[c0] + 210*gf[m1] - 120*gf[m2] + 45*gf[m3] - 10*gf[m4] + gf[m5] + 210*gf[p1] - 120*gf[p2] + 45*gf[p3] - 10*gf[p4] + gf[p5]);
}

} // namespace CXUtils

#endif // #ifndef DERIVSINLINE_HXX

/* derivsinline.hxx */
