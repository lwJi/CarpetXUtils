#ifndef CXUTILS_UTILS_HXX
#define CXUTILS_UTILS_HXX

#include <functional>
#include <loop_device.hxx>

namespace CXUtils {

//// Generic utility to create std::array with a callable (C++20 compatible)
// template <typename T, size_t N, typename F>
// constexpr std::array<T, N> make_array(F &&lambda) {
//   static_assert(N <= 1024, "Array size too large for practical use");
//
//   auto expand = [&lambda]<size_t... Is>(std::index_sequence<Is...>) noexcept(
//                     noexcept(std::array<T, N>{lambda(Is)...})) {
//     return std::array<T, N>{lambda(Is)...};
//   };
//
//   return expand(std::make_index_sequence<N>{});
// }

// Generic utility to create std::array with a callable (C++17 compatible)
template <typename T, size_t N, typename F, size_t... Is>
constexpr std::array<T, N>
make_array_impl(F &&lambda, std::index_sequence<Is...>) noexcept(
    noexcept(std::array<T, N>{{lambda(Is)...}})) {
  return {{lambda(Is)...}};
}

template <typename T, size_t N, typename F>
constexpr std::array<T, N> make_array(F &&lambda) noexcept(
    noexcept(make_array_impl<T, N>(lambda, std::make_index_sequence<N>{}))) {
  static_assert(N <= 1024, "Array size too large for practical use");
  return make_array_impl<T, N>(lambda, std::make_index_sequence<N>{});
}

// GF3D5Factory Class
template <typename T> class GF3D5Factory {
public:
  using GFType = Loop::GF3D5<T>;

  // Type aliases for clarity
  using VecGF = std::array<GFType, 3>;
  using SmatGF = std::array<GFType, 6>;
  using VecVecGF = std::array<VecGF, 3>;
  using VecSmatGF = std::array<SmatGF, 3>;
  using SmatVecGF = std::array<VecGF, 6>;
  using SmatSmatGF = std::array<SmatGF, 6>;

  // Constructor
  GF3D5Factory(const Loop::GF3D5layout &layout5, int ntmps, int &itmp)
      : tmps_(layout5, ntmps), itmp_ref_(itmp) {}

  // Inline functions instead of std::function
  [[nodiscard]] GFType make_gf() const noexcept { return create_gf(); }
  [[nodiscard]] VecGF make_vec_gf() const noexcept {
    return create_vec(&GF3D5Factory::make_gf);
  }
  [[nodiscard]] SmatGF make_smat_gf() const noexcept {
    return create_smat(&GF3D5Factory::make_gf);
  }
  [[nodiscard]] VecVecGF make_vec_vec_gf() const noexcept {
    return create_vec(&GF3D5Factory::make_vec_gf);
  }
  [[nodiscard]] VecSmatGF make_vec_smat_gf() const noexcept {
    return create_vec(&GF3D5Factory::make_smat_gf);
  }
  [[nodiscard]] SmatVecGF make_smat_vec_gf() const noexcept {
    return create_smat(&GF3D5Factory::make_vec_gf);
  }
  [[nodiscard]] SmatSmatGF make_smat_smat_gf() const noexcept {
    return create_smat(&GF3D5Factory::make_smat_gf);
  }

private:
  Loop::GF3D5vector<T> tmps_;
  int &itmp_ref_; // Reference to the external temporary index

  // Generates a single grid function
  [[nodiscard]] GFType create_gf() const noexcept {
    return GFType(tmps_(itmp_ref_++));
  }

  // Helper functions for generating vectors and symmetric matrices
  template <typename Func>
  [[nodiscard]] decltype(auto) create_vec(Func f) const noexcept {
    return make_array<decltype((this->*f)()), 3>(
        [&](size_t) { return (this->*f)(); });
  }

  template <typename Func>
  [[nodiscard]] decltype(auto) create_smat(Func f) const noexcept {
    return make_array<decltype((this->*f)()), 6>(
        [&](size_t) { return (this->*f)(); });
  }
};

// Get GF3D5layout
template <int CI, int CJ, int CK>
inline Loop::GF3D5layout get_GF3D5layout(const cGH *restrict const cctkGH) {
  Arith::vect<int, Loop::dim> imin, imax;
  Loop::GridDescBase(cctkGH).box_int<CI, CJ, CK>({cctkGH->cctk_nghostzones[0],
                                                  cctkGH->cctk_nghostzones[1],
                                                  cctkGH->cctk_nghostzones[2]},
                                                 imin, imax);
  return Loop::GF3D5layout(imin, imax);
}

} // namespace CXUtils

#endif // #ifndef CXUTILS_UTILS_HXX
