#ifndef MC99P2_H
#define MC99P2_H

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
#define PFLAG_ADDR      	0x0187
#define MCR_ADDR        	0x0188
#define INDF3_ADDR      	0x0189
#define INTE_ADDR       	0x018A
#define INTF_ADDR       	0x018B
#define OSCM_ADDR       	0x018C
#define LVDCR_ADDR      	0x018D
#define IOP0_ADDR       	0x0190
#define OEP0_ADDR       	0x0191
#define PUP0_ADDR       	0x0192
#define RUPSEL_ADDR     	0x0193
#define IOP1_ADDR       	0x0194
#define OEP1_ADDR       	0x0195
#define PUP1_ADDR       	0x0196
#define T0CR_ADDR       	0x01A0
#define T0CNT_ADDR      	0x01A1
#define T0LOAD_ADDR     	0x01A2
#define T0DATA_ADDR     	0x01A3
#define T1CR_ADDR       	0x01A4
#define T1CNT_ADDR      	0x01A5
#define T1LOAD_ADDR     	0x01A6
#define T1DATA_ADDR     	0x01A7
#define ADCR0_ADDR      	0x01B0
#define ADCR1_ADDR      	0x01B1
#define ADCR2_ADDR      	0x01B2
#define ADRH_ADDR       	0x01B4
#define ADRM_ADDR       	0x01B5
#define ADRL_ADDR       	0x01B6
#define IICCR_ADDR      	0x01B8
#define IICAR_ADDR      	0x01B9
#define IICDR_ADDR      	0x01BA

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
extern __sfr __at (PFLAG_ADDR)    	PFLAG;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INDF3_ADDR)    	INDF3;
extern __sfr __at (INTE_ADDR)     	INTE;
extern __sfr __at (INTF_ADDR)     	INTF;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (LVDCR_ADDR)    	LVDCR;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (RUPSEL_ADDR)   	RUPSEL;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T1DATA_ADDR)   	T1DATA;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADCR2_ADDR)    	ADCR2;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRM_ADDR)     	ADRM;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (IICCR_ADDR)    	IICCR;
extern __sfr __at (IICAR_ADDR)    	IICAR;
extern __sfr __at (IICDR_ADDR)    	IICDR;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0

// ----- INDF0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INDF00:1;
		unsigned char INDF01:1;
		unsigned char INDF02:1;
		unsigned char INDF03:1;
		unsigned char INDF04:1;
		unsigned char INDF05:1;
		unsigned char INDF06:1;
		unsigned char INDF07:1;
	};
} __INDF0bits_t;
extern volatile __INDF0bits_t __at(INDF0_ADDR) INDF0bits;

#define INDF00    	INDF0bits.INDF00    	/* bit 0 */
#define INDF01    	INDF0bits.INDF01    	/* bit 1 */
#define INDF02    	INDF0bits.INDF02    	/* bit 2 */
#define INDF03    	INDF0bits.INDF03    	/* bit 3 */
#define INDF04    	INDF0bits.INDF04    	/* bit 4 */
#define INDF05    	INDF0bits.INDF05    	/* bit 5 */
#define INDF06    	INDF0bits.INDF06    	/* bit 6 */
#define INDF07    	INDF0bits.INDF07    	/* bit 7 */

// ----- INDF1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INDF10:1;
		unsigned char INDF11:1;
		unsigned char INDF12:1;
		unsigned char INDF13:1;
		unsigned char INDF14:1;
		unsigned char INDF15:1;
		unsigned char INDF16:1;
		unsigned char INDF17:1;
	};
} __INDF1bits_t;
extern volatile __INDF1bits_t __at(INDF1_ADDR) INDF1bits;

#define INDF10    	INDF1bits.INDF10    	/* bit 0 */
#define INDF11    	INDF1bits.INDF11    	/* bit 1 */
#define INDF12    	INDF1bits.INDF12    	/* bit 2 */
#define INDF13    	INDF1bits.INDF13    	/* bit 3 */
#define INDF14    	INDF1bits.INDF14    	/* bit 4 */
#define INDF15    	INDF1bits.INDF15    	/* bit 5 */
#define INDF16    	INDF1bits.INDF16    	/* bit 6 */
#define INDF17    	INDF1bits.INDF17    	/* bit 7 */

// ----- INDF2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INDF20:1;
		unsigned char INDF21:1;
		unsigned char INDF22:1;
		unsigned char INDF23:1;
		unsigned char INDF24:1;
		unsigned char INDF25:1;
		unsigned char INDF26:1;
		unsigned char INDF27:1;
	};
} __INDF2bits_t;
extern volatile __INDF2bits_t __at(INDF2_ADDR) INDF2bits;

#define INDF20    	INDF2bits.INDF20    	/* bit 0 */
#define INDF21    	INDF2bits.INDF21    	/* bit 1 */
#define INDF22    	INDF2bits.INDF22    	/* bit 2 */
#define INDF23    	INDF2bits.INDF23    	/* bit 3 */
#define INDF24    	INDF2bits.INDF24    	/* bit 4 */
#define INDF25    	INDF2bits.INDF25    	/* bit 5 */
#define INDF26    	INDF2bits.INDF26    	/* bit 6 */
#define INDF27    	INDF2bits.INDF27    	/* bit 7 */

// ----- HIBYTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char HIBYTE0:1;
		unsigned char HIBYTE1:1;
		unsigned char HIBYTE2:1;
		unsigned char HIBYTE3:1;
		unsigned char HIBYTE4:1;
		unsigned char HIBYTE5:1;
		unsigned char HIBYTE6:1;
		unsigned char HIBYTE7:1;
	};
} __HIBYTEbits_t;
extern volatile __HIBYTEbits_t __at(HIBYTE_ADDR) HIBYTEbits;

#define HIBYTE0   	HIBYTEbits.HIBYTE0  	/* bit 0 */
#define HIBYTE1   	HIBYTEbits.HIBYTE1  	/* bit 1 */
#define HIBYTE2   	HIBYTEbits.HIBYTE2  	/* bit 2 */
#define HIBYTE3   	HIBYTEbits.HIBYTE3  	/* bit 3 */
#define HIBYTE4   	HIBYTEbits.HIBYTE4  	/* bit 4 */
#define HIBYTE5   	HIBYTEbits.HIBYTE5  	/* bit 5 */
#define HIBYTE6   	HIBYTEbits.HIBYTE6  	/* bit 6 */
#define HIBYTE7   	HIBYTEbits.HIBYTE7  	/* bit 7 */

// ----- FSR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char SFR00:1;
		unsigned char SFR01:1;
		unsigned char SFR02:1;
		unsigned char SFR03:1;
		unsigned char SFR04:1;
		unsigned char SFR05:1;
		unsigned char SFR06:1;
		unsigned char SFR07:1;
	};
} __FSR0bits_t;
extern volatile __FSR0bits_t __at(FSR0_ADDR) FSR0bits;

#define SFR00     	FSR0bits.SFR00      	/* bit 0 */
#define SFR01     	FSR0bits.SFR01      	/* bit 1 */
#define SFR02     	FSR0bits.SFR02      	/* bit 2 */
#define SFR03     	FSR0bits.SFR03      	/* bit 3 */
#define SFR04     	FSR0bits.SFR04      	/* bit 4 */
#define SFR05     	FSR0bits.SFR05      	/* bit 5 */
#define SFR06     	FSR0bits.SFR06      	/* bit 6 */
#define SFR07     	FSR0bits.SFR07      	/* bit 7 */

// ----- FSR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char SFR10:1;
		unsigned char SFR11:1;
		unsigned char SFR12:1;
		unsigned char SFR13:1;
		unsigned char SFR14:1;
		unsigned char SFR15:1;
		unsigned char SFR16:1;
		unsigned char SFR17:1;
	};
} __FSR1bits_t;
extern volatile __FSR1bits_t __at(FSR1_ADDR) FSR1bits;

#define SFR10     	FSR1bits.SFR10      	/* bit 0 */
#define SFR11     	FSR1bits.SFR11      	/* bit 1 */
#define SFR12     	FSR1bits.SFR12      	/* bit 2 */
#define SFR13     	FSR1bits.SFR13      	/* bit 3 */
#define SFR14     	FSR1bits.SFR14      	/* bit 4 */
#define SFR15     	FSR1bits.SFR15      	/* bit 5 */
#define SFR16     	FSR1bits.SFR16      	/* bit 6 */
#define SFR17     	FSR1bits.SFR17      	/* bit 7 */

// ----- PCL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PC0:1;
		unsigned char PC1:1;
		unsigned char PC2:1;
		unsigned char PC3:1;
		unsigned char PC4:1;
		unsigned char PC5:1;
		unsigned char PC6:1;
		unsigned char PC7:1;
	};
} __PCLbits_t;
extern volatile __PCLbits_t __at(PCL_ADDR) PCLbits;

#define PC0       	PCLbits.PC0         	/* bit 0 */
#define PC1       	PCLbits.PC1         	/* bit 1 */
#define PC2       	PCLbits.PC2         	/* bit 2 */
#define PC3       	PCLbits.PC3         	/* bit 3 */
#define PC4       	PCLbits.PC4         	/* bit 4 */
#define PC5       	PCLbits.PC5         	/* bit 5 */
#define PC6       	PCLbits.PC6         	/* bit 6 */
#define PC7       	PCLbits.PC7         	/* bit 7 */

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

// ----- INDF3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INDF30:1;
		unsigned char INDF31:1;
		unsigned char INDF32:1;
		unsigned char INDF33:1;
		unsigned char INDF34:1;
		unsigned char INDF35:1;
		unsigned char INDF36:1;
		unsigned char INDF37:1;
	};
} __INDF3bits_t;
extern volatile __INDF3bits_t __at(INDF3_ADDR) INDF3bits;

#define INDF30    	INDF3bits.INDF30    	/* bit 0 */
#define INDF31    	INDF3bits.INDF31    	/* bit 1 */
#define INDF32    	INDF3bits.INDF32    	/* bit 2 */
#define INDF33    	INDF3bits.INDF33    	/* bit 3 */
#define INDF34    	INDF3bits.INDF34    	/* bit 4 */
#define INDF35    	INDF3bits.INDF35    	/* bit 5 */
#define INDF36    	INDF3bits.INDF36    	/* bit 6 */
#define INDF37    	INDF3bits.INDF37    	/* bit 7 */

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char :1;
		unsigned char IICIE:1;
		unsigned char ADIE:1;
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define IICIE     	INTEbits.IICIE      	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char :1;
		unsigned char IICIF:1;
		unsigned char ADIF:1;
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define IICIF     	INTFbits.IICIF      	/* bit 5 */
#define ADIF      	INTFbits.ADIF       	/* bit 6 */

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

// ----- LVDCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LVDF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char VLVDS0:1;
		unsigned char VLVDS1:1;
		unsigned char VLVDS2:1;
		unsigned char VLVDS3:1;
		unsigned char LVDEN:1;
	};
} __LVDCRbits_t;
extern volatile __LVDCRbits_t __at(LVDCR_ADDR) LVDCRbits;

#define LVDF      	LVDCRbits.LVDF      	/* bit 0 */
#define VLVDS0    	LVDCRbits.VLVDS0    	/* bit 3 */
#define VLVDS1    	LVDCRbits.VLVDS1    	/* bit 4 */
#define VLVDS2    	LVDCRbits.VLVDS2    	/* bit 5 */
#define VLVDS3    	LVDCRbits.VLVDS3    	/* bit 6 */
#define LVDEN     	LVDCRbits.LVDEN     	/* bit 7 */

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

// ----- RUPSEL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char IICRS:1;
	};
} __RUPSELbits_t;
extern volatile __RUPSELbits_t __at(RUPSEL_ADDR) RUPSELbits;

#define IICRS     	RUPSELbits.IICRS    	/* bit 7 */

// ----- IOP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10D:1;
		unsigned char P11D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define P10D      	IOP1bits.P10D       	/* bit 0 */
#define P11D      	IOP1bits.P11D       	/* bit 1 */

// ----- OEP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10OE:1;
		unsigned char P11OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;

#define P10OE     	OEP1bits.P10OE      	/* bit 0 */
#define P11OE     	OEP1bits.P11OE      	/* bit 1 */

// ----- PUP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10PU:1;
		unsigned char P11PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;

#define P10PU     	PUP1bits.P10PU      	/* bit 0 */
#define P11PU     	PUP1bits.P11PU      	/* bit 1 */

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

// ----- T0CNT Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0CNT0:1;
		unsigned char T0CNT1:1;
		unsigned char T0CNT2:1;
		unsigned char T0CNT3:1;
		unsigned char T0CNT4:1;
		unsigned char T0CNT5:1;
		unsigned char T0CNT6:1;
		unsigned char T0CNT7:1;
	};
} __T0CNTbits_t;
extern volatile __T0CNTbits_t __at(T0CNT_ADDR) T0CNTbits;

#define T0CNT0    	T0CNTbits.T0CNT0    	/* bit 0 */
#define T0CNT1    	T0CNTbits.T0CNT1    	/* bit 1 */
#define T0CNT2    	T0CNTbits.T0CNT2    	/* bit 2 */
#define T0CNT3    	T0CNTbits.T0CNT3    	/* bit 3 */
#define T0CNT4    	T0CNTbits.T0CNT4    	/* bit 4 */
#define T0CNT5    	T0CNTbits.T0CNT5    	/* bit 5 */
#define T0CNT6    	T0CNTbits.T0CNT6    	/* bit 6 */
#define T0CNT7    	T0CNTbits.T0CNT7    	/* bit 7 */

// ----- T0LOAD Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LOAD0:1;
		unsigned char T0LOAD1:1;
		unsigned char T0LOAD2:1;
		unsigned char T0LOAD3:1;
		unsigned char T0LOAD4:1;
		unsigned char T0LOAD5:1;
		unsigned char T0LOAD6:1;
		unsigned char T0LOAD7:1;
	};
} __T0LOADbits_t;
extern volatile __T0LOADbits_t __at(T0LOAD_ADDR) T0LOADbits;

#define T0LOAD0   	T0LOADbits.T0LOAD0  	/* bit 0 */
#define T0LOAD1   	T0LOADbits.T0LOAD1  	/* bit 1 */
#define T0LOAD2   	T0LOADbits.T0LOAD2  	/* bit 2 */
#define T0LOAD3   	T0LOADbits.T0LOAD3  	/* bit 3 */
#define T0LOAD4   	T0LOADbits.T0LOAD4  	/* bit 4 */
#define T0LOAD5   	T0LOADbits.T0LOAD5  	/* bit 5 */
#define T0LOAD6   	T0LOADbits.T0LOAD6  	/* bit 6 */
#define T0LOAD7   	T0LOADbits.T0LOAD7  	/* bit 7 */

// ----- T0DATA Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0DATA0:1;
		unsigned char T0DATA1:1;
		unsigned char T0DATA2:1;
		unsigned char T0DATA3:1;
		unsigned char T0DATA4:1;
		unsigned char T0DATA5:1;
		unsigned char T0DATA6:1;
		unsigned char T0DATA7:1;
	};
} __T0DATAbits_t;
extern volatile __T0DATAbits_t __at(T0DATA_ADDR) T0DATAbits;

#define T0DATA0   	T0DATAbits.T0DATA0  	/* bit 0 */
#define T0DATA1   	T0DATAbits.T0DATA1  	/* bit 1 */
#define T0DATA2   	T0DATAbits.T0DATA2  	/* bit 2 */
#define T0DATA3   	T0DATAbits.T0DATA3  	/* bit 3 */
#define T0DATA4   	T0DATAbits.T0DATA4  	/* bit 4 */
#define T0DATA5   	T0DATAbits.T0DATA5  	/* bit 5 */
#define T0DATA6   	T0DATAbits.T0DATA6  	/* bit 6 */
#define T0DATA7   	T0DATAbits.T0DATA7  	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PRS0:1;
		unsigned char T1PRS1:1;
		unsigned char T1PRS2:1;
		unsigned char T1CKS0:1;
		unsigned char T1CKS1:1;
		unsigned char BUZ1OE:1;
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
#define BUZ1OE    	T1CRbits.BUZ1OE     	/* bit 5 */
#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 6 */
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

// ----- T1DATA Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1DATA0:1;
		unsigned char T1DATA1:1;
		unsigned char T1DATA2:1;
		unsigned char T1DATA3:1;
		unsigned char T1DATA4:1;
		unsigned char T1DATA5:1;
		unsigned char T1DATA6:1;
		unsigned char T1DATA7:1;
	};
} __T1DATAbits_t;
extern volatile __T1DATAbits_t __at(T1DATA_ADDR) T1DATAbits;

#define T1DATA0   	T1DATAbits.T1DATA0  	/* bit 0 */
#define T1DATA1   	T1DATAbits.T1DATA1  	/* bit 1 */
#define T1DATA2   	T1DATAbits.T1DATA2  	/* bit 2 */
#define T1DATA3   	T1DATAbits.T1DATA3  	/* bit 3 */
#define T1DATA4   	T1DATAbits.T1DATA4  	/* bit 4 */
#define T1DATA5   	T1DATAbits.T1DATA5  	/* bit 5 */
#define T1DATA6   	T1DATAbits.T1DATA6  	/* bit 6 */
#define T1DATA7   	T1DATAbits.T1DATA7  	/* bit 7 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char ADCHS3:1;
		unsigned char ADCKS0:1;
		unsigned char ADCKS1:1;
		unsigned char CHOPEN:1;
		unsigned char ADEN:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADCHS0    	ADCR0bits.ADCHS0    	/* bit 0 */
#define ADCHS1    	ADCR0bits.ADCHS1    	/* bit 1 */
#define ADCHS2    	ADCR0bits.ADCHS2    	/* bit 2 */
#define ADCHS3    	ADCR0bits.ADCHS3    	/* bit 3 */
#define ADCKS0    	ADCR0bits.ADCKS0    	/* bit 4 */
#define ADCKS1    	ADCR0bits.ADCKS1    	/* bit 5 */
#define CHOPEN    	ADCR0bits.CHOPEN    	/* bit 6 */
#define ADEN      	ADCR0bits.ADEN      	/* bit 7 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADGAS0:1;
		unsigned char ADGAS1:1;
		unsigned char ADGAS2:1;
		unsigned char ADGAS3:1;
		unsigned char ADSPS0:1;
		unsigned char ADSPS1:1;
		unsigned char ADSPS2:1;
		unsigned char ADSPS3:1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define ADGAS0    	ADCR1bits.ADGAS0    	/* bit 0 */
#define ADGAS1    	ADCR1bits.ADGAS1    	/* bit 1 */
#define ADGAS2    	ADCR1bits.ADGAS2    	/* bit 2 */
#define ADGAS3    	ADCR1bits.ADGAS3    	/* bit 3 */
#define ADSPS0    	ADCR1bits.ADSPS0    	/* bit 4 */
#define ADSPS1    	ADCR1bits.ADSPS1    	/* bit 5 */
#define ADSPS2    	ADCR1bits.ADSPS2    	/* bit 6 */
#define ADSPS3    	ADCR1bits.ADSPS3    	/* bit 7 */

// ----- ADCR2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADVRS:1;
		unsigned char LDOEN:1;
		unsigned char VLDOS1:1;
		unsigned char VLDOS0:1;
		unsigned char AD2EN:1;
		unsigned char AD1EN:1;
		unsigned char AD0EN:1;
		unsigned char :1;
	};
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define ADVRS     	ADCR2bits.ADVRS     	/* bit 0 */
#define LDOEN     	ADCR2bits.LDOEN     	/* bit 1 */
#define VLDOS1    	ADCR2bits.VLDOS1    	/* bit 2 */
#define VLDOS0    	ADCR2bits.VLDOS0    	/* bit 3 */
#define AD2EN     	ADCR2bits.AD2EN     	/* bit 4 */
#define AD1EN     	ADCR2bits.AD1EN     	/* bit 5 */
#define AD0EN     	ADCR2bits.AD0EN     	/* bit 6 */

// ----- ADRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADR16:1;
		unsigned char ADR17:1;
		unsigned char ADR18:1;
		unsigned char ADR19:1;
		unsigned char ADR20:1;
		unsigned char ADR21:1;
		unsigned char ADR22:1;
		unsigned char ADR23:1;
	};
} __ADRHbits_t;
extern volatile __ADRHbits_t __at(ADRH_ADDR) ADRHbits;

#define ADR16     	ADRHbits.ADR16      	/* bit 0 */
#define ADR17     	ADRHbits.ADR17      	/* bit 1 */
#define ADR18     	ADRHbits.ADR18      	/* bit 2 */
#define ADR19     	ADRHbits.ADR19      	/* bit 3 */
#define ADR20     	ADRHbits.ADR20      	/* bit 4 */
#define ADR21     	ADRHbits.ADR21      	/* bit 5 */
#define ADR22     	ADRHbits.ADR22      	/* bit 6 */
#define ADR23     	ADRHbits.ADR23      	/* bit 7 */

// ----- ADRM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADR8:1;
		unsigned char ADR9:1;
		unsigned char ADR10:1;
		unsigned char ADR11:1;
		unsigned char ADR12:1;
		unsigned char ADR13:1;
		unsigned char ADR14:1;
		unsigned char ADR15:1;
	};
} __ADRMbits_t;
extern volatile __ADRMbits_t __at(ADRM_ADDR) ADRMbits;

#define ADR8      	ADRMbits.ADR8       	/* bit 0 */
#define ADR9      	ADRMbits.ADR9       	/* bit 1 */
#define ADR10     	ADRMbits.ADR10      	/* bit 2 */
#define ADR11     	ADRMbits.ADR11      	/* bit 3 */
#define ADR12     	ADRMbits.ADR12      	/* bit 4 */
#define ADR13     	ADRMbits.ADR13      	/* bit 5 */
#define ADR14     	ADRMbits.ADR14      	/* bit 6 */
#define ADR15     	ADRMbits.ADR15      	/* bit 7 */

// ----- IICCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char RACK:1;
		unsigned char IICEN:1;
		unsigned char MSTCMD:1;
		unsigned char SACK:1;
		unsigned char IICM0D:1;
		unsigned char IICBUSY:1;
		unsigned char IICAAS:1;
		unsigned char IICE0F:1;
	};
} __IICCRbits_t;
extern volatile __IICCRbits_t __at(IICCR_ADDR) IICCRbits;

#define RACK      	IICCRbits.RACK      	/* bit 0 */
#define IICEN     	IICCRbits.IICEN     	/* bit 1 */
#define MSTCMD    	IICCRbits.MSTCMD    	/* bit 2 */
#define SACK      	IICCRbits.SACK      	/* bit 3 */
#define IICM0D    	IICCRbits.IICM0D    	/* bit 4 */
#define IICBUSY   	IICCRbits.IICBUSY   	/* bit 5 */
#define IICAAS    	IICCRbits.IICAAS    	/* bit 6 */
#define IICE0F    	IICCRbits.IICE0F    	/* bit 7 */

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

// ----- IICDR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char IICDT0:1;
		unsigned char IICDT1:1;
		unsigned char IICDT2:1;
		unsigned char IICDT3:1;
		unsigned char IICDT4:1;
		unsigned char IICDT6:1;
		unsigned char IICDT7:1;
	};
} __IICDRbits_t;
extern volatile __IICDRbits_t __at(IICDR_ADDR) IICDRbits;

#define IICDT0    	IICDRbits.IICDT0    	/* bit 0 */
#define IICDT1    	IICDRbits.IICDT1    	/* bit 1 */
#define IICDT2    	IICDRbits.IICDT2    	/* bit 2 */
#define IICDT3    	IICDRbits.IICDT3    	/* bit 3 */
#define IICDT4    	IICDRbits.IICDT4    	/* bit 4 */
#define IICDT6    	IICDRbits.IICDT6    	/* bit 6 */
#define IICDT7    	IICDRbits.IICDT7    	/* bit 7 */

#endif
