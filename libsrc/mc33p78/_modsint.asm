;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:37:00 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_modsint.c"
	list	p=33p78
	radix dec
	include "mc33p78.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__moduint

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
	global	__modsint

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__modsint_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1003	res	1
r0x1002	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
r0x1008	res	1
r0x1009	res	1
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
code__modsint	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __modsint	;Function start
; 2 exit points
;has an exit
;functions called:
;   __moduint
;   __moduint
;   __moduint
;   __moduint
;   __moduint
;   __moduint
;   __moduint
;   __moduint
;13 compiler assigned registers:
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
;; Starting pCode block
;;[ICODE] ../libsdcc/_modsint.c:32:  _entry($11) :
;;[ICODE] ../libsdcc/_modsint.c:32: 	proc __modsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
__modsint	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_modsint.c:32: iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ] = recv __modsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
;	.line	32; "../libsdcc/_modsint.c"	_modsint (int a, int b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/_modsint.c:32: iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ] = recv __modsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_modsint.c:34: 	iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
;	.line	34; "../libsdcc/_modsint.c"	if (a < 0) {
	BSET	STATUS,0
	JBSET	r0x1000,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbff84db0
;;[ICODE] ../libsdcc/_modsint.c:34: 	if iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($8)
;;[ICODE] ../libsdcc/_modsint.c:35: 	iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
;	.line	35; "../libsdcc/_modsint.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1002,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3246: created from rifx:0xbff84db0
;;[ICODE] ../libsdcc/_modsint.c:35: 	if iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../libsdcc/_modsint.c:36: 	iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ]
;	.line	36; "../libsdcc/_modsint.c"	return _moduint ((unsigned int)-a, (unsigned int)-b);
	COMAR	r0x1001
	MOVRA	r0x1004
	COMAR	r0x1000
	MOVRA	r0x1005
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:36: 	iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	r0x1006
	MOVAR	r0x1005
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modsint.c:36: 	iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ]
	COMAR	r0x1003
	MOVRA	r0x1004
	COMAR	r0x1002
	MOVRA	r0x1005
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:36: 	iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ] = (unsigned-int fixed)iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
;;112	MOVAR	r0x1004
;;114	MOVAR	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:36: 	send iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:36: 	send iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:36: 	iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __moduint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;;111	MOVAR	r0x1008
	MOVAR	r0x1004
	MOVRA	r0x1008
	MOVRA	STK02
;;113	MOVAR	r0x1009
	MOVAR	r0x1005
	MOVRA	r0x1009
	MOVRA	STK01
	MOVAR	r0x1006
	MOVRA	STK00
	MOVAR	r0x1007
	CALL	__moduint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/_modsint.c:36: 	ret iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modsint.c:36:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/_modsint.c:38: 	iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ]
_00106_DS_
;	.line	38; "../libsdcc/_modsint.c"	return _moduint ((unsigned int)-a, (unsigned int)b);
	COMAR	r0x1001
	MOVRA	r0x1004
	COMAR	r0x1000
	MOVRA	r0x1005
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:38: 	iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	r0x1006
	MOVAR	r0x1005
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modsint.c:38: 	iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ]
;;104	MOVAR	r0x1003
;;106	MOVAR	r0x1002
;;[ICODE] ../libsdcc/_modsint.c:38: 	send iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:38: 	send iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:38: 	iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __moduint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;;103	MOVAR	r0x1004
	MOVAR	r0x1003
	MOVRA	r0x1004
	MOVRA	STK02
;;105	MOVAR	r0x1005
	MOVAR	r0x1002
	MOVRA	r0x1005
	MOVRA	STK01
	MOVAR	r0x1006
	MOVRA	STK00
	MOVAR	r0x1007
	CALL	__moduint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/_modsint.c:38: 	ret iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modsint.c:38:  _iffalse_2($8) :
;;[ICODE] ../libsdcc/_modsint.c:40: 	iTemp13 [k20 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
_00112_DS_
;	.line	40; "../libsdcc/_modsint.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1002,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00109_DS_
;;genSkipc:3246: created from rifx:0xbff84db0
;;[ICODE] ../libsdcc/_modsint.c:40: 	if iTemp13 [k20 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($5)
;;[ICODE] ../libsdcc/_modsint.c:41: 	iTemp14 [k21 lr28:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ]
;	.line	41; "../libsdcc/_modsint.c"	return _moduint ((unsigned int)a, (unsigned int)-b);
	MOVAR	r0x1001
	MOVRA	r0x1004
	MOVAR	r0x1000
	MOVRA	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:41: 	iTemp15 [k22 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] = - iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ]
	COMAR	r0x1003
	MOVRA	r0x1006
	COMAR	r0x1002
	MOVRA	r0x1007
	INCR	r0x1006
	JBCLR	STATUS,2
	INCR	r0x1007
;;[ICODE] ../libsdcc/_modsint.c:41: 	iTemp16 [k23 lr30:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ] = (unsigned-int fixed)iTemp15 [k22 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ]
;;108	MOVAR	r0x1006
;;110	MOVAR	r0x1007
;;[ICODE] ../libsdcc/_modsint.c:41: 	send iTemp14 [k21 lr28:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:41: 	send iTemp16 [k23 lr30:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:41: 	iTemp17 [k24 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __moduint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;;107	MOVAR	r0x1008
	MOVAR	r0x1006
	MOVRA	r0x1008
	MOVRA	STK02
;;109	MOVAR	r0x1009
	MOVAR	r0x1007
	MOVRA	r0x1009
	MOVRA	STK01
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	CALL	__moduint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/_modsint.c:41: 	ret iTemp17 [k24 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modsint.c:41:  _iffalse_1($5) :
;;[ICODE] ../libsdcc/_modsint.c:43: 	iTemp18 [k25 lr36:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_a_1_2}[r0x1000 r0x1001 ]
_00109_DS_
;	.line	43; "../libsdcc/_modsint.c"	return _moduint ((unsigned int)a, (unsigned int)b);
	MOVAR	r0x1001
	MOVRA	r0x1004
	MOVAR	r0x1000
	MOVRA	r0x1005
;;[ICODE] ../libsdcc/_modsint.c:43: 	iTemp19 [k26 lr37:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = (unsigned-int fixed)iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __modsint_b_1_2}[r0x1002 r0x1003 ]
;;100	MOVAR	r0x1003
;;102	MOVAR	r0x1002
;;[ICODE] ../libsdcc/_modsint.c:43: 	send iTemp18 [k25 lr36:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:43: 	send iTemp19 [k26 lr37:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modsint.c:43: 	iTemp20 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = call __moduint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
;;99	MOVAR	r0x1001
	MOVAR	r0x1003
	MOVRA	r0x1001
	MOVRA	STK02
;;101	MOVAR	r0x1000
	MOVAR	r0x1002
	MOVRA	r0x1000
	MOVRA	STK01
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	CALL	__moduint
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/_modsint.c:43: 	ret iTemp20 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ]
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/_modsint.c:43:  _return($10) :
;;[ICODE] ../libsdcc/_modsint.c:43: 	eproc __modsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
_00114_DS_
	RETURN	
; exit point of __modsint


;	code size estimation:
;	  134+    0 =   134 instructions (  268 byte)

	end
