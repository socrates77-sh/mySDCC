;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.1.0 (Dec 19 2017) (MINGW32)
; This file was generated Mon Jan 08 15:50:08 2018
;--------------------------------------------------------
; MC32 port for the RISC core
;--------------------------------------------------------
;	.file	"mc32p5314.c"
	list	p=3316
	radix dec
	include "3316.inc"
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
	global	_PFLAGbits
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
	global	_LCDIOSP1bits
	global	_IOP2bits
	global	_OEP2bits
	global	_PUP2bits
	global	_LCDIOSP2bits
	global	_IOP3bits
	global	_OEP3bits
	global	_PUP3bits
	global	_LCDIOSP3bits
	global	_IOP4bits
	global	_OEP4bits
	global	_PUP4bits
	global	_LCDIOSP4bits
	global	_IOP5bits
	global	_OEP5bits
	global	_PUP5bits
	global	_LCDIOSP5bits
	global	_T0CR0bits
	global	_T0CR1bits
	global	_T0LOADLbits
	global	_T0DATAHbits
	global	_T0DATALbits
	global	_T0LATRHbits
	global	_T0LATRLbits
	global	_T0LATFHbits
	global	_T0LATFLbits
	global	_T1CRbits
	global	_T1DATAbits
	global	_T1LOADbits
	global	_ADCR0bits
	global	_ADCR1bits
	global	_ADCR2bits
	global	_OPCR0bits
	global	_OPCR1bits
	global	_LCDCR0bits
	global	_LCDCR1bits
	global	_DKWbits
	global	_KBCRbits
	global	_LCDDRVbits
	global	_LCDDS00
	global	_LCDDS01
	global	_LCDDS02
	global	_LCDDS03
	global	_LCDDS04
	global	_LCDDS05
	global	_LCDDS06
	global	_LCDDS07
	global	_LCDDS08
	global	_LCDDS09
	global	_LCDDS10
	global	_LCDDS11
	global	_LCDDS12
	global	_LCDDS13
	global	_LCDDS14
	global	_LCDDS15
	global	_LCDDS16
	global	_LCDDS17
	global	_LCDDS18
	global	_LCDDS19
	global	_LCDDS20
	global	_LCDDS21
	global	_LCDDS22
	global	_LCDDS23
	global	_LCDDS24
	global	_LCDDS25
	global	_LCDDS26
	global	_LCDDS27
	global	_LCDDS28
	global	_LCDDS29
	global	_INDF0
	global	_INDF1
	global	_INDF2
	global	_HIBYTE
	global	_FSR0
	global	_FSR1
	global	_PCL
	global	_PFLAG
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
	global	_LCDIOSP1
	global	_IOP2
	global	_OEP2
	global	_PUP2
	global	_LCDIOSP2
	global	_IOP3
	global	_OEP3
	global	_PUP3
	global	_LCDIOSP3
	global	_IOP4
	global	_OEP4
	global	_PUP4
	global	_LCDIOSP4
	global	_IOP5
	global	_OEP5
	global	_PUP5
	global	_LCDIOSP5
	global	_T0CR0
	global	_T0CR1
	global	_T0LOADH
	global	_T0LOADL
	global	_T0DATAH
	global	_T0DATAL
	global	_T0LATRH
	global	_T0LATRL
	global	_T0LATFH
	global	_T0LATFL
	global	_T1CR
	global	_T1DATA
	global	_T1LOAD
	global	_ADCR0
	global	_ADCR1
	global	_ADCR2
	global	_ADDRH
	global	_ADDRL
	global	_OPCR0
	global	_OPCR1
	global	_LCDCR0
	global	_LCDCR1
	global	_DKW
	global	_KBCR
	global	_LCDDRV

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc32p5314_100	udata_ovr	0x0100
_LCDDS00
	res	1
UD_abs_mc32p5314_101	udata_ovr	0x0101
_LCDDS01
	res	1
UD_abs_mc32p5314_102	udata_ovr	0x0102
_LCDDS02
	res	1
UD_abs_mc32p5314_103	udata_ovr	0x0103
_LCDDS03
	res	1
UD_abs_mc32p5314_104	udata_ovr	0x0104
_LCDDS04
	res	1
UD_abs_mc32p5314_105	udata_ovr	0x0105
_LCDDS05
	res	1
UD_abs_mc32p5314_106	udata_ovr	0x0106
_LCDDS06
	res	1
UD_abs_mc32p5314_107	udata_ovr	0x0107
_LCDDS07
	res	1
UD_abs_mc32p5314_108	udata_ovr	0x0108
_LCDDS08
	res	1
UD_abs_mc32p5314_109	udata_ovr	0x0109
_LCDDS09
	res	1
UD_abs_mc32p5314_10a	udata_ovr	0x010a
_LCDDS10
	res	1
UD_abs_mc32p5314_10b	udata_ovr	0x010b
_LCDDS11
	res	1
UD_abs_mc32p5314_10c	udata_ovr	0x010c
_LCDDS12
	res	1
UD_abs_mc32p5314_10d	udata_ovr	0x010d
_LCDDS13
	res	1
UD_abs_mc32p5314_10e	udata_ovr	0x010e
_LCDDS14
	res	1
UD_abs_mc32p5314_10f	udata_ovr	0x010f
_LCDDS15
	res	1
UD_abs_mc32p5314_110	udata_ovr	0x0110
_LCDDS16
	res	1
UD_abs_mc32p5314_111	udata_ovr	0x0111
_LCDDS17
	res	1
UD_abs_mc32p5314_112	udata_ovr	0x0112
_LCDDS18
	res	1
UD_abs_mc32p5314_113	udata_ovr	0x0113
_LCDDS19
	res	1
UD_abs_mc32p5314_114	udata_ovr	0x0114
_LCDDS20
	res	1
UD_abs_mc32p5314_115	udata_ovr	0x0115
_LCDDS21
	res	1
UD_abs_mc32p5314_116	udata_ovr	0x0116
_LCDDS22
	res	1
UD_abs_mc32p5314_117	udata_ovr	0x0117
_LCDDS23
	res	1
UD_abs_mc32p5314_118	udata_ovr	0x0118
_LCDDS24
	res	1
UD_abs_mc32p5314_119	udata_ovr	0x0119
_LCDDS25
	res	1
UD_abs_mc32p5314_11a	udata_ovr	0x011a
_LCDDS26
	res	1
UD_abs_mc32p5314_11b	udata_ovr	0x011b
_LCDDS27
	res	1
UD_abs_mc32p5314_11c	udata_ovr	0x011c
_LCDDS28
	res	1
UD_abs_mc32p5314_11d	udata_ovr	0x011d
_LCDDS29
	res	1
UD_abs_mc32p5314_1b0	udata_ovr	0x01b0
_INDF0bits
_INDF0
	res	1
UD_abs_mc32p5314_1b1	udata_ovr	0x01b1
_INDF1bits
_INDF1
	res	1
UD_abs_mc32p5314_1b2	udata_ovr	0x01b2
_INDF2bits
_INDF2
	res	1
UD_abs_mc32p5314_1b3	udata_ovr	0x01b3
_HIBYTEbits
_HIBYTE
	res	1
UD_abs_mc32p5314_1b4	udata_ovr	0x01b4
_FSR0bits
_FSR0
	res	1
UD_abs_mc32p5314_1b5	udata_ovr	0x01b5
_FSR1bits
_FSR1
	res	1
UD_abs_mc32p5314_1b6	udata_ovr	0x01b6
_PCLbits
_PCL
	res	1
UD_abs_mc32p5314_1b7	udata_ovr	0x01b7
_PFLAGbits
_PFLAG
	res	1
UD_abs_mc32p5314_1b8	udata_ovr	0x01b8
_MCRbits
_MCR
	res	1
UD_abs_mc32p5314_1b9	udata_ovr	0x01b9
_INDF3bits
_INDF3
	res	1
UD_abs_mc32p5314_1ba	udata_ovr	0x01ba
_INTEbits
_INTE
	res	1
UD_abs_mc32p5314_1bb	udata_ovr	0x01bb
_INTFbits
_INTF
	res	1
UD_abs_mc32p5314_1bc	udata_ovr	0x01bc
_OSCMbits
_OSCM
	res	1
UD_abs_mc32p5314_1bd	udata_ovr	0x01bd
_LVDCRbits
_LVDCR
	res	1
UD_abs_mc32p5314_1be	udata_ovr	0x01be
_LXTCRbits
_LXTCR
	res	1
UD_abs_mc32p5314_1c0	udata_ovr	0x01c0
_IOP0bits
_IOP0
	res	1
UD_abs_mc32p5314_1c1	udata_ovr	0x01c1
_OEP0bits
_OEP0
	res	1
UD_abs_mc32p5314_1c2	udata_ovr	0x01c2
_PUP0bits
_PUP0
	res	1
UD_abs_mc32p5314_1c3	udata_ovr	0x01c3
_DKWP0bits
_DKWP0
	res	1
UD_abs_mc32p5314_1c4	udata_ovr	0x01c4
_IOP1bits
_IOP1
	res	1
UD_abs_mc32p5314_1c5	udata_ovr	0x01c5
_OEP1bits
_OEP1
	res	1
UD_abs_mc32p5314_1c6	udata_ovr	0x01c6
_PUP1bits
_PUP1
	res	1
UD_abs_mc32p5314_1c7	udata_ovr	0x01c7
_LCDIOSP1bits
_LCDIOSP1
	res	1
UD_abs_mc32p5314_1c8	udata_ovr	0x01c8
_IOP2bits
_IOP2
	res	1
UD_abs_mc32p5314_1c9	udata_ovr	0x01c9
_OEP2bits
_OEP2
	res	1
UD_abs_mc32p5314_1ca	udata_ovr	0x01ca
_PUP2bits
_PUP2
	res	1
UD_abs_mc32p5314_1cb	udata_ovr	0x01cb
_LCDIOSP2bits
_LCDIOSP2
	res	1
UD_abs_mc32p5314_1cc	udata_ovr	0x01cc
_IOP3bits
_IOP3
	res	1
UD_abs_mc32p5314_1cd	udata_ovr	0x01cd
_OEP3bits
_OEP3
	res	1
UD_abs_mc32p5314_1ce	udata_ovr	0x01ce
_PUP3bits
_PUP3
	res	1
UD_abs_mc32p5314_1cf	udata_ovr	0x01cf
_LCDIOSP3bits
_LCDIOSP3
	res	1
UD_abs_mc32p5314_1d0	udata_ovr	0x01d0
_IOP4bits
_IOP4
	res	1
UD_abs_mc32p5314_1d1	udata_ovr	0x01d1
_OEP4bits
_OEP4
	res	1
UD_abs_mc32p5314_1d2	udata_ovr	0x01d2
_PUP4bits
_PUP4
	res	1
UD_abs_mc32p5314_1d3	udata_ovr	0x01d3
_LCDIOSP4bits
_LCDIOSP4
	res	1
UD_abs_mc32p5314_1d4	udata_ovr	0x01d4
_IOP5bits
_IOP5
	res	1
UD_abs_mc32p5314_1d5	udata_ovr	0x01d5
_OEP5bits
_OEP5
	res	1
UD_abs_mc32p5314_1d6	udata_ovr	0x01d6
_PUP5bits
_PUP5
	res	1
UD_abs_mc32p5314_1d7	udata_ovr	0x01d7
_LCDIOSP5bits
_LCDIOSP5
	res	1
UD_abs_mc32p5314_1d8	udata_ovr	0x01d8
_T0CR0bits
_T0CR0
	res	1
UD_abs_mc32p5314_1d9	udata_ovr	0x01d9
_T0CR1bits
_T0CR1
	res	1
UD_abs_mc32p5314_1dc	udata_ovr	0x01dc
_T0LOADH
	res	1
UD_abs_mc32p5314_1dd	udata_ovr	0x01dd
_T0LOADLbits
_T0LOADL
	res	1
UD_abs_mc32p5314_1de	udata_ovr	0x01de
_T0DATAHbits
_T0DATAH
	res	1
UD_abs_mc32p5314_1df	udata_ovr	0x01df
_T0DATALbits
_T0DATAL
	res	1
UD_abs_mc32p5314_1e0	udata_ovr	0x01e0
_T0LATRHbits
_T0LATRH
	res	1
UD_abs_mc32p5314_1e1	udata_ovr	0x01e1
_T0LATRLbits
_T0LATRL
	res	1
UD_abs_mc32p5314_1e2	udata_ovr	0x01e2
_T0LATFHbits
_T0LATFH
	res	1
UD_abs_mc32p5314_1e3	udata_ovr	0x01e3
_T0LATFLbits
_T0LATFL
	res	1
UD_abs_mc32p5314_1e4	udata_ovr	0x01e4
_T1CRbits
_T1CR
	res	1
UD_abs_mc32p5314_1e5	udata_ovr	0x01e5
_T1DATAbits
_T1DATA
	res	1
UD_abs_mc32p5314_1e6	udata_ovr	0x01e6
_T1LOADbits
_T1LOAD
	res	1
UD_abs_mc32p5314_1e8	udata_ovr	0x01e8
_ADCR0bits
_ADCR0
	res	1
UD_abs_mc32p5314_1e9	udata_ovr	0x01e9
_ADCR1bits
_ADCR1
	res	1
UD_abs_mc32p5314_1ea	udata_ovr	0x01ea
_ADCR2bits
_ADCR2
	res	1
UD_abs_mc32p5314_1ec	udata_ovr	0x01ec
_ADDRH
	res	1
UD_abs_mc32p5314_1ed	udata_ovr	0x01ed
_ADDRL
	res	1
UD_abs_mc32p5314_1f0	udata_ovr	0x01f0
_OPCR0bits
_OPCR0
	res	1
UD_abs_mc32p5314_1f1	udata_ovr	0x01f1
_OPCR1bits
_OPCR1
	res	1
UD_abs_mc32p5314_1f2	udata_ovr	0x01f2
_LCDCR0bits
_LCDCR0
	res	1
UD_abs_mc32p5314_1f3	udata_ovr	0x01f3
_LCDCR1bits
_LCDCR1
	res	1
UD_abs_mc32p5314_1f4	udata_ovr	0x01f4
_DKWbits
_DKW
	res	1
UD_abs_mc32p5314_1f5	udata_ovr	0x01f5
_KBCRbits
_KBCR
	res	1
UD_abs_mc32p5314_1f6	udata_ovr	0x01f6
_LCDDRVbits
_LCDDRV
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
code_mc32p5314	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
