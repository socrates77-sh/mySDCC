#include "reg_def.h"

#define SET_BITS(x,n,of) (~((~(((-1) << (n)) | (x))) << (of))) & 0xFFFF

const struct reg_def all_reg[] = {
	{ "INDF",    0x00e7, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "HIBYTE",  0x0082, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "FSR",     0x0083, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "FSR0",    0x0083, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "FSR1",    0x0084, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "PCH",     0x00cf, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "PCL",     0x00ce, 0, { {"", 0}, {"", 0},  {"", 0}, {"", 0}, {"", 0}, {"", 0},  {"", 0}, {"", 0} } },
	{ "STATUS",  0x0086, 1, 
		{
			{"Z", 1}, {"DC", 1},  {"C", 1}, {"", 0}, 
			{"", 0}, {"", 0},  {"", 0}, {"", 0}
		}
	}

};

const int num_reg = sizeof(all_reg) / sizeof(all_reg[0]);

const int maxram = 0x0ff;
const int badram[][2] = { {0x80, 0x81}, {0x85, 0x85}, {0x87, 0x9f}, {0xa1, 0xa4},
						  {0xa6, 0xac}, {0xb0, 0xb0}, {0xb6, 0xb7}, {0xb9, 0xbe},
						  {0xc0, 0xc3}, {0xc6, 0xc7}, {0xd1, 0xd3}, {0xd6, 0xd7},
						  {0xdd, 0xde}, {0xe1, 0xe3}, {0xe6, 0xe6}, {0xef, 0xef},
						  {-1, -1} };


const struct bit_def config1[] = {
};
const int num_config1 = sizeof(config1) / sizeof(config1[0]);
const int config1_addr = 0x8001;

const struct bit_def config0[] = {
};
const int num_config0 = sizeof(config0) / sizeof(config0[0]);
const int config0_addr = 0x8000;
