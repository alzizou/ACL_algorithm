#include "__cf_Cooperative_Quad_09_VelEst_02.h"
#ifndef RTW_HEADER_Cooperative_Quad_09_VelEst_02_private_h_
#define RTW_HEADER_Cooperative_Quad_09_VelEst_02_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Cooperative_Quad_09_VelEst_02.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) ; real_T rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; void
rt_TDelayFreeBuf ( void * buf ) ; extern void ihouus1chq ( const real_T
anhjewobnm [ 6 ] , bnke3tdprc * localB ) ; extern void g4g4bdu0ia ( real_T
bzsy3edq02 , const real_T fxjmelxcxk [ 6 ] , dbcl0xeupb * localB ) ; extern
void ijextzfzou ( const real_T as0slvcd4k [ 36 ] , const real_T evyixzyx5o [
36 ] , mse3h2ftgz * localB ) ; extern void l3dvuo1xw3 ( const real_T
owlsxfafsf [ 6 ] , const real_T d5hib54nne [ 6 ] , mu1vmeaxft * localB ) ;
extern void lgndixfdt3 ( const real_T al2lunlm4b [ 6 ] , gdb14qhzuk * localB
) ; extern void lvvcxitelq ( const real_T g0eic1btf3 [ 6 ] , const real_T
ogw40qmced [ 6 ] , const real_T ajegbo1ahs [ 36 ] , dtavxwjdhj * localB ) ;
extern void bmxkvlwnui ( const real_T ejplzsu2bn [ 6 ] , const real_T
mj01hqexai [ 6 ] , const real_T em4h4dw5yu [ 36 ] , const real_T bjcozpvrzq [
36 ] , jajski1k0u * localB ) ; extern void jvlvilab4w ( const real_T
oexbw4nvh5 [ 6 ] , const real_T hhxq1jqqm2 [ 6 ] , const real_T omhcrter1d [
6 ] , const real_T gh0mpay5wb [ 36 ] , const real_T hyjceobmbu [ 36 ] , const
real_T cex2mrfzqe [ 6 ] , const real_T kre4ojvqmh [ 6 ] , b2p0222gkg * localB
) ; extern void m1hec3vrd2 ( const real_T aj1sgw205c [ 12 ] , const real_T
ieqyvfjn0s [ 3 ] , const real_T bszzozixyu [ 6 ] , ddr40jvpzk * localB ) ;
extern void d4w44phvgb ( const real_T mllnjppvp0 [ 6 ] , const real_T
dy5fgbbgqm [ 6 ] , kkwsfb1bht * localB ) ; extern void nnvj0nbsr4 ( const
real_T o23ecwi00m [ 12 ] , real_T lkhv0noozn , real_T j1yzquu10j , real_T
alftjmzvnx , const real_T hz1nyz423a [ 6 ] , h1o13zkcgj * localB ) ; extern
void my0xtyxafz ( const real_T munon5ksyp [ 3 ] , const real_T lknhq5bywb [
15 ] , real_T gqj3vx0o0t , klganzpzjd * localB ) ; extern void lunmotda0s (
real_T dtf5yqtjsv , real_T i5214tkprj , fgw5sini0c * localB ) ; extern void
c3hsf3zf4q ( real_T dfco35ev32 , bzt4d3mdqo * localB ) ; extern void
hwodfh00oh ( const real_T iu3czjdy3h [ 12 ] , const real_T cqwqvekp4q [ 2 ] ,
real_T kyr0og2ni5 , const real_T c2s20noxkv [ 2 ] , real_T ffcltkfjor ,
ap0k121r2c * localB ) ; extern void olmchesjlh ( const real_T dyryfc4jnl [ 2
] , const real_T khpnmdaoh4 [ 2 ] , const real_T izw0kcqljo [ 2 ] , const
real_T nl0wqqwkmt [ 2 ] , const real_T be5ql5gqew [ 2 ] , const real_T
bf0d5xg4tz [ 2 ] , const real_T bk0gn52prv [ 2 ] , const real_T ltr5igat1h [
2 ] , real_T iodgoazcfv , real_T keaen1whku , const real_T jl35h4iafw [ 2 ] ,
const real_T erwrb5niab [ 2 ] , const real_T cfvcyfzgwh [ 2 ] , const real_T
j4cawou1dj [ 2 ] , const real_T hqh5ky5t2a [ 2 ] , real_T encawndg2g ,
ov12mb433f * localB ) ; extern void ew4afwvte5 ( const real_T nx51zxl44v [ 2
] , const real_T eht1kzjsnz [ 2 ] , const real_T fyugyymaaf [ 2 ] , const
real_T i1elytuqz5 [ 2 ] , const real_T p1nucck3fq [ 2 ] , const real_T
nbvsqmxnba [ 2 ] , const real_T hoiel5bjtr [ 2 ] , const real_T evrhrqjnp0 [
2 ] , const real_T enklap4tiu [ 2 ] , const real_T amwl4upe3f [ 2 ] , const
real_T gceiustsl0 [ 2 ] , const real_T oczn0k3emj [ 2 ] , const real_T
cfpvkhiape [ 2 ] , const real_T phjejfpjej [ 2 ] , real_T evxod0y3rk ,
k0s5cnp1qe * localB ) ; extern void g0rn2igfkt ( const T_bus * e1vn4ulzpu ,
const epsilon_bus * d440o3ywrk , const real_T k4d4z5eppd [ 15 ] , const
real_T izq5f24mr2 [ 15 ] , real_T mbyuqbb0gq , m1hjhmjwg5 * localB ) ; extern
void bifsfih4ms ( const real_T bv25vihqpg [ 12 ] , real_T eb1petavsd , real_T
ipfnyd1r1n , real_T dhr5u3poqu , real_T k4n1imnnsv , real_T hdyhmdlabm ,
awhjeott21 * localB ) ; extern void onqykep2vg ( const real_T gxgrs5oabc [ 2
] , real_T exdyxrscw1 , const real_T jlmm4dc35p [ 2 ] , kvooenmmxs * localB )
; extern void ifmmcug2wn ( const real_T gouta4wgnp [ 2 ] , real_T bkjhjzemgo
, const real_T p5y1kkldmx [ 2 ] , jeft2nmhia * localB ) ; extern void
hp20ymhe1e ( real_T omx0naxsga , real_T mztud3dn4q , const real_T p0hp0amzyt
[ 2 ] , pmfwaobihs * localB ) ; extern void l1ggp544gs ( const real_T
cithc5btav [ 2 ] , const real_T iwqgu021ob [ 2 ] , m1ole03jfu * localB ) ;
extern void akyqzm0njl ( const real_T bs0rg1tnta [ 36 ] , gxaahiqdto * localB
) ; extern void bn5e2i2ijs ( const real_T enht2u1u0h [ 15 ] , gor4c4smif *
localB ) ; extern void iysmccme2o ( const real_T hkksstn4f2 [ 2 ] , const
real_T i5zqyudzmt [ 2 ] , ivinvzhydj * localB ) ; extern void eejedaxwca (
const real_T luzprktxbu [ 2 ] , eo1i0pkmfn * localB ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
