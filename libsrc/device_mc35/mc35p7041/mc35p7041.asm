;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Wed Dec 20 12:01:09 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"mc35p7041.c"
	list	p=2K7041
	radix dec
	include "2K7041.inc"
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
	global	_ZEROTRbits
	global	_OSCCALbits
	global	_WKCR0bits
	global	_WKCR5bits
	global	_ADIOS0bits
	global	_ADIOS1bits
	global	_ADIOS2bits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_OEP0bits
	global	_EINTCRbits
	global	_OEP4bits
	global	_OEP5bits
	global	_INTFbits
	global	_INTEbits
	global	_OSCMbits
	global	_WDTCRbits
	global	_T1LDRbits
	global	_PCLbits
	global	_PCHbits
	global	_IOP0bits
	global	_IOP4bits
	global	_IOP5bits
	global	_T0CRbits
	global	_T0CNTbits
	global	_T1CRbits
	global	_T1CNTbits
	global	_BUZCRbits
	global	_MCRbits
	global	_PUP0bits
	global	_PUP4bits
	global	_PUP5bits
	global	_INDFbits
	global	_PWMCR0bits
	global	_PWMCR1bits
	global	_PWMCNTbits
	global	_PWMADTbits
	global	_PWMBDTbits
	global	_PWMCDTbits
	global	_PWMPDbits
	global	_HIBYTE
	global	_FSR0
	global	_FSR1
	global	_PFLAG
	global	_ZEROTR
	global	_OSCCAL
	global	_WKCR0
	global	_WKCR5
	global	_ADIOS0
	global	_ADIOS1
	global	_ADIOS2
	global	_ADCR0
	global	_ADCR1
	global	_ADRH
	global	_ADRL
	global	_ADCR2
	global	_OEP0
	global	_EINTCR
	global	_OEP4
	global	_OEP5
	global	_INTF
	global	_INTE
	global	_OSCM
	global	_WDTCR
	global	_T1LDR
	global	_PCL
	global	_PCH
	global	_IOP0
	global	_IOP4
	global	_IOP5
	global	_T0CR
	global	_T0CNT
	global	_T1CR
	global	_T1CNT
	global	_BUZCR
	global	_MCR
	global	_PUP0
	global	_PUP4
	global	_PUP5
	global	_INDF
	global	_PWMCR0
	global	_PWMCR1
	global	_PWMCNT
	global	_PWMADT
	global	_PWMBDT
	global	_PWMCDT
	global	_PWMPD
	global	_STKR0L
	global	_STKR0H
	global	_STKR1L
	global	_STKR1H
	global	_STKR2L
	global	_STKR2H
	global	_STKR3L
	global	_STKR3H
	global	_STKR4L
	global	_STKR4H
	global	_STKR5L
	global	_STKR5H
	global	_STKR6L
	global	_STKR6H
	global	_STKR7L
	global	_STKR7H

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc35p7041_82	udata_ovr	0x0082
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc35p7041_83	udata_ovr	0x0083
_FSR0bits
_FSR0
	res	1
UD_abs_mc35p7041_84	udata_ovr	0x0084
_FSR1bits
_FSR1
	res	1
UD_abs_mc35p7041_86	udata_ovr	0x0086
_PFLAGbits
_PFLAG
	res	1
UD_abs_mc35p7041_8e	udata_ovr	0x008e
_ZEROTRbits
_ZEROTR
	res	1
UD_abs_mc35p7041_8f	udata_ovr	0x008f
_OSCCALbits
_OSCCAL
	res	1
UD_abs_mc35p7041_a0	udata_ovr	0x00a0
_WKCR0bits
_WKCR0
	res	1
UD_abs_mc35p7041_a5	udata_ovr	0x00a5
_WKCR5bits
_WKCR5
	res	1
UD_abs_mc35p7041_ad	udata_ovr	0x00ad
_ADIOS0bits
_ADIOS0
	res	1
UD_abs_mc35p7041_ae	udata_ovr	0x00ae
_ADIOS1bits
_ADIOS1
	res	1
UD_abs_mc35p7041_af	udata_ovr	0x00af
_ADIOS2bits
_ADIOS2
	res	1
UD_abs_mc35p7041_b1	udata_ovr	0x00b1
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc35p7041_b2	udata_ovr	0x00b2
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc35p7041_b3	udata_ovr	0x00b3
_ADRH
	res	1
UD_abs_mc35p7041_b4	udata_ovr	0x00b4
_ADRL
	res	1
UD_abs_mc35p7041_b5	udata_ovr	0x00b5
_ADCR2bits
_ADCR2
	res	1
UD_abs_mc35p7041_b8	udata_ovr	0x00b8
_OEP0bits
_OEP0
	res	1
UD_abs_mc35p7041_bf	udata_ovr	0x00bf
_EINTCRbits
_EINTCR
	res	1
UD_abs_mc35p7041_c4	udata_ovr	0x00c4
_OEP4bits
_OEP4
	res	1
UD_abs_mc35p7041_c5	udata_ovr	0x00c5
_OEP5bits
_OEP5
	res	1
UD_abs_mc35p7041_c8	udata_ovr	0x00c8
_INTFbits
_INTF
	res	1
UD_abs_mc35p7041_c9	udata_ovr	0x00c9
_INTEbits
_INTE
	res	1
UD_abs_mc35p7041_ca	udata_ovr	0x00ca
_OSCMbits
_OSCM
	res	1
UD_abs_mc35p7041_cc	udata_ovr	0x00cc
_WDTCRbits
_WDTCR
	res	1
UD_abs_mc35p7041_cd	udata_ovr	0x00cd
_T1LDRbits
_T1LDR
	res	1
UD_abs_mc35p7041_ce	udata_ovr	0x00ce
_PCLbits
_PCL
	res	1
UD_abs_mc35p7041_cf	udata_ovr	0x00cf
_PCHbits
_PCH
	res	1
UD_abs_mc35p7041_d0	udata_ovr	0x00d0
_IOP0bits
_IOP0
	res	1
UD_abs_mc35p7041_d4	udata_ovr	0x00d4
_IOP4bits
_IOP4
	res	1
UD_abs_mc35p7041_d5	udata_ovr	0x00d5
_IOP5bits
_IOP5
	res	1
UD_abs_mc35p7041_d8	udata_ovr	0x00d8
_T0CRbits
_T0CR
	res	1
UD_abs_mc35p7041_d9	udata_ovr	0x00d9
_T0CNTbits
_T0CNT
	res	1
UD_abs_mc35p7041_da	udata_ovr	0x00da
_T1CRbits
_T1CR
	res	1
UD_abs_mc35p7041_db	udata_ovr	0x00db
_T1CNTbits
_T1CNT
	res	1
UD_abs_mc35p7041_dc	udata_ovr	0x00dc
_BUZCRbits
_BUZCR
	res	1
UD_abs_mc35p7041_df	udata_ovr	0x00df
_MCRbits
_MCR
	res	1
UD_abs_mc35p7041_e0	udata_ovr	0x00e0
_PUP0bits
_PUP0
	res	1
UD_abs_mc35p7041_e4	udata_ovr	0x00e4
_PUP4bits
_PUP4
	res	1
UD_abs_mc35p7041_e5	udata_ovr	0x00e5
_PUP5bits
_PUP5
	res	1
UD_abs_mc35p7041_e7	udata_ovr	0x00e7
_INDFbits
_INDF
	res	1
UD_abs_mc35p7041_e8	udata_ovr	0x00e8
_PWMCR0bits
_PWMCR0
	res	1
UD_abs_mc35p7041_e9	udata_ovr	0x00e9
_PWMCR1bits
_PWMCR1
	res	1
UD_abs_mc35p7041_ea	udata_ovr	0x00ea
_PWMCNTbits
_PWMCNT
	res	1
UD_abs_mc35p7041_eb	udata_ovr	0x00eb
_PWMADTbits
_PWMADT
	res	1
UD_abs_mc35p7041_ec	udata_ovr	0x00ec
_PWMBDTbits
_PWMBDT
	res	1
UD_abs_mc35p7041_ed	udata_ovr	0x00ed
_PWMCDTbits
_PWMCDT
	res	1
UD_abs_mc35p7041_ee	udata_ovr	0x00ee
_PWMPDbits
_PWMPD
	res	1
UD_abs_mc35p7041_f0	udata_ovr	0x00f0
_STKR0L
	res	1
UD_abs_mc35p7041_f1	udata_ovr	0x00f1
_STKR0H
	res	1
UD_abs_mc35p7041_f2	udata_ovr	0x00f2
_STKR1L
	res	1
UD_abs_mc35p7041_f3	udata_ovr	0x00f3
_STKR1H
	res	1
UD_abs_mc35p7041_f4	udata_ovr	0x00f4
_STKR2L
	res	1
UD_abs_mc35p7041_f5	udata_ovr	0x00f5
_STKR2H
	res	1
UD_abs_mc35p7041_f6	udata_ovr	0x00f6
_STKR3L
	res	1
UD_abs_mc35p7041_f7	udata_ovr	0x00f7
_STKR3H
	res	1
UD_abs_mc35p7041_f8	udata_ovr	0x00f8
_STKR4L
	res	1
UD_abs_mc35p7041_f9	udata_ovr	0x00f9
_STKR4H
	res	1
UD_abs_mc35p7041_fa	udata_ovr	0x00fa
_STKR5L
	res	1
UD_abs_mc35p7041_fb	udata_ovr	0x00fb
_STKR5H
	res	1
UD_abs_mc35p7041_fc	udata_ovr	0x00fc
_STKR6L
	res	1
UD_abs_mc35p7041_fd	udata_ovr	0x00fd
_STKR6H
	res	1
UD_abs_mc35p7041_fe	udata_ovr	0x00fe
_STKR7L
	res	1
UD_abs_mc35p7041_ff	udata_ovr	0x00ff
_STKR7H
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
code_mc35p7041	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
