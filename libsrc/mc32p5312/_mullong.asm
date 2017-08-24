;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:35:32 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_mullong.c"
	list	p=32p5312
	radix dec
	include "mc32p5312.inc"
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
	global	__mullong

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__mullong_0	udata
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
r0x1010	res	1
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
code__mullong	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __mullong	;Function start
; 2 exit points
;has an exit
;24 compiler assigned registers:
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
;   r0x1010
;; Starting pCode block
;;[ICODE] ../libsdcc/_mullong.c:33:  _entry($16) :
;;[ICODE] ../libsdcc/_mullong.c:33: 	proc __mullong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
__mullong	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_mullong.c:33: iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv __mullong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
;	.line	33; "../libsdcc/_mullong.c"	_mullong (long a, long b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_mullong.c:33: iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv __mullong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x1004
	MOVAR	STK04
	MOVRA	r0x1005
	MOVAR	STK05
	MOVRA	r0x1006
	MOVAR	STK06
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_mullong.c:35: 	iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] := 0x0 {long-int literal}
;	.line	35; "../libsdcc/_mullong.c"	long result = 0;
	CLRR	r0x1008
	CLRR	r0x1009
	CLRR	r0x100A
	CLRR	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:39: 	iTemp3 [k8 lr6:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mullong_i_1_2}[r0x100C ] := 0x8 {unsigned-char literal}
;	.line	39; "../libsdcc/_mullong.c"	for (i = 0; i < 8u; i++) {
	MOVAI	0x08
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/_mullong.c:39:  _forcontinue_0($14) :
;;[ICODE] ../libsdcc/_mullong.c:41: 	iTemp4 [k10 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed} = iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0x1 {long-int literal}
_00118_DS_
;	.line	41; "../libsdcc/_mullong.c"	if (a & 0x0001u) result += b;
	JBSET	r0x1003,0
	GOTO	_00109_DS_
;;[ICODE] ../libsdcc/_mullong.c:41: 	if iTemp4 [k10 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed} == 0 goto _andif_0($5)
;;[ICODE] ../libsdcc/_mullong.c:41: 	iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] + iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x1007
	ADDRA	r0x1008
	MOVAR	r0x1006
	JBCLR	STATUS,0
	JZAR	r0x1006
	ADDRA	r0x1009
	MOVAR	r0x1005
	JBCLR	STATUS,0
	JZAR	r0x1005
	ADDRA	r0x100A
	MOVAR	r0x1004
	JBCLR	STATUS,0
	JZAR	r0x1004
	ADDRA	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:42:  _andif_0($5) :
;;[ICODE] ../libsdcc/_mullong.c:42: 	iTemp6 [k12 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] = (unsigned-long-int register)iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00109_DS_
;	.line	42; "../libsdcc/_mullong.c"	if (sizeof (a) > 1 && (a & 0x00000100ul)) result += (b << 8u);
	MOVAR	r0x1003
	MOVRA	r0x100D
	MOVAR	r0x1002
	MOVRA	r0x100E
	MOVAR	r0x1001
	MOVRA	r0x100F
	MOVAR	r0x1000
	MOVRA	r0x1010
;;[ICODE] ../libsdcc/_mullong.c:42: 	iTemp7 [k13 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp6 [k12 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] & 0x100 {const-unsigned-long-int literal}
	JBSET	r0x100E,0
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/_mullong.c:42: 	if iTemp7 [k13 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _andif_1($8)
;;[ICODE] ../libsdcc/_mullong.c:42: 	iTemp8 [k14 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] = iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] << 0x8 {const-unsigned-int literal}
	MOVAR	r0x1005
	MOVRA	r0x1010
	MOVAR	r0x1006
	MOVRA	r0x100F
;;100	MOVAR	r0x1007
	CLRR	r0x100D
;;[ICODE] ../libsdcc/_mullong.c:42: 	iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] + iTemp8 [k14 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ]
	MOVAI	0x00
	ADDRA	r0x1008
;;99	MOVAR	r0x100E
	MOVAR	r0x1007
	MOVRA	r0x100E
	JBCLR	STATUS,0
	JZAR	r0x100E
	ADDRA	r0x1009
	MOVAR	r0x100F
	JBCLR	STATUS,0
	JZAR	r0x100F
	ADDRA	r0x100A
	MOVAR	r0x1010
	JBCLR	STATUS,0
	JZAR	r0x1010
	ADDRA	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:43:  _andif_1($8) :
;;[ICODE] ../libsdcc/_mullong.c:43: 	iTemp10 [k16 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] = (unsigned-long-int register)iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00112_DS_
;	.line	43; "../libsdcc/_mullong.c"	if (sizeof (a) > 2 && (a & 0x00010000ul)) result += (b << 16u);
	MOVAR	r0x1003
	MOVRA	r0x100D
	MOVAR	r0x1002
	MOVRA	r0x100E
	MOVAR	r0x1001
	MOVRA	r0x100F
	MOVAR	r0x1000
	MOVRA	r0x1010
;;[ICODE] ../libsdcc/_mullong.c:43: 	iTemp11 [k17 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp10 [k16 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] & 0x10000 {const-unsigned-long-int literal}
	JBSET	r0x100F,0
	GOTO	_00115_DS_
;;[ICODE] ../libsdcc/_mullong.c:43: 	if iTemp11 [k17 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _andif_2($11)
;;[ICODE] ../libsdcc/_mullong.c:43: 	iTemp12 [k18 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] = iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] << 0x10 {const-unsigned-int literal}
	MOVAR	r0x1006
	MOVRA	r0x1010
	MOVAR	r0x1007
	MOVRA	r0x100F
	CLRR	r0x100E
	CLRR	r0x100D
;;[ICODE] ../libsdcc/_mullong.c:43: 	iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] + iTemp12 [k18 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ]
	MOVAI	0x00
	ADDRA	r0x1008
	MOVAI	0x00
	JBCLR	STATUS,0
	JZAR	r0x100E
	ADDRA	r0x1009
	MOVAR	r0x100F
	JBCLR	STATUS,0
	JZAR	r0x100F
	ADDRA	r0x100A
	MOVAR	r0x1010
	JBCLR	STATUS,0
	JZAR	r0x1010
	ADDRA	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:44:  _andif_2($11) :
;;[ICODE] ../libsdcc/_mullong.c:44: 	iTemp14 [k20 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] = (unsigned-long-int register)iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00115_DS_
;	.line	44; "../libsdcc/_mullong.c"	if (sizeof (a) > 3 && (a & 0x01000000ul)) result += (b << 24u);
	MOVAR	r0x1003
	MOVRA	r0x100D
	MOVAR	r0x1002
	MOVRA	r0x100E
	MOVAR	r0x1001
	MOVRA	r0x100F
	MOVAR	r0x1000
	MOVRA	r0x1010
;;[ICODE] ../libsdcc/_mullong.c:44: 	iTemp15 [k21 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp14 [k20 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] & 0x1000000 {const-unsigned-long-int literal}
	JBSET	r0x1010,0
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_mullong.c:44: 	if iTemp15 [k21 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _iffalse_3($10)
;;[ICODE] ../libsdcc/_mullong.c:44: 	iTemp16 [k22 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] = iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] << 0x18 {const-unsigned-int literal}
	MOVAR	r0x1007
	MOVRA	r0x1010
	CLRR	r0x100F
	CLRR	r0x100E
	CLRR	r0x100D
;;[ICODE] ../libsdcc/_mullong.c:44: 	iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ] + iTemp16 [k22 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ]
	MOVAI	0x00
	ADDRA	r0x1008
	MOVAI	0x00
	JBCLR	STATUS,0
	JZAR	r0x100E
	ADDRA	r0x1009
	MOVAR	r0x100F
	JBCLR	STATUS,0
	JZAR	r0x100F
	ADDRA	r0x100A
	MOVAR	r0x1010
	JBCLR	STATUS,0
	JZAR	r0x1010
	ADDRA	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:44:  _iffalse_3($10) :
;;[ICODE] ../libsdcc/_mullong.c:45: 	iTemp18 [k24 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] = (unsigned-long-int fixed)iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00114_DS_
;	.line	45; "../libsdcc/_mullong.c"	a = ((unsigned long)a) >> 1u;
	MOVAR	r0x1003
	MOVRA	r0x100D
	MOVAR	r0x1002
	MOVRA	r0x100E
	MOVAR	r0x1001
	MOVRA	r0x100F
	MOVAR	r0x1000
	MOVRA	r0x1010
;;[ICODE] ../libsdcc/_mullong.c:45: 	iTemp0 [k2 lr3:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_a_1_1}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp18 [k24 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] >> 0x1 {const-unsigned-int literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=0, same=0, offr=0
	BCLR	STATUS,0
	RRAR	r0x1010
	MOVRA	r0x1000
	RRAR	r0x100F
	MOVRA	r0x1001
	RRAR	r0x100E
	MOVRA	r0x1002
	RRAR	r0x100D
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_mullong.c:46: 	iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] = iTemp1 [k4 lr4:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_b_1_1}[r0x1004 r0x1005 r0x1006 r0x1007 ] << 0x1 {const-unsigned-int literal}
;	.line	46; "../libsdcc/_mullong.c"	b <<= 1u;
	BCLR	STATUS,0
	RLR	r0x1007
	RLR	r0x1006
	RLR	r0x1005
	RLR	r0x1004
;;[ICODE] ../libsdcc/_mullong.c:46: 	iTemp21 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char register}[r0x100D ] = (char register)iTemp3 [k8 lr6:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mullong_i_1_2}[r0x100C ]
	MOVAR	r0x100C
	MOVRA	r0x100D
;;[ICODE] ../libsdcc/_mullong.c:46: 	iTemp3 [k8 lr6:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mullong_i_1_2}[r0x100C ] = iTemp21 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char register}[r0x100D ] - 0x1 {const-char literal}
	DECAR	r0x100D
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/_mullong.c:39: 	if iTemp3 [k8 lr6:43 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ __mullong_i_1_2}[r0x100C ] != 0 goto _forcontinue_0($14)
;	.line	39; "../libsdcc/_mullong.c"	for (i = 0; i < 8u; i++) {
	MOVAI	0x00
	ORAR	r0x100C
	JBSET	STATUS,2
	GOTO	_00118_DS_
;;[ICODE] ../libsdcc/_mullong.c:49: 	ret iTemp2 [k6 lr5:44 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __mullong_result_1_2}[r0x1008 r0x1009 r0x100A r0x100B ]
;	.line	49; "../libsdcc/_mullong.c"	return result;
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
;;[ICODE] ../libsdcc/_mullong.c:49:  _return($15) :
;;[ICODE] ../libsdcc/_mullong.c:49: 	eproc __mullong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
	RETURN	
; exit point of __mullong


;	code size estimation:
;	  164+    0 =   164 instructions (  328 byte)

	end
