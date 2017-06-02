#ifndef MC32P7311_H
#define MC32P7311_H

#include <mc3x-common.h>

//
// Register addresses.
//
#define INDF_ADDR               0x0180
#define INDF0_ADDR              0x0180
#define INDF1_ADDR              0x0181
#define INDF2_ADDR              0x0182
#define HIBYTE_ADDR             0x0183
#define FSR_ADDR                0x0184
#define FSR0_ADDR               0x0184
#define FSR1_ADDR               0x0185
#define PCL_ADDR                0x0186
#define STATUS_ADDR             0x0187
#define PFLAG_ADDR     	        0x0187
#define MCR_ADDR                0x0188
#define INDF3_ADDR              0x0189
#define INTE_ADDR               0x018A
#define INTF_ADDR               0x018B
#define DRVCR_ADDR              0x018C
#define KBCR_ADDR               0x018E

#define IOP0_ADDR               0x0190
#define OEP0_ADDR               0x0191
#define PUP0_ADDR               0x0192
#define PDP0_ADDR               0x0193
#define IOP1_ADDR               0x0194
#define OEP1_ADDR               0x0195
#define PUP1_ADDR               0x0196
#define PDP1_ADDR               0x0197

#define T0CR_ADDR               0x0198
#define T0CNT_ADDR              0x0199
#define T0LOAD_ADDR             0x019A
#define T0DATA_ADDR             0x019B
#define T1CR_ADDR               0x019C
#define T1CNT_ADDR              0x019D
#define T1LOAD_ADDR             0x019E
#define T1DATA_ADDR             0x019F

#define T2CR_ADDR               0x01A0
#define T2CNT_ADDR              0x01A1
#define T2LOAD_ADDR             0x01A2
#define T2DATA_ADDR             0x01A3
#define T3CR_ADDR               0x01A4
#define T3CNT_ADDR              0x01A5
#define T3LOAD_ADDR             0x01A6

#define PWM0DE_ADDR             0x01A8
#define PWM1DE_ADDR             0x01A9
#define PWM2DE_ADDR             0x01AA
#define PWMCR0_ADDR             0x01AC
#define PWMCR1_ADDR             0x01AD
#define OSCM_ADDR               0x01AE
#define LVDCR_ADDR              0x01AF

#define ADCR0_ADDR              0x01B0
#define ADCR1_ADDR              0x01B1
#define ADCR2_ADDR              0x01B2
#define ADRH_ADDR               0x01B4
#define ADRL_ADDR               0x01B5
#define ANSEL0_ADDR             0x01B6
#define ANSEL1_ADDR             0x01B7

#define VBGCAL_ADDR             0x01F8
#define OSCCALH_ADDR            0x01FB
#define OSCCALL_ADDR            0x01FC

//----- Register Files -----------------------------------------------------

extern __sfr __at (INDF_ADDR)           INDF;
extern __sfr __at (INDF0_ADDR)          INDF0;
extern __sfr __at (INDF1_ADDR)          INDF1;
extern __sfr __at (INDF2_ADDR)          INDF2;
extern __sfr __at (HIBYTE_ADDR)         HIBYTE;
extern __sfr __at (FSR_ADDR)            FSR;
extern __sfr __at (FSR0_ADDR)           FSR0;
extern __sfr __at (FSR1_ADDR)           FSR1;
extern __sfr __at (PCL_ADDR)            PCL;
extern __sfr __at (STATUS_ADDR)         STATUS;
extern __sfr __at (PFLAG_ADDR)          PFLAG;
extern __sfr __at (MCR_ADDR)            MCR;
extern __sfr __at (INDF3_ADDR)          INDF3;
extern __sfr __at (INTE_ADDR)           INTE;
extern __sfr __at (INTF_ADDR)           INTF;
extern __sfr __at (DRVCR_ADDR)          DRVCR;
extern __sfr __at (KBCR_ADDR)           KBCR;
extern __sfr __at (IOP0_ADDR)           IOP0;
extern __sfr __at (OEP0_ADDR)           OEP0;
extern __sfr __at (PUP0_ADDR)           PUP0;
extern __sfr __at (PDP0_ADDR)           PDP0;
extern __sfr __at (IOP1_ADDR)           IOP1;
extern __sfr __at (OEP1_ADDR)           OEP1;
extern __sfr __at (PUP1_ADDR)  	        PUP1;
extern __sfr __at (PDP1_ADDR)  	        PDP1;
extern __sfr __at (T0CR_ADDR)           T0CR;
extern __sfr __at (T0CNT_ADDR)          T0CNT;
extern __sfr __at (T0LOAD_ADDR)         T0LOAD;
extern __sfr __at (T0DATA_ADDR)         T0DATA;
extern __sfr __at (T1CR_ADDR)           T1CR;
extern __sfr __at (T1CNT_ADDR)          T1CNT;
extern __sfr __at (T1LOAD_ADDR)         T1LOAD;
extern __sfr __at (T1DATA_ADDR)         T1DATA;
extern __sfr __at (T2CR_ADDR)           T2CR;
extern __sfr __at (T2CNT_ADDR)          T2CNT;
extern __sfr __at (T2LOAD_ADDR)         T2LOAD;
extern __sfr __at (T2DATA_ADDR)         T2DATA;
extern __sfr __at (T3CR_ADDR)           T3CR;
extern __sfr __at (T3CNT_ADDR)          T3CNT;
extern __sfr __at (T3LOAD_ADDR)         T3LOAD;
extern __sfr __at (PWM0DE_ADDR)         PWM0DE;
extern __sfr __at (PWM1DE_ADDR)         PWM1DE;
extern __sfr __at (PWM2DE_ADDR)         PWM2DE;
extern __sfr __at (PWMCR0_ADDR)         PWMCR0;
extern __sfr __at (PWMCR1_ADDR)         PWMCR1;
extern __sfr __at (OSCM_ADDR)           OSCM;
extern __sfr __at (LVDCR_ADDR)          LVDCR;
extern __sfr __at (ADCR0_ADDR)          ADCR0;
extern __sfr __at (ADCR1_ADDR)          ADCR1;
extern __sfr __at (ADCR2_ADDR)          ADCR2;
extern __sfr __at (ADRH_ADDR)           ADRH;
extern __sfr __at (ADRL_ADDR)           ADRL;
extern __sfr __at (ANSEL0_ADDR)         ANSEL0;
extern __sfr __at (ANSEL1_ADDR)         ANSEL1;
extern __sfr __at (VBGCAL_ADDR)         VBGCAL;
extern __sfr __at (OSCCALH_ADDR)        OSCCALH;
extern __sfr __at (OSCCALL_ADDR)        OSCCALL;
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
		unsigned char KBIE:1;
		unsigned char T2IE:1;
		unsigned char ADIE:1;
		unsigned char T3IE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	    INTEbits.T0IE    	      /* bit 0 */
#define T1IE            INTEbits.T1IE           /* bit 1 */
#define INT0IE          INTEbits.INT0IE         /* bit 2 */
#define INT1IE          INTEbits.INT1IE         /* bit 3 */
#define KBIE      	    INTEbits.KBIE    	      /* bit 4 */
#define T2IE            INTEbits.T2IE           /* bit 5 */
#define ADIE            INTEbits.ADIE           /* bit 6 */
#define T3IE            INTEbits.T3IE           /* bit 7 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char KBIF:1;
		unsigned char T2IF:1;
		unsigned char ADIF:1;
		unsigned char T3IF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	    INTFbits.T0IF    	      /* bit 0 */
#define T1IF            INTFbits.T1IF           /* bit 1 */
#define INT0IF    	    INTFbits.INT0IF  	      /* bit 2 */
#define INT1IF          INTFbits.INT1IF         /* bit 3 */
#define KBIF            INTFbits.KBIF           /* bit 4 */
#define T2IF    	      INTFbits.T2IF    	      /* bit 5 */
#define ADIF            INTFbits.ADIF           /* bit 6 */
#define T3IF            INTFbits.T3IF           /* bit 7 */

// ----- DRVCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char PSPDS0:1;
		unsigned char PSPDS1:1;
		unsigned char PDLYS0:1;
		unsigned char PDLYS1:1;
		unsigned char PDRVS0:1;
		unsigned char PDRVS:1;
		unsigned char LDRVS:1;
		unsigned char DRVS:1;
	};
} __DRVCRbits_t;
extern volatile __DRVCRbits_t __at(DRVCR_ADDR) DRVCRbits;

#define PSPDS0      	  DRVCRbits.PSPDS0    	   /* bit 0 */
#define PSPDS1          DRVCRbits.PSPDS1         /* bit 1 */
#define PDLYS0    	    DRVCRbits.PDLYS0  	     /* bit 2 */
#define PDLYS1          DRVCRbits.PDLYS1         /* bit 3 */
#define PDRVS0          DRVCRbits.PDRVS0         /* bit 4 */
#define PDRVS    	      DRVCRbits.PDRVS  	       /* bit 5 */
#define LDRVS           DRVCRbits.LDRVS          /* bit 6 */
#define DRVS            DRVCRbits.DRVS           /* bit 7 */

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

#define KBCR0      	    KBCRbits.KBCR0    	   /* bit 0 */
#define KBCR1           KBCRbits.KBCR1         /* bit 1 */
#define KBCR2    	      KBCRbits.KBCR2  	     /* bit 2 */
#define KBCR3           KBCRbits.KBCR3         /* bit 3 */
#define KBCR4           KBCRbits.KBCR4         /* bit 4 */
#define KBCR5    	      KBCRbits.KBCR5  	     /* bit 5 */
#define KBCR6           KBCRbits.KBCR6         /* bit 6 */

// ----- IOP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00D:1;
                unsigned char P01D:1;
                unsigned char P02D:1;
                unsigned char P03D:1;
                unsigned char P04D:1;
                unsigned char P05D:1;
                unsigned char :1;
                unsigned char :1;
        };
} __IOP0bits_t;
extern volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;

#define P00D             IOP0bits.P00D            /* bit 0 */
#define P01D             IOP0bits.P01D            /* bit 1 */
#define P02D             IOP0bits.P02D            /* bit 2 */
#define P03D             IOP0bits.P03D            /* bit 3 */
#define P04D             IOP0bits.P04D            /* bit 4 */
#define P05D             IOP0bits.P05D            /* bit 5 */

// ----- OEP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00OE:1;
                unsigned char P01OE:1;
                unsigned char P02OE:1;
                unsigned char P03OE:1;
                unsigned char P04OE:1;
                unsigned char P05OE:1;
                unsigned char :1;
                unsigned char :1;
        };
} __OEP0bits_t;
extern volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;

#define P00OE           OEP0bits.P00OE          /* bit 0 */
#define P01OE           OEP0bits.P01OE          /* bit 1 */
#define P02OE           OEP0bits.P02OE          /* bit 2 */
#define P03OE           OEP0bits.P03OE          /* bit 3 */
#define P04OE           OEP0bits.P04OE          /* bit 4 */
#define P05OE           OEP0bits.P05OE          /* bit 5 */

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

#define P00PU           PUP0bits.P00PU          /* bit 0 */
#define P01PU           PUP0bits.P01PU          /* bit 1 */
#define P02PU           PUP0bits.P02PU          /* bit 2 */
#define P03PU           PUP0bits.P03PU          /* bit 3 */
#define P04PU           PUP0bits.P04PU          /* bit 4 */
#define P05PU           PUP0bits.P05PU          /* bit 5 */

// ----- PDP0 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P00PD:1;
                unsigned char P01PD:1;
                unsigned char P02PD:1;
                unsigned char P03PD:1;
                unsigned char P04PD:1;
                unsigned char P05PD:1;
                unsigned char :1;
                unsigned char :1;	
        };
} __PDP0bits_t;
extern volatile __PDP0bits_t __at(PDP0_ADDR) PDP0bits;

#define P00PD           PDP0bits.P00PD          /* bit 0 */
#define P01PD           PDP0bits.P01PD          /* bit 1 */
#define P02PD           PDP0bits.P02PD          /* bit 2 */
#define P03PD           PDP0bits.P03PD          /* bit 3 */
#define P04PD           PDP0bits.P04PD          /* bit 4 */
#define P05PD           PDP0bits.P05PD          /* bit 5 */

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

#define P10D             IOP1bits.P10D            /* bit 0 */
#define P11D             IOP1bits.P11D            /* bit 1 */
#define P12D             IOP1bits.P12D            /* bit 2 */
#define P13D             IOP1bits.P13D            /* bit 3 */
#define P14D             IOP1bits.P14D            /* bit 4 */
#define P15D             IOP1bits.P15D            /* bit 5 */
#define P16D             IOP1bits.P16D            /* bit 6 */
#define P17D             IOP1bits.P17D            /* bit 7 */

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

#define P10OE           OEP1bits.P10OE          /* bit 0 */
#define P11OE           OEP1bits.P11OE          /* bit 1 */
#define P12OE           OEP1bits.P12OE          /* bit 2 */
#define P13OE           OEP1bits.P13OE          /* bit 3 */
#define P14OE           OEP1bits.P14OE          /* bit 4 */
#define P15OE           OEP1bits.P15OE          /* bit 5 */
#define P16OE           OEP1bits.P16OE          /* bit 6 */
#define P17OE           OEP1bits.P17OE          /* bit 7 */

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

#define P10PU           PUP1bits.P10PU          /* bit 0 */
#define P11PU           PUP1bits.P11PU          /* bit 1 */
#define P12PU           PUP1bits.P12PU          /* bit 2 */
#define P13PU           PUP1bits.P13PU          /* bit 3 */
#define P14PU           PUP1bits.P14PU          /* bit 4 */
#define P15PU           PUP1bits.P15PU          /* bit 5 */
#define P16PU           PUP1bits.P16PU          /* bit 6 */
#define P17PU           PUP1bits.P17PU          /* bit 7 */

// ----- PDP1 Bits --------------------------------------------
typedef union {
         struct {
                unsigned char P10PD:1;
                unsigned char P11PD:1;
                unsigned char P12PD:1;
                unsigned char P13PD:1;
                unsigned char P14PD:1;
                unsigned char P15PD:1;
                unsigned char P16PD:1;
                unsigned char P17PD:1;
        };
} __PDP1bits_t;
extern volatile __PDP1bits_t __at(PDP1_ADDR) PDP1bits;

#define P10PD           PDP1bits.P10PD          /* bit 0 */
#define P11PD           PDP1bits.P11PD          /* bit 1 */
#define P12PD           PDP1bits.P12PD          /* bit 2 */
#define P13PD           PDP1bits.P13PD          /* bit 3 */
#define P14PD           PDP1bits.P14PD          /* bit 4 */
#define P15PD           PDP1bits.P15PD          /* bit 5 */
#define P16PD           PDP1bits.P16PD          /* bit 6 */
#define P17PD           PDP1bits.P17PD          /* bit 7 */

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

// ----- T2CR Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T2PR:3;
                unsigned char T2PS:2;
                unsigned char BUZ2OE:1;
                unsigned char PWM2OE:1;  
                unsigned char TC2EN:1;
        };
} __T2CRbits_t;
extern volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;

#define T2PR            T2CRbits.T2PR           /* bit 2-0 */
#define T2PS            T2CRbits.T2PS           /* bit 4-3 */
#define BUZ2OE          T2CRbits.BUZ2OE         /* bit 5 */
#define PWM2OE          T2CRbits.PWM2OE         /* bit 6 */
#define TC2EN           T2CRbits.TC2EN          /* bit 7 */

// ----- T2CNT Bits --------------------------------------------
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
} __T2CNTbits_t;
extern volatile __T2CNTbits_t __at(T2CNT_ADDR) T2CNTbits;

#define T2C0            T2CNTbits.T2C0           /* bit 0 */
#define T2C1            T2CNTbits.T2C1           /* bit 1 */
#define T2C2            T2CNTbits.T2C2           /* bit 2 */
#define T2C3            T2CNTbits.T2C3           /* bit 3 */
#define T2C4            T2CNTbits.T2C4           /* bit 4 */
#define T2C5            T2CNTbits.T2C5           /* bit 5 */
#define T2C6            T2CNTbits.T2C6           /* bit 6 */
#define T2C7            T2CNTbits.T2C7           /* bit 7 */

// ----- T2LOAD Bits --------------------------------------------
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
} __T2LOADbits_t;
extern volatile __T2LOADbits_t __at(T2LOAD_ADDR) T2LOADbits;

#define T2LOAD0         T2LOADbits.T2LOAD0       /* bit 0 */
#define T2LOAD1         T2LOADbits.T2LOAD1       /* bit 1 */
#define T2LOAD2         T2LOADbits.T2LOAD2       /* bit 2 */
#define T2LOAD3         T2LOADbits.T2LOAD3       /* bit 3 */
#define T2LOAD4         T2LOADbits.T2LOAD4       /* bit 4 */
#define T2LOAD5         T2LOADbits.T2LOAD5       /* bit 5 */
#define T2LOAD6         T2LOADbits.T2LOAD6       /* bit 6 */
#define T2LOAD7         T2LOADbits.T2LOAD7       /* bit 7 */

// ----- T2DATA Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T2DATA0:1;
                unsigned char T2DATA1:1;
                unsigned char T2DATA2:1;
                unsigned char T2DATA3:1;
                unsigned char T2DATA4:1;
                unsigned char T2DATA5:1;
                unsigned char T2DATA6:1;
                unsigned char T2DATA7:1;
        };
} __T2DATAbits_t;
extern volatile __T2DATAbits_t __at(T2DATA_ADDR) T2DATAbits;

#define T2DATA0         T2DATAbits.T2DATA0       /* bit 0 */
#define T2DATA1         T2DATAbits.T2DATA1       /* bit 1 */
#define T2DATA2         T2DATAbits.T2DATA2       /* bit 2 */
#define T2DATA3         T2DATAbits.T2DATA3       /* bit 3 */
#define T2DATA4         T2DATAbits.T2DATA4       /* bit 4 */
#define T2DATA5         T2DATAbits.T2DATA5       /* bit 5 */
#define T2DATA6         T2DATAbits.T2DATA6       /* bit 6 */
#define T2DATA7         T2DATAbits.T2DATA7       /* bit 7 */

// ----- T3CR Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T3PR:3;
                unsigned char T3PS:2;
                unsigned char :1;
                unsigned char :1;  
                unsigned char TC3EN:1;
        };
} __T3CRbits_t;
extern volatile __T3CRbits_t __at(T3CR_ADDR) T3CRbits;

#define T3PR            T3CRbits.T3PR           /* bit 2-0 */
#define T3PS            T3CRbits.T3PS           /* bit 4-3 */
#define TC3EN           T3CRbits.TC3EN          /* bit 7 */

// ----- T3CNT Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T3C0:1;
                unsigned char T3C1:1;
                unsigned char T3C2:1;
                unsigned char T3C3:1;
                unsigned char T3C4:1;
                unsigned char T3C5:1;
                unsigned char T3C6:1;
                unsigned char T3C7:1;
        };
} __T3CNTbits_t;
extern volatile __T3CNTbits_t __at(T3CNT_ADDR) T3CNTbits;

#define T3C0            T3CNTbits.T3C0           /* bit 0 */
#define T3C1            T3CNTbits.T3C1           /* bit 1 */
#define T3C2            T3CNTbits.T3C2           /* bit 2 */
#define T3C3            T3CNTbits.T3C3           /* bit 3 */
#define T3C4            T3CNTbits.T3C4           /* bit 4 */
#define T3C5            T3CNTbits.T3C5           /* bit 5 */
#define T3C6            T3CNTbits.T3C6           /* bit 6 */
#define T3C7            T3CNTbits.T3C7           /* bit 7 */

// ----- T3LOAD Bits --------------------------------------------
typedef union {
         struct {
                unsigned char T3LOAD0:1;
                unsigned char T3LOAD1:1;
                unsigned char T3LOAD2:1;
                unsigned char T3LOAD3:1;
                unsigned char T3LOAD4:1;
                unsigned char T3LOAD5:1;
                unsigned char T3LOAD6:1;
                unsigned char T3LOAD7:1;
        };
} __T3LOADbits_t;
extern volatile __T3LOADbits_t __at(T3LOAD_ADDR) T3LOADbits;

#define T3LOAD0         T3LOADbits.T3LOAD0       /* bit 0 */
#define T3LOAD1         T3LOADbits.T3LOAD1       /* bit 1 */
#define T3LOAD2         T3LOADbits.T3LOAD2       /* bit 2 */
#define T3LOAD3         T3LOADbits.T3LOAD3       /* bit 3 */
#define T3LOAD4         T3LOADbits.T3LOAD4       /* bit 4 */
#define T3LOAD5         T3LOADbits.T3LOAD5       /* bit 5 */
#define T3LOAD6         T3LOADbits.T3LOAD6       /* bit 6 */
#define T3LOAD7         T3LOADbits.T3LOAD7       /* bit 7 */

// ---- PWM0DE Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char PWM0DE0:1;
                unsigned char PWM0DE1:1;
                unsigned char PWM0DE2:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;  
                unsigned char :1;
                unsigned char :1;  
        };
} __PWM0DEbits_t;
extern volatile __PWM0DEbits_t __at(PWM0DE_ADDR) PWM0DEbits;

#define PWM0DE0           PWM0DEbits.PWM0DE0           /* bit 0 */
#define PWM0DE1           PWM0DEbits.PWM0DE1           /* bit 1 */
#define PWM0DE2           PWM0DEbits.PWM0DE2           /* bit 2 */

// ---- PWM1DE Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char PWM1DE0:1;
                unsigned char PWM1DE1:1;
                unsigned char PWM1DE2:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;  
                unsigned char :1;
                unsigned char :1;  
        };
} __PWM1DEbits_t;
extern volatile __PWM1DEbits_t __at(PWM1DE_ADDR) PWM1DEbits;

#define PWM1DE0           PWM1DEbits.PWM1DE0           /* bit 0 */
#define PWM1DE1           PWM1DEbits.PWM1DE1           /* bit 1 */
#define PWM1DE2           PWM1DEbits.PWM1DE2           /* bit 2 */

// ---- PWM2DE Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char PWM2DE0:1;
                unsigned char PWM2DE1:1;
                unsigned char PWM2DE2:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;  
                unsigned char :1;
                unsigned char :1;  
        };
} __PWM2DEbits_t;
extern volatile __PWM2DEbits_t __at(PWM2DE_ADDR) OPCR0bits;

#define PWM2DE0           PWM2DEbits.PWM2DE0           /* bit 0 */
#define PWM2DE1           PWM2DEbits.PWM2DE1           /* bit 1 */
#define PWM2DE2           PWM2DEbits.PWM2DE2           /* bit 2 */

// ---- PWMCR0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char FPWMF0:1;
                unsigned char FPWMF1:1;  
                unsigned char FPWMR0:1;
                unsigned char FPWMR1:1;  
                unsigned char PWM0INV:1;
                unsigned char PWM1INV:1;
                unsigned char PWM2INV:1;
                unsigned char FPWMEN:1;
        };
} __PWMCR0bits_t;
extern volatile __PWMCR0bits_t __at(PWMCR0_ADDR) PWMCR0bits;

#define FPWMF0            PWMCR0bits.FPWMF0            /* bit 0 */
#define FPWMF1            PWMCR0bits.FPWMF1            /* bit 1 */
#define FPWMR0            PWMCR0bits.FPWMR0            /* bit 2 */
#define FPWMR1            PWMCR0bits.FPWMR1            /* bit 3 */
#define PWM0INV           PWMCR0bits.PWM0INV           /* bit 4 */
#define PWM1INV           PWMCR0bits.PWM1INV           /* bit 5 */
#define PWM2INV           PWMCR0bits.PWM2INV           /* bit 6 */
#define FPWMEN            PWMCR0bits.FPWMEN            /* bit 7 */

// ---- PWMCR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char PMODE0:1;
                unsigned char PMODE1:1;
                unsigned char PMODE2:1;
                unsigned char TMRCKS0:1;
                unsigned char TMRCKS1:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;  
        };
} __PWMCR1bits_t;
extern volatile __PWMCR1bits_t __at(PWMCR1_ADDR) PWMCR1bits;

#define PMODE0            PWMCR1bits.PMODE0          /* bit 0 */
#define PMODE1            PWMCR1bits.PMODE1          /* bit 1 */
#define PMODE2            PWMCR1bits.PMODE2          /* bit 2 */
#define TMRCKS0           PWMCR1bits.TMRCKS0         /* bit 3 */
#define TMRCKS1           PWMCR1bits.TMRCKS1         /* bit 4 */

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

// ---- LVDCR Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char LVDF:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char LVDS0:1;
                unsigned char LVDS1:1;
                unsigned char LVDS2:1;
                unsigned char LVDS3:1;
                unsigned char LVDEN:1;    
        };
} __LVDCRbits_t;
extern volatile __LVDCRbits_t __at(LVDCR_ADDR) LVDCRbits;

#define LVDF            LVDCRbits.LVDF          /* bit 0 */
#define LVDS0           LVDCRbits.LVDS0         /* bit 3 */
#define LVDS1           LVDCRbits.LVDS1         /* bit 4 */
#define LVDS2           LVDCRbits.LVDS2         /* bit 5 */
#define LVDS3           LVDCRbits.LVDS3         /* bit 6 */
#define LVDEN           LVDCRbits.LVDEN         /* bit 7 */

// ---- ADCR0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char ADON:1;
                unsigned char ADEOC:1;
                unsigned char :1;
                unsigned char ADLEN:1;
                unsigned char ADCHS0:1;
                unsigned char ADCHS1:1;
                unsigned char ADCHS2:1;
                unsigned char ADCHS3:1;    
        };
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADON            ADCR0bits.ADON          /* bit 0 */
#define ADEOC           ADCR0bits.ADEOC         /* bit 1 */
#define ADLEN           ADCR0bits.ADLEN         /* bit 3 */
#define ADCHS0          ADCR0bits.ADCHS0         /* bit 4 */
#define ADCHS1          ADCR0bits.ADCHS1         /* bit 5 */
#define ADCHS2          ADCR0bits.ADCHS2         /* bit 6 */
#define ADCHS3          ADCR0bits.ADCHS3         /* bit 7 */

// ---- ADCR1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char VRS0:1;
                unsigned char VRS1:1;
                unsigned char VRS2:1;
                unsigned char RESS0:1;
                unsigned char ADTST:1;
                unsigned char ADCKS0:1;
                unsigned char ADCKS1:1;
                unsigned char ADCKS2:1;    
        };
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define VRS0            ADCR1bits.VRS0          /* bit 0 */
#define VRS1            ADCR1bits.VRS1          /* bit 1 */
#define VRS2            ADCR1bits.VRS2          /* bit 2 */
#define RESS0           ADCR1bits.RESS0         /* bit 3 */
#define ADTST           ADCR1bits.ADTST         /* bit 4 */
#define ADCKS0          ADCR1bits.ADCKS0        /* bit 6 */
#define ADCKS1          ADCR1bits.ADCKS1        /* bit 6 */
#define ADCKS2          ADCR1bits.ADCKS2        /* bit 7 */

// ---- ADCR2 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char ADSMP0:1;
                unsigned char ADSMP1:1;
                unsigned char ADSMP2:1;
                unsigned char ADSMP3:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;    
        };
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define ADSMP0            ADCR2bits.ADSMP0          /* bit 0 */
#define ADSMP1            ADCR2bits.ADSMP1          /* bit 1 */
#define ADSMP2            ADCR2bits.ADSMP2          /* bit 2 */
#define ADSMP3            ADCR2bits.ADSMP3          /* bit 3 */

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

#define ADR4            ADRHbits.ADR4          /* bit 0 */
#define ADR5            ADRHbits.ADR5          /* bit 1 */
#define ADR6            ADRHbits.ADR6          /* bit 2 */
#define ADR7            ADRHbits.ADR7          /* bit 3 */
#define ADR8            ADRHbits.ADR8          /* bit 4 */
#define ADR9            ADRHbits.ADR9          /* bit 5 */
#define ADR10           ADRHbits.ADR10         /* bit 6 */
#define ADR11           ADRHbits.ADR11         /* bit 7 */

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

#define ADR0            ADRLbits.ADR0          /* bit 0 */
#define ADR1            ADRLbits.ADR1          /* bit 1 */
#define ADR2            ADRLbits.ADR2          /* bit 2 */
#define ADR3            ADRLbits.ADR3          /* bit 3 */

// ---- ANSEL0 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char P00ANS:1;
                unsigned char P01ANS:1;
                unsigned char P02ANS:1;
                unsigned char P03ANS:1;
                unsigned char P04ANS:1;
                unsigned char P05ANS:1;
                unsigned char P11ANS:1;
                unsigned char P12ANS:1;    
        };
} __ANSEL0bits_t;
extern volatile __ANSEL0bits_t __at(ANSEL0_ADDR) ANSEL0bits;

#define P00ANS            ANSEL0bits.P00ANS          /* bit 0 */
#define P01ANS            ANSEL0bits.P01ANS          /* bit 1 */
#define P02ANS            ANSEL0bits.P02ANS          /* bit 2 */
#define P03ANS            ANSEL0bits.P03ANS          /* bit 3 */
#define P04ANS            ANSEL0bits.P04ANS          /* bit 4 */
#define P05ANS            ANSEL0bits.P05ANS          /* bit 5 */
#define P11ANS            ANSEL0bits.P11ANS          /* bit 6 */
#define P12ANS            ANSEL0bits.P12ANS          /* bit 7 */

// ---- ANSEL1 Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char P14ANS:1;
                unsigned char P15ANS:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;    
        };
} __ANSEL1bits_t;
extern volatile __ANSEL1bits_t __at(ANSEL1_ADDR) ANSEL1bits;

#define P14ANS            ANSEL1bits.P14ANS          /* bit 0 */
#define P15ANS            ANSEL1bits.P15ANS          /* bit 1 */

// ---- VBGCAL Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char VBGCAL0:1;
                unsigned char VBGCAL1:1;
                unsigned char VBGCAL2:1;
                unsigned char VBGCAL3:1;
                unsigned char VBGCAL4:1;
                unsigned char VBGCAL5:1;
                unsigned char VBGCAL6:1;
                unsigned char VBGCAL7:1;    
        };
} __VBGCALbits_t;
extern volatile __VBGCALbits_t __at(VBGCAL_ADDR) VBGCALbits;

#define VBGCAL0            VBGCALbits.VBGCAL0          /* bit 0 */
#define VBGCAL1            VBGCALbits.VBGCAL1          /* bit 1 */
#define VBGCAL2            VBGCALbits.VBGCAL2          /* bit 2 */
#define VBGCAL3            VBGCALbits.VBGCAL3          /* bit 3 */
#define VBGCAL4            VBGCALbits.VBGCAL4          /* bit 4 */
#define VBGCAL5            VBGCALbits.VBGCAL5          /* bit 5 */
#define VBGCAL6            VBGCALbits.VBGCAL6          /* bit 6 */
#define VBGCAL7            VBGCALbits.VBGCAL7          /* bit 7 */

// ---- OSCCALL Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char OSCCAL0:1;
                unsigned char OSCCAL1:1;
                unsigned char OSCCAL2:1;
                unsigned char OSCCAL3:1;
                unsigned char OSCCAL4:1;
                unsigned char OSCCAL5:1;
                unsigned char OSCCAL6:1;
                unsigned char OSCCAL7:1;    
        };
} __OSCCALLbits_t;
extern volatile __OSCCALLbits_t __at(OSCCALL_ADDR) OSCCALLbits;

#define OSCCAL0            OSCCALLbits.OSCCAL0          /* bit 0 */
#define OSCCAL1            OSCCALLbits.OSCCAL1          /* bit 1 */
#define OSCCAL2            OSCCALLbits.OSCCAL2          /* bit 2 */
#define OSCCAL3            OSCCALLbits.OSCCAL3          /* bit 3 */
#define OSCCAL4            OSCCALLbits.OSCCAL4          /* bit 4 */
#define OSCCAL5            OSCCALLbits.OSCCAL5          /* bit 5 */
#define OSCCAL6            OSCCALLbits.OSCCAL6          /* bit 6 */
#define OSCCAL7            OSCCALLbits.OSCCAL7          /* bit 7 */

// ---- OSCCALH Bits ----------------------------------------------
typedef union {
         struct {
                unsigned char OSCCAL8:1;
                unsigned char OSCCAL9:1;
                unsigned char OSCCAL10:1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;
                unsigned char :1;    
        };
} __OSCCALHbits_t;
extern volatile __OSCCALHbits_t __at(OSCCALH_ADDR) OSCCALHbits;

#define OSCCAL8            OSCCALHbits.OSCCAL8          /* bit 0 */
#define OSCCAL9            OSCCALHbits.OSCCAL9          /* bit 1 */
#define OSCCAL10           OSCCALHbits.OSCCAL10          /* bit 2 */

#endif
