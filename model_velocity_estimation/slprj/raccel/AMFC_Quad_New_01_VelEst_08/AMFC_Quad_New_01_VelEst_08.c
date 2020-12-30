#include "__cf_AMFC_Quad_New_01_VelEst_08.h"
#include "rt_logging_mmi.h"
#include "AMFC_Quad_New_01_VelEst_08_capi.h"
#include <math.h>
#include "AMFC_Quad_New_01_VelEst_08.h"
#include "AMFC_Quad_New_01_VelEst_08_private.h"
#include "AMFC_Quad_New_01_VelEst_08_dt.h"
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
 "slprj\\raccel\\AMFC_Quad_New_01_VelEst_08\\AMFC_Quad_New_01_VelEst_08_Jpattern.mat"
; const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const
int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1
} ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const real_T AMFC_Quad_New_01_VelEst_08_RGND = 0.0 ; B rtB ; X rtX ; DW rtDW
; static SimStruct model_S ; SimStruct * const rtS = & model_S ; static void
jd4ezcvle4 ( const real_T x [ 36 ] , real_T y [ 36 ] ) ; static void
fl1odpwfid ( const real_T a [ 9 ] , real_T c [ 9 ] ) ;
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
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void jiqhbaps0d (
const real_T ntfm5wyyos [ 36 ] , const real_T eoxgvmfexp [ 36 ] , o1slwgqdlm
* localB ) { real_T eoxgvmfexp_p [ 36 ] ; real_T ntfm5wyyos_p [ 36 ] ;
int32_T i ; int32_T i_p ; int32_T i_e ; real_T ntfm5wyyos_e [ 36 ] ; real_T
ntfm5wyyos_i [ 36 ] ; real_T ntfm5wyyos_m [ 36 ] ; real_T tmp ; for ( i = 0 ;
i < 6 ; i ++ ) { for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { eoxgvmfexp_p [ i + 6 *
i_p ] = 0.0 ; ntfm5wyyos_p [ i + 6 * i_p ] = 0.0 ; ntfm5wyyos_e [ i + 6 * i_p
] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e ++ ) { eoxgvmfexp_p [ i + 6 * i_p ]
+= eoxgvmfexp [ 6 * i_e + i ] * ntfm5wyyos [ 6 * i_p + i_e ] ; ntfm5wyyos_p [
i + 6 * i_p ] += ntfm5wyyos [ 6 * i_e + i ] * eoxgvmfexp [ 6 * i_e + i_p ] ;
ntfm5wyyos_e [ i + 6 * i_p ] += ntfm5wyyos [ 6 * i_e + i ] * rtP . B [ 6 *
i_p + i_e ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { ntfm5wyyos_i [ i + 6 *
i_p ] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e ++ ) { ntfm5wyyos_i [ i + 6 * i_p
] += ntfm5wyyos_e [ 6 * i_e + i ] * rtP . R [ 6 * i_p + i_e ] ; } } for ( i_p
= 0 ; i_p < 6 ; i_p ++ ) { ntfm5wyyos_m [ i + 6 * i_p ] = 0.0 ; for ( i_e = 0
; i_e < 6 ; i_e ++ ) { ntfm5wyyos_m [ i + 6 * i_p ] += ntfm5wyyos_i [ 6 * i_e
+ i ] * rtP . B [ 6 * i_e + i_p ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
tmp = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp += ntfm5wyyos_m [ 6 *
i_e + i ] * ntfm5wyyos [ 6 * i_p + i_e ] ; } localB -> cxgasfu34l [ i + 6 *
i_p ] = ( ( eoxgvmfexp_p [ 6 * i_p + i ] + ntfm5wyyos_p [ 6 * i_p + i ] ) -
tmp ) + rtP . Q [ 6 * i_p + i ] * 2.0 ; } } } void k5z0pc1ypp ( const real_T
ihvcx1pkz5 [ 6 ] , const real_T axfks553mz [ 6 ] , fwylrlcfrr * localB ) {
int32_T i ; real_T ABS ; for ( i = 0 ; i < 6 ; i ++ ) { if ( axfks553mz [ i ]
> 0.0 ) { ABS = axfks553mz [ i ] ; } else { ABS = - axfks553mz [ i ] ; }
localB -> ao4ocy3oo3 [ i ] = muDoubleScalarSqrt ( ABS ) ; localB ->
ao4ocy3oo3 [ i ] = ihvcx1pkz5 [ i ] - axfks553mz [ i ] / ( ABS + 0.01 ) * (
rtP . k1 * localB -> ao4ocy3oo3 [ i ] ) ; } } void pqkbkv225c ( const real_T
jjomphwdey [ 6 ] , lthd11jgkt * localB ) { int32_T i ; for ( i = 0 ; i < 6 ;
i ++ ) { if ( jjomphwdey [ i ] > 0.0 ) { localB -> oaqi4nmegi [ i ] =
jjomphwdey [ i ] ; } else { localB -> oaqi4nmegi [ i ] = - jjomphwdey [ i ] ;
} localB -> oaqi4nmegi [ i ] = jjomphwdey [ i ] / ( localB -> oaqi4nmegi [ i
] + 0.01 ) * - rtP . k2 ; } } void o4x1a0lhdq ( const real_T k5mfunhgj4 [ 6 ]
, const real_T nichsfli03 [ 6 ] , const real_T idotbkjchs [ 36 ] , db1uh4mzfc
* localB ) { real_T tmp [ 36 ] ; int32_T i ; int32_T i_p ; real_T tmp_p [ 36
] ; int32_T i_e ; real_T tmp_e [ 6 ] ; real_T tmp_i [ 6 ] ; real_T tmp_m ;
for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp [ i +
6 * i_p ] = - rtP . gamma_1 [ 6 * i_p + i ] ; } } for ( i_p = 0 ; i_p < 6 ;
i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp_p [ i_p + 6 * i ] = 0.0 ; for (
i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp_m = tmp [ 6 * i_e + i_p ] * idotbkjchs [ 6
* i + i_e ] + tmp_p [ 6 * i + i_p ] ; tmp_p [ i_p + 6 * i ] = tmp_m ; } } }
for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_e [ i_p ] = 0.0 ; for ( i = 0 ; i <
6 ; i ++ ) { tmp_m = tmp_p [ 6 * i + i_p ] * k5mfunhgj4 [ i ] + tmp_e [ i_p ]
; tmp_e [ i_p ] = tmp_m ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_i [
i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { tmp_m = rtP . gamma_1 [ 6 * i +
i_p ] * rtP . rho_1 * nichsfli03 [ i ] + tmp_i [ i_p ] ; tmp_i [ i_p ] =
tmp_m ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { localB -> n54ymdd4p0 [ i_p ]
= tmp_e [ i_p ] - tmp_i [ i_p ] ; } } void hdagumznar ( const real_T
azrtukjyo3 [ 6 ] , const real_T mbkt3c5lml [ 6 ] , const real_T dr5igse0fb [
36 ] , const real_T aoipawa0bm [ 36 ] , na51yrjijx * localB ) { real_T
DVa_hat [ 6 ] ; real_T d [ 36 ] ; int32_T j ; real_T b_d [ 6 ] ; real_T tmp [
36 ] ; int32_T i ; real_T tmp_p [ 36 ] ; int32_T i_p ; real_T tmp_e [ 36 ] ;
real_T mbkt3c5lml_p [ 6 ] ; real_T tmp_i [ 6 ] ; real_T tmp_m [ 6 ] ; memset
( & d [ 0 ] , 0 , 36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) {
d [ j + 6 * j ] = azrtukjyo3 [ j ] ; b_d [ j ] = aoipawa0bm [ j * 7 ] ; for (
i = 0 ; i < 6 ; i ++ ) { tmp [ i + 6 * j ] = - rtP . gamma_0 [ 6 * j + i ] ;
} } for ( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ; j < 6 ; j ++ ) { tmp_p [ i +
6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_p [ i + 6 * j ] +=
tmp [ 6 * i_p + i ] * dr5igse0fb [ 6 * j + i_p ] ; } } for ( j = 0 ; j < 6 ;
j ++ ) { tmp_e [ i + 6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
tmp_e [ i + 6 * j ] += tmp_p [ 6 * i_p + i ] * d [ 6 * j + i_p ] ; } }
mbkt3c5lml_p [ i ] = mbkt3c5lml [ i ] - azrtukjyo3 [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { tmp_i [ i ] = 0.0 ; tmp_m [ i ] = 0.0 ; for ( j = 0 ; j < 6 ;
j ++ ) { tmp_i [ i ] += tmp_e [ 6 * j + i ] * mbkt3c5lml_p [ j ] ; tmp_m [ i
] += rtP . gamma_0 [ 6 * j + i ] * rtP . rho_0 * b_d [ j ] ; } DVa_hat [ i ]
= tmp_i [ i ] - tmp_m [ i ] ; } memset ( & localB -> ejjucyteji [ 0 ] , 0 ,
36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) { localB ->
ejjucyteji [ j + 6 * j ] = DVa_hat [ j ] ; } } static void jd4ezcvle4 ( const
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
] ; } } } } } void l2lj4cmfck ( const real_T fy0kyp3umm [ 6 ] , const real_T
ioqjsibok0 [ 6 ] , const real_T fa2brwwlb2 [ 6 ] , const real_T kkedrh1goh [
36 ] , const real_T p4gjxfn55e [ 36 ] , const real_T ilb0lcvng0 [ 6 ] , const
real_T olxmf2elsi [ 6 ] , bzqp5lmsxs * localB ) { int8_T I [ 36 ] ; int32_T k
; real_T tmp [ 36 ] ; int32_T i ; int32_T i_p ; real_T tmp_p [ 36 ] ; real_T
I_p [ 36 ] ; real_T fa2brwwlb2_p [ 6 ] ; real_T I_e [ 6 ] ; real_T
fa2brwwlb2_e [ 6 ] ; real_T I_i ; for ( k = 0 ; k < 36 ; k ++ ) { I [ k ] = 0
; } for ( k = 0 ; k < 6 ; k ++ ) { I [ k + 6 * k ] = 1 ; } jd4ezcvle4 (
kkedrh1goh , I_p ) ; for ( k = 0 ; k < 6 ; k ++ ) { for ( i = 0 ; i < 6 ; i
++ ) { tmp [ k + 6 * i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp [ k
+ 6 * i ] += rtP . R [ 6 * i_p + k ] * 0.5 * rtP . B [ 6 * i_p + i ] ; } } }
for ( k = 0 ; k < 6 ; k ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp_p [ k + 6 *
i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { I_i = tmp [ 6 * i_p + k ] *
kkedrh1goh [ 6 * i + i_p ] + tmp_p [ 6 * i + k ] ; tmp_p [ k + 6 * i ] = I_i
; } } } for ( k = 0 ; k < 6 ; k ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp [ i
+ 6 * k ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp [ i + 6 * k ] +=
I_p [ 6 * i_p + i ] * rtP . Q [ 6 * k + i_p ] ; } } } for ( k = 0 ; k < 6 ; k
++ ) { for ( i = 0 ; i < 6 ; i ++ ) { I_p [ i + 6 * k ] = ( tmp [ 6 * k + i ]
* 2.0 + ( real_T ) I [ 6 * k + i ] ) + p4gjxfn55e [ 6 * k + i ] ; } } for ( k
= 0 ; k < 6 ; k ++ ) { I_i = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { I_i +=
p4gjxfn55e [ 6 * i + k ] * olxmf2elsi [ i ] ; } fa2brwwlb2_p [ k ] =
fa2brwwlb2 [ k ] - I_i ; } for ( k = 0 ; k < 6 ; k ++ ) { I_e [ k ] = 0.0 ;
for ( i = 0 ; i < 6 ; i ++ ) { I_i = I_p [ 6 * i + k ] * fy0kyp3umm [ i ] +
I_e [ k ] ; I_e [ k ] = I_i ; } } for ( k = 0 ; k < 6 ; k ++ ) { fa2brwwlb2_e
[ k ] = ( ( fa2brwwlb2_p [ k ] + I_e [ k ] ) - ilb0lcvng0 [ k ] ) -
ioqjsibok0 [ k ] ; } for ( k = 0 ; k < 6 ; k ++ ) { for ( i = 0 ; i < 6 ; i
++ ) { I_p [ k + 6 * i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { I_p [ k
+ 6 * i ] += rtP . R [ 6 * i_p + k ] * 0.75 * rtP . B [ 6 * i_p + i ] ; } } }
for ( k = 0 ; k < 6 ; k ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp [ k + 6 * i
] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { I_i = I_p [ 6 * i_p + k ] *
kkedrh1goh [ 6 * i + i_p ] + tmp [ 6 * i + k ] ; tmp [ k + 6 * i ] = I_i ; }
} } for ( k = 0 ; k < 6 ; k ++ ) { fa2brwwlb2_p [ k ] = 0.0 ; for ( i = 0 ; i
< 6 ; i ++ ) { fa2brwwlb2_p [ k ] += rtP . BBT_inv [ 6 * i + k ] *
fa2brwwlb2_e [ i ] ; } } for ( k = 0 ; k < 6 ; k ++ ) { fa2brwwlb2_e [ k ] =
0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { I_i = tmp [ 6 * i + k ] * fy0kyp3umm [ i
] + fa2brwwlb2_e [ k ] ; fa2brwwlb2_e [ k ] = I_i ; } } for ( k = 0 ; k < 6 ;
k ++ ) { I_i = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { I_i += tmp_p [ 6 * i + k
] * fy0kyp3umm [ i ] ; } localB -> jb4t0dt15b [ k ] = ( fa2brwwlb2_p [ k ] -
fa2brwwlb2_e [ k ] ) + I_i ; } } void j3iimcdkll ( real_T kcuffxjwhs , real_T
mt1y5gzj5r , fkz4aojsrd * localB ) { real_T ABS ; ABS = muDoubleScalarAbs (
mt1y5gzj5r ) ; localB -> gydza50f0o = kcuffxjwhs - mt1y5gzj5r / ( ABS + rtP .
alpha_Slid ) * muDoubleScalarSqrt ( ABS ) * rtP . k1o ; } void ibkgszeens (
real_T nrguswsx3t , bzcun1m1ez * localB ) { localB -> h0xntzw5zb = nrguswsx3t
/ ( muDoubleScalarAbs ( nrguswsx3t ) + rtP . alpha_Slid ) * - rtP . k2o ; }
static void fl1odpwfid ( const real_T a [ 9 ] , real_T c [ 9 ] ) { real_T x [
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
MdlInitialize ( void ) { int32_T i ; memcpy ( & rtX . jod1emscae [ 0 ] , &
rtP . Integrator_IC [ 0 ] , 12U * sizeof ( real_T ) ) ; rtX . h0zdgk0gmo [ 0
] = rtP . Integrator2_IC [ 0 ] ; rtX . d4nsqahaas [ 0 ] = rtP .
Integrator1_IC [ 0 ] ; rtX . h0zdgk0gmo [ 1 ] = rtP . Integrator2_IC [ 1 ] ;
rtX . d4nsqahaas [ 1 ] = rtP . Integrator1_IC [ 1 ] ; rtX . dtrsdauv2w = rtP
. Integrator_IC_bzpo215sgo ; rtX . mba3iviq3e = rtP .
Integrator1_IC_kniptj1kxt ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . p4zavbehwu [
i ] = rtP . Integrator3_IC [ i ] ; rtDW . lh1jhunvsh [ i ] = rtP .
Memory_InitialCondition [ i ] ; rtX . k4rm2q2icw [ i ] = rtP .
Integrator_IC_kjcjwivfdd [ i ] ; rtX . kymqljywk0 [ i ] = rtP .
Integrator1_IC_bfgbvvrang [ i ] ; } memcpy ( & rtX . mcdw1mvklq [ 0 ] , & rtP
. Integrator1_IC_etk5iarzoa [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . mzqqw2gt2r [ 0 ] , & rtP . Integrator_IC_d53cezkjnk [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . ilympk0to1 [ i ] =
rtP . Integrator2_IC_milw2qy4e1 [ i ] ; rtX . kuge0cvnkg [ i ] = rtP .
Integrator3_IC_mvcbk0lpqx [ i ] ; rtDW . ekrugbtxsn [ i ] = rtP .
Memory_InitialCondition_ltjalipc0r [ i ] ; rtX . fqjvdv4ykq [ i ] = rtP .
Integrator_IC_i2crhtqu0w [ i ] ; rtX . nmmu3qxl0s [ i ] = rtP .
Integrator1_IC_og2211l4hi [ i ] ; } memcpy ( & rtX . hlskz0axkk [ 0 ] , & rtP
. Integrator1_IC_ea4j2itlpr [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . mvnt0cytdi [ 0 ] , & rtP . Integrator_IC_lijhdzhcao [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . nsega0fhex [ i ] =
rtP . Integrator2_IC_eshmddcula [ i ] ; } memcpy ( & rtDW . iuen2h2uzw [ 0 ]
, & rtP . Memory_InitialCondition_cltcggngaa [ 0 ] , 12U * sizeof ( real_T )
) ; rtX . ec4fcf3fdu = 0.0 ; rtX . o14hhuay2v = 0.0 ; rtX . hwaaltmfd1 = 0.0
; rtX . o2isawjn1o = 0.0 ; rtX . lgendzn5vu = rtP . Integrator1_IC_cysw5lmkvd
; rtX . libflrt1jq = rtP . Integrator_IC_mdtcnu4jbd ; } void MdlStart ( void
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
} } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths
[ ] = { 12 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static
int_T rt_ScopeSignalDimensions [ ] = { 12 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_08/Scope" ; static int_T rt_ScopeFrameData [ ] = { 0
} ; static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs [
] = { ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo .
numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
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
rtDW . l4oivvvvyz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "X" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . l4oivvvvyz . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Scope1" ; static
int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . jzvi34rmlr . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . jzvi34rmlr . LoggedData == ( NULL ) )
return ; } { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024
, sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . pnp5xqshxz . Tail = 0
; rtDW . pnp5xqshxz . Head = 0 ; rtDW . pnp5xqshxz . Last = 0 ; rtDW .
pnp5xqshxz . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
ascbhwveph . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
ascbhwveph . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . d2lrwdgt4h . Tail = 0
; rtDW . d2lrwdgt4h . Head = 0 ; rtDW . d2lrwdgt4h . Last = 0 ; rtDW .
d2lrwdgt4h . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
m5ovno0zss . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
m5ovno0zss . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . cfbh3wuutq . Tail = 0
; rtDW . cfbh3wuutq . Head = 0 ; rtDW . cfbh3wuutq . Last = 0 ; rtDW .
cfbh3wuutq . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
dx5bxpzipw . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
dx5bxpzipw . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } {
RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] =
{ 3 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_08/Scope3" ; static int_T rt_ScopeFrameData [ ] = {
0 } ; static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs
[ ] = { ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo
. numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
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
rtDW . ah4xxhij4f . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "e" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . ah4xxhij4f . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Scope5" ; static
int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . hklofzqmuc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . hklofzqmuc . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Scope6" ; static
int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . kie23jbppm . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Euler" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . kie23jbppm . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 4 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 4 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Scope7" ; static
int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . p1ppyahmgi . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "U" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . p1ppyahmgi . LoggedData == ( NULL ) )
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
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Scope10" ; static int_T
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
rtDW . o5lhljo4nd . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData2" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . o5lhljo4nd .
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
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Scope2" ; static int_T
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
rtDW . boirfqbbsy . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData5" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . boirfqbbsy .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 36 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 2 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 , 6 } ; static void * rt_ScopeCurrSigDims
[ ] = { ( NULL ) , ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = {
4 , 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static
char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName
[ ] = "AMFC_Quad_New_01_VelEst_08/Ali/Translational/Scope4" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ;
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
rtDW . cdnjpny0g4 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData7" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . cdnjpny0g4 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 36 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 2 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 6 , 6 } ; static void * rt_ScopeCurrSigDims
[ ] = { ( NULL ) , ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = {
4 , 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static
char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName
[ ] = "AMFC_Quad_New_01_VelEst_08/Ali/Translational/Scope5" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ;
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
rtDW . fo3urnu55t . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData8" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fo3urnu55t .
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
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Scope8" ; static int_T
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
rtDW . eux4lj2epg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData11" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . eux4lj2epg .
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
"AMFC_Quad_New_01_VelEst_08/Ref/Scope1" ; static int_T rt_ScopeFrameData [ ]
= { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . emqqixgbtf . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Ref" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . emqqixgbtf . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 1 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Ref/Scope2" ; static
int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . oxyc14cgy1 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Ref1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . oxyc14cgy1 . LoggedData == ( NULL ) )
return ; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * )
calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 6 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . czs5ji1vj4 . TimePtr = fromwksInfo
-> time ; rtDW . czs5ji1vj4 . DataPtr = fromwksInfo -> data ; rtDW .
czs5ji1vj4 . RSimInfoPtr = fromwksInfo ; } rtDW . phrp5iu5sk . PrevIndex = 0
; { int_T * zcTimeIndices = & rtDW . bpo0twltjm [ 0 ] ; const double *
timePoints = ( double * ) rtDW . czs5ji1vj4 . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 6 - 1 ;
i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ] ) {
zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . mplujf0x0c = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_X" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
gcdvojgmqy . TimePtr = fromwksInfo -> time ; rtDW . gcdvojgmqy . DataPtr =
fromwksInfo -> data ; rtDW . gcdvojgmqy . RSimInfoPtr = fromwksInfo ; } rtDW
. cmi14xe5ec . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Y" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace1_Time0 ; rtDW
. nlbag1a2v1 . TimePtr = fromwksInfo -> time ; rtDW . nlbag1a2v1 . DataPtr =
fromwksInfo -> data ; rtDW . nlbag1a2v1 . RSimInfoPtr = fromwksInfo ; } rtDW
. m5jz3vy2cr . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Z" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace3_Time0 ; rtDW
. k4aipb3zed . TimePtr = fromwksInfo -> time ; rtDW . k4aipb3zed . DataPtr =
fromwksInfo -> data ; rtDW . k4aipb3zed . RSimInfoPtr = fromwksInfo ; } rtDW
. k20gh5ioaa . PrevIndex = 0 ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
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
rt_ScopeBlockName [ ] = "AMFC_Quad_New_01_VelEst_08/Ref/Subsystem/Scope2" ;
static int_T rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static
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
rtDW . k2xhaupeb3 . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Ref_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . k2xhaupeb3 .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 3 } ; static
int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope1" ; static int_T
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
rtDW . dxomvattco . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Acc" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo ,
rt_ScopeBlockName ) ; if ( rtDW . dxomvattco . LoggedData == ( NULL ) )
return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T
rt_ScopeSignalWidths [ ] = { 2 } ; static int_T rt_ScopeSignalNumDimensions [
] = { 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 2 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope2" ; static int_T
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
rtDW . ppz3sujyuc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Rel_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ppz3sujyuc .
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
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope3" ; static int_T
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
rtDW . epkhmc0w1c . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Rel_Vel" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . epkhmc0w1c .
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
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope4" ; static int_T
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
rtDW . ebulbgz34l . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ebulbgz34l .
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
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope5" ; static int_T
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
rtDW . k5k0a3kpu3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . k5k0a3kpu3 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Scope6" ; static int_T
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
rtDW . oyuwqi1alg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Dist" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . oyuwqi1alg . LoggedData == ( NULL ) )
return ; } MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat = false
; void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T kmtjerxmgm ; real_T atqkjbstde ;
real_T fz3qil14fr [ 6 ] ; real_T opwshl1u5c [ 6 ] ; real_T lwsngxyxzq ;
real_T ay0axd0znm ; real_T d4j3bzuvk0 ; real_T hgehlgr1j0 ; real_T m53l5vwqrg
; real_T Rq [ 9 ] ; real_T EXT_PRD [ 3 ] ; real_T F1 ; real_T DP [ 3 ] ;
real_T ipqok5yhgr [ 12 ] ; int32_T i ; real_T tmp [ 9 ] ; real_T tmp_p [ 9 ]
; real_T DP_p [ 3 ] ; real_T tmp_e [ 3 ] ; real_T tmp_i [ 3 ] ; real_T tmp_m
[ 3 ] ; real_T y [ 3 ] ; real_T enycig2xut_idx_3 ; real_T enycig2xut_idx_4 ;
real_T enycig2xut_idx_5 ; real_T enycig2xut_idx_9 ; real_T enycig2xut_idx_10
; real_T enycig2xut_idx_11 ; memcpy ( & rtB . f3qdvlncs2 [ 0 ] , & rtX .
jod1emscae [ 0 ] , 12U * sizeof ( real_T ) ) ; if ( ssGetLogOutput ( rtS ) )
{ StructLogVar * svar = ( StructLogVar * ) rtDW . l4oivvvvyz . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 12 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . f3qdvlncs2 [
0 ] , 12 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar
* ) rtDW . jzvi34rmlr . LoggedData ; LogVar * var = svar -> signals . values
; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar
* ) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
f3qdvlncs2 [ 6 ] ; up0 [ 1 ] = rtB . f3qdvlncs2 [ 7 ] ; up0 [ 2 ] = rtB .
f3qdvlncs2 [ 8 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } {
real_T * * uBuffer = ( real_T * * ) & rtDW . ascbhwveph . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . ascbhwveph . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay_Delay ; rtB . cvaerauj1g = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * tBuffer , * uBuffer , rtDW . pnp5xqshxz . CircularBufSize , & rtDW
. pnp5xqshxz . Last , rtDW . pnp5xqshxz . Tail , rtDW . pnp5xqshxz . Head ,
rtP . TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS
) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . m5ovno0zss . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . m5ovno0zss . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay ; rtB . luue0kfi2i = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * tBuffer , * uBuffer , rtDW . d2lrwdgt4h . CircularBufSize , & rtDW
. d2lrwdgt4h . Last , rtDW . d2lrwdgt4h . Tail , rtDW . d2lrwdgt4h . Head ,
rtP . TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . dx5bxpzipw . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & rtDW . dx5bxpzipw . TUbufferPtrs [ 1 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay2_Delay ; rtB . cp0haf23uy = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * tBuffer , * uBuffer , rtDW . cfbh3wuutq . CircularBufSize , & rtDW
. cfbh3wuutq . Last , rtDW . cfbh3wuutq . Tail , rtDW . cfbh3wuutq . Head ,
rtP . TransportDelay2_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
out1onmc3n [ 0 ] = rtB . cvaerauj1g - rtB . f3qdvlncs2 [ 0 ] ; rtB .
out1onmc3n [ 1 ] = rtB . luue0kfi2i - rtB . f3qdvlncs2 [ 1 ] ; rtB .
out1onmc3n [ 2 ] = rtB . cp0haf23uy - rtB . f3qdvlncs2 [ 2 ] ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
ah4xxhij4f . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
out1onmc3n [ 0 ] ; up0 [ 1 ] = rtB . out1onmc3n [ 1 ] ; up0 [ 2 ] = rtB .
out1onmc3n [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
hklofzqmuc . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
f3qdvlncs2 [ 0 ] ; up0 [ 1 ] = rtB . f3qdvlncs2 [ 1 ] ; up0 [ 2 ] = rtB .
f3qdvlncs2 [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
kie23jbppm . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
f3qdvlncs2 [ 3 ] ; up0 [ 1 ] = rtB . f3qdvlncs2 [ 4 ] ; up0 [ 2 ] = rtB .
f3qdvlncs2 [ 5 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } for (
i = 0 ; i < 6 ; i ++ ) { rtB . iyrr00rsy5 [ i ] = rtX . p4zavbehwu [ i ] ; }
memcpy ( & rtB . dhldqomrw2 [ 0 ] , & rtB . f3qdvlncs2 [ 0 ] , 12U * sizeof (
real_T ) ) ; rtB . jgeak2pmpa [ 0 ] = rtX . h0zdgk0gmo [ 0 ] ; rtB .
fkn5pxjywf [ 0 ] = rtX . d4nsqahaas [ 0 ] ; rtB . jgeak2pmpa [ 1 ] = rtX .
h0zdgk0gmo [ 1 ] ; rtB . fkn5pxjywf [ 1 ] = rtX . d4nsqahaas [ 1 ] ;
kmtjerxmgm = rtX . dtrsdauv2w ; atqkjbstde = rtP . Gain_Gain * rtX .
mba3iviq3e - rtB . dhldqomrw2 [ 2 ] ; j3iimcdkll ( kmtjerxmgm , atqkjbstde ,
& rtB . j2zidd3tqj ) ; enycig2xut_idx_3 = rtB . dhldqomrw2 [ 3 ] ;
enycig2xut_idx_4 = rtB . dhldqomrw2 [ 4 ] ; enycig2xut_idx_5 = rtB .
dhldqomrw2 [ 5 ] ; enycig2xut_idx_9 = rtB . dhldqomrw2 [ 9 ] ;
enycig2xut_idx_10 = rtB . dhldqomrw2 [ 10 ] ; enycig2xut_idx_11 = rtB .
dhldqomrw2 [ 11 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . eja0y2gles [ i ] = rtDW . lh1jhunvsh [ i ] ; } } rtB .
bgofqzyuag [ 0 ] = rtB . cvaerauj1g ; rtB . bgofqzyuag [ 1 ] = rtB .
luue0kfi2i ; rtB . bgofqzyuag [ 2 ] = rtB . cp0haf23uy ; rtB . j5d2rfynpz [ 0
] = rtB . jgeak2pmpa [ 0 ] ; rtB . j5d2rfynpz [ 3 ] = rtB . fkn5pxjywf [ 0 ]
; rtB . bgofqzyuag [ 3 ] = rtB . eja0y2gles [ 0 ] ; rtB . j5d2rfynpz [ 1 ] =
rtB . jgeak2pmpa [ 1 ] ; rtB . j5d2rfynpz [ 4 ] = rtB . fkn5pxjywf [ 1 ] ;
rtB . bgofqzyuag [ 4 ] = rtB . eja0y2gles [ 1 ] ; rtB . j5d2rfynpz [ 2 ] =
rtB . dhldqomrw2 [ 2 ] ; rtB . j5d2rfynpz [ 5 ] = rtB . j2zidd3tqj .
gydza50f0o ; rtB . bgofqzyuag [ 5 ] = rtB . eja0y2gles [ 2 ] ; for ( i = 0 ;
i < 6 ; i ++ ) { rtB . hyspkccycp [ i ] = rtB . bgofqzyuag [ i ] - rtB .
j5d2rfynpz [ i ] ; rtB . ncyc1gpaj2 [ i ] = rtB . iyrr00rsy5 [ i ] + rtB .
hyspkccycp [ i ] ; fz3qil14fr [ i ] = rtX . k4rm2q2icw [ i ] ; rtB .
mqwm4nfdap [ i ] = rtX . kymqljywk0 [ i ] - rtB . bgofqzyuag [ i ] ; }
k5z0pc1ypp ( fz3qil14fr , rtB . mqwm4nfdap , & rtB . cvltowsf2b ) ; memcpy (
& rtB . pnzkimrl2h [ 0 ] , & rtX . mcdw1mvklq [ 0 ] , 36U * sizeof ( real_T )
) ; memcpy ( & rtB . fjffiex4ix [ 0 ] , & rtX . mzqqw2gt2r [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . c05vhcs2pf [ i ] =
rtX . ilympk0to1 [ i ] ; } l2lj4cmfck ( rtB . ncyc1gpaj2 , rtB . iyrr00rsy5 ,
rtB . cvltowsf2b . ao4ocy3oo3 , rtB . pnzkimrl2h , rtB . fjffiex4ix , rtB .
c05vhcs2pf , rtB . j5d2rfynpz , & rtB . lxb4grs0ty ) ; F1 =
muDoubleScalarSqrt ( ( rtB . lxb4grs0ty . jb4t0dt15b [ 3 ] * rtB . lxb4grs0ty
. jb4t0dt15b [ 3 ] + rtB . lxb4grs0ty . jb4t0dt15b [ 4 ] * rtB . lxb4grs0ty .
jb4t0dt15b [ 4 ] ) + rtB . lxb4grs0ty . jb4t0dt15b [ 5 ] * rtB . lxb4grs0ty .
jb4t0dt15b [ 5 ] ) ; rtB . ksdh1okcet [ 0 ] = muDoubleScalarAsin (
muDoubleScalarMin ( muDoubleScalarMax ( ( 0.0 * rtB . lxb4grs0ty . jb4t0dt15b
[ 3 ] - rtB . lxb4grs0ty . jb4t0dt15b [ 4 ] ) / ( F1 + 0.001 ) , - 1.0 ) ,
1.0 ) ) ; rtB . ksdh1okcet [ 1 ] = muDoubleScalarAtan ( ( 0.0 * rtB .
lxb4grs0ty . jb4t0dt15b [ 4 ] + rtB . lxb4grs0ty . jb4t0dt15b [ 3 ] ) / ( rtB
. lxb4grs0ty . jb4t0dt15b [ 5 ] + 0.001 ) ) ; rtB . ksdh1okcet [ 2 ] = 0.0 ;
rtB . it5y34mzxt = F1 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . m2sfecaklo [ i ]
= rtX . kuge0cvnkg [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i =
0 ; i < 6 ; i ++ ) { rtB . oidskutggb [ i ] = rtDW . ekrugbtxsn [ i ] ; } }
rtB . fgqxwi1chj [ 0 ] = enycig2xut_idx_3 ; rtB . fgqxwi1chj [ 3 ] =
enycig2xut_idx_9 ; rtB . fz3gjqjow4 [ 0 ] = rtB . ksdh1okcet [ 0 ] ; rtB .
fz3gjqjow4 [ 3 ] = rtB . oidskutggb [ 0 ] ; rtB . fgqxwi1chj [ 1 ] =
enycig2xut_idx_4 ; rtB . fgqxwi1chj [ 4 ] = enycig2xut_idx_10 ; rtB .
fz3gjqjow4 [ 1 ] = rtB . ksdh1okcet [ 1 ] ; rtB . fz3gjqjow4 [ 4 ] = rtB .
oidskutggb [ 1 ] ; rtB . fgqxwi1chj [ 2 ] = enycig2xut_idx_5 ; rtB .
fgqxwi1chj [ 5 ] = enycig2xut_idx_11 ; rtB . fz3gjqjow4 [ 2 ] = rtB .
ksdh1okcet [ 2 ] ; rtB . fz3gjqjow4 [ 5 ] = rtB . oidskutggb [ 2 ] ; for ( i
= 0 ; i < 6 ; i ++ ) { rtB . b4h3ks3r0d [ i ] = rtB . fz3gjqjow4 [ i ] - rtB
. fgqxwi1chj [ i ] ; rtB . o2eyjfo1wi [ i ] = rtB . m2sfecaklo [ i ] + rtB .
b4h3ks3r0d [ i ] ; opwshl1u5c [ i ] = rtX . fqjvdv4ykq [ i ] ; rtB .
m0blghypsp [ i ] = rtX . nmmu3qxl0s [ i ] - rtB . fz3gjqjow4 [ i ] ; }
k5z0pc1ypp ( opwshl1u5c , rtB . m0blghypsp , & rtB . paq4dzeup4 ) ; memcpy (
& rtB . es2yapuiac [ 0 ] , & rtX . hlskz0axkk [ 0 ] , 36U * sizeof ( real_T )
) ; memcpy ( & rtB . ix2okivzvw [ 0 ] , & rtX . mvnt0cytdi [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . mghhh4y54x [ i ] =
rtX . nsega0fhex [ i ] ; } l2lj4cmfck ( rtB . o2eyjfo1wi , rtB . m2sfecaklo ,
rtB . paq4dzeup4 . ao4ocy3oo3 , rtB . es2yapuiac , rtB . ix2okivzvw , rtB .
mghhh4y54x , rtB . fgqxwi1chj , & rtB . l1rejasabs ) ; for ( i = 0 ; i < 4 ;
i ++ ) { rtB . oflhugxayb [ i ] = 0.0 ; rtB . oflhugxayb [ i ] += rtP . RM_1
[ i ] * rtB . it5y34mzxt ; rtB . oflhugxayb [ i ] += rtP . RM_1 [ i + 4 ] *
rtB . l1rejasabs . jb4t0dt15b [ 3 ] ; rtB . oflhugxayb [ i ] += rtP . RM_1 [
i + 8 ] * rtB . l1rejasabs . jb4t0dt15b [ 4 ] ; rtB . oflhugxayb [ i ] += rtP
. RM_1 [ i + 12 ] * rtB . l1rejasabs . jb4t0dt15b [ 5 ] ; rtB . oflhugxayb [
i ] = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB . oflhugxayb [ i ] ) ) ; }
if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW
. p1ppyahmgi . LoggedData ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 4 ] ; up0 [ 0 ] = rtB .
oflhugxayb [ 0 ] ; up0 [ 1 ] = rtB . oflhugxayb [ 1 ] ; up0 [ 2 ] = rtB .
oflhugxayb [ 2 ] ; up0 [ 3 ] = rtB . oflhugxayb [ 3 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
o4x1a0lhdq ( rtB . o2eyjfo1wi , rtB . mghhh4y54x , rtB . es2yapuiac , & rtB .
n11qfveosl ) ; jiqhbaps0d ( rtB . es2yapuiac , rtB . ix2okivzvw , & rtB .
jr4hvs211j ) ; pqkbkv225c ( rtB . m0blghypsp , & rtB . jrhbb2xk4n ) ;
hdagumznar ( rtB . o2eyjfo1wi , rtB . fgqxwi1chj , rtB . es2yapuiac , rtB .
ix2okivzvw , & rtB . cwezlbfqfz ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW
. o5lhljo4nd . LoggedData ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( &
up0 [ 0 ] , & rtB . ncyc1gpaj2 [ 0 ] , 6 * sizeof ( real_T ) ) ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . boirfqbbsy .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. c05vhcs2pf [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } o4x1a0lhdq ( rtB . ncyc1gpaj2 , rtB . c05vhcs2pf , rtB
. pnzkimrl2h , & rtB . ca4s31r1o4 ) ; if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . cdnjpny0g4 . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 36 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . fjffiex4ix [
0 ] , 36 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar
* ) rtDW . fo3urnu55t . LoggedData ; LogVar * var = svar -> signals . values
; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar
* ) svar -> time , & locTime , 0 ) ; } { real_T up0 [ 36 ] ; ( void ) memcpy
( & up0 [ 0 ] , & rtB . pnzkimrl2h [ 0 ] , 36 * sizeof ( real_T ) ) ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . eux4lj2epg .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 6 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB
. cvltowsf2b . ao4ocy3oo3 [ 0 ] , 6 * sizeof ( real_T ) ) ; rt_UpdateLogVar (
( LogVar * ) var , up0 , 0 ) ; } } hdagumznar ( rtB . ncyc1gpaj2 , rtB .
j5d2rfynpz , rtB . pnzkimrl2h , rtB . fjffiex4ix , & rtB . ipiqttfm4x ) ;
jiqhbaps0d ( rtB . pnzkimrl2h , rtB . fjffiex4ix , & rtB . ffhxpulbso ) ;
pqkbkv225c ( rtB . mqwm4nfdap , & rtB . pg0yucqphr ) ; enycig2xut_idx_3 =
ssGetT ( rtS ) ; Rq [ 0 ] = muDoubleScalarCos ( rtB . f3qdvlncs2 [ 5 ] ) *
muDoubleScalarCos ( rtB . f3qdvlncs2 [ 4 ] ) ; Rq [ 3 ] = muDoubleScalarCos (
rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB . f3qdvlncs2 [ 4 ] ) *
muDoubleScalarSin ( rtB . f3qdvlncs2 [ 3 ] ) + - muDoubleScalarSin ( rtB .
f3qdvlncs2 [ 5 ] ) * muDoubleScalarCos ( rtB . f3qdvlncs2 [ 3 ] ) ; Rq [ 6 ]
= muDoubleScalarCos ( rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB .
f3qdvlncs2 [ 4 ] ) * muDoubleScalarCos ( rtB . f3qdvlncs2 [ 3 ] ) +
muDoubleScalarSin ( rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB .
f3qdvlncs2 [ 3 ] ) ; Rq [ 1 ] = muDoubleScalarSin ( rtB . f3qdvlncs2 [ 5 ] )
* muDoubleScalarCos ( rtB . f3qdvlncs2 [ 4 ] ) ; Rq [ 4 ] = muDoubleScalarSin
( rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB . f3qdvlncs2 [ 4 ] ) *
muDoubleScalarSin ( rtB . f3qdvlncs2 [ 3 ] ) + muDoubleScalarCos ( rtB .
f3qdvlncs2 [ 5 ] ) * muDoubleScalarCos ( rtB . f3qdvlncs2 [ 3 ] ) ; Rq [ 7 ]
= muDoubleScalarSin ( rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB .
f3qdvlncs2 [ 4 ] ) * muDoubleScalarCos ( rtB . f3qdvlncs2 [ 3 ] ) + -
muDoubleScalarCos ( rtB . f3qdvlncs2 [ 5 ] ) * muDoubleScalarSin ( rtB .
f3qdvlncs2 [ 3 ] ) ; Rq [ 2 ] = - muDoubleScalarSin ( rtB . f3qdvlncs2 [ 4 ]
) ; Rq [ 5 ] = muDoubleScalarCos ( rtB . f3qdvlncs2 [ 4 ] ) *
muDoubleScalarSin ( rtB . f3qdvlncs2 [ 3 ] ) ; Rq [ 8 ] = muDoubleScalarCos (
rtB . f3qdvlncs2 [ 4 ] ) * muDoubleScalarCos ( rtB . f3qdvlncs2 [ 3 ] ) ; for
( i = 0 ; i < 3 ; i ++ ) { EXT_PRD [ i ] = 0.0 ; DP [ i ] = rtP . J [ i + 6 ]
* rtB . f3qdvlncs2 [ 11 ] + ( rtP . J [ i + 3 ] * rtB . f3qdvlncs2 [ 10 ] +
rtP . J [ i ] * rtB . f3qdvlncs2 [ 9 ] ) ; } EXT_PRD [ 1 ] = - ( rtB .
f3qdvlncs2 [ 9 ] * DP [ 2 ] - rtB . f3qdvlncs2 [ 11 ] * DP [ 0 ] ) ; EXT_PRD
[ 0 ] = rtB . f3qdvlncs2 [ 9 ] * DP [ 1 ] - rtB . f3qdvlncs2 [ 10 ] * DP [ 0
] ; F1 = rtB . oflhugxayb [ 0 ] * rtB . oflhugxayb [ 0 ] * rtP . Kf ;
enycig2xut_idx_4 = rtB . oflhugxayb [ 1 ] * rtB . oflhugxayb [ 1 ] * rtP . Kf
; enycig2xut_idx_5 = rtB . oflhugxayb [ 2 ] * rtB . oflhugxayb [ 2 ] * rtP .
Kf ; enycig2xut_idx_9 = rtB . oflhugxayb [ 3 ] * rtB . oflhugxayb [ 3 ] * rtP
. Kf ; enycig2xut_idx_10 = ( ( F1 + enycig2xut_idx_4 ) + enycig2xut_idx_5 ) +
enycig2xut_idx_9 ; for ( i = 0 ; i < 3 ; i ++ ) { DP [ i ] = Rq [ i + 6 ] *
enycig2xut_idx_10 + ( Rq [ i + 3 ] * 0.0 + Rq [ i ] * 0.0 ) ; }
enycig2xut_idx_10 = 1.0 / rtP . M ; enycig2xut_idx_11 = muDoubleScalarSin (
enycig2xut_idx_3 ) ; enycig2xut_idx_3 = muDoubleScalarSin ( enycig2xut_idx_3
) ; tmp [ 0 ] = 1.0 ; tmp [ 3 ] = 0.0 ; tmp [ 6 ] = - muDoubleScalarSin ( rtB
. f3qdvlncs2 [ 4 ] ) ; tmp [ 1 ] = 0.0 ; tmp [ 4 ] = muDoubleScalarCos ( rtB
. f3qdvlncs2 [ 3 ] ) ; tmp [ 7 ] = muDoubleScalarCos ( rtB . f3qdvlncs2 [ 4 ]
) * muDoubleScalarSin ( rtB . f3qdvlncs2 [ 3 ] ) ; tmp [ 2 ] = 0.0 ; tmp [ 5
] = - muDoubleScalarSin ( rtB . f3qdvlncs2 [ 3 ] ) ; tmp [ 8 ] =
muDoubleScalarCos ( rtB . f3qdvlncs2 [ 4 ] ) * muDoubleScalarCos ( rtB .
f3qdvlncs2 [ 3 ] ) ; fl1odpwfid ( tmp , tmp_p ) ; fl1odpwfid ( rtP . J , tmp
) ; DP_p [ 0 ] = DP [ 0 ] ; DP_p [ 1 ] = DP [ 1 ] ; DP_p [ 2 ] = DP [ 2 ] ;
DP [ 0 ] = rtP . M * 0.0 ; DP [ 1 ] = rtP . M * 0.0 ; DP [ 2 ] = rtP . M *
rtP . ge ; tmp_e [ 0 ] = ( enycig2xut_idx_5 - F1 ) * rtP . L ; tmp_e [ 1 ] =
( enycig2xut_idx_9 - enycig2xut_idx_4 ) * rtP . L ; tmp_e [ 2 ] = ( ( rtB .
oflhugxayb [ 0 ] * rtB . oflhugxayb [ 0 ] * rtP . Kt - rtB . oflhugxayb [ 1 ]
* rtB . oflhugxayb [ 1 ] * rtP . Kt ) + rtB . oflhugxayb [ 2 ] * rtB .
oflhugxayb [ 2 ] * rtP . Kt ) - rtB . oflhugxayb [ 3 ] * rtB . oflhugxayb [ 3
] * rtP . Kt ; for ( i = 0 ; i < 3 ; i ++ ) { tmp_i [ i ] = ( tmp_e [ i ] -
rtB . f3qdvlncs2 [ 9 + i ] * rtP . Ka ) - EXT_PRD [ i ] ; y [ i ] = ( ( DP_p
[ i ] - rtB . f3qdvlncs2 [ 6 + i ] * rtP . Kd ) - DP [ i ] ) *
enycig2xut_idx_10 + ( ( Rq [ i + 3 ] * enycig2xut_idx_11 * 0.0 + Rq [ i ] *
enycig2xut_idx_11 * 0.0 ) + Rq [ i + 6 ] * enycig2xut_idx_11 ) ; tmp_m [ i ]
= tmp_p [ i + 6 ] * rtB . f3qdvlncs2 [ 11 ] + ( tmp_p [ i + 3 ] * rtB .
f3qdvlncs2 [ 10 ] + tmp_p [ i ] * rtB . f3qdvlncs2 [ 9 ] ) ; } for ( i = 0 ;
i < 3 ; i ++ ) { rtB . jdqmorg3jr [ i ] = rtB . f3qdvlncs2 [ 6 + i ] ; rtB .
jdqmorg3jr [ i + 3 ] = tmp_m [ i ] ; rtB . jdqmorg3jr [ i + 6 ] = y [ i ] ;
rtB . jdqmorg3jr [ i + 9 ] = ( ( tmp [ i + 3 ] * tmp_i [ 1 ] + tmp [ i ] *
tmp_i [ 0 ] ) + tmp [ i + 6 ] * tmp_i [ 2 ] ) + enycig2xut_idx_3 ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & ipqok5yhgr [ 0 ] , & rtDW .
iuen2h2uzw [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssGetLogOutput ( rtS )
) { StructLogVar * svar = ( StructLogVar * ) rtDW . emqqixgbtf . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . cvaerauj1g ; up0 [ 1 ] = rtB .
luue0kfi2i ; up0 [ 2 ] = rtB . cp0haf23uy ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } rtB . hut5rsdm1t = rtP . Gain_Gain_pqv5poqtm5 * ssGetT
( rtS ) ; rtB . db0sdie5cx = muDoubleScalarSin ( rtP . SineWave_Freq *
ssGetTaskTime ( rtS , 0 ) + rtP . SineWave_Phase ) * rtP . SineWave_Amp + rtP
. SineWave_Bias ; rtB . olp0aypydn = muDoubleScalarSin ( rtP . SineWave1_Freq
* ssGetTaskTime ( rtS , 0 ) + rtP . SineWave1_Phase ) * rtP . SineWave1_Amp +
rtP . SineWave1_Bias ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
oxyc14cgy1 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = 0.0 ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } { real_T * pDataValues
= ( real_T * ) rtDW . czs5ji1vj4 . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . czs5ji1vj4 . TimePtr ; int_T currTimeIndex = rtDW . phrp5iu5sk .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . czs5ji1vj4 . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . phrp5iu5sk . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . hdwtb14kjv =
pDataValues [ currTimeIndex ] ; } else { rtB . hdwtb14kjv = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . bpo0twltjm [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . mplujf0x0c ; int_T zcIdx = zcTimeIndices [ *
zcTimeIndicesIdx ] ; int_T numZcTimes = 2 ; if ( * zcTimeIndicesIdx <
numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [
zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t >
pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices
[ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [ zcIdx ] && (
ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues
[ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 =
pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2
- t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2 =
pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } rtB .
hdwtb14kjv = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } { real_T * pDataValues = ( real_T * ) rtDW . gcdvojgmqy .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . gcdvojgmqy . TimePtr ;
int_T currTimeIndex = rtDW . cmi14xe5ec . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . gcdvojgmqy . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . cmi14xe5ec . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { lwsngxyxzq =
pDataValues [ currTimeIndex ] ; } else { lwsngxyxzq = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; lwsngxyxzq = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . h0vfo44bet = rtP .
Gain_Gain_bttrwertaz * lwsngxyxzq ; { real_T * pDataValues = ( real_T * )
rtDW . nlbag1a2v1 . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
nlbag1a2v1 . TimePtr ; int_T currTimeIndex = rtDW . m5jz3vy2cr . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . nlbag1a2v1 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . m5jz3vy2cr . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { ay0axd0znm =
pDataValues [ currTimeIndex ] ; } else { ay0axd0znm = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ay0axd0znm = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . apsqtgdw2k = rtP . Gain1_Gain *
ay0axd0znm ; { real_T * pDataValues = ( real_T * ) rtDW . k4aipb3zed .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . k4aipb3zed . TimePtr ;
int_T currTimeIndex = rtDW . k20gh5ioaa . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . k4aipb3zed . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . k20gh5ioaa . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { d4j3bzuvk0 =
pDataValues [ currTimeIndex ] ; } else { d4j3bzuvk0 = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; d4j3bzuvk0 = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . niozx0x3bq = ssGetT ( rtS ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . jfw2terd0g = ( rtB . niozx0x3bq > rtP .
Switch_Threshold ) ; } if ( rtDW . jfw2terd0g ) { rtB . mhmxoetwje = rtP .
Gain2_Gain * d4j3bzuvk0 ; rtB . bzt0lwzvse = rtB . mhmxoetwje ; } else { rtB
. bzt0lwzvse = rtP . DesiredPosition4_Value ; } if ( ssGetLogOutput ( rtS ) )
{ StructLogVar * svar = ( StructLogVar * ) rtDW . k2xhaupeb3 . LoggedData [ 0
] ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . h0vfo44bet ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } {
real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . apsqtgdw2k ; rt_UpdateLogVar ( ( LogVar
* ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] =
rtB . bzt0lwzvse ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . hrymkwe4oo [ 0 ] = ipqok5yhgr [ 6 ] -
rtP . Constant2_Value_p1uxhfeofi [ 0 ] ; rtB . hrymkwe4oo [ 1 ] = ipqok5yhgr
[ 7 ] - rtP . Constant2_Value_p1uxhfeofi [ 1 ] ; rtB . hrymkwe4oo [ 2 ] =
ipqok5yhgr [ 8 ] - rtP . Constant2_Value_p1uxhfeofi [ 2 ] ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
dxomvattco . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
hrymkwe4oo [ 0 ] ; up0 [ 1 ] = rtB . hrymkwe4oo [ 1 ] ; up0 [ 2 ] = rtB .
hrymkwe4oo [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } if
( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
ppz3sujyuc . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
jgeak2pmpa [ 0 ] ; up0 [ 1 ] = rtB . jgeak2pmpa [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . epkhmc0w1c . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . fkn5pxjywf [ 0 ] ; up0 [ 1 ] = rtB . fkn5pxjywf
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } rtB . a2l3vjk5kk
[ 0 ] = rtB . dhldqomrw2 [ 0 ] - rtB . jgeak2pmpa [ 0 ] ; rtB . a2l3vjk5kk [
1 ] = rtB . dhldqomrw2 [ 1 ] - rtB . jgeak2pmpa [ 1 ] ; if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . ebulbgz34l .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . a2l3vjk5kk [ 0 ] ;
up0 [ 1 ] = rtB . a2l3vjk5kk [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0
, 0 ) ; } } rtB . bslv0j5s21 [ 0 ] = rtB . dhldqomrw2 [ 6 ] - rtB .
fkn5pxjywf [ 0 ] ; rtB . bslv0j5s21 [ 1 ] = rtB . dhldqomrw2 [ 7 ] - rtB .
fkn5pxjywf [ 1 ] ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . k5k0a3kpu3 . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . bslv0j5s21 [ 0 ] ; up0 [ 1 ] = rtB . bslv0j5s21
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } F1 = rtB .
dhldqomrw2 [ 0 ] - rtP . Constant1_Value_k0amvdt1or [ 0 ] ; enycig2xut_idx_4
= rtB . dhldqomrw2 [ 1 ] - rtP . Constant1_Value_k0amvdt1or [ 1 ] ; rtB .
dlysorqgi3 = F1 * F1 + enycig2xut_idx_4 * enycig2xut_idx_4 ; rtB . dlysorqgi3
= muDoubleScalarSqrt ( rtB . dlysorqgi3 ) ; if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . oyuwqi1alg . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . dlysorqgi3 ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } hgehlgr1j0 = rtX . libflrt1jq ; m53l5vwqrg =
rtP . Gain_Gain_mauqb2akec * rtX . lgendzn5vu - rtB . dlysorqgi3 ; j3iimcdkll
( hgehlgr1j0 , m53l5vwqrg , & rtB . feorxccqpz ) ; ibkgszeens ( m53l5vwqrg ,
& rtB . eg12osul0v ) ; ibkgszeens ( atqkjbstde , & rtB . hpraryzlaj ) ;
enycig2xut_idx_3 = rtB . fkn5pxjywf [ 0 ] - rtP . Constant1_Value_k0amvdt1or
[ 0 ] ; F1 = rtB . jgeak2pmpa [ 0 ] * enycig2xut_idx_3 ; enycig2xut_idx_4 =
enycig2xut_idx_3 ; enycig2xut_idx_3 = rtB . fkn5pxjywf [ 1 ] - rtP .
Constant1_Value_k0amvdt1or [ 1 ] ; F1 += rtB . jgeak2pmpa [ 1 ] *
enycig2xut_idx_3 ; F1 = muDoubleScalarSign ( ( rtB . dlysorqgi3 * rtB .
dlysorqgi3 - ( rtB . jgeak2pmpa [ 0 ] * rtB . jgeak2pmpa [ 0 ] + rtB .
jgeak2pmpa [ 1 ] * rtB . jgeak2pmpa [ 1 ] ) ) * F1 ) * rtP . alpha_P + 1.0 ;
rtB . lipu0dbc2k [ 0 ] = F1 * enycig2xut_idx_4 ; rtB . ab5rfxknmw [ 0 ] = rtB
. hrymkwe4oo [ 0 ] ; rtB . lipu0dbc2k [ 1 ] = F1 * enycig2xut_idx_3 ; rtB .
ab5rfxknmw [ 1 ] = rtB . hrymkwe4oo [ 1 ] ; F1 = muDoubleScalarSign ( ( rtB .
feorxccqpz . gydza50f0o * rtB . feorxccqpz . gydza50f0o - ( rtB . fkn5pxjywf
[ 0 ] * rtB . fkn5pxjywf [ 0 ] + rtB . fkn5pxjywf [ 1 ] * rtB . fkn5pxjywf [
1 ] ) ) * ( rtB . fkn5pxjywf [ 0 ] * rtB . ab5rfxknmw [ 0 ] + rtB .
fkn5pxjywf [ 1 ] * rtB . ab5rfxknmw [ 1 ] ) ) * rtP . alpha_V + 1.0 ; rtB .
ab5rfxknmw [ 0 ] *= F1 ; rtB . ab5rfxknmw [ 1 ] *= F1 ; UNUSED_PARAMETER (
tid ) ; } void MdlUpdate ( int_T tid ) { int32_T i ; { real_T * * uBuffer = (
real_T * * ) & rtDW . ascbhwveph . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & rtDW . ascbhwveph . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . pnp5xqshxz . Head = ( ( rtDW . pnp5xqshxz . Head < (
rtDW . pnp5xqshxz . CircularBufSize - 1 ) ) ? ( rtDW . pnp5xqshxz . Head + 1
) : 0 ) ; if ( rtDW . pnp5xqshxz . Head == rtDW . pnp5xqshxz . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . pnp5xqshxz . CircularBufSize , &
rtDW . pnp5xqshxz . Tail , & rtDW . pnp5xqshxz . Head , & rtDW . pnp5xqshxz .
Last , simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) ,
( boolean_T ) 0 , false , & rtDW . pnp5xqshxz . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . pnp5xqshxz . Head ] = simTime ; ( * uBuffer ) [ rtDW .
pnp5xqshxz . Head ] = rtB . db0sdie5cx ; } { real_T * * uBuffer = ( real_T *
* ) & rtDW . m5ovno0zss . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . m5ovno0zss . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . d2lrwdgt4h . Head = ( ( rtDW . d2lrwdgt4h . Head < ( rtDW .
d2lrwdgt4h . CircularBufSize - 1 ) ) ? ( rtDW . d2lrwdgt4h . Head + 1 ) : 0 )
; if ( rtDW . d2lrwdgt4h . Head == rtDW . d2lrwdgt4h . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . d2lrwdgt4h . CircularBufSize , & rtDW
. d2lrwdgt4h . Tail , & rtDW . d2lrwdgt4h . Head , & rtDW . d2lrwdgt4h . Last
, simTime - rtP . TransportDelay1_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . d2lrwdgt4h . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . d2lrwdgt4h . Head ] = simTime ; ( * uBuffer ) [ rtDW .
d2lrwdgt4h . Head ] = rtB . olp0aypydn ; } { real_T * * uBuffer = ( real_T *
* ) & rtDW . dx5bxpzipw . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . dx5bxpzipw . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . cfbh3wuutq . Head = ( ( rtDW . cfbh3wuutq . Head < ( rtDW .
cfbh3wuutq . CircularBufSize - 1 ) ) ? ( rtDW . cfbh3wuutq . Head + 1 ) : 0 )
; if ( rtDW . cfbh3wuutq . Head == rtDW . cfbh3wuutq . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . cfbh3wuutq . CircularBufSize , & rtDW
. cfbh3wuutq . Tail , & rtDW . cfbh3wuutq . Head , & rtDW . cfbh3wuutq . Last
, simTime - rtP . TransportDelay2_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . cfbh3wuutq . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . cfbh3wuutq . Head ] = simTime ; ( * uBuffer ) [ rtDW .
cfbh3wuutq . Head ] = rtB . hut5rsdm1t ; } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW . lh1jhunvsh [ i ] = rtB . lxb4grs0ty
. jb4t0dt15b [ i ] ; rtDW . ekrugbtxsn [ i ] = rtB . l1rejasabs . jb4t0dt15b
[ i ] ; } memcpy ( & rtDW . iuen2h2uzw [ 0 ] , & rtB . jdqmorg3jr [ 0 ] , 12U
* sizeof ( real_T ) ) ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
int32_T i ; XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
memcpy ( & _rtXdot -> jod1emscae [ 0 ] , & rtB . jdqmorg3jr [ 0 ] , 12U *
sizeof ( real_T ) ) ; _rtXdot -> h0zdgk0gmo [ 0 ] = rtB . lipu0dbc2k [ 0 ] ;
_rtXdot -> d4nsqahaas [ 0 ] = rtB . ab5rfxknmw [ 0 ] ; _rtXdot -> h0zdgk0gmo
[ 1 ] = rtB . lipu0dbc2k [ 1 ] ; _rtXdot -> d4nsqahaas [ 1 ] = rtB .
ab5rfxknmw [ 1 ] ; _rtXdot -> dtrsdauv2w = rtB . hpraryzlaj . h0xntzw5zb ;
_rtXdot -> mba3iviq3e = rtB . j2zidd3tqj . gydza50f0o ; for ( i = 0 ; i < 6 ;
i ++ ) { _rtXdot -> p4zavbehwu [ i ] = rtB . hyspkccycp [ i ] ; _rtXdot ->
k4rm2q2icw [ i ] = rtB . pg0yucqphr . oaqi4nmegi [ i ] ; _rtXdot ->
kymqljywk0 [ i ] = rtB . cvltowsf2b . ao4ocy3oo3 [ i ] ; } memcpy ( & _rtXdot
-> mcdw1mvklq [ 0 ] , & rtB . ffhxpulbso . cxgasfu34l [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> mzqqw2gt2r [ 0 ] , & rtB . ipiqttfm4x .
ejjucyteji [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> ilympk0to1 [ i ] = rtB . ca4s31r1o4 . n54ymdd4p0 [ i ] ; _rtXdot
-> kuge0cvnkg [ i ] = rtB . b4h3ks3r0d [ i ] ; _rtXdot -> fqjvdv4ykq [ i ] =
rtB . jrhbb2xk4n . oaqi4nmegi [ i ] ; _rtXdot -> nmmu3qxl0s [ i ] = rtB .
paq4dzeup4 . ao4ocy3oo3 [ i ] ; } memcpy ( & _rtXdot -> hlskz0axkk [ 0 ] , &
rtB . jr4hvs211j . cxgasfu34l [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> mvnt0cytdi [ 0 ] , & rtB . cwezlbfqfz . ejjucyteji [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> nsega0fhex [
i ] = rtB . n11qfveosl . n54ymdd4p0 [ i ] ; } _rtXdot -> ec4fcf3fdu = 0.0 ;
_rtXdot -> ec4fcf3fdu += rtP . TransferFcn2_A * rtX . ec4fcf3fdu ; _rtXdot ->
ec4fcf3fdu += rtP . Constant_Value ; _rtXdot -> o14hhuay2v = 0.0 ; _rtXdot ->
o14hhuay2v += rtP . TransferFcn3_A * rtX . o14hhuay2v ; _rtXdot -> o14hhuay2v
+= rtP . Constant1_Value ; _rtXdot -> hwaaltmfd1 = 0.0 ; _rtXdot ->
hwaaltmfd1 += rtP . TransferFcn1_A * rtX . hwaaltmfd1 ; _rtXdot -> hwaaltmfd1
+= rtP . Constant2_Value ; _rtXdot -> o2isawjn1o = 0.0 ; _rtXdot ->
o2isawjn1o += rtP . TransferFcn_A * rtX . o2isawjn1o ; _rtXdot -> o2isawjn1o
+= rtB . hdwtb14kjv ; _rtXdot -> lgendzn5vu = rtB . feorxccqpz . gydza50f0o ;
_rtXdot -> libflrt1jq = rtB . eg12osul0v . h0xntzw5zb ; } void MdlProjection
( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; { const double * timePtr = (
double * ) rtDW . czs5ji1vj4 . TimePtr ; int_T * zcTimeIndices = & rtDW .
bpo0twltjm [ 0 ] ; int_T zcTimeIndicesIdx = rtDW . mplujf0x0c ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> c5pv2pnafs = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV -> n0sjedb0f3 = rtB .
niozx0x3bq - rtP . Switch_Threshold ; } void MdlTerminate ( void ) {
rt_TDelayFreeBuf ( rtDW . ascbhwveph . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . m5ovno0zss . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . dx5bxpzipw . TUbufferPtrs [ 0 ] ) ; rt_FREE ( rtDW
. czs5ji1vj4 . RSimInfoPtr ) ; rt_FREE ( rtDW . gcdvojgmqy . RSimInfoPtr ) ;
rt_FREE ( rtDW . nlbag1a2v1 . RSimInfoPtr ) ; rt_FREE ( rtDW . k4aipb3zed .
RSimInfoPtr ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 216 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 158 ) ; ssSetNumBlockIO ( rtS , 63 ) ;
ssSetNumBlockParams ( rtS , 4149 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1399061238U ) ;
ssSetChecksumVal ( rtS , 1 , 1260434799U ) ; ssSetChecksumVal ( rtS , 2 ,
1108173927U ) ; ssSetChecksumVal ( rtS , 3 , 2886202868U ) ; }
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
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
AMFC_Quad_New_01_VelEst_08_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"AMFC_Quad_New_01_VelEst_08" ) ; ssSetPath ( rtS ,
"AMFC_Quad_New_01_VelEst_08" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 360.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 12 , 6 , 2 , 2 , 1 , 1 , 6 , 6 ,
36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 12 , 6 , 2 , 2 , 1 , 1 , 6 , 6 , 36 , 36 , 6
, 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"AMFC_Quad_New_01_VelEst_08/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator2" ,
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Integrator1" ,
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator2/Integrator1"
, "AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Differentiator/Integrator1" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Translational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Differentiator/Integrator1" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator" ,
"AMFC_Quad_New_01_VelEst_08/Ali/Rotational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn2" ,
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn3" ,
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn1" ,
"AMFC_Quad_New_01_VelEst_08/Ref/Transfer Fcn" ,
"AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Integrator1"
, "AMFC_Quad_New_01_VelEst_08/Velocity Estimation/Differentiator1/Integrator"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 ,
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
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo =
{ 23 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) , ( NULL
) , { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 23 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . jod1emscae [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . p4zavbehwu [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . h0zdgk0gmo [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . d4nsqahaas [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . dtrsdauv2w ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . mba3iviq3e ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . k4rm2q2icw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . kymqljywk0 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . mcdw1mvklq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . mzqqw2gt2r [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . ilympk0to1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . kuge0cvnkg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . fqjvdv4ykq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . nmmu3qxl0s [ 0 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . hlskz0axkk [ 0 ] ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . mvnt0cytdi [ 0 ] ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . nsega0fhex [ 0 ] ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . ec4fcf3fdu ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . o14hhuay2v ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . hwaaltmfd1 ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . o2isawjn1o ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . lgendzn5vu ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . libflrt1jq ; }
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
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 216 ] ; static
real_T absTol [ 216 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
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
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 216 ] = { 0U , 0U , 0U ,
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
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 2 ] = { ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 3 ] = { { 3 * sizeof ( real_T ) ,
( char * ) ( & rtB . hrymkwe4oo [ 0 ] ) , ( NULL ) } , { 6 * sizeof ( real_T
) , ( char * ) ( & rtB . oidskutggb [ 0 ] ) , ( NULL ) } , { 6 * sizeof (
real_T ) , ( char * ) ( & rtB . eja0y2gles [ 0 ] ) , ( NULL ) } } ;
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 7.2 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 3 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 2 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1399061238U ) ; ssSetChecksumVal ( rtS , 1 ,
1260434799U ) ; ssSetChecksumVal ( rtS , 2 , 1108173927U ) ; ssSetChecksumVal
( rtS , 3 , 2886202868U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 27 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
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
systemRan [ 26 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
