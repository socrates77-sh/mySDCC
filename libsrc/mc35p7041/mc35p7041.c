#include <mc35p7041.h>

__sfr __at (INDF_ADDR)     	INDF;
__sfr __at (HIBYTE_ADDR)   	HIBYTE;
__sfr __at (FSR_ADDR)      	FSR;
__sfr __at (FSR0_ADDR)     	FSR0;
__sfr __at (FSR1_ADDR)     	FSR1;
__sfr __at (PCH_ADDR)      	PCH;
__sfr __at (PCL_ADDR)      	PCL;
__sfr __at (STATUS_ADDR)   	STATUS;

volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;
