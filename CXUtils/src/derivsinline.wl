(* ::Package:: *)

(* derivsinline.wl *)

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

SetOutputFile[FileNameJoin[{Directory[], "derivsinline.hxx"}]];

SetMainPrint[
  pr["#include <loop_device.hxx>"];
  pr[];
  pr["#include <array>"];
  pr["#include <cmath>"];
  pr[];
  pr["#include \"powerinline.hxx\""];
  pr[];

  pr["namespace CXUtils {"];
  pr["using namespace Loop;"];
  pr[];

  (****************************************)
  (* First-order Finite Difference Scheme *)
  (****************************************)

  Do[
    pr["template <int DI, typename T>"];
    pr["CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T"];
    pr["fd_1_o" <> ToString[aOrd]
                <> "(const GF3D2layout &layout, const T *gf, "
                <> "int i, int j, int k, const std::array<T, 3> &invDx) {"];
    PrintIndexes3D[aOrd, 1, "DI"];
    pr["  return"];
    PrintFDExpression[aOrd, 1, "invDx"];
    pr["}"];
    pr[]
    ,
    {aOrd, 2, 8, 2}
  ];

  (*****************************************)
  (* Second-order Finite Difference Scheme *)
  (*****************************************)

  Do[
    pr["template <int DI, int DJ, typename T>"];
    pr["CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T"];
    pr["fd_2_o" <> ToString[aOrd]
                <> "(const GF3D2layout &layout, const T *gf, "
                <> "int i, int j, int k, const std::array<T, 3> &invDx) {"];
    pr["  if constexpr (DI == DJ) {"];
    PrintIndexes3D[aOrd, 2, "DI"];
    pr["    return"];
    PrintFDExpression[aOrd, 2, "invDx"];
    pr["  } else {"];
    PrintIndexes3DMix2nd[aOrd, "DI", "DJ"];
    pr["    return"];
    PrintFDExpressionMix2nd[aOrd, "invDx"];
    pr["  }"];
    pr["}"];
    pr[]
    ,
    {aOrd, 2, 8, 2}
  ];

  (********************************************)
  (* Finite Difference Scheme for Dissipation *)
  (********************************************)

  Do[
    pr["template <int DI, typename T>"];
    pr["CCTK_DEVICE CCTK_HOST CCTK_ATTRIBUTE_ALWAYS_INLINE inline T"];
    pr["diss_" <> ToString[aOrd] <>"_o" <> ToString[aOrd]
               <> "(const GF3D2layout &layout, const T *gf, "
               <> "int i, int j, int k, const std::array<T, 3> &invDx) {"];
    PrintIndexes3D[aOrd, aOrd, "DI"];
    pr["  return"];
    PrintFDExpression[{ForDissipation -> True}, aOrd, aOrd, "invDx"];
    pr["}"];
    pr[]
    ,
    {aOrd, 4, 10, 2}
  ];

  pr["} // namespace CXUtils"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
