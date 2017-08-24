;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:36:59 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fsadd.c"
	list	p=33p78
	radix dec
	include "mc33p78.inc"
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
	extern	___fssub
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
	global	___fsadd

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fsadd_0	udata
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
r0x101B	res	1
r0x101C	res	1
r0x101D	res	1
r0x101E	res	1
r0x101F	res	1
___fsadd_fl1_1_22	res	4
___fsadd_fl2_1_22	res	4
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
code_fsadd	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fsadd	;Function start
; 2 exit points
;has an exit
;31 compiler assigned registers:
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
;   r0x101B
;   r0x101C
;   r0x101D
;   r0x101E
;   r0x101F
;; Starting pCode block
;;[ICODE] ../libsdcc/fsadd.c:53:  _entry($30) :
;;[ICODE] ../libsdcc/fsadd.c:53: 	proc ___fsadd [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
___fsadd	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fsadd.c:53: iTemp0 [k2 lr3:7 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsadd_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fsadd [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
;	.line	53; "../libsdcc/fsadd.c"	float __fsadd (float a1, float a2) _FS_REENTRANT
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fsadd.c:53: iTemp1 [k4 lr4:9 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsadd_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv ___fsadd [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x100C
	MOVAR	STK04
	MOVRA	r0x100D
	MOVAR	STK05
	MOVRA	r0x100E
	MOVAR	STK06
	MOVRA	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsadd.c:58: 	iTemp2 [k6 lr5:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsadd_sign_1_22}[r0x1008 r0x1009 r0x100A r0x100B ] := 0x0 {unsigned-long-int literal}
;	.line	58; "../libsdcc/fsadd.c"	unsigned long sign = 0;
	CLRR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
	CLRR	r0x1013
;;[ICODE] ../libsdcc/fsadd.c:60: 	iTemp3 [k9 lr6:7 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:60: 	*(iTemp3 [k9 lr6:7 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:7 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsadd_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;117	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	60; "../libsdcc/fsadd.c"	fl1.f = a1;
	MOVAR	r0x100A
	MOVRA	(___fsadd_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsadd_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsadd_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsadd.c:61: 	iTemp5 [k13 lr8:9 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:61: 	*(iTemp5 [k13 lr8:9 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp1 [k4 lr4:9 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsadd_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;118	MOVAR	r0x100F
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	61; "../libsdcc/fsadd.c"	fl2.f = a2;
	MOVAR	r0x100E
	MOVRA	(___fsadd_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fsadd_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fsadd_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsadd.c:64: 	iTemp7 [k16 lr10:11 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:64: 	iTemp9 [k19 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp7 [k16 lr10:11 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	64; "../libsdcc/fsadd.c"	if (!fl1.l)
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:64: 	if iTemp9 [k19 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_0($2)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBSET	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fsadd.c:65: 	iTemp10 [k20 lr13:14 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:65: 	iTemp12 [k23 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp10 [k20 lr13:14 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	65; "../libsdcc/fsadd.c"	return (fl2.f);
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:65: 	ret iTemp12 [k23 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
	GOTO	_00133_DS_
;;[ICODE] ../libsdcc/fsadd.c:65:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fsadd.c:66: 	iTemp13 [k24 lr17:18 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:66: 	iTemp15 [k27 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp13 [k24 lr17:18 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00106_DS_
;	.line	66; "../libsdcc/fsadd.c"	if (!fl2.l)
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:66: 	if iTemp15 [k27 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_1($4)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1009
	ORAR	r0x1008
	JBSET	STATUS,2
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/fsadd.c:67: 	iTemp16 [k28 lr20:21 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:67: 	iTemp18 [k31 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp16 [k28 lr20:21 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	67; "../libsdcc/fsadd.c"	return (fl1.f);
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:67: 	ret iTemp18 [k31 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x1008
	GOTO	_00133_DS_
;;[ICODE] ../libsdcc/fsadd.c:67:  _iffalse_1($4) :
;;[ICODE] ../libsdcc/fsadd.c:69: 	iTemp20 [k34 lr24:25 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:69: 	iTemp22 [k37 lr25:26 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp20 [k34 lr24:25 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00108_DS_
;	.line	69; "../libsdcc/fsadd.c"	exp1 = EXP (fl1.l);
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:69: 	iTemp23 [k38 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = iTemp22 [k37 lr25:26 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x1009
	RLAR	r0x1008
	MOVRA	r0x100B
	MOVRA	r0x100F
	CLRR	r0x100E
	RLR	r0x100E
	CLRR	r0x100D
	CLRR	r0x100C
;;[ICODE] ../libsdcc/fsadd.c:69: 	iTemp24 [k39 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp23 [k38 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] & 0xff {unsigned-long-int literal}
;;116	MOVAR	r0x100F
	CLRR	r0x100A
	CLRR	r0x1009
	CLRR	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:69: 	iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] = (int fixed)iTemp24 [k39 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x100B
	MOVRA	r0x100F
	MOVAI	0x00
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:70: 	iTemp27 [k43 lr30:31 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:70: 	iTemp29 [k46 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp27 [k43 lr30:31 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	70; "../libsdcc/fsadd.c"	exp2 = EXP (fl2.l);
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:70: 	iTemp30 [k47 lr32:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1006 r0x1007 r0x100C r0x100D ] = iTemp29 [k46 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x1009
	RLAR	r0x1008
	MOVRA	r0x100D
	CLRR	r0x100C
	RLR	r0x100C
	CLRR	r0x1014
	CLRR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:70: 	iTemp31 [k48 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp30 [k47 lr32:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1006 r0x1007 r0x100C r0x100D ] & 0xff {unsigned-long-int literal}
	MOVAR	r0x100D
	MOVRA	r0x100D
	MOVRA	r0x100B
	CLRR	r0x100A
	CLRR	r0x1009
	CLRR	r0x1008
;;[ICODE] ../libsdcc/fsadd.c:70: 	iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ] = (int fixed)iTemp31 [k48 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;115	MOVAR	r0x100B
	MOVAI	0x00
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fsadd.c:72: 	iTemp33 [k50 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int register}[r0x1000 r0x1001 ] = iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ] + 0x19 {int literal}
;	.line	72; "../libsdcc/fsadd.c"	if (exp1 > exp2 + 25)
	MOVAI	0x19
	ADDAR	r0x100D
	MOVRA	r0x100B
	CLRR	r0x100A
	RLR	r0x100A
	MOVAR	r0x100C
	ADDRA	r0x100A
;;[ICODE] ../libsdcc/fsadd.c:72: 	iTemp34 [k51 lr37:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] > iTemp33 [k50 lr36:37 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int register}[r0x1000 r0x1001 ]
	MOVAR	r0x100A
	ADDAI	0x80
	MOVRA	r0x1016
	MOVAR	r0x100E
	ADDAI	0x80
	RSUBAR	r0x1016
	JBSET	STATUS,2
	GOTO	_00165_DS_
	MOVAR	r0x100F
	RSUBAR	r0x100B
_00165_DS_
	JBCLR	STATUS,0
	GOTO	_00110_DS_
;;genSkipc:3246: created from rifx:0xbfe61180
;;[ICODE] ../libsdcc/fsadd.c:72: 	if iTemp34 [k51 lr37:38 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($6)
;;[ICODE] ../libsdcc/fsadd.c:73: 	iTemp35 [k52 lr39:40 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:73: 	iTemp37 [k55 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x100C r0x100D ] = @[iTemp35 [k52 lr39:40 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	73; "../libsdcc/fsadd.c"	return (fl1.f);
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1014
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:73: 	ret iTemp37 [k55 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x100C r0x100D ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1014
	MOVRA	STK00
	MOVAR	r0x1015
	GOTO	_00133_DS_
;;[ICODE] ../libsdcc/fsadd.c:73:  _iffalse_2($6) :
;;[ICODE] ../libsdcc/fsadd.c:74: 	iTemp38 [k56 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int register}[r0x1000 r0x1001 ] = iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] + 0x19 {int literal}
_00110_DS_
;	.line	74; "../libsdcc/fsadd.c"	if (exp2 > exp1 + 25)
	MOVAI	0x19
	ADDAR	r0x100F
	MOVRA	r0x100B
	CLRR	r0x100A
	RLR	r0x100A
	MOVAR	r0x100E
	ADDRA	r0x100A
;;[ICODE] ../libsdcc/fsadd.c:74: 	iTemp39 [k57 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ] > iTemp38 [k56 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int register}[r0x1000 r0x1001 ]
	MOVAR	r0x100A
	ADDAI	0x80
	MOVRA	r0x1016
	MOVAR	r0x100C
	ADDAI	0x80
	RSUBAR	r0x1016
	JBSET	STATUS,2
	GOTO	_00166_DS_
	MOVAR	r0x100D
	RSUBAR	r0x100B
_00166_DS_
	JBCLR	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbfe61180
;;[ICODE] ../libsdcc/fsadd.c:74: 	if iTemp39 [k57 lr44:45 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_3($8)
;;[ICODE] ../libsdcc/fsadd.c:75: 	iTemp40 [k58 lr46:47 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:75: 	iTemp42 [k61 lr47:48 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x100C r0x100D ] = @[iTemp40 [k58 lr46:47 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	75; "../libsdcc/fsadd.c"	return (fl2.f);
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x1014
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:75: 	ret iTemp42 [k61 lr47:48 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x100C r0x100D ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1014
	MOVRA	STK00
	MOVAR	r0x1015
	GOTO	_00133_DS_
;;[ICODE] ../libsdcc/fsadd.c:75:  _iffalse_3($8) :
;;[ICODE] ../libsdcc/fsadd.c:77: 	iTemp44 [k64 lr50:51 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:77: 	iTemp46 [k67 lr51:52 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ] = @[iTemp44 [k64 lr50:51 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00112_DS_
;	.line	77; "../libsdcc/fsadd.c"	mant1 = MANT (fl1.l);
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1014
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:77: 	iTemp47 [k68 lr52:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp46 [k67 lr51:52 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ] & 0x7fffff {unsigned-long-int literal}
	BCLR	r0x1014,7
	CLRR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:77: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp47 [k68 lr52:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1000 r0x1001 r0x100C r0x100D ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1014,7
;;[ICODE] ../libsdcc/fsadd.c:78: 	iTemp50 [k72 lr55:56 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:78: 	iTemp52 [k75 lr56:57 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100E r0x100F r0x1010 r0x1011 ] = @[iTemp50 [k72 lr55:56 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	78; "../libsdcc/fsadd.c"	mant2 = MANT (fl2.l);
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x1016
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x1017
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x1018
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x1019
;;[ICODE] ../libsdcc/fsadd.c:78: 	iTemp53 [k76 lr57:58 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100E r0x100F r0x1010 r0x1011 ] = iTemp52 [k75 lr56:57 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x100E r0x100F r0x1010 r0x1011 ] & 0x7fffff {unsigned-long-int literal}
	BCLR	r0x1018,7
	CLRR	r0x1019
;;[ICODE] ../libsdcc/fsadd.c:78: 	iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ] = iTemp53 [k76 lr57:58 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100E r0x100F r0x1010 r0x1011 ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1018,7
;;[ICODE] ../libsdcc/fsadd.c:80: 	iTemp55 [k78 lr60:61 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:80: 	iTemp57 [k81 lr61:62 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1012 r0x1013 r0x1014 r0x1015 ] = @[iTemp55 [k78 lr60:61 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	80; "../libsdcc/fsadd.c"	if (SIGN (fl1.l))
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x101A
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x101B
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x101C
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x101D
;;[ICODE] ../libsdcc/fsadd.c:80: 	iTemp58 [k82 lr62:63 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1016 ] = gabit iTemp57 [k81 lr61:62 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1012 r0x1013 r0x1014 r0x1015 ]
	MOVAR	r0x101D
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x101E
;;[ICODE] ../libsdcc/fsadd.c:80: 	if iTemp58 [k82 lr62:63 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1016 ] == 0 goto _iffalse_4($10)
	MOVAI	0x00
	ORAR	r0x101E
	JBCLR	STATUS,2
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/fsadd.c:81: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = - iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ]
;	.line	81; "../libsdcc/fsadd.c"	mant1 = -mant1;
	COMR	r0x100B
	COMR	r0x100A
	COMR	r0x1014
	COMR	r0x1015
	INCR	r0x100B
	JBCLR	STATUS,2
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x1014
	JBCLR	STATUS,2
	INCR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:81:  _iffalse_4($10) :
;;[ICODE] ../libsdcc/fsadd.c:82: 	iTemp60 [k84 lr67:68 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl2_1_22 [k12 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:82: 	iTemp62 [k87 lr68:69 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1012 r0x1013 r0x1014 r0x1015 ] = @[iTemp60 [k84 lr67:68 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00114_DS_
;	.line	82; "../libsdcc/fsadd.c"	if (SIGN (fl2.l))
	MOVAR	(___fsadd_fl2_1_22 + 0)
	MOVRA	r0x101A
	MOVAR	(___fsadd_fl2_1_22 + 1)
	MOVRA	r0x101B
	MOVAR	(___fsadd_fl2_1_22 + 2)
	MOVRA	r0x101C
	MOVAR	(___fsadd_fl2_1_22 + 3)
	MOVRA	r0x101D
;;[ICODE] ../libsdcc/fsadd.c:82: 	iTemp63 [k88 lr69:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1016 ] = gabit iTemp62 [k87 lr68:69 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-long-int fixed}[r0x1012 r0x1013 r0x1014 r0x1015 ]
	MOVAR	r0x101D
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x101E
;;[ICODE] ../libsdcc/fsadd.c:82: 	if iTemp63 [k88 lr69:70 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1016 ] == 0 goto _iffalse_5($12)
	MOVAI	0x00
	ORAR	r0x101E
	JBCLR	STATUS,2
	GOTO	_00116_DS_
;;[ICODE] ../libsdcc/fsadd.c:83: 	iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ] = - iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ]
;	.line	83; "../libsdcc/fsadd.c"	mant2 = -mant2;
	COMR	r0x1016
	COMR	r0x1017
	COMR	r0x1018
	COMR	r0x1019
	INCR	r0x1016
	JBCLR	STATUS,2
	INCR	r0x1017
	JBCLR	STATUS,2
	INCR	r0x1018
	JBCLR	STATUS,2
	INCR	r0x1019
;;[ICODE] ../libsdcc/fsadd.c:83:  _iffalse_5($12) :
;;[ICODE] ../libsdcc/fsadd.c:85: 	iTemp65 [k90 lr74:75 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] > iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ]
_00116_DS_
;	.line	85; "../libsdcc/fsadd.c"	if (exp1 > exp2)
	MOVAR	r0x100C
	ADDAI	0x80
	MOVRA	r0x101F
	MOVAR	r0x100E
	ADDAI	0x80
	RSUBAR	r0x101F
	JBSET	STATUS,2
	GOTO	_00167_DS_
	MOVAR	r0x100F
	RSUBAR	r0x100D
_00167_DS_
	JBCLR	STATUS,0
	GOTO	_00118_DS_
;;genSkipc:3246: created from rifx:0xbfe61180
;;[ICODE] ../libsdcc/fsadd.c:85: 	if iTemp65 [k90 lr74:75 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_6($14)
;;[ICODE] ../libsdcc/fsadd.c:87: 	iTemp66 [k91 lr76:77 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1012 r0x1013 ] = iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] - iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ]
;	.line	87; "../libsdcc/fsadd.c"	mant2 >>= exp1 - exp2;
	MOVAR	r0x100D
	RSUBAR	r0x100F
	MOVRA	r0x101A
	MOVAR	r0x100C
	JBSET	STATUS,0
	INCAR	r0x100C
	RSUBAR	r0x100E
	MOVRA	r0x101B
;;[ICODE] ../libsdcc/fsadd.c:87: 	iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ] = iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ] >> iTemp66 [k91 lr76:77 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1012 r0x1013 ]
	MOVAR	r0x101A
	JBCLR	r0x101A,7
	GOTO	_00170_DS_
	ISUBAI	0x00
	JBCLR	STATUS,2
	GOTO	_00169_DS_
_00168_DS_
	BCLR	STATUS,0
	JBCLR	r0x1019,7
	BSET	STATUS,0
	RRR	r0x1019
	RRR	r0x1018
	RRR	r0x1017
	RRR	r0x1016
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00168_DS_
	GOTO	_00169_DS_
_00170_DS_
	BCLR	STATUS,0
_00171_DS_
	RLR	r0x1016
	RLR	r0x1017
	RLR	r0x1018
	RLR	r0x1019
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00171_DS_
;;[ICODE] ../libsdcc/fsadd.c:87: 	 goto _ifend_6($15)
_00169_DS_
	GOTO	_00119_DS_
;;[ICODE] ../libsdcc/fsadd.c:87:  _iffalse_6($14) :
;;[ICODE] ../libsdcc/fsadd.c:91: 	iTemp68 [k93 lr81:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1012 r0x1013 ] = iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ] - iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ]
_00118_DS_
;	.line	91; "../libsdcc/fsadd.c"	mant1 >>= exp2 - exp1;
	MOVAR	r0x100F
	RSUBAR	r0x100D
	MOVRA	r0x101A
	MOVAR	r0x100E
	JBSET	STATUS,0
	INCAR	r0x100E
	RSUBAR	r0x100C
	MOVRA	r0x101B
;;[ICODE] ../libsdcc/fsadd.c:91: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] >> iTemp68 [k93 lr81:82 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1012 r0x1013 ]
	MOVAR	r0x101A
	JBCLR	r0x101A,7
	GOTO	_00174_DS_
	ISUBAI	0x00
	JBCLR	STATUS,2
	GOTO	_00173_DS_
_00172_DS_
	BCLR	STATUS,0
	JBCLR	r0x1015,7
	BSET	STATUS,0
	RRR	r0x1015
	RRR	r0x1014
	RRR	r0x100A
	RRR	r0x100B
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00172_DS_
	GOTO	_00173_DS_
_00174_DS_
	BCLR	STATUS,0
_00175_DS_
	RLR	r0x100B
	RLR	r0x100A
	RLR	r0x1014
	RLR	r0x1015
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00175_DS_
;;[ICODE] ../libsdcc/fsadd.c:92: 	iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] := iTemp26 [k41 lr34:84 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp2_1_22}[r0x1006 r0x1007 ]
_00173_DS_
;	.line	92; "../libsdcc/fsadd.c"	exp1 = exp2;
	MOVAR	r0x100D
	MOVRA	r0x100F
	MOVAR	r0x100C
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:92:  _ifend_6($15) :
;;[ICODE] ../libsdcc/fsadd.c:94: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] + iTemp49 [k70 lr58:86 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant2_1_22}[r0x100E r0x100F r0x1010 r0x1011 ]
_00119_DS_
;	.line	94; "../libsdcc/fsadd.c"	mant1 += mant2;
	MOVAR	r0x1016
	ADDRA	r0x100B
	MOVAR	r0x1017
	JBCLR	STATUS,0
	JZAR	r0x1017
	ADDRA	r0x100A
	MOVAR	r0x1018
	JBCLR	STATUS,0
	JZAR	r0x1018
	ADDRA	r0x1014
	MOVAR	r0x1019
	JBCLR	STATUS,0
	JZAR	r0x1019
	ADDRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:96: 	iTemp71 [k96 lr88:89 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] < 0x0 {long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
;	.line	96; "../libsdcc/fsadd.c"	if (mant1 < 0)
	BSET	STATUS,0
	JBSET	r0x1015,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00123_DS_
;;genSkipc:3246: created from rifx:0xbfe61180
;;[ICODE] ../libsdcc/fsadd.c:96: 	if iTemp71 [k96 lr88:89 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_8($19)
;;[ICODE] ../libsdcc/fsadd.c:98: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = - iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ]
;	.line	98; "../libsdcc/fsadd.c"	mant1 = -mant1;
	COMR	r0x100B
	COMR	r0x100A
	COMR	r0x1014
	COMR	r0x1015
	INCR	r0x100B
	JBCLR	STATUS,2
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x1014
	JBCLR	STATUS,2
	INCR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:99: 	iTemp2 [k6 lr5:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsadd_sign_1_22}[r0x1008 r0x1009 r0x100A r0x100B ] := 0x80000000 {unsigned-long-int literal}
;	.line	99; "../libsdcc/fsadd.c"	sign = SIGNBIT;
	CLRR	r0x1010
	CLRR	r0x1011
	CLRR	r0x1012
	MOVAI	0x80
	MOVRA	r0x1013
;;[ICODE] ../libsdcc/fsadd.c:99: 	 goto preHeaderLbl0($41)
	GOTO	_00125_DS_
;;[ICODE] ../libsdcc/fsadd.c:99:  _iffalse_8($19) :
;;[ICODE] ../libsdcc/fsadd.c:101: 	if iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] != 0 goto preHeaderLbl0($41)
_00123_DS_
;	.line	101; "../libsdcc/fsadd.c"	else if (!mant1)
	MOVAR	r0x100B
	ORAR	r0x100A
	ORAR	r0x1014
	ORAR	r0x1015
	JBSET	STATUS,2
	GOTO	_00125_DS_
;;[ICODE] ../libsdcc/fsadd.c:102: 	ret 0 {float literal}
;	.line	102; "../libsdcc/fsadd.c"	return (0);
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00133_DS_
;;[ICODE] ../libsdcc/fsadd.c:105:  preHeaderLbl0($41) :
;;[ICODE] ../libsdcc/fsadd.c:105: 	iTemp77 [k102 lr98:109 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] := iTemp19 [k32 lr28:98 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ]
;;[ICODE] ../libsdcc/fsadd.c:105:  _whilecontinue_0($21) :
;;[ICODE] ../libsdcc/fsadd.c:105: 	iTemp73 [k98 lr101:102 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x1007 r0x100E r0x100F ] = (unsigned-long-int register)iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ]
_00125_DS_
;	.line	105; "../libsdcc/fsadd.c"	while (mant1<HIDDEN) {
	MOVAR	r0x100B
	MOVRA	r0x100D
	MOVAR	r0x100A
	MOVRA	r0x100C
;;112	MOVAR	r0x1014
	MOVAR	r0x1015
	MOVRA	r0x1017
;;[ICODE] ../libsdcc/fsadd.c:105: 	iTemp74 [k99 lr102:103 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp73 [k98 lr101:102 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x1007 r0x100E r0x100F ] & 0xff800000 {const-long-int literal}
;;111	MOVAR	r0x1016
	MOVAR	r0x1014
	MOVRA	r0x1016
	JBCLR	r0x1016,7
	GOTO	_00130_DS_
	MOVAR	r0x1017
	ANDAI	0xff
	JBSET	STATUS,2
	GOTO	_00130_DS_
;;[ICODE] ../libsdcc/fsadd.c:105: 	if iTemp74 [k99 lr102:103 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto preHeaderLbl1($44)
;;[ICODE] ../libsdcc/fsadd.c:106: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] << 0x1 {const-unsigned-char literal}
;	.line	106; "../libsdcc/fsadd.c"	mant1 <<= 1;
	BCLR	STATUS,0
	RLR	r0x100B
	RLR	r0x100A
	RLR	r0x1014
	RLR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:107: 	iTemp77 [k102 lr98:109 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] = iTemp77 [k102 lr98:109 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ] - 0x1 {const-unsigned-char literal}
;	.line	107; "../libsdcc/fsadd.c"	exp1--;
	MOVAI	0xff
	ADDRA	r0x100F
	JBSET	STATUS,0
	DECR	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:107: 	 goto _whilecontinue_0($21)
	GOTO	_00125_DS_
;;[ICODE] ../libsdcc/fsadd.c:111:  preHeaderLbl1($44) :
;;[ICODE] ../libsdcc/fsadd.c:111: 	iTemp84 [k109 lr109:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] := iTemp77 [k102 lr98:109 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1004 r0x1005 ]
;;[ICODE] ../libsdcc/fsadd.c:111:  _whilecontinue_1($26) :
;;[ICODE] ../libsdcc/fsadd.c:111: 	iTemp78 [k103 lr112:125 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x1007 r0x100E r0x100F ] = (unsigned-long-int register)iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ]
_00130_DS_
;	.line	111; "../libsdcc/fsadd.c"	while (mant1 & 0xff000000) {
	MOVAR	r0x100B
	MOVRA	r0x100D
	MOVAR	r0x100A
	MOVRA	r0x100C
	MOVAR	r0x1014
	MOVRA	r0x1016
;;114	MOVAR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:111: 	iTemp79 [k104 lr113:114 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp78 [k103 lr112:125 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x1007 r0x100E r0x100F ] & 0xff000000 {const-unsigned-long-int literal}
;;113	MOVAR	r0x1017
	MOVAR	r0x1015
	MOVRA	r0x1017
	ANDAI	0xff
	JBCLR	STATUS,2
	GOTO	_00132_DS_
;;[ICODE] ../libsdcc/fsadd.c:111: 	if iTemp79 [k104 lr113:114 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto _whilebreak_1($28)
;;[ICODE] ../libsdcc/fsadd.c:112: 	iTemp80 [k105 lr115:116 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed} = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] & 0x1 {long-int literal}
;	.line	112; "../libsdcc/fsadd.c"	if (mant1&1)
	JBSET	r0x100B,0
	GOTO	_00129_DS_
;;[ICODE] ../libsdcc/fsadd.c:112: 	if iTemp80 [k105 lr115:116 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int fixed} == 0 goto _iffalse_9($25)
;;[ICODE] ../libsdcc/fsadd.c:113: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] + 0x2 {long-int literal}
;	.line	113; "../libsdcc/fsadd.c"	mant1 += 2;
	MOVAI	0x02
	ADDRA	r0x100B
	JBCLR	STATUS,0
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x1014
	JBCLR	STATUS,2
	INCR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:113:  _iffalse_9($25) :
;;[ICODE] ../libsdcc/fsadd.c:114: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=1, same=1, offr=0
_00129_DS_
;	.line	114; "../libsdcc/fsadd.c"	mant1 >>= 1 ;
	BCLR	STATUS,0
	JBCLR	r0x1015,7
	BSET	STATUS,0
	RRR	r0x1015
	RRR	r0x1014
	RRR	r0x100A
	RRR	r0x100B
;;[ICODE] ../libsdcc/fsadd.c:115: 	iTemp84 [k109 lr109:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] = iTemp84 [k109 lr109:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ] + 0x1 {const-unsigned-char literal}
;	.line	115; "../libsdcc/fsadd.c"	exp1++;
	INCR	r0x100F
	JBCLR	STATUS,2
	INCR	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:115: 	 goto _whilecontinue_1($26)
	GOTO	_00130_DS_
;;[ICODE] ../libsdcc/fsadd.c:115:  _whilebreak_1($28) :
;;[ICODE] ../libsdcc/fsadd.c:119: 	iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp78 [k103 lr112:125 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x1007 r0x100E r0x100F ] & 0xff7fffff {unsigned-long-int literal}
_00132_DS_
;	.line	119; "../libsdcc/fsadd.c"	mant1 &= ~HIDDEN;
	MOVAR	r0x100D
	MOVRA	r0x100B
	MOVAR	r0x100C
	MOVRA	r0x100A
	MOVAI	0x7f
	ANDAR	r0x1016
	MOVRA	r0x1014
	MOVAR	r0x1017
	MOVRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp87 [k112 lr127:133 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp89 [k115 lr128:129 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x100E r0x100F ] = (unsigned-long-int fixed)iTemp84 [k109 lr109:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsadd_exp1_1_22}[r0x1004 r0x1005 ]
;	.line	122; "../libsdcc/fsadd.c"	fl1.l = PACK (sign, (unsigned long) exp1, mant1);
	MOVAR	r0x100F
	MOVRA	r0x100D
	MOVAR	r0x100E
	MOVRA	r0x100C
	MOVAI	0x00
	JBCLR	r0x100C,7
	MOVAI	0xff
	MOVRA	r0x1017
	MOVRA	r0x1016
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp90 [k116 lr129:130 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1010 r0x1011 ] = iTemp89 [k115 lr128:129 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x100E r0x100F ] << 0x17 {const-unsigned-char literal}
	RRAR	r0x100C
	RRAR	r0x100D
	MOVRA	r0x1019
	CLRR	r0x1018
	RRR	r0x1018
	CLRR	r0x100E
	CLRR	r0x100F
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp91 [k117 lr130:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] = iTemp2 [k6 lr5:130 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsadd_sign_1_22}[r0x1008 r0x1009 r0x100A r0x100B ] | iTemp90 [k116 lr129:130 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1010 r0x1011 ]
	MOVAI	0x00
	ORRA	r0x1010
	MOVAI	0x00
	ORRA	r0x1011
	MOVAR	r0x1018
	ORRA	r0x1012
	MOVAR	r0x1019
	ORRA	r0x1013
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp92 [k118 lr131:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = (unsigned-long-int fixed)iTemp43 [k62 lr53:131 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsadd_mant1_1_22}[r0x1000 r0x1001 r0x100C r0x100D ]
;;102	MOVAR	r0x100B
;;104	MOVAR	r0x100A
;;106	MOVAR	r0x1014
;;108	MOVAR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:122: 	iTemp93 [k119 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ] = iTemp91 [k117 lr130:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1008 r0x1009 r0x100A r0x100B ] | iTemp92 [k118 lr131:132 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;101	MOVAR	r0x100F
	MOVAR	r0x100B
	MOVRA	r0x100F
	ORAR	r0x1010
	MOVRA	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
;;103	MOVAR	r0x100E
	MOVAR	r0x100A
	MOVRA	r0x100E
	ORAR	r0x1011
	MOVRA	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
;;105	MOVAR	r0x100D
	MOVAR	r0x1014
	MOVRA	r0x100D
	ORAR	r0x1012
	MOVRA	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x1014
;;107	MOVAR	r0x100C
	MOVAR	r0x1015
	MOVRA	r0x100C
	ORAR	r0x1013
	MOVRA	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:122: 	*(iTemp87 [k112 lr127:133 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-long-int near* fixed}[remat]) := iTemp93 [k119 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;99	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;;100	MOVAR	r0x100A
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
;;109	MOVAR	r0x1014
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
;;110	MOVAR	r0x1015
;;[ICODE] ../libsdcc/fsadd.c:124: 	iTemp94 [k120 lr134:135 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsadd_fl1_1_22 [k8 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsadd.c:124: 	iTemp96 [k123 lr135:136 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1004 r0x1005 ] = @[iTemp94 [k120 lr134:135 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	124; "../libsdcc/fsadd.c"	return (fl1.f);
	MOVAR	(___fsadd_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsadd_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsadd_fl1_1_22 + 2)
	MOVRA	r0x100F
	MOVAR	(___fsadd_fl1_1_22 + 3)
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:124: 	ret iTemp96 [k123 lr135:136 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1004 r0x1005 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x100F
	MOVRA	STK00
	MOVAR	r0x100E
;;[ICODE] ../libsdcc/fsadd.c:124:  _return($29) :
;;[ICODE] ../libsdcc/fsadd.c:124: 	eproc ___fsadd [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
_00133_DS_
	RETURN	
; exit point of ___fsadd


;	code size estimation:
;	  545+    0 =   545 instructions ( 1090 byte)

	end
