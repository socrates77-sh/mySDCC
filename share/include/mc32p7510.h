#ifndef _MC32P7510_H_
#define _MC32P7510_H_

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR		0x180
#define INDF0_ADDR		0x180
#define INDF1_ADDR		0x181
#define INDF2_ADDR		0x182
#define HIBYTE_ADDR		0x183
#define FSR_ADDR		0x184
#define FSR0_ADDR		0x184
#define FSR1_ADDR		0x185
#define PCL_ADDR		0x186
#define STATUS_ADDR		0x187
#define PFLAG_ADDR		0x187
 
#define MCR_ADDR		0x188
#define INDF3_ADDR		0x189
#define INTE_ADDR		0x18A
#define INTF_ADDR		0x18B

#define IOP0_ADDR		0x190
#define OEP0_ADDR		0x191
#define PUP0_ADDR		0x192
#define PDP0_ADDR		0x193
#define IOP1_ADDR		0x194
#define OEP1_ADDR		0x195
#define PUP1_ADDR		0x196
#define PDP1_ADDR		0x197

#define T0CR_ADDR		0x1A0
#define T0CNT_ADDR		0x1A1
#define T0LOAD_ADDR		0X1A2
#define T0DATA_ADDR		0X1A3
#define T1CR_ADDR		0X1A4
#define T1CNT_ADDR		0X1A5
#define T1LOAD_ADDR		0X1A6
#define T1DATA_ADDR		0X1A7

#define AUCR_ADDR		0X1A8
#define KBCR_ADDR		0X1A9

#define OSCM_ADDR		0X1AE
#define LVDCR_ADDR		0X1AF

#define ADCR0_ADDR		0X1B0
#define ADCR1_ADDR		0X1B1
#define AN0SEL_ADDR		0X1B2
#define AN1SEL_ADDR		0X1B3
#define ADRH_ADDR		0X1B4
#define ADRL_ADDR		0X1B5

#define OSCCAL_ADDR		0X1FB


//----- Register Files -----------------------------------------------------
extern __sfr __at (INDF_ADDR)		INDF;
extern __sfr __at (INDF0_ADDR)		INDF0;
extern __sfr __at (INDF1_ADDR)		INDF1;
extern __sfr __at (INDF2_ADDR)		INDF2;
extern __sfr __at (HIBYTE_ADDR)		HIBYTE;
extern __sfr __at (FSR_ADDR)		FSR;
extern __sfr __at (FSR0_ADDR)		FSR0;
extern __sfr __at (FSR1_ADDR)		FSR1;
extern __sfr __at (PCL_ADDR)		PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (PFLAG_ADDR)		PFLAG;
extern __sfr __at (MCR_ADDR)		MCR;
extern __sfr __at (INDF3_ADDR)		INDF3;
extern __sfr __at (INTE_ADDR)		INTE;
extern __sfr __at (INTF_ADDR)		INTF;

extern __sfr __at (IOP0_ADDR)		IOP0;
extern __sfr __at (OEP0_ADDR)		OEP0;
extern __sfr __at (PUP0_ADDR)		PUP0;
extern __sfr __at (PDP0_ADDR)		PDP0;
extern __sfr __at (IOP1_ADDR)		IOP1;
extern __sfr __at (OEP1_ADDR)		OEP1;
extern __sfr __at (PUP1_ADDR)		PUP1;
extern __sfr __at (PDP1_ADDR)		PDP1;

extern __sfr __at (T0CR_ADDR)		T0CR;
extern __sfr __at (T0CNT_ADDR)		T0CNT;
extern __sfr __at (T0LOAD_ADDR)		T0LOAD;
extern __sfr __at (T0DATA_ADDR)		T0DATA;
extern __sfr __at (T1CR_ADDR)		T1CR;
extern __sfr __at (T1CNT_ADDR)		T1CNT;
extern __sfr __at (T1LOAD_ADDR)		T1LOAD;
extern __sfr __at (T1DATA_ADDR)		T1DATA;

extern __sfr __at (AUCR_ADDR)		AUCR;
extern __sfr __at (KBCR_ADDR)		KBCR;

extern __sfr __at (OSCM_ADDR)		OSCM;
extern __sfr __at (LVDCR_ADDR)		LVDCR;

extern __sfr __at (ADCR0_ADDR)		ADCR0;
extern __sfr __at (ADCR1_ADDR)		ADCR1;
extern __sfr __at (AN0SEL_ADDR)		AN0SEL;
extern __sfr __at (AN1SEL_ADDR)		AN1SEL;
extern __sfr __at (ADRH_ADDR)		ADRH;
extern __sfr __at (ADRL_ADDR)		ADRL;

extern __sfr __at (OSCCAL_ADDR)		OSCCAL;

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

#define INDF00           INDF0bits.INDF00          /* bit 0 */
#define INDF01           INDF0bits.INDF01          /* bit 1 */
#define INDF02           INDF0bits.INDF02          /* bit 2 */
#define INDF03           INDF0bits.INDF03          /* bit 3 */
#define INDF04           INDF0bits.INDF04          /* bit 4 */
#define INDF05           INDF0bits.INDF05          /* bit 5 */
#define INDF06           INDF0bits.INDF06          /* bit 6 */
#define INDF07           INDF0bits.INDF07          /* bit 7 */

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

#define INDF10           INDF1bits.INDF10          /* bit 0 */
#define INDF11           INDF1bits.INDF11          /* bit 1 */
#define INDF12           INDF1bits.INDF12          /* bit 2 */
#define INDF13           INDF1bits.INDF13          /* bit 3 */
#define INDF14           INDF1bits.INDF14          /* bit 4 */
#define INDF15           INDF1bits.INDF15          /* bit 5 */
#define INDF16           INDF1bits.INDF16          /* bit 6 */
#define INDF17           INDF1bits.INDF17          /* bit 7 */

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

#define INDF20           INDF2bits.INDF20          /* bit 0 */
#define INDF21           INDF2bits.INDF21          /* bit 1 */
#define INDF22           INDF2bits.INDF22          /* bit 2 */
#define INDF23           INDF2bits.INDF23          /* bit 3 */
#define INDF24           INDF2bits.INDF24          /* bit 4 */
#define INDF25           INDF2bits.INDF25          /* bit 5 */
#define INDF26           INDF2bits.INDF26          /* bit 6 */
#define INDF27           INDF2bits.INDF27          /* bit 7 */

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

#define HIBYTE0           HIBYTEbits.HIBYTE0          /* bit 0 */
#define HIBYTE1           HIBYTEbits.HIBYTE1          /* bit 1 */
#define HIBYTE2           HIBYTEbits.HIBYTE2          /* bit 2 */
#define HIBYTE3           HIBYTEbits.HIBYTE3          /* bit 3 */
#define HIBYTE4           HIBYTEbits.HIBYTE4          /* bit 4 */
#define HIBYTE5           HIBYTEbits.HIBYTE5          /* bit 5 */
#define HIBYTE6           HIBYTEbits.HIBYTE6          /* bit 6 */
#define HIBYTE7           HIBYTEbits.HIBYTE7          /* bit 7 */

// ----- FSR0 Bits ---------------------------------------------
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

#define FSR00           FSR0bits.FSR00          /* bit 0 */
#define FSR01           FSR0bits.FSR01          /* bit 1 */
#define FSR02           FSR0bits.FSR02          /* bit 2 */
#define FSR03           FSR0bits.FSR03          /* bit 3 */
#define FSR04           FSR0bits.FSR04          /* bit 4 */
#define FSR05           FSR0bits.FSR05          /* bit 5 */
#define FSR06           FSR0bits.FSR06          /* bit 6 */
#define FSR07           FSR0bits.FSR07          /* bit 7 */

// ----- FSR1 Bits ---------------------------------------------
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

#define FSR10           FSR1bits.FSR10          /* bit 0 */
#define FSR11           FSR1bits.FSR11          /* bit 1 */
#define FSR12           FSR1bits.FSR12          /* bit 2 */
#define FSR13           FSR1bits.FSR13          /* bit 3 */
#define FSR14           FSR1bits.FSR14          /* bit 4 */
#define FSR15           FSR1bits.FSR15          /* bit 5 */
#define FSR16           FSR1bits.FSR16          /* bit 6 */
#define FSR17           FSR1bits.FSR17          /* bit 7 */

// ----- PCL Bits ---------------------------------------------
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

#define PC0           PCLbits.PC0          /* bit 0 */
#define PC1           PCLbits.PC1          /* bit 1 */
#define PC2           PCLbits.PC2          /* bit 2 */
#define PC3           PCLbits.PC3          /* bit 3 */
#define PC4           PCLbits.PC4          /* bit 4 */
#define PC5           PCLbits.PC5          /* bit 5 */
#define PC6           PCLbits.PC6          /* bit 6 */
#define PC7           PCLbits.PC7          /* bit 7 */

//----- PFLAG Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char C:	1;
		unsigned char DC:	1;
		unsigned char Z:	1;
		unsigned char :		5;
		};
} __PFLAGbits_t;
extern volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;
	
#define C         	PFLAGbits.C   
#define DC        	PFLAGbits.DC
#define Z         	PFLAGbits.Z


//----- MCR Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char MINT0:	2;
		unsigned char MINT1:	2;
		unsigned char PD:		1;
		unsigned char TO:		1;
		unsigned char :			1;
		unsigned char GIE:		1;
		};
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;
		
#define MINT0		MCRbits.MINT0
#define MINT1		MCRbits.MINT1
#define PD      MCRbits.PD
#define	TO			MCRbits.TO
#define	GIE			MCRbits.GIE

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

#define INDF30           INDF3bits.INDF30          /* bit 0 */
#define INDF31           INDF3bits.INDF31          /* bit 1 */
#define INDF32           INDF3bits.INDF32          /* bit 2 */
#define INDF33           INDF3bits.INDF33          /* bit 3 */
#define INDF34           INDF3bits.INDF34          /* bit 4 */
#define INDF35           INDF3bits.INDF35          /* bit 5 */
#define INDF36           INDF3bits.INDF36          /* bit 6 */
#define INDF37           INDF3bits.INDF37          /* bit 7 */

//;----- INTE Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char T0IE:		1;
		unsigned char T1IE:		1;
		unsigned char INT0IE:	1;
		unsigned char INT1IE:	1;
		unsigned char KBIE:		1;
		unsigned char	:		1;
		unsigned char ADIE:		1;
		unsigned char	:		1;
		};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;
			
#define T0IE		INTEbits.T0IE
#define T1IE		INTEbits.T1IE
#define INT0IE      INTEbits.INT0IE
#define	INT1IE		INTEbits.INT1IE
#define	KBIE		INTEbits.KBIE
#define	ADIE		INTEbits.ADIE

//----- INTF Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char T0IF: 	1;
		unsigned char T1IF: 	1;
		unsigned char INT0IF:	1;
		unsigned char INT1IF:	1;
		unsigned char KBIF: 	1;
		unsigned char	:		1;
		unsigned char ADIF: 	1;
		unsigned char	:		1;
		};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;
				
#define T0IF		INTFbits.T0IF
#define T1IF		INTFbits.T1IF
#define INT0IF		INTFbits.INT0IF
#define	INT1IF		INTFbits.INT1IF
#define	KBIF		INTFbits.KBIF
#define	ADIF		INTFbits.ADIF

//----- OSCM Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char HFEN: 	1;
		unsigned char LFEN: 	1;
		unsigned char CLKS:		1;
		unsigned char	:		1;
		unsigned char STBH:		1;
		unsigned char STBL: 	1;
		unsigned char	:		1;
		unsigned char	:		1;
		};
} __OSCMbits_t;
extern volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;
					
#define HFEN		OSCMbits.HFEN
#define LFEN		OSCMbits.LFEN
#define CLKS		OSCMbits.CLKS
#define	STBH		OSCMbits.STBH
#define	STBH		OSCMbits.STBH
#define	STBL		OSCMbits.STBL

//----- IOP0 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P00: 	1;
		unsigned char P01: 	1;
		unsigned char P02: 	1;
		unsigned char P03:	1;
		unsigned char P04: 	1;
		unsigned char P05: 	1;
		unsigned char P06:	1;
		unsigned char :		1;
		};
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;
						
#define P00		IOP0bits.P00
#define P01		IOP0bits.P01
#define P02		IOP0bits.P02
#define	P03		IOP0bits.P03
#define	P04		IOP0bits.P04
#define	P05		IOP0bits.P05
#define	P06		IOP0bits.P06


//----- OEP0 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P00OE:	1;
		unsigned char P01OE:	1;
		unsigned char P02OE:	1;
		unsigned char P03OE:	1;
		unsigned char P04OE:	1;
		unsigned char P05OE:	1;
		unsigned char P06OE:	1;
		unsigned char : 	1;
		};
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;
							
#define P00OE		OEP0bits.P00OE
#define P01OE		OEP0bits.P01OE
#define P02OE		OEP0bits.P02OE
#define	P03OE		OEP0bits.P03OE
#define	P04OE		OEP0bits.P04OE
#define	P05OE		OEP0bits.P05OE
#define	P06OE		OEP0bits.P06OE

//----- PUP0 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P00PU:	1;
		unsigned char P01PU:	1;
		unsigned char P02PU:	1;
		unsigned char P03PU:	1;
		unsigned char P04PU:	1;
		unsigned char P05PU:	1;
		unsigned char P06PU:	1;
		unsigned char : 	1;
		};
} __PUP0bits_t;
extern volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;
							
#define P00PU		PUP0bits.P00PU
#define P01PU		PUP0bits.P01PU
#define P02PU		PUP0bits.P02PU
#define	P03PU		PUP0bits.P03PU
#define	P04PU		PUP0bits.P04PU
#define	P05PU		PUP0bits.P05PU
#define	P06PU		PUP0bits.P06PU


//----- PDP0 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P00PD:	1;
		unsigned char P01PD:	1;
		unsigned char P02PD:	1;
		unsigned char P03PD:	1;
		unsigned char P04PD:	1;
		unsigned char P05PD:	1;
		unsigned char P06PD:	1;
		unsigned char : 	1;
		};
} __PDP0bits_t;
extern volatile __PDP0bits_t __at(PDP0_ADDR) PDP0bits;
							
#define P00PD		PDP0bits.P00PD
#define P01PD		PDP0bits.P01PD
#define P02PD		PDP0bits.P02PD
#define	P03PD		PDP0bits.P03PD
#define	P04PD		PDP0bits.P04PD
#define	P05PD		PDP0bits.P05PD
#define	P06PD		PDP0bits.P06PD


//----- IOP1 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P10: 	1;
		unsigned char P11: 	1;
		unsigned char P12: 	1;
		unsigned char P13:	1;
		unsigned char P14: 	1;
		unsigned char P15: 	1;
		unsigned char P16:	1;
		unsigned char :		1;
		};
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;
						
#define P10		IOP1bits.P10
#define P11		IOP1bits.P11
#define P12		IOP1bits.P12
#define	P13		IOP1bits.P13
#define	P14		IOP1bits.P14
#define	P15		IOP1bits.P15
#define	P16		IOP1bits.P16


//----- OEP1 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P10OE:	1;
		unsigned char P11OE:	1;
		unsigned char P12OE:	1;
		unsigned char P13OE:	1;
		unsigned char P14OE:	1;
		unsigned char P15OE:	1;
		unsigned char P16OE:	1;
		unsigned char : 	1;
		};
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;
							
#define P10OE		OEP1bits.P10OE
#define P11OE		OEP1bits.P11OE
#define P12OE		OEP1bits.P12OE
#define	P13OE		OEP1bits.P13OE
#define	P14OE		OEP1bits.P14OE
#define	P15OE		OEP1bits.P15OE
#define	P16OE		OEP1bits.P16OE


//----- PUP1 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P10PU:	1;
		unsigned char P11PU:	1;
		unsigned char P12PU:	1;
		unsigned char P13PU:	1;
		unsigned char P14PU:	1;
		unsigned char P15PU:	1;
		unsigned char P16PU:	1;
		unsigned char : 	1;
		};
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;
							
#define P10PU		PUP1bits.P10PU
#define P11PU		PUP1bits.P11PU
#define P12PU		PUP1bits.P12PU
#define	P13PU		PUP1bits.P13PU
#define	P14PU		PUP1bits.P14PU
#define	P15PU		PUP1bits.P15PU
#define	P16PU		PUP1bits.P16PU


//----- PDP1 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P10PD:	1;
		unsigned char P11PD:	1;
		unsigned char P12PD:	1;
		unsigned char P13PD:	1;
		unsigned char P14PD:	1;
		unsigned char P15PD:	1;
		unsigned char P16PD:	1;
		unsigned char : 	1;
		};
} __PDP1bits_t;
extern volatile __PDP1bits_t __at(PDP1_ADDR) PDP1bits;
							
#define P10PD		PDP1bits.P10PD
#define P11PD		PDP1bits.P11PD
#define P12PD		PDP1bits.P12PD
#define	P13PD		PDP1bits.P13PD
#define	P14PD		PDP1bits.P14PD
#define	P15PD		PDP1bits.P15PD
#define	P16PD		PDP1bits.P16PD


//--- T0CR Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char T0PR:		3;
		unsigned char T0PTS:		2;
		unsigned char BUZ0OE:	1;
		unsigned char PWM0OE:	1;
		unsigned char TC0EN:	1;
		};
} __T0CRbits_t;
extern volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;
							
#define T0PR		T0CRbits.T0PR
#define T0PTS		T0CRbits.T0PTS
#define BUZ0OE		T0CRbits.BUZ0OE
#define	PWM0OE		T0CRbits.PWM0OE
#define	TC0EN		T0CRbits.TC0EN

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

#define T0C0            T0CNTbits.T0C0           /* bit 0 */
#define T0C1            T0CNTbits.T0C1           /* bit 1 */
#define T0C2            T0CNTbits.T0C2           /* bit 2 */
#define T0C3            T0CNTbits.T0C3           /* bit 3 */
#define T0C4            T0CNTbits.T0C4           /* bit 4 */
#define T0C5            T0CNTbits.T0C5           /* bit 5 */
#define T0C6            T0CNTbits.T0C6           /* bit 6 */
#define T0C7            T0CNTbits.T0C7           /* bit 7 */

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

#define T0LOAD0         T0LOADbits.T0LOAD0       /* bit 0 */
#define T0LOAD1         T0LOADbits.T0LOAD1       /* bit 1 */
#define T0LOAD2         T0LOADbits.T0LOAD2       /* bit 2 */
#define T0LOAD3         T0LOADbits.T0LOAD3       /* bit 3 */
#define T0LOAD4         T0LOADbits.T0LOAD4       /* bit 4 */
#define T0LOAD5         T0LOADbits.T0LOAD5       /* bit 5 */
#define T0LOAD6         T0LOADbits.T0LOAD6       /* bit 6 */
#define T0LOAD7         T0LOADbits.T0LOAD7       /* bit 7 */

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

#define T0DATA0         T0DATAbits.T0DATA0       /* bit 0 */
#define T0DATA1         T0DATAbits.T0DATA1       /* bit 1 */
#define T0DATA2         T0DATAbits.T0DATA2       /* bit 2 */
#define T0DATA3         T0DATAbits.T0DATA3       /* bit 3 */
#define T0DATA4         T0DATAbits.T0DATA4       /* bit 4 */
#define T0DATA5         T0DATAbits.T0DATA5       /* bit 5 */
#define T0DATA6         T0DATAbits.T0DATA6       /* bit 6 */
#define T0DATA7         T0DATAbits.T0DATA7       /* bit 7 */

//----- T1CR Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char T1PR:		3;
		unsigned char T1PTS:		2;
		unsigned char BUZ1OE:	1;
		unsigned char PWM1OE:	1;
		unsigned char TC1EN:	1;
		};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;
							
#define T1PR		T1CRbits.T1PR
#define T1PTS		T1CRbits.T1PTS
#define BUZ1OE		T1CRbits.BUZ1OE
#define	PWM1OE		T1CRbits.PWM1OE
#define	TC1EN		T1CRbits.TC1EN

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

#define T1C0            T1CNTbits.T1C0           /* bit 0 */
#define T1C1            T1CNTbits.T1C1           /* bit 1 */
#define T1C2            T1CNTbits.T1C2           /* bit 2 */
#define T1C3            T1CNTbits.T1C3           /* bit 3 */
#define T1C4            T1CNTbits.T1C4           /* bit 4 */
#define T1C5            T1CNTbits.T1C5           /* bit 5 */
#define T1C6            T1CNTbits.T1C6           /* bit 6 */
#define T1C7            T1CNTbits.T1C7           /* bit 7 */

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

#define T1LOAD0         T1LOADbits.T1LOAD0       /* bit 0 */
#define T1LOAD1         T1LOADbits.T1LOAD1       /* bit 1 */
#define T1LOAD2         T1LOADbits.T1LOAD2       /* bit 2 */
#define T1LOAD3         T1LOADbits.T1LOAD3       /* bit 3 */
#define T1LOAD4         T1LOADbits.T1LOAD4       /* bit 4 */
#define T1LOAD5         T1LOADbits.T1LOAD5       /* bit 5 */
#define T1LOAD6         T1LOADbits.T1LOAD6       /* bit 6 */
#define T1LOAD7         T1LOADbits.T1LOAD7       /* bit 7 */

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

#define T1DATA0         T1DATAbits.T1DATA0       /* bit 0 */
#define T1DATA1         T1DATAbits.T1DATA1       /* bit 1 */
#define T1DATA2         T1DATAbits.T1DATA2       /* bit 2 */
#define T1DATA3         T1DATAbits.T1DATA3       /* bit 3 */
#define T1DATA4         T1DATAbits.T1DATA4       /* bit 4 */
#define T1DATA5         T1DATAbits.T1DATA5       /* bit 5 */
#define T1DATA6         T1DATAbits.T1DATA6       /* bit 6 */
#define T1DATA7         T1DATAbits.T1DATA7       /* bit 7 */

//----- AUCR Bits ----------------------------------------------------
typedef union {
	struct {
		unsigned char NMOS0ON:		1;
		unsigned char PMOS1ON:		1;
		unsigned char P11DV:		1;
		unsigned char P01DV:		1;
		unsigned char P13SP:		1;
		unsigned char P04WP:		1;
		unsigned char SPDSL:		1;
		unsigned char DRVEN:		1;
		};
} __AUCRbits_t;
extern volatile __AUCRbits_t __at(AUCR_ADDR) AUCRbits;
							
#define NMOS0ON		AUCRbits.NMOS0ON
#define PMOS1ON		AUCRbits.PMOS1ON
#define P11DV		AUCRbits.P11DV
#define	P01DV		AUCRbits.P01DV
#define	P13SP		AUCRbits.P13SP
#define	P04WP		AUCRbits.P04WP
#define	SPDSL		AUCRbits.SPDSL
#define	DRVEN		AUCRbits.DRVEN

// ----- KBCR Bits --------------------------------------------
typedef union {
         struct {
                unsigned char KBCR0:1;
                unsigned char KBCR1:1;
                unsigned char KBCR2:1;
                unsigned char KBCR3:1;
                unsigned char KBCR4:1;
                unsigned char KBCR5:1;
                unsigned char KBCR6:1;
                unsigned char :1;
        };
} __KBCRbits_t;
extern volatile __KBCRbits_t __at(KBCR_ADDR) KBCRbits;

#define KBCR0         KBCRbits.KBCR0       /* bit 0 */
#define KBCR1         KBCRbits.KBCR1       /* bit 1 */
#define KBCR2         KBCRbits.KBCR2       /* bit 2 */
#define KBCR3         KBCRbits.KBCR3       /* bit 3 */
#define KBCR4         KBCRbits.KBCR4       /* bit 4 */
#define KBCR5         KBCRbits.KBCR5       /* bit 5 */
#define KBCR6         KBCRbits.KBCR6       /* bit 6 */

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

//----- ADCR0 Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char ADON:			1;
		unsigned char ADEOC:		1;
		unsigned char ADCKS:		2;
		unsigned char ADCHS:		4;
		};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;
							
#define ADON		ADCR0bits.ADON
#define ADEOC		ADCR0bits.ADEOC
#define ADCKS		ADCR0bits.ADCKS
#define	ADCHS		ADCR0bits.ADCHS

//----- ADCR1 Bits ---------------------------------------------------
typedef union{
	struct {
		unsigned char VRS:			3;
		unsigned char :				5;
		};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;
							
#define VRS			ADCR1bits.VRS

//----- AN0SEL Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P00ANS:	1;
		unsigned char P01ANS:	1;
		unsigned char P02ANS:	1;
		unsigned char P03ANS:	1;
		unsigned char P04ANS:	1;
		unsigned char P05ANS:	1;
		unsigned char P06ANS:	1;
		unsigned char : 	1;
		};
} __AN0SELbits_t;
extern volatile __AN0SELbits_t __at(AN0SEL_ADDR) AN0SELbits;
							
#define P00ANS		AN0SELbits.P00ANS
#define P01ANS		AN0SELbits.P01ANS
#define P02ANS		AN0SELbits.P02ANS
#define	P03ANS		AN0SELbits.P03ANS
#define	P04ANS		AN0SELbits.P04ANS
#define	P05ANS		AN0SELbits.P05ANS
#define	P06ANS		AN0SELbits.P06ANS


//----- AN1SEL Bits ---------------------------------------------------
typedef union {
	struct {
		unsigned char P10ANS:	1;
		unsigned char P11ANS:	1;
		unsigned char P12ANS:	1;
		unsigned char P13ANS:	1;
		unsigned char P14ANS:	1;
		unsigned char P15ANS:	1;
		unsigned char P16ANS:	1;
		unsigned char : 	1;
		};
} __AN1SELbits_t;
extern volatile __AN1SELbits_t __at(AN1SEL_ADDR) AN1SELbits;
							
#define P10ANS		AN1SELbits.P00ANS
#define P11ANS		AN1SELbits.P11ANS
#define P12ANS		AN1SELbits.P12ANS
#define	P13ANS		AN1SELbits.P13ANS
#define	P14ANS		AN1SELbits.P14ANS
#define	P15ANS		AN1SELbits.P15ANS
#define	P16ANS		AN1SELbits.P16ANS

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

#define ADR4       	  ADRHbits.ADR4       	  /* bit 0 */
#define ADR5       	  ADRHbits.ADR5         	/* bit 1 */
#define ADR6        	ADRHbits.ADR6         	/* bit 2 */
#define ADR7        	ADRHbits.ADR7         	/* bit 3 */
#define ADR8        	ADRHbits.ADR8         	/* bit 4 */
#define ADR9        	ADRHbits.ADR9         	/* bit 5 */
#define ADR10       	ADRHbits.ADR10        	/* bit 6 */
#define ADR11       	ADRHbits.ADR11        	/* bit 7 */

// ----- ADRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADR0:1;
		unsigned char ADR1:1;
		unsigned char ADR2:1;
		unsigned char ADR3:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;	
	};
} __ADRLbits_t;
extern volatile __ADRLbits_t __at(ADRL_ADDR) ADRLbits;

#define ADR0       	  ADRLbits.ADR0       	  /* bit 0 */
#define ADR1       	  ADRLbits.ADR1         	/* bit 1 */
#define ADR2        	ADRLbits.ADR2         	/* bit 2 */
#define ADR3        	ADRLbits.ADR3         	/* bit 3 */

#endif

