#include "__cf_AMFC_Quad_New_01_VelEst_08.h"
#ifndef RTW_HEADER_AMFC_Quad_New_01_VelEst_08_private_h_
#define RTW_HEADER_AMFC_Quad_New_01_VelEst_08_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "AMFC_Quad_New_01_VelEst_08.h"
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
rt_TDelayFreeBuf ( void * buf ) ; extern void jiqhbaps0d ( const real_T
ntfm5wyyos [ 36 ] , const real_T eoxgvmfexp [ 36 ] , o1slwgqdlm * localB ) ;
extern void k5z0pc1ypp ( const real_T ihvcx1pkz5 [ 6 ] , const real_T
axfks553mz [ 6 ] , fwylrlcfrr * localB ) ; extern void pqkbkv225c ( const
real_T jjomphwdey [ 6 ] , lthd11jgkt * localB ) ; extern void o4x1a0lhdq (
const real_T k5mfunhgj4 [ 6 ] , const real_T nichsfli03 [ 6 ] , const real_T
idotbkjchs [ 36 ] , db1uh4mzfc * localB ) ; extern void hdagumznar ( const
real_T azrtukjyo3 [ 6 ] , const real_T mbkt3c5lml [ 6 ] , const real_T
dr5igse0fb [ 36 ] , const real_T aoipawa0bm [ 36 ] , na51yrjijx * localB ) ;
extern void l2lj4cmfck ( const real_T fy0kyp3umm [ 6 ] , const real_T
ioqjsibok0 [ 6 ] , const real_T fa2brwwlb2 [ 6 ] , const real_T kkedrh1goh [
36 ] , const real_T p4gjxfn55e [ 36 ] , const real_T ilb0lcvng0 [ 6 ] , const
real_T olxmf2elsi [ 6 ] , bzqp5lmsxs * localB ) ; extern void j3iimcdkll (
real_T kcuffxjwhs , real_T mt1y5gzj5r , fkz4aojsrd * localB ) ; extern void
ibkgszeens ( real_T nrguswsx3t , bzcun1m1ez * localB ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
