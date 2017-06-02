;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Mon May 15 15:28:52 2017
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc9904.c"
	list	p=9904
	radix dec
	include "9904.inc"
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
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_IOP2bits
	global	_OEP2bits
	global	_PUP2bits
	global	_T0CRbits
	global	_T1CRbits
	global	_IICCRbits
	global	_IICSRbits
	global	_EECRbits
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
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_IOP2
	global	_OEP2
	global	_PUP2
	global	_T0CR
	global	_T0CNT
	global	_T0LOAD
	global	_T0DATA
	global	_T1CR
	global	_T1CNTH
	global	_T1CNTL
	global	_T1LOADH
	global	_T1LOADL
	global	_T1DATAH
	global	_T1DATAL
	global	_IICCR
	global	_IICSR
	global	_IICDR
	global	_EECR
	global	_EEMASK
	global	_EEAR
	global	_EEDR
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
UD_abs_mc9904_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_mc9904_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_mc9904_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_mc9904_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_mc9904_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_mc9904_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_mc9904_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc9904_187	udata_ovr	0x0187
_PFLAGbits
_STATUS
_PFLAG
	res	1
UD_abs_mc9904_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc9904_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_mc9904_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc9904_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc9904_18c	udata_ovr	0x018c
_OSCMbits
_OSCM
	res	1
UD_abs_mc9904_18f	udata_ovr	0x018f
_KBCR
	res	1
UD_abs_mc9904_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc9904_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc9904_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc9904_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc9904_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc9904_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc9904_198	udata_ovr	0x0198
_IOP2bits
_IOP2
	res	1
UD_abs_mc9904_199	udata_ovr	0x0199
_OEP2bits
_OEP2
	res	1
UD_abs_mc9904_19a	udata_ovr	0x019a
_PUP2bits
_PUP2
	res	1
UD_abs_mc9904_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc9904_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_mc9904_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_mc9904_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_mc9904_1a8	udata_ovr	0x01a8
_T1CRbits
_T1CR
	res	1
UD_abs_mc9904_1a9	udata_ovr	0x01a9
_T1CNTH
	res	1
UD_abs_mc9904_1aa	udata_ovr	0x01aa
_T1CNTL
	res	1
UD_abs_mc9904_1ab	udata_ovr	0x01ab
_T1LOADH
	res	1
UD_abs_mc9904_1ac	udata_ovr	0x01ac
_T1LOADL
	res	1
UD_abs_mc9904_1ad	udata_ovr	0x01ad
_T1DATAH
	res	1
UD_abs_mc9904_1ae	udata_ovr	0x01ae
_T1DATAL
	res	1
UD_abs_mc9904_1b0	udata_ovr	0x01b0
_IICCRbits
_IICCR
	res	1
UD_abs_mc9904_1b1	udata_ovr	0x01b1
_IICSRbits
_IICSR
	res	1
UD_abs_mc9904_1b2	udata_ovr	0x01b2
_IICDR
	res	1
UD_abs_mc9904_1b4	udata_ovr	0x01b4
_EECRbits
_EECR
	res	1
UD_abs_mc9904_1b5	udata_ovr	0x01b5
_EEMASK
	res	1
UD_abs_mc9904_1b6	udata_ovr	0x01b6
_EEAR
	res	1
UD_abs_mc9904_1b7	udata_ovr	0x01b7
_EEDR
	res	1
UD_abs_mc9904_1b8	udata_ovr	0x01b8
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc9904_1b9	udata_ovr	0x01b9
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc9904_1ba	udata_ovr	0x01ba
_ADRH
	res	1
UD_abs_mc9904_1bb	udata_ovr	0x01bb
_ADRL
	res	1
UD_abs_mc9904_1bc	udata_ovr	0x01bc
_ADIOS0bits
_ADIOS0
	res	1
UD_abs_mc9904_1bd	udata_ovr	0x01bd
_ADIOS1bits
_ADIOS1
	res	1
UD_abs_mc9904_1be	udata_ovr	0x01be
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
code_mc9904	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
