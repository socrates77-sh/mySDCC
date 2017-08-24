#include "reg_def.h"

#define SET_BITS(x,n,of) (~((~(((-1) << (n)) | (x))) << (of))) & 0x3FFF

const struct reg_def all_reg[] = {
	{ "INDF",    0x0000, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "T0CNT",   0x0001, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "PCL",     0x0002, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "STATUS",  0x0003, 1, 
		{
			{"C", 1}, {"DC", 1},  {"Z", 1}, {"PD", 1}, 
			{"TO", 1}, {"", 0},  {"", 0}, {"RST", 1}
		}
	},
	{ "FSR",     0x0004, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "P0",      0x0005, 1, 
		{
			{"P00", 1}, {"P01", 1},  {"P02", 1}, {"P03", 1}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "P1",      0x0006, 1, 
		{
			{"P10", 1}, {"P11", 1},  {"P12", 1}, {"P13", 1}, 
			{"P14", 1}, {"P15", 1},  {"P16", 1}, {"P17", 1}
		}
	},
	{ "MCR",     0x0008, 1, 
		{
			{"", 0}, {"", 0},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"EIS", 1}, {"WDTEN", 1}
		}
	},
	{ "KBIM",     0x0009, 1, 
		{
			{"KBIM0", 1}, {"KBIM1", 1},  {"KBIM2", 1}, {"KBIM3", 1}, 
			{"KBIM4", 1}, {"KBIM5", 1},  {"KBIM6", 1}, {"KBIM7", 1}
		}
	},
	{ "PCLATH",   0x000a, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "PDCON",    0x000b, 1, 
		{
			{"P00PD", 1}, {"P01PD", 1},  {"P02PD", 1}, {"P03PD", 1}, 
			{"P10PD", 1}, {"P11PD", 1},  {"P12PD", 1}, {"", 0}
		}
	},
	{ "ODCON",    0x000c, 1, 
		{
			{"P10OD", 1}, {"P11OD", 1},  {"P12OD", 1}, {"", 0}, 
			{"P14OD", 1}, {"P15OD", 1},  {"P16OD", 1}, {"P17OD", 1}
		}
	},
	{ "PUCON",    0x000d, 1, 
		{
			{"P10PU", 1}, {"P11PU", 1},  {"P12PU", 1}, {"", 0}, 
			{"P14PU", 1}, {"P15PU", 1},  {"P16PU", 1}, {"P17PU", 1}
		}
	},
	{ "INTECON",  0x000e, 1, 
		{
			{"T0IE", 1}, {"KBIE", 1},  {"INT0IE", 1}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"GIE", 1}
		}
	},
	{ "INTFLAG",  0x000f, 1, 
		{
			{"T0IF", 1}, {"KBIF", 1},  {"INT0IF", 1}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "T0CR",  0x0041, 1, 
		{
			{"T0PR", 3}, {"", -1},  {"", -1}, {"T0PTA", 1}, 
			{"T0SE", 1}, {"T0PTS", 1},  {"INT0M", 1}, {"", 0}
		}
	},
	{ "DDR0",  0x0045, 1, 
		{
			{"DDR00", 1}, {"DDR01", 1},  {"DDR02", 1}, {"DDR03", 1}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "DDR1",  0x0046, 1, 
		{
			{"DDR10", 1}, {"DDR11", 1},  {"DDR12", 1}, {"", 0}, 
			{"DDR14", 1}, {"DDR15", 1},  {"DDR16", 1}, {"DDR17", 1}
		}
	},
	{ "TMCR",  0x004b, 1, 
		{
			{"T1IF", 1}, {"T1IE", 1},  {"", 0}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"TBS", 1}
		}
	},
	{ "T1CR",  0x004c, 1, 
		{
			{"T1PR", 3}, {"", -1},  {"", -1}, {"T1PTS", 2}, 
			{"", -1}, {"BUZOUT", 1},  {"PWMOUT", 1}, {"TMR1EN", 1}
		}
	},
	{ "T1CNT",   0x004d, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "T1LOAD",  0x004e, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "T1DATA",  0x004f, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } }
};

const int num_reg = sizeof(all_reg) / sizeof(all_reg[0]);

const int maxram = 0x4f;
//const int badram[][2] = { {0x00, 0x06}, {0x08, 0x0f}, {-1, -1} };
const int badram[][2] = { {-1, -1} };

const struct bit_def config1[] = {
	{"_CP_ALL",              SET_BITS(0, 1, 13)},
	{"_OSC_IRC_RTC",         SET_BITS(3, 2, 11)},
	{"_OSC_IRC",             SET_BITS(2, 2, 11)},
	{"_OSC_HXT",             SET_BITS(1, 2, 11)},
	{"_OSC_LXT",             SET_BITS(0, 2, 11)},
	{"_SMT_OFF",             SET_BITS(1, 1, 9)},
	{"_SMT_ON",              SET_BITS(0, 1, 9)},
	{"_RD_FROM_PIN",         SET_BITS(1, 1, 8)},
	{"_RD_FROM_REG",         SET_BITS(0, 1, 8)}
};

const int num_config1 = sizeof(config1) / sizeof(config1[0]);
const int config1_addr = 0x2001;

const struct bit_def config0[] = {
	{"_WDT_ON",              SET_BITS(1, 1, 11)},
	{"_WDT_OFF",             SET_BITS(0, 1, 11)},
	{"_PWRT_ON",             SET_BITS(1, 1, 10)},
	{"_PWRT_OFF",            SET_BITS(0, 1, 10)},
	{"_TWDT_18MS",           SET_BITS(3, 2, 8)},
	{"_TWDT_4P5MS",          SET_BITS(2, 2, 8)},
	{"_TWDT_288MS",          SET_BITS(1, 2, 8)},
	{"_TWDT_72MS",           SET_BITS(0, 2, 8)},
	{"_FCPU_4T",             SET_BITS(1, 1, 7)},
	{"_FCPU_2T",             SET_BITS(0, 1, 7)},
	{"_IRC_8M",              SET_BITS(7, 3, 4)},
	{"_IRC_4M",              SET_BITS(6, 3, 4)},
	{"_IRC_2M",              SET_BITS(5, 3, 4)},
	{"_IRC_1M",              SET_BITS(4, 3, 4)},
	{"_IRC_444K",            SET_BITS(2, 3, 4)},
	{"_MCLR_ON",             SET_BITS(1, 1, 3)},
	{"_MCLR_OFF",            SET_BITS(0, 1, 3)},
	{"_VBOR_36",             SET_BITS(7, 3, 0)},
	{"_VBOR_30",             SET_BITS(6, 3, 0)},
	{"_VBOR_26",             SET_BITS(5, 3, 0)},
	{"_VBOR_24",             SET_BITS(4, 3, 0)},
	{"_VBOR_22",             SET_BITS(3, 3, 0)},
	{"_VBOR_20",             SET_BITS(2, 3, 0)},
	{"_VBOR_18",             SET_BITS(1, 3, 0)},
	{"_VBOR_15",             SET_BITS(0, 3, 0)},
};

const int num_config0 = sizeof(config0) / sizeof(config0[0]);
const int config0_addr = 0x2000;
