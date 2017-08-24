;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:36:17 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fs2ulong.c"
	list	p=32p7022
	radix dec
	include "mc32p7022.inc"
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
	global	___fs2ulong

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fs2ulong_0	udata
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
___fs2ulong_fl1_1_22	res	4
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
code_fs2ulong	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fs2ulong	;Function start
; 2 exit points
;has an exit
;16 compiler assigned registers:
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
;   r0x1010
;; Starting pCode block
;;[ICODE] ../libsdcc/fs2ulong.c:55:  _entry($5) :
;;[ICODE] ../libsdcc/fs2ulong.c:55: 	proc ___fs2ulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
___fs2ulong	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fs2ulong.c:55: iTemp0 [k2 lr3:5 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2ulong_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fs2ulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
;	.line	55; "../libsdcc/fs2ulong.c"	unsigned long __fs2ulong (float a1) _FS_REENTRANT
	MOVRA	r0x1004
	MOVAR	STK00
	MOVRA	r0x1005
	MOVAR	STK01
	MOVRA	r0x1006
	MOVAR	STK02
	MOVRA	(___fs2ulong_fl1_1_22 + 0)
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/fs2ulong.c:61: 	iTemp1 [k5 lr4:5 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fs2ulong_fl1_1_22 [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fs2ulong.c:61: 	*(iTemp1 [k5 lr4:5 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:5 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2ulong_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;110	MOVAR	r0x1007
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	61; "../libsdcc/fs2ulong.c"	fl1.f = a1;
	MOVAR	r0x1006
	MOVRA	(___fs2ulong_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1005
	MOVRA	(___fs2ulong_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1004
	MOVRA	(___fs2ulong_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp3 [k8 lr6:7 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fs2ulong_fl1_1_22 [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp5 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp3 [k8 lr6:7 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	63; "../libsdcc/fs2ulong.c"	if (!fl1.l || SIGN(fl1.l))
	MOVAR	(___fs2ulong_fl1_1_22 + 0)
	MOVRA	r0x1007
	MOVAR	(___fs2ulong_fl1_1_22 + 1)
	MOVRA	r0x1006
	MOVAR	(___fs2ulong_fl1_1_22 + 2)
	MOVRA	r0x1005
	MOVAR	(___fs2ulong_fl1_1_22 + 3)
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	if iTemp5 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] == 0 goto _iftrue_0($1)
	MOVAR	r0x1007
	ORAR	r0x1006
	ORAR	r0x1005
	ORAR	r0x1004
	JBCLR	STATUS,2
	GOTO	_00105_DS_
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp6 [k12 lr9:10 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fs2ulong_fl1_1_22 [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp8 [k15 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp6 [k12 lr9:10 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fs2ulong_fl1_1_22 + 0)
	MOVRA	r0x1008
	MOVRA	r0x1007
	MOVAR	(___fs2ulong_fl1_1_22 + 1)
	MOVRA	r0x1009
	MOVRA	r0x1006
	MOVAR	(___fs2ulong_fl1_1_22 + 2)
	MOVRA	r0x100A
	MOVRA	r0x1005
	MOVAR	(___fs2ulong_fl1_1_22 + 3)
	MOVRA	r0x100B
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp9 [k16 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = (unsigned-long-int fixed)iTemp8 [k15 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;109	MOVAR	r0x1007
;;100	MOVAR	r0x1006
;;101	MOVAR	r0x1005
;;102	MOVAR	r0x1004
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	iTemp10 [k17 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1000 ] = gabit iTemp9 [k16 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x100B
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x1007
;;[ICODE] ../libsdcc/fs2ulong.c:63: 	if iTemp10 [k17 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1000 ] == 0 goto _iffalse_0($2)
	MOVAI	0x00
	ORAR	r0x1007
	JBCLR	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fs2ulong.c:63:  _iftrue_0($1) :
;;[ICODE] ../libsdcc/fs2ulong.c:64: 	ret 0x0 {unsigned-long-int literal}
_00105_DS_
;	.line	64; "../libsdcc/fs2ulong.c"	return (0);
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/fs2ulong.c:64:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp12 [k20 lr17:18 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fs2ulong_fl1_1_22 [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp14 [k23 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1004 r0x1005 r0x1006 ] = @[iTemp12 [k20 lr17:18 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00106_DS_
;	.line	66; "../libsdcc/fs2ulong.c"	exp = EXP (fl1.l) - EXCESS - 24;
	MOVAR	(___fs2ulong_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVRA	r0x1007
	MOVAR	(___fs2ulong_fl1_1_22 + 1)
	MOVRA	r0x100C
	MOVRA	r0x1008
	MOVAR	(___fs2ulong_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fs2ulong_fl1_1_22 + 3)
	MOVRA	r0x100E
	MOVRA	r0x100A
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp15 [k24 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = (unsigned-long-int fixed)iTemp14 [k23 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1004 r0x1005 r0x1006 ]
;;107	MOVAR	r0x1007
;;103	MOVAR	r0x1008
	MOVAR	r0x1009
	MOVRA	r0x100D
;;108	MOVAR	r0x100A
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp16 [k25 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1004 r0x1005 r0x1006 ] = iTemp15 [k24 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x100D
	RLAR	r0x100E
	MOVRA	r0x100B
	MOVRA	r0x1007
	CLRR	r0x1008
	RLR	r0x1008
	CLRR	r0x1009
	CLRR	r0x100A
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp17 [k26 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp16 [k25 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1004 r0x1005 r0x1006 ] & 0xff {unsigned-long-int literal}
;;99	MOVAR	r0x1007
	CLRR	r0x100C
	CLRR	r0x100D
	CLRR	r0x100E
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp18 [k27 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] = iTemp17 [k26 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ] - 0x96 {unsigned-long-int literal}
	MOVAI	0x6a
	ADDRA	r0x100B
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x100C
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x100D
	MOVAI	0xff
	JBSET	STATUS,0
	ADDRA	r0x100E
;;[ICODE] ../libsdcc/fs2ulong.c:66: 	iTemp11 [k18 lr23:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fs2ulong_exp_1_22}[r0x1000 r0x1004 ] = (int fixed)iTemp18 [k27 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1007 r0x1008 r0x1009 r0x100A ]
	MOVAR	r0x100B
	MOVRA	r0x1007
	MOVAR	r0x100C
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fs2ulong.c:67: 	iTemp21 [k31 lr25:26 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fs2ulong_fl1_1_22 [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fs2ulong.c:67: 	iTemp23 [k34 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1005 r0x1006 r0x1007 r0x1008 ] = @[iTemp21 [k31 lr25:26 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	67; "../libsdcc/fs2ulong.c"	l = MANT (fl1.l);
	MOVAR	(___fs2ulong_fl1_1_22 + 0)
	MOVRA	r0x1009
	MOVAR	(___fs2ulong_fl1_1_22 + 1)
	MOVRA	r0x100E
	MOVRA	r0x100A
	MOVAR	(___fs2ulong_fl1_1_22 + 2)
	MOVRA	r0x100F
	MOVRA	r0x100B
	MOVAR	(___fs2ulong_fl1_1_22 + 3)
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fs2ulong.c:67: 	iTemp24 [k35 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1009 r0x100A r0x100B r0x100C ] = (unsigned-long-int register)iTemp23 [k34 lr26:27 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1005 r0x1006 r0x1007 r0x1008 ]
	MOVAR	r0x1009
	MOVRA	r0x1009
	MOVRA	r0x100D
;;104	MOVAR	r0x100A
;;105	MOVAR	r0x100B
	MOVAR	r0x100C
;;1	MOVRA	r0x1010
;;[ICODE] ../libsdcc/fs2ulong.c:67: 	iTemp25 [k36 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1005 r0x1006 r0x1007 r0x1008 ] = iTemp24 [k35 lr27:28 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1009 r0x100A r0x100B r0x100C ] & 0x7fffff {unsigned-long-int literal}
;;106	MOVAR	r0x100D
	MOVAR	r0x100E
	MOVRA	r0x100A
	MOVAI	0x7f
	ANDAR	r0x100F
	MOVRA	r0x100B
	CLRR	r0x100C
;;[ICODE] ../libsdcc/fs2ulong.c:67: 	iTemp20 [k29 lr29:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2ulong_l_1_22}[r0x1005 r0x1006 r0x1007 r0x1008 ] = iTemp25 [k36 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1005 r0x1006 r0x1007 r0x1008 ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x100B,7
;;[ICODE] ../libsdcc/fs2ulong.c:69: 	iTemp27 [k38 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1000 r0x1004 ] = - iTemp11 [k18 lr23:31 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fs2ulong_exp_1_22}[r0x1000 r0x1004 ]
;	.line	69; "../libsdcc/fs2ulong.c"	l >>= -exp;
	COMR	r0x1007
	COMR	r0x1008
	INCR	r0x1007
	JBCLR	STATUS,2
	INCR	r0x1008
;;[ICODE] ../libsdcc/fs2ulong.c:69: 	iTemp20 [k29 lr29:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2ulong_l_1_22}[r0x1005 r0x1006 r0x1007 r0x1008 ] = iTemp20 [k29 lr29:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2ulong_l_1_22}[r0x1005 r0x1006 r0x1007 r0x1008 ] >> iTemp27 [k38 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed}[r0x1000 r0x1004 ]
	MOVAR	r0x1007
	JBCLR	r0x1007,7
	GOTO	_00114_DS_
	ISUBAI	0x00
	JBCLR	STATUS,2
	GOTO	_00113_DS_
_00112_DS_
	RRR	r0x100C
	RRR	r0x100B
	RRR	r0x100A
	RRR	r0x1009
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00112_DS_
	GOTO	_00113_DS_
_00114_DS_
	BCLR	STATUS,0
_00115_DS_
	RLR	r0x1009
	RLR	r0x100A
	RLR	r0x100B
	RLR	r0x100C
	ADDAI	0x01
	JBSET	STATUS,0
	GOTO	_00115_DS_
;;[ICODE] ../libsdcc/fs2ulong.c:71: 	ret iTemp20 [k29 lr29:34 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2ulong_l_1_22}[r0x1005 r0x1006 r0x1007 r0x1008 ]
_00113_DS_
;	.line	71; "../libsdcc/fs2ulong.c"	return l;
	MOVAR	r0x1009
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x100B
	MOVRA	STK00
	MOVAR	r0x100C
;;[ICODE] ../libsdcc/fs2ulong.c:71:  _return($4) :
;;[ICODE] ../libsdcc/fs2ulong.c:71: 	eproc ___fs2ulong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
_00108_DS_
	RETURN	
; exit point of ___fs2ulong


;	code size estimation:
;	  152+    0 =   152 instructions (  304 byte)

	end
