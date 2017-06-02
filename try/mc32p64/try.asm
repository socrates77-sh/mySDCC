;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 19 2013) (Linux)
; This file was generated Tue Nov 19 14:03:23 2013
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"try.c"
	list	p=32p64
	radix dec
	include "mc32p64.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_STATUSbits
	extern	_MCRbits
	extern	_INTEbits
	extern	_INTFbits
	extern	_OSCMbits
	extern	_IOP0bits
	extern	_OEP0bits
	extern	_PUP0bits
	extern	_IOP1bits
	extern	_OEP1bits
	extern	_PUP1bits
	extern	_IOP2bits
	extern	_OEP2bits
	extern	_PUP2bits
	extern	_IOP3bits
	extern	_OEP3bits
	extern	_PUP3bits
	extern	_T0CRbits
	extern	_T1CRbits
	extern	_T2CRbits
	extern	_TK0CRHbits
	extern	_TK0CRLbits
	extern	_TK1CRHbits
	extern	_TK1CRLbits
	extern	_TK2CRHbits
	extern	_TK2CRLbits
	extern	_ADCR0bits
	extern	_ADCR1bits
	extern	_I2CCRbits
	extern	_INDF
	extern	_INDF0
	extern	_INDF1
	extern	_INDF2
	extern	_HIBYTE
	extern	_FSR
	extern	_FSR0
	extern	_FSR1
	extern	_PCL
	extern	_STATUS
	extern	_MCR
	extern	_INDF3
	extern	_INTE
	extern	_INTF
	extern	_OSCM
	extern	_IOP0
	extern	_OEP0
	extern	_PUP0
	extern	_IOP1
	extern	_OEP1
	extern	_PUP1
	extern	_IOP2
	extern	_OEP2
	extern	_PUP2
	extern	_IOP3
	extern	_OEP3
	extern	_PUP3
	extern	_T0CR
	extern	_T0CNT
	extern	_T0LOAD
	extern	_T0DATA
	extern	_T1CR
	extern	_T1CNT
	extern	_T1LOAD
	extern	_T1DATA
	extern	_T2CR
	extern	_T2CNTH
	extern	_T2CNTL
	extern	_T2LOADH
	extern	_T2LOADL
	extern	_TK0CRH
	extern	_TK0CRL
	extern	_TK0CNTH
	extern	_TK0CNTL
	extern	_TK1CRH
	extern	_TK1CRL
	extern	_TK1CNTH
	extern	_TK1CNTL
	extern	_TK2CRH
	extern	_TK2CRL
	extern	_TK2CNTH
	extern	_TK2CNTL
	extern	_ADCR0
	extern	_ADCR1
	extern	_ADRH
	extern	_ADRL
	extern	_I2CCR
	extern	_I2CADDR
	extern	_I2CDATA
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
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
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
code_try	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	5; "try.c"	OEP0 = 0xff;
	MOVAI	0xff
	MOVRA	_OEP0
;	.line	6; "try.c"	IOP0 = 0xff;
	MOVAI	0xff
	MOVRA	_IOP0
_00106_DS_
;	.line	9; "try.c"	IOP0 = ~IOP0;
	COMAR	_IOP0
	MOVRA	_IOP0
	GOTO	_00106_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	    8+    0 =     8 instructions (   16 byte)

	end
