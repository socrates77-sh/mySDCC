;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8004 (Jun 26 2013) (Linux)
; This file was generated Tue Aug  6 17:27:47 2013
;--------------------------------------------------------
; PIC16 port for the Microchip 16-bit core micros
;--------------------------------------------------------

	.ident "SDCC version 3.2.0 #8004 [pic16 port]"
	.file	"test.c"
	list	p=18f1220

	radix dec

;--------------------------------------------------------
; public variables in this module
;--------------------------------------------------------
	global	_k
	global	_Flag1
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
WREG	equ	0xfe8
PRODH	equ	0xff4


; Internal registers
.registers	udata_ovr	0x0000
r0x00	res	1
r0x01	res	1

udata_test_0	udata
_k	res	2

udata_test_1	udata
_Flag1	res	1

;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
; I code from now on!
; ; Starting pCode block
; ;ic:1:  _entry($13) :
; ;ic:2: 	proc _main [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{void function ( ) fixed}
S_test__main	code
_main:
; ;ic:3: 	_PORTA [k2 lr0:0 so:0]{ ia1 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-char sfr} := 0x1 {const-unsigned-char literal}
	.line	31; test.c	PORTA = 0x01;
	MOVLW	0x01
	MOVWF	_PORTA
; ;ic:4: 	_k [k3 lr0:0 so:0]{ ia1 a2p0 re0 rm0 nos0 ru0 dp0}{int fixed} := 0x0 {int literal}
	BANKSEL	_k
	.line	33; test.c	k=0;
	CLRF	_k, B
	BANKSEL	(_k + 1)
	CLRF	(_k + 1), B
; ;ic:5: 	iTemp1 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] = &[_Flag1 [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct __00000158 fixed}]
; ;ic:6: 	iTemp2 [k8 lr6:7 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] := iTemp1 [k6 lr5:6 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]
; ;ic:7: 	*(iTemp2 [k8 lr6:7 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]) := 0x1 {const-unsigned-char literal}
	BANKSEL	_Flag1
	.line	35; test.c	F4ms = 1;
	BSF	_Flag1, 2, B
; ;ic:8: 	iTemp3 [k9 lr8:9 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] = &[_Flag1 [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct __00000158 fixed}]
; ;ic:9: 	iTemp4 [k11 lr9:15 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] := iTemp3 [k9 lr8:9 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]
; ;ic:10: 	iTemp5 [k12 lr10:11 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] = &[_Flag1 [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct __00000158 fixed}]
; ;ic:11: 	iTemp6 [k14 lr11:12 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] := iTemp5 [k12 lr10:11 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]
; ;ic:12: 	iTemp7 [k15 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} fixed}[r0x00 ] = @[iTemp6 [k14 lr11:12 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] + 0x0 {const-unsigned-char literal}]
	.line	36; test.c	F4ms = !F4ms;
	CLRF	r0x00
	BANKSEL	_Flag1
	BTFSC	_Flag1, 2, B
	INCF	r0x00, F
; ;ic:13: 	iTemp8 [k16 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{bit fixed}[r0x00 ] = not iTemp7 [k15 lr12:13 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} fixed}[r0x00 ]
	MOVF	r0x00, W
	BSF	STATUS, 0
	TSTFSZ	WREG
	BCF	STATUS, 0
	CLRF	r0x00
	RLCF	r0x00, F
; ;ic:14: 	iTemp9 [k17 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} fixed}[r0x00 ] = (volatile-unsigned-bitfield {2,1} fixed)iTemp8 [k16 lr13:14 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{bit fixed}[r0x00 ]
; ;ic:15: 	*(iTemp4 [k11 lr9:15 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]) := iTemp9 [k17 lr14:15 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} fixed}[r0x00 ]
	MOVF	r0x00, W
	ANDLW	0x01
	RLNCF	WREG, W
	RLNCF	WREG, W
	MOVWF	PRODH
	BANKSEL	_Flag1
	MOVF	_Flag1, W, B
	ANDLW	0xfb
	IORWF	PRODH, W
	BANKSEL	_Flag1
	MOVWF	_Flag1, B
; ;ic:16: 	iTemp17 [k29 lr16:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_i_1_2}[r0x00 r0x01 ] := 0x0 {unsigned-int literal}
	.line	41; test.c	for(i=0; i<10; i++) F4ms = ~F4ms;
	CLRF	r0x00
	CLRF	r0x01
; ;ic:18:  _forcond_0($4) :
; ;ic:19: 	iTemp13 [k24 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp17 [k29 lr16:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_i_1_2}[r0x00 r0x01 ] < 0xa {unsigned-int literal}
_00108_DS_:
	MOVLW	0x00
	SUBWF	r0x01, W
	BNZ	_00133_DS_
	MOVLW	0x0a
	SUBWF	r0x00, W
_00133_DS_:
	BC	_00111_DS_
; ;ic:20: 	if iTemp13 [k24 lr19:20 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _forbreak_0($7)
; ;ic:21: 	iTemp14 [k25 lr21:22 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] = &[_Flag1 [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct __00000158 fixed}]
; ;ic:22: 	iTemp15 [k27 lr22:23 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] := iTemp14 [k25 lr21:22 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]
; ;ic:23: 	*(iTemp15 [k27 lr22:23 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]) := 0x1 {volatile-unsigned-bitfield {2,1} literal}
	BANKSEL	_Flag1
	BSF	_Flag1, 2, B
; ;ic:24: 	iTemp17 [k29 lr16:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_i_1_2}[r0x00 r0x01 ] = iTemp17 [k29 lr16:25 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_i_1_2}[r0x00 r0x01 ] + 0x1 {const-unsigned-char literal}
	INFSNZ	r0x00, F
	INCF	r0x01, F
; ;ic:25: 	 goto _forcond_0($4)
	BRA	_00108_DS_
; ;ic:26:  _forbreak_0($7) :
; ;ic:27: 	iTemp23 [k37 lr27:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_j_1_2}[r0x00 r0x01 ] := 0x0 {unsigned-int literal}
_00111_DS_:
	.line	43; test.c	for(j=0; j<100; j++) F4ms = ~F4ms;
	CLRF	r0x00
	CLRF	r0x01
; ;ic:29:  _forcond_1($8) :
; ;ic:30: 	iTemp19 [k32 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp23 [k37 lr27:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_j_1_2}[r0x00 r0x01 ] < 0x64 {unsigned-int literal}
_00112_DS_:
	MOVLW	0x00
	SUBWF	r0x01, W
	BNZ	_00134_DS_
	MOVLW	0x64
	SUBWF	r0x00, W
_00134_DS_:
	BC	_00123_DS_
; ;ic:31: 	if iTemp19 [k32 lr30:31 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto preHeaderLbl2($19)
; ;ic:32: 	iTemp20 [k33 lr32:33 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] = &[_Flag1 [k5 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{volatile-struct __00000158 fixed}]
; ;ic:33: 	iTemp21 [k35 lr33:34 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat] := iTemp20 [k33 lr32:33 so:0]{ ia0 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]
; ;ic:34: 	*(iTemp21 [k35 lr33:34 so:0]{ ia1 a2p0 re0 rm1 nos0 ru0 dp0}{volatile-unsigned-bitfield {2,1} near* fixed}[remat]) := 0x1 {volatile-unsigned-bitfield {2,1} literal}
	BANKSEL	_Flag1
	BSF	_Flag1, 2, B
; ;ic:35: 	iTemp23 [k37 lr27:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_j_1_2}[r0x00 r0x01 ] = iTemp23 [k37 lr27:36 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-int fixed}{ sir@ _main_j_1_2}[r0x00 r0x01 ] + 0x1 {const-unsigned-char literal}
	INFSNZ	r0x00, F
	INCF	r0x01, F
; ;ic:36: 	 goto _forcond_1($8)
	BRA	_00112_DS_
; ;ic:37:  preHeaderLbl2($19) :
; ;ic:38: 	iTemp26 [k40 lr38:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ _main_a_1_2}[r0x00 ] := 0x1 {const-unsigned-char literal}
_00123_DS_:
	.line	46; test.c	while(a==3)
	MOVLW	0x01
	MOVWF	r0x00
; ;ic:39: 	iTemp27 [k41 lr39:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char register}{ sir@ _main_b_1_2}[r0x01 ] := 0x2 {const-unsigned-char literal}
	MOVLW	0x02
	MOVWF	r0x01
; ;ic:41:  _whilecontinue_0($1) :
; ;ic:42: 	iTemp24 [k38 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} = iTemp26 [k40 lr38:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ _main_a_1_2}[r0x00 ] == 0x3 {const-unsigned-char literal}
_00105_DS_:
	MOVF	r0x00, W
	XORLW	0x03
	BNZ	_00116_DS_
; ;ic:43: 	if iTemp24 [k38 lr42:43 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{char fixed} == 0 goto _return($12)
; ;ic:44: 	iTemp26 [k40 lr38:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ _main_a_1_2}[r0x00 ] = iTemp26 [k40 lr38:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char fixed}{ sir@ _main_a_1_2}[r0x00 ] + 0x1 {const-unsigned-char literal}
	.line	48; test.c	a++;
	INCF	r0x00, F
; ;ic:45: 	iTemp27 [k41 lr39:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char register}{ sir@ _main_b_1_2}[r0x01 ] = iTemp27 [k41 lr39:46 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{unsigned-char register}{ sir@ _main_b_1_2}[r0x01 ] + 0x2 {const-unsigned-char literal}
	.line	49; test.c	b = b + 2;
	INCF	r0x01, F
	INCF	r0x01, F
; ;ic:46: 	 goto _whilecontinue_0($1)
	.line	50; test.c	c = a + b;
	BRA	_00105_DS_
; ;ic:47:  _return($12) :
; ;ic:48: 	eproc _main [k1 lr0:0 so:0]{ ia0 a2p0 re0 rm0 nos0 ru0 dp0}{void function ( ) fixed}
_00116_DS_:
	RETURN	



; Statistics:
; code size:	  134 (0x0086) bytes ( 0.10%)
;           	   67 (0x0043) words
; udata size:	    3 (0x0003) bytes ( 4.69%)
; access size:	    2 (0x0002) bytes


	end
