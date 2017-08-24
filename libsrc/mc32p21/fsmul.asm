;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:32:13 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fsmul.c"
	list	p=32p21
	radix dec
	include "mc32p21.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	___uchar2fs
	extern	___schar2fs
	extern	___uint2fs
	extern	___sint2fs
	extern	___ulong2fs
	extern	___slong2fs
	extern	___fs2uchar
	extern	___fs2schar
	extern	___fs2uint
	extern	___fs2sint
	extern	___fs2ulong
	extern	___fs2slong
	extern	___fsadd
	extern	___fssub
	extern	___fsdiv
	extern	___fslt
	extern	___fseq
	extern	___fsneq
	extern	___fsgt
	extern	__mullong

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
	global	___fsmul

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fsmul_0	udata
r0x100B	res	1
r0x100A	res	1
r0x1009	res	1
r0x1008	res	1
r0x100F	res	1
r0x100E	res	1
r0x100D	res	1
r0x100C	res	1
r0x1010	res	1
r0x1011	res	1
r0x1012	res	1
r0x1013	res	1
r0x1014	res	1
r0x1015	res	1
r0x1016	res	1
r0x1017	res	1
r0x1018	res	1
r0x1019	res	1
r0x101A	res	1
___fsmul_fl1_1_22	res	4
___fsmul_fl2_1_22	res	4
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
code_fsmul	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fsmul	;Function start
; 2 exit points
;has an exit
;functions called:
;   __mullong
;   __mullong
;   __mullong
;   __mullong
;   __mullong
;   __mullong
;26 compiler assigned registers:
;   r0x1008
;   STK00
;   r0x1009
;   STK01
;   r0x100A
;   STK02
;   r0x100B
;   STK03
;   r0x100C
;   STK04
;   r0x100D
;   STK05
;   r0x100E
;   STK06
;   r0x100F
;   r0x1010
;   r0x1011
;   r0x1012
;   r0x1013
;   r0x1014
;   r0x1015
;   r0x1016
;   r0x1017
;   r0x1018
;   r0x1019
;   r0x101A
;; Starting pCode block
;;[ICODE] ../libsdcc/fsmul.c:55:  _entry($14) :
;;[ICODE] ../libsdcc/fsmul.c:55: 	proc ___fsmul [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
___fsmul	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fsmul.c:55: iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsmul_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fsmul [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
;	.line	55; "../libsdcc/fsmul.c"	float __fsmul (float a1, float a2) _FS_REENTRANT
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fsmul.c:55: iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsmul_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv ___fsmul [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x100C
	MOVAR	STK04
	MOVRA	r0x100D
	MOVAR	STK05
	MOVRA	r0x100E
	MOVAR	STK06
	MOVRA	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:62: 	iTemp2 [k7 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:62: 	*(iTemp2 [k7 lr5:6 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsmul_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;99	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	62; "../libsdcc/fsmul.c"	fl1.f = a1;
	MOVAR	r0x100A
	MOVRA	(___fsmul_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsmul_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsmul_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:63: 	iTemp4 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:63: 	*(iTemp4 [k11 lr7:8 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsmul_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;125	MOVAR	r0x100F
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	63; "../libsdcc/fsmul.c"	fl2.f = a2;
	MOVAR	r0x100E
	MOVRA	(___fsmul_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fsmul_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fsmul_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:65: 	iTemp6 [k14 lr9:10 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:65: 	iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp6 [k14 lr9:10 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	65; "../libsdcc/fsmul.c"	if (!fl1.l || !fl2.l)
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:65: 	if iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] == 0 goto _iftrue_0($1)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBCLR	STATUS,2
	GOTO	_00105_DS_
;;[ICODE] ../libsdcc/fsmul.c:65: 	iTemp9 [k18 lr12:13 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:65: 	iTemp11 [k21 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp9 [k18 lr12:13 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:65: 	if iTemp11 [k21 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_0($2)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBSET	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fsmul.c:65:  _iftrue_0($1) :
;;[ICODE] ../libsdcc/fsmul.c:66: 	ret 0 {float literal}
_00105_DS_
;	.line	66; "../libsdcc/fsmul.c"	return (0);
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00117_DS_
;;[ICODE] ../libsdcc/fsmul.c:66:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp13 [k24 lr18:19 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp15 [k27 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp13 [k24 lr18:19 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00106_DS_
;	.line	69; "../libsdcc/fsmul.c"	sign = SIGN (fl1.l) ^ SIGN (fl2.l);
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp16 [k28 lr20:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1004 ] = gabit iTemp15 [k27 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1008
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp17 [k29 lr21:22 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp19 [k32 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp17 [k29 lr21:22 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp20 [k33 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1005 ] = gabit iTemp19 [k32 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1008
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsmul.c:69: 	iTemp12 [k22 lr24:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsmul_sign_1_22}[r0x1000 ] = iTemp16 [k28 lr20:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1004 ] ^ iTemp20 [k33 lr23:24 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1005 ]
	MOVAR	r0x100E
	XORAR	r0x100F
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp23 [k37 lr26:27 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp25 [k40 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp23 [k37 lr26:27 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	70; "../libsdcc/fsmul.c"	exp = EXP (fl1.l) - EXCESS;
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp26 [k41 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1005 r0x1006 r0x1007 r0x1008 ] = iTemp25 [k40 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x1008
	RLAR	r0x100F
	MOVRA	r0x100A
	MOVRA	r0x100E
	CLRR	r0x100D
	RLR	r0x100D
	CLRR	r0x100C
	CLRR	r0x1010
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp27 [k42 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp26 [k41 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1005 r0x1006 r0x1007 r0x1008 ] & 0xff {unsigned-long-int literal}
;;103	MOVAR	r0x100E
	CLRR	r0x1009
	CLRR	r0x1008
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp28 [k43 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp27 [k42 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] - 0x7e {unsigned-long-int literal}
	MOVAI	0x82
	ADDRA	r0x100A
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x1009
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x1008
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:70: 	iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] = (int fixed)iTemp28 [k43 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ]
	MOVAR	r0x100A
	MOVRA	r0x100E
	MOVAR	r0x1009
	MOVRA	r0x100D
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp30 [k45 lr33:34 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp32 [k48 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp30 [k45 lr33:34 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	71; "../libsdcc/fsmul.c"	exp += EXP (fl2.l);
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp33 [k49 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp32 [k48 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x1008
	RLAR	r0x100F
	MOVRA	r0x100A
	MOVRA	r0x100C
	CLRR	r0x1010
	RLR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp34 [k50 lr36:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp33 [k49 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] & 0xff {unsigned-long-int literal}
;;104	MOVAR	r0x100C
	CLRR	r0x1009
	CLRR	r0x1008
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp35 [k51 lr37:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = (unsigned-long-int fixed)iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ]
	MOVAR	r0x100E
	MOVRA	r0x100C
	MOVAR	r0x100D
	MOVRA	r0x1010
	MOVAI	0x00
	JBCLR	r0x1010,7
	MOVAI	0xff
	MOVRA	r0x1012
	MOVRA	r0x1011
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp36 [k52 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp35 [k51 lr37:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] + iTemp34 [k50 lr36:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ]
	MOVAR	r0x100A
	ADDAR	r0x100C
	MOVRA	r0x100A
	MOVAR	r0x1010
	JBCLR	STATUS,0
	JZAR	r0x1010
	ADDRA	r0x1009
	MOVAR	r0x1011
	JBCLR	STATUS,0
	JZAR	r0x1011
	ADDRA	r0x1008
	MOVAR	r0x1012
	JBCLR	STATUS,0
	JZAR	r0x1012
	ADDRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:71: 	iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] = (int fixed)iTemp36 [k52 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ]
	MOVAR	r0x100A
	MOVRA	r0x100E
	MOVAR	r0x1009
	MOVRA	r0x100D
;;[ICODE] ../libsdcc/fsmul.c:73: 	iTemp38 [k54 lr41:46 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:73: 	iTemp40 [k57 lr42:43 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:73: 	iTemp42 [k60 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp40 [k57 lr42:43 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	73; "../libsdcc/fsmul.c"	fl1.l = MANT (fl1.l);
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:73: 	iTemp43 [k61 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp42 [k60 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] & 0x7fffff {unsigned-long-int literal}
	BCLR	r0x1008,7
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:73: 	iTemp44 [k62 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp43 [k61 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1008,7
;;[ICODE] ../libsdcc/fsmul.c:73: 	*(iTemp38 [k54 lr41:46 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := iTemp44 [k62 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x100A
	MOVRA	(___fsmul_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsmul_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsmul_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAI	0x00
	MOVRA	(___fsmul_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:74: 	iTemp45 [k63 lr47:52 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:74: 	iTemp47 [k66 lr48:49 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:74: 	iTemp49 [k69 lr49:50 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp47 [k66 lr48:49 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	74; "../libsdcc/fsmul.c"	fl2.l = MANT (fl2.l);
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:74: 	iTemp50 [k70 lr50:51 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp49 [k69 lr49:50 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] & 0x7fffff {unsigned-long-int literal}
	BCLR	r0x1008,7
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:74: 	iTemp51 [k71 lr51:52 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp50 [k70 lr50:51 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1008,7
;;[ICODE] ../libsdcc/fsmul.c:74: 	*(iTemp45 [k63 lr47:52 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := iTemp51 [k71 lr51:52 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1001 r0x1002 r0x1003 r0x1004 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x100A
	MOVRA	(___fsmul_fl2_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsmul_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsmul_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAI	0x00
	MOVRA	(___fsmul_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp53 [k74 lr53:54 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp55 [k77 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp53 [k74 lr53:54 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	77; "../libsdcc/fsmul.c"	result = (fl1.l >> 8) * (fl2.l >> 8);
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x100C
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1010
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1011
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp56 [k78 lr55:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp55 [k77 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x8 {const-unsigned-char literal}
;;119	MOVAR	r0x1009
;;101	MOVAR	r0x1008
;;120	MOVAR	r0x100F
	CLRR	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp57 [k79 lr56:57 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp59 [k82 lr57:58 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = @[iTemp57 [k79 lr56:57 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x1013
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1008
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x1015
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp60 [k83 lr58:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] = iTemp59 [k82 lr57:58 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x8 {const-unsigned-char literal}
;;100	MOVAR	r0x1009
;;124	MOVAR	r0x1008
;;102	MOVAR	r0x100F
	CLRR	r0x1016
;;[ICODE] ../libsdcc/fsmul.c:77: 	send iTemp56 [k78 lr55:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:77: 	send iTemp60 [k83 lr58:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:77: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = call __mullong [k141 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
	MOVAR	r0x1013
	MOVRA	STK06
;;123	MOVAR	r0x1014
	MOVAR	r0x1008
	MOVRA	r0x1014
	MOVRA	STK05
	MOVAR	r0x1015
	MOVRA	STK04
	MOVAI	0x00
	MOVRA	STK03
	MOVAR	r0x100C
	MOVRA	STK02
	MOVAR	r0x1010
	MOVRA	STK01
	MOVAR	r0x1011
	MOVRA	STK00
	MOVAI	0x00
	CALL	__mullong
	MOVRA	r0x100F
	MOVAR	STK00
	MOVRA	r0x1008
	MOVAR	STK01
	MOVRA	r0x1009
	MOVAR	STK02
	MOVRA	r0x100A
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp62 [k85 lr63:64 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp64 [k88 lr64:65 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = @[iTemp62 [k85 lr63:64 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	78; "../libsdcc/fsmul.c"	result += ((fl1.l & (unsigned long) 0xFF) * (fl2.l >> 8)) >> 8;
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100C
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x1010
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1011
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp65 [k89 lr65:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp64 [k88 lr64:65 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] & 0xff {unsigned-long-int literal}
	CLRR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp66 [k90 lr66:67 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp68 [k93 lr67:68 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] = @[iTemp66 [k90 lr66:67 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x1013
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x1014
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1015
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x1016
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp69 [k94 lr68:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100F r0x1010 r0x1011 r0x1012 ] = iTemp68 [k93 lr67:68 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] >> 0x8 {const-unsigned-char literal}
;;114	MOVAR	r0x1014
;;116	MOVAR	r0x1015
;;118	MOVAR	r0x1016
	CLRR	r0x101A
;;[ICODE] ../libsdcc/fsmul.c:78: 	send iTemp65 [k89 lr65:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:78: 	send iTemp69 [k94 lr68:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100F r0x1010 r0x1011 r0x1012 ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp70 [k95 lr71:72 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = call __mullong [k141 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
;;113	MOVAR	r0x1017
	MOVAR	r0x1014
	MOVRA	r0x1017
	MOVRA	STK06
;;115	MOVAR	r0x1018
	MOVAR	r0x1015
	MOVRA	r0x1018
	MOVRA	STK05
;;117	MOVAR	r0x1019
	MOVAR	r0x1016
	MOVRA	r0x1019
	MOVRA	STK04
	MOVAI	0x00
	MOVRA	STK03
	MOVAR	r0x100C
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	CALL	__mullong
	MOVRA	r0x1015
	MOVRA	r0x1012
	MOVAR	STK00
	MOVRA	r0x1014
	MOVRA	r0x1011
	MOVAR	STK01
	MOVRA	r0x1010
	MOVAR	STK02
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp71 [k96 lr72:73 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] = iTemp70 [k95 lr71:72 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] >> 0x8 {const-unsigned-char literal}
;;109	MOVAR	r0x1010
;;121	MOVAR	r0x1011
;;122	MOVAR	r0x1012
	CLRR	r0x1016
;;[ICODE] ../libsdcc/fsmul.c:78: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] + iTemp71 [k96 lr72:73 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ]
;;108	MOVAR	r0x1013
	MOVAR	r0x1010
	MOVRA	r0x1013
	ADDRA	r0x100A
	MOVAR	r0x1014
	JBCLR	STATUS,0
	JZAR	r0x1014
	ADDRA	r0x1009
	MOVAR	r0x1015
	JBCLR	STATUS,0
	JZAR	r0x1015
	ADDRA	r0x1008
	MOVAR	r0x1016
	JBCLR	STATUS,0
	JZAR	r0x1016
	ADDRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp73 [k98 lr75:76 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp75 [k101 lr76:77 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = @[iTemp73 [k98 lr75:76 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	79; "../libsdcc/fsmul.c"	result += ((fl2.l & (unsigned long) 0xFF) * (fl1.l >> 8)) >> 8;
	MOVAR	(___fsmul_fl2_1_22 + 0)
	MOVRA	r0x100C
	MOVAR	(___fsmul_fl2_1_22 + 1)
	MOVRA	r0x1010
	MOVAR	(___fsmul_fl2_1_22 + 2)
	MOVRA	r0x1011
	MOVAR	(___fsmul_fl2_1_22 + 3)
	MOVRA	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp76 [k102 lr77:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp75 [k101 lr76:77 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] & 0xff {unsigned-long-int literal}
	CLRR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp77 [k103 lr78:79 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp79 [k106 lr79:80 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] = @[iTemp77 [k103 lr78:79 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x1013
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x1017
	MOVRA	r0x1014
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1018
	MOVRA	r0x1015
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1019
	MOVRA	r0x1016
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp80 [k107 lr80:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100F r0x1010 r0x1011 r0x1012 ] = iTemp79 [k106 lr79:80 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] >> 0x8 {const-unsigned-char literal}
;;110	MOVAR	r0x1014
;;111	MOVAR	r0x1015
;;112	MOVAR	r0x1016
	CLRR	r0x101A
;;[ICODE] ../libsdcc/fsmul.c:79: 	send iTemp76 [k102 lr77:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:79: 	send iTemp80 [k107 lr80:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100F r0x1010 r0x1011 r0x1012 ]{argreg = 1}
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp81 [k108 lr83:84 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = call __mullong [k141 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( long-int fixed, long-int fixed) fixed}
	MOVAR	r0x1017
	MOVRA	STK06
	MOVAR	r0x1018
	MOVRA	STK05
	MOVAR	r0x1019
	MOVRA	STK04
	MOVAI	0x00
	MOVRA	STK03
	MOVAR	r0x100C
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	CALL	__mullong
	MOVRA	r0x1015
	MOVRA	r0x1012
	MOVAR	STK00
	MOVRA	r0x1014
	MOVRA	r0x1011
	MOVAR	STK01
	MOVRA	r0x1013
	MOVRA	r0x1010
	MOVAR	STK02
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp82 [k109 lr84:85 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ] = iTemp81 [k108 lr83:84 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] >> 0x8 {const-unsigned-char literal}
;;105	MOVAR	r0x1010
;;106	MOVAR	r0x1011
;;107	MOVAR	r0x1012
	CLRR	r0x1016
;;[ICODE] ../libsdcc/fsmul.c:79: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] + iTemp82 [k109 lr84:85 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100B r0x100C r0x100D r0x100E ]
	MOVAR	r0x1013
	ADDRA	r0x100A
	MOVAR	r0x1014
	JBCLR	STATUS,0
	JZAR	r0x1014
	ADDRA	r0x1009
	MOVAR	r0x1015
	JBCLR	STATUS,0
	JZAR	r0x1015
	ADDRA	r0x1008
	MOVAR	r0x1016
	JBCLR	STATUS,0
	JZAR	r0x1016
	ADDRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:82: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] + 0x40 {unsigned-long-int literal}
;	.line	82; "../libsdcc/fsmul.c"	result += 0x40;
	MOVAI	0x40
	ADDRA	r0x100A
	JBCLR	STATUS,0
	INCR	r0x1009
	JBCLR	STATUS,2
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:84: 	iTemp85 [k112 lr89:90 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] & 0x80000000 {unsigned-long-int literal}
;	.line	84; "../libsdcc/fsmul.c"	if (result & SIGNBIT)
	JBSET	r0x100F,7
	GOTO	_00109_DS_
;;[ICODE] ../libsdcc/fsmul.c:84: 	if iTemp85 [k112 lr89:90 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _iffalse_1($5)
;;[ICODE] ../libsdcc/fsmul.c:87: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] + 0x40 {unsigned-long-int literal}
;	.line	87; "../libsdcc/fsmul.c"	result += 0x40;
	MOVAI	0x40
	ADDRA	r0x100A
	JBCLR	STATUS,0
	INCR	r0x1009
	JBCLR	STATUS,2
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:88: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x8 {const-unsigned-char literal}
;	.line	88; "../libsdcc/fsmul.c"	result >>= 8;
	MOVAR	r0x1009
	MOVRA	r0x100A
	MOVAR	r0x1008
	MOVRA	r0x1009
	MOVAR	r0x100F
	MOVRA	r0x1008
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:88: 	 goto _ifend_1($6)
	GOTO	_00110_DS_
;;[ICODE] ../libsdcc/fsmul.c:88:  _iffalse_1($5) :
;;[ICODE] ../libsdcc/fsmul.c:92: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] >> 0x7 {const-unsigned-char literal}
_00109_DS_
;	.line	92; "../libsdcc/fsmul.c"	result >>= 7;
	RLAR	r0x100A
	RLAR	r0x1009
	MOVRA	r0x100A
	RLAR	r0x1008
	MOVRA	r0x1009
	RLAR	r0x100F
	MOVRA	r0x1008
	CLRR	r0x100F
	RLR	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:93: 	iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] = iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] - 0x1 {const-unsigned-char literal}
;	.line	93; "../libsdcc/fsmul.c"	exp--;
	MOVAI	0xff
	ADDRA	r0x100E
	JBSET	STATUS,0
	DECR	r0x100D
;;[ICODE] ../libsdcc/fsmul.c:93:  _ifend_1($6) :
;;[ICODE] ../libsdcc/fsmul.c:96: 	iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ] & 0xff7fffff {unsigned-long-int literal}
_00110_DS_
;	.line	96; "../libsdcc/fsmul.c"	result &= ~HIDDEN;
	BCLR	r0x1008,7
;;[ICODE] ../libsdcc/fsmul.c:99: 	iTemp92 [k119 lr104:105 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] < 0x100 {const-int literal}
;;signed compare: left < lit(0x100=256), size=2, mask=ffff
;	.line	99; "../libsdcc/fsmul.c"	if (exp >= 0x100)
	MOVAR	r0x100D
	ADDAI	0x80
	ADDAI	0x7f
	JBSET	STATUS,2
	GOTO	_00135_DS_
	MOVAI	0x00
	RSUBAR	r0x100E
_00135_DS_
	JBSET	STATUS,0
	GOTO	_00115_DS_
;;genSkipc:3246: created from rifx:0xbff34ef0
;;[ICODE] ../libsdcc/fsmul.c:99: 	if iTemp92 [k119 lr104:105 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_3($11)
;;[ICODE] ../libsdcc/fsmul.c:100: 	iTemp93 [k120 lr106:114 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:100: 	if iTemp12 [k22 lr24:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsmul_sign_1_22}[r0x1000 ] == 0 goto iTempLbl0($15)
;	.line	100; "../libsdcc/fsmul.c"	fl1.l = (sign ? SIGNBIT : 0) | 0x7F800000;
	MOVAI	0x00
	ORAR	r0x100B
	JBCLR	STATUS,2
	GOTO	_00119_DS_
;;[ICODE] ../libsdcc/fsmul.c:100: 	iTemp95 [k123 lr108:113 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] := 0x80000000 {unsigned-long-int literal}
	CLRR	r0x100C
	CLRR	r0x1010
	CLRR	r0x1011
	MOVAI	0x80
	MOVRA	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:100: 	 goto iTempLbl1($16)
	GOTO	_00120_DS_
;;[ICODE] ../libsdcc/fsmul.c:100:  iTempLbl0($15) :
;;[ICODE] ../libsdcc/fsmul.c:100: 	iTemp95 [k123 lr108:113 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] := 0x0 {unsigned-long-int literal}
_00119_DS_
	CLRR	r0x100C
	CLRR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:100:  iTempLbl1($16) :
;;[ICODE] ../libsdcc/fsmul.c:100: 	iTemp96 [k124 lr113:114 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp95 [k123 lr108:113 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ] | 0x7f800000 {unsigned-long-int literal}
_00120_DS_
	BSET	r0x1011,7
	MOVAI	0x7f
	ORRA	r0x1012
;;[ICODE] ../libsdcc/fsmul.c:100: 	*(iTemp93 [k120 lr106:114 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := iTemp96 [k124 lr113:114 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1007 r0x1008 r0x1009 r0x100A ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fsmul_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1010
	MOVRA	(___fsmul_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1011
	MOVRA	(___fsmul_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1012
	MOVRA	(___fsmul_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:100: 	 goto _ifend_3($12)
	GOTO	_00116_DS_
;;[ICODE] ../libsdcc/fsmul.c:100:  _iffalse_3($11) :
;;[ICODE] ../libsdcc/fsmul.c:101: 	iTemp97 [k125 lr117:118 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
_00115_DS_
;	.line	101; "../libsdcc/fsmul.c"	else if (exp < 0)
	BSET	STATUS,0
	JBSET	r0x100D,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbff34ef0
;;[ICODE] ../libsdcc/fsmul.c:101: 	if iTemp97 [k125 lr117:118 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($8)
;;[ICODE] ../libsdcc/fsmul.c:102: 	iTemp98 [k126 lr119:120 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:102: 	*(iTemp98 [k126 lr119:120 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := 0x0 {volatile-unsigned-long-int literal}
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;	.line	102; "../libsdcc/fsmul.c"	fl1.l = 0;
	CLRR	(___fsmul_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	CLRR	(___fsmul_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	CLRR	(___fsmul_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	CLRR	(___fsmul_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:102: 	 goto _ifend_3($12)
	GOTO	_00116_DS_
;;[ICODE] ../libsdcc/fsmul.c:102:  _iffalse_2($8) :
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp100 [k129 lr123:134 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:104: 	if iTemp12 [k22 lr24:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsmul_sign_1_22}[r0x1000 ] == 0 goto iTempLbl2($17)
_00112_DS_
;	.line	104; "../libsdcc/fsmul.c"	fl1.l = PACK (sign ? SIGNBIT : 0 , exp, result);
	MOVAI	0x00
	ORAR	r0x100B
	JBCLR	STATUS,2
	GOTO	_00121_DS_
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp102 [k132 lr125:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1007 r0x1008 r0x1009 ] := 0x80000000 {unsigned-long-int literal}
	CLRR	r0x100B
	CLRR	r0x100C
	CLRR	r0x1010
	MOVAI	0x80
	MOVRA	r0x1011
;;[ICODE] ../libsdcc/fsmul.c:104: 	 goto iTempLbl3($18)
	GOTO	_00122_DS_
;;[ICODE] ../libsdcc/fsmul.c:104:  iTempLbl2($17) :
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp102 [k132 lr125:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1007 r0x1008 r0x1009 ] := 0x0 {unsigned-long-int literal}
_00121_DS_
	CLRR	r0x100B
	CLRR	r0x100C
	CLRR	r0x1010
	CLRR	r0x1011
;;[ICODE] ../libsdcc/fsmul.c:104:  iTempLbl3($18) :
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp103 [k133 lr130:131 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100A r0x100B r0x100C r0x100D ] = (unsigned-long-int fixed)iTemp22 [k35 lr31:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsmul_exp_1_22}[r0x1005 r0x1006 ]
_00122_DS_
	MOVAR	r0x100E
	MOVRA	r0x1012
	MOVAR	r0x100D
	MOVRA	r0x1013
	MOVAI	0x00
	JBCLR	r0x1013,7
	MOVAI	0xff
	MOVRA	r0x1015
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp104 [k134 lr131:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1005 r0x1006 r0x100E r0x100F ] = iTemp103 [k133 lr130:131 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100A r0x100B r0x100C r0x100D ] << 0x17 {const-unsigned-char literal}
	RRAR	r0x1013
	RRAR	r0x1012
	MOVRA	r0x1017
	CLRR	r0x1016
	RRR	r0x1016
	CLRR	r0x100D
	CLRR	r0x100E
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp105 [k135 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1007 r0x1008 r0x1009 ] = iTemp102 [k132 lr125:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1007 r0x1008 r0x1009 ] | iTemp104 [k134 lr131:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1005 r0x1006 r0x100E r0x100F ]
	MOVAI	0x00
	ORRA	r0x100B
	MOVAI	0x00
	ORRA	r0x100C
	MOVAR	r0x1016
	ORRA	r0x1010
	MOVAR	r0x1017
	ORRA	r0x1011
;;[ICODE] ../libsdcc/fsmul.c:104: 	iTemp106 [k136 lr133:134 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = iTemp105 [k135 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1007 r0x1008 r0x1009 ] | iTemp52 [k72 lr61:133 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsmul_result_1_22}[r0x1001 r0x1002 r0x1003 r0x1004 ]
	MOVAR	r0x100B
	ORRA	r0x100A
	MOVAR	r0x100C
	ORRA	r0x1009
	MOVAR	r0x1010
	ORRA	r0x1008
	MOVAR	r0x1011
	ORRA	r0x100F
;;[ICODE] ../libsdcc/fsmul.c:104: 	*(iTemp100 [k129 lr123:134 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := iTemp106 [k136 lr133:134 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x100A
	MOVRA	(___fsmul_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsmul_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsmul_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100F
	MOVRA	(___fsmul_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsmul.c:104:  _ifend_3($12) :
;;[ICODE] ../libsdcc/fsmul.c:105: 	iTemp107 [k137 lr136:137 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsmul_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsmul.c:105: 	iTemp109 [k140 lr137:138 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp107 [k137 lr136:137 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00116_DS_
;	.line	105; "../libsdcc/fsmul.c"	return (fl1.f);
	MOVAR	(___fsmul_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsmul_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsmul_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsmul_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:105: 	ret iTemp109 [k140 lr137:138 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
;;[ICODE] ../libsdcc/fsmul.c:105:  _return($13) :
;;[ICODE] ../libsdcc/fsmul.c:105: 	eproc ___fsmul [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
_00117_DS_
	RETURN	
; exit point of ___fsmul


;	code size estimation:
;	  543+    0 =   543 instructions ( 1086 byte)

	end
