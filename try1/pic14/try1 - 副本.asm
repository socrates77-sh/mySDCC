;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 2.0.0 (Oct 16 2019) (MINGW32)
; This file was generated Wed Oct 16 17:19:56 2019
;--------------------------------------------------------
; MC32 port for the RISC core
;--------------------------------------------------------
;	.file	"try1.c"
	list	p=7511
	radix dec
	include "7511.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__rlsint
	extern	__rruint
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main
	global	_uc_a
	global	_ram0
	global	_ram1

	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x0000
STK06	res 1
STK05	res 1
STK04	res 1
STK03	res 1
STK02	res 1
STK01	res 1
STK00	res 1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
UD_try1_0	udata
_uc_a	res	2

;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_try1_20	udata_ovr	0x0020
_ram0
	res	1
UD_abs_try1_21	udata_ovr	0x0021
_ram1
	res	1
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_try1_0	udata
r0x1003	res	1
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

;@Allocation info for local variables in function 'main'
;@main main                      Allocated to registers ;size:2
;@main _rlsint                   Allocated to registers ;size:2
;@main _rruint                   Allocated to registers ;size:2
;@main uc_a                      Allocated to registers ;size:2
;@main ram0                      Allocated to registers ;size:1
;@main ram1                      Allocated to registers ;size:1
;@end Allocation info for local variables in function 'main';

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
STARTUP	code 0x0000
	goto	_main
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_try1	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;functions called:
;   __rlsint
;   __rruint
;   __rlsint
;   __rruint
;7 compiler assigned registers:
;   r0x1003
;   r0x1004
;   STK02
;   STK01
;   STK00
;   r0x1005
;   r0x1006
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	10; "try1.c"	uc_a = (ram1<<2) + ram0;
	MOVAR	_ram1
	MOVRA	r0x1003
	CLRR	r0x1004
	MOVAI	0x02
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAR	r0x1003
	MOVRA	STK00
	MOVAI	0x00
	CALL	__rlsint
	MOVRA	r0x1004
	MOVAR	STK00
	MOVRA	r0x1003
	MOVAR	_ram0
	MOVRA	r0x1005
	CLRR	r0x1006
	MOVAR	r0x1005
	ADDAR	r0x1003
	MOVRA	_uc_a
	MOVAR	r0x1004
	MOVRA	(_uc_a + 1)
	MOVAI	0x00
	JBCLR	PFLAG,0
	JZAR	r0x1006
	ADDRA	(_uc_a + 1)
;	.line	11; "try1.c"	ram1 = (uc_a)>>8;
	MOVAI	0x08
	MOVRA	STK02
	MOVAI	0x00
	MOVRA	STK01
	MOVAR	_uc_a
	MOVRA	STK00
	MOVAR	(_uc_a + 1)
	CALL	__rruint
	MOVRA	r0x1004
	MOVAR	STK00
	MOVRA	r0x1003
	MOVAR	r0x1003
	MOVRA	_ram1
_00106_DS_
;	.line	13; "try1.c"	while(1);
	GOTO	_00106_DS_
;	.line	14; "try1.c"	}
	RETURN	
; exit point of _main


;	code size estimation:
;	   41+    0 =    41 instructions (   82 byte)

	end
