#include "__cf_AMFC_Quad_New_01_VelEst_09.h"
#include "rt_logging_mmi.h"
#include "AMFC_Quad_New_01_VelEst_09_capi.h"
#include <math.h>
#include "AMFC_Quad_New_01_VelEst_09.h"
#include "AMFC_Quad_New_01_VelEst_09_private.h"
#include "AMFC_Quad_New_01_VelEst_09_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 6 ;
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
 "slprj\\raccel\\AMFC_Quad_New_01_VelEst_09\\AMFC_Quad_New_01_VelEst_09_Jpattern.mat"
; const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const
int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1
} ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const real_T AMFC_Quad_New_01_VelEst_09_RGND = 0.0 ; B rtB ; X rtX ; DW rtDW
; static SimStruct model_S ; SimStruct * const rtS = & model_S ; static void
cznlyklfj2 ( const real_T x [ 36 ] , real_T y [ 36 ] ) ; static void
l53pcohusk ( const real_T a [ 9 ] , real_T c [ 9 ] ) ;
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
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void amnslaei3h (
const real_T e50pf4sszw [ 6 ] , kdy3j1zqh4 * localB ) { real_T u0 ; u0 =
muDoubleScalarSqrt ( ( e50pf4sszw [ 3 ] * e50pf4sszw [ 3 ] + e50pf4sszw [ 4 ]
* e50pf4sszw [ 4 ] ) + e50pf4sszw [ 5 ] * e50pf4sszw [ 5 ] ) ; localB ->
a3fw5udt1f [ 0 ] = muDoubleScalarAsin ( muDoubleScalarMin ( muDoubleScalarMax
( ( 0.0 * e50pf4sszw [ 3 ] - e50pf4sszw [ 4 ] ) / ( u0 + 0.001 ) , - 1.0 ) ,
1.0 ) ) ; localB -> a3fw5udt1f [ 1 ] = muDoubleScalarAtan ( ( 0.0 *
e50pf4sszw [ 4 ] + e50pf4sszw [ 3 ] ) / ( e50pf4sszw [ 5 ] + 0.001 ) ) ;
localB -> a3fw5udt1f [ 2 ] = 0.0 ; localB -> ispj2sto2a = u0 ; } void
ieqavvskat ( real_T livu2yroti , const real_T fbgglxjc5p [ 6 ] , iasl3yiitj *
localB ) { int32_T i ; for ( i = 0 ; i < 4 ; i ++ ) { localB -> h4nyij0txf [
i ] = 0.0 ; localB -> h4nyij0txf [ i ] += rtP . RM_1 [ i ] * livu2yroti ;
localB -> h4nyij0txf [ i ] += rtP . RM_1 [ i + 4 ] * fbgglxjc5p [ 3 ] ;
localB -> h4nyij0txf [ i ] += rtP . RM_1 [ i + 8 ] * fbgglxjc5p [ 4 ] ;
localB -> h4nyij0txf [ i ] += rtP . RM_1 [ i + 12 ] * fbgglxjc5p [ 5 ] ;
localB -> h4nyij0txf [ i ] = muDoubleScalarSqrt ( muDoubleScalarAbs ( localB
-> h4nyij0txf [ i ] ) ) ; } } void kdakkberg2 ( const real_T dcljw4kfl5 [ 36
] , const real_T cauyn0v1en [ 36 ] , kulrpdeeos * localB ) { real_T
cauyn0v1en_p [ 36 ] ; real_T dcljw4kfl5_p [ 36 ] ; int32_T i ; int32_T i_p ;
int32_T i_e ; real_T dcljw4kfl5_e [ 36 ] ; real_T dcljw4kfl5_i [ 36 ] ;
real_T dcljw4kfl5_m [ 36 ] ; real_T tmp ; for ( i = 0 ; i < 6 ; i ++ ) { for
( i_p = 0 ; i_p < 6 ; i_p ++ ) { cauyn0v1en_p [ i + 6 * i_p ] = 0.0 ;
dcljw4kfl5_p [ i + 6 * i_p ] = 0.0 ; dcljw4kfl5_e [ i + 6 * i_p ] = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { cauyn0v1en_p [ i + 6 * i_p ] += cauyn0v1en [
6 * i_e + i ] * dcljw4kfl5 [ 6 * i_p + i_e ] ; dcljw4kfl5_p [ i + 6 * i_p ]
+= dcljw4kfl5 [ 6 * i_e + i ] * cauyn0v1en [ 6 * i_e + i_p ] ; dcljw4kfl5_e [
i + 6 * i_p ] += dcljw4kfl5 [ 6 * i_e + i ] * rtP . B [ 6 * i_p + i_e ] ; } }
for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { dcljw4kfl5_i [ i + 6 * i_p ] = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { dcljw4kfl5_i [ i + 6 * i_p ] += dcljw4kfl5_e
[ 6 * i_e + i ] * rtP . R [ 6 * i_p + i_e ] ; } } for ( i_p = 0 ; i_p < 6 ;
i_p ++ ) { dcljw4kfl5_m [ i + 6 * i_p ] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e
++ ) { dcljw4kfl5_m [ i + 6 * i_p ] += dcljw4kfl5_i [ 6 * i_e + i ] * rtP . B
[ 6 * i_e + i_p ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp = 0.0 ; for
( i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp += dcljw4kfl5_m [ 6 * i_e + i ] *
dcljw4kfl5 [ 6 * i_p + i_e ] ; } localB -> g3f2ipoicp [ i + 6 * i_p ] = ( (
cauyn0v1en_p [ 6 * i_p + i ] + dcljw4kfl5_p [ 6 * i_p + i ] ) - tmp ) + rtP .
Q [ 6 * i_p + i ] * 2.0 ; } } } void kozwe2mnnv ( const real_T jvql1kixgo [ 6
] , const real_T fnj2jhwto0 [ 6 ] , jfvupiqhd2 * localB ) { int32_T i ;
real_T ABS ; for ( i = 0 ; i < 6 ; i ++ ) { if ( fnj2jhwto0 [ i ] > 0.0 ) {
ABS = fnj2jhwto0 [ i ] ; } else { ABS = - fnj2jhwto0 [ i ] ; } localB ->
bkxow1zaxw [ i ] = muDoubleScalarSqrt ( ABS ) ; localB -> bkxow1zaxw [ i ] =
jvql1kixgo [ i ] - fnj2jhwto0 [ i ] / ( ABS + 0.01 ) * ( rtP . k1 * localB ->
bkxow1zaxw [ i ] ) ; } } void fiuiys43oq ( const real_T ip0bo4bex1 [ 6 ] ,
n4lulc2jbj * localB ) { int32_T i ; for ( i = 0 ; i < 6 ; i ++ ) { if (
ip0bo4bex1 [ i ] > 0.0 ) { localB -> c0eitivnzv [ i ] = ip0bo4bex1 [ i ] ; }
else { localB -> c0eitivnzv [ i ] = - ip0bo4bex1 [ i ] ; } localB ->
c0eitivnzv [ i ] = ip0bo4bex1 [ i ] / ( localB -> c0eitivnzv [ i ] + 0.01 ) *
- rtP . k2 ; } } void biysbmp2xz ( const real_T mnai1cdm33 [ 6 ] , const
real_T oplgbc0pbx [ 6 ] , const real_T psd4hmtlez [ 36 ] , e4oqpa2van *
localB ) { real_T tmp [ 36 ] ; int32_T i ; int32_T i_p ; real_T tmp_p [ 36 ]
; int32_T i_e ; real_T tmp_e [ 6 ] ; real_T tmp_i [ 6 ] ; for ( i_p = 0 ; i_p
< 6 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { tmp [ i + 6 * i_p ] = - rtP .
gamma_1 [ 6 * i_p + i ] ; } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_e [
i_p ] = 0.0 ; tmp_i [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { tmp_p [
i_p + 6 * i ] = 0.0 ; for ( i_e = 0 ; i_e < 6 ; i_e ++ ) { tmp_p [ i_p + 6 *
i ] += tmp [ 6 * i_e + i_p ] * psd4hmtlez [ 6 * i + i_e ] ; } tmp_e [ i_p ]
+= tmp_p [ 6 * i + i_p ] * mnai1cdm33 [ i ] ; tmp_i [ i_p ] += rtP . gamma_1
[ 6 * i + i_p ] * rtP . rho_1 * oplgbc0pbx [ i ] ; } localB -> llum1d4imd [
i_p ] = tmp_e [ i_p ] - tmp_i [ i_p ] ; } } void pb1mfspym2 ( const real_T
ddv0orfitt [ 6 ] , const real_T jjxt3gnz3b [ 6 ] , const real_T kchn0gn052 [
36 ] , const real_T haqnobxofj [ 36 ] , l5vwpehasg * localB ) { real_T
DVa_hat [ 6 ] ; real_T d [ 36 ] ; int32_T j ; real_T b_d [ 6 ] ; real_T tmp [
36 ] ; int32_T i ; real_T tmp_p [ 36 ] ; int32_T i_p ; real_T tmp_e [ 36 ] ;
real_T jjxt3gnz3b_p [ 6 ] ; real_T tmp_i [ 6 ] ; real_T tmp_m [ 6 ] ; memset
( & d [ 0 ] , 0 , 36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) {
d [ j + 6 * j ] = ddv0orfitt [ j ] ; b_d [ j ] = haqnobxofj [ j * 7 ] ; for (
i = 0 ; i < 6 ; i ++ ) { tmp [ i + 6 * j ] = - rtP . gamma_0 [ 6 * j + i ] ;
} } for ( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ; j < 6 ; j ++ ) { tmp_p [ i +
6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_p [ i + 6 * j ] +=
tmp [ 6 * i_p + i ] * kchn0gn052 [ 6 * j + i_p ] ; } } for ( j = 0 ; j < 6 ;
j ++ ) { tmp_e [ i + 6 * j ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
tmp_e [ i + 6 * j ] += tmp_p [ 6 * i_p + i ] * d [ 6 * j + i_p ] ; } }
jjxt3gnz3b_p [ i ] = jjxt3gnz3b [ i ] - ddv0orfitt [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { tmp_i [ i ] = 0.0 ; tmp_m [ i ] = 0.0 ; for ( j = 0 ; j < 6 ;
j ++ ) { tmp_i [ i ] += tmp_e [ 6 * j + i ] * jjxt3gnz3b_p [ j ] ; tmp_m [ i
] += rtP . gamma_0 [ 6 * j + i ] * rtP . rho_0 * b_d [ j ] ; } DVa_hat [ i ]
= tmp_i [ i ] - tmp_m [ i ] ; } memset ( & localB -> agvkxpaya3 [ 0 ] , 0 ,
36U * sizeof ( real_T ) ) ; for ( j = 0 ; j < 6 ; j ++ ) { localB ->
agvkxpaya3 [ j + 6 * j ] = DVa_hat [ j ] ; } } static void cznlyklfj2 ( const
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
] ; } } } } } void b42o4l4dbu ( const real_T d2ag3mnpqt [ 6 ] , const real_T
ihu3vrachc [ 6 ] , const real_T mqx4zow5zx [ 6 ] , const real_T j2l0k22yaw [
36 ] , const real_T pkx4fqxbv4 [ 36 ] , const real_T hkihlbn2te [ 6 ] , const
real_T dfcdpznagw [ 6 ] , h4gxvsmp2l * localB ) { int8_T I [ 36 ] ; int32_T k
; real_T tmp [ 36 ] ; int32_T i ; real_T tmp_p [ 36 ] ; int32_T i_p ; real_T
tmp_e [ 36 ] ; real_T tmp_i [ 36 ] ; real_T I_p [ 36 ] ; real_T mqx4zow5zx_p
[ 6 ] ; real_T I_e [ 6 ] ; real_T tmp_m ; real_T mqx4zow5zx_e [ 6 ] ; for ( i
= 0 ; i < 36 ; i ++ ) { I [ i ] = 0 ; } cznlyklfj2 ( j2l0k22yaw , tmp ) ; for
( k = 0 ; k < 6 ; k ++ ) { I [ k + 6 * k ] = 1 ; for ( i = 0 ; i < 6 ; i ++ )
{ tmp_p [ k + 6 * i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_p [ k
+ 6 * i ] += rtP . R [ 6 * i_p + k ] * 0.5 * rtP . B [ 6 * i_p + i ] ; } }
for ( i = 0 ; i < 6 ; i ++ ) { tmp_e [ k + 6 * i ] = 0.0 ; tmp_i [ k + 6 * i
] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_e [ k + 6 * i ] += tmp_p [
6 * i_p + k ] * j2l0k22yaw [ 6 * i + i_p ] ; tmp_i [ k + 6 * i ] += tmp [ 6 *
i_p + k ] * rtP . Q [ 6 * i + i_p ] ; } } } for ( i = 0 ; i < 6 ; i ++ ) {
tmp_m = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { I_p [ i_p + 6 * i ] = (
tmp_i [ 6 * i + i_p ] * 2.0 + ( real_T ) I [ 6 * i + i_p ] ) + pkx4fqxbv4 [ 6
* i + i_p ] ; tmp_m += pkx4fqxbv4 [ 6 * i_p + i ] * dfcdpznagw [ i_p ] ; }
mqx4zow5zx_p [ i ] = mqx4zow5zx [ i ] - tmp_m ; } for ( i = 0 ; i < 6 ; i ++
) { I_e [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp [ i + 6 * i_p
] = 0.0 ; for ( k = 0 ; k < 6 ; k ++ ) { tmp [ i + 6 * i_p ] += rtP . R [ 6 *
k + i ] * 0.75 * rtP . B [ 6 * k + i_p ] ; } I_e [ i ] += I_p [ 6 * i_p + i ]
* d2ag3mnpqt [ i_p ] ; } mqx4zow5zx_e [ i ] = ( ( mqx4zow5zx_p [ i ] + I_e [
i ] ) - hkihlbn2te [ i ] ) - ihu3vrachc [ i ] ; for ( i_p = 0 ; i_p < 6 ; i_p
++ ) { tmp_p [ i + 6 * i_p ] = 0.0 ; for ( k = 0 ; k < 6 ; k ++ ) { tmp_p [ i
+ 6 * i_p ] += tmp [ 6 * k + i ] * j2l0k22yaw [ 6 * i_p + k ] ; } } } for ( i
= 0 ; i < 6 ; i ++ ) { mqx4zow5zx_p [ i ] = 0.0 ; I_e [ i ] = 0.0 ; tmp_m =
0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmp_m += tmp_e [ 6 * i_p + i ] *
d2ag3mnpqt [ i_p ] ; mqx4zow5zx_p [ i ] += rtP . BBT_inv [ 6 * i_p + i ] *
mqx4zow5zx_e [ i_p ] ; I_e [ i ] += tmp_p [ 6 * i_p + i ] * d2ag3mnpqt [ i_p
] ; } localB -> dy01b2bgnp [ i ] = ( mqx4zow5zx_p [ i ] - I_e [ i ] ) + tmp_m
; } } void iexo3cl4az ( const real_T f3i5jffqte [ 12 ] , const real_T
jr1dba04os [ 3 ] , const real_T iiiqtkubdp [ 6 ] , pz5kvzziwe * localB ) {
int32_T i ; localB -> b5v3smwxxf [ 0 ] = f3i5jffqte [ 3 ] ; localB ->
b5v3smwxxf [ 3 ] = f3i5jffqte [ 9 ] ; localB -> nbc5e1aa4y [ 0 ] = jr1dba04os
[ 0 ] ; localB -> nbc5e1aa4y [ 3 ] = iiiqtkubdp [ 0 ] ; localB -> b5v3smwxxf
[ 1 ] = f3i5jffqte [ 4 ] ; localB -> b5v3smwxxf [ 4 ] = f3i5jffqte [ 10 ] ;
localB -> nbc5e1aa4y [ 1 ] = jr1dba04os [ 1 ] ; localB -> nbc5e1aa4y [ 4 ] =
iiiqtkubdp [ 1 ] ; localB -> b5v3smwxxf [ 2 ] = f3i5jffqte [ 5 ] ; localB ->
b5v3smwxxf [ 5 ] = f3i5jffqte [ 11 ] ; localB -> nbc5e1aa4y [ 2 ] =
jr1dba04os [ 2 ] ; localB -> nbc5e1aa4y [ 5 ] = iiiqtkubdp [ 2 ] ; for ( i =
0 ; i < 6 ; i ++ ) { localB -> kncnn35ehq [ i ] = localB -> nbc5e1aa4y [ i ]
- localB -> b5v3smwxxf [ i ] ; } } void g4uofg33hn ( const real_T lvcypb4frb
[ 12 ] , real_T ivkvzaw2u5 , real_T kh43fny0wn , real_T c1lkdoj21v , const
real_T hrldqeqbae [ 6 ] , kjumluinue * localB ) { int32_T i ; localB ->
idzmiix4px [ 0 ] = ivkvzaw2u5 ; localB -> idzmiix4px [ 1 ] = kh43fny0wn ;
localB -> idzmiix4px [ 2 ] = c1lkdoj21v ; localB -> bscgwtwcot [ 0 ] =
lvcypb4frb [ 0 ] ; localB -> bscgwtwcot [ 3 ] = lvcypb4frb [ 6 ] ; localB ->
idzmiix4px [ 3 ] = hrldqeqbae [ 0 ] ; localB -> bscgwtwcot [ 1 ] = lvcypb4frb
[ 1 ] ; localB -> bscgwtwcot [ 4 ] = lvcypb4frb [ 7 ] ; localB -> idzmiix4px
[ 4 ] = hrldqeqbae [ 1 ] ; localB -> bscgwtwcot [ 2 ] = lvcypb4frb [ 2 ] ;
localB -> bscgwtwcot [ 5 ] = lvcypb4frb [ 8 ] ; localB -> idzmiix4px [ 5 ] =
hrldqeqbae [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { localB -> hjeyr5gjr3 [ i ]
= localB -> idzmiix4px [ i ] - localB -> bscgwtwcot [ i ] ; } } static void
l53pcohusk ( const real_T a [ 9 ] , real_T c [ 9 ] ) { real_T x [ 9 ] ;
int32_T p1 ; int32_T p2 ; int32_T p3 ; real_T absx11 ; real_T absx21 ; real_T
absx31 ; int32_T itmp ; memcpy ( & x [ 0 ] , & a [ 0 ] , 9U * sizeof ( real_T
) ) ; p1 = 0 ; p2 = 3 ; p3 = 6 ; absx11 = muDoubleScalarAbs ( a [ 0 ] ) ;
absx21 = muDoubleScalarAbs ( a [ 1 ] ) ; absx31 = muDoubleScalarAbs ( a [ 2 ]
) ; if ( ( absx21 > absx11 ) && ( absx21 > absx31 ) ) { p1 = 3 ; p2 = 0 ; x [
0 ] = a [ 1 ] ; x [ 1 ] = a [ 0 ] ; x [ 3 ] = a [ 4 ] ; x [ 4 ] = a [ 3 ] ; x
[ 6 ] = a [ 7 ] ; x [ 7 ] = a [ 6 ] ; } else { if ( absx31 > absx11 ) { p1 =
6 ; p3 = 0 ; x [ 0 ] = a [ 2 ] ; x [ 2 ] = a [ 0 ] ; x [ 3 ] = a [ 5 ] ; x [
5 ] = a [ 3 ] ; x [ 6 ] = a [ 8 ] ; x [ 8 ] = a [ 6 ] ; } } absx11 = x [ 1 ]
/ x [ 0 ] ; x [ 1 ] /= x [ 0 ] ; absx21 = x [ 2 ] / x [ 0 ] ; x [ 2 ] /= x [
0 ] ; x [ 4 ] -= absx11 * x [ 3 ] ; x [ 5 ] -= absx21 * x [ 3 ] ; x [ 7 ] -=
absx11 * x [ 6 ] ; x [ 8 ] -= absx21 * x [ 6 ] ; if ( muDoubleScalarAbs ( x [
5 ] ) > muDoubleScalarAbs ( x [ 4 ] ) ) { itmp = p2 ; p2 = p3 ; p3 = itmp ; x
[ 1 ] = absx21 ; x [ 2 ] = absx11 ; absx11 = x [ 4 ] ; x [ 4 ] = x [ 5 ] ; x
[ 5 ] = absx11 ; absx11 = x [ 7 ] ; x [ 7 ] = x [ 8 ] ; x [ 8 ] = absx11 ; }
absx11 = x [ 5 ] / x [ 4 ] ; x [ 5 ] /= x [ 4 ] ; x [ 8 ] -= absx11 * x [ 7 ]
; absx11 = ( x [ 5 ] * x [ 1 ] - x [ 2 ] ) / x [ 8 ] ; absx21 = - ( x [ 7 ] *
absx11 + x [ 1 ] ) / x [ 4 ] ; c [ p1 ] = ( ( 1.0 - x [ 3 ] * absx21 ) - x [
6 ] * absx11 ) / x [ 0 ] ; c [ p1 + 1 ] = absx21 ; c [ p1 + 2 ] = absx11 ;
absx11 = - x [ 5 ] / x [ 8 ] ; absx21 = ( 1.0 - x [ 7 ] * absx11 ) / x [ 4 ]
; c [ p2 ] = - ( x [ 3 ] * absx21 + x [ 6 ] * absx11 ) / x [ 0 ] ; c [ p2 + 1
] = absx21 ; c [ p2 + 2 ] = absx11 ; absx11 = 1.0 / x [ 8 ] ; absx21 = - x [
7 ] * absx11 / x [ 4 ] ; c [ p3 ] = - ( x [ 3 ] * absx21 + x [ 6 ] * absx11 )
/ x [ 0 ] ; c [ p3 + 1 ] = absx21 ; c [ p3 + 2 ] = absx11 ; } void bm4zjztzz5
( const real_T a2poltcxks [ 12 ] , const real_T bip35fcvnk [ 4 ] , real_T
li3son1kwn , ppugmfy3jk * localB ) { real_T Rq [ 9 ] ; real_T EXT_PRD [ 3 ] ;
real_T F1 ; real_T F2 ; real_T F3 ; real_T F4 ; real_T DP [ 3 ] ; real_T x ;
real_T b_x ; real_T tmp [ 9 ] ; real_T tmp_p [ 9 ] ; int32_T i ; real_T DP_p
[ 3 ] ; real_T tmp_e [ 3 ] ; real_T tmp_i [ 3 ] ; real_T tmp_m [ 3 ] ; real_T
y [ 3 ] ; real_T tmp_g ; Rq [ 0 ] = muDoubleScalarCos ( a2poltcxks [ 5 ] ) *
muDoubleScalarCos ( a2poltcxks [ 4 ] ) ; Rq [ 3 ] = muDoubleScalarCos (
a2poltcxks [ 5 ] ) * muDoubleScalarSin ( a2poltcxks [ 4 ] ) *
muDoubleScalarSin ( a2poltcxks [ 3 ] ) + - muDoubleScalarSin ( a2poltcxks [ 5
] ) * muDoubleScalarCos ( a2poltcxks [ 3 ] ) ; Rq [ 6 ] = muDoubleScalarCos (
a2poltcxks [ 5 ] ) * muDoubleScalarSin ( a2poltcxks [ 4 ] ) *
muDoubleScalarCos ( a2poltcxks [ 3 ] ) + muDoubleScalarSin ( a2poltcxks [ 5 ]
) * muDoubleScalarSin ( a2poltcxks [ 3 ] ) ; Rq [ 1 ] = muDoubleScalarSin (
a2poltcxks [ 5 ] ) * muDoubleScalarCos ( a2poltcxks [ 4 ] ) ; Rq [ 4 ] =
muDoubleScalarSin ( a2poltcxks [ 5 ] ) * muDoubleScalarSin ( a2poltcxks [ 4 ]
) * muDoubleScalarSin ( a2poltcxks [ 3 ] ) + muDoubleScalarCos ( a2poltcxks [
5 ] ) * muDoubleScalarCos ( a2poltcxks [ 3 ] ) ; Rq [ 7 ] = muDoubleScalarSin
( a2poltcxks [ 5 ] ) * muDoubleScalarSin ( a2poltcxks [ 4 ] ) *
muDoubleScalarCos ( a2poltcxks [ 3 ] ) + - muDoubleScalarCos ( a2poltcxks [ 5
] ) * muDoubleScalarSin ( a2poltcxks [ 3 ] ) ; Rq [ 2 ] = - muDoubleScalarSin
( a2poltcxks [ 4 ] ) ; Rq [ 5 ] = muDoubleScalarCos ( a2poltcxks [ 4 ] ) *
muDoubleScalarSin ( a2poltcxks [ 3 ] ) ; Rq [ 8 ] = muDoubleScalarCos (
a2poltcxks [ 4 ] ) * muDoubleScalarCos ( a2poltcxks [ 3 ] ) ; for ( i = 0 ; i
< 3 ; i ++ ) { EXT_PRD [ i ] = 0.0 ; DP [ i ] = rtP . J [ i + 6 ] *
a2poltcxks [ 11 ] + ( rtP . J [ i + 3 ] * a2poltcxks [ 10 ] + rtP . J [ i ] *
a2poltcxks [ 9 ] ) ; } EXT_PRD [ 1 ] = - ( a2poltcxks [ 9 ] * DP [ 2 ] -
a2poltcxks [ 11 ] * DP [ 0 ] ) ; EXT_PRD [ 0 ] = a2poltcxks [ 9 ] * DP [ 1 ]
- a2poltcxks [ 10 ] * DP [ 0 ] ; F1 = bip35fcvnk [ 0 ] * bip35fcvnk [ 0 ] *
rtP . Kf ; F2 = bip35fcvnk [ 1 ] * bip35fcvnk [ 1 ] * rtP . Kf ; F3 =
bip35fcvnk [ 2 ] * bip35fcvnk [ 2 ] * rtP . Kf ; F4 = bip35fcvnk [ 3 ] *
bip35fcvnk [ 3 ] * rtP . Kf ; tmp_g = ( ( F1 + F2 ) + F3 ) + F4 ; for ( i = 0
; i < 3 ; i ++ ) { DP [ i ] = Rq [ i + 6 ] * tmp_g + ( Rq [ i + 3 ] * 0.0 +
Rq [ i ] * 0.0 ) ; } tmp_g = 1.0 / rtP . M ; x = muDoubleScalarSin (
li3son1kwn ) ; b_x = muDoubleScalarSin ( li3son1kwn ) ; tmp [ 0 ] = 1.0 ; tmp
[ 3 ] = 0.0 ; tmp [ 6 ] = - muDoubleScalarSin ( a2poltcxks [ 4 ] ) ; tmp [ 1
] = 0.0 ; tmp [ 4 ] = muDoubleScalarCos ( a2poltcxks [ 3 ] ) ; tmp [ 7 ] =
muDoubleScalarCos ( a2poltcxks [ 4 ] ) * muDoubleScalarSin ( a2poltcxks [ 3 ]
) ; tmp [ 2 ] = 0.0 ; tmp [ 5 ] = - muDoubleScalarSin ( a2poltcxks [ 3 ] ) ;
tmp [ 8 ] = muDoubleScalarCos ( a2poltcxks [ 4 ] ) * muDoubleScalarCos (
a2poltcxks [ 3 ] ) ; l53pcohusk ( tmp , tmp_p ) ; l53pcohusk ( rtP . J , tmp
) ; DP_p [ 0 ] = DP [ 0 ] ; DP_p [ 1 ] = DP [ 1 ] ; DP_p [ 2 ] = DP [ 2 ] ;
DP [ 0 ] = rtP . M * 0.0 ; DP [ 1 ] = rtP . M * 0.0 ; DP [ 2 ] = rtP . M *
rtP . ge ; tmp_e [ 0 ] = ( F3 - F1 ) * rtP . L ; tmp_e [ 1 ] = ( F4 - F2 ) *
rtP . L ; tmp_e [ 2 ] = ( ( bip35fcvnk [ 0 ] * bip35fcvnk [ 0 ] * rtP . Kt -
bip35fcvnk [ 1 ] * bip35fcvnk [ 1 ] * rtP . Kt ) + bip35fcvnk [ 2 ] *
bip35fcvnk [ 2 ] * rtP . Kt ) - bip35fcvnk [ 3 ] * bip35fcvnk [ 3 ] * rtP .
Kt ; for ( i = 0 ; i < 3 ; i ++ ) { tmp_i [ i ] = ( tmp_e [ i ] - a2poltcxks
[ 9 + i ] * rtP . Ka ) - EXT_PRD [ i ] ; y [ i ] = ( ( DP_p [ i ] -
a2poltcxks [ 6 + i ] * rtP . Kd ) - DP [ i ] ) * tmp_g + ( ( Rq [ i + 3 ] * x
* 0.0 + Rq [ i ] * x * 0.0 ) + Rq [ i + 6 ] * x ) ; tmp_m [ i ] = tmp_p [ i +
6 ] * a2poltcxks [ 11 ] + ( tmp_p [ i + 3 ] * a2poltcxks [ 10 ] + tmp_p [ i ]
* a2poltcxks [ 9 ] ) ; } for ( i = 0 ; i < 3 ; i ++ ) { localB -> o5vw3qgp1n
[ i ] = a2poltcxks [ 6 + i ] ; localB -> o5vw3qgp1n [ i + 3 ] = tmp_m [ i ] ;
localB -> o5vw3qgp1n [ i + 6 ] = y [ i ] ; localB -> o5vw3qgp1n [ i + 9 ] = (
( tmp [ i + 3 ] * tmp_i [ 1 ] + tmp [ i ] * tmp_i [ 0 ] ) + tmp [ i + 6 ] *
tmp_i [ 2 ] ) + b_x ; } } void o2m3ohsxqo ( real_T afohumkv11 , real_T
fvw3nkm4iz , ahvsyvuicz * localB ) { real_T ABS ; ABS = muDoubleScalarAbs (
fvw3nkm4iz ) ; localB -> hfqvj0omua = afohumkv11 - fvw3nkm4iz / ( ABS + rtP .
alpha_Slid ) * muDoubleScalarSqrt ( ABS ) * rtP . k1o ; } void b04przplti (
real_T abcqmfh1zk , l3mc1mdu0x * localB ) { localB -> pccs3jrnen = abcqmfh1zk
/ ( muDoubleScalarAbs ( abcqmfh1zk ) + rtP . alpha_Slid ) * - rtP . k2o ; }
void MdlInitialize ( void ) { int32_T i ; rtX . hdexuidcnz [ 0 ] = rtP .
Integrator2_IC [ 0 ] ; rtX . hdexuidcnz [ 1 ] = rtP . Integrator2_IC [ 1 ] ;
memcpy ( & rtX . abatslrpwk [ 0 ] , & rtP . Integrator_IC [ 0 ] , 12U *
sizeof ( real_T ) ) ; memcpy ( & rtX . egpyww1cv3 [ 0 ] , & rtP .
Integrator_IC_au2dj45vgj [ 0 ] , 12U * sizeof ( real_T ) ) ; rtX . asa03nz13i
[ 0 ] = rtP . Integrator1_IC [ 0 ] ; rtX . asa03nz13i [ 1 ] = rtP .
Integrator1_IC [ 1 ] ; rtX . jrqisqyvic = rtP . Integrator_IC_bzpo215sgo ;
rtX . dydxhc42vx = rtP . Integrator1_IC_kniptj1kxt ; for ( i = 0 ; i < 6 ; i
++ ) { rtX . homekiakrv [ i ] = rtP . Integrator3_IC [ i ] ; rtDW .
ksudpu4fau [ i ] = rtP . Memory_InitialCondition [ i ] ; rtX . kr4xkk5p2d [ i
] = rtP . Integrator_IC_kjcjwivfdd [ i ] ; rtX . p2h3nxwrp4 [ i ] = rtP .
Integrator1_IC_bfgbvvrang [ i ] ; } memcpy ( & rtX . oek5xqhibl [ 0 ] , & rtP
. Integrator1_IC_etk5iarzoa [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . nvdaad4uoo [ 0 ] , & rtP . Integrator_IC_d53cezkjnk [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . ddja0xcub2 [ i ] =
rtP . Integrator2_IC_milw2qy4e1 [ i ] ; rtX . omm0cczmsf [ i ] = rtP .
Integrator3_IC_mvcbk0lpqx [ i ] ; rtDW . knl5mpgsrd [ i ] = rtP .
Memory_InitialCondition_ltjalipc0r [ i ] ; rtX . jwhqqfdfph [ i ] = rtP .
Integrator_IC_i2crhtqu0w [ i ] ; rtX . gbuoa3kpzy [ i ] = rtP .
Integrator1_IC_og2211l4hi [ i ] ; } memcpy ( & rtX . jgzdfwki50 [ 0 ] , & rtP
. Integrator1_IC_ea4j2itlpr [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . b40vzf5iri [ 0 ] , & rtP . Integrator_IC_lijhdzhcao [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . kddg05jdkv [ i ] =
rtP . Integrator2_IC_eshmddcula [ i ] ; } rtX . mleszyt3ph = 0.0 ; rtX .
pqfuc02dbp = 0.0 ; rtX . hprn5xyvyd = 0.0 ; rtX . pcbcrzvlqc = 0.0 ; for ( i
= 0 ; i < 12 ; i ++ ) { rtDW . g0rrq0apzs [ i ] = rtP .
Memory_InitialCondition_cltcggngaa [ i ] ; rtDW . aauqgom500 [ i ] = rtP .
Memory_InitialCondition_ihnyqfqp54 ; } rtX . imqeuuioz0 = rtP .
Integrator1_IC_cysw5lmkvd ; rtX . f21hx01p2a = rtP . Integrator_IC_mdtcnu4jbd
; for ( i = 0 ; i < 6 ; i ++ ) { rtX . a0rpvvfbdg [ i ] = rtP .
Integrator3_IC_nyxzwevmz0 [ i ] ; rtDW . hkoqfk3gpr [ i ] = rtP .
Memory_InitialCondition_ogj5j113sv [ i ] ; rtX . ihuse34h2m [ i ] = rtP .
Integrator_IC_i3pypvjz4s [ i ] ; rtX . gh1xa20c4q [ i ] = rtP .
Integrator1_IC_lyrbs4mryj [ i ] ; } memcpy ( & rtX . bqotilpnhf [ 0 ] , & rtP
. Integrator1_IC_aondaic4tn [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . cndsbhy3yw [ 0 ] , & rtP . Integrator_IC_dn1v3y4i5t [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . leuxkrpbqz [ i ] =
rtP . Integrator2_IC_eq0rr2lar5 [ i ] ; rtX . nzsjppno45 [ i ] = rtP .
Integrator3_IC_oqmkotgcvb [ i ] ; rtDW . l3xxd05qkk [ i ] = rtP .
Memory_InitialCondition_dew5rdr00k [ i ] ; rtX . afi4gqi4rj [ i ] = rtP .
Integrator_IC_ow1ezrd30j [ i ] ; rtX . bwrj1l0x0q [ i ] = rtP .
Integrator1_IC_l4ui1a44g1 [ i ] ; } memcpy ( & rtX . ibhve1q3yt [ 0 ] , & rtP
. Integrator1_IC_dwmkl32mdn [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
rtX . kfyvmtxfyr [ 0 ] , & rtP . Integrator_IC_puc2fkypqe [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtX . e3hflsxbnx [ i ] =
rtP . Integrator2_IC_pkgbdnqjyc [ i ] ; } rtX . pojcnbxabt = 0.0 ; rtX .
ngpl5i0ij4 = 0.0 ; rtX . iqx41iju4f = 0.0 ; rtX . lszq1tgyze = 0.0 ; } void
MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const
char * errorCreatingOSigstreamManager = ( NULL ) ; const char *
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
"AMFC_Quad_New_01_VelEst_09/Agent/Scope" ; static int_T rt_ScopeFrameData [ ]
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
rtDW . eh14jxkpry . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ScopeData1" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . eh14jxkpry .
LoggedData == ( NULL ) ) return ; } { { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . b2wnsubu1l . Tail = 0 ; rtDW . b2wnsubu1l . Head = 0 ; rtDW .
b2wnsubu1l . Last = 0 ; rtDW . b2wnsubu1l . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . ftwma3npp0 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
ftwma3npp0 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . lxjlqbqfhh . Tail = 0
; rtDW . lxjlqbqfhh . Head = 0 ; rtDW . lxjlqbqfhh . Last = 0 ; rtDW .
lxjlqbqfhh . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
emkvxxu5kw . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
emkvxxu5kw . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . fsebzkjcav . Tail = 0
; rtDW . fsebzkjcav . Head = 0 ; rtDW . fsebzkjcav . Last = 0 ; rtDW .
fsebzkjcav . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
ikb4keconr . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
ikb4keconr . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } {
RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] =
{ 3 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Agent/Scope1" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . jhpavj442h . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_e" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jhpavj442h .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Scope3" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . dbrb4job1l . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . dbrb4job1l .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Scope4" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . pw1fr2aeqv . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Euler" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pw1fr2aeqv .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Scope5" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . jon4oo2kgm . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Vel" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jon4oo2kgm .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Scope6" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . bpfscmb3y2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Omega" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . bpfscmb3y2 .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 4 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 4 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1
] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Agent/Scope7" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . d2eq1qne2f . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_U" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . d2eq1qne2f .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 4 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 4 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1
] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Scope1" ; static int_T
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
rtDW . j3huo2xvys . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_MotorSpeed" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . j3huo2xvys .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Scope1" ; static int_T
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
rtDW . p4sgzkj20f . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Ref" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . p4sgzkj20f .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Scope2" ; static int_T
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
rtDW . dvrntr3mzm . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Ref1" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . dvrntr3mzm . LoggedData == ( NULL ) )
return ; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * )
calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 6 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . pvuv30ujfg . TimePtr = fromwksInfo
-> time ; rtDW . pvuv30ujfg . DataPtr = fromwksInfo -> data ; rtDW .
pvuv30ujfg . RSimInfoPtr = fromwksInfo ; } rtDW . edcbzf0yn0 . PrevIndex = 0
; { int_T * zcTimeIndices = & rtDW . hn2dovhdxs [ 0 ] ; const double *
timePoints = ( double * ) rtDW . pvuv30ujfg . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 6 - 1 ;
i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ] ) {
zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . ldylaj45rj = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_X" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
df5c2nfbgg . TimePtr = fromwksInfo -> time ; rtDW . df5c2nfbgg . DataPtr =
fromwksInfo -> data ; rtDW . df5c2nfbgg . RSimInfoPtr = fromwksInfo ; } rtDW
. pnnerq5f2i . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Y" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace1_Time0 ; rtDW
. n1ay2gmo0o . TimePtr = fromwksInfo -> time ; rtDW . n1ay2gmo0o . DataPtr =
fromwksInfo -> data ; rtDW . n1ay2gmo0o . RSimInfoPtr = fromwksInfo ; } rtDW
. exnemuedsi . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Z" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0 ; fromwksInfo -> nDataPoints
= 601 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace3_Time0 ; rtDW
. pjpkrcvyhb . TimePtr = fromwksInfo -> time ; rtDW . pjpkrcvyhb . DataPtr =
fromwksInfo -> data ; rtDW . pjpkrcvyhb . RSimInfoPtr = fromwksInfo ; } rtDW
. ayaahgomzc . PrevIndex = 0 ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
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
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Subsystem/Scope2" ; static int_T
rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ;
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
rtDW . g4djpfw4yq . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Ref_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . g4djpfw4yq .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 2 } ; static
int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope1" ; static int_T
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
rtDW . eu2d5e54n4 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Est_Rel_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . eu2d5e54n4 .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope2" ; static int_T
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
rtDW . nvpfdb2hmo . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Est_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . nvpfdb2hmo .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope3" ; static int_T
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
rtDW . earmeghfsf . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Est_Rel_Vel" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . earmeghfsf .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope4" ; static int_T
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
rtDW . bb1yh35qnp . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Est_Vel" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . bb1yh35qnp .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 3 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope5" ; static int_T
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
rtDW . l4liyn0zrr . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Agent_Rel_Acc" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . l4liyn0zrr .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope6" ; static int_T
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
rtDW . hjrvfzz0ar . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Pos_est_err" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . hjrvfzz0ar .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope7" ; static int_T
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
rtDW . ekl3igs5tb . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Vel_est_err" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ekl3igs5tb .
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
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Scope8" ; static int_T
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
rtDW . o3rktodv2z . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Dist" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . o3rktodv2z . LoggedData == ( NULL ) )
return ; } { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024
, sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . autydayctb . Tail = 0
; rtDW . autydayctb . Head = 0 ; rtDW . autydayctb . Last = 0 ; rtDW .
autydayctb . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput_bw2s5ogtcl ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . fzezo0tjjd . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
fzezo0tjjd . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . cctjnquf0p . Tail = 0
; rtDW . cctjnquf0p . Head = 0 ; rtDW . cctjnquf0p . Last = 0 ; rtDW .
cctjnquf0p . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_ctmwtl3hbr ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . nashv3gsf0 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
nashv3gsf0 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . npknkce1d5 . Tail = 0
; rtDW . npknkce1d5 . Head = 0 ; rtDW . npknkce1d5 . Last = 0 ; rtDW .
npknkce1d5 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay2_InitOutput_ddz2iqhful ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . lwvvduadv2 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
lwvvduadv2 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } {
RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] =
{ 3 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 3 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] =
{ SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Beacon/Scope1" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . pskx1pep5n . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_e" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pskx1pep5n .
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
"AMFC_Quad_New_01_VelEst_09/Beacon/Scope2" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . jozpq0htbq . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_Euler" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . jozpq0htbq .
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
"AMFC_Quad_New_01_VelEst_09/Beacon/Scope3" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . msfllwrq11 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_Pos" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . msfllwrq11 .
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
"AMFC_Quad_New_01_VelEst_09/Beacon/Scope4" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . lkmyovzpp0 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_Vel" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . lkmyovzpp0 .
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
"AMFC_Quad_New_01_VelEst_09/Beacon/Scope5" ; static int_T rt_ScopeFrameData [
] = { 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . l2kwb1e0rl . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_Omega" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . l2kwb1e0rl .
LoggedData == ( NULL ) ) return ; } { RTWLogSignalInfo rt_ScopeSignalInfo ;
static int_T rt_ScopeSignalWidths [ ] = { 4 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 4 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1
] = { SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] =
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Scope1" ; static int_T
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
rtDW . fntjtmi5ec . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_MotorSpeed" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fntjtmi5ec .
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
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Scope1" ; static int_T
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
rtDW . j2g15onptf . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Beacon_Ref" , 1 , 0 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . j2g15onptf .
LoggedData == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0_bk0ugsj5dc ; fromwksInfo -> nDataPoints = 6 ;
fromwksInfo -> time = ( double * ) rtP . FromWs_Time0_dvongqu3oc ; rtDW .
gq3i5ctc0q . TimePtr = fromwksInfo -> time ; rtDW . gq3i5ctc0q . DataPtr =
fromwksInfo -> data ; rtDW . gq3i5ctc0q . RSimInfoPtr = fromwksInfo ; } rtDW
. awfq5ek0fh . PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . kaqmnwj2wn
[ 0 ] ; const double * timePoints = ( double * ) rtDW . gq3i5ctc0q . TimePtr
; boolean_T justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ;
i < 6 - 1 ; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [
i + 1 ] ) { zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . gytwfjza2q = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "RECT_Z" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace3_Data0_glaft0xfxw ; fromwksInfo ->
nDataPoints = 601 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace3_Time0_arirwmivf2 ; rtDW . lp5ova0wqa . TimePtr = fromwksInfo
-> time ; rtDW . lp5ova0wqa . DataPtr = fromwksInfo -> data ; rtDW .
lp5ova0wqa . RSimInfoPtr = fromwksInfo ; } rtDW . frrqi3axqr . PrevIndex = 0
; } MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat = false ; void
* pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T miytes2tvt ; real_T fv3qsmsc1m ;
real_T mlhduyqdvv [ 6 ] ; real_T bjedpqnxv5 [ 6 ] ; real_T c0hdt0m2zt [ 6 ] ;
real_T m3k2qzxoeh [ 6 ] ; real_T eayozdct2h [ 36 ] ; real_T opibnuyfwc [ 36 ]
; real_T nim53pdrsq [ 6 ] ; real_T nqkcq4q4k4 [ 6 ] ; real_T dmjnaw5ypd [ 6 ]
; real_T oev5zlwych [ 6 ] ; real_T forcphg10y [ 6 ] ; real_T hz5ykiq5lz [ 36
] ; real_T c33vonnmp3 [ 36 ] ; real_T hhfldylj1c [ 6 ] ; real_T l3iey2r12p ;
real_T bi5denbrjj ; real_T emjyhkrctj ; real_T jyyjfylkqx ; real_T iag0cjmzio
; real_T milqzezrm3 ; real_T ovuhprin02 ; real_T hdylao5fn3 ; real_T
cmhkw31uih ; real_T ojod04n21a [ 6 ] ; real_T djo3vwpfxh [ 6 ] ; real_T
f0acp1nsry [ 6 ] ; real_T ayjpbog0d1 [ 6 ] ; real_T k0nhpglyzi [ 36 ] ;
real_T etb2toit4y [ 36 ] ; real_T akbqwmk5wa [ 6 ] ; real_T oo0qjvcdnf [ 6 ]
; real_T iui5uk0vs0 [ 6 ] ; real_T gdcpvaevzs [ 6 ] ; real_T n4mrkjb3g3 [ 6 ]
; real_T ckfpyllpje [ 36 ] ; real_T fovurthzu1 [ 36 ] ; real_T gt3nfieghm [ 6
] ; real_T pdnc4dxnsp ; real_T jgo1pnbqse ; real_T a ; real_T b_a ; real_T
ipqok5yhgr [ 12 ] ; int32_T i ; memcpy ( & rtB . ivgrkuetfr [ 0 ] , & rtX .
abatslrpwk [ 0 ] , 12U * sizeof ( real_T ) ) ; if ( ssGetLogOutput ( rtS ) )
{ StructLogVar * svar = ( StructLogVar * ) rtDW . eh14jxkpry . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 12 ] ; ( void ) memcpy ( & up0 [ 0 ] , & rtB . ivgrkuetfr [
0 ] , 12 * sizeof ( real_T ) ) ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0
) ; } } { real_T * * uBuffer = ( real_T * * ) & rtDW . ftwma3npp0 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ftwma3npp0
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay_Delay ; rtB . jx10qz0y32 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
b2wnsubu1l . CircularBufSize , & rtDW . b2wnsubu1l . Last , rtDW . b2wnsubu1l
. Tail , rtDW . b2wnsubu1l . Head , rtP . TransportDelay_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
emkvxxu5kw . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. emkvxxu5kw . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay1_Delay ; rtB . mgwl4qchuz =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
lxjlqbqfhh . CircularBufSize , & rtDW . lxjlqbqfhh . Last , rtDW . lxjlqbqfhh
. Tail , rtDW . lxjlqbqfhh . Head , rtP . TransportDelay1_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
ikb4keconr . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. ikb4keconr . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay2_Delay ; rtB . g4uzmogaho =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
fsebzkjcav . CircularBufSize , & rtDW . fsebzkjcav . Last , rtDW . fsebzkjcav
. Tail , rtDW . fsebzkjcav . Head , rtP . TransportDelay2_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } rtB . iolwo3nnoi [ 0 ] = rtB . jx10qz0y32 - rtB .
ivgrkuetfr [ 0 ] ; rtB . iolwo3nnoi [ 1 ] = rtB . mgwl4qchuz - rtB .
ivgrkuetfr [ 1 ] ; rtB . iolwo3nnoi [ 2 ] = rtB . g4uzmogaho - rtB .
ivgrkuetfr [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . jhpavj442h . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . iolwo3nnoi [ 0 ] ; up0 [ 1 ] = rtB . iolwo3nnoi
[ 1 ] ; up0 [ 2 ] = rtB . iolwo3nnoi [ 2 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } rtB . fp1jf5ytc0 [ 0 ] = rtX . hdexuidcnz [ 0 ] ; rtB .
fp1jf5ytc0 [ 1 ] = rtX . hdexuidcnz [ 1 ] ; memcpy ( & rtB . etvvsvbtr0 [ 0 ]
, & rtB . ivgrkuetfr [ 0 ] , 12U * sizeof ( real_T ) ) ; memcpy ( & rtB .
lxmuzwnnxk [ 0 ] , & rtX . egpyww1cv3 [ 0 ] , 12U * sizeof ( real_T ) ) ; rtB
. cn0dzpfmb5 [ 0 ] = rtB . fp1jf5ytc0 [ 0 ] + rtB . lxmuzwnnxk [ 0 ] ; rtB .
dlk22jmuti [ 0 ] = rtX . asa03nz13i [ 0 ] ; rtB . f5ibyqhnm5 [ 0 ] = rtB .
dlk22jmuti [ 0 ] + rtB . lxmuzwnnxk [ 6 ] ; rtB . cn0dzpfmb5 [ 1 ] = rtB .
fp1jf5ytc0 [ 1 ] + rtB . lxmuzwnnxk [ 1 ] ; rtB . dlk22jmuti [ 1 ] = rtX .
asa03nz13i [ 1 ] ; rtB . f5ibyqhnm5 [ 1 ] = rtB . dlk22jmuti [ 1 ] + rtB .
lxmuzwnnxk [ 7 ] ; miytes2tvt = rtX . jrqisqyvic ; fv3qsmsc1m = rtP .
Gain_Gain * rtX . dydxhc42vx - rtB . etvvsvbtr0 [ 2 ] ; o2m3ohsxqo (
miytes2tvt , fv3qsmsc1m , & rtB . bmakjzspmx ) ; rtB . nof2skbwsq [ 0 ] = rtB
. cn0dzpfmb5 [ 0 ] ; rtB . nof2skbwsq [ 1 ] = rtB . cn0dzpfmb5 [ 1 ] ; rtB .
nof2skbwsq [ 2 ] = rtB . etvvsvbtr0 [ 2 ] ; rtB . nof2skbwsq [ 3 ] = rtB .
etvvsvbtr0 [ 3 ] ; rtB . nof2skbwsq [ 4 ] = rtB . etvvsvbtr0 [ 4 ] ; rtB .
nof2skbwsq [ 5 ] = rtB . etvvsvbtr0 [ 5 ] ; rtB . nof2skbwsq [ 6 ] = rtB .
f5ibyqhnm5 [ 0 ] ; rtB . nof2skbwsq [ 7 ] = rtB . f5ibyqhnm5 [ 1 ] ; rtB .
nof2skbwsq [ 8 ] = rtB . bmakjzspmx . hfqvj0omua ; rtB . nof2skbwsq [ 9 ] =
rtB . etvvsvbtr0 [ 9 ] ; rtB . nof2skbwsq [ 10 ] = rtB . etvvsvbtr0 [ 10 ] ;
rtB . nof2skbwsq [ 11 ] = rtB . etvvsvbtr0 [ 11 ] ; if ( ssGetLogOutput ( rtS
) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . dbrb4job1l . LoggedData
; LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime
( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 )
; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . ivgrkuetfr [ 0 ] ; up0 [ 1 ] = rtB
. ivgrkuetfr [ 1 ] ; up0 [ 2 ] = rtB . ivgrkuetfr [ 2 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . pw1fr2aeqv . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . ivgrkuetfr [ 3 ] ; up0 [ 1 ] = rtB . ivgrkuetfr
[ 4 ] ; up0 [ 2 ] = rtB . ivgrkuetfr [ 5 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . jon4oo2kgm . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . ivgrkuetfr [ 6 ] ; up0 [ 1 ] = rtB . ivgrkuetfr
[ 7 ] ; up0 [ 2 ] = rtB . ivgrkuetfr [ 8 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . bpfscmb3y2 . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . ivgrkuetfr [ 9 ] ; up0 [ 1 ] = rtB . ivgrkuetfr
[ 10 ] ; up0 [ 2 ] = rtB . ivgrkuetfr [ 11 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } for ( i = 0 ; i < 6 ; i ++ ) { mlhduyqdvv [ i ] = rtX .
homekiakrv [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . ofqfdlsgnm [ i ] = rtDW . ksudpu4fau [ i ] ; } }
g4uofg33hn ( rtB . nof2skbwsq , rtB . jx10qz0y32 , rtB . mgwl4qchuz , rtB .
g4uzmogaho , rtB . ofqfdlsgnm , & rtB . ne34mblrux ) ; for ( i = 0 ; i < 6 ;
i ++ ) { bjedpqnxv5 [ i ] = mlhduyqdvv [ i ] + rtB . ne34mblrux . hjeyr5gjr3
[ i ] ; c0hdt0m2zt [ i ] = rtX . kr4xkk5p2d [ i ] ; m3k2qzxoeh [ i ] = rtX .
p2h3nxwrp4 [ i ] - rtB . ne34mblrux . idzmiix4px [ i ] ; } kozwe2mnnv (
c0hdt0m2zt , m3k2qzxoeh , & rtB . kwzvd2zz43 ) ; memcpy ( & eayozdct2h [ 0 ]
, & rtX . oek5xqhibl [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
opibnuyfwc [ 0 ] , & rtX . nvdaad4uoo [ 0 ] , 36U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 6 ; i ++ ) { nim53pdrsq [ i ] = rtX . ddja0xcub2 [ i ] ; }
b42o4l4dbu ( bjedpqnxv5 , mlhduyqdvv , rtB . kwzvd2zz43 . bkxow1zaxw ,
eayozdct2h , opibnuyfwc , nim53pdrsq , rtB . ne34mblrux . bscgwtwcot , & rtB
. imeubyypoc ) ; amnslaei3h ( rtB . imeubyypoc . dy01b2bgnp , & rtB .
jqsclsqnve ) ; for ( i = 0 ; i < 6 ; i ++ ) { nqkcq4q4k4 [ i ] = rtX .
omm0cczmsf [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . ozsyjbt0zf [ i ] = rtDW . knl5mpgsrd [ i ] ; } }
iexo3cl4az ( rtB . nof2skbwsq , rtB . jqsclsqnve . a3fw5udt1f , rtB .
ozsyjbt0zf , & rtB . pcmu2rnoht ) ; for ( i = 0 ; i < 6 ; i ++ ) { dmjnaw5ypd
[ i ] = nqkcq4q4k4 [ i ] + rtB . pcmu2rnoht . kncnn35ehq [ i ] ; oev5zlwych [
i ] = rtX . jwhqqfdfph [ i ] ; forcphg10y [ i ] = rtX . gbuoa3kpzy [ i ] -
rtB . pcmu2rnoht . nbc5e1aa4y [ i ] ; } kozwe2mnnv ( oev5zlwych , forcphg10y
, & rtB . ccm3czt3ct ) ; memcpy ( & hz5ykiq5lz [ 0 ] , & rtX . jgzdfwki50 [ 0
] , 36U * sizeof ( real_T ) ) ; memcpy ( & c33vonnmp3 [ 0 ] , & rtX .
b40vzf5iri [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
hhfldylj1c [ i ] = rtX . kddg05jdkv [ i ] ; } b42o4l4dbu ( dmjnaw5ypd ,
nqkcq4q4k4 , rtB . ccm3czt3ct . bkxow1zaxw , hz5ykiq5lz , c33vonnmp3 ,
hhfldylj1c , rtB . pcmu2rnoht . b5v3smwxxf , & rtB . lfuuj0xy5s ) ;
ieqavvskat ( rtB . jqsclsqnve . ispj2sto2a , rtB . lfuuj0xy5s . dy01b2bgnp ,
& rtB . opcrukpa55 ) ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar =
( StructLogVar * ) rtDW . d2eq1qne2f . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 4 ] ; up0 [ 0 ] = rtB . opcrukpa55 . h4nyij0txf [ 0 ] ; up0 [ 1 ] = rtB
. opcrukpa55 . h4nyij0txf [ 1 ] ; up0 [ 2 ] = rtB . opcrukpa55 . h4nyij0txf [
2 ] ; up0 [ 3 ] = rtB . opcrukpa55 . h4nyij0txf [ 3 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . j3huo2xvys . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 4 ] ; up0 [ 0 ] = rtB . opcrukpa55 . h4nyij0txf [ 0 ] ; up0 [ 1 ] = rtB
. opcrukpa55 . h4nyij0txf [ 1 ] ; up0 [ 2 ] = rtB . opcrukpa55 . h4nyij0txf [
2 ] ; up0 [ 3 ] = rtB . opcrukpa55 . h4nyij0txf [ 3 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } kdakkberg2 ( hz5ykiq5lz , c33vonnmp3 , & rtB
. himcwdjdya ) ; fiuiys43oq ( forcphg10y , & rtB . kwvmxh0kpo ) ; biysbmp2xz
( dmjnaw5ypd , hhfldylj1c , hz5ykiq5lz , & rtB . gxc0uqkvgw ) ; pb1mfspym2 (
dmjnaw5ypd , rtB . pcmu2rnoht . b5v3smwxxf , hz5ykiq5lz , c33vonnmp3 , & rtB
. duudknct5v ) ; pb1mfspym2 ( bjedpqnxv5 , rtB . ne34mblrux . bscgwtwcot ,
eayozdct2h , opibnuyfwc , & rtB . porpvvdkpb ) ; kdakkberg2 ( eayozdct2h ,
opibnuyfwc , & rtB . o3xr450ufq ) ; fiuiys43oq ( m3k2qzxoeh , & rtB .
pmwvgwx3i3 ) ; biysbmp2xz ( bjedpqnxv5 , nim53pdrsq , eayozdct2h , & rtB .
lfdnfksqrv ) ; l3iey2r12p = ssGetT ( rtS ) ; bm4zjztzz5 ( rtB . ivgrkuetfr ,
rtB . opcrukpa55 . h4nyij0txf , l3iey2r12p , & rtB . oxu2odnx00 ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & ipqok5yhgr [ 0 ] , & rtDW .
g0rrq0apzs [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssGetLogOutput ( rtS )
) { StructLogVar * svar = ( StructLogVar * ) rtDW . p4sgzkj20f . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . jx10qz0y32 ; up0 [ 1 ] = rtB .
mgwl4qchuz ; up0 [ 2 ] = rtB . g4uzmogaho ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } rtB . l2okftp1nu = rtP . Gain_Gain_pqv5poqtm5 * ssGetT
( rtS ) ; rtB . jfhxiyyt2e = muDoubleScalarSin ( rtP . SineWave_Freq *
ssGetTaskTime ( rtS , 0 ) + rtP . SineWave_Phase ) * rtP . SineWave_Amp + rtP
. SineWave_Bias ; rtB . m45fkguer0 = muDoubleScalarSin ( rtP . SineWave1_Freq
* ssGetTaskTime ( rtS , 0 ) + rtP . SineWave1_Phase ) * rtP . SineWave1_Amp +
rtP . SineWave1_Bias ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
dvrntr3mzm . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = 0.0 ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } } { real_T * pDataValues
= ( real_T * ) rtDW . pvuv30ujfg . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . pvuv30ujfg . TimePtr ; int_T currTimeIndex = rtDW . edcbzf0yn0 .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . pvuv30ujfg . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . edcbzf0yn0 . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . hzr1dfuf5l =
pDataValues [ currTimeIndex ] ; } else { rtB . hzr1dfuf5l = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . hn2dovhdxs [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . ldylaj45rj ; int_T zcIdx = zcTimeIndices [ *
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
hzr1dfuf5l = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } { real_T * pDataValues = ( real_T * ) rtDW . df5c2nfbgg .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . df5c2nfbgg . TimePtr ;
int_T currTimeIndex = rtDW . pnnerq5f2i . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . df5c2nfbgg . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . pnnerq5f2i . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { bi5denbrjj =
pDataValues [ currTimeIndex ] ; } else { bi5denbrjj = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; bi5denbrjj = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . m3xmkbwv00 = rtP .
Gain_Gain_bttrwertaz * bi5denbrjj ; { real_T * pDataValues = ( real_T * )
rtDW . n1ay2gmo0o . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
n1ay2gmo0o . TimePtr ; int_T currTimeIndex = rtDW . exnemuedsi . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . n1ay2gmo0o . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . exnemuedsi . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { emjyhkrctj =
pDataValues [ currTimeIndex ] ; } else { emjyhkrctj = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; emjyhkrctj = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . bzd1lyzgz1 = rtP . Gain1_Gain *
emjyhkrctj ; { real_T * pDataValues = ( real_T * ) rtDW . pjpkrcvyhb .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . pjpkrcvyhb . TimePtr ;
int_T currTimeIndex = rtDW . ayaahgomzc . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . pjpkrcvyhb . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . ayaahgomzc . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { jyyjfylkqx =
pDataValues [ currTimeIndex ] ; } else { jyyjfylkqx = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; jyyjfylkqx = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . lgrmzrtnoa = ssGetT ( rtS ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . ata4d5ulcr = ( rtB . lgrmzrtnoa > rtP .
Switch_Threshold ) ; } if ( rtDW . ata4d5ulcr ) { rtB . pc3poziqbx = rtP .
Gain2_Gain * jyyjfylkqx ; rtB . nnr1ahifvl = rtB . pc3poziqbx ; } else { rtB
. nnr1ahifvl = rtP . DesiredPosition4_Value ; } if ( ssGetLogOutput ( rtS ) )
{ StructLogVar * svar = ( StructLogVar * ) rtDW . g4djpfw4yq . LoggedData [ 0
] ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . m3xmkbwv00 ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } {
real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . bzd1lyzgz1 ; rt_UpdateLogVar ( ( LogVar
* ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] =
rtB . nnr1ahifvl ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
eu2d5e54n4 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
fp1jf5ytc0 [ 0 ] ; up0 [ 1 ] = rtB . fp1jf5ytc0 [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . nvpfdb2hmo . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . cn0dzpfmb5 [ 0 ] ; up0 [ 1 ] = rtB . cn0dzpfmb5
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
earmeghfsf . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB .
dlk22jmuti [ 0 ] ; up0 [ 1 ] = rtB . dlk22jmuti [ 1 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . bb1yh35qnp . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . f5ibyqhnm5 [ 0 ] ; up0 [ 1 ] = rtB . f5ibyqhnm5
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ndl3k25chw [ 0 ] = ipqok5yhgr [ 6 ] -
rtDW . aauqgom500 [ 6 ] ; rtB . ndl3k25chw [ 1 ] = ipqok5yhgr [ 7 ] - rtDW .
aauqgom500 [ 7 ] ; rtB . ndl3k25chw [ 2 ] = ipqok5yhgr [ 8 ] - rtDW .
aauqgom500 [ 8 ] ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . l4liyn0zrr . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . ndl3k25chw [ 0 ] ; up0 [ 1 ] = rtB . ndl3k25chw
[ 1 ] ; up0 [ 2 ] = rtB . ndl3k25chw [ 2 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } } rtB . gslpjnsh5g [ 0 ] = rtB . etvvsvbtr0 [ 0 ] - rtB
. cn0dzpfmb5 [ 0 ] ; rtB . gslpjnsh5g [ 1 ] = rtB . etvvsvbtr0 [ 1 ] - rtB .
cn0dzpfmb5 [ 1 ] ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . hjrvfzz0ar . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 2 ] ; up0 [ 0 ] = rtB . gslpjnsh5g [ 0 ] ; up0 [ 1 ] = rtB . gslpjnsh5g
[ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } rtB . fb2enyqb0z
[ 0 ] = rtB . etvvsvbtr0 [ 6 ] - rtB . f5ibyqhnm5 [ 0 ] ; rtB . fb2enyqb0z [
1 ] = rtB . etvvsvbtr0 [ 7 ] - rtB . f5ibyqhnm5 [ 1 ] ; if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . ekl3igs5tb .
LoggedData ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . fb2enyqb0z [ 0 ] ;
up0 [ 1 ] = rtB . fb2enyqb0z [ 1 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0
, 0 ) ; } } a = rtB . etvvsvbtr0 [ 0 ] - rtB . lxmuzwnnxk [ 0 ] ; b_a = rtB .
etvvsvbtr0 [ 1 ] - rtB . lxmuzwnnxk [ 1 ] ; rtB . o3szt5ur1k = a * a + b_a *
b_a ; rtB . o3szt5ur1k = muDoubleScalarSqrt ( rtB . o3szt5ur1k ) ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
o3rktodv2z . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB .
o3szt5ur1k ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } iag0cjmzio
= rtX . f21hx01p2a ; milqzezrm3 = rtP . Gain_Gain_mauqb2akec * rtX .
imqeuuioz0 - rtB . o3szt5ur1k ; o2m3ohsxqo ( iag0cjmzio , milqzezrm3 , & rtB
. kscttm531o ) ; b04przplti ( milqzezrm3 , & rtB . ghv0odgskz ) ; b04przplti
( fv3qsmsc1m , & rtB . p4ycag1e5s ) ; a = muDoubleScalarSign ( ( rtB .
o3szt5ur1k * rtB . o3szt5ur1k - ( rtB . fp1jf5ytc0 [ 0 ] * rtB . fp1jf5ytc0 [
0 ] + rtB . fp1jf5ytc0 [ 1 ] * rtB . fp1jf5ytc0 [ 1 ] ) ) * ( rtB .
fp1jf5ytc0 [ 0 ] * rtB . dlk22jmuti [ 0 ] + rtB . fp1jf5ytc0 [ 1 ] * rtB .
dlk22jmuti [ 1 ] ) ) * rtP . alpha_P + 1.0 ; rtB . liy3ccyuzf [ 0 ] = a * rtB
. dlk22jmuti [ 0 ] ; rtB . c3o3xjf5wt [ 0 ] = rtB . ndl3k25chw [ 0 ] ; rtB .
liy3ccyuzf [ 1 ] = a * rtB . dlk22jmuti [ 1 ] ; rtB . c3o3xjf5wt [ 1 ] = rtB
. ndl3k25chw [ 1 ] ; a = muDoubleScalarSign ( ( rtB . kscttm531o . hfqvj0omua
* rtB . kscttm531o . hfqvj0omua - ( rtB . dlk22jmuti [ 0 ] * rtB . dlk22jmuti
[ 0 ] + rtB . dlk22jmuti [ 1 ] * rtB . dlk22jmuti [ 1 ] ) ) * ( rtB .
dlk22jmuti [ 0 ] * rtB . c3o3xjf5wt [ 0 ] + rtB . dlk22jmuti [ 1 ] * rtB .
c3o3xjf5wt [ 1 ] ) ) * rtP . alpha_V + 1.0 ; rtB . c3o3xjf5wt [ 0 ] *= a ;
rtB . c3o3xjf5wt [ 1 ] *= a ; { real_T * * uBuffer = ( real_T * * ) & rtDW .
fzezo0tjjd . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. fzezo0tjjd . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . TransportDelay_Delay_mrtq4yly2u ; ovuhprin02 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
autydayctb . CircularBufSize , & rtDW . autydayctb . Last , rtDW . autydayctb
. Tail , rtDW . autydayctb . Head , rtP .
TransportDelay_InitOutput_bw2s5ogtcl , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
f5j3k1cgkz = rtP . Gain1_Gain_lwvfyvhuab * ovuhprin02 ; { real_T * * uBuffer
= ( real_T * * ) & rtDW . nashv3gsf0 . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & rtDW . nashv3gsf0 . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay_l2osw0ocdi ; hdylao5fn3 = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . cctjnquf0p .
CircularBufSize , & rtDW . cctjnquf0p . Last , rtDW . cctjnquf0p . Tail ,
rtDW . cctjnquf0p . Head , rtP . TransportDelay1_InitOutput_ctmwtl3hbr , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } rtB . ejv5n5dh4j = rtP . Gain2_Gain_gy0kebd21j *
hdylao5fn3 ; { real_T * * uBuffer = ( real_T * * ) & rtDW . lwvvduadv2 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . lwvvduadv2
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay2_Delay_dxj4qf2s24 ; cmhkw31uih =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
npknkce1d5 . CircularBufSize , & rtDW . npknkce1d5 . Last , rtDW . npknkce1d5
. Tail , rtDW . npknkce1d5 . Head , rtP .
TransportDelay2_InitOutput_ddz2iqhful , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
gol00soltl = rtP . Gain3_Gain * cmhkw31uih ; rtB . edxclkusat [ 0 ] = rtB .
f5j3k1cgkz - rtB . lxmuzwnnxk [ 0 ] ; rtB . edxclkusat [ 1 ] = rtB .
ejv5n5dh4j - rtB . lxmuzwnnxk [ 1 ] ; rtB . edxclkusat [ 2 ] = rtB .
gol00soltl - rtB . lxmuzwnnxk [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . pskx1pep5n . LoggedData ;
LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . edxclkusat [ 0 ] ; up0 [ 1 ] = rtB .
edxclkusat [ 1 ] ; up0 [ 2 ] = rtB . edxclkusat [ 2 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar
* svar = ( StructLogVar * ) rtDW . jozpq0htbq . LoggedData ; LogVar * var =
svar -> signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . lxmuzwnnxk [ 3 ] ; up0 [ 1 ] = rtB . lxmuzwnnxk
[ 4 ] ; up0 [ 2 ] = rtB . lxmuzwnnxk [ 5 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . msfllwrq11 . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . lxmuzwnnxk [ 0 ] ; up0 [ 1 ] = rtB . lxmuzwnnxk
[ 1 ] ; up0 [ 2 ] = rtB . lxmuzwnnxk [ 2 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . lkmyovzpp0 . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . lxmuzwnnxk [ 6 ] ; up0 [ 1 ] = rtB . lxmuzwnnxk
[ 7 ] ; up0 [ 2 ] = rtB . lxmuzwnnxk [ 8 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . l2kwb1e0rl . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 3 ] ; up0 [ 0 ] = rtB . lxmuzwnnxk [ 9 ] ; up0 [ 1 ] = rtB . lxmuzwnnxk
[ 10 ] ; up0 [ 2 ] = rtB . lxmuzwnnxk [ 11 ] ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } for ( i = 0 ; i < 6 ; i ++ ) { ojod04n21a [ i ] = rtX .
a0rpvvfbdg [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . bu5fouv53z [ i ] = rtDW . hkoqfk3gpr [ i ] ; } }
g4uofg33hn ( rtB . lxmuzwnnxk , rtB . f5j3k1cgkz , rtB . ejv5n5dh4j , rtB .
gol00soltl , rtB . bu5fouv53z , & rtB . hc5s13aofb ) ; for ( i = 0 ; i < 6 ;
i ++ ) { djo3vwpfxh [ i ] = ojod04n21a [ i ] + rtB . hc5s13aofb . hjeyr5gjr3
[ i ] ; f0acp1nsry [ i ] = rtX . ihuse34h2m [ i ] ; ayjpbog0d1 [ i ] = rtX .
gh1xa20c4q [ i ] - rtB . hc5s13aofb . idzmiix4px [ i ] ; } kozwe2mnnv (
f0acp1nsry , ayjpbog0d1 , & rtB . lqm3tkmrj0 ) ; memcpy ( & k0nhpglyzi [ 0 ]
, & rtX . bqotilpnhf [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
etb2toit4y [ 0 ] , & rtX . cndsbhy3yw [ 0 ] , 36U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 6 ; i ++ ) { akbqwmk5wa [ i ] = rtX . leuxkrpbqz [ i ] ; }
b42o4l4dbu ( djo3vwpfxh , ojod04n21a , rtB . lqm3tkmrj0 . bkxow1zaxw ,
k0nhpglyzi , etb2toit4y , akbqwmk5wa , rtB . hc5s13aofb . bscgwtwcot , & rtB
. iz2vhx1had ) ; amnslaei3h ( rtB . iz2vhx1had . dy01b2bgnp , & rtB .
esmlujbtbz ) ; for ( i = 0 ; i < 6 ; i ++ ) { oo0qjvcdnf [ i ] = rtX .
nzsjppno45 [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i <
6 ; i ++ ) { rtB . ftcjn2x21e [ i ] = rtDW . l3xxd05qkk [ i ] ; } }
iexo3cl4az ( rtB . lxmuzwnnxk , rtB . esmlujbtbz . a3fw5udt1f , rtB .
ftcjn2x21e , & rtB . ddjji0axxh ) ; for ( i = 0 ; i < 6 ; i ++ ) { iui5uk0vs0
[ i ] = oo0qjvcdnf [ i ] + rtB . ddjji0axxh . kncnn35ehq [ i ] ; gdcpvaevzs [
i ] = rtX . afi4gqi4rj [ i ] ; n4mrkjb3g3 [ i ] = rtX . bwrj1l0x0q [ i ] -
rtB . ddjji0axxh . nbc5e1aa4y [ i ] ; } kozwe2mnnv ( gdcpvaevzs , n4mrkjb3g3
, & rtB . kblwc120uj ) ; memcpy ( & ckfpyllpje [ 0 ] , & rtX . ibhve1q3yt [ 0
] , 36U * sizeof ( real_T ) ) ; memcpy ( & fovurthzu1 [ 0 ] , & rtX .
kfyvmtxfyr [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
gt3nfieghm [ i ] = rtX . e3hflsxbnx [ i ] ; } b42o4l4dbu ( iui5uk0vs0 ,
oo0qjvcdnf , rtB . kblwc120uj . bkxow1zaxw , ckfpyllpje , fovurthzu1 ,
gt3nfieghm , rtB . ddjji0axxh . b5v3smwxxf , & rtB . dbfm2fggcf ) ;
ieqavvskat ( rtB . esmlujbtbz . ispj2sto2a , rtB . dbfm2fggcf . dy01b2bgnp ,
& rtB . crvoapndv2 ) ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar =
( StructLogVar * ) rtDW . fntjtmi5ec . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 4 ] ; up0 [ 0 ] = rtB . crvoapndv2 . h4nyij0txf [ 0 ] ; up0 [ 1 ] = rtB
. crvoapndv2 . h4nyij0txf [ 1 ] ; up0 [ 2 ] = rtB . crvoapndv2 . h4nyij0txf [
2 ] ; up0 [ 3 ] = rtB . crvoapndv2 . h4nyij0txf [ 3 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; } } kdakkberg2 ( ckfpyllpje , fovurthzu1 , & rtB
. cnusct4inu ) ; fiuiys43oq ( n4mrkjb3g3 , & rtB . dwyanlti1g ) ; biysbmp2xz
( iui5uk0vs0 , gt3nfieghm , ckfpyllpje , & rtB . dwgomjumxz ) ; pb1mfspym2 (
iui5uk0vs0 , rtB . ddjji0axxh . b5v3smwxxf , ckfpyllpje , fovurthzu1 , & rtB
. n5z0v3jy3r ) ; pb1mfspym2 ( djo3vwpfxh , rtB . hc5s13aofb . bscgwtwcot ,
k0nhpglyzi , etb2toit4y , & rtB . evmbjc0b4d ) ; kdakkberg2 ( k0nhpglyzi ,
etb2toit4y , & rtB . drmxackmon ) ; fiuiys43oq ( ayjpbog0d1 , & rtB .
m4nweffg3k ) ; biysbmp2xz ( djo3vwpfxh , akbqwmk5wa , k0nhpglyzi , & rtB .
fch5gmq0mk ) ; pdnc4dxnsp = ssGetT ( rtS ) ; bm4zjztzz5 ( rtB . lxmuzwnnxk ,
rtB . crvoapndv2 . h4nyij0txf , pdnc4dxnsp , & rtB . hqeceb1qj5 ) ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
j2g15onptf . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar
-> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
f5j3k1cgkz ; up0 [ 1 ] = rtB . ejv5n5dh4j ; up0 [ 2 ] = rtB . gol00soltl ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } rtB . e2xua1vi2a = rtP .
Gain_Gain_pjv0l5nu25 * ssGetT ( rtS ) ; rtB . h1dldewdlg = muDoubleScalarSin
( rtP . SineWave_Freq_hkeiim1l54 * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave_Phase_atfet5pyf2 ) * rtP . SineWave_Amp_cqusaijwz1 + rtP .
SineWave_Bias_dhkcw5madh ; rtB . e43dgc14sk = muDoubleScalarSin ( rtP .
SineWave1_Freq_ekxuh2oqwg * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave1_Phase_pvy3avqa4x ) * rtP . SineWave1_Amp_mdrsfgbaur + rtP .
SineWave1_Bias_eubjrqq2u4 ; { real_T * pDataValues = ( real_T * ) rtDW .
gq3i5ctc0q . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . gq3i5ctc0q
. TimePtr ; int_T currTimeIndex = rtDW . awfq5ek0fh . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . gq3i5ctc0q . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . awfq5ek0fh . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . kryicu302t =
pDataValues [ currTimeIndex ] ; } else { rtB . kryicu302t = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . kaqmnwj2wn [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . gytwfjza2q ; int_T zcIdx = zcTimeIndices [ *
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
kryicu302t = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues +=
numPoints ; } } } rtB . jz5340fyqc = ssGetT ( rtS ) ; { real_T * pDataValues
= ( real_T * ) rtDW . lp5ova0wqa . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . lp5ova0wqa . TimePtr ; int_T currTimeIndex = rtDW . frrqi3axqr .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . lp5ova0wqa . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . frrqi3axqr . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { jgo1pnbqse =
pDataValues [ currTimeIndex ] ; } else { jgo1pnbqse = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; jgo1pnbqse = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
c3h4wxu1yg = ( rtB . jz5340fyqc > rtP . Switch_Threshold_isku2iufnm ) ; } if
( rtDW . c3h4wxu1yg ) { rtB . mztx0ubroi = rtP . Gain2_Gain_c2uyk0coml *
jgo1pnbqse ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
int32_T i ; { real_T * * uBuffer = ( real_T * * ) & rtDW . ftwma3npp0 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ftwma3npp0
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW . b2wnsubu1l .
Head = ( ( rtDW . b2wnsubu1l . Head < ( rtDW . b2wnsubu1l . CircularBufSize -
1 ) ) ? ( rtDW . b2wnsubu1l . Head + 1 ) : 0 ) ; if ( rtDW . b2wnsubu1l .
Head == rtDW . b2wnsubu1l . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . b2wnsubu1l . CircularBufSize , & rtDW . b2wnsubu1l . Tail , & rtDW .
b2wnsubu1l . Head , & rtDW . b2wnsubu1l . Last , simTime - rtP .
TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false
, & rtDW . b2wnsubu1l . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
b2wnsubu1l . Head ] = simTime ; ( * uBuffer ) [ rtDW . b2wnsubu1l . Head ] =
rtB . jfhxiyyt2e ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
emkvxxu5kw . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. emkvxxu5kw . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
lxjlqbqfhh . Head = ( ( rtDW . lxjlqbqfhh . Head < ( rtDW . lxjlqbqfhh .
CircularBufSize - 1 ) ) ? ( rtDW . lxjlqbqfhh . Head + 1 ) : 0 ) ; if ( rtDW
. lxjlqbqfhh . Head == rtDW . lxjlqbqfhh . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . lxjlqbqfhh . CircularBufSize , & rtDW
. lxjlqbqfhh . Tail , & rtDW . lxjlqbqfhh . Head , & rtDW . lxjlqbqfhh . Last
, simTime - rtP . TransportDelay1_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . lxjlqbqfhh . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . lxjlqbqfhh . Head ] = simTime ; ( * uBuffer ) [ rtDW .
lxjlqbqfhh . Head ] = rtB . m45fkguer0 ; } { real_T * * uBuffer = ( real_T *
* ) & rtDW . ikb4keconr . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . ikb4keconr . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . fsebzkjcav . Head = ( ( rtDW . fsebzkjcav . Head < ( rtDW .
fsebzkjcav . CircularBufSize - 1 ) ) ? ( rtDW . fsebzkjcav . Head + 1 ) : 0 )
; if ( rtDW . fsebzkjcav . Head == rtDW . fsebzkjcav . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . fsebzkjcav . CircularBufSize , & rtDW
. fsebzkjcav . Tail , & rtDW . fsebzkjcav . Head , & rtDW . fsebzkjcav . Last
, simTime - rtP . TransportDelay2_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . fsebzkjcav . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . fsebzkjcav . Head ] = simTime ; ( * uBuffer ) [ rtDW .
fsebzkjcav . Head ] = rtB . l2okftp1nu ; } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ksudpu4fau [ i ] = rtB . imeubyypoc
. dy01b2bgnp [ i ] ; rtDW . knl5mpgsrd [ i ] = rtB . lfuuj0xy5s . dy01b2bgnp
[ i ] ; } memcpy ( & rtDW . g0rrq0apzs [ 0 ] , & rtB . oxu2odnx00 .
o5vw3qgp1n [ 0 ] , 12U * sizeof ( real_T ) ) ; memcpy ( & rtDW . aauqgom500 [
0 ] , & rtB . hqeceb1qj5 . o5vw3qgp1n [ 0 ] , 12U * sizeof ( real_T ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . fzezo0tjjd . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . fzezo0tjjd . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; rtDW . autydayctb . Head = ( ( rtDW .
autydayctb . Head < ( rtDW . autydayctb . CircularBufSize - 1 ) ) ? ( rtDW .
autydayctb . Head + 1 ) : 0 ) ; if ( rtDW . autydayctb . Head == rtDW .
autydayctb . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
autydayctb . CircularBufSize , & rtDW . autydayctb . Tail , & rtDW .
autydayctb . Head , & rtDW . autydayctb . Last , simTime - rtP .
TransportDelay_Delay_mrtq4yly2u , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . autydayctb . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW
. autydayctb . Head ] = simTime ; ( * uBuffer ) [ rtDW . autydayctb . Head ]
= rtB . h1dldewdlg ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
nashv3gsf0 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. nashv3gsf0 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
cctjnquf0p . Head = ( ( rtDW . cctjnquf0p . Head < ( rtDW . cctjnquf0p .
CircularBufSize - 1 ) ) ? ( rtDW . cctjnquf0p . Head + 1 ) : 0 ) ; if ( rtDW
. cctjnquf0p . Head == rtDW . cctjnquf0p . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . cctjnquf0p . CircularBufSize , & rtDW
. cctjnquf0p . Tail , & rtDW . cctjnquf0p . Head , & rtDW . cctjnquf0p . Last
, simTime - rtP . TransportDelay1_Delay_l2osw0ocdi , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . cctjnquf0p . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . cctjnquf0p . Head ] = simTime ; ( * uBuffer ) [ rtDW .
cctjnquf0p . Head ] = rtB . e43dgc14sk ; } { real_T * * uBuffer = ( real_T *
* ) & rtDW . lwvvduadv2 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . lwvvduadv2 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . npknkce1d5 . Head = ( ( rtDW . npknkce1d5 . Head < ( rtDW .
npknkce1d5 . CircularBufSize - 1 ) ) ? ( rtDW . npknkce1d5 . Head + 1 ) : 0 )
; if ( rtDW . npknkce1d5 . Head == rtDW . npknkce1d5 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . npknkce1d5 . CircularBufSize , & rtDW
. npknkce1d5 . Tail , & rtDW . npknkce1d5 . Head , & rtDW . npknkce1d5 . Last
, simTime - rtP . TransportDelay2_Delay_dxj4qf2s24 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . npknkce1d5 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . npknkce1d5 . Head ] = simTime ; ( * uBuffer ) [ rtDW .
npknkce1d5 . Head ] = rtB . e2xua1vi2a ; } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW . hkoqfk3gpr [ i ] = rtB . iz2vhx1had
. dy01b2bgnp [ i ] ; rtDW . l3xxd05qkk [ i ] = rtB . dbfm2fggcf . dy01b2bgnp
[ i ] ; } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { int32_T i ; XDot
* _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> hdexuidcnz
[ 0 ] = rtB . liy3ccyuzf [ 0 ] ; _rtXdot -> hdexuidcnz [ 1 ] = rtB .
liy3ccyuzf [ 1 ] ; memcpy ( & _rtXdot -> abatslrpwk [ 0 ] , & rtB .
oxu2odnx00 . o5vw3qgp1n [ 0 ] , 12U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> egpyww1cv3 [ 0 ] , & rtB . hqeceb1qj5 . o5vw3qgp1n [ 0 ] , 12U *
sizeof ( real_T ) ) ; _rtXdot -> asa03nz13i [ 0 ] = rtB . c3o3xjf5wt [ 0 ] ;
_rtXdot -> asa03nz13i [ 1 ] = rtB . c3o3xjf5wt [ 1 ] ; _rtXdot -> jrqisqyvic
= rtB . p4ycag1e5s . pccs3jrnen ; _rtXdot -> dydxhc42vx = rtB . bmakjzspmx .
hfqvj0omua ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> homekiakrv [ i ] = rtB
. ne34mblrux . hjeyr5gjr3 [ i ] ; _rtXdot -> kr4xkk5p2d [ i ] = rtB .
pmwvgwx3i3 . c0eitivnzv [ i ] ; _rtXdot -> p2h3nxwrp4 [ i ] = rtB .
kwzvd2zz43 . bkxow1zaxw [ i ] ; } memcpy ( & _rtXdot -> oek5xqhibl [ 0 ] , &
rtB . o3xr450ufq . g3f2ipoicp [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> nvdaad4uoo [ 0 ] , & rtB . porpvvdkpb . agvkxpaya3 [ 0 ] , 36U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> ddja0xcub2 [
i ] = rtB . lfdnfksqrv . llum1d4imd [ i ] ; _rtXdot -> omm0cczmsf [ i ] = rtB
. pcmu2rnoht . kncnn35ehq [ i ] ; _rtXdot -> jwhqqfdfph [ i ] = rtB .
kwvmxh0kpo . c0eitivnzv [ i ] ; _rtXdot -> gbuoa3kpzy [ i ] = rtB .
ccm3czt3ct . bkxow1zaxw [ i ] ; } memcpy ( & _rtXdot -> jgzdfwki50 [ 0 ] , &
rtB . himcwdjdya . g3f2ipoicp [ 0 ] , 36U * sizeof ( real_T ) ) ; memcpy ( &
_rtXdot -> b40vzf5iri [ 0 ] , & rtB . duudknct5v . agvkxpaya3 [ 0 ] , 36U *
sizeof ( real_T ) ) ; _rtXdot -> mleszyt3ph = 0.0 ; _rtXdot -> mleszyt3ph +=
rtP . TransferFcn2_A * rtX . mleszyt3ph ; _rtXdot -> mleszyt3ph += rtP .
Constant_Value ; _rtXdot -> pqfuc02dbp = 0.0 ; _rtXdot -> pqfuc02dbp += rtP .
TransferFcn3_A * rtX . pqfuc02dbp ; _rtXdot -> pqfuc02dbp += rtP .
Constant1_Value ; _rtXdot -> hprn5xyvyd = 0.0 ; _rtXdot -> hprn5xyvyd += rtP
. TransferFcn1_A * rtX . hprn5xyvyd ; _rtXdot -> hprn5xyvyd += rtP .
Constant2_Value ; _rtXdot -> pcbcrzvlqc = 0.0 ; _rtXdot -> pcbcrzvlqc += rtP
. TransferFcn_A * rtX . pcbcrzvlqc ; _rtXdot -> pcbcrzvlqc += rtB .
hzr1dfuf5l ; _rtXdot -> imqeuuioz0 = rtB . kscttm531o . hfqvj0omua ; _rtXdot
-> f21hx01p2a = rtB . ghv0odgskz . pccs3jrnen ; for ( i = 0 ; i < 6 ; i ++ )
{ _rtXdot -> kddg05jdkv [ i ] = rtB . gxc0uqkvgw . llum1d4imd [ i ] ; _rtXdot
-> a0rpvvfbdg [ i ] = rtB . hc5s13aofb . hjeyr5gjr3 [ i ] ; _rtXdot ->
ihuse34h2m [ i ] = rtB . m4nweffg3k . c0eitivnzv [ i ] ; _rtXdot ->
gh1xa20c4q [ i ] = rtB . lqm3tkmrj0 . bkxow1zaxw [ i ] ; } memcpy ( & _rtXdot
-> bqotilpnhf [ 0 ] , & rtB . drmxackmon . g3f2ipoicp [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> cndsbhy3yw [ 0 ] , & rtB . evmbjc0b4d .
agvkxpaya3 [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> leuxkrpbqz [ i ] = rtB . fch5gmq0mk . llum1d4imd [ i ] ; _rtXdot
-> nzsjppno45 [ i ] = rtB . ddjji0axxh . kncnn35ehq [ i ] ; _rtXdot ->
afi4gqi4rj [ i ] = rtB . dwyanlti1g . c0eitivnzv [ i ] ; _rtXdot ->
bwrj1l0x0q [ i ] = rtB . kblwc120uj . bkxow1zaxw [ i ] ; } memcpy ( & _rtXdot
-> ibhve1q3yt [ 0 ] , & rtB . cnusct4inu . g3f2ipoicp [ 0 ] , 36U * sizeof (
real_T ) ) ; memcpy ( & _rtXdot -> kfyvmtxfyr [ 0 ] , & rtB . n5z0v3jy3r .
agvkxpaya3 [ 0 ] , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) {
_rtXdot -> e3hflsxbnx [ i ] = rtB . dwgomjumxz . llum1d4imd [ i ] ; } _rtXdot
-> pojcnbxabt = 0.0 ; _rtXdot -> pojcnbxabt += rtP .
TransferFcn2_A_a0oyqusjcz * rtX . pojcnbxabt ; _rtXdot -> pojcnbxabt += rtP .
Constant_Value_f3fl4m3lns ; _rtXdot -> ngpl5i0ij4 = 0.0 ; _rtXdot ->
ngpl5i0ij4 += rtP . TransferFcn3_A_luwp2lluol * rtX . ngpl5i0ij4 ; _rtXdot ->
ngpl5i0ij4 += rtP . Constant1_Value_bfcgyn3zal ; _rtXdot -> iqx41iju4f = 0.0
; _rtXdot -> iqx41iju4f += rtP . TransferFcn1_A_bowexjz0op * rtX . iqx41iju4f
; _rtXdot -> iqx41iju4f += rtP . Constant2_Value_imre1apqn2 ; _rtXdot ->
lszq1tgyze = 0.0 ; _rtXdot -> lszq1tgyze += rtP . TransferFcn_A_opc1nfp3z4 *
rtX . lszq1tgyze ; _rtXdot -> lszq1tgyze += rtB . kryicu302t ; } void
MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; { const double *
timePtr = ( double * ) rtDW . pvuv30ujfg . TimePtr ; int_T * zcTimeIndices =
& rtDW . hn2dovhdxs [ 0 ] ; int_T zcTimeIndicesIdx = rtDW . ldylaj45rj ; ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> pkwvzyrmwh = ssGetT ( rtS ) -
timePtr [ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV -> dedxn5i5eo =
rtB . lgrmzrtnoa - rtP . Switch_Threshold ; { const double * timePtr = (
double * ) rtDW . gq3i5ctc0q . TimePtr ; int_T * zcTimeIndices = & rtDW .
kaqmnwj2wn [ 0 ] ; int_T zcTimeIndicesIdx = rtDW . gytwfjza2q ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> ilvi0y3uv1 = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV -> c1b3jziwcm = rtB .
jz5340fyqc - rtP . Switch_Threshold_isku2iufnm ; } void MdlTerminate ( void )
{ rt_TDelayFreeBuf ( rtDW . ftwma3npp0 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . emkvxxu5kw . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . ikb4keconr . TUbufferPtrs [ 0 ] ) ; rt_FREE ( rtDW
. pvuv30ujfg . RSimInfoPtr ) ; rt_FREE ( rtDW . df5c2nfbgg . RSimInfoPtr ) ;
rt_FREE ( rtDW . n1ay2gmo0o . RSimInfoPtr ) ; rt_FREE ( rtDW . pjpkrcvyhb .
RSimInfoPtr ) ; rt_TDelayFreeBuf ( rtDW . fzezo0tjjd . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . nashv3gsf0 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . lwvvduadv2 . TUbufferPtrs [ 0 ] ) ; rt_FREE ( rtDW
. gq3i5ctc0q . RSimInfoPtr ) ; rt_FREE ( rtDW . lp5ova0wqa . RSimInfoPtr ) ;
if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 424 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 198 ) ; ssSetNumBlockIO ( rtS , 89 ) ;
ssSetNumBlockParams ( rtS , 5607 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2903976693U ) ;
ssSetChecksumVal ( rtS , 1 , 1265714942U ) ; ssSetChecksumVal ( rtS , 2 ,
460222312U ) ; ssSetChecksumVal ( rtS , 3 , 547042216U ) ; }
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
AMFC_Quad_New_01_VelEst_09_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"AMFC_Quad_New_01_VelEst_09" ) ; ssSetPath ( rtS ,
"AMFC_Quad_New_01_VelEst_09" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 360.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 12 , 2 , 12 , 2 , 1 , 1 , 6 , 6 ,
6 , 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6
, 36 , 36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 12 , 2 , 12 , 2 , 1 , 1 , 6 , 6 , 6 , 36 ,
36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 36 ,
36 , 6 , 6 , 6 , 6 , 36 , 36 , 6 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "AMFC_Quad_New_01_VelEst_09/Agent/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator2" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Integrator1" ,
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Integrator"
,
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator2/Integrator1"
, "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Integrator"
,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Differentiator/Integrator1"
, "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Translational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Differentiator/Integrator1"
, "AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ali/Rotational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn2" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn3" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn1" ,
"AMFC_Quad_New_01_VelEst_09/Agent/Ref/Transfer Fcn" ,
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Integrator1"
,
 "AMFC_Quad_New_01_VelEst_09/Agent/Velocity Estimation/Differentiator1/Integrator"
, "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Integrator"
,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Differentiator/Integrator1"
, "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Translational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator3" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Integrator"
,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Differentiator/Integrator1"
, "AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator1" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ali/Rotational/Integrator2" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn2" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn3" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn1" ,
"AMFC_Quad_New_01_VelEst_09/Beacon/Ref/Transfer Fcn" } ; static const char_T
* rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
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
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 40 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , ( NULL ) , { rt_LoggedStateLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , {
rt_LoggedStateNames } , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert
} ; static void * rt_LoggedStateSignalPtrs [ 40 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . abatslrpwk [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . hdexuidcnz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . egpyww1cv3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . asa03nz13i [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . jrqisqyvic ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . dydxhc42vx ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . homekiakrv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . kr4xkk5p2d [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . p2h3nxwrp4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . oek5xqhibl [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . nvdaad4uoo [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . ddja0xcub2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . omm0cczmsf [ 0 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . jwhqqfdfph [ 0 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . gbuoa3kpzy [ 0 ] ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . jgzdfwki50 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . b40vzf5iri [ 0 ] ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . kddg05jdkv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . mleszyt3ph ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . pqfuc02dbp ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . hprn5xyvyd ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . pcbcrzvlqc ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . imqeuuioz0 ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtX . f21hx01p2a ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtX . a0rpvvfbdg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtX . ihuse34h2m [ 0 ] ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtX . gh1xa20c4q [ 0 ] ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtX . bqotilpnhf [ 0 ] ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtX . cndsbhy3yw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtX . leuxkrpbqz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) & rtX . nzsjppno45 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) & rtX . afi4gqi4rj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 32 ] = ( void * ) & rtX . bwrj1l0x0q [ 0 ] ;
rt_LoggedStateSignalPtrs [ 33 ] = ( void * ) & rtX . ibhve1q3yt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 34 ] = ( void * ) & rtX . kfyvmtxfyr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 35 ] = ( void * ) & rtX . e3hflsxbnx [ 0 ] ;
rt_LoggedStateSignalPtrs [ 36 ] = ( void * ) & rtX . pojcnbxabt ;
rt_LoggedStateSignalPtrs [ 37 ] = ( void * ) & rtX . ngpl5i0ij4 ;
rt_LoggedStateSignalPtrs [ 38 ] = ( void * ) & rtX . iqx41iju4f ;
rt_LoggedStateSignalPtrs [ 39 ] = ( void * ) & rtX . lszq1tgyze ; }
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
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 424 ] ; static
real_T absTol [ 424 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
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
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 424 ] = { 0U , 0U , 0U ,
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
, 0U , 0U } ; static uint8_T zcAttributes [ 4 ] = { ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 5 ] = { { 6 * sizeof ( real_T ) ,
( char * ) ( & rtB . ftcjn2x21e [ 0 ] ) , ( NULL ) } , { 6 * sizeof ( real_T
) , ( char * ) ( & rtB . bu5fouv53z [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . ndl3k25chw [ 0 ] ) , ( NULL ) } , { 6 *
sizeof ( real_T ) , ( char * ) ( & rtB . ozsyjbt0zf [ 0 ] ) , ( NULL ) } , {
6 * sizeof ( real_T ) , ( char * ) ( & rtB . ofqfdlsgnm [ 0 ] ) , ( NULL ) }
} ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 7.2 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 5 ) ; ssSetNonContDerivSigInfos ( rtS ,
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
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 4 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2903976693U ) ; ssSetChecksumVal ( rtS , 1 ,
1265714942U ) ; ssSetChecksumVal ( rtS , 2 , 460222312U ) ; ssSetChecksumVal
( rtS , 3 , 547042216U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 45 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
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
systemRan [ 44 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
