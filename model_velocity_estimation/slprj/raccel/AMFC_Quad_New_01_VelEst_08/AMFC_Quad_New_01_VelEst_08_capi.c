#include "__cf_AMFC_Quad_New_01_VelEst_08.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "AMFC_Quad_New_01_VelEst_08_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "AMFC_Quad_New_01_VelEst_08.h"
#include "AMFC_Quad_New_01_VelEst_08_capi.h"
#include "AMFC_Quad_New_01_VelEst_08_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 17 , TARGET_STRING
( "AMFC_Quad_New_01_VelEst_08/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 2 , 0 , TARGET_STRING ( "AMFC_Quad_New_01_VelEst_08/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 1 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Controller interpreter" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 4 , 1 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Controller interpreter" ) , TARGET_STRING (
"" ) , 1 , 0 , 1 , 0 , 0 } , { 5 , 2 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Controller interpreter1" ) , TARGET_STRING (
"" ) , 0 , 0 , 3 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 ,
0 , 0 } , { 7 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave" ) , TARGET_STRING ( "" ) , 0 , 0 ,
2 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave1" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 12 , 24 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Relative estimation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 13 , 25 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Relative estimation1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 14 , 26 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Relative measurements" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Sum1" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Sum3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Sum4" ) , TARGET_STRING ( ""
) , 0 , 0 , 4 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Sum5" ) , TARGET_STRING ( ""
) , 0 , 0 , 4 , 0 , 0 } , { 21 , 3 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/CARE" ) , TARGET_STRING ( "" ) , 0
, 0 , 5 , 0 , 0 } , { 22 , 6 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/g-Estimator" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 0 } , { 23 , 7 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/g-Estimator1" ) , TARGET_STRING (
"" ) , 0 , 0 , 5 , 0 , 0 } , { 24 , 8 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/main" ) , TARGET_STRING ( "" ) , 0
, 0 , 6 , 0 , 0 } , { 25 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/variable change" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 0 } , { 26 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/variable change" ) , TARGET_STRING
( "" ) , 1 , 0 , 6 , 0 , 0 } , { 27 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/variable change" ) , TARGET_STRING
( "" ) , 2 , 0 , 6 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 5 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator1" ) , TARGET_STRING (
"" ) , 0 , 0 , 5 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator2" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator3" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Memory" ) , TARGET_STRING ( "" ) ,
0 , 0 , 6 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 6 , 0 , 0 } , { 34 , 10 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/A-Estimator" ) , TARGET_STRING
( "" ) , 0 , 0 , 5 , 0 , 0 } , { 35 , 11 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/CARE" ) , TARGET_STRING ( "" )
, 0 , 0 , 5 , 0 , 0 } , { 36 , 14 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/g-Estimator" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 0 } , { 37 , 15 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/main" ) , TARGET_STRING ( "" )
, 0 , 0 , 6 , 0 , 0 } , { 38 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 39 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 40 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 6 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator" ) , TARGET_STRING (
"" ) , 0 , 0 , 5 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator1" ) , TARGET_STRING
( "" ) , 0 , 0 , 5 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator2" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator3" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Memory" ) , TARGET_STRING ( ""
) , 0 , 0 , 6 , 0 , 1 } , { 46 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Sum" ) , TARGET_STRING ( "" ) ,
0 , 0 , 6 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Signal Builder/FromWs" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Clock1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 51 , 18 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain2" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Switch" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 53 , 19 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 54 , 20 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 55 , 21 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 56 , 22 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 57 , 4 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 58 , 5 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 59 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 60 , 12 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 61 , 13 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 63 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Memory" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 65 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
2 , 0 } , { 66 , TARGET_STRING ( "AMFC_Quad_New_01_VelEst_08/Ref/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Constant2" ) , TARGET_STRING ( "Value" ) , 0
, 2 , 0 } , { 68 , TARGET_STRING ( "AMFC_Quad_New_01_VelEst_08/Ref/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 69 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave" ) , TARGET_STRING ( "Amplitude" )
, 0 , 2 , 0 } , { 70 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave" ) , TARGET_STRING ( "Bias" ) , 0 ,
2 , 0 } , { 71 , TARGET_STRING ( "AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave" )
, TARGET_STRING ( "Frequency" ) , 0 , 2 , 0 } , { 72 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave" ) , TARGET_STRING ( "Phase" ) , 0
, 2 , 0 } , { 73 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave1" ) , TARGET_STRING ( "Amplitude" )
, 0 , 2 , 0 } , { 74 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave1" ) , TARGET_STRING ( "Bias" ) , 0
, 2 , 0 } , { 75 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave1" ) , TARGET_STRING ( "Frequency" )
, 0 , 2 , 0 } , { 76 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Sine Wave1" ) , TARGET_STRING ( "Phase" ) , 0
, 2 , 0 } , { 77 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 ,
2 , 0 } , { 78 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn" ) , TARGET_STRING ( "C" ) , 0 ,
2 , 0 } , { 79 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0
, 2 , 0 } , { 80 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn1" ) , TARGET_STRING ( "C" ) , 0
, 2 , 0 } , { 81 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn2" ) , TARGET_STRING ( "A" ) , 0
, 2 , 0 } , { 82 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn2" ) , TARGET_STRING ( "C" ) , 0
, 2 , 0 } , { 83 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn3" ) , TARGET_STRING ( "A" ) , 0
, 2 , 0 } , { 84 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn3" ) , TARGET_STRING ( "C" ) , 0
, 2 , 0 } , { 85 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 86 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 87 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay1" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 88 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 89 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay2" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 90 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Transport Delay2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 91 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Constant1" ) , TARGET_STRING
( "Value" ) , 0 , 4 , 0 } , { 92 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Constant2" ) , TARGET_STRING
( "Value" ) , 0 , 1 , 0 } , { 93 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 4 , 0 } , { 94 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 4 , 0 } , { 95 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 5 , 0 } , { 96 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 5 , 0 } , { 97 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 98 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 99 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 100 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 5 , 0 } , { 101 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 5 , 0 } , { 102 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator2" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 6 , 0 } , { 103 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator3" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 6 , 0 } , { 104 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 105 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Signal Builder/FromWs" ) , TARGET_STRING (
"Time0" ) , 0 , 6 , 0 } , { 106 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Signal Builder/FromWs" ) , TARGET_STRING (
"Data0" ) , 0 , 6 , 0 } , { 107 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Desired Position4" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 108 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace" ) , TARGET_STRING (
"Time0" ) , 0 , 7 , 0 } , { 109 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 7 , 0 } , { 110 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace1" ) , TARGET_STRING
( "Time0" ) , 0 , 7 , 0 } , { 111 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace1" ) , TARGET_STRING
( "Data0" ) , 0 , 7 , 0 } , { 112 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace3" ) , TARGET_STRING
( "Time0" ) , 0 , 7 , 0 } , { 113 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/From Workspace3" ) , TARGET_STRING
( "Data0" ) , 0 , 7 , 0 } , { 114 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 115 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain1" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 116 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Gain2" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 117 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 2 , 0 } , { 118 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 119 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 120 , TARGET_STRING
(
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 121 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 122 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 123 , TARGET_STRING
(
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 124 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 125 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 126 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 127 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [
] = { { 128 , TARGET_STRING ( "B" ) , 0 , 5 , 0 } , { 129 , TARGET_STRING (
"BBT_inv" ) , 0 , 5 , 0 } , { 130 , TARGET_STRING ( "J" ) , 0 , 8 , 0 } , {
131 , TARGET_STRING ( "Ka" ) , 0 , 2 , 0 } , { 132 , TARGET_STRING ( "Kd" ) ,
0 , 2 , 0 } , { 133 , TARGET_STRING ( "Kf" ) , 0 , 2 , 0 } , { 134 ,
TARGET_STRING ( "Kt" ) , 0 , 2 , 0 } , { 135 , TARGET_STRING ( "L" ) , 0 , 2
, 0 } , { 136 , TARGET_STRING ( "M" ) , 0 , 2 , 0 } , { 137 , TARGET_STRING (
"Q" ) , 0 , 5 , 0 } , { 138 , TARGET_STRING ( "R" ) , 0 , 5 , 0 } , { 139 ,
TARGET_STRING ( "RM_1" ) , 0 , 9 , 0 } , { 140 , TARGET_STRING ( "alpha_P" )
, 0 , 2 , 0 } , { 141 , TARGET_STRING ( "alpha_Slid" ) , 0 , 2 , 0 } , { 142
, TARGET_STRING ( "alpha_V" ) , 0 , 2 , 0 } , { 143 , TARGET_STRING (
"gamma_0" ) , 0 , 5 , 0 } , { 144 , TARGET_STRING ( "gamma_1" ) , 0 , 5 , 0 }
, { 145 , TARGET_STRING ( "ge" ) , 0 , 2 , 0 } , { 146 , TARGET_STRING ( "k1"
) , 0 , 2 , 0 } , { 147 , TARGET_STRING ( "k1o" ) , 0 , 2 , 0 } , { 148 ,
TARGET_STRING ( "k2" ) , 0 , 2 , 0 } , { 149 , TARGET_STRING ( "k2o" ) , 0 ,
2 , 0 } , { 150 , TARGET_STRING ( "rho_0" ) , 0 , 2 , 0 } , { 151 ,
TARGET_STRING ( "rho_1" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . jdqmorg3jr [ 0 ] , & rtB .
f3qdvlncs2 [ 0 ] , & rtB . out1onmc3n [ 0 ] , & rtB . it5y34mzxt , & rtB .
ksdh1okcet [ 0 ] , & rtB . oflhugxayb [ 0 ] , & rtB . hut5rsdm1t , & rtB .
db0sdie5cx , & rtB . olp0aypydn , & rtB . cvaerauj1g , & rtB . luue0kfi2i , &
rtB . cp0haf23uy , & rtB . lipu0dbc2k [ 0 ] , & rtB . ab5rfxknmw [ 0 ] , &
rtB . dlysorqgi3 , & rtB . fkn5pxjywf [ 0 ] , & rtB . jgeak2pmpa [ 0 ] , &
rtB . hrymkwe4oo [ 0 ] , & rtB . dhldqomrw2 [ 0 ] , & rtB . a2l3vjk5kk [ 0 ]
, & rtB . bslv0j5s21 [ 0 ] , & rtB . jr4hvs211j . cxgasfu34l [ 0 ] , & rtB .
n11qfveosl . n54ymdd4p0 [ 0 ] , & rtB . cwezlbfqfz . ejjucyteji [ 0 ] , & rtB
. l1rejasabs . jb4t0dt15b [ 0 ] , & rtB . fgqxwi1chj [ 0 ] , & rtB .
fz3gjqjow4 [ 0 ] , & rtB . b4h3ks3r0d [ 0 ] , & rtB . ix2okivzvw [ 0 ] , &
rtB . es2yapuiac [ 0 ] , & rtB . mghhh4y54x [ 0 ] , & rtB . m2sfecaklo [ 0 ]
, & rtB . oidskutggb [ 0 ] , & rtB . o2eyjfo1wi [ 0 ] , & rtB . ipiqttfm4x .
ejjucyteji [ 0 ] , & rtB . ffhxpulbso . cxgasfu34l [ 0 ] , & rtB . ca4s31r1o4
. n54ymdd4p0 [ 0 ] , & rtB . lxb4grs0ty . jb4t0dt15b [ 0 ] , & rtB .
j5d2rfynpz [ 0 ] , & rtB . bgofqzyuag [ 0 ] , & rtB . hyspkccycp [ 0 ] , &
rtB . fjffiex4ix [ 0 ] , & rtB . pnzkimrl2h [ 0 ] , & rtB . c05vhcs2pf [ 0 ]
, & rtB . iyrr00rsy5 [ 0 ] , & rtB . eja0y2gles [ 0 ] , & rtB . ncyc1gpaj2 [
0 ] , & rtB . hdwtb14kjv , & rtB . niozx0x3bq , & rtB . h0vfo44bet , & rtB .
apsqtgdw2k , & rtB . mhmxoetwje , & rtB . bzt0lwzvse , & rtB . feorxccqpz .
gydza50f0o , & rtB . eg12osul0v . h0xntzw5zb , & rtB . j2zidd3tqj .
gydza50f0o , & rtB . hpraryzlaj . h0xntzw5zb , & rtB . paq4dzeup4 .
ao4ocy3oo3 [ 0 ] , & rtB . jrhbb2xk4n . oaqi4nmegi [ 0 ] , & rtB . m0blghypsp
[ 0 ] , & rtB . cvltowsf2b . ao4ocy3oo3 [ 0 ] , & rtB . pg0yucqphr .
oaqi4nmegi [ 0 ] , & rtB . mqwm4nfdap [ 0 ] , & rtP . Integrator_IC [ 0 ] , &
rtP . Memory_InitialCondition_cltcggngaa [ 0 ] , & rtP . Constant_Value , &
rtP . Constant1_Value , & rtP . Constant2_Value , & rtP .
Gain_Gain_pqv5poqtm5 , & rtP . SineWave_Amp , & rtP . SineWave_Bias , & rtP .
SineWave_Freq , & rtP . SineWave_Phase , & rtP . SineWave1_Amp , & rtP .
SineWave1_Bias , & rtP . SineWave1_Freq , & rtP . SineWave1_Phase , & rtP .
TransferFcn_A , & rtP . TransferFcn_C , & rtP . TransferFcn1_A , & rtP .
TransferFcn1_C , & rtP . TransferFcn2_A , & rtP . TransferFcn2_C , & rtP .
TransferFcn3_A , & rtP . TransferFcn3_C , & rtP . TransportDelay_Delay , &
rtP . TransportDelay_InitOutput , & rtP . TransportDelay1_Delay , & rtP .
TransportDelay1_InitOutput , & rtP . TransportDelay2_Delay , & rtP .
TransportDelay2_InitOutput , & rtP . Constant1_Value_k0amvdt1or [ 0 ] , & rtP
. Constant2_Value_p1uxhfeofi [ 0 ] , & rtP . Integrator1_IC [ 0 ] , & rtP .
Integrator2_IC [ 0 ] , & rtP . Integrator_IC_lijhdzhcao [ 0 ] , & rtP .
Integrator1_IC_ea4j2itlpr [ 0 ] , & rtP . Integrator2_IC_eshmddcula [ 0 ] , &
rtP . Integrator3_IC_mvcbk0lpqx [ 0 ] , & rtP .
Memory_InitialCondition_ltjalipc0r [ 0 ] , & rtP . Integrator_IC_d53cezkjnk [
0 ] , & rtP . Integrator1_IC_etk5iarzoa [ 0 ] , & rtP .
Integrator2_IC_milw2qy4e1 [ 0 ] , & rtP . Integrator3_IC [ 0 ] , & rtP .
Memory_InitialCondition [ 0 ] , & rtP . FromWs_Time0 [ 0 ] , & rtP .
FromWs_Data0 [ 0 ] , & rtP . DesiredPosition4_Value , & rtP .
FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , & rtP .
FromWorkspace1_Time0 [ 0 ] , & rtP . FromWorkspace1_Data0 [ 0 ] , & rtP .
FromWorkspace3_Time0 [ 0 ] , & rtP . FromWorkspace3_Data0 [ 0 ] , & rtP .
Gain_Gain_bttrwertaz , & rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP .
Switch_Threshold , & rtP . Gain_Gain_mauqb2akec , & rtP .
Integrator_IC_mdtcnu4jbd , & rtP . Integrator1_IC_cysw5lmkvd , & rtP .
Gain_Gain , & rtP . Integrator_IC_bzpo215sgo , & rtP .
Integrator1_IC_kniptj1kxt , & rtP . Integrator_IC_i2crhtqu0w [ 0 ] , & rtP .
Integrator1_IC_og2211l4hi [ 0 ] , & rtP . Integrator_IC_kjcjwivfdd [ 0 ] , &
rtP . Integrator1_IC_bfgbvvrang [ 0 ] , & rtP . B [ 0 ] , & rtP . BBT_inv [ 0
] , & rtP . J [ 0 ] , & rtP . Ka , & rtP . Kd , & rtP . Kf , & rtP . Kt , &
rtP . L , & rtP . M , & rtP . Q [ 0 ] , & rtP . R [ 0 ] , & rtP . RM_1 [ 0 ]
, & rtP . alpha_P , & rtP . alpha_Slid , & rtP . alpha_V , & rtP . gamma_0 [
0 ] , & rtP . gamma_1 [ 0 ] , & rtP . ge , & rtP . k1 , & rtP . k1o , & rtP .
k2 , & rtP . k2o , & rtP . rho_0 , & rtP . rho_1 , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_SCALAR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 12 , 1 , 3 , 1 , 1 , 1
, 4 , 1 , 2 , 1 , 6 , 6 , 6 , 1 , 601 , 1 , 3 , 3 , 4 , 4 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , 0 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void
* ) & rtcapiStoredFloats [ 1 ] , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 63 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 65 , rtModelParameters , 24 } ,
{ ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1399061238U
, 1260434799U , 1108173927U , 2886202868U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * AMFC_Quad_New_01_VelEst_08_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void AMFC_Quad_New_01_VelEst_08_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void AMFC_Quad_New_01_VelEst_08_host_InitializeDataMapInfo (
AMFC_Quad_New_01_VelEst_08_host_DataMapInfo_T * dataMap , const char * path )
{ rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap
-> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
