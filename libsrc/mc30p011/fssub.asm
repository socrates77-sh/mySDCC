;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:30:20 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fssub.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
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
	extern	___fsmul
	extern	___fsdiv
	extern	___fslt
	extern	___fseq
	extern	___fsneq
	extern	___fsgt

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
	global	___fssub

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fssub_0	udata
r0x100B	res	1
r0x100A	res	1
r0x1009	res	1
r0x1008	res	1
r0x100F	res	1
r0x100E	res	1
r0x100D	res	1
r0x100C	res	1
___fssub_fl1_1_22	res	4
___fssub_fl2_1_22	res	4
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
code_fssub	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fssub	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___fsadd
;   ___fsadd
;15 compiler assigned registers:
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
;; Starting pCode block
;;[ICODE] ../libsdcc/fssub.c:55:  _entry($6) :
;;[ICODE] ../libsdcc/fssub.c:55: 	proc ___fssub [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
___fssub	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fssub.c:55: iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fssub_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fssub [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
;	.line	55; "../libsdcc/fssub.c"	float __fssub (float a1, float a2) _FS_REENTRANT
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	(___fssub_fl1_1_22 + 0)
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fssub.c:55: iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fssub_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv ___fssub [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x100C
	MOVAR	STK04
	MOVRA	r0x100D
	MOVAR	STK05
	MOVRA	r0x100E
	MOVAR	STK06
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fssub.c:59: 	iTemp2 [k7 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:59: 	*(iTemp2 [k7 lr5:6 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fssub_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;109	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	59; "../libsdcc/fssub.c"	fl1.f = a1;
	MOVAR	r0x100A
	MOVRA	(___fssub_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fssub_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fssub_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fssub.c:60: 	iTemp4 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:60: 	*(iTemp4 [k11 lr7:8 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fssub_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;	.line	60; "../libsdcc/fssub.c"	fl2.f = a2;
	MOVAR	r0x100F
	MOVRA	(___fssub_fl2_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x100E
	MOVRA	(___fssub_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fssub_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fssub_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fssub.c:63: 	iTemp6 [k14 lr9:10 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:63: 	iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp6 [k14 lr9:10 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	63; "../libsdcc/fssub.c"	if (!fl2.l)
	MOVAR	(___fssub_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fssub_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fssub_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fssub_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:63: 	if iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_0($2)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBSET	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fssub.c:64: 	iTemp9 [k18 lr12:13 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:64: 	iTemp11 [k21 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp9 [k18 lr12:13 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	64; "../libsdcc/fssub.c"	return (fl1.f);
	MOVAR	(___fssub_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fssub_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fssub_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fssub_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:64: 	ret iTemp11 [k21 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
	GOTO	_00109_DS_
;;[ICODE] ../libsdcc/fssub.c:64:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fssub.c:65: 	iTemp12 [k22 lr16:17 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fssub_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:65: 	iTemp14 [k25 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp12 [k22 lr16:17 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00106_DS_
;	.line	65; "../libsdcc/fssub.c"	if (!fl1.l)
	MOVAR	(___fssub_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fssub_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fssub_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fssub_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:65: 	if iTemp14 [k25 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_1($4)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBSET	STATUS,2
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/fssub.c:66: 	iTemp15 [k26 lr19:20 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:66: 	iTemp17 [k29 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp15 [k26 lr19:20 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	66; "../libsdcc/fssub.c"	return (-fl2.f);
	MOVAR	(___fssub_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fssub_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fssub_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fssub_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:66: 	iTemp18 [k30 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = - iTemp17 [k29 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1008
	XORAI	0x80
	MOVRA	r0x1008
	MOVAR	r0x1009
	MOVRA	r0x1009
	MOVAR	r0x100A
	MOVRA	r0x100A
	MOVAR	r0x100B
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fssub.c:66: 	ret iTemp18 [k30 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
	GOTO	_00109_DS_
;;[ICODE] ../libsdcc/fssub.c:66:  _iffalse_1($4) :
;;[ICODE] ../libsdcc/fssub.c:69: 	iTemp19 [k31 lr24:29 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:69: 	iTemp21 [k34 lr25:26 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:69: 	iTemp23 [k37 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp21 [k34 lr25:26 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00108_DS_
;	.line	69; "../libsdcc/fssub.c"	fl2.l ^= SIGNBIT;
	MOVAR	(___fssub_fl2_1_22 + 0)
	MOVRA	r0x100F
	MOVRA	r0x100B
	MOVAR	(___fssub_fl2_1_22 + 1)
	MOVRA	r0x100E
	MOVRA	r0x100A
	MOVAR	(___fssub_fl2_1_22 + 2)
	MOVRA	r0x100D
	MOVRA	r0x1009
	MOVAR	(___fssub_fl2_1_22 + 3)
	MOVRA	r0x100C
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:69: 	iTemp24 [k38 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1006 r0x1007 ] = (unsigned-long-int register)iTemp23 [k37 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;106	MOVAR	r0x100B
;;107	MOVAR	r0x100A
;;108	MOVAR	r0x1009
;;105	MOVAR	r0x1008
;;[ICODE] ../libsdcc/fssub.c:69: 	iTemp25 [k39 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp24 [k38 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1006 r0x1007 ] ^ 0x80000000 {unsigned-long-int literal}
;;100	MOVAR	r0x100F
;;102	MOVAR	r0x100E
;;104	MOVAR	r0x100D
	MOVAI	0x80
	XORAR	r0x100C
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:69: 	*(iTemp19 [k31 lr24:29 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := iTemp25 [k39 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;99	MOVAR	r0x100B
	MOVAR	r0x100F
	MOVRA	r0x100B
	MOVRA	(___fssub_fl2_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;;101	MOVAR	r0x100A
	MOVAR	r0x100E
	MOVRA	r0x100A
	MOVRA	(___fssub_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
;;103	MOVAR	r0x1009
	MOVAR	r0x100D
	MOVRA	r0x1009
	MOVRA	(___fssub_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fssub_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fssub.c:70: 	iTemp26 [k40 lr30:31 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:70: 	iTemp28 [k43 lr31:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp26 [k40 lr30:31 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	70; "../libsdcc/fssub.c"	return fl1.f + fl2.f; 
	MOVAR	(___fssub_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fssub_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fssub_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fssub_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fssub.c:70: 	iTemp29 [k44 lr32:33 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fssub_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fssub.c:70: 	iTemp31 [k47 lr33:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = @[iTemp29 [k44 lr32:33 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fssub_fl2_1_22 + 0)
	MOVRA	r0x100F
	MOVAR	(___fssub_fl2_1_22 + 1)
	MOVRA	r0x100E
	MOVAR	(___fssub_fl2_1_22 + 2)
	MOVRA	r0x100D
	MOVAR	(___fssub_fl2_1_22 + 3)
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fssub.c:70: 	send iTemp28 [k43 lr31:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../libsdcc/fssub.c:70: 	send iTemp31 [k47 lr33:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/fssub.c:70: 	iTemp32 [k48 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___fsadd [k49 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
	MOVAR	r0x100F
	MOVRA	STK06
	MOVAR	r0x100E
	MOVRA	STK05
	MOVAR	r0x100D
	MOVRA	STK04
	MOVAR	r0x100C
	MOVRA	STK03
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
	CALL	___fsadd
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fssub.c:70: 	ret iTemp32 [k48 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
;;[ICODE] ../libsdcc/fssub.c:70:  _return($5) :
;;[ICODE] ../libsdcc/fssub.c:70: 	eproc ___fssub [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
_00109_DS_
	RETURN	
; exit point of ___fssub


;	code size estimation:
;	  172+    0 =   172 instructions (  344 byte)

	end
