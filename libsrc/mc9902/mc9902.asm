;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Wed May 31 15:52:39 2017
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc9902.c"
	list	p=9902
	radix dec
	include "9902.inc"
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
	global	_PFLAGbits
	global	_MCRbits
	global	_INDF3bits
	global	_INTEbits
	global	_INTFbits
	global	_OSCMbits
	global	_LVDCRbits
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_RUPSELbits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_T0CRbits
	global	_T0CNTbits
	global	_T0LOADbits
	global	_T0DATAbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T1DATAbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_ADRHbits
	global	_ADRMbits
	global	_IICCRbits
	global	_IICARbits
	global	_IICDRbits
	global	_INDF
	global	_INDF0
	global	_INDF1
	global	_INDF2
	global	_HIBYTE
	global	_FSR
	global	_FSR0
	global	_FSR1
	global	_PCL
	global	_PFLAG
	global	_MCR
	global	_INDF3
	global	_INTE
	global	_INTF
	global	_OSCM
	global	_LVDCR
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_RUPSEL
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_ADCR0
	global	_ADCR1
	global	_ADCR2
	global	_ADRH
	global	_ADRM
	global	_ADRL
	global	_IICCR
	global	_IICAR
	global	_IICDR

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc9902_180	udata_ovr	0x0180
_INDF0bits
_INDF
_INDF0
	res	1
UD_abs_mc9902_181	udata_ovr	0x0181
_INDF1bits
_INDF1
	res	1
UD_abs_mc9902_182	udata_ovr	0x0182
_INDF2bits
_INDF2
	res	1
UD_abs_mc9902_183	udata_ovr	0x0183
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc9902_184	udata_ovr	0x0184
_FSR0bits
_FSR
_FSR0
	res	1
UD_abs_mc9902_185	udata_ovr	0x0185
_FSR1bits
_FSR1
	res	1
UD_abs_mc9902_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc9902_187	udata_ovr	0x0187
_PFLAGbits
_PFLAG
	res	1
UD_abs_mc9902_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc9902_189	udata_ovr	0x0189
_INDF3bits
_INDF3
	res	1
UD_abs_mc9902_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc9902_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc9902_18c	udata_ovr	0x018c
_OSCMbits
_OSCM
	res	1
UD_abs_mc9902_18d	udata_ovr	0x018d
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc9902_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc9902_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc9902_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc9902_193	udata_ovr	0x0193
_RUPSELbits
_RUPSEL
	res	1
UD_abs_mc9902_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc9902_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc9902_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc9902_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc9902_1a1	udata_ovr	0x01a1
_T0CNTbits
_T0CNT
	res	1
UD_abs_mc9902_1a2	udata_ovr	0x01a2
_T0LOADbits
_T0LOAD
	res	1
UD_abs_mc9902_1a3	udata_ovr	0x01a3
_T0DATAbits
_T0DATA
	res	1
UD_abs_mc9902_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_mc9902_1a5	udata_ovr	0x01a5
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc9902_1a6	udata_ovr	0x01a6
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc9902_1a7	udata_ovr	0x01a7
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc9902_1b0	udata_ovr	0x01b0
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc9902_1b1	udata_ovr	0x01b1
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc9902_1b2	udata_ovr	0x01b2
_ADCR2bits
_ADCR2
	res	1
UD_abs_mc9902_1b4	udata_ovr	0x01b4
_ADRHbits
_ADRH
	res	1
UD_abs_mc9902_1b5	udata_ovr	0x01b5
_ADRMbits
_ADRM
	res	1
UD_abs_mc9902_1b6	udata_ovr	0x01b6
_ADRL
	res	1
UD_abs_mc9902_1b8	udata_ovr	0x01b8
_IICCRbits
_IICCR
	res	1
UD_abs_mc9902_1b9	udata_ovr	0x01b9
_IICARbits
_IICAR
	res	1
UD_abs_mc9902_1ba	udata_ovr	0x01ba
_IICDRbits
_IICDR
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
code_mc9902	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
