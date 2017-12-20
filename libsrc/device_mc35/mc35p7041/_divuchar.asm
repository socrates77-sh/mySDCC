;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Wed Dec 20 12:01:11 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../../libsdcc_mc35/_divuchar.c"
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
	global	__divuchar

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__divuchar_0	udata
r0x1000	res	1
r0x1001	res	1
r0x1002	res	1
r0x1003	res	1
r0x1004	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

;@Allocation info for local variables in function '_divuchar'
;@_divuchar b                         Allocated to registers r0x1001 ;size:1
;@_divuchar a                         Allocated to registers r0x1000 ;size:1
;@_divuchar result                    Allocated to registers r0x1002 ;size:1
;@_divuchar mask                      Allocated to registers r0x1003 ;size:1
;@end Allocation info for local variables in function '_divuchar';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code__divuchar	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __divuchar	;Function start
; 2 exit points
;has an exit
;9 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;; Starting pCode block
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:30:  _entry($12) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:30: 	proc __divuchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
__divuchar	;Function start
; 2 exit points
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:30: iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_a_1_1}[r0x1000 ] = recv __divuchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
;	.line	30; "../../libsdcc_mc35/_divuchar.c"	_divuchar (unsigned char a, unsigned char b)
	MOVRA	r0x1000
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:30: iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] = recv __divuchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:32: 	iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_result_1_2}[r0x1002 ] := 0x0 {const-unsigned-char literal}
;	.line	32; "../../libsdcc_mc35/_divuchar.c"	unsigned char result = 0;
	CLRR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:33: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] := 0x1 {const-unsigned-char literal}
;	.line	33; "../../libsdcc_mc35/_divuchar.c"	unsigned char mask = 0x01;
	MOVAI	0x01
	MOVRA	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:36: 	if iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] != 0 goto _whilecontinue_0($3)
;	.line	36; "../../libsdcc_mc35/_divuchar.c"	if (!b) return (unsigned char)-1;
	MOVAI	0x00
	ORAR	r0x1001
	JBSET	PFLAG,0
	GOTO	_00107_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:36: 	ret 0xff {unsigned-char literal}
	MOVAI	0xff
	GOTO	_00115_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:40:  _whilecontinue_0($3) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:40: 	iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1006 r0x1007 ] = (unsigned-long-int register)iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ]
_00107_DS_
;	.line	40; "../../libsdcc_mc35/_divuchar.c"	while (!(b & (1UL << (8*sizeof(unsigned char)-1)))) {
	MOVAR	r0x1001
	MOVRA	r0x1004
;;1	CLRR	r0x1005
;;1	CLRR	r0x1006
;;1	CLRR	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:40: 	iTemp5 [k11 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1006 r0x1007 ] & 0x80 {unsigned-long-int literal}
	JBCLR	r0x1004,7
	GOTO	_00112_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:40: 	if iTemp5 [k11 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} != 0 goto _whilecontinue_1($8)
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:41: 	iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] = iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] << 0x1 {const-unsigned-char literal}
;	.line	41; "../../libsdcc_mc35/_divuchar.c"	b <<= 1;
	BCLR	PFLAG,2
	RLR	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:42: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] = iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] << 0x1 {const-unsigned-char literal}
;	.line	42; "../../libsdcc_mc35/_divuchar.c"	mask <<= 1;
	BCLR	PFLAG,2
	RLR	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:42: 	 goto _whilecontinue_0($3)
	GOTO	_00107_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:47:  _whilecontinue_1($8) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:47: 	if iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] == 0 goto _whilebreak_1($10)
_00112_DS_
;	.line	47; "../../libsdcc_mc35/_divuchar.c"	while (mask) {
	MOVAI	0x00
	ORAR	r0x1003
	JBCLR	PFLAG,0
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:48: 	iTemp8 [k14 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_a_1_1}[r0x1000 ] < iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ]
;	.line	48; "../../libsdcc_mc35/_divuchar.c"	if (a >= b) {
	MOVAR	r0x1001
	XCH	r0x1000
	ASUBRA	r0x1000
	XCH	r0x1000
	JBSET	PFLAG,2
	GOTO	_00111_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:48: 	if iTemp8 [k14 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_1($7)
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:49: 	iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_result_1_2}[r0x1002 ] = iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_result_1_2}[r0x1002 ] + iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ]
;	.line	49; "../../libsdcc_mc35/_divuchar.c"	result += mask;
	MOVAR	r0x1003
	ADDRA	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:50: 	iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_a_1_1}[r0x1000 ] = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_a_1_1}[r0x1000 ] - iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ]
;	.line	50; "../../libsdcc_mc35/_divuchar.c"	a -= b;
	MOVAR	r0x1001
	XCH	r0x1000
	ASUBAR	r0x1000
	XCH	r0x1000
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:50:  _iffalse_1($7) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:52: 	iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] = iTemp1 [k4 lr4:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_b_1_1}[r0x1001 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5270: shCount=1, size=1, sign=0, same=1, offr=0
_00111_DS_
;	.line	52; "../../libsdcc_mc35/_divuchar.c"	b >>= 1;
	BCLR	PFLAG,2
	RRR	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:53: 	iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] = iTemp3 [k8 lr6:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_mask_1_2}[r0x1003 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5270: shCount=1, size=1, sign=0, same=1, offr=0
;	.line	53; "../../libsdcc_mc35/_divuchar.c"	mask >>= 1;
	BCLR	PFLAG,2
	RRR	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:53: 	 goto _whilecontinue_1($8)
	GOTO	_00112_DS_
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:53:  _whilebreak_1($10) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:56: 	ret iTemp2 [k6 lr5:35 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __divuchar_result_1_2}[r0x1002 ]
_00114_DS_
;	.line	56; "../../libsdcc_mc35/_divuchar.c"	return result;
	MOVAR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:56:  _return($11) :
;;[ICODE] ../../libsdcc_mc35/_divuchar.c:56: 	eproc __divuchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
_00115_DS_
	RETURN	
; exit point of __divuchar


;	code size estimation:
;	   44+    0 =    44 instructions (   88 byte)

	end
