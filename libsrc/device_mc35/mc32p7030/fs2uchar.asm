;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Wed Dec 20 12:04:42 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../../libsdcc_mc35/fs2uchar.c"
	list	p=7030
	radix dec
	include "7030.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	___uchar2fs
	extern	___schar2fs
	extern	___uint2fs
	extern	___sint2fs
	extern	___ulong2fs
	extern	___slong2fs
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
	global	___fs2uchar

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_fs2uchar_0	udata
r0x1003	res	1
r0x1002	res	1
r0x1001	res	1
r0x1000	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

;@Allocation info for local variables in function '__fs2uchar'
;@__fs2uchar __uchar2fs                Allocated to registers ;size:2
;@__fs2uchar __schar2fs                Allocated to registers ;size:2
;@__fs2uchar __uint2fs                 Allocated to registers ;size:2
;@__fs2uchar __sint2fs                 Allocated to registers ;size:2
;@__fs2uchar __ulong2fs                Allocated to registers ;size:2
;@__fs2uchar __slong2fs                Allocated to registers ;size:2
;@__fs2uchar __fs2schar                Allocated to registers ;size:2
;@__fs2uchar __fs2uint                 Allocated to registers ;size:2
;@__fs2uchar __fs2sint                 Allocated to registers ;size:2
;@__fs2uchar __fs2ulong                Allocated to registers ;size:2
;@__fs2uchar __fs2slong                Allocated to registers ;size:2
;@__fs2uchar __fsadd                   Allocated to registers ;size:2
;@__fs2uchar __fssub                   Allocated to registers ;size:2
;@__fs2uchar __fsmul                   Allocated to registers ;size:2
;@__fs2uchar __fsdiv                   Allocated to registers ;size:2
;@__fs2uchar __fslt                    Allocated to registers ;size:2
;@__fs2uchar __fseq                    Allocated to registers ;size:2
;@__fs2uchar __fsneq                   Allocated to registers ;size:2
;@__fs2uchar __fsgt                    Allocated to registers ;size:2
;@__fs2uchar f                         Allocated to registers r0x1003 r0x1002 r0x1001 r0x1000 ;size:4
;@__fs2uchar ul                        Allocated to registers r0x1003 r0x1002 r0x1001 r0x1000 ;size:4
;@end Allocation info for local variables in function '__fs2uchar';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_fs2uchar	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  ___fs2uchar	;Function start
; 2 exit points
;has an exit
;functions called:
;   ___fs2ulong
;   ___fs2ulong
;8 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;   STK01
;   r0x1002
;   STK02
;   r0x1003
;   r0x1004
;; Starting pCode block
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:33:  _entry($4) :
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:33: 	proc ___fs2uchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( float fixed) fixed}
___fs2uchar	;Function start
; 2 exit points
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:33: iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru1 dp0}{float fixed}{ sir@ ___fs2uchar_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ] = recv ___fs2uchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( float fixed) fixed}
;	.line	33; "../../libsdcc_mc35/fs2uchar.c"	unsigned char __fs2uchar (float f) _FS_REENTRANT
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
	MOVAR	STK01
	MOVRA	r0x1002
	MOVAR	STK02
	MOVRA	r0x1003
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:35: 	send iTemp0 [k2 lr3:4 so:0]{ ia0 a2p0 re1 rm0 nos0 ru1 dp0}{float fixed}{ sir@ ___fs2uchar_f_1_21}[r0x1000 r0x1001 r0x1002 r0x1003 ]{argreg = 1}
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:35: 	iTemp1 [k4 lr5:11 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2uchar_ul_1_22}[r0x1000 r0x1001 r0x1002 r0x1003 ] = call ___fs2ulong [k6 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-long-int function ( float fixed) fixed}
;	.line	35; "../../libsdcc_mc35/fs2uchar.c"	unsigned long ul=__fs2ulong(f);
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
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:36: 	iTemp3 [k9 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp1 [k4 lr5:11 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2uchar_ul_1_22}[r0x1000 r0x1001 r0x1002 r0x1003 ] < 0xff {unsigned-long-int literal}
;;unsigned compare: left < lit(0xFF=255), size=4
;	.line	36; "../../libsdcc_mc35/fs2uchar.c"	if (ul>=UCHAR_MAX) return UCHAR_MAX;
	MOVAI	0x00
	XCH	r0x1000
	ASUBRA	r0x1000
	XCH	r0x1000
	JBSET	PFLAG,0
	GOTO	_00111_DS_
	MOVAI	0x00
	XCH	r0x1001
	ASUBRA	r0x1001
	XCH	r0x1001
	JBSET	PFLAG,0
	GOTO	_00111_DS_
	MOVAI	0x00
	XCH	r0x1002
	ASUBRA	r0x1002
	XCH	r0x1002
	JBSET	PFLAG,0
	GOTO	_00111_DS_
	MOVAI	0xff
	XCH	r0x1003
	ASUBRA	r0x1003
	XCH	r0x1003
_00111_DS_
	JBSET	PFLAG,2
	GOTO	_00106_DS_
;;genSkipc:3223: created from rifx:00DD608C
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:36: 	if iTemp3 [k9 lr7:8 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} != 0 goto _iffalse_0($2)
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:36: 	ret 0xff {const-unsigned-char literal}
	MOVAI	0xff
	GOTO	_00107_DS_
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:36:  _iffalse_0($2) :
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:37: 	iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1004 ] = (unsigned-char fixed)iTemp1 [k4 lr5:11 so:0]{ ia0 a2p0 re1 rm0 nos0 ru0 dp0}{unsigned-long-int fixed}{ sir@ ___fs2uchar_ul_1_22}[r0x1000 r0x1001 r0x1002 r0x1003 ]
;;101	MOVAR	r0x1003
;;99	MOVRA	r0x1004
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:37: 	ret iTemp4 [k10 lr11:12 so:0]{ ia0 a2p0 re0 rm0 nos0 ru1 dp0}{unsigned-char fixed}[r0x1004 ]
;;100	MOVAR	r0x1004
_00106_DS_
;	.line	37; "../../libsdcc_mc35/fs2uchar.c"	return ul;
	MOVAR	r0x1003
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:37:  _return($3) :
;;[ICODE] ../../libsdcc_mc35/fs2uchar.c:37: 	eproc ___fs2uchar [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char function ( float fixed) fixed}
_00107_DS_
	RETURN	
; exit point of ___fs2uchar


;	code size estimation:
;	   50+    0 =    50 instructions (  100 byte)

	end
