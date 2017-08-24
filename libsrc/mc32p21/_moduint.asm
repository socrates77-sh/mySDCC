;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:32:14 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_moduint.c"
	list	p=32p21
	radix dec
	include "mc32p21.inc"
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
	global	__moduint

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__moduint_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1003	res	1
r0x1002	res	1
r0x1004	res	1
r0x1006	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code__moduint	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __moduint	;Function start
; 2 exit points
;has an exit
;12 compiler assigned registers:
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
;; Starting pCode block
;;[ICODE] ../libsdcc/_moduint.c:30:  _entry($12) :
;;[ICODE] ../libsdcc/_moduint.c:30: 	proc __moduint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
__moduint	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_moduint.c:30: iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_a_1_1}[r0x1000 r0x1001 ] = recv __moduint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;	.line	30; "../libsdcc/_moduint.c"	_moduint (unsigned int a, unsigned int b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/_moduint.c:30: iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] = recv __moduint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_moduint.c:35: 	if iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] != 0 goto preHeaderLbl0($15)
;	.line	35; "../libsdcc/_moduint.c"	if (!b) return (unsigned int)-1;
	MOVAR	r0x1003
	ORAR	r0x1002
	JBSET	STATUS,2
	GOTO	_00119_DS_
;;[ICODE] ../libsdcc/_moduint.c:35: 	ret 0xffff {unsigned-int literal}
	MOVAI	0xff
	MOVRA	STK00
	MOVAI	0xff
	GOTO	_00115_DS_
;;[ICODE] ../libsdcc/_moduint.c:39:  preHeaderLbl0($15) :
;;[ICODE] ../libsdcc/_moduint.c:39: 	iTemp6 [k11 lr8:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] := 0x1 {const-unsigned-char literal}
_00119_DS_
;	.line	39; "../libsdcc/_moduint.c"	while (!(b & (1UL << (8*sizeof(unsigned int)-1)))) {
	MOVAI	0x01
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/_moduint.c:39:  _whilecontinue_0($3) :
;;[ICODE] ../libsdcc/_moduint.c:39: 	iTemp3 [k8 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1005 r0x1006 r0x1007 r0x1008 ] = (unsigned-long-int register)iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ]
_00107_DS_
	MOVAR	r0x1003
;;1	MOVRA	r0x1005
	MOVAR	r0x1002
	MOVRA	r0x1006
;;1	CLRR	r0x1007
;;1	CLRR	r0x1008
;;[ICODE] ../libsdcc/_moduint.c:39: 	iTemp4 [k9 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp3 [k8 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1005 r0x1006 r0x1007 r0x1008 ] & 0x8000 {unsigned-long-int literal}
	JBCLR	r0x1006,7
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/_moduint.c:39: 	if iTemp4 [k9 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} != 0 goto preHeaderLbl1($18)
;;[ICODE] ../libsdcc/_moduint.c:40: 	iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] = iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] << 0x1 {const-unsigned-char literal}
;	.line	40; "../libsdcc/_moduint.c"	b <<= 1;
	BCLR	STATUS,0
	RLR	r0x1003
	RLR	r0x1002
;;[ICODE] ../libsdcc/_moduint.c:41: 	iTemp6 [k11 lr8:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] = iTemp6 [k11 lr8:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] + 0x1 {const-unsigned-char literal}
;	.line	41; "../libsdcc/_moduint.c"	++count;
	INCR	r0x1004
;;[ICODE] ../libsdcc/_moduint.c:41: 	 goto _whilecontinue_0($3)
	GOTO	_00107_DS_
;;[ICODE] ../libsdcc/_moduint.c:45:  preHeaderLbl1($18) :
;;[ICODE] ../libsdcc/_moduint.c:45: 	iTemp10 [k15 lr19:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] := iTemp6 [k11 lr8:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ]
;;[ICODE] ../libsdcc/_moduint.c:45:  _whilecontinue_1($8) :
;;[ICODE] ../libsdcc/_moduint.c:45: 	if iTemp10 [k15 lr19:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] == 0 goto _whilebreak_1($10)
_00112_DS_
;	.line	45; "../libsdcc/_moduint.c"	while (count) {
	MOVAI	0x00
	ORAR	r0x1004
	JBCLR	STATUS,2
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_moduint.c:46: 	iTemp7 [k12 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_a_1_1}[r0x1000 r0x1001 ] < iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ]
;	.line	46; "../libsdcc/_moduint.c"	if (a >= b) {
	MOVAR	r0x1002
	RSUBAR	r0x1000
	JBSET	STATUS,2
	GOTO	_00131_DS_
	MOVAR	r0x1003
	RSUBAR	r0x1001
_00131_DS_
	JBSET	STATUS,0
	GOTO	_00111_DS_
;;genSkipc:3246: created from rifx:0xbfe3cfb0
;;[ICODE] ../libsdcc/_moduint.c:46: 	if iTemp7 [k12 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_1($7)
;;[ICODE] ../libsdcc/_moduint.c:47: 	iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_a_1_1}[r0x1000 r0x1001 ] = iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_a_1_1}[r0x1000 r0x1001 ] - iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ]
;	.line	47; "../libsdcc/_moduint.c"	a -= b;
	MOVAR	r0x1003
	RSUBRA	r0x1001
	MOVAR	r0x1002
	JBSET	STATUS,0
	JZAR	r0x1002
	RSUBRA	r0x1000
;;[ICODE] ../libsdcc/_moduint.c:47:  _iffalse_1($7) :
;;[ICODE] ../libsdcc/_moduint.c:49: 	iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] = iTemp1 [k4 lr4:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_b_1_1}[r0x1002 r0x1003 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=2, sign=0, same=1, offr=0
_00111_DS_
;	.line	49; "../libsdcc/_moduint.c"	b >>= 1;
	BCLR	STATUS,0
	RRR	r0x1002
	RRR	r0x1003
;;[ICODE] ../libsdcc/_moduint.c:50: 	iTemp10 [k15 lr19:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] = iTemp10 [k15 lr19:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __moduint_count_1_2}[r0x1004 ] - 0x1 {const-unsigned-char literal}
;	.line	50; "../libsdcc/_moduint.c"	--count;
	DECR	r0x1004
;;[ICODE] ../libsdcc/_moduint.c:50: 	 goto _whilecontinue_1($8)
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/_moduint.c:50:  _whilebreak_1($10) :
;;[ICODE] ../libsdcc/_moduint.c:53: 	ret iTemp0 [k2 lr3:33 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ __moduint_a_1_1}[r0x1000 r0x1001 ]
_00114_DS_
;	.line	53; "../libsdcc/_moduint.c"	return a;
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/_moduint.c:53:  _return($11) :
;;[ICODE] ../libsdcc/_moduint.c:53: 	eproc __moduint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
_00115_DS_
	RETURN	
; exit point of __moduint


;	code size estimation:
;	   54+    0 =    54 instructions (  108 byte)

	end
