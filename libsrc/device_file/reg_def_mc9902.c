#include "reg_def.h"
#define SET_BITS(x,n,of) (~((~(((-1) << (n)) | (x))) << (of))) & 0xFFFF

const struct reg_def all_reg[] = {
	{ "INDF",    0x0180, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "INDF0",   0x0180, 1, { {"INDF00", 1}, {"INDF01", 1},  {"INDF02", 1}, {"INDF03", 1}, {"INDF04", 1}, {"INDF05", 1},  {"INDF06", 1}, {"INDF07", 1} } },
	{ "INDF1",   0x0181, 1, { {"INDF10", 1}, {"INDF11", 1},  {"INDF12", 1}, {"INDF13", 1}, {"INDF14", 1}, {"INDF15", 1},  {"INDF16", 1}, {"INDF17", 1} } },
	{ "INDF2",   0x0182, 1, { {"INDF20", 1}, {"INDF21", 1},  {"INDF22", 1}, {"INDF23", 1}, {"INDF24", 1}, {"INDF25", 1},  {"INDF26", 1}, {"INDF27", 1} } },
	{ "HIBYTE",  0x0183, 1, { {"HIBYTE0", 1}, {"HIBYTE1", 1},  {"HIBYTE2", 1}, {"HIBYTE3", 1}, {"HIBYTE4", 1}, {"HIBYTE5", 1},  {"HIBYTE6", 1}, {"HIBYTE7", 1} } },
	{ "FSR",     0x0184, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "FSR0",    0x0184, 1, { {"SFR00", 1}, {"SFR01", 1},  {"SFR02", 1}, {"SFR03", 1}, {"SFR04", 1}, {"SFR05", 1},  {"SFR06", 1}, {"SFR07", 1} } },
	{ "FSR1",    0x0185, 1, { {"SFR10", 1}, {"SFR11", 1},  {"SFR12", 1}, {"SFR13", 1}, {"SFR14", 1}, {"SFR15", 1},  {"SFR16", 1}, {"SFR17", 1} } },
	{ "PCL",     0x0186, 1, { {"PC0", 1}, {"PC1", 1},  {"PC2", 1}, {"PC3", 1}, {"PC4", 1}, {"PC5", 1},  {"PC6", 1}, {"PC7", 1} } },
	{ "PFLAG",  0x0187, 1, 
		{
			{"C", 1}, {"DC", 1},  {"Z", 1}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "MCR",     0x0188, 1, 
		{
			{"MINT00", 1}, {"MINT01", 1},  {"MINT10", 1}, {"MINT11", 1}, 
			{"PD", 1}, {"TO", 1},  {"", 0}, {"GIE", 1}
		}
	},
	{ "INDF3",   0x0189, 1, { {"INDF30", 1}, {"INDF31", 1},  {"INDF32", 1}, {"INDF33", 1}, {"INDF34", 1}, {"INDF35", 1},  {"INDF36", 1}, {"INDF37", 1} } },
	{ "INTE",    0x018a, 1, 
		{
			{"T0IE", 1}, {"T1IE", 1},  {"INT0IE", 1}, {"INT1IE", 1}, 
			{"", 0}, {"IICIE", 1},  {"ADIE", 1}, {"", 0}
		}
	},
	{ "INTF",    0x018b, 1, 
		{
			{"T0IF", 1}, {"T1IF", 1},  {"INT0IF", 1}, {"INT1IF", 1}, 
			{"", 0}, {"IICIF", 1},  {"ADIF", 1}, {"", 0}
		}
	},
	{ "OSCM",    0x018c, 1, 
		{
			{"HFEN", 1}, {"LFEN", 1},  {"CLKS", 1}, {"", 0}, 
			{"STBH", 1}, {"STBL", 1},  {"", 0}, {"", 0}
		}
	},
	{ "LVDCR",    0x018d, 1, 
		{
			{"LVDF", 1}, {"", 0},  {"", 0}, {"VLVDS0", 1}, 
			{"VLVDS1", 1}, {"VLVDS2", 1},  {"VLVDS3", 1}, {"LVDEN", 1}
		}
	},    //insert by lyl
	{ "IOP0",    0x0190, 1, 
		{
			{"P00D", 1}, {"P01D", 1},  {"P02D", 1}, {"P03D", 1}, 
			{"P04D", 1}, {"P05D", 1},  {"P06D", 1}, {"P07D", 1}
		}
	},
	{ "OEP0",    0x0191, 1, 
		{
			{"P00OE", 1}, {"P01OE", 1},  {"P02OE", 1}, {"P03OE", 1}, 
			{"P04OE", 1}, {"P05OE", 1},  {"P06OE", 1}, {"P07OE", 1}
		}
	},
	{ "PUP0",    0x0192, 1, 
		{
			{"P00PU", 1}, {"P01PU", 1},  {"P02PU", 1}, {"P03PU", 1}, 
			{"P04PU", 1}, {"P05PU", 1},  {"P06PU", 1}, {"P07PU", 1}
		}
	},
	{ "RUPSEL",    0x0193, 1, 
		{
			{"", 0}, {"", 0},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"IICRS", 1}
		}
	},//  insert by lyl
	{ "IOP1",    0x0194, 1, 
		{
			{"P10D", 1}, {"P11D", 1},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "OEP1",    0x0195, 1, 
		{
			{"P10OE", 1}, {"P11OE", 1},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "PUP1",    0x0196, 1, 
		{
			{"P10PU", 1}, {"P11PU", 1},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},			///////  
	{ "T0CR",    0x01a0, 1, 
		{
			{"T0PRS0", 1}, {"T0PRS1", 1},  {"T0PRS2", 1}, {"T0CKS0", 1}, 
			{"T0CKS1", 1}, {"BUZ0OE", 1},  {"PWM0OE", 1}, {"T0EN", 1}
		}
	},
	{ "T0CNT",   0x01a1, 1, { {"T0CNT0", 1}, {"T0CNT1", 1},  {"T0CNT2", 1}, {"T0CNT3", 1}, {"T0CNT4", 1}, {"T0CNT5", 1},  {"T0CNT6", 1}, {"T0CNT7", 1} } },
	{ "T0LOAD",  0x01a2, 1, { {"T0LOAD0", 1}, {"T0LOAD1", 1},  {"T0LOAD2", 1}, {"T0LOAD3", 1}, {"T0LOAD4", 1}, {"T0LOAD5", 1},  {"T0LOAD6", 1}, {"T0LOAD7", 1} } },
	{ "T0DATA",  0x01a3, 1, { {"T0DATA0", 1}, {"T0DATA1", 1},  {"T0DATA2", 1}, {"T0DATA3", 1}, {"T0DATA4", 1}, {"T0DATA5", 1},  {"T0DATA6", 1}, {"T0DATA7", 1} } },
	{ "T1CR",    0x01a4, 1, 
		{
			{"T1PRS0", 1}, {"T1PRS1", 1},  {"T1PRS2", 1}, {"T1CKS0", 1}, 
			{"T1CKS1", 1}, {"BUZ1OE", 1},  {"PWM1OE", 1}, {"T1EN", 1}
		}
	},
	{ "T1CNT",   0x01a5, 1, { {"T1CNT0", 1}, {"T1CNT1", 1},  {"T1CNT2", 1}, {"T1CNT3", 1}, {"T1CNT4", 1}, {"T1CNT5", 1},  {"T1CNT6", 1}, {"T1CNT7", 1} } },
	{ "T1LOAD",  0x01a6, 1, { {"T1LOAD0", 1}, {"T1LOAD1", 1},  {"T1LOAD2", 1}, {"T1LOAD3", 1}, {"T1LOAD4", 1}, {"T1LOAD5", 1},  {"T1LOAD6", 1}, {"T1LOAD7", 1} } },
	{ "T1DATA",  0x01a7, 1, { {"T1DATA0", 1}, {"T1DATA1", 1},  {"T1DATA2", 1}, {"T1DATA3", 1}, {"T1DATA4", 1}, {"T1DATA5", 1},  {"T1DATA6", 1}, {"T1DATA7", 1} } },
	{ "ADCR0",   0x01b0, 1, 
		{
			{"ADCHS0", 1}, {"ADCHS1", 1},  {"ADCHS2", 1}, {"ADCHS3", 1}, 
			{"ADCKS0", 1}, {"ADCKS1", 1},  {"CHOPEN", 1}, {"ADEN", 1}
		}
	},
	{ "ADCR1",   0x01b1, 1, 
		{
			{"ADGAS0", 1}, {"ADGAS1", 1},  {"ADGAS2", 1}, {"ADGAS3", 1}, 
			{"ADSPS0", 1}, {"ADSPS1", 1},  {"ADSPS2", 1}, {"ADSPS3", 1}
		}
	},
	{ "ADCR2",   0x01b2, 1, 
		{
			{"ADVRS", 1}, {"LDOEN", 1},  {"VLDOS1", 1}, {"VLDOS0", 1}, 
			{"AD2EN", 1}, {"AD1EN", 1},  {"AD0EN", 1}, {"", 0}
		}
	},				
	{ "ADRH",    0x01b4, 1,
		 { 
			{"ADR16", 1}, {"ADR17", 1},  {"ADR18", 1}, {"ADR19", 1},
			{"ADR20", 1}, {"ADR21", 1},  {"ADR22", 1}, {"ADR23", 1} 
		}
	 },	
	{ "ADRM",    0x01b5, 1, 
		{ 
			{"ADR8", 1}, {"ADR9", 1},  {"ADR10", 1}, {"ADR11", 1}, 
			{"ADR12", 1}, {"ADR13", 1},  {"ADR14", 1}, {"ADR15", 1}
		 }
	 },
	{ "ADRL",    0x01b6, 0,
		 {
			 {"ADR0", 1}, {"ADR1", 1},  {"ADR2", 1}, {"ADR3", 1},
			 {"ADR4", 1}, {"ADR5", 1},  {"ADR6", 1}, {"ADR7", 1}
		 } 
	},
	{ "IICCR",   0x01b8, 1, 
		{
			{"RACK", 1}, {"IICEN", 1},  {"MSTCMD", 1}, {"SACK", 1}, 
			{"IICM0D", 1}, {"IICBUSY", 1},  {"IICAAS", 1}, {"IICE0F", 1}
		}
	},
	{ "IICAR", 0x01b9, 1, { {"", 0}, {"IICAD0", 1},  {"IICAD1", 1}, {"IICAD2", 1}, {"IICAD3", 1}, {"IICAD4", 1},  {"IICAD5", 1}, {"IICAD6", 1} } },
	{ "IICDR", 0x01ba, 1, { {"IICDT0", 1}, {"IICDT1", 1},  {"IICDT2", 1}, {"IICDT3", 1}, {"IICDT4", 1}, {"IICDT5", -1},  {"IICDT6", 1}, {"IICDT7", 1} } }
};

const int num_reg = sizeof(all_reg) / sizeof(all_reg[0]);

const int maxram = 0x1ff;
const int badram[][2] = { {0x80, 0x17f}, {0x18e, 0x18f}, {0x197, 0x197}, {0x198, 0x19f}, {0x1a8, 0x1af},
			 {0x1b3, 0x1b3}, {0x1b7, 0x1b7},{0x1bb,0x1bf},{0x1c0,0x1ff}, {-1, -1} };

const struct bit_def config1[] = {
};

const int num_config1 = sizeof(config1) / sizeof(config1[0]);
const int config1_addr = 0x0fed;
/*
const struct bit_def config0[] = {
	{"_CP_ALL",              SET_BITS(0, 1, 15)},
	{"_WDT_ALWAYS_OFF",      SET_BITS(0, 2, 0)},
	{"_WDT_SLEEP_OFF",       SET_BITS(1, 2, 0)},
	{"_WDT_ALWAYS_ON",       SET_BITS(3, 2, 0)},
	{"_PTWRT_4_4",           SET_BITS(0, 1, 13) & SET_BITS(0, 2, 2)},
	{"_PTWRT_16_16",         SET_BITS(0, 1, 13) & SET_BITS(1, 2, 2)},
	{"_PTWRT_64_64",         SET_BITS(0, 1, 13) & SET_BITS(2, 2, 2)},
	{"_PTWRT_256_256",       SET_BITS(0, 1, 13) & SET_BITS(3, 2, 2)},
	{"_PTWRT_4_512",         SET_BITS(0, 2, 2)},
	{"_PTWRT_16_1024",       SET_BITS(1, 2, 2)},
	{"_PTWRT_64_2048",       SET_BITS(2, 2, 2)},
	{"_PTWRT_256_4096",      SET_BITS(3, 2, 2)},
	{"_FCPU_2T",             SET_BITS(0, 3, 4)},
	{"_FCPU_4T",             SET_BITS(1, 3, 4)},
	{"_FCPU_8T",             SET_BITS(2, 3, 4)},
	{"_FCPU_16T",            SET_BITS(3, 3, 4)},
	{"_FCPU_32T",            SET_BITS(4, 3, 4)},
	{"_FCPU_64T",            SET_BITS(5, 3, 4)},
	{"_FCPU_128T",           SET_BITS(6, 3, 4)},
	{"_FCPU_256T",           SET_BITS(7, 3, 4)},
	{"_MCLR_ON",             SET_BITS(1, 1, 7)},
	{"_MCLR_OFF",            SET_BITS(0, 1, 7)},
	{"_HRC_LRC",             SET_BITS(0, 2, 8)},
	{"_HRC_LXT",             SET_BITS(1, 2, 8)},
	{"_HXT_LRC",             SET_BITS(2, 2, 8)},
	{"_VLVR_160",            SET_BITS(0, 3, 10)},
	{"_VLVR_185",            SET_BITS(1, 3, 10)},
	{"_VLVR_205",            SET_BITS(2, 3, 10)},
	{"_VLVR_218",            SET_BITS(3, 3, 10)},
	{"_VLVR_232",            SET_BITS(4, 3, 10)},
	{"_VLVR_245",            SET_BITS(5, 3, 10)},
	{"_VLVR_305",            SET_BITS(6, 3, 10)},
	{"_VLVR_360",            SET_BITS(7, 3, 10)}
};*/

const struct bit_def config0[] = {
};
const int num_config0 = sizeof(config0) / sizeof(config0[0]);
const int config0_addr = 0x0fec;
