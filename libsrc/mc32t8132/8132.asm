;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Mon Nov 30 22:56:07 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"8132.c"
	list	p=8132
	radix dec
	include "8132.inc"
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
	global	_CLKObits
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_PDP0bits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_PDP1bits
	global	_IOP2bits
	global	_OEP2bits
	global	_PUP2bits
	global	_PDP2bits
	global	_IOP3bits
	global	_OEP3bits
	global	_PUP3bits
	global	_PDP3bits
	global	_T0CRbits
	global	_T0CNTbits
	global	_T0LOADbits
	global	_T0DATAbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T1DATAbits
	global	_T2CRbits
	global	_T2CNTHbits
	global	_T2CNTLbits
	global	_T2LOADHbits
	global	_T2LOADLbits
	global	_TK0CR0bits
	global	_TK0CR1bits
	global	_TK0CR2bits
	global	_TK0CNTHbits
	global	_TK0CNTLbits
	global	_TK1CR0bits
	global	_TK1CR1bits
	global	_TK1CR2bits
	global	_TK1CNTHbits
	global	_TK1CNTLbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_ADIO0bits
	global	_ADIO1bits
	global	_ADRHbits
	global	_ADRLbits
	global	_LEDCR0bits
	global	_LEDCR1bits
	global	_LEDIOS0bits
	global	_LEDIOS1bits
	global	_LEDDRVbits
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
	global	_PFLAG
	global	_MCR
	global	_INDF3
	global	_INTE
	global	_INTF
	global	_OSCM
	global	_CLKO
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_PDP0
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_PDP1
	global	_IOP2
	global	_OEP2
	global	_PUP2
	global	_PDP2
	global	_IOP3
	global	_OEP3
	global	_PUP3
	global	_PDP3
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
	global	_TK0CR0
	global	_TK0CR1
	global	_TK0CR2
	global	_TK0CNTH
	global	_TK0CNTL
	global	_TK1CR0
	global	_TK1CR1
	global	_TK1CR2
	global	_TK1CNTH
	global	_TK1CNTL
	global	_ADCR0
	global	_ADCR1
	global	_ADCR2
	global	_ADIO0
	global	_ADIO1
	global	_ADRH
	global	_ADRL
	global	_LEDDS1
	global	_LEDDS2
	global	_LEDDS3
	global	_LEDDS4
	global	_LEDDS5
	global	_LEDDS6
	global	_LEDDS7
	global	_LEDDS8
	global	_LEDCR0
	global	_LEDCR1
	global	_LEDIOS0
	global	_LEDIOS1
	global	_LEDDRV

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_8132_1a0	udata_ovr	0x01a0
_INDF0bits
_INDF
_INDF0
	res	1
UD_abs_8132_1a1	udata_ovr	0x01a1
_INDF1bits
_INDF1
	res	1
UD_abs_8132_1a2	udata_ovr	0x01a2
_INDF2bits
_INDF2
	res	1
UD_abs_8132_1a3	udata_ovr	0x01a3
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_8132_1a4	udata_ovr	0x01a4
_FSR0bits
_FSR
_FSR0
	res	1
UD_abs_8132_1a5	udata_ovr	0x01a5
_FSR1bits
_FSR1
	res	1
UD_abs_8132_1a6	udata_ovr	0x01a6
_PCLbits
_PCL
	res	1
UD_abs_8132_1a7	udata_ovr	0x01a7
_STATUSbits
_STATUS
_PFLAG
	res	1
UD_abs_8132_1a8	udata_ovr	0x01a8
_MCRbits
_MCR
	res	1
UD_abs_8132_1a9	udata_ovr	0x01a9
_INDF3bits
_INDF3
	res	1
UD_abs_8132_1aa	udata_ovr	0x01aa
_INTEbits
_INTE
	res	1
UD_abs_8132_1ab	udata_ovr	0x01ab
_INTFbits
_INTF
	res	1
UD_abs_8132_1ac	udata_ovr	0x01ac
_OSCMbits
_OSCM
	res	1
UD_abs_8132_1ad	udata_ovr	0x01ad
_CLKObits
_CLKO
	res	1
UD_abs_8132_1b0	udata_ovr	0x01b0
_IOP0bits
_IOP0
	res	1
UD_abs_8132_1b1	udata_ovr	0x01b1
_OEP0bits
_OEP0
	res	1
UD_abs_8132_1b2	udata_ovr	0x01b2
_PUP0bits
_PUP0
	res	1
UD_abs_8132_1b3	udata_ovr	0x01b3
_PDP0bits
_PDP0
	res	1
UD_abs_8132_1b4	udata_ovr	0x01b4
_IOP1bits
_IOP1
	res	1
UD_abs_8132_1b5	udata_ovr	0x01b5
_OEP1bits
_OEP1
	res	1
UD_abs_8132_1b6	udata_ovr	0x01b6
_PUP1bits
_PUP1
	res	1
UD_abs_8132_1b7	udata_ovr	0x01b7
_PDP1bits
_PDP1
	res	1
UD_abs_8132_1b8	udata_ovr	0x01b8
_IOP2bits
_IOP2
	res	1
UD_abs_8132_1b9	udata_ovr	0x01b9
_OEP2bits
_OEP2
	res	1
UD_abs_8132_1ba	udata_ovr	0x01ba
_PUP2bits
_PUP2
	res	1
UD_abs_8132_1bb	udata_ovr	0x01bb
_PDP2bits
_PDP2
	res	1
UD_abs_8132_1bc	udata_ovr	0x01bc
_IOP3bits
_IOP3
	res	1
UD_abs_8132_1bd	udata_ovr	0x01bd
_OEP3bits
_OEP3
	res	1
UD_abs_8132_1be	udata_ovr	0x01be
_PUP3bits
_PUP3
	res	1
UD_abs_8132_1bf	udata_ovr	0x01bf
_PDP3bits
_PDP3
	res	1
UD_abs_8132_1c0	udata_ovr	0x01c0
_T0CRbits
_T0CR
	res	1
UD_abs_8132_1c1	udata_ovr	0x01c1
_T0CNTbits
_T0CNT
	res	1
UD_abs_8132_1c2	udata_ovr	0x01c2
_T0LOADbits
_T0LOAD
	res	1
UD_abs_8132_1c3	udata_ovr	0x01c3
_T0DATAbits
_T0DATA
	res	1
UD_abs_8132_1c4	udata_ovr	0x01c4
_T1CRbits
_T1CR
	res	1
UD_abs_8132_1c5	udata_ovr	0x01c5
_T1CNTbits
_T1CNT
	res	1
UD_abs_8132_1c6	udata_ovr	0x01c6
_T1LOADbits
_T1LOAD
	res	1
UD_abs_8132_1c7	udata_ovr	0x01c7
_T1DATAbits
_T1DATA
	res	1
UD_abs_8132_1c8	udata_ovr	0x01c8
_T2CRbits
_T2CR
	res	1
UD_abs_8132_1c9	udata_ovr	0x01c9
_T2CNTHbits
_T2CNTH
	res	1
UD_abs_8132_1ca	udata_ovr	0x01ca
_T2CNTLbits
_T2CNTL
	res	1
UD_abs_8132_1cb	udata_ovr	0x01cb
_T2LOADHbits
_T2LOADH
	res	1
UD_abs_8132_1cc	udata_ovr	0x01cc
_T2LOADLbits
_T2LOADL
	res	1
UD_abs_8132_1d0	udata_ovr	0x01d0
_TK0CR0bits
_TK0CR0
	res	1
UD_abs_8132_1d1	udata_ovr	0x01d1
_TK0CR1bits
_TK0CR1
	res	1
UD_abs_8132_1d2	udata_ovr	0x01d2
_TK0CR2bits
_TK0CR2
	res	1
UD_abs_8132_1d3	udata_ovr	0x01d3
_TK0CNTHbits
_TK0CNTH
	res	1
UD_abs_8132_1d4	udata_ovr	0x01d4
_TK0CNTLbits
_TK0CNTL
	res	1
UD_abs_8132_1d8	udata_ovr	0x01d8
_TK1CR0bits
_TK1CR0
	res	1
UD_abs_8132_1d9	udata_ovr	0x01d9
_TK1CR1bits
_TK1CR1
	res	1
UD_abs_8132_1da	udata_ovr	0x01da
_TK1CR2bits
_TK1CR2
	res	1
UD_abs_8132_1db	udata_ovr	0x01db
_TK1CNTHbits
_TK1CNTH
	res	1
UD_abs_8132_1dc	udata_ovr	0x01dc
_TK1CNTLbits
_TK1CNTL
	res	1
UD_abs_8132_1e0	udata_ovr	0x01e0
_ADCR0bits
_ADCR0
	res	1
UD_abs_8132_1e1	udata_ovr	0x01e1
_ADCR1bits
_ADCR1
	res	1
UD_abs_8132_1e2	udata_ovr	0x01e2
_ADCR2bits
_ADCR2
	res	1
UD_abs_8132_1e3	udata_ovr	0x01e3
_ADIO0bits
_ADIO0
	res	1
UD_abs_8132_1e4	udata_ovr	0x01e4
_ADIO1bits
_ADIO1
	res	1
UD_abs_8132_1e5	udata_ovr	0x01e5
_ADRHbits
_ADRH
	res	1
UD_abs_8132_1e6	udata_ovr	0x01e6
_ADRLbits
_ADRL
	res	1
UD_abs_8132_1e8	udata_ovr	0x01e8
_LEDDS1
	res	1
UD_abs_8132_1e9	udata_ovr	0x01e9
_LEDDS2
	res	1
UD_abs_8132_1ea	udata_ovr	0x01ea
_LEDDS3
	res	1
UD_abs_8132_1eb	udata_ovr	0x01eb
_LEDDS4
	res	1
UD_abs_8132_1ec	udata_ovr	0x01ec
_LEDDS5
	res	1
UD_abs_8132_1ed	udata_ovr	0x01ed
_LEDDS6
	res	1
UD_abs_8132_1ee	udata_ovr	0x01ee
_LEDDS7
	res	1
UD_abs_8132_1ef	udata_ovr	0x01ef
_LEDDS8
	res	1
UD_abs_8132_1f0	udata_ovr	0x01f0
_LEDCR0bits
_LEDCR0
	res	1
UD_abs_8132_1f1	udata_ovr	0x01f1
_LEDCR1bits
_LEDCR1
	res	1
UD_abs_8132_1f2	udata_ovr	0x01f2
_LEDIOS0bits
_LEDIOS0
	res	1
UD_abs_8132_1f3	udata_ovr	0x01f3
_LEDIOS1bits
_LEDIOS1
	res	1
UD_abs_8132_1f4	udata_ovr	0x01f4
_LEDDRVbits
_LEDDRV
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
code_8132	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
