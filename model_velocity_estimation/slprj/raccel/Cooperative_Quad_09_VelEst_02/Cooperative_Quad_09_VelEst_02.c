#include "__cf_Cooperative_Quad_09_VelEst_02.h"
#include "rt_logging_mmi.h"
#include "Cooperative_Quad_09_VelEst_02_capi.h"
#include <math.h>
#include "Cooperative_Quad_09_VelEst_02.h"
#include "Cooperative_Quad_09_VelEst_02_private.h"
#include "Cooperative_Quad_09_VelEst_02_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 4 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.13 (R2017b) 24-Jul-2017" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
 "slprj\\raccel\\Cooperative_Quad_09_VelEst_02\\Cooperative_Quad_09_VelEst_02_Jpattern.mat"
; const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const
int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1
} ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
#define efueyx1ojy (2.0)
#define mnw1ao5qgp (2.0)
#define amqgqkb2nu (3.0)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void obtisppc2e ( const real_T x [ 36 ] , real_T y [ 36 ]
) ; static void hakwjia2pv ( const real_T a [ 9 ] , real_T c [ 9 ] ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void ihouus1chq (
const real_T anhjewobnm [ 6 ] , bnke3tdprc * localB ) { real_T u0 ; u0 =
muDoubleScalarSqrt ( ( anhjewobnm [ 3 ] * anhjewobnm [ 3 ] + anhjewobnm [ 4 ]
* anhjewobnm [ 4 ] ) + anhjewobnm [ 5 ] * anhjewobnm [ 5 ] ) ; localB ->
gwmh5422nv [ 0 ] = muDoubleScalarAsin ( muDoubleScalarMin ( muDoubleScalarMax
( ( 0.0 * anhjewobnm [ 3 ] - anhjewobnm [ 4 ] ) / ( u0 + 0.001 ) , - 1.0 ) ,
1.0 ) ) ; localB -> gwmh5422nv [ 1 ] = muDoubleScalarAtan ( ( 0.0 *
anhjewobnm [ 4 ] + anhjewobnm [ 3 ] ) / ( anhjewobnm [ 5 ] + 0.001 ) ) ;
localB -> gwmh5422nv [ 2 ] = 0.0 ; localB -> hw5tnzrodd = u0 ; } void
g4g4bdu0ia ( real_T bzsy3edq02 , const real_T fxjmelxcxk [ 6 ] , dbcl0xeupb *
localB ) { int32_T i ; for ( i = 0 ; i < 4 ; i ++ ) { localB -> ollm0kao5t [
i ] = 0.0 ; localB -> ollm0kao5t [ i ] += rtP . RM_1 [ i ] * bzsy3edq02 ;
localB -> ollm0kao5t [ i ] += rtP . RM_1 [ i + 4 ] * fxjmelxcxk [ 3 ] ;
localB -> ollm0kao5t [ i ] += rtP . RM_1 [ i + 8 ] * fxjmelxcxk [ 4 ] ;
localB -> ollm0kao5t [ i ] += rtP . RM_1 [ i + 12 ] * fxjmelxcxk [ 5 ] ;
localB -> ollm0kao5t [ i ] = muDoubleScalarSqrt ( muDoubleScalarAbs ( localB
-> ollm0kao5t [ i ] ) ) ; } } void ijextzfzou ( const real_T as0slvcd4k [ 36
] , const real_T evyixzyx5o [ 36 ] , mse3h2ftgz * localB ) { real_T
evyixzyx5o_p [ 36 ] ; real_T as0slvcd4k_p [ 36 ] ; int32_T i ; int32_T i_p ;
int32_T i_e ; real_T as0slvcd4k_e [ 36 ] ; real_T as0slvcd4k_i [ 36 ] ;
real_T as0slvcd4k_m [ 36 ] ; real_T tmp ; for ( i = 0 ; i < 6 ; i ++ ) { for
( i_p = 0 ; i_p < 6 ; i_p ++ ) { evyixzyx5o_p [ i + 6 * i_p ] = 0.0 ;
as0slvcd4k_p [ i + 6 * i_p ] = 0.0 ; as0slvcd4k_e [ i + 6 * i_p ] = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { evyixzyx5o_p [ i + 6 * i_p ] += evyixzyx5o [
6 * i_e + i ] * as0slvcd4k [ 6 * i_p + i_e ] ; as0slvcd4k_p [ i + 6 * i_p ]
+= as0slvcd4k [ 6 * i_e + i ] * evyixzyx5o [ 6 * i_e + i_p ] ; as0slvcd4k_e [
i + 6 * i_p ] += as0slvcd4k [ 6 * i_e + i ] * rtP . B [ 6 * i_p + i_e ] ; } }
for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { as0slvcd4k_i [ i + 6 * i_p ] = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { as0slvcd4k_i [ i + 6 * i_p ] += as0slvcd4k_e
[ 6 * i_e + i ] * rtP . R [ 6 * i_p + i_e ] ; } } for ( i_p = 0 ; i_p < 6 ;
i_p ++ ) { as0slvcd4k_m [ i + 6 * i_p ] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e
++ ) { as0slvcd4k_m [ i + 6 * i_p ] += as0slvcd4k_i [ 6 * i_e + i ] * rtP . B
[ 6 * i_e + i_p ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp += as0slvcd4k_m [ 6 * i_e + i ] *
as0slvcd4k [ 6 * i_p + i_e ] ; } localB -> of10phaqxi [ i + 6 * i_p ] = ( (
evyixzyx5o_p [ 6 * i_p + i ] + as0slvcd4k_p [ 6 * i_p + i ] ) - tmp ) + rtP .
Q [ 6 * i_p + i ] * 2.0 ; } } } void l3dvuo1xw3 ( const real_T owlsxfafsf [ 6
] , const real_T d5hib54nne [ 6 ] , mu1vmeaxft * localB ) { int32_T i ;
real_T ABS ; for ( i = 0 ; i < 6 ; i ++ ) { if ( d5hib54nne [ i ] > 0.0 ) {
ABS = d5hib54nne [ i ] ; } else { ABS = - d5hib54nne [ i ] ; } localB ->
l5c2p5rmcp [ i ] = muDoubleScalarSqrt ( ABS ) ; localB -> l5c2p5rmcp [ i ] =
owlsxfafsf [ i ] - d5hib54nne [ i ] / ( ABS + 0.01 ) * ( rtP . k1 * localB ->
l5c2p5rmcp [ i ] ) ; } } void lgndixfdt3 ( const real_T al2lunlm4b [ 6 ] ,
gdb14qhzuk * localB ) { int32_T i ; for ( i = 0 ; i < 6 ; i ++ ) { if (
al2lunlm4b [ i ] > 0.0 ) { localB -> abjrrhoh5i [ i ] = al2lunlm4b [ i ] ; }
else { localB -> abjrrhoh5i [ i ] = - al2lunlm4b [ i ] ; } localB ->
abjrrhoh5i [ i ] = al2lunlm4b [ i ] / ( localB -> abjrrhoh5i [ i ] + 0.01 ) *
- rtP . k2 ; } } void lvvcxitelq ( const real_T g0eic1btf3 [ 6 ] , const
real_T ogw40qmced [ 6 ] , const real_T ajegbo1ahs [ 36 ] , dtavxwjdhj *
localB ) { real_T tmp [ 36 ] ; int32_T i ; int32_T i_p ; real_T tmp_p [ 36 ]
; int32_T i_e ; real_T tmp_e [ 6 ] ; real_T tmp_i [ 6 ] ; for ( i_p = 0 ; i_p
< 6 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp [ i + 6 * i_p ] = - rtP .
gamma_1 [ 6 * i_p + i ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_e [
i_p ] = 0.0 ; tmp_i [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { tmp_p [
i_p + 6 * i ] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp_p [ i_p + 6 *
i ] += tmp [ 6 * i_e + i_p ] * ajegbo1ahs [ 6 * i + i_e ] ; } tmp_e [ i_p ]
+= tmp_p [ 6 * i + i_p ] * g0eic1btf3 [ i ] ; tmp_i [ i_p ] += rtP . gamma_1
[ 6 * i + i_p ] * rtP . rho_1 * ogw40qmced [ i ] ; } localB -> jhz4hydf42 [
i_p ] = tmp_e [ i_p ] - tmp_i [ i_p ] ; } } void bmxkvlwnui ( const real_T
ejplzsu2bn [ 6 ] , const real_T mj01hqexai [ 6 ] , const real_T em4h4dw5yu [
36 ] , const real_T bjcozpvrzq [ 36 ] , jajski1k0u * localB ) { real_T
DVa_hat [ 6 ] ; real_T d [ 36 ] ; int32_T j ; real_T b_d [ 6 ] ; real_T tmp [
36 ] ; int32_T i ; real_T tmp_p [ 36 ] ; int32_T i_p ; real_T tmp_e [ 36 ] ;
real_T mj01hqexai_p [ 6 ] ; real_T tmp_i [ 6 ] ; real_T tmp_m [ 6 ] ; memset
( & d [ 0 ] , 0 , 36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) {
d [ j + 6 * j ] = ejplzsu2bn [ j ] ; b_d [ j ] = bjcozpvrzq [ j * 7 ] ; for (
i = 0 ; i < 6 ; i ++ ) { tmp [ i + 6 * j ] = - rtP . gamma_0 [ 6 * j + i ] ;
} } for ( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ; j < 6 ; j ++ ) { tmp_p [ i +
6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_p [ i + 6 * j ] +=
tmp [ 6 * i_p + i ] * em4h4dw5yu [ 6 * j + i_p ] ; } } for ( j = 0 ; j < 6 ;
j ++ ) { tmp_e [ i + 6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
tmp_e [ i + 6 * j ] += tmp_p [ 6 * i_p + i ] * d [ 6 * j + i_p ] ; } }
mj01hqexai_p [ i ] = mj01hqexai [ i ] - ejplzsu2bn [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { tmp_i [ i ] = 0.0 ; tmp_m [ i ] = 0.0 ; for ( j = 0 ; j < 6 ;
j ++ ) { tmp_i [ i ] += tmp_e [ 6 * j + i ] * mj01hqexai_p [ j ] ; tmp_m [ i
] += rtP . gamma_0 [ 6 * j + i ] * rtP . rho_0 * b_d [ j ] ; } DVa_hat [ i ]
= tmp_i [ i ] - tmp_m [ i ] ; } memset ( & localB -> ltfzlzvs0c [ 0 ] , 0 ,
36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) { localB ->
ltfzlzvs0c [ j + 6 * j ] = DVa_hat [ j ] ; } } static void obtisppc2e ( const
real_T x [ 36 ] , real_T y [ 36 ] ) { int8_T p [ 6 ] ; real_T A [ 36 ] ;
int8_T ipiv [ 6 ] ; int32_T b_j ; int32_T ix ; real_T smax ; real_T s ;
int32_T b_k ; int32_T iy ; int32_T c_ix ; int32_T d ; int32_T ijA ; int32_T
pipk ; for ( b_j = 0 ; b_j < 36 ; b_j ++ ) { y [ b_j ] = 0.0 ; A [ b_j ] = x
[ b_j ] ; } for ( b_j = 0 ; b_j < 6 ; b_j ++ ) { ipiv [ b_j ] = ( int8_T ) (
1 + b_j ) ; } for ( b_j = 0 ; b_j < 5 ; b_j ++ ) { pipk = b_j * 7 ; iy = 0 ;
ix = pipk ; smax = muDoubleScalarAbs ( A [ pipk ] ) ; for ( b_k = 2 ; b_k <=
6 - b_j ; b_k ++ ) { ix ++ ; s = muDoubleScalarAbs ( A [ ix ] ) ; if ( s >
smax ) { iy = b_k - 1 ; smax = s ; } } if ( A [ pipk + iy ] != 0.0 ) { if (
iy != 0 ) { ipiv [ b_j ] = ( int8_T ) ( ( b_j + iy ) + 1 ) ; ix = b_j ; iy +=
b_j ; for ( b_k = 0 ; b_k < 6 ; b_k ++ ) { smax = A [ ix ] ; A [ ix ] = A [
iy ] ; A [ iy ] = smax ; ix += 6 ; iy += 6 ; } } iy = ( pipk - b_j ) + 6 ;
for ( ix = pipk + 1 ; ix + 1 <= iy ; ix ++ ) { A [ ix ] /= A [ pipk ] ; } }
iy = pipk ; ix = pipk + 6 ; for ( b_k = 1 ; b_k <= 5 - b_j ; b_k ++ ) { smax
= A [ ix ] ; if ( A [ ix ] != 0.0 ) { c_ix = pipk + 1 ; d = ( iy - b_j ) + 12
; for ( ijA = 7 + iy ; ijA + 1 <= d ; ijA ++ ) { A [ ijA ] += A [ c_ix ] * -
smax ; c_ix ++ ; } } ix += 6 ; iy += 6 ; } } for ( b_j = 0 ; b_j < 6 ; b_j ++
) { p [ b_j ] = ( int8_T ) ( 1 + b_j ) ; } for ( b_j = 0 ; b_j < 5 ; b_j ++ )
{ if ( ipiv [ b_j ] > 1 + b_j ) { pipk = p [ ipiv [ b_j ] - 1 ] ; p [ ipiv [
b_j ] - 1 ] = p [ b_j ] ; p [ b_j ] = ( int8_T ) pipk ; } } for ( b_j = 0 ;
b_j < 6 ; b_j ++ ) { pipk = p [ b_j ] - 1 ; y [ b_j + 6 * ( p [ b_j ] - 1 ) ]
= 1.0 ; for ( iy = b_j ; iy + 1 < 7 ; iy ++ ) { if ( y [ 6 * pipk + iy ] !=
0.0 ) { for ( ix = iy + 1 ; ix + 1 < 7 ; ix ++ ) { y [ ix + 6 * pipk ] -= y [
6 * pipk + iy ] * A [ 6 * iy + ix ] ; } } } } for ( b_j = 0 ; b_j < 6 ; b_j
++ ) { pipk = 6 * b_j ; for ( iy = 5 ; iy >= 0 ; iy -- ) { ix = 6 * iy ; if (
y [ iy + pipk ] != 0.0 ) { y [ iy + pipk ] /= A [ iy + ix ] ; for ( b_k = 0 ;
b_k + 1 <= iy ; b_k ++ ) { y [ b_k + pipk ] -= y [ iy + pipk ] * A [ b_k + ix
] ; } } } } } void jvlvilab4w ( const real_T oexbw4nvh5 [ 6 ] , const real_T
hhxq1jqqm2 [ 6 ] , const real_T omhcrter1d [ 6 ] , const real_T gh0mpay5wb [
36 ] , const real_T hyjceobmbu [ 36 ] , const real_T cex2mrfzqe [ 6 ] , const
real_T kre4ojvqmh [ 6 ] , b2p0222gkg * localB ) { int8_T I [ 36 ] ; int32_T k
; real_T tmp [ 36 ] ; int32_T i ; real_T tmp_p [ 36 ] ; int32_T i_p ; real_T
tmp_e [ 36 ] ; real_T tmp_i [ 36 ] ; real_T I_p [ 36 ] ; real_T omhcrter1d_p
[ 6 ] ; real_T I_e [ 6 ] ; real_T tmp_m ; real_T omhcrter1d_e [ 6 ] ; for ( i
= 0 ; i < 36 ; i ++ ) { I [ i ] = 0 ; } obtisppc2e ( gh0mpay5wb , tmp ) ; for
( k = 0 ; k < 6 ; k ++ ) { I [ k + 6 * k ] = 1 ; for ( i = 0 ; i < 6 ; i ++ )
{ tmp_p [ k + 6 * i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_p [ k
+ 6 * i ] += rtP . R [ 6 * i_p + k ] * 0.5 * rtP . B [ 6 * i_p + i ] ; } }
for ( i = 0 ; i < 6 ; i ++ ) { tmp_e [ k + 6 * i ] = 0.0 ; tmp_i [ k + 6 * i
] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_e [ k + 6 * i ] += tmp_p [
6 * i_p + k ] * gh0mpay5wb [ 6 * i + i_p ] ; tmp_i [ k + 6 * i ] += tmp [ 6 *
i_p + k ] * rtP . Q [ 6 * i + i_p ] ; } } } for ( i = 0 ; i < 6 ; i ++ ) {
tmp_m = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { I_p [ i_p + 6 * i ] = (
tmp_i [ 6 * i + i_p ] * 2.0 + ( real_T ) I [ 6 * i + i_p ] ) + hyjceobmbu [ 6
* i + i_p ] ; tmp_m += hyjceobmbu [ 6 * i_p + i ] * kre4ojvqmh [ i_p ] ; }
omhcrter1d_p [ i ] = omhcrter1d [ i ] - tmp_m ; } for ( i = 0 ; i < 6 ; i ++
) { I_e [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp [ i + 6 * i_p
] = 0.0 ; for ( k = 0 ; k < 6 ; k ++ ) { tmp [ i + 6 * i_p ] += rtP . R [ 6 *
k + i ] * 0.75 * rtP . B [ 6 * k + i_p ] ; } I_e [ i ] += I_p [ 6 * i_p + i ]
* oexbw4nvh5 [ i_p ] ; } omhcrter1d_e [ i ] = ( ( omhcrter1d_p [ i ] + I_e [
i ] ) - cex2mrfzqe [ i ] ) - hhxq1jqqm2 [ i ] ; for ( i_p = 0 ; i_p < 6 ; i_p
++ ) { tmp_p [ i + 6 * i_p ] = 0.0 ; for ( k = 0 ; k < 6 ; k ++ ) { tmp_p [ i
+ 6 * i_p ] += tmp [ 6 * k + i ] * gh0mpay5wb [ 6 * i_p + k ] ; } } } for ( i
= 0 ; i < 6 ; i ++ ) { omhcrter1d_p [ i ] = 0.0 ; I_e [ i ] = 0.0 ; tmp_m =
0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_m += tmp_e [ 6 * i_p + i ] *
oexbw4nvh5 [ i_p ] ; omhcrter1d_p [ i ] += rtP . BBT_inv [ 6 * i_p + i ] *
omhcrter1d_e [ i_p ] ; I_e [ i ] += tmp_p [ 6 * i_p + i ] * oexbw4nvh5 [ i_p
] ; } localB -> m0i0p0mohd [ i ] = ( omhcrter1d_p [ i ] - I_e [ i ] ) + tmp_m
; } } void m1hec3vrd2 ( const real_T aj1sgw205c [ 12 ] , const real_T
ieqyvfjn0s [ 3 ] , const real_T bszzozixyu [ 6 ] , ddr40jvpzk * localB ) {
int32_T i ; localB -> dzda0l3ztv [ 0 ] = aj1sgw205c [ 3 ] ; localB ->
dzda0l3ztv [ 3 ] = aj1sgw205c [ 9 ] ; localB -> j1zyuz5kzg [ 0 ] = ieqyvfjn0s
[ 0 ] ; localB -> j1zyuz5kzg [ 3 ] = bszzozixyu [ 0 ] ; localB -> dzda0l3ztv
[ 1 ] = aj1sgw205c [ 4 ] ; localB -> dzda0l3ztv [ 4 ] = aj1sgw205c [ 10 ] ;
localB -> j1zyuz5kzg [ 1 ] = ieqyvfjn0s [ 1 ] ; localB -> j1zyuz5kzg [ 4 ] =
bszzozixyu [ 1 ] ; localB -> dzda0l3ztv [ 2 ] = aj1sgw205c [ 5 ] ; localB ->
dzda0l3ztv [ 5 ] = aj1sgw205c [ 11 ] ; localB -> j1zyuz5kzg [ 2 ] =
ieqyvfjn0s [ 2 ] ; localB -> j1zyuz5kzg [ 5 ] = bszzozixyu [ 2 ] ; for ( i =
0 ; i < 6 ; i ++ ) { localB -> jl4fbhrop1 [ i ] = localB -> j1zyuz5kzg [ i ]
- localB -> dzda0l3ztv [ i ] ; } } void d4w44phvgb ( const real_T mllnjppvp0
[ 6 ] , const real_T dy5fgbbgqm [ 6 ] , kkwsfb1bht * localB ) { int32_T i ;
real_T ABS ; for ( i = 0 ; i < 6 ; i ++ ) { if ( dy5fgbbgqm [ i ] > 0.0 ) {
ABS = dy5fgbbgqm [ i ] ; } else { ABS = - dy5fgbbgqm [ i ] ; } localB ->
hg1x1nd45k [ i ] = muDoubleScalarSqrt ( ABS ) ; localB -> hg1x1nd45k [ i ] =
mllnjppvp0 [ i ] - dy5fgbbgqm [ i ] / ( ABS + 0.01 ) * ( rtP . k1 * localB ->
hg1x1nd45k [ i ] ) ; } } void nnvj0nbsr4 ( const real_T o23ecwi00m [ 12 ] ,
real_T lkhv0noozn , real_T j1yzquu10j , real_T alftjmzvnx , const real_T
hz1nyz423a [ 6 ] , h1o13zkcgj * localB ) { int32_T i ; localB -> gtmlnhqoq0 [
0 ] = lkhv0noozn ; localB -> gtmlnhqoq0 [ 1 ] = j1yzquu10j ; localB ->
gtmlnhqoq0 [ 2 ] = alftjmzvnx ; localB -> jaolq3jrhd [ 0 ] = o23ecwi00m [ 0 ]
; localB -> jaolq3jrhd [ 3 ] = o23ecwi00m [ 6 ] ; localB -> gtmlnhqoq0 [ 3 ]
= hz1nyz423a [ 0 ] ; localB -> jaolq3jrhd [ 1 ] = o23ecwi00m [ 1 ] ; localB
-> jaolq3jrhd [ 4 ] = o23ecwi00m [ 7 ] ; localB -> gtmlnhqoq0 [ 4 ] =
hz1nyz423a [ 1 ] ; localB -> jaolq3jrhd [ 2 ] = o23ecwi00m [ 2 ] ; localB ->
jaolq3jrhd [ 5 ] = o23ecwi00m [ 8 ] ; localB -> gtmlnhqoq0 [ 5 ] = hz1nyz423a
[ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { localB -> admi3yqyf0 [ i ] = localB ->
gtmlnhqoq0 [ i ] - localB -> jaolq3jrhd [ i ] ; } } void my0xtyxafz ( const
real_T munon5ksyp [ 3 ] , const real_T lknhq5bywb [ 15 ] , real_T gqj3vx0o0t
, klganzpzjd * localB ) { int32_T gqj3vx0o0t_p ; gqj3vx0o0t_p = ( int32_T ) (
gqj3vx0o0t + 1.0 ) ; localB -> hia3u3mq0v [ 0 ] = ( munon5ksyp [ 0 ] +
lknhq5bywb [ 0 ] ) + lknhq5bywb [ gqj3vx0o0t_p - 1 ] ; localB -> hia3u3mq0v [
1 ] = ( munon5ksyp [ 1 ] + lknhq5bywb [ 5 ] ) + lknhq5bywb [ gqj3vx0o0t_p + 4
] ; localB -> hia3u3mq0v [ 2 ] = ( munon5ksyp [ 2 ] + lknhq5bywb [ 10 ] ) +
lknhq5bywb [ gqj3vx0o0t_p + 9 ] ; } void lunmotda0s ( real_T dtf5yqtjsv ,
real_T i5214tkprj , fgw5sini0c * localB ) { real_T ABS ; ABS =
muDoubleScalarAbs ( i5214tkprj ) ; localB -> mxe5eu4hb4 = dtf5yqtjsv -
i5214tkprj / ( ABS + rtP . alpha_Slid ) * muDoubleScalarSqrt ( ABS ) * rtP .
k1o ; } void c3hsf3zf4q ( real_T dfco35ev32 , bzt4d3mdqo * localB ) { localB
-> g2eupjim4n = dfco35ev32 / ( muDoubleScalarAbs ( dfco35ev32 ) + rtP .
alpha_Slid ) * - rtP . k2o ; } void hwodfh00oh ( const real_T iu3czjdy3h [ 12
] , const real_T cqwqvekp4q [ 2 ] , real_T kyr0og2ni5 , const real_T
c2s20noxkv [ 2 ] , real_T ffcltkfjor , ap0k121r2c * localB ) { localB ->
ikd1vheez0 [ 0 ] = cqwqvekp4q [ 0 ] ; localB -> ikd1vheez0 [ 1 ] = cqwqvekp4q
[ 1 ] ; localB -> ikd1vheez0 [ 2 ] = kyr0og2ni5 ; localB -> ikd1vheez0 [ 3 ]
= iu3czjdy3h [ 3 ] ; localB -> ikd1vheez0 [ 4 ] = iu3czjdy3h [ 4 ] ; localB
-> ikd1vheez0 [ 5 ] = iu3czjdy3h [ 5 ] ; localB -> ikd1vheez0 [ 6 ] =
c2s20noxkv [ 0 ] ; localB -> ikd1vheez0 [ 7 ] = c2s20noxkv [ 1 ] ; localB ->
ikd1vheez0 [ 8 ] = ffcltkfjor ; localB -> ikd1vheez0 [ 9 ] = iu3czjdy3h [ 9 ]
; localB -> ikd1vheez0 [ 10 ] = iu3czjdy3h [ 10 ] ; localB -> ikd1vheez0 [ 11
] = iu3czjdy3h [ 11 ] ; } void olmchesjlh ( const real_T dyryfc4jnl [ 2 ] ,
const real_T khpnmdaoh4 [ 2 ] , const real_T izw0kcqljo [ 2 ] , const real_T
nl0wqqwkmt [ 2 ] , const real_T be5ql5gqew [ 2 ] , const real_T bf0d5xg4tz [
2 ] , const real_T bk0gn52prv [ 2 ] , const real_T ltr5igat1h [ 2 ] , real_T
iodgoazcfv , real_T keaen1whku , const real_T jl35h4iafw [ 2 ] , const real_T
erwrb5niab [ 2 ] , const real_T cfvcyfzgwh [ 2 ] , const real_T j4cawou1dj [
2 ] , const real_T hqh5ky5t2a [ 2 ] , real_T encawndg2g , ov12mb433f * localB
) { real_T P_hat_in [ 8 ] ; real_T P_rel_local_in [ 8 ] ; real_T tau_in [ 8 ]
; int32_T i ; int32_T b ; int32_T c ; real_T jo3ha1pnnb [ 8 ] ; real_T
kr1mqi10ym [ 8 ] ; real_T fmw1juj5fp [ 8 ] ; real_T bigaj1bzad_data [ 8 ] ;
int32_T i_p ; real_T Vec_idx_0 ; real_T Vec_idx_1 ; jo3ha1pnnb [ 0 ] =
dyryfc4jnl [ 0 ] ; jo3ha1pnnb [ 2 ] = khpnmdaoh4 [ 0 ] ; jo3ha1pnnb [ 4 ] =
izw0kcqljo [ 0 ] ; jo3ha1pnnb [ 6 ] = nl0wqqwkmt [ 0 ] ; kr1mqi10ym [ 0 ] =
be5ql5gqew [ 0 ] ; kr1mqi10ym [ 2 ] = bf0d5xg4tz [ 0 ] ; kr1mqi10ym [ 4 ] =
bk0gn52prv [ 0 ] ; kr1mqi10ym [ 6 ] = ltr5igat1h [ 0 ] ; fmw1juj5fp [ 0 ] =
jl35h4iafw [ 0 ] ; fmw1juj5fp [ 2 ] = erwrb5niab [ 0 ] ; fmw1juj5fp [ 4 ] =
cfvcyfzgwh [ 0 ] ; fmw1juj5fp [ 6 ] = j4cawou1dj [ 0 ] ; jo3ha1pnnb [ 1 ] =
dyryfc4jnl [ 1 ] ; jo3ha1pnnb [ 3 ] = khpnmdaoh4 [ 1 ] ; jo3ha1pnnb [ 5 ] =
izw0kcqljo [ 1 ] ; jo3ha1pnnb [ 7 ] = nl0wqqwkmt [ 1 ] ; kr1mqi10ym [ 1 ] =
be5ql5gqew [ 1 ] ; kr1mqi10ym [ 3 ] = bf0d5xg4tz [ 1 ] ; kr1mqi10ym [ 5 ] =
bk0gn52prv [ 1 ] ; kr1mqi10ym [ 7 ] = ltr5igat1h [ 1 ] ; fmw1juj5fp [ 1 ] =
jl35h4iafw [ 1 ] ; fmw1juj5fp [ 3 ] = erwrb5niab [ 1 ] ; fmw1juj5fp [ 5 ] =
cfvcyfzgwh [ 1 ] ; fmw1juj5fp [ 7 ] = j4cawou1dj [ 1 ] ; for ( i = 0 ; i < 4
; i ++ ) { b = i * ( int32_T ) efueyx1ojy ; c = ( 1 + i ) * ( int32_T )
efueyx1ojy ; if ( b + 1 > c ) { b = 0 ; c = 0 ; } c -= b ; for ( i_p = 0 ;
i_p < c ; i_p ++ ) { bigaj1bzad_data [ i_p ] = jo3ha1pnnb [ b + i_p ] ; }
P_hat_in [ i << 1 ] = bigaj1bzad_data [ 0 ] ; P_hat_in [ 1 + ( i << 1 ) ] =
bigaj1bzad_data [ 1 ] ; b = i * ( int32_T ) efueyx1ojy ; c = ( 1 + i ) * (
int32_T ) efueyx1ojy ; if ( b + 1 > c ) { b = 0 ; c = 0 ; } c -= b ; for (
i_p = 0 ; i_p < c ; i_p ++ ) { bigaj1bzad_data [ i_p ] = fmw1juj5fp [ b + i_p
] ; } P_rel_local_in [ i << 1 ] = bigaj1bzad_data [ 0 ] ; P_rel_local_in [ 1
+ ( i << 1 ) ] = bigaj1bzad_data [ 1 ] ; b = i * ( int32_T ) efueyx1ojy ; c =
( 1 + i ) * ( int32_T ) efueyx1ojy ; if ( b + 1 > c ) { b = 0 ; c = 0 ; } c
-= b ; for ( i_p = 0 ; i_p < c ; i_p ++ ) { bigaj1bzad_data [ i_p ] =
kr1mqi10ym [ b + i_p ] ; } tau_in [ i << 1 ] = bigaj1bzad_data [ 0 ] ; tau_in
[ 1 + ( i << 1 ) ] = bigaj1bzad_data [ 1 ] ; } b = ( int32_T ) encawndg2g ;
localB -> arptmdt05w [ 0 ] = rtP . BN [ ( ( ( ( int32_T ) encawndg2g - 1 ) <<
2 ) + ( int32_T ) encawndg2g ) - 1 ] * ( P_hat_in [ ( b - 1 ) << 1 ] - (
iodgoazcfv + hqh5ky5t2a [ 0 ] ) ) ; Vec_idx_0 = 0.0 ; localB -> arptmdt05w [
1 ] = rtP . BN [ ( ( ( ( int32_T ) encawndg2g - 1 ) << 2 ) + ( int32_T )
encawndg2g ) - 1 ] * ( P_hat_in [ ( ( b - 1 ) << 1 ) + 1 ] - ( keaen1whku +
hqh5ky5t2a [ 1 ] ) ) ; Vec_idx_1 = 0.0 ; b = ( int32_T ) encawndg2g ; for ( i
= 0 ; i < 4 ; i ++ ) { localB -> arptmdt05w [ 0 ] += rtP . AN [ ( ( i << 2 )
+ ( int32_T ) encawndg2g ) - 1 ] * ( P_hat_in [ ( b - 1 ) << 1 ] - ( P_hat_in
[ i << 1 ] + P_rel_local_in [ i << 1 ] ) ) ; Vec_idx_0 += rtP . H [ ( ( i <<
2 ) + ( int32_T ) encawndg2g ) - 1 ] * tau_in [ i << 1 ] ; localB ->
arptmdt05w [ 1 ] += ( P_hat_in [ ( ( b - 1 ) << 1 ) + 1 ] - ( P_hat_in [ ( i
<< 1 ) + 1 ] + P_rel_local_in [ ( i << 1 ) + 1 ] ) ) * rtP . AN [ ( ( i << 2
) + ( int32_T ) encawndg2g ) - 1 ] ; Vec_idx_1 += rtP . H [ ( ( i << 2 ) + (
int32_T ) encawndg2g ) - 1 ] * tau_in [ ( i << 1 ) + 1 ] ; } Vec_idx_0 /=
muDoubleScalarAbs ( Vec_idx_0 ) + rtP . alpha ; localB -> d1dlzas2mm [ 0 ] =
- ( rtP . Mu_P * localB -> arptmdt05w [ 0 ] ) - ( Vec_idx_0 * rtP . Mb_P [ 0
] + 0.0 * rtP . Mb_P [ 1 ] ) ; localB -> d1dlzas2mm [ 1 ] = - ( rtP . Mu_P *
localB -> arptmdt05w [ 1 ] ) - ( Vec_idx_1 / ( muDoubleScalarAbs ( Vec_idx_1
) + rtP . alpha ) * rtP . Mb_P [ 1 ] + 0.0 * rtP . Mb_P [ 0 ] ) ; } void
ew4afwvte5 ( const real_T nx51zxl44v [ 2 ] , const real_T eht1kzjsnz [ 2 ] ,
const real_T fyugyymaaf [ 2 ] , const real_T i1elytuqz5 [ 2 ] , const real_T
p1nucck3fq [ 2 ] , const real_T nbvsqmxnba [ 2 ] , const real_T hoiel5bjtr [
2 ] , const real_T evrhrqjnp0 [ 2 ] , const real_T enklap4tiu [ 2 ] , const
real_T amwl4upe3f [ 2 ] , const real_T gceiustsl0 [ 2 ] , const real_T
oczn0k3emj [ 2 ] , const real_T cfpvkhiape [ 2 ] , const real_T phjejfpjej [
2 ] , real_T evxod0y3rk , k0s5cnp1qe * localB ) { real_T P_hat_in [ 8 ] ;
real_T P_rel_local_in [ 8 ] ; real_T tau_in [ 8 ] ; int32_T i ; int32_T b ;
int32_T c ; real_T iypwx3a5dy [ 8 ] ; real_T ogilblnbzw [ 8 ] ; real_T
jm2rixjzsz [ 8 ] ; real_T mskz0ro2zs_data [ 8 ] ; int32_T i_p ; real_T
Vec_idx_0 ; real_T Vec_idx_1 ; iypwx3a5dy [ 0 ] = nx51zxl44v [ 0 ] ;
iypwx3a5dy [ 2 ] = eht1kzjsnz [ 0 ] ; iypwx3a5dy [ 4 ] = fyugyymaaf [ 0 ] ;
iypwx3a5dy [ 6 ] = i1elytuqz5 [ 0 ] ; ogilblnbzw [ 0 ] = p1nucck3fq [ 0 ] ;
ogilblnbzw [ 2 ] = nbvsqmxnba [ 0 ] ; ogilblnbzw [ 4 ] = hoiel5bjtr [ 0 ] ;
ogilblnbzw [ 6 ] = evrhrqjnp0 [ 0 ] ; jm2rixjzsz [ 0 ] = amwl4upe3f [ 0 ] ;
jm2rixjzsz [ 2 ] = gceiustsl0 [ 0 ] ; jm2rixjzsz [ 4 ] = oczn0k3emj [ 0 ] ;
jm2rixjzsz [ 6 ] = cfpvkhiape [ 0 ] ; iypwx3a5dy [ 1 ] = nx51zxl44v [ 1 ] ;
iypwx3a5dy [ 3 ] = eht1kzjsnz [ 1 ] ; iypwx3a5dy [ 5 ] = fyugyymaaf [ 1 ] ;
iypwx3a5dy [ 7 ] = i1elytuqz5 [ 1 ] ; ogilblnbzw [ 1 ] = p1nucck3fq [ 1 ] ;
ogilblnbzw [ 3 ] = nbvsqmxnba [ 1 ] ; ogilblnbzw [ 5 ] = hoiel5bjtr [ 1 ] ;
ogilblnbzw [ 7 ] = evrhrqjnp0 [ 1 ] ; jm2rixjzsz [ 1 ] = amwl4upe3f [ 1 ] ;
jm2rixjzsz [ 3 ] = gceiustsl0 [ 1 ] ; jm2rixjzsz [ 5 ] = oczn0k3emj [ 1 ] ;
jm2rixjzsz [ 7 ] = cfpvkhiape [ 1 ] ; for ( i = 0 ; i < 4 ; i ++ ) { b = i *
( int32_T ) mnw1ao5qgp ; c = ( 1 + i ) * ( int32_T ) mnw1ao5qgp ; if ( b + 1
> c ) { b = 0 ; c = 0 ; } c -= b ; for ( i_p = 0 ; i_p < c ; i_p ++ ) {
mskz0ro2zs_data [ i_p ] = iypwx3a5dy [ b + i_p ] ; } P_hat_in [ i << 1 ] =
mskz0ro2zs_data [ 0 ] ; P_hat_in [ 1 + ( i << 1 ) ] = mskz0ro2zs_data [ 1 ] ;
b = i * ( int32_T ) mnw1ao5qgp ; c = ( 1 + i ) * ( int32_T ) mnw1ao5qgp ; if
( b + 1 > c ) { b = 0 ; c = 0 ; } c -= b ; for ( i_p = 0 ; i_p < c ; i_p ++ )
{ mskz0ro2zs_data [ i_p ] = jm2rixjzsz [ b + i_p ] ; } P_rel_local_in [ i <<
1 ] = mskz0ro2zs_data [ 0 ] ; P_rel_local_in [ 1 + ( i << 1 ) ] =
mskz0ro2zs_data [ 1 ] ; b = i * ( int32_T ) mnw1ao5qgp ; c = ( 1 + i ) * (
int32_T ) mnw1ao5qgp ; if ( b + 1 > c ) { b = 0 ; c = 0 ; } c -= b ; for (
i_p = 0 ; i_p < c ; i_p ++ ) { mskz0ro2zs_data [ i_p ] = ogilblnbzw [ b + i_p
] ; } tau_in [ i << 1 ] = mskz0ro2zs_data [ 0 ] ; tau_in [ 1 + ( i << 1 ) ] =
mskz0ro2zs_data [ 1 ] ; } b = ( int32_T ) evxod0y3rk ; localB -> fyzqgebnzz [
0 ] = rtP . BN [ ( ( ( ( int32_T ) evxod0y3rk - 1 ) << 2 ) + ( int32_T )
evxod0y3rk ) - 1 ] * ( P_hat_in [ ( b - 1 ) << 1 ] - ( enklap4tiu [ 0 ] +
phjejfpjej [ 0 ] ) ) ; Vec_idx_0 = 0.0 ; localB -> fyzqgebnzz [ 1 ] = rtP .
BN [ ( ( ( ( int32_T ) evxod0y3rk - 1 ) << 2 ) + ( int32_T ) evxod0y3rk ) - 1
] * ( P_hat_in [ ( ( b - 1 ) << 1 ) + 1 ] - ( enklap4tiu [ 1 ] + phjejfpjej [
1 ] ) ) ; Vec_idx_1 = 0.0 ; b = ( int32_T ) evxod0y3rk ; for ( i = 0 ; i < 4
; i ++ ) { localB -> fyzqgebnzz [ 0 ] += rtP . AN [ ( ( i << 2 ) + ( int32_T
) evxod0y3rk ) - 1 ] * ( P_hat_in [ ( b - 1 ) << 1 ] - ( P_hat_in [ i << 1 ]
+ P_rel_local_in [ i << 1 ] ) ) ; Vec_idx_0 += rtP . H [ ( ( i << 2 ) + (
int32_T ) evxod0y3rk ) - 1 ] * tau_in [ i << 1 ] ; localB -> fyzqgebnzz [ 1 ]
+= ( P_hat_in [ ( ( b - 1 ) << 1 ) + 1 ] - ( P_hat_in [ ( i << 1 ) + 1 ] +
P_rel_local_in [ ( i << 1 ) + 1 ] ) ) * rtP . AN [ ( ( i << 2 ) + ( int32_T )
evxod0y3rk ) - 1 ] ; Vec_idx_1 += rtP . H [ ( ( i << 2 ) + ( int32_T )
evxod0y3rk ) - 1 ] * tau_in [ ( i << 1 ) + 1 ] ; } Vec_idx_0 /=
muDoubleScalarAbs ( Vec_idx_0 ) + rtP . alpha ; localB -> ntmpjrn1e1 [ 0 ] =
- ( rtP . Mu_V * localB -> fyzqgebnzz [ 0 ] ) - ( Vec_idx_0 * rtP . Mb_V [ 0
] + 0.0 * rtP . Mb_V [ 1 ] ) ; localB -> ntmpjrn1e1 [ 1 ] = - ( rtP . Mu_V *
localB -> fyzqgebnzz [ 1 ] ) - ( Vec_idx_1 / ( muDoubleScalarAbs ( Vec_idx_1
) + rtP . alpha ) * rtP . Mb_V [ 1 ] + 0.0 * rtP . Mb_V [ 0 ] ) ; } void
g0rn2igfkt ( const T_bus * e1vn4ulzpu , const epsilon_bus * d440o3ywrk ,
const real_T k4d4z5eppd [ 15 ] , const real_T izq5f24mr2 [ 15 ] , real_T
mbyuqbb0gq , m1hjhmjwg5 * localB ) { real_T Sum2 [ 15 ] ; int32_T i ;
hdbeuipdt4 b_T_struct [ 4 ] ; hdbeuipdt4 b_epsilon_struct [ 4 ] ; real_T y [
15 ] ; real_T d [ 9 ] ; static const int8_T b [ 16 ] = { 1 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static const int8_T c [ 16 ] =
{ 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 } ; int32_T
i_p ; real_T Sum2_p [ 15 ] ; for ( i_p = 0 ; i_p < 15 ; i_p ++ ) { b_T_struct
[ 0 ] . data [ i_p ] = e1vn4ulzpu -> t1 [ i_p ] ; b_T_struct [ 1 ] . data [
i_p ] = e1vn4ulzpu -> t2 [ i_p ] ; b_T_struct [ 2 ] . data [ i_p ] =
e1vn4ulzpu -> t3 [ i_p ] ; b_T_struct [ 3 ] . data [ i_p ] = e1vn4ulzpu -> t4
[ i_p ] ; b_epsilon_struct [ 0 ] . data [ i_p ] = d440o3ywrk -> eps1 [ i_p ]
; b_epsilon_struct [ 1 ] . data [ i_p ] = d440o3ywrk -> eps2 [ i_p ] ;
b_epsilon_struct [ 2 ] . data [ i_p ] = d440o3ywrk -> eps3 [ i_p ] ;
b_epsilon_struct [ 3 ] . data [ i_p ] = d440o3ywrk -> eps4 [ i_p ] ; localB
-> n4wcvzk1ua [ i_p ] = ( real_T ) b [ ( ( ( ( int32_T ) mbyuqbb0gq - 1 ) <<
2 ) + ( int32_T ) mbyuqbb0gq ) - 1 ] * ( k4d4z5eppd [ i_p ] - izq5f24mr2 [
i_p ] ) ; Sum2 [ i_p ] = 0.0 ; } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0
; i_p < 15 ; i_p ++ ) { localB -> n4wcvzk1ua [ i_p ] += ( real_T ) c [ ( ( i
<< 2 ) + ( int32_T ) mbyuqbb0gq ) - 1 ] * ( k4d4z5eppd [ i_p ] - b_T_struct [
i ] . data [ i_p ] ) ; Sum2 [ i_p ] += rtP . H [ ( ( ( int32_T ) mbyuqbb0gq -
1 ) << 2 ) + i ] * b_epsilon_struct [ i ] . data [ i_p ] ; } } for ( i = 0 ;
i < 15 ; i ++ ) { y [ i ] = muDoubleScalarAbs ( Sum2 [ i ] ) ; } memset ( & d
[ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 3 ; i ++ ) { d [ i +
3 * i ] = rtP . Upsilon_M [ i ] ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { Sum2_p
[ i_p + 5 * i ] = Sum2 [ 5 * i + i_p ] / ( y [ 5 * i + i_p ] + rtP . alpha )
; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0 ; i < 5 ; i ++ ) {
localB -> jtrbmpg3lt [ i + 5 * i_p ] = localB -> n4wcvzk1ua [ 5 * i_p + i ] *
- rtP . Observer_Gain1 - ( ( d [ 3 * i_p + 1 ] * Sum2_p [ i + 5 ] + d [ 3 *
i_p ] * Sum2_p [ i ] ) + d [ 3 * i_p + 2 ] * Sum2_p [ i + 10 ] ) ; } } }
static void hakwjia2pv ( const real_T a [ 9 ] , real_T c [ 9 ] ) { real_T x [
9 ] ; int32_T p1 ; int32_T p2 ; int32_T p3 ; real_T absx11 ; real_T absx21 ;
real_T absx31 ; int32_T itmp ; memcpy ( & x [ 0 ] , & a [ 0 ] , 9U * sizeof (
real_T ) ) ; p1 = 0 ; p2 = 3 ; p3 = 6 ; absx11 = muDoubleScalarAbs ( a [ 0 ]
) ; absx21 = muDoubleScalarAbs ( a [ 1 ] ) ; absx31 = muDoubleScalarAbs ( a [
2 ] ) ; if ( ( absx21 > absx11 ) && ( absx21 > absx31 ) ) { p1 = 3 ; p2 = 0 ;
x [ 0 ] = a [ 1 ] ; x [ 1 ] = a [ 0 ] ; x [ 3 ] = a [ 4 ] ; x [ 4 ] = a [ 3 ]
; x [ 6 ] = a [ 7 ] ; x [ 7 ] = a [ 6 ] ; } else { if ( absx31 > absx11 ) {
p1 = 6 ; p3 = 0 ; x [ 0 ] = a [ 2 ] ; x [ 2 ] = a [ 0 ] ; x [ 3 ] = a [ 5 ] ;
x [ 5 ] = a [ 3 ] ; x [ 6 ] = a [ 8 ] ; x [ 8 ] = a [ 6 ] ; } } absx11 = x [
1 ] / x [ 0 ] ; x [ 1 ] /= x [ 0 ] ; absx21 = x [ 2 ] / x [ 0 ] ; x [ 2 ] /=
x [ 0 ] ; x [ 4 ] -= absx11 * x [ 3 ] ; x [ 5 ] -= absx21 * x [ 3 ] ; x [ 7 ]
-= absx11 * x [ 6 ] ; x [ 8 ] -= absx21 * x [ 6 ] ; if ( muDoubleScalarAbs (
x [ 5 ] ) > muDoubleScalarAbs ( x [ 4 ] ) ) { itmp = p2 ; p2 = p3 ; p3 = itmp
; x [ 1 ] = absx21 ; x [ 2 ] = absx11 ; absx11 = x [ 4 ] ; x [ 4 ] = x [ 5 ]
; x [ 5 ] = absx11 ; absx11 = x [ 7 ] ; x [ 7 ] = x [ 8 ] ; x [ 8 ] = absx11
; } absx11 = x [ 5 ] / x [ 4 ] ; x [ 5 ] /= x [ 4 ] ; x [ 8 ] -= absx11 * x [
7 ] ; absx11 = ( x [ 5 ] * x [ 1 ] - x [ 2 ] ) / x [ 8 ] ; absx21 = - ( x [ 7
] * absx11 + x [ 1 ] ) / x [ 4 ] ; c [ p1 ] = ( ( 1.0 - x [ 3 ] * absx21 ) -
x [ 6 ] * absx11 ) / x [ 0 ] ; c [ p1 + 1 ] = absx21 ; c [ p1 + 2 ] = absx11
; absx11 = - x [ 5 ] / x [ 8 ] ; absx21 = ( 1.0 - x [ 7 ] * absx11 ) / x [ 4
] ; c [ p2 ] = - ( x [ 3 ] * absx21 + x [ 6 ] * absx11 ) / x [ 0 ] ; c [ p2 +
1 ] = absx21 ; c [ p2 + 2 ] = absx11 ; absx11 = 1.0 / x [ 8 ] ; absx21 = - x
[ 7 ] * absx11 / x [ 4 ] ; c [ p3 ] = - ( x [ 3 ] * absx21 + x [ 6 ] * absx11
) / x [ 0 ] ; c [ p3 + 1 ] = absx21 ; c [ p3 + 2 ] = absx11 ; } void
bifsfih4ms ( const real_T bv25vihqpg [ 12 ] , real_T eb1petavsd , real_T
ipfnyd1r1n , real_T dhr5u3poqu , real_T k4n1imnnsv , real_T hdyhmdlabm ,
awhjeott21 * localB ) { real_T F1 ; real_T F2 ; real_T F3 ; real_T F4 ;
real_T Rq [ 9 ] ; real_T EXT_PRD [ 3 ] ; real_T DP [ 3 ] ; real_T y ; real_T
x ; real_T b_x ; real_T tmp [ 9 ] ; real_T tmp_p [ 9 ] ; int32_T i ; real_T
tmp_e [ 3 ] ; real_T tmp_i [ 3 ] ; real_T tmp_m [ 3 ] ; real_T y_p [ 3 ] ;
real_T tmp_g ; F1 = eb1petavsd * eb1petavsd * rtP . Kf ; F2 = ipfnyd1r1n *
ipfnyd1r1n * rtP . Kf ; F3 = dhr5u3poqu * dhr5u3poqu * rtP . Kf ; F4 =
k4n1imnnsv * k4n1imnnsv * rtP . Kf ; Rq [ 0 ] = muDoubleScalarCos (
bv25vihqpg [ 5 ] ) * muDoubleScalarCos ( bv25vihqpg [ 4 ] ) ; Rq [ 3 ] =
muDoubleScalarCos ( bv25vihqpg [ 5 ] ) * muDoubleScalarSin ( bv25vihqpg [ 4 ]
) * muDoubleScalarSin ( bv25vihqpg [ 3 ] ) + - muDoubleScalarSin ( bv25vihqpg
[ 5 ] ) * muDoubleScalarCos ( bv25vihqpg [ 3 ] ) ; Rq [ 6 ] =
muDoubleScalarCos ( bv25vihqpg [ 5 ] ) * muDoubleScalarSin ( bv25vihqpg [ 4 ]
) * muDoubleScalarCos ( bv25vihqpg [ 3 ] ) + muDoubleScalarSin ( bv25vihqpg [
5 ] ) * muDoubleScalarSin ( bv25vihqpg [ 3 ] ) ; Rq [ 1 ] = muDoubleScalarSin
( bv25vihqpg [ 5 ] ) * muDoubleScalarCos ( bv25vihqpg [ 4 ] ) ; Rq [ 4 ] =
muDoubleScalarSin ( bv25vihqpg [ 5 ] ) * muDoubleScalarSin ( bv25vihqpg [ 4 ]
) * muDoubleScalarSin ( bv25vihqpg [ 3 ] ) + muDoubleScalarCos ( bv25vihqpg [
5 ] ) * muDoubleScalarCos ( bv25vihqpg [ 3 ] ) ; Rq [ 7 ] = muDoubleScalarSin
( bv25vihqpg [ 5 ] ) * muDoubleScalarSin ( bv25vihqpg [ 4 ] ) *
muDoubleScalarCos ( bv25vihqpg [ 3 ] ) + - muDoubleScalarCos ( bv25vihqpg [ 5
] ) * muDoubleScalarSin ( bv25vihqpg [ 3 ] ) ; Rq [ 2 ] = - muDoubleScalarSin
( bv25vihqpg [ 4 ] ) ; Rq [ 5 ] = muDoubleScalarCos ( bv25vihqpg [ 4 ] ) *
muDoubleScalarSin ( bv25vihqpg [ 3 ] ) ; Rq [ 8 ] = muDoubleScalarCos (
bv25vihqpg [ 4 ] ) * muDoubleScalarCos ( bv25vihqpg [ 3 ] ) ; for ( i = 0 ; i
< 3 ; i ++ ) { EXT_PRD [ i ] = 0.0 ; DP [ i ] = rtP . J [ i + 6 ] *
bv25vihqpg [ 11 ] + ( rtP . J [ i + 3 ] * bv25vihqpg [ 10 ] + rtP . J [ i ] *
bv25vihqpg [ 9 ] ) ; } EXT_PRD [ 1 ] = - ( bv25vihqpg [ 9 ] * DP [ 2 ] -
bv25vihqpg [ 11 ] * DP [ 0 ] ) ; EXT_PRD [ 0 ] = bv25vihqpg [ 9 ] * DP [ 1 ]
- bv25vihqpg [ 10 ] * DP [ 0 ] ; y = 1.0 / rtP . M ; x = muDoubleScalarSin (
hdyhmdlabm ) ; b_x = muDoubleScalarSin ( hdyhmdlabm ) ; tmp [ 0 ] = 1.0 ; tmp
[ 3 ] = 0.0 ; tmp [ 6 ] = - muDoubleScalarSin ( bv25vihqpg [ 4 ] ) ; tmp [ 1
] = 0.0 ; tmp [ 4 ] = muDoubleScalarCos ( bv25vihqpg [ 3 ] ) ; tmp [ 7 ] =
muDoubleScalarCos ( bv25vihqpg [ 4 ] ) * muDoubleScalarSin ( bv25vihqpg [ 3 ]
) ; tmp [ 2 ] = 0.0 ; tmp [ 5 ] = - muDoubleScalarSin ( bv25vihqpg [ 3 ] ) ;
tmp [ 8 ] = muDoubleScalarCos ( bv25vihqpg [ 4 ] ) * muDoubleScalarCos (
bv25vihqpg [ 3 ] ) ; hakwjia2pv ( tmp , tmp_p ) ; hakwjia2pv ( rtP . J , tmp
) ; tmp_g = ( ( F1 + F2 ) + F3 ) + F4 ; DP [ 0 ] = rtP . M * 0.0 ; DP [ 1 ] =
rtP . M * 0.0 ; DP [ 2 ] = rtP . M * rtP . g ; tmp_e [ 0 ] = ( F3 - F1 ) *
rtP . Lq ; tmp_e [ 1 ] = ( F4 - F2 ) * rtP . Lq ; tmp_e [ 2 ] = ( (
eb1petavsd * eb1petavsd * rtP . Kt - ipfnyd1r1n * ipfnyd1r1n * rtP . Kt ) +
dhr5u3poqu * dhr5u3poqu * rtP . Kt ) - k4n1imnnsv * k4n1imnnsv * rtP . Kt ;
for ( i = 0 ; i < 3 ; i ++ ) { tmp_i [ i ] = ( tmp_e [ i ] - bv25vihqpg [ 9 +
i ] * rtP . Ka ) - EXT_PRD [ i ] ; y_p [ i ] = ( ( ( ( Rq [ i + 3 ] * 0.0 +
Rq [ i ] * 0.0 ) + Rq [ i + 6 ] * tmp_g ) - bv25vihqpg [ 6 + i ] * rtP . Kd )
- DP [ i ] ) * y + ( ( Rq [ i + 3 ] * x * 0.0 + Rq [ i ] * x * 0.0 ) + Rq [ i
+ 6 ] * x ) ; tmp_m [ i ] = tmp_p [ i + 6 ] * bv25vihqpg [ 11 ] + ( tmp_p [ i
+ 3 ] * bv25vihqpg [ 10 ] + tmp_p [ i ] * bv25vihqpg [ 9 ] ) ; } for ( i = 0
; i < 3 ; i ++ ) { localB -> hpfjqszf4x [ i ] = bv25vihqpg [ 6 + i ] ; localB
-> hpfjqszf4x [ i + 3 ] = tmp_m [ i ] ; localB -> hpfjqszf4x [ i + 6 ] = y_p
[ i ] ; localB -> hpfjqszf4x [ i + 9 ] = ( ( tmp [ i + 3 ] * tmp_i [ 1 ] +
tmp [ i ] * tmp_i [ 0 ] ) + tmp [ i + 6 ] * tmp_i [ 2 ] ) + b_x ; } localB ->
kfb55nbxu2 = bv25vihqpg [ 2 ] ; localB -> k5iezadngg [ 0 ] = bv25vihqpg [ 0 ]
; localB -> atfess0a2f [ 0 ] = bv25vihqpg [ 6 ] ; localB -> jrp1fodqyr [ 0 ]
= localB -> hpfjqszf4x [ 6 ] ; localB -> k5iezadngg [ 1 ] = bv25vihqpg [ 1 ]
; localB -> atfess0a2f [ 1 ] = bv25vihqpg [ 7 ] ; localB -> jrp1fodqyr [ 1 ]
= localB -> hpfjqszf4x [ 7 ] ; } void onqykep2vg ( const real_T gxgrs5oabc [
2 ] , real_T exdyxrscw1 , const real_T jlmm4dc35p [ 2 ] , kvooenmmxs * localB
) { real_T a ; a = muDoubleScalarSign ( ( exdyxrscw1 * exdyxrscw1 - (
jlmm4dc35p [ 0 ] * jlmm4dc35p [ 0 ] + jlmm4dc35p [ 1 ] * jlmm4dc35p [ 1 ] ) )
* ( jlmm4dc35p [ 0 ] * gxgrs5oabc [ 0 ] + jlmm4dc35p [ 1 ] * gxgrs5oabc [ 1 ]
) ) * rtP . alpha_P + 1.0 ; localB -> go4wiq4kbo [ 0 ] = a * gxgrs5oabc [ 0 ]
; localB -> go4wiq4kbo [ 1 ] = a * gxgrs5oabc [ 1 ] ; } void ifmmcug2wn (
const real_T gouta4wgnp [ 2 ] , real_T bkjhjzemgo , const real_T p5y1kkldmx [
2 ] , jeft2nmhia * localB ) { real_T a ; a = muDoubleScalarSign ( (
bkjhjzemgo * bkjhjzemgo - ( p5y1kkldmx [ 0 ] * p5y1kkldmx [ 0 ] + p5y1kkldmx
[ 1 ] * p5y1kkldmx [ 1 ] ) ) * ( p5y1kkldmx [ 0 ] * gouta4wgnp [ 0 ] +
p5y1kkldmx [ 1 ] * gouta4wgnp [ 1 ] ) ) * rtP . alpha_V + 1.0 ; localB ->
fzjsuutou0 [ 0 ] = a * gouta4wgnp [ 0 ] ; localB -> fzjsuutou0 [ 1 ] = a *
gouta4wgnp [ 1 ] ; } void hp20ymhe1e ( real_T omx0naxsga , real_T mztud3dn4q
, const real_T p0hp0amzyt [ 2 ] , pmfwaobihs * localB ) { real_T a ; real_T
b_a ; a = p0hp0amzyt [ 0 ] - omx0naxsga ; b_a = p0hp0amzyt [ 1 ] - mztud3dn4q
; localB -> esbc0t1dta = a * a + b_a * b_a ; localB -> esbc0t1dta =
muDoubleScalarSqrt ( localB -> esbc0t1dta ) ; } void l1ggp544gs ( const
real_T cithc5btav [ 2 ] , const real_T iwqgu021ob [ 2 ] , m1ole03jfu * localB
) { real_T a ; real_T b_a ; a = iwqgu021ob [ 0 ] - cithc5btav [ 0 ] ; b_a =
iwqgu021ob [ 1 ] - cithc5btav [ 1 ] ; localB -> ortedkvoqi = a * a + b_a *
b_a ; localB -> ortedkvoqi = muDoubleScalarSqrt ( localB -> ortedkvoqi ) ; }
void akyqzm0njl ( const real_T bs0rg1tnta [ 36 ] , gxaahiqdto * localB ) {
real_T num ; int32_T i ; int32_T j ; memset ( & localB -> kh05gq2bif [ 0 ] ,
0 , 36U * sizeof ( real_T ) ) ; num = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) {
num ++ ; localB -> kh05gq2bif [ ( int32_T ) num - 1 ] = bs0rg1tnta [ i ] ;
for ( j = 0 ; j < 5 ; j ++ ) { num ++ ; localB -> kh05gq2bif [ ( int32_T )
num - 1 ] = bs0rg1tnta [ 6 * ( j + 1 ) + i ] ; } } } void bn5e2i2ijs ( const
real_T enht2u1u0h [ 15 ] , gor4c4smif * localB ) { real_T num ; int32_T i ;
memset ( & localB -> jemkrzqk3c [ 0 ] , 0 , 15U * sizeof ( real_T ) ) ; num =
0.0 ; for ( i = 0 ; i < 5 ; i ++ ) { num ++ ; localB -> jemkrzqk3c [ (
int32_T ) num - 1 ] = enht2u1u0h [ i ] ; num ++ ; localB -> jemkrzqk3c [ (
int32_T ) num - 1 ] = enht2u1u0h [ i + 5 ] ; num ++ ; localB -> jemkrzqk3c [
( int32_T ) num - 1 ] = enht2u1u0h [ i + 10 ] ; } } void iysmccme2o ( const
real_T hkksstn4f2 [ 2 ] , const real_T i5zqyudzmt [ 2 ] , ivinvzhydj * localB
) { real_T ABS ; if ( i5zqyudzmt [ 0 ] > 0.0 ) { ABS = i5zqyudzmt [ 0 ] ; }
else { ABS = - i5zqyudzmt [ 0 ] ; } localB -> g2qarspkxz [ 0 ] =
muDoubleScalarSqrt ( ABS ) ; localB -> g2qarspkxz [ 0 ] = hkksstn4f2 [ 0 ] -
i5zqyudzmt [ 0 ] / ( ABS + 0.01 ) * ( rtP . k1 * localB -> g2qarspkxz [ 0 ] )
; if ( i5zqyudzmt [ 1 ] > 0.0 ) { ABS = i5zqyudzmt [ 1 ] ; } else { ABS = -
i5zqyudzmt [ 1 ] ; } localB -> g2qarspkxz [ 1 ] = muDoubleScalarSqrt ( ABS )
; localB -> g2qarspkxz [ 1 ] = hkksstn4f2 [ 1 ] - i5zqyudzmt [ 1 ] / ( ABS +
0.01 ) * ( rtP . k1 * localB -> g2qarspkxz [ 1 ] ) ; } void eejedaxwca (
const real_T luzprktxbu [ 2 ] , eo1i0pkmfn * localB ) { if ( luzprktxbu [ 0 ]
> 0.0 ) { localB -> eup5e2ipsb [ 0 ] = luzprktxbu [ 0 ] ; } else { localB ->
eup5e2ipsb [ 0 ] = - luzprktxbu [ 0 ] ; } localB -> eup5e2ipsb [ 0 ] =
luzprktxbu [ 0 ] / ( localB -> eup5e2ipsb [ 0 ] + 0.01 ) * - rtP . k2 ; if (
luzprktxbu [ 1 ] > 0.0 ) { localB -> eup5e2ipsb [ 1 ] = luzprktxbu [ 1 ] ; }
else { localB -> eup5e2ipsb [ 1 ] = - luzprktxbu [ 1 ] ; } localB ->
eup5e2ipsb [ 1 ] = luzprktxbu [ 1 ] / ( localB -> eup5e2ipsb [ 1 ] + 0.01 ) *
- rtP . k2 ; } void MdlInitialize ( void ) { int32_T i ; for ( i = 0 ; i < 6
; i ++ ) { rtX . ionyxldtcw [ i ] = rtP . Integrator3_IC [ i ] ; } memcpy ( &
rtDW . ljf3bzpuxv [ 0 ] , & rtP . Memory2_InitialCondition [ 0 ] , 12U *
sizeof ( real_T ) ) ; rtX . jls05hpmo2 [ 0 ] = rtP . Integrator_IC [ 0 ] ;
rtX . jls05hpmo2 [ 1 ] = rtP . Integrator_IC [ 1 ] ; rtX . jls05hpmo2 [ 2 ] =
rtP . Integrator_IC [ 2 ] ; memcpy ( & rtX . mf3bhm1i2g [ 0 ] , & rtP .
Integrator5_IC [ 0 ] , 15U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++
) { rtDW . g1vhr4ol4w [ i ] = rtP . Memory_InitialCondition [ i ] ; rtX .
jhjq50hamr [ i ] = rtP . Integrator_IC_cfyiwll4yt [ i ] ; rtX . luz4nck343 [
i ] = rtP . Integrator1_IC [ i ] ; } memcpy ( & rtX . fwt4soxxlc [ 0 ] , &
rtP . Integrator1_IC_p4daeceqsz [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy (
& rtX . lmukmnay3o [ 0 ] , & rtP . Integrator_IC_luefkzx4q2 [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . oblwbzt05m [ i ] =
rtP . Integrator2_IC [ i ] ; rtX . mgsh4lifu4 [ i ] = rtP .
Integrator3_IC_f4caslm1kl [ i ] ; rtDW . p5cipt2vk2 [ i ] = rtP .
Memory_InitialCondition_o1obpzfklx [ i ] ; rtX . g4ve5h5vh2 [ i ] = rtP .
Integrator_IC_puas1ar3n0 [ i ] ; rtX . mc4ye23acv [ i ] = rtP .
Integrator1_IC_jmeepbpmgb [ i ] ; } memcpy ( & rtX . pusmj51k2o [ 0 ] , & rtP
. Integrator1_IC_ansfzl4d2f [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . oh4v0qnmbl [ 0 ] , & rtP . Integrator_IC_g3bsi3eu3w [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . i0ozzqeoz4 [ i ] =
rtP . Integrator2_IC_dbnyypfy52 [ i ] ; } rtX . gttal13ne4 = rtP .
Integrator_IC_alldriazdb ; rtX . lhg5uf35jg = rtP . Integrator1_IC_mwmzuv30pe
; rtDW . gutf3fahtc = rtP . Memory2_InitialCondition_or5foxlh2c ; rtX .
jyxqpcbioa [ 0 ] = rtP . Integrator1_IC_lhgdj0vm4i [ 0 ] ; rtX . f5podaplbs [
0 ] = rtP . Integrator2_IC_inq5mdqzms [ 0 ] ; rtX . jyxqpcbioa [ 1 ] = rtP .
Integrator1_IC_lhgdj0vm4i [ 1 ] ; rtX . f5podaplbs [ 1 ] = rtP .
Integrator2_IC_inq5mdqzms [ 1 ] ; memcpy ( & rtX . armybl4b3j [ 0 ] , & rtP .
Integrator_IC_h34fkmtcfd [ 0 ] , 12U * sizeof ( real_T ) ) ; rtDW .
l0nq3lmdeg [ 0 ] = rtP . Memory_InitialCondition_j0f1njy0lm [ 0 ] ; rtDW .
i1hjxzs31f [ 0 ] = rtP . Memory1_InitialCondition [ 0 ] ; rtX . omoyscdlkq [
0 ] = rtP . Integrator1_IC_jwivcicess [ 0 ] ; rtX . bvv2j1fvkj [ 0 ] = rtP .
Integrator1_IC_buluaviyk2 [ 0 ] ; rtX . jyfm4clkt1 [ 0 ] = rtP .
Integrator1_IC_fmwjvqa0ff [ 0 ] ; rtDW . gjvtrlsfwe [ 0 ] = rtP .
Memory_InitialCondition_e5i1evne12 [ 0 ] ; rtDW . pzvvqboa5v [ 0 ] = rtP .
Memory_InitialCondition_c4k5ozqenb [ 0 ] ; rtDW . orrbrxbq10 [ 0 ] = rtP .
Memory_InitialCondition_pzkv5ibku3 [ 0 ] ; rtX . an1dy1scdv [ 0 ] = rtP .
Integrator2_IC_luckixqhsj [ 0 ] ; rtX . ajilevaypm [ 0 ] = rtP .
Integrator2_IC_l52mdbixg1 [ 0 ] ; rtX . ndnjgxlg32 [ 0 ] = rtP .
Integrator2_IC_eackpwye4n [ 0 ] ; rtX . mampjjggm5 [ 0 ] = rtP .
Integrator2_IC_ozsu04xgc2 [ 0 ] ; rtDW . ldao3hyxar [ 0 ] = rtP .
Memory3_InitialCondition [ 0 ] ; rtDW . o4urslscxv [ 0 ] = rtP .
Memory_InitialCondition_a54hsbpodr [ 0 ] ; rtX . c1zyhspvvj [ 0 ] = rtP .
Integrator2_IC_b4dyjqfehg [ 0 ] ; rtX . bozttf3lme [ 0 ] = rtP .
Integrator2_IC_gqrhtfqr04 [ 0 ] ; rtX . lu2z2r1bq1 [ 0 ] = rtP .
Integrator2_IC_frwewj40xa [ 0 ] ; rtDW . biuieiqmxp [ 0 ] = rtP .
Memory1_InitialCondition_jn0l5tcosh [ 0 ] ; rtDW . kxmjiaeunc [ 0 ] = rtP .
Memory1_InitialCondition_mouimmo5pb [ 0 ] ; rtDW . gq1mgiuwz2 [ 0 ] = rtP .
Memory1_InitialCondition_msgkygoak0 [ 0 ] ; rtX . au25a2kq45 [ 0 ] = rtP .
Integrator_IC_bb2yzpjx1c [ 0 ] ; rtX . n1g43fm50u [ 0 ] = rtP .
Integrator1_IC_dlyjrsv10d [ 0 ] ; rtX . jjhfp4nquz [ 0 ] = rtP .
Integrator1_IC_jknekxlqkt [ 0 ] ; rtX . j0sputa12i [ 0 ] = rtP .
Integrator1_IC_jhcbpibgpz [ 0 ] ; rtX . bpzbkldlw5 [ 0 ] = rtP .
Integrator1_IC_ccghmuj11r [ 0 ] ; rtX . djt2dez0wq [ 0 ] = rtP .
Integrator1_IC_ma130clpzn [ 0 ] ; rtDW . l0nq3lmdeg [ 1 ] = rtP .
Memory_InitialCondition_j0f1njy0lm [ 1 ] ; rtDW . i1hjxzs31f [ 1 ] = rtP .
Memory1_InitialCondition [ 1 ] ; rtX . omoyscdlkq [ 1 ] = rtP .
Integrator1_IC_jwivcicess [ 1 ] ; rtX . bvv2j1fvkj [ 1 ] = rtP .
Integrator1_IC_buluaviyk2 [ 1 ] ; rtX . jyfm4clkt1 [ 1 ] = rtP .
Integrator1_IC_fmwjvqa0ff [ 1 ] ; rtDW . gjvtrlsfwe [ 1 ] = rtP .
Memory_InitialCondition_e5i1evne12 [ 1 ] ; rtDW . pzvvqboa5v [ 1 ] = rtP .
Memory_InitialCondition_c4k5ozqenb [ 1 ] ; rtDW . orrbrxbq10 [ 1 ] = rtP .
Memory_InitialCondition_pzkv5ibku3 [ 1 ] ; rtX . an1dy1scdv [ 1 ] = rtP .
Integrator2_IC_luckixqhsj [ 1 ] ; rtX . ajilevaypm [ 1 ] = rtP .
Integrator2_IC_l52mdbixg1 [ 1 ] ; rtX . ndnjgxlg32 [ 1 ] = rtP .
Integrator2_IC_eackpwye4n [ 1 ] ; rtX . mampjjggm5 [ 1 ] = rtP .
Integrator2_IC_ozsu04xgc2 [ 1 ] ; rtDW . ldao3hyxar [ 1 ] = rtP .
Memory3_InitialCondition [ 1 ] ; rtDW . o4urslscxv [ 1 ] = rtP .
Memory_InitialCondition_a54hsbpodr [ 1 ] ; rtX . c1zyhspvvj [ 1 ] = rtP .
Integrator2_IC_b4dyjqfehg [ 1 ] ; rtX . bozttf3lme [ 1 ] = rtP .
Integrator2_IC_gqrhtfqr04 [ 1 ] ; rtX . lu2z2r1bq1 [ 1 ] = rtP .
Integrator2_IC_frwewj40xa [ 1 ] ; rtDW . biuieiqmxp [ 1 ] = rtP .
Memory1_InitialCondition_jn0l5tcosh [ 1 ] ; rtDW . kxmjiaeunc [ 1 ] = rtP .
Memory1_InitialCondition_mouimmo5pb [ 1 ] ; rtDW . gq1mgiuwz2 [ 1 ] = rtP .
Memory1_InitialCondition_msgkygoak0 [ 1 ] ; rtX . au25a2kq45 [ 1 ] = rtP .
Integrator_IC_bb2yzpjx1c [ 1 ] ; rtX . n1g43fm50u [ 1 ] = rtP .
Integrator1_IC_dlyjrsv10d [ 1 ] ; rtX . jjhfp4nquz [ 1 ] = rtP .
Integrator1_IC_jknekxlqkt [ 1 ] ; rtX . j0sputa12i [ 1 ] = rtP .
Integrator1_IC_jhcbpibgpz [ 1 ] ; rtX . bpzbkldlw5 [ 1 ] = rtP .
Integrator1_IC_ccghmuj11r [ 1 ] ; rtX . djt2dez0wq [ 1 ] = rtP .
Integrator1_IC_ma130clpzn [ 1 ] ; memcpy ( & rtX . chv5h33ild [ 0 ] , & rtP .
Integrator5_IC_g5vs3m5xow [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtX
. f5c0yrpl0m [ 0 ] , & rtP . Integrator5_IC_nvscsito40 [ 0 ] , 15U * sizeof (
real_T ) ) ; memcpy ( & rtX . jee34x0zc4 [ 0 ] , & rtP .
Integrator5_IC_i1zdqa2rj1 [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtDW
. lwlz3gfxgb [ 0 ] , & rtP . Memory3_InitialCondition_df5j2apngc [ 0 ] , 15U
* sizeof ( real_T ) ) ; memcpy ( & rtDW . ekvleb1gcq [ 0 ] , & rtP .
Memory3_InitialCondition_il5t0irnrb [ 0 ] , 15U * sizeof ( real_T ) ) ;
memcpy ( & rtDW . k3kw4exkgg [ 0 ] , & rtP .
Memory3_InitialCondition_hjfhfwrpya [ 0 ] , 15U * sizeof ( real_T ) ) ;
memcpy ( & rtDW . cr0y2nzbkc [ 0 ] , & rtP .
Memory3_InitialCondition_iydqxjne5u [ 0 ] , 15U * sizeof ( real_T ) ) ; rtDW
. eftcuoxcfp [ 0 ] = rtP . Memory_InitialCondition_fm40pkxs2j [ 0 ] ; rtX .
im051m03c0 [ 0 ] = rtP . Integrator_IC_jm5bas01zb [ 0 ] ; rtX . ossqjsfts4 [
0 ] = rtP . Integrator_IC_hf52glxiva [ 0 ] ; rtX . ivslgspzyl [ 0 ] = rtP .
Integrator_IC_heikj2oluh [ 0 ] ; rtDW . bdxxdlvg4e [ 0 ] = rtP .
Memory_InitialCondition_mfuzsoq04q [ 0 ] ; rtDW . l34b1ws24z [ 0 ] = rtP .
Memory_InitialCondition_ceftgwwddl [ 0 ] ; rtDW . lbl43aynsc [ 0 ] = rtP .
Memory_InitialCondition_e1qx5hl0e5 [ 0 ] ; rtDW . eftcuoxcfp [ 1 ] = rtP .
Memory_InitialCondition_fm40pkxs2j [ 1 ] ; rtX . im051m03c0 [ 1 ] = rtP .
Integrator_IC_jm5bas01zb [ 1 ] ; rtX . ossqjsfts4 [ 1 ] = rtP .
Integrator_IC_hf52glxiva [ 1 ] ; rtX . ivslgspzyl [ 1 ] = rtP .
Integrator_IC_heikj2oluh [ 1 ] ; rtDW . bdxxdlvg4e [ 1 ] = rtP .
Memory_InitialCondition_mfuzsoq04q [ 1 ] ; rtDW . l34b1ws24z [ 1 ] = rtP .
Memory_InitialCondition_ceftgwwddl [ 1 ] ; rtDW . lbl43aynsc [ 1 ] = rtP .
Memory_InitialCondition_e1qx5hl0e5 [ 1 ] ; rtDW . eftcuoxcfp [ 2 ] = rtP .
Memory_InitialCondition_fm40pkxs2j [ 2 ] ; rtX . im051m03c0 [ 2 ] = rtP .
Integrator_IC_jm5bas01zb [ 2 ] ; rtX . ossqjsfts4 [ 2 ] = rtP .
Integrator_IC_hf52glxiva [ 2 ] ; rtX . ivslgspzyl [ 2 ] = rtP .
Integrator_IC_heikj2oluh [ 2 ] ; rtDW . bdxxdlvg4e [ 2 ] = rtP .
Memory_InitialCondition_mfuzsoq04q [ 2 ] ; rtDW . l34b1ws24z [ 2 ] = rtP .
Memory_InitialCondition_ceftgwwddl [ 2 ] ; rtDW . lbl43aynsc [ 2 ] = rtP .
Memory_InitialCondition_e1qx5hl0e5 [ 2 ] ; rtX . hiamj1oevs = rtP .
Integrator1_IC_pqkea5opj5 ; rtX . gx3o1bpm3a = rtP . Integrator_IC_gppaao1n14
; rtX . joe5wc3vru = rtP . Integrator1_IC_jo4u2yf5bh ; rtX . belilpb3dk = rtP
. Integrator_IC_m1rvafnpvi ; rtX . bxlordfjyp = rtP .
Integrator1_IC_juteqbkjag ; rtX . mva2o1cupz = rtP . Integrator_IC_przqtc044z
; rtX . lmqns2m2fd = rtP . Integrator1_IC_ap5ygu2w0o ; rtX . du3cl5u2br = rtP
. Integrator_IC_murofkqkz0 ; rtDW . euwquc1ohh [ 0 ] = rtP .
Memory1_InitialCondition_pueehz5zfr [ 0 ] ; rtX . gtdwc5tdzv [ 0 ] = rtP .
Integrator_IC_immn4e5mqy [ 0 ] ; rtX . cg2tzvhg1s [ 0 ] = rtP .
Integrator1_IC_nnr4vlcuc2 [ 0 ] ; rtDW . kb1zmmywdq [ 0 ] = rtP .
Memory_InitialCondition_g42qsp0l1h [ 0 ] ; rtDW . nsyupx5qza [ 0 ] = rtP .
Memory1_InitialCondition_gelzc052fw [ 0 ] ; rtDW . mfzuy1fnjf [ 0 ] = rtP .
Memory_InitialCondition_nt0x1sjcbl [ 0 ] ; rtDW . meq4arbagn [ 0 ] = rtP .
Memory1_InitialCondition_ogwkymdxxn [ 0 ] ; rtDW . elhi3coyqa [ 0 ] = rtP .
Memory_InitialCondition_kvnigjfe1g [ 0 ] ; rtDW . cb4caomchi [ 0 ] = rtP .
Memory1_InitialCondition_on2mrgcv1u [ 0 ] ; rtDW . euwquc1ohh [ 1 ] = rtP .
Memory1_InitialCondition_pueehz5zfr [ 1 ] ; rtX . gtdwc5tdzv [ 1 ] = rtP .
Integrator_IC_immn4e5mqy [ 1 ] ; rtX . cg2tzvhg1s [ 1 ] = rtP .
Integrator1_IC_nnr4vlcuc2 [ 1 ] ; rtDW . kb1zmmywdq [ 1 ] = rtP .
Memory_InitialCondition_g42qsp0l1h [ 1 ] ; rtDW . nsyupx5qza [ 1 ] = rtP .
Memory1_InitialCondition_gelzc052fw [ 1 ] ; rtDW . mfzuy1fnjf [ 1 ] = rtP .
Memory_InitialCondition_nt0x1sjcbl [ 1 ] ; rtDW . meq4arbagn [ 1 ] = rtP .
Memory1_InitialCondition_ogwkymdxxn [ 1 ] ; rtDW . elhi3coyqa [ 1 ] = rtP .
Memory_InitialCondition_kvnigjfe1g [ 1 ] ; rtDW . cb4caomchi [ 1 ] = rtP .
Memory1_InitialCondition_on2mrgcv1u [ 1 ] ; for ( i = 0 ; i < 6 ; i ++ ) {
rtX . aqayeibnbf [ i ] = rtP . Integrator3_IC_bat4zspnyz [ i ] ; } memcpy ( &
rtDW . njybh3xjqw [ 0 ] , & rtP . Memory2_InitialCondition_cllveugtjf [ 0 ] ,
12U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtDW . hdkreqmds2
[ i ] = rtP . Memory_InitialCondition_mnixxfx3nr [ i ] ; rtX . mnhjgksiva [ i
] = rtP . Integrator_IC_la40lha0dg [ i ] ; rtX . p5euhzgph2 [ i ] = rtP .
Integrator1_IC_bvirkw3omb [ i ] ; } memcpy ( & rtX . nsygkjz001 [ 0 ] , & rtP
. Integrator1_IC_eusbq4wn0r [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . pyssp52j4v [ 0 ] , & rtP . Integrator_IC_irtz3fkjrz [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . fig1xy4s5q [ i ] =
rtP . Integrator2_IC_azzaqyagzs [ i ] ; rtX . lovsimzfsp [ i ] = rtP .
Integrator3_IC_hcz3efl52b [ i ] ; rtDW . k5rawm0exp [ i ] = rtP .
Memory_InitialCondition_kch2d0yyuo [ i ] ; rtX . dvkhmbnof2 [ i ] = rtP .
Integrator_IC_ccbgpins5s [ i ] ; rtX . gqi2mgds2b [ i ] = rtP .
Integrator1_IC_pthm2elxch [ i ] ; } memcpy ( & rtX . ppo5lvnsbd [ 0 ] , & rtP
. Integrator1_IC_c3juh3gqkf [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . aslzbhpikx [ 0 ] , & rtP . Integrator_IC_jxexmo2voq [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . m20bb5px11 [ i ] =
rtP . Integrator2_IC_hxbmyx5eah [ i ] ; } rtX . dmaqihaxaq = rtP .
Integrator_IC_m32gmcozch ; rtX . dsaqs0egeg = rtP . Integrator1_IC_jgedvswz2a
; rtDW . eb005l0rcc = rtP . Memory2_InitialCondition_mvgnd5dmek ; memcpy ( &
rtX . hj3xpt5hh3 [ 0 ] , & rtP . Integrator_IC_jawnn4hfs5 [ 0 ] , 12U *
sizeof ( real_T ) ) ; rtX . fmtqkgzjo2 [ 0 ] = rtP .
Integrator2_IC_at433khehz [ 0 ] ; rtX . eqlst0fie1 [ 0 ] = rtP .
Integrator2_IC_cta555k1jf [ 0 ] ; rtX . jhyl0nmftj [ 0 ] = rtP .
Integrator2_IC_ayj33d1kgk [ 0 ] ; rtX . dufp23q24f [ 0 ] = rtP .
Integrator2_IC_ixgs0iiwuj [ 0 ] ; rtDW . jhqxxzie31 [ 0 ] = rtP .
Memory3_InitialCondition_ak45y034mz [ 0 ] ; rtX . e5bm4mxp4y [ 0 ] = rtP .
Integrator1_IC_jw3s5b3wbf [ 0 ] ; rtX . d2zjdsdy3t [ 0 ] = rtP .
Integrator1_IC_mnm25x5z0c [ 0 ] ; rtX . atdwxldcaa [ 0 ] = rtP .
Integrator1_IC_bog1m1eab0 [ 0 ] ; rtX . kdrbhkothr [ 0 ] = rtP .
Integrator1_IC_cgdc4o0005 [ 0 ] ; rtX . fmtqkgzjo2 [ 1 ] = rtP .
Integrator2_IC_at433khehz [ 1 ] ; rtX . eqlst0fie1 [ 1 ] = rtP .
Integrator2_IC_cta555k1jf [ 1 ] ; rtX . jhyl0nmftj [ 1 ] = rtP .
Integrator2_IC_ayj33d1kgk [ 1 ] ; rtX . dufp23q24f [ 1 ] = rtP .
Integrator2_IC_ixgs0iiwuj [ 1 ] ; rtDW . jhqxxzie31 [ 1 ] = rtP .
Memory3_InitialCondition_ak45y034mz [ 1 ] ; rtX . e5bm4mxp4y [ 1 ] = rtP .
Integrator1_IC_jw3s5b3wbf [ 1 ] ; rtX . d2zjdsdy3t [ 1 ] = rtP .
Integrator1_IC_mnm25x5z0c [ 1 ] ; rtX . atdwxldcaa [ 1 ] = rtP .
Integrator1_IC_bog1m1eab0 [ 1 ] ; rtX . kdrbhkothr [ 1 ] = rtP .
Integrator1_IC_cgdc4o0005 [ 1 ] ; rtX . l1nyqmvwst = rtP .
Integrator1_IC_galmbeklcp ; rtX . ca2tchanai = rtP . Integrator_IC_lqe0iyuxyo
; rtX . ooketywe0t = rtP . Integrator1_IC_fx0ci3hz34 ; rtX . mjw0keqmwr = rtP
. Integrator_IC_hr1rckzr4f ; rtX . fb0bskoedk = rtP .
Integrator1_IC_bzcdkgnkfw ; rtX . phfjeo0drc = rtP . Integrator_IC_hfcstb1haw
; rtX . d0fq4dyqzm = rtP . Integrator1_IC_ocig5embg4 ; rtX . irfwmkoozp = rtP
. Integrator_IC_dtb4wwgoan ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . gfix1az2dy
[ i ] = rtP . Integrator3_IC_pjrjnyinks [ i ] ; } memcpy ( & rtDW .
oywwglvnbw [ 0 ] , & rtP . Memory2_InitialCondition_ox3hrrh33c [ 0 ] , 12U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ekk5eebzqc [ i ]
= rtP . Memory_InitialCondition_kojwdv1sdm [ i ] ; rtX . lajj3kiv0r [ i ] =
rtP . Integrator_IC_a5nuunpklh [ i ] ; rtX . musq314bsn [ i ] = rtP .
Integrator1_IC_lta2vdh0b5 [ i ] ; } memcpy ( & rtX . oljl1r15sy [ 0 ] , & rtP
. Integrator1_IC_jl3wybgxkk [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . kdjra2pfq4 [ 0 ] , & rtP . Integrator_IC_fvj1kiy40w [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . ox0f0pxtqm [ i ] =
rtP . Integrator2_IC_datw0m0fum [ i ] ; rtX . eu121u4uj2 [ i ] = rtP .
Integrator3_IC_atv2wvjo44 [ i ] ; rtDW . mec2hevem0 [ i ] = rtP .
Memory_InitialCondition_oimiahzldu [ i ] ; rtX . bgjp3vzt5z [ i ] = rtP .
Integrator_IC_cqcfpzgjin [ i ] ; rtX . dn5twkxizj [ i ] = rtP .
Integrator1_IC_bopood34gi [ i ] ; } memcpy ( & rtX . eeiannul5v [ 0 ] , & rtP
. Integrator1_IC_p2dirrdsf0 [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . czjyxcctju [ 0 ] , & rtP . Integrator_IC_ltadafrs2p [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . m0wpx0tt4b [ i ] =
rtP . Integrator2_IC_culhmos0yl [ i ] ; } rtX . kr3nejsoss = rtP .
Integrator_IC_jpe5v3shtd ; rtX . jclkuzenpd = rtP . Integrator1_IC_ekqbzs401u
; rtDW . gx01drbeka = rtP . Memory2_InitialCondition_hek5amttia ; memcpy ( &
rtX . bpmgvfdh3p [ 0 ] , & rtP . Integrator_IC_gzbylzelej [ 0 ] , 12U *
sizeof ( real_T ) ) ; rtX . ntmiect20q [ 0 ] = rtP .
Integrator2_IC_nxpf2pqtyt [ 0 ] ; rtX . nw2qbjtrfg [ 0 ] = rtP .
Integrator2_IC_pib2yu51bl [ 0 ] ; rtX . eysiy0scrq [ 0 ] = rtP .
Integrator2_IC_pywmt1vi3k [ 0 ] ; rtX . cyoaoohsr1 [ 0 ] = rtP .
Integrator2_IC_nlyzfo2eo2 [ 0 ] ; rtDW . c1300gzrjt [ 0 ] = rtP .
Memory3_InitialCondition_fm5muett4l [ 0 ] ; rtX . d5kjlwmgrk [ 0 ] = rtP .
Integrator1_IC_gsbwkeuy32 [ 0 ] ; rtX . i1zsver5ig [ 0 ] = rtP .
Integrator1_IC_j55wlx1pla [ 0 ] ; rtX . llgwidxzty [ 0 ] = rtP .
Integrator1_IC_d2dmy2bonh [ 0 ] ; rtX . dcluu2qq0c [ 0 ] = rtP .
Integrator1_IC_ne5nj2sehc [ 0 ] ; rtX . ntmiect20q [ 1 ] = rtP .
Integrator2_IC_nxpf2pqtyt [ 1 ] ; rtX . nw2qbjtrfg [ 1 ] = rtP .
Integrator2_IC_pib2yu51bl [ 1 ] ; rtX . eysiy0scrq [ 1 ] = rtP .
Integrator2_IC_pywmt1vi3k [ 1 ] ; rtX . cyoaoohsr1 [ 1 ] = rtP .
Integrator2_IC_nlyzfo2eo2 [ 1 ] ; rtDW . c1300gzrjt [ 1 ] = rtP .
Memory3_InitialCondition_fm5muett4l [ 1 ] ; rtX . d5kjlwmgrk [ 1 ] = rtP .
Integrator1_IC_gsbwkeuy32 [ 1 ] ; rtX . i1zsver5ig [ 1 ] = rtP .
Integrator1_IC_j55wlx1pla [ 1 ] ; rtX . llgwidxzty [ 1 ] = rtP .
Integrator1_IC_d2dmy2bonh [ 1 ] ; rtX . dcluu2qq0c [ 1 ] = rtP .
Integrator1_IC_ne5nj2sehc [ 1 ] ; rtX . mfmirsuvi1 = rtP .
Integrator1_IC_oy1tpyez4k ; rtX . ajtyxihfqa = rtP . Integrator_IC_ja4tf50vgl
; rtX . fev21ha45i = rtP . Integrator1_IC_minhdvdh30 ; rtX . daodwibywh = rtP
. Integrator_IC_dld3rufdd5 ; rtX . lkyqetg5kb = rtP .
Integrator1_IC_br0lavttge ; rtX . btc4odj1vw = rtP . Integrator_IC_etl3cet4i2
; rtX . c0pmpkzruv = rtP . Integrator1_IC_b5usglq0ml ; rtX . jlansep42b = rtP
. Integrator_IC_b2w1tqip2f ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . lbivgbnpeh
[ i ] = rtP . Integrator3_IC_hkv2shesyg [ i ] ; } memcpy ( & rtDW .
kbb0qw5mp3 [ 0 ] , & rtP . Memory2_InitialCondition_dsgb11uldn [ 0 ] , 12U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ppddj1qhga [ i ]
= rtP . Memory_InitialCondition_nxqwvrpsn1 [ i ] ; rtX . m54hyt4uuq [ i ] =
rtP . Integrator_IC_kix2wy0eko [ i ] ; rtX . lxl24bgnmj [ i ] = rtP .
Integrator1_IC_arlagfg51h [ i ] ; } memcpy ( & rtX . efyhshm0ot [ 0 ] , & rtP
. Integrator1_IC_odxe20ktyc [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . gdfmrn5gpc [ 0 ] , & rtP . Integrator_IC_mvuvpk12n1 [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . jbncktdjxo [ i ] =
rtP . Integrator2_IC_hyg2lufwlm [ i ] ; rtX . kwvqencn2m [ i ] = rtP .
Integrator3_IC_ph5vo1wzew [ i ] ; rtDW . igxhj4adkf [ i ] = rtP .
Memory_InitialCondition_ksrwjf202x [ i ] ; rtX . el0s1crasb [ i ] = rtP .
Integrator_IC_emuquk5caa [ i ] ; rtX . iiijpho0bw [ i ] = rtP .
Integrator1_IC_bjc5tuilet [ i ] ; } memcpy ( & rtX . ef5r0lp3ux [ 0 ] , & rtP
. Integrator1_IC_bobsrkoroo [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . iuw551xzyz [ 0 ] , & rtP . Integrator_IC_ogv01dnfdg [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . fqk1pcxz11 [ i ] =
rtP . Integrator2_IC_m1d2qyymbe [ i ] ; } rtX . guiwz4qjqi = rtP .
Integrator_IC_owq0oqmk1f ; rtX . nvrhieikes = rtP . Integrator1_IC_nih23smxre
; rtDW . kiivcdig1l = rtP . Memory2_InitialCondition_d2b5f3zpoa ; memcpy ( &
rtX . p3bnpoi4ms [ 0 ] , & rtP . Integrator_IC_fl4lytvimx [ 0 ] , 12U *
sizeof ( real_T ) ) ; rtX . fat2ntucmp [ 0 ] = rtP .
Integrator2_IC_mbl4x3euf4 [ 0 ] ; rtX . f23ygfhi2f [ 0 ] = rtP .
Integrator2_IC_dcmgupiz3t [ 0 ] ; rtX . jl5u0so5kr [ 0 ] = rtP .
Integrator2_IC_ksdgd0umq4 [ 0 ] ; rtX . m4oor1dqcu [ 0 ] = rtP .
Integrator2_IC_ediny1ej1a [ 0 ] ; rtDW . jpwsqsteoo [ 0 ] = rtP .
Memory3_InitialCondition_ieed2vz1s2 [ 0 ] ; rtX . edonk3lpof [ 0 ] = rtP .
Integrator1_IC_kd3xpoijkg [ 0 ] ; rtX . c2d4vnjngq [ 0 ] = rtP .
Integrator1_IC_kesvi0bnff [ 0 ] ; rtX . ixb5n0f1pg [ 0 ] = rtP .
Integrator1_IC_oa0pqhkumw [ 0 ] ; rtX . mvd25m5wxn [ 0 ] = rtP .
Integrator1_IC_ng3itygk5x [ 0 ] ; rtX . fat2ntucmp [ 1 ] = rtP .
Integrator2_IC_mbl4x3euf4 [ 1 ] ; rtX . f23ygfhi2f [ 1 ] = rtP .
Integrator2_IC_dcmgupiz3t [ 1 ] ; rtX . jl5u0so5kr [ 1 ] = rtP .
Integrator2_IC_ksdgd0umq4 [ 1 ] ; rtX . m4oor1dqcu [ 1 ] = rtP .
Integrator2_IC_ediny1ej1a [ 1 ] ; rtDW . jpwsqsteoo [ 1 ] = rtP .
Memory3_InitialCondition_ieed2vz1s2 [ 1 ] ; rtX . edonk3lpof [ 1 ] = rtP .
Integrator1_IC_kd3xpoijkg [ 1 ] ; rtX . c2d4vnjngq [ 1 ] = rtP .
Integrator1_IC_kesvi0bnff [ 1 ] ; rtX . ixb5n0f1pg [ 1 ] = rtP .
Integrator1_IC_oa0pqhkumw [ 1 ] ; rtX . mvd25m5wxn [ 1 ] = rtP .
Integrator1_IC_ng3itygk5x [ 1 ] ; rtX . axapvnuown = rtP .
Integrator1_IC_hypargdhjw ; rtX . fk4euimlnu = rtP . Integrator_IC_oxt3eyodwq
; rtX . gvdlmv0f2h = rtP . Integrator1_IC_cyyevy5f4u ; rtX . g4o2mykdy0 = rtP
. Integrator_IC_fnbynjhgz2 ; rtX . ms3jvyzwa2 = rtP .
Integrator1_IC_btfuanhu4f ; rtX . hftm5kpfrm = rtP . Integrator_IC_f2beosksxv
; rtX . a0vktynhmg = rtP . Integrator1_IC_ofl0ycjsiu ; rtX . ok1bkcbj54 = rtP
. Integrator_IC_ptvmn4pn2v ; rtX . f0gxn5lxra = 0.0 ; } void MdlStart ( void
) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = (
NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const char *
errorCreatingOSigstreamManager = ( NULL ) ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ) ; if (
errorCreatingOSigstreamManager != ( NULL ) ) { * pOSigstreamManagerAddr = (
NULL ) ; ssSetErrorStatus ( rtS , errorCreatingOSigstreamManager ) ; return ;
} } { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 ,
sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . kxnrq3j5gh . Tail = 0
; rtDW . kxnrq3j5gh . Head = 0 ; rtDW . kxnrq3j5gh . Last = 0 ; rtDW .
kxnrq3j5gh . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
ir3tccey2d . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
ir3tccey2d . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . f4c4a4mj3p . Tail = 0
; rtDW . f4c4a4mj3p . Head = 0 ; rtDW . f4c4a4mj3p . Last = 0 ; rtDW .
f4c4a4mj3p . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
mahzin5xie . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
mahzin5xie . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . hflmn5zw4g . Tail = 0
; rtDW . hflmn5zw4g . Head = 0 ; rtDW . hflmn5zw4g . Last = 0 ; rtDW .
hflmn5zw4g . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
em4ieblqdo . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
em4ieblqdo . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . ogn0tnbje1 . Tail = 0
; rtDW . ogn0tnbje1 . Head = 0 ; rtDW . ogn0tnbje1 . Last = 0 ; rtDW .
ogn0tnbje1 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_jipm0sgfem ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . cp2wd3yek3 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
cp2wd3yek3 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . lyazy3gnn2 . Tail = 0
; rtDW . lyazy3gnn2 . Head = 0 ; rtDW . lyazy3gnn2 . Last = 0 ; rtDW .
lyazy3gnn2 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_io3d45ar21 ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . nuyw1oa5lu . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
nuyw1oa5lu . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . je3z34ckbn . Tail = 0
; rtDW . je3z34ckbn . Head = 0 ; rtDW . je3z34ckbn . Last = 0 ; rtDW .
je3z34ckbn . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput_kznqd41xd4 ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . ongfcz4dhf . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
ongfcz4dhf . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . fyo23snxav . Tail = 0
; rtDW . fyo23snxav . Head = 0 ; rtDW . fyo23snxav . Last = 0 ; rtDW .
fyo23snxav . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_irtprymfig ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . jzm2uqh05o . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
jzm2uqh05o . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . b4ivhh52o2 . Tail = 0
; rtDW . b4ivhh52o2 . Head = 0 ; rtDW . b4ivhh52o2 . Last = 0 ; rtDW .
b4ivhh52o2 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput_lmsg2pl2kj ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . kim1kgtcyq . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
kim1kgtcyq . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . j5kjeh2fcr . Tail = 0
; rtDW . j5kjeh2fcr . Head = 0 ; rtDW . j5kjeh2fcr . Last = 0 ; rtDW .
j5kjeh2fcr . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_mvsywcmphq ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . e0iyas1xpb . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
e0iyas1xpb . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . fckn41cqic . Tail = 0
; rtDW . fckn41cqic . Head = 0 ; rtDW . fckn41cqic . Last = 0 ; rtDW .
fckn41cqic . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput_gcfy4mzc0f ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . gcbrh04vlv . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
gcbrh04vlv . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } {
static int_T rt_ToWksWidths [ ] = { 15 } ; static int_T rt_ToWksNumDimensions
[ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 15 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = {
( NULL ) } ; static const char_T * rt_ToWksLabels [ ] = { "" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot10/To Workspace" ;
rtDW . cku5zcj5in . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "T3" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . cku5zcj5in . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 15 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
15 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot11/To Workspace" ;
rtDW . cdsdbyqqzu . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "T4" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . cdsdbyqqzu . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 15 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
15 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot8/To Workspace" ;
rtDW . j5tckppox0 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "T1" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . j5tckppox0 . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 15 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
15 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot9/To Workspace" ;
rtDW . eywuoilqki . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "T2" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . eywuoilqki . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 15 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
15 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot12/To Workspace" ;
rtDW . pmas04mzh3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "epsilon1" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . pmas04mzh3 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 15
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 15 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot13/To Workspace" ;
rtDW . lhbec2ip5d . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "epsilon2" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . lhbec2ip5d .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 15
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 15 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot14/To Workspace" ;
rtDW . nyqddap2e3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "epsilon3" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . nyqddap2e3 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 15
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 15 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /For matrix Plot15/To Workspace" ;
rtDW . h0qwwidrrt . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "epsilon4" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . h0qwwidrrt .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 3 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope20" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . hugbzsrs2a . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "q1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . hugbzsrs2a . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope21" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . mi55warbfl . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "q2" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . mi55warbfl . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope22" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . cr4rc4zkjl . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "q3" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . cr4rc4zkjl . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope23" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . lif3zndlrk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "q4" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . lif3zndlrk . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope14" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . dqsdd0iav1 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "e3" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . dqsdd0iav1 . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope15" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . jtrbooxbd3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "e4" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . jtrbooxbd3 . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope12" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . cjri132aia . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "e1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . cjri132aia . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope13" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . lusxtmzcjz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "e2" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . lusxtmzcjz . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 12 } ; static int_T rt_ScopeSignalNumDimensions
[ ] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 12 } ; static
void * rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" } ; static char_T rt_ScopeSignalTitles [ ] =
"" ; static int_T rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope18" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . nujtkogswx . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "x3" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . nujtkogswx . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 12 } ; static int_T rt_ScopeSignalNumDimensions
[ ] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 12 } ; static
void * rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" } ; static char_T rt_ScopeSignalTitles [ ] =
"" ; static int_T rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope19" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . o4dhmx5qrq . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "x4" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . o4dhmx5qrq . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 12 } ; static int_T rt_ScopeSignalNumDimensions
[ ] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 12 } ; static
void * rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" } ; static char_T rt_ScopeSignalTitles [ ] =
"" ; static int_T rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope16" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . jqjkpgnny2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "x1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . jqjkpgnny2 . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 12 } ; static int_T rt_ScopeSignalNumDimensions
[ ] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 12 } ; static
void * rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" } ; static char_T rt_ScopeSignalTitles [ ] =
"" ; static int_T rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope17" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . dl3c4wd40p . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "x2" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . dl3c4wd40p . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope4" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . bhza4smniz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "tau1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . bhza4smniz . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope5" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . m5vo5zrdwd . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "tau2" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . m5vo5zrdwd . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope6" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . j44z1n4syw . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "tau3" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . j44z1n4syw . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Scope7" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fqe3wzj2rm . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "tau4" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . fqe3wzj2rm . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot/To Workspace"
; rtDW . mweg4p0tza . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P1_T" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . mweg4p0tza . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot1/To Workspace"
; rtDW . lmqaiznxh2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P2_T" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . lmqaiznxh2 . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot16/To Workspace"
; rtDW . btfxhaa12b . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P1_R" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . btfxhaa12b . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot17/To Workspace"
; rtDW . dvgadtng5f . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P2_R" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . dvgadtng5f . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot18/To Workspace"
; rtDW . o1tss2hntz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P3_R" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . o1tss2hntz . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot19/To Workspace"
; rtDW . c2pncb15ww . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P4_R" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . c2pncb15ww . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot2/To Workspace"
; rtDW . gau0w0subc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P3_T" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . gau0w0subc . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot20/To Workspace"
; rtDW . gf3gsxu3l0 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat1_R" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . gf3gsxu3l0 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot21/To Workspace"
; rtDW . ml2ga241wu . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat2_R" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ml2ga241wu .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot22/To Workspace"
; rtDW . ptdrnn4gkj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat3_R" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ptdrnn4gkj .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot23/To Workspace"
; rtDW . egvebj0vzk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat4_R" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . egvebj0vzk .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot3/To Workspace"
; rtDW . azxrx1pbjx . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P4_T" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo
, rt_ToWksBlockName ) ; if ( rtDW . azxrx1pbjx . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 36 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
36 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot4/To Workspace"
; rtDW . kqv43bmmbb . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat1_T" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . kqv43bmmbb .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot5/To Workspace"
; rtDW . pnnupo15gj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat2_T" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . pnnupo15gj .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot6/To Workspace"
; rtDW . m5pscv5mzf . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat3_T" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . m5pscv5mzf .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 36
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 36 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/For matrix Plot7/To Workspace"
; rtDW . e1dat3np50 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "A_hat4_T" , 1 , 0 , 1 , 0.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . e1dat3np50 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . jesgoxpysk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat1_T" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jesgoxpysk .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope33"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . bxokau5rly . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat1_R" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . bxokau5rly .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope34"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ikckvftlj0 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat2_R" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ikckvftlj0 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope35"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . kuf1r1iib1 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat3_R" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . kuf1r1iib1 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope36"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . dzd50qusdc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat4_R" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . dzd50qusdc .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope1"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . hxmfmxbxzg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat2_T" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . hxmfmxbxzg .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope27"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . b31ricvahq . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u1_T" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . b31ricvahq . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope28"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . k5v5nydhl2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u2_T" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . k5v5nydhl2 . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope29"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . aszo4opjoq . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u3_T" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . aszo4opjoq . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope30"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . gk5p53h1wj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u4_T" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . gk5p53h1wj . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope37"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . lu4iopse32 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u1_R" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . lu4iopse32 . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope38"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . knsumlziop . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u2_R" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . knsumlziop . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope39"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ky1g0helic . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u3_R" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . ky1g0helic . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope40"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fvoj0brkji . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "u4_R" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . fvoj0brkji . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope2"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . dkoo4kcfaj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat3_T" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . dkoo4kcfaj .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 6 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Communications for controllers/Scope3"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . i5grh4jmh3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "g_hat4_T" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . i5grh4jmh3 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope12"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . pdkyev51db . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pdkyev51db .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope15"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . i4dnzdgvyj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err4" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . i4dnzdgvyj .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope5"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . jzughaiexw . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P1_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jzughaiexw .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope6"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . jeazhlxihn . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P2_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jeazhlxihn .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope7"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fhvzke4cet . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P3_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fhvzke4cet .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope8"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . j50ebbuydy . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "P4_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . j50ebbuydy .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope10"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . mxwnv4z2lq . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_P3" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . mxwnv4z2lq .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope11"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . g15tyxojey . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_P4" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . g15tyxojey .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope20"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . f4mz54thlc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_P2" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . f4mz54thlc .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope9"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . oiwwfvr1a5 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_P1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . oiwwfvr1a5 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope16"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . lh0nbilqnw . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos1_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . lh0nbilqnw .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope17"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fj5wqp1pom . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos2_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fj5wqp1pom .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope18"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . onngtoccwk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos3_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . onngtoccwk .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope13"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ozyfkr2biz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err2" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ozyfkr2biz .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope19"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . bzo2lxtcos . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos4_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . bzo2lxtcos .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope26"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . gjzrj5vwzi . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "V1_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . gjzrj5vwzi .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope27"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . o54vw4q3ry . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "V2_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . o54vw4q3ry .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope28"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . esfmkot2gm . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "V3_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . esfmkot2gm .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope29"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fwolkb0vlk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "V4_hat_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fwolkb0vlk .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope23"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . orxq3kojbg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_V3" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . orxq3kojbg .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope24"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ovq0d1ceac . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_V4" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ovq0d1ceac .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope25"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fup4sk0rmj . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_V2" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fup4sk0rmj .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope30"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . g5difolfpk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Tau_V1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . g5difolfpk .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope1"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . j1krmqotmd . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos1_Z" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . j1krmqotmd .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope31"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . mpaolyryto . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . mpaolyryto .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope34"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . kabuwjql3m . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err4" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . kabuwjql3m .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope35"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fng5gfijxe . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel1_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fng5gfijxe .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope2"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . az4riutx0n . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos2_Z" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . az4riutx0n .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope36"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . pw42vsjs5z . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel2_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pw42vsjs5z .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope37"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ieqghgs4hk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel3_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ieqghgs4hk .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope32"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . cd4funmbby . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err2" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . cd4funmbby .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope38"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ahjraffioz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel4_XY" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ahjraffioz .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope3"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . cvspglvkum . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos3_Z" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . cvspglvkum .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope33"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . cwywqcfbrn . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err3" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . cwywqcfbrn .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope4"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . kjacqpc401 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos4_Z" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . kjacqpc401 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
 "Cooperative_Quad_09_VelEst_02/Data Bus /Coomunications for localization/Scope14"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . pa44p12zb2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err3" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pa44p12zb2 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Scope1" ;
static int_T rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ;
rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo .
numDims = rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . pywvylisvs . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Ref" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . pywvylisvs . LoggedData [ 0 ] == ( NULL )
) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Scope26" ;
static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . itaaab0kng . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . itaaab0kng .
LoggedData == ( NULL ) ) return ; } { { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . jkuwdaephj . Tail = 0 ; rtDW . jkuwdaephj . Head = 0 ; rtDW .
jkuwdaephj . Last = 0 ; rtDW . jkuwdaephj . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay2_InitOutput_hl0tfnim04 ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; rtDW . aoi2q222df . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . aoi2q222df . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * )
calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 6 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . p0dm4cko3k . TimePtr = fromwksInfo
-> time ; rtDW . p0dm4cko3k . DataPtr = fromwksInfo -> data ; rtDW .
p0dm4cko3k . RSimInfoPtr = fromwksInfo ; } rtDW . i42enhfwq5 . PrevIndex = 0
; { int_T * zcTimeIndices = & rtDW . fm531h0dfy [ 0 ] ; const double *
timePoints = ( double * ) rtDW . p0dm4cko3k . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 6 - 1 ;
i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ] ) {
zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . ary12ruqzb = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_X" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
puereonu00 . TimePtr = fromwksInfo -> time ; rtDW . puereonu00 . DataPtr =
fromwksInfo -> data ; rtDW . puereonu00 . RSimInfoPtr = fromwksInfo ; } rtDW
. hjvjlcfeww . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Y" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace1_Time0 ; rtDW
. iwwdwmgwmf . TimePtr = fromwksInfo -> time ; rtDW . iwwdwmgwmf . DataPtr =
fromwksInfo -> data ; rtDW . iwwdwmgwmf . RSimInfoPtr = fromwksInfo ; } rtDW
. l1lz31mbjt . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Z" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace3_Time0 ; rtDW
. drrrzdfjw3 . TimePtr = fromwksInfo -> time ; rtDW . drrrzdfjw3 . DataPtr =
fromwksInfo -> data ; rtDW . drrrzdfjw3 . RSimInfoPtr = fromwksInfo ; } rtDW
. bawkp25aax . PrevIndex = 0 ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 2 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ;
static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 , 4 } ; static const
char_T * rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] =
"Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Subsystem1/Scope2"
; static int_T rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals =
3 ; rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo
. numDims = rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . mjdday0cuw . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Ref_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . mjdday0cuw .
LoggedData [ 0 ] == ( NULL ) ) return ; } MdlInitialize ( ) ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } } void MdlOutputs ( int_T tid ) {
T_bus hkxtd2yqjg ; T_bus lanqfvssdm ; T_bus kob0ibjlgv ; T_bus hue2gx3vel ;
real_T osd5bxpstb [ 6 ] ; real_T khu3wekibw ; real_T c10xsvgo14 ; real_T
mk2kwho04h [ 15 ] ; real_T o4cbbaxgvp [ 6 ] ; real_T i2ywewpy23 [ 6 ] ;
real_T l4uoo2mfo4 [ 36 ] ; real_T i0pfjcbccz [ 36 ] ; real_T ctwsuok4do [ 6 ]
; real_T fwwibk2gqx [ 6 ] ; real_T ngtk3krag1 [ 6 ] ; real_T minlglel5f [ 6 ]
; real_T axxzmwrdb1 [ 36 ] ; real_T oz3y0ehsly [ 36 ] ; real_T pfg3fpzt01 ;
real_T lxkqalaokb ; real_T g0yerdzy4e [ 2 ] ; real_T j32hx2yjlk [ 2 ] ;
real_T f1fl5j3sr1 [ 2 ] ; real_T bvvaglfnyg [ 2 ] ; real_T jruuzkvv4x [ 2 ] ;
real_T bgjulh42sn [ 2 ] ; real_T kjpnkazon3 [ 2 ] ; real_T muz343ptzl [ 2 ] ;
real_T ognna4atll [ 2 ] ; real_T dkplwwqhlq [ 2 ] ; real_T ft1p4me3if [ 15 ]
; real_T bcehnxyd3h [ 15 ] ; real_T myowtlscss [ 15 ] ; real_T kderxbgjob [
15 ] ; real_T ibg3dwhse0 [ 15 ] ; real_T fnkf1abqw5 [ 15 ] ; real_T
pk1hppghip [ 15 ] ; real_T cajljq2wjj ; real_T mprhv4gcwl ; real_T mnr4evnmg5
; real_T gnayzxxwhh [ 2 ] ; real_T d4m4v5phyn [ 2 ] ; real_T dyrfriuf53 [ 2 ]
; real_T epi5h543uq ; real_T gkeiwcjlga ; real_T m1qgpyagnk ; real_T
lyp5lcgplc ; real_T mted2snvh3 ; real_T fub54w4kmy ; real_T makrbjzw3u [ 6 ]
; real_T abgyidwyxb ; real_T csfv2uibob ; real_T bhc0g2tr1b [ 6 ] ; real_T
hhsezyptna [ 6 ] ; real_T fpbyp3gnlt [ 36 ] ; real_T hifhopdemn [ 36 ] ;
real_T pyfwtl3j0a [ 6 ] ; real_T p3ubxu5hwv [ 6 ] ; real_T n4lxva3wkp [ 6 ] ;
real_T kfglakgeuu [ 6 ] ; real_T o4hmshkh13 [ 36 ] ; real_T ppmcvosloc [ 36 ]
; real_T k0x1jfr1ix ; real_T p1mc2go3l4 ; real_T gbjfazf2je [ 2 ] ; real_T
agfcgsovpn [ 2 ] ; real_T mctw4f5pif [ 2 ] ; real_T meapna2wrq [ 2 ] ; real_T
buvtunq30h [ 2 ] ; real_T fbmoupq1qk [ 2 ] ; real_T b3qjlp2a05 [ 2 ] ; real_T
mr30ur40cd [ 2 ] ; real_T gabmlgsqlv ; real_T ktxr5ga4nn ; real_T gflar2srxf
; real_T hnnw2hujma [ 2 ] ; real_T e30wrenqhp ; real_T hlk05ayvhp ; real_T
eq1eix1lpn ; real_T hizdkkioqb ; real_T mfvoeip4zj ; real_T es2otmhxnl ;
real_T m5jtfekt2h [ 6 ] ; real_T k5arailkcv ; real_T iidkxpk2kt ; real_T
j1fevedgmn [ 6 ] ; real_T igwfvnz3vs [ 6 ] ; real_T eqhsiqgube [ 36 ] ;
real_T cmxgtuqnwg [ 36 ] ; real_T cojthb5n01 [ 6 ] ; real_T jvbvctwmjc [ 6 ]
; real_T oujugd4xou [ 6 ] ; real_T f3tjt1n2uw [ 6 ] ; real_T asjv0xjmii [ 36
] ; real_T hceboz13qc [ 36 ] ; real_T cqeiqxau2e ; real_T e4pkw5vin4 ; real_T
p4ux2p5zld [ 2 ] ; real_T dlbvbal5em [ 2 ] ; real_T mn0cep4xml [ 2 ] ; real_T
hwanmflst1 [ 2 ] ; real_T dioxq0k1s2 [ 2 ] ; real_T ngodd0lb2l [ 2 ] ; real_T
d5pt2aombs [ 2 ] ; real_T d0n3jvuzli [ 2 ] ; real_T opqefn2kjs ; real_T
mmucqnnnoe ; real_T jsyspemnzc ; real_T clizedqd12 [ 2 ] ; real_T ejuilkyqm0
; real_T ahff4el43j ; real_T f4sgkgovmw ; real_T hadxatt5uc ; real_T
hzqungsokc ; real_T kjsm5iare5 ; real_T kevdovkfex [ 6 ] ; real_T c1isjfsich
; real_T doxfufmtfc ; real_T da3asulki1 [ 6 ] ; real_T a0zewajuko [ 6 ] ;
real_T ewjuw2ilww [ 36 ] ; real_T g3tawas44r [ 36 ] ; real_T hb2wqxwtnz [ 6 ]
; real_T hkyzlc0yxi [ 6 ] ; real_T nkxdy02403 [ 6 ] ; real_T de5pktfu00 [ 6 ]
; real_T afwyumpfjk [ 36 ] ; real_T lwby3kv103 [ 36 ] ; real_T owsbtwq0e0 ;
real_T egrxutye5g ; real_T aoe4zh2mj2 [ 2 ] ; real_T lrzsifyq0e [ 2 ] ;
real_T nbzg4ig4di [ 2 ] ; real_T gd0aup02ek [ 2 ] ; real_T ocfqrkadip [ 2 ] ;
real_T ncs31u0ld2 [ 2 ] ; real_T nzppf3gsca [ 2 ] ; real_T nwevcd1hd3 [ 2 ] ;
real_T hqsfqbo3wu ; real_T py5tr2btjw ; real_T abqgyjydct ; real_T exvktcaqkj
[ 2 ] ; real_T lseqequu0d ; real_T pkzoi1pdsa ; real_T lpn0hnh5du ; real_T
o0qnvkc3xx ; real_T ha3stdwxjl ; real_T bdonqro1qr ; real_T mbhupmv1uh ;
real_T gpsgjm1xmt ; real_T miumiqeamo ; real_T ixtkvycozy ; real_T ikri1d1nmq
[ 15 ] ; int32_T b ; int32_T c ; real_T b_d [ 9 ] ; static const int8_T l [
16 ] = { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static const int8_T m [ 16 ] = { 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 ,
1 , 0 , 0 , 1 , 0 } ; static const int8_T l_p [ 16 ] = { 1 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static const int8_T m_p [ 16 ]
= { 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 } ; static
const int8_T l_e [ 16 ] = { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static const int8_T m_e [ 16 ] = { 0 , 1 , 0 , 0 , 1 , 0 , 1
, 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 } ; static const int8_T l_i [ 16 ] = { 1
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static const
int8_T m_i [ 16 ] = { 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 0 ,
1 , 0 } ; real_T bv0exnxaiw ; real_T biumkvvuc1 ; real_T nat0cpttuo ; real_T
mza03d5fve [ 12 ] ; real_T dhuhfjmuec [ 12 ] ; int32_T i ; int8_T b_data [ 12
] ; int32_T i_p ; for ( i = 0 ; i < 6 ; i ++ ) { osd5bxpstb [ i ] = rtX .
ionyxldtcw [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & rtB .
hoefupodzc [ 0 ] , & rtDW . ljf3bzpuxv [ 0 ] , 12U * sizeof ( real_T ) ) ; }
{ real_T * * uBuffer = ( real_T * * ) & rtDW . ir3tccey2d . TUbufferPtrs [ 0
] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ir3tccey2d . TUbufferPtrs [
1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay ; khu3wekibw = rt_TDelayInterpolate ( tMinusDelay , 0.0
, * tBuffer , * uBuffer , rtDW . kxnrq3j5gh . CircularBufSize , & rtDW .
kxnrq3j5gh . Last , rtDW . kxnrq3j5gh . Tail , rtDW . kxnrq3j5gh . Head , rtP
. TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS )
&& ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . mahzin5xie . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . mahzin5xie . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay2_Delay ; c10xsvgo14 = rt_TDelayInterpolate ( tMinusDelay , 0.0
, * tBuffer , * uBuffer , rtDW . f4c4a4mj3p . CircularBufSize , & rtDW .
f4c4a4mj3p . Last , rtDW . f4c4a4mj3p . Tail , rtDW . f4c4a4mj3p . Head , rtP
. TransportDelay2_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS )
&& ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
cbz53iqiop [ 0 ] = rtX . jls05hpmo2 [ 0 ] ; rtB . cbz53iqiop [ 1 ] = rtX .
jls05hpmo2 [ 1 ] ; rtB . cbz53iqiop [ 2 ] = rtX . jls05hpmo2 [ 2 ] ; memcpy (
& mk2kwho04h [ 0 ] , & rtX . mf3bhm1i2g [ 0 ] , 15U * sizeof ( real_T ) ) ;
my0xtyxafz ( rtB . cbz53iqiop , mk2kwho04h , rtP . Agent_Value , & rtB .
elri1t014b ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i
++ ) { rtB . cltq0cfb00 [ i ] = rtDW . g1vhr4ol4w [ i ] ; } } nnvj0nbsr4 (
rtB . hoefupodzc , khu3wekibw , c10xsvgo14 , rtB . elri1t014b . hia3u3mq0v [
2 ] , rtB . cltq0cfb00 , & rtB . dtk02osx1k ) ; for ( i = 0 ; i < 6 ; i ++ )
{ o4cbbaxgvp [ i ] = osd5bxpstb [ i ] + rtB . dtk02osx1k . admi3yqyf0 [ i ] ;
i2ywewpy23 [ i ] = rtX . jhjq50hamr [ i ] ; rtB . cri1kl2qhs [ i ] = rtX .
luz4nck343 [ i ] - rtB . dtk02osx1k . gtmlnhqoq0 [ i ] ; } d4w44phvgb (
i2ywewpy23 , rtB . cri1kl2qhs , & rtB . nfjyzad3my ) ; memcpy ( & l4uoo2mfo4
[ 0 ] , & rtX . fwt4soxxlc [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
i0pfjcbccz [ 0 ] , & rtX . lmukmnay3o [ 0 ] , 36U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 6 ; i ++ ) { rtB . haamgpyyku [ i ] = rtX . oblwbzt05m [ i ] ;
} jvlvilab4w ( o4cbbaxgvp , osd5bxpstb , rtB . nfjyzad3my . hg1x1nd45k ,
l4uoo2mfo4 , i0pfjcbccz , rtB . haamgpyyku , rtB . dtk02osx1k . jaolq3jrhd ,
& rtB . m2f3uzhfsg ) ; ihouus1chq ( rtB . m2f3uzhfsg . m0i0p0mohd , & rtB .
ia0kb0ljog ) ; for ( i = 0 ; i < 6 ; i ++ ) { ctwsuok4do [ i ] = rtX .
mgsh4lifu4 [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . naukoivzmr [ i ] = rtDW . p5cipt2vk2 [ i ] ; } }
m1hec3vrd2 ( rtB . hoefupodzc , rtB . ia0kb0ljog . gwmh5422nv , rtB .
naukoivzmr , & rtB . bydx3i5iwd ) ; for ( i = 0 ; i < 6 ; i ++ ) { fwwibk2gqx
[ i ] = ctwsuok4do [ i ] + rtB . bydx3i5iwd . jl4fbhrop1 [ i ] ; ngtk3krag1 [
i ] = rtX . g4ve5h5vh2 [ i ] ; minlglel5f [ i ] = rtX . mc4ye23acv [ i ] -
rtB . bydx3i5iwd . j1zyuz5kzg [ i ] ; } l3dvuo1xw3 ( ngtk3krag1 , minlglel5f
, & rtB . eetjt415xo ) ; memcpy ( & axxzmwrdb1 [ 0 ] , & rtX . pusmj51k2o [ 0
] , 36U * sizeof ( real_T ) ) ; memcpy ( & oz3y0ehsly [ 0 ] , & rtX .
oh4v0qnmbl [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
rtB . nlsv5ptysw [ i ] = rtX . i0ozzqeoz4 [ i ] ; } jvlvilab4w ( fwwibk2gqx ,
ctwsuok4do , rtB . eetjt415xo . l5c2p5rmcp , axxzmwrdb1 , oz3y0ehsly , rtB .
nlsv5ptysw , rtB . bydx3i5iwd . dzda0l3ztv , & rtB . euig1sdxae ) ;
g4g4bdu0ia ( rtB . ia0kb0ljog . hw5tnzrodd , rtB . euig1sdxae . m0i0p0mohd ,
& rtB . eo0mj2ipwy ) ; ijextzfzou ( axxzmwrdb1 , oz3y0ehsly , & rtB .
eu03stat4s ) ; lgndixfdt3 ( minlglel5f , & rtB . kuuq0qawad ) ; lvvcxitelq (
fwwibk2gqx , rtB . nlsv5ptysw , axxzmwrdb1 , & rtB . nqkvnie0as ) ;
bmxkvlwnui ( fwwibk2gqx , rtB . bydx3i5iwd . dzda0l3ztv , axxzmwrdb1 ,
oz3y0ehsly , & rtB . b4e1ilqhrp ) ; bmxkvlwnui ( o4cbbaxgvp , rtB .
dtk02osx1k . jaolq3jrhd , l4uoo2mfo4 , i0pfjcbccz , & rtB . otvyyn5pvr ) ;
ijextzfzou ( l4uoo2mfo4 , i0pfjcbccz , & rtB . ikvvizl300 ) ; lgndixfdt3 (
rtB . cri1kl2qhs , & rtB . fbwflwjjvm ) ; lvvcxitelq ( o4cbbaxgvp , rtB .
haamgpyyku , l4uoo2mfo4 , & rtB . jisefsiylr ) ; pfg3fpzt01 = rtX .
gttal13ne4 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fsylupg2ie = rtDW .
gutf3fahtc ; } lxkqalaokb = rtX . lhg5uf35jg - rtB . fsylupg2ie ; lunmotda0s
( pfg3fpzt01 , lxkqalaokb , & rtB . ngb4hyklf3 ) ; c3hsf3zf4q ( lxkqalaokb ,
& rtB . kaxep214he ) ; rtB . ovp54ku00f [ 0 ] = rtX . jyxqpcbioa [ 0 ] ; rtB
. guii4af3w0 [ 0 ] = rtX . f5podaplbs [ 0 ] ; rtB . ovp54ku00f [ 1 ] = rtX .
jyxqpcbioa [ 1 ] ; rtB . guii4af3w0 [ 1 ] = rtX . f5podaplbs [ 1 ] ; memcpy (
& rtB . j2lsirb0ej [ 0 ] , & rtX . armybl4b3j [ 0 ] , 12U * sizeof ( real_T )
) ; hwodfh00oh ( rtB . j2lsirb0ej , rtB . ovp54ku00f , rtB . fsylupg2ie , rtB
. guii4af3w0 , rtB . ngb4hyklf3 . mxe5eu4hb4 , & rtB . gi0uwyfhqp ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fyll5jdjjj [ 0 ] = rtDW . l0nq3lmdeg
[ 0 ] ; rtB . mka13uwfw0 [ 0 ] = rtDW . i1hjxzs31f [ 0 ] ; rtB . fyll5jdjjj [
1 ] = rtDW . l0nq3lmdeg [ 1 ] ; rtB . mka13uwfw0 [ 1 ] = rtDW . i1hjxzs31f [
1 ] ; rtB . obobcozbfh [ 0 ] = rtDW . gjvtrlsfwe [ 0 ] ; rtB . kthfd0aif2 [ 0
] = rtDW . pzvvqboa5v [ 0 ] ; rtB . n1skxybgba [ 0 ] = rtDW . orrbrxbq10 [ 0
] ; rtB . obobcozbfh [ 1 ] = rtDW . gjvtrlsfwe [ 1 ] ; rtB . kthfd0aif2 [ 1 ]
= rtDW . pzvvqboa5v [ 1 ] ; rtB . n1skxybgba [ 1 ] = rtDW . orrbrxbq10 [ 1 ]
; } rtB . au5wbjjqt3 [ 0 ] = rtX . omoyscdlkq [ 0 ] ; rtB . jiz3a002c3 [ 0 ]
= rtX . bvv2j1fvkj [ 0 ] ; rtB . peasbjr2ah [ 0 ] = rtX . jyfm4clkt1 [ 0 ] ;
rtB . au5wbjjqt3 [ 1 ] = rtX . omoyscdlkq [ 1 ] ; rtB . jiz3a002c3 [ 1 ] =
rtX . bvv2j1fvkj [ 1 ] ; rtB . peasbjr2ah [ 1 ] = rtX . jyfm4clkt1 [ 1 ] ; {
real_T * * uBuffer = ( real_T * * ) & rtDW . em4ieblqdo . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . em4ieblqdo . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay_Delay ; rtB . c0vcvn0r0g = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * tBuffer , * uBuffer , rtDW . hflmn5zw4g . CircularBufSize , & rtDW
. hflmn5zw4g . Last , rtDW . hflmn5zw4g . Tail , rtDW . hflmn5zw4g . Head ,
rtP . TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS
) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . cp2wd3yek3 . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . cp2wd3yek3 . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay_bf3u4wh1iu ; rtB . mwkffby2ul = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . ogn0tnbje1 .
CircularBufSize , & rtDW . ogn0tnbje1 . Last , rtDW . ogn0tnbje1 . Tail ,
rtDW . ogn0tnbje1 . Head , rtP . TransportDelay1_InitOutput_jipm0sgfem , 1 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } g0yerdzy4e [ 0 ] = rtX . an1dy1scdv [ 0 ] ;
j32hx2yjlk [ 0 ] = rtX . ajilevaypm [ 0 ] ; f1fl5j3sr1 [ 0 ] = rtX .
ndnjgxlg32 [ 0 ] ; bvvaglfnyg [ 0 ] = rtX . mampjjggm5 [ 0 ] ; g0yerdzy4e [ 1
] = rtX . an1dy1scdv [ 1 ] ; j32hx2yjlk [ 1 ] = rtX . ajilevaypm [ 1 ] ;
f1fl5j3sr1 [ 1 ] = rtX . ndnjgxlg32 [ 1 ] ; bvvaglfnyg [ 1 ] = rtX .
mampjjggm5 [ 1 ] ; olmchesjlh ( rtB . ovp54ku00f , rtB . au5wbjjqt3 , rtB .
jiz3a002c3 , rtB . peasbjr2ah , rtB . fyll5jdjjj , rtB . obobcozbfh , rtB .
kthfd0aif2 , rtB . n1skxybgba , rtB . c0vcvn0r0g , rtB . mwkffby2ul , rtP .
Constant2_Value , g0yerdzy4e , j32hx2yjlk , f1fl5j3sr1 , bvvaglfnyg , rtP .
Agent_Value , & rtB . oqwk5hg0e3 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . hhq2gz3sy3 [ 0 ] = rtDW . ldao3hyxar [ 0 ] ; rtB . hhq2gz3sy3 [ 1 ] =
rtDW . ldao3hyxar [ 1 ] ; rtB . ibguh2azcu [ 0 ] = rtDW . o4urslscxv [ 0 ] ;
rtB . ibguh2azcu [ 1 ] = rtDW . o4urslscxv [ 1 ] ; } rtB . p123e5cq2h [ 0 ] =
rtB . hhq2gz3sy3 [ 0 ] - rtB . guii4af3w0 [ 0 ] ; rtB . p123e5cq2h [ 1 ] =
rtB . hhq2gz3sy3 [ 1 ] - rtB . guii4af3w0 [ 1 ] ; rtB . kcifbusgyp [ 0 ] =
rtB . ibguh2azcu [ 0 ] - rtB . ovp54ku00f [ 0 ] ; rtB . nr2xhydys1 [ 0 ] =
rtX . c1zyhspvvj [ 0 ] ; rtB . a03f1j3hsr [ 0 ] = rtX . bozttf3lme [ 0 ] ;
rtB . ma4hr1zg5h [ 0 ] = rtX . lu2z2r1bq1 [ 0 ] ; rtB . kcifbusgyp [ 1 ] =
rtB . ibguh2azcu [ 1 ] - rtB . ovp54ku00f [ 1 ] ; rtB . nr2xhydys1 [ 1 ] =
rtX . c1zyhspvvj [ 1 ] ; rtB . a03f1j3hsr [ 1 ] = rtX . bozttf3lme [ 1 ] ;
rtB . ma4hr1zg5h [ 1 ] = rtX . lu2z2r1bq1 [ 1 ] ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtB . kjfk5s4txt [ 0 ] = rtDW . biuieiqmxp [ 0 ] ; rtB .
cq2ac25vvr [ 0 ] = rtDW . kxmjiaeunc [ 0 ] ; rtB . f3swi4wykw [ 0 ] = rtDW .
gq1mgiuwz2 [ 0 ] ; rtB . kjfk5s4txt [ 1 ] = rtDW . biuieiqmxp [ 1 ] ; rtB .
cq2ac25vvr [ 1 ] = rtDW . kxmjiaeunc [ 1 ] ; rtB . f3swi4wykw [ 1 ] = rtDW .
gq1mgiuwz2 [ 1 ] ; } jruuzkvv4x [ 0 ] = rtX . au25a2kq45 [ 0 ] ; jruuzkvv4x [
1 ] = rtX . au25a2kq45 [ 1 ] ; bgjulh42sn [ 0 ] = rtX . n1g43fm50u [ 0 ] -
rtB . c0vcvn0r0g ; bgjulh42sn [ 1 ] = rtX . n1g43fm50u [ 1 ] - rtB .
mwkffby2ul ; iysmccme2o ( jruuzkvv4x , bgjulh42sn , & rtB . olxq5nidun ) ;
kjpnkazon3 [ 0 ] = rtX . jjhfp4nquz [ 0 ] ; muz343ptzl [ 0 ] = rtX .
j0sputa12i [ 0 ] ; ognna4atll [ 0 ] = rtX . bpzbkldlw5 [ 0 ] ; dkplwwqhlq [ 0
] = rtX . djt2dez0wq [ 0 ] ; kjpnkazon3 [ 1 ] = rtX . jjhfp4nquz [ 1 ] ;
muz343ptzl [ 1 ] = rtX . j0sputa12i [ 1 ] ; ognna4atll [ 1 ] = rtX .
bpzbkldlw5 [ 1 ] ; dkplwwqhlq [ 1 ] = rtX . djt2dez0wq [ 1 ] ; ew4afwvte5 (
rtB . guii4af3w0 , rtB . nr2xhydys1 , rtB . a03f1j3hsr , rtB . ma4hr1zg5h ,
rtB . mka13uwfw0 , rtB . kjfk5s4txt , rtB . cq2ac25vvr , rtB . f3swi4wykw ,
rtB . olxq5nidun . g2qarspkxz , rtP . Constant1_Value , kjpnkazon3 ,
muz343ptzl , ognna4atll , dkplwwqhlq , rtP . Agent_Value , & rtB . pqggajaphk
) ; for ( i = 0 ; i < 15 ; i ++ ) { ft1p4me3if [ i ] = rtX . chv5h33ild [ i ]
; bcehnxyd3h [ i ] = rtX . f5c0yrpl0m [ i ] ; myowtlscss [ i ] = rtX .
jee34x0zc4 [ i ] ; hkxtd2yqjg . t1 [ i ] = mk2kwho04h [ i ] ; hkxtd2yqjg . t2
[ i ] = ft1p4me3if [ i ] ; hkxtd2yqjg . t3 [ i ] = bcehnxyd3h [ i ] ;
hkxtd2yqjg . t4 [ i ] = myowtlscss [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { for ( i = 0 ; i < 15 ; i ++ ) { kderxbgjob [ i ] = rtDW . lwlz3gfxgb [
i ] ; ibg3dwhse0 [ i ] = rtDW . ekvleb1gcq [ i ] ; fnkf1abqw5 [ i ] = rtDW .
k3kw4exkgg [ i ] ; pk1hppghip [ i ] = rtDW . cr0y2nzbkc [ i ] ; rtB .
hvniiswj0n . eps1 [ i ] = kderxbgjob [ i ] ; rtB . hvniiswj0n . eps2 [ i ] =
ibg3dwhse0 [ i ] ; rtB . hvniiswj0n . eps3 [ i ] = fnkf1abqw5 [ i ] ; rtB .
hvniiswj0n . eps4 [ i ] = pk1hppghip [ i ] ; } rtB . fjnyclhmei [ 0 ] = rtDW
. eftcuoxcfp [ 0 ] ; rtB . fjnyclhmei [ 1 ] = rtDW . eftcuoxcfp [ 1 ] ; rtB .
fjnyclhmei [ 2 ] = rtDW . eftcuoxcfp [ 2 ] ; } rtB . etgxr0b4e3 = ssGetT (
rtS ) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . k1smvi2dzs = ( rtB .
etgxr0b4e3 > rtP . Switch2_Threshold ) ; rtDW . fianodont1 = ( rtB .
etgxr0b4e3 > rtP . Switch1_Threshold ) ; } if ( rtDW . k1smvi2dzs ) {
bv0exnxaiw = rtP . DesiredPosition5_Value ; } else { bv0exnxaiw = rtP .
DesiredPosition6_Value ; } if ( rtDW . fianodont1 ) { biumkvvuc1 = rtP .
DesiredPosition2_Value ; } else { biumkvvuc1 = rtP . DesiredPosition3_Value ;
} if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . msmqvj5ygx = ( rtB . etgxr0b4e3 >
rtP . Switch_Threshold ) ; } if ( rtDW . msmqvj5ygx ) { nat0cpttuo = rtP .
DesiredPosition1_Value ; } else { nat0cpttuo = rtP . DesiredPosition4_Value ;
} ikri1d1nmq [ 0 ] = 0.0 ; ikri1d1nmq [ 5 ] = 0.0 ; ikri1d1nmq [ 10 ] = 0.0 ;
ikri1d1nmq [ 1 ] = bv0exnxaiw ; ikri1d1nmq [ 6 ] = biumkvvuc1 ; ikri1d1nmq [
11 ] = nat0cpttuo ; ikri1d1nmq [ 2 ] = - bv0exnxaiw ; ikri1d1nmq [ 7 ] =
biumkvvuc1 ; ikri1d1nmq [ 12 ] = - nat0cpttuo ; ikri1d1nmq [ 3 ] = -
bv0exnxaiw ; ikri1d1nmq [ 8 ] = - biumkvvuc1 ; ikri1d1nmq [ 13 ] = 2.0 *
nat0cpttuo ; ikri1d1nmq [ 4 ] = bv0exnxaiw ; ikri1d1nmq [ 9 ] = - biumkvvuc1
; ikri1d1nmq [ 14 ] = - 2.0 * nat0cpttuo ; g0rn2igfkt ( & hkxtd2yqjg , & rtB
. hvniiswj0n , mk2kwho04h , ikri1d1nmq , rtP . Agent_Value , & rtB .
nrezxvhxow ) ; rtB . jp4yty50ed [ 0 ] = rtX . im051m03c0 [ 0 ] ; rtB .
c5ojbulhcl [ 0 ] = rtX . ossqjsfts4 [ 0 ] ; rtB . c2fmjucg5f [ 0 ] = rtX .
ivslgspzyl [ 0 ] ; rtB . jp4yty50ed [ 1 ] = rtX . im051m03c0 [ 1 ] ; rtB .
c5ojbulhcl [ 1 ] = rtX . ossqjsfts4 [ 1 ] ; rtB . c2fmjucg5f [ 1 ] = rtX .
ivslgspzyl [ 1 ] ; rtB . jp4yty50ed [ 2 ] = rtX . im051m03c0 [ 2 ] ; rtB .
c5ojbulhcl [ 2 ] = rtX . ossqjsfts4 [ 2 ] ; rtB . c2fmjucg5f [ 2 ] = rtX .
ivslgspzyl [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . i10izinweb [
0 ] = rtDW . bdxxdlvg4e [ 0 ] ; rtB . ar5mtka5cc [ 0 ] = rtDW . l34b1ws24z [
0 ] ; rtB . gorv20ywqu [ 0 ] = rtDW . lbl43aynsc [ 0 ] ; rtB . i10izinweb [ 1
] = rtDW . bdxxdlvg4e [ 1 ] ; rtB . ar5mtka5cc [ 1 ] = rtDW . l34b1ws24z [ 1
] ; rtB . gorv20ywqu [ 1 ] = rtDW . lbl43aynsc [ 1 ] ; rtB . i10izinweb [ 2 ]
= rtDW . bdxxdlvg4e [ 2 ] ; rtB . ar5mtka5cc [ 2 ] = rtDW . l34b1ws24z [ 2 ]
; rtB . gorv20ywqu [ 2 ] = rtDW . lbl43aynsc [ 2 ] ; } mza03d5fve [ 0 ] = rtB
. cbz53iqiop [ 0 ] ; mza03d5fve [ 3 ] = rtB . jp4yty50ed [ 0 ] ; mza03d5fve [
6 ] = rtB . c5ojbulhcl [ 0 ] ; mza03d5fve [ 9 ] = rtB . c2fmjucg5f [ 0 ] ;
dhuhfjmuec [ 0 ] = rtB . fjnyclhmei [ 0 ] ; dhuhfjmuec [ 3 ] = rtB .
i10izinweb [ 0 ] ; dhuhfjmuec [ 6 ] = rtB . ar5mtka5cc [ 0 ] ; dhuhfjmuec [ 9
] = rtB . gorv20ywqu [ 0 ] ; rtB . ashx3cqs2u [ 0 ] = ( real_T ) l [ ( ( ( (
int32_T ) rtP . Agent_Value - 1 ) << 2 ) + ( int32_T ) rtP . Agent_Value ) -
1 ] * ( rtB . cbz53iqiop [ 0 ] - rtB . c0vcvn0r0g ) ; bv0exnxaiw = 0.0 ;
mza03d5fve [ 1 ] = rtB . cbz53iqiop [ 1 ] ; mza03d5fve [ 4 ] = rtB .
jp4yty50ed [ 1 ] ; mza03d5fve [ 7 ] = rtB . c5ojbulhcl [ 1 ] ; mza03d5fve [
10 ] = rtB . c2fmjucg5f [ 1 ] ; dhuhfjmuec [ 1 ] = rtB . fjnyclhmei [ 1 ] ;
dhuhfjmuec [ 4 ] = rtB . i10izinweb [ 1 ] ; dhuhfjmuec [ 7 ] = rtB .
ar5mtka5cc [ 1 ] ; dhuhfjmuec [ 10 ] = rtB . gorv20ywqu [ 1 ] ; rtB .
ashx3cqs2u [ 1 ] = ( real_T ) l [ ( ( ( ( int32_T ) rtP . Agent_Value - 1 )
<< 2 ) + ( int32_T ) rtP . Agent_Value ) - 1 ] * ( rtB . cbz53iqiop [ 1 ] -
rtB . mwkffby2ul ) ; biumkvvuc1 = 0.0 ; mza03d5fve [ 2 ] = rtB . cbz53iqiop [
2 ] ; mza03d5fve [ 5 ] = rtB . jp4yty50ed [ 2 ] ; mza03d5fve [ 8 ] = rtB .
c5ojbulhcl [ 2 ] ; mza03d5fve [ 11 ] = rtB . c2fmjucg5f [ 2 ] ; dhuhfjmuec [
2 ] = rtB . fjnyclhmei [ 2 ] ; dhuhfjmuec [ 5 ] = rtB . i10izinweb [ 2 ] ;
dhuhfjmuec [ 8 ] = rtB . ar5mtka5cc [ 2 ] ; dhuhfjmuec [ 11 ] = rtB .
gorv20ywqu [ 2 ] ; rtB . ashx3cqs2u [ 2 ] = ( real_T ) l [ ( ( ( ( int32_T )
rtP . Agent_Value - 1 ) << 2 ) + ( int32_T ) rtP . Agent_Value ) - 1 ] * (
rtB . cbz53iqiop [ 2 ] - rtB . i3h3tvdsd4 ) ; nat0cpttuo = 0.0 ; for ( i = 0
; i < 4 ; i ++ ) { b = i * ( int32_T ) amqgqkb2nu + 1 ; c = ( 1 + i ) * (
int32_T ) amqgqkb2nu ; if ( b > c ) { b = 1 ; c = 0 ; } c -= b ; for ( i_p =
0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] = ( int8_T ) ( b + i_p ) ; } rtB .
ashx3cqs2u [ 0 ] += ( real_T ) m [ ( ( i << 2 ) + ( int32_T ) rtP .
Agent_Value ) - 1 ] * ( rtB . cbz53iqiop [ 0 ] - mza03d5fve [ b_data [ 0 ] -
1 ] ) ; rtB . ashx3cqs2u [ 1 ] += ( real_T ) m [ ( ( i << 2 ) + ( int32_T )
rtP . Agent_Value ) - 1 ] * ( rtB . cbz53iqiop [ 1 ] - mza03d5fve [ b_data [
1 ] - 1 ] ) ; rtB . ashx3cqs2u [ 2 ] += ( real_T ) m [ ( ( i << 2 ) + (
int32_T ) rtP . Agent_Value ) - 1 ] * ( rtB . cbz53iqiop [ 2 ] - mza03d5fve [
b_data [ 2 ] - 1 ] ) ; b = i * ( int32_T ) amqgqkb2nu + 1 ; c = ( 1 + i ) * (
int32_T ) amqgqkb2nu ; if ( b > c ) { b = 1 ; c = 0 ; } c -= b ; for ( i_p =
0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] = ( int8_T ) ( b + i_p ) ; }
bv0exnxaiw += rtP . H [ ( ( ( int32_T ) rtP . Agent_Value - 1 ) << 2 ) + i ]
* dhuhfjmuec [ b_data [ 0 ] - 1 ] ; biumkvvuc1 += rtP . H [ ( ( ( int32_T )
rtP . Agent_Value - 1 ) << 2 ) + i ] * dhuhfjmuec [ b_data [ 1 ] - 1 ] ;
nat0cpttuo += rtP . H [ ( ( ( int32_T ) rtP . Agent_Value - 1 ) << 2 ) + i ]
* dhuhfjmuec [ b_data [ 2 ] - 1 ] ; } bv0exnxaiw /= muDoubleScalarAbs (
bv0exnxaiw ) + rtP . alpha ; biumkvvuc1 /= muDoubleScalarAbs ( biumkvvuc1 ) +
rtP . alpha ; memset ( & b_d [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; b_d [ 0 ]
= bv0exnxaiw ; b_d [ 4 ] = biumkvvuc1 ; b_d [ 8 ] = nat0cpttuo / (
muDoubleScalarAbs ( nat0cpttuo ) + rtP . alpha ) ; for ( i_p = 0 ; i_p < 3 ;
i_p ++ ) { rtB . ll4nivtt3m [ i_p ] = - rtP . Observer_Gain * rtB .
ashx3cqs2u [ i_p ] - ( ( b_d [ i_p + 3 ] * rtP . U_dot0_M [ 1 ] + b_d [ i_p ]
* rtP . U_dot0_M [ 0 ] ) + b_d [ i_p + 6 ] * rtP . U_dot0_M [ 2 ] ) ; } rtB .
irxau0vegh [ 0 ] = khu3wekibw - rtB . ibguh2azcu [ 0 ] ; rtB . irxau0vegh [ 1
] = c10xsvgo14 - rtB . ibguh2azcu [ 1 ] ; rtB . irxau0vegh [ 2 ] = rtB .
elri1t014b . hia3u3mq0v [ 2 ] - rtB . fsylupg2ie ; cajljq2wjj = ssGetT ( rtS
) ; bifsfih4ms ( rtB . j2lsirb0ej , rtB . eo0mj2ipwy . ollm0kao5t [ 0 ] , rtB
. eo0mj2ipwy . ollm0kao5t [ 1 ] , rtB . eo0mj2ipwy . ollm0kao5t [ 2 ] , rtB .
eo0mj2ipwy . ollm0kao5t [ 3 ] , cajljq2wjj , & rtB . hfjw0isrvt ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . kakeuy45nl [ 0 ] = rtDW . euwquc1ohh
[ 0 ] ; rtB . kakeuy45nl [ 1 ] = rtDW . euwquc1ohh [ 1 ] ; } bv0exnxaiw = rtP
. Gain_Gain * rtX . hiamj1oevs ; mprhv4gcwl = rtX . gx3o1bpm3a ; hp20ymhe1e (
rtB . c0vcvn0r0g , rtB . mwkffby2ul , rtB . ibguh2azcu , & rtB . c531ff4wpr )
; mnr4evnmg5 = bv0exnxaiw - rtB . c531ff4wpr . esbc0t1dta ; lunmotda0s (
mprhv4gcwl , mnr4evnmg5 , & rtB . by2102zg1w ) ; c3hsf3zf4q ( mnr4evnmg5 , &
rtB . dukk21lgx3 ) ; onqykep2vg ( dkplwwqhlq , rtB . c531ff4wpr . esbc0t1dta
, bvvaglfnyg , & rtB . ezrv5s44v4 ) ; gnayzxxwhh [ 0 ] = rtX . gtdwc5tdzv [ 0
] ; d4m4v5phyn [ 0 ] = rtX . cg2tzvhg1s [ 0 ] - rtB . olxq5nidun . g2qarspkxz
[ 0 ] ; gnayzxxwhh [ 1 ] = rtX . gtdwc5tdzv [ 1 ] ; d4m4v5phyn [ 1 ] = rtX .
cg2tzvhg1s [ 1 ] - rtB . olxq5nidun . g2qarspkxz [ 1 ] ; iysmccme2o (
gnayzxxwhh , d4m4v5phyn , & rtB . oule4qndjw ) ; dyrfriuf53 [ 0 ] = rtB .
kakeuy45nl [ 0 ] - rtB . oule4qndjw . g2qarspkxz [ 0 ] ; dyrfriuf53 [ 1 ] =
rtB . kakeuy45nl [ 1 ] - rtB . oule4qndjw . g2qarspkxz [ 1 ] ; ifmmcug2wn (
dyrfriuf53 , rtB . by2102zg1w . mxe5eu4hb4 , dkplwwqhlq , & rtB . k2f1farrzj
) ; bv0exnxaiw = rtP . Gain_Gain_nk254mxa1l * rtX . joe5wc3vru ; epi5h543uq =
rtX . belilpb3dk ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . leex1vr2mc [
0 ] = rtDW . kb1zmmywdq [ 0 ] ; rtB . leex1vr2mc [ 1 ] = rtDW . kb1zmmywdq [
1 ] ; l1ggp544gs ( rtB . leex1vr2mc , rtB . ibguh2azcu , & rtB . bfqgyvaqcz )
; } gkeiwcjlga = bv0exnxaiw - rtB . bfqgyvaqcz . ortedkvoqi ; lunmotda0s (
epi5h543uq , gkeiwcjlga , & rtB . jkmnldsv41 ) ; c3hsf3zf4q ( gkeiwcjlga , &
rtB . hduc3332fp ) ; onqykep2vg ( kjpnkazon3 , rtB . bfqgyvaqcz . ortedkvoqi
, g0yerdzy4e , & rtB . nj24ds003u ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . ixqvkyn0bs [ 0 ] = rtDW . nsyupx5qza [ 0 ] ; rtB . g2pdbeghl4 [ 0 ] =
rtB . kakeuy45nl [ 0 ] - rtB . ixqvkyn0bs [ 0 ] ; rtB . ixqvkyn0bs [ 1 ] =
rtDW . nsyupx5qza [ 1 ] ; rtB . g2pdbeghl4 [ 1 ] = rtB . kakeuy45nl [ 1 ] -
rtB . ixqvkyn0bs [ 1 ] ; } ifmmcug2wn ( rtB . g2pdbeghl4 , rtB . jkmnldsv41 .
mxe5eu4hb4 , kjpnkazon3 , & rtB . cc0eq1pdzz ) ; bv0exnxaiw = rtP .
Gain_Gain_ikzgx3yo5o * rtX . bxlordfjyp ; m1qgpyagnk = rtX . mva2o1cupz ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . cdzixgvais [ 0 ] = rtDW .
mfzuy1fnjf [ 0 ] ; rtB . cdzixgvais [ 1 ] = rtDW . mfzuy1fnjf [ 1 ] ;
l1ggp544gs ( rtB . cdzixgvais , rtB . ibguh2azcu , & rtB . ey4yzgiezw ) ; }
lyp5lcgplc = bv0exnxaiw - rtB . ey4yzgiezw . ortedkvoqi ; lunmotda0s (
m1qgpyagnk , lyp5lcgplc , & rtB . peplmogpy4 ) ; c3hsf3zf4q ( lyp5lcgplc , &
rtB . cyju4j1oji ) ; onqykep2vg ( muz343ptzl , rtB . ey4yzgiezw . ortedkvoqi
, j32hx2yjlk , & rtB . nj0q0pfqt4 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . bqxn34m0qr [ 0 ] = rtDW . meq4arbagn [ 0 ] ; rtB . icqhriylz3 [ 0 ] =
rtB . kakeuy45nl [ 0 ] - rtB . bqxn34m0qr [ 0 ] ; rtB . bqxn34m0qr [ 1 ] =
rtDW . meq4arbagn [ 1 ] ; rtB . icqhriylz3 [ 1 ] = rtB . kakeuy45nl [ 1 ] -
rtB . bqxn34m0qr [ 1 ] ; } ifmmcug2wn ( rtB . icqhriylz3 , rtB . peplmogpy4 .
mxe5eu4hb4 , muz343ptzl , & rtB . fqy4bphp3r ) ; bv0exnxaiw = rtP .
Gain_Gain_odpbsclc5n * rtX . lmqns2m2fd ; mted2snvh3 = rtX . du3cl5u2br ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ordnmswswg [ 0 ] = rtDW .
elhi3coyqa [ 0 ] ; rtB . ordnmswswg [ 1 ] = rtDW . elhi3coyqa [ 1 ] ;
l1ggp544gs ( rtB . ordnmswswg , rtB . ibguh2azcu , & rtB . fnvhv3sjko ) ; }
fub54w4kmy = bv0exnxaiw - rtB . fnvhv3sjko . ortedkvoqi ; lunmotda0s (
mted2snvh3 , fub54w4kmy , & rtB . dqmxq5wims ) ; c3hsf3zf4q ( fub54w4kmy , &
rtB . h32zv1canq ) ; onqykep2vg ( ognna4atll , rtB . fnvhv3sjko . ortedkvoqi
, f1fl5j3sr1 , & rtB . pogoxyyi05 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . ajq0qn0k3g [ 0 ] = rtDW . cb4caomchi [ 0 ] ; rtB . f5apej04cu [ 0 ] =
rtB . kakeuy45nl [ 0 ] - rtB . ajq0qn0k3g [ 0 ] ; rtB . ajq0qn0k3g [ 1 ] =
rtDW . cb4caomchi [ 1 ] ; rtB . f5apej04cu [ 1 ] = rtB . kakeuy45nl [ 1 ] -
rtB . ajq0qn0k3g [ 1 ] ; } ifmmcug2wn ( rtB . f5apej04cu , rtB . dqmxq5wims .
mxe5eu4hb4 , ognna4atll , & rtB . hubjvrmjeu ) ; for ( i = 0 ; i < 6 ; i ++ )
{ makrbjzw3u [ i ] = rtX . aqayeibnbf [ i ] ; } if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { memcpy ( & rtB . ktzqeyaa2j [ 0 ] , & rtDW . njybh3xjqw [ 0 ] , 12U
* sizeof ( real_T ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
nuyw1oa5lu . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. nuyw1oa5lu . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay1_Delay_ksw2xmlzvn ; abgyidwyxb =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
lyazy3gnn2 . CircularBufSize , & rtDW . lyazy3gnn2 . Last , rtDW . lyazy3gnn2
. Tail , rtDW . lyazy3gnn2 . Head , rtP .
TransportDelay1_InitOutput_io3d45ar21 , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . ongfcz4dhf . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . ongfcz4dhf . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay2_Delay_muwonazjkp ; csfv2uibob = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . je3z34ckbn .
CircularBufSize , & rtDW . je3z34ckbn . Last , rtDW . je3z34ckbn . Tail ,
rtDW . je3z34ckbn . Head , rtP . TransportDelay2_InitOutput_kznqd41xd4 , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } my0xtyxafz ( rtB . jp4yty50ed , ft1p4me3if , rtP
. Agent_Value_kelyffe2iy , & rtB . gt3vc04dxa ) ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB . cj3tu2cvgj [ i ] = rtDW .
hdkreqmds2 [ i ] ; } } nnvj0nbsr4 ( rtB . ktzqeyaa2j , abgyidwyxb ,
csfv2uibob , rtB . gt3vc04dxa . hia3u3mq0v [ 2 ] , rtB . cj3tu2cvgj , & rtB .
lycfgsadwf ) ; for ( i = 0 ; i < 6 ; i ++ ) { bhc0g2tr1b [ i ] = makrbjzw3u [
i ] + rtB . lycfgsadwf . admi3yqyf0 [ i ] ; hhsezyptna [ i ] = rtX .
mnhjgksiva [ i ] ; rtB . bzdtapi1nn [ i ] = rtX . p5euhzgph2 [ i ] - rtB .
lycfgsadwf . gtmlnhqoq0 [ i ] ; } d4w44phvgb ( hhsezyptna , rtB . bzdtapi1nn
, & rtB . fuoxbigwkf ) ; memcpy ( & fpbyp3gnlt [ 0 ] , & rtX . nsygkjz001 [ 0
] , 36U * sizeof ( real_T ) ) ; memcpy ( & hifhopdemn [ 0 ] , & rtX .
pyssp52j4v [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
rtB . e5sbn5ywmn [ i ] = rtX . fig1xy4s5q [ i ] ; } jvlvilab4w ( bhc0g2tr1b ,
makrbjzw3u , rtB . fuoxbigwkf . hg1x1nd45k , fpbyp3gnlt , hifhopdemn , rtB .
e5sbn5ywmn , rtB . lycfgsadwf . jaolq3jrhd , & rtB . l3bbgfkbil ) ;
ihouus1chq ( rtB . l3bbgfkbil . m0i0p0mohd , & rtB . ngywhtsz3l ) ; for ( i =
0 ; i < 6 ; i ++ ) { pyfwtl3j0a [ i ] = rtX . lovsimzfsp [ i ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB .
k2wfwxwner [ i ] = rtDW . k5rawm0exp [ i ] ; } } m1hec3vrd2 ( rtB .
ktzqeyaa2j , rtB . ngywhtsz3l . gwmh5422nv , rtB . k2wfwxwner , & rtB .
ghgs23hmyk ) ; for ( i = 0 ; i < 6 ; i ++ ) { p3ubxu5hwv [ i ] = pyfwtl3j0a [
i ] + rtB . ghgs23hmyk . jl4fbhrop1 [ i ] ; n4lxva3wkp [ i ] = rtX .
dvkhmbnof2 [ i ] ; kfglakgeuu [ i ] = rtX . gqi2mgds2b [ i ] - rtB .
ghgs23hmyk . j1zyuz5kzg [ i ] ; } l3dvuo1xw3 ( n4lxva3wkp , kfglakgeuu , &
rtB . e2iscjaunx ) ; memcpy ( & o4hmshkh13 [ 0 ] , & rtX . ppo5lvnsbd [ 0 ] ,
36U * sizeof ( real_T ) ) ; memcpy ( & ppmcvosloc [ 0 ] , & rtX . aslzbhpikx
[ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
kan4kiqahi [ i ] = rtX . m20bb5px11 [ i ] ; } jvlvilab4w ( p3ubxu5hwv ,
pyfwtl3j0a , rtB . e2iscjaunx . l5c2p5rmcp , o4hmshkh13 , ppmcvosloc , rtB .
kan4kiqahi , rtB . ghgs23hmyk . dzda0l3ztv , & rtB . ng0oekyoml ) ;
g4g4bdu0ia ( rtB . ngywhtsz3l . hw5tnzrodd , rtB . ng0oekyoml . m0i0p0mohd ,
& rtB . gntssldk33 ) ; ijextzfzou ( o4hmshkh13 , ppmcvosloc , & rtB .
dhwkhs2uoc ) ; lgndixfdt3 ( kfglakgeuu , & rtB . ofq5zlashb ) ; lvvcxitelq (
p3ubxu5hwv , rtB . kan4kiqahi , o4hmshkh13 , & rtB . kn0eokpsnw ) ;
bmxkvlwnui ( p3ubxu5hwv , rtB . ghgs23hmyk . dzda0l3ztv , o4hmshkh13 ,
ppmcvosloc , & rtB . cphdqdow2s ) ; bmxkvlwnui ( bhc0g2tr1b , rtB .
lycfgsadwf . jaolq3jrhd , fpbyp3gnlt , hifhopdemn , & rtB . fgdsj1go3f ) ;
ijextzfzou ( fpbyp3gnlt , hifhopdemn , & rtB . e3k2wvkram ) ; lgndixfdt3 (
rtB . bzdtapi1nn , & rtB . dnncszfbjm ) ; lvvcxitelq ( bhc0g2tr1b , rtB .
e5sbn5ywmn , fpbyp3gnlt , & rtB . ikazhomoow ) ; k0x1jfr1ix = rtX .
dmaqihaxaq ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ll2wsps0hn = rtDW .
eb005l0rcc ; } p1mc2go3l4 = rtX . dsaqs0egeg - rtB . ll2wsps0hn ; lunmotda0s
( k0x1jfr1ix , p1mc2go3l4 , & rtB . gsjc2uausd ) ; c3hsf3zf4q ( p1mc2go3l4 ,
& rtB . l3bm1rlyki ) ; memcpy ( & rtB . pm1tjuoiq2 [ 0 ] , & rtX . hj3xpt5hh3
[ 0 ] , 12U * sizeof ( real_T ) ) ; hwodfh00oh ( rtB . pm1tjuoiq2 , rtB .
au5wbjjqt3 , rtB . ll2wsps0hn , rtB . nr2xhydys1 , rtB . gsjc2uausd .
mxe5eu4hb4 , & rtB . htnejvn3py ) ; gbjfazf2je [ 0 ] = rtX . fmtqkgzjo2 [ 0 ]
; agfcgsovpn [ 0 ] = rtX . eqlst0fie1 [ 0 ] ; mctw4f5pif [ 0 ] = rtX .
jhyl0nmftj [ 0 ] ; meapna2wrq [ 0 ] = rtX . dufp23q24f [ 0 ] ; gbjfazf2je [ 1
] = rtX . fmtqkgzjo2 [ 1 ] ; agfcgsovpn [ 1 ] = rtX . eqlst0fie1 [ 1 ] ;
mctw4f5pif [ 1 ] = rtX . jhyl0nmftj [ 1 ] ; meapna2wrq [ 1 ] = rtX .
dufp23q24f [ 1 ] ; olmchesjlh ( rtB . ovp54ku00f , rtB . au5wbjjqt3 , rtB .
jiz3a002c3 , rtB . peasbjr2ah , rtB . fyll5jdjjj , rtB . obobcozbfh , rtB .
kthfd0aif2 , rtB . n1skxybgba , rtB . c0vcvn0r0g , rtB . mwkffby2ul , rtP .
Constant2_Value_lx1k4y1rld , gbjfazf2je , agfcgsovpn , mctw4f5pif ,
meapna2wrq , rtP . Agent_Value_kelyffe2iy , & rtB . lj1isfudih ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . myenxxvcic [ 0 ] = rtDW . jhqxxzie31
[ 0 ] ; rtB . myenxxvcic [ 1 ] = rtDW . jhqxxzie31 [ 1 ] ; } rtB . lvotrv1jjx
[ 0 ] = rtB . myenxxvcic [ 0 ] - rtB . nr2xhydys1 [ 0 ] ; rtB . gr0jp0xo2u [
0 ] = rtB . leex1vr2mc [ 0 ] - rtB . au5wbjjqt3 [ 0 ] ; buvtunq30h [ 0 ] =
rtX . e5bm4mxp4y [ 0 ] ; fbmoupq1qk [ 0 ] = rtX . d2zjdsdy3t [ 0 ] ;
b3qjlp2a05 [ 0 ] = rtX . atdwxldcaa [ 0 ] ; mr30ur40cd [ 0 ] = rtX .
kdrbhkothr [ 0 ] ; rtB . lvotrv1jjx [ 1 ] = rtB . myenxxvcic [ 1 ] - rtB .
nr2xhydys1 [ 1 ] ; rtB . gr0jp0xo2u [ 1 ] = rtB . leex1vr2mc [ 1 ] - rtB .
au5wbjjqt3 [ 1 ] ; buvtunq30h [ 1 ] = rtX . e5bm4mxp4y [ 1 ] ; fbmoupq1qk [ 1
] = rtX . d2zjdsdy3t [ 1 ] ; b3qjlp2a05 [ 1 ] = rtX . atdwxldcaa [ 1 ] ;
mr30ur40cd [ 1 ] = rtX . kdrbhkothr [ 1 ] ; ew4afwvte5 ( rtB . guii4af3w0 ,
rtB . nr2xhydys1 , rtB . a03f1j3hsr , rtB . ma4hr1zg5h , rtB . mka13uwfw0 ,
rtB . kjfk5s4txt , rtB . cq2ac25vvr , rtB . f3swi4wykw , rtB . olxq5nidun .
g2qarspkxz , rtP . Constant1_Value_leogo0eo3x , buvtunq30h , fbmoupq1qk ,
b3qjlp2a05 , mr30ur40cd , rtP . Agent_Value_kelyffe2iy , & rtB . eolycnedw1 )
; memcpy ( & lanqfvssdm . t1 [ 0 ] , & mk2kwho04h [ 0 ] , 15U * sizeof (
real_T ) ) ; memcpy ( & lanqfvssdm . t2 [ 0 ] , & ft1p4me3if [ 0 ] , 15U *
sizeof ( real_T ) ) ; memcpy ( & lanqfvssdm . t3 [ 0 ] , & bcehnxyd3h [ 0 ] ,
15U * sizeof ( real_T ) ) ; memcpy ( & lanqfvssdm . t4 [ 0 ] , & myowtlscss [
0 ] , 15U * sizeof ( real_T ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
memcpy ( & rtB . hbcqjuse5q . eps1 [ 0 ] , & kderxbgjob [ 0 ] , 15U * sizeof
( real_T ) ) ; memcpy ( & rtB . hbcqjuse5q . eps2 [ 0 ] , & ibg3dwhse0 [ 0 ]
, 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . hbcqjuse5q . eps3 [ 0 ] , &
fnkf1abqw5 [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . hbcqjuse5q .
eps4 [ 0 ] , & pk1hppghip [ 0 ] , 15U * sizeof ( real_T ) ) ; } g0rn2igfkt (
& lanqfvssdm , & rtB . hbcqjuse5q , ft1p4me3if , ikri1d1nmq , rtP .
Agent_Value_kelyffe2iy , & rtB . onfv1wmnyg ) ; mza03d5fve [ 0 ] = rtB .
cbz53iqiop [ 0 ] ; mza03d5fve [ 3 ] = rtB . jp4yty50ed [ 0 ] ; mza03d5fve [ 6
] = rtB . c5ojbulhcl [ 0 ] ; mza03d5fve [ 9 ] = rtB . c2fmjucg5f [ 0 ] ;
dhuhfjmuec [ 0 ] = rtB . fjnyclhmei [ 0 ] ; dhuhfjmuec [ 3 ] = rtB .
i10izinweb [ 0 ] ; dhuhfjmuec [ 6 ] = rtB . ar5mtka5cc [ 0 ] ; dhuhfjmuec [ 9
] = rtB . gorv20ywqu [ 0 ] ; rtB . l1wjcn1r3q [ 0 ] = ( real_T ) l_p [ ( ( (
( int32_T ) rtP . Agent_Value_kelyffe2iy - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_kelyffe2iy ) - 1 ] * ( rtB . jp4yty50ed [ 0 ] - rtB . c0vcvn0r0g
) ; bv0exnxaiw = 0.0 ; mza03d5fve [ 1 ] = rtB . cbz53iqiop [ 1 ] ; mza03d5fve
[ 4 ] = rtB . jp4yty50ed [ 1 ] ; mza03d5fve [ 7 ] = rtB . c5ojbulhcl [ 1 ] ;
mza03d5fve [ 10 ] = rtB . c2fmjucg5f [ 1 ] ; dhuhfjmuec [ 1 ] = rtB .
fjnyclhmei [ 1 ] ; dhuhfjmuec [ 4 ] = rtB . i10izinweb [ 1 ] ; dhuhfjmuec [ 7
] = rtB . ar5mtka5cc [ 1 ] ; dhuhfjmuec [ 10 ] = rtB . gorv20ywqu [ 1 ] ; rtB
. l1wjcn1r3q [ 1 ] = ( real_T ) l_p [ ( ( ( ( int32_T ) rtP .
Agent_Value_kelyffe2iy - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_kelyffe2iy ) - 1 ] * ( rtB . jp4yty50ed [ 1 ] - rtB . mwkffby2ul
) ; biumkvvuc1 = 0.0 ; mza03d5fve [ 2 ] = rtB . cbz53iqiop [ 2 ] ; mza03d5fve
[ 5 ] = rtB . jp4yty50ed [ 2 ] ; mza03d5fve [ 8 ] = rtB . c5ojbulhcl [ 2 ] ;
mza03d5fve [ 11 ] = rtB . c2fmjucg5f [ 2 ] ; dhuhfjmuec [ 2 ] = rtB .
fjnyclhmei [ 2 ] ; dhuhfjmuec [ 5 ] = rtB . i10izinweb [ 2 ] ; dhuhfjmuec [ 8
] = rtB . ar5mtka5cc [ 2 ] ; dhuhfjmuec [ 11 ] = rtB . gorv20ywqu [ 2 ] ; rtB
. l1wjcn1r3q [ 2 ] = ( real_T ) l_p [ ( ( ( ( int32_T ) rtP .
Agent_Value_kelyffe2iy - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_kelyffe2iy ) - 1 ] * ( rtB . jp4yty50ed [ 2 ] - rtB . i3h3tvdsd4
) ; nat0cpttuo = 0.0 ; for ( i = 0 ; i < 4 ; i ++ ) { b = i * ( int32_T )
amqgqkb2nu + 1 ; c = ( 1 + i ) * ( int32_T ) amqgqkb2nu ; if ( b > c ) { b =
1 ; c = 0 ; } c -= b ; for ( i_p = 0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] =
( int8_T ) ( b + i_p ) ; } rtB . l1wjcn1r3q [ 0 ] += ( real_T ) m_p [ ( ( i
<< 2 ) + ( int32_T ) rtP . Agent_Value_kelyffe2iy ) - 1 ] * ( rtB .
jp4yty50ed [ 0 ] - mza03d5fve [ b_data [ 0 ] - 1 ] ) ; rtB . l1wjcn1r3q [ 1 ]
+= ( real_T ) m_p [ ( ( i << 2 ) + ( int32_T ) rtP . Agent_Value_kelyffe2iy )
- 1 ] * ( rtB . jp4yty50ed [ 1 ] - mza03d5fve [ b_data [ 1 ] - 1 ] ) ; rtB .
l1wjcn1r3q [ 2 ] += ( real_T ) m_p [ ( ( i << 2 ) + ( int32_T ) rtP .
Agent_Value_kelyffe2iy ) - 1 ] * ( rtB . jp4yty50ed [ 2 ] - mza03d5fve [
b_data [ 2 ] - 1 ] ) ; b = i * ( int32_T ) amqgqkb2nu + 1 ; c = ( 1 + i ) * (
int32_T ) amqgqkb2nu ; if ( b > c ) { b = 1 ; c = 0 ; } c -= b ; for ( i_p =
0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] = ( int8_T ) ( b + i_p ) ; }
bv0exnxaiw += rtP . H [ ( ( ( int32_T ) rtP . Agent_Value_kelyffe2iy - 1 ) <<
2 ) + i ] * dhuhfjmuec [ b_data [ 0 ] - 1 ] ; biumkvvuc1 += rtP . H [ ( ( (
int32_T ) rtP . Agent_Value_kelyffe2iy - 1 ) << 2 ) + i ] * dhuhfjmuec [
b_data [ 1 ] - 1 ] ; nat0cpttuo += rtP . H [ ( ( ( int32_T ) rtP .
Agent_Value_kelyffe2iy - 1 ) << 2 ) + i ] * dhuhfjmuec [ b_data [ 2 ] - 1 ] ;
} bv0exnxaiw /= muDoubleScalarAbs ( bv0exnxaiw ) + rtP . alpha ; biumkvvuc1
/= muDoubleScalarAbs ( biumkvvuc1 ) + rtP . alpha ; memset ( & b_d [ 0 ] , 0
, 9U * sizeof ( real_T ) ) ; b_d [ 0 ] = bv0exnxaiw ; b_d [ 4 ] = biumkvvuc1
; b_d [ 8 ] = nat0cpttuo / ( muDoubleScalarAbs ( nat0cpttuo ) + rtP . alpha )
; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . gac1ybd3gq [ i_p ] = - rtP .
Observer_Gain * rtB . l1wjcn1r3q [ i_p ] - ( ( b_d [ i_p + 3 ] * rtP .
U_dot0_M [ 1 ] + b_d [ i_p ] * rtP . U_dot0_M [ 0 ] ) + b_d [ i_p + 6 ] * rtP
. U_dot0_M [ 2 ] ) ; } rtB . iwqydkbfig [ 0 ] = abgyidwyxb - rtB . leex1vr2mc
[ 0 ] ; rtB . iwqydkbfig [ 1 ] = csfv2uibob - rtB . leex1vr2mc [ 1 ] ; rtB .
iwqydkbfig [ 2 ] = rtB . gt3vc04dxa . hia3u3mq0v [ 2 ] - rtB . ll2wsps0hn ;
gabmlgsqlv = ssGetT ( rtS ) ; bifsfih4ms ( rtB . pm1tjuoiq2 , rtB .
gntssldk33 . ollm0kao5t [ 0 ] , rtB . gntssldk33 . ollm0kao5t [ 1 ] , rtB .
gntssldk33 . ollm0kao5t [ 2 ] , rtB . gntssldk33 . ollm0kao5t [ 3 ] ,
gabmlgsqlv , & rtB . cz230wcizx ) ; bv0exnxaiw = rtP . Gain_Gain_mutzwvqirh *
rtX . l1nyqmvwst ; ktxr5ga4nn = rtX . ca2tchanai ; hp20ymhe1e ( rtB .
c0vcvn0r0g , rtB . mwkffby2ul , rtB . leex1vr2mc , & rtB . nz4rsiamof ) ;
gflar2srxf = bv0exnxaiw - rtB . nz4rsiamof . esbc0t1dta ; lunmotda0s (
ktxr5ga4nn , gflar2srxf , & rtB . obfqahvmjm ) ; c3hsf3zf4q ( gflar2srxf , &
rtB . p43v4vgoay ) ; onqykep2vg ( mr30ur40cd , rtB . nz4rsiamof . esbc0t1dta
, meapna2wrq , & rtB . bgqjdgwjco ) ; hnnw2hujma [ 0 ] = rtB . ixqvkyn0bs [ 0
] - rtB . oule4qndjw . g2qarspkxz [ 0 ] ; hnnw2hujma [ 1 ] = rtB . ixqvkyn0bs
[ 1 ] - rtB . oule4qndjw . g2qarspkxz [ 1 ] ; ifmmcug2wn ( hnnw2hujma , rtB .
obfqahvmjm . mxe5eu4hb4 , mr30ur40cd , & rtB . obs2vasvj2 ) ; bv0exnxaiw =
rtP . Gain_Gain_hmnuazlmcb * rtX . ooketywe0t ; e30wrenqhp = rtX . mjw0keqmwr
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB . ibguh2azcu , rtB
. leex1vr2mc , & rtB . ina2eaxl2c ) ; } hlk05ayvhp = bv0exnxaiw - rtB .
ina2eaxl2c . ortedkvoqi ; lunmotda0s ( e30wrenqhp , hlk05ayvhp , & rtB .
jkdewgbanl ) ; c3hsf3zf4q ( hlk05ayvhp , & rtB . kzcw4mi4zh ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . hcksi1q3o0 [ 0 ] = rtB . ixqvkyn0bs [
0 ] - rtB . kakeuy45nl [ 0 ] ; rtB . hcksi1q3o0 [ 1 ] = rtB . ixqvkyn0bs [ 1
] - rtB . kakeuy45nl [ 1 ] ; } ifmmcug2wn ( rtB . hcksi1q3o0 , rtB .
jkdewgbanl . mxe5eu4hb4 , buvtunq30h , & rtB . mx2c20cuvt ) ; onqykep2vg (
buvtunq30h , rtB . ina2eaxl2c . ortedkvoqi , gbjfazf2je , & rtB . gnuxcvc0rq
) ; bv0exnxaiw = rtP . Gain_Gain_aphuk1riyf * rtX . fb0bskoedk ; eq1eix1lpn =
rtX . phfjeo0drc ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB .
cdzixgvais , rtB . leex1vr2mc , & rtB . cgmylk2bxu ) ; } hizdkkioqb =
bv0exnxaiw - rtB . cgmylk2bxu . ortedkvoqi ; lunmotda0s ( eq1eix1lpn ,
hizdkkioqb , & rtB . nimb0vszrh ) ; c3hsf3zf4q ( hizdkkioqb , & rtB .
ilz4rw1itf ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . jpsqiswtns [ 0 ]
= rtB . ixqvkyn0bs [ 0 ] - rtB . bqxn34m0qr [ 0 ] ; rtB . jpsqiswtns [ 1 ] =
rtB . ixqvkyn0bs [ 1 ] - rtB . bqxn34m0qr [ 1 ] ; } ifmmcug2wn ( rtB .
jpsqiswtns , rtB . nimb0vszrh . mxe5eu4hb4 , fbmoupq1qk , & rtB . a0eglqqncr
) ; onqykep2vg ( fbmoupq1qk , rtB . cgmylk2bxu . ortedkvoqi , agfcgsovpn , &
rtB . pi5klgxywb ) ; bv0exnxaiw = rtP . Gain_Gain_gamljvupvn * rtX .
d0fq4dyqzm ; mfvoeip4zj = rtX . irfwmkoozp ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { l1ggp544gs ( rtB . ordnmswswg , rtB . leex1vr2mc , & rtB . nwyzua4gjf )
; } es2otmhxnl = bv0exnxaiw - rtB . nwyzua4gjf . ortedkvoqi ; lunmotda0s (
mfvoeip4zj , es2otmhxnl , & rtB . fvjwsgw14y ) ; c3hsf3zf4q ( es2otmhxnl , &
rtB . cg5bnbimqw ) ; onqykep2vg ( b3qjlp2a05 , rtB . nwyzua4gjf . ortedkvoqi
, mctw4f5pif , & rtB . iw5aeqjlmr ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . kfsw4l5xh5 [ 0 ] = rtB . ixqvkyn0bs [ 0 ] - rtB . ajq0qn0k3g [ 0 ] ;
rtB . kfsw4l5xh5 [ 1 ] = rtB . ixqvkyn0bs [ 1 ] - rtB . ajq0qn0k3g [ 1 ] ; }
ifmmcug2wn ( rtB . kfsw4l5xh5 , rtB . fvjwsgw14y . mxe5eu4hb4 , b3qjlp2a05 ,
& rtB . lofsb5hfpk ) ; for ( i = 0 ; i < 6 ; i ++ ) { m5jtfekt2h [ i ] = rtX
. gfix1az2dy [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & rtB
. ixaiy5tpfv [ 0 ] , & rtDW . oywwglvnbw [ 0 ] , 12U * sizeof ( real_T ) ) ;
} { real_T * * uBuffer = ( real_T * * ) & rtDW . jzm2uqh05o . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . jzm2uqh05o . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP
. TransportDelay1_Delay_ppziigp4pi ; k5arailkcv = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . fyo23snxav .
CircularBufSize , & rtDW . fyo23snxav . Last , rtDW . fyo23snxav . Tail ,
rtDW . fyo23snxav . Head , rtP . TransportDelay1_InitOutput_irtprymfig , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
kim1kgtcyq . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. kim1kgtcyq . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay2_Delay_pcfeeikpk2 ; iidkxpk2kt =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
b4ivhh52o2 . CircularBufSize , & rtDW . b4ivhh52o2 . Last , rtDW . b4ivhh52o2
. Tail , rtDW . b4ivhh52o2 . Head , rtP .
TransportDelay2_InitOutput_lmsg2pl2kj , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; }
my0xtyxafz ( rtB . c5ojbulhcl , bcehnxyd3h , rtP . Agent_Value_isepnlmbdh , &
rtB . bhiqn3njpt ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . mgul3pau2j [ i ] = rtDW . ekk5eebzqc [ i ] ; } }
nnvj0nbsr4 ( rtB . ixaiy5tpfv , k5arailkcv , iidkxpk2kt , rtB . bhiqn3njpt .
hia3u3mq0v [ 2 ] , rtB . mgul3pau2j , & rtB . mkh53mukfc ) ; for ( i = 0 ; i
< 6 ; i ++ ) { j1fevedgmn [ i ] = m5jtfekt2h [ i ] + rtB . mkh53mukfc .
admi3yqyf0 [ i ] ; igwfvnz3vs [ i ] = rtX . lajj3kiv0r [ i ] ; rtB .
axybt0iosa [ i ] = rtX . musq314bsn [ i ] - rtB . mkh53mukfc . gtmlnhqoq0 [ i
] ; } d4w44phvgb ( igwfvnz3vs , rtB . axybt0iosa , & rtB . jc521lazxl ) ;
memcpy ( & eqhsiqgube [ 0 ] , & rtX . oljl1r15sy [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & cmxgtuqnwg [ 0 ] , & rtX . kdjra2pfq4 [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . cib1121v1a [ i ] =
rtX . ox0f0pxtqm [ i ] ; } jvlvilab4w ( j1fevedgmn , m5jtfekt2h , rtB .
jc521lazxl . hg1x1nd45k , eqhsiqgube , cmxgtuqnwg , rtB . cib1121v1a , rtB .
mkh53mukfc . jaolq3jrhd , & rtB . e5mxo1itjx ) ; ihouus1chq ( rtB .
e5mxo1itjx . m0i0p0mohd , & rtB . kkorjs14db ) ; for ( i = 0 ; i < 6 ; i ++ )
{ cojthb5n01 [ i ] = rtX . eu121u4uj2 [ i ] ; } if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB . jrkcafrldp [ i ] = rtDW .
mec2hevem0 [ i ] ; } } m1hec3vrd2 ( rtB . ixaiy5tpfv , rtB . kkorjs14db .
gwmh5422nv , rtB . jrkcafrldp , & rtB . dshtigbj0k ) ; for ( i = 0 ; i < 6 ;
i ++ ) { jvbvctwmjc [ i ] = cojthb5n01 [ i ] + rtB . dshtigbj0k . jl4fbhrop1
[ i ] ; oujugd4xou [ i ] = rtX . bgjp3vzt5z [ i ] ; f3tjt1n2uw [ i ] = rtX .
dn5twkxizj [ i ] - rtB . dshtigbj0k . j1zyuz5kzg [ i ] ; } l3dvuo1xw3 (
oujugd4xou , f3tjt1n2uw , & rtB . flkl1uejjb ) ; memcpy ( & asjv0xjmii [ 0 ]
, & rtX . eeiannul5v [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
hceboz13qc [ 0 ] , & rtX . czjyxcctju [ 0 ] , 36U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 6 ; i ++ ) { rtB . hb01w4hsae [ i ] = rtX . m0wpx0tt4b [ i ] ;
} jvlvilab4w ( jvbvctwmjc , cojthb5n01 , rtB . flkl1uejjb . l5c2p5rmcp ,
asjv0xjmii , hceboz13qc , rtB . hb01w4hsae , rtB . dshtigbj0k . dzda0l3ztv ,
& rtB . bv2yjfnafy ) ; g4g4bdu0ia ( rtB . kkorjs14db . hw5tnzrodd , rtB .
bv2yjfnafy . m0i0p0mohd , & rtB . lyoqvsgui4 ) ; ijextzfzou ( asjv0xjmii ,
hceboz13qc , & rtB . pjulmwnqfc ) ; lgndixfdt3 ( f3tjt1n2uw , & rtB .
plfgevb5mc ) ; lvvcxitelq ( jvbvctwmjc , rtB . hb01w4hsae , asjv0xjmii , &
rtB . fyu31sinwv ) ; bmxkvlwnui ( jvbvctwmjc , rtB . dshtigbj0k . dzda0l3ztv
, asjv0xjmii , hceboz13qc , & rtB . lnm54cnchk ) ; bmxkvlwnui ( j1fevedgmn ,
rtB . mkh53mukfc . jaolq3jrhd , eqhsiqgube , cmxgtuqnwg , & rtB . czo35p4wud
) ; ijextzfzou ( eqhsiqgube , cmxgtuqnwg , & rtB . epn4fcspwt ) ; lgndixfdt3
( rtB . axybt0iosa , & rtB . a4hw5bc5zg ) ; lvvcxitelq ( j1fevedgmn , rtB .
cib1121v1a , eqhsiqgube , & rtB . pxgpfywurc ) ; cqeiqxau2e = rtX .
kr3nejsoss ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . okfse5qvqh = rtDW .
gx01drbeka ; } e4pkw5vin4 = rtX . jclkuzenpd - rtB . okfse5qvqh ; lunmotda0s
( cqeiqxau2e , e4pkw5vin4 , & rtB . cxzd2dbymf ) ; c3hsf3zf4q ( e4pkw5vin4 ,
& rtB . h5gd3tgpey ) ; memcpy ( & rtB . l1rog3vm3b [ 0 ] , & rtX . bpmgvfdh3p
[ 0 ] , 12U * sizeof ( real_T ) ) ; hwodfh00oh ( rtB . l1rog3vm3b , rtB .
jiz3a002c3 , rtB . okfse5qvqh , rtB . a03f1j3hsr , rtB . cxzd2dbymf .
mxe5eu4hb4 , & rtB . de51ggtvmf ) ; p4ux2p5zld [ 0 ] = rtX . ntmiect20q [ 0 ]
; dlbvbal5em [ 0 ] = rtX . nw2qbjtrfg [ 0 ] ; mn0cep4xml [ 0 ] = rtX .
eysiy0scrq [ 0 ] ; hwanmflst1 [ 0 ] = rtX . cyoaoohsr1 [ 0 ] ; p4ux2p5zld [ 1
] = rtX . ntmiect20q [ 1 ] ; dlbvbal5em [ 1 ] = rtX . nw2qbjtrfg [ 1 ] ;
mn0cep4xml [ 1 ] = rtX . eysiy0scrq [ 1 ] ; hwanmflst1 [ 1 ] = rtX .
cyoaoohsr1 [ 1 ] ; olmchesjlh ( rtB . ovp54ku00f , rtB . au5wbjjqt3 , rtB .
jiz3a002c3 , rtB . peasbjr2ah , rtB . fyll5jdjjj , rtB . obobcozbfh , rtB .
kthfd0aif2 , rtB . n1skxybgba , rtB . c0vcvn0r0g , rtB . mwkffby2ul , rtP .
Constant2_Value_pdqwrfjlqe , p4ux2p5zld , dlbvbal5em , mn0cep4xml ,
hwanmflst1 , rtP . Agent_Value_isepnlmbdh , & rtB . kcdsohu0vj ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . p32mbcnx3i [ 0 ] = rtDW . c1300gzrjt
[ 0 ] ; rtB . p32mbcnx3i [ 1 ] = rtDW . c1300gzrjt [ 1 ] ; } rtB . ewwxrohews
[ 0 ] = rtB . p32mbcnx3i [ 0 ] - rtB . a03f1j3hsr [ 0 ] ; rtB . ika3sw4mwy [
0 ] = rtB . cdzixgvais [ 0 ] - rtB . jiz3a002c3 [ 0 ] ; dioxq0k1s2 [ 0 ] =
rtX . d5kjlwmgrk [ 0 ] ; ngodd0lb2l [ 0 ] = rtX . i1zsver5ig [ 0 ] ;
d5pt2aombs [ 0 ] = rtX . llgwidxzty [ 0 ] ; d0n3jvuzli [ 0 ] = rtX .
dcluu2qq0c [ 0 ] ; rtB . ewwxrohews [ 1 ] = rtB . p32mbcnx3i [ 1 ] - rtB .
a03f1j3hsr [ 1 ] ; rtB . ika3sw4mwy [ 1 ] = rtB . cdzixgvais [ 1 ] - rtB .
jiz3a002c3 [ 1 ] ; dioxq0k1s2 [ 1 ] = rtX . d5kjlwmgrk [ 1 ] ; ngodd0lb2l [ 1
] = rtX . i1zsver5ig [ 1 ] ; d5pt2aombs [ 1 ] = rtX . llgwidxzty [ 1 ] ;
d0n3jvuzli [ 1 ] = rtX . dcluu2qq0c [ 1 ] ; ew4afwvte5 ( rtB . guii4af3w0 ,
rtB . nr2xhydys1 , rtB . a03f1j3hsr , rtB . ma4hr1zg5h , rtB . mka13uwfw0 ,
rtB . kjfk5s4txt , rtB . cq2ac25vvr , rtB . f3swi4wykw , rtB . olxq5nidun .
g2qarspkxz , rtP . Constant1_Value_bg3mr2ch10 , dioxq0k1s2 , ngodd0lb2l ,
d5pt2aombs , d0n3jvuzli , rtP . Agent_Value_isepnlmbdh , & rtB . jwtc4eqcdp )
; memcpy ( & kob0ibjlgv . t1 [ 0 ] , & mk2kwho04h [ 0 ] , 15U * sizeof (
real_T ) ) ; memcpy ( & kob0ibjlgv . t2 [ 0 ] , & ft1p4me3if [ 0 ] , 15U *
sizeof ( real_T ) ) ; memcpy ( & kob0ibjlgv . t3 [ 0 ] , & bcehnxyd3h [ 0 ] ,
15U * sizeof ( real_T ) ) ; memcpy ( & kob0ibjlgv . t4 [ 0 ] , & myowtlscss [
0 ] , 15U * sizeof ( real_T ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
memcpy ( & rtB . bszz24pz1b . eps1 [ 0 ] , & kderxbgjob [ 0 ] , 15U * sizeof
( real_T ) ) ; memcpy ( & rtB . bszz24pz1b . eps2 [ 0 ] , & ibg3dwhse0 [ 0 ]
, 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . bszz24pz1b . eps3 [ 0 ] , &
fnkf1abqw5 [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . bszz24pz1b .
eps4 [ 0 ] , & pk1hppghip [ 0 ] , 15U * sizeof ( real_T ) ) ; } g0rn2igfkt (
& kob0ibjlgv , & rtB . bszz24pz1b , bcehnxyd3h , ikri1d1nmq , rtP .
Agent_Value_isepnlmbdh , & rtB . a51pswiot5 ) ; mza03d5fve [ 0 ] = rtB .
cbz53iqiop [ 0 ] ; mza03d5fve [ 3 ] = rtB . jp4yty50ed [ 0 ] ; mza03d5fve [ 6
] = rtB . c5ojbulhcl [ 0 ] ; mza03d5fve [ 9 ] = rtB . c2fmjucg5f [ 0 ] ;
dhuhfjmuec [ 0 ] = rtB . fjnyclhmei [ 0 ] ; dhuhfjmuec [ 3 ] = rtB .
i10izinweb [ 0 ] ; dhuhfjmuec [ 6 ] = rtB . ar5mtka5cc [ 0 ] ; dhuhfjmuec [ 9
] = rtB . gorv20ywqu [ 0 ] ; rtB . cbvb41g3bt [ 0 ] = ( real_T ) l_e [ ( ( (
( int32_T ) rtP . Agent_Value_isepnlmbdh - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_isepnlmbdh ) - 1 ] * ( rtB . c5ojbulhcl [ 0 ] - rtB . c0vcvn0r0g
) ; bv0exnxaiw = 0.0 ; mza03d5fve [ 1 ] = rtB . cbz53iqiop [ 1 ] ; mza03d5fve
[ 4 ] = rtB . jp4yty50ed [ 1 ] ; mza03d5fve [ 7 ] = rtB . c5ojbulhcl [ 1 ] ;
mza03d5fve [ 10 ] = rtB . c2fmjucg5f [ 1 ] ; dhuhfjmuec [ 1 ] = rtB .
fjnyclhmei [ 1 ] ; dhuhfjmuec [ 4 ] = rtB . i10izinweb [ 1 ] ; dhuhfjmuec [ 7
] = rtB . ar5mtka5cc [ 1 ] ; dhuhfjmuec [ 10 ] = rtB . gorv20ywqu [ 1 ] ; rtB
. cbvb41g3bt [ 1 ] = ( real_T ) l_e [ ( ( ( ( int32_T ) rtP .
Agent_Value_isepnlmbdh - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_isepnlmbdh ) - 1 ] * ( rtB . c5ojbulhcl [ 1 ] - rtB . mwkffby2ul
) ; biumkvvuc1 = 0.0 ; mza03d5fve [ 2 ] = rtB . cbz53iqiop [ 2 ] ; mza03d5fve
[ 5 ] = rtB . jp4yty50ed [ 2 ] ; mza03d5fve [ 8 ] = rtB . c5ojbulhcl [ 2 ] ;
mza03d5fve [ 11 ] = rtB . c2fmjucg5f [ 2 ] ; dhuhfjmuec [ 2 ] = rtB .
fjnyclhmei [ 2 ] ; dhuhfjmuec [ 5 ] = rtB . i10izinweb [ 2 ] ; dhuhfjmuec [ 8
] = rtB . ar5mtka5cc [ 2 ] ; dhuhfjmuec [ 11 ] = rtB . gorv20ywqu [ 2 ] ; rtB
. cbvb41g3bt [ 2 ] = ( real_T ) l_e [ ( ( ( ( int32_T ) rtP .
Agent_Value_isepnlmbdh - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_isepnlmbdh ) - 1 ] * ( rtB . c5ojbulhcl [ 2 ] - rtB . i3h3tvdsd4
) ; nat0cpttuo = 0.0 ; for ( i = 0 ; i < 4 ; i ++ ) { b = i * ( int32_T )
amqgqkb2nu + 1 ; c = ( 1 + i ) * ( int32_T ) amqgqkb2nu ; if ( b > c ) { b =
1 ; c = 0 ; } c -= b ; for ( i_p = 0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] =
( int8_T ) ( b + i_p ) ; } rtB . cbvb41g3bt [ 0 ] += ( real_T ) m_e [ ( ( i
<< 2 ) + ( int32_T ) rtP . Agent_Value_isepnlmbdh ) - 1 ] * ( rtB .
c5ojbulhcl [ 0 ] - mza03d5fve [ b_data [ 0 ] - 1 ] ) ; rtB . cbvb41g3bt [ 1 ]
+= ( real_T ) m_e [ ( ( i << 2 ) + ( int32_T ) rtP . Agent_Value_isepnlmbdh )
- 1 ] * ( rtB . c5ojbulhcl [ 1 ] - mza03d5fve [ b_data [ 1 ] - 1 ] ) ; rtB .
cbvb41g3bt [ 2 ] += ( real_T ) m_e [ ( ( i << 2 ) + ( int32_T ) rtP .
Agent_Value_isepnlmbdh ) - 1 ] * ( rtB . c5ojbulhcl [ 2 ] - mza03d5fve [
b_data [ 2 ] - 1 ] ) ; b = i * ( int32_T ) amqgqkb2nu + 1 ; c = ( 1 + i ) * (
int32_T ) amqgqkb2nu ; if ( b > c ) { b = 1 ; c = 0 ; } c -= b ; for ( i_p =
0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] = ( int8_T ) ( b + i_p ) ; }
bv0exnxaiw += rtP . H [ ( ( ( int32_T ) rtP . Agent_Value_isepnlmbdh - 1 ) <<
2 ) + i ] * dhuhfjmuec [ b_data [ 0 ] - 1 ] ; biumkvvuc1 += rtP . H [ ( ( (
int32_T ) rtP . Agent_Value_isepnlmbdh - 1 ) << 2 ) + i ] * dhuhfjmuec [
b_data [ 1 ] - 1 ] ; nat0cpttuo += rtP . H [ ( ( ( int32_T ) rtP .
Agent_Value_isepnlmbdh - 1 ) << 2 ) + i ] * dhuhfjmuec [ b_data [ 2 ] - 1 ] ;
} bv0exnxaiw /= muDoubleScalarAbs ( bv0exnxaiw ) + rtP . alpha ; biumkvvuc1
/= muDoubleScalarAbs ( biumkvvuc1 ) + rtP . alpha ; memset ( & b_d [ 0 ] , 0
, 9U * sizeof ( real_T ) ) ; b_d [ 0 ] = bv0exnxaiw ; b_d [ 4 ] = biumkvvuc1
; b_d [ 8 ] = nat0cpttuo / ( muDoubleScalarAbs ( nat0cpttuo ) + rtP . alpha )
; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . awhqz5sjvx [ i_p ] = - rtP .
Observer_Gain * rtB . cbvb41g3bt [ i_p ] - ( ( b_d [ i_p + 3 ] * rtP .
U_dot0_M [ 1 ] + b_d [ i_p ] * rtP . U_dot0_M [ 0 ] ) + b_d [ i_p + 6 ] * rtP
. U_dot0_M [ 2 ] ) ; } rtB . mfq4qoe4yi [ 0 ] = k5arailkcv - rtB . cdzixgvais
[ 0 ] ; rtB . mfq4qoe4yi [ 1 ] = iidkxpk2kt - rtB . cdzixgvais [ 1 ] ; rtB .
mfq4qoe4yi [ 2 ] = rtB . bhiqn3njpt . hia3u3mq0v [ 2 ] - rtB . okfse5qvqh ;
opqefn2kjs = ssGetT ( rtS ) ; bifsfih4ms ( rtB . l1rog3vm3b , rtB .
lyoqvsgui4 . ollm0kao5t [ 0 ] , rtB . lyoqvsgui4 . ollm0kao5t [ 1 ] , rtB .
lyoqvsgui4 . ollm0kao5t [ 2 ] , rtB . lyoqvsgui4 . ollm0kao5t [ 3 ] ,
opqefn2kjs , & rtB . ntpm2p40uf ) ; bv0exnxaiw = rtP . Gain_Gain_acstczzfy2 *
rtX . mfmirsuvi1 ; mmucqnnnoe = rtX . ajtyxihfqa ; hp20ymhe1e ( rtB .
c0vcvn0r0g , rtB . mwkffby2ul , rtB . cdzixgvais , & rtB . gmjjjikxkv ) ;
jsyspemnzc = bv0exnxaiw - rtB . gmjjjikxkv . esbc0t1dta ; lunmotda0s (
mmucqnnnoe , jsyspemnzc , & rtB . oja35avhxy ) ; c3hsf3zf4q ( jsyspemnzc , &
rtB . ga1oou1sez ) ; onqykep2vg ( d0n3jvuzli , rtB . gmjjjikxkv . esbc0t1dta
, hwanmflst1 , & rtB . oiztqgxwa2 ) ; clizedqd12 [ 0 ] = rtB . bqxn34m0qr [ 0
] - rtB . oule4qndjw . g2qarspkxz [ 0 ] ; clizedqd12 [ 1 ] = rtB . bqxn34m0qr
[ 1 ] - rtB . oule4qndjw . g2qarspkxz [ 1 ] ; ifmmcug2wn ( clizedqd12 , rtB .
oja35avhxy . mxe5eu4hb4 , d0n3jvuzli , & rtB . aqzxsisqqu ) ; bv0exnxaiw =
rtP . Gain_Gain_kma3okcfj1 * rtX . fev21ha45i ; ejuilkyqm0 = rtX . daodwibywh
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB . ibguh2azcu , rtB
. cdzixgvais , & rtB . l2j5ycxexp ) ; } ahff4el43j = bv0exnxaiw - rtB .
l2j5ycxexp . ortedkvoqi ; lunmotda0s ( ejuilkyqm0 , ahff4el43j , & rtB .
cx0tbybfel ) ; c3hsf3zf4q ( ahff4el43j , & rtB . aax0e1c4lb ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . jaakjngya0 [ 0 ] = rtB . bqxn34m0qr [
0 ] - rtB . kakeuy45nl [ 0 ] ; rtB . jaakjngya0 [ 1 ] = rtB . bqxn34m0qr [ 1
] - rtB . kakeuy45nl [ 1 ] ; } ifmmcug2wn ( rtB . jaakjngya0 , rtB .
cx0tbybfel . mxe5eu4hb4 , dioxq0k1s2 , & rtB . mdircrytff ) ; onqykep2vg (
dioxq0k1s2 , rtB . l2j5ycxexp . ortedkvoqi , p4ux2p5zld , & rtB . avalzerqm0
) ; bv0exnxaiw = rtP . Gain_Gain_k45mubfrmr * rtX . lkyqetg5kb ; f4sgkgovmw =
rtX . btc4odj1vw ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB .
leex1vr2mc , rtB . cdzixgvais , & rtB . ns3lzfiy1g ) ; } hadxatt5uc =
bv0exnxaiw - rtB . ns3lzfiy1g . ortedkvoqi ; lunmotda0s ( f4sgkgovmw ,
hadxatt5uc , & rtB . pltjyjalnc ) ; c3hsf3zf4q ( hadxatt5uc , & rtB .
iinpzr5pdo ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ielqt1mrev [ 0 ]
= rtB . bqxn34m0qr [ 0 ] - rtB . ixqvkyn0bs [ 0 ] ; rtB . ielqt1mrev [ 1 ] =
rtB . bqxn34m0qr [ 1 ] - rtB . ixqvkyn0bs [ 1 ] ; } ifmmcug2wn ( rtB .
ielqt1mrev , rtB . pltjyjalnc . mxe5eu4hb4 , ngodd0lb2l , & rtB . l1combp0kl
) ; onqykep2vg ( ngodd0lb2l , rtB . ns3lzfiy1g . ortedkvoqi , dlbvbal5em , &
rtB . h2durator1 ) ; bv0exnxaiw = rtP . Gain_Gain_ofmtkpdy0q * rtX .
c0pmpkzruv ; hzqungsokc = rtX . jlansep42b ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { l1ggp544gs ( rtB . ordnmswswg , rtB . cdzixgvais , & rtB . mrepog2h42 )
; } kjsm5iare5 = bv0exnxaiw - rtB . mrepog2h42 . ortedkvoqi ; lunmotda0s (
hzqungsokc , kjsm5iare5 , & rtB . axqhmtwvft ) ; c3hsf3zf4q ( kjsm5iare5 , &
rtB . fsjvhtbxoc ) ; onqykep2vg ( d5pt2aombs , rtB . mrepog2h42 . ortedkvoqi
, mn0cep4xml , & rtB . c5nge20guz ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . amoxktpzg5 [ 0 ] = rtB . bqxn34m0qr [ 0 ] - rtB . ajq0qn0k3g [ 0 ] ;
rtB . amoxktpzg5 [ 1 ] = rtB . bqxn34m0qr [ 1 ] - rtB . ajq0qn0k3g [ 1 ] ; }
ifmmcug2wn ( rtB . amoxktpzg5 , rtB . axqhmtwvft . mxe5eu4hb4 , d5pt2aombs ,
& rtB . h0rgneuhfx ) ; for ( i = 0 ; i < 6 ; i ++ ) { kevdovkfex [ i ] = rtX
. lbivgbnpeh [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & rtB
. keppwjdt4q [ 0 ] , & rtDW . kbb0qw5mp3 [ 0 ] , 12U * sizeof ( real_T ) ) ;
} { real_T * * uBuffer = ( real_T * * ) & rtDW . e0iyas1xpb . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . e0iyas1xpb . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP
. TransportDelay1_Delay_kvdadosi3i ; c1isjfsich = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . j5kjeh2fcr .
CircularBufSize , & rtDW . j5kjeh2fcr . Last , rtDW . j5kjeh2fcr . Tail ,
rtDW . j5kjeh2fcr . Head , rtP . TransportDelay1_InitOutput_mvsywcmphq , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
gcbrh04vlv . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. gcbrh04vlv . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay2_Delay_odn4ujxefs ; doxfufmtfc =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
fckn41cqic . CircularBufSize , & rtDW . fckn41cqic . Last , rtDW . fckn41cqic
. Tail , rtDW . fckn41cqic . Head , rtP .
TransportDelay2_InitOutput_gcfy4mzc0f , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; }
my0xtyxafz ( rtB . c2fmjucg5f , myowtlscss , rtP . Agent_Value_og3en2mdcn , &
rtB . bsfibrztcn ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . c01olslca1 [ i ] = rtDW . ppddj1qhga [ i ] ; } }
nnvj0nbsr4 ( rtB . keppwjdt4q , c1isjfsich , doxfufmtfc , rtB . bsfibrztcn .
hia3u3mq0v [ 2 ] , rtB . c01olslca1 , & rtB . ayhvjwdkil ) ; for ( i = 0 ; i
< 6 ; i ++ ) { da3asulki1 [ i ] = kevdovkfex [ i ] + rtB . ayhvjwdkil .
admi3yqyf0 [ i ] ; a0zewajuko [ i ] = rtX . m54hyt4uuq [ i ] ; rtB .
nnrb331rfb [ i ] = rtX . lxl24bgnmj [ i ] - rtB . ayhvjwdkil . gtmlnhqoq0 [ i
] ; } d4w44phvgb ( a0zewajuko , rtB . nnrb331rfb , & rtB . czfjlbeq0m ) ;
memcpy ( & ewjuw2ilww [ 0 ] , & rtX . efyhshm0ot [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & g3tawas44r [ 0 ] , & rtX . gdfmrn5gpc [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . fmwnvf0vev [ i ] =
rtX . jbncktdjxo [ i ] ; } jvlvilab4w ( da3asulki1 , kevdovkfex , rtB .
czfjlbeq0m . hg1x1nd45k , ewjuw2ilww , g3tawas44r , rtB . fmwnvf0vev , rtB .
ayhvjwdkil . jaolq3jrhd , & rtB . nbpckilwbi ) ; ihouus1chq ( rtB .
nbpckilwbi . m0i0p0mohd , & rtB . nxtnef4xl5 ) ; for ( i = 0 ; i < 6 ; i ++ )
{ hb2wqxwtnz [ i ] = rtX . kwvqencn2m [ i ] ; } if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB . nx0lawusi5 [ i ] = rtDW .
igxhj4adkf [ i ] ; } } m1hec3vrd2 ( rtB . keppwjdt4q , rtB . nxtnef4xl5 .
gwmh5422nv , rtB . nx0lawusi5 , & rtB . p3oko5rg5q ) ; for ( i = 0 ; i < 6 ;
i ++ ) { hkyzlc0yxi [ i ] = hb2wqxwtnz [ i ] + rtB . p3oko5rg5q . jl4fbhrop1
[ i ] ; nkxdy02403 [ i ] = rtX . el0s1crasb [ i ] ; de5pktfu00 [ i ] = rtX .
iiijpho0bw [ i ] - rtB . p3oko5rg5q . j1zyuz5kzg [ i ] ; } l3dvuo1xw3 (
nkxdy02403 , de5pktfu00 , & rtB . cycndcb0jh ) ; memcpy ( & afwyumpfjk [ 0 ]
, & rtX . ef5r0lp3ux [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
lwby3kv103 [ 0 ] , & rtX . iuw551xzyz [ 0 ] , 36U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 6 ; i ++ ) { rtB . o2px3pavbt [ i ] = rtX . fqk1pcxz11 [ i ] ;
} jvlvilab4w ( hkyzlc0yxi , hb2wqxwtnz , rtB . cycndcb0jh . l5c2p5rmcp ,
afwyumpfjk , lwby3kv103 , rtB . o2px3pavbt , rtB . p3oko5rg5q . dzda0l3ztv ,
& rtB . ejz0pvfgin ) ; g4g4bdu0ia ( rtB . nxtnef4xl5 . hw5tnzrodd , rtB .
ejz0pvfgin . m0i0p0mohd , & rtB . hfcfmmylgh ) ; ijextzfzou ( afwyumpfjk ,
lwby3kv103 , & rtB . c2otonew4a ) ; lgndixfdt3 ( de5pktfu00 , & rtB .
oreloirudv ) ; lvvcxitelq ( hkyzlc0yxi , rtB . o2px3pavbt , afwyumpfjk , &
rtB . mnhfszymlh ) ; bmxkvlwnui ( hkyzlc0yxi , rtB . p3oko5rg5q . dzda0l3ztv
, afwyumpfjk , lwby3kv103 , & rtB . hclvb5l0yw ) ; bmxkvlwnui ( da3asulki1 ,
rtB . ayhvjwdkil . jaolq3jrhd , ewjuw2ilww , g3tawas44r , & rtB . aps0x4iowd
) ; ijextzfzou ( ewjuw2ilww , g3tawas44r , & rtB . jwvzg3dbyn ) ; lgndixfdt3
( rtB . nnrb331rfb , & rtB . ock5oqnuqf ) ; lvvcxitelq ( da3asulki1 , rtB .
fmwnvf0vev , ewjuw2ilww , & rtB . fxmpoowwke ) ; owsbtwq0e0 = rtX .
guiwz4qjqi ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fzvqljdzf0 = rtDW .
kiivcdig1l ; } egrxutye5g = rtX . nvrhieikes - rtB . fzvqljdzf0 ; lunmotda0s
( owsbtwq0e0 , egrxutye5g , & rtB . lh525nk5c4 ) ; c3hsf3zf4q ( egrxutye5g ,
& rtB . gbsw4vtbfc ) ; memcpy ( & rtB . azahyglgjt [ 0 ] , & rtX . p3bnpoi4ms
[ 0 ] , 12U * sizeof ( real_T ) ) ; hwodfh00oh ( rtB . azahyglgjt , rtB .
peasbjr2ah , rtB . fzvqljdzf0 , rtB . ma4hr1zg5h , rtB . lh525nk5c4 .
mxe5eu4hb4 , & rtB . krha0qyekz ) ; aoe4zh2mj2 [ 0 ] = rtX . fat2ntucmp [ 0 ]
; lrzsifyq0e [ 0 ] = rtX . f23ygfhi2f [ 0 ] ; nbzg4ig4di [ 0 ] = rtX .
jl5u0so5kr [ 0 ] ; gd0aup02ek [ 0 ] = rtX . m4oor1dqcu [ 0 ] ; aoe4zh2mj2 [ 1
] = rtX . fat2ntucmp [ 1 ] ; lrzsifyq0e [ 1 ] = rtX . f23ygfhi2f [ 1 ] ;
nbzg4ig4di [ 1 ] = rtX . jl5u0so5kr [ 1 ] ; gd0aup02ek [ 1 ] = rtX .
m4oor1dqcu [ 1 ] ; olmchesjlh ( rtB . ovp54ku00f , rtB . au5wbjjqt3 , rtB .
jiz3a002c3 , rtB . peasbjr2ah , rtB . fyll5jdjjj , rtB . obobcozbfh , rtB .
kthfd0aif2 , rtB . n1skxybgba , rtB . c0vcvn0r0g , rtB . mwkffby2ul , rtP .
Constant2_Value_oeh4ce2iba , aoe4zh2mj2 , lrzsifyq0e , nbzg4ig4di ,
gd0aup02ek , rtP . Agent_Value_og3en2mdcn , & rtB . ktgydrdwot ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . e4bknlrhvn [ 0 ] = rtDW . jpwsqsteoo
[ 0 ] ; rtB . e4bknlrhvn [ 1 ] = rtDW . jpwsqsteoo [ 1 ] ; } rtB . lipbvqqq2c
[ 0 ] = rtB . e4bknlrhvn [ 0 ] - rtB . ma4hr1zg5h [ 0 ] ; rtB . jbsiq0ysnz [
0 ] = rtB . ordnmswswg [ 0 ] - rtB . peasbjr2ah [ 0 ] ; ocfqrkadip [ 0 ] =
rtX . edonk3lpof [ 0 ] ; ncs31u0ld2 [ 0 ] = rtX . c2d4vnjngq [ 0 ] ;
nzppf3gsca [ 0 ] = rtX . ixb5n0f1pg [ 0 ] ; nwevcd1hd3 [ 0 ] = rtX .
mvd25m5wxn [ 0 ] ; rtB . lipbvqqq2c [ 1 ] = rtB . e4bknlrhvn [ 1 ] - rtB .
ma4hr1zg5h [ 1 ] ; rtB . jbsiq0ysnz [ 1 ] = rtB . ordnmswswg [ 1 ] - rtB .
peasbjr2ah [ 1 ] ; ocfqrkadip [ 1 ] = rtX . edonk3lpof [ 1 ] ; ncs31u0ld2 [ 1
] = rtX . c2d4vnjngq [ 1 ] ; nzppf3gsca [ 1 ] = rtX . ixb5n0f1pg [ 1 ] ;
nwevcd1hd3 [ 1 ] = rtX . mvd25m5wxn [ 1 ] ; ew4afwvte5 ( rtB . guii4af3w0 ,
rtB . nr2xhydys1 , rtB . a03f1j3hsr , rtB . ma4hr1zg5h , rtB . mka13uwfw0 ,
rtB . kjfk5s4txt , rtB . cq2ac25vvr , rtB . f3swi4wykw , rtB . olxq5nidun .
g2qarspkxz , rtP . Constant1_Value_d1t3cyklvs , ocfqrkadip , ncs31u0ld2 ,
nzppf3gsca , nwevcd1hd3 , rtP . Agent_Value_og3en2mdcn , & rtB . jh4bhzwp5a )
; memcpy ( & hue2gx3vel . t1 [ 0 ] , & mk2kwho04h [ 0 ] , 15U * sizeof (
real_T ) ) ; memcpy ( & hue2gx3vel . t2 [ 0 ] , & ft1p4me3if [ 0 ] , 15U *
sizeof ( real_T ) ) ; memcpy ( & hue2gx3vel . t3 [ 0 ] , & bcehnxyd3h [ 0 ] ,
15U * sizeof ( real_T ) ) ; memcpy ( & hue2gx3vel . t4 [ 0 ] , & myowtlscss [
0 ] , 15U * sizeof ( real_T ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
memcpy ( & rtB . fxxr4yxfew . eps1 [ 0 ] , & kderxbgjob [ 0 ] , 15U * sizeof
( real_T ) ) ; memcpy ( & rtB . fxxr4yxfew . eps2 [ 0 ] , & ibg3dwhse0 [ 0 ]
, 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . fxxr4yxfew . eps3 [ 0 ] , &
fnkf1abqw5 [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtB . fxxr4yxfew .
eps4 [ 0 ] , & pk1hppghip [ 0 ] , 15U * sizeof ( real_T ) ) ; } g0rn2igfkt (
& hue2gx3vel , & rtB . fxxr4yxfew , myowtlscss , ikri1d1nmq , rtP .
Agent_Value_og3en2mdcn , & rtB . cynnr55l50 ) ; mza03d5fve [ 0 ] = rtB .
cbz53iqiop [ 0 ] ; mza03d5fve [ 3 ] = rtB . jp4yty50ed [ 0 ] ; mza03d5fve [ 6
] = rtB . c5ojbulhcl [ 0 ] ; mza03d5fve [ 9 ] = rtB . c2fmjucg5f [ 0 ] ;
dhuhfjmuec [ 0 ] = rtB . fjnyclhmei [ 0 ] ; dhuhfjmuec [ 3 ] = rtB .
i10izinweb [ 0 ] ; dhuhfjmuec [ 6 ] = rtB . ar5mtka5cc [ 0 ] ; dhuhfjmuec [ 9
] = rtB . gorv20ywqu [ 0 ] ; rtB . gsrbrbeiwt [ 0 ] = ( real_T ) l_i [ ( ( (
( int32_T ) rtP . Agent_Value_og3en2mdcn - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_og3en2mdcn ) - 1 ] * ( rtB . c2fmjucg5f [ 0 ] - rtB . c0vcvn0r0g
) ; bv0exnxaiw = 0.0 ; mza03d5fve [ 1 ] = rtB . cbz53iqiop [ 1 ] ; mza03d5fve
[ 4 ] = rtB . jp4yty50ed [ 1 ] ; mza03d5fve [ 7 ] = rtB . c5ojbulhcl [ 1 ] ;
mza03d5fve [ 10 ] = rtB . c2fmjucg5f [ 1 ] ; dhuhfjmuec [ 1 ] = rtB .
fjnyclhmei [ 1 ] ; dhuhfjmuec [ 4 ] = rtB . i10izinweb [ 1 ] ; dhuhfjmuec [ 7
] = rtB . ar5mtka5cc [ 1 ] ; dhuhfjmuec [ 10 ] = rtB . gorv20ywqu [ 1 ] ; rtB
. gsrbrbeiwt [ 1 ] = ( real_T ) l_i [ ( ( ( ( int32_T ) rtP .
Agent_Value_og3en2mdcn - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_og3en2mdcn ) - 1 ] * ( rtB . c2fmjucg5f [ 1 ] - rtB . mwkffby2ul
) ; biumkvvuc1 = 0.0 ; mza03d5fve [ 2 ] = rtB . cbz53iqiop [ 2 ] ; mza03d5fve
[ 5 ] = rtB . jp4yty50ed [ 2 ] ; mza03d5fve [ 8 ] = rtB . c5ojbulhcl [ 2 ] ;
mza03d5fve [ 11 ] = rtB . c2fmjucg5f [ 2 ] ; dhuhfjmuec [ 2 ] = rtB .
fjnyclhmei [ 2 ] ; dhuhfjmuec [ 5 ] = rtB . i10izinweb [ 2 ] ; dhuhfjmuec [ 8
] = rtB . ar5mtka5cc [ 2 ] ; dhuhfjmuec [ 11 ] = rtB . gorv20ywqu [ 2 ] ; rtB
. gsrbrbeiwt [ 2 ] = ( real_T ) l_i [ ( ( ( ( int32_T ) rtP .
Agent_Value_og3en2mdcn - 1 ) << 2 ) + ( int32_T ) rtP .
Agent_Value_og3en2mdcn ) - 1 ] * ( rtB . c2fmjucg5f [ 2 ] - rtB . i3h3tvdsd4
) ; nat0cpttuo = 0.0 ; for ( i = 0 ; i < 4 ; i ++ ) { b = i * ( int32_T )
amqgqkb2nu + 1 ; c = ( 1 + i ) * ( int32_T ) amqgqkb2nu ; if ( b > c ) { b =
1 ; c = 0 ; } c -= b ; for ( i_p = 0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] =
( int8_T ) ( b + i_p ) ; } rtB . gsrbrbeiwt [ 0 ] += ( real_T ) m_i [ ( ( i
<< 2 ) + ( int32_T ) rtP . Agent_Value_og3en2mdcn ) - 1 ] * ( rtB .
c2fmjucg5f [ 0 ] - mza03d5fve [ b_data [ 0 ] - 1 ] ) ; rtB . gsrbrbeiwt [ 1 ]
+= ( real_T ) m_i [ ( ( i << 2 ) + ( int32_T ) rtP . Agent_Value_og3en2mdcn )
- 1 ] * ( rtB . c2fmjucg5f [ 1 ] - mza03d5fve [ b_data [ 1 ] - 1 ] ) ; rtB .
gsrbrbeiwt [ 2 ] += ( real_T ) m_i [ ( ( i << 2 ) + ( int32_T ) rtP .
Agent_Value_og3en2mdcn ) - 1 ] * ( rtB . c2fmjucg5f [ 2 ] - mza03d5fve [
b_data [ 2 ] - 1 ] ) ; b = i * ( int32_T ) amqgqkb2nu + 1 ; c = ( 1 + i ) * (
int32_T ) amqgqkb2nu ; if ( b > c ) { b = 1 ; c = 0 ; } c -= b ; for ( i_p =
0 ; i_p <= c ; i_p ++ ) { b_data [ i_p ] = ( int8_T ) ( b + i_p ) ; }
bv0exnxaiw += rtP . H [ ( ( ( int32_T ) rtP . Agent_Value_og3en2mdcn - 1 ) <<
2 ) + i ] * dhuhfjmuec [ b_data [ 0 ] - 1 ] ; biumkvvuc1 += rtP . H [ ( ( (
int32_T ) rtP . Agent_Value_og3en2mdcn - 1 ) << 2 ) + i ] * dhuhfjmuec [
b_data [ 1 ] - 1 ] ; nat0cpttuo += rtP . H [ ( ( ( int32_T ) rtP .
Agent_Value_og3en2mdcn - 1 ) << 2 ) + i ] * dhuhfjmuec [ b_data [ 2 ] - 1 ] ;
} bv0exnxaiw /= muDoubleScalarAbs ( bv0exnxaiw ) + rtP . alpha ; biumkvvuc1
/= muDoubleScalarAbs ( biumkvvuc1 ) + rtP . alpha ; memset ( & b_d [ 0 ] , 0
, 9U * sizeof ( real_T ) ) ; b_d [ 0 ] = bv0exnxaiw ; b_d [ 4 ] = biumkvvuc1
; b_d [ 8 ] = nat0cpttuo / ( muDoubleScalarAbs ( nat0cpttuo ) + rtP . alpha )
; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . epn3tgotb3 [ i_p ] = - rtP .
Observer_Gain * rtB . gsrbrbeiwt [ i_p ] - ( ( b_d [ i_p + 3 ] * rtP .
U_dot0_M [ 1 ] + b_d [ i_p ] * rtP . U_dot0_M [ 0 ] ) + b_d [ i_p + 6 ] * rtP
. U_dot0_M [ 2 ] ) ; } rtB . ndqfi1y1ay [ 0 ] = c1isjfsich - rtB . ordnmswswg
[ 0 ] ; rtB . ndqfi1y1ay [ 1 ] = doxfufmtfc - rtB . ordnmswswg [ 1 ] ; rtB .
ndqfi1y1ay [ 2 ] = rtB . bsfibrztcn . hia3u3mq0v [ 2 ] - rtB . fzvqljdzf0 ;
hqsfqbo3wu = ssGetT ( rtS ) ; bifsfih4ms ( rtB . azahyglgjt , rtB .
hfcfmmylgh . ollm0kao5t [ 0 ] , rtB . hfcfmmylgh . ollm0kao5t [ 1 ] , rtB .
hfcfmmylgh . ollm0kao5t [ 2 ] , rtB . hfcfmmylgh . ollm0kao5t [ 3 ] ,
hqsfqbo3wu , & rtB . kb4nwcrwes ) ; bv0exnxaiw = rtP . Gain_Gain_nfjg5pily2 *
rtX . axapvnuown ; py5tr2btjw = rtX . fk4euimlnu ; hp20ymhe1e ( rtB .
c0vcvn0r0g , rtB . mwkffby2ul , rtB . ordnmswswg , & rtB . hej02ixwew ) ;
abqgyjydct = bv0exnxaiw - rtB . hej02ixwew . esbc0t1dta ; lunmotda0s (
py5tr2btjw , abqgyjydct , & rtB . ngaywgoh4j ) ; c3hsf3zf4q ( abqgyjydct , &
rtB . a40jt3tdup ) ; onqykep2vg ( nwevcd1hd3 , rtB . hej02ixwew . esbc0t1dta
, gd0aup02ek , & rtB . oddtrbrdmn ) ; exvktcaqkj [ 0 ] = rtB . ajq0qn0k3g [ 0
] - rtB . oule4qndjw . g2qarspkxz [ 0 ] ; exvktcaqkj [ 1 ] = rtB . ajq0qn0k3g
[ 1 ] - rtB . oule4qndjw . g2qarspkxz [ 1 ] ; ifmmcug2wn ( exvktcaqkj , rtB .
ngaywgoh4j . mxe5eu4hb4 , nwevcd1hd3 , & rtB . myur3d20g5 ) ; bv0exnxaiw =
rtP . Gain_Gain_n2wlxh3aqj * rtX . gvdlmv0f2h ; lseqequu0d = rtX . g4o2mykdy0
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB . ibguh2azcu , rtB
. ordnmswswg , & rtB . nd45g0hfjt ) ; } pkzoi1pdsa = bv0exnxaiw - rtB .
nd45g0hfjt . ortedkvoqi ; lunmotda0s ( lseqequu0d , pkzoi1pdsa , & rtB .
fozmp525vk ) ; c3hsf3zf4q ( pkzoi1pdsa , & rtB . e11zyd4z32 ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . g3orff0vvz [ 0 ] = rtB . ajq0qn0k3g [
0 ] - rtB . kakeuy45nl [ 0 ] ; rtB . g3orff0vvz [ 1 ] = rtB . ajq0qn0k3g [ 1
] - rtB . kakeuy45nl [ 1 ] ; } ifmmcug2wn ( rtB . g3orff0vvz , rtB .
fozmp525vk . mxe5eu4hb4 , ocfqrkadip , & rtB . bbzxnckkdp ) ; onqykep2vg (
ocfqrkadip , rtB . nd45g0hfjt . ortedkvoqi , aoe4zh2mj2 , & rtB . hetjmev4n0
) ; bv0exnxaiw = rtP . Gain_Gain_ijdkxsl31m * rtX . ms3jvyzwa2 ; lpn0hnh5du =
rtX . hftm5kpfrm ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { l1ggp544gs ( rtB .
leex1vr2mc , rtB . ordnmswswg , & rtB . bznnvznea4 ) ; } o0qnvkc3xx =
bv0exnxaiw - rtB . bznnvznea4 . ortedkvoqi ; lunmotda0s ( lpn0hnh5du ,
o0qnvkc3xx , & rtB . i3j3yx4m45 ) ; c3hsf3zf4q ( o0qnvkc3xx , & rtB .
i2czmwyezh ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . da52lxzfo3 [ 0 ]
= rtB . ajq0qn0k3g [ 0 ] - rtB . ixqvkyn0bs [ 0 ] ; rtB . da52lxzfo3 [ 1 ] =
rtB . ajq0qn0k3g [ 1 ] - rtB . ixqvkyn0bs [ 1 ] ; } ifmmcug2wn ( rtB .
da52lxzfo3 , rtB . i3j3yx4m45 . mxe5eu4hb4 , ncs31u0ld2 , & rtB . lfwezxmueh
) ; onqykep2vg ( ncs31u0ld2 , rtB . bznnvznea4 . ortedkvoqi , lrzsifyq0e , &
rtB . ofj3udt4tn ) ; bv0exnxaiw = rtP . Gain_Gain_injbjuibga * rtX .
a0vktynhmg ; ha3stdwxjl = rtX . ok1bkcbj54 ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { l1ggp544gs ( rtB . cdzixgvais , rtB . ordnmswswg , & rtB . b5wgwyu43w )
; } bdonqro1qr = bv0exnxaiw - rtB . b5wgwyu43w . ortedkvoqi ; lunmotda0s (
ha3stdwxjl , bdonqro1qr , & rtB . lm3v4bjggl ) ; c3hsf3zf4q ( bdonqro1qr , &
rtB . eocfzlmdyi ) ; onqykep2vg ( nzppf3gsca , rtB . b5wgwyu43w . ortedkvoqi
, nbzg4ig4di , & rtB . jrmqablme2 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . f1botvjvoe [ 0 ] = rtB . ajq0qn0k3g [ 0 ] - rtB . bqxn34m0qr [ 0 ] ;
rtB . f1botvjvoe [ 1 ] = rtB . ajq0qn0k3g [ 1 ] - rtB . bqxn34m0qr [ 1 ] ; }
ifmmcug2wn ( rtB . f1botvjvoe , rtB . lm3v4bjggl . mxe5eu4hb4 , nzppf3gsca ,
& rtB . hnz1gucse0 ) ; bn5e2i2ijs ( bcehnxyd3h , & rtB . jwd1fkztpc ) ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . cku5zcj5in . LoggedData , & locTime , & rtB .
jwd1fkztpc . jemkrzqk3c [ 0 ] ) ; } } } } bn5e2i2ijs ( myowtlscss , & rtB .
bvxcorhvnz ) ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . cdsdbyqqzu . LoggedData , & locTime , & rtB .
bvxcorhvnz . jemkrzqk3c [ 0 ] ) ; } } } } bn5e2i2ijs ( mk2kwho04h , & rtB .
evh0wbev03 ) ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . j5tckppox0 . LoggedData , & locTime , & rtB .
evh0wbev03 . jemkrzqk3c [ 0 ] ) ; } } } } bn5e2i2ijs ( ft1p4me3if , & rtB .
a5jargzydm ) ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . eywuoilqki . LoggedData , & locTime , & rtB .
a5jargzydm . jemkrzqk3c [ 0 ] ) ; } } } } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { bn5e2i2ijs ( kderxbgjob , & rtB . gxozu2rlri ) ; { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . pmas04mzh3 .
LoggedData , & locTime , & rtB . gxozu2rlri . jemkrzqk3c [ 0 ] ) ; } } } }
bn5e2i2ijs ( ibg3dwhse0 , & rtB . pr4fonk2dq ) ; { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . lhbec2ip5d .
LoggedData , & locTime , & rtB . pr4fonk2dq . jemkrzqk3c [ 0 ] ) ; } } } }
bn5e2i2ijs ( fnkf1abqw5 , & rtB . f4fb5d4j31 ) ; { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . nyqddap2e3 .
LoggedData , & locTime , & rtB . f4fb5d4j31 . jemkrzqk3c [ 0 ] ) ; } } } }
bn5e2i2ijs ( pk1hppghip , & rtB . fheiecna2a ) ; { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . h0qwwidrrt .
LoggedData , & locTime , & rtB . fheiecna2a . jemkrzqk3c [ 0 ] ) ; } } } } }
if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW
. hugbzsrs2a . LoggedData ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
cbz53iqiop [ 0 ] ; up0 [ 1 ] = rtB . cbz53iqiop [ 1 ] ; up0 [ 2 ] = rtB .
cbz53iqiop [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
mi55warbfl . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
jp4yty50ed [ 0 ] ; up0 [ 1 ] = rtB . jp4yty50ed [ 1 ] ; up0 [ 2 ] = rtB .
jp4yty50ed [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
cr4rc4zkjl . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
c5ojbulhcl [ 0 ] ; up0 [ 1 ] = rtB . c5ojbulhcl [ 1 ] ; up0 [ 2 ] = rtB .
c5ojbulhcl [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
lif3zndlrk . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
c2fmjucg5f [ 0 ] ; up0 [ 1 ] = rtB . c2fmjucg5f [ 1 ] ; up0 [ 2 ] = rtB .
c2fmjucg5f [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
dqsdd0iav1 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
mfq4qoe4yi [ 0 ] ; up0 [ 1 ] = rtB . mfq4qoe4yi [ 1 ] ; up0 [ 2 ] = rtB .
mfq4qoe4yi [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
jtrbooxbd3 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
ndqfi1y1ay [ 0 ] ; up0 [ 1 ] = rtB . ndqfi1y1ay [ 1 ] ; up0 [ 2 ] = rtB .
ndqfi1y1ay [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
cjri132aia . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
irxau0vegh [ 0 ] ; up0 [ 1 ] = rtB . irxau0vegh [ 1 ] ; up0 [ 2 ] = rtB .
irxau0vegh [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
lusxtmzcjz . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
iwqydkbfig [ 0 ] ; up0 [ 1 ] = rtB . iwqydkbfig [ 1 ] ; up0 [ 2 ] = rtB .
iwqydkbfig [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
nujtkogswx . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 12 ] ; ( void ) memcpy ( & up0 [
0 ] , & rtB . l1rog3vm3b [ 0 ] , 12 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . o4dhmx5qrq . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 12 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . azahyglgjt [
0 ] , 12 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar
* ) rtDW . jqjkpgnny2 . LoggedData ; LogVar * var = svar -> signals . values
; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar
* ) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 12 ] ; ( void ) memcpy
( & up0 [ 0 ] , & rtB . j2lsirb0ej [ 0 ] , 12 * sizeof ( real_T ) ) ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . dl3c4wd40p .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 12 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. pm1tjuoiq2 [ 0 ] , 12 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar *
) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
bhza4smniz . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
fjnyclhmei [ 0 ] ; up0 [ 1 ] = rtB . fjnyclhmei [ 1 ] ; up0 [ 2 ] = rtB .
fjnyclhmei [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
m5vo5zrdwd . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
i10izinweb [ 0 ] ; up0 [ 1 ] = rtB . i10izinweb [ 1 ] ; up0 [ 2 ] = rtB .
i10izinweb [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
j44z1n4syw . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
ar5mtka5cc [ 0 ] ; up0 [ 1 ] = rtB . ar5mtka5cc [ 1 ] ; up0 [ 2 ] = rtB .
ar5mtka5cc [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
fqe3wzj2rm . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
gorv20ywqu [ 0 ] ; up0 [ 1 ] = rtB . gorv20ywqu [ 1 ] ; up0 [ 2 ] = rtB .
gorv20ywqu [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } }
akyqzm0njl ( l4uoo2mfo4 , & rtB . fq3vfzzwja ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . mweg4p0tza .
LoggedData , & locTime , & rtB . fq3vfzzwja . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( fpbyp3gnlt , & rtB . a4teg0k51j ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . lmqaiznxh2 .
LoggedData , & locTime , & rtB . a4teg0k51j . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( axxzmwrdb1 , & rtB . e1yst2ptdp ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . btfxhaa12b .
LoggedData , & locTime , & rtB . e1yst2ptdp . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( o4hmshkh13 , & rtB . p5pqkurl0x ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . dvgadtng5f .
LoggedData , & locTime , & rtB . p5pqkurl0x . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( asjv0xjmii , & rtB . m4ijqp4odc ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . o1tss2hntz .
LoggedData , & locTime , & rtB . m4ijqp4odc . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( afwyumpfjk , & rtB . hl0u2uhz0x ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . c2pncb15ww .
LoggedData , & locTime , & rtB . hl0u2uhz0x . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( eqhsiqgube , & rtB . k4omfwosju ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gau0w0subc .
LoggedData , & locTime , & rtB . k4omfwosju . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( oz3y0ehsly , & rtB . d52hlymzlr ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gf3gsxu3l0 .
LoggedData , & locTime , & rtB . d52hlymzlr . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( ppmcvosloc , & rtB . kkuccmfrbi ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ml2ga241wu .
LoggedData , & locTime , & rtB . kkuccmfrbi . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( hceboz13qc , & rtB . p4upkbqkhe ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ptdrnn4gkj .
LoggedData , & locTime , & rtB . p4upkbqkhe . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( lwby3kv103 , & rtB . bbqw0bl5gl ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . egvebj0vzk .
LoggedData , & locTime , & rtB . bbqw0bl5gl . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( ewjuw2ilww , & rtB . nuraudbnmw ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . azxrx1pbjx .
LoggedData , & locTime , & rtB . nuraudbnmw . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( i0pfjcbccz , & rtB . hteupnqrx4 ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . kqv43bmmbb .
LoggedData , & locTime , & rtB . hteupnqrx4 . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( hifhopdemn , & rtB . euxu4ep35i ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . pnnupo15gj .
LoggedData , & locTime , & rtB . euxu4ep35i . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( cmxgtuqnwg , & rtB . gw4ba2toit ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . m5pscv5mzf .
LoggedData , & locTime , & rtB . gw4ba2toit . kh05gq2bif [ 0 ] ) ; } } } }
akyqzm0njl ( g3tawas44r , & rtB . nq1hfz3a31 ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . e1dat3np50 .
LoggedData , & locTime , & rtB . nq1hfz3a31 . kh05gq2bif [ 0 ] ) ; } } } } if
( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
jesgoxpysk . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [
0 ] , & rtB . haamgpyyku [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . bxokau5rly . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . nlsv5ptysw [ 0
] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 )
; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar *
) rtDW . ikckvftlj0 . LoggedData ; LogVar * var = svar -> signals . values ;
{ double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar *
) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( &
up0 [ 0 ] , & rtB . kan4kiqahi [ 0 ] , 6 * sizeof ( real_T ) ) ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . kuf1r1iib1 .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. hb01w4hsae [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . dzd50qusdc . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . o2px3pavbt [ 0 ] , 6 *
sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if
( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
hxmfmxbxzg . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [
0 ] , & rtB . e5sbn5ywmn [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . b31ricvahq . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . m2f3uzhfsg .
m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . k5v5nydhl2 . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . l3bbgfkbil . m0i0p0mohd [
0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar
* ) rtDW . aszo4opjoq . LoggedData ; LogVar * var = svar -> signals . values
; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar
* ) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy (
& up0 [ 0 ] , & rtB . e5mxo1itjx . m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) )
; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . gk5p53h1wj .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. nbpckilwbi . m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . lu4iopse32 . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . euig1sdxae .
m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . knsumlziop . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . ng0oekyoml . m0i0p0mohd [
0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar
* ) rtDW . ky1g0helic . LoggedData ; LogVar * var = svar -> signals . values
; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar
* ) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy (
& up0 [ 0 ] , & rtB . bv2yjfnafy . m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) )
; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . fvoj0brkji .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. ejz0pvfgin . m0i0p0mohd [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . dkoo4kcfaj . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . cib1121v1a [ 0
] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 )
; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar *
) rtDW . i5grh4jmh3 . LoggedData ; LogVar * var = svar -> signals . values ;
{ double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar *
) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( &
up0 [ 0 ] , & rtB . fmwnvf0vev [ 0 ] , 6 * sizeof ( real_T ) ) ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . pdkyev51db .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . kcifbusgyp [ 0 ] ;
up0 [ 1 ] = rtB . kcifbusgyp [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0
, 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . i4dnzdgvyj . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . jbsiq0ysnz [ 0 ] ; up0 [ 1 ] = rtB . jbsiq0ysnz
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
jzughaiexw . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
ovp54ku00f [ 0 ] ; up0 [ 1 ] = rtB . ovp54ku00f [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . jeazhlxihn . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . au5wbjjqt3 [ 0 ] ; up0 [ 1 ] = rtB . au5wbjjqt3
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
fhvzke4cet . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
jiz3a002c3 [ 0 ] ; up0 [ 1 ] = rtB . jiz3a002c3 [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . j50ebbuydy . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . peasbjr2ah [ 0 ] ; up0 [ 1 ] = rtB . peasbjr2ah
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . mxwnv4z2lq . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . kthfd0aif2 [ 0 ] ; up0 [ 1 ] = rtB .
kthfd0aif2 [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
g15tyxojey . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
n1skxybgba [ 0 ] ; up0 [ 1 ] = rtB . n1skxybgba [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . f4mz54thlc . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . obobcozbfh [ 0 ] ; up0 [ 1 ] = rtB . obobcozbfh
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
oiwwfvr1a5 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
fyll5jdjjj [ 0 ] ; up0 [ 1 ] = rtB . fyll5jdjjj [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . lh0nbilqnw . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . ibguh2azcu [ 0 ] ; up0 [ 1 ] = rtB . ibguh2azcu
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
fj5wqp1pom . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
leex1vr2mc [ 0 ] ; up0 [ 1 ] = rtB . leex1vr2mc [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . onngtoccwk . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . cdzixgvais [ 0 ] ; up0 [ 1 ] = rtB . cdzixgvais
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
ozyfkr2biz . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
gr0jp0xo2u [ 0 ] ; up0 [ 1 ] = rtB . gr0jp0xo2u [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
bzo2lxtcos . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
ordnmswswg [ 0 ] ; up0 [ 1 ] = rtB . ordnmswswg [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } } if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . gjzrj5vwzi . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . guii4af3w0 [ 0 ] ; up0 [ 1 ] = rtB .
guii4af3w0 [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
o54vw4q3ry . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
nr2xhydys1 [ 0 ] ; up0 [ 1 ] = rtB . nr2xhydys1 [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . esfmkot2gm . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . a03f1j3hsr [ 0 ] ; up0 [ 1 ] = rtB . a03f1j3hsr
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
fwolkb0vlk . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
ma4hr1zg5h [ 0 ] ; up0 [ 1 ] = rtB . ma4hr1zg5h [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
orxq3kojbg . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
cq2ac25vvr [ 0 ] ; up0 [ 1 ] = rtB . cq2ac25vvr [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . ovq0d1ceac . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . f3swi4wykw [ 0 ] ; up0 [ 1 ] = rtB . f3swi4wykw
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
fup4sk0rmj . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
kjfk5s4txt [ 0 ] ; up0 [ 1 ] = rtB . kjfk5s4txt [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . g5difolfpk . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . mka13uwfw0 [ 0 ] ; up0 [ 1 ] = rtB . mka13uwfw0
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
j1krmqotmd . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
fsylupg2ie ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
mpaolyryto . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
p123e5cq2h [ 0 ] ; up0 [ 1 ] = rtB . p123e5cq2h [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . kabuwjql3m . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . lipbvqqq2c [ 0 ] ; up0 [ 1 ] = rtB . lipbvqqq2c
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . fng5gfijxe . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . hhq2gz3sy3 [ 0 ] ; up0 [ 1 ] = rtB .
hhq2gz3sy3 [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
az4riutx0n . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
ll2wsps0hn ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
pw42vsjs5z . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
myenxxvcic [ 0 ] ; up0 [ 1 ] = rtB . myenxxvcic [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . ieqghgs4hk . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . p32mbcnx3i [ 0 ] ; up0 [ 1 ] = rtB . p32mbcnx3i
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
cd4funmbby . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
lvotrv1jjx [ 0 ] ; up0 [ 1 ] = rtB . lvotrv1jjx [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
ahjraffioz . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
e4bknlrhvn [ 0 ] ; up0 [ 1 ] = rtB . e4bknlrhvn [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
cvspglvkum . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
okfse5qvqh ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
cwywqcfbrn . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
ewwxrohews [ 0 ] ; up0 [ 1 ] = rtB . ewwxrohews [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
kjacqpc401 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
fzvqljdzf0 ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
pa44p12zb2 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
ika3sw4mwy [ 0 ] ; up0 [ 1 ] = rtB . ika3sw4mwy [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . pywvylisvs . LoggedData [ 0 ] ; LogVar *
var = svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 )
; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } {
real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . c0vcvn0r0g ; rt_UpdateLogVar ( ( LogVar
* ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ; up1 [ 0 ] =
rtB . mwkffby2ul ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 ) ; var = var
-> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . i3h3tvdsd4 ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . itaaab0kng .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . c0vcvn0r0g ; up0 [ 1
] = rtB . mwkffby2ul ; up0 [ 2 ] = rtB . i3h3tvdsd4 ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } eejedaxwca ( bgjulh42sn , & rtB . odmwzwbx3r
) ; eejedaxwca ( d4m4v5phyn , & rtB . edifya2tdy ) ; { real_T * * uBuffer = (
real_T * * ) & rtDW . aoi2q222df . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & rtDW . aoi2q222df . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay2_Delay_ecl5sy0jio ; mbhupmv1uh = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . jkuwdaephj .
CircularBufSize , & rtDW . jkuwdaephj . Last , rtDW . jkuwdaephj . Tail ,
rtDW . jkuwdaephj . Head , rtP . TransportDelay2_InitOutput_hl0tfnim04 , 1 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } if ( 0.0 > rtP . Switch_Threshold_ireer3ad0m ) {
rtB . dzrglp0ucc = mbhupmv1uh ; } else { rtB . dzrglp0ucc = rtB . a0erqdse13
; } { real_T * pDataValues = ( real_T * ) rtDW . p0dm4cko3k . DataPtr ;
real_T * pTimeValues = ( real_T * ) rtDW . p0dm4cko3k . TimePtr ; int_T
currTimeIndex = rtDW . i42enhfwq5 . PrevIndex ; real_T t = ssGetTaskTime (
rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo *
) rtDW . p0dm4cko3k . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
i42enhfwq5 . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { rtB . ctbtcnregv = pDataValues [ currTimeIndex ] ; }
else { rtB . ctbtcnregv = pDataValues [ currTimeIndex + 1 ] ; } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; int_T * zcTimeIndices = & rtDW
. fm531h0dfy [ 0 ] ; int_T * zcTimeIndicesIdx = & rtDW . ary12ruqzb ; int_T
zcIdx = zcTimeIndices [ * zcTimeIndicesIdx ] ; int_T numZcTimes = 2 ; if ( *
zcTimeIndicesIdx < numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t >
pTimeValues [ zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) &&
( t > pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx =
zcTimeIndices [ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [
zcIdx ] && ( ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 =
pTimeValues [ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; }
else { t1 = pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 -
t ) / ( t2 - t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2
= pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } rtB .
ctbtcnregv = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } { real_T * pDataValues = ( real_T * ) rtDW . puereonu00 .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . puereonu00 . TimePtr ;
int_T currTimeIndex = rtDW . hjvjlcfeww . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . puereonu00 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . hjvjlcfeww . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { gpsgjm1xmt =
pDataValues [ currTimeIndex ] ; } else { gpsgjm1xmt = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; gpsgjm1xmt = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . cqxgiryrfh = rtP .
Gain_Gain_kzy0ayrwxy * gpsgjm1xmt ; { real_T * pDataValues = ( real_T * )
rtDW . iwwdwmgwmf . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
iwwdwmgwmf . TimePtr ; int_T currTimeIndex = rtDW . l1lz31mbjt . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . iwwdwmgwmf . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . l1lz31mbjt . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { miumiqeamo =
pDataValues [ currTimeIndex ] ; } else { miumiqeamo = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; miumiqeamo = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . l1umxbg5f0 = rtP . Gain1_Gain *
miumiqeamo ; { real_T * pDataValues = ( real_T * ) rtDW . drrrzdfjw3 .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . drrrzdfjw3 . TimePtr ;
int_T currTimeIndex = rtDW . bawkp25aax . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . drrrzdfjw3 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . bawkp25aax . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { ixtkvycozy =
pDataValues [ currTimeIndex ] ; } else { ixtkvycozy = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ixtkvycozy = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . g3ehhuuywp = ssGetT ( rtS ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . jkpae01oin = ( rtB . g3ehhuuywp > rtP .
Switch_Threshold_bpzjw1hzqd ) ; } if ( rtDW . jkpae01oin ) { rtB . ngglndshnd
= rtP . Gain2_Gain * ixtkvycozy ; rtB . nl3ka3mlrr = rtB . ngglndshnd ; }
else { rtB . nl3ka3mlrr = rtP . DesiredPosition4_Value_idpjit2rxr ; } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
mjdday0cuw . LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
cqxgiryrfh ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var ->
next ; } { real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . l1umxbg5f0 ; rt_UpdateLogVar
( ( LogVar * ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ;
up2 [ 0 ] = rtB . nl3ka3mlrr ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 )
; } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { rtB .
i3h3tvdsd4 = rtP . Constant5_Value ; rtB . a0erqdse13 = rtP .
Gain2_Gain_ibspipwmaz * 0.0 ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { int32_T i ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( &
rtDW . ljf3bzpuxv [ 0 ] , & rtB . gi0uwyfhqp . ikd1vheez0 [ 0 ] , 12U *
sizeof ( real_T ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
ir3tccey2d . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. ir3tccey2d . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
kxnrq3j5gh . Head = ( ( rtDW . kxnrq3j5gh . Head < ( rtDW . kxnrq3j5gh .
CircularBufSize - 1 ) ) ? ( rtDW . kxnrq3j5gh . Head + 1 ) : 0 ) ; if ( rtDW
. kxnrq3j5gh . Head == rtDW . kxnrq3j5gh . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . kxnrq3j5gh . CircularBufSize , & rtDW
. kxnrq3j5gh . Tail , & rtDW . kxnrq3j5gh . Head , & rtDW . kxnrq3j5gh . Last
, simTime - rtP . TransportDelay1_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . kxnrq3j5gh . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . kxnrq3j5gh . Head ] = simTime ; ( * uBuffer ) [ rtDW .
kxnrq3j5gh . Head ] = rtB . elri1t014b . hia3u3mq0v [ 0 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . mahzin5xie . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . mahzin5xie . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . f4c4a4mj3p . Head = ( ( rtDW . f4c4a4mj3p .
Head < ( rtDW . f4c4a4mj3p . CircularBufSize - 1 ) ) ? ( rtDW . f4c4a4mj3p .
Head + 1 ) : 0 ) ; if ( rtDW . f4c4a4mj3p . Head == rtDW . f4c4a4mj3p . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . f4c4a4mj3p .
CircularBufSize , & rtDW . f4c4a4mj3p . Tail , & rtDW . f4c4a4mj3p . Head , &
rtDW . f4c4a4mj3p . Last , simTime - rtP . TransportDelay2_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . f4c4a4mj3p .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ) [ rtDW . f4c4a4mj3p . Head ] = simTime ; ( *
uBuffer ) [ rtDW . f4c4a4mj3p . Head ] = rtB . elri1t014b . hia3u3mq0v [ 1 ]
; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) {
rtDW . g1vhr4ol4w [ i ] = rtB . m2f3uzhfsg . m0i0p0mohd [ i ] ; rtDW .
p5cipt2vk2 [ i ] = rtB . euig1sdxae . m0i0p0mohd [ i ] ; } rtDW . gutf3fahtc
= rtB . hfjw0isrvt . kfb55nbxu2 ; rtDW . l0nq3lmdeg [ 0 ] = rtB . oqwk5hg0e3
. arptmdt05w [ 0 ] ; rtDW . i1hjxzs31f [ 0 ] = rtB . pqggajaphk . fyzqgebnzz
[ 0 ] ; rtDW . gjvtrlsfwe [ 0 ] = rtB . lj1isfudih . arptmdt05w [ 0 ] ; rtDW
. pzvvqboa5v [ 0 ] = rtB . kcdsohu0vj . arptmdt05w [ 0 ] ; rtDW . orrbrxbq10
[ 0 ] = rtB . ktgydrdwot . arptmdt05w [ 0 ] ; rtDW . l0nq3lmdeg [ 1 ] = rtB .
oqwk5hg0e3 . arptmdt05w [ 1 ] ; rtDW . i1hjxzs31f [ 1 ] = rtB . pqggajaphk .
fyzqgebnzz [ 1 ] ; rtDW . gjvtrlsfwe [ 1 ] = rtB . lj1isfudih . arptmdt05w [
1 ] ; rtDW . pzvvqboa5v [ 1 ] = rtB . kcdsohu0vj . arptmdt05w [ 1 ] ; rtDW .
orrbrxbq10 [ 1 ] = rtB . ktgydrdwot . arptmdt05w [ 1 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . em4ieblqdo . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . em4ieblqdo . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . hflmn5zw4g . Head = ( ( rtDW . hflmn5zw4g .
Head < ( rtDW . hflmn5zw4g . CircularBufSize - 1 ) ) ? ( rtDW . hflmn5zw4g .
Head + 1 ) : 0 ) ; if ( rtDW . hflmn5zw4g . Head == rtDW . hflmn5zw4g . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hflmn5zw4g .
CircularBufSize , & rtDW . hflmn5zw4g . Tail , & rtDW . hflmn5zw4g . Head , &
rtDW . hflmn5zw4g . Last , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hflmn5zw4g .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ) [ rtDW . hflmn5zw4g . Head ] = simTime ; ( *
uBuffer ) [ rtDW . hflmn5zw4g . Head ] = rtB . dzrglp0ucc ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . cp2wd3yek3 . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . cp2wd3yek3 . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . ogn0tnbje1 . Head = ( ( rtDW . ogn0tnbje1 .
Head < ( rtDW . ogn0tnbje1 . CircularBufSize - 1 ) ) ? ( rtDW . ogn0tnbje1 .
Head + 1 ) : 0 ) ; if ( rtDW . ogn0tnbje1 . Head == rtDW . ogn0tnbje1 . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ogn0tnbje1 .
CircularBufSize , & rtDW . ogn0tnbje1 . Tail , & rtDW . ogn0tnbje1 . Head , &
rtDW . ogn0tnbje1 . Last , simTime - rtP . TransportDelay1_Delay_bf3u4wh1iu ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ogn0tnbje1
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
ogn0tnbje1 . Head ] = simTime ; ( * uBuffer ) [ rtDW . ogn0tnbje1 . Head ] =
0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . ldao3hyxar [ 0 ] = rtB
. hfjw0isrvt . atfess0a2f [ 0 ] ; rtDW . o4urslscxv [ 0 ] = rtB . hfjw0isrvt
. k5iezadngg [ 0 ] ; rtDW . biuieiqmxp [ 0 ] = rtB . eolycnedw1 . fyzqgebnzz
[ 0 ] ; rtDW . kxmjiaeunc [ 0 ] = rtB . jwtc4eqcdp . fyzqgebnzz [ 0 ] ; rtDW
. gq1mgiuwz2 [ 0 ] = rtB . jh4bhzwp5a . fyzqgebnzz [ 0 ] ; rtDW . ldao3hyxar
[ 1 ] = rtB . hfjw0isrvt . atfess0a2f [ 1 ] ; rtDW . o4urslscxv [ 1 ] = rtB .
hfjw0isrvt . k5iezadngg [ 1 ] ; rtDW . biuieiqmxp [ 1 ] = rtB . eolycnedw1 .
fyzqgebnzz [ 1 ] ; rtDW . kxmjiaeunc [ 1 ] = rtB . jwtc4eqcdp . fyzqgebnzz [
1 ] ; rtDW . gq1mgiuwz2 [ 1 ] = rtB . jh4bhzwp5a . fyzqgebnzz [ 1 ] ; memcpy
( & rtDW . lwlz3gfxgb [ 0 ] , & rtB . nrezxvhxow . n4wcvzk1ua [ 0 ] , 15U *
sizeof ( real_T ) ) ; memcpy ( & rtDW . ekvleb1gcq [ 0 ] , & rtB . onfv1wmnyg
. n4wcvzk1ua [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( & rtDW . k3kw4exkgg
[ 0 ] , & rtB . a51pswiot5 . n4wcvzk1ua [ 0 ] , 15U * sizeof ( real_T ) ) ;
memcpy ( & rtDW . cr0y2nzbkc [ 0 ] , & rtB . cynnr55l50 . n4wcvzk1ua [ 0 ] ,
15U * sizeof ( real_T ) ) ; rtDW . eftcuoxcfp [ 0 ] = rtB . ashx3cqs2u [ 0 ]
; rtDW . bdxxdlvg4e [ 0 ] = rtB . l1wjcn1r3q [ 0 ] ; rtDW . l34b1ws24z [ 0 ]
= rtB . cbvb41g3bt [ 0 ] ; rtDW . lbl43aynsc [ 0 ] = rtB . gsrbrbeiwt [ 0 ] ;
rtDW . eftcuoxcfp [ 1 ] = rtB . ashx3cqs2u [ 1 ] ; rtDW . bdxxdlvg4e [ 1 ] =
rtB . l1wjcn1r3q [ 1 ] ; rtDW . l34b1ws24z [ 1 ] = rtB . cbvb41g3bt [ 1 ] ;
rtDW . lbl43aynsc [ 1 ] = rtB . gsrbrbeiwt [ 1 ] ; rtDW . eftcuoxcfp [ 2 ] =
rtB . ashx3cqs2u [ 2 ] ; rtDW . bdxxdlvg4e [ 2 ] = rtB . l1wjcn1r3q [ 2 ] ;
rtDW . l34b1ws24z [ 2 ] = rtB . cbvb41g3bt [ 2 ] ; rtDW . lbl43aynsc [ 2 ] =
rtB . gsrbrbeiwt [ 2 ] ; rtDW . euwquc1ohh [ 0 ] = rtB . hfjw0isrvt .
jrp1fodqyr [ 0 ] ; rtDW . kb1zmmywdq [ 0 ] = rtB . cz230wcizx . k5iezadngg [
0 ] ; rtDW . nsyupx5qza [ 0 ] = rtB . cz230wcizx . jrp1fodqyr [ 0 ] ; rtDW .
mfzuy1fnjf [ 0 ] = rtB . ntpm2p40uf . k5iezadngg [ 0 ] ; rtDW . meq4arbagn [
0 ] = rtB . ntpm2p40uf . jrp1fodqyr [ 0 ] ; rtDW . elhi3coyqa [ 0 ] = rtB .
kb4nwcrwes . k5iezadngg [ 0 ] ; rtDW . cb4caomchi [ 0 ] = rtB . kb4nwcrwes .
jrp1fodqyr [ 0 ] ; rtDW . euwquc1ohh [ 1 ] = rtB . hfjw0isrvt . jrp1fodqyr [
1 ] ; rtDW . kb1zmmywdq [ 1 ] = rtB . cz230wcizx . k5iezadngg [ 1 ] ; rtDW .
nsyupx5qza [ 1 ] = rtB . cz230wcizx . jrp1fodqyr [ 1 ] ; rtDW . mfzuy1fnjf [
1 ] = rtB . ntpm2p40uf . k5iezadngg [ 1 ] ; rtDW . meq4arbagn [ 1 ] = rtB .
ntpm2p40uf . jrp1fodqyr [ 1 ] ; rtDW . elhi3coyqa [ 1 ] = rtB . kb4nwcrwes .
k5iezadngg [ 1 ] ; rtDW . cb4caomchi [ 1 ] = rtB . kb4nwcrwes . jrp1fodqyr [
1 ] ; memcpy ( & rtDW . njybh3xjqw [ 0 ] , & rtB . htnejvn3py . ikd1vheez0 [
0 ] , 12U * sizeof ( real_T ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . nuyw1oa5lu . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& rtDW . nuyw1oa5lu . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
rtDW . lyazy3gnn2 . Head = ( ( rtDW . lyazy3gnn2 . Head < ( rtDW . lyazy3gnn2
. CircularBufSize - 1 ) ) ? ( rtDW . lyazy3gnn2 . Head + 1 ) : 0 ) ; if (
rtDW . lyazy3gnn2 . Head == rtDW . lyazy3gnn2 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . lyazy3gnn2 . CircularBufSize , & rtDW
. lyazy3gnn2 . Tail , & rtDW . lyazy3gnn2 . Head , & rtDW . lyazy3gnn2 . Last
, simTime - rtP . TransportDelay1_Delay_ksw2xmlzvn , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . lyazy3gnn2 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . lyazy3gnn2 . Head ] = simTime ; ( * uBuffer ) [ rtDW .
lyazy3gnn2 . Head ] = rtB . gt3vc04dxa . hia3u3mq0v [ 0 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . ongfcz4dhf . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . ongfcz4dhf . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . je3z34ckbn . Head = ( ( rtDW . je3z34ckbn .
Head < ( rtDW . je3z34ckbn . CircularBufSize - 1 ) ) ? ( rtDW . je3z34ckbn .
Head + 1 ) : 0 ) ; if ( rtDW . je3z34ckbn . Head == rtDW . je3z34ckbn . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . je3z34ckbn .
CircularBufSize , & rtDW . je3z34ckbn . Tail , & rtDW . je3z34ckbn . Head , &
rtDW . je3z34ckbn . Last , simTime - rtP . TransportDelay2_Delay_muwonazjkp ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . je3z34ckbn
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
je3z34ckbn . Head ] = simTime ; ( * uBuffer ) [ rtDW . je3z34ckbn . Head ] =
rtB . gt3vc04dxa . hia3u3mq0v [ 1 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ for ( i = 0 ; i < 6 ; i ++ ) { rtDW . hdkreqmds2 [ i ] = rtB . l3bbgfkbil .
m0i0p0mohd [ i ] ; rtDW . k5rawm0exp [ i ] = rtB . ng0oekyoml . m0i0p0mohd [
i ] ; } rtDW . eb005l0rcc = rtB . cz230wcizx . kfb55nbxu2 ; rtDW . jhqxxzie31
[ 0 ] = rtB . cz230wcizx . atfess0a2f [ 0 ] ; rtDW . jhqxxzie31 [ 1 ] = rtB .
cz230wcizx . atfess0a2f [ 1 ] ; memcpy ( & rtDW . oywwglvnbw [ 0 ] , & rtB .
de51ggtvmf . ikd1vheez0 [ 0 ] , 12U * sizeof ( real_T ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . jzm2uqh05o . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . jzm2uqh05o . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . fyo23snxav . Head = ( ( rtDW . fyo23snxav .
Head < ( rtDW . fyo23snxav . CircularBufSize - 1 ) ) ? ( rtDW . fyo23snxav .
Head + 1 ) : 0 ) ; if ( rtDW . fyo23snxav . Head == rtDW . fyo23snxav . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . fyo23snxav .
CircularBufSize , & rtDW . fyo23snxav . Tail , & rtDW . fyo23snxav . Head , &
rtDW . fyo23snxav . Last , simTime - rtP . TransportDelay1_Delay_ppziigp4pi ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . fyo23snxav
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
fyo23snxav . Head ] = simTime ; ( * uBuffer ) [ rtDW . fyo23snxav . Head ] =
rtB . bhiqn3njpt . hia3u3mq0v [ 0 ] ; } { real_T * * uBuffer = ( real_T * * )
& rtDW . kim1kgtcyq . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & rtDW . kim1kgtcyq . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS )
; rtDW . b4ivhh52o2 . Head = ( ( rtDW . b4ivhh52o2 . Head < ( rtDW .
b4ivhh52o2 . CircularBufSize - 1 ) ) ? ( rtDW . b4ivhh52o2 . Head + 1 ) : 0 )
; if ( rtDW . b4ivhh52o2 . Head == rtDW . b4ivhh52o2 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . b4ivhh52o2 . CircularBufSize , & rtDW
. b4ivhh52o2 . Tail , & rtDW . b4ivhh52o2 . Head , & rtDW . b4ivhh52o2 . Last
, simTime - rtP . TransportDelay2_Delay_pcfeeikpk2 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . b4ivhh52o2 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . b4ivhh52o2 . Head ] = simTime ; ( * uBuffer ) [ rtDW .
b4ivhh52o2 . Head ] = rtB . bhiqn3njpt . hia3u3mq0v [ 1 ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW .
ekk5eebzqc [ i ] = rtB . e5mxo1itjx . m0i0p0mohd [ i ] ; rtDW . mec2hevem0 [
i ] = rtB . bv2yjfnafy . m0i0p0mohd [ i ] ; } rtDW . gx01drbeka = rtB .
ntpm2p40uf . kfb55nbxu2 ; rtDW . c1300gzrjt [ 0 ] = rtB . ntpm2p40uf .
atfess0a2f [ 0 ] ; rtDW . c1300gzrjt [ 1 ] = rtB . ntpm2p40uf . atfess0a2f [
1 ] ; memcpy ( & rtDW . kbb0qw5mp3 [ 0 ] , & rtB . krha0qyekz . ikd1vheez0 [
0 ] , 12U * sizeof ( real_T ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . e0iyas1xpb . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& rtDW . e0iyas1xpb . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
rtDW . j5kjeh2fcr . Head = ( ( rtDW . j5kjeh2fcr . Head < ( rtDW . j5kjeh2fcr
. CircularBufSize - 1 ) ) ? ( rtDW . j5kjeh2fcr . Head + 1 ) : 0 ) ; if (
rtDW . j5kjeh2fcr . Head == rtDW . j5kjeh2fcr . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . j5kjeh2fcr . CircularBufSize , & rtDW
. j5kjeh2fcr . Tail , & rtDW . j5kjeh2fcr . Head , & rtDW . j5kjeh2fcr . Last
, simTime - rtP . TransportDelay1_Delay_kvdadosi3i , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . j5kjeh2fcr . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . j5kjeh2fcr . Head ] = simTime ; ( * uBuffer ) [ rtDW .
j5kjeh2fcr . Head ] = rtB . bsfibrztcn . hia3u3mq0v [ 0 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . gcbrh04vlv . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . gcbrh04vlv . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . fckn41cqic . Head = ( ( rtDW . fckn41cqic .
Head < ( rtDW . fckn41cqic . CircularBufSize - 1 ) ) ? ( rtDW . fckn41cqic .
Head + 1 ) : 0 ) ; if ( rtDW . fckn41cqic . Head == rtDW . fckn41cqic . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . fckn41cqic .
CircularBufSize , & rtDW . fckn41cqic . Tail , & rtDW . fckn41cqic . Head , &
rtDW . fckn41cqic . Last , simTime - rtP . TransportDelay2_Delay_odn4ujxefs ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . fckn41cqic
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
fckn41cqic . Head ] = simTime ; ( * uBuffer ) [ rtDW . fckn41cqic . Head ] =
rtB . bsfibrztcn . hia3u3mq0v [ 1 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ppddj1qhga [ i ] = rtB . nbpckilwbi .
m0i0p0mohd [ i ] ; rtDW . igxhj4adkf [ i ] = rtB . ejz0pvfgin . m0i0p0mohd [
i ] ; } rtDW . kiivcdig1l = rtB . kb4nwcrwes . kfb55nbxu2 ; rtDW . jpwsqsteoo
[ 0 ] = rtB . kb4nwcrwes . atfess0a2f [ 0 ] ; rtDW . jpwsqsteoo [ 1 ] = rtB .
kb4nwcrwes . atfess0a2f [ 1 ] ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . aoi2q222df . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& rtDW . aoi2q222df . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
rtDW . jkuwdaephj . Head = ( ( rtDW . jkuwdaephj . Head < ( rtDW . jkuwdaephj
. CircularBufSize - 1 ) ) ? ( rtDW . jkuwdaephj . Head + 1 ) : 0 ) ; if (
rtDW . jkuwdaephj . Head == rtDW . jkuwdaephj . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . jkuwdaephj . CircularBufSize , & rtDW
. jkuwdaephj . Tail , & rtDW . jkuwdaephj . Head , & rtDW . jkuwdaephj . Last
, simTime - rtP . TransportDelay2_Delay_ecl5sy0jio , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . jkuwdaephj . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . jkuwdaephj . Head ] = simTime ; ( * uBuffer ) [ rtDW .
jkuwdaephj . Head ] = 0.0 ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
int32_T i ; XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; for (
i = 0 ; i < 6 ; i ++ ) { _rtXdot -> ionyxldtcw [ i ] = rtB . dtk02osx1k .
admi3yqyf0 [ i ] ; } _rtXdot -> jls05hpmo2 [ 0 ] = rtB . ll4nivtt3m [ 0 ] ;
_rtXdot -> jls05hpmo2 [ 1 ] = rtB . ll4nivtt3m [ 1 ] ; _rtXdot -> jls05hpmo2
[ 2 ] = rtB . ll4nivtt3m [ 2 ] ; memcpy ( & _rtXdot -> mf3bhm1i2g [ 0 ] , &
rtB . nrezxvhxow . jtrbmpg3lt [ 0 ] , 15U * sizeof ( real_T ) ) ; for ( i = 0
; i < 6 ; i ++ ) { _rtXdot -> jhjq50hamr [ i ] = rtB . fbwflwjjvm .
abjrrhoh5i [ i ] ; _rtXdot -> luz4nck343 [ i ] = rtB . nfjyzad3my .
hg1x1nd45k [ i ] ; } memcpy ( & _rtXdot -> fwt4soxxlc [ 0 ] , & rtB .
ikvvizl300 . of10phaqxi [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> lmukmnay3o [ 0 ] , & rtB . otvyyn5pvr . ltfzlzvs0c [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> oblwbzt05m [
i ] = rtB . jisefsiylr . jhz4hydf42 [ i ] ; _rtXdot -> mgsh4lifu4 [ i ] = rtB
. bydx3i5iwd . jl4fbhrop1 [ i ] ; _rtXdot -> g4ve5h5vh2 [ i ] = rtB .
kuuq0qawad . abjrrhoh5i [ i ] ; _rtXdot -> mc4ye23acv [ i ] = rtB .
eetjt415xo . l5c2p5rmcp [ i ] ; } memcpy ( & _rtXdot -> pusmj51k2o [ 0 ] , &
rtB . eu03stat4s . of10phaqxi [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> oh4v0qnmbl [ 0 ] , & rtB . b4e1ilqhrp . ltfzlzvs0c [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> i0ozzqeoz4 [
i ] = rtB . nqkvnie0as . jhz4hydf42 [ i ] ; } _rtXdot -> gttal13ne4 = rtB .
kaxep214he . g2eupjim4n ; _rtXdot -> lhg5uf35jg = rtB . ngb4hyklf3 .
mxe5eu4hb4 ; _rtXdot -> jyxqpcbioa [ 0 ] = rtB . oqwk5hg0e3 . d1dlzas2mm [ 0
] ; _rtXdot -> f5podaplbs [ 0 ] = rtB . pqggajaphk . ntmpjrn1e1 [ 0 ] ;
_rtXdot -> jyxqpcbioa [ 1 ] = rtB . oqwk5hg0e3 . d1dlzas2mm [ 1 ] ; _rtXdot
-> f5podaplbs [ 1 ] = rtB . pqggajaphk . ntmpjrn1e1 [ 1 ] ; memcpy ( &
_rtXdot -> armybl4b3j [ 0 ] , & rtB . hfjw0isrvt . hpfjqszf4x [ 0 ] , 12U *
sizeof ( real_T ) ) ; _rtXdot -> omoyscdlkq [ 0 ] = rtB . lj1isfudih .
d1dlzas2mm [ 0 ] ; _rtXdot -> bvv2j1fvkj [ 0 ] = rtB . kcdsohu0vj .
d1dlzas2mm [ 0 ] ; _rtXdot -> jyfm4clkt1 [ 0 ] = rtB . ktgydrdwot .
d1dlzas2mm [ 0 ] ; _rtXdot -> an1dy1scdv [ 0 ] = rtB . nj24ds003u .
go4wiq4kbo [ 0 ] ; _rtXdot -> ajilevaypm [ 0 ] = rtB . nj0q0pfqt4 .
go4wiq4kbo [ 0 ] ; _rtXdot -> ndnjgxlg32 [ 0 ] = rtB . pogoxyyi05 .
go4wiq4kbo [ 0 ] ; _rtXdot -> mampjjggm5 [ 0 ] = rtB . ezrv5s44v4 .
go4wiq4kbo [ 0 ] ; _rtXdot -> c1zyhspvvj [ 0 ] = rtB . eolycnedw1 .
ntmpjrn1e1 [ 0 ] ; _rtXdot -> bozttf3lme [ 0 ] = rtB . jwtc4eqcdp .
ntmpjrn1e1 [ 0 ] ; _rtXdot -> lu2z2r1bq1 [ 0 ] = rtB . jh4bhzwp5a .
ntmpjrn1e1 [ 0 ] ; _rtXdot -> au25a2kq45 [ 0 ] = rtB . odmwzwbx3r .
eup5e2ipsb [ 0 ] ; _rtXdot -> n1g43fm50u [ 0 ] = rtB . olxq5nidun .
g2qarspkxz [ 0 ] ; _rtXdot -> jjhfp4nquz [ 0 ] = rtB . cc0eq1pdzz .
fzjsuutou0 [ 0 ] ; _rtXdot -> j0sputa12i [ 0 ] = rtB . fqy4bphp3r .
fzjsuutou0 [ 0 ] ; _rtXdot -> bpzbkldlw5 [ 0 ] = rtB . hubjvrmjeu .
fzjsuutou0 [ 0 ] ; _rtXdot -> djt2dez0wq [ 0 ] = rtB . k2f1farrzj .
fzjsuutou0 [ 0 ] ; _rtXdot -> omoyscdlkq [ 1 ] = rtB . lj1isfudih .
d1dlzas2mm [ 1 ] ; _rtXdot -> bvv2j1fvkj [ 1 ] = rtB . kcdsohu0vj .
d1dlzas2mm [ 1 ] ; _rtXdot -> jyfm4clkt1 [ 1 ] = rtB . ktgydrdwot .
d1dlzas2mm [ 1 ] ; _rtXdot -> an1dy1scdv [ 1 ] = rtB . nj24ds003u .
go4wiq4kbo [ 1 ] ; _rtXdot -> ajilevaypm [ 1 ] = rtB . nj0q0pfqt4 .
go4wiq4kbo [ 1 ] ; _rtXdot -> ndnjgxlg32 [ 1 ] = rtB . pogoxyyi05 .
go4wiq4kbo [ 1 ] ; _rtXdot -> mampjjggm5 [ 1 ] = rtB . ezrv5s44v4 .
go4wiq4kbo [ 1 ] ; _rtXdot -> c1zyhspvvj [ 1 ] = rtB . eolycnedw1 .
ntmpjrn1e1 [ 1 ] ; _rtXdot -> bozttf3lme [ 1 ] = rtB . jwtc4eqcdp .
ntmpjrn1e1 [ 1 ] ; _rtXdot -> lu2z2r1bq1 [ 1 ] = rtB . jh4bhzwp5a .
ntmpjrn1e1 [ 1 ] ; _rtXdot -> au25a2kq45 [ 1 ] = rtB . odmwzwbx3r .
eup5e2ipsb [ 1 ] ; _rtXdot -> n1g43fm50u [ 1 ] = rtB . olxq5nidun .
g2qarspkxz [ 1 ] ; _rtXdot -> jjhfp4nquz [ 1 ] = rtB . cc0eq1pdzz .
fzjsuutou0 [ 1 ] ; _rtXdot -> j0sputa12i [ 1 ] = rtB . fqy4bphp3r .
fzjsuutou0 [ 1 ] ; _rtXdot -> bpzbkldlw5 [ 1 ] = rtB . hubjvrmjeu .
fzjsuutou0 [ 1 ] ; _rtXdot -> djt2dez0wq [ 1 ] = rtB . k2f1farrzj .
fzjsuutou0 [ 1 ] ; memcpy ( & _rtXdot -> chv5h33ild [ 0 ] , & rtB .
onfv1wmnyg . jtrbmpg3lt [ 0 ] , 15U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> f5c0yrpl0m [ 0 ] , & rtB . a51pswiot5 . jtrbmpg3lt [ 0 ] , 15U *
sizeof ( real_T ) ) ; memcpy ( & _rtXdot -> jee34x0zc4 [ 0 ] , & rtB .
cynnr55l50 . jtrbmpg3lt [ 0 ] , 15U * sizeof ( real_T ) ) ; _rtXdot ->
im051m03c0 [ 0 ] = rtB . gac1ybd3gq [ 0 ] ; _rtXdot -> ossqjsfts4 [ 0 ] = rtB
. awhqz5sjvx [ 0 ] ; _rtXdot -> ivslgspzyl [ 0 ] = rtB . epn3tgotb3 [ 0 ] ;
_rtXdot -> im051m03c0 [ 1 ] = rtB . gac1ybd3gq [ 1 ] ; _rtXdot -> ossqjsfts4
[ 1 ] = rtB . awhqz5sjvx [ 1 ] ; _rtXdot -> ivslgspzyl [ 1 ] = rtB .
epn3tgotb3 [ 1 ] ; _rtXdot -> im051m03c0 [ 2 ] = rtB . gac1ybd3gq [ 2 ] ;
_rtXdot -> ossqjsfts4 [ 2 ] = rtB . awhqz5sjvx [ 2 ] ; _rtXdot -> ivslgspzyl
[ 2 ] = rtB . epn3tgotb3 [ 2 ] ; _rtXdot -> hiamj1oevs = rtB . by2102zg1w .
mxe5eu4hb4 ; _rtXdot -> gx3o1bpm3a = rtB . dukk21lgx3 . g2eupjim4n ; _rtXdot
-> gtdwc5tdzv [ 0 ] = rtB . edifya2tdy . eup5e2ipsb [ 0 ] ; _rtXdot ->
cg2tzvhg1s [ 0 ] = rtB . oule4qndjw . g2qarspkxz [ 0 ] ; _rtXdot ->
gtdwc5tdzv [ 1 ] = rtB . edifya2tdy . eup5e2ipsb [ 1 ] ; _rtXdot ->
cg2tzvhg1s [ 1 ] = rtB . oule4qndjw . g2qarspkxz [ 1 ] ; _rtXdot ->
joe5wc3vru = rtB . jkmnldsv41 . mxe5eu4hb4 ; _rtXdot -> belilpb3dk = rtB .
hduc3332fp . g2eupjim4n ; _rtXdot -> bxlordfjyp = rtB . peplmogpy4 .
mxe5eu4hb4 ; _rtXdot -> mva2o1cupz = rtB . cyju4j1oji . g2eupjim4n ; _rtXdot
-> lmqns2m2fd = rtB . dqmxq5wims . mxe5eu4hb4 ; _rtXdot -> du3cl5u2br = rtB .
h32zv1canq . g2eupjim4n ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot ->
aqayeibnbf [ i ] = rtB . lycfgsadwf . admi3yqyf0 [ i ] ; _rtXdot ->
mnhjgksiva [ i ] = rtB . dnncszfbjm . abjrrhoh5i [ i ] ; _rtXdot ->
p5euhzgph2 [ i ] = rtB . fuoxbigwkf . hg1x1nd45k [ i ] ; } memcpy ( & _rtXdot
-> nsygkjz001 [ 0 ] , & rtB . e3k2wvkram . of10phaqxi [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> pyssp52j4v [ 0 ] , & rtB . fgdsj1go3f .
ltfzlzvs0c [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> fig1xy4s5q [ i ] = rtB . ikazhomoow . jhz4hydf42 [ i ] ; _rtXdot
-> lovsimzfsp [ i ] = rtB . ghgs23hmyk . jl4fbhrop1 [ i ] ; _rtXdot ->
dvkhmbnof2 [ i ] = rtB . ofq5zlashb . abjrrhoh5i [ i ] ; _rtXdot ->
gqi2mgds2b [ i ] = rtB . e2iscjaunx . l5c2p5rmcp [ i ] ; } memcpy ( & _rtXdot
-> ppo5lvnsbd [ 0 ] , & rtB . dhwkhs2uoc . of10phaqxi [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> aslzbhpikx [ 0 ] , & rtB . cphdqdow2s .
ltfzlzvs0c [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> m20bb5px11 [ i ] = rtB . kn0eokpsnw . jhz4hydf42 [ i ] ; } _rtXdot
-> dmaqihaxaq = rtB . l3bm1rlyki . g2eupjim4n ; _rtXdot -> dsaqs0egeg = rtB .
gsjc2uausd . mxe5eu4hb4 ; memcpy ( & _rtXdot -> hj3xpt5hh3 [ 0 ] , & rtB .
cz230wcizx . hpfjqszf4x [ 0 ] , 12U * sizeof ( real_T ) ) ; _rtXdot ->
fmtqkgzjo2 [ 0 ] = rtB . gnuxcvc0rq . go4wiq4kbo [ 0 ] ; _rtXdot ->
eqlst0fie1 [ 0 ] = rtB . pi5klgxywb . go4wiq4kbo [ 0 ] ; _rtXdot ->
jhyl0nmftj [ 0 ] = rtB . iw5aeqjlmr . go4wiq4kbo [ 0 ] ; _rtXdot ->
dufp23q24f [ 0 ] = rtB . bgqjdgwjco . go4wiq4kbo [ 0 ] ; _rtXdot ->
e5bm4mxp4y [ 0 ] = rtB . mx2c20cuvt . fzjsuutou0 [ 0 ] ; _rtXdot ->
d2zjdsdy3t [ 0 ] = rtB . a0eglqqncr . fzjsuutou0 [ 0 ] ; _rtXdot ->
atdwxldcaa [ 0 ] = rtB . lofsb5hfpk . fzjsuutou0 [ 0 ] ; _rtXdot ->
kdrbhkothr [ 0 ] = rtB . obs2vasvj2 . fzjsuutou0 [ 0 ] ; _rtXdot ->
fmtqkgzjo2 [ 1 ] = rtB . gnuxcvc0rq . go4wiq4kbo [ 1 ] ; _rtXdot ->
eqlst0fie1 [ 1 ] = rtB . pi5klgxywb . go4wiq4kbo [ 1 ] ; _rtXdot ->
jhyl0nmftj [ 1 ] = rtB . iw5aeqjlmr . go4wiq4kbo [ 1 ] ; _rtXdot ->
dufp23q24f [ 1 ] = rtB . bgqjdgwjco . go4wiq4kbo [ 1 ] ; _rtXdot ->
e5bm4mxp4y [ 1 ] = rtB . mx2c20cuvt . fzjsuutou0 [ 1 ] ; _rtXdot ->
d2zjdsdy3t [ 1 ] = rtB . a0eglqqncr . fzjsuutou0 [ 1 ] ; _rtXdot ->
atdwxldcaa [ 1 ] = rtB . lofsb5hfpk . fzjsuutou0 [ 1 ] ; _rtXdot ->
kdrbhkothr [ 1 ] = rtB . obs2vasvj2 . fzjsuutou0 [ 1 ] ; _rtXdot ->
l1nyqmvwst = rtB . obfqahvmjm . mxe5eu4hb4 ; _rtXdot -> ca2tchanai = rtB .
p43v4vgoay . g2eupjim4n ; _rtXdot -> ooketywe0t = rtB . jkdewgbanl .
mxe5eu4hb4 ; _rtXdot -> mjw0keqmwr = rtB . kzcw4mi4zh . g2eupjim4n ; _rtXdot
-> fb0bskoedk = rtB . nimb0vszrh . mxe5eu4hb4 ; _rtXdot -> phfjeo0drc = rtB .
ilz4rw1itf . g2eupjim4n ; _rtXdot -> d0fq4dyqzm = rtB . fvjwsgw14y .
mxe5eu4hb4 ; _rtXdot -> irfwmkoozp = rtB . cg5bnbimqw . g2eupjim4n ; for ( i
= 0 ; i < 6 ; i ++ ) { _rtXdot -> gfix1az2dy [ i ] = rtB . mkh53mukfc .
admi3yqyf0 [ i ] ; _rtXdot -> lajj3kiv0r [ i ] = rtB . a4hw5bc5zg .
abjrrhoh5i [ i ] ; _rtXdot -> musq314bsn [ i ] = rtB . jc521lazxl .
hg1x1nd45k [ i ] ; } memcpy ( & _rtXdot -> oljl1r15sy [ 0 ] , & rtB .
epn4fcspwt . of10phaqxi [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> kdjra2pfq4 [ 0 ] , & rtB . czo35p4wud . ltfzlzvs0c [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> ox0f0pxtqm [
i ] = rtB . pxgpfywurc . jhz4hydf42 [ i ] ; _rtXdot -> eu121u4uj2 [ i ] = rtB
. dshtigbj0k . jl4fbhrop1 [ i ] ; _rtXdot -> bgjp3vzt5z [ i ] = rtB .
plfgevb5mc . abjrrhoh5i [ i ] ; _rtXdot -> dn5twkxizj [ i ] = rtB .
flkl1uejjb . l5c2p5rmcp [ i ] ; } memcpy ( & _rtXdot -> eeiannul5v [ 0 ] , &
rtB . pjulmwnqfc . of10phaqxi [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> czjyxcctju [ 0 ] , & rtB . lnm54cnchk . ltfzlzvs0c [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> m0wpx0tt4b [
i ] = rtB . fyu31sinwv . jhz4hydf42 [ i ] ; } _rtXdot -> kr3nejsoss = rtB .
h5gd3tgpey . g2eupjim4n ; _rtXdot -> jclkuzenpd = rtB . cxzd2dbymf .
mxe5eu4hb4 ; memcpy ( & _rtXdot -> bpmgvfdh3p [ 0 ] , & rtB . ntpm2p40uf .
hpfjqszf4x [ 0 ] , 12U * sizeof ( real_T ) ) ; _rtXdot -> ntmiect20q [ 0 ] =
rtB . avalzerqm0 . go4wiq4kbo [ 0 ] ; _rtXdot -> nw2qbjtrfg [ 0 ] = rtB .
h2durator1 . go4wiq4kbo [ 0 ] ; _rtXdot -> eysiy0scrq [ 0 ] = rtB .
c5nge20guz . go4wiq4kbo [ 0 ] ; _rtXdot -> cyoaoohsr1 [ 0 ] = rtB .
oiztqgxwa2 . go4wiq4kbo [ 0 ] ; _rtXdot -> d5kjlwmgrk [ 0 ] = rtB .
mdircrytff . fzjsuutou0 [ 0 ] ; _rtXdot -> i1zsver5ig [ 0 ] = rtB .
l1combp0kl . fzjsuutou0 [ 0 ] ; _rtXdot -> llgwidxzty [ 0 ] = rtB .
h0rgneuhfx . fzjsuutou0 [ 0 ] ; _rtXdot -> dcluu2qq0c [ 0 ] = rtB .
aqzxsisqqu . fzjsuutou0 [ 0 ] ; _rtXdot -> ntmiect20q [ 1 ] = rtB .
avalzerqm0 . go4wiq4kbo [ 1 ] ; _rtXdot -> nw2qbjtrfg [ 1 ] = rtB .
h2durator1 . go4wiq4kbo [ 1 ] ; _rtXdot -> eysiy0scrq [ 1 ] = rtB .
c5nge20guz . go4wiq4kbo [ 1 ] ; _rtXdot -> cyoaoohsr1 [ 1 ] = rtB .
oiztqgxwa2 . go4wiq4kbo [ 1 ] ; _rtXdot -> d5kjlwmgrk [ 1 ] = rtB .
mdircrytff . fzjsuutou0 [ 1 ] ; _rtXdot -> i1zsver5ig [ 1 ] = rtB .
l1combp0kl . fzjsuutou0 [ 1 ] ; _rtXdot -> llgwidxzty [ 1 ] = rtB .
h0rgneuhfx . fzjsuutou0 [ 1 ] ; _rtXdot -> dcluu2qq0c [ 1 ] = rtB .
aqzxsisqqu . fzjsuutou0 [ 1 ] ; _rtXdot -> mfmirsuvi1 = rtB . oja35avhxy .
mxe5eu4hb4 ; _rtXdot -> ajtyxihfqa = rtB . ga1oou1sez . g2eupjim4n ; _rtXdot
-> fev21ha45i = rtB . cx0tbybfel . mxe5eu4hb4 ; _rtXdot -> daodwibywh = rtB .
aax0e1c4lb . g2eupjim4n ; _rtXdot -> lkyqetg5kb = rtB . pltjyjalnc .
mxe5eu4hb4 ; _rtXdot -> btc4odj1vw = rtB . iinpzr5pdo . g2eupjim4n ; _rtXdot
-> c0pmpkzruv = rtB . axqhmtwvft . mxe5eu4hb4 ; _rtXdot -> jlansep42b = rtB .
fsjvhtbxoc . g2eupjim4n ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot ->
lbivgbnpeh [ i ] = rtB . ayhvjwdkil . admi3yqyf0 [ i ] ; _rtXdot ->
m54hyt4uuq [ i ] = rtB . ock5oqnuqf . abjrrhoh5i [ i ] ; _rtXdot ->
lxl24bgnmj [ i ] = rtB . czfjlbeq0m . hg1x1nd45k [ i ] ; } memcpy ( & _rtXdot
-> efyhshm0ot [ 0 ] , & rtB . jwvzg3dbyn . of10phaqxi [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> gdfmrn5gpc [ 0 ] , & rtB . aps0x4iowd .
ltfzlzvs0c [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> jbncktdjxo [ i ] = rtB . fxmpoowwke . jhz4hydf42 [ i ] ; _rtXdot
-> kwvqencn2m [ i ] = rtB . p3oko5rg5q . jl4fbhrop1 [ i ] ; _rtXdot ->
el0s1crasb [ i ] = rtB . oreloirudv . abjrrhoh5i [ i ] ; _rtXdot ->
iiijpho0bw [ i ] = rtB . cycndcb0jh . l5c2p5rmcp [ i ] ; } memcpy ( & _rtXdot
-> ef5r0lp3ux [ 0 ] , & rtB . c2otonew4a . of10phaqxi [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> iuw551xzyz [ 0 ] , & rtB . hclvb5l0yw .
ltfzlzvs0c [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> fqk1pcxz11 [ i ] = rtB . mnhfszymlh . jhz4hydf42 [ i ] ; } _rtXdot
-> guiwz4qjqi = rtB . gbsw4vtbfc . g2eupjim4n ; _rtXdot -> nvrhieikes = rtB .
lh525nk5c4 . mxe5eu4hb4 ; memcpy ( & _rtXdot -> p3bnpoi4ms [ 0 ] , & rtB .
kb4nwcrwes . hpfjqszf4x [ 0 ] , 12U * sizeof ( real_T ) ) ; _rtXdot ->
fat2ntucmp [ 0 ] = rtB . hetjmev4n0 . go4wiq4kbo [ 0 ] ; _rtXdot ->
f23ygfhi2f [ 0 ] = rtB . ofj3udt4tn . go4wiq4kbo [ 0 ] ; _rtXdot ->
jl5u0so5kr [ 0 ] = rtB . jrmqablme2 . go4wiq4kbo [ 0 ] ; _rtXdot ->
m4oor1dqcu [ 0 ] = rtB . oddtrbrdmn . go4wiq4kbo [ 0 ] ; _rtXdot ->
edonk3lpof [ 0 ] = rtB . bbzxnckkdp . fzjsuutou0 [ 0 ] ; _rtXdot ->
c2d4vnjngq [ 0 ] = rtB . lfwezxmueh . fzjsuutou0 [ 0 ] ; _rtXdot ->
ixb5n0f1pg [ 0 ] = rtB . hnz1gucse0 . fzjsuutou0 [ 0 ] ; _rtXdot ->
mvd25m5wxn [ 0 ] = rtB . myur3d20g5 . fzjsuutou0 [ 0 ] ; _rtXdot ->
fat2ntucmp [ 1 ] = rtB . hetjmev4n0 . go4wiq4kbo [ 1 ] ; _rtXdot ->
f23ygfhi2f [ 1 ] = rtB . ofj3udt4tn . go4wiq4kbo [ 1 ] ; _rtXdot ->
jl5u0so5kr [ 1 ] = rtB . jrmqablme2 . go4wiq4kbo [ 1 ] ; _rtXdot ->
m4oor1dqcu [ 1 ] = rtB . oddtrbrdmn . go4wiq4kbo [ 1 ] ; _rtXdot ->
edonk3lpof [ 1 ] = rtB . bbzxnckkdp . fzjsuutou0 [ 1 ] ; _rtXdot ->
c2d4vnjngq [ 1 ] = rtB . lfwezxmueh . fzjsuutou0 [ 1 ] ; _rtXdot ->
ixb5n0f1pg [ 1 ] = rtB . hnz1gucse0 . fzjsuutou0 [ 1 ] ; _rtXdot ->
mvd25m5wxn [ 1 ] = rtB . myur3d20g5 . fzjsuutou0 [ 1 ] ; _rtXdot ->
axapvnuown = rtB . ngaywgoh4j . mxe5eu4hb4 ; _rtXdot -> fk4euimlnu = rtB .
a40jt3tdup . g2eupjim4n ; _rtXdot -> gvdlmv0f2h = rtB . fozmp525vk .
mxe5eu4hb4 ; _rtXdot -> g4o2mykdy0 = rtB . e11zyd4z32 . g2eupjim4n ; _rtXdot
-> ms3jvyzwa2 = rtB . i3j3yx4m45 . mxe5eu4hb4 ; _rtXdot -> hftm5kpfrm = rtB .
i2czmwyezh . g2eupjim4n ; _rtXdot -> a0vktynhmg = rtB . lm3v4bjggl .
mxe5eu4hb4 ; _rtXdot -> ok1bkcbj54 = rtB . eocfzlmdyi . g2eupjim4n ; _rtXdot
-> f0gxn5lxra = 0.0 ; _rtXdot -> f0gxn5lxra += rtP . TransferFcn2_A * rtX .
f0gxn5lxra ; _rtXdot -> f0gxn5lxra += rtB . ctbtcnregv ; } void MdlProjection
( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> dev4s5rhsx = rtB .
etgxr0b4e3 - rtP . Switch2_Threshold ; _rtZCSV -> kgqoabbasj = rtB .
etgxr0b4e3 - rtP . Switch1_Threshold ; _rtZCSV -> ly02rzbkpp = rtB .
etgxr0b4e3 - rtP . Switch_Threshold ; { const double * timePtr = ( double * )
rtDW . p0dm4cko3k . TimePtr ; int_T * zcTimeIndices = & rtDW . fm531h0dfy [ 0
] ; int_T zcTimeIndicesIdx = rtDW . ary12ruqzb ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> elz2ohubbn = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV -> axhdhlbt0p = rtB .
g3ehhuuywp - rtP . Switch_Threshold_bpzjw1hzqd ; } void MdlTerminate ( void )
{ rt_TDelayFreeBuf ( rtDW . ir3tccey2d . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . mahzin5xie . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . em4ieblqdo . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . cp2wd3yek3 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . nuyw1oa5lu . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . ongfcz4dhf . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . jzm2uqh05o . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . kim1kgtcyq . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . e0iyas1xpb . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . gcbrh04vlv . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . aoi2q222df . TUbufferPtrs [ 0 ] ) ; rt_FREE ( rtDW
. p0dm4cko3k . RSimInfoPtr ) ; rt_FREE ( rtDW . puereonu00 . RSimInfoPtr ) ;
rt_FREE ( rtDW . iwwdwmgwmf . RSimInfoPtr ) ; rt_FREE ( rtDW . drrrzdfjw3 .
RSimInfoPtr ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 1017 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 723 ) ; ssSetNumBlockIO ( rtS , 368 ) ;
ssSetNumBlockParams ( rtS , 5243 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3552983888U ) ;
ssSetChecksumVal ( rtS , 1 , 601198247U ) ; ssSetChecksumVal ( rtS , 2 ,
753867492U ) ; ssSetChecksumVal ( rtS , 3 , 1027603516U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 17 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
Cooperative_Quad_09_VelEst_02_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Cooperative_Quad_09_VelEst_02" ) ; ssSetPath ( rtS ,
"Cooperative_Quad_09_VelEst_02" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 120.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 6 , 3 , 15 , 6 , 6 , 36 , 36 , 6
, 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 2 , 2 , 12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 15 , 15 , 15 , 3 , 3 , 3 , 1 , 1 , 2 , 2
, 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 ,
1 , 1 , 12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
6 , 6 , 6 , 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 12 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 36 , 36 , 6 ,
6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ]
= { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions
[ ] = { 6 , 3 , 15 , 6 , 6 , 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 ,
2 , 2 , 12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 ,
15 , 15 , 15 , 3 , 3 , 3 , 1 , 1 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6
, 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 12 , 2 , 2 , 2 , 2 , 2 , 2
, 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 36 , 36 , 6 , 6 , 6 , 6
, 36 , 36 , 6 , 1 , 1 , 12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 6 , 6 , 6 , 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 ,
12 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for Xd-1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for Xd-1/Integrator5"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Translational-1/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Ali-1/Rotational-1/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for X-1/Differentiator2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for X-1/Differentiator2/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for X-1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Decenteralized Cooperaive Controller #1/Cooperative Observers for X-1/Integrator2"
, "Cooperative_Quad_09_VelEst_02/Agent #1/Plant #1/Integrator" ,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for X-2/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for X-3/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for X-4/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_12/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_13/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_14/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_10/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for X-2/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for X-3/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for X-4/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_12/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_13/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_14/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_10/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for Xd-2/Integrator5"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for Xd-3/Integrator5"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for Xd-4/Integrator5"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for Xd-2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for Xd-3/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for Xd-4/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_10/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_10/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_12/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_12/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_13/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_13/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_14/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #1/Relative estimations-1/Rel_14/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Translational-2/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Ali-2/Rotational-2/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for X-2/Differentiator2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Decenteralized Cooperaive Controller #2/Cooperative Observers for X-2/Differentiator2/Integrator1"
, "Cooperative_Quad_09_VelEst_02/Agent #2/Plant #2/Integrator" ,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_21/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_23/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_24/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_20/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_21/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_23/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_24/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_20/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_20/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_20/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_21/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_21/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_23/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_23/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_24/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #2/Relative estimations-2/Rel_24/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Translational-3/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Ali-3/Rotational-3/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for X-3/Differentiator2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Decenteralized Cooperaive Controller #3/Cooperative Observers for X-3/Differentiator2/Integrator1"
, "Cooperative_Quad_09_VelEst_02/Agent #3/Plant #3/Integrator" ,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_31/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_32/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_34/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_30/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_31/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_32/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_34/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_30/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_30/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_30/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_31/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_31/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_32/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_32/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_34/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #3/Relative estimations-3/Rel_34/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Translational-4/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Integrator3"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Differentiator/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Differentiator/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Ali-4/Rotational-4/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for X-4/Differentiator2/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Decenteralized Cooperaive Controller #4/Cooperative Observers for X-4/Differentiator2/Integrator1"
, "Cooperative_Quad_09_VelEst_02/Agent #4/Plant #4/Integrator" ,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_41/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_42/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_43/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_40/Integrator2"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_41/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_42/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_43/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_40/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_40/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_40/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_41/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_41/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_42/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_42/Differentiator1/Integrator"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_43/Differentiator1/Integrator1"
,
 "Cooperative_Quad_09_VelEst_02/Agent #4/Relative estimations-4/Rel_43/Differentiator1/Integrator"
,
"Cooperative_Quad_09_VelEst_02/Data Bus /Reference Trajectory/Transfer Fcn2"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = {
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 145 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , ( NULL ) , { rt_LoggedStateLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , {
rt_LoggedStateNames } , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert
} ; static void * rt_LoggedStateSignalPtrs [ 145 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ionyxldtcw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jls05hpmo2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . mf3bhm1i2g [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . jhjq50hamr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . luz4nck343 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . fwt4soxxlc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . lmukmnay3o [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . oblwbzt05m [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . mgsh4lifu4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . g4ve5h5vh2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . mc4ye23acv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . pusmj51k2o [ 0 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . oh4v0qnmbl [ 0 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . i0ozzqeoz4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . gttal13ne4 ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . lhg5uf35jg ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . jyxqpcbioa [ 0 ] ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . f5podaplbs [ 0 ] ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . armybl4b3j [ 0 ] ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . omoyscdlkq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . bvv2j1fvkj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . jyfm4clkt1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . an1dy1scdv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtX . ajilevaypm [ 0 ] ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtX . ndnjgxlg32 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtX . mampjjggm5 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtX . c1zyhspvvj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtX . bozttf3lme [ 0 ] ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtX . lu2z2r1bq1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtX . au25a2kq45 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) & rtX . n1g43fm50u [ 0 ] ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) & rtX . jjhfp4nquz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 32 ] = ( void * ) & rtX . j0sputa12i [ 0 ] ;
rt_LoggedStateSignalPtrs [ 33 ] = ( void * ) & rtX . bpzbkldlw5 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 34 ] = ( void * ) & rtX . djt2dez0wq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 35 ] = ( void * ) & rtX . chv5h33ild [ 0 ] ;
rt_LoggedStateSignalPtrs [ 36 ] = ( void * ) & rtX . f5c0yrpl0m [ 0 ] ;
rt_LoggedStateSignalPtrs [ 37 ] = ( void * ) & rtX . jee34x0zc4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 38 ] = ( void * ) & rtX . im051m03c0 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 39 ] = ( void * ) & rtX . ossqjsfts4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 40 ] = ( void * ) & rtX . ivslgspzyl [ 0 ] ;
rt_LoggedStateSignalPtrs [ 41 ] = ( void * ) & rtX . hiamj1oevs ;
rt_LoggedStateSignalPtrs [ 42 ] = ( void * ) & rtX . gx3o1bpm3a ;
rt_LoggedStateSignalPtrs [ 43 ] = ( void * ) & rtX . gtdwc5tdzv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 44 ] = ( void * ) & rtX . cg2tzvhg1s [ 0 ] ;
rt_LoggedStateSignalPtrs [ 45 ] = ( void * ) & rtX . joe5wc3vru ;
rt_LoggedStateSignalPtrs [ 46 ] = ( void * ) & rtX . belilpb3dk ;
rt_LoggedStateSignalPtrs [ 47 ] = ( void * ) & rtX . bxlordfjyp ;
rt_LoggedStateSignalPtrs [ 48 ] = ( void * ) & rtX . mva2o1cupz ;
rt_LoggedStateSignalPtrs [ 49 ] = ( void * ) & rtX . lmqns2m2fd ;
rt_LoggedStateSignalPtrs [ 50 ] = ( void * ) & rtX . du3cl5u2br ;
rt_LoggedStateSignalPtrs [ 51 ] = ( void * ) & rtX . aqayeibnbf [ 0 ] ;
rt_LoggedStateSignalPtrs [ 52 ] = ( void * ) & rtX . mnhjgksiva [ 0 ] ;
rt_LoggedStateSignalPtrs [ 53 ] = ( void * ) & rtX . p5euhzgph2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 54 ] = ( void * ) & rtX . nsygkjz001 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 55 ] = ( void * ) & rtX . pyssp52j4v [ 0 ] ;
rt_LoggedStateSignalPtrs [ 56 ] = ( void * ) & rtX . fig1xy4s5q [ 0 ] ;
rt_LoggedStateSignalPtrs [ 57 ] = ( void * ) & rtX . lovsimzfsp [ 0 ] ;
rt_LoggedStateSignalPtrs [ 58 ] = ( void * ) & rtX . dvkhmbnof2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 59 ] = ( void * ) & rtX . gqi2mgds2b [ 0 ] ;
rt_LoggedStateSignalPtrs [ 60 ] = ( void * ) & rtX . ppo5lvnsbd [ 0 ] ;
rt_LoggedStateSignalPtrs [ 61 ] = ( void * ) & rtX . aslzbhpikx [ 0 ] ;
rt_LoggedStateSignalPtrs [ 62 ] = ( void * ) & rtX . m20bb5px11 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 63 ] = ( void * ) & rtX . dmaqihaxaq ;
rt_LoggedStateSignalPtrs [ 64 ] = ( void * ) & rtX . dsaqs0egeg ;
rt_LoggedStateSignalPtrs [ 65 ] = ( void * ) & rtX . hj3xpt5hh3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 66 ] = ( void * ) & rtX . fmtqkgzjo2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 67 ] = ( void * ) & rtX . eqlst0fie1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 68 ] = ( void * ) & rtX . jhyl0nmftj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 69 ] = ( void * ) & rtX . dufp23q24f [ 0 ] ;
rt_LoggedStateSignalPtrs [ 70 ] = ( void * ) & rtX . e5bm4mxp4y [ 0 ] ;
rt_LoggedStateSignalPtrs [ 71 ] = ( void * ) & rtX . d2zjdsdy3t [ 0 ] ;
rt_LoggedStateSignalPtrs [ 72 ] = ( void * ) & rtX . atdwxldcaa [ 0 ] ;
rt_LoggedStateSignalPtrs [ 73 ] = ( void * ) & rtX . kdrbhkothr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 74 ] = ( void * ) & rtX . l1nyqmvwst ;
rt_LoggedStateSignalPtrs [ 75 ] = ( void * ) & rtX . ca2tchanai ;
rt_LoggedStateSignalPtrs [ 76 ] = ( void * ) & rtX . ooketywe0t ;
rt_LoggedStateSignalPtrs [ 77 ] = ( void * ) & rtX . mjw0keqmwr ;
rt_LoggedStateSignalPtrs [ 78 ] = ( void * ) & rtX . fb0bskoedk ;
rt_LoggedStateSignalPtrs [ 79 ] = ( void * ) & rtX . phfjeo0drc ;
rt_LoggedStateSignalPtrs [ 80 ] = ( void * ) & rtX . d0fq4dyqzm ;
rt_LoggedStateSignalPtrs [ 81 ] = ( void * ) & rtX . irfwmkoozp ;
rt_LoggedStateSignalPtrs [ 82 ] = ( void * ) & rtX . gfix1az2dy [ 0 ] ;
rt_LoggedStateSignalPtrs [ 83 ] = ( void * ) & rtX . lajj3kiv0r [ 0 ] ;
rt_LoggedStateSignalPtrs [ 84 ] = ( void * ) & rtX . musq314bsn [ 0 ] ;
rt_LoggedStateSignalPtrs [ 85 ] = ( void * ) & rtX . oljl1r15sy [ 0 ] ;
rt_LoggedStateSignalPtrs [ 86 ] = ( void * ) & rtX . kdjra2pfq4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 87 ] = ( void * ) & rtX . ox0f0pxtqm [ 0 ] ;
rt_LoggedStateSignalPtrs [ 88 ] = ( void * ) & rtX . eu121u4uj2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 89 ] = ( void * ) & rtX . bgjp3vzt5z [ 0 ] ;
rt_LoggedStateSignalPtrs [ 90 ] = ( void * ) & rtX . dn5twkxizj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 91 ] = ( void * ) & rtX . eeiannul5v [ 0 ] ;
rt_LoggedStateSignalPtrs [ 92 ] = ( void * ) & rtX . czjyxcctju [ 0 ] ;
rt_LoggedStateSignalPtrs [ 93 ] = ( void * ) & rtX . m0wpx0tt4b [ 0 ] ;
rt_LoggedStateSignalPtrs [ 94 ] = ( void * ) & rtX . kr3nejsoss ;
rt_LoggedStateSignalPtrs [ 95 ] = ( void * ) & rtX . jclkuzenpd ;
rt_LoggedStateSignalPtrs [ 96 ] = ( void * ) & rtX . bpmgvfdh3p [ 0 ] ;
rt_LoggedStateSignalPtrs [ 97 ] = ( void * ) & rtX . ntmiect20q [ 0 ] ;
rt_LoggedStateSignalPtrs [ 98 ] = ( void * ) & rtX . nw2qbjtrfg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 99 ] = ( void * ) & rtX . eysiy0scrq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 100 ] = ( void * ) & rtX . cyoaoohsr1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 101 ] = ( void * ) & rtX . d5kjlwmgrk [ 0 ] ;
rt_LoggedStateSignalPtrs [ 102 ] = ( void * ) & rtX . i1zsver5ig [ 0 ] ;
rt_LoggedStateSignalPtrs [ 103 ] = ( void * ) & rtX . llgwidxzty [ 0 ] ;
rt_LoggedStateSignalPtrs [ 104 ] = ( void * ) & rtX . dcluu2qq0c [ 0 ] ;
rt_LoggedStateSignalPtrs [ 105 ] = ( void * ) & rtX . mfmirsuvi1 ;
rt_LoggedStateSignalPtrs [ 106 ] = ( void * ) & rtX . ajtyxihfqa ;
rt_LoggedStateSignalPtrs [ 107 ] = ( void * ) & rtX . fev21ha45i ;
rt_LoggedStateSignalPtrs [ 108 ] = ( void * ) & rtX . daodwibywh ;
rt_LoggedStateSignalPtrs [ 109 ] = ( void * ) & rtX . lkyqetg5kb ;
rt_LoggedStateSignalPtrs [ 110 ] = ( void * ) & rtX . btc4odj1vw ;
rt_LoggedStateSignalPtrs [ 111 ] = ( void * ) & rtX . c0pmpkzruv ;
rt_LoggedStateSignalPtrs [ 112 ] = ( void * ) & rtX . jlansep42b ;
rt_LoggedStateSignalPtrs [ 113 ] = ( void * ) & rtX . lbivgbnpeh [ 0 ] ;
rt_LoggedStateSignalPtrs [ 114 ] = ( void * ) & rtX . m54hyt4uuq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 115 ] = ( void * ) & rtX . lxl24bgnmj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 116 ] = ( void * ) & rtX . efyhshm0ot [ 0 ] ;
rt_LoggedStateSignalPtrs [ 117 ] = ( void * ) & rtX . gdfmrn5gpc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 118 ] = ( void * ) & rtX . jbncktdjxo [ 0 ] ;
rt_LoggedStateSignalPtrs [ 119 ] = ( void * ) & rtX . kwvqencn2m [ 0 ] ;
rt_LoggedStateSignalPtrs [ 120 ] = ( void * ) & rtX . el0s1crasb [ 0 ] ;
rt_LoggedStateSignalPtrs [ 121 ] = ( void * ) & rtX . iiijpho0bw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 122 ] = ( void * ) & rtX . ef5r0lp3ux [ 0 ] ;
rt_LoggedStateSignalPtrs [ 123 ] = ( void * ) & rtX . iuw551xzyz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 124 ] = ( void * ) & rtX . fqk1pcxz11 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 125 ] = ( void * ) & rtX . guiwz4qjqi ;
rt_LoggedStateSignalPtrs [ 126 ] = ( void * ) & rtX . nvrhieikes ;
rt_LoggedStateSignalPtrs [ 127 ] = ( void * ) & rtX . p3bnpoi4ms [ 0 ] ;
rt_LoggedStateSignalPtrs [ 128 ] = ( void * ) & rtX . fat2ntucmp [ 0 ] ;
rt_LoggedStateSignalPtrs [ 129 ] = ( void * ) & rtX . f23ygfhi2f [ 0 ] ;
rt_LoggedStateSignalPtrs [ 130 ] = ( void * ) & rtX . jl5u0so5kr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 131 ] = ( void * ) & rtX . m4oor1dqcu [ 0 ] ;
rt_LoggedStateSignalPtrs [ 132 ] = ( void * ) & rtX . edonk3lpof [ 0 ] ;
rt_LoggedStateSignalPtrs [ 133 ] = ( void * ) & rtX . c2d4vnjngq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 134 ] = ( void * ) & rtX . ixb5n0f1pg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 135 ] = ( void * ) & rtX . mvd25m5wxn [ 0 ] ;
rt_LoggedStateSignalPtrs [ 136 ] = ( void * ) & rtX . axapvnuown ;
rt_LoggedStateSignalPtrs [ 137 ] = ( void * ) & rtX . fk4euimlnu ;
rt_LoggedStateSignalPtrs [ 138 ] = ( void * ) & rtX . gvdlmv0f2h ;
rt_LoggedStateSignalPtrs [ 139 ] = ( void * ) & rtX . g4o2mykdy0 ;
rt_LoggedStateSignalPtrs [ 140 ] = ( void * ) & rtX . ms3jvyzwa2 ;
rt_LoggedStateSignalPtrs [ 141 ] = ( void * ) & rtX . hftm5kpfrm ;
rt_LoggedStateSignalPtrs [ 142 ] = ( void * ) & rtX . a0vktynhmg ;
rt_LoggedStateSignalPtrs [ 143 ] = ( void * ) & rtX . ok1bkcbj54 ;
rt_LoggedStateSignalPtrs [ 144 ] = ( void * ) & rtX . f0gxn5lxra ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 1017 ] ; static
real_T absTol [ 1017 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 1017 ] =
{ 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 5 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 64 ] = { { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
f1botvjvoe [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( &
rtB . da52lxzfo3 [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * )
( & rtB . g3orff0vvz [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( epsilon_bus ) , (
char * ) ( & rtB . fxxr4yxfew ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . fzvqljdzf0 ) , ( NULL ) } , { 6 * sizeof ( real_T ) , (
char * ) ( & rtB . nx0lawusi5 [ 0 ] ) , ( NULL ) } , { 6 * sizeof ( real_T )
, ( char * ) ( & rtB . c01olslca1 [ 0 ] ) , ( NULL ) } , { 12 * sizeof (
real_T ) , ( char * ) ( & rtB . keppwjdt4q [ 0 ] ) , ( NULL ) } , { 2 *
sizeof ( real_T ) , ( char * ) ( & rtB . amoxktpzg5 [ 0 ] ) , ( NULL ) } , {
2 * sizeof ( real_T ) , ( char * ) ( & rtB . ielqt1mrev [ 0 ] ) , ( NULL ) }
, { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . jaakjngya0 [ 0 ] ) , ( NULL
) } , { 1 * sizeof ( epsilon_bus ) , ( char * ) ( & rtB . bszz24pz1b ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . okfse5qvqh ) , (
NULL ) } , { 6 * sizeof ( real_T ) , ( char * ) ( & rtB . jrkcafrldp [ 0 ] )
, ( NULL ) } , { 6 * sizeof ( real_T ) , ( char * ) ( & rtB . mgul3pau2j [ 0
] ) , ( NULL ) } , { 12 * sizeof ( real_T ) , ( char * ) ( & rtB . ixaiy5tpfv
[ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
kfsw4l5xh5 [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( &
rtB . jpsqiswtns [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * )
( & rtB . hcksi1q3o0 [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( epsilon_bus ) , (
char * ) ( & rtB . hbcqjuse5q ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . ll2wsps0hn ) , ( NULL ) } , { 6 * sizeof ( real_T ) , (
char * ) ( & rtB . k2wfwxwner [ 0 ] ) , ( NULL ) } , { 6 * sizeof ( real_T )
, ( char * ) ( & rtB . cj3tu2cvgj [ 0 ] ) , ( NULL ) } , { 12 * sizeof (
real_T ) , ( char * ) ( & rtB . ktzqeyaa2j [ 0 ] ) , ( NULL ) } , { 2 *
sizeof ( real_T ) , ( char * ) ( & rtB . f5apej04cu [ 0 ] ) , ( NULL ) } , {
2 * sizeof ( real_T ) , ( char * ) ( & rtB . ajq0qn0k3g [ 0 ] ) , ( NULL ) }
, { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . ordnmswswg [ 0 ] ) , ( NULL
) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . icqhriylz3 [ 0 ] ) , (
NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . bqxn34m0qr [ 0 ] )
, ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . cdzixgvais [ 0
] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . g2pdbeghl4
[ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
ixqvkyn0bs [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( &
rtB . leex1vr2mc [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * )
( & rtB . kakeuy45nl [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T ) , ( char
* ) ( & rtB . gorv20ywqu [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . ar5mtka5cc [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T )
, ( char * ) ( & rtB . i10izinweb [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . fjnyclhmei [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( epsilon_bus ) , ( char * ) ( & rtB . hvniiswj0n ) , ( NULL ) } , { 2
* sizeof ( real_T ) , ( char * ) ( & rtB . f3swi4wykw [ 0 ] ) , ( NULL ) } ,
{ 2 * sizeof ( real_T ) , ( char * ) ( & rtB . cq2ac25vvr [ 0 ] ) , ( NULL )
} , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . kjfk5s4txt [ 0 ] ) , (
NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . ibguh2azcu [ 0 ] )
, ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . n1skxybgba [ 0
] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB . kthfd0aif2
[ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
obobcozbfh [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( &
rtB . mka13uwfw0 [ 0 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * )
( & rtB . fyll5jdjjj [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char
* ) ( & rtB . fsylupg2ie ) , ( NULL ) } , { 6 * sizeof ( real_T ) , ( char *
) ( & rtB . naukoivzmr [ 0 ] ) , ( NULL ) } , { 6 * sizeof ( real_T ) , (
char * ) ( & rtB . cltq0cfb00 [ 0 ] ) , ( NULL ) } , { 12 * sizeof ( real_T )
, ( char * ) ( & rtB . hoefupodzc [ 0 ] ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . b5wgwyu43w . ortedkvoqi ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . bznnvznea4 . ortedkvoqi ) , ( NULL
) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . nd45g0hfjt . ortedkvoqi
) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . mrepog2h42 .
ortedkvoqi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ns3lzfiy1g . ortedkvoqi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * )
( & rtB . l2j5ycxexp . ortedkvoqi ) , ( NULL ) } , { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . nwyzua4gjf . ortedkvoqi ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . cgmylk2bxu . ortedkvoqi ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . ina2eaxl2c . ortedkvoqi ) , ( NULL
) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . fnvhv3sjko . ortedkvoqi
) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . ey4yzgiezw .
ortedkvoqi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
bfqgyvaqcz . ortedkvoqi ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 )
; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 2.4 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
64 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 5 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 5 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3552983888U ) ; ssSetChecksumVal ( rtS , 1 ,
601198247U ) ; ssSetChecksumVal ( rtS , 2 , 753867492U ) ; ssSetChecksumVal (
rtS , 3 , 1027603516U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 211 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ;
systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = & rtAlwaysEnabled ;
systemRan [ 26 ] = & rtAlwaysEnabled ; systemRan [ 27 ] = & rtAlwaysEnabled ;
systemRan [ 28 ] = & rtAlwaysEnabled ; systemRan [ 29 ] = & rtAlwaysEnabled ;
systemRan [ 30 ] = & rtAlwaysEnabled ; systemRan [ 31 ] = & rtAlwaysEnabled ;
systemRan [ 32 ] = & rtAlwaysEnabled ; systemRan [ 33 ] = & rtAlwaysEnabled ;
systemRan [ 34 ] = & rtAlwaysEnabled ; systemRan [ 35 ] = & rtAlwaysEnabled ;
systemRan [ 36 ] = & rtAlwaysEnabled ; systemRan [ 37 ] = & rtAlwaysEnabled ;
systemRan [ 38 ] = & rtAlwaysEnabled ; systemRan [ 39 ] = & rtAlwaysEnabled ;
systemRan [ 40 ] = & rtAlwaysEnabled ; systemRan [ 41 ] = & rtAlwaysEnabled ;
systemRan [ 42 ] = & rtAlwaysEnabled ; systemRan [ 43 ] = & rtAlwaysEnabled ;
systemRan [ 44 ] = & rtAlwaysEnabled ; systemRan [ 45 ] = & rtAlwaysEnabled ;
systemRan [ 46 ] = & rtAlwaysEnabled ; systemRan [ 47 ] = & rtAlwaysEnabled ;
systemRan [ 48 ] = & rtAlwaysEnabled ; systemRan [ 49 ] = & rtAlwaysEnabled ;
systemRan [ 50 ] = & rtAlwaysEnabled ; systemRan [ 51 ] = & rtAlwaysEnabled ;
systemRan [ 52 ] = & rtAlwaysEnabled ; systemRan [ 53 ] = & rtAlwaysEnabled ;
systemRan [ 54 ] = & rtAlwaysEnabled ; systemRan [ 55 ] = & rtAlwaysEnabled ;
systemRan [ 56 ] = & rtAlwaysEnabled ; systemRan [ 57 ] = & rtAlwaysEnabled ;
systemRan [ 58 ] = & rtAlwaysEnabled ; systemRan [ 59 ] = & rtAlwaysEnabled ;
systemRan [ 60 ] = & rtAlwaysEnabled ; systemRan [ 61 ] = & rtAlwaysEnabled ;
systemRan [ 62 ] = & rtAlwaysEnabled ; systemRan [ 63 ] = & rtAlwaysEnabled ;
systemRan [ 64 ] = & rtAlwaysEnabled ; systemRan [ 65 ] = & rtAlwaysEnabled ;
systemRan [ 66 ] = & rtAlwaysEnabled ; systemRan [ 67 ] = & rtAlwaysEnabled ;
systemRan [ 68 ] = & rtAlwaysEnabled ; systemRan [ 69 ] = & rtAlwaysEnabled ;
systemRan [ 70 ] = & rtAlwaysEnabled ; systemRan [ 71 ] = & rtAlwaysEnabled ;
systemRan [ 72 ] = & rtAlwaysEnabled ; systemRan [ 73 ] = & rtAlwaysEnabled ;
systemRan [ 74 ] = & rtAlwaysEnabled ; systemRan [ 75 ] = & rtAlwaysEnabled ;
systemRan [ 76 ] = & rtAlwaysEnabled ; systemRan [ 77 ] = & rtAlwaysEnabled ;
systemRan [ 78 ] = & rtAlwaysEnabled ; systemRan [ 79 ] = & rtAlwaysEnabled ;
systemRan [ 80 ] = & rtAlwaysEnabled ; systemRan [ 81 ] = & rtAlwaysEnabled ;
systemRan [ 82 ] = & rtAlwaysEnabled ; systemRan [ 83 ] = & rtAlwaysEnabled ;
systemRan [ 84 ] = & rtAlwaysEnabled ; systemRan [ 85 ] = & rtAlwaysEnabled ;
systemRan [ 86 ] = & rtAlwaysEnabled ; systemRan [ 87 ] = & rtAlwaysEnabled ;
systemRan [ 88 ] = & rtAlwaysEnabled ; systemRan [ 89 ] = & rtAlwaysEnabled ;
systemRan [ 90 ] = & rtAlwaysEnabled ; systemRan [ 91 ] = & rtAlwaysEnabled ;
systemRan [ 92 ] = & rtAlwaysEnabled ; systemRan [ 93 ] = & rtAlwaysEnabled ;
systemRan [ 94 ] = & rtAlwaysEnabled ; systemRan [ 95 ] = & rtAlwaysEnabled ;
systemRan [ 96 ] = & rtAlwaysEnabled ; systemRan [ 97 ] = & rtAlwaysEnabled ;
systemRan [ 98 ] = & rtAlwaysEnabled ; systemRan [ 99 ] = & rtAlwaysEnabled ;
systemRan [ 100 ] = & rtAlwaysEnabled ; systemRan [ 101 ] = & rtAlwaysEnabled
; systemRan [ 102 ] = & rtAlwaysEnabled ; systemRan [ 103 ] = &
rtAlwaysEnabled ; systemRan [ 104 ] = & rtAlwaysEnabled ; systemRan [ 105 ] =
& rtAlwaysEnabled ; systemRan [ 106 ] = & rtAlwaysEnabled ; systemRan [ 107 ]
= & rtAlwaysEnabled ; systemRan [ 108 ] = & rtAlwaysEnabled ; systemRan [ 109
] = & rtAlwaysEnabled ; systemRan [ 110 ] = & rtAlwaysEnabled ; systemRan [
111 ] = & rtAlwaysEnabled ; systemRan [ 112 ] = & rtAlwaysEnabled ; systemRan
[ 113 ] = & rtAlwaysEnabled ; systemRan [ 114 ] = & rtAlwaysEnabled ;
systemRan [ 115 ] = & rtAlwaysEnabled ; systemRan [ 116 ] = & rtAlwaysEnabled
; systemRan [ 117 ] = & rtAlwaysEnabled ; systemRan [ 118 ] = &
rtAlwaysEnabled ; systemRan [ 119 ] = & rtAlwaysEnabled ; systemRan [ 120 ] =
& rtAlwaysEnabled ; systemRan [ 121 ] = & rtAlwaysEnabled ; systemRan [ 122 ]
= & rtAlwaysEnabled ; systemRan [ 123 ] = & rtAlwaysEnabled ; systemRan [ 124
] = & rtAlwaysEnabled ; systemRan [ 125 ] = & rtAlwaysEnabled ; systemRan [
126 ] = & rtAlwaysEnabled ; systemRan [ 127 ] = & rtAlwaysEnabled ; systemRan
[ 128 ] = & rtAlwaysEnabled ; systemRan [ 129 ] = & rtAlwaysEnabled ;
systemRan [ 130 ] = & rtAlwaysEnabled ; systemRan [ 131 ] = & rtAlwaysEnabled
; systemRan [ 132 ] = & rtAlwaysEnabled ; systemRan [ 133 ] = &
rtAlwaysEnabled ; systemRan [ 134 ] = & rtAlwaysEnabled ; systemRan [ 135 ] =
& rtAlwaysEnabled ; systemRan [ 136 ] = & rtAlwaysEnabled ; systemRan [ 137 ]
= & rtAlwaysEnabled ; systemRan [ 138 ] = & rtAlwaysEnabled ; systemRan [ 139
] = & rtAlwaysEnabled ; systemRan [ 140 ] = & rtAlwaysEnabled ; systemRan [
141 ] = & rtAlwaysEnabled ; systemRan [ 142 ] = & rtAlwaysEnabled ; systemRan
[ 143 ] = & rtAlwaysEnabled ; systemRan [ 144 ] = & rtAlwaysEnabled ;
systemRan [ 145 ] = & rtAlwaysEnabled ; systemRan [ 146 ] = & rtAlwaysEnabled
; systemRan [ 147 ] = & rtAlwaysEnabled ; systemRan [ 148 ] = &
rtAlwaysEnabled ; systemRan [ 149 ] = & rtAlwaysEnabled ; systemRan [ 150 ] =
& rtAlwaysEnabled ; systemRan [ 151 ] = & rtAlwaysEnabled ; systemRan [ 152 ]
= & rtAlwaysEnabled ; systemRan [ 153 ] = & rtAlwaysEnabled ; systemRan [ 154
] = & rtAlwaysEnabled ; systemRan [ 155 ] = & rtAlwaysEnabled ; systemRan [
156 ] = & rtAlwaysEnabled ; systemRan [ 157 ] = & rtAlwaysEnabled ; systemRan
[ 158 ] = & rtAlwaysEnabled ; systemRan [ 159 ] = & rtAlwaysEnabled ;
systemRan [ 160 ] = & rtAlwaysEnabled ; systemRan [ 161 ] = & rtAlwaysEnabled
; systemRan [ 162 ] = & rtAlwaysEnabled ; systemRan [ 163 ] = &
rtAlwaysEnabled ; systemRan [ 164 ] = & rtAlwaysEnabled ; systemRan [ 165 ] =
& rtAlwaysEnabled ; systemRan [ 166 ] = & rtAlwaysEnabled ; systemRan [ 167 ]
= & rtAlwaysEnabled ; systemRan [ 168 ] = & rtAlwaysEnabled ; systemRan [ 169
] = & rtAlwaysEnabled ; systemRan [ 170 ] = & rtAlwaysEnabled ; systemRan [
171 ] = & rtAlwaysEnabled ; systemRan [ 172 ] = & rtAlwaysEnabled ; systemRan
[ 173 ] = & rtAlwaysEnabled ; systemRan [ 174 ] = & rtAlwaysEnabled ;
systemRan [ 175 ] = & rtAlwaysEnabled ; systemRan [ 176 ] = & rtAlwaysEnabled
; systemRan [ 177 ] = & rtAlwaysEnabled ; systemRan [ 178 ] = &
rtAlwaysEnabled ; systemRan [ 179 ] = & rtAlwaysEnabled ; systemRan [ 180 ] =
& rtAlwaysEnabled ; systemRan [ 181 ] = & rtAlwaysEnabled ; systemRan [ 182 ]
= & rtAlwaysEnabled ; systemRan [ 183 ] = & rtAlwaysEnabled ; systemRan [ 184
] = & rtAlwaysEnabled ; systemRan [ 185 ] = & rtAlwaysEnabled ; systemRan [
186 ] = & rtAlwaysEnabled ; systemRan [ 187 ] = & rtAlwaysEnabled ; systemRan
[ 188 ] = & rtAlwaysEnabled ; systemRan [ 189 ] = & rtAlwaysEnabled ;
systemRan [ 190 ] = & rtAlwaysEnabled ; systemRan [ 191 ] = & rtAlwaysEnabled
; systemRan [ 192 ] = & rtAlwaysEnabled ; systemRan [ 193 ] = &
rtAlwaysEnabled ; systemRan [ 194 ] = & rtAlwaysEnabled ; systemRan [ 195 ] =
& rtAlwaysEnabled ; systemRan [ 196 ] = & rtAlwaysEnabled ; systemRan [ 197 ]
= & rtAlwaysEnabled ; systemRan [ 198 ] = & rtAlwaysEnabled ; systemRan [ 199
] = & rtAlwaysEnabled ; systemRan [ 200 ] = & rtAlwaysEnabled ; systemRan [
201 ] = & rtAlwaysEnabled ; systemRan [ 202 ] = & rtAlwaysEnabled ; systemRan
[ 203 ] = & rtAlwaysEnabled ; systemRan [ 204 ] = & rtAlwaysEnabled ;
systemRan [ 205 ] = & rtAlwaysEnabled ; systemRan [ 206 ] = & rtAlwaysEnabled
; systemRan [ 207 ] = & rtAlwaysEnabled ; systemRan [ 208 ] = &
rtAlwaysEnabled ; systemRan [ 209 ] = & rtAlwaysEnabled ; systemRan [ 210 ] =
& rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS )
, & ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
