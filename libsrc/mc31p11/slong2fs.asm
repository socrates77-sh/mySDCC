;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:34:25 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/slong2fs.c"
	list	p=31p11
	radix dec
	include "mc31p11.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	___uchar2fs
	extern	___schar2fs
	extern	___uint2fs
	extern	___sint2fs
	extern	___ulong2fs
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
	global	___slong2fs

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_slong2fs_0	udata
r0x1003	res	1
r0x1002	res	1
r0x1001	res	1
r0x1000	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
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
code_slong2fs	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___slong2fs	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___ulong2fs
;   ___ulong2fs
;   ___ulong2fs
;   ___ulong2fs
;11 compiler assigned registers:
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
;; Starting pCode block
;;[ICODE] ../libsdcc/slong2fs.c:33:  _entry($5) :
;;[ICODE] ../libsdcc/slong2fs.c:33: 	proc ___slong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( long-int fixed) fixed}
___slong2fs	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/slong2fs.c:33: iTemp0 [k2 lr3:12 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___slong2fs_sl_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___slong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( long-int fixed) fixed}
;	.line	33; "../libsdcc/slong2fs.c"	float __slong2fs (signed long sl) _FS_REENTRANT
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/slong2fs.c:35: 	iTemp1 [k4 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp0 [k2 lr3:12 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___slong2fs_sl_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] < 0x0 {long-int literal}
;;signed compare: left < lit(0x0=0), size=4, mask=ffffffff
;	.line	35; "../libsdcc/slong2fs.c"	if (sl<0) 
	BSET	STATUS,0
	JBSET	r0x1000,7
	BCLR	STATUS,0
	JBSET	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3246: created from rifx:0xbfedf700
;;[ICODE] ../libsdcc/slong2fs.c:35: 	if iTemp1 [k4 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _iffalse_0($2)
;;[ICODE] ../libsdcc/slong2fs.c:36: 	iTemp2 [k6 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = - iTemp0 [k2 lr3:12 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___slong2fs_sl_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;	.line	36; "../libsdcc/slong2fs.c"	return -__ulong2fs(-sl);
	COMAR	r0x1003
	MOVRA	r0x1004
	COMAR	r0x1002
	MOVRA	r0x1005
	COMAR	r0x1001
	MOVRA	r0x1006
	COMAR	r0x1000
	MOVRA	r0x1007
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1005
	JBCLR	STATUS,2
	INCR	r0x1006
	JBCLR	STATUS,2
	INCR	r0x1007
;;[ICODE] ../libsdcc/slong2fs.c:36: 	send iTemp2 [k6 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/slong2fs.c:36: 	iTemp3 [k8 lr8:9 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = call ___ulong2fs [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
	MOVAR	r0x1004
	MOVRA	STK02
	MOVAR	r0x1005
	MOVRA	STK01
	MOVAR	r0x1006
	MOVRA	STK00
	MOVAR	r0x1007
	CALL	___ulong2fs
	MOVRA	r0x1007
	MOVAR	STK00
	MOVRA	r0x1006
	MOVAR	STK01
	MOVRA	r0x1005
	MOVAR	STK02
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/slong2fs.c:36: 	iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = - iTemp3 [k8 lr8:9 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x1007
	XORAI	0x80
	MOVRA	r0x1007
	MOVAR	r0x1006
	MOVRA	r0x1006
	MOVAR	r0x1005
	MOVRA	r0x1005
	MOVAR	r0x1004
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/slong2fs.c:36: 	ret iTemp4 [k9 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x1004
	MOVRA	STK02
	MOVAR	r0x1005
	MOVRA	STK01
	MOVAR	r0x1006
	MOVRA	STK00
	MOVAR	r0x1007
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/slong2fs.c:36:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/slong2fs.c:38: 	send iTemp0 [k2 lr3:12 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{long-int fixed}{ sir@ ___slong2fs_sl_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../libsdcc/slong2fs.c:38: 	iTemp5 [k10 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___ulong2fs [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
_00106_DS_
;	.line	38; "../libsdcc/slong2fs.c"	return __ulong2fs(sl);
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
	CALL	___ulong2fs
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/slong2fs.c:38: 	ret iTemp5 [k10 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/slong2fs.c:38:  _return($4) :
;;[ICODE] ../libsdcc/slong2fs.c:38: 	eproc ___slong2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( long-int fixed) fixed}
_00108_DS_
	RETURN	
; exit point of ___slong2fs


;	code size estimation:
;	   82+    0 =    82 instructions (  164 byte)

	end
