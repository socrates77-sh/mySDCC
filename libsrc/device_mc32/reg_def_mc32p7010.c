#include "reg_def.h"

#define SET_BITS(x, n, of) (~((~(((-1) << (n)) | (x))) << (of))) & 0xFFFF

const struct reg_def all_reg[] = {
	{"INDF0", 0x0180, 1, {{"INDF00", 1}, {"INDF01", 1}, {"INDF02", 1}, {"INDF03", 1}, {"INDF04", 1}, {"INDF05", 1}, {"INDF06", 1}, {"INDF07", 1}}},
	{"INDF1", 0x0181, 1, {{"INDF10", 1}, {"INDF11", 1}, {"INDF12", 1}, {"INDF13", 1}, {"INDF14", 1}, {"INDF15", 1}, {"INDF16", 1}, {"INDF17", 1}}},
	{"INDF2", 0x0182, 1, {{"INDF20", 1}, {"INDF21", 1}, {"INDF22", 1}, {"INDF23", 1}, {"INDF24", 1}, {"INDF25", 1}, {"INDF26", 1}, {"INDF27", 1}}},
	{"HIBYTE", 0x0183, 1, {{"HIBYTE0", 1}, {"HIBYTE1", 1}, {"HIBYTE2", 1}, {"HIBYTE3", 1}, {"HIBYTE4", 1}, {"HIBYTE5", 1}, {"HIBYTE6", 1}, {"HIBYTE7", 1}}},
	{"FSR0", 0x0184, 1, {{"FSR00", 1}, {"FSR01", 1}, {"FSR02", 1}, {"FSR03", 1}, {"FSR04", 1}, {"FSR05", 1}, {"FSR06", 1}, {"FSR07", 1}}},
	{"FSR1", 0x0185, 1, {{"FSR10", 1}, {"FSR11", 1}, {"FSR12", 1}, {"FSR13", 1}, {"FSR14", 1}, {"FSR15", 1}, {"FSR16", 1}, {"FSR17", 1}}},
	{"PCL", 0x0186, 1, {{"PC0", 1}, {"PC1", 1}, {"PC2", 1}, {"PC3", 1}, {"PC4", 1}, {"PC5", 1}, {"PC6", 1}, {"PC7", 1}}},
	{"PFLAG", 0x0187, 1, {{"C", 1}, {"DC", 1}, {"Z", 1}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}}},
	{"MCR", 0x0188, 1, {{"MINT00", 1}, {"MINT01", 1}, {"MINT10", 1}, {"MINT11", 1}, {"PD", 1}, {"TO", 1}, {"", 0}, {"GIE", 1}}},
	{"INDF3", 0x0189, 1, {{"INDF30", 1}, {"INDF31", 1}, {"INDF32", 1}, {"INDF33", 1}, {"INDF34", 1}, {"INDF35", 1}, {"INDF36", 1}, {"INDF37", 1}}},
	{"INTE", 0x018a, 1, {{"T0IE", 1}, {"T1IE", 1}, {"INT0IE", 1}, {"INT1IE", 1}, {"KBIE", 1}, {"", 0}, {"ADIE", 1}, {"", 0}}},
	{"INTF", 0x018b, 1, {{"T0IF", 1}, {"T1IF", 1}, {"INT0IF", 1}, {"INT1IF", 1}, {"KBIF", 1}, {"", 0}, {"ADIF", 1}, {"", 0}}},
	{"IOP0", 0x0190, 1, {{"P00D", 1}, {"P01D", 1}, {"P02D", 1}, {"P03D", 1}, {"P04D", 1}, {"", 0}, {"", 0}, {"", 0}}},
	{"OEP0", 0x0191, 1, {{"P00OE", 1}, {"P01OE", 1}, {"P02OE", 1}, {"P03OE", 1}, {"P04OE", 1}, {"", 0}, {"", 0}, {"", 0}}},
	{"PUP0", 0x0192, 1, {{"P00PU", 1}, {"P01PU", 1}, {"P02PU", 1}, {"P03PU", 1}, {"P04PU", 1}, {"", 0}, {"", 0}, {"", 0}}},
	{"ANSEL", 0x0193, 1, {{"P00ANS", 1}, {"P01ANS", 1}, {"P02ANS", 1}, {"P03ANS", 1}, {"P04ANS", 1}, {"P12ANS", 1}, {"P13ANS", 1}, {"", 0}}},
	{"IOP1", 0x0194, 1, {{"P10D", 1}, {"P11D", 1}, {"P12D", 1}, {"P13D", 1}, {"P14D", 1}, {"P15D", 1}, {"P16D", 1}, {"", 0}}},
	{"OEP1", 0x0195, 1, {{"P10OE", 1}, {"P11OE", 1}, {"P12OE", 1}, {"P13OE", 1}, {"P14OE", 1}, {"P15OE", 1}, {"P16OE", 1}, {"", 0}}},
	{"PUP1", 0x0196, 1, {{"P10PU", 1}, {"P11PU", 1}, {"P12PU", 1}, {"P13PU", 1}, {"P14PU", 1}, {"P15PU", 1}, {"P16PU", 1}, {"", 0}}},
	{"KBCR", 0x0197, 1, {{"KBCR0", 1}, {"KBCR1", 1}, {"KBCR2", 1}, {"KBCR3", 1}, {"KBCR4", 1}, {"KBCR5", 1}, {"KBCR6", 1}, {"", 0}}},
	{"T0CR", 0x01a0, 1, {{"T0PR0", 1}, {"T0PR1", 1}, {"T0PR2", 1}, {"T0PTS0", 1}, {"T0PTS1", 1}, {"BUZ0OE", 1}, {"PWM0OE", 1}, {"TC0EN", 1}}},
	{"T0CNT", 0x01a1, 1, {{"T0C0", 1}, {"T0C1", 1}, {"T0C2", 1}, {"T0C3", 1}, {"T0C4", 1}, {"T0C5", 1}, {"T0C6", 1}, {"T0C7", 1}}},
	{"T0LOAD", 0x01a2, 1, {{"T0LOAD0", 1}, {"T0LOAD1", 1}, {"T0LOAD2", 1}, {"T0LOAD3", 1}, {"T0LOAD4", 1}, {"T0LOAD5", 1}, {"T0LOAD6", 1}, {"T0LOAD7", 1}}},
	{"T0DATA", 0x01a3, 1, {{"T0DATA0", 1}, {"T0DATA1", 1}, {"T0DATA2", 1}, {"T0DATA3", 1}, {"T0DATA4", 1}, {"T0DATA5", 1}, {"T0DATA6", 1}, {"T0DATA7", 1}}},
	{"T1CR", 0x01a4, 1, {{"T1PR0", 1}, {"T1PR1", 1}, {"T1PR2", 1}, {"T1PTS0", 1}, {"T1PTS1", 1}, {"BUZ1OE", 1}, {"PWM1OE", 1}, {"TC1EN", 1}}},
	{"T1CNT", 0x01a5, 1, {{"T1C0", 1}, {"T1C1", 1}, {"T1C2", 1}, {"T1C3", 1}, {"T1C4", 1}, {"T1C5", 1}, {"T1C6", 1}, {"T1C7", 1}}},
	{"T1LOAD", 0x01a6, 1, {{"T1LOAD0", 1}, {"T1LOAD1", 1}, {"T1LOAD2", 1}, {"T1LOAD3", 1}, {"T1LOAD4", 1}, {"T1LOAD5", 1}, {"T1LOAD6", 1}, {"T1LOAD7", 1}}},
	{"T1DATA", 0x01a7, 1, {{"T1DATA0", 1}, {"T1DATA1", 1}, {"T1DATA2", 1}, {"T1DATA3", 1}, {"T1DATA4", 1}, {"T1DATA5", 1}, {"T1DATA6", 1}, {"T1DATA7", 1}}},
	{"OSCM", 0x01ae, 1, {{"HFEN", 1}, {"LFEN", 1}, {"CLKS", 1}, {"", 0}, {"STBH", 1}, {"STBL", 1}, {"", 0}, {"", 0}}},
	{"LVDCR", 0x01af, 1, {{"LVDF", 1}, {"", 0}, {"", 0}, {"", 0}, {"LVDS0", 1}, {"LVDS1", 1}, {"LVDS2", 1}, {"LVDEN", 1}}},
	{"ADCR0", 0x01b0, 1, {{"ADON", 1}, {"ADEOC", 1}, {"ADCKS0", 1}, {"ADCKS1", 1}, {"ADCHS0", 1}, {"ADCHS1", 1}, {"ADCHS2", 1}, {"ADCHS3", 1}}},
	{"ADCR1", 0x01b1, 1, {{"VRS0", 1}, {"VRS1", 1}, {"VRS2", 1}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}}},
	{"ADRH", 0x01b4, 1, {{"ADR4", 1}, {"ADR5", 1}, {"ADR6", 1}, {"ADR7", 1}, {"ADR8", 1}, {"ADR9", 1}, {"ADR10", 1}, {"ADR11", 1}}},
	{"ADRL", 0x01b5, 1, {{"ADR0", 1}, {"ADR1", 1}, {"ADR2", 1}, {"ADR3", 1}, {"", 0}, {"", 0}, {"", 0}, {"", 0}}},
	{"OSCCAL", 0x01fb, 1, {{"OSCCAL0", 1}, {"OSCCAL1", 1}, {"OSCCAL2", 1}, {"OSCCAL3", 1}, {"OSCCAL4", 1}, {"OSCCAL5", 1}, {"OSCCAL6", 1}, {"OSCCAL7", 1}}}
};

const int num_reg = sizeof(all_reg) / sizeof(all_reg[0]);

const int maxram = 0x1ff;
const int badram[][2] = { {0x80, 0x17f}, {0x18c, 0x18f}, {0x198, 0x19f}, {0x1a8, 0x1ac},
						  {0x1af, 0x1af}, {0x1b2, 0x1b3}, {0x1b6, 0x1fa}, {0x1fc, 0x1ff},
						  {-1, -1} };

const struct bit_def config1[] = {};
const int num_config1 = sizeof(config1) / sizeof(config1[0]);
const int config1_addr = 0x8001;

const struct bit_def config0[] = {};
const int num_config0 = sizeof(config0) / sizeof(config0[0]);
const int config0_addr = 0x8000;
