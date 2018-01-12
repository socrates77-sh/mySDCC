#include "reg_def.h"

#define SET_BITS(x, n, of) (~((~(((-1) << (n)) | (x))) << (of))) & 0xFFFF

const struct reg_def all_reg[] = {
