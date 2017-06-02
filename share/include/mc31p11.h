#ifndef MC31P11_H
#define MC31P11_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x0000
#define FSR_ADDR        	0x0001
#define PCL_ADDR        	0x0002
#define STATUS_ADDR     	0x0003
#define MCR_ADDR        	0x0004
#define INTECON_ADDR    	0x0005
#define INTFLAG_ADDR    	0x0006
#define IOP0_ADDR       	0x0007
#define OEP0_ADDR       	0x0008
#define PUP0_ADDR       	0x0009
#define DKWP0_ADDR      	0x000A
#define IOP1_ADDR       	0x000B
#define OEP1_ADDR       	0x000C
#define PUP1_ADDR       	0x000D
#define DKWP1_ADDR      	0x000E
#define DKW_ADDR        	0x000F

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (FSR_ADDR)      	FSR;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INTECON_ADDR)  	INTECON;
extern __sfr __at (INTFLAG_ADDR)  	INTFLAG;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (DKWP0_ADDR)    	DKWP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (DKWP1_ADDR)    	DKWP1;
extern __sfr __at (DKW_ADDR)      	DKW;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0
#define _CP_ALL         	0x0FFF
#define _WDT_ALWAYS_OFF 	0x1FFC
#define _WDT_SLEEP_OFF  	0x1FFD
#define _WDT_ALWAYS_ON  	0x1FFF
#define _FCPU_2X        	0x1FF3
#define _FCPU_4X        	0x1FF7
#define _FCPU_8X        	0x1FFB
#define _FCPU_16X       	0x1FFF

// ----- STATUS Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char C:1;
		unsigned char DC:1;
		unsigned char Z:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __STATUSbits_t;
extern volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;

#define C         	STATUSbits.C        	/* bit 0 */
#define DC        	STATUSbits.DC       	/* bit 1 */
#define Z         	STATUSbits.Z        	/* bit 2 */

// ----- MCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char MINT0:2;
		unsigned char MINT1:2;
		unsigned char PD:1;
		unsigned char TO:1;
		unsigned char :1;
		unsigned char GIE:1;
	};
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;

#define MINT0     	MCRbits.MINT0       	/* bit 1-0 */
#define MINT1     	MCRbits.MINT1       	/* bit 3-2 */
#define PD        	MCRbits.PD          	/* bit 4 */
#define TO        	MCRbits.TO          	/* bit 5 */
#define GIE       	MCRbits.GIE         	/* bit 7 */

// ----- INTECON Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __INTECONbits_t;
extern volatile __INTECONbits_t __at(INTECON_ADDR) INTECONbits;

#define INT0IE    	INTECONbits.INT0IE  	/* bit 2 */
#define INT1IE    	INTECONbits.INT1IE  	/* bit 3 */

// ----- INTFLAG Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __INTFLAGbits_t;
extern volatile __INTFLAGbits_t __at(INTFLAG_ADDR) INTFLAGbits;

#define INT0IF    	INTFLAGbits.INT0IF  	/* bit 2 */
#define INT1IF    	INTFLAGbits.INT1IF  	/* bit 3 */

// ----- IOP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char IOP00:1;
		unsigned char IOP01:1;
		unsigned char IOP02:1;
		unsigned char IOP03:1;
		unsigned char IOP04:1;
		unsigned char IOP05:1;
		unsigned char IOP06:1;
		unsigned char :1;
	};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define IOP00     	IOP0bits.IOP00      	/* bit 0 */
#define IOP01     	IOP0bits.IOP01      	/* bit 1 */
#define IOP02     	IOP0bits.IOP02      	/* bit 2 */
#define IOP03     	IOP0bits.IOP03      	/* bit 3 */
#define IOP04     	IOP0bits.IOP04      	/* bit 4 */
#define IOP05     	IOP0bits.IOP05      	/* bit 5 */
#define IOP06     	IOP0bits.IOP06      	/* bit 6 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OEP00:1;
		unsigned char OEP01:1;
		unsigned char OEP02:1;
		unsigned char OEP03:1;
		unsigned char OEP04:1;
		unsigned char OEP05:1;
		unsigned char OEP06:1;
		unsigned char :1;
	};
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;

#define OEP00     	OEP0bits.OEP00      	/* bit 0 */
#define OEP01     	OEP0bits.OEP01      	/* bit 1 */
#define OEP02     	OEP0bits.OEP02      	/* bit 2 */
#define OEP03     	OEP0bits.OEP03      	/* bit 3 */
#define OEP04     	OEP0bits.OEP04      	/* bit 4 */
#define OEP05     	OEP0bits.OEP05      	/* bit 5 */
#define OEP06     	OEP0bits.OEP06      	/* bit 6 */

// ----- PUP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PUP00:1;
		unsigned char PUP01:1;
		unsigned char PUP02:1;
		unsigned char PUP03:1;
		unsigned char PUP04:1;
		unsigned char PUP05:1;
		unsigned char PUP06:1;
		unsigned char :1;
	};
} __PUP0bits_t;
extern volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;

#define PUP00     	PUP0bits.PUP00      	/* bit 0 */
#define PUP01     	PUP0bits.PUP01      	/* bit 1 */
#define PUP02     	PUP0bits.PUP02      	/* bit 2 */
#define PUP03     	PUP0bits.PUP03      	/* bit 3 */
#define PUP04     	PUP0bits.PUP04      	/* bit 4 */
#define PUP05     	PUP0bits.PUP05      	/* bit 5 */
#define PUP06     	PUP0bits.PUP06      	/* bit 6 */

// ----- DKWP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DKWP00:1;
		unsigned char DKWP01:1;
		unsigned char DKWP02:1;
		unsigned char DKWP03:1;
		unsigned char DKWP04:1;
		unsigned char DKWP05:1;
		unsigned char :1;
		unsigned char :1;
	};
} __DKWP0bits_t;
extern volatile __DKWP0bits_t __at(DKWP0_ADDR) DKWP0bits;

#define DKWP00    	DKWP0bits.DKWP00    	/* bit 0 */
#define DKWP01    	DKWP0bits.DKWP01    	/* bit 1 */
#define DKWP02    	DKWP0bits.DKWP02    	/* bit 2 */
#define DKWP03    	DKWP0bits.DKWP03    	/* bit 3 */
#define DKWP04    	DKWP0bits.DKWP04    	/* bit 4 */
#define DKWP05    	DKWP0bits.DKWP05    	/* bit 5 */

// ----- IOP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char IOP10:1;
		unsigned char IOP11:1;
		unsigned char IOP12:1;
		unsigned char IOP13:1;
		unsigned char IOP14:1;
		unsigned char IOP15:1;
		unsigned char IOP16:1;
		unsigned char :1;
	};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define IOP10     	IOP1bits.IOP10      	/* bit 0 */
#define IOP11     	IOP1bits.IOP11      	/* bit 1 */
#define IOP12     	IOP1bits.IOP12      	/* bit 2 */
#define IOP13     	IOP1bits.IOP13      	/* bit 3 */
#define IOP14     	IOP1bits.IOP14      	/* bit 4 */
#define IOP15     	IOP1bits.IOP15      	/* bit 5 */
#define IOP16     	IOP1bits.IOP16      	/* bit 6 */

// ----- OEP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OEP10:1;
		unsigned char OEP11:1;
		unsigned char OEP12:1;
		unsigned char OEP13:1;
		unsigned char OEP14:1;
		unsigned char OEP15:1;
		unsigned char OEP16:1;
		unsigned char :1;
	};
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;

#define OEP10     	OEP1bits.OEP10      	/* bit 0 */
#define OEP11     	OEP1bits.OEP11      	/* bit 1 */
#define OEP12     	OEP1bits.OEP12      	/* bit 2 */
#define OEP13     	OEP1bits.OEP13      	/* bit 3 */
#define OEP14     	OEP1bits.OEP14      	/* bit 4 */
#define OEP15     	OEP1bits.OEP15      	/* bit 5 */
#define OEP16     	OEP1bits.OEP16      	/* bit 6 */

// ----- PUP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PUP10:1;
		unsigned char PUP11:1;
		unsigned char PUP12:1;
		unsigned char PUP13:1;
		unsigned char PUP14:1;
		unsigned char PUP15:1;
		unsigned char PUP16:1;
		unsigned char :1;
	};
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;

#define PUP10     	PUP1bits.PUP10      	/* bit 0 */
#define PUP11     	PUP1bits.PUP11      	/* bit 1 */
#define PUP12     	PUP1bits.PUP12      	/* bit 2 */
#define PUP13     	PUP1bits.PUP13      	/* bit 3 */
#define PUP14     	PUP1bits.PUP14      	/* bit 4 */
#define PUP15     	PUP1bits.PUP15      	/* bit 5 */
#define PUP16     	PUP1bits.PUP16      	/* bit 6 */

// ----- DKWP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DKWP10:1;
		unsigned char DKWP11:1;
		unsigned char DKWP12:1;
		unsigned char DKWP13:1;
		unsigned char DKWP14:1;
		unsigned char DKWP15:1;
		unsigned char DKWP16:1;
		unsigned char :1;
	};
} __DKWP1bits_t;
extern volatile __DKWP1bits_t __at(DKWP1_ADDR) DKWP1bits;

#define DKWP10    	DKWP1bits.DKWP10    	/* bit 0 */
#define DKWP11    	DKWP1bits.DKWP11    	/* bit 1 */
#define DKWP12    	DKWP1bits.DKWP12    	/* bit 2 */
#define DKWP13    	DKWP1bits.DKWP13    	/* bit 3 */
#define DKWP14    	DKWP1bits.DKWP14    	/* bit 4 */
#define DKWP15    	DKWP1bits.DKWP15    	/* bit 5 */
#define DKWP16    	DKWP1bits.DKWP16    	/* bit 6 */

// ----- DKW Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DEL:2;
		unsigned char WSEL:2;
		unsigned char LSEL:2;
		unsigned char RSEL:1;
		unsigned char DKWE:1;
	};
} __DKWbits_t;
extern volatile __DKWbits_t __at(DKW_ADDR) DKWbits;

#define DEL       	DKWbits.DEL         	/* bit 1-0 */
#define WSEL      	DKWbits.WSEL        	/* bit 3-2 */
#define LSEL      	DKWbits.LSEL        	/* bit 5-4 */
#define RSEL      	DKWbits.RSEL        	/* bit 6 */
#define DKWE      	DKWbits.DKWE        	/* bit 7 */

#endif
