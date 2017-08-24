;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:36:58 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc33p78.c"
	list	p=33p78
	radix dec
	include "mc33p78.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------

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
	global	_INDF0bits
	global	_INDF1bits
	global	_INDF2bits
	global	_HIBYTEbits
	global	_FSR0bits
	global	_FSR1bits
	global	_PCLbits
	global	_STATUSbits
	global	_MCRbits
	global	_INDF3bits
	global	_INTEbits
	global	_INTFbits
	global	_OSCMbits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_DKWP1bits
	global	_IOP2bits
	global	_OEP2bits
	global	_PUP2bits
	global	_DKWP2bits
	global	_T0CRbits
	global	_T0LOADHbits
	global	_T0LOADLbits
	global	_T0LATRHbits
	global	_T0LATRLbits
	global	_T0LATFHbits
	global	_T0LATFLbits
	global	_T1CRbits
	global	_T1DATAbits
	global	_T1LOADbits
	global	_OPCR0bits
	global	_OPCR1bits
	global	_DKW0bits
	global	_DKW1bits
	global	_INDF
	global	_INDF0
	global	_INDF1
	global	_INDF2
	global	_HIBYTE
	global	_FSR
	global	_FSR0
	global	_FSR1
	global	_PCL
	global	_STATUS
	global	_MCR
	global	_INDF3
	global	_INTE
	global	_INTF
	global	_OSCM
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_DKWP1
	global	_IOP2
	global	_OEP2
	global	_PUP2
	global	_DKWP2
	global	_T0CR
	global	_T0LOADH
	global	_T0LOADL
	global	_T0LATRH
	global	_T0LATRL
	global	_T0LATFH
	global	_T0LATFL
	global	_T1CR
	global	_T1DATA
	global	_T1LOAD
	global	_OPCR0
	global	_OPCR1
	global	_DKW0
	global	_DKW1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc33p78_1b0	udata_ovr	0x01b0
_INDF0bits
_INDF
_INDF0
	res	1
UD_abs_mc33p78_1b1	udata_ovr	0x01b1
_INDF1bits
_INDF1
	res	1
UD_abs_mc33p78_1b2	udata_ovr	0x01b2
_INDF2bits
_INDF2
	res	1
UD_abs_mc33p78_1b3	udata_ovr	0x01b3
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc33p78_1b4	udata_ovr	0x01b4
_FSR0bits
_FSR
_FSR0
	res	1
UD_abs_mc33p78_1b5	udata_ovr	0x01b5
_FSR1bits
_FSR1
	res	1
UD_abs_mc33p78_1b6	udata_ovr	0x01b6
_PCLbits
_PCL
	res	1
UD_abs_mc33p78_1b7	udata_ovr	0x01b7
_STATUSbits
_STATUS
	res	1
UD_abs_mc33p78_1b8	udata_ovr	0x01b8
_MCRbits
_MCR
	res	1
UD_abs_mc33p78_1b9	udata_ovr	0x01b9
_INDF3bits
_INDF3
	res	1
UD_abs_mc33p78_1ba	udata_ovr	0x01ba
_INTEbits
_INTE
	res	1
UD_abs_mc33p78_1bb	udata_ovr	0x01bb
_INTFbits
_INTF
	res	1
UD_abs_mc33p78_1bc	udata_ovr	0x01bc
_OSCMbits
_OSCM
	res	1
UD_abs_mc33p78_1c8	udata_ovr	0x01c8
_IOP1bits
_IOP1
	res	1
UD_abs_mc33p78_1c9	udata_ovr	0x01c9
_OEP1bits
_OEP1
	res	1
UD_abs_mc33p78_1ca	udata_ovr	0x01ca
_PUP1bits
_PUP1
	res	1
UD_abs_mc33p78_1ce	udata_ovr	0x01ce
_DKWP1bits
_DKWP1
	res	1
UD_abs_mc33p78_1d0	udata_ovr	0x01d0
_IOP2bits
_IOP2
	res	1
UD_abs_mc33p78_1d1	udata_ovr	0x01d1
_OEP2bits
_OEP2
	res	1
UD_abs_mc33p78_1d2	udata_ovr	0x01d2
_PUP2bits
_PUP2
	res	1
UD_abs_mc33p78_1d6	udata_ovr	0x01d6
_DKWP2bits
_DKWP2
	res	1
UD_abs_mc33p78_1d8	udata_ovr	0x01d8
_T0CRbits
_T0CR
	res	1
UD_abs_mc33p78_1d9	udata_ovr	0x01d9
_T0LOADHbits
_T0LOADH
	res	1
UD_abs_mc33p78_1da	udata_ovr	0x01da
_T0LOADLbits
_T0LOADL
	res	1
UD_abs_mc33p78_1db	udata_ovr	0x01db
_T0LATRHbits
_T0LATRH
	res	1
UD_abs_mc33p78_1dc	udata_ovr	0x01dc
_T0LATRLbits
_T0LATRL
	res	1
UD_abs_mc33p78_1dd	udata_ovr	0x01dd
_T0LATFHbits
_T0LATFH
	res	1
UD_abs_mc33p78_1de	udata_ovr	0x01de
_T0LATFLbits
_T0LATFL
	res	1
UD_abs_mc33p78_1e0	udata_ovr	0x01e0
_T1CRbits
_T1CR
	res	1
UD_abs_mc33p78_1e1	udata_ovr	0x01e1
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc33p78_1e2	udata_ovr	0x01e2
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc33p78_1e4	udata_ovr	0x01e4
_OPCR0bits
_OPCR0
	res	1
UD_abs_mc33p78_1e5	udata_ovr	0x01e5
_OPCR1bits
_OPCR1
	res	1
UD_abs_mc33p78_1e6	udata_ovr	0x01e6
_DKW0bits
_DKW0
	res	1
UD_abs_mc33p78_1e7	udata_ovr	0x01e7
_DKW1bits
_DKW1
	res	1
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
; code
;--------------------------------------------------------
code_mc33p78	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
