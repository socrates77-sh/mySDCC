;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 25 2013) (Linux)
; This file was generated Tue Jun 25 18:35:41 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"test.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_STATUSbits
	extern	_P0bits
	extern	_P1bits
	extern	_MCRbits
	extern	_KBIMbits
	extern	_PDCONbits
	extern	_ODCONbits
	extern	_PUCONbits
	extern	_INTECONbits
	extern	_INTFLAGbits
	extern	_DDR0bits
	extern	_DDR1bits
	extern	_TMCRbits
	extern	_T1CRbits
	extern	_INDF
	extern	_T0CNT
	extern	_PCL
	extern	_STATUS
	extern	_FSR
	extern	_P0
	extern	_P1
	extern	_MCR
	extern	_KBIM
	extern	_PCLATH
	extern	_PDCON
	extern	_ODCON
	extern	_PUCON
	extern	_INTECON
	extern	_INTFLAG
	extern	_TOCR
	extern	_DDR0
	extern	_DDR1
	extern	_TMCR
	extern	_T1CR
	extern	_T1CNT
	extern	_T1LOAD
	extern	_T1DATA
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main

	global PSAVE
	global SSAVE
	global WSAVE
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

sharebank udata_ovr 0x0010
PSAVE	res 1
SSAVE	res 1
WSAVE	res 1
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
;	.line	7; "test.c"	DDR1 = 0x01;
	MOVAI	0x01
	MOVRA	_DDR1
;	.line	8; "test.c"	KBIM = DDR1 & 0x55;
	MOVAI	0x55
	ANDAR	_DDR1
	MOVRA	_KBIM
;	.line	9; "test.c"	KBIM = DDR1 | 0x66;
	MOVAI	0x66
	ORAR	_DDR1
	MOVRA	_KBIM
;	.line	10; "test.c"	KBIM = DDR1 ^ 0x66;
	MOVAI	0x66
	XORAR	_DDR1
	MOVRA	_KBIM
;	.line	11; "test.c"	KBIE = 1;
	BSET	_INTECONbits,1
;	.line	15; "test.c"	while(a==3)
	MOVAI	0x01
	MOVRA	r0x1000
	MOVAI	0x02
	MOVRA	r0x1001
_00105_DS_
	MOVAR	r0x1000
	XORAI	0x03
	JBSET	STATUS,2
	GOTO	_00108_DS_
;	.line	17; "test.c"	a++;
	INCR	r0x1000
;	.line	18; "test.c"	b = b + 2;
	INCR	r0x1001
	INCR	r0x1001
;	.line	19; "test.c"	c = a + b;
	GOTO	_00105_DS_
_00108_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	   25+    0 =    25 instructions (   50 byte)

	end
