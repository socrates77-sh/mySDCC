;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Wed Dec 20 12:04:39 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../../libsdcc_mc35/_divsint.c"
	list	p=7030
	radix dec
	include "7030.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__divuint

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
	global	__divsint

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL__divsint_0	udata
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

;@Allocation info for local variables in function '_divsint'
;@_divsint _divuint                  Allocated to registers ;size:2
;@_divsint b                         Allocated to registers r0x1003 r0x1002 ;size:2
;@_divsint a                         Allocated to registers r0x1001 r0x1000 ;size:2
;@end Allocation info for local variables in function '_divsint';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code__divsint	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __divsint	;Function start
; 2 exit points
;has an exit
;functions called:
;   __divuint
;   __divuint
;   __divuint
;   __divuint
;   __divuint
;   __divuint
;   __divuint
;   __divuint
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
;;[ICODE] ../../libsdcc_mc35/_divsint.c:32:  _entry($11) :
;;[ICODE] ../../libsdcc_mc35/_divsint.c:32: 	proc __divsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
__divsint	;Function start
; 2 exit points
;;[ICODE] ../../libsdcc_mc35/_divsint.c:32: iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ] = recv __divsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
;	.line	32; "../../libsdcc_mc35/_divsint.c"	_divsint (int a, int b)
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divsint.c:32: iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ] = recv __divsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../../libsdcc_mc35/_divsint.c:34: 	iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
;	.line	34; "../../libsdcc_mc35/_divsint.c"	if (a < 0) {
	BSET	PFLAG,2
	JBSET	r0x1000,7
	BCLR	PFLAG,2
	JBSET	PFLAG,2
	GOTO	_00112_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/_divsint.c:34: 	if iTemp2 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($8)
;;[ICODE] ../../libsdcc_mc35/_divsint.c:36: 	iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
;	.line	36; "../../libsdcc_mc35/_divsint.c"	if (b < 0)
	BSET	PFLAG,2
	JBSET	r0x1002,7
	BCLR	PFLAG,2
	JBSET	PFLAG,2
	GOTO	_00106_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/_divsint.c:36: 	if iTemp3 [k7 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ]
;	.line	37; "../../libsdcc_mc35/_divsint.c"	return _divuint ((unsigned int)-a, (unsigned int)-b);
	MOVAI	0xff
	XORAR	r0x1001
	MOVRA	r0x1004
	MOVAI	0xff
	XORAR	r0x1000
	MOVRA	r0x1005
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	PFLAG,0
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	r0x1006
	MOVAR	r0x1005
	MOVRA	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ]
	MOVAI	0xff
	XORAR	r0x1003
	MOVRA	r0x1004
	MOVAI	0xff
	XORAR	r0x1002
	MOVRA	r0x1005
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	PFLAG,0
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ] = (unsigned-int fixed)iTemp6 [k11 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
;;112	MOVAR	r0x1004
;;114	MOVAR	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	send iTemp5 [k10 lr10:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	send iTemp7 [k12 lr12:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __divuint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
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
	CALL	__divuint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37: 	ret iTemp8 [k15 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_divsint.c:37:  _iffalse_0($2) :
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = - iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ]
_00106_DS_
;	.line	39; "../../libsdcc_mc35/_divsint.c"	return -_divuint ((unsigned int)-a, (unsigned int)b);
	MOVAI	0xff
	XORAR	r0x1001
	MOVRA	r0x1004
	MOVAI	0xff
	XORAR	r0x1000
	MOVRA	r0x1005
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	PFLAG,0
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = (unsigned-int fixed)iTemp9 [k16 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	r0x1006
	MOVAR	r0x1005
	MOVRA	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ]
;;104	MOVAR	r0x1003
;;106	MOVAR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	send iTemp10 [k17 lr19:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	send iTemp11 [k18 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __divuint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
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
	CALL	__divuint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	iTemp13 [k20 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = - iTemp12 [k19 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAI	0xff
	XORRA	r0x1004
	MOVAI	0xff
	XORRA	r0x1005
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	PFLAG,0
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39: 	ret iTemp13 [k20 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_divsint.c:39:  _iffalse_2($8) :
;;[ICODE] ../../libsdcc_mc35/_divsint.c:42: 	iTemp14 [k21 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
_00112_DS_
;	.line	42; "../../libsdcc_mc35/_divsint.c"	if (b < 0)
	BSET	PFLAG,2
	JBSET	r0x1002,7
	BCLR	PFLAG,2
	JBSET	PFLAG,2
	GOTO	_00109_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/_divsint.c:42: 	if iTemp14 [k21 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($5)
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	iTemp15 [k22 lr29:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ]
;	.line	43; "../../libsdcc_mc35/_divsint.c"	return -_divuint ((unsigned int)a, (unsigned int)-b);
	MOVAR	r0x1001
	MOVRA	r0x1004
	MOVAR	r0x1000
	MOVRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	iTemp16 [k23 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] = - iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ]
	MOVAI	0xff
	XORAR	r0x1003
	MOVRA	r0x1006
	MOVAI	0xff
	XORAR	r0x1002
	MOVRA	r0x1007
	MOVAI	0x01
	ADDRA	r0x1006
	JBCLR	PFLAG,0
	ADDRA	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	iTemp17 [k24 lr31:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ] = (unsigned-int fixed)iTemp16 [k23 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ]
;;108	MOVAR	r0x1006
;;110	MOVAR	r0x1007
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	send iTemp15 [k22 lr29:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	send iTemp17 [k24 lr31:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1008 r0x1009 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	iTemp18 [k25 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = call __divuint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
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
	CALL	__divuint
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1004
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	iTemp19 [k26 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = - iTemp18 [k25 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAI	0xff
	XORRA	r0x1004
	MOVAI	0xff
	XORRA	r0x1005
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	PFLAG,0
	ADDRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43: 	ret iTemp19 [k26 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]
	MOVAR	r0x1004
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00114_DS_
;;[ICODE] ../../libsdcc_mc35/_divsint.c:43:  _iffalse_1($5) :
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	iTemp20 [k27 lr38:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] = (unsigned-int fixed)iTemp0 [k2 lr3:38 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_a_1_2}[r0x1000 r0x1001 ]
_00109_DS_
;	.line	45; "../../libsdcc_mc35/_divsint.c"	return _divuint ((unsigned int)a, (unsigned int)b);
	MOVAR	r0x1001
	MOVRA	r0x1004
	MOVAR	r0x1000
	MOVRA	r0x1005
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	iTemp21 [k28 lr39:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = (unsigned-int fixed)iTemp1 [k4 lr4:39 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ __divsint_b_1_2}[r0x1002 r0x1003 ]
;;100	MOVAR	r0x1003
;;102	MOVAR	r0x1002
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	send iTemp20 [k27 lr38:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	send iTemp21 [k28 lr39:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	iTemp22 [k29 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = call __divuint [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int function ( unsigned-int fixed, unsigned-int fixed) fixed}
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
	CALL	__divuint
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	ret iTemp22 [k29 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ]
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45:  _return($10) :
;;[ICODE] ../../libsdcc_mc35/_divsint.c:45: 	eproc __divsint [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int function ( int fixed, int fixed) fixed}
_00114_DS_
	RETURN	
; exit point of __divsint


;	code size estimation:
;	  162+    0 =   162 instructions (  324 byte)

	end
