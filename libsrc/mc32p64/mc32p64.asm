;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.0.0 (Sep 28 2017) (MINGW32)
; This file was generated Thu Dec 07 13:58:34 2017
;--------------------------------------------------------
; MC30/MC32 port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p64.c"
	list	p=3264
	radix dec
	include "3264.inc"
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
	global	_STATUSbits
	global	_MCRbits
	global	_INTEbits
	global	_INTFbits
	global	_OSCMbits
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_IOP2bits
	global	_OEP2bits
	global	_PUP2bits
	global	_IOP3bits
	global	_OEP3bits
	global	_PUP3bits
	global	_T0CRbits
	global	_T1CRbits
	global	_T2CRbits
	global	_TK0CRHbits
	global	_TK0CRLbits
	global	_TK1CRHbits
	global	_TK1CRLbits
	global	_TK2CRHbits
	global	_TK2CRLbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_I2CCRbits
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
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_IOP2
	global	_OEP2
	global	_PUP2
	global	_IOP3
	global	_OEP3
	global	_PUP3
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_T2CR
	global	_T2CNTH
	global	_T2CNTL
	global	_T2LOADH
	global	_T2LOADL
	global	_TK0CRH
	global	_TK0CRL
	global	_TK0CNTH
	global	_TK0CNTL
	global	_TK1CRH
	global	_TK1CRL
	global	_TK1CNTH
	global	_TK1CNTL
	global	_TK2CRH
	global	_TK2CRL
	global	_TK2CNTH
	global	_TK2CNTL
	global	_ADCR0
	global	_ADCR1
	global	_ADRH
	global	_ADRL
	global	_I2CCR
	global	_I2CADDR
	global	_I2CDATA

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p64_1b0	udata_ovr	0x01b0
_INDF
_INDF0
	res	1
UD_abs_mc32p64_1b1	udata_ovr	0x01b1
_INDF1
	res	1
UD_abs_mc32p64_1b2	udata_ovr	0x01b2
_INDF2
	res	1
UD_abs_mc32p64_1b3	udata_ovr	0x01b3
_HIBYTE
	res	1
UD_abs_mc32p64_1b4	udata_ovr	0x01b4
_FSR
_FSR0
	res	1
UD_abs_mc32p64_1b5	udata_ovr	0x01b5
_FSR1
	res	1
UD_abs_mc32p64_1b6	udata_ovr	0x01b6
_PCL
	res	1
UD_abs_mc32p64_1b7	udata_ovr	0x01b7
_STATUSbits
_STATUS
	res	1
UD_abs_mc32p64_1b8	udata_ovr	0x01b8
_MCRbits
_MCR
	res	1
UD_abs_mc32p64_1b9	udata_ovr	0x01b9
_INDF3
	res	1
UD_abs_mc32p64_1ba	udata_ovr	0x01ba
_INTEbits
_INTE
	res	1
UD_abs_mc32p64_1bb	udata_ovr	0x01bb
_INTFbits
_INTF
	res	1
UD_abs_mc32p64_1bc	udata_ovr	0x01bc
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p64_1c0	udata_ovr	0x01c0
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p64_1c1	udata_ovr	0x01c1
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p64_1c2	udata_ovr	0x01c2
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p64_1c4	udata_ovr	0x01c4
_IOP1bits
_IOP1
	res	1
UD_abs_mc32p64_1c5	udata_ovr	0x01c5
_OEP1bits
_OEP1
	res	1
UD_abs_mc32p64_1c6	udata_ovr	0x01c6
_PUP1bits
_PUP1
	res	1
UD_abs_mc32p64_1c8	udata_ovr	0x01c8
_IOP2bits
_IOP2
	res	1
UD_abs_mc32p64_1c9	udata_ovr	0x01c9
_OEP2bits
_OEP2
	res	1
UD_abs_mc32p64_1ca	udata_ovr	0x01ca
_PUP2bits
_PUP2
	res	1
UD_abs_mc32p64_1cc	udata_ovr	0x01cc
_IOP3bits
_IOP3
	res	1
UD_abs_mc32p64_1cd	udata_ovr	0x01cd
_OEP3bits
_OEP3
	res	1
UD_abs_mc32p64_1ce	udata_ovr	0x01ce
_PUP3bits
_PUP3
	res	1
UD_abs_mc32p64_1d0	udata_ovr	0x01d0
_T0CRbits
_T0CR
	res	1
UD_abs_mc32p64_1d1	udata_ovr	0x01d1
_T0CNT
	res	1
UD_abs_mc32p64_1d2	udata_ovr	0x01d2
_T0LOAD
	res	1
UD_abs_mc32p64_1d3	udata_ovr	0x01d3
_T0DATA
	res	1
UD_abs_mc32p64_1d4	udata_ovr	0x01d4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p64_1d5	udata_ovr	0x01d5
_T1CNT
	res	1
UD_abs_mc32p64_1d6	udata_ovr	0x01d6
_T1LOAD
	res	1
UD_abs_mc32p64_1d7	udata_ovr	0x01d7
_T1DATA
	res	1
UD_abs_mc32p64_1d8	udata_ovr	0x01d8
_T2CRbits
_T2CR
	res	1
UD_abs_mc32p64_1d9	udata_ovr	0x01d9
_T2CNTH
	res	1
UD_abs_mc32p64_1da	udata_ovr	0x01da
_T2CNTL
	res	1
UD_abs_mc32p64_1db	udata_ovr	0x01db
_T2LOADH
	res	1
UD_abs_mc32p64_1dc	udata_ovr	0x01dc
_T2LOADL
	res	1
UD_abs_mc32p64_1e0	udata_ovr	0x01e0
_TK0CRHbits
_TK0CRH
	res	1
UD_abs_mc32p64_1e1	udata_ovr	0x01e1
_TK0CRLbits
_TK0CRL
	res	1
UD_abs_mc32p64_1e2	udata_ovr	0x01e2
_TK0CNTH
	res	1
UD_abs_mc32p64_1e3	udata_ovr	0x01e3
_TK0CNTL
	res	1
UD_abs_mc32p64_1e4	udata_ovr	0x01e4
_TK1CRHbits
_TK1CRH
	res	1
UD_abs_mc32p64_1e5	udata_ovr	0x01e5
_TK1CRLbits
_TK1CRL
	res	1
UD_abs_mc32p64_1e6	udata_ovr	0x01e6
_TK1CNTH
	res	1
UD_abs_mc32p64_1e7	udata_ovr	0x01e7
_TK1CNTL
	res	1
UD_abs_mc32p64_1e8	udata_ovr	0x01e8
_TK2CRHbits
_TK2CRH
	res	1
UD_abs_mc32p64_1e9	udata_ovr	0x01e9
_TK2CRLbits
_TK2CRL
	res	1
UD_abs_mc32p64_1ea	udata_ovr	0x01ea
_TK2CNTH
	res	1
UD_abs_mc32p64_1eb	udata_ovr	0x01eb
_TK2CNTL
	res	1
UD_abs_mc32p64_1ec	udata_ovr	0x01ec
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32p64_1ed	udata_ovr	0x01ed
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32p64_1ee	udata_ovr	0x01ee
_ADRH
	res	1
UD_abs_mc32p64_1ef	udata_ovr	0x01ef
_ADRL
	res	1
UD_abs_mc32p64_1f0	udata_ovr	0x01f0
_I2CCRbits
_I2CCR
	res	1
UD_abs_mc32p64_1f1	udata_ovr	0x01f1
_I2CADDR
	res	1
UD_abs_mc32p64_1f2	udata_ovr	0x01f2
_I2CDATA
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
code_mc32p64	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
