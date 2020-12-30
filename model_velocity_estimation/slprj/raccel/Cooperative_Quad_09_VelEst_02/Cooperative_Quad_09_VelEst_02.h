#include "__cf_Cooperative_Quad_09_VelEst_02.h"
#ifndef RTW_HEADER_Cooperative_Quad_09_VelEst_02_h_
#define RTW_HEADER_Cooperative_Quad_09_VelEst_02_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Cooperative_Quad_09_VelEst_02_COMMON_INCLUDES_
#define Cooperative_Quad_09_VelEst_02_COMMON_INCLUDES_
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
#include "Cooperative_Quad_09_VelEst_02_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Cooperative_Quad_09_VelEst_02
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (368) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (1017)   
#elif NCSTATES != 1017
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
typedef struct { real_T hw5tnzrodd ; real_T gwmh5422nv [ 3 ] ; } bnke3tdprc ;
typedef struct { real_T ollm0kao5t [ 4 ] ; } dbcl0xeupb ; typedef struct {
real_T of10phaqxi [ 36 ] ; } mse3h2ftgz ; typedef struct { real_T l5c2p5rmcp
[ 6 ] ; } mu1vmeaxft ; typedef struct { real_T abjrrhoh5i [ 6 ] ; }
gdb14qhzuk ; typedef struct { real_T jhz4hydf42 [ 6 ] ; } dtavxwjdhj ;
typedef struct { real_T ltfzlzvs0c [ 36 ] ; } jajski1k0u ; typedef struct {
real_T m0i0p0mohd [ 6 ] ; } b2p0222gkg ; typedef struct { real_T dzda0l3ztv [
6 ] ; real_T j1zyuz5kzg [ 6 ] ; real_T jl4fbhrop1 [ 6 ] ; } ddr40jvpzk ;
typedef struct { real_T hg1x1nd45k [ 6 ] ; } kkwsfb1bht ; typedef struct {
real_T jaolq3jrhd [ 6 ] ; real_T gtmlnhqoq0 [ 6 ] ; real_T admi3yqyf0 [ 6 ] ;
} h1o13zkcgj ; typedef struct { real_T hia3u3mq0v [ 3 ] ; } klganzpzjd ;
typedef struct { real_T mxe5eu4hb4 ; } fgw5sini0c ; typedef struct { real_T
g2eupjim4n ; } bzt4d3mdqo ; typedef struct { real_T ikd1vheez0 [ 12 ] ; }
ap0k121r2c ; typedef struct { real_T d1dlzas2mm [ 2 ] ; real_T arptmdt05w [ 2
] ; } ov12mb433f ; typedef struct { real_T ntmpjrn1e1 [ 2 ] ; real_T
fyzqgebnzz [ 2 ] ; } k0s5cnp1qe ; typedef struct { real_T jtrbmpg3lt [ 15 ] ;
real_T n4wcvzk1ua [ 15 ] ; } m1hjhmjwg5 ; typedef struct { real_T hpfjqszf4x
[ 12 ] ; real_T k5iezadngg [ 2 ] ; real_T kfb55nbxu2 ; real_T atfess0a2f [ 2
] ; real_T jrp1fodqyr [ 2 ] ; } awhjeott21 ; typedef struct { real_T
go4wiq4kbo [ 2 ] ; } kvooenmmxs ; typedef struct { real_T fzjsuutou0 [ 2 ] ;
} jeft2nmhia ; typedef struct { real_T esbc0t1dta ; } pmfwaobihs ; typedef
struct { real_T ortedkvoqi ; } m1ole03jfu ; typedef struct { real_T
kh05gq2bif [ 36 ] ; } gxaahiqdto ; typedef struct { real_T jemkrzqk3c [ 15 ]
; } gor4c4smif ; typedef struct { real_T g2qarspkxz [ 2 ] ; } ivinvzhydj ;
typedef struct { real_T eup5e2ipsb [ 2 ] ; } eo1i0pkmfn ; typedef struct {
epsilon_bus hvniiswj0n ; epsilon_bus hbcqjuse5q ; epsilon_bus bszz24pz1b ;
epsilon_bus fxxr4yxfew ; real_T hoefupodzc [ 12 ] ; real_T cbz53iqiop [ 3 ] ;
real_T cltq0cfb00 [ 6 ] ; real_T cri1kl2qhs [ 6 ] ; real_T haamgpyyku [ 6 ] ;
real_T naukoivzmr [ 6 ] ; real_T nlsv5ptysw [ 6 ] ; real_T fsylupg2ie ;
real_T ovp54ku00f [ 2 ] ; real_T guii4af3w0 [ 2 ] ; real_T j2lsirb0ej [ 12 ]
; real_T fyll5jdjjj [ 2 ] ; real_T mka13uwfw0 [ 2 ] ; real_T au5wbjjqt3 [ 2 ]
; real_T jiz3a002c3 [ 2 ] ; real_T peasbjr2ah [ 2 ] ; real_T obobcozbfh [ 2 ]
; real_T kthfd0aif2 [ 2 ] ; real_T n1skxybgba [ 2 ] ; real_T c0vcvn0r0g ;
real_T mwkffby2ul ; real_T hhq2gz3sy3 [ 2 ] ; real_T p123e5cq2h [ 2 ] ;
real_T ibguh2azcu [ 2 ] ; real_T kcifbusgyp [ 2 ] ; real_T nr2xhydys1 [ 2 ] ;
real_T a03f1j3hsr [ 2 ] ; real_T ma4hr1zg5h [ 2 ] ; real_T kjfk5s4txt [ 2 ] ;
real_T cq2ac25vvr [ 2 ] ; real_T f3swi4wykw [ 2 ] ; real_T fjnyclhmei [ 3 ] ;
real_T etgxr0b4e3 ; real_T jp4yty50ed [ 3 ] ; real_T c5ojbulhcl [ 3 ] ;
real_T c2fmjucg5f [ 3 ] ; real_T i10izinweb [ 3 ] ; real_T ar5mtka5cc [ 3 ] ;
real_T gorv20ywqu [ 3 ] ; real_T i3h3tvdsd4 ; real_T irxau0vegh [ 3 ] ;
real_T kakeuy45nl [ 2 ] ; real_T leex1vr2mc [ 2 ] ; real_T ixqvkyn0bs [ 2 ] ;
real_T g2pdbeghl4 [ 2 ] ; real_T cdzixgvais [ 2 ] ; real_T bqxn34m0qr [ 2 ] ;
real_T icqhriylz3 [ 2 ] ; real_T ordnmswswg [ 2 ] ; real_T ajq0qn0k3g [ 2 ] ;
real_T f5apej04cu [ 2 ] ; real_T ktzqeyaa2j [ 12 ] ; real_T cj3tu2cvgj [ 6 ]
; real_T bzdtapi1nn [ 6 ] ; real_T e5sbn5ywmn [ 6 ] ; real_T k2wfwxwner [ 6 ]
; real_T kan4kiqahi [ 6 ] ; real_T ll2wsps0hn ; real_T pm1tjuoiq2 [ 12 ] ;
real_T myenxxvcic [ 2 ] ; real_T lvotrv1jjx [ 2 ] ; real_T gr0jp0xo2u [ 2 ] ;
real_T iwqydkbfig [ 3 ] ; real_T hcksi1q3o0 [ 2 ] ; real_T jpsqiswtns [ 2 ] ;
real_T kfsw4l5xh5 [ 2 ] ; real_T ixaiy5tpfv [ 12 ] ; real_T mgul3pau2j [ 6 ]
; real_T axybt0iosa [ 6 ] ; real_T cib1121v1a [ 6 ] ; real_T jrkcafrldp [ 6 ]
; real_T hb01w4hsae [ 6 ] ; real_T okfse5qvqh ; real_T l1rog3vm3b [ 12 ] ;
real_T p32mbcnx3i [ 2 ] ; real_T ewwxrohews [ 2 ] ; real_T ika3sw4mwy [ 2 ] ;
real_T mfq4qoe4yi [ 3 ] ; real_T jaakjngya0 [ 2 ] ; real_T ielqt1mrev [ 2 ] ;
real_T amoxktpzg5 [ 2 ] ; real_T keppwjdt4q [ 12 ] ; real_T c01olslca1 [ 6 ]
; real_T nnrb331rfb [ 6 ] ; real_T fmwnvf0vev [ 6 ] ; real_T nx0lawusi5 [ 6 ]
; real_T o2px3pavbt [ 6 ] ; real_T fzvqljdzf0 ; real_T azahyglgjt [ 12 ] ;
real_T e4bknlrhvn [ 2 ] ; real_T lipbvqqq2c [ 2 ] ; real_T jbsiq0ysnz [ 2 ] ;
real_T ndqfi1y1ay [ 3 ] ; real_T g3orff0vvz [ 2 ] ; real_T da52lxzfo3 [ 2 ] ;
real_T f1botvjvoe [ 2 ] ; real_T a0erqdse13 ; real_T dzrglp0ucc ; real_T
ctbtcnregv ; real_T cqxgiryrfh ; real_T l1umxbg5f0 ; real_T g3ehhuuywp ;
real_T nl3ka3mlrr ; real_T ngglndshnd ; real_T epn3tgotb3 [ 3 ] ; real_T
gsrbrbeiwt [ 3 ] ; real_T awhqz5sjvx [ 3 ] ; real_T cbvb41g3bt [ 3 ] ; real_T
gac1ybd3gq [ 3 ] ; real_T l1wjcn1r3q [ 3 ] ; real_T ll4nivtt3m [ 3 ] ; real_T
ashx3cqs2u [ 3 ] ; eo1i0pkmfn edifya2tdy ; ivinvzhydj oule4qndjw ; eo1i0pkmfn
odmwzwbx3r ; ivinvzhydj olxq5nidun ; gor4c4smif a5jargzydm ; gor4c4smif
evh0wbev03 ; gor4c4smif fheiecna2a ; gor4c4smif f4fb5d4j31 ; gor4c4smif
pr4fonk2dq ; gor4c4smif gxozu2rlri ; gor4c4smif bvxcorhvnz ; gor4c4smif
jwd1fkztpc ; gxaahiqdto nq1hfz3a31 ; gxaahiqdto gw4ba2toit ; gxaahiqdto
euxu4ep35i ; gxaahiqdto hteupnqrx4 ; gxaahiqdto nuraudbnmw ; gxaahiqdto
bbqw0bl5gl ; gxaahiqdto p4upkbqkhe ; gxaahiqdto kkuccmfrbi ; gxaahiqdto
d52hlymzlr ; gxaahiqdto k4omfwosju ; gxaahiqdto hl0u2uhz0x ; gxaahiqdto
m4ijqp4odc ; gxaahiqdto p5pqkurl0x ; gxaahiqdto e1yst2ptdp ; gxaahiqdto
a4teg0k51j ; gxaahiqdto fq3vfzzwja ; m1ole03jfu b5wgwyu43w ; jeft2nmhia
hnz1gucse0 ; kvooenmmxs jrmqablme2 ; bzt4d3mdqo eocfzlmdyi ; fgw5sini0c
lm3v4bjggl ; m1ole03jfu bznnvznea4 ; kvooenmmxs ofj3udt4tn ; jeft2nmhia
lfwezxmueh ; bzt4d3mdqo i2czmwyezh ; fgw5sini0c i3j3yx4m45 ; m1ole03jfu
nd45g0hfjt ; kvooenmmxs hetjmev4n0 ; jeft2nmhia bbzxnckkdp ; bzt4d3mdqo
e11zyd4z32 ; fgw5sini0c fozmp525vk ; pmfwaobihs hej02ixwew ; jeft2nmhia
myur3d20g5 ; kvooenmmxs oddtrbrdmn ; bzt4d3mdqo a40jt3tdup ; fgw5sini0c
ngaywgoh4j ; awhjeott21 kb4nwcrwes ; m1hjhmjwg5 cynnr55l50 ; k0s5cnp1qe
jh4bhzwp5a ; ov12mb433f ktgydrdwot ; ap0k121r2c krha0qyekz ; bzt4d3mdqo
gbsw4vtbfc ; fgw5sini0c lh525nk5c4 ; klganzpzjd bsfibrztcn ; h1o13zkcgj
ayhvjwdkil ; b2p0222gkg nbpckilwbi ; dtavxwjdhj fxmpoowwke ; gdb14qhzuk
ock5oqnuqf ; kkwsfb1bht czfjlbeq0m ; mse3h2ftgz jwvzg3dbyn ; jajski1k0u
aps0x4iowd ; ddr40jvpzk p3oko5rg5q ; b2p0222gkg ejz0pvfgin ; jajski1k0u
hclvb5l0yw ; dtavxwjdhj mnhfszymlh ; gdb14qhzuk oreloirudv ; mu1vmeaxft
cycndcb0jh ; mse3h2ftgz c2otonew4a ; dbcl0xeupb hfcfmmylgh ; bnke3tdprc
nxtnef4xl5 ; m1ole03jfu mrepog2h42 ; jeft2nmhia h0rgneuhfx ; kvooenmmxs
c5nge20guz ; bzt4d3mdqo fsjvhtbxoc ; fgw5sini0c axqhmtwvft ; m1ole03jfu
ns3lzfiy1g ; kvooenmmxs h2durator1 ; jeft2nmhia l1combp0kl ; bzt4d3mdqo
iinpzr5pdo ; fgw5sini0c pltjyjalnc ; m1ole03jfu l2j5ycxexp ; kvooenmmxs
avalzerqm0 ; jeft2nmhia mdircrytff ; bzt4d3mdqo aax0e1c4lb ; fgw5sini0c
cx0tbybfel ; pmfwaobihs gmjjjikxkv ; jeft2nmhia aqzxsisqqu ; kvooenmmxs
oiztqgxwa2 ; bzt4d3mdqo ga1oou1sez ; fgw5sini0c oja35avhxy ; awhjeott21
ntpm2p40uf ; m1hjhmjwg5 a51pswiot5 ; k0s5cnp1qe jwtc4eqcdp ; ov12mb433f
kcdsohu0vj ; ap0k121r2c de51ggtvmf ; bzt4d3mdqo h5gd3tgpey ; fgw5sini0c
cxzd2dbymf ; klganzpzjd bhiqn3njpt ; h1o13zkcgj mkh53mukfc ; b2p0222gkg
e5mxo1itjx ; dtavxwjdhj pxgpfywurc ; gdb14qhzuk a4hw5bc5zg ; kkwsfb1bht
jc521lazxl ; mse3h2ftgz epn4fcspwt ; jajski1k0u czo35p4wud ; ddr40jvpzk
dshtigbj0k ; b2p0222gkg bv2yjfnafy ; jajski1k0u lnm54cnchk ; dtavxwjdhj
fyu31sinwv ; gdb14qhzuk plfgevb5mc ; mu1vmeaxft flkl1uejjb ; mse3h2ftgz
pjulmwnqfc ; dbcl0xeupb lyoqvsgui4 ; bnke3tdprc kkorjs14db ; m1ole03jfu
nwyzua4gjf ; jeft2nmhia lofsb5hfpk ; kvooenmmxs iw5aeqjlmr ; bzt4d3mdqo
cg5bnbimqw ; fgw5sini0c fvjwsgw14y ; m1ole03jfu cgmylk2bxu ; kvooenmmxs
pi5klgxywb ; jeft2nmhia a0eglqqncr ; bzt4d3mdqo ilz4rw1itf ; fgw5sini0c
nimb0vszrh ; m1ole03jfu ina2eaxl2c ; kvooenmmxs gnuxcvc0rq ; jeft2nmhia
mx2c20cuvt ; bzt4d3mdqo kzcw4mi4zh ; fgw5sini0c jkdewgbanl ; pmfwaobihs
nz4rsiamof ; jeft2nmhia obs2vasvj2 ; kvooenmmxs bgqjdgwjco ; bzt4d3mdqo
p43v4vgoay ; fgw5sini0c obfqahvmjm ; awhjeott21 cz230wcizx ; m1hjhmjwg5
onfv1wmnyg ; k0s5cnp1qe eolycnedw1 ; ov12mb433f lj1isfudih ; ap0k121r2c
htnejvn3py ; bzt4d3mdqo l3bm1rlyki ; fgw5sini0c gsjc2uausd ; klganzpzjd
gt3vc04dxa ; h1o13zkcgj lycfgsadwf ; b2p0222gkg l3bbgfkbil ; dtavxwjdhj
ikazhomoow ; gdb14qhzuk dnncszfbjm ; kkwsfb1bht fuoxbigwkf ; mse3h2ftgz
e3k2wvkram ; jajski1k0u fgdsj1go3f ; ddr40jvpzk ghgs23hmyk ; b2p0222gkg
ng0oekyoml ; jajski1k0u cphdqdow2s ; dtavxwjdhj kn0eokpsnw ; gdb14qhzuk
ofq5zlashb ; mu1vmeaxft e2iscjaunx ; mse3h2ftgz dhwkhs2uoc ; dbcl0xeupb
gntssldk33 ; bnke3tdprc ngywhtsz3l ; m1ole03jfu fnvhv3sjko ; jeft2nmhia
hubjvrmjeu ; kvooenmmxs pogoxyyi05 ; bzt4d3mdqo h32zv1canq ; fgw5sini0c
dqmxq5wims ; m1ole03jfu ey4yzgiezw ; jeft2nmhia fqy4bphp3r ; kvooenmmxs
nj0q0pfqt4 ; bzt4d3mdqo cyju4j1oji ; fgw5sini0c peplmogpy4 ; m1ole03jfu
bfqgyvaqcz ; jeft2nmhia cc0eq1pdzz ; kvooenmmxs nj24ds003u ; bzt4d3mdqo
hduc3332fp ; fgw5sini0c jkmnldsv41 ; pmfwaobihs c531ff4wpr ; jeft2nmhia
k2f1farrzj ; kvooenmmxs ezrv5s44v4 ; bzt4d3mdqo dukk21lgx3 ; fgw5sini0c
by2102zg1w ; awhjeott21 hfjw0isrvt ; m1hjhmjwg5 nrezxvhxow ; k0s5cnp1qe
pqggajaphk ; ov12mb433f oqwk5hg0e3 ; ap0k121r2c gi0uwyfhqp ; bzt4d3mdqo
kaxep214he ; fgw5sini0c ngb4hyklf3 ; klganzpzjd elri1t014b ; h1o13zkcgj
dtk02osx1k ; b2p0222gkg m2f3uzhfsg ; dtavxwjdhj jisefsiylr ; gdb14qhzuk
fbwflwjjvm ; kkwsfb1bht nfjyzad3my ; mse3h2ftgz ikvvizl300 ; jajski1k0u
otvyyn5pvr ; ddr40jvpzk bydx3i5iwd ; b2p0222gkg euig1sdxae ; jajski1k0u
b4e1ilqhrp ; dtavxwjdhj nqkvnie0as ; gdb14qhzuk kuuq0qawad ; mu1vmeaxft
eetjt415xo ; mse3h2ftgz eu03stat4s ; dbcl0xeupb eo0mj2ipwy ; bnke3tdprc
ia0kb0ljog ; } B ; typedef struct { real_T ljf3bzpuxv [ 12 ] ; real_T
g1vhr4ol4w [ 6 ] ; real_T p5cipt2vk2 [ 6 ] ; real_T gutf3fahtc ; real_T
l0nq3lmdeg [ 2 ] ; real_T i1hjxzs31f [ 2 ] ; real_T gjvtrlsfwe [ 2 ] ; real_T
pzvvqboa5v [ 2 ] ; real_T orrbrxbq10 [ 2 ] ; real_T ldao3hyxar [ 2 ] ; real_T
o4urslscxv [ 2 ] ; real_T biuieiqmxp [ 2 ] ; real_T kxmjiaeunc [ 2 ] ; real_T
gq1mgiuwz2 [ 2 ] ; real_T lwlz3gfxgb [ 15 ] ; real_T ekvleb1gcq [ 15 ] ;
real_T k3kw4exkgg [ 15 ] ; real_T cr0y2nzbkc [ 15 ] ; real_T eftcuoxcfp [ 3 ]
; real_T bdxxdlvg4e [ 3 ] ; real_T l34b1ws24z [ 3 ] ; real_T lbl43aynsc [ 3 ]
; real_T euwquc1ohh [ 2 ] ; real_T kb1zmmywdq [ 2 ] ; real_T nsyupx5qza [ 2 ]
; real_T mfzuy1fnjf [ 2 ] ; real_T meq4arbagn [ 2 ] ; real_T elhi3coyqa [ 2 ]
; real_T cb4caomchi [ 2 ] ; real_T njybh3xjqw [ 12 ] ; real_T hdkreqmds2 [ 6
] ; real_T k5rawm0exp [ 6 ] ; real_T eb005l0rcc ; real_T jhqxxzie31 [ 2 ] ;
real_T oywwglvnbw [ 12 ] ; real_T ekk5eebzqc [ 6 ] ; real_T mec2hevem0 [ 6 ]
; real_T gx01drbeka ; real_T c1300gzrjt [ 2 ] ; real_T kbb0qw5mp3 [ 12 ] ;
real_T ppddj1qhga [ 6 ] ; real_T igxhj4adkf [ 6 ] ; real_T kiivcdig1l ;
real_T jpwsqsteoo [ 2 ] ; struct { real_T modelTStart ; } kamedad4fc ; struct
{ real_T modelTStart ; } pz0fn4jcir ; struct { real_T modelTStart ; }
nfi1o0zqhe ; struct { real_T modelTStart ; } iga0qrpgxp ; struct { real_T
modelTStart ; } cmp3pciv1k ; struct { real_T modelTStart ; } cwubgwufhu ;
struct { real_T modelTStart ; } pgotf00qki ; struct { real_T modelTStart ; }
f2xybhnfah ; struct { real_T modelTStart ; } nzpfoot5zb ; struct { real_T
modelTStart ; } hmdv3jgo0w ; struct { real_T modelTStart ; } hjbirfpqlz ;
struct { void * TUbufferPtrs [ 2 ] ; } ir3tccey2d ; struct { void *
TUbufferPtrs [ 2 ] ; } mahzin5xie ; struct { void * LoggedData ; } ar5aitlh0p
; struct { void * LoggedData ; } otjnghacse ; struct { void * TUbufferPtrs [
2 ] ; } em4ieblqdo ; struct { void * TUbufferPtrs [ 2 ] ; } cp2wd3yek3 ;
struct { void * TUbufferPtrs [ 2 ] ; } nuyw1oa5lu ; struct { void *
TUbufferPtrs [ 2 ] ; } ongfcz4dhf ; struct { void * LoggedData ; } khahckeavp
; struct { void * LoggedData ; } otavtmkifg ; struct { void * TUbufferPtrs [
2 ] ; } jzm2uqh05o ; struct { void * TUbufferPtrs [ 2 ] ; } kim1kgtcyq ;
struct { void * LoggedData ; } bmyivgml4h ; struct { void * LoggedData ; }
h1xavsnqdm ; struct { void * TUbufferPtrs [ 2 ] ; } e0iyas1xpb ; struct {
void * TUbufferPtrs [ 2 ] ; } gcbrh04vlv ; struct { void * LoggedData ; }
gqt3nydeks ; struct { void * LoggedData ; } ej35jv00ok ; struct { void *
LoggedData ; } cnv2qh3oxp ; struct { void * LoggedData ; } cku5zcj5in ;
struct { void * LoggedData ; } afsvhrfqgs ; struct { void * LoggedData ; }
cdsdbyqqzu ; struct { void * LoggedData ; } ipoi1altor ; struct { void *
LoggedData ; } j5tckppox0 ; struct { void * LoggedData ; } fykosnvvaa ;
struct { void * LoggedData ; } eywuoilqki ; struct { void * LoggedData ; }
dn3eyt5r41 ; struct { void * LoggedData ; } pmas04mzh3 ; struct { void *
LoggedData ; } hiugye00am ; struct { void * LoggedData ; } lhbec2ip5d ;
struct { void * LoggedData ; } jv5zdrn2x3 ; struct { void * LoggedData ; }
nyqddap2e3 ; struct { void * LoggedData ; } bccb5ha5vc ; struct { void *
LoggedData ; } h0qwwidrrt ; struct { void * LoggedData ; } hugbzsrs2a ;
struct { void * LoggedData ; } mi55warbfl ; struct { void * LoggedData ; }
cr4rc4zkjl ; struct { void * LoggedData ; } lif3zndlrk ; struct { void *
LoggedData ; } dqsdd0iav1 ; struct { void * LoggedData ; } jtrbooxbd3 ;
struct { void * LoggedData ; } cjri132aia ; struct { void * LoggedData ; }
lusxtmzcjz ; struct { void * LoggedData ; } nujtkogswx ; struct { void *
LoggedData ; } o4dhmx5qrq ; struct { void * LoggedData ; } jqjkpgnny2 ;
struct { void * LoggedData ; } dl3c4wd40p ; struct { void * LoggedData ; }
bhza4smniz ; struct { void * LoggedData ; } m5vo5zrdwd ; struct { void *
LoggedData ; } j44z1n4syw ; struct { void * LoggedData ; } fqe3wzj2rm ;
struct { void * LoggedData ; } ayulsnbsp1 ; struct { void * LoggedData ; }
mweg4p0tza ; struct { void * LoggedData ; } cp12dwm5j2 ; struct { void *
LoggedData ; } lmqaiznxh2 ; struct { void * LoggedData ; } muzjnzi4ha ;
struct { void * LoggedData ; } btfxhaa12b ; struct { void * LoggedData ; }
bm0dfne2co ; struct { void * LoggedData ; } dvgadtng5f ; struct { void *
LoggedData ; } ne3xkbigd3 ; struct { void * LoggedData ; } o1tss2hntz ;
struct { void * LoggedData ; } cuqr2hwfzx ; struct { void * LoggedData ; }
c2pncb15ww ; struct { void * LoggedData ; } pa52z4wohc ; struct { void *
LoggedData ; } gau0w0subc ; struct { void * LoggedData ; } cugbohahl2 ;
struct { void * LoggedData ; } gf3gsxu3l0 ; struct { void * LoggedData ; }
ls1lel04nj ; struct { void * LoggedData ; } ml2ga241wu ; struct { void *
LoggedData ; } np2hti1a1a ; struct { void * LoggedData ; } ptdrnn4gkj ;
struct { void * LoggedData ; } ctxmgcldmt ; struct { void * LoggedData ; }
egvebj0vzk ; struct { void * LoggedData ; } iuqftoyemw ; struct { void *
LoggedData ; } azxrx1pbjx ; struct { void * LoggedData ; } hnmfnkx4kz ;
struct { void * LoggedData ; } kqv43bmmbb ; struct { void * LoggedData ; }
gea3tezmhg ; struct { void * LoggedData ; } pnnupo15gj ; struct { void *
LoggedData ; } jlh0sku320 ; struct { void * LoggedData ; } m5pscv5mzf ;
struct { void * LoggedData ; } ft5vk4jxv2 ; struct { void * LoggedData ; }
e1dat3np50 ; struct { void * LoggedData ; } jesgoxpysk ; struct { void *
LoggedData ; } bxokau5rly ; struct { void * LoggedData ; } ikckvftlj0 ;
struct { void * LoggedData ; } kuf1r1iib1 ; struct { void * LoggedData ; }
dzd50qusdc ; struct { void * LoggedData ; } hxmfmxbxzg ; struct { void *
LoggedData ; } b31ricvahq ; struct { void * LoggedData ; } k5v5nydhl2 ;
struct { void * LoggedData ; } aszo4opjoq ; struct { void * LoggedData ; }
gk5p53h1wj ; struct { void * LoggedData ; } lu4iopse32 ; struct { void *
LoggedData ; } knsumlziop ; struct { void * LoggedData ; } ky1g0helic ;
struct { void * LoggedData ; } fvoj0brkji ; struct { void * LoggedData ; }
dkoo4kcfaj ; struct { void * LoggedData ; } i5grh4jmh3 ; struct { void *
LoggedData ; } pdkyev51db ; struct { void * LoggedData ; } i4dnzdgvyj ;
struct { void * LoggedData ; } jzughaiexw ; struct { void * LoggedData ; }
jeazhlxihn ; struct { void * LoggedData ; } fhvzke4cet ; struct { void *
LoggedData ; } j50ebbuydy ; struct { void * LoggedData ; } mxwnv4z2lq ;
struct { void * LoggedData ; } g15tyxojey ; struct { void * LoggedData ; }
f4mz54thlc ; struct { void * LoggedData ; } oiwwfvr1a5 ; struct { void *
LoggedData ; } lh0nbilqnw ; struct { void * LoggedData ; } fj5wqp1pom ;
struct { void * LoggedData ; } onngtoccwk ; struct { void * LoggedData ; }
ozyfkr2biz ; struct { void * LoggedData ; } bzo2lxtcos ; struct { void *
LoggedData ; } ofyltfe4ni ; struct { void * LoggedData ; } gjzrj5vwzi ;
struct { void * LoggedData ; } o54vw4q3ry ; struct { void * LoggedData ; }
esfmkot2gm ; struct { void * LoggedData ; } fwolkb0vlk ; struct { void *
LoggedData ; } orxq3kojbg ; struct { void * LoggedData ; } ovq0d1ceac ;
struct { void * LoggedData ; } fup4sk0rmj ; struct { void * LoggedData ; }
g5difolfpk ; struct { void * LoggedData ; } j1krmqotmd ; struct { void *
LoggedData ; } df1ipbmg3z ; struct { void * LoggedData ; } mpaolyryto ;
struct { void * LoggedData ; } kabuwjql3m ; struct { void * LoggedData ; }
fng5gfijxe ; struct { void * LoggedData ; } az4riutx0n ; struct { void *
LoggedData ; } pw42vsjs5z ; struct { void * LoggedData ; } ieqghgs4hk ;
struct { void * LoggedData ; } cd4funmbby ; struct { void * LoggedData ; }
ahjraffioz ; struct { void * LoggedData ; } chracf5vkk ; struct { void *
LoggedData ; } a44p0qs4mp ; struct { void * LoggedData ; } cvspglvkum ;
struct { void * LoggedData ; } cwywqcfbrn ; struct { void * LoggedData ; }
kjacqpc401 ; struct { void * LoggedData ; } pa44p12zb2 ; struct { void *
LoggedData [ 3 ] ; } pywvylisvs ; struct { void * LoggedData ; } itaaab0kng ;
struct { void * TUbufferPtrs [ 2 ] ; } aoi2q222df ; struct { void * TimePtr ;
void * DataPtr ; void * RSimInfoPtr ; } p0dm4cko3k ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } puereonu00 ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } iwwdwmgwmf ; struct { void
* TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } drrrzdfjw3 ; struct {
void * LoggedData [ 3 ] ; } mjdday0cuw ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } kxnrq3j5gh ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } f4c4a4mj3p ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } hflmn5zw4g ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } ogn0tnbje1 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } lyazy3gnn2 ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
je3z34ckbn ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } fyo23snxav ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
b4ivhh52o2 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } j5kjeh2fcr ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
fckn41cqic ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } jkuwdaephj ; int_T fm531h0dfy [ 2 ]
; int_T ary12ruqzb ; struct { int_T PrevIndex ; } i42enhfwq5 ; struct { int_T
PrevIndex ; } hjvjlcfeww ; struct { int_T PrevIndex ; } l1lz31mbjt ; struct {
int_T PrevIndex ; } bawkp25aax ; boolean_T k1smvi2dzs ; boolean_T fianodont1
; boolean_T msmqvj5ygx ; boolean_T jkpae01oin ; } DW ; typedef struct {
real_T ionyxldtcw [ 6 ] ; real_T jls05hpmo2 [ 3 ] ; real_T mf3bhm1i2g [ 15 ]
; real_T jhjq50hamr [ 6 ] ; real_T luz4nck343 [ 6 ] ; real_T fwt4soxxlc [ 36
] ; real_T lmukmnay3o [ 36 ] ; real_T oblwbzt05m [ 6 ] ; real_T mgsh4lifu4 [
6 ] ; real_T g4ve5h5vh2 [ 6 ] ; real_T mc4ye23acv [ 6 ] ; real_T pusmj51k2o [
36 ] ; real_T oh4v0qnmbl [ 36 ] ; real_T i0ozzqeoz4 [ 6 ] ; real_T gttal13ne4
; real_T lhg5uf35jg ; real_T jyxqpcbioa [ 2 ] ; real_T f5podaplbs [ 2 ] ;
real_T armybl4b3j [ 12 ] ; real_T omoyscdlkq [ 2 ] ; real_T bvv2j1fvkj [ 2 ]
; real_T jyfm4clkt1 [ 2 ] ; real_T an1dy1scdv [ 2 ] ; real_T ajilevaypm [ 2 ]
; real_T ndnjgxlg32 [ 2 ] ; real_T mampjjggm5 [ 2 ] ; real_T c1zyhspvvj [ 2 ]
; real_T bozttf3lme [ 2 ] ; real_T lu2z2r1bq1 [ 2 ] ; real_T au25a2kq45 [ 2 ]
; real_T n1g43fm50u [ 2 ] ; real_T jjhfp4nquz [ 2 ] ; real_T j0sputa12i [ 2 ]
; real_T bpzbkldlw5 [ 2 ] ; real_T djt2dez0wq [ 2 ] ; real_T chv5h33ild [ 15
] ; real_T f5c0yrpl0m [ 15 ] ; real_T jee34x0zc4 [ 15 ] ; real_T im051m03c0 [
3 ] ; real_T ossqjsfts4 [ 3 ] ; real_T ivslgspzyl [ 3 ] ; real_T hiamj1oevs ;
real_T gx3o1bpm3a ; real_T gtdwc5tdzv [ 2 ] ; real_T cg2tzvhg1s [ 2 ] ;
real_T joe5wc3vru ; real_T belilpb3dk ; real_T bxlordfjyp ; real_T mva2o1cupz
; real_T lmqns2m2fd ; real_T du3cl5u2br ; real_T aqayeibnbf [ 6 ] ; real_T
mnhjgksiva [ 6 ] ; real_T p5euhzgph2 [ 6 ] ; real_T nsygkjz001 [ 36 ] ;
real_T pyssp52j4v [ 36 ] ; real_T fig1xy4s5q [ 6 ] ; real_T lovsimzfsp [ 6 ]
; real_T dvkhmbnof2 [ 6 ] ; real_T gqi2mgds2b [ 6 ] ; real_T ppo5lvnsbd [ 36
] ; real_T aslzbhpikx [ 36 ] ; real_T m20bb5px11 [ 6 ] ; real_T dmaqihaxaq ;
real_T dsaqs0egeg ; real_T hj3xpt5hh3 [ 12 ] ; real_T fmtqkgzjo2 [ 2 ] ;
real_T eqlst0fie1 [ 2 ] ; real_T jhyl0nmftj [ 2 ] ; real_T dufp23q24f [ 2 ] ;
real_T e5bm4mxp4y [ 2 ] ; real_T d2zjdsdy3t [ 2 ] ; real_T atdwxldcaa [ 2 ] ;
real_T kdrbhkothr [ 2 ] ; real_T l1nyqmvwst ; real_T ca2tchanai ; real_T
ooketywe0t ; real_T mjw0keqmwr ; real_T fb0bskoedk ; real_T phfjeo0drc ;
real_T d0fq4dyqzm ; real_T irfwmkoozp ; real_T gfix1az2dy [ 6 ] ; real_T
lajj3kiv0r [ 6 ] ; real_T musq314bsn [ 6 ] ; real_T oljl1r15sy [ 36 ] ;
real_T kdjra2pfq4 [ 36 ] ; real_T ox0f0pxtqm [ 6 ] ; real_T eu121u4uj2 [ 6 ]
; real_T bgjp3vzt5z [ 6 ] ; real_T dn5twkxizj [ 6 ] ; real_T eeiannul5v [ 36
] ; real_T czjyxcctju [ 36 ] ; real_T m0wpx0tt4b [ 6 ] ; real_T kr3nejsoss ;
real_T jclkuzenpd ; real_T bpmgvfdh3p [ 12 ] ; real_T ntmiect20q [ 2 ] ;
real_T nw2qbjtrfg [ 2 ] ; real_T eysiy0scrq [ 2 ] ; real_T cyoaoohsr1 [ 2 ] ;
real_T d5kjlwmgrk [ 2 ] ; real_T i1zsver5ig [ 2 ] ; real_T llgwidxzty [ 2 ] ;
real_T dcluu2qq0c [ 2 ] ; real_T mfmirsuvi1 ; real_T ajtyxihfqa ; real_T
fev21ha45i ; real_T daodwibywh ; real_T lkyqetg5kb ; real_T btc4odj1vw ;
real_T c0pmpkzruv ; real_T jlansep42b ; real_T lbivgbnpeh [ 6 ] ; real_T
m54hyt4uuq [ 6 ] ; real_T lxl24bgnmj [ 6 ] ; real_T efyhshm0ot [ 36 ] ;
real_T gdfmrn5gpc [ 36 ] ; real_T jbncktdjxo [ 6 ] ; real_T kwvqencn2m [ 6 ]
; real_T el0s1crasb [ 6 ] ; real_T iiijpho0bw [ 6 ] ; real_T ef5r0lp3ux [ 36
] ; real_T iuw551xzyz [ 36 ] ; real_T fqk1pcxz11 [ 6 ] ; real_T guiwz4qjqi ;
real_T nvrhieikes ; real_T p3bnpoi4ms [ 12 ] ; real_T fat2ntucmp [ 2 ] ;
real_T f23ygfhi2f [ 2 ] ; real_T jl5u0so5kr [ 2 ] ; real_T m4oor1dqcu [ 2 ] ;
real_T edonk3lpof [ 2 ] ; real_T c2d4vnjngq [ 2 ] ; real_T ixb5n0f1pg [ 2 ] ;
real_T mvd25m5wxn [ 2 ] ; real_T axapvnuown ; real_T fk4euimlnu ; real_T
gvdlmv0f2h ; real_T g4o2mykdy0 ; real_T ms3jvyzwa2 ; real_T hftm5kpfrm ;
real_T a0vktynhmg ; real_T ok1bkcbj54 ; real_T f0gxn5lxra ; } X ; typedef
struct { real_T ionyxldtcw [ 6 ] ; real_T jls05hpmo2 [ 3 ] ; real_T
mf3bhm1i2g [ 15 ] ; real_T jhjq50hamr [ 6 ] ; real_T luz4nck343 [ 6 ] ;
real_T fwt4soxxlc [ 36 ] ; real_T lmukmnay3o [ 36 ] ; real_T oblwbzt05m [ 6 ]
; real_T mgsh4lifu4 [ 6 ] ; real_T g4ve5h5vh2 [ 6 ] ; real_T mc4ye23acv [ 6 ]
; real_T pusmj51k2o [ 36 ] ; real_T oh4v0qnmbl [ 36 ] ; real_T i0ozzqeoz4 [ 6
] ; real_T gttal13ne4 ; real_T lhg5uf35jg ; real_T jyxqpcbioa [ 2 ] ; real_T
f5podaplbs [ 2 ] ; real_T armybl4b3j [ 12 ] ; real_T omoyscdlkq [ 2 ] ;
real_T bvv2j1fvkj [ 2 ] ; real_T jyfm4clkt1 [ 2 ] ; real_T an1dy1scdv [ 2 ] ;
real_T ajilevaypm [ 2 ] ; real_T ndnjgxlg32 [ 2 ] ; real_T mampjjggm5 [ 2 ] ;
real_T c1zyhspvvj [ 2 ] ; real_T bozttf3lme [ 2 ] ; real_T lu2z2r1bq1 [ 2 ] ;
real_T au25a2kq45 [ 2 ] ; real_T n1g43fm50u [ 2 ] ; real_T jjhfp4nquz [ 2 ] ;
real_T j0sputa12i [ 2 ] ; real_T bpzbkldlw5 [ 2 ] ; real_T djt2dez0wq [ 2 ] ;
real_T chv5h33ild [ 15 ] ; real_T f5c0yrpl0m [ 15 ] ; real_T jee34x0zc4 [ 15
] ; real_T im051m03c0 [ 3 ] ; real_T ossqjsfts4 [ 3 ] ; real_T ivslgspzyl [ 3
] ; real_T hiamj1oevs ; real_T gx3o1bpm3a ; real_T gtdwc5tdzv [ 2 ] ; real_T
cg2tzvhg1s [ 2 ] ; real_T joe5wc3vru ; real_T belilpb3dk ; real_T bxlordfjyp
; real_T mva2o1cupz ; real_T lmqns2m2fd ; real_T du3cl5u2br ; real_T
aqayeibnbf [ 6 ] ; real_T mnhjgksiva [ 6 ] ; real_T p5euhzgph2 [ 6 ] ; real_T
nsygkjz001 [ 36 ] ; real_T pyssp52j4v [ 36 ] ; real_T fig1xy4s5q [ 6 ] ;
real_T lovsimzfsp [ 6 ] ; real_T dvkhmbnof2 [ 6 ] ; real_T gqi2mgds2b [ 6 ] ;
real_T ppo5lvnsbd [ 36 ] ; real_T aslzbhpikx [ 36 ] ; real_T m20bb5px11 [ 6 ]
; real_T dmaqihaxaq ; real_T dsaqs0egeg ; real_T hj3xpt5hh3 [ 12 ] ; real_T
fmtqkgzjo2 [ 2 ] ; real_T eqlst0fie1 [ 2 ] ; real_T jhyl0nmftj [ 2 ] ; real_T
dufp23q24f [ 2 ] ; real_T e5bm4mxp4y [ 2 ] ; real_T d2zjdsdy3t [ 2 ] ; real_T
atdwxldcaa [ 2 ] ; real_T kdrbhkothr [ 2 ] ; real_T l1nyqmvwst ; real_T
ca2tchanai ; real_T ooketywe0t ; real_T mjw0keqmwr ; real_T fb0bskoedk ;
real_T phfjeo0drc ; real_T d0fq4dyqzm ; real_T irfwmkoozp ; real_T gfix1az2dy
[ 6 ] ; real_T lajj3kiv0r [ 6 ] ; real_T musq314bsn [ 6 ] ; real_T oljl1r15sy
[ 36 ] ; real_T kdjra2pfq4 [ 36 ] ; real_T ox0f0pxtqm [ 6 ] ; real_T
eu121u4uj2 [ 6 ] ; real_T bgjp3vzt5z [ 6 ] ; real_T dn5twkxizj [ 6 ] ; real_T
eeiannul5v [ 36 ] ; real_T czjyxcctju [ 36 ] ; real_T m0wpx0tt4b [ 6 ] ;
real_T kr3nejsoss ; real_T jclkuzenpd ; real_T bpmgvfdh3p [ 12 ] ; real_T
ntmiect20q [ 2 ] ; real_T nw2qbjtrfg [ 2 ] ; real_T eysiy0scrq [ 2 ] ; real_T
cyoaoohsr1 [ 2 ] ; real_T d5kjlwmgrk [ 2 ] ; real_T i1zsver5ig [ 2 ] ; real_T
llgwidxzty [ 2 ] ; real_T dcluu2qq0c [ 2 ] ; real_T mfmirsuvi1 ; real_T
ajtyxihfqa ; real_T fev21ha45i ; real_T daodwibywh ; real_T lkyqetg5kb ;
real_T btc4odj1vw ; real_T c0pmpkzruv ; real_T jlansep42b ; real_T lbivgbnpeh
[ 6 ] ; real_T m54hyt4uuq [ 6 ] ; real_T lxl24bgnmj [ 6 ] ; real_T efyhshm0ot
[ 36 ] ; real_T gdfmrn5gpc [ 36 ] ; real_T jbncktdjxo [ 6 ] ; real_T
kwvqencn2m [ 6 ] ; real_T el0s1crasb [ 6 ] ; real_T iiijpho0bw [ 6 ] ; real_T
ef5r0lp3ux [ 36 ] ; real_T iuw551xzyz [ 36 ] ; real_T fqk1pcxz11 [ 6 ] ;
real_T guiwz4qjqi ; real_T nvrhieikes ; real_T p3bnpoi4ms [ 12 ] ; real_T
fat2ntucmp [ 2 ] ; real_T f23ygfhi2f [ 2 ] ; real_T jl5u0so5kr [ 2 ] ; real_T
m4oor1dqcu [ 2 ] ; real_T edonk3lpof [ 2 ] ; real_T c2d4vnjngq [ 2 ] ; real_T
ixb5n0f1pg [ 2 ] ; real_T mvd25m5wxn [ 2 ] ; real_T axapvnuown ; real_T
fk4euimlnu ; real_T gvdlmv0f2h ; real_T g4o2mykdy0 ; real_T ms3jvyzwa2 ;
real_T hftm5kpfrm ; real_T a0vktynhmg ; real_T ok1bkcbj54 ; real_T f0gxn5lxra
; } XDot ; typedef struct { boolean_T ionyxldtcw [ 6 ] ; boolean_T jls05hpmo2
[ 3 ] ; boolean_T mf3bhm1i2g [ 15 ] ; boolean_T jhjq50hamr [ 6 ] ; boolean_T
luz4nck343 [ 6 ] ; boolean_T fwt4soxxlc [ 36 ] ; boolean_T lmukmnay3o [ 36 ]
; boolean_T oblwbzt05m [ 6 ] ; boolean_T mgsh4lifu4 [ 6 ] ; boolean_T
g4ve5h5vh2 [ 6 ] ; boolean_T mc4ye23acv [ 6 ] ; boolean_T pusmj51k2o [ 36 ] ;
boolean_T oh4v0qnmbl [ 36 ] ; boolean_T i0ozzqeoz4 [ 6 ] ; boolean_T
gttal13ne4 ; boolean_T lhg5uf35jg ; boolean_T jyxqpcbioa [ 2 ] ; boolean_T
f5podaplbs [ 2 ] ; boolean_T armybl4b3j [ 12 ] ; boolean_T omoyscdlkq [ 2 ] ;
boolean_T bvv2j1fvkj [ 2 ] ; boolean_T jyfm4clkt1 [ 2 ] ; boolean_T
an1dy1scdv [ 2 ] ; boolean_T ajilevaypm [ 2 ] ; boolean_T ndnjgxlg32 [ 2 ] ;
boolean_T mampjjggm5 [ 2 ] ; boolean_T c1zyhspvvj [ 2 ] ; boolean_T
bozttf3lme [ 2 ] ; boolean_T lu2z2r1bq1 [ 2 ] ; boolean_T au25a2kq45 [ 2 ] ;
boolean_T n1g43fm50u [ 2 ] ; boolean_T jjhfp4nquz [ 2 ] ; boolean_T
j0sputa12i [ 2 ] ; boolean_T bpzbkldlw5 [ 2 ] ; boolean_T djt2dez0wq [ 2 ] ;
boolean_T chv5h33ild [ 15 ] ; boolean_T f5c0yrpl0m [ 15 ] ; boolean_T
jee34x0zc4 [ 15 ] ; boolean_T im051m03c0 [ 3 ] ; boolean_T ossqjsfts4 [ 3 ] ;
boolean_T ivslgspzyl [ 3 ] ; boolean_T hiamj1oevs ; boolean_T gx3o1bpm3a ;
boolean_T gtdwc5tdzv [ 2 ] ; boolean_T cg2tzvhg1s [ 2 ] ; boolean_T
joe5wc3vru ; boolean_T belilpb3dk ; boolean_T bxlordfjyp ; boolean_T
mva2o1cupz ; boolean_T lmqns2m2fd ; boolean_T du3cl5u2br ; boolean_T
aqayeibnbf [ 6 ] ; boolean_T mnhjgksiva [ 6 ] ; boolean_T p5euhzgph2 [ 6 ] ;
boolean_T nsygkjz001 [ 36 ] ; boolean_T pyssp52j4v [ 36 ] ; boolean_T
fig1xy4s5q [ 6 ] ; boolean_T lovsimzfsp [ 6 ] ; boolean_T dvkhmbnof2 [ 6 ] ;
boolean_T gqi2mgds2b [ 6 ] ; boolean_T ppo5lvnsbd [ 36 ] ; boolean_T
aslzbhpikx [ 36 ] ; boolean_T m20bb5px11 [ 6 ] ; boolean_T dmaqihaxaq ;
boolean_T dsaqs0egeg ; boolean_T hj3xpt5hh3 [ 12 ] ; boolean_T fmtqkgzjo2 [ 2
] ; boolean_T eqlst0fie1 [ 2 ] ; boolean_T jhyl0nmftj [ 2 ] ; boolean_T
dufp23q24f [ 2 ] ; boolean_T e5bm4mxp4y [ 2 ] ; boolean_T d2zjdsdy3t [ 2 ] ;
boolean_T atdwxldcaa [ 2 ] ; boolean_T kdrbhkothr [ 2 ] ; boolean_T
l1nyqmvwst ; boolean_T ca2tchanai ; boolean_T ooketywe0t ; boolean_T
mjw0keqmwr ; boolean_T fb0bskoedk ; boolean_T phfjeo0drc ; boolean_T
d0fq4dyqzm ; boolean_T irfwmkoozp ; boolean_T gfix1az2dy [ 6 ] ; boolean_T
lajj3kiv0r [ 6 ] ; boolean_T musq314bsn [ 6 ] ; boolean_T oljl1r15sy [ 36 ] ;
boolean_T kdjra2pfq4 [ 36 ] ; boolean_T ox0f0pxtqm [ 6 ] ; boolean_T
eu121u4uj2 [ 6 ] ; boolean_T bgjp3vzt5z [ 6 ] ; boolean_T dn5twkxizj [ 6 ] ;
boolean_T eeiannul5v [ 36 ] ; boolean_T czjyxcctju [ 36 ] ; boolean_T
m0wpx0tt4b [ 6 ] ; boolean_T kr3nejsoss ; boolean_T jclkuzenpd ; boolean_T
bpmgvfdh3p [ 12 ] ; boolean_T ntmiect20q [ 2 ] ; boolean_T nw2qbjtrfg [ 2 ] ;
boolean_T eysiy0scrq [ 2 ] ; boolean_T cyoaoohsr1 [ 2 ] ; boolean_T
d5kjlwmgrk [ 2 ] ; boolean_T i1zsver5ig [ 2 ] ; boolean_T llgwidxzty [ 2 ] ;
boolean_T dcluu2qq0c [ 2 ] ; boolean_T mfmirsuvi1 ; boolean_T ajtyxihfqa ;
boolean_T fev21ha45i ; boolean_T daodwibywh ; boolean_T lkyqetg5kb ;
boolean_T btc4odj1vw ; boolean_T c0pmpkzruv ; boolean_T jlansep42b ;
boolean_T lbivgbnpeh [ 6 ] ; boolean_T m54hyt4uuq [ 6 ] ; boolean_T
lxl24bgnmj [ 6 ] ; boolean_T efyhshm0ot [ 36 ] ; boolean_T gdfmrn5gpc [ 36 ]
; boolean_T jbncktdjxo [ 6 ] ; boolean_T kwvqencn2m [ 6 ] ; boolean_T
el0s1crasb [ 6 ] ; boolean_T iiijpho0bw [ 6 ] ; boolean_T ef5r0lp3ux [ 36 ] ;
boolean_T iuw551xzyz [ 36 ] ; boolean_T fqk1pcxz11 [ 6 ] ; boolean_T
guiwz4qjqi ; boolean_T nvrhieikes ; boolean_T p3bnpoi4ms [ 12 ] ; boolean_T
fat2ntucmp [ 2 ] ; boolean_T f23ygfhi2f [ 2 ] ; boolean_T jl5u0so5kr [ 2 ] ;
boolean_T m4oor1dqcu [ 2 ] ; boolean_T edonk3lpof [ 2 ] ; boolean_T
c2d4vnjngq [ 2 ] ; boolean_T ixb5n0f1pg [ 2 ] ; boolean_T mvd25m5wxn [ 2 ] ;
boolean_T axapvnuown ; boolean_T fk4euimlnu ; boolean_T gvdlmv0f2h ;
boolean_T g4o2mykdy0 ; boolean_T ms3jvyzwa2 ; boolean_T hftm5kpfrm ;
boolean_T a0vktynhmg ; boolean_T ok1bkcbj54 ; boolean_T f0gxn5lxra ; } XDis ;
typedef struct { real_T ionyxldtcw [ 6 ] ; real_T jls05hpmo2 [ 3 ] ; real_T
mf3bhm1i2g [ 15 ] ; real_T jhjq50hamr [ 6 ] ; real_T luz4nck343 [ 6 ] ;
real_T fwt4soxxlc [ 36 ] ; real_T lmukmnay3o [ 36 ] ; real_T oblwbzt05m [ 6 ]
; real_T mgsh4lifu4 [ 6 ] ; real_T g4ve5h5vh2 [ 6 ] ; real_T mc4ye23acv [ 6 ]
; real_T pusmj51k2o [ 36 ] ; real_T oh4v0qnmbl [ 36 ] ; real_T i0ozzqeoz4 [ 6
] ; real_T gttal13ne4 ; real_T lhg5uf35jg ; real_T jyxqpcbioa [ 2 ] ; real_T
f5podaplbs [ 2 ] ; real_T armybl4b3j [ 12 ] ; real_T omoyscdlkq [ 2 ] ;
real_T bvv2j1fvkj [ 2 ] ; real_T jyfm4clkt1 [ 2 ] ; real_T an1dy1scdv [ 2 ] ;
real_T ajilevaypm [ 2 ] ; real_T ndnjgxlg32 [ 2 ] ; real_T mampjjggm5 [ 2 ] ;
real_T c1zyhspvvj [ 2 ] ; real_T bozttf3lme [ 2 ] ; real_T lu2z2r1bq1 [ 2 ] ;
real_T au25a2kq45 [ 2 ] ; real_T n1g43fm50u [ 2 ] ; real_T jjhfp4nquz [ 2 ] ;
real_T j0sputa12i [ 2 ] ; real_T bpzbkldlw5 [ 2 ] ; real_T djt2dez0wq [ 2 ] ;
real_T chv5h33ild [ 15 ] ; real_T f5c0yrpl0m [ 15 ] ; real_T jee34x0zc4 [ 15
] ; real_T im051m03c0 [ 3 ] ; real_T ossqjsfts4 [ 3 ] ; real_T ivslgspzyl [ 3
] ; real_T hiamj1oevs ; real_T gx3o1bpm3a ; real_T gtdwc5tdzv [ 2 ] ; real_T
cg2tzvhg1s [ 2 ] ; real_T joe5wc3vru ; real_T belilpb3dk ; real_T bxlordfjyp
; real_T mva2o1cupz ; real_T lmqns2m2fd ; real_T du3cl5u2br ; real_T
aqayeibnbf [ 6 ] ; real_T mnhjgksiva [ 6 ] ; real_T p5euhzgph2 [ 6 ] ; real_T
nsygkjz001 [ 36 ] ; real_T pyssp52j4v [ 36 ] ; real_T fig1xy4s5q [ 6 ] ;
real_T lovsimzfsp [ 6 ] ; real_T dvkhmbnof2 [ 6 ] ; real_T gqi2mgds2b [ 6 ] ;
real_T ppo5lvnsbd [ 36 ] ; real_T aslzbhpikx [ 36 ] ; real_T m20bb5px11 [ 6 ]
; real_T dmaqihaxaq ; real_T dsaqs0egeg ; real_T hj3xpt5hh3 [ 12 ] ; real_T
fmtqkgzjo2 [ 2 ] ; real_T eqlst0fie1 [ 2 ] ; real_T jhyl0nmftj [ 2 ] ; real_T
dufp23q24f [ 2 ] ; real_T e5bm4mxp4y [ 2 ] ; real_T d2zjdsdy3t [ 2 ] ; real_T
atdwxldcaa [ 2 ] ; real_T kdrbhkothr [ 2 ] ; real_T l1nyqmvwst ; real_T
ca2tchanai ; real_T ooketywe0t ; real_T mjw0keqmwr ; real_T fb0bskoedk ;
real_T phfjeo0drc ; real_T d0fq4dyqzm ; real_T irfwmkoozp ; real_T gfix1az2dy
[ 6 ] ; real_T lajj3kiv0r [ 6 ] ; real_T musq314bsn [ 6 ] ; real_T oljl1r15sy
[ 36 ] ; real_T kdjra2pfq4 [ 36 ] ; real_T ox0f0pxtqm [ 6 ] ; real_T
eu121u4uj2 [ 6 ] ; real_T bgjp3vzt5z [ 6 ] ; real_T dn5twkxizj [ 6 ] ; real_T
eeiannul5v [ 36 ] ; real_T czjyxcctju [ 36 ] ; real_T m0wpx0tt4b [ 6 ] ;
real_T kr3nejsoss ; real_T jclkuzenpd ; real_T bpmgvfdh3p [ 12 ] ; real_T
ntmiect20q [ 2 ] ; real_T nw2qbjtrfg [ 2 ] ; real_T eysiy0scrq [ 2 ] ; real_T
cyoaoohsr1 [ 2 ] ; real_T d5kjlwmgrk [ 2 ] ; real_T i1zsver5ig [ 2 ] ; real_T
llgwidxzty [ 2 ] ; real_T dcluu2qq0c [ 2 ] ; real_T mfmirsuvi1 ; real_T
ajtyxihfqa ; real_T fev21ha45i ; real_T daodwibywh ; real_T lkyqetg5kb ;
real_T btc4odj1vw ; real_T c0pmpkzruv ; real_T jlansep42b ; real_T lbivgbnpeh
[ 6 ] ; real_T m54hyt4uuq [ 6 ] ; real_T lxl24bgnmj [ 6 ] ; real_T efyhshm0ot
[ 36 ] ; real_T gdfmrn5gpc [ 36 ] ; real_T jbncktdjxo [ 6 ] ; real_T
kwvqencn2m [ 6 ] ; real_T el0s1crasb [ 6 ] ; real_T iiijpho0bw [ 6 ] ; real_T
ef5r0lp3ux [ 36 ] ; real_T iuw551xzyz [ 36 ] ; real_T fqk1pcxz11 [ 6 ] ;
real_T guiwz4qjqi ; real_T nvrhieikes ; real_T p3bnpoi4ms [ 12 ] ; real_T
fat2ntucmp [ 2 ] ; real_T f23ygfhi2f [ 2 ] ; real_T jl5u0so5kr [ 2 ] ; real_T
m4oor1dqcu [ 2 ] ; real_T edonk3lpof [ 2 ] ; real_T c2d4vnjngq [ 2 ] ; real_T
ixb5n0f1pg [ 2 ] ; real_T mvd25m5wxn [ 2 ] ; real_T axapvnuown ; real_T
fk4euimlnu ; real_T gvdlmv0f2h ; real_T g4o2mykdy0 ; real_T ms3jvyzwa2 ;
real_T hftm5kpfrm ; real_T a0vktynhmg ; real_T ok1bkcbj54 ; real_T f0gxn5lxra
; } CStateAbsTol ; typedef struct { real_T dev4s5rhsx ; real_T kgqoabbasj ;
real_T ly02rzbkpp ; real_T elz2ohubbn ; real_T axhdhlbt0p ; } ZCV ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T AN
[ 16 ] ; real_T B [ 36 ] ; real_T BBT_inv [ 36 ] ; real_T BN [ 16 ] ; real_T
H [ 16 ] ; real_T J [ 9 ] ; real_T Ka ; real_T Kd ; real_T Kf ; real_T Kt ;
real_T Lq ; real_T M ; real_T Mb_P [ 2 ] ; real_T Mb_V [ 2 ] ; real_T Mu_P ;
real_T Mu_V ; real_T Observer_Gain ; real_T Observer_Gain1 ; real_T Q [ 36 ]
; real_T R [ 36 ] ; real_T RM_1 [ 16 ] ; real_T U_dot0_M [ 3 ] ; real_T
Upsilon_M [ 3 ] ; real_T alpha ; real_T alpha_P ; real_T alpha_Slid ; real_T
alpha_V ; real_T g ; real_T gamma_0 [ 36 ] ; real_T gamma_1 [ 36 ] ; real_T
k1 ; real_T k1o ; real_T k2 ; real_T k2o ; real_T rho_0 ; real_T rho_1 ;
real_T Gain2_Gain ; real_T Agent_Value ; real_T Constant1_Value [ 2 ] ;
real_T Constant2_Value [ 2 ] ; real_T Integrator3_IC [ 6 ] ; real_T
Memory2_InitialCondition [ 12 ] ; real_T TransportDelay1_Delay ; real_T
TransportDelay1_InitOutput ; real_T TransportDelay2_Delay ; real_T
TransportDelay2_InitOutput ; real_T Integrator_IC [ 3 ] ; real_T
Integrator5_IC [ 15 ] ; real_T Memory_InitialCondition [ 6 ] ; real_T
Integrator_IC_cfyiwll4yt [ 6 ] ; real_T Integrator1_IC [ 6 ] ; real_T
Integrator1_IC_p4daeceqsz [ 36 ] ; real_T Integrator_IC_luefkzx4q2 [ 36 ] ;
real_T Integrator2_IC [ 6 ] ; real_T Integrator3_IC_f4caslm1kl [ 6 ] ; real_T
Memory_InitialCondition_o1obpzfklx [ 6 ] ; real_T Integrator_IC_puas1ar3n0 [
6 ] ; real_T Integrator1_IC_jmeepbpmgb [ 6 ] ; real_T
Integrator1_IC_ansfzl4d2f [ 36 ] ; real_T Integrator_IC_g3bsi3eu3w [ 36 ] ;
real_T Integrator2_IC_dbnyypfy52 [ 6 ] ; real_T Integrator_IC_alldriazdb ;
real_T Integrator1_IC_mwmzuv30pe ; real_T Memory2_InitialCondition_or5foxlh2c
; real_T Integrator1_IC_lhgdj0vm4i [ 2 ] ; real_T Integrator2_IC_inq5mdqzms [
2 ] ; real_T Integrator_IC_h34fkmtcfd [ 12 ] ; real_T
Memory_InitialCondition_j0f1njy0lm [ 2 ] ; real_T Memory1_InitialCondition [
2 ] ; real_T Integrator1_IC_jwivcicess [ 2 ] ; real_T
Integrator1_IC_buluaviyk2 [ 2 ] ; real_T Integrator1_IC_fmwjvqa0ff [ 2 ] ;
real_T Memory_InitialCondition_e5i1evne12 [ 2 ] ; real_T
Memory_InitialCondition_c4k5ozqenb [ 2 ] ; real_T
Memory_InitialCondition_pzkv5ibku3 [ 2 ] ; real_T TransportDelay_Delay ;
real_T TransportDelay_InitOutput ; real_T TransportDelay1_Delay_bf3u4wh1iu ;
real_T TransportDelay1_InitOutput_jipm0sgfem ; real_T
Integrator2_IC_luckixqhsj [ 2 ] ; real_T Integrator2_IC_l52mdbixg1 [ 2 ] ;
real_T Integrator2_IC_eackpwye4n [ 2 ] ; real_T Integrator2_IC_ozsu04xgc2 [ 2
] ; real_T Memory3_InitialCondition [ 2 ] ; real_T
Memory_InitialCondition_a54hsbpodr [ 2 ] ; real_T Integrator2_IC_b4dyjqfehg [
2 ] ; real_T Integrator2_IC_gqrhtfqr04 [ 2 ] ; real_T
Integrator2_IC_frwewj40xa [ 2 ] ; real_T Memory1_InitialCondition_jn0l5tcosh
[ 2 ] ; real_T Memory1_InitialCondition_mouimmo5pb [ 2 ] ; real_T
Memory1_InitialCondition_msgkygoak0 [ 2 ] ; real_T Integrator_IC_bb2yzpjx1c [
2 ] ; real_T Integrator1_IC_dlyjrsv10d [ 2 ] ; real_T
Integrator1_IC_jknekxlqkt [ 2 ] ; real_T Integrator1_IC_jhcbpibgpz [ 2 ] ;
real_T Integrator1_IC_ccghmuj11r [ 2 ] ; real_T Integrator1_IC_ma130clpzn [ 2
] ; real_T Integrator5_IC_g5vs3m5xow [ 15 ] ; real_T
Integrator5_IC_nvscsito40 [ 15 ] ; real_T Integrator5_IC_i1zdqa2rj1 [ 15 ] ;
real_T Memory3_InitialCondition_df5j2apngc [ 15 ] ; real_T
Memory3_InitialCondition_il5t0irnrb [ 15 ] ; real_T
Memory3_InitialCondition_hjfhfwrpya [ 15 ] ; real_T
Memory3_InitialCondition_iydqxjne5u [ 15 ] ; real_T
Memory_InitialCondition_fm40pkxs2j [ 3 ] ; real_T DesiredPosition5_Value ;
real_T DesiredPosition6_Value ; real_T Switch2_Threshold ; real_T
DesiredPosition2_Value ; real_T DesiredPosition3_Value ; real_T
Switch1_Threshold ; real_T DesiredPosition1_Value ; real_T
DesiredPosition4_Value ; real_T Switch_Threshold ; real_T
Integrator_IC_jm5bas01zb [ 3 ] ; real_T Integrator_IC_hf52glxiva [ 3 ] ;
real_T Integrator_IC_heikj2oluh [ 3 ] ; real_T
Memory_InitialCondition_mfuzsoq04q [ 3 ] ; real_T
Memory_InitialCondition_ceftgwwddl [ 3 ] ; real_T
Memory_InitialCondition_e1qx5hl0e5 [ 3 ] ; real_T Constant5_Value ; real_T
Memory1_InitialCondition_pueehz5zfr [ 2 ] ; real_T Integrator1_IC_pqkea5opj5
; real_T Gain_Gain ; real_T Integrator_IC_gppaao1n14 ; real_T
Integrator_IC_immn4e5mqy [ 2 ] ; real_T Integrator1_IC_nnr4vlcuc2 [ 2 ] ;
real_T Integrator1_IC_jo4u2yf5bh ; real_T Gain_Gain_nk254mxa1l ; real_T
Integrator_IC_m1rvafnpvi ; real_T Memory_InitialCondition_g42qsp0l1h [ 2 ] ;
real_T Memory1_InitialCondition_gelzc052fw [ 2 ] ; real_T
Integrator1_IC_juteqbkjag ; real_T Gain_Gain_ikzgx3yo5o ; real_T
Integrator_IC_przqtc044z ; real_T Memory_InitialCondition_nt0x1sjcbl [ 2 ] ;
real_T Memory1_InitialCondition_ogwkymdxxn [ 2 ] ; real_T
Integrator1_IC_ap5ygu2w0o ; real_T Gain_Gain_odpbsclc5n ; real_T
Integrator_IC_murofkqkz0 ; real_T Memory_InitialCondition_kvnigjfe1g [ 2 ] ;
real_T Memory1_InitialCondition_on2mrgcv1u [ 2 ] ; real_T
Agent_Value_kelyffe2iy ; real_T Constant1_Value_leogo0eo3x [ 2 ] ; real_T
Constant2_Value_lx1k4y1rld [ 2 ] ; real_T Integrator3_IC_bat4zspnyz [ 6 ] ;
real_T Memory2_InitialCondition_cllveugtjf [ 12 ] ; real_T
TransportDelay1_Delay_ksw2xmlzvn ; real_T
TransportDelay1_InitOutput_io3d45ar21 ; real_T
TransportDelay2_Delay_muwonazjkp ; real_T
TransportDelay2_InitOutput_kznqd41xd4 ; real_T
Memory_InitialCondition_mnixxfx3nr [ 6 ] ; real_T Integrator_IC_la40lha0dg [
6 ] ; real_T Integrator1_IC_bvirkw3omb [ 6 ] ; real_T
Integrator1_IC_eusbq4wn0r [ 36 ] ; real_T Integrator_IC_irtz3fkjrz [ 36 ] ;
real_T Integrator2_IC_azzaqyagzs [ 6 ] ; real_T Integrator3_IC_hcz3efl52b [ 6
] ; real_T Memory_InitialCondition_kch2d0yyuo [ 6 ] ; real_T
Integrator_IC_ccbgpins5s [ 6 ] ; real_T Integrator1_IC_pthm2elxch [ 6 ] ;
real_T Integrator1_IC_c3juh3gqkf [ 36 ] ; real_T Integrator_IC_jxexmo2voq [
36 ] ; real_T Integrator2_IC_hxbmyx5eah [ 6 ] ; real_T
Integrator_IC_m32gmcozch ; real_T Integrator1_IC_jgedvswz2a ; real_T
Memory2_InitialCondition_mvgnd5dmek ; real_T Integrator_IC_jawnn4hfs5 [ 12 ]
; real_T Integrator2_IC_at433khehz [ 2 ] ; real_T Integrator2_IC_cta555k1jf [
2 ] ; real_T Integrator2_IC_ayj33d1kgk [ 2 ] ; real_T
Integrator2_IC_ixgs0iiwuj [ 2 ] ; real_T Memory3_InitialCondition_ak45y034mz
[ 2 ] ; real_T Integrator1_IC_jw3s5b3wbf [ 2 ] ; real_T
Integrator1_IC_mnm25x5z0c [ 2 ] ; real_T Integrator1_IC_bog1m1eab0 [ 2 ] ;
real_T Integrator1_IC_cgdc4o0005 [ 2 ] ; real_T Integrator1_IC_galmbeklcp ;
real_T Gain_Gain_mutzwvqirh ; real_T Integrator_IC_lqe0iyuxyo ; real_T
Integrator1_IC_fx0ci3hz34 ; real_T Gain_Gain_hmnuazlmcb ; real_T
Integrator_IC_hr1rckzr4f ; real_T Integrator1_IC_bzcdkgnkfw ; real_T
Gain_Gain_aphuk1riyf ; real_T Integrator_IC_hfcstb1haw ; real_T
Integrator1_IC_ocig5embg4 ; real_T Gain_Gain_gamljvupvn ; real_T
Integrator_IC_dtb4wwgoan ; real_T Agent_Value_isepnlmbdh ; real_T
Constant1_Value_bg3mr2ch10 [ 2 ] ; real_T Constant2_Value_pdqwrfjlqe [ 2 ] ;
real_T Integrator3_IC_pjrjnyinks [ 6 ] ; real_T
Memory2_InitialCondition_ox3hrrh33c [ 12 ] ; real_T
TransportDelay1_Delay_ppziigp4pi ; real_T
TransportDelay1_InitOutput_irtprymfig ; real_T
TransportDelay2_Delay_pcfeeikpk2 ; real_T
TransportDelay2_InitOutput_lmsg2pl2kj ; real_T
Memory_InitialCondition_kojwdv1sdm [ 6 ] ; real_T Integrator_IC_a5nuunpklh [
6 ] ; real_T Integrator1_IC_lta2vdh0b5 [ 6 ] ; real_T
Integrator1_IC_jl3wybgxkk [ 36 ] ; real_T Integrator_IC_fvj1kiy40w [ 36 ] ;
real_T Integrator2_IC_datw0m0fum [ 6 ] ; real_T Integrator3_IC_atv2wvjo44 [ 6
] ; real_T Memory_InitialCondition_oimiahzldu [ 6 ] ; real_T
Integrator_IC_cqcfpzgjin [ 6 ] ; real_T Integrator1_IC_bopood34gi [ 6 ] ;
real_T Integrator1_IC_p2dirrdsf0 [ 36 ] ; real_T Integrator_IC_ltadafrs2p [
36 ] ; real_T Integrator2_IC_culhmos0yl [ 6 ] ; real_T
Integrator_IC_jpe5v3shtd ; real_T Integrator1_IC_ekqbzs401u ; real_T
Memory2_InitialCondition_hek5amttia ; real_T Integrator_IC_gzbylzelej [ 12 ]
; real_T Integrator2_IC_nxpf2pqtyt [ 2 ] ; real_T Integrator2_IC_pib2yu51bl [
2 ] ; real_T Integrator2_IC_pywmt1vi3k [ 2 ] ; real_T
Integrator2_IC_nlyzfo2eo2 [ 2 ] ; real_T Memory3_InitialCondition_fm5muett4l
[ 2 ] ; real_T Integrator1_IC_gsbwkeuy32 [ 2 ] ; real_T
Integrator1_IC_j55wlx1pla [ 2 ] ; real_T Integrator1_IC_d2dmy2bonh [ 2 ] ;
real_T Integrator1_IC_ne5nj2sehc [ 2 ] ; real_T Integrator1_IC_oy1tpyez4k ;
real_T Gain_Gain_acstczzfy2 ; real_T Integrator_IC_ja4tf50vgl ; real_T
Integrator1_IC_minhdvdh30 ; real_T Gain_Gain_kma3okcfj1 ; real_T
Integrator_IC_dld3rufdd5 ; real_T Integrator1_IC_br0lavttge ; real_T
Gain_Gain_k45mubfrmr ; real_T Integrator_IC_etl3cet4i2 ; real_T
Integrator1_IC_b5usglq0ml ; real_T Gain_Gain_ofmtkpdy0q ; real_T
Integrator_IC_b2w1tqip2f ; real_T Agent_Value_og3en2mdcn ; real_T
Constant1_Value_d1t3cyklvs [ 2 ] ; real_T Constant2_Value_oeh4ce2iba [ 2 ] ;
real_T Integrator3_IC_hkv2shesyg [ 6 ] ; real_T
Memory2_InitialCondition_dsgb11uldn [ 12 ] ; real_T
TransportDelay1_Delay_kvdadosi3i ; real_T
TransportDelay1_InitOutput_mvsywcmphq ; real_T
TransportDelay2_Delay_odn4ujxefs ; real_T
TransportDelay2_InitOutput_gcfy4mzc0f ; real_T
Memory_InitialCondition_nxqwvrpsn1 [ 6 ] ; real_T Integrator_IC_kix2wy0eko [
6 ] ; real_T Integrator1_IC_arlagfg51h [ 6 ] ; real_T
Integrator1_IC_odxe20ktyc [ 36 ] ; real_T Integrator_IC_mvuvpk12n1 [ 36 ] ;
real_T Integrator2_IC_hyg2lufwlm [ 6 ] ; real_T Integrator3_IC_ph5vo1wzew [ 6
] ; real_T Memory_InitialCondition_ksrwjf202x [ 6 ] ; real_T
Integrator_IC_emuquk5caa [ 6 ] ; real_T Integrator1_IC_bjc5tuilet [ 6 ] ;
real_T Integrator1_IC_bobsrkoroo [ 36 ] ; real_T Integrator_IC_ogv01dnfdg [
36 ] ; real_T Integrator2_IC_m1d2qyymbe [ 6 ] ; real_T
Integrator_IC_owq0oqmk1f ; real_T Integrator1_IC_nih23smxre ; real_T
Memory2_InitialCondition_d2b5f3zpoa ; real_T Integrator_IC_fl4lytvimx [ 12 ]
; real_T Integrator2_IC_mbl4x3euf4 [ 2 ] ; real_T Integrator2_IC_dcmgupiz3t [
2 ] ; real_T Integrator2_IC_ksdgd0umq4 [ 2 ] ; real_T
Integrator2_IC_ediny1ej1a [ 2 ] ; real_T Memory3_InitialCondition_ieed2vz1s2
[ 2 ] ; real_T Integrator1_IC_kd3xpoijkg [ 2 ] ; real_T
Integrator1_IC_kesvi0bnff [ 2 ] ; real_T Integrator1_IC_oa0pqhkumw [ 2 ] ;
real_T Integrator1_IC_ng3itygk5x [ 2 ] ; real_T Integrator1_IC_hypargdhjw ;
real_T Gain_Gain_nfjg5pily2 ; real_T Integrator_IC_oxt3eyodwq ; real_T
Integrator1_IC_cyyevy5f4u ; real_T Gain_Gain_n2wlxh3aqj ; real_T
Integrator_IC_fnbynjhgz2 ; real_T Integrator1_IC_btfuanhu4f ; real_T
Gain_Gain_ijdkxsl31m ; real_T Integrator_IC_f2beosksxv ; real_T
Integrator1_IC_ofl0ycjsiu ; real_T Gain_Gain_injbjuibga ; real_T
Integrator_IC_ptvmn4pn2v ; real_T Gain2_Gain_ibspipwmaz ; real_T
TransportDelay2_Delay_ecl5sy0jio ; real_T
TransportDelay2_InitOutput_hl0tfnim04 ; real_T Switch_Threshold_ireer3ad0m ;
real_T FromWs_Time0 [ 6 ] ; real_T FromWs_Data0 [ 6 ] ; real_T TransferFcn2_A
; real_T TransferFcn2_C ; real_T FromWorkspace_Time0 [ 601 ] ; real_T
FromWorkspace_Data0 [ 601 ] ; real_T Gain_Gain_kzy0ayrwxy ; real_T
FromWorkspace1_Time0 [ 601 ] ; real_T FromWorkspace1_Data0 [ 601 ] ; real_T
Gain1_Gain ; real_T FromWorkspace3_Time0 [ 601 ] ; real_T
FromWorkspace3_Data0 [ 601 ] ; real_T DesiredPosition4_Value_idpjit2rxr ;
real_T Switch_Threshold_bpzjw1hzqd ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
Cooperative_Quad_09_VelEst_02_GetCAPIStaticMap ( void ) ; extern SimStruct *
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
