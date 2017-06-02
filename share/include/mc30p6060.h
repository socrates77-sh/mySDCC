#ifndef MC30P6060_H
#define MC30P6060_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR       	0x0000
#define T0CNT_ADDR      	0x0001
#define PCL_ADDR        	0x0002
#define STATUS_ADDR     	0x0003
#define FSR_ADDR        	0x0004
#define P0_ADDR         	0x0005
#define P1_ADDR         	0x0006
#define MCR_ADDR        	0x0008
#define KBIM_ADDR       	0x0009
#define PCLATH_ADDR     	0x000A
#define PDCON_ADDR      	0x000B
#define ODCON_ADDR      	0x000C
#define PUCON_ADDR      	0x000D
#define INTECON_ADDR    	0x000E
#define INTFLAG_ADDR    	0x000F
#define T0CR_ADDR       	0x0041
#define DDR0_ADDR       	0x0045
#define DDR1_ADDR       	0x0046
#define PWMCR_ADDR       	0x0048
#define T1DATA1_ADDR		0x0049
#define T1DATA2_ADDR		0x004A
#define TM0CR_ADDR       	0x004B
#define T1CR_ADDR       	0x004C
#define T1CNT_ADDR      	0x004D
#define T1LOAD_ADDR     	0x004E
#define T1DATA0_ADDR     	0x004F

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)     	INDF;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (FSR_ADDR)      	FSR;
extern __sfr __at (P0_ADDR)       	P0;
extern __sfr __at (P1_ADDR)       	P1;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (KBIM_ADDR)     	KBIM;
extern __sfr __at (PCLATH_ADDR)   	PCLATH;
extern __sfr __at (PDCON_ADDR)    	PDCON;
extern __sfr __at (ODCON_ADDR)    	ODCON;
extern __sfr __at (PUCON_ADDR)    	PUCON;
extern __sfr __at (INTECON_ADDR)  	INTECON;
extern __sfr __at (INTFLAG_ADDR)  	INTFLAG;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (DDR0_ADDR)     	DDR0;
extern __sfr __at (DDR1_ADDR)     	DDR1;
extern __sfr __at (PWMCR_ADDR)     	PWMCR;
extern __sfr __at (T1DATA1_ADDR)	T1DATA1;
extern __sfr __at (T1DATA2_ADDR)	T1DATA2;
extern __sfr __at (TM0CR_ADDR)     	TM0CR;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1CNT_ADDR)    	T1CNT;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (T1DATA0_ADDR)   	T1DATA0;


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

#define INDF0       INDFbits.INDF0      /* bit 0 */
#define INDF1       INDFbits.INDF1      /* bit 1 */
#define INDF2       INDFbits.INDF2      /* bit 2 */
#define INDF3       INDFbits.INDF3      /* bit 3 */
#define INDF4       INDFbits.INDF4     	/* bit 4 */
#define INDF5       INDFbits.INDF5      /* bit 5 */
#define INDF6       INDFbits.INDF6     	/* bit 6 */
#define INDF7      	INDFbits.INDF7     	/* bit 7 */

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

#define PC0       PCLbits.PC0      /* bit 0 */
#define PC1       PCLbits.PC1      /* bit 1 */
#define PC2       PCLbits.PC2      /* bit 2 */
#define PC3       PCLbits.PC3      /* bit 3 */
#define PC4       PCLbits.PC4      /* bit 4 */
#define PC5       PCLbits.PC5      /* bit 5 */
#define PC6       PCLbits.PC6      /* bit 6 */
#define PC7      	PCLbits.PC7      /* bit 7 */

// ----- STATUS Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char C:1;
		unsigned char DC:1;
		unsigned char Z:1;
		unsigned char PD:1;
		unsigned char TO:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char RST:1;
	};
} __STATUSbits_t;
extern volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;

#define C         	STATUSbits.C        	/* bit 0 */
#define DC        	STATUSbits.DC       	/* bit 1 */
#define Z         	STATUSbits.Z        	/* bit 2 */
#define PD        	STATUSbits.PD       	/* bit 3 */
#define TO        	STATUSbits.TO       	/* bit 4 */
#define RST       	STATUSbits.RST      	/* bit 7 */

// ----- FSR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FSR0:1;
		unsigned char FSR1:1;
		unsigned char FSR2:1;
		unsigned char FSR3:1;
		unsigned char FSR4:1;
		unsigned char FSR5:1;
		unsigned char :1;
		unsigned char :1;
	};
} __FSRbits_t;
extern volatile __FSRbits_t __at(FSR_ADDR) FSRbits;

#define FSR0       FSRbits.FSR0      /* bit 0 */
#define FSR1       FSRbits.FSR1      /* bit 1 */
#define FSR2       FSRbits.FSR2      /* bit 2 */
#define FSR3       FSRbits.FSR3      /* bit 3 */
#define FSR4       FSRbits.FSR4      /* bit 4 */
#define FSR5       FSRbits.FSR5      /* bit 5 */

// ----- P0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00D:1;
		unsigned char P01D:1;
		unsigned char P02D:1;
		unsigned char P03D:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __P0bits_t;
extern volatile __P0bits_t __at(P0_ADDR) P0bits;

#define P00D       	P0bits.P00D          	/* bit 0 */
#define P01D       	P0bits.P01D          	/* bit 1 */
#define P02D       	P0bits.P02D          	/* bit 2 */
#define P03D       	P0bits.P03D          	/* bit 3 */

// ----- P1 Bits --------------------------------------------
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
} __P1bits_t;
extern volatile __P1bits_t __at(P1_ADDR) P1bits;

#define P10D       	P1bits.P10D          	/* bit 0 */
#define P11D       	P1bits.P11D          	/* bit 1 */
#define P12D       	P1bits.P12D          	/* bit 2 */
#define P13D       	P1bits.P13D          	/* bit 3 */
#define P14D       	P1bits.P14D          	/* bit 4 */
#define P15D       	P1bits.P15D          	/* bit 5 */
#define P16D       	P1bits.P16D          	/* bit 6 */
#define P17D       	P1bits.P17D          	/* bit 7 */

// ----- MCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LVDEN:1;
		unsigned char LVDSEL:4;
		unsigned char LVDF:1;
		unsigned char EIS:1;
		unsigned char WDTEN:1;
	};
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;

#define LVDEN     	MCRbits.LVDEN      	  /* bit 0 */
#define LVDSEL     	MCRbits.LVDSEL      	/* bit 1-4 */
#define LVDF     	  MCRbits.LVDF      	  /* bit 5 */
#define EIS       	MCRbits.EIS         	/* bit 6 */
#define WDTEN     	MCRbits.WDTEN       	/* bit 7 */

// ----- KBIM Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char KBIM0:1;
		unsigned char KBIM1:1;
		unsigned char KBIM2:1;
		unsigned char KBIM3:1;
		unsigned char KBIM4:1;
		unsigned char KBIM5:1;
		unsigned char :1;
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

// ----- PCLATH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PCH0:1;
		unsigned char PCH1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PCLATHbits_t;
extern volatile __PCLATHbits_t __at(PCLATH_ADDR) PCLATHbits;

#define PCH0       PCLATHbits.PCH0      /* bit 0 */
#define PCH1       PCLATHbits.PCH1      /* bit 1 */

// ----- PDCON Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P00PD:1;
		unsigned char P01PD:1;
		unsigned char P02PD:1;
		unsigned char P03PD:1;
		unsigned char P10PD:1;
		unsigned char P11PD:1;
		unsigned char P12PD:1;
		unsigned char :1;
	};
} __PDCONbits_t;
extern volatile __PDCONbits_t __at(PDCON_ADDR) PDCONbits;

#define P00PD     	PDCONbits.P00PD     	/* bit 0 */
#define P01PD     	PDCONbits.P01PD     	/* bit 1 */
#define P02PD     	PDCONbits.P02PD     	/* bit 2 */
#define P03PD     	PDCONbits.P03PD     	/* bit 3 */
#define P10PD     	PDCONbits.P10PD     	/* bit 4 */
#define P11PD     	PDCONbits.P11PD     	/* bit 5 */
#define P12PD     	PDCONbits.P12PD     	/* bit 6 */

// ----- ODCON Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10OD:1;
		unsigned char P11OD:1;
		unsigned char P12OD:1;
		unsigned char :1;
		unsigned char P14OD:1;
		unsigned char P15OD:1;
		unsigned char P16OD:1;
		unsigned char P17OD:1;
	};
} __ODCONbits_t;
extern volatile __ODCONbits_t __at(ODCON_ADDR) ODCONbits;

#define P10OD     	ODCONbits.P10OD     	/* bit 0 */
#define P11OD     	ODCONbits.P11OD     	/* bit 1 */
#define P12OD     	ODCONbits.P12OD     	/* bit 2 */
#define P14OD     	ODCONbits.P14OD     	/* bit 4 */
#define P15OD     	ODCONbits.P15OD     	/* bit 5 */
#define P16OD     	ODCONbits.P16OD     	/* bit 6 */
#define P17OD     	ODCONbits.P17OD     	/* bit 7 */

// ----- PUCON Bits --------------------------------------------
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
} __PUCONbits_t;
extern volatile __PUCONbits_t __at(PUCON_ADDR) PUCONbits;

#define P10PU     	PUCONbits.P10PU     	/* bit 0 */
#define P11PU     	PUCONbits.P11PU     	/* bit 1 */
#define P12PU     	PUCONbits.P12PU     	/* bit 2 */
#define P13PU     	PUCONbits.P13PU     	/* bit 3 */
#define P14PU     	PUCONbits.P14PU     	/* bit 4 */
#define P15PU     	PUCONbits.P15PU     	/* bit 5 */
#define P16PU     	PUCONbits.P16PU     	/* bit 6 */
#define P17PU     	PUCONbits.P17PU     	/* bit 7 */

// ----- INTECON Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char KBIE:1;
		unsigned char INTIE:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char GIE:1;
	};
} __INTECONbits_t;
extern volatile __INTECONbits_t __at(INTECON_ADDR) INTECONbits;

#define T0IE      	INTECONbits.T0IE    	/* bit 0 */
#define KBIE      	INTECONbits.KBIE    	/* bit 1 */
#define INTIE    	  INTECONbits.INTIE  	  /* bit 2 */
#define GIE       	INTECONbits.GIE     	/* bit 7 */

// ----- INTFLAG Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char KBIF:1;
		unsigned char INTIF:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __INTFLAGbits_t;
extern volatile __INTFLAGbits_t __at(INTFLAG_ADDR) INTFLAGbits;

#define T0IF      	INTFLAGbits.T0IF    	/* bit 0 */
#define KBIF      	INTFLAGbits.KBIF    	/* bit 1 */
#define INTIF    	  INTFLAGbits.INTIF  	  /* bit 2 */

// ----- T0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0PR:3;
		unsigned char T0PTA:1;
		unsigned char T0SE:1;
		unsigned char T0PTS:1;
		unsigned char INTOM:1;
		unsigned char :1;
	};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;

#define T0PR      	T0CRbits.T0PR       	/* bit 2-0 */
#define T0PTA     	T0CRbits.T0PTA      	/* bit 3 */
#define T0SE      	T0CRbits.T0SE       	/* bit 4 */
#define T0PTS     	T0CRbits.T0PTS      	/* bit 5 */
#define INTOM     	T0CRbits.INTOM      	/* bit 6 */

// ----- TM0CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1IF:1;
		unsigned char T1IE:1;
		unsigned char :1;
		unsigned char :1;  
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char TBS:1;
	};
} __TM0CRbits_t;
extern volatile __TM0CRbits_t __at(TM0CR_ADDR) TM0CRbits;

#define T1IF      	TM0CRbits.T1IF       	/* bit 0 */
#define T1IE     	  TM0CRbits.T1IE      	/* bit 1 */
#define TBS      	  TM0CRbits.TBS       	/* bit 7 */

// ----- T0CNT Bits --------------------------------------------
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
} __T0CNTbits_t;
extern volatile __T0CNTbits_t __at(T0CNT_ADDR) T0CNTbits;

#define T0C0     	  T0CNTbits.T0C0     	  /* bit 0 */
#define T0C1     	  T0CNTbits.T0C1     	  /* bit 1 */
#define T0C2     	  T0CNTbits.T0C2     	  /* bit 2 */
#define T0C3     	  T0CNTbits.T0C3     	  /* bit 3 */
#define T0C4     	  T0CNTbits.T0C4     	  /* bit 4 */
#define T0C5       	T0CNTbits.T0C5     	  /* bit 5 */
#define T0C6     	  T0CNTbits.T0C6     	  /* bit 6 */
#define T0C7     	  T0CNTbits.T0C7     	  /* bit 7 */

// ----- DDR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DDR00:1;
		unsigned char DDR01:1;
		unsigned char DDR02:1;
		unsigned char DDR03:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __DDR0bits_t;
extern volatile __DDR0bits_t __at(DDR0_ADDR) DDR0bits;

#define DDR00     	DDR0bits.DDR00      	/* bit 0 */
#define DDR01     	DDR0bits.DDR01      	/* bit 1 */
#define DDR02     	DDR0bits.DDR02      	/* bit 2 */
#define DDR03     	DDR0bits.DDR03      	/* bit 3 */

// ----- DDR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DDR10:1;
		unsigned char DDR11:1;
		unsigned char DDR12:1;
		unsigned char DDR13:1;
		unsigned char DDR14:1;
		unsigned char DDR15:1;
		unsigned char DDR16:1;
		unsigned char DDR17:1;
	};
} __DDR1bits_t;
extern volatile __DDR1bits_t __at(DDR1_ADDR) DDR1bits;

#define DDR10     	DDR1bits.DDR10      	/* bit 0 */
#define DDR11     	DDR1bits.DDR11      	/* bit 1 */
#define DDR12     	DDR1bits.DDR12      	/* bit 2 */
#define DDR13     	DDR1bits.DDR13      	/* bit 3 */
#define DDR14     	DDR1bits.DDR14      	/* bit 4 */
#define DDR15     	DDR1bits.DDR15      	/* bit 5 */
#define DDR16     	DDR1bits.DDR16      	/* bit 6 */
#define DDR17     	DDR1bits.DDR17      	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PR:3;
		unsigned char T1PTS:2;
		unsigned char BUZE:1;
		unsigned char PWM0E:1;
		unsigned char TC1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PR      	T1CRbits.T1PR       	/* bit 2-0 */
#define T1PTS     	T1CRbits.T1PTS      	/* bit 4-3 */
#define BUZE    	  T1CRbits.BUZE     	  /* bit 5 */
#define PWM0E    	  T1CRbits.PWM0E     	  /* bit 6 */
#define TC1EN    	  T1CRbits.TC1EN     	  /* bit 7 */

// ----- PWMCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PWM2E:1;
		unsigned char PWM1E:1;
		unsigned char PWMINV:1;
		unsigned char PWMMD:1;
		unsigned char DBLCK:1;
		unsigned char PWM2OE:1;
		unsigned char PWM1OE:1;
		unsigned char PMW0OE:1;
	};
} __PWMCRbits_t;
extern volatile __PWMCRbits_t __at(PWMCR_ADDR) PWMCRbits;

#define PWM2E     	PWMCRbits.PWM2E      	/* bit 0 */
#define PWM1E     	PWMCRbits.PWM1E      	/* bit 1 */
#define PWMINV     	PWMCRbits.PWMINV     	/* bit 2 */
#define PWMMD     	PWMCRbits.PWMMD      	/* bit 3 */
#define DBLCK     	PWMCRbits.DBLCK      	/* bit 4 */
#define PWM2OE     	PWMCRbits.PWM2OE     	/* bit 5 */
#define PWM1OE     	PWMCRbits.PWM1OE     	/* bit 6 */
#define PMW0OE     	PWMCRbits.PMW0OE     	/* bit 7 */

// ----- T1CNT Bits --------------------------------------------
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
} __T1CNTbits_t;
extern volatile __T1CNTbits_t __at(T1CNT_ADDR) T1CNTbits;

#define T1C0     	  T1CNTbits.T1C0     	  /* bit 0 */
#define T1C1     	  T1CNTbits.T1C1     	  /* bit 1 */
#define T1C2     	  T1CNTbits.T1C2     	  /* bit 2 */
#define T1C3     	  T1CNTbits.T1C3     	  /* bit 3 */
#define T1C4     	  T1CNTbits.T1C4     	  /* bit 4 */
#define T1C5       	T1CNTbits.T1C5     	  /* bit 5 */
#define T1C6     	  T1CNTbits.T1C6     	  /* bit 6 */
#define T1C7     	  T1CNTbits.T1C7     	  /* bit 7 */

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

#define T1LOAD0     T1LOADbits.T1LOAD0    /* bit 0 */
#define T1LOAD1     T1LOADbits.T1LOAD1    /* bit 1 */
#define T1LOAD2     T1LOADbits.T1LOAD2    /* bit 2 */
#define T1LOAD3     T1LOADbits.T1LOAD3    /* bit 3 */
#define T1LOAD4     T1LOADbits.T1LOAD4    /* bit 4 */
#define T1LOAD5     T1LOADbits.T1LOAD5    /* bit 5 */
#define T1LOAD6     T1LOADbits.T1LOAD6    /* bit 6 */
#define T1LOAD7     T1LOADbits.T1LOAD7    /* bit 7 */

// ----- T1DATA0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1DATA00:1;
		unsigned char T1DATA01:1;
		unsigned char T1DATA02:1;
		unsigned char T1DATA03:1;
		unsigned char T1DATA04:1;
		unsigned char T1DATA05:1;
		unsigned char T1DATA06:1;
		unsigned char T1DATA07:1;
	};
} __T1DATA0bits_t;
extern volatile __T1DATA0bits_t __at(T1DATA0_ADDR) T1DATA0bits;

#define T1DATA00     T1DATA0bits.T1DATA00    /* bit 0 */
#define T1DATA01     T1DATA0bits.T1DATA01    /* bit 1 */
#define T1DATA02     T1DATA0bits.T1DATA02    /* bit 2 */
#define T1DATA03     T1DATA0bits.T1DATA03    /* bit 3 */
#define T1DATA04     T1DATA0bits.T1DATA04    /* bit 4 */
#define T1DATA05     T1DATA0bits.T1DATA05    /* bit 5 */
#define T1DATA06     T1DATA0bits.T1DATA06    /* bit 6 */
#define T1DATA07     T1DATA0bits.T1DATA07    /* bit 7 */

// ----- T1DATA1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1DATA10:1;
		unsigned char T1DATA11:1;
		unsigned char T1DATA12:1;
		unsigned char T1DATA13:1;
		unsigned char T1DATA14:1;
		unsigned char T1DATA15:1;
		unsigned char T1DATA16:1;
		unsigned char T1DATA17:1;
	};
} __T1DATA1bits_t;
extern volatile __T1DATA1bits_t __at(T1DATA1_ADDR) T1DATA1bits;

#define T1DATA10     T1DATA1bits.T1DATA10    /* bit 0 */
#define T1DATA11     T1DATA1bits.T1DATA11    /* bit 1 */
#define T1DATA12     T1DATA1bits.T1DATA12    /* bit 2 */
#define T1DATA13     T1DATA1bits.T1DATA13    /* bit 3 */
#define T1DATA14     T1DATA1bits.T1DATA14    /* bit 4 */
#define T1DATA15     T1DATA1bits.T1DATA15    /* bit 5 */
#define T1DATA16     T1DATA1bits.T1DATA16    /* bit 6 */
#define T1DATA17     T1DATA1bits.T1DATA17    /* bit 7 */

// ----- T1DATA2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1DATA20:1;
		unsigned char T1DATA21:1;
		unsigned char T1DATA22:1;
		unsigned char T1DATA23:1;
		unsigned char T1DATA24:1;
		unsigned char T1DATA25:1;
		unsigned char T1DATA26:1;
		unsigned char T1DATA27:1;
	};
} __T1DATA2bits_t;
extern volatile __T1DATA2bits_t __at(T1DATA2_ADDR) T1DATA2bits;

#define T1DATA20     T1DATA2bits.T1DATA20    /* bit 0 */
#define T1DATA21     T1DATA2bits.T1DATA21    /* bit 1 */
#define T1DATA22     T1DATA2bits.T1DATA22    /* bit 2 */
#define T1DATA23     T1DATA2bits.T1DATA23    /* bit 3 */
#define T1DATA24     T1DATA2bits.T1DATA24    /* bit 4 */
#define T1DATA25     T1DATA2bits.T1DATA25    /* bit 5 */
#define T1DATA26     T1DATA2bits.T1DATA26    /* bit 6 */
#define T1DATA27     T1DATA2bits.T1DATA27    /* bit 7 */

#endif
