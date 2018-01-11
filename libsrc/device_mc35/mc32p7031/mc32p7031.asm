;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Thu Jan 04 10:24:18 2018
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p7031.c"
	list	p=7011
	radix dec
	include "7011.inc"
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
	global	_HIBYTEbits
	global	_FSR0bits
	global	_FSR1bits
	global	_PFLAGbits
	global	_ANSELbits
	global	_VREFbits
	global	_ADCRbits
	global	_ADRHbits
	global	_ADRLbits
	global	_OEP0bits
	global	_PEDGEbits
	global	_OEP4bits
	global	_OEP5bits
	global	_INTFbits
	global	_INTEbits
	global	_OSCMbits
	global	_WDTRbits
	global	_T0Dbits
	global	_PCLbits
	global	_PCHbits
	global	_IOP0bits
	global	_IOP4bits
	global	_IOP5bits
	global	_TXCRbits
	global	_T0CRbits
	global	_T0Cbits
	global	_T1CRbits
	global	_T1Cbits
	global	_T1Dbits
	global	_STKPbits
	global	_PUP0bits
	global	_PUP4bits
	global	_PUP5bits
	global	_INDFbits
	global	_T2CRbits
	global	_T2Cbits
	global	_T2Dbits
	global	_HIBYTE
	global	_FSR0
	global	_FSR1
	global	_PFLAG
	global	_ANSEL
	global	_VREF
	global	_ADCR
	global	_ADRH
	global	_ADRL
	global	_OEP0
	global	_PEDGE
	global	_OEP4
	global	_OEP5
	global	_INTF
	global	_INTE
	global	_OSCM
	global	_WDTR
	global	_T0D
	global	_PCL
	global	_PCH
	global	_IOP0
	global	_IOP4
	global	_IOP5
	global	_TXCR
	global	_T0CR
	global	_T0C
	global	_T1CR
	global	_T1C
	global	_T1D
	global	_STKP
	global	_PUP0
	global	_PUP4
	global	_PUP5
	global	_INDF
	global	_T2CR
	global	_T2C
	global	_T2D
	global	_STK3L
	global	_STK3H
	global	_STK2L
	global	_STK2H
	global	_STK1L
	global	_STK1H
	global	_STK0L
	global	_STK0H

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p7031_82	udata_ovr	0x0082
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc32p7031_83	udata_ovr	0x0083
_FSR0bits
_FSR0
	res	1
UD_abs_mc32p7031_84	udata_ovr	0x0084
_FSR1bits
_FSR1
	res	1
UD_abs_mc32p7031_86	udata_ovr	0x0086
_PFLAGbits
_PFLAG
	res	1
UD_abs_mc32p7031_ae	udata_ovr	0x00ae
_ANSELbits
_ANSEL
	res	1
UD_abs_mc32p7031_af	udata_ovr	0x00af
_VREFbits
_VREF
	res	1
UD_abs_mc32p7031_b1	udata_ovr	0x00b1
_ADCRbits
_ADCR
	res	1
UD_abs_mc32p7031_b2	udata_ovr	0x00b2
_ADRHbits
_ADRH
	res	1
UD_abs_mc32p7031_b3	udata_ovr	0x00b3
_ADRLbits
_ADRL
	res	1
UD_abs_mc32p7031_b8	udata_ovr	0x00b8
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p7031_bf	udata_ovr	0x00bf
_PEDGEbits
_PEDGE
	res	1
UD_abs_mc32p7031_c4	udata_ovr	0x00c4
_OEP4bits
_OEP4
	res	1
UD_abs_mc32p7031_c5	udata_ovr	0x00c5
_OEP5bits
_OEP5
	res	1
UD_abs_mc32p7031_c8	udata_ovr	0x00c8
_INTFbits
_INTF
	res	1
UD_abs_mc32p7031_c9	udata_ovr	0x00c9
_INTEbits
_INTE
	res	1
UD_abs_mc32p7031_ca	udata_ovr	0x00ca
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p7031_cc	udata_ovr	0x00cc
_WDTRbits
_WDTR
	res	1
UD_abs_mc32p7031_cd	udata_ovr	0x00cd
_T0Dbits
_T0D
	res	1
UD_abs_mc32p7031_ce	udata_ovr	0x00ce
_PCLbits
_PCL
	res	1
UD_abs_mc32p7031_cf	udata_ovr	0x00cf
_PCHbits
_PCH
	res	1
UD_abs_mc32p7031_d0	udata_ovr	0x00d0
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p7031_d4	udata_ovr	0x00d4
_IOP4bits
_IOP4
	res	1
UD_abs_mc32p7031_d5	udata_ovr	0x00d5
_IOP5bits
_IOP5
	res	1
UD_abs_mc32p7031_d8	udata_ovr	0x00d8
_TXCRbits
_TXCR
	res	1
UD_abs_mc32p7031_da	udata_ovr	0x00da
_T0CRbits
_T0CR
	res	1
UD_abs_mc32p7031_db	udata_ovr	0x00db
_T0Cbits
_T0C
	res	1
UD_abs_mc32p7031_dc	udata_ovr	0x00dc
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p7031_dd	udata_ovr	0x00dd
_T1Cbits
_T1C
	res	1
UD_abs_mc32p7031_de	udata_ovr	0x00de
_T1Dbits
_T1D
	res	1
UD_abs_mc32p7031_df	udata_ovr	0x00df
_STKPbits
_STKP
	res	1
UD_abs_mc32p7031_e0	udata_ovr	0x00e0
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p7031_e4	udata_ovr	0x00e4
_PUP4bits
_PUP4
	res	1
UD_abs_mc32p7031_e5	udata_ovr	0x00e5
_PUP5bits
_PUP5
	res	1
UD_abs_mc32p7031_e7	udata_ovr	0x00e7
_INDFbits
_INDF
	res	1
UD_abs_mc32p7031_ec	udata_ovr	0x00ec
_T2CRbits
_T2CR
	res	1
UD_abs_mc32p7031_ed	udata_ovr	0x00ed
_T2Cbits
_T2C
	res	1
UD_abs_mc32p7031_ee	udata_ovr	0x00ee
_T2Dbits
_T2D
	res	1
UD_abs_mc32p7031_f8	udata_ovr	0x00f8
_STK3L
	res	1
UD_abs_mc32p7031_f9	udata_ovr	0x00f9
_STK3H
	res	1
UD_abs_mc32p7031_fa	udata_ovr	0x00fa
_STK2L
	res	1
UD_abs_mc32p7031_fb	udata_ovr	0x00fb
_STK2H
	res	1
UD_abs_mc32p7031_fc	udata_ovr	0x00fc
_STK1L
	res	1
UD_abs_mc32p7031_fd	udata_ovr	0x00fd
_STK1H
	res	1
UD_abs_mc32p7031_fe	udata_ovr	0x00fe
_STK0L
	res	1
UD_abs_mc32p7031_ff	udata_ovr	0x00ff
_STK0H
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
code_mc32p7031	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
