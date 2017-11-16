#ifndef MC35P7041_H
#define MC35P7041_H

#include <mc30-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x00E7
#define HIBYTE_ADDR     	0x0082
#define FSR_ADDR        	0x0083
#define FSR0_ADDR       	0x0083
#define FSR1_ADDR       	0x0084
#define PCH_ADDR        	0x00CF
#define PCL_ADDR        	0x00CE
#define STATUS_ADDR     	0x0086

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (HIBYTE_ADDR)   	HIBYTE;
extern __sfr __at (FSR_ADDR)      	FSR;
extern __sfr __at (FSR0_ADDR)     	FSR0;
extern __sfr __at (FSR1_ADDR)     	FSR1;
extern __sfr __at (PCH_ADDR)      	PCH;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0

// ----- STATUS Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char Z:1;
		unsigned char DC:1;
		unsigned char C:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __STATUSbits_t;
extern volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;

#define Z         	STATUSbits.Z        	/* bit 0 */
#define DC        	STATUSbits.DC       	/* bit 1 */
#define C         	STATUSbits.C        	/* bit 2 */

#endif
