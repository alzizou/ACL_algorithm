#include "__cf_AMFC_Quad_New_01_VelEst_09.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . ivgrkuetfr
[ 0 ] ) , 0 , 0 , 119 } , { ( char_T * ) ( & rtB . hqeceb1qj5 . o5vw3qgp1n [
0 ] ) , 0 , 0 , 12 } , { ( char_T * ) ( & rtB . hc5s13aofb . bscgwtwcot [ 0 ]
) , 0 , 0 , 18 } , { ( char_T * ) ( & rtB . iz2vhx1had . dy01b2bgnp [ 0 ] ) ,
0 , 0 , 6 } , { ( char_T * ) ( & rtB . fch5gmq0mk . llum1d4imd [ 0 ] ) , 0 ,
0 , 6 } , { ( char_T * ) ( & rtB . m4nweffg3k . c0eitivnzv [ 0 ] ) , 0 , 0 ,
6 } , { ( char_T * ) ( & rtB . lqm3tkmrj0 . bkxow1zaxw [ 0 ] ) , 0 , 0 , 6 }
, { ( char_T * ) ( & rtB . drmxackmon . g3f2ipoicp [ 0 ] ) , 0 , 0 , 36 } , {
( char_T * ) ( & rtB . evmbjc0b4d . agvkxpaya3 [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . ddjji0axxh . b5v3smwxxf [ 0 ] ) , 0 , 0 , 18 } , { (
char_T * ) ( & rtB . dbfm2fggcf . dy01b2bgnp [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . n5z0v3jy3r . agvkxpaya3 [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . dwgomjumxz . llum1d4imd [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . dwyanlti1g . c0eitivnzv [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . kblwc120uj . bkxow1zaxw [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . cnusct4inu . g3f2ipoicp [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . crvoapndv2 . h4nyij0txf [ 0 ] ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtB . esmlujbtbz . ispj2sto2a ) , 0 , 0 , 4 } , { ( char_T * )
( & rtB . p4ycag1e5s . pccs3jrnen ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB .
bmakjzspmx . hfqvj0omua ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . ghv0odgskz
. pccs3jrnen ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . kscttm531o .
hfqvj0omua ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . oxu2odnx00 . o5vw3qgp1n
[ 0 ] ) , 0 , 0 , 12 } , { ( char_T * ) ( & rtB . ne34mblrux . bscgwtwcot [ 0
] ) , 0 , 0 , 18 } , { ( char_T * ) ( & rtB . imeubyypoc . dy01b2bgnp [ 0 ] )
, 0 , 0 , 6 } , { ( char_T * ) ( & rtB . lfdnfksqrv . llum1d4imd [ 0 ] ) , 0
, 0 , 6 } , { ( char_T * ) ( & rtB . pmwvgwx3i3 . c0eitivnzv [ 0 ] ) , 0 , 0
, 6 } , { ( char_T * ) ( & rtB . kwzvd2zz43 . bkxow1zaxw [ 0 ] ) , 0 , 0 , 6
} , { ( char_T * ) ( & rtB . o3xr450ufq . g3f2ipoicp [ 0 ] ) , 0 , 0 , 36 } ,
{ ( char_T * ) ( & rtB . porpvvdkpb . agvkxpaya3 [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . pcmu2rnoht . b5v3smwxxf [ 0 ] ) , 0 , 0 , 18 } , { (
char_T * ) ( & rtB . lfuuj0xy5s . dy01b2bgnp [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . duudknct5v . agvkxpaya3 [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . gxc0uqkvgw . llum1d4imd [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . kwvmxh0kpo . c0eitivnzv [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . ccm3czt3ct . bkxow1zaxw [ 0 ] ) , 0 , 0 , 6 } , { (
char_T * ) ( & rtB . himcwdjdya . g3f2ipoicp [ 0 ] ) , 0 , 0 , 36 } , { (
char_T * ) ( & rtB . opcrukpa55 . h4nyij0txf [ 0 ] ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtB . jqsclsqnve . ispj2sto2a ) , 0 , 0 , 4 } , { ( char_T * )
( & rtDW . ksudpu4fau [ 0 ] ) , 0 , 0 , 54 } , { ( char_T * ) ( & rtDW .
eh14jxkpry . LoggedData ) , 11 , 0 , 51 } , { ( char_T * ) ( & rtDW .
b2wnsubu1l . Tail ) , 10 , 0 , 18 } , { ( char_T * ) ( & rtDW . ata4d5ulcr )
, 8 , 0 , 2 } } ; static DataTypeTransitionTable rtBTransTable = { 43U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . B [ 0 ] ) , 0 , 0 , 5607 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
