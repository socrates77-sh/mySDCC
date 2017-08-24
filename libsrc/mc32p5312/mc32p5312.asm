;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:35:30 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p5312.c"
	list	p=32p5312
	radix dec
	include "mc32p5312.inc"
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
	global	_LVDCRbits
	global	_LXTCRbits
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_DKWP0bits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_DKWP1bits
	global	_T0CRbits
	global	_T0CNTbits
	global	_T0LOADbits
	global	_T0DATAbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T1DATAbits
	global	_LCDCR0bits
	global	_LCDCR1bits
	global	_LCDSP0bits
	global	_LCDSP1bits
	global	_DKWbits
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
	global	_LVDCR
	global	_LXTCR
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_DKWP0
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_DKWP1
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_LCDCR0
	global	_LCDCR1
	global	_LCDSP0
	global	_LCDSP1
	global	_DKW

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p5312_1b0	udata_ovr	0x01b0
_INDF0bits
_INDF
_INDF0
	res	1
UD_abs_mc32p5312_1b1	udata_ovr	0x01b1
_INDF1bits
_INDF1
	res	1
UD_abs_mc32p5312_1b2	udata_ovr	0x01b2
_INDF2bits
_INDF2
	res	1
UD_abs_mc32p5312_1b3	udata_ovr	0x01b3
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc32p5312_1b4	udata_ovr	0x01b4
_FSR0bits
_FSR
_FSR0
	res	1
UD_abs_mc32p5312_1b5	udata_ovr	0x01b5
_FSR1bits
_FSR1
	res	1
UD_abs_mc32p5312_1b6	udata_ovr	0x01b6
_PCLbits
_PCL
	res	1
UD_abs_mc32p5312_1b7	udata_ovr	0x01b7
_STATUSbits
_STATUS
	res	1
UD_abs_mc32p5312_1b8	udata_ovr	0x01b8
_MCRbits
_MCR
	res	1
UD_abs_mc32p5312_1b9	udata_ovr	0x01b9
_INDF3bits
_INDF3
	res	1
UD_abs_mc32p5312_1ba	udata_ovr	0x01ba
_INTEbits
_INTE
	res	1
UD_abs_mc32p5312_1bb	udata_ovr	0x01bb
_INTFbits
_INTF
	res	1
UD_abs_mc32p5312_1bc	udata_ovr	0x01bc
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p5312_1bd	udata_ovr	0x01bd
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc32p5312_1be	udata_ovr	0x01be
_LXTCRbits
_LXTCR
	res	1
UD_abs_mc32p5312_1c0	udata_ovr	0x01c0
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p5312_1c1	udata_ovr	0x01c1
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p5312_1c2	udata_ovr	0x01c2
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p5312_1c3	udata_ovr	0x01c3
_DKWP0bits
_DKWP0
	res	1
UD_abs_mc32p5312_1c4	udata_ovr	0x01c4
_IOP1bits
_IOP1
	res	1
UD_abs_mc32p5312_1c5	udata_ovr	0x01c5
_OEP1bits
_OEP1
	res	1
UD_abs_mc32p5312_1c6	udata_ovr	0x01c6
_PUP1bits
_PUP1
	res	1
UD_abs_mc32p5312_1c7	udata_ovr	0x01c7
_DKWP1bits
_DKWP1
	res	1
UD_abs_mc32p5312_1c8	udata_ovr	0x01c8
_T0CRbits
_T0CR
	res	1
UD_abs_mc32p5312_1c9	udata_ovr	0x01c9
_T0CNTbits
_T0CNT
	res	1
UD_abs_mc32p5312_1ca	udata_ovr	0x01ca
_T0LOADbits
_T0LOAD
	res	1
UD_abs_mc32p5312_1cb	udata_ovr	0x01cb
_T0DATAbits
_T0DATA
	res	1
UD_abs_mc32p5312_1cc	udata_ovr	0x01cc
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p5312_1cd	udata_ovr	0x01cd
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc32p5312_1ce	udata_ovr	0x01ce
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc32p5312_1cf	udata_ovr	0x01cf
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc32p5312_1d0	udata_ovr	0x01d0
_LCDCR0bits
_LCDCR0
	res	1
UD_abs_mc32p5312_1d1	udata_ovr	0x01d1
_LCDCR1bits
_LCDCR1
	res	1
UD_abs_mc32p5312_1d2	udata_ovr	0x01d2
_LCDSP0bits
_LCDSP0
	res	1
UD_abs_mc32p5312_1d3	udata_ovr	0x01d3
_LCDSP1bits
_LCDSP1
	res	1
UD_abs_mc32p5312_1d4	udata_ovr	0x01d4
_DKWbits
_DKW
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
code_mc32p5312	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
