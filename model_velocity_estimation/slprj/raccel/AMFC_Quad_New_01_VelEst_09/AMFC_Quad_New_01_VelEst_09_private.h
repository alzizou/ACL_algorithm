#include "__cf_AMFC_Quad_New_01_VelEst_09.h"
#ifndef RTW_HEADER_AMFC_Quad_New_01_VelEst_09_private_h_
#define RTW_HEADER_AMFC_Quad_New_01_VelEst_09_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "AMFC_Quad_New_01_VelEst_09.h"
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
rt_TDelayFreeBuf ( void * buf ) ; extern void amnslaei3h ( const real_T
e50pf4sszw [ 6 ] , kdy3j1zqh4 * localB ) ; extern void ieqavvskat ( real_T
livu2yroti , const real_T fbgglxjc5p [ 6 ] , iasl3yiitj * localB ) ; extern
void kdakkberg2 ( const real_T dcljw4kfl5 [ 36 ] , const real_T cauyn0v1en [
36 ] , kulrpdeeos * localB ) ; extern void kozwe2mnnv ( const real_T
jvql1kixgo [ 6 ] , const real_T fnj2jhwto0 [ 6 ] , jfvupiqhd2 * localB ) ;
extern void fiuiys43oq ( const real_T ip0bo4bex1 [ 6 ] , n4lulc2jbj * localB
) ; extern void biysbmp2xz ( const real_T mnai1cdm33 [ 6 ] , const real_T
oplgbc0pbx [ 6 ] , const real_T psd4hmtlez [ 36 ] , e4oqpa2van * localB ) ;
extern void pb1mfspym2 ( const real_T ddv0orfitt [ 6 ] , const real_T
jjxt3gnz3b [ 6 ] , const real_T kchn0gn052 [ 36 ] , const real_T haqnobxofj [
36 ] , l5vwpehasg * localB ) ; extern void b42o4l4dbu ( const real_T
d2ag3mnpqt [ 6 ] , const real_T ihu3vrachc [ 6 ] , const real_T mqx4zow5zx [
6 ] , const real_T j2l0k22yaw [ 36 ] , const real_T pkx4fqxbv4 [ 36 ] , const
real_T hkihlbn2te [ 6 ] , const real_T dfcdpznagw [ 6 ] , h4gxvsmp2l * localB
) ; extern void iexo3cl4az ( const real_T f3i5jffqte [ 12 ] , const real_T
jr1dba04os [ 3 ] , const real_T iiiqtkubdp [ 6 ] , pz5kvzziwe * localB ) ;
extern void g4uofg33hn ( const real_T lvcypb4frb [ 12 ] , real_T ivkvzaw2u5 ,
real_T kh43fny0wn , real_T c1lkdoj21v , const real_T hrldqeqbae [ 6 ] ,
kjumluinue * localB ) ; extern void bm4zjztzz5 ( const real_T a2poltcxks [ 12
] , const real_T bip35fcvnk [ 4 ] , real_T li3son1kwn , ppugmfy3jk * localB )
; extern void o2m3ohsxqo ( real_T afohumkv11 , real_T fvw3nkm4iz , ahvsyvuicz
* localB ) ; extern void b04przplti ( real_T abcqmfh1zk , l3mc1mdu0x * localB
) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
