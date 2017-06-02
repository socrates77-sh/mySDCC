#ifndef MC32P64_H
#define MC32P64_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x01B0
#define INDF0_ADDR      	0x01B0
#define INDF1_ADDR      	0x01B1
#define INDF2_ADDR      	0x01B2
#define HIBYTE_ADDR     	0x01B3
#define FSR_ADDR        	0x01B4
#define FSR0_ADDR       	0x01B4
#define FSR1_ADDR       	0x01B5
#define PCL_ADDR        	0x01B6
#define STATUS_ADDR     	0x01B7
#define MCR_ADDR        	0x01B8
#define INDF3_ADDR      	0x01B9
#define INTE_ADDR       	0x01BA
#define INTF_ADDR       	0x01BB
#define OSCM_ADDR       	0x01BC
#define IOP0_ADDR       	0x01C0
#define OEP0_ADDR       	0x01C1
#define PUP0_ADDR       	0x01C2
#define IOP1_ADDR       	0x01C4
#define OEP1_ADDR       	0x01C5
#define PUP1_ADDR       	0x01C6
#define IOP2_ADDR       	0x01C8
#define OEP2_ADDR       	0x01C9
#define PUP2_ADDR       	0x01CA
#define IOP3_ADDR       	0x01CC
#define OEP3_ADDR       	0x01CD
#define PUP3_ADDR       	0x01CE
#define T0CR_ADDR       	0x01D0
#define T0CNT_ADDR      	0x01D1
#define T0LOAD_ADDR     	0x01D2
#define T0DATA_ADDR     	0x01D3
#define T1CR_ADDR       	0x01D4
#define T1CNT_ADDR      	0x01D5
#define T1LOAD_ADDR     	0x01D6
#define T1DATA_ADDR     	0x01D7
#define T2CR_ADDR       	0x01D8
#define T2CNTH_ADDR     	0x01D9
#define T2CNTL_ADDR     	0x01DA
#define T2LOADH_ADDR    	0x01DB
#define T2LOADL_ADDR    	0x01DC
#define TK0CRH_ADDR     	0x01E0
#define TK0CRL_ADDR     	0x01E1
#define TK0CNTH_ADDR    	0x01E2
#define TK0CNTL_ADDR    	0x01E3
#define TK1CRH_ADDR     	0x01E4
#define TK1CRL_ADDR     	0x01E5
#define TK1CNTH_ADDR    	0x01E6
#define TK1CNTL_ADDR    	0x01E7
#define TK2CRH_ADDR     	0x01E8
#define TK2CRL_ADDR     	0x01E9
#define TK2CNTH_ADDR    	0x01EA
#define TK2CNTL_ADDR    	0x01EB
#define ADCR0_ADDR      	0x01EC
#define ADCR1_ADDR      	0x01ED
#define ADRH_ADDR       	0x01EE
#define ADRL_ADDR       	0x01EF
#define I2CCR_ADDR      	0x01F0
#define I2CADDR_ADDR    	0x01F1
#define I2CDATA_ADDR    	0x01F2

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
extern __sfr __at (T2CR_ADDR)     	T2CR;
extern __sfr __at (T2CNTH_ADDR)   	T2CNTH;
extern __sfr __at (T2CNTL_ADDR)   	T2CNTL;
extern __sfr __at (T2LOADH_ADDR)  	T2LOADH;
extern __sfr __at (T2LOADL_ADDR)  	T2LOADL;
extern __sfr __at (TK0CRH_ADDR)   	TK0CRH;
extern __sfr __at (TK0CRL_ADDR)   	TK0CRL;
extern __sfr __at (TK0CNTH_ADDR)  	TK0CNTH;
extern __sfr __at (TK0CNTL_ADDR)  	TK0CNTL;
extern __sfr __at (TK1CRH_ADDR)   	TK1CRH;
extern __sfr __at (TK1CRL_ADDR)   	TK1CRL;
extern __sfr __at (TK1CNTH_ADDR)  	TK1CNTH;
extern __sfr __at (TK1CNTL_ADDR)  	TK1CNTL;
extern __sfr __at (TK2CRH_ADDR)   	TK2CRH;
extern __sfr __at (TK2CRL_ADDR)   	TK2CRL;
extern __sfr __at (TK2CNTH_ADDR)  	TK2CNTH;
extern __sfr __at (TK2CNTL_ADDR)  	TK2CNTL;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (I2CCR_ADDR)    	I2CCR;
extern __sfr __at (I2CADDR_ADDR)  	I2CADDR;
extern __sfr __at (I2CDATA_ADDR)  	I2CDATA;

//==========================================================================
//
//	Configuration Bits
//
//==========================================================================

//OPBIT1

//OPBIT0
#define _CP_ALL         	0x7FFF
#define _WDT_ALWAYS_OFF 	0xFFFC
#define _WDT_SLEEP_OFF  	0xFFFD
#define _WDT_ALWAYS_ON  	0xFFFF
#define _PTWRT_4_4      	0xDFF3
#define _PTWRT_16_16    	0xDFF7
#define _PTWRT_64_64    	0xDFFB
#define _PTWRT_256_256  	0xDFFF
#define _PTWRT_4_512    	0xFFF3
#define _PTWRT_16_1024  	0xFFF7
#define _PTWRT_64_2048  	0xFFFB
#define _PTWRT_256_4096 	0xFFFF
#define _FCPU_2T        	0xFF8F
#define _FCPU_4T        	0xFF9F
#define _FCPU_8T        	0xFFAF
#define _FCPU_16T       	0xFFBF
#define _FCPU_32T       	0xFFCF
#define _FCPU_64T       	0xFFDF
#define _FCPU_128T      	0xFFEF
#define _FCPU_256T      	0xFFFF
#define _MCLR_ON        	0xFFFF
#define _MCLR_OFF       	0xFF7F
#define _HRC_LRC        	0xFCFF
#define _HRC_LXT        	0xFDFF
#define _HXT_LRC        	0xFEFF
#define _VLVR_160       	0xE3FF
#define _VLVR_185       	0xE7FF
#define _VLVR_205       	0xEBFF
#define _VLVR_218       	0xEFFF
#define _VLVR_232       	0xF3FF
#define _VLVR_245       	0xF7FF
#define _VLVR_305       	0xFBFF
#define _VLVR_360       	0xFFFF

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

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char T2IE:1;
		unsigned char I2CIE:1;
		unsigned char ADIE:1;
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define T2IE      	INTEbits.T2IE       	/* bit 4 */
#define I2CIE     	INTEbits.I2CIE      	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char T2IF:1;
		unsigned char I2CIF:1;
		unsigned char ADIF:1;
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define T2IF      	INTFbits.T2IF       	/* bit 4 */
#define I2CIF     	INTFbits.I2CIF      	/* bit 5 */
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
		unsigned char P00:1;
		unsigned char P01:1;
		unsigned char P02:1;
		unsigned char P03:1;
		unsigned char P04:1;
		unsigned char P05:1;
		unsigned char P06:1;
		unsigned char P07:1;
	};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define P00       	IOP0bits.P00        	/* bit 0 */
#define P01       	IOP0bits.P01        	/* bit 1 */
#define P02       	IOP0bits.P02        	/* bit 2 */
#define P03       	IOP0bits.P03        	/* bit 3 */
#define P04       	IOP0bits.P04        	/* bit 4 */
#define P05       	IOP0bits.P05        	/* bit 5 */
#define P06       	IOP0bits.P06        	/* bit 6 */
#define P07       	IOP0bits.P07        	/* bit 7 */

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
		unsigned char P10:1;
		unsigned char P11:1;
		unsigned char P12:1;
		unsigned char P13:1;
		unsigned char P14:1;
		unsigned char P15:1;
		unsigned char P16:1;
		unsigned char P17:1;
	};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define P10       	IOP1bits.P10        	/* bit 0 */
#define P11       	IOP1bits.P11        	/* bit 1 */
#define P12       	IOP1bits.P12        	/* bit 2 */
#define P13       	IOP1bits.P13        	/* bit 3 */
#define P14       	IOP1bits.P14        	/* bit 4 */
#define P15       	IOP1bits.P15        	/* bit 5 */
#define P16       	IOP1bits.P16        	/* bit 6 */
#define P17       	IOP1bits.P17        	/* bit 7 */

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
		unsigned char P20:1;
		unsigned char P21:1;
		unsigned char P22:1;
		unsigned char P23:1;
		unsigned char P24:1;
		unsigned char P25:1;
		unsigned char P26:1;
		unsigned char P27:1;
	};
} __IOP2bits_t;
extern volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;

#define P20       	IOP2bits.P20        	/* bit 0 */
#define P21       	IOP2bits.P21        	/* bit 1 */
#define P22       	IOP2bits.P22        	/* bit 2 */
#define P23       	IOP2bits.P23        	/* bit 3 */
#define P24       	IOP2bits.P24        	/* bit 4 */
#define P25       	IOP2bits.P25        	/* bit 5 */
#define P26       	IOP2bits.P26        	/* bit 6 */
#define P27       	IOP2bits.P27        	/* bit 7 */

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
		unsigned char P30:1;
		unsigned char P31:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP3bits_t;
extern volatile __IOP3bits_t __at(IOP3_ADDR) IOP3bits;

#define P30       	IOP3bits.P30        	/* bit 0 */
#define P31       	IOP3bits.P31        	/* bit 1 */

// ----- OEP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30OE:1;
		unsigned char P31OE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __OEP3bits_t;
extern volatile __OEP3bits_t __at(OEP3_ADDR) OEP3bits;

#define P30OE     	OEP3bits.P30OE      	/* bit 0 */
#define P31OE     	OEP3bits.P31OE      	/* bit 1 */

// ----- PUP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30PU:1;
		unsigned char P31PU:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP3bits_t;
extern volatile __PUP3bits_t __at(PUP3_ADDR) PUP3bits;

#define P30PU     	PUP3bits.P30PU      	/* bit 0 */
#define P31PU     	PUP3bits.P31PU      	/* bit 1 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0PR:3;
		unsigned char T0PS:2;
		unsigned char BUZ0OE:1;
		unsigned char PWM0OE:1;
		unsigned char TC0EN:1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define T0PR      	T0CRbits.T0PR       	/* bit 2-0 */
#define T0PS      	T0CRbits.T0PS       	/* bit 4-3 */
#define BUZ0OE    	T0CRbits.BUZ0OE     	/* bit 5 */
#define PWM0OE    	T0CRbits.PWM0OE     	/* bit 6 */
#define TC0EN     	T0CRbits.TC0EN      	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PR:3;
		unsigned char T1PS:2;
		unsigned char BUZ1OE:1;
		unsigned char PWM1OE:1;
		unsigned char TC1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PR      	T1CRbits.T1PR       	/* bit 2-0 */
#define T1PS      	T1CRbits.T1PS       	/* bit 4-3 */
#define BUZ1OE    	T1CRbits.BUZ1OE     	/* bit 5 */
#define PWM1OE    	T1CRbits.PWM1OE     	/* bit 6 */
#define TC1EN     	T1CRbits.TC1EN      	/* bit 7 */

// ----- T2CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2PR:3;
		unsigned char T2PS:2;
		unsigned char T2MOD:1;
		unsigned char :1;
		unsigned char TC2EN:1;
	};
} __T2CRbits_t;
extern volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;

#define T2PR      	T2CRbits.T2PR       	/* bit 2-0 */
#define T2PS      	T2CRbits.T2PS       	/* bit 4-3 */
#define T2MOD     	T2CRbits.T2MOD      	/* bit 5 */
#define TC2EN     	T2CRbits.TC2EN      	/* bit 7 */

// ----- TK0CRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK0FQ:3;
		unsigned char TK0CLR:1;
		unsigned char TK0RCE:1;
		unsigned char TK0JE:1;
		unsigned char TK0K:2;
	};
} __TK0CRHbits_t;
extern volatile __TK0CRHbits_t __at(TK0CRH_ADDR) TK0CRHbits;

#define TK0FQ     	TK0CRHbits.TK0FQ    	/* bit 2-0 */
#define TK0CLR    	TK0CRHbits.TK0CLR   	/* bit 3 */
#define TK0RCE    	TK0CRHbits.TK0RCE   	/* bit 4 */
#define TK0JE     	TK0CRHbits.TK0JE    	/* bit 5 */
#define TK0K      	TK0CRHbits.TK0K     	/* bit 7-6 */

// ----- TK0CRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK0IO:4;
		unsigned char TK0FL:2;
		unsigned char TK0IE:1;
		unsigned char TK0IF:1;
	};
} __TK0CRLbits_t;
extern volatile __TK0CRLbits_t __at(TK0CRL_ADDR) TK0CRLbits;

#define TK0IO     	TK0CRLbits.TK0IO    	/* bit 3-0 */
#define TK0FL     	TK0CRLbits.TK0FL    	/* bit 5-4 */
#define TK0IE     	TK0CRLbits.TK0IE    	/* bit 6 */
#define TK0IF     	TK0CRLbits.TK0IF    	/* bit 7 */

// ----- TK1CRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK1FQ:3;
		unsigned char TK1CLR:1;
		unsigned char TK1RCE:1;
		unsigned char TK1JE:1;
		unsigned char TK1K:2;
	};
} __TK1CRHbits_t;
extern volatile __TK1CRHbits_t __at(TK1CRH_ADDR) TK1CRHbits;

#define TK1FQ     	TK1CRHbits.TK1FQ    	/* bit 2-0 */
#define TK1CLR    	TK1CRHbits.TK1CLR   	/* bit 3 */
#define TK1RCE    	TK1CRHbits.TK1RCE   	/* bit 4 */
#define TK1JE     	TK1CRHbits.TK1JE    	/* bit 5 */
#define TK1K      	TK1CRHbits.TK1K     	/* bit 7-6 */

// ----- TK1CRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK1IO:4;
		unsigned char TK1FL:2;
		unsigned char TK1IE:1;
		unsigned char TK1IF:1;
	};
} __TK1CRLbits_t;
extern volatile __TK1CRLbits_t __at(TK1CRL_ADDR) TK1CRLbits;

#define TK1IO     	TK1CRLbits.TK1IO    	/* bit 3-0 */
#define TK1FL     	TK1CRLbits.TK1FL    	/* bit 5-4 */
#define TK1IE     	TK1CRLbits.TK1IE    	/* bit 6 */
#define TK1IF     	TK1CRLbits.TK1IF    	/* bit 7 */

// ----- TK2CRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK2FQ:3;
		unsigned char TK2CLR:1;
		unsigned char TK2RCE:1;
		unsigned char TK2JE:1;
		unsigned char TK2K:2;
	};
} __TK2CRHbits_t;
extern volatile __TK2CRHbits_t __at(TK2CRH_ADDR) TK2CRHbits;

#define TK2FQ     	TK2CRHbits.TK2FQ    	/* bit 2-0 */
#define TK2CLR    	TK2CRHbits.TK2CLR   	/* bit 3 */
#define TK2RCE    	TK2CRHbits.TK2RCE   	/* bit 4 */
#define TK2JE     	TK2CRHbits.TK2JE    	/* bit 5 */
#define TK2K      	TK2CRHbits.TK2K     	/* bit 7-6 */

// ----- TK2CRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK2IO:4;
		unsigned char TK2FL:2;
		unsigned char TK2IE:1;
		unsigned char TK2IF:1;
	};
} __TK2CRLbits_t;
extern volatile __TK2CRLbits_t __at(TK2CRL_ADDR) TK2CRLbits;

#define TK2IO     	TK2CRLbits.TK2IO    	/* bit 3-0 */
#define TK2FL     	TK2CRLbits.TK2FL    	/* bit 5-4 */
#define TK2IE     	TK2CRLbits.TK2IE    	/* bit 6 */
#define TK2IF     	TK2CRLbits.TK2IF    	/* bit 7 */

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
		unsigned char ADIOS0:1;
		unsigned char ADIOS1:1;
		unsigned char ADOIS2:1;
		unsigned char ADIOS3:1;
		unsigned char ADIOS4:1;
		unsigned char ADIOS5:1;
		unsigned char ADOIS6:1;
		unsigned char ADIOS7:1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define ADIOS0    	ADCR1bits.ADIOS0    	/* bit 0 */
#define ADIOS1    	ADCR1bits.ADIOS1    	/* bit 1 */
#define ADOIS2    	ADCR1bits.ADOIS2    	/* bit 2 */
#define ADIOS3    	ADCR1bits.ADIOS3    	/* bit 3 */
#define ADIOS4    	ADCR1bits.ADIOS4    	/* bit 4 */
#define ADIOS5    	ADCR1bits.ADIOS5    	/* bit 5 */
#define ADOIS6    	ADCR1bits.ADOIS6    	/* bit 6 */
#define ADIOS7    	ADCR1bits.ADIOS7    	/* bit 7 */

// ----- I2CCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char RXAK:1;
		unsigned char HEN:1;
		unsigned char SRW:1;
		unsigned char TXAK:1;
		unsigned char HTX:1;
		unsigned char HBB:1;
		unsigned char HAAS:1;
		unsigned char HCF:1;
	};
} __I2CCRbits_t;
extern volatile __I2CCRbits_t __at(I2CCR_ADDR) I2CCRbits;

#define RXAK      	I2CCRbits.RXAK      	/* bit 0 */
#define HEN       	I2CCRbits.HEN       	/* bit 1 */
#define SRW       	I2CCRbits.SRW       	/* bit 2 */
#define TXAK      	I2CCRbits.TXAK      	/* bit 3 */
#define HTX       	I2CCRbits.HTX       	/* bit 4 */
#define HBB       	I2CCRbits.HBB       	/* bit 5 */
#define HAAS      	I2CCRbits.HAAS      	/* bit 6 */
#define HCF       	I2CCRbits.HCF       	/* bit 7 */

#endif
