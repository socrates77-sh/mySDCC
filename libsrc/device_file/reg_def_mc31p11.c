#include "reg_def.h"

#define SET_BITS(x,n,of) (~((~(((-1) << (n)) | (x))) << (of))) & 0x1FFF

const struct reg_def all_reg[] = {
	{ "INDF",    0x0000, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "FSR",     0x0001, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "PCL",     0x0002, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "STATUS",  0x0003, 1, 
		{
			{"C", 1}, {"DC", 1},  {"Z", 1}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "MCR",     0x0004, 1, 
		{
			{"MINT0", 2}, {"", -1},  {"MINT1", 2}, {"", -1}, 
			{"PD", 1}, {"TO", 1},  {"", 0}, {"GIE", 1}
		}
	},
	{ "INTECON",  0x0005, 1, 
		{
			{"", 0}, {"", 0},  {"INT0IE", 1}, {"INT1IE", 1}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "INTFLAG",  0x0006, 1, 
		{
			{"", 0}, {"", 0},  {"INT0IF", 1}, {"INT1IF", 1}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	},
	{ "IOP0",    0x0007, 1, 
		{
			{"IOP00", 1}, {"IOP01", 1},  {"IOP02", 1}, {"IOP03", 1}, 
			{"IOP04", 1}, {"IOP05", 1},  {"IOP06", 1}, {"", 0}
		}
	},
	{ "OEP0",    0x0008, 1, 
		{
			{"OEP00", 1}, {"OEP01", 1},  {"OEP02", 1}, {"OEP03", 1}, 
			{"OEP04", 1}, {"OEP05", 1},  {"OEP06", 1}, {"", 0}
		}
	},
	{ "PUP0",    0x0009, 1, 
		{
			{"PUP00", 1}, {"PUP01", 1},  {"PUP02", 1}, {"PUP03", 1}, 
			{"PUP04", 1}, {"PUP05", 1},  {"PUP06", 1}, {"", 0}
		}
	},
	{ "DKWP0",    0x000a, 1, 
		{
			{"DKWP00", 1}, {"DKWP01", 1},  {"DKWP02", 1}, {"DKWP03", 1}, 
			{"DKWP04", 1}, {"DKWP05", 1},  {"", 0}, {"", 0}
		}
	},
	{ "IOP1",    0x000b, 1, 
		{
			{"IOP10", 1}, {"IOP11", 1},  {"IOP12", 1}, {"IOP13", 1}, 
			{"IOP14", 1}, {"IOP15", 1},  {"IOP16", 1}, {"", 0}
		}
	},
	{ "OEP1",    0x000c, 1, 
		{
			{"OEP10", 1}, {"OEP11", 1},  {"OEP12", 1}, {"OEP13", 1}, 
			{"OEP14", 1}, {"OEP15", 1},  {"OEP16", 1}, {"", 0}
		}
	},
	{ "PUP1",    0x000d, 1, 
		{
			{"PUP10", 1}, {"PUP11", 1},  {"PUP12", 1}, {"PUP13", 1}, 
			{"PUP14", 1}, {"PUP15", 1},  {"PUP16", 1}, {"", 0}
		}
	},
	{ "DKWP1",    0x000e, 1, 
		{
			{"DKWP10", 1}, {"DKWP11", 1},  {"DKWP12", 1}, {"DKWP13", 1}, 
			{"DKWP14", 1}, {"DKWP15", 1},  {"DKWP16", 1}, {"", 0}
		}
	},
	{ "DKW",    0x000f, 1, 
		{
			{"DEL", 2}, {"", -1},  {"WSEL", 2}, {"", -1}, 
			{"LSEL", 2}, {"", -1},  {"RSEL", 1}, {"DKWE", 1}
		}
	}
};

const int num_reg = sizeof(all_reg) / sizeof(all_reg[0]);

const int maxram = 0x2f;
const int badram[][2] = { {-1, -1} };

const struct bit_def config1[] = {
};

const int num_config1 = sizeof(config1) / sizeof(config1[0]);
const int config1_addr = 0x8001;

const struct bit_def config0[] = {
	{"_CP_ALL",              SET_BITS(0, 1, 12)},
	{"_WDT_ALWAYS_OFF",      SET_BITS(0, 2, 0)},
	{"_WDT_SLEEP_OFF",       SET_BITS(1, 2, 0)},
	{"_WDT_ALWAYS_ON",       SET_BITS(3, 2, 0)},
	{"_FCPU_2X",             SET_BITS(0, 2, 2)},
	{"_FCPU_4X",             SET_BITS(1, 2, 2)},
	{"_FCPU_8X",             SET_BITS(2, 2, 2)},
	{"_FCPU_16X",            SET_BITS(3, 2, 2)}
};

const int num_config0 = sizeof(config0) / sizeof(config0[0]);
const int config0_addr = 0x8000;
