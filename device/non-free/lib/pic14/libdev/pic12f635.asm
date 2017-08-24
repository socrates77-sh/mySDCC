;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8004 (Aug 21 2017) (MINGW32)
; This file was generated Mon Aug 21 13:39:10 2017
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"pic12f635.c"
	list	p=12f635
	radix dec
	include "p12f635.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------

	extern PSAVE
	extern SSAVE
	extern WSAVE
	extern STK12
	extern STK11
	extern STK10
	extern STK09
	extern STK08
	extern STK07
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
	global	_CMCON0bits
	global	_CMCON1bits
	global	_CRCONbits
	global	_EECON1bits
	global	_GPIObits
	global	_INTCONbits
	global	_IOCAbits
	global	_LVDCONbits
	global	_OPTION_REGbits
	global	_OSCCONbits
	global	_OSCTUNEbits
	global	_PCONbits
	global	_PIE1bits
	global	_PIR1bits
	global	_PORTAbits
	global	_STATUSbits
	global	_T1CONbits
	global	_VRCONbits
	global	_WDAbits
	global	_WDTCONbits
	global	_WPUDAbits
	global	_INDF
	global	_TMR0
	global	_PCL
	global	_STATUS
	global	_FSR
	global	_PORTA
	global	_GPIO
	global	_PCLATH
	global	_INTCON
	global	_PIR1
	global	_TMR1L
	global	_TMR1H
	global	_T1CON
	global	_WDTCON
	global	_CMCON0
	global	_CMCON1
	global	_OPTION_REG
	global	_TRISA
	global	_TRISIO
	global	_PIE1
	global	_PCON
	global	_OSCCON
	global	_OSCTUNE
	global	_LVDCON
	global	_WPUDA
	global	_IOCA
	global	_WDA
	global	_VRCON
	global	_EEDAT
	global	_EEDATA
	global	_EEADR
	global	_EECON1
	global	_EECON2
	global	_CRCON
	global	_CRDAT0
	global	_CRDAT1
	global	_CRDAT2
	global	_CRDAT3

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_pic12f635_0	udata_ovr	0x0000
_INDF
	res	1
UD_abs_pic12f635_1	udata_ovr	0x0001
_TMR0
	res	1
UD_abs_pic12f635_2	udata_ovr	0x0002
_PCL
	res	1
UD_abs_pic12f635_3	udata_ovr	0x0003
_STATUSbits
_STATUS
	res	1
UD_abs_pic12f635_4	udata_ovr	0x0004
_FSR
	res	1
UD_abs_pic12f635_5	udata_ovr	0x0005
_GPIObits
_PORTAbits
_PORTA
_GPIO
	res	1
UD_abs_pic12f635_a	udata_ovr	0x000a
_PCLATH
	res	1
UD_abs_pic12f635_b	udata_ovr	0x000b
_INTCONbits
_INTCON
	res	1
UD_abs_pic12f635_c	udata_ovr	0x000c
_PIR1bits
_PIR1
	res	1
UD_abs_pic12f635_e	udata_ovr	0x000e
_TMR1L
	res	1
UD_abs_pic12f635_f	udata_ovr	0x000f
_TMR1H
	res	1
UD_abs_pic12f635_10	udata_ovr	0x0010
_T1CONbits
_T1CON
	res	1
UD_abs_pic12f635_18	udata_ovr	0x0018
_WDTCONbits
_WDTCON
	res	1
UD_abs_pic12f635_19	udata_ovr	0x0019
_CMCON0bits
_CMCON0
	res	1
UD_abs_pic12f635_1a	udata_ovr	0x001a
_CMCON1bits
_CMCON1
	res	1
UD_abs_pic12f635_81	udata_ovr	0x0081
_OPTION_REGbits
_OPTION_REG
	res	1
UD_abs_pic12f635_85	udata_ovr	0x0085
_TRISA
_TRISIO
	res	1
UD_abs_pic12f635_8c	udata_ovr	0x008c
_PIE1bits
_PIE1
	res	1
UD_abs_pic12f635_8e	udata_ovr	0x008e
_PCONbits
_PCON
	res	1
UD_abs_pic12f635_8f	udata_ovr	0x008f
_OSCCONbits
_OSCCON
	res	1
UD_abs_pic12f635_90	udata_ovr	0x0090
_OSCTUNEbits
_OSCTUNE
	res	1
UD_abs_pic12f635_94	udata_ovr	0x0094
_LVDCONbits
_LVDCON
	res	1
UD_abs_pic12f635_95	udata_ovr	0x0095
_WPUDAbits
_WPUDA
	res	1
UD_abs_pic12f635_96	udata_ovr	0x0096
_IOCAbits
_IOCA
	res	1
UD_abs_pic12f635_97	udata_ovr	0x0097
_WDAbits
_WDA
	res	1
UD_abs_pic12f635_99	udata_ovr	0x0099
_VRCONbits
_VRCON
	res	1
UD_abs_pic12f635_9a	udata_ovr	0x009a
_EEDAT
_EEDATA
	res	1
UD_abs_pic12f635_9b	udata_ovr	0x009b
_EEADR
	res	1
UD_abs_pic12f635_9c	udata_ovr	0x009c
_EECON1bits
_EECON1
	res	1
UD_abs_pic12f635_9d	udata_ovr	0x009d
_EECON2
	res	1
UD_abs_pic12f635_110	udata_ovr	0x0110
_CRCONbits
_CRCON
	res	1
UD_abs_pic12f635_111	udata_ovr	0x0111
_CRDAT0
	res	1
UD_abs_pic12f635_112	udata_ovr	0x0112
_CRDAT1
	res	1
UD_abs_pic12f635_113	udata_ovr	0x0113
_CRDAT2
	res	1
UD_abs_pic12f635_114	udata_ovr	0x0114
_CRDAT3
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
code_pic12f635	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
