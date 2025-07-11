(* ::Package:: *)

(* dissinline.wl *)

(* (c) Liwei Ji, 02/2025 *)

(******************)
(* Configurations *)
(******************)

Needs["xAct`xCoba`", FileNameJoin[{Environment["GENERATO"], "src/Generato.wl"}]]

SetPVerbose[False];

SetPrintDate[False];


(******************)
(* Print to Files *)
(******************)

SetOutputFile[FileNameJoin[{Directory[], "dissinline.hxx"}]];

SetMainPrint[
  pr["#include <loop_device.hxx>"];
  pr[];
  pr["#include <array>"];
  pr["#include <cmath>"];
  pr[];
  pr["#include \"derivsinline.hxx\""];
  pr[];
  pr["namespace CXUtils {"];
  pr["using namespace Arith;"];
  pr["using namespace Loop;"];
  pr[];
  pr["template <int deriv_order, typename T>"];
  pr["CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T"];
  pr["calc_diss(const GF3D2layout &layout, const T *gf, int i, int j, int k,"];
  pr["          const std::array<T, 3> &invDx) {"];
  pr["  constexpr int diss_order = deriv_order + 2;"];
  pr["  constexpr int sign = diss_order % 4 == 0 ? -1 : +1;"];
  Do[
    pr[If[aOrd == 2, "  ", "  } else "]
      <> "if constexpr (deriv_order == " <> ToString[aOrd] <>") {"];
    pr["    return sign / T(pown(2, deriv_order + 2)) *"];
    pr["           (diss_" <>  ToString[aOrd + 2] <> "_o" <> ToString[aOrd + 2]
                           <> "<1>(layout, gf, i, j, k, invDx) +"];
    pr["            diss_" <>  ToString[aOrd + 2] <> "_o" <> ToString[aOrd + 2]
                           <> "<2>(layout, gf, i, j, k, invDx) +"];
    pr["            diss_" <>  ToString[aOrd + 2] <> "_o" <> ToString[aOrd + 2]
                           <> "<3>(layout, gf, i, j, k, invDx));"];
    ,
    {aOrd, 2, 8, 2}
  ];
  pr["  } else {"];
  pr["    assert(0);"];
  pr["  }"];
  pr["}"];
  pr[];

  pr["} // namespace CXUtils"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
