#ifndef MC32F7122_H
#define MC32F7122_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x0180
#define INDF0_ADDR      	0x0180
#define INDF1_ADDR      	0x0181
#define INDF2_ADDR      	0x0182
#define HIBYTE_ADDR     	0x0183
#define FSR_ADDR        	0x0184
#define FSR0_ADDR       	0x0184
#define FSR1_ADDR       	0x0185
#define PCL_ADDR        	0x0186
#define STATUS_ADDR     	0x0187
#define PFLAG_ADDR      	0x0187
#define MCR_ADDR        	0x0188
#define INDF3_ADDR      	0x0189
#define INTE_ADDR       	0x018A
#define INTF_ADDR       	0x018B
#define OSCM_ADDR       	0x018C
#define INTE1_ADDR      	0x018D
#define INTF1_ADDR      	0x018E
#define LCDCR_ADDR      	0x018F
#define IOP0_ADDR       	0x0190
#define OEP0_ADDR       	0x0191
#define PUP0_ADDR       	0x0192
#define PDP0_ADDR       	0x0193
#define IOP1_ADDR       	0x0194
#define OEP1_ADDR       	0x0195
#define PUP1_ADDR       	0x0196
#define PDP1_ADDR       	0x0197
#define IOP2_ADDR       	0x0198
#define OEP2_ADDR       	0x0199
#define PUP2_ADDR       	0x019A
#define PDP2_ADDR       	0x019B
#define T0CR_ADDR       	0x01A0
#define T0CNT_ADDR      	0x01A1
#define T0LOAD_ADDR     	0x01A2
#define T0DATA_ADDR     	0x01A3
#define T0EFR_ADDR      	0x01A4
#define T1CR_ADDR       	0x01A5
#define T1CNT_ADDR      	0x01A6
#define T1LOAD_ADDR     	0x01A7
#define T2CR_ADDR       	0x01A8
#define T2CNT_ADDR      	0x01A9
#define T2LOAD_ADDR     	0x01AA
#define T2EFR_ADDR      	0x01AC
#define T3CR_ADDR       	0x01AD
#define T3CNT_ADDR      	0x01AE
#define T3LOAD_ADDR     	0x01AF
#define IICCR_ADDR      	0x01B0
#define IICAR_ADDR      	0x01B1
#define IICDR_ADDR      	0x01B2
#define EECR_ADDR       	0x01B4
#define EEMASK_ADDR     	0x01B5
#define EEAR_ADDR       	0x01B6
#define EEDR_ADDR       	0x01B7
#define ADCR0_ADDR      	0x01B8
#define ADCR1_ADDR      	0x01B9
#define ADRH_ADDR       	0x01BA
#define ADRL_ADDR       	0x01BB
#define ADIOS0_ADDR     	0x01BC
#define ADIOS1_ADDR     	0x01BD
#define OSADJCR_ADDR    	0x01BE
#define PPGCR_ADDR      	0x01C0
#define PPGLOAD_ADDR    	0x01C1
#define PPGTDL_ADDR     	0x01C2
#define PPGTDB_ADDR     	0x01C3
#define OPACR_ADDR      	0x01C4
#define OPACLR_ADDR     	0x01C5
#define CPCR_ADDR       	0x01C8
#define CPSR_ADDR       	0x01C9
#define CPVR0_ADDR      	0x01CA
#define CPVR1_ADDR      	0x01CB
#define CP0CLR_ADDR     	0x01CC
#define CP1CLR_ADDR     	0x01CD
#define CP2CLR_ADDR     	0x01CE
#define CP3CLR_ADDR     	0x01CF

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (INDF0_ADDR)    	INDF0;
extern __sfr __at (INDF1_ADDR)    	INDF1;
extern __sfr __at (INDF2_ADDR)    	INDF2;
extern __sfr __at (HIBYTE_ADDR)   	HIBYTE;
extern __sfr __at (FSR_ADDR)      	FSR;
extern __sfr __at (FSR0_ADDR)     	FSR0;
extern __sfr __at (FSR1_ADDR)     	FSR1;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (PFLAG_ADDR)    	PFLAG;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INDF3_ADDR)    	INDF3;
extern __sfr __at (INTE_ADDR)     	INTE;
extern __sfr __at (INTF_ADDR)     	INTF;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (INTE1_ADDR)    	INTE1;
extern __sfr __at (INTF1_ADDR)    	INTF1;
extern __sfr __at (LCDCR_ADDR)    	LCDCR;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (PDP0_ADDR)     	PDP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (PDP1_ADDR)     	PDP1;
extern __sfr __at (IOP2_ADDR)     	IOP2;
extern __sfr __at (OEP2_ADDR)     	OEP2;
extern __sfr __at (PUP2_ADDR)     	PUP2;
extern __sfr __at (PDP2_ADDR)     	PDP2;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T0EFR_ADDR)    	T0EFR;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T2CR_ADDR)     	T2CR;
extern __sfr __at (T2CNT_ADDR)    	T2CNT;
extern __sfr __at (T2LOAD_ADDR)   	T2LOAD;
extern __sfr __at (T2EFR_ADDR)    	T2EFR;
extern __sfr __at (T3CR_ADDR)     	T3CR;
extern __sfr __at (T3CNT_ADDR)    	T3CNT;
extern __sfr __at (T3LOAD_ADDR)   	T3LOAD;
extern __sfr __at (IICCR_ADDR)    	IICCR;
extern __sfr __at (IICAR_ADDR)    	IICAR;
extern __sfr __at (IICDR_ADDR)    	IICDR;
extern __sfr __at (EECR_ADDR)     	EECR;
extern __sfr __at (EEMASK_ADDR)   	EEMASK;
extern __sfr __at (EEAR_ADDR)     	EEAR;
extern __sfr __at (EEDR_ADDR)     	EEDR;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (ADIOS0_ADDR)   	ADIOS0;
extern __sfr __at (ADIOS1_ADDR)   	ADIOS1;
extern __sfr __at (OSADJCR_ADDR)  	OSADJCR;
extern __sfr __at (PPGCR_ADDR)    	PPGCR;
extern __sfr __at (PPGLOAD_ADDR)  	PPGLOAD;
extern __sfr __at (PPGTDL_ADDR)   	PPGTDL;
extern __sfr __at (PPGTDB_ADDR)   	PPGTDB;
extern __sfr __at (OPACR_ADDR)    	OPACR;
extern __sfr __at (OPACLR_ADDR)   	OPACLR;
extern __sfr __at (CPCR_ADDR)     	CPCR;
extern __sfr __at (CPSR_ADDR)     	CPSR;
extern __sfr __at (CPVR0_ADDR)    	CPVR0;
extern __sfr __at (CPVR1_ADDR)    	CPVR1;
extern __sfr __at (CP0CLR_ADDR)   	CP0CLR;
extern __sfr __at (CP1CLR_ADDR)   	CP1CLR;
extern __sfr __at (CP2CLR_ADDR)   	CP2CLR;
extern __sfr __at (CP3CLR_ADDR)   	CP3CLR;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0

// ----- PCL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PC:8;
	};
} __PCLbits_t;
extern volatile __PCLbits_t __at(PCL_ADDR) PCLbits;

#define PC        	PCLbits.PC          	/* bit 7-0 */

// ----- PFLAG Bits --------------------------------------------
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
} __PFLAGbits_t;
extern volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;

#define C         	PFLAGbits.C         	/* bit 0 */
#define DC        	PFLAGbits.DC        	/* bit 1 */
#define Z         	PFLAGbits.Z         	/* bit 2 */

// ----- MCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char MINT00:1;
		unsigned char MINT01:1;
		unsigned char MINT10:1;
		unsigned char MINT11:1;
		unsigned char PD:1;
		unsigned char TO:1;
		unsigned char :1;
		unsigned char GIE:1;
	};
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;

#define MINT00    	MCRbits.MINT00      	/* bit 0 */
#define MINT01    	MCRbits.MINT01      	/* bit 1 */
#define MINT10    	MCRbits.MINT10      	/* bit 2 */
#define MINT11    	MCRbits.MINT11      	/* bit 3 */
#define PD        	MCRbits.PD          	/* bit 4 */
#define TO        	MCRbits.TO          	/* bit 5 */
#define GIE       	MCRbits.GIE         	/* bit 7 */

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char LVDIE:1;
		unsigned char IICIE:1;
		unsigned char ADIE:1;
		unsigned char PPGTIE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define LVDIE     	INTEbits.LVDIE      	/* bit 4 */
#define IICIE     	INTEbits.IICIE      	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */
#define PPGTIE    	INTEbits.PPGTIE     	/* bit 7 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char LVDIF:1;
		unsigned char IICIF:1;
		unsigned char ADIF:1;
		unsigned char PPGTIF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define LVDIF     	INTFbits.LVDIF      	/* bit 4 */
#define IICIF     	INTFbits.IICIF      	/* bit 5 */
#define ADIF      	INTFbits.ADIF       	/* bit 6 */
#define PPGTIF    	INTFbits.PPGTIF     	/* bit 7 */

// ----- OSCM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char HFEN:1;
		unsigned char LFEN:1;
		unsigned char CLKS:1;
		unsigned char :1;
		unsigned char STBH:1;
		unsigned char STBL:1;
		unsigned char :1;
		unsigned char :1;
	};
} __OSCMbits_t;
extern volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;

#define HFEN      	OSCMbits.HFEN       	/* bit 0 */
#define LFEN      	OSCMbits.LFEN       	/* bit 1 */
#define CLKS      	OSCMbits.CLKS       	/* bit 2 */
#define STBH      	OSCMbits.STBH       	/* bit 4 */
#define STBL      	OSCMbits.STBL       	/* bit 5 */

// ----- INTE1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2IE:1;
		unsigned char T3IE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char CP1IE:1;
		unsigned char CP2IE:1;
		unsigned char CP3IE:1;
	};
} __INTE1bits_t;
extern volatile __INTE1bits_t __at(INTE1_ADDR) INTE1bits;

#define T2IE      	INTE1bits.T2IE      	/* bit 0 */
#define T3IE      	INTE1bits.T3IE      	/* bit 1 */
#define CP1IE     	INTE1bits.CP1IE     	/* bit 5 */
#define CP2IE     	INTE1bits.CP2IE     	/* bit 6 */
#define CP3IE     	INTE1bits.CP3IE     	/* bit 7 */

// ----- INTF1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2IF:1;
		unsigned char T3IF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char CP1IF:1;
		unsigned char CP2IF:1;
		unsigned char CP3IF:1;
	};
} __INTF1bits_t;
extern volatile __INTF1bits_t __at(INTF1_ADDR) INTF1bits;

#define T2IF      	INTF1bits.T2IF      	/* bit 0 */
#define T3IF      	INTF1bits.T3IF      	/* bit 1 */
#define CP1IF     	INTF1bits.CP1IF     	/* bit 5 */
#define CP2IF     	INTF1bits.CP2IF     	/* bit 6 */
#define CP3IF     	INTF1bits.CP3IF     	/* bit 7 */

// ----- LCDCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LVDF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char VLVDS:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char LVDEN:1;
	};
} __LCDCRbits_t;
extern volatile __LCDCRbits_t __at(LCDCR_ADDR) LCDCRbits;

#define LVDF      	LCDCRbits.LVDF      	/* bit 0 */
#define VLVDS     	LCDCRbits.VLVDS     	/* bit 4 */
#define LVDEN     	LCDCRbits.LVDEN     	/* bit 7 */

// ----- IOP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00D:1;
		unsigned char P01D:1;
		unsigned char P02D:1;
		unsigned char P03D:1;
		unsigned char P04D:1;
		unsigned char P05D:1;
		unsigned char P06D:1;
		unsigned char P07D:1;
	};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define P00D      	IOP0bits.P00D       	/* bit 0 */
#define P01D      	IOP0bits.P01D       	/* bit 1 */
#define P02D      	IOP0bits.P02D       	/* bit 2 */
#define P03D      	IOP0bits.P03D       	/* bit 3 */
#define P04D      	IOP0bits.P04D       	/* bit 4 */
#define P05D      	IOP0bits.P05D       	/* bit 5 */
#define P06D      	IOP0bits.P06D       	/* bit 6 */
#define P07D      	IOP0bits.P07D       	/* bit 7 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00OE:1;
		unsigned char P01OE:1;
		unsigned char P02OE:1;
		unsigned char P03OE:1;
		unsigned char P04OE:1;
		unsigned char P05OE:1;
		unsigned char P06OE:1;
		unsigned char P07OE:1;
	};
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;

#define P00OE     	OEP0bits.P00OE      	/* bit 0 */
#define P01OE     	OEP0bits.P01OE      	/* bit 1 */
#define P02OE     	OEP0bits.P02OE      	/* bit 2 */
#define P03OE     	OEP0bits.P03OE      	/* bit 3 */
#define P04OE     	OEP0bits.P04OE      	/* bit 4 */
#define P05OE     	OEP0bits.P05OE      	/* bit 5 */
#define P06OE     	OEP0bits.P06OE      	/* bit 6 */
#define P07OE     	OEP0bits.P07OE      	/* bit 7 */

// ----- PUP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00PU:1;
		unsigned char P01PU:1;
		unsigned char P02PU:1;
		unsigned char P03PU:1;
		unsigned char P04PU:1;
		unsigned char P05PU:1;
		unsigned char P06PU:1;
		unsigned char P07PU:1;
	};
} __PUP0bits_t;
extern volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;

#define P00PU     	PUP0bits.P00PU      	/* bit 0 */
#define P01PU     	PUP0bits.P01PU      	/* bit 1 */
#define P02PU     	PUP0bits.P02PU      	/* bit 2 */
#define P03PU     	PUP0bits.P03PU      	/* bit 3 */
#define P04PU     	PUP0bits.P04PU      	/* bit 4 */
#define P05PU     	PUP0bits.P05PU      	/* bit 5 */
#define P06PU     	PUP0bits.P06PU      	/* bit 6 */
#define P07PU     	PUP0bits.P07PU      	/* bit 7 */

// ----- PDP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00PD:1;
		unsigned char P01PD:1;
		unsigned char P02PD:1;
		unsigned char P03PD:1;
		unsigned char P04PD:1;
		unsigned char P05PD:1;
		unsigned char P06PD:1;
		unsigned char P07PD:1;
	};
} __PDP0bits_t;
extern volatile __PDP0bits_t __at(PDP0_ADDR) PDP0bits;

#define P00PD     	PDP0bits.P00PD      	/* bit 0 */
#define P01PD     	PDP0bits.P01PD      	/* bit 1 */
#define P02PD     	PDP0bits.P02PD      	/* bit 2 */
#define P03PD     	PDP0bits.P03PD      	/* bit 3 */
#define P04PD     	PDP0bits.P04PD      	/* bit 4 */
#define P05PD     	PDP0bits.P05PD      	/* bit 5 */
#define P06PD     	PDP0bits.P06PD      	/* bit 6 */
#define P07PD     	PDP0bits.P07PD      	/* bit 7 */

// ----- IOP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10D:1;
		unsigned char P11D:1;
		unsigned char P12D:1;
		unsigned char P13D:1;
		unsigned char P14D:1;
		unsigned char P15D:1;
		unsigned char P16D:1;
		unsigned char P17D:1;
	};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define P10D      	IOP1bits.P10D       	/* bit 0 */
#define P11D      	IOP1bits.P11D       	/* bit 1 */
#define P12D      	IOP1bits.P12D       	/* bit 2 */
#define P13D      	IOP1bits.P13D       	/* bit 3 */
#define P14D      	IOP1bits.P14D       	/* bit 4 */
#define P15D      	IOP1bits.P15D       	/* bit 5 */
#define P16D      	IOP1bits.P16D       	/* bit 6 */
#define P17D      	IOP1bits.P17D       	/* bit 7 */

// ----- OEP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10OE:1;
		unsigned char P11OE:1;
		unsigned char P12OE:1;
		unsigned char P13OE:1;
		unsigned char P14OE:1;
		unsigned char P15OE:1;
		unsigned char P16OE:1;
		unsigned char P17OE:1;
	};
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;

#define P10OE     	OEP1bits.P10OE      	/* bit 0 */
#define P11OE     	OEP1bits.P11OE      	/* bit 1 */
#define P12OE     	OEP1bits.P12OE      	/* bit 2 */
#define P13OE     	OEP1bits.P13OE      	/* bit 3 */
#define P14OE     	OEP1bits.P14OE      	/* bit 4 */
#define P15OE     	OEP1bits.P15OE      	/* bit 5 */
#define P16OE     	OEP1bits.P16OE      	/* bit 6 */
#define P17OE     	OEP1bits.P17OE      	/* bit 7 */

// ----- PUP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10PU:1;
		unsigned char P11PU:1;
		unsigned char P12PU:1;
		unsigned char P13PU:1;
		unsigned char P14PU:1;
		unsigned char P15PU:1;
		unsigned char P16PU:1;
		unsigned char P17PU:1;
	};
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;

#define P10PU     	PUP1bits.P10PU      	/* bit 0 */
#define P11PU     	PUP1bits.P11PU      	/* bit 1 */
#define P12PU     	PUP1bits.P12PU      	/* bit 2 */
#define P13PU     	PUP1bits.P13PU      	/* bit 3 */
#define P14PU     	PUP1bits.P14PU      	/* bit 4 */
#define P15PU     	PUP1bits.P15PU      	/* bit 5 */
#define P16PU     	PUP1bits.P16PU      	/* bit 6 */
#define P17PU     	PUP1bits.P17PU      	/* bit 7 */

// ----- PDP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10PD:1;
		unsigned char P11PD:1;
		unsigned char P12PD:1;
		unsigned char P13PD:1;
		unsigned char P14PD:1;
		unsigned char P15PD:1;
		unsigned char P16PD:1;
		unsigned char P17PD:1;
	};
} __PDP1bits_t;
extern volatile __PDP1bits_t __at(PDP1_ADDR) PDP1bits;

#define P10PD     	PDP1bits.P10PD      	/* bit 0 */
#define P11PD     	PDP1bits.P11PD      	/* bit 1 */
#define P12PD     	PDP1bits.P12PD      	/* bit 2 */
#define P13PD     	PDP1bits.P13PD      	/* bit 3 */
#define P14PD     	PDP1bits.P14PD      	/* bit 4 */
#define P15PD     	PDP1bits.P15PD      	/* bit 5 */
#define P16PD     	PDP1bits.P16PD      	/* bit 6 */
#define P17PD     	PDP1bits.P17PD      	/* bit 7 */

// ----- IOP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20D:1;
		unsigned char P21D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP2bits_t;
extern volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;

#define P20D      	IOP2bits.P20D       	/* bit 0 */
#define P21D      	IOP2bits.P21D       	/* bit 1 */

// ----- OEP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20OE:1;
		unsigned char P21OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP2bits_t;
extern volatile __OEP2bits_t __at(OEP2_ADDR) OEP2bits;

#define P20OE     	OEP2bits.P20OE      	/* bit 0 */
#define P21OE     	OEP2bits.P21OE      	/* bit 1 */

// ----- PUP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20PU:1;
		unsigned char P21PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP2bits_t;
extern volatile __PUP2bits_t __at(PUP2_ADDR) PUP2bits;

#define P20PU     	PUP2bits.P20PU      	/* bit 0 */
#define P21PU     	PUP2bits.P21PU      	/* bit 1 */

// ----- PDP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20PD:1;
		unsigned char P21PD:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PDP2bits_t;
extern volatile __PDP2bits_t __at(PDP2_ADDR) PDP2bits;

#define P20PD     	PDP2bits.P20PD      	/* bit 0 */
#define P21PD     	PDP2bits.P21PD      	/* bit 1 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0PRS0:1;
		unsigned char T0PRS1:1;
		unsigned char T0PRS2:1;
		unsigned char T0CKS0:1;
		unsigned char T0CKS1:1;
		unsigned char BUZ0OE:1;
		unsigned char PWM0OE:1;
		unsigned char T0EN:1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define T0PRS0    	T0CRbits.T0PRS0     	/* bit 0 */
#define T0PRS1    	T0CRbits.T0PRS1     	/* bit 1 */
#define T0PRS2    	T0CRbits.T0PRS2     	/* bit 2 */
#define T0CKS0    	T0CRbits.T0CKS0     	/* bit 3 */
#define T0CKS1    	T0CRbits.T0CKS1     	/* bit 4 */
#define BUZ0OE    	T0CRbits.BUZ0OE     	/* bit 5 */
#define PWM0OE    	T0CRbits.PWM0OE     	/* bit 6 */
#define T0EN      	T0CRbits.T0EN       	/* bit 7 */

// ----- T0EFR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWMOD0:1;
		unsigned char PWMOD1:1;
		unsigned char PWMOD2:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __T0EFRbits_t;
extern volatile __T0EFRbits_t __at(T0EFR_ADDR) T0EFRbits;

#define PWMOD0    	T0EFRbits.PWMOD0    	/* bit 0 */
#define PWMOD1    	T0EFRbits.PWMOD1    	/* bit 1 */
#define PWMOD2    	T0EFRbits.PWMOD2    	/* bit 2 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PRS0:1;
		unsigned char T1PRS1:1;
		unsigned char T1PRS2:1;
		unsigned char T1CKS0:1;
		unsigned char T1CKS1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char T1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PRS0    	T1CRbits.T1PRS0     	/* bit 0 */
#define T1PRS1    	T1CRbits.T1PRS1     	/* bit 1 */
#define T1PRS2    	T1CRbits.T1PRS2     	/* bit 2 */
#define T1CKS0    	T1CRbits.T1CKS0     	/* bit 3 */
#define T1CKS1    	T1CRbits.T1CKS1     	/* bit 4 */
#define T1EN      	T1CRbits.T1EN       	/* bit 7 */

// ----- T1CNT Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1CNT0:1;
		unsigned char T1CNT1:1;
		unsigned char T1CNT2:1;
		unsigned char T1CNT3:1;
		unsigned char T1CNT4:1;
		unsigned char T1CNT5:1;
		unsigned char T1CNT6:1;
		unsigned char T1CNT7:1;
	};
} __T1CNTbits_t;
extern volatile __T1CNTbits_t __at(T1CNT_ADDR) T1CNTbits;

#define T1CNT0    	T1CNTbits.T1CNT0    	/* bit 0 */
#define T1CNT1    	T1CNTbits.T1CNT1    	/* bit 1 */
#define T1CNT2    	T1CNTbits.T1CNT2    	/* bit 2 */
#define T1CNT3    	T1CNTbits.T1CNT3    	/* bit 3 */
#define T1CNT4    	T1CNTbits.T1CNT4    	/* bit 4 */
#define T1CNT5    	T1CNTbits.T1CNT5    	/* bit 5 */
#define T1CNT6    	T1CNTbits.T1CNT6    	/* bit 6 */
#define T1CNT7    	T1CNTbits.T1CNT7    	/* bit 7 */

// ----- T1LOAD Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1LOAD0:1;
		unsigned char T1LOAD1:1;
		unsigned char T1LOAD2:1;
		unsigned char T1LOAD3:1;
		unsigned char T1LOAD4:1;
		unsigned char T1LOAD5:1;
		unsigned char T1LOAD6:1;
		unsigned char T1LOAD7:1;
	};
} __T1LOADbits_t;
extern volatile __T1LOADbits_t __at(T1LOAD_ADDR) T1LOADbits;

#define T1LOAD0   	T1LOADbits.T1LOAD0  	/* bit 0 */
#define T1LOAD1   	T1LOADbits.T1LOAD1  	/* bit 1 */
#define T1LOAD2   	T1LOADbits.T1LOAD2  	/* bit 2 */
#define T1LOAD3   	T1LOADbits.T1LOAD3  	/* bit 3 */
#define T1LOAD4   	T1LOADbits.T1LOAD4  	/* bit 4 */
#define T1LOAD5   	T1LOADbits.T1LOAD5  	/* bit 5 */
#define T1LOAD6   	T1LOADbits.T1LOAD6  	/* bit 6 */
#define T1LOAD7   	T1LOADbits.T1LOAD7  	/* bit 7 */

// ----- T2CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2PRS0:1;
		unsigned char T2PRS1:1;
		unsigned char T2PRS2:1;
		unsigned char T2CKS0:1;
		unsigned char T2CKS1:1;
		unsigned char :1;
		unsigned char T2MOD:1;
		unsigned char T2EN:1;
	};
} __T2CRbits_t;
extern volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;

#define T2PRS0    	T2CRbits.T2PRS0     	/* bit 0 */
#define T2PRS1    	T2CRbits.T2PRS1     	/* bit 1 */
#define T2PRS2    	T2CRbits.T2PRS2     	/* bit 2 */
#define T2CKS0    	T2CRbits.T2CKS0     	/* bit 3 */
#define T2CKS1    	T2CRbits.T2CKS1     	/* bit 4 */
#define T2MOD     	T2CRbits.T2MOD      	/* bit 6 */
#define T2EN      	T2CRbits.T2EN       	/* bit 7 */

// ----- T2CNT Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2CNT0:1;
		unsigned char T2CNT1:1;
		unsigned char T2CNT2:1;
		unsigned char T2CNT3:1;
		unsigned char T2CNT4:1;
		unsigned char T2CNT5:1;
		unsigned char T2CNT6:1;
		unsigned char T2CNT7:1;
	};
} __T2CNTbits_t;
extern volatile __T2CNTbits_t __at(T2CNT_ADDR) T2CNTbits;

#define T2CNT0    	T2CNTbits.T2CNT0    	/* bit 0 */
#define T2CNT1    	T2CNTbits.T2CNT1    	/* bit 1 */
#define T2CNT2    	T2CNTbits.T2CNT2    	/* bit 2 */
#define T2CNT3    	T2CNTbits.T2CNT3    	/* bit 3 */
#define T2CNT4    	T2CNTbits.T2CNT4    	/* bit 4 */
#define T2CNT5    	T2CNTbits.T2CNT5    	/* bit 5 */
#define T2CNT6    	T2CNTbits.T2CNT6    	/* bit 6 */
#define T2CNT7    	T2CNTbits.T2CNT7    	/* bit 7 */

// ----- T2LOAD Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2LOAD0:1;
		unsigned char T2LOAD1:1;
		unsigned char T2LOAD2:1;
		unsigned char T2LOAD3:1;
		unsigned char T2LOAD4:1;
		unsigned char T2LOAD5:1;
		unsigned char T2LOAD6:1;
		unsigned char T2LOAD7:1;
	};
} __T2LOADbits_t;
extern volatile __T2LOADbits_t __at(T2LOAD_ADDR) T2LOADbits;

#define T2LOAD0   	T2LOADbits.T2LOAD0  	/* bit 0 */
#define T2LOAD1   	T2LOADbits.T2LOAD1  	/* bit 1 */
#define T2LOAD2   	T2LOADbits.T2LOAD2  	/* bit 2 */
#define T2LOAD3   	T2LOADbits.T2LOAD3  	/* bit 3 */
#define T2LOAD4   	T2LOADbits.T2LOAD4  	/* bit 4 */
#define T2LOAD5   	T2LOADbits.T2LOAD5  	/* bit 5 */
#define T2LOAD6   	T2LOADbits.T2LOAD6  	/* bit 6 */
#define T2LOAD7   	T2LOADbits.T2LOAD7  	/* bit 7 */

// ----- T2EFR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2PLS:1;
		unsigned char T2PIS:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __T2EFRbits_t;
extern volatile __T2EFRbits_t __at(T2EFR_ADDR) T2EFRbits;

#define T2PLS     	T2EFRbits.T2PLS     	/* bit 0 */
#define T2PIS     	T2EFRbits.T2PIS     	/* bit 1 */

// ----- T3CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T3PRS0:1;
		unsigned char T3PRS1:1;
		unsigned char T3PRS2:1;
		unsigned char T3CKS0:1;
		unsigned char T3CKS1:1;
		unsigned char :1;
		unsigned char T3MOD:1;
		unsigned char T3EN:1;
	};
} __T3CRbits_t;
extern volatile __T3CRbits_t __at(T3CR_ADDR) T3CRbits;

#define T3PRS0    	T3CRbits.T3PRS0     	/* bit 0 */
#define T3PRS1    	T3CRbits.T3PRS1     	/* bit 1 */
#define T3PRS2    	T3CRbits.T3PRS2     	/* bit 2 */
#define T3CKS0    	T3CRbits.T3CKS0     	/* bit 3 */
#define T3CKS1    	T3CRbits.T3CKS1     	/* bit 4 */
#define T3MOD     	T3CRbits.T3MOD      	/* bit 6 */
#define T3EN      	T3CRbits.T3EN       	/* bit 7 */

// ----- T3CNT Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T3CNT0:1;
		unsigned char T3CNT1:1;
		unsigned char T3CNT2:1;
		unsigned char T3CNT3:1;
		unsigned char T3CNT4:1;
		unsigned char T3CNT5:1;
		unsigned char T3CNT6:1;
		unsigned char T3CNT7:1;
	};
} __T3CNTbits_t;
extern volatile __T3CNTbits_t __at(T3CNT_ADDR) T3CNTbits;

#define T3CNT0    	T3CNTbits.T3CNT0    	/* bit 0 */
#define T3CNT1    	T3CNTbits.T3CNT1    	/* bit 1 */
#define T3CNT2    	T3CNTbits.T3CNT2    	/* bit 2 */
#define T3CNT3    	T3CNTbits.T3CNT3    	/* bit 3 */
#define T3CNT4    	T3CNTbits.T3CNT4    	/* bit 4 */
#define T3CNT5    	T3CNTbits.T3CNT5    	/* bit 5 */
#define T3CNT6    	T3CNTbits.T3CNT6    	/* bit 6 */
#define T3CNT7    	T3CNTbits.T3CNT7    	/* bit 7 */

// ----- T3LOAD Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T3LOAD0:1;
		unsigned char T3LOAD1:1;
		unsigned char T3LOAD2:1;
		unsigned char T3LOAD3:1;
		unsigned char T3LOAD4:1;
		unsigned char T3LOAD5:1;
		unsigned char T3LOAD6:1;
		unsigned char T3LOAD7:1;
	};
} __T3LOADbits_t;
extern volatile __T3LOADbits_t __at(T3LOAD_ADDR) T3LOADbits;

#define T3LOAD0   	T3LOADbits.T3LOAD0  	/* bit 0 */
#define T3LOAD1   	T3LOADbits.T3LOAD1  	/* bit 1 */
#define T3LOAD2   	T3LOADbits.T3LOAD2  	/* bit 2 */
#define T3LOAD3   	T3LOADbits.T3LOAD3  	/* bit 3 */
#define T3LOAD4   	T3LOADbits.T3LOAD4  	/* bit 4 */
#define T3LOAD5   	T3LOADbits.T3LOAD5  	/* bit 5 */
#define T3LOAD6   	T3LOADbits.T3LOAD6  	/* bit 6 */
#define T3LOAD7   	T3LOADbits.T3LOAD7  	/* bit 7 */

// ----- IICCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char RACK:1;
		unsigned char IICEN:1;
		unsigned char MSTCMD:1;
		unsigned char SACK:1;
		unsigned char IICMOD:1;
		unsigned char IICBUSY:1;
		unsigned char IICAAS:1;
		unsigned char IICEOF:1;
	};
} __IICCRbits_t;
extern volatile __IICCRbits_t __at(IICCR_ADDR) IICCRbits;

#define RACK      	IICCRbits.RACK      	/* bit 0 */
#define IICEN     	IICCRbits.IICEN     	/* bit 1 */
#define MSTCMD    	IICCRbits.MSTCMD    	/* bit 2 */
#define SACK      	IICCRbits.SACK      	/* bit 3 */
#define IICMOD    	IICCRbits.IICMOD    	/* bit 4 */
#define IICBUSY   	IICCRbits.IICBUSY   	/* bit 5 */
#define IICAAS    	IICCRbits.IICAAS    	/* bit 6 */
#define IICEOF    	IICCRbits.IICEOF    	/* bit 7 */

// ----- IICAR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char IICAD0:1;
		unsigned char IICAD1:1;
		unsigned char IICAD2:1;
		unsigned char IICAD3:1;
		unsigned char IICAD4:1;
		unsigned char IICAD5:1;
		unsigned char IICAD6:1;
	};
} __IICARbits_t;
extern volatile __IICARbits_t __at(IICAR_ADDR) IICARbits;

#define IICAD0    	IICARbits.IICAD0    	/* bit 1 */
#define IICAD1    	IICARbits.IICAD1    	/* bit 2 */
#define IICAD2    	IICARbits.IICAD2    	/* bit 3 */
#define IICAD3    	IICARbits.IICAD3    	/* bit 4 */
#define IICAD4    	IICARbits.IICAD4    	/* bit 5 */
#define IICAD5    	IICARbits.IICAD5    	/* bit 6 */
#define IICAD6    	IICARbits.IICAD6    	/* bit 7 */

// ----- EECR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char EERW:1;
		unsigned char EETRIG:1;
	};
} __EECRbits_t;
extern volatile __EECRbits_t __at(EECR_ADDR) EECRbits;

#define EERW      	EECRbits.EERW       	/* bit 6 */
#define EETRIG    	EECRbits.EETRIG     	/* bit 7 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADEN:1;
		unsigned char ADEOC:1;
		unsigned char ADVRS:1;
		unsigned char :1;
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char ADCHS3:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADEN      	ADCR0bits.ADEN      	/* bit 0 */
#define ADEOC     	ADCR0bits.ADEOC     	/* bit 1 */
#define ADVRS     	ADCR0bits.ADVRS     	/* bit 2 */
#define ADCHS0    	ADCR0bits.ADCHS0    	/* bit 4 */
#define ADCHS1    	ADCR0bits.ADCHS1    	/* bit 5 */
#define ADCHS2    	ADCR0bits.ADCHS2    	/* bit 6 */
#define ADCHS3    	ADCR0bits.ADCHS3    	/* bit 7 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADSPS0:1;
		unsigned char ADSPS1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char ADCKS0:1;
		unsigned char ADCKS1:1;
		unsigned char :1;
		unsigned char ADRSEL:1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define ADSPS0    	ADCR1bits.ADSPS0    	/* bit 0 */
#define ADSPS1    	ADCR1bits.ADSPS1    	/* bit 1 */
#define ADCKS0    	ADCR1bits.ADCKS0    	/* bit 4 */
#define ADCKS1    	ADCR1bits.ADCKS1    	/* bit 5 */
#define ADRSEL    	ADCR1bits.ADRSEL    	/* bit 7 */

// ----- ADIOS0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00ADS:1;
		unsigned char P01ADS:1;
		unsigned char P02ADS:1;
		unsigned char P03ADS:1;
		unsigned char P04ADS:1;
		unsigned char P05ADS:1;
		unsigned char P06ADS:1;
		unsigned char P07ADS:1;
	};
} __ADIOS0bits_t;
extern volatile __ADIOS0bits_t __at(ADIOS0_ADDR) ADIOS0bits;

#define P00ADS    	ADIOS0bits.P00ADS   	/* bit 0 */
#define P01ADS    	ADIOS0bits.P01ADS   	/* bit 1 */
#define P02ADS    	ADIOS0bits.P02ADS   	/* bit 2 */
#define P03ADS    	ADIOS0bits.P03ADS   	/* bit 3 */
#define P04ADS    	ADIOS0bits.P04ADS   	/* bit 4 */
#define P05ADS    	ADIOS0bits.P05ADS   	/* bit 5 */
#define P06ADS    	ADIOS0bits.P06ADS   	/* bit 6 */
#define P07ADS    	ADIOS0bits.P07ADS   	/* bit 7 */

// ----- ADIOS1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10ADS:1;
		unsigned char P11ADS:1;
		unsigned char P12ADS:1;
		unsigned char P13ADS:1;
		unsigned char P14ADS:1;
		unsigned char P15ADS:1;
		unsigned char P16ADS:1;
		unsigned char P17ADS:1;
	};
} __ADIOS1bits_t;
extern volatile __ADIOS1bits_t __at(ADIOS1_ADDR) ADIOS1bits;

#define P10ADS    	ADIOS1bits.P10ADS   	/* bit 0 */
#define P11ADS    	ADIOS1bits.P11ADS   	/* bit 1 */
#define P12ADS    	ADIOS1bits.P12ADS   	/* bit 2 */
#define P13ADS    	ADIOS1bits.P13ADS   	/* bit 3 */
#define P14ADS    	ADIOS1bits.P14ADS   	/* bit 4 */
#define P15ADS    	ADIOS1bits.P15ADS   	/* bit 5 */
#define P16ADS    	ADIOS1bits.P16ADS   	/* bit 6 */
#define P17ADS    	ADIOS1bits.P17ADS   	/* bit 7 */

// ----- OSADJCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OSADJTR0:1;
		unsigned char OSADJTR1:1;
		unsigned char OSADJTR2:1;
		unsigned char OSADJTR3:1;
		unsigned char OSADJTR4:1;
		unsigned char OSADJTR5:1;
		unsigned char :1;
		unsigned char OSADJEN:1;
	};
} __OSADJCRbits_t;
extern volatile __OSADJCRbits_t __at(OSADJCR_ADDR) OSADJCRbits;

#define OSADJTR0  	OSADJCRbits.OSADJTR0	/* bit 0 */
#define OSADJTR1  	OSADJCRbits.OSADJTR1	/* bit 1 */
#define OSADJTR2  	OSADJCRbits.OSADJTR2	/* bit 2 */
#define OSADJTR3  	OSADJCRbits.OSADJTR3	/* bit 3 */
#define OSADJTR4  	OSADJCRbits.OSADJTR4	/* bit 4 */
#define OSADJTR5  	OSADJCRbits.OSADJTR5	/* bit 5 */
#define OSADJEN   	OSADJCRbits.OSADJEN 	/* bit 7 */

// ----- PPGCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PPGPRS0:1;
		unsigned char PPGPRS1:1;
		unsigned char PPGSTR:1;
		unsigned char TRIGSYN:1;
		unsigned char PSTPEN:1;
		unsigned char PSTREN:1;
		unsigned char POLEV:1;
		unsigned char PPGEN:1;
	};
} __PPGCRbits_t;
extern volatile __PPGCRbits_t __at(PPGCR_ADDR) PPGCRbits;

#define PPGPRS0   	PPGCRbits.PPGPRS0   	/* bit 0 */
#define PPGPRS1   	PPGCRbits.PPGPRS1   	/* bit 1 */
#define PPGSTR    	PPGCRbits.PPGSTR    	/* bit 2 */
#define TRIGSYN   	PPGCRbits.TRIGSYN   	/* bit 3 */
#define PSTPEN    	PPGCRbits.PSTPEN    	/* bit 4 */
#define PSTREN    	PPGCRbits.PSTREN    	/* bit 5 */
#define POLEV     	PPGCRbits.POLEV     	/* bit 6 */
#define PPGEN     	PPGCRbits.PPGEN     	/* bit 7 */

// ----- PPGLOAD Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PGLOAD0:1;
		unsigned char PGLOAD1:1;
		unsigned char PGLOAD2:1;
		unsigned char PGLOAD3:1;
		unsigned char PGLOAD4:1;
		unsigned char PGLOAD5:1;
		unsigned char PGLOAD6:1;
		unsigned char PGLOAD7:1;
	};
} __PPGLOADbits_t;
extern volatile __PPGLOADbits_t __at(PPGLOAD_ADDR) PPGLOADbits;

#define PGLOAD0   	PPGLOADbits.PGLOAD0 	/* bit 0 */
#define PGLOAD1   	PPGLOADbits.PGLOAD1 	/* bit 1 */
#define PGLOAD2   	PPGLOADbits.PGLOAD2 	/* bit 2 */
#define PGLOAD3   	PPGLOADbits.PGLOAD3 	/* bit 3 */
#define PGLOAD4   	PPGLOADbits.PGLOAD4 	/* bit 4 */
#define PGLOAD5   	PPGLOADbits.PGLOAD5 	/* bit 5 */
#define PGLOAD6   	PPGLOADbits.PGLOAD6 	/* bit 6 */
#define PGLOAD7   	PPGLOADbits.PGLOAD7 	/* bit 7 */

// ----- PPGTDL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PPGTDL0:1;
		unsigned char PPGTDL1:1;
		unsigned char PPGTDL2:1;
		unsigned char PPGTDL3:1;
		unsigned char PPGTDL4:1;
		unsigned char PPGTDL5:1;
		unsigned char PGLOAD8:1;
		unsigned char PGLOAD9:1;
	};
} __PPGTDLbits_t;
extern volatile __PPGTDLbits_t __at(PPGTDL_ADDR) PPGTDLbits;

#define PPGTDL0   	PPGTDLbits.PPGTDL0  	/* bit 0 */
#define PPGTDL1   	PPGTDLbits.PPGTDL1  	/* bit 1 */
#define PPGTDL2   	PPGTDLbits.PPGTDL2  	/* bit 2 */
#define PPGTDL3   	PPGTDLbits.PPGTDL3  	/* bit 3 */
#define PPGTDL4   	PPGTDLbits.PPGTDL4  	/* bit 4 */
#define PPGTDL5   	PPGTDLbits.PPGTDL5  	/* bit 5 */
#define PGLOAD8   	PPGTDLbits.PGLOAD8  	/* bit 6 */
#define PGLOAD9   	PPGTDLbits.PGLOAD9  	/* bit 7 */

// ----- PPGTDB Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PPGTDB0:1;
		unsigned char PPGTDB1:1;
		unsigned char PPGTDB2:1;
		unsigned char PPGTDB3:1;
		unsigned char PPGTDB4:1;
		unsigned char PPGTDB5:1;
		unsigned char PPGTEG:1;
		unsigned char PPGTIS:1;
	};
} __PPGTDBbits_t;
extern volatile __PPGTDBbits_t __at(PPGTDB_ADDR) PPGTDBbits;

#define PPGTDB0   	PPGTDBbits.PPGTDB0  	/* bit 0 */
#define PPGTDB1   	PPGTDBbits.PPGTDB1  	/* bit 1 */
#define PPGTDB2   	PPGTDBbits.PPGTDB2  	/* bit 2 */
#define PPGTDB3   	PPGTDBbits.PPGTDB3  	/* bit 3 */
#define PPGTDB4   	PPGTDBbits.PPGTDB4  	/* bit 4 */
#define PPGTDB5   	PPGTDBbits.PPGTDB5  	/* bit 5 */
#define PPGTEG    	PPGTDBbits.PPGTEG   	/* bit 6 */
#define PPGTIS    	PPGTDBbits.PPGTIS   	/* bit 7 */

// ----- OPACR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OPAPS0:1;
		unsigned char OPAPS1:1;
		unsigned char OPAOS0:1;
		unsigned char OPAOS1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char OPAOP:1;
		unsigned char OPAEN:1;
	};
} __OPACRbits_t;
extern volatile __OPACRbits_t __at(OPACR_ADDR) OPACRbits;

#define OPAPS0    	OPACRbits.OPAPS0    	/* bit 0 */
#define OPAPS1    	OPACRbits.OPAPS1    	/* bit 1 */
#define OPAOS0    	OPACRbits.OPAOS0    	/* bit 2 */
#define OPAOS1    	OPACRbits.OPAOS1    	/* bit 3 */
#define OPAOP     	OPACRbits.OPAOP     	/* bit 6 */
#define OPAEN     	OPACRbits.OPAEN     	/* bit 7 */

// ----- OPACLR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OPADLR0:1;
		unsigned char OPADLR1:1;
		unsigned char OPADLR2:1;
		unsigned char OPADLR3:1;
		unsigned char OPADLR4:1;
		unsigned char OPADLR5:1;
		unsigned char OPACLRS:1;
		unsigned char OPAMOD:1;
	};
} __OPACLRbits_t;
extern volatile __OPACLRbits_t __at(OPACLR_ADDR) OPACLRbits;

#define OPADLR0   	OPACLRbits.OPADLR0  	/* bit 0 */
#define OPADLR1   	OPACLRbits.OPADLR1  	/* bit 1 */
#define OPADLR2   	OPACLRbits.OPADLR2  	/* bit 2 */
#define OPADLR3   	OPACLRbits.OPADLR3  	/* bit 3 */
#define OPADLR4   	OPACLRbits.OPADLR4  	/* bit 4 */
#define OPADLR5   	OPACLRbits.OPADLR5  	/* bit 5 */
#define OPACLRS   	OPACLRbits.OPACLRS  	/* bit 6 */
#define OPAMOD    	OPACLRbits.OPAMOD   	/* bit 7 */

// ----- CPCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP0EN:1;
		unsigned char CP1EN:1;
		unsigned char CP2EN:1;
		unsigned char CP3EN:1;
		unsigned char CP1NS:1;
		unsigned char CP3NS0:1;
		unsigned char CP3NS1:1;
		unsigned char :1;
	};
} __CPCRbits_t;
extern volatile __CPCRbits_t __at(CPCR_ADDR) CPCRbits;

#define CP0EN     	CPCRbits.CP0EN      	/* bit 0 */
#define CP1EN     	CPCRbits.CP1EN      	/* bit 1 */
#define CP2EN     	CPCRbits.CP2EN      	/* bit 2 */
#define CP3EN     	CPCRbits.CP3EN      	/* bit 3 */
#define CP1NS     	CPCRbits.CP1NS      	/* bit 4 */
#define CP3NS0    	CPCRbits.CP3NS0     	/* bit 5 */
#define CP3NS1    	CPCRbits.CP3NS1     	/* bit 6 */

// ----- CPSR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP0OP:1;
		unsigned char CP1OP:1;
		unsigned char CP2OP:1;
		unsigned char CP3OP:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __CPSRbits_t;
extern volatile __CPSRbits_t __at(CPSR_ADDR) CPSRbits;

#define CP0OP     	CPSRbits.CP0OP      	/* bit 0 */
#define CP1OP     	CPSRbits.CP1OP      	/* bit 1 */
#define CP2OP     	CPSRbits.CP2OP      	/* bit 2 */
#define CP3OP     	CPSRbits.CP3OP      	/* bit 3 */

// ----- CPVR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP1VS0:1;
		unsigned char CP1VS1:1;
		unsigned char CP1VS2:1;
		unsigned char CP1VS3:1;
		unsigned char CP2VS0:1;
		unsigned char VP2VS1:1;
		unsigned char CP2VS2:1;
		unsigned char CP2VS3:1;
	};
} __CPVR0bits_t;
extern volatile __CPVR0bits_t __at(CPVR0_ADDR) CPVR0bits;

#define CP1VS0    	CPVR0bits.CP1VS0    	/* bit 0 */
#define CP1VS1    	CPVR0bits.CP1VS1    	/* bit 1 */
#define CP1VS2    	CPVR0bits.CP1VS2    	/* bit 2 */
#define CP1VS3    	CPVR0bits.CP1VS3    	/* bit 3 */
#define CP2VS0    	CPVR0bits.CP2VS0    	/* bit 4 */
#define VP2VS1    	CPVR0bits.VP2VS1    	/* bit 5 */
#define CP2VS2    	CPVR0bits.CP2VS2    	/* bit 6 */
#define CP2VS3    	CPVR0bits.CP2VS3    	/* bit 7 */

// ----- CPVR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP3VS0:1;
		unsigned char CP3VS1:1;
		unsigned char CP3VS2:1;
		unsigned char CP3VS3:1;
		unsigned char CP3VS4:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __CPVR1bits_t;
extern volatile __CPVR1bits_t __at(CPVR1_ADDR) CPVR1bits;

#define CP3VS0    	CPVR1bits.CP3VS0    	/* bit 0 */
#define CP3VS1    	CPVR1bits.CP3VS1    	/* bit 1 */
#define CP3VS2    	CPVR1bits.CP3VS2    	/* bit 2 */
#define CP3VS3    	CPVR1bits.CP3VS3    	/* bit 3 */
#define CP3VS4    	CPVR1bits.CP3VS4    	/* bit 4 */

// ----- CP0CLR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP0CLR0:1;
		unsigned char CP0CLR1:1;
		unsigned char CP0CLR2:1;
		unsigned char CP0CLR3:1;
		unsigned char CP0CLR4:1;
		unsigned char CP0CLR5:1;
		unsigned char CP0CLRS:1;
		unsigned char CP0MOD:1;
	};
} __CP0CLRbits_t;
extern volatile __CP0CLRbits_t __at(CP0CLR_ADDR) CP0CLRbits;

#define CP0CLR0   	CP0CLRbits.CP0CLR0  	/* bit 0 */
#define CP0CLR1   	CP0CLRbits.CP0CLR1  	/* bit 1 */
#define CP0CLR2   	CP0CLRbits.CP0CLR2  	/* bit 2 */
#define CP0CLR3   	CP0CLRbits.CP0CLR3  	/* bit 3 */
#define CP0CLR4   	CP0CLRbits.CP0CLR4  	/* bit 4 */
#define CP0CLR5   	CP0CLRbits.CP0CLR5  	/* bit 5 */
#define CP0CLRS   	CP0CLRbits.CP0CLRS  	/* bit 6 */
#define CP0MOD    	CP0CLRbits.CP0MOD   	/* bit 7 */

// ----- CP1CLR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP1CLR0:1;
		unsigned char CP1CLR1:1;
		unsigned char CP1CLR2:1;
		unsigned char CP1CLR3:1;
		unsigned char CP1CLR4:1;
		unsigned char CP1CLR5:1;
		unsigned char CP1CLRS:1;
		unsigned char CP1MOD:1;
	};
} __CP1CLRbits_t;
extern volatile __CP1CLRbits_t __at(CP1CLR_ADDR) CP1CLRbits;

#define CP1CLR0   	CP1CLRbits.CP1CLR0  	/* bit 0 */
#define CP1CLR1   	CP1CLRbits.CP1CLR1  	/* bit 1 */
#define CP1CLR2   	CP1CLRbits.CP1CLR2  	/* bit 2 */
#define CP1CLR3   	CP1CLRbits.CP1CLR3  	/* bit 3 */
#define CP1CLR4   	CP1CLRbits.CP1CLR4  	/* bit 4 */
#define CP1CLR5   	CP1CLRbits.CP1CLR5  	/* bit 5 */
#define CP1CLRS   	CP1CLRbits.CP1CLRS  	/* bit 6 */
#define CP1MOD    	CP1CLRbits.CP1MOD   	/* bit 7 */

// ----- CP2CLR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP2CLR0:1;
		unsigned char CP2CLR1:1;
		unsigned char CP2CLR2:1;
		unsigned char CP2CLR3:1;
		unsigned char CP2CLR4:1;
		unsigned char CP2CLR5:1;
		unsigned char CP2CLRS:1;
		unsigned char CP2MOD:1;
	};
} __CP2CLRbits_t;
extern volatile __CP2CLRbits_t __at(CP2CLR_ADDR) CP2CLRbits;

#define CP2CLR0   	CP2CLRbits.CP2CLR0  	/* bit 0 */
#define CP2CLR1   	CP2CLRbits.CP2CLR1  	/* bit 1 */
#define CP2CLR2   	CP2CLRbits.CP2CLR2  	/* bit 2 */
#define CP2CLR3   	CP2CLRbits.CP2CLR3  	/* bit 3 */
#define CP2CLR4   	CP2CLRbits.CP2CLR4  	/* bit 4 */
#define CP2CLR5   	CP2CLRbits.CP2CLR5  	/* bit 5 */
#define CP2CLRS   	CP2CLRbits.CP2CLRS  	/* bit 6 */
#define CP2MOD    	CP2CLRbits.CP2MOD   	/* bit 7 */

// ----- CP3CLR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CP3CLR0:1;
		unsigned char CP3CLR1:1;
		unsigned char CP3CLR2:1;
		unsigned char CP3CLR3:1;
		unsigned char CP3CLR4:1;
		unsigned char CP3CLR5:1;
		unsigned char CP3CLRS:1;
		unsigned char CP3MOD:1;
	};
} __CP3CLRbits_t;
extern volatile __CP3CLRbits_t __at(CP3CLR_ADDR) CP3CLRbits;

#define CP3CLR0   	CP3CLRbits.CP3CLR0  	/* bit 0 */
#define CP3CLR1   	CP3CLRbits.CP3CLR1  	/* bit 1 */
#define CP3CLR2   	CP3CLRbits.CP3CLR2  	/* bit 2 */
#define CP3CLR3   	CP3CLRbits.CP3CLR3  	/* bit 3 */
#define CP3CLR4   	CP3CLRbits.CP3CLR4  	/* bit 4 */
#define CP3CLR5   	CP3CLRbits.CP3CLR5  	/* bit 5 */
#define CP3CLRS   	CP3CLRbits.CP3CLRS  	/* bit 6 */
#define CP3MOD    	CP3CLRbits.CP3MOD   	/* bit 7 */

#endif
