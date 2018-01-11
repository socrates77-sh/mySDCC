;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Thu Jan 04 10:24:31 2018
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../../libsdcc_mc35/_mulint.c"
	list	p=7011
	radix dec
	include "7011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------

	extern STK06
	extern STK05
	extern STK04
	extern STK03
	extern STK02
	extern STK01
	extern STK00
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	__mulint

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__mulint_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1003	res	1
r0x1002	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
r0x1008	res	1
r0x100A	res	1
r0x1009	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

;@Allocation info for local variables in function '_mulint'
;@_mulint b                         Allocated to registers r0x1003 r0x1002 ;size:2
;@_mulint a                         Allocated to registers r0x1001 r0x1000 ;size:2
;@_mulint result                    Allocated to registers r0x1004 r0x1005 ;size:2
;@_mulint i                         Allocated to registers r0x1006 ;size:1
;@end Allocation info for local variables in function '_mulint';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code__mulint	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __mulint	;Function start
; 2 exit points
;has an exit
;14 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   STK01
;   r0x1002
;   STK02
;   r0x1003
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;   r0x1008
;   r0x1009
;   r0x100A
;; Starting pCode block
;;[ICODE] ../../libsdcc_mc35/_mulint.c:33:  _entry($16) :
;;[ICODE] ../../libsdcc_mc35/_mulint.c:33: 	proc __mulint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
__mulint	;Function start
; 2 exit points
;;[ICODE] ../../libsdcc_mc35/_mulint.c:33: iTemp0 [k2 lr3:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_a_1_1}[r0x1000 r0x1001 ] = recv __mulint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
;	.line	33; "../../libsdcc_mc35/_mulint.c"	_mulint (int a, int b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_mulint.c:33: iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_b_1_1}[r0x1002 r0x1003 ] = recv __mulint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../../libsdcc_mc35/_mulint.c:35: 	iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ] := 0x0 {int literal}
;	.line	35; "../../libsdcc_mc35/_mulint.c"	int result = 0;
	CLRR	r0x1004
	CLRR	r0x1005
;;[ICODE] ../../libsdcc_mc35/_mulint.c:39: 	iTemp3 [k8 lr6:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mulint_i_1_2}[r0x1006 ] := 0x8 {unsigned-char literal}
;	.line	39; "../../libsdcc_mc35/_mulint.c"	for (i = 0; i < 8u; i++) {
	MOVAI	0x08
	MOVRA	r0x1006
;;[ICODE] ../../libsdcc_mc35/_mulint.c:39:  _forcontinue_0($14) :
;;[ICODE] ../../libsdcc_mc35/_mulint.c:41: 	iTemp4 [k10 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1007 r0x1008 ] = (unsigned-int register)iTemp0 [k2 lr3:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_a_1_1}[r0x1000 r0x1001 ]
_00118_DS_
;	.line	41; "../../libsdcc_mc35/_mulint.c"	if (a & 0x0001u) result += b;
	MOVAR	r0x1001
	MOVRA	r0x1007
	MOVAR	r0x1000
	MOVRA	r0x1008
;;[ICODE] ../../libsdcc_mc35/_mulint.c:41: 	iTemp5 [k11 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register} = iTemp4 [k10 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1007 r0x1008 ] & 0x1 {const-unsigned-int literal}
	JBSET	r0x1007,0
	GOTO	_00109_DS_
;;[ICODE] ../../libsdcc_mc35/_mulint.c:41: 	if iTemp5 [k11 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register} == 0 goto _andif_0($5)
;;[ICODE] ../../libsdcc_mc35/_mulint.c:41: 	iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ] = iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ] + iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_b_1_1}[r0x1002 r0x1003 ]
	MOVAR	r0x1003
	ADDRA	r0x1004
	MOVAR	r0x1002
	JBCLR	PFLAG,2
	JZAR	r0x1002
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42:  _andif_0($5) :
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	iTemp7 [k13 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] = (unsigned-long-int register)iTemp0 [k2 lr3:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_a_1_1}[r0x1000 r0x1001 ]
_00109_DS_
;	.line	42; "../../libsdcc_mc35/_mulint.c"	if (sizeof (a) > 1 && (a & 0x00000100ul)) result += (b << 8u);
	MOVAR	r0x1001
	MOVRA	r0x1007
	MOVAR	r0x1000
	MOVRA	r0x1008
	MOVAI	0x00
	JBCLR	r0x1008,7
	MOVAI	0xff
	MOVRA	r0x1009
	MOVRA	r0x100A
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	iTemp8 [k14 lr16:17 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp7 [k13 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] & 0x100 {const-unsigned-long-int literal}
	JBSET	r0x1008,0
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	if iTemp8 [k14 lr16:17 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _iffalse_3($10)
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	iTemp10 [k16 lr18:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1007 r0x1008 ] = iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_b_1_1}[r0x1002 r0x1003 ] << 0x8 {const-unsigned-int literal}
;;100	MOVAR	r0x1003
	CLRR	r0x1007
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	iTemp11 [k17 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1009 r0x100A ] = (unsigned-int register)iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	r0x100A
	MOVAR	r0x1005
	MOVRA	r0x1005
	MOVRA	r0x1009
;;[ICODE] ../../libsdcc_mc35/_mulint.c:42: 	iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ] = iTemp11 [k17 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1009 r0x100A ] + iTemp10 [k16 lr18:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int register}[r0x1007 r0x1008 ]
	MOVAI	0x00
	ADDAR	r0x100A
	MOVRA	r0x1004
;;101	MOVAR	r0x1009
;;99	MOVAR	r0x1008
	MOVAR	r0x1003
	MOVRA	r0x1008
	JBCLR	PFLAG,2
	JZAR	r0x1008
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_mulint.c:44:  _iffalse_3($10) :
;;[ICODE] ../../libsdcc_mc35/_mulint.c:45: 	iTemp19 [k25 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1007 r0x1008 ] = (unsigned-int fixed)iTemp0 [k2 lr3:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_a_1_1}[r0x1000 r0x1001 ]
_00114_DS_
;	.line	45; "../../libsdcc_mc35/_mulint.c"	a = ((unsigned int)a) >> 1u;
	MOVAR	r0x1001
	MOVRA	r0x1007
	MOVAR	r0x1000
	MOVRA	r0x1008
;;[ICODE] ../../libsdcc_mc35/_mulint.c:45: 	iTemp0 [k2 lr3:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_a_1_1}[r0x1000 r0x1001 ] = iTemp19 [k25 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1007 r0x1008 ] >> 0x1 {const-unsigned-int literal}
;;shiftRight_Left2ResultLit:5270: shCount=1, size=2, sign=0, same=0, offr=0
	BCLR	PFLAG,2
	RRAR	r0x1008
	MOVRA	r0x1000
	RRAR	r0x1007
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_mulint.c:46: 	iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_b_1_1}[r0x1002 r0x1003 ] = iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_b_1_1}[r0x1002 r0x1003 ] << 0x1 {const-unsigned-int literal}
;	.line	46; "../../libsdcc_mc35/_mulint.c"	b <<= 1u;
	BCLR	PFLAG,2
	RLR	r0x1003
	RLR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_mulint.c:46: 	iTemp23 [k29 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char register}[r0x1007 ] = (char register)iTemp3 [k8 lr6:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mulint_i_1_2}[r0x1006 ]
	MOVAR	r0x1006
	MOVRA	r0x1007
;;[ICODE] ../../libsdcc_mc35/_mulint.c:46: 	iTemp3 [k8 lr6:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mulint_i_1_2}[r0x1006 ] = iTemp23 [k29 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char register}[r0x1007 ] - 0x1 {const-char literal}
	DJZAR	r0x1007
	NOP	
	MOVRA	r0x1006
;;[ICODE] ../../libsdcc_mc35/_mulint.c:39: 	if iTemp3 [k8 lr6:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mulint_i_1_2}[r0x1006 ] != 0 goto _forcontinue_0($14)
;	.line	39; "../../libsdcc_mc35/_mulint.c"	for (i = 0; i < 8u; i++) {
	MOVAI	0x00
	ORAR	r0x1006
	JBSET	PFLAG,0
	GOTO	_00118_DS_
;;[ICODE] ../../libsdcc_mc35/_mulint.c:49: 	ret iTemp2 [k6 lr5:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __mulint_result_1_2}[r0x1004 r0x1005 ]
;	.line	49; "../../libsdcc_mc35/_mulint.c"	return result;
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
;;[ICODE] ../../libsdcc_mc35/_mulint.c:49:  _return($15) :
;;[ICODE] ../../libsdcc_mc35/_mulint.c:49: 	eproc __mulint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
	RETURN	
; exit point of __mulint


;	code size estimation:
;	   73+    0 =    73 instructions (  146 byte)

	end
