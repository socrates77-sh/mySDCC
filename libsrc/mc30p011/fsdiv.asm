;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:30:20 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fsdiv.c"
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
	extern	___fssub
	extern	___fsmul
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
	global	___fsdiv

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fsdiv_0	udata
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
r0x1020	res	1
r0x1021	res	1
r0x1022	res	1
r0x1023	res	1
r0x1024	res	1
___fsdiv_fl1_1_22	res	4
___fsdiv_fl2_1_22	res	4
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
code_fsdiv	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fsdiv	;Function start
; 2 exit points
;has an exit
;36 compiler assigned registers:
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
;   r0x1020
;   r0x1021
;   r0x1022
;   r0x1023
;   r0x1024
;; Starting pCode block
;;[ICODE] ../libsdcc/fsdiv.c:55:  _entry($19) :
;;[ICODE] ../libsdcc/fsdiv.c:55: 	proc ___fsdiv [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
___fsdiv	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fsdiv.c:55: iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsdiv_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fsdiv [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
;	.line	55; "../libsdcc/fsdiv.c"	float __fsdiv (float a1, float a2) _FS_REENTRANT
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fsdiv.c:55: iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsdiv_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv ___fsdiv [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x100C
	MOVAR	STK04
	MOVRA	r0x100D
	MOVAR	STK05
	MOVRA	r0x100E
	MOVAR	STK06
	MOVRA	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsdiv.c:64: 	iTemp2 [k7 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:64: 	*(iTemp2 [k7 lr5:6 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsdiv_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;136	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	64; "../libsdcc/fsdiv.c"	fl1.f = a1;
	MOVAR	r0x100A
	MOVRA	(___fsdiv_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsdiv_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsdiv_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:65: 	iTemp4 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:65: 	*(iTemp4 [k11 lr7:8 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsdiv_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;133	MOVAR	r0x100F
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	65; "../libsdcc/fsdiv.c"	fl2.f = a2;
	MOVAR	r0x100E
	MOVRA	(___fsdiv_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fsdiv_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fsdiv_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp7 [k16 lr9:10 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp9 [k19 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp7 [k16 lr9:10 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	68; "../libsdcc/fsdiv.c"	exp = EXP (fl1.l) ;
	MOVAR	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x100F
	MOVRA	r0x100B
	MOVAR	(___fsdiv_fl1_1_22 + 1)
	MOVRA	r0x100E
	MOVRA	r0x100A
	MOVAR	(___fsdiv_fl1_1_22 + 2)
	MOVRA	r0x100D
	MOVRA	r0x1009
	MOVAR	(___fsdiv_fl1_1_22 + 3)
	MOVRA	r0x100C
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp10 [k20 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = (unsigned-long-int fixed)iTemp9 [k19 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;130	MOVAR	r0x100B
;;122	MOVAR	r0x100A
;;137	MOVAR	r0x1009
;;132	MOVAR	r0x1008
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp11 [k21 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = iTemp10 [k20 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x100D
	RLAR	r0x100C
	MOVRA	r0x100F
	MOVRA	r0x100B
	CLRR	r0x100A
	RLR	r0x100A
	CLRR	r0x1009
	CLRR	r0x1008
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp12 [k22 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = iTemp11 [k21 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] & 0xff {unsigned-long-int literal}
;;121	MOVAR	r0x100B
	CLRR	r0x100E
	CLRR	r0x100D
	CLRR	r0x100C
;;[ICODE] ../libsdcc/fsdiv.c:68: 	iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] = (int fixed)iTemp12 [k22 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x100F
	MOVRA	r0x100B
	MOVAI	0x00
	MOVRA	r0x100A
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp14 [k24 lr16:17 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp16 [k27 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] = @[iTemp14 [k24 lr16:17 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	69; "../libsdcc/fsdiv.c"	exp -= EXP (fl2.l);
	MOVAR	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x100D
	MOVRA	r0x1009
	MOVAR	(___fsdiv_fl2_1_22 + 1)
	MOVRA	r0x100C
	MOVRA	r0x1008
	MOVAR	(___fsdiv_fl2_1_22 + 2)
	MOVRA	r0x1010
	MOVRA	r0x100F
	MOVAR	(___fsdiv_fl2_1_22 + 3)
	MOVRA	r0x1011
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp17 [k28 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] = (unsigned-long-int fixed)iTemp16 [k27 lr17:18 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ]
;;131	MOVAR	r0x1009
;;124	MOVAR	r0x1008
;;125	MOVAR	r0x100F
;;126	MOVAR	r0x100E
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp18 [k29 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] = iTemp17 [k28 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] >> 0x17 {const-unsigned-char literal}
	RLAR	r0x1010
	RLAR	r0x1011
	MOVRA	r0x100D
	MOVRA	r0x1009
	CLRR	r0x1008
	RLR	r0x1008
	CLRR	r0x100F
	CLRR	r0x100E
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp19 [k30 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] = iTemp18 [k29 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] & 0xff {unsigned-long-int literal}
;;123	MOVAR	r0x1009
	CLRR	r0x100C
	CLRR	r0x1010
	CLRR	r0x1011
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp20 [k31 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] = (unsigned-long-int fixed)iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ]
	MOVAR	r0x100B
	MOVRA	r0x1009
	MOVAR	r0x100A
	MOVRA	r0x1008
	MOVAI	0x00
	JBCLR	r0x1008,7
	MOVAI	0xff
	MOVRA	r0x100E
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp21 [k32 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] = iTemp20 [k31 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] - iTemp19 [k30 lr20:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ]
	MOVAR	r0x100D
	RSUBAR	r0x1009
	MOVRA	r0x100D
	MOVAR	r0x100C
	JBSET	STATUS,0
	JZAR	r0x100C
	GOTO	_00148_DS_
	MOVAR	r0x1008
	GOTO	_00149_DS_
_00148_DS_
	RSUBAR	r0x1008
_00149_DS_
	MOVRA	r0x100C
	MOVAR	r0x1010
	JBSET	STATUS,0
	JZAR	r0x1010
	GOTO	_00150_DS_
	MOVAR	r0x100F
	GOTO	_00151_DS_
_00150_DS_
	RSUBAR	r0x100F
_00151_DS_
	MOVRA	r0x1010
	MOVAR	r0x1011
	JBSET	STATUS,0
	INCAR	r0x1011
	RSUBAR	r0x100E
	MOVRA	r0x1011
;;[ICODE] ../libsdcc/fsdiv.c:69: 	iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] = (int fixed)iTemp21 [k32 lr22:23 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ]
	MOVAR	r0x100D
	MOVRA	r0x100B
	MOVAR	r0x100C
	MOVRA	r0x100A
;;[ICODE] ../libsdcc/fsdiv.c:70: 	iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] = iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] + 0x7e {int literal}
;	.line	70; "../libsdcc/fsdiv.c"	exp += EXCESS;
	MOVAI	0x7e
	ADDRA	r0x100B
	JBCLR	STATUS,0
	INCR	r0x100A
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp25 [k37 lr27:28 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp27 [k40 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] = @[iTemp25 [k37 lr27:28 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	73; "../libsdcc/fsdiv.c"	sign = SIGN (fl1.l) ^ SIGN (fl2.l);
	MOVAR	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x100D
	MOVRA	r0x1009
	MOVAR	(___fsdiv_fl1_1_22 + 1)
	MOVRA	r0x100C
	MOVRA	r0x1008
	MOVAR	(___fsdiv_fl1_1_22 + 2)
	MOVRA	r0x1010
	MOVRA	r0x100F
	MOVAR	(___fsdiv_fl1_1_22 + 3)
	MOVRA	r0x1011
	MOVRA	r0x100E
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp28 [k41 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] = (unsigned-long-int fixed)iTemp27 [k40 lr28:29 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ]
;;103	MOVAR	r0x1009
;;104	MOVAR	r0x1008
;;105	MOVAR	r0x100F
;;106	MOVAR	r0x100E
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp29 [k42 lr30:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1002 ] = gabit iTemp28 [k41 lr29:30 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ]
	MOVAR	r0x1011
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x1009
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp30 [k43 lr31:32 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp32 [k46 lr32:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ] = @[iTemp30 [k43 lr31:32 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x1012
	MOVRA	r0x100D
	MOVAR	(___fsdiv_fl2_1_22 + 1)
	MOVRA	r0x1013
	MOVRA	r0x100C
	MOVAR	(___fsdiv_fl2_1_22 + 2)
	MOVRA	r0x1014
	MOVRA	r0x1010
	MOVAR	(___fsdiv_fl2_1_22 + 3)
	MOVRA	r0x1015
	MOVRA	r0x1011
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp33 [k47 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100A r0x100B r0x100C r0x100D ] = (unsigned-long-int fixed)iTemp32 [k46 lr32:33 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x1007 r0x1008 r0x1009 ]
;;134	MOVAR	r0x100D
;;108	MOVAR	r0x100C
;;109	MOVAR	r0x1010
;;110	MOVAR	r0x1011
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp34 [k48 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1006 ] = gabit iTemp33 [k47 lr33:34 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100A r0x100B r0x100C r0x100D ]
	MOVAR	r0x1015
	ANDAI	0x80
	JBSET	STATUS,2
	MOVAI	0x01
	MOVRA	r0x100D
;;[ICODE] ../libsdcc/fsdiv.c:73: 	iTemp24 [k35 lr35:118 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsdiv_sign_1_22}[r0x1002 ] = iTemp29 [k42 lr30:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1002 ] ^ iTemp34 [k48 lr34:35 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1006 ]
	MOVAR	r0x100D
	XORRA	r0x1009
;;[ICODE] ../libsdcc/fsdiv.c:76: 	iTemp36 [k50 lr37:38 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:76: 	iTemp38 [k53 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ] = @[iTemp36 [k50 lr37:38 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	76; "../libsdcc/fsdiv.c"	if (!fl2.l)
	MOVAR	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x100D
	MOVAR	(___fsdiv_fl2_1_22 + 1)
	MOVRA	r0x1012
	MOVAR	(___fsdiv_fl2_1_22 + 2)
	MOVRA	r0x1013
	MOVAR	(___fsdiv_fl2_1_22 + 3)
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:76: 	if iTemp38 [k53 lr38:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ] != 0 goto _iffalse_0($2)
	MOVAR	r0x100D
	ORAR	r0x1012
	ORAR	r0x1013
	ORAR	r0x1014
	JBSET	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fsdiv.c:78: 	iTemp39 [k54 lr40:41 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:78: 	*(iTemp39 [k54 lr40:41 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := 0x7fc00000 {const-long-int literal}
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;	.line	78; "../libsdcc/fsdiv.c"	fl2.l = 0x7FC00000;
	CLRR	(___fsdiv_fl2_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	CLRR	(___fsdiv_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAI	0xc0
	MOVRA	(___fsdiv_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAI	0x7f
	MOVRA	(___fsdiv_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:79: 	iTemp41 [k57 lr42:43 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:79: 	iTemp43 [k60 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1006 r0x100A r0x100B r0x100C ] = @[iTemp41 [k57 lr42:43 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	79; "../libsdcc/fsdiv.c"	return (fl2.f);
	MOVAR	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x100D
	MOVAR	(___fsdiv_fl2_1_22 + 1)
	MOVRA	r0x1012
	MOVAR	(___fsdiv_fl2_1_22 + 2)
	MOVRA	r0x1013
	MOVAR	(___fsdiv_fl2_1_22 + 3)
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:79: 	ret iTemp43 [k60 lr43:44 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1006 r0x100A r0x100B r0x100C ]
	MOVAR	r0x100D
	MOVRA	STK02
	MOVAR	r0x1012
	MOVRA	STK01
	MOVAR	r0x1013
	MOVRA	STK00
	MOVAR	r0x1014
	GOTO	_00122_DS_
;;[ICODE] ../libsdcc/fsdiv.c:79:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fsdiv.c:83: 	iTemp44 [k61 lr46:47 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:83: 	iTemp46 [k64 lr47:48 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ] = @[iTemp44 [k61 lr46:47 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00106_DS_
;	.line	83; "../libsdcc/fsdiv.c"	if (!fl1.l)
	MOVAR	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x100D
	MOVAR	(___fsdiv_fl1_1_22 + 1)
	MOVRA	r0x1012
	MOVAR	(___fsdiv_fl1_1_22 + 2)
	MOVRA	r0x1013
	MOVAR	(___fsdiv_fl1_1_22 + 3)
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:83: 	if iTemp46 [k64 lr47:48 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ] != 0 goto _iffalse_1($4)
	MOVAR	r0x100D
	ORAR	r0x1012
	ORAR	r0x1013
	ORAR	r0x1014
	JBSET	STATUS,2
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/fsdiv.c:84: 	ret 0 {float literal}
;	.line	84; "../libsdcc/fsdiv.c"	return (0);
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00122_DS_
;;[ICODE] ../libsdcc/fsdiv.c:84:  _iffalse_1($4) :
;;[ICODE] ../libsdcc/fsdiv.c:87: 	iTemp48 [k67 lr51:52 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:87: 	iTemp50 [k70 lr52:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ] = @[iTemp48 [k67 lr51:52 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00108_DS_
;	.line	87; "../libsdcc/fsdiv.c"	mant1 = MANT (fl1.l);
	MOVAR	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x1015
	MOVRA	r0x100D
	MOVAR	(___fsdiv_fl1_1_22 + 1)
	MOVRA	r0x1016
	MOVRA	r0x1012
	MOVAR	(___fsdiv_fl1_1_22 + 2)
	MOVRA	r0x1017
	MOVRA	r0x1013
	MOVAR	(___fsdiv_fl1_1_22 + 3)
	MOVRA	r0x1018
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:87: 	iTemp51 [k71 lr53:54 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] = (unsigned-long-int register)iTemp50 [k70 lr52:53 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1006 r0x100A r0x100B r0x100C ]
;;127	MOVAR	r0x100D
;;128	MOVAR	r0x1012
;;112	MOVAR	r0x1013
;;135	MOVAR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:87: 	iTemp52 [k72 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp51 [k71 lr53:54 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] & 0x7fffff {unsigned-long-int literal}
	MOVAR	r0x1015
	MOVRA	r0x100D
	MOVAR	r0x1016
	MOVRA	r0x1012
	MOVAI	0x7f
	ANDAR	r0x1017
	MOVRA	r0x1013
	CLRR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:87: 	iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp52 [k72 lr54:55 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1013,7
;;[ICODE] ../libsdcc/fsdiv.c:88: 	iTemp55 [k76 lr57:58 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:88: 	iTemp57 [k79 lr58:59 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ] = @[iTemp55 [k76 lr57:58 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	88; "../libsdcc/fsdiv.c"	mant2 = MANT (fl2.l);
	MOVAR	(___fsdiv_fl2_1_22 + 0)
	MOVRA	r0x1015
	MOVAR	(___fsdiv_fl2_1_22 + 1)
	MOVRA	r0x101A
	MOVRA	r0x1016
	MOVAR	(___fsdiv_fl2_1_22 + 2)
	MOVRA	r0x101B
	MOVRA	r0x1017
	MOVAR	(___fsdiv_fl2_1_22 + 3)
	MOVRA	r0x101C
	MOVRA	r0x1018
;;[ICODE] ../libsdcc/fsdiv.c:88: 	iTemp58 [k80 lr59:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1011 r0x1012 r0x1013 r0x1014 ] = (unsigned-long-int register)iTemp57 [k79 lr58:59 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x100D r0x100E r0x100F r0x1010 ]
	MOVAR	r0x1015
	MOVRA	r0x1015
	MOVRA	r0x1019
;;117	MOVAR	r0x1016
;;118	MOVAR	r0x1017
;;119	MOVAR	r0x1018
;;[ICODE] ../libsdcc/fsdiv.c:88: 	iTemp59 [k81 lr60:61 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] = iTemp58 [k80 lr59:60 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1011 r0x1012 r0x1013 r0x1014 ] & 0x7fffff {unsigned-long-int literal}
;;120	MOVAR	r0x1019
	MOVAR	r0x101A
	MOVRA	r0x1016
	MOVAI	0x7f
	ANDAR	r0x101B
	MOVRA	r0x1017
	CLRR	r0x1018
;;[ICODE] ../libsdcc/fsdiv.c:88: 	iTemp54 [k74 lr61:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant2_1_22}[r0x100D r0x100E r0x100F r0x1010 ] = iTemp59 [k81 lr60:61 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x100D r0x100E r0x100F r0x1010 ] | 0x800000 {unsigned-long-int literal}
	BSET	r0x1017,7
;;[ICODE] ../libsdcc/fsdiv.c:91: 	iTemp61 [k83 lr63:64 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] < iTemp54 [k74 lr61:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant2_1_22}[r0x100D r0x100E r0x100F r0x1010 ]
	MOVAI	0x00
	ADDAI	0x80
	MOVRA	r0x101D
	MOVAI	0x00
	ADDAI	0x80
	RSUBAR	r0x101D
	JBSET	STATUS,2
	GOTO	_00152_DS_
	MOVAR	r0x1017
	RSUBAR	r0x1013
	JBSET	STATUS,2
	GOTO	_00152_DS_
	MOVAR	r0x1016
	RSUBAR	r0x1012
	JBSET	STATUS,2
	GOTO	_00152_DS_
	MOVAR	r0x1015
	RSUBAR	r0x100D
_00152_DS_
	JBCLR	STATUS,0
	GOTO	_00110_DS_
;;genSkipc:3246: created from rifx:0xbfe5d080
;;[ICODE] ../libsdcc/fsdiv.c:91: 	if iTemp61 [k83 lr63:64 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($6)
;;[ICODE] ../libsdcc/fsdiv.c:93: 	iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] << 0x1 {const-unsigned-char literal}
;	.line	93; "../libsdcc/fsdiv.c"	mant1 <<= 1;
	BCLR	STATUS,0
	RLR	r0x100D
	RLR	r0x1012
	RLR	r0x1013
	RLR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:94: 	iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] = iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] - 0x1 {const-unsigned-char literal}
;	.line	94; "../libsdcc/fsdiv.c"	exp--;
	MOVAI	0xff
	ADDRA	r0x100B
	JBSET	STATUS,0
	DECR	r0x100A
;;[ICODE] ../libsdcc/fsdiv.c:94:  _iffalse_2($6) :
;;[ICODE] ../libsdcc/fsdiv.c:98: 	iTemp65 [k87 lr70:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsdiv_mask_1_22}[r0x1011 r0x1012 r0x1013 r0x1014 ] := 0x1000000 {const-long-int literal}
_00110_DS_
;	.line	98; "../libsdcc/fsdiv.c"	mask = 0x1000000;
	CLRR	r0x1019
	CLRR	r0x101A
	CLRR	r0x101B
	MOVAI	0x01
	MOVRA	r0x101C
;;[ICODE] ../libsdcc/fsdiv.c:99: 	iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] := 0x0 {long-int literal}
;	.line	99; "../libsdcc/fsdiv.c"	result = 0;
	CLRR	r0x101D
	CLRR	r0x101E
	CLRR	r0x101F
	CLRR	r0x1020
;;[ICODE] ../libsdcc/fsdiv.c:100:  _whilecontinue_0($9) :
;;[ICODE] ../libsdcc/fsdiv.c:100: 	if iTemp65 [k87 lr70:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsdiv_mask_1_22}[r0x1011 r0x1012 r0x1013 r0x1014 ] == 0 goto _whilebreak_0($11)
_00113_DS_
;	.line	100; "../libsdcc/fsdiv.c"	while (mask)
	MOVAR	r0x1019
	ORAR	r0x101A
	ORAR	r0x101B
	ORAR	r0x101C
	JBCLR	STATUS,2
	GOTO	_00115_DS_
;;[ICODE] ../libsdcc/fsdiv.c:102: 	iTemp67 [k91 lr75:76 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] < iTemp54 [k74 lr61:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant2_1_22}[r0x100D r0x100E r0x100F r0x1010 ]
;	.line	102; "../libsdcc/fsdiv.c"	if (mant1 >= mant2)
	MOVAR	r0x1014
	ADDAI	0x80
	MOVRA	r0x1021
	MOVAR	r0x1018
	ADDAI	0x80
	RSUBAR	r0x1021
	JBSET	STATUS,2
	GOTO	_00153_DS_
	MOVAR	r0x1017
	RSUBAR	r0x1013
	JBSET	STATUS,2
	GOTO	_00153_DS_
	MOVAR	r0x1016
	RSUBAR	r0x1012
	JBSET	STATUS,2
	GOTO	_00153_DS_
	MOVAR	r0x1015
	RSUBAR	r0x100D
_00153_DS_
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3246: created from rifx:0xbfe5d080
;;[ICODE] ../libsdcc/fsdiv.c:102: 	if iTemp67 [k91 lr75:76 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_3($8)
;;[ICODE] ../libsdcc/fsdiv.c:104: 	iTemp68 [k92 lr77:78 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1019 r0x101A r0x101B r0x101C ] = (unsigned-long-int fixed)iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ]
;	.line	104; "../libsdcc/fsdiv.c"	result |= mask;
	MOVAR	r0x101D
	MOVRA	r0x1021
	MOVAR	r0x101E
	MOVRA	r0x1022
	MOVAR	r0x101F
	MOVRA	r0x1023
	MOVAR	r0x1020
	MOVRA	r0x1024
;;[ICODE] ../libsdcc/fsdiv.c:104: 	iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] = iTemp68 [k92 lr77:78 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1019 r0x101A r0x101B r0x101C ] | iTemp65 [k87 lr70:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsdiv_mask_1_22}[r0x1011 r0x1012 r0x1013 r0x1014 ]
	MOVAR	r0x1019
	ORAR	r0x1021
	MOVRA	r0x101D
	MOVAR	r0x101A
	ORAR	r0x1022
	MOVRA	r0x101E
	MOVAR	r0x101B
	ORAR	r0x1023
	MOVRA	r0x101F
	MOVAR	r0x101C
	ORAR	r0x1024
	MOVRA	r0x1020
;;[ICODE] ../libsdcc/fsdiv.c:105: 	iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] - iTemp54 [k74 lr61:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant2_1_22}[r0x100D r0x100E r0x100F r0x1010 ]
;	.line	105; "../libsdcc/fsdiv.c"	mant1 -= mant2;
	MOVAR	r0x1015
	RSUBRA	r0x100D
	MOVAR	r0x1016
	JBSET	STATUS,0
	JZAR	r0x1016
	RSUBRA	r0x1012
	MOVAR	r0x1017
	JBSET	STATUS,0
	JZAR	r0x1017
	RSUBRA	r0x1013
	MOVAR	r0x1018
	JBSET	STATUS,0
	JZAR	r0x1018
	RSUBRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:105:  _iffalse_3($8) :
;;[ICODE] ../libsdcc/fsdiv.c:107: 	iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp47 [k65 lr55:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_mant1_1_22}[r0x1006 r0x100A r0x100B r0x100C ] << 0x1 {const-unsigned-char literal}
_00112_DS_
;	.line	107; "../libsdcc/fsdiv.c"	mant1 <<= 1;
	BCLR	STATUS,0
	RLR	r0x100D
	RLR	r0x1012
	RLR	r0x1013
	RLR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:108: 	iTemp65 [k87 lr70:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsdiv_mask_1_22}[r0x1011 r0x1012 r0x1013 r0x1014 ] = iTemp65 [k87 lr70:87 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fsdiv_mask_1_22}[r0x1011 r0x1012 r0x1013 r0x1014 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=0, same=1, offr=0
;	.line	108; "../libsdcc/fsdiv.c"	mask >>= 1;
	BCLR	STATUS,0
	RRR	r0x101C
	RRR	r0x101B
	RRR	r0x101A
	RRR	r0x1019
;;[ICODE] ../libsdcc/fsdiv.c:108: 	 goto _whilecontinue_0($9)
	GOTO	_00113_DS_
;;[ICODE] ../libsdcc/fsdiv.c:108:  _whilebreak_0($11) :
;;[ICODE] ../libsdcc/fsdiv.c:112: 	iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] = iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] + 0x1 {long-int literal}
_00115_DS_
;	.line	112; "../libsdcc/fsdiv.c"	result += 1;
	INCR	r0x101D
	JBCLR	STATUS,2
	INCR	r0x101E
	JBCLR	STATUS,2
	INCR	r0x101F
	JBCLR	STATUS,2
	INCR	r0x1020
;;[ICODE] ../libsdcc/fsdiv.c:115: 	iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] = iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] + 0x1 {const-unsigned-char literal}
;	.line	115; "../libsdcc/fsdiv.c"	exp++;
	INCR	r0x100B
	JBCLR	STATUS,2
	INCR	r0x100A
;;[ICODE] ../libsdcc/fsdiv.c:116: 	iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] = iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] >> 0x1 {const-unsigned-char literal}
;;shiftRight_Left2ResultLit:5278: shCount=1, size=4, sign=1, same=1, offr=0
;	.line	116; "../libsdcc/fsdiv.c"	result >>= 1;
	BCLR	STATUS,0
	JBCLR	r0x1020,7
	BSET	STATUS,0
	RRR	r0x1020
	RRR	r0x101F
	RRR	r0x101E
	RRR	r0x101D
;;[ICODE] ../libsdcc/fsdiv.c:118: 	iTemp77 [k101 lr95:96 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] = (unsigned-long-int register)iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ]
;	.line	118; "../libsdcc/fsdiv.c"	result &= ~HIDDEN;
	MOVAR	r0x101D
	MOVRA	r0x101D
	MOVRA	r0x100D
	MOVAR	r0x101E
	MOVRA	r0x101E
	MOVRA	r0x1012
	MOVAR	r0x101F
	MOVRA	r0x1013
	MOVAR	r0x1020
	MOVRA	r0x1020
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:118: 	iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ] = iTemp77 [k101 lr95:96 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] & 0xff7fffff {unsigned-long-int literal}
;;107	MOVAR	r0x100D
;;111	MOVAR	r0x1012
	MOVAI	0x7f
	ANDAR	r0x1013
	MOVRA	r0x101F
;;129	MOVAR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:121: 	iTemp79 [k103 lr98:99 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] < 0x100 {const-int literal}
;;signed compare: left < lit(0x100=256), size=2, mask=ffff
;	.line	121; "../libsdcc/fsdiv.c"	if (exp >= 0x100)
	MOVAR	r0x100A
	ADDAI	0x80
	ADDAI	0x7f
	JBSET	STATUS,2
	GOTO	_00154_DS_
	MOVAI	0x00
	RSUBAR	r0x100B
_00154_DS_
	JBSET	STATUS,0
	GOTO	_00120_DS_
;;genSkipc:3246: created from rifx:0xbfe5d080
;;[ICODE] ../libsdcc/fsdiv.c:121: 	if iTemp79 [k103 lr98:99 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_5($16)
;;[ICODE] ../libsdcc/fsdiv.c:122: 	iTemp80 [k104 lr100:108 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:122: 	if iTemp24 [k35 lr35:118 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsdiv_sign_1_22}[r0x1002 ] == 0 goto iTempLbl0($20)
;	.line	122; "../libsdcc/fsdiv.c"	fl1.l = (sign ? SIGNBIT : 0) | 0x7F800000;
	MOVAI	0x00
	ORAR	r0x1009
	JBCLR	STATUS,2
	GOTO	_00124_DS_
;;[ICODE] ../libsdcc/fsdiv.c:122: 	iTemp82 [k107 lr102:107 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] := 0x80000000 {unsigned-long-int literal}
	CLRR	r0x100D
	CLRR	r0x1012
	CLRR	r0x1013
	MOVAI	0x80
	MOVRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:122: 	 goto iTempLbl1($21)
	GOTO	_00125_DS_
;;[ICODE] ../libsdcc/fsdiv.c:122:  iTempLbl0($20) :
;;[ICODE] ../libsdcc/fsdiv.c:122: 	iTemp82 [k107 lr102:107 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] := 0x0 {unsigned-long-int literal}
_00124_DS_
	CLRR	r0x100D
	CLRR	r0x1012
	CLRR	r0x1013
	CLRR	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:122:  iTempLbl1($21) :
;;[ICODE] ../libsdcc/fsdiv.c:122: 	iTemp83 [k108 lr107:108 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] = iTemp82 [k107 lr102:107 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ] | 0x7f800000 {unsigned-long-int literal}
_00125_DS_
	BSET	r0x1013,7
	MOVAI	0x7f
	ORRA	r0x1014
;;[ICODE] ../libsdcc/fsdiv.c:122: 	*(iTemp80 [k104 lr100:108 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := iTemp83 [k108 lr107:108 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1006 r0x100A r0x100B r0x100C ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fsdiv_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x1012
	MOVRA	(___fsdiv_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1013
	MOVRA	(___fsdiv_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1014
	MOVRA	(___fsdiv_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:122: 	 goto _ifend_5($17)
	GOTO	_00121_DS_
;;[ICODE] ../libsdcc/fsdiv.c:122:  _iffalse_5($16) :
;;[ICODE] ../libsdcc/fsdiv.c:123: 	iTemp84 [k109 lr111:112 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ] < 0x0 {int literal}
;;signed compare: left < lit(0x0=0), size=2, mask=ffff
_00120_DS_
;	.line	123; "../libsdcc/fsdiv.c"	else if (exp < 0)
	BSET	STATUS,0
	JBSET	r0x100A,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00117_DS_
;;genSkipc:3246: created from rifx:0xbfe5d080
;;[ICODE] ../libsdcc/fsdiv.c:123: 	if iTemp84 [k109 lr111:112 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_4($13)
;;[ICODE] ../libsdcc/fsdiv.c:124: 	iTemp85 [k110 lr113:114 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:124: 	*(iTemp85 [k110 lr113:114 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := 0x0 {volatile-long-int literal}
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;	.line	124; "../libsdcc/fsdiv.c"	fl1.l = 0;
	CLRR	(___fsdiv_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	CLRR	(___fsdiv_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	CLRR	(___fsdiv_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	CLRR	(___fsdiv_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:124: 	 goto _ifend_5($17)
	GOTO	_00121_DS_
;;[ICODE] ../libsdcc/fsdiv.c:124:  _iffalse_4($13) :
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp87 [k113 lr117:129 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:126: 	if iTemp24 [k35 lr35:118 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{char fixed}{ sir@ ___fsdiv_sign_1_22}[r0x1002 ] == 0 goto iTempLbl2($22)
_00117_DS_
;	.line	126; "../libsdcc/fsdiv.c"	fl1.l = PACK (sign ? SIGNBIT : 0 , exp, result);
	MOVAI	0x00
	ORAR	r0x1009
	JBCLR	STATUS,2
	GOTO	_00126_DS_
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp89 [k116 lr119:126 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1002 r0x1006 r0x100A r0x100B ] := 0x80000000 {unsigned-long-int literal}
	CLRR	r0x1009
	CLRR	r0x100D
	CLRR	r0x1012
	MOVAI	0x80
	MOVRA	r0x1013
;;[ICODE] ../libsdcc/fsdiv.c:126: 	 goto iTempLbl3($23)
	GOTO	_00127_DS_
;;[ICODE] ../libsdcc/fsdiv.c:126:  iTempLbl2($22) :
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp89 [k116 lr119:126 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1002 r0x1006 r0x100A r0x100B ] := 0x0 {unsigned-long-int literal}
_00126_DS_
	CLRR	r0x1009
	CLRR	r0x100D
	CLRR	r0x1012
	CLRR	r0x1013
;;[ICODE] ../libsdcc/fsdiv.c:126:  iTempLbl3($23) :
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp90 [k117 lr124:125 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ] = (unsigned-long-int fixed)iTemp6 [k14 lr14:124 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___fsdiv_exp_1_22}[r0x1000 r0x1001 ]
_00127_DS_
	MOVAR	r0x100B
	MOVRA	r0x1014
	MOVAR	r0x100A
	MOVRA	r0x1015
	MOVAI	0x00
	JBCLR	r0x1015,7
	MOVAI	0xff
	MOVRA	r0x1017
	MOVRA	r0x1016
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp91 [k118 lr125:126 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1010 r0x1011 ] = iTemp90 [k117 lr124:125 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x100C r0x100D r0x100E r0x100F ] << 0x17 {const-unsigned-char literal}
	RRAR	r0x1015
	RRAR	r0x1014
	MOVRA	r0x1019
	CLRR	r0x1018
	RRR	r0x1018
	CLRR	r0x100A
	CLRR	r0x100B
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp92 [k119 lr126:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1006 r0x100A r0x100B ] = iTemp89 [k116 lr119:126 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int register}[r0x1002 r0x1006 r0x100A r0x100B ] | iTemp91 [k118 lr125:126 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1010 r0x1011 ]
	MOVAI	0x00
	ORRA	r0x1009
	MOVAI	0x00
	ORRA	r0x100D
	MOVAR	r0x1018
	ORRA	r0x1012
	MOVAR	r0x1019
	ORRA	r0x1013
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp93 [k120 lr127:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ] = (unsigned-long-int fixed)iTemp66 [k89 lr71:127 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___fsdiv_result_1_22}[r0x1015 r0x1016 r0x1017 r0x1018 ]
;;100	MOVAR	r0x101D
;;102	MOVAR	r0x101E
;;114	MOVAR	r0x101F
;;116	MOVAR	r0x1020
;;[ICODE] ../libsdcc/fsdiv.c:126: 	iTemp94 [k121 lr128:129 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1015 r0x1016 r0x1017 r0x1018 ] = iTemp92 [k119 lr126:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1002 r0x1006 r0x100A r0x100B ] | iTemp93 [k120 lr127:128 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x100C r0x100D ]
;;99	MOVAR	r0x100B
	MOVAR	r0x101D
	MOVRA	r0x100B
	ORAR	r0x1009
	MOVRA	r0x101D
;;101	MOVAR	r0x100A
	MOVAR	r0x101E
	MOVRA	r0x100A
	ORAR	r0x100D
	MOVRA	r0x101E
;;113	MOVAR	r0x1014
	MOVAR	r0x101F
	MOVRA	r0x1014
	ORAR	r0x1012
	MOVRA	r0x101F
;;115	MOVAR	r0x1015
	MOVAR	r0x1020
	MOVRA	r0x1015
	ORAR	r0x1013
	MOVRA	r0x1020
;;[ICODE] ../libsdcc/fsdiv.c:126: 	*(iTemp87 [k113 lr117:129 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat]) := iTemp94 [k121 lr128:129 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1015 r0x1016 r0x1017 r0x1018 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
	MOVAR	r0x101D
	MOVRA	(___fsdiv_fl1_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x101E
	MOVRA	(___fsdiv_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x101F
	MOVRA	(___fsdiv_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1020
	MOVRA	(___fsdiv_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsdiv.c:126:  _ifend_5($17) :
;;[ICODE] ../libsdcc/fsdiv.c:127: 	iTemp95 [k122 lr131:132 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsdiv_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsdiv.c:127: 	iTemp97 [k125 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1006 ] = @[iTemp95 [k122 lr131:132 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00121_DS_
;	.line	127; "../libsdcc/fsdiv.c"	return (fl1.f);
	MOVAR	(___fsdiv_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsdiv_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsdiv_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsdiv_fl1_1_22 + 3)
	MOVRA	r0x100D
;;[ICODE] ../libsdcc/fsdiv.c:127: 	ret iTemp97 [k125 lr132:133 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{volatile-float fixed}[r0x1000 r0x1001 r0x1002 r0x1006 ]
	MOVAR	r0x100B
	MOVRA	STK02
	MOVAR	r0x100A
	MOVRA	STK01
	MOVAR	r0x1009
	MOVRA	STK00
	MOVAR	r0x100D
;;[ICODE] ../libsdcc/fsdiv.c:127:  _return($18) :
;;[ICODE] ../libsdcc/fsdiv.c:127: 	eproc ___fsdiv [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( float fixed, float fixed) fixed}
_00122_DS_
	RETURN	
; exit point of ___fsdiv


;	code size estimation:
;	  519+    0 =   519 instructions ( 1038 byte)

	end
