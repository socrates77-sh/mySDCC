;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:36:59 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_divulong.c"
	list	p=33p78
	radix dec
	include "mc33p78.inc"
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
	global	__divulong

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__divulong_0	udata
r0x1003	res	1
r0x1002	res	1
r0x1001	res	1
r0x1000	res	1
r0x1007	res	1
r0x1006	res	1
r0x1005	res	1
r0x1004	res	1
r0x1008	res	1
r0x1009	res	1
r0x100A	res	1
r0x100B	res	1
r0x100C	res	1
r0x100D	res	1
r0x100E	res	1
r0x100F	res	1
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
code__divulong	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __divulong	;Function start
; 2 exit points
;has an exit
;23 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   STK01
;   r0x1002
;   STK02
;   r0x1003
;   STK03
;   r0x1004
;   STK04
;   r0x1005
;   STK05
;   r0x1006
;   STK06
;   r0x1007
;   r0x1008
;   r0x1009
;   r0x100A
;   r0x100B
;   r0x100C
;   r0x100D
;   r0x100E
;   r0x100F
;; Starting pCode block
;;[ICODE] ../libsdcc/_divulong.c:30:  _entry($12) :
;;[ICODE] ../libsdcc/_divulong.c:30: 	proc __divulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
__divulong	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_divulong.c:30: iTemp0 [k2 lr3:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv __divulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
;	.line	30; "../libsdcc/_divulong.c"	_divulong (unsigned long a, unsigned long b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_divulong.c:30: iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv __divulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x1004
	MOVAR	STK04
	MOVRA	r0x1005
	MOVAR	STK05
	MOVRA	r0x1006
	MOVAR	STK06
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_divulong.c:32: 	iTemp2 [k6 lr5:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] := 0x0 {unsigned-long-int literal}
;	.line	32; "../libsdcc/_divulong.c"	unsigned long result = 0;
	CLRR	r0x1008
	CLRR	r0x1009
	CLRR	r0x100A
	CLRR	r0x100B
;;[ICODE] ../libsdcc/_divulong.c:33: 	iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] := 0x1 {unsigned-long-int literal}
;	.line	33; "../libsdcc/_divulong.c"	unsigned long mask = 0x01;
	MOVAI	0x01
	MOVRA	r0x100C
	CLRR	r0x100D
	CLRR	r0x100E
	CLRR	r0x100F
;;[ICODE] ../libsdcc/_divulong.c:36: 	if iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] != 0 goto _whilecontinue_0($3)
;	.line	36; "../libsdcc/_divulong.c"	if (!b) return (unsigned long)-1;
	MOVAR	r0x1007
	ORAR	r0x1006
	ORAR	r0x1005
	ORAR	r0x1004
	JBSET	STATUS,2
	GOTO	_00107_DS_
;;[ICODE] ../libsdcc/_divulong.c:36: 	ret 0xffffffff {unsigned-long-int literal}
	MOVAI	0xff
	MOVRA	STK02
	MOVAI	0xff
	MOVRA	STK01
	MOVAI	0xff
	MOVRA	STK00
	MOVAI	0xff
	GOTO	_00115_DS_
;;[ICODE] ../libsdcc/_divulong.c:40:  _whilecontinue_0($3) :
;;[ICODE] ../libsdcc/_divulong.c:40: 	iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] & 0x80000000 {unsigned-long-int literal}
_00107_DS_
;	.line	40; "../libsdcc/_divulong.c"	while (!(b & (1UL << (8*sizeof(unsigned long)-1)))) {
	JBCLR	r0x1004,7
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/_divulong.c:40: 	if iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} != 0 goto _whilecontinue_1($8)
;;[ICODE] ../libsdcc/_divulong.c:41: 	iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] = iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] << 0x1 {const-unsigned-char literal}
;	.line	41; "../libsdcc/_divulong.c"	b <<= 1;
	BCLR	STATUS,0
	RLR	r0x1007
	RLR	r0x1006
	RLR	r0x1005
	RLR	r0x1004
;;[ICODE] ../libsdcc/_divulong.c:42: 	iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] = iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] << 0x1 {const-unsigned-char literal}
;	.line	42; "../libsdcc/_divulong.c"	mask <<= 1;
	BCLR	STATUS,0
	RLR	r0x100C
	RLR	r0x100D
	RLR	r0x100E
	RLR	r0x100F
;;[ICODE] ../libsdcc/_divulong.c:42: 	 goto _whilecontinue_0($3)
	GOTO	_00107_DS_
;;[ICODE] ../libsdcc/_divulong.c:47:  _whilecontinue_1($8) :
;;[ICODE] ../libsdcc/_divulong.c:47: 	if iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] == 0 goto _whilebreak_1($10)
_00112_DS_
;	.line	47; "../libsdcc/_divulong.c"	while (mask) {
	MOVAR	r0x100C
	ORAR	r0x100D
	ORAR	r0x100E
	ORAR	r0x100F
	JBCLR	STATUS,2
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_divulong.c:48: 	iTemp7 [k13 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] < iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;	.line	48; "../libsdcc/_divulong.c"	if (a >= b) {
	MOVAR	r0x1004
	RSUBAR	r0x1000
	JBSET	STATUS,2
	GOTO	_00129_DS_
	MOVAR	r0x1005
	RSUBAR	r0x1001
	JBSET	STATUS,2
	GOTO	_00129_DS_
	MOVAR	r0x1006
	RSUBAR	r0x1002
	JBSET	STATUS,2
	GOTO	_00129_DS_
	MOVAR	r0x1007
	RSUBAR	r0x1003
_00129_DS_
	JBSET	STATUS,0
	GOTO	_00111_DS_
;;genSkipc:3246: created from rifx:0xbfdf6930
;;[ICODE] ../libsdcc/_divulong.c:48: 	if iTemp7 [k13 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_1($7)
;;[ICODE] ../libsdcc/_divulong.c:49: 	iTemp2 [k6 lr5:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] + iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ]
;	.line	49; "../libsdcc/_divulong.c"	result += mask;
	MOVAR	r0x100C
	ADDRA	r0x1008
	MOVAR	r0x100D
	JBCLR	STATUS,0
	JZAR	r0x100D
	ADDRA	r0x1009
	MOVAR	r0x100E
	JBCLR	STATUS,0
	JZAR	r0x100E
	ADDRA	r0x100A
	MOVAR	r0x100F
	JBCLR	STATUS,0
	JZAR	r0x100F
	ADDRA	r0x100B
;;[ICODE] ../libsdcc/_divulong.c:50: 	iTemp0 [k2 lr3:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp0 [k2 lr3:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] - iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;	.line	50; "../libsdcc/_divulong.c"	a -= b;
	MOVAR	r0x1007
	RSUBRA	r0x1003
	MOVAR	r0x1006
	JBSET	STATUS,0
	JZAR	r0x1006
	RSUBRA	r0x1002
	MOVAR	r0x1005
	JBSET	STATUS,0
	JZAR	r0x1005
	RSUBRA	r0x1001
	MOVAR	r0x1004
	JBSET	STATUS,0
	JZAR	r0x1004
	RSUBRA	r0x1000
;;[ICODE] ../libsdcc/_divulong.c:50:  _iffalse_1($7) :
;;[ICODE] ../libsdcc/_divulong.c:52: 	iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] = iTemp1 [k4 lr4:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=0, same=1, offr=0
_00111_DS_
;	.line	52; "../libsdcc/_divulong.c"	b >>= 1;
	BCLR	STATUS,0
	RRR	r0x1004
	RRR	r0x1005
	RRR	r0x1006
	RRR	r0x1007
;;[ICODE] ../libsdcc/_divulong.c:53: 	iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] = iTemp3 [k8 lr6:32 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_mask_1_2}[r0x100C r0x100D r0x100E r0x100F ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=0, same=1, offr=0
;	.line	53; "../libsdcc/_divulong.c"	mask >>= 1;
	BCLR	STATUS,0
	RRR	r0x100F
	RRR	r0x100E
	RRR	r0x100D
	RRR	r0x100C
;;[ICODE] ../libsdcc/_divulong.c:53: 	 goto _whilecontinue_1($8)
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/_divulong.c:53:  _whilebreak_1($10) :
;;[ICODE] ../libsdcc/_divulong.c:56: 	ret iTemp2 [k6 lr5:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ __divulong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ]
_00114_DS_
;	.line	56; "../libsdcc/_divulong.c"	return result;
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
;;[ICODE] ../libsdcc/_divulong.c:56:  _return($11) :
;;[ICODE] ../libsdcc/_divulong.c:56: 	eproc __divulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
_00115_DS_
	RETURN	
; exit point of __divulong


;	code size estimation:
;	  120+    0 =   120 instructions (  240 byte)

	end
