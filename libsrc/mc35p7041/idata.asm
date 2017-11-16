;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.0.0 (Sep 28 2017) (MINGW32)
; This file was generated Tue Nov 14 18:38:40 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"../libsdcc_mc35/idata.c"
	list	p=2K7041
	radix dec
	include "2K7041.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_main
	extern	_cinit
	extern	__gptrget2
	extern	__gptrget1

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
	global	__sdcc_gsinit_startup

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_idata_0	udata
r0x1001	res	1
r0x1000	res	1
r0x1002	res	1
r0x1003	res	1
r0x1004	res	1
r0x1005	res	1
r0x1007	res	1
r0x1006	res	1
r0x1009	res	1
r0x1008	res	1
r0x100B	res	1
r0x100A	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

ID_idata_0	idata
_force_cinit
	db	0x00


;@Allocation info for local variables in function '_sdcc_gsinit_startup'
;@_sdcc_gsinit_startup main                      Allocated to registers ;size:2
;@_sdcc_gsinit_startup _sdcc_gsinit_startup      Allocated to registers ;size:2
;@_sdcc_gsinit_startup force_cinit               Allocated to registers ;size:1
;@_sdcc_gsinit_startup num                       Allocated to registers ;size:2
;@_sdcc_gsinit_startup size                      Allocated to registers ;size:2
;@_sdcc_gsinit_startup cptr                      Allocated to registers ;size:2
;@_sdcc_gsinit_startup src                       Allocated to registers ;size:2
;@_sdcc_gsinit_startup dst                       Allocated to registers ;size:2
;@end Allocation info for local variables in function '_sdcc_gsinit_startup';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_idata	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  __sdcc_gsinit_startup	;Function start
; 2 exit points
;has an exit
;functions called:
;   __gptrget2
;   __gptrget2
;   __gptrget2
;   __gptrget2
;   __gptrget1
;   __gptrget2
;   __gptrget2
;   __gptrget2
;   __gptrget2
;   __gptrget1
;14 compiler assigned registers:
;   STK01
;   STK00
;   r0x1000
;   r0x1001
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;   r0x1008
;   r0x1009
;   r0x100A
;   r0x100B
;; Starting pCode block
;;[ICODE] ../libsdcc_mc35/idata.c:68:  _entry($8) :
;;[ICODE] ../libsdcc_mc35/idata.c:68: 	proc __sdcc_gsinit_startup [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{void function ( ) fixed}
__sdcc_gsinit_startup	;Function start
; 2 exit points
;;[ICODE] ../libsdcc_mc35/idata.c:75: 	iTemp1 [k5 lr3:4 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{const-unsigned-int code* code}[remat] = &[_cinit [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000001 code}]
;;[ICODE] ../libsdcc_mc35/idata.c:75: 	iTemp9 [k16 lr4:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = @[iTemp1 [k5 lr3:4 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{const-unsigned-int code* code}[remat] + 0x0 {const-unsigned-char literal}]
;	.line	75; "../libsdcc_mc35/idata.c"	num = cinit.records;
	MOVAI	(_cinit + 0)
	MOVRA	STK01
	MOVAI	high (_cinit + 0)
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget2
	MOVRA	r0x1000
	MOVAR	STK00
	MOVRA	r0x1001
;;[ICODE] ../libsdcc_mc35/idata.c:76: 	iTemp5 [k11 lr6:7 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{const-struct __00000001 code* code}[remat] = &[_cinit [k4 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000001 code}]
;;[ICODE] ../libsdcc_mc35/idata.c:76: 	iTemp34 [k47 lr7:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] = iTemp5 [k11 lr6:7 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{const-struct __00000001 code* code}[remat] + 0x2 {const-unsigned-char literal}
;	.line	76; "../libsdcc_mc35/idata.c"	cptr = &cinit.entry[0];
	MOVAI	(_cinit + 2)
	MOVRA	r0x1002
	MOVAI	high (_cinit + 2)
	MOVRA	r0x1003
;;[ICODE] ../libsdcc_mc35/idata.c:79:  _whilecontinue_0($4) :
;;[ICODE] ../libsdcc_mc35/idata.c:79: 	iTemp8 [k15 lr14:16 so:0]{ ia0 a2p0 re0 rm0 nos1 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] := iTemp9 [k16 lr4:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ]
_00108_DS_
;	.line	79; "../libsdcc_mc35/idata.c"	while (num--) {
	MOVAR	r0x1001
	MOVRA	r0x1004
	MOVAR	r0x1000
	MOVRA	r0x1005
;;[ICODE] ../libsdcc_mc35/idata.c:79: 	iTemp9 [k16 lr4:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] = iTemp9 [k16 lr4:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1000 r0x1001 ] - 0x1 {const-unsigned-char literal}
	MOVAI	0xff
	ADDRA	r0x1001
	JBSET	STATUS,0
	DJZR	r0x1000
	NOP	
;;[ICODE] ../libsdcc_mc35/idata.c:79: 	if iTemp8 [k15 lr14:16 so:0]{ ia0 a2p0 re0 rm0 nos1 ru0 dp0}{unsigned-int fixed}[r0x1004 r0x1005 ] == 0 goto _whilebreak_0($6)
	MOVAR	r0x1004
	ORAR	r0x1005
	JBCLR	STATUS,2
	GOTO	_00110_DS_
;;[ICODE] ../libsdcc_mc35/idata.c:80: 	iTemp12 [k21 lr17:18 so:0]{ ia1 a2p0 re0 rm0 nos0 ru1 dp0}{const-unsigned-int code* fixed}[r0x1004 r0x1005 ] = iTemp34 [k47 lr7:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] + 0x4 {const-unsigned-char literal}
;	.line	80; "../libsdcc_mc35/idata.c"	size = cptr->size;
	MOVAI	0x04
	ADDAR	r0x1002
	MOVRA	r0x1004
	CLRR	r0x1005
	RLR	r0x1005
	MOVAR	r0x1003
	ADDRA	r0x1005
;;[ICODE] ../libsdcc_mc35/idata.c:80: 	iTemp25 [k38 lr18:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = @[iTemp12 [k21 lr17:18 so:0]{ ia1 a2p0 re0 rm0 nos0 ru1 dp0}{const-unsigned-int code* fixed}[r0x1004 r0x1005 ] + 0x0 {const-unsigned-char literal}]
	MOVAR	r0x1004
	MOVRA	STK01
	MOVAR	r0x1005
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget2
	MOVRA	r0x1006
	MOVAR	STK00
	MOVRA	r0x1007
;;[ICODE] ../libsdcc_mc35/idata.c:81: 	iTemp17 [k28 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-unsigned-int fixed}[r0x1004 r0x1005 ] = @[iTemp34 [k47 lr7:42 so:0]{ ia1 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] + 0x0 {const-unsigned-char literal}]
;	.line	81; "../libsdcc_mc35/idata.c"	src = (__code char *) cptr->src;
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1003
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget2
	MOVRA	r0x1008
	MOVRA	r0x1005
	MOVAR	STK00
	MOVRA	r0x1009
	MOVRA	r0x1004
;;[ICODE] ../libsdcc_mc35/idata.c:81: 	iTemp30 [k43 lr21:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-char code* fixed}[r0x1008 r0x1009 ] = (const-char code* fixed)iTemp17 [k28 lr20:21 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-unsigned-int fixed}[r0x1004 r0x1005 ]
;;100	MOVAR	r0x1005
;;99	MOVAR	r0x1004
;;[ICODE] ../libsdcc_mc35/idata.c:82: 	iTemp21 [k34 lr23:24 so:0]{ ia1 a2p0 re0 rm0 nos0 ru1 dp0}{const-unsigned-int code* fixed}[r0x1004 r0x1005 ] = iTemp34 [k47 lr7:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] + 0x2 {const-unsigned-char literal}
;	.line	82; "../libsdcc_mc35/idata.c"	dst = (__data char *) cptr->dst;
	MOVAI	0x02
	ADDAR	r0x1002
	MOVRA	r0x1004
	CLRR	r0x1005
	RLR	r0x1005
	MOVAR	r0x1003
	ADDRA	r0x1005
;;[ICODE] ../libsdcc_mc35/idata.c:82: 	iTemp22 [k35 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-unsigned-int fixed}[r0x100A r0x100B ] = @[iTemp21 [k34 lr23:24 so:0]{ ia1 a2p0 re0 rm0 nos0 ru1 dp0}{const-unsigned-int code* fixed}[r0x1004 r0x1005 ] + 0x0 {const-unsigned-char literal}]
	MOVAR	r0x1004
	MOVRA	STK01
	MOVAR	r0x1005
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget2
	MOVRA	r0x1005
	MOVRA	r0x100A
	MOVAR	STK00
	MOVRA	r0x1004
	MOVRA	r0x100B
;;[ICODE] ../libsdcc_mc35/idata.c:82: 	iTemp32 [k45 lr25:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char near* fixed}[r0x1004 r0x1005 ] = (char near* fixed)iTemp22 [k35 lr24:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-unsigned-int fixed}[r0x100A r0x100B ]
;;102	MOVAR	r0x100A
;;101	MOVAR	r0x100B
;;[ICODE] ../libsdcc_mc35/idata.c:85:  _whilecontinue_1($1) :
;;[ICODE] ../libsdcc_mc35/idata.c:85: 	iTemp24 [k37 lr32:34 so:0]{ ia0 a2p0 re0 rm0 nos1 ru0 dp0}{unsigned-int fixed}[r0x100A r0x100B ] := iTemp25 [k38 lr18:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ]
_00105_DS_
;	.line	85; "../libsdcc_mc35/idata.c"	while (size--) {
	MOVAR	r0x1007
	MOVRA	r0x100B
	MOVAR	r0x1006
	MOVRA	r0x100A
;;[ICODE] ../libsdcc_mc35/idata.c:85: 	iTemp25 [k38 lr18:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] = iTemp25 [k38 lr18:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}[r0x1006 r0x1007 ] - 0x1 {const-unsigned-char literal}
	MOVAI	0xff
	ADDRA	r0x1007
	JBSET	STATUS,0
	DJZR	r0x1006
	NOP	
;;[ICODE] ../libsdcc_mc35/idata.c:85: 	if iTemp24 [k37 lr32:34 so:0]{ ia0 a2p0 re0 rm0 nos1 ru0 dp0}{unsigned-int fixed}[r0x100A r0x100B ] == 0 goto _whilebreak_1($3)
	MOVAR	r0x100B
	ORAR	r0x100A
	JBCLR	STATUS,2
	GOTO	_00107_DS_
;;[ICODE] ../libsdcc_mc35/idata.c:86: 	iTemp28 [k41 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-char register}[r0x100A ] = @[iTemp30 [k43 lr21:39 so:0]{ ia1 a2p0 re0 rm0 nos0 ru0 dp0}{const-char code* fixed}[r0x1008 r0x1009 ] + 0x0 {const-unsigned-char literal}]
;	.line	86; "../libsdcc_mc35/idata.c"	*dst = *src;
	MOVAR	r0x1009
	MOVRA	STK01
	MOVAR	r0x1008
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget1
	MOVRA	r0x100B
;;[ICODE] ../libsdcc_mc35/idata.c:86: 	*(iTemp32 [k45 lr25:39 so:0]{ ia1 a2p0 re0 rm0 nos0 ru0 dp0}{char near* fixed}[r0x1004 r0x1005 ]) := iTemp28 [k41 lr35:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-char register}[r0x100A ]
	MOVAR	r0x1004
	MOVRA	FSR
	BCLR	STATUS,7
	JBCLR	r0x1005,0
	BSET	STATUS,7
	MOVAR	r0x100B
	MOVRA	INDF
;;[ICODE] ../libsdcc_mc35/idata.c:87: 	iTemp30 [k43 lr21:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-char code* fixed}[r0x1008 r0x1009 ] = iTemp30 [k43 lr21:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-char code* fixed}[r0x1008 r0x1009 ] + 0x1 {const-unsigned-char literal}
;	.line	87; "../libsdcc_mc35/idata.c"	src++;
	MOVAI	0x01
	ADDRA	r0x1009
	JBCLR	STATUS,2
	ADDRA	r0x1008
;;[ICODE] ../libsdcc_mc35/idata.c:88: 	iTemp32 [k45 lr25:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char near* fixed}[r0x1004 r0x1005 ] = iTemp32 [k45 lr25:39 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char near* fixed}[r0x1004 r0x1005 ] + 0x1 {const-unsigned-char literal}
;	.line	88; "../libsdcc_mc35/idata.c"	dst++;
	MOVAI	0x01
	ADDRA	r0x1004
	JBCLR	STATUS,2
	ADDRA	r0x1005
;;[ICODE] ../libsdcc_mc35/idata.c:88: 	 goto _whilecontinue_1($1)
	GOTO	_00105_DS_
;;[ICODE] ../libsdcc_mc35/idata.c:88:  _whilebreak_1($3) :
;;[ICODE] ../libsdcc_mc35/idata.c:92: 	iTemp34 [k47 lr7:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] = iTemp34 [k47 lr7:42 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{const-struct __00000000 code* fixed}[r0x1002 r0x1003 ] + 0x6 {const-unsigned-char literal}
_00107_DS_
;	.line	92; "../libsdcc_mc35/idata.c"	cptr++;
	MOVAI	0x06
	ADDRA	r0x1002
	JBCLR	STATUS,0
	JZR	r0x1003
	NOP	
;;[ICODE] ../libsdcc_mc35/idata.c:92: 	 goto _whilecontinue_0($4)
	GOTO	_00108_DS_
;;[ICODE] ../libsdcc_mc35/idata.c:92:  _whilebreak_0($6) :
;;[ICODE] ../libsdcc_mc35/idata.c:99: inline
_00110_DS_
;	.line	99; "../libsdcc_mc35/idata.c"	__endasm;
	GOTO _main
	
;;[ICODE] ../libsdcc_mc35/idata.c:99:  _return($7) :
;;[ICODE] ../libsdcc_mc35/idata.c:99: 	eproc __sdcc_gsinit_startup [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{void function ( ) fixed}
	RETURN	
; exit point of __sdcc_gsinit_startup


;	code size estimation:
;	  114+    0 =   114 instructions (  228 byte)

	end
