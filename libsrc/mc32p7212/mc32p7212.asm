;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Tue Mar 21 16:52:42 2017
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p7212.c"
	list	p=7212
	radix dec
	include "7212.inc"
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
	global	_PFLAGbits
	global	_MCRbits
	global	_INTEbits
	global	_INTFbits
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
	global	_LXTCRbits
	global	_PUMPbits
	global	_OSCMbits
	global	_LVDCRbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_TPSCbits
	global	_LCDCR0bits
	global	_LCDCR1bits
	global	_LCDIOS2bits
	global	_LCDDS2bits
	global	_LCDDS3bits
	global	_LCDDS4bits
	global	_LCDDS5bits
	global	_LCDDS6bits
	global	_LCDDS7bits
	global	_LCDDS8bits
	global	_LCDDS9bits
	global	_LCDDS10bits
	global	_LCDDS11bits
	global	_LCDDS12bits
	global	_LCDDS13bits
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
	global	_LXTCR
	global	_PUMP
	global	_OSCM
	global	_LVDCR
	global	_ADCR0
	global	_ADCR1
	global	_ADCR2
	global	_TPSC
	global	_ADRH
	global	_ADRM
	global	_ADRL
	global	_LCDCR0
	global	_LCDCR1
	global	_LCDIOS1
	global	_LCDIOS2
	global	_LCDDS2
	global	_LCDDS3
	global	_LCDDS4
	global	_LCDDS5
	global	_LCDDS6
	global	_LCDDS7
	global	_LCDDS8
	global	_LCDDS9
	global	_LCDDS10
	global	_LCDDS11
	global	_LCDDS12
	global	_LCDDS13

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p7212_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_mc32p7212_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_mc32p7212_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_mc32p7212_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_mc32p7212_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_mc32p7212_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_mc32p7212_186	udata_ovr	0x0186
_PCL
	res	1
UD_abs_mc32p7212_187	udata_ovr	0x0187
_PFLAGbits
_STATUS
_PFLAG
	res	1
UD_abs_mc32p7212_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc32p7212_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_mc32p7212_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc32p7212_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc32p7212_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p7212_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p7212_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p7212_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc32p7212_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc32p7212_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc32p7212_198	udata_ovr	0x0198
_IOP2bits
_IOP2
	res	1
UD_abs_mc32p7212_199	udata_ovr	0x0199
_OEP2bits
_OEP2
	res	1
UD_abs_mc32p7212_19a	udata_ovr	0x019a
_PUP2bits
_PUP2
	res	1
UD_abs_mc32p7212_19c	udata_ovr	0x019c
_IOP3bits
_IOP3
	res	1
UD_abs_mc32p7212_19d	udata_ovr	0x019d
_OEP3bits
_OEP3
	res	1
UD_abs_mc32p7212_19e	udata_ovr	0x019e
_PUP3bits
_PUP3
	res	1
UD_abs_mc32p7212_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc32p7212_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_mc32p7212_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_mc32p7212_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_mc32p7212_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p7212_1a5	udata_ovr	0x01a5
_T1CNT
	res	1
UD_abs_mc32p7212_1a6	udata_ovr	0x01a6
_T1LOAD
	res	1
UD_abs_mc32p7212_1a7	udata_ovr	0x01a7
_T1DATA
	res	1
UD_abs_mc32p7212_1a8	udata_ovr	0x01a8
_LXTCRbits
_LXTCR
	res	1
UD_abs_mc32p7212_1ad	udata_ovr	0x01ad
_PUMPbits
_PUMP
	res	1
UD_abs_mc32p7212_1ae	udata_ovr	0x01ae
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p7212_1af	udata_ovr	0x01af
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc32p7212_1b0	udata_ovr	0x01b0
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32p7212_1b1	udata_ovr	0x01b1
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32p7212_1b2	udata_ovr	0x01b2
_ADCR2bits
_ADCR2
	res	1
UD_abs_mc32p7212_1b3	udata_ovr	0x01b3
_TPSCbits
_TPSC
	res	1
UD_abs_mc32p7212_1b4	udata_ovr	0x01b4
_ADRH
	res	1
UD_abs_mc32p7212_1b5	udata_ovr	0x01b5
_ADRM
	res	1
UD_abs_mc32p7212_1b6	udata_ovr	0x01b6
_ADRL
	res	1
UD_abs_mc32p7212_1b8	udata_ovr	0x01b8
_LCDCR0bits
_LCDCR0
	res	1
UD_abs_mc32p7212_1b9	udata_ovr	0x01b9
_LCDCR1bits
_LCDCR1
	res	1
UD_abs_mc32p7212_1ba	udata_ovr	0x01ba
_LCDIOS1
	res	1
UD_abs_mc32p7212_1bb	udata_ovr	0x01bb
_LCDIOS2bits
_LCDIOS2
	res	1
UD_abs_mc32p7212_1c0	udata_ovr	0x01c0
_LCDDS2bits
_LCDDS2
	res	1
UD_abs_mc32p7212_1c1	udata_ovr	0x01c1
_LCDDS3bits
_LCDDS3
	res	1
UD_abs_mc32p7212_1c2	udata_ovr	0x01c2
_LCDDS4bits
_LCDDS4
	res	1
UD_abs_mc32p7212_1c3	udata_ovr	0x01c3
_LCDDS5bits
_LCDDS5
	res	1
UD_abs_mc32p7212_1c4	udata_ovr	0x01c4
_LCDDS6bits
_LCDDS6
	res	1
UD_abs_mc32p7212_1c5	udata_ovr	0x01c5
_LCDDS7bits
_LCDDS7
	res	1
UD_abs_mc32p7212_1c6	udata_ovr	0x01c6
_LCDDS8bits
_LCDDS8
	res	1
UD_abs_mc32p7212_1c7	udata_ovr	0x01c7
_LCDDS9bits
_LCDDS9
	res	1
UD_abs_mc32p7212_1c8	udata_ovr	0x01c8
_LCDDS10bits
_LCDDS10
	res	1
UD_abs_mc32p7212_1c9	udata_ovr	0x01c9
_LCDDS11bits
_LCDDS11
	res	1
UD_abs_mc32p7212_1ca	udata_ovr	0x01ca
_LCDDS12bits
_LCDDS12
	res	1
UD_abs_mc32p7212_1cb	udata_ovr	0x01cb
_LCDDS13bits
_LCDDS13
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
code_mc32p7212	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
