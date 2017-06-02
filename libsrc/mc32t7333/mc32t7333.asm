;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Tue Dec 27 16:04:25 2016
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc32t7333.c"
	list	p=7333
	radix dec
	include "7333.inc"
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
	global	_PCLbits
	global	_PFLAGbits
	global	_MCRbits
	global	_INTEbits
	global	_INTFbits
	global	_OSCMbits
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
	global	_T0CRbits
	global	_T1CRbits
	global	_IICCRbits
	global	_IICSRbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADIOS0bits
	global	_ADIOS1bits
	global	_OSADJCRbits
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
	global	_KBCR
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
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_IICCR
	global	_IICSR
	global	_IICDR
	global	_ADCR0
	global	_ADCR1
	global	_ADRH
	global	_ADRL
	global	_ADIOS0
	global	_ADIOS1
	global	_OSADJCR

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32t7333_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_mc32t7333_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_mc32t7333_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_mc32t7333_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_mc32t7333_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_mc32t7333_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_mc32t7333_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc32t7333_187	udata_ovr	0x0187
_PFLAGbits
_STATUS
_PFLAG
	res	1
UD_abs_mc32t7333_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc32t7333_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_mc32t7333_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc32t7333_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc32t7333_18c	udata_ovr	0x018c
_OSCMbits
_OSCM
	res	1
UD_abs_mc32t7333_18f	udata_ovr	0x018f
_KBCR
	res	1
UD_abs_mc32t7333_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc32t7333_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc32t7333_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc32t7333_193	udata_ovr	0x0193
_PDP0bits
_PDP0
	res	1
UD_abs_mc32t7333_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc32t7333_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc32t7333_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc32t7333_197	udata_ovr	0x0197
_PDP1bits
_PDP1
	res	1
UD_abs_mc32t7333_198	udata_ovr	0x0198
_IOP2bits
_IOP2
	res	1
UD_abs_mc32t7333_199	udata_ovr	0x0199
_OEP2bits
_OEP2
	res	1
UD_abs_mc32t7333_19a	udata_ovr	0x019a
_PUP2bits
_PUP2
	res	1
UD_abs_mc32t7333_19b	udata_ovr	0x019b
_PDP2bits
_PDP2
	res	1
UD_abs_mc32t7333_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc32t7333_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_mc32t7333_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_mc32t7333_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_mc32t7333_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32t7333_1a5	udata_ovr	0x01a5
_T1CNT
	res	1
UD_abs_mc32t7333_1a6	udata_ovr	0x01a6
_T1LOAD
	res	1
UD_abs_mc32t7333_1a7	udata_ovr	0x01a7
_T1DATA
	res	1
UD_abs_mc32t7333_1b0	udata_ovr	0x01b0
_IICCRbits
_IICCR
	res	1
UD_abs_mc32t7333_1b1	udata_ovr	0x01b1
_IICSRbits
_IICSR
	res	1
UD_abs_mc32t7333_1b2	udata_ovr	0x01b2
_IICDR
	res	1
UD_abs_mc32t7333_1b8	udata_ovr	0x01b8
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32t7333_1b9	udata_ovr	0x01b9
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32t7333_1ba	udata_ovr	0x01ba
_ADRH
	res	1
UD_abs_mc32t7333_1bb	udata_ovr	0x01bb
_ADRL
	res	1
UD_abs_mc32t7333_1bc	udata_ovr	0x01bc
_ADIOS0bits
_ADIOS0
	res	1
UD_abs_mc32t7333_1bd	udata_ovr	0x01bd
_ADIOS1bits
_ADIOS1
	res	1
UD_abs_mc32t7333_1be	udata_ovr	0x01be
_OSADJCRbits
_OSADJCR
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
code_mc32t7333	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
