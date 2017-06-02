;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Thu Apr 27 10:00:40 2017
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc32f7122.c"
	list	p=7122
	radix dec
	include "7122.inc"
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
	global	_INTE1bits
	global	_INTF1bits
	global	_LCDCRbits
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
	global	_T0EFRbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_T1LOADbits
	global	_T2CRbits
	global	_T2CNTbits
	global	_T2LOADbits
	global	_T2EFRbits
	global	_T3CRbits
	global	_T3CNTbits
	global	_T3LOADbits
	global	_IICCRbits
	global	_IICARbits
	global	_EECRbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADIOS0bits
	global	_ADIOS1bits
	global	_OSADJCRbits
	global	_PPGCRbits
	global	_PPGLOADbits
	global	_PPGTDLbits
	global	_PPGTDBbits
	global	_OPACRbits
	global	_OPACLRbits
	global	_CPCRbits
	global	_CPSRbits
	global	_CPVR0bits
	global	_CPVR1bits
	global	_CP0CLRbits
	global	_CP1CLRbits
	global	_CP2CLRbits
	global	_CP3CLRbits
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
	global	_INTE1
	global	_INTF1
	global	_LCDCR
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
	global	_T0EFR
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T2CR
	global	_T2CNT
	global	_T2LOAD
	global	_T2EFR
	global	_T3CR
	global	_T3CNT
	global	_T3LOAD
	global	_IICCR
	global	_IICAR
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
	global	_PPGCR
	global	_PPGLOAD
	global	_PPGTDL
	global	_PPGTDB
	global	_OPACR
	global	_OPACLR
	global	_CPCR
	global	_CPSR
	global	_CPVR0
	global	_CPVR1
	global	_CP0CLR
	global	_CP1CLR
	global	_CP2CLR
	global	_CP3CLR

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32f7122_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_mc32f7122_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_mc32f7122_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_mc32f7122_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_mc32f7122_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_mc32f7122_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_mc32f7122_186	udata_ovr	0x0186
_PCLbits
_PCL
	res	1
UD_abs_mc32f7122_187	udata_ovr	0x0187
_PFLAGbits
_STATUS
_PFLAG
	res	1
UD_abs_mc32f7122_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_mc32f7122_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_mc32f7122_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_mc32f7122_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_mc32f7122_18c	udata_ovr	0x018c
_OSCMbits
_OSCM
	res	1
UD_abs_mc32f7122_18d	udata_ovr	0x018d
_INTE1bits
_INTE1
	res	1
UD_abs_mc32f7122_18e	udata_ovr	0x018e
_INTF1bits
_INTF1
	res	1
UD_abs_mc32f7122_18f	udata_ovr	0x018f
_LCDCRbits
_LCDCR
	res	1
UD_abs_mc32f7122_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_mc32f7122_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_mc32f7122_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_mc32f7122_193	udata_ovr	0x0193
_PDP0bits
_PDP0
	res	1
UD_abs_mc32f7122_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_mc32f7122_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_mc32f7122_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_mc32f7122_197	udata_ovr	0x0197
_PDP1bits
_PDP1
	res	1
UD_abs_mc32f7122_198	udata_ovr	0x0198
_IOP2bits
_IOP2
	res	1
UD_abs_mc32f7122_199	udata_ovr	0x0199
_OEP2bits
_OEP2
	res	1
UD_abs_mc32f7122_19a	udata_ovr	0x019a
_PUP2bits
_PUP2
	res	1
UD_abs_mc32f7122_19b	udata_ovr	0x019b
_PDP2bits
_PDP2
	res	1
UD_abs_mc32f7122_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_mc32f7122_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_mc32f7122_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_mc32f7122_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_mc32f7122_1a4	udata_ovr	0x01a4
_T0EFRbits
_T0EFR
	res	1
UD_abs_mc32f7122_1a5	udata_ovr	0x01a5
_T1CRbits
_T1CR
	res	1
UD_abs_mc32f7122_1a6	udata_ovr	0x01a6
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc32f7122_1a7	udata_ovr	0x01a7
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc32f7122_1a8	udata_ovr	0x01a8
_T2CRbits
_T2CR
	res	1
UD_abs_mc32f7122_1a9	udata_ovr	0x01a9
_T2CNTbits
_T2CNT
	res	1
UD_abs_mc32f7122_1aa	udata_ovr	0x01aa
_T2LOADbits
_T2LOAD
	res	1
UD_abs_mc32f7122_1ac	udata_ovr	0x01ac
_T2EFRbits
_T2EFR
	res	1
UD_abs_mc32f7122_1ad	udata_ovr	0x01ad
_T3CRbits
_T3CR
	res	1
UD_abs_mc32f7122_1ae	udata_ovr	0x01ae
_T3CNTbits
_T3CNT
	res	1
UD_abs_mc32f7122_1af	udata_ovr	0x01af
_T3LOADbits
_T3LOAD
	res	1
UD_abs_mc32f7122_1b0	udata_ovr	0x01b0
_IICCRbits
_IICCR
	res	1
UD_abs_mc32f7122_1b1	udata_ovr	0x01b1
_IICARbits
_IICAR
	res	1
UD_abs_mc32f7122_1b2	udata_ovr	0x01b2
_IICDR
	res	1
UD_abs_mc32f7122_1b4	udata_ovr	0x01b4
_EECRbits
_EECR
	res	1
UD_abs_mc32f7122_1b5	udata_ovr	0x01b5
_EEMASK
	res	1
UD_abs_mc32f7122_1b6	udata_ovr	0x01b6
_EEAR
	res	1
UD_abs_mc32f7122_1b7	udata_ovr	0x01b7
_EEDR
	res	1
UD_abs_mc32f7122_1b8	udata_ovr	0x01b8
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32f7122_1b9	udata_ovr	0x01b9
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32f7122_1ba	udata_ovr	0x01ba
_ADRH
	res	1
UD_abs_mc32f7122_1bb	udata_ovr	0x01bb
_ADRL
	res	1
UD_abs_mc32f7122_1bc	udata_ovr	0x01bc
_ADIOS0bits
_ADIOS0
	res	1
UD_abs_mc32f7122_1bd	udata_ovr	0x01bd
_ADIOS1bits
_ADIOS1
	res	1
UD_abs_mc32f7122_1be	udata_ovr	0x01be
_OSADJCRbits
_OSADJCR
	res	1
UD_abs_mc32f7122_1c0	udata_ovr	0x01c0
_PPGCRbits
_PPGCR
	res	1
UD_abs_mc32f7122_1c1	udata_ovr	0x01c1
_PPGLOADbits
_PPGLOAD
	res	1
UD_abs_mc32f7122_1c2	udata_ovr	0x01c2
_PPGTDLbits
_PPGTDL
	res	1
UD_abs_mc32f7122_1c3	udata_ovr	0x01c3
_PPGTDBbits
_PPGTDB
	res	1
UD_abs_mc32f7122_1c4	udata_ovr	0x01c4
_OPACRbits
_OPACR
	res	1
UD_abs_mc32f7122_1c5	udata_ovr	0x01c5
_OPACLRbits
_OPACLR
	res	1
UD_abs_mc32f7122_1c8	udata_ovr	0x01c8
_CPCRbits
_CPCR
	res	1
UD_abs_mc32f7122_1c9	udata_ovr	0x01c9
_CPSRbits
_CPSR
	res	1
UD_abs_mc32f7122_1ca	udata_ovr	0x01ca
_CPVR0bits
_CPVR0
	res	1
UD_abs_mc32f7122_1cb	udata_ovr	0x01cb
_CPVR1bits
_CPVR1
	res	1
UD_abs_mc32f7122_1cc	udata_ovr	0x01cc
_CP0CLRbits
_CP0CLR
	res	1
UD_abs_mc32f7122_1cd	udata_ovr	0x01cd
_CP1CLRbits
_CP1CLR
	res	1
UD_abs_mc32f7122_1ce	udata_ovr	0x01ce
_CP2CLRbits
_CP2CLR
	res	1
UD_abs_mc32f7122_1cf	udata_ovr	0x01cf
_CP3CLRbits
_CP3CLR
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
code_mc32f7122	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
