;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:34:25 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/_modslong.c"
	list	p=31p11
	radix dec
	include "mc31p11.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__modulong

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
	global	__modslong

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__modslong_0	udata
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
r0x1011	res	1
r0x1012	res	1
r0x1013	res	1
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
code__modslong	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __modslong	;Function start
; 2 exit points
;has an exit
;functions called:
;   __modulong
;   __modulong
;   __modulong
;   __modulong
;   __modulong
;   __modulong
;   __modulong
;   __modulong
;27 compiler assigned registers:
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
;   r0x1011
;   r0x1012
;   r0x1013
;; Starting pCode block
;;[ICODE] ../libsdcc/_modslong.c:32:  _entry($11) :
;;[ICODE] ../libsdcc/_modslong.c:32: 	proc __modslong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
__modslong	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/_modslong.c:32: iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv __modslong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
;	.line	32; "../libsdcc/_modslong.c"	_modslong (long a, long b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_modslong.c:32: iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv __modslong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x1004
	MOVAR	STK04
	MOVRA	r0x1005
	MOVAR	STK05
	MOVRA	r0x1006
	MOVAR	STK06
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/_modslong.c:34: 	iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ] < 0x0 {long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
;	.line	34; "../libsdcc/_modslong.c"	if (a < 0) {
	BSET	STATUS,0
	JBSET	r0x1000,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbff89850
;;[ICODE] ../libsdcc/_modslong.c:34: 	if iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($8)
;;[ICODE] ../libsdcc/_modslong.c:35: 	iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ] < 0x0 {long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
;	.line	35; "../libsdcc/_modslong.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1004,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3246: created from rifx:0xbff89850
;;[ICODE] ../libsdcc/_modslong.c:35: 	if iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../libsdcc/_modslong.c:36: 	iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = - iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;	.line	36; "../libsdcc/_modslong.c"	return _modulong ((unsigned long)-a, (unsigned long)-b);
	COMAR	r0x1003
	MOVRA	r0x1008
	COMAR	r0x1002
	MOVRA	r0x1009
	COMAR	r0x1001
	MOVRA	r0x100A
	COMAR	r0x1000
	MOVRA	r0x100B
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x1009
	JBCLR	STATUS,2
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:36: 	iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ] = (unsigned-long-int fixed)iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
	MOVAR	r0x1008
	MOVRA	r0x100C
	MOVAR	r0x1009
	MOVRA	r0x100D
	MOVAR	r0x100A
	MOVRA	r0x100E
	MOVAR	r0x100B
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/_modslong.c:36: 	iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = - iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	COMAR	r0x1007
	MOVRA	r0x1008
	COMAR	r0x1006
	MOVRA	r0x1009
	COMAR	r0x1005
	MOVRA	r0x100A
	COMAR	r0x1004
	MOVRA	r0x100B
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x1009
	JBCLR	STATUS,2
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:36: 	iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1010 r0x1011 r0x1012 r0x1013 ] = (unsigned-long-int fixed)iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
;;124	MOVAR	r0x1008
;;126	MOVAR	r0x1009
;;128	MOVAR	r0x100A
;;130	MOVAR	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:36: 	send iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:36: 	send iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1010 r0x1011 r0x1012 r0x1013 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:36: 	iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = call __modulong [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
;;123	MOVAR	r0x1010
	MOVAR	r0x1008
	MOVRA	r0x1010
	MOVRA	STK06
;;125	MOVAR	r0x1011
	MOVAR	r0x1009
	MOVRA	r0x1011
	MOVRA	STK05
;;127	MOVAR	r0x1012
	MOVAR	r0x100A
	MOVRA	r0x1012
	MOVRA	STK04
;;129	MOVAR	r0x1013
	MOVAR	r0x100B
	MOVRA	r0x1013
	MOVRA	STK03
	MOVAR	r0x100C
	MOVRA	STK02
	MOVAR	r0x100D
	MOVRA	STK01
	MOVAR	r0x100E
	MOVRA	STK00
	MOVAR	r0x100F
	CALL	__modulong
	MOVRA	r0x100B
	MOVAR	STK00
	MOVRA	r0x100A
	MOVAR	STK01
	MOVRA	r0x1009
	MOVAR	STK02
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/_modslong.c:36: 	ret iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modslong.c:36:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/_modslong.c:38: 	iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = - iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00106_DS_
;	.line	38; "../libsdcc/_modslong.c"	return _modulong ((unsigned long)-a, (unsigned long)b);
	COMAR	r0x1003
	MOVRA	r0x1008
	COMAR	r0x1002
	MOVRA	r0x1009
	COMAR	r0x1001
	MOVRA	r0x100A
	COMAR	r0x1000
	MOVRA	r0x100B
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x1009
	JBCLR	STATUS,2
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:38: 	iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ] = (unsigned-long-int fixed)iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
	MOVAR	r0x1008
	MOVRA	r0x100C
	MOVAR	r0x1009
	MOVRA	r0x100D
	MOVAR	r0x100A
	MOVRA	r0x100E
	MOVAR	r0x100B
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/_modslong.c:38: 	iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = (unsigned-long-int fixed)iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;108	MOVAR	r0x1007
;;110	MOVAR	r0x1006
;;112	MOVAR	r0x1005
;;114	MOVAR	r0x1004
;;[ICODE] ../libsdcc/_modslong.c:38: 	send iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:38: 	send iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:38: 	iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = call __modulong [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
;;107	MOVAR	r0x1008
	MOVAR	r0x1007
	MOVRA	r0x1008
	MOVRA	STK06
;;109	MOVAR	r0x1009
	MOVAR	r0x1006
	MOVRA	r0x1009
	MOVRA	STK05
;;111	MOVAR	r0x100A
	MOVAR	r0x1005
	MOVRA	r0x100A
	MOVRA	STK04
;;113	MOVAR	r0x100B
	MOVAR	r0x1004
	MOVRA	r0x100B
	MOVRA	STK03
	MOVAR	r0x100C
	MOVRA	STK02
	MOVAR	r0x100D
	MOVRA	STK01
	MOVAR	r0x100E
	MOVRA	STK00
	MOVAR	r0x100F
	CALL	__modulong
	MOVRA	r0x100B
	MOVAR	STK00
	MOVRA	r0x100A
	MOVAR	STK01
	MOVRA	r0x1009
	MOVAR	STK02
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/_modslong.c:38: 	ret iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modslong.c:38:  _iffalse_2($8) :
;;[ICODE] ../libsdcc/_modslong.c:40: 	iTemp13 [k20 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ] < 0x0 {long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
_00112_DS_
;	.line	40; "../libsdcc/_modslong.c"	if (b < 0)
	BSET	STATUS,0
	JBSET	r0x1004,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00109_DS_
;;genSkipc:3246: created from rifx:0xbff89850
;;[ICODE] ../libsdcc/_modslong.c:40: 	if iTemp13 [k20 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($5)
;;[ICODE] ../libsdcc/_modslong.c:41: 	iTemp14 [k21 lr28:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = (unsigned-long-int fixed)iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;	.line	41; "../libsdcc/_modslong.c"	return _modulong ((unsigned long)a, (unsigned long)-b);
	MOVAR	r0x1003
	MOVRA	r0x1008
	MOVAR	r0x1002
	MOVRA	r0x1009
	MOVAR	r0x1001
	MOVRA	r0x100A
	MOVAR	r0x1000
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:41: 	iTemp15 [k22 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100C r0x100D r0x100E r0x100F ] = - iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	COMAR	r0x1007
	MOVRA	r0x100C
	COMAR	r0x1006
	MOVRA	r0x100D
	COMAR	r0x1005
	MOVRA	r0x100E
	COMAR	r0x1004
	MOVRA	r0x100F
	INCR	r0x100C
	JBCLR	STATUS,2
	INCR	r0x100D
	JBCLR	STATUS,2
	INCR	r0x100E
	JBCLR	STATUS,2
	INCR	r0x100F
;;[ICODE] ../libsdcc/_modslong.c:41: 	iTemp16 [k23 lr30:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1010 r0x1011 r0x1012 r0x1013 ] = (unsigned-long-int fixed)iTemp15 [k22 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed}[r0x100C r0x100D r0x100E r0x100F ]
;;116	MOVAR	r0x100C
;;118	MOVAR	r0x100D
;;120	MOVAR	r0x100E
;;122	MOVAR	r0x100F
;;[ICODE] ../libsdcc/_modslong.c:41: 	send iTemp14 [k21 lr28:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:41: 	send iTemp16 [k23 lr30:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1010 r0x1011 r0x1012 r0x1013 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:41: 	iTemp17 [k24 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = call __modulong [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
;;115	MOVAR	r0x1010
	MOVAR	r0x100C
	MOVRA	r0x1010
	MOVRA	STK06
;;117	MOVAR	r0x1011
	MOVAR	r0x100D
	MOVRA	r0x1011
	MOVRA	STK05
;;119	MOVAR	r0x1012
	MOVAR	r0x100E
	MOVRA	r0x1012
	MOVRA	STK04
;;121	MOVAR	r0x1013
	MOVAR	r0x100F
	MOVRA	r0x1013
	MOVRA	STK03
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
	CALL	__modulong
	MOVRA	r0x100B
	MOVAR	STK00
	MOVRA	r0x100A
	MOVAR	STK01
	MOVRA	r0x1009
	MOVAR	STK02
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/_modslong.c:41: 	ret iTemp17 [k24 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/_modslong.c:41:  _iffalse_1($5) :
;;[ICODE] ../libsdcc/_modslong.c:43: 	iTemp18 [k25 lr36:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = (unsigned-long-int fixed)iTemp0 [k2 lr3:36 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_a_1_2}[r0x1000 r0x1001 r0x1002 r0x1003 ]
_00109_DS_
;	.line	43; "../libsdcc/_modslong.c"	return _modulong ((unsigned long)a, (unsigned long)b);
	MOVAR	r0x1003
	MOVRA	r0x1008
	MOVAR	r0x1002
	MOVRA	r0x1009
	MOVAR	r0x1001
	MOVRA	r0x100A
	MOVAR	r0x1000
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/_modslong.c:43: 	iTemp19 [k26 lr37:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = (unsigned-long-int fixed)iTemp1 [k4 lr4:37 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ __modslong_b_1_2}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;100	MOVAR	r0x1007
;;102	MOVAR	r0x1006
;;104	MOVAR	r0x1005
;;106	MOVAR	r0x1004
;;[ICODE] ../libsdcc/_modslong.c:43: 	send iTemp18 [k25 lr36:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:43: 	send iTemp19 [k26 lr37:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../libsdcc/_modslong.c:43: 	iTemp20 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call __modulong [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( unsigned-long-int fixed, unsigned-long-int fixed) fixed}
;;99	MOVAR	r0x1003
	MOVAR	r0x1007
	MOVRA	r0x1003
	MOVRA	STK06
;;101	MOVAR	r0x1002
	MOVAR	r0x1006
	MOVRA	r0x1002
	MOVRA	STK05
;;103	MOVAR	r0x1001
	MOVAR	r0x1005
	MOVRA	r0x1001
	MOVRA	STK04
;;105	MOVAR	r0x1000
	MOVAR	r0x1004
	MOVRA	r0x1000
	MOVRA	STK03
	MOVAR	r0x1008
	MOVRA	STK02
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x100A
	MOVRA	STK00
	MOVAR	r0x100B
	CALL	__modulong
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/_modslong.c:43: 	ret iTemp20 [k27 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/_modslong.c:43:  _return($10) :
;;[ICODE] ../libsdcc/_modslong.c:43: 	eproc __modslong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
_00114_DS_
	RETURN	
; exit point of __modslong


;	code size estimation:
;	  262+    0 =   262 instructions (  524 byte)

	end
