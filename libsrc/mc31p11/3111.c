#include <mc31p11.h>

__sfr __at (INDF_ADDR)     	INDF;
__sfr __at (FSR_ADDR)      	FSR;
__sfr __at (PCL_ADDR)      	PCL;
__sfr __at (STATUS_ADDR)   	STATUS;
__sfr __at (MCR_ADDR)      	MCR;
__sfr __at (INTECON_ADDR)  	INTECON;
__sfr __at (INTFLAG_ADDR)  	INTFLAG;
__sfr __at (IOP0_ADDR)     	IOP0;
__sfr __at (OEP0_ADDR)     	OEP0;
__sfr __at (PUP0_ADDR)     	PUP0;
__sfr __at (DKWP0_ADDR)    	DKWP0;
__sfr __at (IOP1_ADDR)     	IOP1;
__sfr __at (OEP1_ADDR)     	OEP1;
__sfr __at (PUP1_ADDR)     	PUP1;
__sfr __at (DKWP1_ADDR)    	DKWP1;
__sfr __at (DKW_ADDR)      	DKW;

volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;
volatile __MCRbits_t __at(MCR_ADDR) MCRbits;
volatile __INTECONbits_t __at(INTECON_ADDR) INTECONbits;
volatile __INTFLAGbits_t __at(INTFLAG_ADDR) INTFLAGbits;
volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;
volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;
volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;
volatile __DKWP0bits_t __at(DKWP0_ADDR) DKWP0bits;
volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;
volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;
volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;
volatile __DKWP1bits_t __at(DKWP1_ADDR) DKWP1bits;
volatile __DKWbits_t __at(DKW_ADDR) DKWbits;
