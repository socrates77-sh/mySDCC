#ifndef MC32P7212_H
#define MC32P7212_H

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
#define IOP0_ADDR       	0x0190
#define OEP0_ADDR       	0x0191
#define PUP0_ADDR       	0x0192
#define IOP1_ADDR       	0x0194
#define OEP1_ADDR       	0x0195
#define PUP1_ADDR       	0x0196
#define IOP2_ADDR       	0x0198
#define OEP2_ADDR       	0x0199
#define PUP2_ADDR       	0x019A
#define IOP3_ADDR       	0x019C
#define OEP3_ADDR       	0x019D
#define PUP3_ADDR       	0x019E
#define T0CR_ADDR       	0x01A0
#define T0CNT_ADDR      	0x01A1
#define T0LOAD_ADDR     	0x01A2
#define T0DATA_ADDR     	0x01A3
#define T1CR_ADDR       	0x01A4
#define T1CNT_ADDR      	0x01A5
#define T1LOAD_ADDR     	0x01A6
#define T1DATA_ADDR     	0x01A7
#define LXTCR_ADDR      	0x01A8
#define PUMP_ADDR       	0x01AD
#define OSCM_ADDR       	0x01AE
#define LVDCR_ADDR      	0x01AF
#define ADCR0_ADDR      	0x01B0
#define ADCR1_ADDR      	0x01B1
#define ADCR2_ADDR      	0x01B2
#define TPSC_ADDR       	0x01B3
#define ADRH_ADDR       	0x01B4
#define ADRM_ADDR       	0x01B5
#define ADRL_ADDR       	0x01B6
#define LCDCR0_ADDR     	0x01B8
#define LCDCR1_ADDR     	0x01B9
#define LCDIOS1_ADDR    	0x01BA
#define LCDIOS2_ADDR    	0x01BB
#define LCDDS2_ADDR     	0x01C0
#define LCDDS3_ADDR     	0x01C1
#define LCDDS4_ADDR     	0x01C2
#define LCDDS5_ADDR     	0x01C3
#define LCDDS6_ADDR     	0x01C4
#define LCDDS7_ADDR     	0x01C5
#define LCDDS8_ADDR     	0x01C6
#define LCDDS9_ADDR     	0x01C7
#define LCDDS10_ADDR    	0x01C8
#define LCDDS11_ADDR    	0x01C9
#define LCDDS12_ADDR    	0x01CA
#define LCDDS13_ADDR    	0x01CB

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
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (IOP2_ADDR)     	IOP2;
extern __sfr __at (OEP2_ADDR)     	OEP2;
extern __sfr __at (PUP2_ADDR)     	PUP2;
extern __sfr __at (IOP3_ADDR)     	IOP3;
extern __sfr __at (OEP3_ADDR)     	OEP3;
extern __sfr __at (PUP3_ADDR)     	PUP3;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T1DATA_ADDR)   	T1DATA;
extern __sfr __at (LXTCR_ADDR)    	LXTCR;
extern __sfr __at (PUMP_ADDR)     	PUMP;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (LVDCR_ADDR)    	LVDCR;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADCR2_ADDR)    	ADCR2;
extern __sfr __at (TPSC_ADDR)     	TPSC;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRM_ADDR)     	ADRM;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (LCDCR0_ADDR)   	LCDCR0;
extern __sfr __at (LCDCR1_ADDR)   	LCDCR1;
extern __sfr __at (LCDIOS1_ADDR)  	LCDIOS1;
extern __sfr __at (LCDIOS2_ADDR)  	LCDIOS2;
extern __sfr __at (LCDDS2_ADDR)   	LCDDS2;
extern __sfr __at (LCDDS3_ADDR)   	LCDDS3;
extern __sfr __at (LCDDS4_ADDR)   	LCDDS4;
extern __sfr __at (LCDDS5_ADDR)   	LCDDS5;
extern __sfr __at (LCDDS6_ADDR)   	LCDDS6;
extern __sfr __at (LCDDS7_ADDR)   	LCDDS7;
extern __sfr __at (LCDDS8_ADDR)   	LCDDS8;
extern __sfr __at (LCDDS9_ADDR)   	LCDDS9;
extern __sfr __at (LCDDS10_ADDR)  	LCDDS10;
extern __sfr __at (LCDDS11_ADDR)  	LCDDS11;
extern __sfr __at (LCDDS12_ADDR)  	LCDDS12;
extern __sfr __at (LCDDS13_ADDR)  	LCDDS13;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0

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

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char :1;
		unsigned char T2IE:1;
		unsigned char ADIE:1;
		unsigned char T3IE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define T2IE      	INTEbits.T2IE       	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */
#define T3IE      	INTEbits.T3IE       	/* bit 7 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char :1;
		unsigned char T2IF:1;
		unsigned char ADIF:1;
		unsigned char T3IF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define T2IF      	INTFbits.T2IF       	/* bit 5 */
#define ADIF      	INTFbits.ADIF       	/* bit 6 */
#define T3IF      	INTFbits.T3IF       	/* bit 7 */

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
		unsigned char :1;
		unsigned char :1;
	};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define P10D      	IOP1bits.P10D       	/* bit 0 */
#define P11D      	IOP1bits.P11D       	/* bit 1 */
#define P12D      	IOP1bits.P12D       	/* bit 2 */
#define P13D      	IOP1bits.P13D       	/* bit 3 */
#define P14D      	IOP1bits.P14D       	/* bit 4 */
#define P15D      	IOP1bits.P15D       	/* bit 5 */

// ----- OEP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10OE:1;
		unsigned char P11OE:1;
		unsigned char P12OE:1;
		unsigned char P13OE:1;
		unsigned char P14OE:1;
		unsigned char P15OE:1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;

#define P10OE     	OEP1bits.P10OE      	/* bit 0 */
#define P11OE     	OEP1bits.P11OE      	/* bit 1 */
#define P12OE     	OEP1bits.P12OE      	/* bit 2 */
#define P13OE     	OEP1bits.P13OE      	/* bit 3 */
#define P14OE     	OEP1bits.P14OE      	/* bit 4 */
#define P15OE     	OEP1bits.P15OE      	/* bit 5 */

// ----- PUP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10PU:1;
		unsigned char P11PU:1;
		unsigned char P12PU:1;
		unsigned char P13PU:1;
		unsigned char P14PU:1;
		unsigned char P15PU:1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;

#define P10PU     	PUP1bits.P10PU      	/* bit 0 */
#define P11PU     	PUP1bits.P11PU      	/* bit 1 */
#define P12PU     	PUP1bits.P12PU      	/* bit 2 */
#define P13PU     	PUP1bits.P13PU      	/* bit 3 */
#define P14PU     	PUP1bits.P14PU      	/* bit 4 */
#define P15PU     	PUP1bits.P15PU      	/* bit 5 */

// ----- IOP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20D:1;
		unsigned char P21D:1;
		unsigned char P22D:1;
		unsigned char P23D:1;
		unsigned char P24D:1;
		unsigned char P25D:1;
		unsigned char P26D:1;
		unsigned char P27D:1;
	};
} __IOP2bits_t;
extern volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;

#define P20D      	IOP2bits.P20D       	/* bit 0 */
#define P21D      	IOP2bits.P21D       	/* bit 1 */
#define P22D      	IOP2bits.P22D       	/* bit 2 */
#define P23D      	IOP2bits.P23D       	/* bit 3 */
#define P24D      	IOP2bits.P24D       	/* bit 4 */
#define P25D      	IOP2bits.P25D       	/* bit 5 */
#define P26D      	IOP2bits.P26D       	/* bit 6 */
#define P27D      	IOP2bits.P27D       	/* bit 7 */

// ----- OEP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20OE:1;
		unsigned char P21OE:1;
		unsigned char P22OE:1;
		unsigned char P23OE:1;
		unsigned char P24OE:1;
		unsigned char P25OE:1;
		unsigned char P26OE:1;
		unsigned char P27OE:1;
	};
} __OEP2bits_t;
extern volatile __OEP2bits_t __at(OEP2_ADDR) OEP2bits;

#define P20OE     	OEP2bits.P20OE      	/* bit 0 */
#define P21OE     	OEP2bits.P21OE      	/* bit 1 */
#define P22OE     	OEP2bits.P22OE      	/* bit 2 */
#define P23OE     	OEP2bits.P23OE      	/* bit 3 */
#define P24OE     	OEP2bits.P24OE      	/* bit 4 */
#define P25OE     	OEP2bits.P25OE      	/* bit 5 */
#define P26OE     	OEP2bits.P26OE      	/* bit 6 */
#define P27OE     	OEP2bits.P27OE      	/* bit 7 */

// ----- PUP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20PU:1;
		unsigned char P21PU:1;
		unsigned char P22PU:1;
		unsigned char P23PU:1;
		unsigned char P24PU:1;
		unsigned char P25PU:1;
		unsigned char P26PU:1;
		unsigned char P27PU:1;
	};
} __PUP2bits_t;
extern volatile __PUP2bits_t __at(PUP2_ADDR) PUP2bits;

#define P20PU     	PUP2bits.P20PU      	/* bit 0 */
#define P21PU     	PUP2bits.P21PU      	/* bit 1 */
#define P22PU     	PUP2bits.P22PU      	/* bit 2 */
#define P23PU     	PUP2bits.P23PU      	/* bit 3 */
#define P24PU     	PUP2bits.P24PU      	/* bit 4 */
#define P25PU     	PUP2bits.P25PU      	/* bit 5 */
#define P26PU     	PUP2bits.P26PU      	/* bit 6 */
#define P27PU     	PUP2bits.P27PU      	/* bit 7 */

// ----- IOP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30D:1;
		unsigned char P31D:1;
		unsigned char P32D:1;
		unsigned char P33D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP3bits_t;
extern volatile __IOP3bits_t __at(IOP3_ADDR) IOP3bits;

#define P30D      	IOP3bits.P30D       	/* bit 0 */
#define P31D      	IOP3bits.P31D       	/* bit 1 */
#define P32D      	IOP3bits.P32D       	/* bit 2 */
#define P33D      	IOP3bits.P33D       	/* bit 3 */

// ----- OEP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30OE:1;
		unsigned char P31OE:1;
		unsigned char P32OE:1;
		unsigned char P33OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP3bits_t;
extern volatile __OEP3bits_t __at(OEP3_ADDR) OEP3bits;

#define P30OE     	OEP3bits.P30OE      	/* bit 0 */
#define P31OE     	OEP3bits.P31OE      	/* bit 1 */
#define P32OE     	OEP3bits.P32OE      	/* bit 2 */
#define P33OE     	OEP3bits.P33OE      	/* bit 3 */

// ----- PUP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30PU:1;
		unsigned char P31PU:1;
		unsigned char P32PU:1;
		unsigned char P33PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP3bits_t;
extern volatile __PUP3bits_t __at(PUP3_ADDR) PUP3bits;

#define P30PU     	PUP3bits.P30PU      	/* bit 0 */
#define P31PU     	PUP3bits.P31PU      	/* bit 1 */
#define P32PU     	PUP3bits.P32PU      	/* bit 2 */
#define P33PU     	PUP3bits.P33PU      	/* bit 3 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0PR:3;
		unsigned char T0PTS:2;
		unsigned char BUZ0OE:1;
		unsigned char PWM0OE:1;
		unsigned char TC0EN:1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define T0PR      	T0CRbits.T0PR       	/* bit 2-0 */
#define T0PTS     	T0CRbits.T0PTS      	/* bit 4-3 */
#define BUZ0OE    	T0CRbits.BUZ0OE     	/* bit 5 */
#define PWM0OE    	T0CRbits.PWM0OE     	/* bit 6 */
#define TC0EN     	T0CRbits.TC0EN      	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PR:3;
		unsigned char T1PTS:2;
		unsigned char BUZ1OE:1;
		unsigned char PWM1OE:1;
		unsigned char TC1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PR      	T1CRbits.T1PR       	/* bit 2-0 */
#define T1PTS     	T1CRbits.T1PTS      	/* bit 4-3 */
#define BUZ1OE    	T1CRbits.BUZ1OE     	/* bit 5 */
#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 6 */
#define TC1EN     	T1CRbits.TC1EN      	/* bit 7 */

// ----- LXTCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LPEN:3;
		unsigned char FILS:1;
		unsigned char VDLSEL:1;
		unsigned char RSEL:1;
		unsigned char LDOLPEN:1;
		unsigned char :1;
	};
} __LXTCRbits_t;
extern volatile __LXTCRbits_t __at(LXTCR_ADDR) LXTCRbits;

#define LPEN      	LXTCRbits.LPEN      	/* bit 2-0 */
#define FILS      	LXTCRbits.FILS      	/* bit 3 */
#define VDLSEL    	LXTCRbits.VDLSEL    	/* bit 4 */
#define RSEL      	LXTCRbits.RSEL      	/* bit 5 */
#define LDOLPEN   	LXTCRbits.LDOLPEN   	/* bit 6 */

// ----- PUMP Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VLCDX:2;
		unsigned char CHP_VPP:1;
		unsigned char PGMTIME:1;
		unsigned char VCP_CAL:1;
		unsigned char CPCKS:1;
		unsigned char PUMPEN:1;
		unsigned char ERV:1;
	};
} __PUMPbits_t;
extern volatile __PUMPbits_t __at(PUMP_ADDR) PUMPbits;

#define VLCDX     	PUMPbits.VLCDX      	/* bit 1-0 */
#define CHP_VPP   	PUMPbits.CHP_VPP    	/* bit 2 */
#define PGMTIME   	PUMPbits.PGMTIME    	/* bit 3 */
#define VCP_CAL   	PUMPbits.VCP_CAL    	/* bit 4 */
#define CPCKS     	PUMPbits.CPCKS      	/* bit 5 */
#define PUMPEN    	PUMPbits.PUMPEN     	/* bit 6 */
#define ERV       	PUMPbits.ERV        	/* bit 7 */

// ----- OSCM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char HFEN:1;
		unsigned char LFEN:1;
		unsigned char CLKS:1;
		unsigned char HIRCOUTEN:1;
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
#define HIRCOUTEN 	OSCMbits.HIRCOUTEN  	/* bit 3 */
#define STBH      	OSCMbits.STBH       	/* bit 4 */
#define STBL      	OSCMbits.STBL       	/* bit 5 */

// ----- LVDCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LVDF:1;
		unsigned char :1;
		unsigned char VBGSEL:1;
		unsigned char LVDS:4;
		unsigned char LVDEN:1;
	};
} __LVDCRbits_t;
extern volatile __LVDCRbits_t __at(LVDCR_ADDR) LVDCRbits;

#define LVDF      	LVDCRbits.LVDF      	/* bit 0 */
#define VBGSEL    	LVDCRbits.VBGSEL    	/* bit 2 */
#define LVDS      	LVDCRbits.LVDS      	/* bit 6-3 */
#define LVDEN     	LVDCRbits.LVDEN     	/* bit 7 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADCHS:2;
		unsigned char ADCKS:2;
		unsigned char VREF_ICTL:1;
		unsigned char PGA_EN:1;
		unsigned char CHOP_EN:1;
		unsigned char ADEN:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADCHS     	ADCR0bits.ADCHS     	/* bit 1-0 */
#define ADCKS     	ADCR0bits.ADCKS     	/* bit 3-2 */
#define VREF_ICTL 	ADCR0bits.VREF_ICTL 	/* bit 4 */
#define PGA_EN    	ADCR0bits.PGA_EN    	/* bit 5 */
#define CHOP_EN   	ADCR0bits.CHOP_EN   	/* bit 6 */
#define ADEN      	ADCR0bits.ADEN      	/* bit 7 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PGS:4;
		unsigned char ADHS:4;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define PGS       	ADCR1bits.PGS       	/* bit 3-0 */
#define ADHS      	ADCR1bits.ADHS      	/* bit 7-4 */

// ----- ADCR2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADC_ICTL:6;
		unsigned char T_PGA_OUT_ENB:1;
		unsigned char T_ADC_IN_RNB:1;
	};
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define ADC_ICTL  	ADCR2bits.ADC_ICTL  	/* bit 5-0 */
#define T_PGA_OUT_ENB	ADCR2bits.T_PGA_OUT_ENB	/* bit 6 */
#define T_ADC_IN_RNB	ADCR2bits.T_ADC_IN_RNB	/* bit 7 */

// ----- TPSC Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TPS_TST:2;
		unsigned char PT_TS:1;
		unsigned char VBGEN:1;
		unsigned char VLDOEN:1;
		unsigned char VLDOSL1:1;
		unsigned char VLDOSL0:1;
		unsigned char ADC_T:1;
	};
} __TPSCbits_t;
extern volatile __TPSCbits_t __at(TPSC_ADDR) TPSCbits;

#define TPS_TST   	TPSCbits.TPS_TST    	/* bit 1-0 */
#define PT_TS     	TPSCbits.PT_TS      	/* bit 2 */
#define VBGEN     	TPSCbits.VBGEN      	/* bit 3 */
#define VLDOEN    	TPSCbits.VLDOEN     	/* bit 4 */
#define VLDOSL1   	TPSCbits.VLDOSL1    	/* bit 5 */
#define VLDOSL0   	TPSCbits.VLDOSL0    	/* bit 6 */
#define ADC_T     	TPSCbits.ADC_T      	/* bit 7 */

// ----- LCDCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDRS:2;
		unsigned char LCDSPEED:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char LCDSP:2;
		unsigned char LCDEN:1;
	};
} __LCDCR0bits_t;
extern volatile __LCDCR0bits_t __at(LCDCR0_ADDR) LCDCR0bits;

#define LCDRS     	LCDCR0bits.LCDRS    	/* bit 1-0 */
#define LCDSPEED  	LCDCR0bits.LCDSPEED 	/* bit 2 */
#define LCDSP     	LCDCR0bits.LCDSP    	/* bit 6-5 */
#define LCDEN     	LCDCR0bits.LCDEN    	/* bit 7 */

// ----- LCDCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FLCD:2;
		unsigned char LCDCKS:1;
		unsigned char LCDM:1;
		unsigned char BEN:1;
		unsigned char LCDDUTY:2;
		unsigned char :1;
	};
} __LCDCR1bits_t;
extern volatile __LCDCR1bits_t __at(LCDCR1_ADDR) LCDCR1bits;

#define FLCD      	LCDCR1bits.FLCD     	/* bit 1-0 */
#define LCDCKS    	LCDCR1bits.LCDCKS   	/* bit 2 */
#define LCDM      	LCDCR1bits.LCDM     	/* bit 3 */
#define BEN       	LCDCR1bits.BEN      	/* bit 4 */
#define LCDDUTY   	LCDCR1bits.LCDDUTY  	/* bit 6-5 */

// ----- LCDIOS2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char :1;
		unsigned char SEGIOS11:1;
		unsigned char SEGIOS12:1;
		unsigned char SEGIOS13:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDIOS2bits_t;
extern volatile __LCDIOS2bits_t __at(LCDIOS2_ADDR) LCDIOS2bits;

#define SEGIOS11  	LCDIOS2bits.SEGIOS11	/* bit 1 */
#define SEGIOS12  	LCDIOS2bits.SEGIOS12	/* bit 2 */
#define SEGIOS13  	LCDIOS2bits.SEGIOS13	/* bit 3 */

// ----- LCDDS2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG2:1;
		unsigned char COM1SEG2:1;
		unsigned char COM2SEG2:1;
		unsigned char COM3SEG2:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS2bits_t;
extern volatile __LCDDS2bits_t __at(LCDDS2_ADDR) LCDDS2bits;

#define COM0SEG2  	LCDDS2bits.COM0SEG2 	/* bit 0 */
#define COM1SEG2  	LCDDS2bits.COM1SEG2 	/* bit 1 */
#define COM2SEG2  	LCDDS2bits.COM2SEG2 	/* bit 2 */
#define COM3SEG2  	LCDDS2bits.COM3SEG2 	/* bit 3 */

// ----- LCDDS3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG3:1;
		unsigned char COM1SEG3:1;
		unsigned char COM2SEG3:1;
		unsigned char COM3SEG3:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS3bits_t;
extern volatile __LCDDS3bits_t __at(LCDDS3_ADDR) LCDDS3bits;

#define COM0SEG3  	LCDDS3bits.COM0SEG3 	/* bit 0 */
#define COM1SEG3  	LCDDS3bits.COM1SEG3 	/* bit 1 */
#define COM2SEG3  	LCDDS3bits.COM2SEG3 	/* bit 2 */
#define COM3SEG3  	LCDDS3bits.COM3SEG3 	/* bit 3 */

// ----- LCDDS4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG4:1;
		unsigned char COM1SEG4:1;
		unsigned char COM2SEG4:1;
		unsigned char COM3SEG4:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS4bits_t;
extern volatile __LCDDS4bits_t __at(LCDDS4_ADDR) LCDDS4bits;

#define COM0SEG4  	LCDDS4bits.COM0SEG4 	/* bit 0 */
#define COM1SEG4  	LCDDS4bits.COM1SEG4 	/* bit 1 */
#define COM2SEG4  	LCDDS4bits.COM2SEG4 	/* bit 2 */
#define COM3SEG4  	LCDDS4bits.COM3SEG4 	/* bit 3 */

// ----- LCDDS5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG5:1;
		unsigned char COM1SEG5:1;
		unsigned char COM2SEG5:1;
		unsigned char COM3SEG5:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS5bits_t;
extern volatile __LCDDS5bits_t __at(LCDDS5_ADDR) LCDDS5bits;

#define COM0SEG5  	LCDDS5bits.COM0SEG5 	/* bit 0 */
#define COM1SEG5  	LCDDS5bits.COM1SEG5 	/* bit 1 */
#define COM2SEG5  	LCDDS5bits.COM2SEG5 	/* bit 2 */
#define COM3SEG5  	LCDDS5bits.COM3SEG5 	/* bit 3 */

// ----- LCDDS6 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG6:1;
		unsigned char COM1SEG6:1;
		unsigned char COM2SEG6:1;
		unsigned char COM3SEG6:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS6bits_t;
extern volatile __LCDDS6bits_t __at(LCDDS6_ADDR) LCDDS6bits;

#define COM0SEG6  	LCDDS6bits.COM0SEG6 	/* bit 0 */
#define COM1SEG6  	LCDDS6bits.COM1SEG6 	/* bit 1 */
#define COM2SEG6  	LCDDS6bits.COM2SEG6 	/* bit 2 */
#define COM3SEG6  	LCDDS6bits.COM3SEG6 	/* bit 3 */

// ----- LCDDS7 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG7:1;
		unsigned char COM1SEG7:1;
		unsigned char COM2SEG7:1;
		unsigned char COM3SEG7:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS7bits_t;
extern volatile __LCDDS7bits_t __at(LCDDS7_ADDR) LCDDS7bits;

#define COM0SEG7  	LCDDS7bits.COM0SEG7 	/* bit 0 */
#define COM1SEG7  	LCDDS7bits.COM1SEG7 	/* bit 1 */
#define COM2SEG7  	LCDDS7bits.COM2SEG7 	/* bit 2 */
#define COM3SEG7  	LCDDS7bits.COM3SEG7 	/* bit 3 */

// ----- LCDDS8 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG8:1;
		unsigned char COM1SEG8:1;
		unsigned char COM2SEG8:1;
		unsigned char COM3SEG8:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS8bits_t;
extern volatile __LCDDS8bits_t __at(LCDDS8_ADDR) LCDDS8bits;

#define COM0SEG8  	LCDDS8bits.COM0SEG8 	/* bit 0 */
#define COM1SEG8  	LCDDS8bits.COM1SEG8 	/* bit 1 */
#define COM2SEG8  	LCDDS8bits.COM2SEG8 	/* bit 2 */
#define COM3SEG8  	LCDDS8bits.COM3SEG8 	/* bit 3 */

// ----- LCDDS9 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG9:1;
		unsigned char COM1SEG9:1;
		unsigned char COM2SEG9:1;
		unsigned char COM3SEG9:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS9bits_t;
extern volatile __LCDDS9bits_t __at(LCDDS9_ADDR) LCDDS9bits;

#define COM0SEG9  	LCDDS9bits.COM0SEG9 	/* bit 0 */
#define COM1SEG9  	LCDDS9bits.COM1SEG9 	/* bit 1 */
#define COM2SEG9  	LCDDS9bits.COM2SEG9 	/* bit 2 */
#define COM3SEG9  	LCDDS9bits.COM3SEG9 	/* bit 3 */

// ----- LCDDS10 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG10:1;
		unsigned char COM1SEG10:1;
		unsigned char COM2SEG10:1;
		unsigned char COM3SEG10:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS10bits_t;
extern volatile __LCDDS10bits_t __at(LCDDS10_ADDR) LCDDS10bits;

#define COM0SEG10 	LCDDS10bits.COM0SEG10	/* bit 0 */
#define COM1SEG10 	LCDDS10bits.COM1SEG10	/* bit 1 */
#define COM2SEG10 	LCDDS10bits.COM2SEG10	/* bit 2 */
#define COM3SEG10 	LCDDS10bits.COM3SEG10	/* bit 3 */

// ----- LCDDS11 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG11:1;
		unsigned char COM1SEG11:1;
		unsigned char COM2SEG11:1;
		unsigned char COM3SEG11:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS11bits_t;
extern volatile __LCDDS11bits_t __at(LCDDS11_ADDR) LCDDS11bits;

#define COM0SEG11 	LCDDS11bits.COM0SEG11	/* bit 0 */
#define COM1SEG11 	LCDDS11bits.COM1SEG11	/* bit 1 */
#define COM2SEG11 	LCDDS11bits.COM2SEG11	/* bit 2 */
#define COM3SEG11 	LCDDS11bits.COM3SEG11	/* bit 3 */

// ----- LCDDS12 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG12:1;
		unsigned char COM1SEG12:1;
		unsigned char COM2SEG12:1;
		unsigned char COM3SEG12:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS12bits_t;
extern volatile __LCDDS12bits_t __at(LCDDS12_ADDR) LCDDS12bits;

#define COM0SEG12 	LCDDS12bits.COM0SEG12	/* bit 0 */
#define COM1SEG12 	LCDDS12bits.COM1SEG12	/* bit 1 */
#define COM2SEG12 	LCDDS12bits.COM2SEG12	/* bit 2 */
#define COM3SEG12 	LCDDS12bits.COM3SEG12	/* bit 3 */

// ----- LCDDS13 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COM0SEG13:1;
		unsigned char COM1SEG13:1;
		unsigned char COM2SEG13:1;
		unsigned char COM3SEG13:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDS13bits_t;
extern volatile __LCDDS13bits_t __at(LCDDS13_ADDR) LCDDS13bits;

#define COM0SEG13 	LCDDS13bits.COM0SEG13	/* bit 0 */
#define COM1SEG13 	LCDDS13bits.COM1SEG13	/* bit 1 */
#define COM2SEG13 	LCDDS13bits.COM2SEG13	/* bit 2 */
#define COM3SEG13 	LCDDS13bits.COM3SEG13	/* bit 3 */

#endif
