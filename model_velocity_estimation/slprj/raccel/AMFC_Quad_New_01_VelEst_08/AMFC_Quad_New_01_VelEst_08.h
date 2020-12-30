#include "__cf_AMFC_Quad_New_01_VelEst_08.h"
#ifndef RTW_HEADER_AMFC_Quad_New_01_VelEst_08_h_
#define RTW_HEADER_AMFC_Quad_New_01_VelEst_08_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "rtw_modelmap.h"
#ifndef AMFC_Quad_New_01_VelEst_08_COMMON_INCLUDES_
#define AMFC_Quad_New_01_VelEst_08_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "AMFC_Quad_New_01_VelEst_08_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME AMFC_Quad_New_01_VelEst_08
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (63) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (216)   
#elif NCSTATES != 216
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T cxgasfu34l [ 36 ] ; } o1slwgqdlm ; typedef struct {
real_T ao4ocy3oo3 [ 6 ] ; } fwylrlcfrr ; typedef struct { real_T oaqi4nmegi [
6 ] ; } lthd11jgkt ; typedef struct { real_T n54ymdd4p0 [ 6 ] ; } db1uh4mzfc
; typedef struct { real_T ejjucyteji [ 36 ] ; } na51yrjijx ; typedef struct {
real_T jb4t0dt15b [ 6 ] ; } bzqp5lmsxs ; typedef struct { real_T gydza50f0o ;
} fkz4aojsrd ; typedef struct { real_T h0xntzw5zb ; } bzcun1m1ez ; typedef
struct { real_T f3qdvlncs2 [ 12 ] ; real_T cvaerauj1g ; real_T luue0kfi2i ;
real_T cp0haf23uy ; real_T out1onmc3n [ 3 ] ; real_T iyrr00rsy5 [ 6 ] ;
real_T dhldqomrw2 [ 12 ] ; real_T jgeak2pmpa [ 2 ] ; real_T fkn5pxjywf [ 2 ]
; real_T eja0y2gles [ 6 ] ; real_T ncyc1gpaj2 [ 6 ] ; real_T mqwm4nfdap [ 6 ]
; real_T pnzkimrl2h [ 36 ] ; real_T fjffiex4ix [ 36 ] ; real_T c05vhcs2pf [ 6
] ; real_T m2sfecaklo [ 6 ] ; real_T oidskutggb [ 6 ] ; real_T o2eyjfo1wi [ 6
] ; real_T m0blghypsp [ 6 ] ; real_T es2yapuiac [ 36 ] ; real_T ix2okivzvw [
36 ] ; real_T mghhh4y54x [ 6 ] ; real_T hut5rsdm1t ; real_T db0sdie5cx ;
real_T olp0aypydn ; real_T hdwtb14kjv ; real_T h0vfo44bet ; real_T apsqtgdw2k
; real_T niozx0x3bq ; real_T bzt0lwzvse ; real_T hrymkwe4oo [ 3 ] ; real_T
a2l3vjk5kk [ 2 ] ; real_T bslv0j5s21 [ 2 ] ; real_T dlysorqgi3 ; real_T
ab5rfxknmw [ 2 ] ; real_T lipu0dbc2k [ 2 ] ; real_T mhmxoetwje ; real_T
jdqmorg3jr [ 12 ] ; real_T j5d2rfynpz [ 6 ] ; real_T bgofqzyuag [ 6 ] ;
real_T hyspkccycp [ 6 ] ; real_T fgqxwi1chj [ 6 ] ; real_T fz3gjqjow4 [ 6 ] ;
real_T b4h3ks3r0d [ 6 ] ; real_T oflhugxayb [ 4 ] ; real_T it5y34mzxt ;
real_T ksdh1okcet [ 3 ] ; bzcun1m1ez hpraryzlaj ; fkz4aojsrd j2zidd3tqj ;
bzcun1m1ez eg12osul0v ; fkz4aojsrd feorxccqpz ; bzqp5lmsxs lxb4grs0ty ;
db1uh4mzfc ca4s31r1o4 ; lthd11jgkt pg0yucqphr ; fwylrlcfrr cvltowsf2b ;
o1slwgqdlm ffhxpulbso ; na51yrjijx ipiqttfm4x ; bzqp5lmsxs l1rejasabs ;
na51yrjijx cwezlbfqfz ; db1uh4mzfc n11qfveosl ; lthd11jgkt jrhbb2xk4n ;
fwylrlcfrr paq4dzeup4 ; o1slwgqdlm jr4hvs211j ; } B ; typedef struct { real_T
lh1jhunvsh [ 6 ] ; real_T ekrugbtxsn [ 6 ] ; real_T iuen2h2uzw [ 12 ] ;
struct { real_T modelTStart ; } gp01wmmidy ; struct { real_T modelTStart ; }
kdwpr03ybd ; struct { real_T modelTStart ; } pmxp5qek5h ; struct { void *
LoggedData ; } l4oivvvvyz ; struct { void * LoggedData ; } jzvi34rmlr ;
struct { void * TUbufferPtrs [ 2 ] ; } ascbhwveph ; struct { void *
TUbufferPtrs [ 2 ] ; } m5ovno0zss ; struct { void * TUbufferPtrs [ 2 ] ; }
dx5bxpzipw ; struct { void * LoggedData ; } ah4xxhij4f ; struct { void *
LoggedData ; } hklofzqmuc ; struct { void * LoggedData ; } kie23jbppm ;
struct { void * LoggedData ; } p1ppyahmgi ; struct { void * LoggedData ; }
d310uncg1y ; struct { void * LoggedData [ 2 ] ; } jo3cx5bohy ; struct { void
* LoggedData ; } nmdc4rqnwf ; struct { void * LoggedData ; } gqqn5cu3v3 ;
struct { void * LoggedData ; } fpcaxygowv ; struct { void * LoggedData ; }
j3rkq32ahw ; struct { void * LoggedData ; } ecce2dvsos ; struct { void *
LoggedData ; } j1o5yxgppi ; struct { void * LoggedData ; } pwowgrrppn ;
struct { void * LoggedData ; } ninuxp2rok ; struct { void * LoggedData ; }
gcoy2nk0hc ; struct { void * LoggedData ; } kbvzsvjrbk ; struct { void *
LoggedData ; } d0yl2k2gt3 ; struct { void * LoggedData ; } jvk5wijwro ;
struct { void * LoggedData ; } c4oxhjn4wm ; struct { void * LoggedData ; }
jqjrqjyjli ; struct { void * LoggedData ; } aa5gpmhc3a ; struct { void *
LoggedData ; } lvqguxuqdr ; struct { void * LoggedData ; } o5lhljo4nd ;
struct { void * LoggedData ; } hla0xdzqni ; struct { void * LoggedData ; }
boirfqbbsy ; struct { void * LoggedData ; } dtaltrldf4 ; struct { void *
LoggedData ; } cdnjpny0g4 ; struct { void * LoggedData ; } fo3urnu55t ;
struct { void * LoggedData ; } ebj5iepbj5 ; struct { void * LoggedData ; }
di2sxodqb0 ; struct { void * LoggedData ; } eux4lj2epg ; struct { void *
LoggedData ; } iw2kvox1xe ; struct { void * LoggedData ; } i4u5v5s0km ;
struct { void * LoggedData ; } pju1hy2pt4 ; struct { void * LoggedData ; }
emqqixgbtf ; struct { void * LoggedData ; } oxyc14cgy1 ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } czs5ji1vj4 ; struct { void
* TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } gcdvojgmqy ; struct {
void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } nlbag1a2v1 ; struct
{ void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } k4aipb3zed ;
struct { void * LoggedData [ 3 ] ; } k2xhaupeb3 ; struct { void * LoggedData
[ 2 ] ; } pdea4rxbko ; struct { void * LoggedData ; } dxomvattco ; struct {
void * LoggedData ; } ppz3sujyuc ; struct { void * LoggedData ; } epkhmc0w1c
; struct { void * LoggedData ; } ebulbgz34l ; struct { void * LoggedData ; }
k5k0a3kpu3 ; struct { void * LoggedData ; } oyuwqi1alg ; struct { void *
LoggedData [ 2 ] ; } d1paqxnris ; struct { int_T Tail ; int_T Head ; int_T
Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } pnp5xqshxz ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } d2lrwdgt4h ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } cfbh3wuutq ; int_T
bpo0twltjm [ 2 ] ; int_T mplujf0x0c ; struct { int_T PrevIndex ; } phrp5iu5sk
; struct { int_T PrevIndex ; } cmi14xe5ec ; struct { int_T PrevIndex ; }
m5jz3vy2cr ; struct { int_T PrevIndex ; } k20gh5ioaa ; boolean_T jfw2terd0g ;
} DW ; typedef struct { real_T jod1emscae [ 12 ] ; real_T p4zavbehwu [ 6 ] ;
real_T h0zdgk0gmo [ 2 ] ; real_T d4nsqahaas [ 2 ] ; real_T dtrsdauv2w ;
real_T mba3iviq3e ; real_T k4rm2q2icw [ 6 ] ; real_T kymqljywk0 [ 6 ] ;
real_T mcdw1mvklq [ 36 ] ; real_T mzqqw2gt2r [ 36 ] ; real_T ilympk0to1 [ 6 ]
; real_T kuge0cvnkg [ 6 ] ; real_T fqjvdv4ykq [ 6 ] ; real_T nmmu3qxl0s [ 6 ]
; real_T hlskz0axkk [ 36 ] ; real_T mvnt0cytdi [ 36 ] ; real_T nsega0fhex [ 6
] ; real_T ec4fcf3fdu ; real_T o14hhuay2v ; real_T hwaaltmfd1 ; real_T
o2isawjn1o ; real_T lgendzn5vu ; real_T libflrt1jq ; } X ; typedef struct {
real_T jod1emscae [ 12 ] ; real_T p4zavbehwu [ 6 ] ; real_T h0zdgk0gmo [ 2 ]
; real_T d4nsqahaas [ 2 ] ; real_T dtrsdauv2w ; real_T mba3iviq3e ; real_T
k4rm2q2icw [ 6 ] ; real_T kymqljywk0 [ 6 ] ; real_T mcdw1mvklq [ 36 ] ;
real_T mzqqw2gt2r [ 36 ] ; real_T ilympk0to1 [ 6 ] ; real_T kuge0cvnkg [ 6 ]
; real_T fqjvdv4ykq [ 6 ] ; real_T nmmu3qxl0s [ 6 ] ; real_T hlskz0axkk [ 36
] ; real_T mvnt0cytdi [ 36 ] ; real_T nsega0fhex [ 6 ] ; real_T ec4fcf3fdu ;
real_T o14hhuay2v ; real_T hwaaltmfd1 ; real_T o2isawjn1o ; real_T lgendzn5vu
; real_T libflrt1jq ; } XDot ; typedef struct { boolean_T jod1emscae [ 12 ] ;
boolean_T p4zavbehwu [ 6 ] ; boolean_T h0zdgk0gmo [ 2 ] ; boolean_T
d4nsqahaas [ 2 ] ; boolean_T dtrsdauv2w ; boolean_T mba3iviq3e ; boolean_T
k4rm2q2icw [ 6 ] ; boolean_T kymqljywk0 [ 6 ] ; boolean_T mcdw1mvklq [ 36 ] ;
boolean_T mzqqw2gt2r [ 36 ] ; boolean_T ilympk0to1 [ 6 ] ; boolean_T
kuge0cvnkg [ 6 ] ; boolean_T fqjvdv4ykq [ 6 ] ; boolean_T nmmu3qxl0s [ 6 ] ;
boolean_T hlskz0axkk [ 36 ] ; boolean_T mvnt0cytdi [ 36 ] ; boolean_T
nsega0fhex [ 6 ] ; boolean_T ec4fcf3fdu ; boolean_T o14hhuay2v ; boolean_T
hwaaltmfd1 ; boolean_T o2isawjn1o ; boolean_T lgendzn5vu ; boolean_T
libflrt1jq ; } XDis ; typedef struct { real_T jod1emscae [ 12 ] ; real_T
p4zavbehwu [ 6 ] ; real_T h0zdgk0gmo [ 2 ] ; real_T d4nsqahaas [ 2 ] ; real_T
dtrsdauv2w ; real_T mba3iviq3e ; real_T k4rm2q2icw [ 6 ] ; real_T kymqljywk0
[ 6 ] ; real_T mcdw1mvklq [ 36 ] ; real_T mzqqw2gt2r [ 36 ] ; real_T
ilympk0to1 [ 6 ] ; real_T kuge0cvnkg [ 6 ] ; real_T fqjvdv4ykq [ 6 ] ; real_T
nmmu3qxl0s [ 6 ] ; real_T hlskz0axkk [ 36 ] ; real_T mvnt0cytdi [ 36 ] ;
real_T nsega0fhex [ 6 ] ; real_T ec4fcf3fdu ; real_T o14hhuay2v ; real_T
hwaaltmfd1 ; real_T o2isawjn1o ; real_T lgendzn5vu ; real_T libflrt1jq ; }
CStateAbsTol ; typedef struct { real_T c5pv2pnafs ; real_T n0sjedb0f3 ; } ZCV
; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T B [ 36 ] ; real_T BBT_inv [ 36 ] ; real_T J [ 9 ] ; real_T Ka ; real_T
Kd ; real_T Kf ; real_T Kt ; real_T L ; real_T M ; real_T Q [ 36 ] ; real_T R
[ 36 ] ; real_T RM_1 [ 16 ] ; real_T alpha_P ; real_T alpha_Slid ; real_T
alpha_V ; real_T gamma_0 [ 36 ] ; real_T gamma_1 [ 36 ] ; real_T ge ; real_T
k1 ; real_T k1o ; real_T k2 ; real_T k2o ; real_T rho_0 ; real_T rho_1 ;
real_T Gain2_Gain ; real_T Integrator_IC [ 12 ] ; real_T TransportDelay_Delay
; real_T TransportDelay_InitOutput ; real_T TransportDelay1_Delay ; real_T
TransportDelay1_InitOutput ; real_T TransportDelay2_Delay ; real_T
TransportDelay2_InitOutput ; real_T Integrator3_IC [ 6 ] ; real_T
Integrator2_IC [ 2 ] ; real_T Integrator1_IC [ 2 ] ; real_T
Integrator_IC_bzpo215sgo ; real_T Integrator1_IC_kniptj1kxt ; real_T
Gain_Gain ; real_T Memory_InitialCondition [ 6 ] ; real_T
Integrator_IC_kjcjwivfdd [ 6 ] ; real_T Integrator1_IC_bfgbvvrang [ 6 ] ;
real_T Integrator1_IC_etk5iarzoa [ 36 ] ; real_T Integrator_IC_d53cezkjnk [
36 ] ; real_T Integrator2_IC_milw2qy4e1 [ 6 ] ; real_T
Integrator3_IC_mvcbk0lpqx [ 6 ] ; real_T Memory_InitialCondition_ltjalipc0r [
6 ] ; real_T Integrator_IC_i2crhtqu0w [ 6 ] ; real_T
Integrator1_IC_og2211l4hi [ 6 ] ; real_T Integrator1_IC_ea4j2itlpr [ 36 ] ;
real_T Integrator_IC_lijhdzhcao [ 36 ] ; real_T Integrator2_IC_eshmddcula [ 6
] ; real_T Memory_InitialCondition_cltcggngaa [ 12 ] ; real_T
Gain_Gain_pqv5poqtm5 ; real_T SineWave_Amp ; real_T SineWave_Bias ; real_T
SineWave_Freq ; real_T SineWave_Phase ; real_T SineWave1_Amp ; real_T
SineWave1_Bias ; real_T SineWave1_Freq ; real_T SineWave1_Phase ; real_T
Constant_Value ; real_T TransferFcn2_A ; real_T TransferFcn2_C ; real_T
Constant1_Value ; real_T TransferFcn3_A ; real_T TransferFcn3_C ; real_T
Constant2_Value ; real_T TransferFcn1_A ; real_T TransferFcn1_C ; real_T
FromWs_Time0 [ 6 ] ; real_T FromWs_Data0 [ 6 ] ; real_T TransferFcn_A ;
real_T TransferFcn_C ; real_T FromWorkspace_Time0 [ 601 ] ; real_T
FromWorkspace_Data0 [ 601 ] ; real_T Gain_Gain_bttrwertaz ; real_T
FromWorkspace1_Time0 [ 601 ] ; real_T FromWorkspace1_Data0 [ 601 ] ; real_T
Gain1_Gain ; real_T FromWorkspace3_Time0 [ 601 ] ; real_T
FromWorkspace3_Data0 [ 601 ] ; real_T DesiredPosition4_Value ; real_T
Switch_Threshold ; real_T Constant2_Value_p1uxhfeofi [ 3 ] ; real_T
Constant1_Value_k0amvdt1or [ 2 ] ; real_T Integrator1_IC_cysw5lmkvd ; real_T
Gain_Gain_mauqb2akec ; real_T Integrator_IC_mdtcnu4jbd ; } ; extern const
real_T AMFC_Quad_New_01_VelEst_08_RGND ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
AMFC_Quad_New_01_VelEst_08_GetCAPIStaticMap ( void ) ; extern SimStruct *
const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern size_t gblCurrentSFcnIdx ;
extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
