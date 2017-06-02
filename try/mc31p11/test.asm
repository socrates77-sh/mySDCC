;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 19 2013) (Linux)
; This file was generated Tue Nov 19 14:03:03 2013
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"test.c"
	list	p=31p11
	radix dec
	include "mc31p11.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_STATUSbits
	extern	_MCRbits
	extern	_INTECONbits
	extern	_INTFLAGbits
	extern	_IOP0bits
	extern	_OEP0bits
	extern	_PUP0bits
	extern	_DKWP0bits
	extern	_IOP1bits
	extern	_OEP1bits
	extern	_PUP1bits
	extern	_DKWP1bits
	extern	_DKWbits
	extern	_INDF
	extern	_FSR
	extern	_PCL
	extern	_STATUS
	extern	_MCR
	extern	_INTECON
	extern	_INTFLAG
	extern	_IOP0
	extern	_OEP0
	extern	_PUP0
	extern	_DKWP0
	extern	_IOP1
	extern	_OEP1
	extern	_PUP1
	extern	_DKWP1
	extern	_DKW
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main

	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x0010
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
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_test_0	udata
r0x1000	res	1
r0x1001	res	1
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
	goto	__sdcc_gsinit_startup
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_test	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;2 compiler assigned registers:
;   r0x1000
;   r0x1001
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	7; "test.c"	IOP0 = 0x01;
	MOVAI	0x01
	MOVRA	_IOP0
;	.line	8; "test.c"	DKW = IOP0 & 0x55;
	MOVAI	0x55
	ANDAR	_IOP0
	MOVRA	_DKW
;	.line	9; "test.c"	DKW = IOP0 | 0x66;
	MOVAI	0x66
	ORAR	_IOP0
	MOVRA	_DKW
;	.line	10; "test.c"	DKW = IOP0 ^ 0x66;
	MOVAI	0x66
	XORAR	_IOP0
	MOVRA	_DKW
;	.line	11; "test.c"	GIE = 1;
	BSET	_MCRbits,7
;	.line	12; "test.c"	MINT0 = 2;
	MOVAR	(_MCRbits + 0)
	ANDAI	0xfc
	ORAI	0x02
	MOVRA	(_MCRbits + 0)
;	.line	16; "test.c"	while(a==3)
	MOVAI	0x01
	MOVRA	r0x1000
	MOVAI	0x02
	MOVRA	r0x1001
_00105_DS_
	MOVAR	r0x1000
	XORAI	0x03
	JBSET	STATUS,2
	GOTO	_00108_DS_
;	.line	18; "test.c"	a++;
	INCR	r0x1000
;	.line	19; "test.c"	b = b + 2;
	INCR	r0x1001
	INCR	r0x1001
;	.line	20; "test.c"	c = a + b;
	GOTO	_00105_DS_
_00108_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	   29+    0 =    29 instructions (   58 byte)

	end
