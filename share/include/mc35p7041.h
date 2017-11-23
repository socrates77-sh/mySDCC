#ifndef MC35P7041_H
#define MC35P7041_H

#include <mc30-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x00E7
#define HIBYTE_ADDR     	0x0082
#define FSR0_ADDR       	0x0083
#define FSR1_ADDR       	0x0084
#define PCH_ADDR        	0x00CF
#define PCL_ADDR        	0x00CE
#define STATUS_ADDR     	0x0086
#define PFLAG_ADDR      	0x0086
#define ZEROTR_ADDR     	0x008E
#define OSCCAL_ADDR     	0x008F
#define WKCR0_ADDR      	0x00A0
#define WKCR5_ADDR      	0x00A5
#define ADIOS0_ADDR     	0x00AD
#define ADIOS1_ADDR     	0x00AE
#define ADIOS2_ADDR     	0x00AF
#define ADCR0_ADDR      	0x00B1
#define ADCR1_ADDR      	0x00B2
#define ADRH_ADDR       	0x00B3
#define ADRL_ADDR       	0x00B4
#define ADCR2_ADDR      	0x00B5
#define OEP0_ADDR       	0x00B8
#define EINTCR_ADDR     	0x00BF
#define OEP4_ADDR       	0x00C4
#define OEP5_ADDR       	0x00C5
#define INTF_ADDR       	0x00C8
#define INTE_ADDR       	0x00C9
#define OSCM_ADDR       	0x00CA
#define WDTCR_ADDR      	0x00CC
#define T1LDR_ADDR      	0x00CD
#define IOP0_ADDR       	0x00D0
#define IOP4_ADDR       	0x00D4
#define IOP5_ADDR       	0x00D5
#define T0CR_ADDR       	0x00D8
#define T0CNT_ADDR      	0x00D9
#define T1CR_ADDR       	0x00DA
#define T1CNT_ADDR      	0x00DB
#define BUZCR_ADDR      	0x00DC
#define MCR_ADDR        	0x00DF
#define PUP0_ADDR       	0x00E0
#define PUP4_ADDR       	0x00E4
#define PUP5_ADDR       	0x00E5
#define PWMCR0_ADDR     	0x00E8
#define PWMCR1_ADDR     	0x00E9
#define PWMCNT_ADDR     	0x00EA
#define PWMADT_ADDR     	0x00EB
#define PWMBDT_ADDR     	0x00EC
#define PWMCDT_ADDR     	0x00ED
#define PWMPD_ADDR      	0x00EE
#define STKR0L_ADDR     	0x00F0
#define STKR0H_ADDR     	0x00F1
#define STKR1L_ADDR     	0x00F2
#define STKR1H_ADDR     	0x00F3
#define STKR2L_ADDR     	0x00F4
#define STKR2H_ADDR     	0x00F5
#define STKR3L_ADDR     	0x00F6
#define STKR3H_ADDR     	0x00F7
#define STKR4L_ADDR     	0x00F8
#define STKR4H_ADDR     	0x00F9
#define STKR5L_ADDR     	0x00FA
#define STKR5H_ADDR     	0x00FB
#define STKR6L_ADDR     	0x00FC
#define STKR6H_ADDR     	0x00FD
#define STKR7L_ADDR     	0x00FE
#define STKR7H_ADDR     	0x00FF

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (HIBYTE_ADDR)   	HIBYTE;
extern __sfr __at (FSR0_ADDR)     	FSR0;
extern __sfr __at (FSR1_ADDR)     	FSR1;
extern __sfr __at (PCH_ADDR)      	PCH;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (PFLAG_ADDR)    	PFLAG;
extern __sfr __at (ZEROTR_ADDR)   	ZEROTR;
extern __sfr __at (OSCCAL_ADDR)   	OSCCAL;
extern __sfr __at (WKCR0_ADDR)    	WKCR0;
extern __sfr __at (WKCR5_ADDR)    	WKCR5;
extern __sfr __at (ADIOS0_ADDR)   	ADIOS0;
extern __sfr __at (ADIOS1_ADDR)   	ADIOS1;
extern __sfr __at (ADIOS2_ADDR)   	ADIOS2;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (ADCR2_ADDR)    	ADCR2;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (EINTCR_ADDR)   	EINTCR;
extern __sfr __at (OEP4_ADDR)     	OEP4;
extern __sfr __at (OEP5_ADDR)     	OEP5;
extern __sfr __at (INTF_ADDR)     	INTF;
extern __sfr __at (INTE_ADDR)     	INTE;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (WDTCR_ADDR)    	WDTCR;
extern __sfr __at (T1LDR_ADDR)    	T1LDR;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (IOP4_ADDR)     	IOP4;
extern __sfr __at (IOP5_ADDR)     	IOP5;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (BUZCR_ADDR)    	BUZCR;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (PUP4_ADDR)     	PUP4;
extern __sfr __at (PUP5_ADDR)     	PUP5;
extern __sfr __at (PWMCR0_ADDR)   	PWMCR0;
extern __sfr __at (PWMCR1_ADDR)   	PWMCR1;
extern __sfr __at (PWMCNT_ADDR)   	PWMCNT;
extern __sfr __at (PWMADT_ADDR)   	PWMADT;
extern __sfr __at (PWMBDT_ADDR)   	PWMBDT;
extern __sfr __at (PWMCDT_ADDR)   	PWMCDT;
extern __sfr __at (PWMPD_ADDR)    	PWMPD;
extern __sfr __at (STKR0L_ADDR)   	STKR0L;
extern __sfr __at (STKR0H_ADDR)   	STKR0H;
extern __sfr __at (STKR1L_ADDR)   	STKR1L;
extern __sfr __at (STKR1H_ADDR)   	STKR1H;
extern __sfr __at (STKR2L_ADDR)   	STKR2L;
extern __sfr __at (STKR2H_ADDR)   	STKR2H;
extern __sfr __at (STKR3L_ADDR)   	STKR3L;
extern __sfr __at (STKR3H_ADDR)   	STKR3H;
extern __sfr __at (STKR4L_ADDR)   	STKR4L;
extern __sfr __at (STKR4H_ADDR)   	STKR4H;
extern __sfr __at (STKR5L_ADDR)   	STKR5L;
extern __sfr __at (STKR5H_ADDR)   	STKR5H;
extern __sfr __at (STKR6L_ADDR)   	STKR6L;
extern __sfr __at (STKR6H_ADDR)   	STKR6H;
extern __sfr __at (STKR7L_ADDR)   	STKR7L;
extern __sfr __at (STKR7H_ADDR)   	STKR7H;

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

// ----- PFLAG Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char LVD24:1;
		unsigned char LVD36:1;
		unsigned char :1;
		unsigned char :1;
	};
} __PFLAGbits_t;
extern volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;

#define LVD24     	PFLAGbits.LVD24     	/* bit 4 */
#define LVD36     	PFLAGbits.LVD36     	/* bit 5 */

// ----- ZEROTR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ZEROTR0:1;
		unsigned char ZEROTR1:1;
		unsigned char ZEROTR2:1;
		unsigned char ZEROTR3:1;
		unsigned char ZEROTR4:1;
		unsigned char :1;
		unsigned char ZOTEN0:1;
		unsigned char ZOTEN1:1;
	};
} __ZEROTRbits_t;
extern volatile __ZEROTRbits_t __at(ZEROTR_ADDR) ZEROTRbits;

#define ZEROTR0   	ZEROTRbits.ZEROTR0  	/* bit 0 */
#define ZEROTR1   	ZEROTRbits.ZEROTR1  	/* bit 1 */
#define ZEROTR2   	ZEROTRbits.ZEROTR2  	/* bit 2 */
#define ZEROTR3   	ZEROTRbits.ZEROTR3  	/* bit 3 */
#define ZEROTR4   	ZEROTRbits.ZEROTR4  	/* bit 4 */
#define ZOTEN0    	ZEROTRbits.ZOTEN0   	/* bit 6 */
#define ZOTEN1    	ZEROTRbits.ZOTEN1   	/* bit 7 */

// ----- WKCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00WK:1;
		unsigned char P01WK:1;
		unsigned char P02WK:1;
		unsigned char P03WK:1;
		unsigned char P04WK:1;
		unsigned char P05WK:1;
		unsigned char P06WK:1;
		unsigned char P07WK:1;
	};
} __WKCR0bits_t;
extern volatile __WKCR0bits_t __at(WKCR0_ADDR) WKCR0bits;

#define P00WK     	WKCR0bits.P00WK     	/* bit 0 */
#define P01WK     	WKCR0bits.P01WK     	/* bit 1 */
#define P02WK     	WKCR0bits.P02WK     	/* bit 2 */
#define P03WK     	WKCR0bits.P03WK     	/* bit 3 */
#define P04WK     	WKCR0bits.P04WK     	/* bit 4 */
#define P05WK     	WKCR0bits.P05WK     	/* bit 5 */
#define P06WK     	WKCR0bits.P06WK     	/* bit 6 */
#define P07WK     	WKCR0bits.P07WK     	/* bit 7 */

// ----- WKCR5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P50WK:1;
		unsigned char P51WK:1;
		unsigned char P52WK:1;
		unsigned char P53WK:1;
		unsigned char P54WK:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __WKCR5bits_t;
extern volatile __WKCR5bits_t __at(WKCR5_ADDR) WKCR5bits;

#define P50WK     	WKCR5bits.P50WK     	/* bit 0 */
#define P51WK     	WKCR5bits.P51WK     	/* bit 1 */
#define P52WK     	WKCR5bits.P52WK     	/* bit 2 */
#define P53WK     	WKCR5bits.P53WK     	/* bit 3 */
#define P54WK     	WKCR5bits.P54WK     	/* bit 4 */

// ----- ADIOS0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char AN5EN:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char AN9EN:1;
	};
} __ADIOS0bits_t;
extern volatile __ADIOS0bits_t __at(ADIOS0_ADDR) ADIOS0bits;

#define AN5EN     	ADIOS0bits.AN5EN    	/* bit 0 */
#define AN9EN     	ADIOS0bits.AN9EN    	/* bit 7 */

// ----- ADIOS1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char AN8EN:1;
		unsigned char AN7EN:1;
		unsigned char AN6EN:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __ADIOS1bits_t;
extern volatile __ADIOS1bits_t __at(ADIOS1_ADDR) ADIOS1bits;

#define AN8EN     	ADIOS1bits.AN8EN    	/* bit 2 */
#define AN7EN     	ADIOS1bits.AN7EN    	/* bit 3 */
#define AN6EN     	ADIOS1bits.AN6EN    	/* bit 4 */

// ----- ADIOS2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char AN0EN:1;
		unsigned char AN1EN:1;
		unsigned char AN2EN:1;
		unsigned char AN3EN:1;
		unsigned char AN4EN:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __ADIOS2bits_t;
extern volatile __ADIOS2bits_t __at(ADIOS2_ADDR) ADIOS2bits;

#define AN0EN     	ADIOS2bits.AN0EN    	/* bit 0 */
#define AN1EN     	ADIOS2bits.AN1EN    	/* bit 1 */
#define AN2EN     	ADIOS2bits.AN2EN    	/* bit 2 */
#define AN3EN     	ADIOS2bits.AN3EN    	/* bit 3 */
#define AN4EN     	ADIOS2bits.AN4EN    	/* bit 4 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char ADCHS3:1;
		unsigned char GCHS:1;
		unsigned char ADEOC:1;
		unsigned char ADSTR:1;
		unsigned char ADEN:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADCHS0    	ADCR0bits.ADCHS0    	/* bit 0 */
#define ADCHS1    	ADCR0bits.ADCHS1    	/* bit 1 */
#define ADCHS2    	ADCR0bits.ADCHS2    	/* bit 2 */
#define ADCHS3    	ADCR0bits.ADCHS3    	/* bit 3 */
#define GCHS      	ADCR0bits.GCHS      	/* bit 4 */
#define ADEOC     	ADCR0bits.ADEOC     	/* bit 5 */
#define ADSTR     	ADCR0bits.ADSTR     	/* bit 6 */
#define ADEN      	ADCR0bits.ADEN      	/* bit 7 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADSPS0:1;
		unsigned char ADSPS1:1;
		unsigned char ADSPS2:1;
		unsigned char ADSPS3:1;
		unsigned char ADCKS0:1;
		unsigned char ADCKS1:1;
		unsigned char ADCKS2:1;
		unsigned char ADRSEL:1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define ADSPS0    	ADCR1bits.ADSPS0    	/* bit 0 */
#define ADSPS1    	ADCR1bits.ADSPS1    	/* bit 1 */
#define ADSPS2    	ADCR1bits.ADSPS2    	/* bit 2 */
#define ADSPS3    	ADCR1bits.ADSPS3    	/* bit 3 */
#define ADCKS0    	ADCR1bits.ADCKS0    	/* bit 4 */
#define ADCKS1    	ADCR1bits.ADCKS1    	/* bit 5 */
#define ADCKS2    	ADCR1bits.ADCKS2    	/* bit 6 */
#define ADRSEL    	ADCR1bits.ADRSEL    	/* bit 7 */

// ----- ADCR2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VRS0:1;
		unsigned char VRS1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char EVRS:1;
	};
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define VRS0      	ADCR2bits.VRS0      	/* bit 0 */
#define VRS1      	ADCR2bits.VRS1      	/* bit 1 */
#define EVRS      	ADCR2bits.EVRS      	/* bit 7 */

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

// ----- EINTCR Bits --------------------------------------------
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
} __EINTCRbits_t;
extern volatile __EINTCRbits_t __at(EINTCR_ADDR) EINTCRbits;

#define MINT00    	EINTCRbits.MINT00   	/* bit 3 */
#define MINT01    	EINTCRbits.MINT01   	/* bit 4 */

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
		unsigned char P50OE:1;
		unsigned char P51OE:1;
		unsigned char P52OE:1;
		unsigned char P53OE:1;
		unsigned char P54OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP5bits_t;
extern volatile __OEP5bits_t __at(OEP5_ADDR) OEP5bits;

#define P50OE     	OEP5bits.P50OE      	/* bit 0 */
#define P51OE     	OEP5bits.P51OE      	/* bit 1 */
#define P52OE     	OEP5bits.P52OE      	/* bit 2 */
#define P53OE     	OEP5bits.P53OE      	/* bit 3 */
#define P54OE     	OEP5bits.P54OE      	/* bit 4 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INT0IF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char PWMIF:1;
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char :1;
		unsigned char ADIF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define INT0IF    	INTFbits.INT0IF     	/* bit 0 */
#define PWMIF     	INTFbits.PWMIF      	/* bit 3 */
#define T0IF      	INTFbits.T0IF       	/* bit 4 */
#define T1IF      	INTFbits.T1IF       	/* bit 5 */
#define ADIF      	INTFbits.ADIF       	/* bit 7 */

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char INT0IE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char PWMIE:1;
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char :1;
		unsigned char ADIE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define INT0IE    	INTEbits.INT0IE     	/* bit 0 */
#define PWMIE     	INTEbits.PWMIE      	/* bit 3 */
#define T0IE      	INTEbits.T0IE       	/* bit 4 */
#define T1IE      	INTEbits.T1IE       	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 7 */

// ----- OSCM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char HFDE:1;
		unsigned char CLKS:1;
		unsigned char CPUM0:1;
		unsigned char CPUM1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OSCMbits_t;
extern volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;

#define HFDE      	OSCMbits.HFDE       	/* bit 1 */
#define CLKS      	OSCMbits.CLKS       	/* bit 2 */
#define CPUM0     	OSCMbits.CPUM0      	/* bit 3 */
#define CPUM1     	OSCMbits.CPUM1      	/* bit 4 */

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
		unsigned char P50D:1;
		unsigned char P51D:1;
		unsigned char P52D:1;
		unsigned char P53D:1;
		unsigned char P54D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP5bits_t;
extern volatile __IOP5bits_t __at(IOP5_ADDR) IOP5bits;

#define P50D      	IOP5bits.P50D       	/* bit 0 */
#define P51D      	IOP5bits.P51D       	/* bit 1 */
#define P52D      	IOP5bits.P52D       	/* bit 2 */
#define P53D      	IOP5bits.P53D       	/* bit 3 */
#define P54D      	IOP5bits.P54D       	/* bit 4 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char T0CKS1:1;
		unsigned char T0CKS2:1;
		unsigned char T0PRS0:1;
		unsigned char T0PRS1:1;
		unsigned char T0PRS2:1;
		unsigned char T0EN:1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define T0CKS1    	T0CRbits.T0CKS1     	/* bit 2 */
#define T0CKS2    	T0CRbits.T0CKS2     	/* bit 3 */
#define T0PRS0    	T0CRbits.T0PRS0     	/* bit 4 */
#define T0PRS1    	T0CRbits.T0PRS1     	/* bit 5 */
#define T0PRS2    	T0CRbits.T0PRS2     	/* bit 6 */
#define T0EN      	T0CRbits.T0EN       	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWM1OE:1;
		unsigned char BUZ1OE:1;
		unsigned char T1CKS1:1;
		unsigned char T1CKS2:1;
		unsigned char T1PRS0:1;
		unsigned char T1PRS1:1;
		unsigned char T1PRS2:1;
		unsigned char T1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 0 */
#define BUZ1OE    	T1CRbits.BUZ1OE     	/* bit 1 */
#define T1CKS1    	T1CRbits.T1CKS1     	/* bit 2 */
#define T1CKS2    	T1CRbits.T1CKS2     	/* bit 3 */
#define T1PRS0    	T1CRbits.T1PRS0     	/* bit 4 */
#define T1PRS1    	T1CRbits.T1PRS1     	/* bit 5 */
#define T1PRS2    	T1CRbits.T1PRS2     	/* bit 6 */
#define T1EN      	T1CRbits.T1EN       	/* bit 7 */

// ----- BUZCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char BUZPRS0:1;
		unsigned char BUZPRS1:1;
		unsigned char BUZEN:1;
	};
} __BUZCRbits_t;
extern volatile __BUZCRbits_t __at(BUZCR_ADDR) BUZCRbits;

#define BUZPRS0   	BUZCRbits.BUZPRS0   	/* bit 5 */
#define BUZPRS1   	BUZCRbits.BUZPRS1   	/* bit 6 */
#define BUZEN     	BUZCRbits.BUZEN     	/* bit 7 */

// ----- MCR Bits --------------------------------------------
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
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;

#define STKP0     	MCRbits.STKP0       	/* bit 0 */
#define STKP1     	MCRbits.STKP1       	/* bit 1 */
#define STKP2     	MCRbits.STKP2       	/* bit 2 */
#define GIE       	MCRbits.GIE         	/* bit 7 */

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
		unsigned char P50PU:1;
		unsigned char P51PU:1;
		unsigned char P52PU:1;
		unsigned char P53PU:1;
		unsigned char P54PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP5bits_t;
extern volatile __PUP5bits_t __at(PUP5_ADDR) PUP5bits;

#define P50PU     	PUP5bits.P50PU      	/* bit 0 */
#define P51PU     	PUP5bits.P51PU      	/* bit 1 */
#define P52PU     	PUP5bits.P52PU      	/* bit 2 */
#define P53PU     	PUP5bits.P53PU      	/* bit 3 */
#define P54PU     	PUP5bits.P54PU      	/* bit 4 */

// ----- PWMCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWMAOF:1;
		unsigned char PWMBOF:1;
		unsigned char PWMCOF:1;
		unsigned char :1;
		unsigned char PWMPRS0:1;
		unsigned char PWMPRS1:1;
		unsigned char PWMPRS2:1;
		unsigned char PWMEN:1;
	};
} __PWMCR0bits_t;
extern volatile __PWMCR0bits_t __at(PWMCR0_ADDR) PWMCR0bits;

#define PWMAOF    	PWMCR0bits.PWMAOF   	/* bit 0 */
#define PWMBOF    	PWMCR0bits.PWMBOF   	/* bit 1 */
#define PWMCOF    	PWMCR0bits.PWMCOF   	/* bit 2 */
#define PWMPRS0   	PWMCR0bits.PWMPRS0  	/* bit 4 */
#define PWMPRS1   	PWMCR0bits.PWMPRS1  	/* bit 5 */
#define PWMPRS2   	PWMCR0bits.PWMPRS2  	/* bit 6 */
#define PWMEN     	PWMCR0bits.PWMEN    	/* bit 7 */

// ----- PWMCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char PWMAOE:1;
		unsigned char PWMBOE:1;
		unsigned char PWMCOE:1;
	};
} __PWMCR1bits_t;
extern volatile __PWMCR1bits_t __at(PWMCR1_ADDR) PWMCR1bits;

#define PWMAOE    	PWMCR1bits.PWMAOE   	/* bit 5 */
#define PWMBOE    	PWMCR1bits.PWMBOE   	/* bit 6 */
#define PWMCOE    	PWMCR1bits.PWMCOE   	/* bit 7 */

#endif
