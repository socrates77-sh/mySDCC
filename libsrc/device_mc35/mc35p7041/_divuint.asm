;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Wed Dec 20 12:01:11 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../../libsdcc_mc35/_divuint.c"
	list	p=2K7041
	radix dec
	include "2K7041.inc"
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
	global	__divuint

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__divuint_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1003	res	1
r0x1002	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
r0x1009	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

;@Allocation info for local variables in function '_divuint'
;@_divuint b                         Allocated to registers r0x1003 r0x1002 ;size:2
;@_divuint a                         Allocated to registers r0x1001 r0x1000 ;size:2
;@_divuint result                    Allocated to registers r0x1004 r0x1005 ;size:2
;@_divuint mask                      Allocated to registers r0x1006 r0x1007 ;size:2
;@end Allocation info for local variables in function '_divuint';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code__divuint	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __divuint	;Function start
; 2 exit points
;has an exit
;15 compiler assigned registers:
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
;   r0x100B
;; Starting pCode block
;;[ICODE] ../../libsdcc_mc35/_divuint.c:30:  _entry($12) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:30: 	proc __divuint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
__divuint	;Function start
; 2 exit points
;;[ICODE] ../../libsdcc_mc35/_divuint.c:30: iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_a_1_1}[r0x1000 r0x1001 ] = recv __divuint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;	.line	30; "../../libsdcc_mc35/_divuint.c"	_divuint (unsigned int a, unsigned int b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divuint.c:30: iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] = recv __divuint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divuint.c:32: 	iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_result_1_2}[r0x1004 r0x1005 ] := 0x0 {unsigned-int literal}
;	.line	32; "../../libsdcc_mc35/_divuint.c"	unsigned int result = 0;
	CLRR	r0x1004
	CLRR	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divuint.c:33: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] := 0x1 {unsigned-int literal}
;	.line	33; "../../libsdcc_mc35/_divuint.c"	unsigned int mask = 0x01;
	MOVAI	0x01
	MOVRA	r0x1006
	CLRR	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divuint.c:36: 	if iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] != 0 goto _whilecontinue_0($3)
;	.line	36; "../../libsdcc_mc35/_divuint.c"	if (!b) return (unsigned int)-1;
	MOVAR	r0x1003
	ORAR	r0x1002
	JBSET	PFLAG,0
	GOTO	_00107_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:36: 	ret 0xffff {unsigned-int literal}
	MOVAI	0xff
	MOVRA	STK00
	MOVAI	0xff
	GOTO	_00115_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:40:  _whilecontinue_0($3) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:40: 	iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1008 r0x1009 r0x100A r0x100B ] = (unsigned-long-int register)iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ]
_00107_DS_
;	.line	40; "../../libsdcc_mc35/_divuint.c"	while (!(b & (1UL << (8*sizeof(unsigned int)-1)))) {
	MOVAR	r0x1003
;;1	MOVRA	r0x1008
	MOVAR	r0x1002
	MOVRA	r0x1009
;;1	CLRR	r0x100A
;;1	CLRR	r0x100B
;;[ICODE] ../../libsdcc_mc35/_divuint.c:40: 	iTemp5 [k11 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1008 r0x1009 r0x100A r0x100B ] & 0x8000 {unsigned-long-int literal}
	JBCLR	r0x1009,7
	GOTO	_00112_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:40: 	if iTemp5 [k11 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} != 0 goto _whilecontinue_1($8)
;;[ICODE] ../../libsdcc_mc35/_divuint.c:41: 	iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] = iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] << 0x1 {const-unsigned-char literal}
;	.line	41; "../../libsdcc_mc35/_divuint.c"	b <<= 1;
	BCLR	PFLAG,2
	RLR	r0x1003
	RLR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divuint.c:42: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] = iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] << 0x1 {const-unsigned-char literal}
;	.line	42; "../../libsdcc_mc35/_divuint.c"	mask <<= 1;
	BCLR	PFLAG,2
	RLR	r0x1006
	RLR	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divuint.c:42: 	 goto _whilecontinue_0($3)
	GOTO	_00107_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:47:  _whilecontinue_1($8) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:47: 	if iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] == 0 goto _whilebreak_1($10)
_00112_DS_
;	.line	47; "../../libsdcc_mc35/_divuint.c"	while (mask) {
	MOVAR	r0x1006
	ORAR	r0x1007
	JBCLR	PFLAG,0
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:48: 	iTemp8 [k14 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_a_1_1}[r0x1000 r0x1001 ] < iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ]
;	.line	48; "../../libsdcc_mc35/_divuint.c"	if (a >= b) {
	MOVAR	r0x1002
	XCH	r0x1000
	ASUBRA	r0x1000
	XCH	r0x1000
	JBSET	PFLAG,0
	GOTO	_00129_DS_
	MOVAR	r0x1003
	XCH	r0x1001
	ASUBRA	r0x1001
	XCH	r0x1001
_00129_DS_
	JBSET	PFLAG,2
	GOTO	_00111_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/_divuint.c:48: 	if iTemp8 [k14 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_1($7)
;;[ICODE] ../../libsdcc_mc35/_divuint.c:49: 	iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_result_1_2}[r0x1004 r0x1005 ] = iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_result_1_2}[r0x1004 r0x1005 ] + iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ]
;	.line	49; "../../libsdcc_mc35/_divuint.c"	result += mask;
	MOVAR	r0x1006
	ADDRA	r0x1004
	MOVAR	r0x1007
	JBCLR	PFLAG,2
	JZAR	r0x1007
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divuint.c:50: 	iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_a_1_1}[r0x1000 r0x1001 ] = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_a_1_1}[r0x1000 r0x1001 ] - iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ]
;	.line	50; "../../libsdcc_mc35/_divuint.c"	a -= b;
	MOVAR	r0x1003
	XCH	r0x1001
	ASUBAR	r0x1001
	XCH	r0x1001
	MOVAR	r0x1002
	XCH	r0x1000
	JBSET	PFLAG,2
	JZR	r0x1000
	ASUBAR	r0x1000
	XCH	r0x1000
;;[ICODE] ../../libsdcc_mc35/_divuint.c:50:  _iffalse_1($7) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:52: 	iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] = iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_b_1_1}[r0x1002 r0x1003 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5270: shCount=1, size=2, sign=0, same=1, offr=0
_00111_DS_
;	.line	52; "../../libsdcc_mc35/_divuint.c"	b >>= 1;
	BCLR	PFLAG,2
	RRR	r0x1002
	RRR	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divuint.c:53: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] = iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_mask_1_2}[r0x1006 r0x1007 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5270: shCount=1, size=2, sign=0, same=1, offr=0
;	.line	53; "../../libsdcc_mc35/_divuint.c"	mask >>= 1;
	BCLR	PFLAG,2
	RRR	r0x1007
	RRR	r0x1006
;;[ICODE] ../../libsdcc_mc35/_divuint.c:53: 	 goto _whilecontinue_1($8)
	GOTO	_00112_DS_
;;[ICODE] ../../libsdcc_mc35/_divuint.c:53:  _whilebreak_1($10) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:56: 	ret iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __divuint_result_1_2}[r0x1004 r0x1005 ]
_00114_DS_
;	.line	56; "../../libsdcc_mc35/_divuint.c"	return result;
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divuint.c:56:  _return($11) :
;;[ICODE] ../../libsdcc_mc35/_divuint.c:56: 	eproc __divuint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
_00115_DS_
	RETURN	
; exit point of __divuint


;	code size estimation:
;	   75+    0 =    75 instructions (  150 byte)

	end
