#ifndef MC99P3_H
#define MC99P3_H

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
#define KBCR_ADDR       	0x018F
#define IOP0_ADDR       	0x0190
#define OEP0_ADDR       	0x0191
#define PUP0_ADDR       	0x0192
#define IOP1_ADDR       	0x0194
#define OEP1_ADDR       	0x0195
#define PUP1_ADDR       	0x0196
#define IOP2_ADDR       	0x0198
#define OEP2_ADDR       	0x0199
#define PUP2_ADDR       	0x019A
#define T0CR_ADDR       	0x01A0
#define T0CNT_ADDR      	0x01A1
#define T0LOAD_ADDR     	0x01A2
#define T0DATA_ADDR     	0x01A3
#define T1CR_ADDR       	0x01A8
#define T1CNTH_ADDR     	0x01A9
#define T1CNTL_ADDR     	0x01AA
#define T1LOADH_ADDR    	0x01AB
#define T1LOADL_ADDR    	0x01AC
#define T1DATAH_ADDR    	0x01AD
#define T1DATAL_ADDR    	0x01AE
#define IICCR_ADDR      	0x01B0
#define IICSR_ADDR      	0x01B1
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
extern __sfr __at (KBCR_ADDR)     	KBCR;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (IOP2_ADDR)     	IOP2;
extern __sfr __at (OEP2_ADDR)     	OEP2;
extern __sfr __at (PUP2_ADDR)     	PUP2;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNTH_ADDR)   	T1CNTH;
extern __sfr __at (T1CNTL_ADDR)   	T1CNTL;
extern __sfr __at (T1LOADH_ADDR)  	T1LOADH;
extern __sfr __at (T1LOADL_ADDR)  	T1LOADL;
extern __sfr __at (T1DATAH_ADDR)  	T1DATAH;
extern __sfr __at (T1DATAL_ADDR)  	T1DATAL;
extern __sfr __at (IICCR_ADDR)    	IICCR;
extern __sfr __at (IICSR_ADDR)    	IICSR;
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
		unsigned char KBIE:1;
		unsigned char IICIE:1;
		unsigned char ADIE:1;
		unsigned char UARTIE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define KBIE      	INTEbits.KBIE       	/* bit 4 */
#define IICIE     	INTEbits.IICIE      	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */
#define UARTIE    	INTEbits.UARTIE     	/* bit 7 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char KBIF:1;
		unsigned char IICIF:1;
		unsigned char ADIF:1;
		unsigned char UARTIF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define KBIF      	INTFbits.KBIF       	/* bit 4 */
#define IICIF     	INTFbits.IICIF      	/* bit 5 */
#define ADIF      	INTFbits.ADIF       	/* bit 6 */
#define UARTIF    	INTFbits.UARTIF     	/* bit 7 */

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

// ----- IOP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20D:1;
		unsigned char P21D:1;
		unsigned char P22D:1;
		unsigned char P23D:1;
		unsigned char P24D:1;
		unsigned char P25D:1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP2bits_t;
extern volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;

#define P20D      	IOP2bits.P20D       	/* bit 0 */
#define P21D      	IOP2bits.P21D       	/* bit 1 */
#define P22D      	IOP2bits.P22D       	/* bit 2 */
#define P23D      	IOP2bits.P23D       	/* bit 3 */
#define P24D      	IOP2bits.P24D       	/* bit 4 */
#define P25D      	IOP2bits.P25D       	/* bit 5 */

// ----- OEP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20OE:1;
		unsigned char P21OE:1;
		unsigned char P22OE:1;
		unsigned char P23OE:1;
		unsigned char P24OE:1;
		unsigned char P25OE:1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP2bits_t;
extern volatile __OEP2bits_t __at(OEP2_ADDR) OEP2bits;

#define P20OE     	OEP2bits.P20OE      	/* bit 0 */
#define P21OE     	OEP2bits.P21OE      	/* bit 1 */
#define P22OE     	OEP2bits.P22OE      	/* bit 2 */
#define P23OE     	OEP2bits.P23OE      	/* bit 3 */
#define P24OE     	OEP2bits.P24OE      	/* bit 4 */
#define P25OE     	OEP2bits.P25OE      	/* bit 5 */

// ----- PUP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20PU:1;
		unsigned char P21PU:1;
		unsigned char P22PU:1;
		unsigned char P23PU:1;
		unsigned char P24PU:1;
		unsigned char P25PU:1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP2bits_t;
extern volatile __PUP2bits_t __at(PUP2_ADDR) PUP2bits;

#define P20PU     	PUP2bits.P20PU      	/* bit 0 */
#define P21PU     	PUP2bits.P21PU      	/* bit 1 */
#define P22PU     	PUP2bits.P22PU      	/* bit 2 */
#define P23PU     	PUP2bits.P23PU      	/* bit 3 */
#define P24PU     	PUP2bits.P24PU      	/* bit 4 */
#define P25PU     	PUP2bits.P25PU      	/* bit 5 */

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

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PRS0:1;
		unsigned char T1PRS1:1;
		unsigned char T1PRS2:1;
		unsigned char T1CKS0:1;
		unsigned char T1CKS1:1;
		unsigned char :1;
		unsigned char PWM1OE:1;
		unsigned char T1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PRS0    	T1CRbits.T1PRS0     	/* bit 0 */
#define T1PRS1    	T1CRbits.T1PRS1     	/* bit 1 */
#define T1PRS2    	T1CRbits.T1PRS2     	/* bit 2 */
#define T1CKS0    	T1CRbits.T1CKS0     	/* bit 3 */
#define T1CKS1    	T1CRbits.T1CKS1     	/* bit 4 */
#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 6 */
#define T1EN      	T1CRbits.T1EN       	/* bit 7 */

// ----- IICCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char IICIMS:1;
		unsigned char IICRDTP:1;
		unsigned char IICTYP0:1;
		unsigned char IICTYP1:1;
		unsigned char IICCKS0:1;
		unsigned char IICCKS1:1;
		unsigned char IICRS:1;
		unsigned char IICEN:1;
	};
} __IICCRbits_t;
extern volatile __IICCRbits_t __at(IICCR_ADDR) IICCRbits;

#define IICIMS    	IICCRbits.IICIMS    	/* bit 0 */
#define IICRDTP   	IICCRbits.IICRDTP   	/* bit 1 */
#define IICTYP0   	IICCRbits.IICTYP0   	/* bit 2 */
#define IICTYP1   	IICCRbits.IICTYP1   	/* bit 3 */
#define IICCKS0   	IICCRbits.IICCKS0   	/* bit 4 */
#define IICCKS1   	IICCRbits.IICCKS1   	/* bit 5 */
#define IICRS     	IICCRbits.IICRS     	/* bit 6 */
#define IICEN     	IICCRbits.IICEN     	/* bit 7 */

// ----- IICSR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char RACK:1;
		unsigned char SACK:1;
		unsigned char IICACK:1;
		unsigned char IICWR:1;
		unsigned char IICRD:1;
		unsigned char IICSTP:1;
		unsigned char IICSTR:1;
	};
} __IICSRbits_t;
extern volatile __IICSRbits_t __at(IICSR_ADDR) IICSRbits;

#define RACK      	IICSRbits.RACK      	/* bit 1 */
#define SACK      	IICSRbits.SACK      	/* bit 2 */
#define IICACK    	IICSRbits.IICACK    	/* bit 3 */
#define IICWR     	IICSRbits.IICWR     	/* bit 4 */
#define IICRD     	IICSRbits.IICRD     	/* bit 5 */
#define IICSTP    	IICSRbits.IICSTP    	/* bit 6 */
#define IICSTR    	IICSRbits.IICSTR    	/* bit 7 */

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
		unsigned char VRS0:1;
		unsigned char VRS1:1;
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char ADCHS3:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADEN      	ADCR0bits.ADEN      	/* bit 0 */
#define ADEOC     	ADCR0bits.ADEOC     	/* bit 1 */
#define VRS0      	ADCR0bits.VRS0      	/* bit 2 */
#define VRS1      	ADCR0bits.VRS1      	/* bit 3 */
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
		unsigned char AN0EN:1;
		unsigned char AN1EN:1;
		unsigned char AN2EN:1;
		unsigned char AN3EN:1;
		unsigned char AN4EN:1;
		unsigned char AN5EN:1;
		unsigned char AN6EN:1;
		unsigned char AN7EN:1;
	};
} __ADIOS0bits_t;
extern volatile __ADIOS0bits_t __at(ADIOS0_ADDR) ADIOS0bits;

#define AN0EN     	ADIOS0bits.AN0EN    	/* bit 0 */
#define AN1EN     	ADIOS0bits.AN1EN    	/* bit 1 */
#define AN2EN     	ADIOS0bits.AN2EN    	/* bit 2 */
#define AN3EN     	ADIOS0bits.AN3EN    	/* bit 3 */
#define AN4EN     	ADIOS0bits.AN4EN    	/* bit 4 */
#define AN5EN     	ADIOS0bits.AN5EN    	/* bit 5 */
#define AN6EN     	ADIOS0bits.AN6EN    	/* bit 6 */
#define AN7EN     	ADIOS0bits.AN7EN    	/* bit 7 */

// ----- ADIOS1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char AN8EN:1;
		unsigned char AN9EN:1;
		unsigned char AN10EN:1;
		unsigned char AN11EN:1;
		unsigned char AN12EN:1;
		unsigned char AN13EN:1;
		unsigned char :1;
		unsigned char :1;
	};
} __ADIOS1bits_t;
extern volatile __ADIOS1bits_t __at(ADIOS1_ADDR) ADIOS1bits;

#define AN8EN     	ADIOS1bits.AN8EN    	/* bit 0 */
#define AN9EN     	ADIOS1bits.AN9EN    	/* bit 1 */
#define AN10EN    	ADIOS1bits.AN10EN   	/* bit 2 */
#define AN11EN    	ADIOS1bits.AN11EN   	/* bit 3 */
#define AN12EN    	ADIOS1bits.AN12EN   	/* bit 4 */
#define AN13EN    	ADIOS1bits.AN13EN   	/* bit 5 */

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

#endif
