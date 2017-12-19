#ifndef MC32P7030_H
#define MC32P7030_H

#include <mc35-common.h>

//
// Register addresses.
//
#define HIBYTE_ADDR     	0x0082
#define FSR0_ADDR       	0x0083
#define FSR1_ADDR       	0x0084
#define PFLAG_ADDR      	0x0086
#define ANSEL_ADDR      	0x00AE
#define VREF_ADDR       	0x00AF
#define ADCR_ADDR       	0x00B1
#define ADRH_ADDR       	0x00B2
#define ADRL_ADDR       	0x00B3
#define OEP0_ADDR       	0x00B8
#define PEDGE_ADDR      	0x00BF
#define OEP4_ADDR       	0x00C4
#define OEP5_ADDR       	0x00C5
#define INTF_ADDR       	0x00C8
#define INTE_ADDR       	0x00C9
#define OSCM_ADDR       	0x00CA
#define WDTR_ADDR       	0x00CC
#define T0D_ADDR        	0x00CD
#define PCL_ADDR        	0x00CE
#define PCH_ADDR        	0x00CF
#define IOP0_ADDR       	0x00D0
#define IOP4_ADDR       	0x00D4
#define IOP5_ADDR       	0x00D5
#define TXCR_ADDR       	0x00D8
#define T0CR_ADDR       	0x00DA
#define T0C_ADDR        	0x00DB
#define T1CR_ADDR       	0x00DC
#define T1C_ADDR        	0x00DD
#define T1D_ADDR        	0x00DE
#define STKP_ADDR       	0x00DF
#define PUP0_ADDR       	0x00E0
#define PUP4_ADDR       	0x00E4
#define PUP5_ADDR       	0x00E5
#define INDF_ADDR       	0x00E7
#define STK3L_ADDR      	0x00F8
#define STK3H_ADDR      	0x00F9
#define STK2L_ADDR      	0x00FA
#define STK2H_ADDR      	0x00FB
#define STK1L_ADDR      	0x00FC
#define STK1H_ADDR      	0x00FD
#define STK0L_ADDR      	0x00FE
#define STK0H_ADDR      	0x00FF

//----- Register Files -----------------------------------------------------

extern __sfr __at (HIBYTE_ADDR)   	HIBYTE;
extern __sfr __at (FSR0_ADDR)     	FSR0;
extern __sfr __at (FSR1_ADDR)     	FSR1;
extern __sfr __at (PFLAG_ADDR)    	PFLAG;
extern __sfr __at (ANSEL_ADDR)    	ANSEL;
extern __sfr __at (VREF_ADDR)     	VREF;
extern __sfr __at (ADCR_ADDR)     	ADCR;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PEDGE_ADDR)    	PEDGE;
extern __sfr __at (OEP4_ADDR)     	OEP4;
extern __sfr __at (OEP5_ADDR)     	OEP5;
extern __sfr __at (INTF_ADDR)     	INTF;
extern __sfr __at (INTE_ADDR)     	INTE;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (WDTR_ADDR)     	WDTR;
extern __sfr __at (T0D_ADDR)      	T0D;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (PCH_ADDR)      	PCH;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (IOP4_ADDR)     	IOP4;
extern __sfr __at (IOP5_ADDR)     	IOP5;
extern __sfr __at (TXCR_ADDR)     	TXCR;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0C_ADDR)      	T0C;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1C_ADDR)      	T1C;
extern __sfr __at (T1D_ADDR)      	T1D;
extern __sfr __at (STKP_ADDR)     	STKP;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (PUP4_ADDR)     	PUP4;
extern __sfr __at (PUP5_ADDR)     	PUP5;
extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (STK3L_ADDR)    	STK3L;
extern __sfr __at (STK3H_ADDR)    	STK3H;
extern __sfr __at (STK2L_ADDR)    	STK2L;
extern __sfr __at (STK2H_ADDR)    	STK2H;
extern __sfr __at (STK1L_ADDR)    	STK1L;
extern __sfr __at (STK1H_ADDR)    	STK1H;
extern __sfr __at (STK0L_ADDR)    	STK0L;
extern __sfr __at (STK0H_ADDR)    	STK0H;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0

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
		unsigned char FSR00:1;
		unsigned char FSR01:1;
		unsigned char FSR02:1;
		unsigned char FSR03:1;
		unsigned char FSR04:1;
		unsigned char FSR05:1;
		unsigned char FSR06:1;
		unsigned char FSR07:1;
	};
} __FSR0bits_t;
extern volatile __FSR0bits_t __at(FSR0_ADDR) FSR0bits;

#define FSR00     	FSR0bits.FSR00      	/* bit 0 */
#define FSR01     	FSR0bits.FSR01      	/* bit 1 */
#define FSR02     	FSR0bits.FSR02      	/* bit 2 */
#define FSR03     	FSR0bits.FSR03      	/* bit 3 */
#define FSR04     	FSR0bits.FSR04      	/* bit 4 */
#define FSR05     	FSR0bits.FSR05      	/* bit 5 */
#define FSR06     	FSR0bits.FSR06      	/* bit 6 */
#define FSR07     	FSR0bits.FSR07      	/* bit 7 */

// ----- FSR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FSR10:1;
		unsigned char FSR11:1;
		unsigned char FSR12:1;
		unsigned char FSR13:1;
		unsigned char FSR14:1;
		unsigned char FSR15:1;
		unsigned char FSR16:1;
		unsigned char FSR17:1;
	};
} __FSR1bits_t;
extern volatile __FSR1bits_t __at(FSR1_ADDR) FSR1bits;

#define FSR10     	FSR1bits.FSR10      	/* bit 0 */
#define FSR11     	FSR1bits.FSR11      	/* bit 1 */
#define FSR12     	FSR1bits.FSR12      	/* bit 2 */
#define FSR13     	FSR1bits.FSR13      	/* bit 3 */
#define FSR14     	FSR1bits.FSR14      	/* bit 4 */
#define FSR15     	FSR1bits.FSR15      	/* bit 5 */
#define FSR16     	FSR1bits.FSR16      	/* bit 6 */
#define FSR17     	FSR1bits.FSR17      	/* bit 7 */

// ----- PFLAG Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char Z:1;
		unsigned char DC:1;
		unsigned char C:1;
		unsigned char :1;
		unsigned char LVD24:1;
		unsigned char LVD36:1;
		unsigned char NPD:1;
		unsigned char NT0:1;
	};
} __PFLAGbits_t;
extern volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;

#define Z         	PFLAGbits.Z         	/* bit 0 */
#define DC        	PFLAGbits.DC        	/* bit 1 */
#define C         	PFLAGbits.C         	/* bit 2 */
#define LVD24     	PFLAGbits.LVD24     	/* bit 4 */
#define LVD36     	PFLAGbits.LVD36     	/* bit 5 */
#define NPD       	PFLAGbits.NPD       	/* bit 6 */
#define NT0       	PFLAGbits.NT0       	/* bit 7 */

// ----- ANSEL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40ANS:1;
		unsigned char P41ANS:1;
		unsigned char P42ANS:1;
		unsigned char P43ANS:1;
		unsigned char P44ANS:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __ANSELbits_t;
extern volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;

#define P40ANS    	ANSELbits.P40ANS    	/* bit 0 */
#define P41ANS    	ANSELbits.P41ANS    	/* bit 1 */
#define P42ANS    	ANSELbits.P42ANS    	/* bit 2 */
#define P43ANS    	ANSELbits.P43ANS    	/* bit 3 */
#define P44ANS    	ANSELbits.P44ANS    	/* bit 4 */

// ----- VREF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VRS0:1;
		unsigned char VRS1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char VREFS:1;
	};
} __VREFbits_t;
extern volatile __VREFbits_t __at(VREF_ADDR) VREFbits;

#define VRS0      	VREFbits.VRS0       	/* bit 0 */
#define VRS1      	VREFbits.VRS1       	/* bit 1 */
#define VREFS     	VREFbits.VREFS      	/* bit 7 */

// ----- ADCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char :1;
		unsigned char GCHS:1;
		unsigned char ADEOC:1;
		unsigned char ADST:1;
		unsigned char ADON:1;
	};
} __ADCRbits_t;
extern volatile __ADCRbits_t __at(ADCR_ADDR) ADCRbits;

#define ADCHS0    	ADCRbits.ADCHS0     	/* bit 0 */
#define ADCHS1    	ADCRbits.ADCHS1     	/* bit 1 */
#define ADCHS2    	ADCRbits.ADCHS2     	/* bit 2 */
#define GCHS      	ADCRbits.GCHS       	/* bit 4 */
#define ADEOC     	ADCRbits.ADEOC      	/* bit 5 */
#define ADST      	ADCRbits.ADST       	/* bit 6 */
#define ADON      	ADCRbits.ADON       	/* bit 7 */

// ----- ADRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADR4:1;
		unsigned char ADR5:1;
		unsigned char ADR6:1;
		unsigned char ADR7:1;
		unsigned char ADR8:1;
		unsigned char ADR9:1;
		unsigned char ADR10:1;
		unsigned char ADR11:1;
	};
} __ADRHbits_t;
extern volatile __ADRHbits_t __at(ADRH_ADDR) ADRHbits;

#define ADR4      	ADRHbits.ADR4       	/* bit 0 */
#define ADR5      	ADRHbits.ADR5       	/* bit 1 */
#define ADR6      	ADRHbits.ADR6       	/* bit 2 */
#define ADR7      	ADRHbits.ADR7       	/* bit 3 */
#define ADR8      	ADRHbits.ADR8       	/* bit 4 */
#define ADR9      	ADRHbits.ADR9       	/* bit 5 */
#define ADR10     	ADRHbits.ADR10      	/* bit 6 */
#define ADR11     	ADRHbits.ADR11      	/* bit 7 */

// ----- ADRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADR0:1;
		unsigned char ADR1:1;
		unsigned char ADR2:1;
		unsigned char ADR3:1;
		unsigned char ADCKS0:1;
		unsigned char :1;
		unsigned char ADCKS1:1;
		unsigned char :1;
	};
} __ADRLbits_t;
extern volatile __ADRLbits_t __at(ADRL_ADDR) ADRLbits;

#define ADR0      	ADRLbits.ADR0       	/* bit 0 */
#define ADR1      	ADRLbits.ADR1       	/* bit 1 */
#define ADR2      	ADRLbits.ADR2       	/* bit 2 */
#define ADR3      	ADRLbits.ADR3       	/* bit 3 */
#define ADCKS0    	ADRLbits.ADCKS0     	/* bit 4 */
#define ADCKS1    	ADRLbits.ADCKS1     	/* bit 6 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00OE:1;
		unsigned char P01OE:1;
		unsigned char P02OE:1;
		unsigned char P03OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;

#define P00OE     	OEP0bits.P00OE      	/* bit 0 */
#define P01OE     	OEP0bits.P01OE      	/* bit 1 */
#define P02OE     	OEP0bits.P02OE      	/* bit 2 */
#define P03OE     	OEP0bits.P03OE      	/* bit 3 */

// ----- PEDGE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char MINT00:1;
		unsigned char MINT01:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PEDGEbits_t;
extern volatile __PEDGEbits_t __at(PEDGE_ADDR) PEDGEbits;

#define MINT00    	PEDGEbits.MINT00    	/* bit 3 */
#define MINT01    	PEDGEbits.MINT01    	/* bit 4 */

// ----- OEP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40OE:1;
		unsigned char P41OE:1;
		unsigned char P42OE:1;
		unsigned char P43OE:1;
		unsigned char P44OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP4bits_t;
extern volatile __OEP4bits_t __at(OEP4_ADDR) OEP4bits;

#define P40OE     	OEP4bits.P40OE      	/* bit 0 */
#define P41OE     	OEP4bits.P41OE      	/* bit 1 */
#define P42OE     	OEP4bits.P42OE      	/* bit 2 */
#define P43OE     	OEP4bits.P43OE      	/* bit 3 */
#define P44OE     	OEP4bits.P44OE      	/* bit 4 */

// ----- OEP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char P53OE:1;
		unsigned char P54OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP5bits_t;
extern volatile __OEP5bits_t __at(OEP5_ADDR) OEP5bits;

#define P53OE     	OEP5bits.P53OE      	/* bit 3 */
#define P54OE     	OEP5bits.P54OE      	/* bit 4 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char ADIF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define INT0IF    	INTFbits.INT0IF     	/* bit 0 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 1 */
#define T0IF      	INTFbits.T0IF       	/* bit 5 */
#define T1IF      	INTFbits.T1IF       	/* bit 6 */
#define ADIF      	INTFbits.ADIF       	/* bit 7 */

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char ADIE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define INT0IE    	INTEbits.INT0IE     	/* bit 0 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 1 */
#define T0IE      	INTEbits.T0IE       	/* bit 5 */
#define T1IE      	INTEbits.T1IE       	/* bit 6 */
#define ADIE      	INTEbits.ADIE       	/* bit 7 */

// ----- OSCM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char HOFF:1;
		unsigned char CLKS:1;
		unsigned char CPUM0:1;
		unsigned char CPUM1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OSCMbits_t;
extern volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;

#define HOFF      	OSCMbits.HOFF       	/* bit 1 */
#define CLKS      	OSCMbits.CLKS       	/* bit 2 */
#define CPUM0     	OSCMbits.CPUM0      	/* bit 3 */
#define CPUM1     	OSCMbits.CPUM1      	/* bit 4 */

// ----- WDTR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char WDTR0:1;
		unsigned char WDTR1:1;
		unsigned char WDTR2:1;
		unsigned char WDTR3:1;
		unsigned char WDTR4:1;
		unsigned char WDTR5:1;
		unsigned char WDTR6:1;
		unsigned char WDTR7:1;
	};
} __WDTRbits_t;
extern volatile __WDTRbits_t __at(WDTR_ADDR) WDTRbits;

#define WDTR0     	WDTRbits.WDTR0      	/* bit 0 */
#define WDTR1     	WDTRbits.WDTR1      	/* bit 1 */
#define WDTR2     	WDTRbits.WDTR2      	/* bit 2 */
#define WDTR3     	WDTRbits.WDTR3      	/* bit 3 */
#define WDTR4     	WDTRbits.WDTR4      	/* bit 4 */
#define WDTR5     	WDTRbits.WDTR5      	/* bit 5 */
#define WDTR6     	WDTRbits.WDTR6      	/* bit 6 */
#define WDTR7     	WDTRbits.WDTR7      	/* bit 7 */

// ----- T0D Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0D0:1;
		unsigned char T0D1:1;
		unsigned char T0D2:1;
		unsigned char T0D3:1;
		unsigned char T0D4:1;
		unsigned char T0D5:1;
		unsigned char T0D6:1;
		unsigned char T0D7:1;
	};
} __T0Dbits_t;
extern volatile __T0Dbits_t __at(T0D_ADDR) T0Dbits;

#define T0D0      	T0Dbits.T0D0        	/* bit 0 */
#define T0D1      	T0Dbits.T0D1        	/* bit 1 */
#define T0D2      	T0Dbits.T0D2        	/* bit 2 */
#define T0D3      	T0Dbits.T0D3        	/* bit 3 */
#define T0D4      	T0Dbits.T0D4        	/* bit 4 */
#define T0D5      	T0Dbits.T0D5        	/* bit 5 */
#define T0D6      	T0Dbits.T0D6        	/* bit 6 */
#define T0D7      	T0Dbits.T0D7        	/* bit 7 */

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

// ----- PCH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PC8:1;
		unsigned char PC9:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PCHbits_t;
extern volatile __PCHbits_t __at(PCH_ADDR) PCHbits;

#define PC8       	PCHbits.PC8         	/* bit 0 */
#define PC9       	PCHbits.PC9         	/* bit 1 */

// ----- IOP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00D:1;
		unsigned char P01D:1;
		unsigned char P02D:1;
		unsigned char P03D:1;
		unsigned char P04D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define P00D      	IOP0bits.P00D       	/* bit 0 */
#define P01D      	IOP0bits.P01D       	/* bit 1 */
#define P02D      	IOP0bits.P02D       	/* bit 2 */
#define P03D      	IOP0bits.P03D       	/* bit 3 */
#define P04D      	IOP0bits.P04D       	/* bit 4 */

// ----- IOP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40D:1;
		unsigned char P41D:1;
		unsigned char P42D:1;
		unsigned char P43D:1;
		unsigned char P44D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP4bits_t;
extern volatile __IOP4bits_t __at(IOP4_ADDR) IOP4bits;

#define P40D      	IOP4bits.P40D       	/* bit 0 */
#define P41D      	IOP4bits.P41D       	/* bit 1 */
#define P42D      	IOP4bits.P42D       	/* bit 2 */
#define P43D      	IOP4bits.P43D       	/* bit 3 */
#define P44D      	IOP4bits.P44D       	/* bit 4 */

// ----- IOP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char P53D:1;
		unsigned char P54D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP5bits_t;
extern volatile __IOP5bits_t __at(IOP5_ADDR) IOP5bits;

#define P53D      	IOP5bits.P53D       	/* bit 3 */
#define P54D      	IOP5bits.P54D       	/* bit 4 */

// ----- TXCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char T0GE :1;
		unsigned char T0PTSX :1;
		unsigned char T1PTSX:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __TXCRbits_t;
extern volatile __TXCRbits_t __at(TXCR_ADDR) TXCRbits;

#define T0GE      	TXCRbits.T0GE       	/* bit 1 */
#define T0PTSX    	TXCRbits.T0PTSX     	/* bit 2 */
#define T1PTSX    	TXCRbits.T1PTSX     	/* bit 3 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWM0OE:1;
		unsigned char BUZ0OE:1;
		unsigned char T0ALOAD:1;
		unsigned char T0PTS:1;
		unsigned char T0PR0:1;
		unsigned char T0PR1:1;
		unsigned char T0PR2:1;
		unsigned char TC0EN:1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define PWM0OE    	T0CRbits.PWM0OE     	/* bit 0 */
#define BUZ0OE    	T0CRbits.BUZ0OE     	/* bit 1 */
#define T0ALOAD   	T0CRbits.T0ALOAD    	/* bit 2 */
#define T0PTS     	T0CRbits.T0PTS      	/* bit 3 */
#define T0PR0     	T0CRbits.T0PR0      	/* bit 4 */
#define T0PR1     	T0CRbits.T0PR1      	/* bit 5 */
#define T0PR2     	T0CRbits.T0PR2      	/* bit 6 */
#define TC0EN     	T0CRbits.TC0EN      	/* bit 7 */

// ----- T0C Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0C0:1;
		unsigned char T0C1:1;
		unsigned char T0C2:1;
		unsigned char T0C3:1;
		unsigned char T0C4:1;
		unsigned char T0C5:1;
		unsigned char T0C6:1;
		unsigned char T0C7:1;
	};
} __T0Cbits_t;
extern volatile __T0Cbits_t __at(T0C_ADDR) T0Cbits;

#define T0C0      	T0Cbits.T0C0        	/* bit 0 */
#define T0C1      	T0Cbits.T0C1        	/* bit 1 */
#define T0C2      	T0Cbits.T0C2        	/* bit 2 */
#define T0C3      	T0Cbits.T0C3        	/* bit 3 */
#define T0C4      	T0Cbits.T0C4        	/* bit 4 */
#define T0C5      	T0Cbits.T0C5        	/* bit 5 */
#define T0C6      	T0Cbits.T0C6        	/* bit 6 */
#define T0C7      	T0Cbits.T0C7        	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWM1OE:1;
		unsigned char BUZ1OE:1;
		unsigned char T1ALOAD:1;
		unsigned char T1PTS:1;
		unsigned char T1PR0:1;
		unsigned char T1PR1:1;
		unsigned char T1PR2:1;
		unsigned char TC1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 0 */
#define BUZ1OE    	T1CRbits.BUZ1OE     	/* bit 1 */
#define T1ALOAD   	T1CRbits.T1ALOAD    	/* bit 2 */
#define T1PTS     	T1CRbits.T1PTS      	/* bit 3 */
#define T1PR0     	T1CRbits.T1PR0      	/* bit 4 */
#define T1PR1     	T1CRbits.T1PR1      	/* bit 5 */
#define T1PR2     	T1CRbits.T1PR2      	/* bit 6 */
#define TC1EN     	T1CRbits.TC1EN      	/* bit 7 */

// ----- T1C Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1C0:1;
		unsigned char T1C1:1;
		unsigned char T1C2:1;
		unsigned char T1C3:1;
		unsigned char T1C4:1;
		unsigned char T1C5:1;
		unsigned char T1C6:1;
		unsigned char T1C7:1;
	};
} __T1Cbits_t;
extern volatile __T1Cbits_t __at(T1C_ADDR) T1Cbits;

#define T1C0      	T1Cbits.T1C0        	/* bit 0 */
#define T1C1      	T1Cbits.T1C1        	/* bit 1 */
#define T1C2      	T1Cbits.T1C2        	/* bit 2 */
#define T1C3      	T1Cbits.T1C3        	/* bit 3 */
#define T1C4      	T1Cbits.T1C4        	/* bit 4 */
#define T1C5      	T1Cbits.T1C5        	/* bit 5 */
#define T1C6      	T1Cbits.T1C6        	/* bit 6 */
#define T1C7      	T1Cbits.T1C7        	/* bit 7 */

// ----- T1D Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1D0:1;
		unsigned char T1D1:1;
		unsigned char T1D2:1;
		unsigned char T1D3:1;
		unsigned char T1D4:1;
		unsigned char T1D5:1;
		unsigned char T1D6:1;
		unsigned char T1D7:1;
	};
} __T1Dbits_t;
extern volatile __T1Dbits_t __at(T1D_ADDR) T1Dbits;

#define T1D0      	T1Dbits.T1D0        	/* bit 0 */
#define T1D1      	T1Dbits.T1D1        	/* bit 1 */
#define T1D2      	T1Dbits.T1D2        	/* bit 2 */
#define T1D3      	T1Dbits.T1D3        	/* bit 3 */
#define T1D4      	T1Dbits.T1D4        	/* bit 4 */
#define T1D5      	T1Dbits.T1D5        	/* bit 5 */
#define T1D6      	T1Dbits.T1D6        	/* bit 6 */
#define T1D7      	T1Dbits.T1D7        	/* bit 7 */

// ----- STKP Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char STKP0:1;
		unsigned char STKP1:1;
		unsigned char STKP2:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char GIE:1;
	};
} __STKPbits_t;
extern volatile __STKPbits_t __at(STKP_ADDR) STKPbits;

#define STKP0     	STKPbits.STKP0      	/* bit 0 */
#define STKP1     	STKPbits.STKP1      	/* bit 1 */
#define STKP2     	STKPbits.STKP2      	/* bit 2 */
#define GIE       	STKPbits.GIE        	/* bit 7 */

// ----- PUP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00PU:1;
		unsigned char P01PU:1;
		unsigned char P02PU:1;
		unsigned char P03PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP0bits_t;
extern volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;

#define P00PU     	PUP0bits.P00PU      	/* bit 0 */
#define P01PU     	PUP0bits.P01PU      	/* bit 1 */
#define P02PU     	PUP0bits.P02PU      	/* bit 2 */
#define P03PU     	PUP0bits.P03PU      	/* bit 3 */

// ----- PUP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40PU:1;
		unsigned char P41PU:1;
		unsigned char P42PU:1;
		unsigned char P43PU:1;
		unsigned char P44PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP4bits_t;
extern volatile __PUP4bits_t __at(PUP4_ADDR) PUP4bits;

#define P40PU     	PUP4bits.P40PU      	/* bit 0 */
#define P41PU     	PUP4bits.P41PU      	/* bit 1 */
#define P42PU     	PUP4bits.P42PU      	/* bit 2 */
#define P43PU     	PUP4bits.P43PU      	/* bit 3 */
#define P44PU     	PUP4bits.P44PU      	/* bit 4 */

// ----- PUP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char P53PU:1;
		unsigned char P54PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP5bits_t;
extern volatile __PUP5bits_t __at(PUP5_ADDR) PUP5bits;

#define P53PU     	PUP5bits.P53PU      	/* bit 3 */
#define P54PU     	PUP5bits.P54PU      	/* bit 4 */

// ----- INDF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INDF0:1;
		unsigned char INDF1:1;
		unsigned char INDF2:1;
		unsigned char INDF3:1;
		unsigned char INDF4:1;
		unsigned char INDF5:1;
		unsigned char INDF6:1;
		unsigned char INDF7:1;
	};
} __INDFbits_t;
extern volatile __INDFbits_t __at(INDF_ADDR) INDFbits;

#define INDF0     	INDFbits.INDF0      	/* bit 0 */
#define INDF1     	INDFbits.INDF1      	/* bit 1 */
#define INDF2     	INDFbits.INDF2      	/* bit 2 */
#define INDF3     	INDFbits.INDF3      	/* bit 3 */
#define INDF4     	INDFbits.INDF4      	/* bit 4 */
#define INDF5     	INDFbits.INDF5      	/* bit 5 */
#define INDF6     	INDFbits.INDF6      	/* bit 6 */
#define INDF7     	INDFbits.INDF7      	/* bit 7 */

#endif
