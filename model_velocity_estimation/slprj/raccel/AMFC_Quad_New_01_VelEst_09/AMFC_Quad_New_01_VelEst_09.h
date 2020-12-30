#include "__cf_AMFC_Quad_New_01_VelEst_09.h"
#ifndef RTW_HEADER_AMFC_Quad_New_01_VelEst_09_h_
#define RTW_HEADER_AMFC_Quad_New_01_VelEst_09_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "rtw_modelmap.h"
#ifndef AMFC_Quad_New_01_VelEst_09_COMMON_INCLUDES_
#define AMFC_Quad_New_01_VelEst_09_COMMON_INCLUDES_
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
#include "AMFC_Quad_New_01_VelEst_09_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME AMFC_Quad_New_01_VelEst_09
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (89) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (424)   
#elif NCSTATES != 424
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
typedef struct { real_T ispj2sto2a ; real_T a3fw5udt1f [ 3 ] ; } kdy3j1zqh4 ;
typedef struct { real_T h4nyij0txf [ 4 ] ; } iasl3yiitj ; typedef struct {
real_T g3f2ipoicp [ 36 ] ; } kulrpdeeos ; typedef struct { real_T bkxow1zaxw
[ 6 ] ; } jfvupiqhd2 ; typedef struct { real_T c0eitivnzv [ 6 ] ; }
n4lulc2jbj ; typedef struct { real_T llum1d4imd [ 6 ] ; } e4oqpa2van ;
typedef struct { real_T agvkxpaya3 [ 36 ] ; } l5vwpehasg ; typedef struct {
real_T dy01b2bgnp [ 6 ] ; } h4gxvsmp2l ; typedef struct { real_T b5v3smwxxf [
6 ] ; real_T nbc5e1aa4y [ 6 ] ; real_T kncnn35ehq [ 6 ] ; } pz5kvzziwe ;
typedef struct { real_T bscgwtwcot [ 6 ] ; real_T idzmiix4px [ 6 ] ; real_T
hjeyr5gjr3 [ 6 ] ; } kjumluinue ; typedef struct { real_T o5vw3qgp1n [ 12 ] ;
} ppugmfy3jk ; typedef struct { real_T hfqvj0omua ; } ahvsyvuicz ; typedef
struct { real_T pccs3jrnen ; } l3mc1mdu0x ; typedef struct { real_T
ivgrkuetfr [ 12 ] ; real_T jx10qz0y32 ; real_T mgwl4qchuz ; real_T g4uzmogaho
; real_T iolwo3nnoi [ 3 ] ; real_T etvvsvbtr0 [ 12 ] ; real_T fp1jf5ytc0 [ 2
] ; real_T lxmuzwnnxk [ 12 ] ; real_T cn0dzpfmb5 [ 2 ] ; real_T dlk22jmuti [
2 ] ; real_T f5ibyqhnm5 [ 2 ] ; real_T ofqfdlsgnm [ 6 ] ; real_T ozsyjbt0zf [
6 ] ; real_T l2okftp1nu ; real_T jfhxiyyt2e ; real_T m45fkguer0 ; real_T
hzr1dfuf5l ; real_T m3xmkbwv00 ; real_T bzd1lyzgz1 ; real_T lgrmzrtnoa ;
real_T nnr1ahifvl ; real_T ndl3k25chw [ 3 ] ; real_T gslpjnsh5g [ 2 ] ;
real_T fb2enyqb0z [ 2 ] ; real_T f5j3k1cgkz ; real_T ejv5n5dh4j ; real_T
gol00soltl ; real_T edxclkusat [ 3 ] ; real_T bu5fouv53z [ 6 ] ; real_T
ftcjn2x21e [ 6 ] ; real_T e2xua1vi2a ; real_T h1dldewdlg ; real_T e43dgc14sk
; real_T kryicu302t ; real_T jz5340fyqc ; real_T mztx0ubroi ; real_T
o3szt5ur1k ; real_T c3o3xjf5wt [ 2 ] ; real_T liy3ccyuzf [ 2 ] ; real_T
nof2skbwsq [ 12 ] ; real_T pc3poziqbx ; ppugmfy3jk hqeceb1qj5 ; kjumluinue
hc5s13aofb ; h4gxvsmp2l iz2vhx1had ; e4oqpa2van fch5gmq0mk ; n4lulc2jbj
m4nweffg3k ; jfvupiqhd2 lqm3tkmrj0 ; kulrpdeeos drmxackmon ; l5vwpehasg
evmbjc0b4d ; pz5kvzziwe ddjji0axxh ; h4gxvsmp2l dbfm2fggcf ; l5vwpehasg
n5z0v3jy3r ; e4oqpa2van dwgomjumxz ; n4lulc2jbj dwyanlti1g ; jfvupiqhd2
kblwc120uj ; kulrpdeeos cnusct4inu ; iasl3yiitj crvoapndv2 ; kdy3j1zqh4
esmlujbtbz ; l3mc1mdu0x p4ycag1e5s ; ahvsyvuicz bmakjzspmx ; l3mc1mdu0x
ghv0odgskz ; ahvsyvuicz kscttm531o ; ppugmfy3jk oxu2odnx00 ; kjumluinue
ne34mblrux ; h4gxvsmp2l imeubyypoc ; e4oqpa2van lfdnfksqrv ; n4lulc2jbj
pmwvgwx3i3 ; jfvupiqhd2 kwzvd2zz43 ; kulrpdeeos o3xr450ufq ; l5vwpehasg
porpvvdkpb ; pz5kvzziwe pcmu2rnoht ; h4gxvsmp2l lfuuj0xy5s ; l5vwpehasg
duudknct5v ; e4oqpa2van gxc0uqkvgw ; n4lulc2jbj kwvmxh0kpo ; jfvupiqhd2
ccm3czt3ct ; kulrpdeeos himcwdjdya ; iasl3yiitj opcrukpa55 ; kdy3j1zqh4
jqsclsqnve ; } B ; typedef struct { real_T ksudpu4fau [ 6 ] ; real_T
knl5mpgsrd [ 6 ] ; real_T g0rrq0apzs [ 12 ] ; real_T aauqgom500 [ 12 ] ;
real_T hkoqfk3gpr [ 6 ] ; real_T l3xxd05qkk [ 6 ] ; struct { real_T
modelTStart ; } jy3xilpi33 ; struct { real_T modelTStart ; } nwftmqpxni ;
struct { real_T modelTStart ; } ftfqvcynyd ; struct { real_T modelTStart ; }
b1ge0hee1v ; struct { real_T modelTStart ; } b50ygqfxun ; struct { real_T
modelTStart ; } dkp2gvli2p ; struct { void * LoggedData ; } eh14jxkpry ;
struct { void * TUbufferPtrs [ 2 ] ; } ftwma3npp0 ; struct { void *
TUbufferPtrs [ 2 ] ; } emkvxxu5kw ; struct { void * TUbufferPtrs [ 2 ] ; }
ikb4keconr ; struct { void * LoggedData ; } jhpavj442h ; struct { void *
LoggedData ; } idznnk4ivb ; struct { void * LoggedData ; } dbrb4job1l ;
struct { void * LoggedData ; } pw1fr2aeqv ; struct { void * LoggedData ; }
jon4oo2kgm ; struct { void * LoggedData ; } bpfscmb3y2 ; struct { void *
LoggedData ; } d2eq1qne2f ; struct { void * LoggedData ; } j3huo2xvys ;
struct { void * LoggedData ; } p4sgzkj20f ; struct { void * LoggedData ; }
dvrntr3mzm ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} pvuv30ujfg ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } df5c2nfbgg ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } n1ay2gmo0o ; struct { void * TimePtr ; void * DataPtr ; void
* RSimInfoPtr ; } pjpkrcvyhb ; struct { void * LoggedData [ 3 ] ; }
g4djpfw4yq ; struct { void * LoggedData [ 2 ] ; } kwz4psqkit ; struct { void
* LoggedData ; } eu2d5e54n4 ; struct { void * LoggedData ; } nvpfdb2hmo ;
struct { void * LoggedData ; } earmeghfsf ; struct { void * LoggedData ; }
bb1yh35qnp ; struct { void * LoggedData ; } l4liyn0zrr ; struct { void *
LoggedData ; } hjrvfzz0ar ; struct { void * LoggedData ; } ekl3igs5tb ;
struct { void * LoggedData ; } o3rktodv2z ; struct { void * LoggedData [ 2 ]
; } o1d2fjrwn1 ; struct { void * TUbufferPtrs [ 2 ] ; } fzezo0tjjd ; struct {
void * TUbufferPtrs [ 2 ] ; } nashv3gsf0 ; struct { void * TUbufferPtrs [ 2 ]
; } lwvvduadv2 ; struct { void * LoggedData ; } pskx1pep5n ; struct { void *
LoggedData ; } jozpq0htbq ; struct { void * LoggedData ; } msfllwrq11 ;
struct { void * LoggedData ; } lkmyovzpp0 ; struct { void * LoggedData ; }
l2kwb1e0rl ; struct { void * LoggedData ; } fntjtmi5ec ; struct { void *
LoggedData ; } j2g15onptf ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } gq3i5ctc0q ; struct { void * TimePtr ; void * DataPtr ; void
* RSimInfoPtr ; } lp5ova0wqa ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } b2wnsubu1l ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } lxjlqbqfhh ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } fsebzkjcav ; int_T hn2dovhdxs [ 2 ]
; int_T ldylaj45rj ; struct { int_T PrevIndex ; } edcbzf0yn0 ; struct { int_T
PrevIndex ; } pnnerq5f2i ; struct { int_T PrevIndex ; } exnemuedsi ; struct {
int_T PrevIndex ; } ayaahgomzc ; struct { int_T Tail ; int_T Head ; int_T
Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } autydayctb ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } cctjnquf0p ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } npknkce1d5 ; int_T
kaqmnwj2wn [ 2 ] ; int_T gytwfjza2q ; struct { int_T PrevIndex ; } awfq5ek0fh
; struct { int_T PrevIndex ; } frrqi3axqr ; boolean_T ata4d5ulcr ; boolean_T
c3h4wxu1yg ; } DW ; typedef struct { real_T abatslrpwk [ 12 ] ; real_T
hdexuidcnz [ 2 ] ; real_T egpyww1cv3 [ 12 ] ; real_T asa03nz13i [ 2 ] ;
real_T jrqisqyvic ; real_T dydxhc42vx ; real_T homekiakrv [ 6 ] ; real_T
kr4xkk5p2d [ 6 ] ; real_T p2h3nxwrp4 [ 6 ] ; real_T oek5xqhibl [ 36 ] ;
real_T nvdaad4uoo [ 36 ] ; real_T ddja0xcub2 [ 6 ] ; real_T omm0cczmsf [ 6 ]
; real_T jwhqqfdfph [ 6 ] ; real_T gbuoa3kpzy [ 6 ] ; real_T jgzdfwki50 [ 36
] ; real_T b40vzf5iri [ 36 ] ; real_T kddg05jdkv [ 6 ] ; real_T mleszyt3ph ;
real_T pqfuc02dbp ; real_T hprn5xyvyd ; real_T pcbcrzvlqc ; real_T imqeuuioz0
; real_T f21hx01p2a ; real_T a0rpvvfbdg [ 6 ] ; real_T ihuse34h2m [ 6 ] ;
real_T gh1xa20c4q [ 6 ] ; real_T bqotilpnhf [ 36 ] ; real_T cndsbhy3yw [ 36 ]
; real_T leuxkrpbqz [ 6 ] ; real_T nzsjppno45 [ 6 ] ; real_T afi4gqi4rj [ 6 ]
; real_T bwrj1l0x0q [ 6 ] ; real_T ibhve1q3yt [ 36 ] ; real_T kfyvmtxfyr [ 36
] ; real_T e3hflsxbnx [ 6 ] ; real_T pojcnbxabt ; real_T ngpl5i0ij4 ; real_T
iqx41iju4f ; real_T lszq1tgyze ; } X ; typedef struct { real_T abatslrpwk [
12 ] ; real_T hdexuidcnz [ 2 ] ; real_T egpyww1cv3 [ 12 ] ; real_T asa03nz13i
[ 2 ] ; real_T jrqisqyvic ; real_T dydxhc42vx ; real_T homekiakrv [ 6 ] ;
real_T kr4xkk5p2d [ 6 ] ; real_T p2h3nxwrp4 [ 6 ] ; real_T oek5xqhibl [ 36 ]
; real_T nvdaad4uoo [ 36 ] ; real_T ddja0xcub2 [ 6 ] ; real_T omm0cczmsf [ 6
] ; real_T jwhqqfdfph [ 6 ] ; real_T gbuoa3kpzy [ 6 ] ; real_T jgzdfwki50 [
36 ] ; real_T b40vzf5iri [ 36 ] ; real_T kddg05jdkv [ 6 ] ; real_T mleszyt3ph
; real_T pqfuc02dbp ; real_T hprn5xyvyd ; real_T pcbcrzvlqc ; real_T
imqeuuioz0 ; real_T f21hx01p2a ; real_T a0rpvvfbdg [ 6 ] ; real_T ihuse34h2m
[ 6 ] ; real_T gh1xa20c4q [ 6 ] ; real_T bqotilpnhf [ 36 ] ; real_T
cndsbhy3yw [ 36 ] ; real_T leuxkrpbqz [ 6 ] ; real_T nzsjppno45 [ 6 ] ;
real_T afi4gqi4rj [ 6 ] ; real_T bwrj1l0x0q [ 6 ] ; real_T ibhve1q3yt [ 36 ]
; real_T kfyvmtxfyr [ 36 ] ; real_T e3hflsxbnx [ 6 ] ; real_T pojcnbxabt ;
real_T ngpl5i0ij4 ; real_T iqx41iju4f ; real_T lszq1tgyze ; } XDot ; typedef
struct { boolean_T abatslrpwk [ 12 ] ; boolean_T hdexuidcnz [ 2 ] ; boolean_T
egpyww1cv3 [ 12 ] ; boolean_T asa03nz13i [ 2 ] ; boolean_T jrqisqyvic ;
boolean_T dydxhc42vx ; boolean_T homekiakrv [ 6 ] ; boolean_T kr4xkk5p2d [ 6
] ; boolean_T p2h3nxwrp4 [ 6 ] ; boolean_T oek5xqhibl [ 36 ] ; boolean_T
nvdaad4uoo [ 36 ] ; boolean_T ddja0xcub2 [ 6 ] ; boolean_T omm0cczmsf [ 6 ] ;
boolean_T jwhqqfdfph [ 6 ] ; boolean_T gbuoa3kpzy [ 6 ] ; boolean_T
jgzdfwki50 [ 36 ] ; boolean_T b40vzf5iri [ 36 ] ; boolean_T kddg05jdkv [ 6 ]
; boolean_T mleszyt3ph ; boolean_T pqfuc02dbp ; boolean_T hprn5xyvyd ;
boolean_T pcbcrzvlqc ; boolean_T imqeuuioz0 ; boolean_T f21hx01p2a ;
boolean_T a0rpvvfbdg [ 6 ] ; boolean_T ihuse34h2m [ 6 ] ; boolean_T
gh1xa20c4q [ 6 ] ; boolean_T bqotilpnhf [ 36 ] ; boolean_T cndsbhy3yw [ 36 ]
; boolean_T leuxkrpbqz [ 6 ] ; boolean_T nzsjppno45 [ 6 ] ; boolean_T
afi4gqi4rj [ 6 ] ; boolean_T bwrj1l0x0q [ 6 ] ; boolean_T ibhve1q3yt [ 36 ] ;
boolean_T kfyvmtxfyr [ 36 ] ; boolean_T e3hflsxbnx [ 6 ] ; boolean_T
pojcnbxabt ; boolean_T ngpl5i0ij4 ; boolean_T iqx41iju4f ; boolean_T
lszq1tgyze ; } XDis ; typedef struct { real_T abatslrpwk [ 12 ] ; real_T
hdexuidcnz [ 2 ] ; real_T egpyww1cv3 [ 12 ] ; real_T asa03nz13i [ 2 ] ;
real_T jrqisqyvic ; real_T dydxhc42vx ; real_T homekiakrv [ 6 ] ; real_T
kr4xkk5p2d [ 6 ] ; real_T p2h3nxwrp4 [ 6 ] ; real_T oek5xqhibl [ 36 ] ;
real_T nvdaad4uoo [ 36 ] ; real_T ddja0xcub2 [ 6 ] ; real_T omm0cczmsf [ 6 ]
; real_T jwhqqfdfph [ 6 ] ; real_T gbuoa3kpzy [ 6 ] ; real_T jgzdfwki50 [ 36
] ; real_T b40vzf5iri [ 36 ] ; real_T kddg05jdkv [ 6 ] ; real_T mleszyt3ph ;
real_T pqfuc02dbp ; real_T hprn5xyvyd ; real_T pcbcrzvlqc ; real_T imqeuuioz0
; real_T f21hx01p2a ; real_T a0rpvvfbdg [ 6 ] ; real_T ihuse34h2m [ 6 ] ;
real_T gh1xa20c4q [ 6 ] ; real_T bqotilpnhf [ 36 ] ; real_T cndsbhy3yw [ 36 ]
; real_T leuxkrpbqz [ 6 ] ; real_T nzsjppno45 [ 6 ] ; real_T afi4gqi4rj [ 6 ]
; real_T bwrj1l0x0q [ 6 ] ; real_T ibhve1q3yt [ 36 ] ; real_T kfyvmtxfyr [ 36
] ; real_T e3hflsxbnx [ 6 ] ; real_T pojcnbxabt ; real_T ngpl5i0ij4 ; real_T
iqx41iju4f ; real_T lszq1tgyze ; } CStateAbsTol ; typedef struct { real_T
pkwvzyrmwh ; real_T dedxn5i5eo ; real_T ilvi0y3uv1 ; real_T c1b3jziwcm ; }
ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T B [ 36 ] ; real_T BBT_inv [ 36 ] ; real_T J [ 9 ] ; real_T Ka ;
real_T Kd ; real_T Kf ; real_T Kt ; real_T L ; real_T M ; real_T Q [ 36 ] ;
real_T R [ 36 ] ; real_T RM_1 [ 16 ] ; real_T alpha_P ; real_T alpha_Slid ;
real_T alpha_V ; real_T gamma_0 [ 36 ] ; real_T gamma_1 [ 36 ] ; real_T ge ;
real_T k1 ; real_T k1o ; real_T k2 ; real_T k2o ; real_T rho_0 ; real_T rho_1
; real_T Gain2_Gain ; real_T Gain2_Gain_c2uyk0coml ; real_T Integrator_IC [
12 ] ; real_T TransportDelay_Delay ; real_T TransportDelay_InitOutput ;
real_T TransportDelay1_Delay ; real_T TransportDelay1_InitOutput ; real_T
TransportDelay2_Delay ; real_T TransportDelay2_InitOutput ; real_T
Integrator2_IC [ 2 ] ; real_T Integrator_IC_au2dj45vgj [ 12 ] ; real_T
Integrator1_IC [ 2 ] ; real_T Integrator_IC_bzpo215sgo ; real_T
Integrator1_IC_kniptj1kxt ; real_T Gain_Gain ; real_T Integrator3_IC [ 6 ] ;
real_T Memory_InitialCondition [ 6 ] ; real_T Integrator_IC_kjcjwivfdd [ 6 ]
; real_T Integrator1_IC_bfgbvvrang [ 6 ] ; real_T Integrator1_IC_etk5iarzoa [
36 ] ; real_T Integrator_IC_d53cezkjnk [ 36 ] ; real_T
Integrator2_IC_milw2qy4e1 [ 6 ] ; real_T Integrator3_IC_mvcbk0lpqx [ 6 ] ;
real_T Memory_InitialCondition_ltjalipc0r [ 6 ] ; real_T
Integrator_IC_i2crhtqu0w [ 6 ] ; real_T Integrator1_IC_og2211l4hi [ 6 ] ;
real_T Integrator1_IC_ea4j2itlpr [ 36 ] ; real_T Integrator_IC_lijhdzhcao [
36 ] ; real_T Integrator2_IC_eshmddcula [ 6 ] ; real_T
Memory_InitialCondition_cltcggngaa [ 12 ] ; real_T Gain_Gain_pqv5poqtm5 ;
real_T SineWave_Amp ; real_T SineWave_Bias ; real_T SineWave_Freq ; real_T
SineWave_Phase ; real_T SineWave1_Amp ; real_T SineWave1_Bias ; real_T
SineWave1_Freq ; real_T SineWave1_Phase ; real_T Constant_Value ; real_T
TransferFcn2_A ; real_T TransferFcn2_C ; real_T Constant1_Value ; real_T
TransferFcn3_A ; real_T TransferFcn3_C ; real_T Constant2_Value ; real_T
TransferFcn1_A ; real_T TransferFcn1_C ; real_T FromWs_Time0 [ 6 ] ; real_T
FromWs_Data0 [ 6 ] ; real_T TransferFcn_A ; real_T TransferFcn_C ; real_T
FromWorkspace_Time0 [ 601 ] ; real_T FromWorkspace_Data0 [ 601 ] ; real_T
Gain_Gain_bttrwertaz ; real_T FromWorkspace1_Time0 [ 601 ] ; real_T
FromWorkspace1_Data0 [ 601 ] ; real_T Gain1_Gain ; real_T
FromWorkspace3_Time0 [ 601 ] ; real_T FromWorkspace3_Data0 [ 601 ] ; real_T
DesiredPosition4_Value ; real_T Switch_Threshold ; real_T
Memory_InitialCondition_ihnyqfqp54 ; real_T Integrator1_IC_cysw5lmkvd ;
real_T Gain_Gain_mauqb2akec ; real_T Integrator_IC_mdtcnu4jbd ; real_T
TransportDelay_Delay_mrtq4yly2u ; real_T TransportDelay_InitOutput_bw2s5ogtcl
; real_T Gain1_Gain_lwvfyvhuab ; real_T TransportDelay1_Delay_l2osw0ocdi ;
real_T TransportDelay1_InitOutput_ctmwtl3hbr ; real_T Gain2_Gain_gy0kebd21j ;
real_T TransportDelay2_Delay_dxj4qf2s24 ; real_T
TransportDelay2_InitOutput_ddz2iqhful ; real_T Gain3_Gain ; real_T
Integrator3_IC_nyxzwevmz0 [ 6 ] ; real_T Memory_InitialCondition_ogj5j113sv [
6 ] ; real_T Integrator_IC_i3pypvjz4s [ 6 ] ; real_T
Integrator1_IC_lyrbs4mryj [ 6 ] ; real_T Integrator1_IC_aondaic4tn [ 36 ] ;
real_T Integrator_IC_dn1v3y4i5t [ 36 ] ; real_T Integrator2_IC_eq0rr2lar5 [ 6
] ; real_T Integrator3_IC_oqmkotgcvb [ 6 ] ; real_T
Memory_InitialCondition_dew5rdr00k [ 6 ] ; real_T Integrator_IC_ow1ezrd30j [
6 ] ; real_T Integrator1_IC_l4ui1a44g1 [ 6 ] ; real_T
Integrator1_IC_dwmkl32mdn [ 36 ] ; real_T Integrator_IC_puc2fkypqe [ 36 ] ;
real_T Integrator2_IC_pkgbdnqjyc [ 6 ] ; real_T Gain_Gain_pjv0l5nu25 ; real_T
SineWave_Amp_cqusaijwz1 ; real_T SineWave_Bias_dhkcw5madh ; real_T
SineWave_Freq_hkeiim1l54 ; real_T SineWave_Phase_atfet5pyf2 ; real_T
SineWave1_Amp_mdrsfgbaur ; real_T SineWave1_Bias_eubjrqq2u4 ; real_T
SineWave1_Freq_ekxuh2oqwg ; real_T SineWave1_Phase_pvy3avqa4x ; real_T
Constant_Value_f3fl4m3lns ; real_T TransferFcn2_A_a0oyqusjcz ; real_T
TransferFcn2_C_dmkbndw1jb ; real_T Constant1_Value_bfcgyn3zal ; real_T
TransferFcn3_A_luwp2lluol ; real_T TransferFcn3_C_bgvnqgidnw ; real_T
Constant2_Value_imre1apqn2 ; real_T TransferFcn1_A_bowexjz0op ; real_T
TransferFcn1_C_gbzdyi5fsz ; real_T FromWs_Time0_dvongqu3oc [ 6 ] ; real_T
FromWs_Data0_bk0ugsj5dc [ 6 ] ; real_T TransferFcn_A_opc1nfp3z4 ; real_T
TransferFcn_C_etz5z3jsj3 ; real_T DesiredPosition4_Value_izm2550djd ; real_T
FromWorkspace3_Time0_arirwmivf2 [ 601 ] ; real_T
FromWorkspace3_Data0_glaft0xfxw [ 601 ] ; real_T Switch_Threshold_isku2iufnm
; } ; extern const real_T AMFC_Quad_New_01_VelEst_09_RGND ; extern const char
* RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
AMFC_Quad_New_01_VelEst_09_GetCAPIStaticMap ( void ) ; extern SimStruct *
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
