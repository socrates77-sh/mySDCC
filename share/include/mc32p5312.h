#ifndef MC32P5312_H
#define MC32P5312_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR               0x01B0
#define INDF0_ADDR       	0x01B0
#define INDF1_ADDR      	0x01B1
#define INDF2_ADDR        	0x01B2
#define HIBYTE_ADDR             0x01B3
#define FSR_ADDR                0x01B4
#define FSR0_ADDR               0x01B4
#define FSR1_ADDR               0x01B5
#define PCL_ADDR                0x01B6
#define STATUS_ADDR     	0x01B7
#define MCR_ADDR        	0x01B8
#define INDF3_ADDR         	0x01B9
#define INTE_ADDR         	0x01BA
#define INTF_ADDR        	0x01BB
#define OSCM_ADDR       	0x01BC
#define LVDCR_ADDR        	0x01BD
#define LXTCR_ADDR      	0x01BE
#define IOP0_ADDR               0x01C0
#define OEP0_ADDR               0x01C1
#define PUP0_ADDR               0x01C2
#define DKWP0_ADDR              0x01C3
#define IOP1_ADDR               0x01C4
#define OEP1_ADDR               0x01C5
#define PUP1_ADDR               0x01C6
#define DKWP1_ADDR              0x01C7
#define T0CR_ADDR               0x01C8
#define T0CNT_ADDR              0x01C9
#define T0LOAD_ADDR             0x01CA
#define T0DATA_ADDR             0x01CB
#define T1CR_ADDR               0x01CC
#define T1CNT_ADDR              0x01CD
#define T1LOAD_ADDR             0x01CE
#define T1DATA_ADDR             0x01CF
#define LCDCR0_ADDR             0x01D0
#define LCDCR1_ADDR             0x01D1
#define LCDSP0_ADDR             0x01D2
#define LCDSP1_ADDR             0x01D3
#define DKW_ADDR                0x01D4

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)           INDF;
extern __sfr __at (INDF0_ADDR)     	INDF0;
extern __sfr __at (INDF1_ADDR)    	INDF1;
extern __sfr __at (INDF2_ADDR)          INDF2;
extern __sfr __at (HIBYTE_ADDR)         HIBYTE;
extern __sfr __at (FSR_ADDR)            FSR;
extern __sfr __at (FSR0_ADDR)           FSR0;
extern __sfr __at (FSR1_ADDR)           FSR1;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INDF3_ADDR)       	INDF3;
extern __sfr __at (INTE_ADDR)       	INTE;
extern __sfr __at (INTF_ADDR)      	INTF;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (LVDCR_ADDR)   	LVDCR;
extern __sfr __at (LXTCR_ADDR)    	LXTCR;
extern __sfr __at (IOP0_ADDR)    	IOP0;
extern __sfr __at (OEP0_ADDR)    	OEP0;
extern __sfr __at (PUP0_ADDR)  	        PUP0;
extern __sfr __at (DKWP0_ADDR)  	DKWP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (DKWP1_ADDR)     	DKWP1;
extern __sfr __at (T0CR_ADDR)     	T0CR;
extern __sfr __at (T0CNT_ADDR)    	T0CNT;
extern __sfr __at (T0LOAD_ADDR)   	T0LOAD;
extern __sfr __at (T0DATA_ADDR)   	T0DATA;
extern __sfr __at (T1CR_ADDR)           T1CR;
extern __sfr __at (T1CNT_ADDR)          T1CNT;
extern __sfr __at (T1LOAD_ADDR)         T1LOAD;
extern __sfr __at (T1DATA_ADDR)         T1DATA;
extern __sfr __at (LCDCR0_ADDR)         LCDCR0;
extern __sfr __at (LCDCR1_ADDR)         LCDCR1;
extern __sfr __at (LCDSP0_ADDR)         LCDSP0;
extern __sfr __at (LCDSP1_ADDR)         LCDSP1;
extern __sfr __at (DKW_ADDR)            DKW;

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

#define MINT0           MCRbits.MINT0           /* bit 1-0 */
#define MINT1           MCRbits.MINT1           /* bit 3-2 */
#define PD              MCRbits.PD              /* bit 4 */
#define TO              MCRbits.TO              /* bit 5 */
#define GIE             MCRbits.GIE             /* bit 7 */

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

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char :1;
		unsigned char LVDIE:1;
		unsigned char :1;
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE    	/* bit 0 */
#define T1IE            INTEbits.T1IE           /* bit 1 */
#define INT0IE          INTEbits.INT0IE         /* bit 2 */
#define INT1IE          INTEbits.INT1IE         /* bit 3 */
#define LVDIE    	INTEbits.LVDIE  	/* bit 5 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char :1;
		unsigned char LVDIF:1;
		unsigned char :1;
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF    	/* bit 0 */
#define T1IF            INTFbits.T1IF           /* bit 1 */
#define INT0IF    	INTFbits.INT0IF  	/* bit 2 */
#define INT1IF          INTFbits.INT1IF         /* bit 3 */
#define LVDIF           INTFbits.LVDIF          /* bit 5 */

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

#define HFEN            OSCMbits.HFEN           /* bit 0 */
#define LFEN            OSCMbits.LFEN           /* bit 1 */
#define CLKS            OSCMbits.CLKS           /* bit 2 */
#define STBH            OSCMbits.STBH           /* bit 4 */
#define STBL            OSCMbits.STBL           /* bit 5 */

// ----- LVDCR Bits --------------------------------------------
typedef union {
         struct {
                unsigned char LVDF:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char LVDS:4;
                unsigned char LVDEN:1;
        };
} __LVDCRbits_t;
extern volatile __LVDCRbits_t __at(LVDCR_ADDR) LVDCRbits;

#define LVDF            LVDCRbits.LVDF          /* bit 0 */
#define LVDS            LVDCRbits.LVDS          /* bit 6-3 */
#define LVDEN           LVDCRbits.LVDEN         /* bit 7 */

// ----- LXTCR Bits --------------------------------------------
typedef union {
         struct {
                unsigned char LPEN:3;
                unsigned char FILS:1;
                unsigned char VDSEL:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __LXTCRbits_t;
extern volatile __LXTCRbits_t __at(LXTCR_ADDR) LXTCRbits;

#define LPEN            LXTCRbits.LPEN          /* bit 2-0 */
#define FILS            LXTCRbits.FILS          /* bit 3 */
#define VDSEL           LXTCRbits.VDSEL         /* bit 4 */

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

#define P00             IOP0bits.P00            /* bit 0 */
#define P01             IOP0bits.P01            /* bit 1 */
#define P02             IOP0bits.P02            /* bit 2 */
#define P03             IOP0bits.P03            /* bit 3 */
#define P04             IOP0bits.P04            /* bit 4 */
#define P05             IOP0bits.P05            /* bit 5 */
#define P06             IOP0bits.P06            /* bit 6 */
#define P07             IOP0bits.P07            /* bit 7 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00OE:1;
                unsigned char P01OE:1;
                unsigned char P02OE:1;
                unsigned char P03OE:1;
                unsigned char P04OE:1;
                unsigned char P050E:1;
                unsigned char P060E:1;
                unsigned char P070E:1;
        };
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;

#define P00OE           OEP0bits.P00OE          /* bit 0 */
#define P01OE           OEP0bits.P01OE          /* bit 1 */
#define P02OE           OEP0bits.P02OE          /* bit 2 */
#define P03OE           OEP0bits.P03OE          /* bit 3 */
#define P04OE           OEP0bits.P04OE          /* bit 4 */
#define P05OE           OEP0bits.P05OE          /* bit 5 */
#define P06OE           OEP0bits.P06OE          /* bit 6 */
#define P07OE           OEP0bits.P07OE          /* bit 7 */

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

#define P00PU           PUP0bits.P00PU          /* bit 0 */
#define P01PU           PUP0bits.P01PU          /* bit 1 */
#define P02PU           PUP0bits.P02PU          /* bit 2 */
#define P03PU           PUP0bits.P03PU          /* bit 3 */
#define P04PU           PUP0bits.P04PU          /* bit 4 */
#define P05PU           PUP0bits.P05PU          /* bit 5 */
#define P06PU           PUP0bits.P06PU          /* bit 6 */
#define P07PU           PUP0bits.P07PU          /* bit 7 */

// ----- DKWP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00DKW:1;
                unsigned char P01DKW:1;
                unsigned char P02DKW:1;
                unsigned char P03DKW:1;
                unsigned char P04DKW:1;
                unsigned char P05DKW:1;
                unsigned char P06DKW:1;
                unsigned char P07DKW:1;
        };
} __DKWP0bits_t;
extern volatile __DKWP0bits_t __at(DKWP0_ADDR) DKWP0bits;

#define P00DKW           DKWP0bits.P00DKW          /* bit 0 */
#define P01DKW           DKWP0bits.P01DKW          /* bit 1 */
#define P02DKW           DKWP0bits.P02DKW          /* bit 2 */
#define P03DKW           DKWP0bits.P03DKW          /* bit 3 */
#define P04DKW           DKWP0bits.P04DKW          /* bit 4 */
#define P05DKW           DKWP0bits.P05DKW          /* bit 5 */
#define P06DKW           DKWP0bits.P06DKW          /* bit 6 */
#define P07DKW           DKWP0bits.P07DKW          /* bit 7 */

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

#define P10             IOP1bits.P10            /* bit 0 */
#define P11             IOP1bits.P11            /* bit 1 */
#define P12             IOP1bits.P12            /* bit 2 */
#define P13             IOP1bits.P13            /* bit 3 */
#define P14             IOP1bits.P14            /* bit 4 */
#define P15             IOP1bits.P15            /* bit 5 */
#define P16             IOP1bits.P16            /* bit 6 */

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

#define P10OE           OEP1bits.P10OE          /* bit 0 */
#define P11OE           OEP1bits.P11OE          /* bit 1 */
#define P12OE           OEP1bits.P12OE          /* bit 2 */
#define P13OE           OEP1bits.P13OE          /* bit 3 */
#define P14OE           OEP1bits.P14OE          /* bit 4 */
#define P15OE           OEP1bits.P15OE          /* bit 5 */
#define P16OE           OEP1bits.P16OE          /* bit 6 */

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

#define P10PU           PUP1bits.P10PU          /* bit 0 */
#define P11PU           PUP1bits.P11PU          /* bit 1 */
#define P12PU           PUP1bits.P12PU          /* bit 2 */
#define P13PU           PUP1bits.P13PU          /* bit 3 */
#define P14PU           PUP1bits.P14PU          /* bit 4 */
#define P15PU           PUP1bits.P15PU          /* bit 5 */
#define P16PU           PUP1bits.P16PU          /* bit 6 */

// ----- DKWP1 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P10DKW:1;
                unsigned char P11DKW:1;
                unsigned char P12DKW:1;
                unsigned char P13DKW:1;
                unsigned char P14DKW:1;
                unsigned char P15DKW:1;
                unsigned char P16DKW:1;
                unsigned char :1;
        };
} __DKWP1bits_t;
extern volatile __DKWP1bits_t __at(DKWP1_ADDR) DKWP1bits;

#define P10DKW           DKWP1bits.P10DKW          /* bit 0 */
#define P11DKW           DKWP1bits.P11DKW          /* bit 1 */
#define P12DKW           DKWP1bits.P12DKW          /* bit 2 */
#define P13DKW           DKWP1bits.P13DKW          /* bit 3 */
#define P14DKW           DKWP1bits.P14DKW          /* bit 4 */
#define P15DKW           DKWP1bits.P15DKW          /* bit 5 */
#define P16DKW           DKWP1bits.P16DKW          /* bit 6 */

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

#define T0PR            T0CRbits.T0PR           /* bit 2-0 */
#define T0PS            T0CRbits.T0PS           /* bit 4-3 */
#define BUZ0OE          T0CRbits.BUZ0OE         /* bit 5 */
#define PWM0OE          T0CRbits.PWM0OE         /* bit 6 */
#define TC0EN           T0CRbits.TC0EN          /* bit 7 */

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

#define T1PR            T1CRbits.T1PR           /* bit 2-0 */
#define T1PS            T1CRbits.T1PS           /* bit 4-3 */
#define BUZ1OE          T1CRbits.BUZ1OE         /* bit 5 */
#define PWM1OE          T1CRbits.PWM1OE         /* bit 6 */
#define TC1EN           T1CRbits.TC1EN          /* bit 7 */

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

// ---- LCDCR0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char LCDRS:2;
                unsigned char LCDSPEED:1;
                unsigned char LCDSP:2;
                unsigned char LCDEN:1;
                unsigned char :1;
                unsigned char :1;
        };
} __LCDCR0bits_t;
extern volatile __LCDCR0bits_t __at(LCDCR0_ADDR) LCDCR0bits;

#define LCDRS           LCDCR0bits.LCDRS           /* bit 1-0 */
#define LCDSPEED        LCDCR0bits.LCDSPEED        /* bit 2 */
#define LCDSP           LCDCR0bits.LCDSP           /* bit 4-3 */
#define LCDEN           LCDCR0bits.LCDEN           /* bit 5 */

// ---- LCDCR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char FLCD:2;
                unsigned char LCDCKS:1;
                unsigned char LCDM:1;
                unsigned char LCDLED:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __LCDCR1bits_t;
extern volatile __LCDCR1bits_t __at(LCDCR1_ADDR) LCDCR1bits;

#define FLCD            LCDCR1bits.FLCD            /* bit 1-0 */
#define LCDCKS          LCDCR1bits.LCDCKS          /* bit 2 */
#define LCDM            LCDCR1bits.LCDM            /* bit 3 */
#define LCDLED          LCDCR1bits.LCDLED          /* bit 4 */

// ---- LCDSP0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char LCDSP03:1;
                unsigned char LCDSP04:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __LCDSP0bits_t;
extern volatile __LCDSP0bits_t __at(LCDSP0_ADDR) LCDSP0bits;

#define LCDSP03         LCDSP0bits.LCDSP03       /* bit 3 */
#define LCDSP04         LCDSP0bits.LCDSP04       /* bit 4 */

// ---- LCDSP1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char LCDSP10:1;
                unsigned char LCDSP11:1;
                unsigned char LCDSP12:1;
                unsigned char LCDSP13:1;
                unsigned char LCDSP14:1;
                unsigned char LCDSP15:1;
                unsigned char LCDSP16:1;
                unsigned char :1;
        };
} __LCDSP1bits_t;
extern volatile __LCDSP1bits_t __at(LCDSP1_ADDR) LCDSP1bits;

#define LCDSP10         LCDSP1bits.LCDSP10       /* bit 0 */
#define LCDSP11         LCDSP1bits.LCDSP11       /* bit 1 */
#define LCDSP12         LCDSP1bits.LCDSP12       /* bit 2 */
#define LCDSP13         LCDSP1bits.LCDSP13       /* bit 3 */
#define LCDSP14         LCDSP1bits.LCDSP14       /* bit 4 */
#define LCDSP15         LCDSP1bits.LCDSP15       /* bit 5 */
#define LCDSP16         LCDSP1bits.LCDSP16       /* bit 6 */

// ---- DKW Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char IROUTS:1;
                unsigned char IROUTEN:1;
                unsigned char RSEL:1;
                unsigned char WSEL:2;
                unsigned char DKWE:1;
                unsigned char :1;
                unsigned char :1;
        };
} __DKWbits_t;
extern volatile __DKWbits_t __at(DKW_ADDR) DKWbits;

#define IROUTS          DKWbits.IROUTS          /* bit 0 */
#define IROUTEN         DKWbits.IROUTEN         /* bit 1 */
#define RSEL            DKWbits.RSEL            /* bit 2 */
#define WSEL            DKWbits.WSEL            /* bit 4-3 */
#define DKWE            DKWbits.DKWE            /* bit 5 */

#endif
