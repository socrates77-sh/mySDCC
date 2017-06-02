#ifndef __REG_DEF_H__
#define __REG_DEF_H__

struct bit_def {
	const char *name;
	int n;
};

struct reg_def {
	const char *name;
	int address;
	int bBit; //1: bit access enable; 0: disable
	const struct bit_def bit[8];	// bit0 first
};

extern const struct reg_def all_reg[];
extern const int num_reg;
extern const maxram;
extern const badram[][2];
extern const struct bit_def config1[];
extern const struct bit_def config0[];
extern const int num_config1, num_config0;
extern const config1_addr, config0_addr;

#endif
