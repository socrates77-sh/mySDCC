;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.0.0 (Sep 28 2017) (MINGW32)
; This file was generated Thu Dec 07 15:58:25 2017
;--------------------------------------------------------
; MC30/MC32 port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p7510.c"
	list	p=7510
	radix dec
	include "7510.inc"
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
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_PDP0bits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_PDP1bits
	global	_T0CRbits
	global	_T0CNTbits
	global	_T0LOADbits
	global	_T0DATAbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T1DATAbits
	global	_AUCRbits
	global	_KBCRbits
	global	_OSCMbits
	global	_LVDCRbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_AN0SELbits
	global	_AN1SELbits
	global	_ADRHbits
	global	_ADRLbits
	global	_OSCCALbits
	global	_INDF0
	global	_INDF1
	global	_INDF2
	global	_HIBYTE
	global	_FSR0
	global	_FSR1
	global	_PCL
	global	_STATUS
	global	_MCR
	global	_INDF3
	global	_INTE0
	global	_INTF0
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_PDP0
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_PDP1
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_AUCR
	global	_KBCR
	global	_OSCM
	global	_LVDCR
	global	_ADCR0
	global	_ADCR1
	global	_AN0SEL
	global	_AN1SEL
	global	_ADRH
	global	_ADRL
	global	_OSCCAL

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p7510_180	udata_ovr	0x0180
_INDF0bits
_INDF0
	res	1
UD_abs_mc32p7510_181	udata_ovr	0x0181
_INDF1bits
_INDF1
	res	1
UD_abs_mc32p7510_182	udata_ovr	0x0182
_INDF2bits
_INDF2
	res	1
UD_abs_mc32p7510_183	udata_ovr	0x0183
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc32p7510_184	udata_ovr	0x0184
_FSR0bits
_FSR0
	res	1
UD_abs_mc32p7510_185	udata_ovr	0x0185
_FSR1bits
_FSR1
	res	1
UD_abs_mc32p7510_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc32p7510_187	udata_ovr	0x0187
_STATUSbits
_STATUS
	res	1
UD_abs_mc32p7510_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc32p7510_189	udata_ovr	0x0189
_INDF3bits
_INDF3
	res	1
UD_abs_mc32p7510_18a	udata_ovr	0x018a
_INTE0
	res	1
UD_abs_mc32p7510_18b	udata_ovr	0x018b
_INTF0
	res	1
UD_abs_mc32p7510_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p7510_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p7510_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p7510_193	udata_ovr	0x0193
_PDP0bits
_PDP0
	res	1
UD_abs_mc32p7510_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc32p7510_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc32p7510_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc32p7510_197	udata_ovr	0x0197
_PDP1bits
_PDP1
	res	1
UD_abs_mc32p7510_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc32p7510_1a1	udata_ovr	0x01a1
_T0CNTbits
_T0CNT
	res	1
UD_abs_mc32p7510_1a2	udata_ovr	0x01a2
_T0LOADbits
_T0LOAD
	res	1
UD_abs_mc32p7510_1a3	udata_ovr	0x01a3
_T0DATAbits
_T0DATA
	res	1
UD_abs_mc32p7510_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p7510_1a5	udata_ovr	0x01a5
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc32p7510_1a6	udata_ovr	0x01a6
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc32p7510_1a7	udata_ovr	0x01a7
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc32p7510_1a8	udata_ovr	0x01a8
_AUCRbits
_AUCR
	res	1
UD_abs_mc32p7510_1a9	udata_ovr	0x01a9
_KBCRbits
_KBCR
	res	1
UD_abs_mc32p7510_1ae	udata_ovr	0x01ae
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p7510_1af	udata_ovr	0x01af
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc32p7510_1b0	udata_ovr	0x01b0
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32p7510_1b1	udata_ovr	0x01b1
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32p7510_1b2	udata_ovr	0x01b2
_AN0SELbits
_AN0SEL
	res	1
UD_abs_mc32p7510_1b3	udata_ovr	0x01b3
_AN1SELbits
_AN1SEL
	res	1
UD_abs_mc32p7510_1b4	udata_ovr	0x01b4
_ADRHbits
_ADRH
	res	1
UD_abs_mc32p7510_1b5	udata_ovr	0x01b5
_ADRLbits
_ADRL
	res	1
UD_abs_mc32p7510_1fb	udata_ovr	0x01fb
_OSCCALbits
_OSCCAL
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
code_mc32p7510	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
