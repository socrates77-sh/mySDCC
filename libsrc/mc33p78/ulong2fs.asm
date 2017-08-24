;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:37:00 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/ulong2fs.c"
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
	extern	___slong2fs
	extern	___fs2uchar
	extern	___fs2schar
	extern	___fs2uint
	extern	___fs2sint
	extern	___fs2ulong
	extern	___fs2slong
	extern	___fsadd
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
	global	___ulong2fs

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_ulong2fs_0	udata
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
r0x100F	res	1
r0x100E	res	1
___ulong2fs_fl_1_22	res	4
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
code_ulong2fs	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___ulong2fs	;Function start
; 2 exit points
;has an exit
;15 compiler assigned registers:
;   r0x1004
;   STK00
;   r0x1005
;   STK01
;   r0x1006
;   STK02
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
;;[ICODE] ../libsdcc/ulong2fs.c:54:  _entry($14) :
;;[ICODE] ../libsdcc/ulong2fs.c:54: 	proc ___ulong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
___ulong2fs	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/ulong2fs.c:54: iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___ulong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
;	.line	54; "../libsdcc/ulong2fs.c"	float __ulong2fs (unsigned long a ) _FS_REENTRANT
	MOVRA	r0x1004
	MOVAR	STK00
	MOVRA	r0x1005
	MOVAR	STK01
	MOVRA	r0x1006
	MOVAR	STK02
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/ulong2fs.c:59: 	if iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto preHeaderLbl0($17)
;	.line	59; "../libsdcc/ulong2fs.c"	if (!a)
	MOVAR	r0x1007
	ORAR	r0x1006
	ORAR	r0x1005
	ORAR	r0x1004
	JBSET	STATUS,2
	GOTO	_00121_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:61: 	ret 0 {const-float literal}
;	.line	61; "../libsdcc/ulong2fs.c"	return 0.0;
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00117_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:64:  preHeaderLbl0($17) :
;;[ICODE] ../libsdcc/ulong2fs.c:64: 	iTemp5 [k9 lr7:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] := 0x96 {int literal}
_00121_DS_
;	.line	64; "../libsdcc/ulong2fs.c"	while (a & NORM) 
	MOVAI	0x96
	MOVRA	r0x1008
	CLRR	r0x1009
;;[ICODE] ../libsdcc/ulong2fs.c:64:  _whilecontinue_0($3) :
;;[ICODE] ../libsdcc/ulong2fs.c:64: 	iTemp2 [k6 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0xff000000 {const-unsigned-long-int literal}
_00107_DS_
	MOVAR	r0x1004
	ANDAI	0xff
	JBCLR	STATUS,2
	GOTO	_00124_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:64: 	if iTemp2 [k6 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register} == 0 goto loopExitLbl2($20)
;;[ICODE] ../libsdcc/ulong2fs.c:67: 	iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=0, same=1, offr=0
;	.line	67; "../libsdcc/ulong2fs.c"	a >>= 1;
	BCLR	STATUS,0
	RRR	r0x1004
	RRR	r0x1005
	RRR	r0x1006
	RRR	r0x1007
;;[ICODE] ../libsdcc/ulong2fs.c:68: 	iTemp5 [k9 lr7:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] = iTemp5 [k9 lr7:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] + 0x1 {const-unsigned-char literal}
;	.line	68; "../libsdcc/ulong2fs.c"	exp++;
	INCR	r0x1008
	JBCLR	STATUS,2
	INCR	r0x1009
;;[ICODE] ../libsdcc/ulong2fs.c:68: 	 goto _whilecontinue_0($3)
	GOTO	_00107_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:68:  loopExitLbl2($20) :
;;[ICODE] ../libsdcc/ulong2fs.c:68: 	iTemp1 [k4 lr17:40 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] := iTemp5 [k9 lr7:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ]
_00124_DS_
	MOVAR	r0x1008
	MOVRA	r0x100A
	MOVAR	r0x1009
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/ulong2fs.c:72: 	iTemp6 [k10 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0xff800000 {const-long-int literal}
;	.line	72; "../libsdcc/ulong2fs.c"	if(a < HIDDEN) {
	MOVAR	r0x1005
	JBCLR	r0x1005,7
	GOTO	_00114_DS_
	MOVAR	r0x1004
	ANDAI	0xff
	JBSET	STATUS,2
	GOTO	_00114_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:72: 	if iTemp6 [k10 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_1($10)
;;[ICODE] ../libsdcc/ulong2fs.c:73: 	iTemp9 [k13 lr20:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] := iTemp5 [k9 lr7:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ]
;;[ICODE] ../libsdcc/ulong2fs.c:73:  _dobody_0($6) :
;;[ICODE] ../libsdcc/ulong2fs.c:74: 	iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] << 0x1 {const-unsigned-char literal}
_00110_DS_
;	.line	74; "../libsdcc/ulong2fs.c"	a<<=1;
	BCLR	STATUS,0
	RLR	r0x1007
	RLR	r0x1006
	RLR	r0x1005
	RLR	r0x1004
;;[ICODE] ../libsdcc/ulong2fs.c:75: 	iTemp9 [k13 lr20:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] = iTemp9 [k13 lr20:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ] - 0x1 {const-unsigned-char literal}
;	.line	75; "../libsdcc/ulong2fs.c"	exp--;
	MOVAI	0xff
	ADDRA	r0x1008
	JBSET	STATUS,0
	DECR	r0x1009
;;[ICODE] ../libsdcc/ulong2fs.c:76: 	iTemp10 [k14 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0xff800000 {const-long-int literal}
;	.line	76; "../libsdcc/ulong2fs.c"	} while (a < HIDDEN);
	MOVAR	r0x1005
	JBSET	r0x1005,7
	GOTO	_00110_DS_
	MOVAR	r0x1004
	ANDAI	0xff
	JBCLR	STATUS,2
	GOTO	_00110_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:76: 	if iTemp10 [k14 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _dobody_0($6)
;;[ICODE] ../libsdcc/ulong2fs.c:76: 	iTemp1 [k4 lr17:40 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] := iTemp9 [k13 lr20:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___ulong2fs_exp_1_22}[r0x1004 r0x1005 ]
	MOVAR	r0x1008
	MOVRA	r0x100A
	MOVAR	r0x1009
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/ulong2fs.c:76:  _iffalse_1($10) :
;;[ICODE] ../libsdcc/ulong2fs.c:87: 	iTemp11 [k15 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1008 r0x1009 ] = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0x7fffff {unsigned-long-int literal}
;;100	MOVAR	r0x1007
_00114_DS_
;	.line	87; "../libsdcc/ulong2fs.c"	if ((a&0x7fffff)==0x7fffff) {
	MOVAR	r0x1006
	MOVRA	r0x1009
	MOVAI	0x7f
	ANDAR	r0x1005
	MOVRA	r0x100C
	CLRR	r0x100D
;;[ICODE] ../libsdcc/ulong2fs.c:87: 	iTemp12 [k16 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp11 [k15 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1004 r0x1005 r0x1008 r0x1009 ] == 0x7fffff {unsigned-long-int literal}
;;99	MOVAR	r0x1008
	MOVAR	r0x1007
	MOVRA	r0x1008
	XORAI	0xff
	JBSET	STATUS,2
	GOTO	_00116_DS_
	MOVAR	r0x1009
	XORAI	0xff
	JBSET	STATUS,2
	GOTO	_00116_DS_
	MOVAR	r0x100C
	XORAI	0x7f
	JBSET	STATUS,2
	GOTO	_00116_DS_
	MOVAR	r0x100D
	XORAI	0x00
	JBSET	STATUS,2
	GOTO	_00116_DS_
;;[ICODE] ../libsdcc/ulong2fs.c:87: 	if iTemp12 [k16 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($12)
;;[ICODE] ../libsdcc/ulong2fs.c:88: 	iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] := 0x0 {unsigned-long-int literal}
;	.line	88; "../libsdcc/ulong2fs.c"	a=0;
	CLRR	r0x1007
	CLRR	r0x1006
	CLRR	r0x1005
	CLRR	r0x1004
;;[ICODE] ../libsdcc/ulong2fs.c:89: 	iTemp1 [k4 lr17:40 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] = iTemp1 [k4 lr17:40 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ] + 0x1 {const-unsigned-char literal}
;	.line	89; "../libsdcc/ulong2fs.c"	exp++;
	INCR	r0x100A
	JBCLR	STATUS,2
	INCR	r0x100B
;;[ICODE] ../libsdcc/ulong2fs.c:89:  _iffalse_2($12) :
;;[ICODE] ../libsdcc/ulong2fs.c:93: 	iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0xff7fffff {unsigned-long-int literal}
_00116_DS_
;	.line	93; "../libsdcc/ulong2fs.c"	a &= ~HIDDEN ;
	BCLR	r0x1005,7
;;[ICODE] ../libsdcc/ulong2fs.c:95: 	iTemp16 [k21 lr39:43 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___ulong2fs_fl_1_22 [k20 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/ulong2fs.c:95: 	iTemp18 [k24 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1008 r0x1009 ] = (unsigned-long-int fixed)iTemp1 [k4 lr17:40 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}[r0x1006 r0x1007 ]
;	.line	95; "../libsdcc/ulong2fs.c"	fl.l = PACK(0,(unsigned long)exp, a);
	MOVAR	r0x100A
	MOVRA	r0x1008
	MOVAR	r0x100B
	MOVRA	r0x1009
	MOVAI	0x00
	JBCLR	r0x1009,7
	MOVAI	0xff
	MOVRA	r0x100D
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/ulong2fs.c:95: 	iTemp19 [k25 lr41:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x100A r0x100B ] = iTemp18 [k24 lr40:41 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1008 r0x1009 ] << 0x17 {const-unsigned-char literal}
	RRAR	r0x1009
	RRAR	r0x1008
	MOVRA	r0x100E
	CLRR	r0x100F
	RRR	r0x100F
	CLRR	r0x100B
	CLRR	r0x100A
;;[ICODE] ../libsdcc/ulong2fs.c:95: 	iTemp21 [k27 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp19 [k25 lr41:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x100A r0x100B ] | iTemp0 [k2 lr3:42 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___ulong2fs_a_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAI	0x00
	ORRA	r0x1007
	MOVAI	0x00
	ORRA	r0x1006
	MOVAR	r0x100F
	ORRA	r0x1005
	MOVAR	r0x100E
	ORRA	r0x1004
;;[ICODE] ../libsdcc/ulong2fs.c:95: 	*(iTemp16 [k21 lr39:43 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := iTemp21 [k27 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x1007
	MOVRA	(___ulong2fs_fl_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1006
	MOVRA	(___ulong2fs_fl_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1005
	MOVRA	(___ulong2fs_fl_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1004
	MOVRA	(___ulong2fs_fl_1_22 + 3)
;;[ICODE] ../libsdcc/ulong2fs.c:97: 	iTemp22 [k28 lr44:45 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___ulong2fs_fl_1_22 [k20 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/ulong2fs.c:97: 	iTemp24 [k31 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp22 [k28 lr44:45 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	97; "../libsdcc/ulong2fs.c"	return (fl.f);
	MOVAR	(___ulong2fs_fl_1_22 + 0)
	MOVRA	r0x1007
	MOVAR	(___ulong2fs_fl_1_22 + 1)
	MOVRA	r0x1006
	MOVAR	(___ulong2fs_fl_1_22 + 2)
	MOVRA	r0x1005
	MOVAR	(___ulong2fs_fl_1_22 + 3)
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/ulong2fs.c:97: 	ret iTemp24 [k31 lr45:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1007
	MOVRA	STK02
	MOVAR	r0x1006
	MOVRA	STK01
	MOVAR	r0x1005
	MOVRA	STK00
	MOVAR	r0x1004
;;[ICODE] ../libsdcc/ulong2fs.c:97:  _return($13) :
;;[ICODE] ../libsdcc/ulong2fs.c:97: 	eproc ___ulong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
_00117_DS_
	RETURN	
; exit point of ___ulong2fs


;	code size estimation:
;	  147+    0 =   147 instructions (  294 byte)

	end
