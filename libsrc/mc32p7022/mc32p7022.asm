;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:36:16 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p7022.c"
	list	p=32p7022
	radix dec
	include "mc32p7022.inc"
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
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_PDP0bits
	global	_KBCRbits
	global	_T0CR0bits
	global	_T0CNTbits
	global	_T0LOADbits
	global	_T00DATAbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T1DATAbits
	global	_T0CR1bits
	global	_T01DATAbits
	global	_LXTCRbits
	global	_LVDCRbits
	global	_OSCMbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_ADIOSbits
	global	_ADRHbits
	global	_ADRLbits
	global	_KEYCR0bits
	global	_KEYCR1bits
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
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_PDP0
	global	_KBCR
	global	_T0CR0
	global	_T0CNT
	global	_T0LOAD
	global	_T00DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_T0CR1
	global	_T01DATA
	global	_LXTCR
	global	_LVDCR
	global	_OSCM
	global	_ADCR0
	global	_ADCR1
	global	_ADCR2
	global	_ADIOS
	global	_ADRH
	global	_ADRL
	global	_KEYCR0
	global	_KEYCR1
	global	_OSCAL

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p7022_180	udata_ovr	0x0180
_INDF0bits
_INDF
_INDF0
	res	1
UD_abs_mc32p7022_181	udata_ovr	0x0181
_INDF1bits
_INDF1
	res	1
UD_abs_mc32p7022_182	udata_ovr	0x0182
_INDF2bits
_INDF2
	res	1
UD_abs_mc32p7022_183	udata_ovr	0x0183
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc32p7022_184	udata_ovr	0x0184
_FSR0bits
_FSR
_FSR0
	res	1
UD_abs_mc32p7022_185	udata_ovr	0x0185
_FSR1bits
_FSR1
	res	1
UD_abs_mc32p7022_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc32p7022_187	udata_ovr	0x0187
_STATUSbits
_STATUS
	res	1
UD_abs_mc32p7022_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc32p7022_189	udata_ovr	0x0189
_INDF3bits
_INDF3
	res	1
UD_abs_mc32p7022_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc32p7022_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc32p7022_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p7022_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p7022_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p7022_193	udata_ovr	0x0193
_PDP0bits
_PDP0
	res	1
UD_abs_mc32p7022_197	udata_ovr	0x0197
_KBCRbits
_KBCR
	res	1
UD_abs_mc32p7022_1a0	udata_ovr	0x01a0
_T0CR0bits
_T0CR0
	res	1
UD_abs_mc32p7022_1a1	udata_ovr	0x01a1
_T0CNTbits
_T0CNT
	res	1
UD_abs_mc32p7022_1a2	udata_ovr	0x01a2
_T0LOADbits
_T0LOAD
	res	1
UD_abs_mc32p7022_1a3	udata_ovr	0x01a3
_T00DATAbits
_T00DATA
	res	1
UD_abs_mc32p7022_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p7022_1a5	udata_ovr	0x01a5
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc32p7022_1a6	udata_ovr	0x01a6
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc32p7022_1a7	udata_ovr	0x01a7
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc32p7022_1a8	udata_ovr	0x01a8
_T0CR1bits
_T0CR1
	res	1
UD_abs_mc32p7022_1a9	udata_ovr	0x01a9
_T01DATAbits
_T01DATA
	res	1
UD_abs_mc32p7022_1ac	udata_ovr	0x01ac
_LXTCRbits
_LXTCR
	res	1
UD_abs_mc32p7022_1ad	udata_ovr	0x01ad
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc32p7022_1ae	udata_ovr	0x01ae
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p7022_1b0	udata_ovr	0x01b0
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32p7022_1b1	udata_ovr	0x01b1
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32p7022_1b2	udata_ovr	0x01b2
_ADCR2bits
_ADCR2
	res	1
UD_abs_mc32p7022_1b3	udata_ovr	0x01b3
_ADIOSbits
_ADIOS
	res	1
UD_abs_mc32p7022_1b8	udata_ovr	0x01b8
_ADRHbits
_ADRH
	res	1
UD_abs_mc32p7022_1b9	udata_ovr	0x01b9
_ADRLbits
_ADRL
	res	1
UD_abs_mc32p7022_1bc	udata_ovr	0x01bc
_KEYCR0bits
_KEYCR0
	res	1
UD_abs_mc32p7022_1bd	udata_ovr	0x01bd
_KEYCR1bits
_KEYCR1
	res	1
UD_abs_mc32p7022_1fb	udata_ovr	0x01fb
_OSCAL
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
code_mc32p7022	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
