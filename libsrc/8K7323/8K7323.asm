;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Nov 23 2015) (Linux)
; This file was generated Wed Mar 15 14:00:18 2017
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"8K7323.c"
	list	p=8K7323
	radix dec
	include "8K7323.inc"
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
	global	_T2CRbits
	global	_T3CRbits
	global	_PWMCR0bits
	global	_PWMCR1bits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ANSELbits
	global	_LEDCR0bits
	global	_LEDCR1bits
	global	_LCDCR0bits
	global	_LCDCR1bits
	global	_LCDIOS0bits
	global	_LCDIOS1bits
	global	_LCDIOS2bits
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
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA
	global	_T2CR
	global	_T2CNT
	global	_T2LOAD
	global	_T2DATA
	global	_T3CR
	global	_T3CNT
	global	_T3LOAD
	global	_PWM0DE
	global	_PWM1DE
	global	_PWM2DE
	global	_PWMCR0
	global	_PWMCR1
	global	_ADCR0
	global	_ADCR1
	global	_ADRH
	global	_ADRL
	global	_ANSEL
	global	_LEDCR0
	global	_LEDCR1
	global	_LCDCR0
	global	_LCDCR1
	global	_LCDIOS0
	global	_LCDIOS1
	global	_LCDIOS2

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_8K7323_180	udata_ovr	0x0180
_INDF
_INDF0
	res	1
UD_abs_8K7323_181	udata_ovr	0x0181
_INDF1
	res	1
UD_abs_8K7323_182	udata_ovr	0x0182
_INDF2
	res	1
UD_abs_8K7323_183	udata_ovr	0x0183
_HIBYTE
	res	1
UD_abs_8K7323_184	udata_ovr	0x0184
_FSR
_FSR0
	res	1
UD_abs_8K7323_185	udata_ovr	0x0185
_FSR1
	res	1
UD_abs_8K7323_186	udata_ovr	0x0186
_PCL
	res	1
UD_abs_8K7323_187	udata_ovr	0x0187
_PFLAGbits
_STATUS
_PFLAG
	res	1
UD_abs_8K7323_188	udata_ovr	0x0188
_MCRbits
_MCR
	res	1
UD_abs_8K7323_189	udata_ovr	0x0189
_INDF3
	res	1
UD_abs_8K7323_18a	udata_ovr	0x018a
_INTEbits
_INTE
	res	1
UD_abs_8K7323_18b	udata_ovr	0x018b
_INTFbits
_INTF
	res	1
UD_abs_8K7323_18c	udata_ovr	0x018c
_OSCMbits
_OSCM
	res	1
UD_abs_8K7323_190	udata_ovr	0x0190
_IOP0bits
_IOP0
	res	1
UD_abs_8K7323_191	udata_ovr	0x0191
_OEP0bits
_OEP0
	res	1
UD_abs_8K7323_192	udata_ovr	0x0192
_PUP0bits
_PUP0
	res	1
UD_abs_8K7323_194	udata_ovr	0x0194
_IOP1bits
_IOP1
	res	1
UD_abs_8K7323_195	udata_ovr	0x0195
_OEP1bits
_OEP1
	res	1
UD_abs_8K7323_196	udata_ovr	0x0196
_PUP1bits
_PUP1
	res	1
UD_abs_8K7323_198	udata_ovr	0x0198
_IOP2bits
_IOP2
	res	1
UD_abs_8K7323_199	udata_ovr	0x0199
_OEP2bits
_OEP2
	res	1
UD_abs_8K7323_19a	udata_ovr	0x019a
_PUP2bits
_PUP2
	res	1
UD_abs_8K7323_1a0	udata_ovr	0x01a0
_T0CRbits
_T0CR
	res	1
UD_abs_8K7323_1a1	udata_ovr	0x01a1
_T0CNT
	res	1
UD_abs_8K7323_1a2	udata_ovr	0x01a2
_T0LOAD
	res	1
UD_abs_8K7323_1a3	udata_ovr	0x01a3
_T0DATA
	res	1
UD_abs_8K7323_1a4	udata_ovr	0x01a4
_T1CRbits
_T1CR
	res	1
UD_abs_8K7323_1a5	udata_ovr	0x01a5
_T1CNT
	res	1
UD_abs_8K7323_1a6	udata_ovr	0x01a6
_T1LOAD
	res	1
UD_abs_8K7323_1a7	udata_ovr	0x01a7
_T1DATA
	res	1
UD_abs_8K7323_1a8	udata_ovr	0x01a8
_T2CRbits
_T2CR
	res	1
UD_abs_8K7323_1a9	udata_ovr	0x01a9
_T2CNT
	res	1
UD_abs_8K7323_1aa	udata_ovr	0x01aa
_T2LOAD
	res	1
UD_abs_8K7323_1ab	udata_ovr	0x01ab
_T2DATA
	res	1
UD_abs_8K7323_1ac	udata_ovr	0x01ac
_T3CRbits
_T3CR
	res	1
UD_abs_8K7323_1ad	udata_ovr	0x01ad
_T3CNT
	res	1
UD_abs_8K7323_1ae	udata_ovr	0x01ae
_T3LOAD
	res	1
UD_abs_8K7323_1b0	udata_ovr	0x01b0
_PWM0DE
_PWM2DE
	res	1
UD_abs_8K7323_1b1	udata_ovr	0x01b1
_PWM1DE
	res	1
UD_abs_8K7323_1b4	udata_ovr	0x01b4
_PWMCR0bits
_PWMCR0
	res	1
UD_abs_8K7323_1b5	udata_ovr	0x01b5
_PWMCR1bits
_PWMCR1
	res	1
UD_abs_8K7323_1b8	udata_ovr	0x01b8
_ADCR0bits
_ADCR0
	res	1
UD_abs_8K7323_1b9	udata_ovr	0x01b9
_ADCR1bits
_ADCR1
	res	1
UD_abs_8K7323_1bc	udata_ovr	0x01bc
_ADRH
	res	1
UD_abs_8K7323_1bd	udata_ovr	0x01bd
_ADRL
	res	1
UD_abs_8K7323_1be	udata_ovr	0x01be
_ANSELbits
_ANSEL
	res	1
UD_abs_8K7323_1c0	udata_ovr	0x01c0
_LEDCR0bits
_LEDCR0
	res	1
UD_abs_8K7323_1c1	udata_ovr	0x01c1
_LEDCR1bits
_LEDCR1
	res	1
UD_abs_8K7323_1c2	udata_ovr	0x01c2
_LCDCR0bits
_LCDCR0
	res	1
UD_abs_8K7323_1c3	udata_ovr	0x01c3
_LCDCR1bits
_LCDCR1
	res	1
UD_abs_8K7323_1c4	udata_ovr	0x01c4
_LCDIOS0bits
_LCDIOS0
	res	1
UD_abs_8K7323_1c5	udata_ovr	0x01c5
_LCDIOS1bits
_LCDIOS1
	res	1
UD_abs_8K7323_1c6	udata_ovr	0x01c6
_LCDIOS2bits
_LCDIOS2
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
code_8K7323	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
