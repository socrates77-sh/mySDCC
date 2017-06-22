#ifndef __SN8P2711B__H
#define __SN8P2711B__H

void _ClearWatchDogTimer(void);
void _ClrRAM(void);

#define NOP(X)  	__asm{	_NOP X }
#define LOG(X)  	__asm{	LOG CNameToAsmLabel(X) }
sfr	HIBYTE = 0x82;
sbit	HIBYTE0 = 0x82:0;
sbit	HIBYTE1 = 0x82:1;
sbit	HIBYTE2 = 0x82:2;
sbit	HIBYTE3 = 0x82:3;
sbit	HIBYTE4 = 0x82:4;
sbit	HIBYTE5 = 0x82:5;
sbit	HIBYTE6 = 0x82:6;
sbit	HIBYTE7 = 0x82:7;

sfr	FSR0 = 0x83;
sbit	FSR00 = 0x83:0;
sbit	FSR01 = 0x83:1;
sbit	FSR02 = 0x83:2;
sbit	FSR03 = 0x83:3;
sbit	FSR04 = 0x83:4;
sbit	FSR05 = 0x83:5;
sbit	FSR06 = 0x83:6;
sbit	FSR07 = 0x83:7;

sfr	FSR1 = 0x84;
sbit	FSR10 = 0x84:0;
sbit	FSR11 = 0x84:1;
sbit	FSR12 = 0x84:2;
sbit	FSR13 = 0x84:3;
sbit	FSR14 = 0x84:4;
sbit	FSR15 = 0x84:5;
sbit	FSR16 = 0x84:6;
sbit	FSR17 = 0x84:7;

sfr	PFLAG = 0x86;
sbit	Z = 0x86:0;
sbit	DC = 0x86:1;
sbit	C = 0x86:2;
sbit	LVD24 = 0x86:4;
sbit	LVD36 = 0x86:5;
sbit	NPD = 0x86:6;
sbit	NT0 = 0x86:7;

sfr	ANSEL = 0xae;
sbit	P40ANS = 0xae:0;
sbit	P41ANS = 0xae:1;
sbit	P42ANS = 0xae:2;
sbit	P43ANS = 0xae:3;
sbit	P44ANS = 0xae:4;

sfr	VREF = 0xaf;
sbit	VRS0 = 0xaf:0;
sbit	VRS1 = 0xaf:1;
sbit	VREFS = 0xaf:7;

sfr	ADCR = 0xB1;
sbit	ADON = 0xB1:7;
sbit	ADST = 0xB1:6;
sbit	ADEOC = 0xB1:5;
sbit	GCHS = 0xB1:4;
sbit	ADCHS2 = 0xB1:2;
sbit	ADCHS1 = 0xB1:1;
sbit	ADCHS0 = 0xB1:0;

sfr	ADRH = 0xb2;
sbit	ADR4 = 0xb2:0;
sbit	ADR5 = 0xb2:1;
sbit	ADR6 = 0xb2:2;
sbit	ADR7 = 0xb2:3;
sbit	ADR8 = 0xb2:4;
sbit	ADR9 = 0xb2:5;
sbit	ADR10 = 0xb2:6;
sbit	ADR11 = 0xb2:7;

sfr	ADRL = 0xb3;
sbit	ADCKS1 = 0xb3:6;
sbit	ADCKS0 = 0xb3:4;
sbit	ADR3 = 0xb3:3;
sbit	ADR1 = 0xb3:2;
sbit	ADR2 = 0xb3:1;
sbit	ADR0 = 0xb3:0;

sfr	OEP0 = 0xb8;
sbit	P00OE = 0xb8:0;
sbit	P01OE = 0xb8:1;
sbit	P02OE = 0xb8:2;
sbit	P03OE = 0xb8:3;
	
sfr	PEDGE = 0xbf;
sbit	MINT01 = 0xbf:4;
sbit	MINT00 = 0xbf:3;

sfr	OEP4 = 0xc4;
sbit	P40OE = 0xc4:0;
sbit	P41OE = 0xc4:1;
sbit	P42OE = 0xc4:2;
sbit	P43OE = 0xc4:3;
sbit	P44OE = 0xc4:4;

sfr	OEP5 = 0xc5;
sbit	P53OE = 0xc5:3;
sbit	P54OE = 0xc5:4;

sfr	INTF = 0xc8;
sbit	INT0IF = 0xc8:0;
sbit	INT1IF = 0xc8:1;
sbit	T0IF = 0xc8:5;
sbit	T1IF = 0xc8:6;
sbit	ADIF = 0xc8:7;

sfr	INTE = 0xc9;
sbit	INT0IE = 0xc9:0;
sbit	INT1IE = 0xc9:1;
sbit	T0IE = 0xc9:5;
sbit	T1IE = 0xc9:6;
sbit	ADIE = 0xc9:7;

sfr	OSCM = 0xca;
sbit	CPUM1 = 0xca:4;
sbit	CPUM0 = 0xca:3;
sbit	CLKS = 0xca:2;
sbit	HOFF = 0xca:1;

sfr	WDTR = 0xcc;
sbit	WDTR0 = 0xcc:0;
sbit	WDTR1 = 0xcc:1;
sbit	WDTR2 = 0xcc:2;
sbit	WDTR3 = 0xcc:3;
sbit	WDTR4 = 0xcc:4;
sbit	WDTR5 = 0xcc:5;
sbit	WDTR6 = 0xcc:6;
sbit	WDTR7 = 0xcc:7;

sfr	T0D = 0xcd;
sbit	T0D0 = 0xcd:0;
sbit	T0D1 = 0xcd:1;
sbit	T0D2 = 0xcd:2;
sbit	T0D3 = 0xcd:3;
sbit	T0D4 = 0xcd:4;
sbit	T0D5 = 0xcd:5;
sbit	T0D6 = 0xcd:6;
sbit	T0D7 = 0xcd:7;

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

sfr	IOP0 = 0xd0;
sbit	P00D = 0xd0:0;
sbit	P01D = 0xd0:1;
sbit	P02D = 0xd0:2;
sbit	P03D = 0xd0:3;
sbit	P04D = 0xd0:4;

sfr	IOP4 = 0xd4;
sbit	P40D = 0xd4:0;
sbit	P41D = 0xd4:1;
sbit	P42D = 0xd4:2;
sbit	P43D = 0xd4:3;
sbit	P44D = 0xd4:4;

sfr	IOP5 = 0xd5;
sbit	P53D = 0xd5:3;
sbit	P54D = 0xd5:4;

sfr	TXCR = 0xd8;
sbit	T0GE = 0xd8:1;
sbit	T0PTSX = 0xd8:2;
sbit	T1PTSX = 0xd8:3;

sfr	T0CR = 0xda;
sbit	TC0EN = 0xda:7;
sbit	T0PR2 = 0xda:6;
sbit	T0PR1 = 0xda:5;
sbit	T0PR0 = 0xda:4;
sbit	T0PTS = 0xda:3;
sbit	T0ALOAD = 0xda:2;
sbit	BUZ0OE = 0xda:1;
sbit	PWM0OE = 0xda:0;

sfr	T0C = 0xdb;
sbit  T0C0 = 0xdb:0;
sbit  T0C1 = 0xdb:1;
sbit  T0C2 = 0xdb:2;
sbit  T0C3 = 0xdb:3;
sbit  T0C4 = 0xdb:4;
sbit  T0C5 = 0xdb:5;
sbit  T0C6 = 0xdb:6;
sbit  T0C7 = 0xdb:7;

sfr	T1CR = 0xdc;
sbit	TC1EN = 0xdc:7;
sbit	T1PR2 = 0xdc:6;
sbit	T1PR1 = 0xdc:5;
sbit	T1PR0 = 0xdc:4;
sbit	T1PTS = 0xdc:3;
sbit	T1ALOAD = 0xdc:2;
sbit	BUZ1OE = 0xdc:1;
sbit	PWM1OE = 0xdc:0;

sfr	T1C = 0xdd;
sbit	T1C0 = 0xdd:0;
sbit	T1C1 = 0xdd:1;
sbit	T1C2 = 0xdd:2;
sbit	T1C3 = 0xdd:3;
sbit	T1C4 = 0xdd:4;
sbit	T1C5 = 0xdd:5;
sbit	T1C6 = 0xdd:6;
sbit	T1C7 = 0xdd:7;

sfr	T1D = 0xde;
sbit  T1D0 =0xde:0;
sbit  T1D1 =0xde:1;
sbit  T1D2 =0xde:2;
sbit  T1D3 =0xde:3;
sbit  T1D4 =0xde:4;
sbit  T1D5 =0xde:5;
sbit  T1D6 =0xde:6;
sbit  T1D7 =0xde:7;

sfr	STKP = 0xdf;
sbit	GIE = 0xdf:7;
sbit	STKP2 = 0xdf:2;
sbit	STKP1 = 0xdf:1;
sbit	STKP0 = 0xdf:0;

sfr	PUP0 = 0xe0;
sbit	P00PU = 0xe0:0;
sbit	P01PU = 0xe0:1;
sbit	P02PU = 0xe0:2;
sbit	P03PU = 0xe0:3;

sfr	PUP4 = 0xe4;
sbit	P40PU = 0xe4:0;
sbit	P41PU = 0xe4:1;
sbit	P42PU = 0xe4:2;
sbit	P43PU = 0xe4:3;
sbit	P44PU = 0xe4:4;

sfr	PUP5 = 0xe5;
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

sfr	STK3L = 0xf8;
sfr	STK3H = 0xf9;
sfr	STK2L = 0xfa;
sfr	STK2H = 0xfb;
sfr	STK1L = 0xfc;
sfr	STK1H = 0xfd;
sfr	STK0L = 0xfe;
sfr	STK0H = 0xff;
#endif
