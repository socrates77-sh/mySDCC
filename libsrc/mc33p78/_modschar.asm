;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:37:00 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_modschar.c"
	list	p=33p78
	radix dec
	include "mc33p78.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__moduchar

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
	global	__modschar

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__modschar_0	udata
r0x1000	res	1
r0x1001	res	1
r0x1002	res	1
r0x1003	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
r0x1008	res	1
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
code__modschar	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __modschar	;Function start
; 2 exit points
;has an exit
;functions called:
;   __moduchar
;   __moduchar
;   __moduchar
;   __moduchar
;   __moduchar
;   __moduchar
;   __moduchar
;   __moduchar
;11 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;   r0x1008
;   r0x1009
;; Starting pCode block
;;[ICODE] ../libsdcc/_modschar.c:32:  _entry($11) :
;;[ICODE] ../libsdcc/_modschar.c:32: 	proc __modschar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( char fixed, char fixed) fixed}
__modschar	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_modschar.c:32: iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ] = recv __modschar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( char fixed, char fixed) fixed}
;	.line	32; "../libsdcc/_modschar.c"	_modschar (signed char a, signed char b)
	MOVRA	r0x1000
;;[ICODE] ../libsdcc/_modschar.c:32: iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ] = recv __modschar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( char fixed, char fixed) fixed}
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/_modschar.c:34: 	iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ] < 0x0 {const-char literal}
;;signed compare: left < lit(0x0=0), size=1, mask=ff
;	.line	34; "../libsdcc/_modschar.c"	if (a < 0) {
	BSET	STATUS,0
	JBSET	r0x1000,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbffa6a40
;;[ICODE] ../libsdcc/_modschar.c:34: 	if iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($8)
;;[ICODE] ../libsdcc/_modschar.c:36: 	iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ] < 0x0 {const-char literal}
;;signed compare: left < lit(0x0=0), size=1, mask=ff
;	.line	36; "../libsdcc/_modschar.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1001,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3246: created from rifx:0xbffa6a40
;;[ICODE] ../libsdcc/_modschar.c:36: 	if iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1003 ] = (int fixed)iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ]
;	.line	37; "../libsdcc/_modschar.c"	return _moduchar ((unsigned int)-a, (unsigned int)-b);
	MOVAR	r0x1000
	MOVRA	r0x1002
	CLRR	r0x1003
	JBCLR	r0x1002,7
	DECR	r0x1003
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp5 [k10 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1003 ] = - iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1003 ]
	COMR	r0x1002
	COMR	r0x1003
	INCR	r0x1002
	JBCLR	STATUS,2
	INCR	r0x1003
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp5 [k10 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1003 ]
	MOVAR	r0x1002
	MOVRA	r0x1002
	MOVRA	r0x1004
	MOVAR	r0x1003
	MOVRA	r0x1005
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp7 [k12 lr12:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ] = (unsigned-char fixed)iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
;;108	MOVAR	r0x1004
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp8 [k13 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = (int fixed)iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ]
	MOVAR	r0x1001
	MOVRA	r0x1004
	CLRR	r0x1005
	JBCLR	r0x1004,7
	DECR	r0x1005
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp9 [k14 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp8 [k13 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
	COMR	r0x1004
	COMR	r0x1005
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1005
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp10 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp9 [k14 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
;;110	MOVAR	r0x1004
	MOVAR	r0x1005
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp11 [k16 lr16:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1004 ] = (unsigned-char fixed)iTemp10 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]
;;104	MOVAR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:37: 	send iTemp7 [k12 lr12:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:37: 	send iTemp11 [k16 lr16:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1004 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:37: 	iTemp12 [k19 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ] = call __moduchar [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
;;103	MOVAR	r0x1004
;;109	MOVAR	r0x1006
	MOVAR	r0x1004
	MOVRA	r0x1006
	MOVRA	r0x1004
	MOVRA	STK00
	MOVAR	r0x1002
	CALL	__moduchar
	MOVRA	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:37: 	ret iTemp12 [k19 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ]
	MOVAR	r0x1002
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modschar.c:37:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp13 [k20 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1004 ] = (int fixed)iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ]
_00106_DS_
;	.line	39; "../libsdcc/_modschar.c"	return -_moduchar ((unsigned int)-a, (unsigned int)b);
	MOVAR	r0x1000
	MOVRA	r0x1002
	CLRR	r0x1004
	JBCLR	r0x1002,7
	DECR	r0x1004
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp14 [k21 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1004 ] = - iTemp13 [k20 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1004 ]
	COMR	r0x1002
	COMR	r0x1004
	INCR	r0x1002
	JBCLR	STATUS,2
	INCR	r0x1004
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp15 [k22 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp14 [k21 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1004 ]
	MOVAR	r0x1002
	MOVRA	r0x1002
	MOVRA	r0x1006
	MOVAR	r0x1004
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp16 [k23 lr25:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ] = (unsigned-char fixed)iTemp15 [k22 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]
;;105	MOVAR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp17 [k24 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ]
	MOVAR	r0x1001
	MOVRA	r0x1006
	CLRR	r0x1007
	JBCLR	r0x1006,7
	DECR	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp18 [k25 lr27:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1008 ] = (unsigned-char fixed)iTemp17 [k24 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]
;;107	MOVAR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:39: 	send iTemp16 [k23 lr25:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:39: 	send iTemp18 [k25 lr27:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1008 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp19 [k26 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ] = call __moduchar [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
;;106	MOVAR	r0x1008
	MOVAR	r0x1006
	MOVRA	r0x1008
	MOVRA	STK00
	MOVAR	r0x1002
	CALL	__moduchar
	MOVRA	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:39: 	iTemp20 [k27 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ] = - iTemp19 [k26 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ]
	COMR	r0x1002
	INCR	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:39: 	ret iTemp20 [k27 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ]
	MOVAR	r0x1002
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modschar.c:39:  _iffalse_2($8) :
;;[ICODE] ../libsdcc/_modschar.c:42: 	iTemp21 [k28 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ] < 0x0 {const-char literal}
;;signed compare: left < lit(0x0=0), size=1, mask=ff
_00112_DS_
;	.line	42; "../libsdcc/_modschar.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1001,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00109_DS_
;;genSkipc:3246: created from rifx:0xbffa6a40
;;[ICODE] ../libsdcc/_modschar.c:42: 	if iTemp21 [k28 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($5)
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp22 [k29 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1006 ] = (unsigned-int fixed)iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ]
;	.line	43; "../libsdcc/_modschar.c"	return -_moduchar ((unsigned int)a, (unsigned int)-b);
	MOVAR	r0x1000
	MOVRA	r0x1002
	CLRR	r0x1006
	JBCLR	r0x1002,7
	DECR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp23 [k30 lr37:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1007 ] = (unsigned-char fixed)iTemp22 [k29 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1006 ]
	MOVAR	r0x1002
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp24 [k31 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1006 ] = (int fixed)iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ]
	MOVAR	r0x1001
	MOVRA	r0x1002
	CLRR	r0x1006
	JBCLR	r0x1002,7
	DECR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp25 [k32 lr39:40 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1006 ] = - iTemp24 [k31 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1006 ]
	COMR	r0x1002
	COMR	r0x1006
	INCR	r0x1002
	JBCLR	STATUS,2
	INCR	r0x1006
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp26 [k33 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ] = (unsigned-int fixed)iTemp25 [k32 lr39:40 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1002 r0x1006 ]
;;112	MOVAR	r0x1002
	MOVAR	r0x1006
;;1	MOVRA	r0x1009
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp27 [k34 lr41:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ] = (unsigned-char fixed)iTemp26 [k33 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ]
;;102	MOVAR	r0x1008
;;[ICODE] ../libsdcc/_modschar.c:43: 	send iTemp23 [k30 lr37:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:43: 	send iTemp27 [k34 lr41:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp28 [k35 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ] = call __moduchar [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
;;101	MOVAR	r0x1002
;;111	MOVAR	r0x1008
	MOVAR	r0x1002
	MOVRA	r0x1008
	MOVRA	r0x1002
	MOVRA	STK00
	MOVAR	r0x1007
	CALL	__moduchar
	MOVRA	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:43: 	iTemp29 [k36 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ] = - iTemp28 [k35 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1002 ]
	COMR	r0x1002
	INCR	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:43: 	ret iTemp29 [k36 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1002 ]
	MOVAR	r0x1002
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modschar.c:43:  _iffalse_1($5) :
;;[ICODE] ../libsdcc/_modschar.c:45: 	iTemp30 [k37 lr48:49 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1007 ] = (unsigned-int fixed)iTemp0 [k2 lr3:48 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_a_1_2}[r0x1000 ]
_00109_DS_
;	.line	45; "../libsdcc/_modschar.c"	return _moduchar ((unsigned int)a, (unsigned int)b);
	MOVAR	r0x1000
	MOVRA	r0x1002
	CLRR	r0x1007
	JBCLR	r0x1002,7
	DECR	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:45: 	iTemp31 [k38 lr49:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1000 ] = (unsigned-char fixed)iTemp30 [k37 lr48:49 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1007 ]
	MOVAR	r0x1002
	MOVRA	r0x1000
;;[ICODE] ../libsdcc/_modschar.c:45: 	iTemp32 [k39 lr50:51 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1007 ] = (unsigned-int fixed)iTemp1 [k4 lr4:50 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ __modschar_b_1_2}[r0x1001 ]
	MOVAR	r0x1001
	MOVRA	r0x1002
	CLRR	r0x1007
	JBCLR	r0x1002,7
	DECR	r0x1007
;;[ICODE] ../libsdcc/_modschar.c:45: 	iTemp33 [k40 lr51:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1001 ] = (unsigned-char fixed)iTemp32 [k39 lr50:51 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1002 r0x1007 ]
;;100	MOVAR	r0x1002
;;[ICODE] ../libsdcc/_modschar.c:45: 	send iTemp31 [k38 lr49:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1000 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:45: 	send iTemp33 [k40 lr51:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}[r0x1001 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modschar.c:45: 	iTemp34 [k41 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1000 ] = call __moduchar [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( unsigned-char fixed, unsigned-char fixed) fixed}
;;99	MOVAR	r0x1001
	MOVAR	r0x1002
	MOVRA	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
	CALL	__moduchar
	MOVRA	r0x1000
;;[ICODE] ../libsdcc/_modschar.c:45: 	ret iTemp34 [k41 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1000 ]
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/_modschar.c:45:  _return($10) :
;;[ICODE] ../libsdcc/_modschar.c:45: 	eproc __modschar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( char fixed, char fixed) fixed}
_00114_DS_
	RETURN	
; exit point of __modschar


;	code size estimation:
;	  133+    0 =   133 instructions (  266 byte)

	end
