;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Wed Dec  9 21:31:47 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"3221.c"
	list	p=3221
	radix dec
	include "3221.inc"
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
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_ANSELbits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_KBIMbits
	global	_T0CRbits
	global	_T1CRbits
	global	_LVDCRbits
	global	_OSCMbits
	global	_ADCR0bits
	global	_ADCR1bits
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
	global	_ANSEL
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_KBIM
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_LVDCR
	global	_OSCM
	global	_ADCR0
	global	_ADCR1
	global	_ADRH
	global	_ADRL
	global	_OSCAL

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_3221_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_3221_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_3221_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_3221_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_3221_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_3221_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_3221_186	udata_ovr	0x0186
_PCL
	res	1
UD_abs_3221_187	udata_ovr	0x0187
_STATUSbits
_STATUS
	res	1
UD_abs_3221_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_3221_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_3221_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_3221_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_3221_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_3221_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_3221_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_3221_193	udata_ovr	0x0193
_ANSELbits
_ANSEL
	res	1
UD_abs_3221_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_3221_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_3221_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_3221_197	udata_ovr	0x0197
_KBIMbits
_KBIM
	res	1
UD_abs_3221_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_3221_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_3221_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_3221_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_3221_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_3221_1a5	udata_ovr	0x01a5
_T1CNT
	res	1
UD_abs_3221_1a6	udata_ovr	0x01a6
_T1LOAD
	res	1
UD_abs_3221_1a7	udata_ovr	0x01a7
_T1DATA
	res	1
UD_abs_3221_1ae	udata_ovr	0x01ae
_OSCMbits
_OSCM
	res	1
UD_abs_3221_1af	udata_ovr	0x01af
_LVDCRbits
_LVDCR
	res	1
UD_abs_3221_1b0	udata_ovr	0x01b0
_ADCR0bits
_ADCR0
	res	1
UD_abs_3221_1b1	udata_ovr	0x01b1
_ADCR1bits
_ADCR1
	res	1
UD_abs_3221_1b4	udata_ovr	0x01b4
_ADRH
	res	1
UD_abs_3221_1b5	udata_ovr	0x01b5
_ADRL
	res	1
UD_abs_3221_1fb	udata_ovr	0x01fb
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
code_3221	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
