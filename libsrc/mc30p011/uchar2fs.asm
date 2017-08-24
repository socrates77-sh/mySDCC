;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:30:21 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/uchar2fs.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
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
	global	___uchar2fs

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_uchar2fs_0	udata
r0x1000	res	1
r0x1001	res	1
r0x1002	res	1
r0x1003	res	1
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
code_uchar2fs	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___uchar2fs	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___ulong2fs
;   ___ulong2fs
;8 compiler assigned registers:
;   r0x1000
;   r0x1001
;   r0x1002
;   r0x1003
;   r0x1004
;   STK02
;   STK01
;   STK00
;; Starting pCode block
;;[ICODE] ../libsdcc/uchar2fs.c:33:  _entry($2) :
;;[ICODE] ../libsdcc/uchar2fs.c:33: 	proc ___uchar2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-char fixed) fixed}
___uchar2fs	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/uchar2fs.c:33: iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ ___uchar2fs_uc_1_21}[r0x1000 ] = recv ___uchar2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-char fixed) fixed}
	MOVRA	r0x1001
;	.line	33; "../libsdcc/uchar2fs.c"	float __uchar2fs (unsigned char uc) _FS_REENTRANT
	MOVRA	r0x1000
;;[ICODE] ../libsdcc/uchar2fs.c:35: 	iTemp1 [k5 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ] = (unsigned-long-int fixed)iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ ___uchar2fs_uc_1_21}[r0x1000 ]
;;99	MOVAR	r0x1000
;	.line	35; "../libsdcc/uchar2fs.c"	return __ulong2fs(uc);
	CLRR	r0x1002
	CLRR	r0x1003
;;1	CLRR	r0x1004
;;[ICODE] ../libsdcc/uchar2fs.c:35: 	send iTemp1 [k5 lr4:5 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1001 r0x1002 r0x1003 r0x1004 ]{argreg = 1}
;;[ICODE] ../libsdcc/uchar2fs.c:35: 	iTemp2 [k7 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___ulong2fs [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-long-int fixed) fixed}
	MOVAR	r0x1001
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	CALL	___ulong2fs
	MOVRA	r0x1003
	MOVAR	STK00
	MOVRA	r0x1002
	MOVAR	STK01
	MOVRA	r0x1001
	MOVAR	STK02
	MOVRA	r0x1000
;;[ICODE] ../libsdcc/uchar2fs.c:35: 	ret iTemp2 [k7 lr6:7 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1000
	MOVRA	STK02
	MOVAR	r0x1001
	MOVRA	STK01
	MOVAR	r0x1002
	MOVRA	STK00
	MOVAR	r0x1003
;;[ICODE] ../libsdcc/uchar2fs.c:35:  _return($1) :
;;[ICODE] ../libsdcc/uchar2fs.c:35: 	eproc ___uchar2fs [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{float function ( unsigned-char fixed) fixed}
	RETURN	
; exit point of ___uchar2fs


;	code size estimation:
;	   27+    0 =    27 instructions (   54 byte)

	end
