;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:34:25 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/sint2fs.c"
	list	p=31p11
	radix dec
	include "mc31p11.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	___uchar2fs
	extern	___schar2fs
	extern	___uint2fs
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
	global	___sint2fs

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_sint2fs_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1002	res	1
r0x1003	res	1
r0x1005	res	1
r0x1004	res	1
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
code_sint2fs	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___sint2fs	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___slong2fs
;   ___slong2fs
;9 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;   STK02
;   STK01
;; Starting pCode block
;;[ICODE] ../libsdcc/sint2fs.c:33:  _entry($2) :
;;[ICODE] ../libsdcc/sint2fs.c:33: 	proc ___sint2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( int fixed) fixed}
___sint2fs	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/sint2fs.c:33: iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___sint2fs_si_1_21}[r0x1000 r0x1001 ] = recv ___sint2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( int fixed) fixed}
	MOVRA	r0x1003
;	.line	33; "../libsdcc/sint2fs.c"	float __sint2fs (signed int si) _FS_REENTRANT
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1002
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/sint2fs.c:35: 	iTemp1 [k5 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ] = (long-int fixed)iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{int fixed}{ sir@ ___sint2fs_si_1_21}[r0x1000 r0x1001 ]
;;99	MOVAR	r0x1001
;;100	MOVAR	r0x1000
;	.line	35; "../libsdcc/sint2fs.c"	return __slong2fs(si);
	MOVAI	0x00
	JBCLR	r0x1003,7
	MOVAI	0xff
	MOVRA	r0x1004
	MOVRA	r0x1005
;;[ICODE] ../libsdcc/sint2fs.c:35: 	send iTemp1 [k5 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{long-int fixed}[r0x1002 r0x1003 r0x1004 r0x1005 ]{argreg = 1}
;;[ICODE] ../libsdcc/sint2fs.c:35: 	iTemp2 [k7 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___slong2fs [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( long-int fixed) fixed}
	MOVAR	r0x1002
	MOVRA	STK02
	MOVAR	r0x1003
	MOVRA	STK01
	MOVAR	r0x1005
	MOVRA	STK00
	MOVAR	r0x1004
	CALL	___slong2fs
	MOVRA	r0x1003
	MOVAR	STK00
	MOVRA	r0x1002
	MOVAR	STK01
	MOVRA	r0x1000
	MOVAR	STK02
	MOVRA	r0x1001
;;[ICODE] ../libsdcc/sint2fs.c:35: 	ret iTemp2 [k7 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1001
	MOVRA	STK02
	MOVAR	r0x1000
	MOVRA	STK01
	MOVAR	r0x1002
	MOVRA	STK00
	MOVAR	r0x1003
;;[ICODE] ../libsdcc/sint2fs.c:35:  _return($1) :
;;[ICODE] ../libsdcc/sint2fs.c:35: 	eproc ___sint2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( int fixed) fixed}
	RETURN	
; exit point of ___sint2fs


;	code size estimation:
;	   33+    0 =    33 instructions (   66 byte)

	end
