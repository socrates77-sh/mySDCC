#ifndef MC32P21_H
#define MC32P21_H

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
#define MCR_ADDR        	0x0188
#define INDF3_ADDR      	0x0189
#define INTE_ADDR       	0x018A
#define INTF_ADDR       	0x018B
#define IOP0_ADDR       	0x0190
#define OEP0_ADDR       	0x0191
#define PUP0_ADDR       	0x0192
#define ANSEL_ADDR      	0x0193
#define IOP1_ADDR       	0x0194
#define OEP1_ADDR       	0x0195
#define PUP1_ADDR       	0x0196
#define KBIM_ADDR       	0x0197
#define T0CR_ADDR       	0x01A0
#define T0CNT_ADDR      	0x01A1
#define T0LOAD_ADDR     	0x01A2
#define T0DATA_ADDR     	0x01A3
#define T1CR_ADDR       	0x01A4
#define T1CNT_ADDR      	0x01A5
#define T1LOAD_ADDR     	0x01A6
#define T1DATA_ADDR     	0x01A7
#define LVDCR_ADDR      	0x01AD
#define OSCM_ADDR       	0x01AE
#define ADCR0_ADDR      	0x01B0
#define ADCR1_ADDR      	0x01B1
#define ADRH_ADDR       	0x01B4
#define ADRL_ADDR       	0x01B5
#define OSCAL_ADDR      	0x01FB

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
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (ANSEL_ADDR)    	ANSEL;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (KBIM_ADDR)     	KBIM;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T1DATA_ADDR)   	T1DATA;
extern __sfr __at (LVDCR_ADDR)    	LVDCR;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADRH_ADDR)     	ADRH;
extern __sfr __at (ADRL_ADDR)     	ADRL;
extern __sfr __at (OSCAL_ADDR)    	OSCAL;

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
		unsigned char KBIE:1;
		unsigned char :1;
		unsigned char ADIE:1;
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define KBIE      	INTEbits.KBIE       	/* bit 4 */
#define ADIE      	INTEbits.ADIE       	/* bit 6 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char KBIF:1;
		unsigned char :1;
		unsigned char ADIF:1;
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define KBIF      	INTFbits.KBIF       	/* bit 4 */
#define ADIF      	INTFbits.ADIF       	/* bit 6 */

// ----- IOP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00:1;
		unsigned char P01:1;
		unsigned char P02:1;
		unsigned char P03:1;
		unsigned char P04:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define P00       	IOP0bits.P00        	/* bit 0 */
#define P01       	IOP0bits.P01        	/* bit 1 */
#define P02       	IOP0bits.P02        	/* bit 2 */
#define P03       	IOP0bits.P03        	/* bit 3 */
#define P04       	IOP0bits.P04        	/* bit 4 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00OE:1;
		unsigned char P01OE:1;
		unsigned char P02OE:1;
		unsigned char P03OE:1;
		unsigned char P04OE:1;
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
#define P04OE     	OEP0bits.P04OE      	/* bit 4 */

// ----- PUP0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00PU:1;
		unsigned char P01PU:1;
		unsigned char P02PU:1;
		unsigned char P03PU:1;
		unsigned char P04PU:1;
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
#define P04PU     	PUP0bits.P04PU      	/* bit 4 */

// ----- ANSEL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00ANS:1;
		unsigned char P01ANS:1;
		unsigned char P02ANS:1;
		unsigned char P03ANS:1;
		unsigned char P04ANS:1;
		unsigned char P12ANS:1;
		unsigned char P13ANS:1;
		unsigned char :1;
	};
} __ANSELbits_t;
extern volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;

#define P00ANS    	ANSELbits.P00ANS    	/* bit 0 */
#define P01ANS    	ANSELbits.P01ANS    	/* bit 1 */
#define P02ANS    	ANSELbits.P02ANS    	/* bit 2 */
#define P03ANS    	ANSELbits.P03ANS    	/* bit 3 */
#define P04ANS    	ANSELbits.P04ANS    	/* bit 4 */
#define P12ANS    	ANSELbits.P12ANS    	/* bit 5 */
#define P13ANS    	ANSELbits.P13ANS    	/* bit 6 */

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
		unsigned char :1;
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
#define P16OE     	OEP1bits.P16OE      	/* bit 6 */

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
#define P16PU     	PUP1bits.P16PU      	/* bit 6 */

// ----- KBIM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char KBIM0:1;
		unsigned char KBIM1:1;
		unsigned char KBIM2:1;
		unsigned char KBIM3:1;
		unsigned char KBIM4:1;
		unsigned char KBIM5:1;
		unsigned char KBIM6:1;
		unsigned char :1;
	};
} __KBIMbits_t;
extern volatile __KBIMbits_t __at(KBIM_ADDR) KBIMbits;

#define KBIM0     	KBIMbits.KBIM0      	/* bit 0 */
#define KBIM1     	KBIMbits.KBIM1      	/* bit 1 */
#define KBIM2     	KBIMbits.KBIM2      	/* bit 2 */
#define KBIM3     	KBIMbits.KBIM3      	/* bit 3 */
#define KBIM4     	KBIMbits.KBIM4      	/* bit 4 */
#define KBIM5     	KBIMbits.KBIM5      	/* bit 5 */
#define KBIM6     	KBIMbits.KBIM6      	/* bit 6 */

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

// ----- LVDCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LVDF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char LVDS:3;
		unsigned char LVDEN:1;
	};
} __LVDCRbits_t;
extern volatile __LVDCRbits_t __at(LVDCR_ADDR) LVDCRbits;

#define LVDF      	LVDCRbits.LVDF      	/* bit 0 */
#define LVDS      	LVDCRbits.LVDS      	/* bit 6-4 */
#define LVDEN     	LVDCRbits.LVDEN     	/* bit 7 */

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
		unsigned char VSR:3;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define VSR       	ADCR1bits.VSR       	/* bit 2-0 */

#endif
