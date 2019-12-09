;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8004 (Jun 26 2013) (Linux)
; This file was generated Fri Aug  2 17:50:23 2013
;--------------------------------------------------------
; PIC16 port for the Microchip 16-bit core micros
;--------------------------------------------------------

	.ident "SDCC version 3.2.0 #8004 [pic16 port]"
	.file	"type_char.c"
	list	p=18f1220

	radix dec

;--------------------------------------------------------
; public variables in this module
;--------------------------------------------------------
	global	_c_a
	global	_c_b
	global	_uc_a
	global	_uc_b
	global	_main

;--------------------------------------------------------
; extern variables in this module
;--------------------------------------------------------
	extern	_PORTAbits
	extern	_PORTBbits
	extern	_LATAbits
	extern	_LATBbits
	extern	_TRISAbits
	extern	_TRISBbits
	extern	_PIE1bits
	extern	_PIR1bits
	extern	_IPR1bits
	extern	_PIE2bits
	extern	_PIR2bits
	extern	_IPR2bits
	extern	_EECON1bits
	extern	_BAUDCTLbits
	extern	_RCSTAbits
	extern	_TXSTAbits
	extern	_T3CONbits
	extern	_ECCPASbits
	extern	_CCP1CONbits
	extern	_ADCON2bits
	extern	_ADCON1bits
	extern	_ADCON0bits
	extern	_T2CONbits
	extern	_T1CONbits
	extern	_RCONbits
	extern	_WDTCONbits
	extern	_LVDCONbits
	extern	_OSCCONbits
	extern	_T0CONbits
	extern	_STATUSbits
	extern	_INTCON3bits
	extern	_INTCON2bits
	extern	_INTCONbits
	extern	_STKPTRbits
	extern	_PORTA
	extern	_PORTB
	extern	_LATA
	extern	_LATB
	extern	_TRISA
	extern	_TRISB
	extern	_PIE1
	extern	_PIR1
	extern	_IPR1
	extern	_PIE2
	extern	_PIR2
	extern	_IPR2
	extern	_EECON1
	extern	_EECON2
	extern	_EEDATA
	extern	_EEADR
	extern	_BAUDCTL
	extern	_RCSTA
	extern	_TXSTA
	extern	_TXREG
	extern	_RCREG
	extern	_SPBRG
	extern	_SPBRGH
	extern	_T3CON
	extern	_TMR3L
	extern	_TMR3H
	extern	_ECCPAS
	extern	_CCP1CON
	extern	_CCPR1L
	extern	_CCPR1H
	extern	_ADCON2
	extern	_ADCON1
	extern	_ADCON0
	extern	_ADRESL
	extern	_ADRESH
	extern	_T2CON
	extern	_PR2
	extern	_TMR2
	extern	_T1CON
	extern	_TMR1L
	extern	_TMR1H
	extern	_RCON
	extern	_WDTCON
	extern	_LVDCON
	extern	_OSCCON
	extern	_T0CON
	extern	_TMR0L
	extern	_TMR0H
	extern	_STATUS
	extern	_FSR2L
	extern	_FSR2H
	extern	_PLUSW2
	extern	_PREINC2
	extern	_POSTDEC2
	extern	_POSTINC2
	extern	_INDF2
	extern	_BSR
	extern	_FSR1L
	extern	_FSR1H
	extern	_PLUSW1
	extern	_PREINC1
	extern	_POSTDEC1
	extern	_POSTINC1
	extern	_INDF1
	extern	_WREG
	extern	_FSR0L
	extern	_FSR0H
	extern	_PLUSW0
	extern	_PREINC0
	extern	_POSTDEC0
	extern	_POSTINC0
	extern	_INDF0
	extern	_INTCON3
	extern	_INTCON2
	extern	_INTCON
	extern	_PRODL
	extern	_PRODH
	extern	_TABLAT
	extern	_TBLPTRL
	extern	_TBLPTRH
	extern	_TBLPTRU
	extern	_PCL
	extern	_PCLATH
	extern	_PCLATU
	extern	_STKPTR
	extern	_TOSL
	extern	_TOSH
	extern	_TOSU

;--------------------------------------------------------
;	Equates to used internal registers
;--------------------------------------------------------
STATUS	equ	0xfd8


; Internal registers
.registers	udata_ovr	0x0000
r0x00	res	1
r0x01	res	1
r0x02	res	1
r0x03	res	1

udata_type_char_0	udata
_c_a	res	1

udata_type_char_1	udata
_c_b	res	1

udata_type_char_2	udata
_uc_a	res	1

udata_type_char_3	udata
_uc_b	res	1

;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
; I code from now on!
; ; Starting pCode block
S_type_char__main	code
_main:
	.line	9; type_char.c	c_a = PORTB;
	MOVFF	_PORTB, _c_a
	.line	10; type_char.c	c_b = PORTA;
	MOVFF	_PORTA, _c_b
	.line	11; type_char.c	uc_a = PORTA;
	MOVFF	_PORTA, _uc_a
	.line	12; type_char.c	uc_b = PORTB;
	MOVFF	_PORTB, _uc_b
	BANKSEL	_c_b
	.line	14; type_char.c	PORTA = c_a + c_b;
	MOVF	_c_b, W, B
	BANKSEL	_c_a
	ADDWF	_c_a, W, B
	MOVWF	_PORTA
	BANKSEL	_uc_b
	.line	15; type_char.c	PORTA = uc_a + uc_b;
	MOVF	_uc_b, W, B
	BANKSEL	_uc_a
	ADDWF	_uc_a, W, B
	MOVWF	_PORTA
	BANKSEL	_c_b
	.line	16; type_char.c	PORTB = c_a - c_b;
	MOVF	_c_b, W, B
	BANKSEL	_c_a
	SUBWF	_c_a, W, B
	MOVWF	_PORTB
	BANKSEL	_uc_b
	.line	17; type_char.c	PORTB = uc_a - uc_b;
	MOVF	_uc_b, W, B
	BANKSEL	_uc_a
	SUBWF	_uc_a, W, B
	MOVWF	_PORTB
	BANKSEL	_c_a
	.line	19; type_char.c	if (c_a > 0) PORTA = c_b;
	MOVF	_c_a, W, B
	ADDLW	0x80
	ADDLW	0x7f
	BNC	_00106_DS_
	MOVFF	_c_b, _PORTA
_00106_DS_:
	BANKSEL	_uc_a
	.line	20; type_char.c	if (uc_a > 0) PORTA = uc_b;
	MOVF	_uc_a, W, B
	BZ	_00108_DS_
	MOVFF	_uc_b, _PORTA
_00108_DS_:
	BANKSEL	_c_a
	.line	22; type_char.c	if (c_a > -3) PORTA = c_b;
	MOVF	_c_a, W, B
	ADDLW	0x80
	ADDLW	0x82
	BNC	_00110_DS_
	MOVFF	_c_b, _PORTA
_00110_DS_:
	.line	29; type_char.c	if (uc_a == ~uc_b) PORTA = uc_b;
	MOVFF	_uc_b, r0x00
	CLRF	r0x01
	COMF	r0x00, F
	COMF	r0x01, F
	MOVFF	_uc_a, r0x02
	CLRF	r0x03
	MOVF	r0x02, W
	XORWF	r0x00, W
	BNZ	_00130_DS_
	MOVF	r0x03, W
	XORWF	r0x01, W
	BZ	_00131_DS_
_00130_DS_:
	BRA	_00112_DS_
_00131_DS_:
	MOVFF	_uc_b, _PORTA
_00112_DS_:
	.line	31; type_char.c	uc_a = uc_b = 0x33;
	MOVLW	0x33
	BANKSEL	_uc_b
	MOVWF	_uc_b, B
	MOVLW	0x33
	BANKSEL	_uc_a
	MOVWF	_uc_a, B
_00114_DS_:
	.line	33; type_char.c	while(1);
	BRA	_00114_DS_
	RETURN	



; Statistics:
; code size:	  144 (0x0090) bytes ( 0.11%)
;           	   72 (0x0048) words
; udata size:	    4 (0x0004) bytes ( 6.25%)
; access size:	    4 (0x0004) bytes


	end
