;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:34:24 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc/fs2slong.c"
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
	extern	___slong2fs
	extern	___fs2uchar
	extern	___fs2schar
	extern	___fs2uint
	extern	___fs2sint
	extern	___fs2ulong
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
	global	___fs2slong

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fs2slong_0	udata
r0x1003	res	1
r0x1002	res	1
r0x1001	res	1
r0x1000	res	1
r0x1004	res	1
r0x1007	res	1
r0x1006	res	1
r0x1005	res	1
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
code_fs2slong	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fs2slong	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___fslt
;   ___fs2ulong
;   ___fs2ulong
;   ___fslt
;   ___fs2ulong
;   ___fs2ulong
;15 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   STK01
;   r0x1002
;   STK02
;   r0x1003
;   STK06
;   STK05
;   STK04
;   STK03
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;; Starting pCode block
;;[ICODE] ../libsdcc/fs2slong.c:33:  _entry($7) :
;;[ICODE] ../libsdcc/fs2slong.c:33: 	proc ___fs2slong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( float fixed) fixed}
___fs2slong	;Function start
; 2 exit points
;;[ICODE] ../libsdcc/fs2slong.c:33: iTemp0 [k2 lr3:17 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2slong_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fs2slong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( float fixed) fixed}
;	.line	33; "../libsdcc/fs2slong.c"	signed long __fs2slong (float f) _FS_REENTRANT
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/fs2slong.c:36: 	if iTemp0 [k2 lr3:17 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2slong_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] != 0 goto _iffalse_0($2)
;	.line	36; "../libsdcc/fs2slong.c"	if (!f)
	MOVAR	r0x1003
	ORAR	r0x1002
	ORAR	r0x1001
	ORAR	r0x1000
	JBSET	STATUS,2
	GOTO	_00106_DS_
;;[ICODE] ../libsdcc/fs2slong.c:37: 	ret 0x0 {long-int literal}
;	.line	37; "../libsdcc/fs2slong.c"	return 0;
	MOVAI	0x00
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAI	0x00
	MOVRA	STK00
	MOVAI	0x00
	GOTO	_00110_DS_
;;[ICODE] ../libsdcc/fs2slong.c:37:  _iffalse_0($2) :
;;[ICODE] ../libsdcc/fs2slong.c:39: 	send iTemp0 [k2 lr3:17 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2slong_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../libsdcc/fs2slong.c:39: 	send 0 {float literal}{argreg = 1}
;;[ICODE] ../libsdcc/fs2slong.c:39: 	iTemp1 [k4 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1004 ] = call ___fslt [k11 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char function ( float fixed, float fixed) fixed}
_00106_DS_
;	.line	39; "../libsdcc/fs2slong.c"	if (f<0) {
	MOVAI	0x00
	MOVRA	STK06
	MOVAI	0x00
	MOVRA	STK05
	MOVAI	0x00
	MOVRA	STK04
	MOVAI	0x00
	MOVRA	STK03
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
	CALL	___fslt
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/fs2slong.c:39: 	if iTemp1 [k4 lr9:10 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed}[r0x1004 ] == 0 goto _iffalse_1($4)
	MOVAI	0x00
	ORAR	r0x1004
	JBCLR	STATUS,2
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc/fs2slong.c:40: 	iTemp2 [k6 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = - iTemp0 [k2 lr3:17 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2slong_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;	.line	40; "../libsdcc/fs2slong.c"	return -__fs2ulong(-f);
	MOVAR	r0x1000
	XORAI	0x80
	MOVRA	r0x1005
;;104	MOVAR	r0x1001
;;102	MOVAR	r0x1002
;;100	MOVAR	r0x1003
;;[ICODE] ../libsdcc/fs2slong.c:40: 	send iTemp2 [k6 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{float fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]{argreg = 1}
;;[ICODE] ../libsdcc/fs2slong.c:40: 	iTemp3 [k8 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = call ___fs2ulong [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
;;99	MOVAR	r0x1004
	MOVAR	r0x1003
	MOVRA	r0x1004
	MOVRA	STK02
;;101	MOVAR	r0x1007
	MOVAR	r0x1002
	MOVRA	r0x1007
	MOVRA	STK01
;;103	MOVAR	r0x1006
	MOVAR	r0x1001
	MOVRA	r0x1006
	MOVRA	STK00
	MOVAR	r0x1005
	CALL	___fs2ulong
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1006
	MOVAR	STK01
	MOVRA	r0x1007
	MOVAR	STK02
	MOVRA	r0x1004
;;[ICODE] ../libsdcc/fs2slong.c:40: 	iTemp4 [k9 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ] = - iTemp3 [k8 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	COMR	r0x1004
	COMR	r0x1007
	COMR	r0x1006
	COMR	r0x1005
	INCR	r0x1004
	JBCLR	STATUS,2
	INCR	r0x1007
	JBCLR	STATUS,2
	INCR	r0x1006
	JBCLR	STATUS,2
	INCR	r0x1005
;;[ICODE] ../libsdcc/fs2slong.c:40: 	ret iTemp4 [k9 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1004 r0x1005 r0x1006 r0x1007 ]
	MOVAR	r0x1004
	MOVRA	STK02
	MOVAR	r0x1007
	MOVRA	STK01
	MOVAR	r0x1006
	MOVRA	STK00
	MOVAR	r0x1005
	GOTO	_00110_DS_
;;[ICODE] ../libsdcc/fs2slong.c:40:  _iffalse_1($4) :
;;[ICODE] ../libsdcc/fs2slong.c:42: 	send iTemp0 [k2 lr3:17 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{float fixed}{ sir@ ___fs2slong_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../libsdcc/fs2slong.c:42: 	iTemp5 [k10 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___fs2ulong [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
_00108_DS_
;	.line	42; "../libsdcc/fs2slong.c"	return __fs2ulong(f);
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
	CALL	___fs2ulong
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../libsdcc/fs2slong.c:42: 	ret iTemp5 [k10 lr18:19 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-long-int fixed}[r0x1000 r0x1001 r0x1002 r0x1003 ]
	MOVAR	r0x1003
	MOVRA	STK02
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1001
	MOVRA	STK00
	MOVAR	r0x1000
;;[ICODE] ../libsdcc/fs2slong.c:42:  _return($6) :
;;[ICODE] ../libsdcc/fs2slong.c:42: 	eproc ___fs2slong [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{long-int function ( float fixed) fixed}
_00110_DS_
	RETURN	
; exit point of ___fs2slong


;	code size estimation:
;	  105+    0 =   105 instructions (  210 byte)

	end
