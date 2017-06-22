#ifndef __SN8P2711B__H
#define __SN8P2711B__H

void _ClearWatchDogTimer(void);
void _ClrRAM(void);

#define NOP(X)  	__asm{	_NOP X }
#define LOG(X)  	__asm{	LOG CNameToAsmLabel(X) }
sfr	HIBYTE = 0x82;
sfr	FSR0 = 0x83;
sfr	FSR1 = 0x84;

sfr	PFLAG = 0x86;
sbit	Z = 0x86:0;
sbit	DC = 0x86:1;
sbit	C = 0x86:2;
sbit	LVD24 = 0x86:4;
sbit	LVD36 = 0x86:5;
sbit	NPD = 0x86:6;
sbit	NT0 = 0x86:7;
	
sfr	ZEROTR = 0x8e;
sbit	ZEROTR0 = 0x8e:0;
sbit	ZEROTR1 = 0x8e:1;
sbit	ZEROTR2 = 0x8e:2;
sbit	ZEROTR3 = 0x8e:3;
sbit	ZEROTR4 = 0x8e:4;
sbit	Z0TEN0 = 0x8e:6;
sbit	Z0TEN1 = 0x8e:7;
	
sfr	OSCCAL = 0x8f;
sbit	OSCCAL0 = 0x8f:0;
sbit	OSCCAL1 = 0x8f:1;
sbit	OSCCAL2 = 0x8f:2;
sbit	OSCCAL3 = 0x8f:3;
sbit	OSCCAL4 = 0x8f:4;
sbit	OSCCAL5 = 0x8f:5;
sbit	OSCCAL6 = 0x8f:6;
sbit	OSCCAL7 = 0x8f:7;
	
sfr	WKCR0 = 0xa0;
sbit	P00WK = 0xa0:0;
sbit	P01WK = 0xa0:1;
sbit	P02WK = 0xa0:2;
sbit	P03WK = 0xa0:3;
sbit	P04WK = 0xa0:4;
sbit	P05WK = 0xa0:5;
sbit	P06WK = 0xa0:6;
sbit	P07WK = 0xa0:7;
	
sfr	WKCR5 = 0xa5;
sbit	P50WK = 0xa5:0;
sbit	P51WK = 0xa5:1;
sbit	P52WK = 0xa5:2;
sbit	P53WK = 0xa5:3;
sbit	P54WK = 0xa5:4;
	
sfr	ADIOS0 =0xad;
sbit	AN5EN = 0xad:0;
sbit	AN9EN = 0xad:7;
	
sfr	ADIOS1 =0xae;
sbit	AN8EN = 0xae:2;
sbit	AN7EN = 0xae:3;
sbit	AN6EN = 0xae:4;
	
sfr	ADIOS2 =0xaf;
sbit	AN0EN = 0xaf:0;
sbit	AN1EN = 0xaf:1;
sbit	AN2EN = 0xaf:2;
sbit	AN3EN = 0xaf:3;
sbit	AN4EN = 0xaf:4;

sfr	ADCR0 = 0xB1;
sbit	ADEN = 0xB1:7;
sbit	ADSTR = 0xB1:6;
sbit	ADEOC = 0xB1:5;
sbit	GCHS = 0xB1:4;
sbit	ADCHS3 = 0xB1:3;
sbit	ADCHS2 = 0xB1:2;
sbit	ADCHS1 = 0xB1:1;
sbit	ADCHS0 = 0xB1:0;
	
sfr	ADCR1 = 0xB2;
sbit 	ADSPS0 = 0xb2:0;
sbit 	ADSPS1 = 0xb2:1;
sbit 	ADSPS2 = 0xb2:2;
sbit 	ADSPS3 = 0xb2:3;
sbit 	ADCKS0 = 0xb2:4;
sbit 	ADCKS1 = 0xb2:5;
sbit 	ADCKS2 = 0xb2:6;
sbit 	ADRSEL = 0xb2:7;

sfr	ADRH = 0xb3;
sbit	ADR8 = 0xb3:0;
sbit	ADR9 = 0xb3:1;
sbit	ADR10 = 0xb3:2;
sbit	ADR11 = 0xb3:3;
	
sfr	ADRL = 0xb4;
sbit	ADR0 = 0xb4:0;
sbit	ADR1 = 0xb4:1;
sbit	ADR2 = 0xb4:2;
sbit	ADR3 = 0xb4:3;
sbit	ADR4 = 0xb4:4;
sbit	ADR5 = 0xb4:5;
sbit	ADR6 = 0xb4:6;
sbit	ADR7 = 0xb4:7;
	
sfr	ADCR2 = 0xb5;
sbit	VRS0 = 0xb5:0;
sbit	VRS1 = 0xb5:1;
sbit	EVRS = 0xb5:7;
	
sfr	OEP0 = 0xb8;
sbit	P00OE = 0xb8:0;
sbit	P01OE = 0xb8:1;
sbit	P02OE = 0xb8:2;
sbit	P03OE = 0xb8:3;
sbit	P04OE = 0xb8:4;	
sbit	P05OE = 0xb8:5;
sbit	P06OE = 0xb8:6;
sbit	P07OE = 0xb8:7;	
	
sfr	EINTCR = 0xbf;
sbit	MINT00 = 0xbf:3;
sbit	MINT01 = 0xbf:4;
		
sfr	OEP4 = 0xc4;
sbit	P40OE = 0xc4:0;
sbit	P41OE = 0xc4:1;
sbit	P42OE = 0xc4:2;
sbit	P43OE = 0xc4:3;
sbit	P44OE = 0xc4:4;	
	
sfr	OEP5 = 0xc5;
sbit	P50OE = 0xc5:0;
sbit	P51OE = 0xc5:1;
sbit	P52OE = 0xc5:2;
sbit	P53OE = 0xc5:3;
sbit	P54OE = 0xc5:4;
	
sfr	INTF = 0xc8;
sbit	INT0IF = 0xc8:0;
sbit	PWMIF = 0xc8:3;
sbit	T0IF = 0xc8:4;
sbit	T1IF = 0xc8:5;
sbit	ADIF = 0xc8:7;
	
sfr	INTE = 0xc9;
sbit	INT0IE = 0xc9:0;
sbit	PWMIE = 0xc9:3;	
sbit	T0IE = 0xc9:4;
sbit	T1IE = 0xc9:5;
sbit	ADIE = 0xc9:7;
	
sfr	OSCM = 0xca;
sbit	CPUM1 = 0xca:4;
sbit	CPUM0 = 0xca:3;
sbit	CLKS = 0xca:2;
sbit	HFDE = 0xca:1;
	
sfr	WDTCR = 0xcc;
sbit	WDTCR0 = 0xcc:0;
sbit	WDTCR1 = 0xcc:1;
sbit	WDTCR2 = 0xcc:2;
sbit	WDTCR3 = 0xcc:3;
sbit	WDTCR4 = 0xcc:4;
sbit	WDTCR5 = 0xcc:5;
sbit	WDTCR6 = 0xcc:6;
sbit	WDTCR7 = 0xcc:7;

sfr	T1LDR = 0xcd;
sbit	T1LDR0 = 0xcd:0;
sbit	T1LDR1 = 0xcd:1;
sbit	T1LDR2 = 0xcd:2;
sbit	T1LDR3 = 0xcd:3;
sbit	T1LDR4 = 0xcd:4;
sbit	T1LDR5 = 0xcd:5;
sbit	T1LDR6 = 0xcd:6;
sbit	T1LDR7 = 0xcd:7;

sfr	PCL = 0xce;
sbit	PC0 = 0xce:0;
sbit	PC1 = 0xce:1;
sbit	PC2 = 0xce:2;
sbit	PC3 = 0xce:3;
sbit	PC4 = 0xce:4;
sbit	PC5 = 0xce:5;
sbit	PC6 = 0xce:6;
sbit	PC7 = 0xce:7;

sfr	PCH = 0xcf;
sbit	PC8 = 0xcf:0;
sbit	PC9 = 0xcf:1;
sbit	PC10 = 0xcf:2;

sfr	IOP0 = 0xd0;
sbit	P00D = 0xd0:0;
sbit	P01D = 0xd0:1;
sbit	P02D = 0xd0:2;
sbit	P03D = 0xd0:3;
sbit	P04D = 0xd0:4;
sbit	P05D = 0xd0:5;
sbit	P06D = 0xd0:6;
sbit	P07D = 0xd0:7;
	
sfr	IOP4 = 0xd4;
sbit	P40D = 0xd4:0;
sbit	P41D = 0xd4:1;
sbit	P42D = 0xd4:2;
sbit	P43D = 0xd4:3;
sbit	P44D = 0xd4:4;
	
sfr	IOP5 = 0xd5;
sbit	P50D = 0xd5:0;
sbit	P51D = 0xd5:1;
sbit	P52D = 0xd5:2;
sbit	P53D = 0xd5:3;
sbit	P54D = 0xd5:4;
	
sfr	T0CR = 0xd8;
sbit	T1CKS1 = 0xd8:2;
sbit	T1CKS2 = 0xd8:3;
sbit	T0PRS0 = 0xd8:4;	
sbit	T0PRS1 = 0xd8:5;	
sbit	T0PRS2 = 0xd8:6;	
sbit	T0EN = 0xd8:7;
	
sfr	T0CNT = 0xd9;
sbit	T0CNT0 = 0xd9:0;
sbit	T0CNT1 = 0xd9:1;
sbit	T0CNT2 = 0xd9:2;
sbit	T0CNT3 = 0xd9:3;
sbit	T0CNT4 = 0xd9:4;
sbit	T0CNT5 = 0xd9:5;
sbit	T0CNT6 = 0xd9:6;
sbit	T0CNT7 = 0xd9:7;
	
sfr	T1CR = 0xda;
sbit	PWM1OE = 0xda:0;
sbit	BUZ1OE = 0xda:1;
sbit	T1LDEN = 0xda:2;
sbit	T1CKS0 = 0xda:3;
sbit	T1PRS0 = 0xda:4;
sbit	T1PRS1 = 0xda:5;
sbit	T1PRS2 = 0xda:6;
sbit	T1EN   = 0xda:7;

sfr	T1CNT = 0xdb; 
sbit	T1CNT0 = 0xdb:0;
sbit	T1CNT1 = 0xdb:1;
sbit	T1CNT2 = 0xdb:2;
sbit	T1CNT3 = 0xdb:3;
sbit	T1CNT4 = 0xdb:4;
sbit	T1CNT5 = 0xdb:5;
sbit	T1CNT6 = 0xdb:6;
sbit	T1CNT7 = 0xdb:7;

sfr	BUZCR = 0xdc;
sbit	BUZPRS0 = 0xdc:5;
sbit	BUZPRS1 = 0xdc:6;
sbit	BUZEN   = 0xdc:7;

sfr	MCR = 0xdf;
sbit	GIE = 0xdf:7;
sbit	STKP2 = 0xdf:2;
sbit	STKP1 = 0xdf:1;
sbit	STKP0 = 0xdf:0;
	
sfr	PUP0 = 0xe0;
sbit	P00PU = 0xe0:0;
sbit	P01PU = 0xe0:1;
sbit	P02PU = 0xe0:2;
sbit	P03PU = 0xe0:3;
sbit	P04PU = 0xe0:4;
sbit	P05PU = 0xe0:5;
sbit	P06PU = 0xe0:6;
sbit	P07PU = 0xe0:7;

sfr	PUP4 = 0xe4;
sbit	P40PU = 0xe4:0;
sbit	P41PU = 0xe4:1;
sbit	P42PU = 0xe4:2;
sbit	P43PU = 0xe4:3;
sbit	P44PU = 0xe4:4;

sfr	PUP5 = 0xe5;
sbit	P50PU = 0xe5:0;
sbit	P51PU = 0xe5:1;
sbit	P52PU = 0xe5:2;
sbit	P53PU = 0xe5:3;
sbit	P54PU = 0xe5:4;

sfr	INDF = 0xe7;
sbit	INDF0 = 0xe7:0;
sbit	INDF1 = 0xe7:1;
sbit	INDF2 = 0xe7:2;
sbit	INDF3 = 0xe7:3;
sbit	INDF4 = 0xe7:4;
sbit	INDF5 = 0xe7:5;
sbit	INDF6 = 0xe7:6;
sbit	INDF7 = 0xe7:7;

sfr	PWMCR0 = 0xe8;
sbit	PWMAOF = 0xe8:0;
sbit	PWMBOF = 0xe8:1;
sbit	PWMCOF = 0xe8:2;
sbit	PWMPRS0 = 0xe8:4;
sbit	PWMPRS1 = 0xe8:5;
sbit	PWMPRS2 = 0xe8:6;
sbit	PWMEN = 0xe8:7;

sfr	PWMCR1 = 0xe9;
sbit	PWMAOE = 0xe9:5;
sbit	PWMBOE = 0xe9:6;
sbit	PWMCOE = 0xe9:7;

sfr	PWMCNT = 0xea;
sbit	PWMCNT0 = 0xea:0;
sbit	PWMCNT1 = 0xea:1;
sbit	PWMCNT2 = 0xea:2;
sbit	PWMCNT3 = 0xea:3;
sbit	PWMCNT4 = 0xea:4;
sbit	PWMCNT5 = 0xea:5;
sbit	PWMCNT6 = 0xea:6;
sbit	PWMCNT7 = 0xea:7;

sfr	PWMADT = 0xeb;
sbit	PWMADT0 = 0xeb:0;
sbit	PWMADT1 = 0xeb:1;
sbit	PWMADT2 = 0xeb:2;
sbit	PWMADT3 = 0xeb:3;
sbit	PWMADT4 = 0xeb:4;
sbit	PWMADT5 = 0xeb:5;
sbit	PWMADT6 = 0xeb:6;
sbit	PWMADT7 = 0xeb:7;

sfr	PWMBDT = 0xec;
sbit	PWMBDT0 = 0xec:0;
sbit	PWMBDT1 = 0xec:1;
sbit	PWMBDT2 = 0xec:2;
sbit	PWMBDT3 = 0xec:3;
sbit	PWMBDT4 = 0xec:4;
sbit	PWMBDT5 = 0xec:5;
sbit	PWMBDT6 = 0xec:6;
sbit	PWMBDT7 = 0xec:7;

sfr	PWMCDT = 0xed;
sbit	PWMCDT0 = 0xed:0;
sbit	PWMCDT1 = 0xed:1;
sbit	PWMCDT2 = 0xed:2;
sbit	PWMCDT3 = 0xed:3;
sbit	PWMCDT4 = 0xed:4;
sbit	PWMCDT5 = 0xed:5;
sbit	PWMCDT6 = 0xed:6;
sbit	PWMCDT7 = 0xed:7;

sfr	PWMPD = 0xee;
sbit	PWMPD0 = 0xee:0;
sbit	PWMPD1 = 0xee:1;
sbit	PWMPD2 = 0xee:2;
sbit	PWMPD3 = 0xee:3;
sbit	PWMPD4 = 0xee:4;
sbit	PWMPD5 = 0xee:5;
sbit	PWMPD6 = 0xee:6;
sbit	PWMPD7 = 0xee:7;

sfr	STKR0L = 0xf0;
sfr	STKR0H = 0xf1;
sfr	STKR1L = 0xf2;
sfr	STKR1H = 0xf3;
sfr	STKR2L = 0xf4;
sfr	STKR2H = 0xf5;
sfr	STKR3L = 0xf6;
sfr	STKR3H = 0xf7;
sfr	STKR4L = 0xf8;
sfr	STKR4H = 0xf9;
sfr	STKR5L = 0xfa;
sfr	STKR5H = 0xfb;
sfr	STKR6L = 0xfc;
sfr	STKR6H = 0xfd;
sfr	STKR7L = 0xfe;
sfr	STKR7H = 0xff;
#endif
