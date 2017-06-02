#ifndef MC73P3_H
#define MC73P3_H

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
#define T1CR_ADDR       	0x01A4
#define T1CNT_ADDR      	0x01A5
#define T1LOAD_ADDR     	0x01A6
#define T1DATA_ADDR     	0x01A7
#define T2CR_ADDR       	0x01A8
#define T2CNT_ADDR      	0x01A9
#define T2LOAD_ADDR     	0x01AA
#define T2DATA_ADDR     	0x01AB
#define T3CR_ADDR       	0x01AC
#define T3CNT_ADDR      	0x01AD
#define T3LOAD_ADDR     	0x01AE
#define PWM0DE_ADDR     	0x01B0
#define PWM1DE_ADDR     	0x01B1
#define PWM2DE_ADDR     	0x01B0
#define PWMCR0_ADDR     	0x01B4
#define PWMCR1_ADDR     	0x01B5
#define ADCR0_ADDR      	0x01B8
#define ADCR1_ADDR      	0x01B9
#define ADRH_ADDR       	0x01BC
#define ADRL_ADDR       	0x01BD
#define ANSEL_ADDR      	0x01BE
#define LEDCR0_ADDR     	0x01C0
#define LEDCR1_ADDR     	0x01C1
#define LCDCR0_ADDR     	0x01C2
#define LCDCR1_ADDR     	0x01C3
#define LCDIOS0_ADDR    	0x01C4
#define LCDIOS1_ADDR    	0x01C5
#define LCDIOS2_ADDR    	0x01C6

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
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T1DATA_ADDR)   	T1DATA;
extern __sfr __at (T2CR_ADDR)     	T2CR;
extern __sfr __at (T2CNT_ADDR)    	T2CNT;
extern __sfr __at (T2LOAD_ADDR)   	T2LOAD;
extern __sfr __at (T2DATA_ADDR)   	T2DATA;
extern __sfr __at (T3CR_ADDR)     	T3CR;
extern __sfr __at (T3CNT_ADDR)    	T3CNT;
extern __sfr __at (T3LOAD_ADDR)   	T3LOAD;
extern __sfr __at (PWM0DE_ADDR)   	PWM0DE;
extern __sfr __at (PWM1DE_ADDR)   	PWM1DE;
extern __sfr __at (PWM2DE_ADDR)   	PWM2DE;
extern __sfr __at (PWMCR0_ADDR)   	PWMCR0;
extern __sfr __at (PWMCR1_ADDR)   	PWMCR1;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (ANSEL_ADDR)    	ANSEL;
extern __sfr __at (LEDCR0_ADDR)   	LEDCR0;
extern __sfr __at (LEDCR1_ADDR)   	LEDCR1;
extern __sfr __at (LCDCR0_ADDR)   	LCDCR0;
extern __sfr __at (LCDCR1_ADDR)   	LCDCR1;
extern __sfr __at (LCDIOS0_ADDR)  	LCDIOS0;
extern __sfr __at (LCDIOS1_ADDR)  	LCDIOS1;
extern __sfr __at (LCDIOS2_ADDR)  	LCDIOS2;

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
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define T2IE      	INTEbits.T2IE       	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */

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
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define T2IF      	INTFbits.T2IF       	/* bit 5 */
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
		unsigned char :1;
		unsigned char :1;
	};
} __PUP0bits_t;
extern volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;

#define P00PU     	PUP0bits.P00PU      	/* bit 0 */
#define P01PU     	PUP0bits.P01PU      	/* bit 1 */
#define P02PU     	PUP0bits.P02PU      	/* bit 2 */
#define P03PU     	PUP0bits.P03PU      	/* bit 3 */
#define P04PU     	PUP0bits.P04PU      	/* bit 4 */
#define P05PU     	PUP0bits.P05PU      	/* bit 5 */

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

// ----- T2CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2PR:3;
		unsigned char T2PTS:2;
		unsigned char BUZ2OE:1;
		unsigned char PWM2OE:1;
		unsigned char TC2EN:1;
	};
} __T2CRbits_t;
extern volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;

#define T2PR      	T2CRbits.T2PR       	/* bit 2-0 */
#define T2PTS     	T2CRbits.T2PTS      	/* bit 4-3 */
#define BUZ2OE    	T2CRbits.BUZ2OE     	/* bit 5 */
#define PWM2OE    	T2CRbits.PWM2OE     	/* bit 6 */
#define TC2EN     	T2CRbits.TC2EN      	/* bit 7 */

// ----- T3CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T3PR:3;
		unsigned char T3PTS:2;
		unsigned char :1;
		unsigned char :1;
		unsigned char TC3EN:1;
	};
} __T3CRbits_t;
extern volatile __T3CRbits_t __at(T3CR_ADDR) T3CRbits;

#define T3PR      	T3CRbits.T3PR       	/* bit 2-0 */
#define T3PTS     	T3CRbits.T3PTS      	/* bit 4-3 */
#define TC3EN     	T3CRbits.TC3EN      	/* bit 7 */

// ----- PWMCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FPWMF:2;
		unsigned char FPWMR:2;
		unsigned char PWM0INV:1;
		unsigned char FPWM1INV:1;
		unsigned char PWM2INV:1;
		unsigned char FPWMEN:1;
	};
} __PWMCR0bits_t;
extern volatile __PWMCR0bits_t __at(PWMCR0_ADDR) PWMCR0bits;

#define FPWMF     	PWMCR0bits.FPWMF    	/* bit 1-0 */
#define FPWMR     	PWMCR0bits.FPWMR    	/* bit 3-2 */
#define PWM0INV   	PWMCR0bits.PWM0INV  	/* bit 4 */
#define FPWM1INV  	PWMCR0bits.FPWM1INV 	/* bit 5 */
#define PWM2INV   	PWMCR0bits.PWM2INV  	/* bit 6 */
#define FPWMEN    	PWMCR0bits.FPWMEN   	/* bit 7 */

// ----- PWMCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PMODE:3;
		unsigned char TMRCKS:2;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PWMCR1bits_t;
extern volatile __PWMCR1bits_t __at(PWMCR1_ADDR) PWMCR1bits;

#define PMODE     	PWMCR1bits.PMODE    	/* bit 2-0 */
#define TMRCKS    	PWMCR1bits.TMRCKS   	/* bit 4-3 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADON:1;
		unsigned char ADEOC:1;
		unsigned char ADCKS:2;
		unsigned char ADCHS:4;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADON      	ADCR0bits.ADON      	/* bit 0 */
#define ADEOC     	ADCR0bits.ADEOC     	/* bit 1 */
#define ADCKS     	ADCR0bits.ADCKS     	/* bit 3-2 */
#define ADCHS     	ADCR0bits.ADCHS     	/* bit 7-4 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VRS:2;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char ADRSEL:1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define VRS       	ADCR1bits.VRS       	/* bit 1-0 */
#define ADRSEL    	ADCR1bits.ADRSEL    	/* bit 7 */

// ----- ANSEL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P14ANS:1;
		unsigned char P15ANS:1;
		unsigned char P16ANS:1;
		unsigned char P17ANS:1;
		unsigned char P23ANS:1;
		unsigned char P24ANS:1;
		unsigned char P06ANS:1;
		unsigned char P13ANS:1;
	};
} __ANSELbits_t;
extern volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;

#define P14ANS    	ANSELbits.P14ANS    	/* bit 0 */
#define P15ANS    	ANSELbits.P15ANS    	/* bit 1 */
#define P16ANS    	ANSELbits.P16ANS    	/* bit 2 */
#define P17ANS    	ANSELbits.P17ANS    	/* bit 3 */
#define P23ANS    	ANSELbits.P23ANS    	/* bit 4 */
#define P24ANS    	ANSELbits.P24ANS    	/* bit 5 */
#define P06ANS    	ANSELbits.P06ANS    	/* bit 6 */
#define P13ANS    	ANSELbits.P13ANS    	/* bit 7 */

// ----- LEDCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char GYS:3;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char LEDEN:1;
	};
} __LEDCR0bits_t;
extern volatile __LEDCR0bits_t __at(LEDCR0_ADDR) LEDCR0bits;

#define GYS       	LEDCR0bits.GYS      	/* bit 2-0 */
#define LEDEN     	LEDCR0bits.LEDEN    	/* bit 7 */

// ----- LEDCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FLED:2;
		unsigned char :1;
		unsigned char IBPS:2;
		unsigned char :1;
		unsigned char LEDCKS:1;
		unsigned char DRVPS:1;
	};
} __LEDCR1bits_t;
extern volatile __LEDCR1bits_t __at(LEDCR1_ADDR) LEDCR1bits;

#define FLED      	LEDCR1bits.FLED     	/* bit 1-0 */
#define IBPS      	LEDCR1bits.IBPS     	/* bit 4-3 */
#define LEDCKS    	LEDCR1bits.LEDCKS   	/* bit 6 */
#define DRVPS     	LEDCR1bits.DRVPS    	/* bit 7 */

// ----- LCDCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDRS:2;
		unsigned char LCDSPEED:1;
		unsigned char LCDSP:2;
		unsigned char LCDEN:1;
		unsigned char :1;
		unsigned char DISPS:1;
	};
} __LCDCR0bits_t;
extern volatile __LCDCR0bits_t __at(LCDCR0_ADDR) LCDCR0bits;

#define LCDRS     	LCDCR0bits.LCDRS    	/* bit 1-0 */
#define LCDSPEED  	LCDCR0bits.LCDSPEED 	/* bit 2 */
#define LCDSP     	LCDCR0bits.LCDSP    	/* bit 4-3 */
#define LCDEN     	LCDCR0bits.LCDEN    	/* bit 5 */
#define DISPS     	LCDCR0bits.DISPS    	/* bit 7 */

// ----- LCDCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FLCD:2;
		unsigned char LCDCKS:1;
		unsigned char LCDM:1;
		unsigned char LCDBS:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDCR1bits_t;
extern volatile __LCDCR1bits_t __at(LCDCR1_ADDR) LCDCR1bits;

#define FLCD      	LCDCR1bits.FLCD     	/* bit 1-0 */
#define LCDCKS    	LCDCR1bits.LCDCKS   	/* bit 2 */
#define LCDM      	LCDCR1bits.LCDM     	/* bit 3 */
#define LCDBS     	LCDCR1bits.LCDBS    	/* bit 4 */

// ----- LCDIOS0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char COMIOS:4;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDIOS0bits_t;
extern volatile __LCDIOS0bits_t __at(LCDIOS0_ADDR) LCDIOS0bits;

#define COMIOS    	LCDIOS0bits.COMIOS  	/* bit 3-0 */

// ----- LCDIOS1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char SEGIOS9:1;
		unsigned char SEGIOS10:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDIOS1bits_t;
extern volatile __LCDIOS1bits_t __at(LCDIOS1_ADDR) LCDIOS1bits;

#define SEGIOS9   	LCDIOS1bits.SEGIOS9 	/* bit 0 */
#define SEGIOS10  	LCDIOS1bits.SEGIOS10	/* bit 1 */

// ----- LCDIOS2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char SEGIOS1:1;
		unsigned char SEGIOS2:1;
		unsigned char SEGIOS3:1;
		unsigned char SEGIOS4:1;
		unsigned char :1;
		unsigned char SEGIOS6:1;
		unsigned char SEGIOS7:1;
		unsigned char SEGIOS8:1;
	};
} __LCDIOS2bits_t;
extern volatile __LCDIOS2bits_t __at(LCDIOS2_ADDR) LCDIOS2bits;

#define SEGIOS1   	LCDIOS2bits.SEGIOS1 	/* bit 0 */
#define SEGIOS2   	LCDIOS2bits.SEGIOS2 	/* bit 1 */
#define SEGIOS3   	LCDIOS2bits.SEGIOS3 	/* bit 2 */
#define SEGIOS4   	LCDIOS2bits.SEGIOS4 	/* bit 3 */
#define SEGIOS6   	LCDIOS2bits.SEGIOS6 	/* bit 5 */
#define SEGIOS7   	LCDIOS2bits.SEGIOS7 	/* bit 6 */
#define SEGIOS8   	LCDIOS2bits.SEGIOS8 	/* bit 7 */

#endif
