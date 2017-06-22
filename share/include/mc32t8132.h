#ifndef MC32T8132_H
#define MC32T8132_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR               0x01A0
#define INDF0_ADDR              0x01A0
#define INDF1_ADDR       	      0x01A1
#define INDF2_ADDR      	      0x01A2
#define HIBYTE_ADDR       	    0x01A3
#define FSR_ADDR                0x01A4
#define FSR0_ADDR               0x01A4
#define FSR1_ADDR               0x01A5
#define PCL_ADDR                0x01A6
#define STATUS_ADDR             0x01A7
#define PFLAG_ADDR              0x01A7
#define MCR_ADDR                0x01A8
#define INDF3_ADDR     	        0x01A9
#define INTE_ADDR        	      0x01AA
#define INTF_ADDR         	    0x01AB
#define OSCM_ADDR         	    0x01AC
#define CLKO_ADDR        	      0x01AD

#define IOP0_ADDR               0x01B0
#define OEP0_ADDR               0x01B1
#define PUP0_ADDR               0x01B2
#define PDP0_ADDR               0x01B3
#define IOP1_ADDR               0x01B4
#define OEP1_ADDR               0x01B5
#define PUP1_ADDR               0x01B6
#define PDP1_ADDR               0x01B7
#define IOP2_ADDR               0x01B8
#define OEP2_ADDR               0x01B9
#define PUP2_ADDR               0x01BA
#define PDP2_ADDR               0x01BB
#define IOP3_ADDR               0x01BC
#define OEP3_ADDR               0x01BD
#define PUP3_ADDR               0x01BE
#define PDP3_ADDR               0x01BF

#define T0CR_ADDR               0x01C0
#define T0CNT_ADDR              0x01C1
#define T0LOAD_ADDR             0x01C2
#define T0DATA_ADDR             0x01C3
#define T1CR_ADDR               0x01C4
#define T1CNT_ADDR              0x01C5
#define T1LOAD_ADDR             0x01C6
#define T1DATA_ADDR             0x01C7
#define T2CR_ADDR               0x01C8
#define T2CNTH_ADDR             0x01C9
#define T2CNTL_ADDR             0x01CA
#define T2LOADH_ADDR            0x01CB
#define T2LOADL_ADDR            0x01CC

#define TK0CR0_ADDR             0x01D0
#define TK0CR1_ADDR             0x01D1
#define TK0CR2_ADDR             0x01D2
#define TK0CNTH_ADDR            0x01D3
#define TK0CNTL_ADDR            0x01D4
#define TK1CR0_ADDR             0x01D8
#define TK1CR1_ADDR             0x01D9
#define TK1CR2_ADDR             0x01DA
#define TK1CNTH_ADDR            0x01DB
#define TK1CNTL_ADDR            0x01DC

#define ADCR0_ADDR              0x01E0
#define ADCR1_ADDR              0x01E1
#define ADCR2_ADDR              0x01E2
#define ADIO0_ADDR              0x01E3
#define ADIO1_ADDR              0x01E4
#define ADRH_ADDR               0x01E5
#define ADRL_ADDR               0x01E6
#define LEDDS1_ADDR             0x01E8
#define LEDDS2_ADDR             0x01E9
#define LEDDS3_ADDR             0x01EA
#define LEDDS4_ADDR             0x01EB
#define LEDDS5_ADDR             0x01EC
#define LEDDS6_ADDR             0x01ED
#define LEDDS7_ADDR             0x01EE
#define LEDDS8_ADDR             0x01EF

#define LEDCR0_ADDR             0x01F0
#define LEDCR1_ADDR             0x01F1
#define LEDIOS0_ADDR            0x01F2
#define LEDIOS1_ADDR            0x01F3
#define LEDDRV_ADDR             0x01F4

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)       INDF;
extern __sfr __at (INDF0_ADDR)     	INDF0;
extern __sfr __at (INDF1_ADDR)    	INDF1;
extern __sfr __at (INDF2_ADDR)      INDF2;
extern __sfr __at (HIBYTE_ADDR)     HIBYTE;
extern __sfr __at (FSR_ADDR)        FSR;
extern __sfr __at (FSR0_ADDR)       FSR0;
extern __sfr __at (FSR1_ADDR)       FSR1;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (STATUS_ADDR)   	STATUS;
extern __sfr __at (PFLAG_ADDR)   	  PFLAG;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INDF3_ADDR)      INDF3;
extern __sfr __at (INTE_ADDR)       INTE;
extern __sfr __at (INTF_ADDR)      	INTF;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (CLKO_ADDR)   	  CLKO;
extern __sfr __at (IOP0_ADDR)    	  IOP0;
extern __sfr __at (OEP0_ADDR)    	  OEP0;
extern __sfr __at (PUP0_ADDR)  	    PUP0;
extern __sfr __at (PDP0_ADDR)  	    PDP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (PDP1_ADDR)       PDP1;
extern __sfr __at (IOP2_ADDR)     	IOP2;
extern __sfr __at (OEP2_ADDR)     	OEP2;
extern __sfr __at (PUP2_ADDR)   	  PUP2;
extern __sfr __at (PDP2_ADDR)       PDP2;
extern __sfr __at (IOP3_ADDR)       IOP3;
extern __sfr __at (OEP3_ADDR)       OEP3;
extern __sfr __at (PUP3_ADDR)       PUP3;
extern __sfr __at (PDP3_ADDR)       PDP3;
extern __sfr __at (T0CR_ADDR)       T0CR;
extern __sfr __at (T0CNT_ADDR)      T0CNT;
extern __sfr __at (T0LOAD_ADDR)     T0LOAD;
extern __sfr __at (T0DATA_ADDR)     T0DATA;
extern __sfr __at (T1CR_ADDR)       T1CR;
extern __sfr __at (T1CNT_ADDR)      T1CNT;
extern __sfr __at (T1LOAD_ADDR)     T1LOAD;
extern __sfr __at (T1DATA_ADDR)     T1DATA;
extern __sfr __at (T2CR_ADDR)       T2CR;
extern __sfr __at (T2CNTH_ADDR)     T2CNTH;
extern __sfr __at (T2CNTL_ADDR)     T2CNTL;
extern __sfr __at (T2LOADH_ADDR)    T2LOADH;
extern __sfr __at (T2LOADL_ADDR)    T2LOADL;
extern __sfr __at (TK0CR0_ADDR)     TK0CR0;
extern __sfr __at (TK0CR1_ADDR)     TK0CR1;
extern __sfr __at (TK0CR2_ADDR)     TK0CR2;
extern __sfr __at (TK0CNTH_ADDR)    TK0CNTH;
extern __sfr __at (TK0CNTL_ADDR)    TK0CNTL;
extern __sfr __at (TK1CR0_ADDR)     TK1CR0;
extern __sfr __at (TK1CR1_ADDR)     TK1CR1;
extern __sfr __at (TK1CR2_ADDR)     TK1CR2;
extern __sfr __at (TK1CNTH_ADDR)    TK1CNTH;
extern __sfr __at (TK1CNTL_ADDR)    TK1CNTL;
extern __sfr __at (ADCR0_ADDR)      ADCR0;
extern __sfr __at (ADCR1_ADDR)      ADCR1;
extern __sfr __at (ADCR2_ADDR)      ADCR2;
extern __sfr __at (ADIO0_ADDR)      ADIO0;
extern __sfr __at (ADIO1_ADDR)      ADIO1;
extern __sfr __at (ADRH_ADDR)       ADRH;
extern __sfr __at (ADRL_ADDR)       ADRL;
extern __sfr __at (LEDDS1_ADDR)     LEDDS1;
extern __sfr __at (LEDDS2_ADDR)     LEDDS2;
extern __sfr __at (LEDDS3_ADDR)     LEDDS3;
extern __sfr __at (LEDDS4_ADDR)     LEDDS4;
extern __sfr __at (LEDDS5_ADDR)     LEDDS5;
extern __sfr __at (LEDDS6_ADDR)     LEDDS6;
extern __sfr __at (LEDDS7_ADDR)     LEDDS7;
extern __sfr __at (LEDDS8_ADDR)     LEDDS8;
extern __sfr __at (LEDCR0_ADDR)     LEDCR0;
extern __sfr __at (LEDCR1_ADDR)     LEDCR1;
extern __sfr __at (LEDIOS0_ADDR)    LEDIOS0;
extern __sfr __at (LEDIOS1_ADDR)    LEDIOS1;
extern __sfr __at (LEDDRV_ADDR)     LEDDRV;

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
#define INDF01           INDF0bits.INDF01        	 /* bit 1 */
#define INDF02           INDF0bits.INDF02          /* bit 2 */
#define INDF03           INDF0bits.INDF03        	 /* bit 3 */
#define INDF04           INDF0bits.INDF04        	 /* bit 4 */
#define INDF05           INDF0bits.INDF05        	 /* bit 5 */
#define INDF06           INDF0bits.INDF06        	 /* bit 6 */
#define INDF07           INDF0bits.INDF07        	 /* bit 7 */

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
		unsigned char T2IE:1;
		unsigned char :1;
		unsigned char ADIE:1;
		unsigned char :1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	    INTEbits.T0IE    	      /* bit 0 */
#define T1IE            INTEbits.T1IE           /* bit 1 */
#define INT0IE          INTEbits.INT0IE         /* bit 2 */
#define INT1IE          INTEbits.INT1IE         /* bit 3 */
#define KBIE            INTEbits.T2IE           /* bit 4 */
#define ADIE            INTEbits.ADIE           /* bit 6 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char T2IF:1;
		unsigned char :1;
		unsigned char ADIF:1;
		unsigned char :1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	    INTFbits.T0IF         	/* bit 0 */
#define T1IF            INTFbits.T1IF           /* bit 1 */
#define INT0IF    	    INTFbits.INT0IF       	/* bit 2 */
#define INT1IF          INTFbits.INT1IF         /* bit 3 */
#define KBIF            INTFbits.T2IF           /* bit 4 */
#define ADIF            INTFbits.ADIF           /* bit 6 */

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

// ----- CLKO Bits --------------------------------------------
typedef union {
         struct {
                unsigned char CLKOS:3;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;  
                unsigned char CLKOEN:1;
        };
} __CLKObits_t;
extern volatile __CLKObits_t __at(CLKO_ADDR) CLKObits;

#define CLKOS           CLKObits.CLKOS          /* bit 2-0 */
#define CLKOEN          CLKObits.CLKOEN         /* bit 7 */

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

#define P00D            IOP0bits.P00D           /* bit 0 */
#define P01D            IOP0bits.P01D           /* bit 1 */
#define P02D            IOP0bits.P02D           /* bit 2 */
#define P03D            IOP0bits.P03D           /* bit 3 */
#define P04D            IOP0bits.P04D           /* bit 4 */
#define P05D            IOP0bits.P05D           /* bit 5 */
#define P06D            IOP0bits.P06D           /* bit 6 */
#define P07D            IOP0bits.P07D           /* bit 7 */

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

// ----- PDP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00PD:1;
                unsigned char P01PD:1;
                unsigned char P02PD:1;
                unsigned char P03PD:1;
                unsigned char P04PD:1;
                unsigned char P05PD:1;
                unsigned char P06PD:1;
                unsigned char P07PD:1;
        };
} __PDP0bits_t;
extern volatile __PDP0bits_t __at(PDP0_ADDR) PDP0bits;

#define P00PD           PDP0bits.P00PD            /* bit 0 */
#define P01PD           PDP0bits.P01PD            /* bit 1 */
#define P02PD           PDP0bits.P02PD            /* bit 2 */
#define P03PD           PDP0bits.P03PD            /* bit 3 */
#define P04PD           PDP0bits.P04PD            /* bit 4 */
#define P05PD           PDP0bits.P05PD            /* bit 5 */
#define P06PD           PDP0bits.P06PD            /* bit 6 */
#define P07PD           PDP0bits.P07PD            /* bit 7 */

// ----- IOP1 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P10D:1;
                unsigned char P11D:1;
                unsigned char P12D:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __IOP1bits_t;
extern volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;

#define P10D            IOP1bits.P10D           /* bit 0 */
#define P11D            IOP1bits.P11D           /* bit 1 */
#define P12D            IOP1bits.P12D           /* bit 2 */

// ----- OEP1 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P10OE:1;
                unsigned char P11OE:1;
                unsigned char P12OE:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __OEP1bits_t;
extern volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;

#define P10OE           OEP1bits.P10OE          /* bit 0 */
#define P11OE           OEP1bits.P11OE          /* bit 1 */
#define P12OE           OEP1bits.P12OE          /* bit 2 */

// ----- PUP1 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P10PU:1;
                unsigned char P11PU:1;
                unsigned char P12PU:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
        };
} __PUP1bits_t;
extern volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;

#define P10PU           PUP1bits.P10PU          /* bit 0 */
#define P11PU           PUP1bits.P11PU          /* bit 1 */
#define P12PU           PUP1bits.P12PU          /* bit 2 */

// ----- PDP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P10PD:1;
		unsigned char P11PD:1;
		unsigned char P12PD:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __PDP1bits_t;
extern volatile __PDP1bits_t __at(PDP1_ADDR) PDP1bits;

#define P10PD     	    PDP1bits.P10PD      	        /* bit 0 */
#define P11PD     	    PDP1bits.P11PD      	        /* bit 1 */
#define P12PD     	    PDP1bits.P12PD      	        /* bit 2 */

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
                unsigned char :1;
        };
} __IOP2bits_t;
extern volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;

#define P20D            IOP2bits.P20D           /* bit 0 */
#define P21D            IOP2bits.P21D           /* bit 1 */
#define P22D            IOP2bits.P22D           /* bit 2 */
#define P23D            IOP2bits.P23D           /* bit 3 */
#define P24D            IOP2bits.P24D           /* bit 4 */
#define P25D            IOP2bits.P25D           /* bit 5 */
#define P26D            IOP2bits.P26D           /* bit 6 */

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
                unsigned char :1;
        };
} __OEP2bits_t;
extern volatile __OEP2bits_t __at(OEP2_ADDR) OEP2bits;

#define P20OE           OEP2bits.P20OE          /* bit 0 */
#define P21OE           OEP2bits.P21OE          /* bit 1 */
#define P22OE           OEP2bits.P22OE          /* bit 2 */
#define P23OE           OEP2bits.P23OE          /* bit 3 */
#define P24OE           OEP2bits.P24OE          /* bit 4 */
#define P25OE           OEP2bits.P25OE          /* bit 5 */
#define P26OE           OEP2bits.P26OE          /* bit 6 */

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
                unsigned char :1;
        };
} __PUP2bits_t;
extern volatile __PUP2bits_t __at(PUP2_ADDR) PUP2bits;

#define P20PU           PUP2bits.P20PU          /* bit 0 */
#define P21PU           PUP2bits.P21PU          /* bit 1 */
#define P22PU           PUP2bits.P22PU          /* bit 2 */
#define P23PU           PUP2bits.P23PU          /* bit 3 */
#define P24PU           PUP2bits.P24PU          /* bit 4 */
#define P25PU           PUP2bits.P25PU          /* bit 5 */
#define P26PU           PUP2bits.P26PU          /* bit 6 */

// ----- PDP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P20PD:1;
		unsigned char P21PD:1;
		unsigned char P22PD:1;
		unsigned char P23PD:1;
		unsigned char P24PD:1;
		unsigned char P25PD:1;
		unsigned char P26PD:1;
		unsigned char :1;
	};
} __PDP2bits_t;
extern volatile __PDP2bits_t __at(PDP2_ADDR) PDP2bits;

#define P20PD         	PDP2bits.P20PD          /* bit 0 */
#define P21PD     	    PDP2bits.P20PD      	  /* bit 1 */
#define P22PD         	PDP2bits.P20PD      	  /* bit 2 */
#define P23PD         	PDP2bits.P20PD      	  /* bit 3 */
#define P24PD         	PDP2bits.P20PD      	  /* bit 4 */
#define P25PD     	    PDP2bits.P20PD      	  /* bit 5 */
#define P26PD     	    PDP2bits.P20PD      	  /* bit 6 */

// ----- IOP3 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P30D:1;
                unsigned char P31D:1;
                unsigned char P32D:1;
                unsigned char P33D:1;
                unsigned char P34D:1;
                unsigned char P35D:1;
                unsigned char P36D:1;
                unsigned char P37D:1;
        };
} __IOP3bits_t;
extern volatile __IOP3bits_t __at(IOP3_ADDR) IOP3bits;

#define P30D            IOP3bits.P30D           /* bit 0 */
#define P31D            IOP3bits.P31D           /* bit 1 */
#define P32D            IOP3bits.P32D           /* bit 2 */
#define P33D            IOP3bits.P33D           /* bit 3 */
#define P34D            IOP3bits.P34D           /* bit 4 */
#define P35D            IOP3bits.P35D           /* bit 5 */
#define P36D            IOP3bits.P36D           /* bit 6 */
#define P37D            IOP3bits.P37D           /* bit 7 */

// ----- OEP3 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P30OE:1;
                unsigned char P31OE:1;
                unsigned char P32OE:1;
                unsigned char P33OE:1;
                unsigned char P34OE:1;
                unsigned char P35OE:1;
                unsigned char P36OE:1;
                unsigned char P37OE:1;
        };
} __OEP3bits_t;
extern volatile __OEP3bits_t __at(OEP3_ADDR) OEP3bits;

#define P30OE           OEP3bits.P30OE          /* bit 0 */
#define P31OE           OEP3bits.P31OE          /* bit 1 */
#define P32OE           OEP3bits.P32OE          /* bit 2 */
#define P33OE           OEP3bits.P33OE          /* bit 3 */
#define P34OE           OEP3bits.P34OE          /* bit 4 */
#define P35OE           OEP3bits.P35OE          /* bit 5 */
#define P36OE           OEP3bits.P36OE          /* bit 6 */
#define P37OE           OEP3bits.P37OE          /* bit 7 */

// ----- PUP3 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P30PU:1;
                unsigned char P31PU:1;
                unsigned char P32PU:1;
                unsigned char P33PU:1;
                unsigned char P34PU:1;
                unsigned char P35PU:1;
                unsigned char P36PU:1;
                unsigned char P37PU:1;
        };
} __PUP3bits_t;
extern volatile __PUP3bits_t __at(PUP3_ADDR) PUP3bits;

#define P30PU           PUP3bits.P30PU          /* bit 0 */
#define P31PU           PUP3bits.P31PU          /* bit 1 */
#define P32PU           PUP3bits.P32PU          /* bit 2 */
#define P33PU           PUP3bits.P33PU          /* bit 3 */
#define P34PU           PUP3bits.P34PU          /* bit 4 */
#define P35PU           PUP3bits.P35PU          /* bit 5 */
#define P36PU           PUP3bits.P36PU          /* bit 6 */
#define P37PU           PUP3bits.P36PU          /* bit 7 */

// ----- PDP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P30PD:1;
		unsigned char P31PD:1;
		unsigned char P32PD:1;
		unsigned char P33PD:1;
		unsigned char P34PD:1;
		unsigned char P35PD:1;
		unsigned char P36PD:1;
		unsigned char P37PD:1;
	};
} __PDP3bits_t;
extern volatile __PDP3bits_t __at(PDP3_ADDR) PDP3bits;

#define P30PD     	    PDP3bits.P30PD      	  /* bit 0 */
#define P31PD     	    PDP3bits.P31PD      	  /* bit 1 */
#define P32PD     	    PDP3bits.P32PD      	  /* bit 2 */
#define P33PD     	    PDP3bits.P33PD      	  /* bit 3 */
#define P34PD     	    PDP3bits.P34PD      	  /* bit 4 */
#define P35PD     	    PDP3bits.P35PD      	  /* bit 5 */
#define P36PD     	    PDP3bits.P36PD      	  /* bit 6 */
#define P37PD     	    PDP3bits.P37PD      	  /* bit 7 */

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

#define T0PR            T0CRbits.T0PR           /* bit 2-0 */
#define T0PTS           T0CRbits.T0PTS          /* bit 4-3 */
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

#define T0C0            T0CNTbits.T0C0          /* bit 0 */
#define T0C1            T0CNTbits.T0C1          /* bit 1 */
#define T0C2            T0CNTbits.T0C2          /* bit 2 */
#define T0C3            T0CNTbits.T0C3          /* bit 3 */
#define T0C4            T0CNTbits.T0C4          /* bit 4 */
#define T0C5            T0CNTbits.T0C5          /* bit 5 */
#define T0C6            T0CNTbits.T0C6          /* bit 6 */
#define T0C7            T0CNTbits.T0C7          /* bit 7 */

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

#define T0LOAD0         T0LOADbits.T0LOAD0      /* bit 0 */
#define T0LOAD1         T0LOADbits.T0LOAD1      /* bit 1 */
#define T0LOAD2         T0LOADbits.T0LOAD2      /* bit 2 */
#define T0LOAD3         T0LOADbits.T0LOAD3      /* bit 3 */
#define T0LOAD4         T0LOADbits.T0LOAD4      /* bit 4 */
#define T0LOAD5         T0LOADbits.T0LOAD5      /* bit 5 */
#define T0LOAD6         T0LOADbits.T0LOAD6      /* bit 6 */
#define T0LOAD7         T0LOADbits.T0LOAD7      /* bit 7 */

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

#define T0DATA0     	T0DATAbits.T0DATA0        	/* bit 0 */
#define T0DATA1     	T0DATAbits.T0DATA1       	  /* bit 1 */
#define T0DATA2     	T0DATAbits.T0DATA2      	  /* bit 2 */
#define T0DATA3     	T0DATAbits.T0DATA3      	  /* bit 3 */
#define T0DATA4     	T0DATAbits.T0DATA4      	  /* bit 4 */
#define T0DATA5     	T0DATAbits.T0DATA5      	  /* bit 5 */
#define T0DATA6     	T0DATAbits.T0DATA6      	  /* bit 6 */
#define T0DATA7     	T0DATAbits.T0DATA7      	  /* bit 7 */

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

#define T1PR      	    T1CRbits.T1PR           	/* bit 2-0 */
#define T1PTS     	    T1CRbits.T1PTS      	    /* bit 4-3 */
#define BUZ1OE   	      T1CRbits.BUZ1OE    	      /* bit 5 */
#define PWM1OE   	      T1CRbits.PWM1OE    	      /* bit 6 */
#define TC1EN    	      T1CRbits.TC1EN        	  /* bit 7 */

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

#define T1C0            T1CNTbits.T1C0          /* bit 0 */
#define T1C1            T1CNTbits.T1C1          /* bit 1 */
#define T1C2            T1CNTbits.T1C2          /* bit 2 */
#define T1C3            T1CNTbits.T1C3          /* bit 3 */
#define T1C4            T1CNTbits.T1C4          /* bit 4 */
#define T1C5            T1CNTbits.T1C5          /* bit 5 */
#define T1C6            T1CNTbits.T1C6          /* bit 6 */
#define T1C7            T1CNTbits.T1C7          /* bit 7 */

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

#define T1LOAD0      	  T1LOADbits.T1LOAD0       	/* bit 0 */
#define T1LOAD1     	  T1LOADbits.T1LOAD1      	/* bit 1 */
#define T1LOAD2    	    T1LOADbits.T1LOAD2     	  /* bit 2 */
#define T1LOAD3    	    T1LOADbits.T1LOAD3     	  /* bit 3 */
#define T1LOAD4    	    T1LOADbits.T1LOAD4     	  /* bit 4 */
#define T1LOAD5    	    T1LOADbits.T1LOAD5     	  /* bit 5 */
#define T1LOAD6    	    T1LOADbits.T1LOAD6     	  /* bit 6 */
#define T1LOAD7    	    T1LOADbits.T1LOAD7     	  /* bit 7 */

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

#define T1DATA0      	  T1DATAbits.T1DATA0       	/* bit 0 */
#define T1DATA1     	  T1DATAbits.T1DATA1      	/* bit 1 */
#define T1DATA2    	    T1DATAbits.T1DATA2     	  /* bit 2 */
#define T1DATA3    	    T1DATAbits.T1DATA3     	  /* bit 3 */
#define T1DATA4    	    T1DATAbits.T1DATA4     	  /* bit 4 */
#define T1DATA5    	    T1DATAbits.T1DATA5     	  /* bit 5 */
#define T1DATA6    	    T1DATAbits.T1DATA6     	  /* bit 6 */
#define T1DATA7    	    T1DATAbits.T1DATA7     	  /* bit 7 */

// ----- T2CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2PR:3;
		unsigned char T2PTS:2;
		unsigned char T2MODE:1;
		unsigned char :1;  
		unsigned char TC2EN:1;	
	};
} __T2CRbits_t;
extern volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;

#define T2PR      	    T2CRbits.T2PR           	/* bit 2-0 */
#define T2PTS     	    T2CRbits.T2PTS      	    /* bit 4-3 */
#define T2MODE   	      T2CRbits.T2MODE    	      /* bit 5 */
#define TC2EN    	      T2CRbits.TC2EN        	  /* bit 7 */

// ----- T2CNTH Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T2C8:1;
                unsigned char T2C9:1;
                unsigned char T2C10:1;
                unsigned char T2C11:1;
                unsigned char T2C12:1;
                unsigned char T2C13:1;
                unsigned char T2C14:1;
                unsigned char T2C15:1;
        };
} __T2CNTHbits_t;
extern volatile __T2CNTHbits_t __at(T2CNTH_ADDR) T2CNTHbits;

#define T2C8            T2CNTHbits.T2C8           /* bit 0 */
#define T2C9            T2CNTHbits.T2C9           /* bit 1 */
#define T2C10           T2CNTHbits.T2C10          /* bit 2 */
#define T2C11           T2CNTHbits.T2C11          /* bit 3 */
#define T2C12           T2CNTHbits.T2C12          /* bit 4 */
#define T2C13           T2CNTHbits.T2C13          /* bit 5 */
#define T2C14           T2CNTHbits.T2C14          /* bit 6 */
#define T2C15           T2CNTHbits.T2C15          /* bit 7 */

// ----- T2CNTL Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T2C0:1;
                unsigned char T2C1:1;
                unsigned char T2C2:1;
                unsigned char T2C3:1;
                unsigned char T2C4:1;
                unsigned char T2C5:1;
                unsigned char T2C6:1;
                unsigned char T2C7:1;
        };
} __T2CNTLbits_t;
extern volatile __T2CNTLbits_t __at(T2CNTL_ADDR) T2CNTLbits;

#define T2C0            T2CNTLbits.T2C0         /* bit 0 */
#define T2C1            T2CNTLbits.T2C1         /* bit 1 */
#define T2C2            T2CNTLbits.T2C2         /* bit 2 */
#define T2C3            T2CNTLbits.T2C3         /* bit 3 */
#define T2C4            T2CNTLbits.T2C4         /* bit 4 */
#define T2C5            T2CNTLbits.T2C5         /* bit 5 */
#define T2C6            T2CNTLbits.T2C6         /* bit 6 */
#define T2C7            T2CNTLbits.T2C7         /* bit 7 */

// ----- T2LOADH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2LOAD8:1;
		unsigned char T2LOAD9:1;
		unsigned char T2LOAD10:1;
		unsigned char T2LOAD11:1;
		unsigned char T2LOAD12:1;
		unsigned char T2LOAD13:1;
		unsigned char T2LOAD14:1;
		unsigned char T2LOAD15:1;	
	};
} __T2LOADHbits_t;
extern volatile __T2LOADHbits_t __at(T2LOADH_ADDR) T2LOADHbits;

#define T2LOAD8      	  T2LOADHbits.T2LOAD8       	/* bit 0 */
#define T2LOAD9     	  T2LOADHbits.T2LOAD9      	  /* bit 1 */
#define T2LOAD10        T2LOADHbits.T2LOAD10     	  /* bit 2 */
#define T2LOAD11    	  T2LOADHbits.T2LOAD11     	  /* bit 3 */
#define T2LOAD12    	  T2LOADHbits.T2LOAD12     	  /* bit 4 */
#define T2LOAD13    	  T2LOADHbits.T2LOAD13     	  /* bit 5 */
#define T2LOAD14    	  T2LOADHbits.T2LOAD14     	  /* bit 6 */
#define T2LOAD15    	  T2LOADHbits.T2LOAD15     	  /* bit 7 */

// ----- T2LOADL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T2LOAD0:1;
		unsigned char T2LOAD1:1;
		unsigned char T2LOAD2:1;
		unsigned char T2LOAD3:1;
		unsigned char T2LOAD4:1;
		unsigned char T2LOAD5:1;
		unsigned char T2LOAD6:1;
		unsigned char T2LOAD7:1;	
	};
} __T2LOADLbits_t;
extern volatile __T2LOADLbits_t __at(T2LOADL_ADDR) T2LOADLbits;

#define T2LOAD0      	  T2LOADLbits.T2LOAD0       	/* bit 0 */
#define T2LOAD1     	  T2LOADLbits.T2LOAD1      	  /* bit 1 */
#define T2LOAD2    	    T2LOADLbits.T2LOAD2     	  /* bit 2 */
#define T2LOAD3    	    T2LOADLbits.T2LOAD3     	  /* bit 3 */
#define T2LOAD4    	    T2LOADLbits.T2LOAD4     	  /* bit 4 */
#define T2LOAD5    	    T2LOADLbits.T2LOAD5     	  /* bit 5 */
#define T2LOAD6    	    T2LOADLbits.T2LOAD6     	  /* bit 6 */
#define T2LOAD7    	    T2LOADLbits.T2LOAD7     	  /* bit 7 */

// ----- TK0CR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK0FQ:3;
		unsigned char TK0CLR:1;
		unsigned char TK0RCE:1;
		unsigned char TK0JE:1;
		unsigned char :1;
		unsigned char :1;	
	};
} __TK0CR0bits_t;
extern volatile __TK0CR0bits_t __at(TK0CR0_ADDR) TK0CR0bits;

#define TK0FQ      	    TK0CR0bits.TK0FQ       	  /* bit 2-0 */
#define TK0CLR      	  TK0CR0bits.TK0CLR       	/* bit 3 */
#define TK0RCE    	    TK0CR0bits.TK0RCE     	  /* bit 4 */
#define TK0JE     	    TK0CR0bits.TK0JE      	  /* bit 5 */

// ---- TK0CR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK0K:3;
                unsigned char :1;  
                unsigned char TK0FL:2;
                unsigned char TK0IE:1;
                unsigned char TK0IF:1;
        };
} __TK0CR1bits_t;
extern volatile __TK0CR1bits_t __at(TK0CR1_ADDR) TK0CR1bits;

#define TK0K            TK0CR1bits.TK0K            /* bit 2-0 */
#define TK0FL           TK0CR1bits.TK0FL           /* bit 5-4 */
#define TK0IE           TK0CR1bits.TK0IE           /* bit 6 */
#define TK0IF           TK0CR1bits.TK0IF           /* bit 7 */

// ---- TK0CR2 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK0IO0:1;
                unsigned char TK0IO1:1;
                unsigned char TK0IO2:1;
                unsigned char TK0IO3:1;
                unsigned char TK0IO4:1;
                unsigned char TK0IO5:1;
                unsigned char TK0IO6:1;
                unsigned char TK0IO7:1;  
        };
} __TK0CR2bits_t;
extern volatile __TK0CR2bits_t __at(TK0CR2_ADDR) TK0CR2bits;

#define TK0IO0          TK0CR2bits.TK0IO0          /* bit 0 */
#define TK0IO1          TK0CR2bits.TK0IO1          /* bit 1 */
#define TK0IO2          TK0CR2bits.TK0IO2          /* bit 2 */
#define TK0IO3          TK0CR2bits.TK0IO3          /* bit 3 */
#define TK0IO4          TK0CR2bits.TK0IO4          /* bit 4 */
#define TK0IO5          TK0CR2bits.TK0IO5          /* bit 5 */
#define TK0IO6          TK0CR2bits.TK0IO6          /* bit 6 */
#define TK0IO7          TK0CR2bits.TK0IO7          /* bit 7 */

// ---- TK0CNTH Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK0C8:1;
                unsigned char TK0C9:1;
                unsigned char TK0C10:1;
                unsigned char TK0C11:1;
                unsigned char TK0C12:1;  
                unsigned char TK0C13:1;
                unsigned char TK0C14:1;
                unsigned char TK0C15:1;
        };
} __TK0CNTHbits_t;
extern volatile __TK0CNTHbits_t __at(TK0CNTH_ADDR) TK0CNTHbits;

#define TK0C8           TK0CNTHbits.TK0C8          /* bit 0 */
#define TK0C9           TK0CNTHbits.TK0C9          /* bit 1 */
#define TK0C10          TK0CNTHbits.TK0C10         /* bit 2 */
#define TK0C11          TK0CNTHbits.TK0C11         /* bit 3 */
#define TK0C12          TK0CNTHbits.TK0C12         /* bit 4 */
#define TK0C13          TK0CNTHbits.TK0C13         /* bit 5 */
#define TK0C14          TK0CNTHbits.TK0C14         /* bit 6 */
#define TK0C15          TK0CNTHbits.TK0C15         /* bit 7 */

// ----- TK0CNTL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK0C0:1;
		unsigned char TK0C1:1;
		unsigned char TK0C2:1;
		unsigned char TK0C3:1;
		unsigned char TK0C4:1;
		unsigned char TK0C5:1;
		unsigned char TK0C6:1;
		unsigned char TK0C7:1;	
	};
} __TK0CNTLbits_t;
extern volatile __TK0CNTLbits_t __at(TK0CNTL_ADDR) TK0CNTLbits;

#define TK0C0      	    TK0CNTLbits.TK0C0        	 /* bit 0 */
#define TK0C1      	    TK0CNTLbits.TK0C1      	   /* bit 1 */
#define TK0C2      	    TK0CNTLbits.TK0C2     	   /* bit 2 */
#define TK0C3    	      TK0CNTLbits.TK0C3      	   /* bit 3 */
#define TK0C4     	    TK0CNTLbits.TK0C4     	   /* bit 4 */
#define TK0C5    	      TK0CNTLbits.TK0C5      	   /* bit 5 */
#define TK0C6    	      TK0CNTLbits.TK0C6      	   /* bit 6 */
#define TK0C7    	      TK0CNTLbits.TK0C7     	   /* bit 7 */

// ----- TK1CR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK1FQ:3;
		unsigned char TK1CLR:1;
		unsigned char TK1RCE:1;
		unsigned char TK1JE:1;
		unsigned char :1;
		unsigned char :1;	
	};
} __TK1CR0bits_t;
extern volatile __TK1CR0bits_t __at(TK1CR0_ADDR) TK1CR0bits;

#define TK1FQ      	    TK1CR0bits.TK1FQ       	  /* bit 2-0 */
#define TK1CLR      	  TK1CR0bits.TK1CLR       	/* bit 3 */
#define TK1RCE    	    TK1CR0bits.TK1RCE     	  /* bit 4 */
#define TK1JE     	    TK1CR0bits.TK1JE      	  /* bit 5 */

// ---- TK1CR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK1K:3;
                unsigned char :1;  
                unsigned char TK1FL:2;
                unsigned char TK1IE:1;
                unsigned char TK1IF:1;
        };
} __TK1CR1bits_t;
extern volatile __TK1CR1bits_t __at(TK1CR1_ADDR) TK1CR1bits;

#define TK1K            TK0CR1bits.TK1K            /* bit 2-0 */
#define TK1FL           TK0CR1bits.TK1FL           /* bit 5-4 */
#define TK1IE           TK0CR1bits.TK1IE           /* bit 6 */
#define TK1IF           TK0CR1bits.TK1IF           /* bit 7 */

// ---- TK1CR2 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK1IO0:1;
                unsigned char TK1IO1:1;
                unsigned char TK1IO2:1;
                unsigned char TK1IO3:1;
                unsigned char TK1IO4:1;
                unsigned char TK1IO5:1;
                unsigned char TK1IO6:1;
                unsigned char TK1IO7:1;  
        };
} __TK1CR2bits_t;
extern volatile __TK1CR2bits_t __at(TK1CR2_ADDR) TK1CR2bits;

#define TK1IO0          TK1CR2bits.TK1IO0          /* bit 0 */
#define TK1IO1          TK1CR2bits.TK1IO1          /* bit 1 */
#define TK1IO2          TK1CR2bits.TK1IO2          /* bit 2 */
#define TK1IO3          TK1CR2bits.TK1IO3          /* bit 3 */
#define TK1IO4          TK1CR2bits.TK1IO4          /* bit 4 */
#define TK1IO5          TK1CR2bits.TK1IO5          /* bit 5 */
#define TK1IO6          TK1CR2bits.TK1IO6          /* bit 6 */
#define TK1IO7          TK1CR2bits.TK1IO7          /* bit 7 */

// ---- TK1CNTH Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char TK1C8:1;
                unsigned char TK1C9:1;
                unsigned char TK1C10:1;
                unsigned char TK1C11:1;
                unsigned char TK1C12:1;  
                unsigned char TK1C13:1;
                unsigned char TK1C14:1;
                unsigned char TK1C15:1;
        };
} __TK1CNTHbits_t;
extern volatile __TK1CNTHbits_t __at(TK1CNTH_ADDR) TK1CNTHbits;

#define TK1C8           TK1CNTHbits.TK1C8          /* bit 0 */
#define TK1C9           TK1CNTHbits.TK1C9          /* bit 1 */
#define TK1C10          TK1CNTHbits.TK1C10         /* bit 2 */
#define TK1C11          TK1CNTHbits.TK1C11         /* bit 3 */
#define TK1C12          TK1CNTHbits.TK1C12         /* bit 4 */
#define TK1C13          TK1CNTHbits.TK1C13         /* bit 5 */
#define TK1C14          TK1CNTHbits.TK1C14         /* bit 6 */
#define TK1C15          TK1CNTHbits.TK1C15         /* bit 7 */

// ----- TK1CNTL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char TK1C0:1;
		unsigned char TK1C1:1;
		unsigned char TK1C2:1;
		unsigned char TK1C3:1;
		unsigned char TK1C4:1;
		unsigned char TK1C5:1;
		unsigned char TK1C6:1;
		unsigned char TK1C7:1;	
	};
} __TK1CNTLbits_t;
extern volatile __TK1CNTLbits_t __at(TK1CNTL_ADDR) TK1CNTLbits;

#define TK1C0      	    TK1CNTLbits.TK1C0        	 /* bit 0 */
#define TK1C1      	    TK1CNTLbits.TK1C1      	   /* bit 1 */
#define TK1C2      	    TK1CNTLbits.TK1C2     	   /* bit 2 */
#define TK1C3    	      TK1CNTLbits.TK1C3      	   /* bit 3 */
#define TK1C4     	    TK1CNTLbits.TK1C4     	   /* bit 4 */
#define TK1C5    	      TK1CNTLbits.TK1C5      	   /* bit 5 */
#define TK1C6    	      TK1CNTLbits.TK1C6      	   /* bit 6 */
#define TK1C7    	      TK1CNTLbits.TK1C7     	   /* bit 7 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADON:1;
		unsigned char ADEOC:1;
		unsigned char :1;
		unsigned char ADCHS:5;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADON          	ADCR0bits.ADON     	       /* bit 0 */
#define ADEOC  	        ADCR0bits.ADEOC   	       /* bit 1 */
#define ADCHS  	        ADCR0bits.ADCHS 	         /* bit 7-3 */

// ----- ADCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VREFP_PHEN:1;
		unsigned char ADCKS:2;
		unsigned char ADREF:4;
		unsigned char ADTEN:1;	
	};
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define VREFP_PHEN 	    ADCR1bits.VREFP_PHEN   	   /* bit 0 */
#define ADCKS      	    ADCR1bits.ADCKS      	     /* bit 2-1 */
#define ADREF      	    ADCR1bits.ADREF     	     /* bit 6-3 */
#define ADTEN    	      ADCR1bits.ADTEN     	     /* bit 7 */

// ----- ADCR2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADSMP:4;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;  	
	};
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define ADSMP 	        ADCR2bits.ADSMP   	       /* bit 3-0 */

// ---- ADIO0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char ADIOS0:1;
                unsigned char ADIOS1:1;
                unsigned char ADIOS2:1;
                unsigned char ADIOS3:1;
                unsigned char ADIOS4:1;
                unsigned char ADIOS5:1;
                unsigned char ADIOS6:1;
                unsigned char ADIOS7:1;  
        };
} __ADIO0bits_t;
extern volatile __ADIO0bits_t __at(ADIO0_ADDR) ADIO0bits;

#define ADIOS0          ADIO0bits.ADIOS0          /* bit 0 */
#define ADIOS1          ADIO0bits.ADIOS1          /* bit 1 */
#define ADIOS2          ADIO0bits.ADIOS2          /* bit 2 */
#define ADIOS3          ADIO0bits.ADIOS3          /* bit 3 */
#define ADIOS4          ADIO0bits.ADIOS4          /* bit 4 */
#define ADIOS5          ADIO0bits.ADIOS5          /* bit 5 */
#define ADIOS6          ADIO0bits.ADIOS6          /* bit 6 */
#define ADIOS7          ADIO0bits.ADIOS7          /* bit 7 */

// ---- ADIO1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char ADIOS8:1;
                unsigned char ADIOS9:1;
                unsigned char ADIOS10:1;
                unsigned char ADIOS11:1;
                unsigned char ADIOS12:1;  
                unsigned char ADIOS13:1;
                unsigned char ADIOS14:1;
                unsigned char ADIOS15:1;
        };
} __ADIO1bits_t;
extern volatile __ADIO1bits_t __at(ADIO1_ADDR) ADIO1bits;

#define ADIOS8          ADIO1bits.ADIOS8         /* bit 0 */
#define ADIOS9          ADIO1bits.ADIOS9         /* bit 1 */
#define ADIOS10         ADIO1bits.ADIOS10        /* bit 2 */
#define ADIOS11         ADIO1bits.ADIOS11        /* bit 3 */
#define ADIOS12         ADIO1bits.ADIOS12        /* bit 4 */
#define ADIOS13         ADIO1bits.ADIOS13        /* bit 5 */
#define ADIOS14         ADIO1bits.ADIOS14        /* bit 6 */
#define ADIOS15         ADIO1bits.ADIOS15        /* bit 7 */

// ---- ADRH Bits ----------------------------------------------
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

#define ADR4            ADRHbits.ADR4           /* bit 0 */
#define ADR5            ADRHbits.ADR5           /* bit 1 */
#define ADR6            ADRHbits.ADR6           /* bit 2 */
#define ADR7            ADRHbits.ADR7           /* bit 3 */
#define ADR8            ADRHbits.ADR8           /* bit 4 */
#define ADR9            ADRHbits.ADR9           /* bit 5 */
#define ADR10           ADRHbits.ADR10          /* bit 6 */
#define ADR11           ADRHbits.ADR11          /* bit 7 */

// ---- ADRL Bits ----------------------------------------------
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

#define ADR0            ADRLbits.ADR0           /* bit 0 */
#define ADR1            ADRLbits.ADR1           /* bit 1 */
#define ADR2            ADRLbits.ADR2           /* bit 2 */
#define ADR3            ADRLbits.ADR3           /* bit 3 */

// ---- LEDCR0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char GYS:3;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char DUTY:1;  
                unsigned char LEDEN:1;
        };
} __LEDCR0bits_t;
extern volatile __LEDCR0bits_t __at(LEDCR0_ADDR) LEDCR0bits;

#define GYS             LEDCR0bits.GYS            /* bit 2-0 */
#define DUTY            LEDCR0bits.DUTY           /* bit 6 */
#define LEDEN           LEDCR0bits.LEDEN          /* bit 7 */

// ---- LEDCR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char FLED:2;
                unsigned char IREFEN:1;
                unsigned char IBPS:2;
                unsigned char CLKS0:1;
                unsigned char CLKS1:1;
                unsigned char DRVPS:1;
        };
} __LEDCR1bits_t;
extern volatile __LEDCR1bits_t __at(LEDCR1_ADDR) LEDCR1bits;

#define FLED            LEDCR1bits.FLED           /* bit 1-0 */
#define IREFEN          LEDCR1bits.IREFEN         /* bit 2 */
#define IBPS            LEDCR1bits.IBPS           /* bit 4-3 */
#define CLKS0           LEDCR1bits.CLKS0          /* bit 5 */
#define CLKS1           LEDCR1bits.CLKS1          /* bit 6 */
#define DRVPS           LEDCR1bits.DRVPS          /* bit 7 */

// ---- LEDIOS0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char COMIOS1:1;
                unsigned char COMIOS2:1;
                unsigned char COMIOS3:1;
                unsigned char COMIOS4:1;
                unsigned char COMIOS5:1;
                unsigned char COMIOS6:1;
                unsigned char COMIOS7:1;
                unsigned char COMIOS8:1;  
        };
} __LEDIOS0bits_t;
extern volatile __LEDIOS0bits_t __at(LEDIOS0_ADDR) LEDIOS0bits;

#define COMIOS1          LEDIOS0bits.COMIOS1          /* bit 0 */
#define COMIOS2          LEDIOS0bits.COMIOS2          /* bit 1 */
#define COMIOS3          LEDIOS0bits.COMIOS3          /* bit 2 */
#define COMIOS4          LEDIOS0bits.COMIOS4          /* bit 3 */
#define COMIOS5          LEDIOS0bits.COMIOS5          /* bit 4 */
#define COMIOS6          LEDIOS0bits.COMIOS6          /* bit 5 */
#define COMIOS7          LEDIOS0bits.COMIOS7          /* bit 6 */
#define COMIOS8          LEDIOS0bits.COMIOS8          /* bit 7 */

// ---- LEDIOS1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char SEGIOS1:1;
                unsigned char SEGIOS2:1;
                unsigned char SEGIOS3:1;
                unsigned char SEGIOS4:1;
                unsigned char SEGIOS5:1;
                unsigned char SEGIOS6:1;
                unsigned char SEGIOS7:1;
                unsigned char SEGIOS8:1;  
        };
} __LEDIOS1bits_t;
extern volatile __LEDIOS1bits_t __at(LEDIOS1_ADDR) LEDIOS1bits;

#define SEGIOS1          LEDIOS1bits.SEGIOS1          /* bit 0 */
#define SEGIOS2          LEDIOS1bits.SEGIOS2          /* bit 1 */
#define SEGIOS3          LEDIOS1bits.SEGIOS3          /* bit 2 */
#define SEGIOS4          LEDIOS1bits.SEGIOS4          /* bit 3 */
#define SEGIOS5          LEDIOS1bits.SEGIOS5          /* bit 4 */
#define SEGIOS6          LEDIOS1bits.SEGIOS6          /* bit 5 */
#define SEGIOS7          LEDIOS1bits.SEGIOS7          /* bit 6 */
#define SEGIOS8          LEDIOS1bits.SEGIOS8          /* bit 7 */

// ---- LEDDRV Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char COMDV1:1;
                unsigned char COMDV2:1;
                unsigned char COMDV3:1;
                unsigned char COMDV4:1;
                unsigned char COMDV5:1;
                unsigned char COMDV6:1;
                unsigned char COMDV7:1;
                unsigned char COMDV8:1;  
        };
} __LEDDRVbits_t;
extern volatile __LEDDRVbits_t __at(LEDDRV_ADDR) LEDDRVbits;

#define COMDV1          LEDDRVbits.COMDV1          /* bit 0 */
#define COMDV2          LEDDRVbits.COMDV2          /* bit 1 */
#define COMDV3          LEDDRVbits.COMDV3          /* bit 2 */
#define COMDV4          LEDDRVbits.COMDV4          /* bit 3 */
#define COMDV5          LEDDRVbits.COMDV5          /* bit 4 */
#define COMDV6          LEDDRVbits.COMDV6          /* bit 5 */
#define COMDV7          LEDDRVbits.COMDV7          /* bit 6 */
#define COMDV8          LEDDRVbits.COMDV8          /* bit 7 */

#endif
