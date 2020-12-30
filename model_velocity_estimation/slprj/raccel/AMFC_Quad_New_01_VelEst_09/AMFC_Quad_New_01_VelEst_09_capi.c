#include "__cf_AMFC_Quad_New_01_VelEst_09.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "AMFC_Quad_New_01_VelEst_09_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "AMFC_Quad_New_01_VelEst_09.h"
#include "AMFC_Quad_New_01_VelEst_09_capi.h"
#include "AMFC_Quad_New_01_VelEst_09_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 17 , TARGET_STRING
( "AMFC_Quad_New_01_VelEst_09/Agent/MATLAB Function" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Integrator" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 3 , 43 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/MATLAB Function" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Integrator" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 1
, 0 , 0 } , { 6 , 1 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Controller interpreter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 7 , 1 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Controller interpreter" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 1 , 0 , 0 } , { 8 , 2 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Controller interpreter1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay1" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay2" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 15 , 23 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/MATLAB Function1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 24 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Relative estimation" )
, TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 17 , 25 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Relative estimation1" )
, TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 18 , 26 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Relative measurements"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum1" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum2" ) , TARGET_STRING
( "" ) , 0 , 0 , 4 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum3" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum4" ) , TARGET_STRING
( "" ) , 0 , 0 , 4 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum5" ) , TARGET_STRING
( "" ) , 0 , 0 , 4 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Sum6" ) , TARGET_STRING
( "" ) , 0 , 0 , 4 , 0 , 0 } , { 27 , 27 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Controller interpreter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 28 , 27 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Controller interpreter" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 1 , 0 , 0 } , { 29 , 28 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Controller interpreter1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain3" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 36 , 3 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/CARE" ) , TARGET_STRING ( ""
) , 0 , 0 , 5 , 0 , 0 } , { 37 , 6 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/g-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 38 , 7 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/g-Estimator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 39 , 8 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/main" ) , TARGET_STRING ( ""
) , 0 , 0 , 6 , 0 , 0 } , { 40 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 41 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 42 , 9 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 6 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Memory" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 1 } , { 44 , 10 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/A-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 45 , 11 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/CARE" ) , TARGET_STRING (
"" ) , 0 , 0 , 5 , 0 , 0 } , { 46 , 14 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/g-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 47 , 15 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/main" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 0 } , { 48 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 49 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 50 , 16 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 6 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Memory" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Clock1" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain1" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 56 , 18 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain2" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 58 , 19 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 59 , 20 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 60 , 21 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 61 , 22 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 62 , 29 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/CARE" ) , TARGET_STRING (
"" ) , 0 , 0 , 5 , 0 , 0 } , { 63 , 32 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/g-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 64 , 33 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/g-Estimator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 65 , 34 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/main" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 0 } , { 66 , 35 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 67 , 35 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 68 , 35 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/variable change" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 6 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Memory" ) , TARGET_STRING (
"" ) , 0 , 0 , 6 , 0 , 1 } , { 70 , 36 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/A-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 71 , 37 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/CARE" ) , TARGET_STRING
( "" ) , 0 , 0 , 5 , 0 , 0 } , { 72 , 40 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/g-Estimator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 73 , 41 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/main" ) , TARGET_STRING
( "" ) , 0 , 0 , 6 , 0 , 0 } , { 74 , 42 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 75 , 42 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 76 , 42 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/variable change" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 6 , 0 , 0 } , { 77 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 79 , 0 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/Clock1" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 80 , 44 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/Gain2" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 81 , 4 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 82 , 5 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 83 , 12 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 84 , 13 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 85 , 30 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 86 , 31 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 87 , 38 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Sliding differentiator"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 88 , 39 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Sliding differentiator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 89 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 2 , 0 } , { 93 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 2 , 0 } , { 94 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Constant1" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 95 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Constant2" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 96 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Gain" ) , TARGET_STRING ( "Gain" ) , 0
, 2 , 0 } , { 97 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave" ) , TARGET_STRING (
"Amplitude" ) , 0 , 2 , 0 } , { 98 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave" ) , TARGET_STRING ( "Bias" )
, 0 , 2 , 0 } , { 99 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave" ) , TARGET_STRING (
"Frequency" ) , 0 , 2 , 0 } , { 100 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave" ) , TARGET_STRING ( "Phase"
) , 0 , 2 , 0 } , { 101 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 2 , 0 } , { 102 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave1" ) , TARGET_STRING ( "Bias"
) , 0 , 2 , 0 } , { 103 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave1" ) , TARGET_STRING (
"Frequency" ) , 0 , 2 , 0 } , { 104 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Sine Wave1" ) , TARGET_STRING ( "Phase"
) , 0 , 2 , 0 } , { 105 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn" ) , TARGET_STRING ( "A" )
, 0 , 2 , 0 } , { 106 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn" ) , TARGET_STRING ( "C" )
, 0 , 2 , 0 } , { 107 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn1" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 108 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn1" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 109 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn2" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 110 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn2" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 111 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn3" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 112 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn3" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 113 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 114 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 115 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay1" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 116 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 117 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay2" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 118 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transport Delay2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 119 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 4 , 0 } , { 120 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 4 , 0 } , { 121 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 122 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Constant1" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 123 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Constant2" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 124 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain" ) , TARGET_STRING ( "Gain" ) , 0
, 2 , 0 } , { 125 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain1" ) , TARGET_STRING ( "Gain" ) ,
0 , 2 , 0 } , { 126 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain2" ) , TARGET_STRING ( "Gain" ) ,
0 , 2 , 0 } , { 127 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Gain3" ) , TARGET_STRING ( "Gain" ) ,
0 , 2 , 0 } , { 128 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave" ) , TARGET_STRING (
"Amplitude" ) , 0 , 2 , 0 } , { 129 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave" ) , TARGET_STRING ( "Bias"
) , 0 , 2 , 0 } , { 130 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave" ) , TARGET_STRING (
"Frequency" ) , 0 , 2 , 0 } , { 131 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave" ) , TARGET_STRING ( "Phase"
) , 0 , 2 , 0 } , { 132 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 2 , 0 } , { 133 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave1" ) , TARGET_STRING ( "Bias"
) , 0 , 2 , 0 } , { 134 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave1" ) , TARGET_STRING (
"Frequency" ) , 0 , 2 , 0 } , { 135 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Sine Wave1" ) , TARGET_STRING (
"Phase" ) , 0 , 2 , 0 } , { 136 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 137 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 138 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn1" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 139 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn1" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 140 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn2" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 141 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn2" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 142 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn3" ) , TARGET_STRING ( "A"
) , 0 , 2 , 0 } , { 143 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn3" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 144 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 145 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 146 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay1" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 147 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 148 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay2" ) , TARGET_STRING (
"DelayTime" ) , 0 , 2 , 0 } , { 149 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transport Delay2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 2 , 0 } , { 150 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 151 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 152 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 153 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator3" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 154 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 155 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 156 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 157 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 158 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator3" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 159 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Memory" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 6 , 0 } , { 160 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "Time0" ) , 0 , 6 , 0 } , { 161 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "Data0" ) , 0 , 6 , 0 } , { 162 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Desired Position4" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 163 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace" ) ,
TARGET_STRING ( "Time0" ) , 0 , 7 , 0 } , { 164 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace" ) ,
TARGET_STRING ( "Data0" ) , 0 , 7 , 0 } , { 165 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace1" ) ,
TARGET_STRING ( "Time0" ) , 0 , 7 , 0 } , { 166 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace1" ) ,
TARGET_STRING ( "Data0" ) , 0 , 7 , 0 } , { 167 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace3" ) ,
TARGET_STRING ( "Time0" ) , 0 , 7 , 0 } , { 168 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/From Workspace3" ) ,
TARGET_STRING ( "Data0" ) , 0 , 7 , 0 } , { 169 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 170 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 171 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 172 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 2 , 0 } , { 173 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 174 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 175 ,
TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 176 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 177 , TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 178 ,
TARGET_STRING (
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 179 ,
TARGET_STRING ( "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 180 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 181 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 182 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator3" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 183 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 6 , 0 } , { 184 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 185 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 186 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 187 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator3" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 188 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 189 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "Time0" ) , 0 , 6 , 0 } , { 190 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Signal Builder/FromWs" ) ,
TARGET_STRING ( "Data0" ) , 0 , 6 , 0 } , { 191 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/Desired Position4" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 192 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/From Workspace3" ) ,
TARGET_STRING ( "Time0" ) , 0 , 7 , 0 } , { 193 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/From Workspace3" ) ,
TARGET_STRING ( "Data0" ) , 0 , 7 , 0 } , { 194 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 195 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Subsystem/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 2 , 0 } , { 196 , TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 197 , TARGET_STRING
(
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 198 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 199 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 200 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 201 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 202 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 203 ,
TARGET_STRING (
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 204 , TARGET_STRING ( "B" ) , 0 , 5 , 0 } , { 205
, TARGET_STRING ( "BBT_inv" ) , 0 , 5 , 0 } , { 206 , TARGET_STRING ( "J" ) ,
0 , 8 , 0 } , { 207 , TARGET_STRING ( "Ka" ) , 0 , 2 , 0 } , { 208 ,
TARGET_STRING ( "Kd" ) , 0 , 2 , 0 } , { 209 , TARGET_STRING ( "Kf" ) , 0 , 2
, 0 } , { 210 , TARGET_STRING ( "Kt" ) , 0 , 2 , 0 } , { 211 , TARGET_STRING
( "L" ) , 0 , 2 , 0 } , { 212 , TARGET_STRING ( "M" ) , 0 , 2 , 0 } , { 213 ,
TARGET_STRING ( "Q" ) , 0 , 5 , 0 } , { 214 , TARGET_STRING ( "R" ) , 0 , 5 ,
0 } , { 215 , TARGET_STRING ( "RM_1" ) , 0 , 9 , 0 } , { 216 , TARGET_STRING
( "alpha_P" ) , 0 , 2 , 0 } , { 217 , TARGET_STRING ( "alpha_Slid" ) , 0 , 2
, 0 } , { 218 , TARGET_STRING ( "alpha_V" ) , 0 , 2 , 0 } , { 219 ,
TARGET_STRING ( "gamma_0" ) , 0 , 5 , 0 } , { 220 , TARGET_STRING ( "gamma_1"
) , 0 , 5 , 0 } , { 221 , TARGET_STRING ( "ge" ) , 0 , 2 , 0 } , { 222 ,
TARGET_STRING ( "k1" ) , 0 , 2 , 0 } , { 223 , TARGET_STRING ( "k1o" ) , 0 ,
2 , 0 } , { 224 , TARGET_STRING ( "k2" ) , 0 , 2 , 0 } , { 225 ,
TARGET_STRING ( "k2o" ) , 0 , 2 , 0 } , { 226 , TARGET_STRING ( "rho_0" ) , 0
, 2 , 0 } , { 227 , TARGET_STRING ( "rho_1" ) , 0 , 2 , 0 } , { 0 , ( NULL )
, 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . oxu2odnx00 . o5vw3qgp1n [ 0 ] , &
rtB . ivgrkuetfr [ 0 ] , & rtB . iolwo3nnoi [ 0 ] , & rtB . hqeceb1qj5 .
o5vw3qgp1n [ 0 ] , & rtB . lxmuzwnnxk [ 0 ] , & rtB . edxclkusat [ 0 ] , &
rtB . jqsclsqnve . ispj2sto2a , & rtB . jqsclsqnve . a3fw5udt1f [ 0 ] , & rtB
. opcrukpa55 . h4nyij0txf [ 0 ] , & rtB . l2okftp1nu , & rtB . jfhxiyyt2e , &
rtB . m45fkguer0 , & rtB . jx10qz0y32 , & rtB . mgwl4qchuz , & rtB .
g4uzmogaho , & rtB . nof2skbwsq [ 0 ] , & rtB . liy3ccyuzf [ 0 ] , & rtB .
c3o3xjf5wt [ 0 ] , & rtB . o3szt5ur1k , & rtB . dlk22jmuti [ 0 ] , & rtB .
fp1jf5ytc0 [ 0 ] , & rtB . ndl3k25chw [ 0 ] , & rtB . gslpjnsh5g [ 0 ] , &
rtB . etvvsvbtr0 [ 0 ] , & rtB . cn0dzpfmb5 [ 0 ] , & rtB . f5ibyqhnm5 [ 0 ]
, & rtB . fb2enyqb0z [ 0 ] , & rtB . esmlujbtbz . ispj2sto2a , & rtB .
esmlujbtbz . a3fw5udt1f [ 0 ] , & rtB . crvoapndv2 . h4nyij0txf [ 0 ] , & rtB
. e2xua1vi2a , & rtB . f5j3k1cgkz , & rtB . ejv5n5dh4j , & rtB . gol00soltl ,
& rtB . h1dldewdlg , & rtB . e43dgc14sk , & rtB . himcwdjdya . g3f2ipoicp [ 0
] , & rtB . gxc0uqkvgw . llum1d4imd [ 0 ] , & rtB . duudknct5v . agvkxpaya3 [
0 ] , & rtB . lfuuj0xy5s . dy01b2bgnp [ 0 ] , & rtB . pcmu2rnoht . b5v3smwxxf
[ 0 ] , & rtB . pcmu2rnoht . nbc5e1aa4y [ 0 ] , & rtB . pcmu2rnoht .
kncnn35ehq [ 0 ] , & rtB . ozsyjbt0zf [ 0 ] , & rtB . porpvvdkpb . agvkxpaya3
[ 0 ] , & rtB . o3xr450ufq . g3f2ipoicp [ 0 ] , & rtB . lfdnfksqrv .
llum1d4imd [ 0 ] , & rtB . imeubyypoc . dy01b2bgnp [ 0 ] , & rtB . ne34mblrux
. bscgwtwcot [ 0 ] , & rtB . ne34mblrux . idzmiix4px [ 0 ] , & rtB .
ne34mblrux . hjeyr5gjr3 [ 0 ] , & rtB . ofqfdlsgnm [ 0 ] , & rtB . hzr1dfuf5l
, & rtB . lgrmzrtnoa , & rtB . m3xmkbwv00 , & rtB . bzd1lyzgz1 , & rtB .
pc3poziqbx , & rtB . nnr1ahifvl , & rtB . kscttm531o . hfqvj0omua , & rtB .
ghv0odgskz . pccs3jrnen , & rtB . bmakjzspmx . hfqvj0omua , & rtB .
p4ycag1e5s . pccs3jrnen , & rtB . cnusct4inu . g3f2ipoicp [ 0 ] , & rtB .
dwgomjumxz . llum1d4imd [ 0 ] , & rtB . n5z0v3jy3r . agvkxpaya3 [ 0 ] , & rtB
. dbfm2fggcf . dy01b2bgnp [ 0 ] , & rtB . ddjji0axxh . b5v3smwxxf [ 0 ] , &
rtB . ddjji0axxh . nbc5e1aa4y [ 0 ] , & rtB . ddjji0axxh . kncnn35ehq [ 0 ] ,
& rtB . ftcjn2x21e [ 0 ] , & rtB . evmbjc0b4d . agvkxpaya3 [ 0 ] , & rtB .
drmxackmon . g3f2ipoicp [ 0 ] , & rtB . fch5gmq0mk . llum1d4imd [ 0 ] , & rtB
. iz2vhx1had . dy01b2bgnp [ 0 ] , & rtB . hc5s13aofb . bscgwtwcot [ 0 ] , &
rtB . hc5s13aofb . idzmiix4px [ 0 ] , & rtB . hc5s13aofb . hjeyr5gjr3 [ 0 ] ,
& rtB . bu5fouv53z [ 0 ] , & rtB . kryicu302t , & rtB . jz5340fyqc , & rtB .
mztx0ubroi , & rtB . ccm3czt3ct . bkxow1zaxw [ 0 ] , & rtB . kwvmxh0kpo .
c0eitivnzv [ 0 ] , & rtB . kwzvd2zz43 . bkxow1zaxw [ 0 ] , & rtB . pmwvgwx3i3
. c0eitivnzv [ 0 ] , & rtB . kblwc120uj . bkxow1zaxw [ 0 ] , & rtB .
dwyanlti1g . c0eitivnzv [ 0 ] , & rtB . lqm3tkmrj0 . bkxow1zaxw [ 0 ] , & rtB
. m4nweffg3k . c0eitivnzv [ 0 ] , & rtP . Integrator_IC [ 0 ] , & rtP .
Memory_InitialCondition_cltcggngaa [ 0 ] , & rtP . Integrator_IC_au2dj45vgj [
0 ] , & rtP . Memory_InitialCondition_ihnyqfqp54 , & rtP . Constant_Value , &
rtP . Constant1_Value , & rtP . Constant2_Value , & rtP .
Gain_Gain_pqv5poqtm5 , & rtP . SineWave_Amp , & rtP . SineWave_Bias , & rtP .
SineWave_Freq , & rtP . SineWave_Phase , & rtP . SineWave1_Amp , & rtP .
SineWave1_Bias , & rtP . SineWave1_Freq , & rtP . SineWave1_Phase , & rtP .
TransferFcn_A , & rtP . TransferFcn_C , & rtP . TransferFcn1_A , & rtP .
TransferFcn1_C , & rtP . TransferFcn2_A , & rtP . TransferFcn2_C , & rtP .
TransferFcn3_A , & rtP . TransferFcn3_C , & rtP . TransportDelay_Delay , &
rtP . TransportDelay_InitOutput , & rtP . TransportDelay1_Delay , & rtP .
TransportDelay1_InitOutput , & rtP . TransportDelay2_Delay , & rtP .
TransportDelay2_InitOutput , & rtP . Integrator1_IC [ 0 ] , & rtP .
Integrator2_IC [ 0 ] , & rtP . Constant_Value_f3fl4m3lns , & rtP .
Constant1_Value_bfcgyn3zal , & rtP . Constant2_Value_imre1apqn2 , & rtP .
Gain_Gain_pjv0l5nu25 , & rtP . Gain1_Gain_lwvfyvhuab , & rtP .
Gain2_Gain_gy0kebd21j , & rtP . Gain3_Gain , & rtP . SineWave_Amp_cqusaijwz1
, & rtP . SineWave_Bias_dhkcw5madh , & rtP . SineWave_Freq_hkeiim1l54 , & rtP
. SineWave_Phase_atfet5pyf2 , & rtP . SineWave1_Amp_mdrsfgbaur , & rtP .
SineWave1_Bias_eubjrqq2u4 , & rtP . SineWave1_Freq_ekxuh2oqwg , & rtP .
SineWave1_Phase_pvy3avqa4x , & rtP . TransferFcn_A_opc1nfp3z4 , & rtP .
TransferFcn_C_etz5z3jsj3 , & rtP . TransferFcn1_A_bowexjz0op , & rtP .
TransferFcn1_C_gbzdyi5fsz , & rtP . TransferFcn2_A_a0oyqusjcz , & rtP .
TransferFcn2_C_dmkbndw1jb , & rtP . TransferFcn3_A_luwp2lluol , & rtP .
TransferFcn3_C_bgvnqgidnw , & rtP . TransportDelay_Delay_mrtq4yly2u , & rtP .
TransportDelay_InitOutput_bw2s5ogtcl , & rtP .
TransportDelay1_Delay_l2osw0ocdi , & rtP .
TransportDelay1_InitOutput_ctmwtl3hbr , & rtP .
TransportDelay2_Delay_dxj4qf2s24 , & rtP .
TransportDelay2_InitOutput_ddz2iqhful , & rtP . Integrator_IC_lijhdzhcao [ 0
] , & rtP . Integrator1_IC_ea4j2itlpr [ 0 ] , & rtP .
Integrator2_IC_eshmddcula [ 0 ] , & rtP . Integrator3_IC_mvcbk0lpqx [ 0 ] , &
rtP . Memory_InitialCondition_ltjalipc0r [ 0 ] , & rtP .
Integrator_IC_d53cezkjnk [ 0 ] , & rtP . Integrator1_IC_etk5iarzoa [ 0 ] , &
rtP . Integrator2_IC_milw2qy4e1 [ 0 ] , & rtP . Integrator3_IC [ 0 ] , & rtP
. Memory_InitialCondition [ 0 ] , & rtP . FromWs_Time0 [ 0 ] , & rtP .
FromWs_Data0 [ 0 ] , & rtP . DesiredPosition4_Value , & rtP .
FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , & rtP .
FromWorkspace1_Time0 [ 0 ] , & rtP . FromWorkspace1_Data0 [ 0 ] , & rtP .
FromWorkspace3_Time0 [ 0 ] , & rtP . FromWorkspace3_Data0 [ 0 ] , & rtP .
Gain_Gain_bttrwertaz , & rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP .
Switch_Threshold , & rtP . Gain_Gain_mauqb2akec , & rtP .
Integrator_IC_mdtcnu4jbd , & rtP . Integrator1_IC_cysw5lmkvd , & rtP .
Gain_Gain , & rtP . Integrator_IC_bzpo215sgo , & rtP .
Integrator1_IC_kniptj1kxt , & rtP . Integrator_IC_puc2fkypqe [ 0 ] , & rtP .
Integrator1_IC_dwmkl32mdn [ 0 ] , & rtP . Integrator2_IC_pkgbdnqjyc [ 0 ] , &
rtP . Integrator3_IC_oqmkotgcvb [ 0 ] , & rtP .
Memory_InitialCondition_dew5rdr00k [ 0 ] , & rtP . Integrator_IC_dn1v3y4i5t [
0 ] , & rtP . Integrator1_IC_aondaic4tn [ 0 ] , & rtP .
Integrator2_IC_eq0rr2lar5 [ 0 ] , & rtP . Integrator3_IC_nyxzwevmz0 [ 0 ] , &
rtP . Memory_InitialCondition_ogj5j113sv [ 0 ] , & rtP .
FromWs_Time0_dvongqu3oc [ 0 ] , & rtP . FromWs_Data0_bk0ugsj5dc [ 0 ] , & rtP
. DesiredPosition4_Value_izm2550djd , & rtP . FromWorkspace3_Time0_arirwmivf2
[ 0 ] , & rtP . FromWorkspace3_Data0_glaft0xfxw [ 0 ] , & rtP .
Gain2_Gain_c2uyk0coml , & rtP . Switch_Threshold_isku2iufnm , & rtP .
Integrator_IC_i2crhtqu0w [ 0 ] , & rtP . Integrator1_IC_og2211l4hi [ 0 ] , &
rtP . Integrator_IC_kjcjwivfdd [ 0 ] , & rtP . Integrator1_IC_bfgbvvrang [ 0
] , & rtP . Integrator_IC_ow1ezrd30j [ 0 ] , & rtP .
Integrator1_IC_l4ui1a44g1 [ 0 ] , & rtP . Integrator_IC_i3pypvjz4s [ 0 ] , &
rtP . Integrator1_IC_lyrbs4mryj [ 0 ] , & rtP . B [ 0 ] , & rtP . BBT_inv [ 0
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
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 89 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 115 , rtModelParameters , 24 } ,
{ ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 2903976693U
, 1265714942U , 460222312U , 547042216U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * AMFC_Quad_New_01_VelEst_09_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void AMFC_Quad_New_01_VelEst_09_InitializeDataMapInfo ( void ) {
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
void AMFC_Quad_New_01_VelEst_09_host_InitializeDataMapInfo (
AMFC_Quad_New_01_VelEst_09_host_DataMapInfo_T * dataMap , const char * path )
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
