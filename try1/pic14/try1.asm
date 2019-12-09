;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 2.0.0 (Oct 16 2019) (MINGW32)
; This file was generated Wed Oct 16 17:21:16 2019
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"try1.c"
	list	p=16f1507
	radix dec
	include "p16f1507.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main
	global	_uc_a
	global	_ram0
	global	_ram1

	global STK12
	global STK11
	global STK10
	global STK09
	global STK08
	global STK07
	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x0070
STK12	res 1
STK11	res 1
STK10	res 1
STK09	res 1
STK08	res 1
STK07	res 1
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
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
STARTUP	code 0x0000
	nop
	pagesel __sdcc_gsinit_startup
	goto	__sdcc_gsinit_startup
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_try1	code
;***
;  pBlock Stats: dbName = M
;***
;has an exit
;4 compiler assigned registers:
;   r0x1003
;   r0x1004
;   r0x1005
;   r0x1006
;; Starting pCode block
S_try1__main	code
_main:	;Function start
; 2 exit points
;	.line	10; "try1.c"	uc_a = (ram1<<2) + ram0;
	BANKSEL	_ram1
	MOVF	_ram1,W
	BANKSEL	r0x1003
	MOVWF	r0x1003
;; BANKOPT2 BANKSEL dropped; r0x1004 present in same bank as r0x1003
	CLRF	r0x1004
;; BANKOPT2 BANKSEL dropped; r0x1003 present in same bank as r0x1003
	LSLF	r0x1003,W
;; BANKOPT2 BANKSEL dropped; r0x1005 present in same bank as r0x1003
	MOVWF	r0x1005
;; BANKOPT2 BANKSEL dropped; r0x1004 present in same bank as r0x1003
	RLF	r0x1004,W
;; BANKOPT2 BANKSEL dropped; r0x1006 present in same bank as r0x1003
	MOVWF	r0x1006
;; BANKOPT2 BANKSEL dropped; r0x1005 present in same bank as r0x1003
	LSLF	r0x1005,F
;; BANKOPT2 BANKSEL dropped; r0x1006 present in same bank as r0x1003
	RLF	r0x1006,F
	BANKSEL	_ram0
	MOVF	_ram0,W
	BANKSEL	r0x1003
	MOVWF	r0x1003
;; BANKOPT2 BANKSEL dropped; r0x1004 present in same bank as r0x1003
	CLRF	r0x1004
;; BANKOPT2 BANKSEL dropped; r0x1003 present in same bank as r0x1003
	MOVF	r0x1003,W
;; BANKOPT2 BANKSEL dropped; r0x1005 present in same bank as r0x1003
	ADDWF	r0x1005,W
	BANKSEL	_uc_a
	MOVWF	_uc_a
	BANKSEL	r0x1006
	MOVF	r0x1006,W
	BANKSEL	_uc_a
	MOVWF	(_uc_a + 1)
	MOVLW	0x00
;; BANKOPT1 BANKSEL dropped; STATUS present in all of _uc_a's banks
	BTFSS	STATUS,0
	GOTO	_00001_DS_
	BANKSEL	r0x1004
	INCF	r0x1004,W
	BTFSC	STATUS,2
	GOTO	_00002_DS_
;; BANKOPT3 drop assumptions: PCI with label or call found
_00001_DS_:
	BANKSEL	_uc_a
	ADDWF	(_uc_a + 1),F
;; BANKOPT3 drop assumptions: PCI with label or call found
_00002_DS_:
;	.line	11; "try1.c"	ram1 = (uc_a)>>8;
	BANKSEL	_uc_a
	MOVF	(_uc_a + 1),W
	BANKSEL	r0x1003
	MOVWF	r0x1003
;; BANKOPT2 BANKSEL dropped; r0x1004 present in same bank as r0x1003
	CLRF	r0x1004
;; BANKOPT2 BANKSEL dropped; r0x1003 present in same bank as r0x1003
	MOVF	r0x1003,W
	BANKSEL	_ram1
	MOVWF	_ram1
;; BANKOPT3 drop assumptions: PCI with label or call found
_00106_DS_:
;	.line	13; "try1.c"	while(1);
	GOTO	_00106_DS_
;	.line	14; "try1.c"	}
	RETURN	
; exit point of _main


;	code size estimation:
;	   31+   12 =    43 instructions (  110 byte)

	end
