;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:30:20 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fsgt.c"
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
	extern	___fsdiv
	extern	___fslt
	extern	___fseq
	extern	___fsneq

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
	global	___fsgt

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fsgt_0	udata
r0x100B	res	1
r0x100A	res	1
r0x1009	res	1
r0x1008	res	1
r0x100F	res	1
r0x100E	res	1
r0x100D	res	1
r0x100C	res	1
r0x1010	res	1
___fsgt_fl1_1_22	res	4
___fsgt_fl2_1_22	res	4
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
code_fsgt	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fsgt	;Function start
; 2 exit points
;has an exit
;16 compiler assigned registers:
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
;; Starting pCode block
;;[ICODE] ../libsdcc/fsgt.c:55:  _entry($9) :
;;[ICODE] ../libsdcc/fsgt.c:55: 	proc ___fsgt [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( float fixed, float fixed) fixed}
___fsgt	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fsgt.c:55: iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsgt_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fsgt [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( float fixed, float fixed) fixed}
;	.line	55; "../libsdcc/fsgt.c"	char __fsgt (float a1, float a2) _FS_REENTRANT
	MOVRA	r0x1008
	MOVAR	STK00
	MOVRA	r0x1009
	MOVAR	STK01
	MOVRA	r0x100A
	MOVAR	STK02
	MOVRA	(___fsgt_fl1_1_22 + 0)
	MOVRA	r0x100B
;;[ICODE] ../libsdcc/fsgt.c:55: iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsgt_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ] = recv ___fsgt [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( float fixed, float fixed) fixed}
	MOVAR	STK03
	MOVRA	r0x100C
	MOVAR	STK04
	MOVRA	r0x100D
	MOVAR	STK05
	MOVRA	r0x100E
	MOVAR	STK06
	MOVRA	r0x100F
;;[ICODE] ../libsdcc/fsgt.c:59: 	iTemp2 [k7 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsgt_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:59: 	*(iTemp2 [k7 lr5:6 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp0 [k2 lr3:6 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsgt_a1_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;;99	MOVAR	r0x100B
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
;	.line	59; "../libsdcc/fsgt.c"	fl1.f = a1;
	MOVAR	r0x100A
	MOVRA	(___fsgt_fl1_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x1009
	MOVRA	(___fsgt_fl1_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x1008
	MOVRA	(___fsgt_fl1_1_22 + 3)
;;[ICODE] ../libsdcc/fsgt.c:60: 	iTemp4 [k11 lr7:8 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat] = &[___fsgt_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:60: 	*(iTemp4 [k11 lr7:8 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-float near* fixed}[remat]) := iTemp1 [k4 lr4:8 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fsgt_a2_1_21}[r0x1004 r0x1005 r0x1006 r0x1007 ]
;;gen.c:6444: size=3/4, offset=0, AOP_TYPE(res)=8
;	.line	60; "../libsdcc/fsgt.c"	fl2.f = a2;
	MOVAR	r0x100F
	MOVRA	(___fsgt_fl2_1_22 + 0)
;;gen.c:6444: size=2/4, offset=1, AOP_TYPE(res)=8
	MOVAR	r0x100E
	MOVRA	(___fsgt_fl2_1_22 + 1)
;;gen.c:6444: size=1/4, offset=2, AOP_TYPE(res)=8
	MOVAR	r0x100D
	MOVRA	(___fsgt_fl2_1_22 + 2)
;;gen.c:6444: size=0/4, offset=3, AOP_TYPE(res)=8
	MOVAR	r0x100C
	MOVRA	(___fsgt_fl2_1_22 + 3)
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp6 [k14 lr9:10 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp6 [k14 lr9:10 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	62; "../libsdcc/fsgt.c"	if (fl1.l<0 && fl2.l<0) {
	MOVAR	(___fsgt_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsgt_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsgt_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsgt_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp9 [k18 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp8 [k17 lr10:11 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] < 0x0 {volatile-long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
	BSET	STATUS,0
	JBSET	r0x1008,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00108_DS_
;;genSkipc:3246: created from rifx:0xbff16ea0
;;[ICODE] ../libsdcc/fsgt.c:62: 	if iTemp9 [k18 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($4)
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp10 [k19 lr13:14 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp12 [k22 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp10 [k19 lr13:14 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsgt_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsgt_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsgt_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsgt_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsgt.c:62: 	iTemp13 [k23 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp12 [k22 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] < 0x0 {volatile-long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
	BSET	STATUS,0
	JBSET	r0x1008,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00108_DS_
;;genSkipc:3246: created from rifx:0xbff16ea0
;;[ICODE] ../libsdcc/fsgt.c:62: 	if iTemp13 [k23 lr15:16 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_1($4)
;;[ICODE] ../libsdcc/fsgt.c:63: 	iTemp14 [k24 lr17:18 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:63: 	iTemp16 [k27 lr18:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp14 [k24 lr17:18 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	63; "../libsdcc/fsgt.c"	if (fl2.l > fl1.l)
	MOVAR	(___fsgt_fl2_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsgt_fl2_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsgt_fl2_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsgt_fl2_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsgt.c:63: 	iTemp17 [k28 lr19:20 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:63: 	iTemp19 [k31 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = @[iTemp17 [k28 lr19:20 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsgt_fl1_1_22 + 0)
	MOVRA	r0x100F
	MOVAR	(___fsgt_fl1_1_22 + 1)
	MOVRA	r0x100E
	MOVAR	(___fsgt_fl1_1_22 + 2)
	MOVRA	r0x100D
	MOVAR	(___fsgt_fl1_1_22 + 3)
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fsgt.c:63: 	iTemp20 [k32 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp16 [k27 lr18:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] > iTemp19 [k31 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x100C
	ADDAI	0x80
	MOVRA	r0x1010
	MOVAR	r0x1008
	ADDAI	0x80
	RSUBAR	r0x1010
	JBSET	STATUS,2
	GOTO	_00122_DS_
	MOVAR	r0x1009
	RSUBAR	r0x100D
	JBSET	STATUS,2
	GOTO	_00122_DS_
	MOVAR	r0x100A
	RSUBAR	r0x100E
	JBSET	STATUS,2
	GOTO	_00122_DS_
	MOVAR	r0x100B
	RSUBAR	r0x100F
_00122_DS_
	JBCLR	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3246: created from rifx:0xbff16ea0
;;[ICODE] ../libsdcc/fsgt.c:63: 	if iTemp20 [k32 lr21:22 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../libsdcc/fsgt.c:64: 	ret 0x1 {const-unsigned-char literal}
;	.line	64; "../libsdcc/fsgt.c"	return (1);
	MOVAI	0x01
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/fsgt.c:64:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fsgt.c:65: 	ret 0x0 {const-unsigned-char literal}
_00106_DS_
;	.line	65; "../libsdcc/fsgt.c"	return (0);
	MOVAI	0x00
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/fsgt.c:65:  _iffalse_1($4) :
;;[ICODE] ../libsdcc/fsgt.c:68: 	iTemp21 [k33 lr27:28 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl1_1_22 [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:68: 	iTemp23 [k36 lr28:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = @[iTemp21 [k33 lr27:28 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
_00108_DS_
;	.line	68; "../libsdcc/fsgt.c"	if (fl1.l > fl2.l)
	MOVAR	(___fsgt_fl1_1_22 + 0)
	MOVRA	r0x100B
	MOVAR	(___fsgt_fl1_1_22 + 1)
	MOVRA	r0x100A
	MOVAR	(___fsgt_fl1_1_22 + 2)
	MOVRA	r0x1009
	MOVAR	(___fsgt_fl1_1_22 + 3)
	MOVRA	r0x1008
;;[ICODE] ../libsdcc/fsgt.c:68: 	iTemp24 [k37 lr29:30 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] = &[___fsgt_fl2_1_22 [k10 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct float_long fixed}]
;;[ICODE] ../libsdcc/fsgt.c:68: 	iTemp26 [k40 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = @[iTemp24 [k37 lr29:30 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-long-int near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	MOVAR	(___fsgt_fl2_1_22 + 0)
	MOVRA	r0x100F
	MOVAR	(___fsgt_fl2_1_22 + 1)
	MOVRA	r0x100E
	MOVAR	(___fsgt_fl2_1_22 + 2)
	MOVRA	r0x100D
	MOVAR	(___fsgt_fl2_1_22 + 3)
	MOVRA	r0x100C
;;[ICODE] ../libsdcc/fsgt.c:68: 	iTemp27 [k41 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp23 [k36 lr28:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] > iTemp26 [k40 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x100C
	ADDAI	0x80
	MOVRA	r0x1010
	MOVAR	r0x1008
	ADDAI	0x80
	RSUBAR	r0x1010
	JBSET	STATUS,2
	GOTO	_00123_DS_
	MOVAR	r0x1009
	RSUBAR	r0x100D
	JBSET	STATUS,2
	GOTO	_00123_DS_
	MOVAR	r0x100A
	RSUBAR	r0x100E
	JBSET	STATUS,2
	GOTO	_00123_DS_
	MOVAR	r0x100B
	RSUBAR	r0x100F
_00123_DS_
	JBCLR	STATUS,0
	GOTO	_00111_DS_
;;genSkipc:3246: created from rifx:0xbff16ea0
;;[ICODE] ../libsdcc/fsgt.c:68: 	if iTemp27 [k41 lr31:32 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_2($7)
;;[ICODE] ../libsdcc/fsgt.c:69: 	ret 0x1 {const-unsigned-char literal}
;	.line	69; "../libsdcc/fsgt.c"	return (1);
	MOVAI	0x01
	GOTO	_00112_DS_
;;[ICODE] ../libsdcc/fsgt.c:69:  _iffalse_2($7) :
;;[ICODE] ../libsdcc/fsgt.c:70: 	ret 0x0 {const-unsigned-char literal}
_00111_DS_
;	.line	70; "../libsdcc/fsgt.c"	return (0);
	MOVAI	0x00
;;[ICODE] ../libsdcc/fsgt.c:70:  _return($8) :
;;[ICODE] ../libsdcc/fsgt.c:70: 	eproc ___fsgt [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( float fixed, float fixed) fixed}
_00112_DS_
	RETURN	
; exit point of ___fsgt


;	code size estimation:
;	  136+    0 =   136 instructions (  272 byte)

	end
