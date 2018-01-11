#ifndef MC32P5314_H
#define MC32P5314_H

#include <mc32-common.h>

//
// Register addresses.
//
#define LCDDS00_ADDR    	0x0100
#define LCDDS01_ADDR    	0x0101
#define LCDDS02_ADDR    	0x0102
#define LCDDS03_ADDR    	0x0103
#define LCDDS04_ADDR    	0x0104
#define LCDDS05_ADDR    	0x0105
#define LCDDS06_ADDR    	0x0106
#define LCDDS07_ADDR    	0x0107
#define LCDDS08_ADDR    	0x0108
#define LCDDS09_ADDR    	0x0109
#define LCDDS10_ADDR    	0x010A
#define LCDDS11_ADDR    	0x010B
#define LCDDS12_ADDR    	0x010C
#define LCDDS13_ADDR    	0x010D
#define LCDDS14_ADDR    	0x010E
#define LCDDS15_ADDR    	0x010F
#define LCDDS16_ADDR    	0x0110
#define LCDDS17_ADDR    	0x0111
#define LCDDS18_ADDR    	0x0112
#define LCDDS19_ADDR    	0x0113
#define LCDDS20_ADDR    	0x0114
#define LCDDS21_ADDR    	0x0115
#define LCDDS22_ADDR    	0x0116
#define LCDDS23_ADDR    	0x0117
#define LCDDS24_ADDR    	0x0118
#define LCDDS25_ADDR    	0x0119
#define LCDDS26_ADDR    	0x011A
#define LCDDS27_ADDR    	0x011B
#define LCDDS28_ADDR    	0x011C
#define LCDDS29_ADDR    	0x011D
#define INDF0_ADDR      	0x01B0
#define INDF1_ADDR      	0x01B1
#define INDF2_ADDR      	0x01B2
#define HIBYTE_ADDR     	0x01B3
#define FSR0_ADDR       	0x01B4
#define FSR1_ADDR       	0x01B5
#define PCL_ADDR        	0x01B6
#define PFLAG_ADDR      	0x01B7
#define MCR_ADDR        	0x01B8
#define INDF3_ADDR      	0x01B9
#define INTE_ADDR       	0x01BA
#define INTF_ADDR       	0x01BB
#define OSCM_ADDR       	0x01BC
#define LVDCR_ADDR      	0x01BD
#define LXTCR_ADDR      	0x01BE
#define IOP0_ADDR       	0x01C0
#define OEP0_ADDR       	0x01C1
#define PUP0_ADDR       	0x01C2
#define DKWP0_ADDR      	0x01C3
#define IOP1_ADDR       	0x01C4
#define OEP1_ADDR       	0x01C5
#define PUP1_ADDR       	0x01C6
#define LCDIOSP1_ADDR   	0x01C7
#define IOP2_ADDR       	0x01C8
#define OEP2_ADDR       	0x01C9
#define PUP2_ADDR       	0x01CA
#define LCDIOSP2_ADDR   	0x01CB
#define IOP3_ADDR       	0x01CC
#define OEP3_ADDR       	0x01CD
#define PUP3_ADDR       	0x01CE
#define LCDIOSP3_ADDR   	0x01CF
#define IOP4_ADDR       	0x01D0
#define OEP4_ADDR       	0x01D1
#define PUP4_ADDR       	0x01D2
#define LCDIOSP4_ADDR   	0x01D3
#define IOP5_ADDR       	0x01D4
#define OEP5_ADDR       	0x01D5
#define PUP5_ADDR       	0x01D6
#define LCDIOSP5_ADDR   	0x01D7
#define T0CR0_ADDR      	0x01D8
#define T0CR1_ADDR      	0x01D9
#define T0LOADH_ADDR    	0x01DC
#define T0LOADL_ADDR    	0x01DD
#define T0DATAH_ADDR    	0x01DE
#define T0DATAL_ADDR    	0x01DF
#define T0LATRH_ADDR    	0x01E0
#define T0LATRL_ADDR    	0x01E1
#define T0LATFH_ADDR    	0x01E2
#define T0LATFL_ADDR    	0x01E3
#define T1CR_ADDR       	0x01E4
#define T1DATA_ADDR     	0x01E5
#define T1LOAD_ADDR     	0x01E6
#define ADCR0_ADDR      	0x01E8
#define ADCR1_ADDR      	0x01E9
#define ADCR2_ADDR      	0x01EA
#define ADDRH_ADDR      	0x01EC
#define ADDRL_ADDR      	0x01ED
#define OPCR0_ADDR      	0x01F0
#define OPCR1_ADDR      	0x01F1
#define LCDCR0_ADDR     	0x01F2
#define LCDCR1_ADDR     	0x01F3
#define DKW_ADDR        	0x01F4
#define KBCR_ADDR       	0x01F5
#define LCDDRV_ADDR     	0x01F6

//----- Register Files -----------------------------------------------------

extern __sfr __at (LCDDS00_ADDR)  	LCDDS00;
extern __sfr __at (LCDDS01_ADDR)  	LCDDS01;
extern __sfr __at (LCDDS02_ADDR)  	LCDDS02;
extern __sfr __at (LCDDS03_ADDR)  	LCDDS03;
extern __sfr __at (LCDDS04_ADDR)  	LCDDS04;
extern __sfr __at (LCDDS05_ADDR)  	LCDDS05;
extern __sfr __at (LCDDS06_ADDR)  	LCDDS06;
extern __sfr __at (LCDDS07_ADDR)  	LCDDS07;
extern __sfr __at (LCDDS08_ADDR)  	LCDDS08;
extern __sfr __at (LCDDS09_ADDR)  	LCDDS09;
extern __sfr __at (LCDDS10_ADDR)  	LCDDS10;
extern __sfr __at (LCDDS11_ADDR)  	LCDDS11;
extern __sfr __at (LCDDS12_ADDR)  	LCDDS12;
extern __sfr __at (LCDDS13_ADDR)  	LCDDS13;
extern __sfr __at (LCDDS14_ADDR)  	LCDDS14;
extern __sfr __at (LCDDS15_ADDR)  	LCDDS15;
extern __sfr __at (LCDDS16_ADDR)  	LCDDS16;
extern __sfr __at (LCDDS17_ADDR)  	LCDDS17;
extern __sfr __at (LCDDS18_ADDR)  	LCDDS18;
extern __sfr __at (LCDDS19_ADDR)  	LCDDS19;
extern __sfr __at (LCDDS20_ADDR)  	LCDDS20;
extern __sfr __at (LCDDS21_ADDR)  	LCDDS21;
extern __sfr __at (LCDDS22_ADDR)  	LCDDS22;
extern __sfr __at (LCDDS23_ADDR)  	LCDDS23;
extern __sfr __at (LCDDS24_ADDR)  	LCDDS24;
extern __sfr __at (LCDDS25_ADDR)  	LCDDS25;
extern __sfr __at (LCDDS26_ADDR)  	LCDDS26;
extern __sfr __at (LCDDS27_ADDR)  	LCDDS27;
extern __sfr __at (LCDDS28_ADDR)  	LCDDS28;
extern __sfr __at (LCDDS29_ADDR)  	LCDDS29;
extern __sfr __at (INDF0_ADDR)    	INDF0;
extern __sfr __at (INDF1_ADDR)    	INDF1;
extern __sfr __at (INDF2_ADDR)    	INDF2;
extern __sfr __at (HIBYTE_ADDR)   	HIBYTE;
extern __sfr __at (FSR0_ADDR)     	FSR0;
extern __sfr __at (FSR1_ADDR)     	FSR1;
extern __sfr __at (PCL_ADDR)      	PCL;
extern __sfr __at (PFLAG_ADDR)    	PFLAG;
extern __sfr __at (MCR_ADDR)      	MCR;
extern __sfr __at (INDF3_ADDR)    	INDF3;
extern __sfr __at (INTE_ADDR)     	INTE;
extern __sfr __at (INTF_ADDR)     	INTF;
extern __sfr __at (OSCM_ADDR)     	OSCM;
extern __sfr __at (LVDCR_ADDR)    	LVDCR;
extern __sfr __at (LXTCR_ADDR)    	LXTCR;
extern __sfr __at (IOP0_ADDR)     	IOP0;
extern __sfr __at (OEP0_ADDR)     	OEP0;
extern __sfr __at (PUP0_ADDR)     	PUP0;
extern __sfr __at (DKWP0_ADDR)    	DKWP0;
extern __sfr __at (IOP1_ADDR)     	IOP1;
extern __sfr __at (OEP1_ADDR)     	OEP1;
extern __sfr __at (PUP1_ADDR)     	PUP1;
extern __sfr __at (LCDIOSP1_ADDR) 	LCDIOSP1;
extern __sfr __at (IOP2_ADDR)     	IOP2;
extern __sfr __at (OEP2_ADDR)     	OEP2;
extern __sfr __at (PUP2_ADDR)     	PUP2;
extern __sfr __at (LCDIOSP2_ADDR) 	LCDIOSP2;
extern __sfr __at (IOP3_ADDR)     	IOP3;
extern __sfr __at (OEP3_ADDR)     	OEP3;
extern __sfr __at (PUP3_ADDR)     	PUP3;
extern __sfr __at (LCDIOSP3_ADDR) 	LCDIOSP3;
extern __sfr __at (IOP4_ADDR)     	IOP4;
extern __sfr __at (OEP4_ADDR)     	OEP4;
extern __sfr __at (PUP4_ADDR)     	PUP4;
extern __sfr __at (LCDIOSP4_ADDR) 	LCDIOSP4;
extern __sfr __at (IOP5_ADDR)     	IOP5;
extern __sfr __at (OEP5_ADDR)     	OEP5;
extern __sfr __at (PUP5_ADDR)     	PUP5;
extern __sfr __at (LCDIOSP5_ADDR) 	LCDIOSP5;
extern __sfr __at (T0CR0_ADDR)    	T0CR0;
extern __sfr __at (T0CR1_ADDR)    	T0CR1;
extern __sfr __at (T0LOADH_ADDR)  	T0LOADH;
extern __sfr __at (T0LOADL_ADDR)  	T0LOADL;
extern __sfr __at (T0DATAH_ADDR)  	T0DATAH;
extern __sfr __at (T0DATAL_ADDR)  	T0DATAL;
extern __sfr __at (T0LATRH_ADDR)  	T0LATRH;
extern __sfr __at (T0LATRL_ADDR)  	T0LATRL;
extern __sfr __at (T0LATFH_ADDR)  	T0LATFH;
extern __sfr __at (T0LATFL_ADDR)  	T0LATFL;
extern __sfr __at (T1CR_ADDR)     	T1CR;
extern __sfr __at (T1DATA_ADDR)   	T1DATA;
extern __sfr __at (T1LOAD_ADDR)   	T1LOAD;
extern __sfr __at (ADCR0_ADDR)    	ADCR0;
extern __sfr __at (ADCR1_ADDR)    	ADCR1;
extern __sfr __at (ADCR2_ADDR)    	ADCR2;
extern __sfr __at (ADDRH_ADDR)    	ADDRH;
extern __sfr __at (ADDRL_ADDR)    	ADDRL;
extern __sfr __at (OPCR0_ADDR)    	OPCR0;
extern __sfr __at (OPCR1_ADDR)    	OPCR1;
extern __sfr __at (LCDCR0_ADDR)   	LCDCR0;
extern __sfr __at (LCDCR1_ADDR)   	LCDCR1;
extern __sfr __at (DKW_ADDR)      	DKW;
extern __sfr __at (KBCR_ADDR)     	KBCR;
extern __sfr __at (LCDDRV_ADDR)   	LCDDRV;

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

#define INDF00    	INDF0bits.INDF00    	/* bit 0 */
#define INDF01    	INDF0bits.INDF01    	/* bit 1 */
#define INDF02    	INDF0bits.INDF02    	/* bit 2 */
#define INDF03    	INDF0bits.INDF03    	/* bit 3 */
#define INDF04    	INDF0bits.INDF04    	/* bit 4 */
#define INDF05    	INDF0bits.INDF05    	/* bit 5 */
#define INDF06    	INDF0bits.INDF06    	/* bit 6 */
#define INDF07    	INDF0bits.INDF07    	/* bit 7 */

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

#define INDF10    	INDF1bits.INDF10    	/* bit 0 */
#define INDF11    	INDF1bits.INDF11    	/* bit 1 */
#define INDF12    	INDF1bits.INDF12    	/* bit 2 */
#define INDF13    	INDF1bits.INDF13    	/* bit 3 */
#define INDF14    	INDF1bits.INDF14    	/* bit 4 */
#define INDF15    	INDF1bits.INDF15    	/* bit 5 */
#define INDF16    	INDF1bits.INDF16    	/* bit 6 */
#define INDF17    	INDF1bits.INDF17    	/* bit 7 */

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

#define INDF20    	INDF2bits.INDF20    	/* bit 0 */
#define INDF21    	INDF2bits.INDF21    	/* bit 1 */
#define INDF22    	INDF2bits.INDF22    	/* bit 2 */
#define INDF23    	INDF2bits.INDF23    	/* bit 3 */
#define INDF24    	INDF2bits.INDF24    	/* bit 4 */
#define INDF25    	INDF2bits.INDF25    	/* bit 5 */
#define INDF26    	INDF2bits.INDF26    	/* bit 6 */
#define INDF27    	INDF2bits.INDF27    	/* bit 7 */

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

#define HIBYTE0   	HIBYTEbits.HIBYTE0  	/* bit 0 */
#define HIBYTE1   	HIBYTEbits.HIBYTE1  	/* bit 1 */
#define HIBYTE2   	HIBYTEbits.HIBYTE2  	/* bit 2 */
#define HIBYTE3   	HIBYTEbits.HIBYTE3  	/* bit 3 */
#define HIBYTE4   	HIBYTEbits.HIBYTE4  	/* bit 4 */
#define HIBYTE5   	HIBYTEbits.HIBYTE5  	/* bit 5 */
#define HIBYTE6   	HIBYTEbits.HIBYTE6  	/* bit 6 */
#define HIBYTE7   	HIBYTEbits.HIBYTE7  	/* bit 7 */

// ----- FSR0 Bits --------------------------------------------
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

#define FSR00     	FSR0bits.FSR00      	/* bit 0 */
#define FSR01     	FSR0bits.FSR01      	/* bit 1 */
#define FSR02     	FSR0bits.FSR02      	/* bit 2 */
#define FSR03     	FSR0bits.FSR03      	/* bit 3 */
#define FSR04     	FSR0bits.FSR04      	/* bit 4 */
#define FSR05     	FSR0bits.FSR05      	/* bit 5 */
#define FSR06     	FSR0bits.FSR06      	/* bit 6 */
#define FSR07     	FSR0bits.FSR07      	/* bit 7 */

// ----- FSR1 Bits --------------------------------------------
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

#define FSR10     	FSR1bits.FSR10      	/* bit 0 */
#define FSR11     	FSR1bits.FSR11      	/* bit 1 */
#define FSR12     	FSR1bits.FSR12      	/* bit 2 */
#define FSR13     	FSR1bits.FSR13      	/* bit 3 */
#define FSR14     	FSR1bits.FSR14      	/* bit 4 */
#define FSR15     	FSR1bits.FSR15      	/* bit 5 */
#define FSR16     	FSR1bits.FSR16      	/* bit 6 */
#define FSR17     	FSR1bits.FSR17      	/* bit 7 */

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

#define PC0       	PCLbits.PC0         	/* bit 0 */
#define PC1       	PCLbits.PC1         	/* bit 1 */
#define PC2       	PCLbits.PC2         	/* bit 2 */
#define PC3       	PCLbits.PC3         	/* bit 3 */
#define PC4       	PCLbits.PC4         	/* bit 4 */
#define PC5       	PCLbits.PC5         	/* bit 5 */
#define PC6       	PCLbits.PC6         	/* bit 6 */
#define PC7       	PCLbits.PC7         	/* bit 7 */

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
		unsigned char MINT00:1;
		unsigned char MINT01:1;
		unsigned char MINT10:1;
		unsigned char MINT11:1;
		unsigned char PD:1;
		unsigned char TO:1;
		unsigned char :1;
		unsigned char GIE:1;
	};
} __MCRbits_t;
extern volatile __MCRbits_t __at(MCR_ADDR) MCRbits;

#define MINT00    	MCRbits.MINT00      	/* bit 0 */
#define MINT01    	MCRbits.MINT01      	/* bit 1 */
#define MINT10    	MCRbits.MINT10      	/* bit 2 */
#define MINT11    	MCRbits.MINT11      	/* bit 3 */
#define PD        	MCRbits.PD          	/* bit 4 */
#define TO        	MCRbits.TO          	/* bit 5 */
#define GIE       	MCRbits.GIE         	/* bit 7 */

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

#define INDF30    	INDF3bits.INDF30    	/* bit 0 */
#define INDF31    	INDF3bits.INDF31    	/* bit 1 */
#define INDF32    	INDF3bits.INDF32    	/* bit 2 */
#define INDF33    	INDF3bits.INDF33    	/* bit 3 */
#define INDF34    	INDF3bits.INDF34    	/* bit 4 */
#define INDF35    	INDF3bits.INDF35    	/* bit 5 */
#define INDF36    	INDF3bits.INDF36    	/* bit 6 */
#define INDF37    	INDF3bits.INDF37    	/* bit 7 */

// ----- INTE Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IE:1;
		unsigned char T1IE:1;
		unsigned char INT0IE:1;
		unsigned char INT1IE:1;
		unsigned char KBIE:1;
		unsigned char LVDIE:1;
		unsigned char :1;
		unsigned char ADIE:1;
	};
} __INTEbits_t;
extern volatile __INTEbits_t __at(INTE_ADDR) INTEbits;

#define T0IE      	INTEbits.T0IE       	/* bit 0 */
#define T1IE      	INTEbits.T1IE       	/* bit 1 */
#define INT0IE    	INTEbits.INT0IE     	/* bit 2 */
#define INT1IE    	INTEbits.INT1IE     	/* bit 3 */
#define KBIE      	INTEbits.KBIE       	/* bit 4 */
#define LVDIE     	INTEbits.LVDIE      	/* bit 5 */
#define ADIE      	INTEbits.ADIE       	/* bit 7 */

// ----- INTF Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0IF:1;
		unsigned char T1IF:1;
		unsigned char INT0IF:1;
		unsigned char INT1IF:1;
		unsigned char KBIF:1;
		unsigned char LVDIF:1;
		unsigned char T0RF:1;
		unsigned char ADIF:1;
	};
} __INTFbits_t;
extern volatile __INTFbits_t __at(INTF_ADDR) INTFbits;

#define T0IF      	INTFbits.T0IF       	/* bit 0 */
#define T1IF      	INTFbits.T1IF       	/* bit 1 */
#define INT0IF    	INTFbits.INT0IF     	/* bit 2 */
#define INT1IF    	INTFbits.INT1IF     	/* bit 3 */
#define KBIF      	INTFbits.KBIF       	/* bit 4 */
#define LVDIF     	INTFbits.LVDIF      	/* bit 5 */
#define T0RF      	INTFbits.T0RF       	/* bit 6 */
#define ADIF      	INTFbits.ADIF       	/* bit 7 */

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

// ----- LVDCR Bits --------------------------------------------
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

#define LVDF      	LVDCRbits.LVDF      	/* bit 0 */
#define LVDS0     	LVDCRbits.LVDS0     	/* bit 3 */
#define LVDS1     	LVDCRbits.LVDS1     	/* bit 4 */
#define LVDS2     	LVDCRbits.LVDS2     	/* bit 5 */
#define LVDS3     	LVDCRbits.LVDS3     	/* bit 6 */
#define LVDEN     	LVDCRbits.LVDEN     	/* bit 7 */

// ----- LXTCR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LPEN0:1;
		unsigned char LPEN1:1;
		unsigned char LPEN2:1;
		unsigned char FILS:1;
		unsigned char VDLSEL:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LXTCRbits_t;
extern volatile __LXTCRbits_t __at(LXTCR_ADDR) LXTCRbits;

#define LPEN0     	LXTCRbits.LPEN0     	/* bit 0 */
#define LPEN1     	LXTCRbits.LPEN1     	/* bit 1 */
#define LPEN2     	LXTCRbits.LPEN2     	/* bit 2 */
#define FILS      	LXTCRbits.FILS      	/* bit 3 */
#define VDLSEL    	LXTCRbits.VDLSEL    	/* bit 4 */

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

#define P00DKW    	DKWP0bits.P00DKW    	/* bit 0 */
#define P01DKW    	DKWP0bits.P01DKW    	/* bit 1 */
#define P02DKW    	DKWP0bits.P02DKW    	/* bit 2 */
#define P03DKW    	DKWP0bits.P03DKW    	/* bit 3 */
#define P04DKW    	DKWP0bits.P04DKW    	/* bit 4 */
#define P05DKW    	DKWP0bits.P05DKW    	/* bit 5 */
#define P06DKW    	DKWP0bits.P06DKW    	/* bit 6 */
#define P07DKW    	DKWP0bits.P07DKW    	/* bit 7 */

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

// ----- LCDIOSP1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDIOSP10:1;
		unsigned char LCDIOSP11:1;
		unsigned char LCDIOSP12:1;
		unsigned char LCDIOSP13:1;
		unsigned char LCDIOSP14:1;
		unsigned char LCDIOSP15:1;
		unsigned char LCDIOSP16:1;
		unsigned char LCDIOSP17:1;
	};
} __LCDIOSP1bits_t;
extern volatile __LCDIOSP1bits_t __at(LCDIOSP1_ADDR) LCDIOSP1bits;

#define LCDIOSP10 	LCDIOSP1bits.LCDIOSP10	/* bit 0 */
#define LCDIOSP11 	LCDIOSP1bits.LCDIOSP11	/* bit 1 */
#define LCDIOSP12 	LCDIOSP1bits.LCDIOSP12	/* bit 2 */
#define LCDIOSP13 	LCDIOSP1bits.LCDIOSP13	/* bit 3 */
#define LCDIOSP14 	LCDIOSP1bits.LCDIOSP14	/* bit 4 */
#define LCDIOSP15 	LCDIOSP1bits.LCDIOSP15	/* bit 5 */
#define LCDIOSP16 	LCDIOSP1bits.LCDIOSP16	/* bit 6 */
#define LCDIOSP17 	LCDIOSP1bits.LCDIOSP17	/* bit 7 */

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

// ----- LCDIOSP2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDIOSP20:1;
		unsigned char LCDIOSP21:1;
		unsigned char LCDIOSP22:1;
		unsigned char LCDIOSP23:1;
		unsigned char LCDIOSP24:1;
		unsigned char LCDIOSP25:1;
		unsigned char LCDIOSP26:1;
		unsigned char LCDIOSP27:1;
	};
} __LCDIOSP2bits_t;
extern volatile __LCDIOSP2bits_t __at(LCDIOSP2_ADDR) LCDIOSP2bits;

#define LCDIOSP20 	LCDIOSP2bits.LCDIOSP20	/* bit 0 */
#define LCDIOSP21 	LCDIOSP2bits.LCDIOSP21	/* bit 1 */
#define LCDIOSP22 	LCDIOSP2bits.LCDIOSP22	/* bit 2 */
#define LCDIOSP23 	LCDIOSP2bits.LCDIOSP23	/* bit 3 */
#define LCDIOSP24 	LCDIOSP2bits.LCDIOSP24	/* bit 4 */
#define LCDIOSP25 	LCDIOSP2bits.LCDIOSP25	/* bit 5 */
#define LCDIOSP26 	LCDIOSP2bits.LCDIOSP26	/* bit 6 */
#define LCDIOSP27 	LCDIOSP2bits.LCDIOSP27	/* bit 7 */

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

#define P30D      	IOP3bits.P30D       	/* bit 0 */
#define P31D      	IOP3bits.P31D       	/* bit 1 */
#define P32D      	IOP3bits.P32D       	/* bit 2 */
#define P33D      	IOP3bits.P33D       	/* bit 3 */
#define P34D      	IOP3bits.P34D       	/* bit 4 */
#define P35D      	IOP3bits.P35D       	/* bit 5 */
#define P36D      	IOP3bits.P36D       	/* bit 6 */
#define P37D      	IOP3bits.P37D       	/* bit 7 */

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

#define P30OE     	OEP3bits.P30OE      	/* bit 0 */
#define P31OE     	OEP3bits.P31OE      	/* bit 1 */
#define P32OE     	OEP3bits.P32OE      	/* bit 2 */
#define P33OE     	OEP3bits.P33OE      	/* bit 3 */
#define P34OE     	OEP3bits.P34OE      	/* bit 4 */
#define P35OE     	OEP3bits.P35OE      	/* bit 5 */
#define P36OE     	OEP3bits.P36OE      	/* bit 6 */
#define P37OE     	OEP3bits.P37OE      	/* bit 7 */

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

#define P30PU     	PUP3bits.P30PU      	/* bit 0 */
#define P31PU     	PUP3bits.P31PU      	/* bit 1 */
#define P32PU     	PUP3bits.P32PU      	/* bit 2 */
#define P33PU     	PUP3bits.P33PU      	/* bit 3 */
#define P34PU     	PUP3bits.P34PU      	/* bit 4 */
#define P35PU     	PUP3bits.P35PU      	/* bit 5 */
#define P36PU     	PUP3bits.P36PU      	/* bit 6 */
#define P37PU     	PUP3bits.P37PU      	/* bit 7 */

// ----- LCDIOSP3 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDIOSP30:1;
		unsigned char LCDIOSP31:1;
		unsigned char LCDIOSP32:1;
		unsigned char LCDIOSP33:1;
		unsigned char LCDIOSP34:1;
		unsigned char LCDIOSP35:1;
		unsigned char LCDIOSP36:1;
		unsigned char LCDIOSP37:1;
	};
} __LCDIOSP3bits_t;
extern volatile __LCDIOSP3bits_t __at(LCDIOSP3_ADDR) LCDIOSP3bits;

#define LCDIOSP30 	LCDIOSP3bits.LCDIOSP30	/* bit 0 */
#define LCDIOSP31 	LCDIOSP3bits.LCDIOSP31	/* bit 1 */
#define LCDIOSP32 	LCDIOSP3bits.LCDIOSP32	/* bit 2 */
#define LCDIOSP33 	LCDIOSP3bits.LCDIOSP33	/* bit 3 */
#define LCDIOSP34 	LCDIOSP3bits.LCDIOSP34	/* bit 4 */
#define LCDIOSP35 	LCDIOSP3bits.LCDIOSP35	/* bit 5 */
#define LCDIOSP36 	LCDIOSP3bits.LCDIOSP36	/* bit 6 */
#define LCDIOSP37 	LCDIOSP3bits.LCDIOSP37	/* bit 7 */

// ----- IOP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40D:1;
		unsigned char P41D:1;
		unsigned char P42D:1;
		unsigned char P43D:1;
		unsigned char P44D:1;
		unsigned char P45D:1;
		unsigned char P46D:1;
		unsigned char P47D:1;
	};
} __IOP4bits_t;
extern volatile __IOP4bits_t __at(IOP4_ADDR) IOP4bits;

#define P40D      	IOP4bits.P40D       	/* bit 0 */
#define P41D      	IOP4bits.P41D       	/* bit 1 */
#define P42D      	IOP4bits.P42D       	/* bit 2 */
#define P43D      	IOP4bits.P43D       	/* bit 3 */
#define P44D      	IOP4bits.P44D       	/* bit 4 */
#define P45D      	IOP4bits.P45D       	/* bit 5 */
#define P46D      	IOP4bits.P46D       	/* bit 6 */
#define P47D      	IOP4bits.P47D       	/* bit 7 */

// ----- OEP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40OE:1;
		unsigned char P41OE:1;
		unsigned char P42OE:1;
		unsigned char P43OE:1;
		unsigned char P44OE:1;
		unsigned char P45OE:1;
		unsigned char P46OE:1;
		unsigned char P47OE:1;
	};
} __OEP4bits_t;
extern volatile __OEP4bits_t __at(OEP4_ADDR) OEP4bits;

#define P40OE     	OEP4bits.P40OE      	/* bit 0 */
#define P41OE     	OEP4bits.P41OE      	/* bit 1 */
#define P42OE     	OEP4bits.P42OE      	/* bit 2 */
#define P43OE     	OEP4bits.P43OE      	/* bit 3 */
#define P44OE     	OEP4bits.P44OE      	/* bit 4 */
#define P45OE     	OEP4bits.P45OE      	/* bit 5 */
#define P46OE     	OEP4bits.P46OE      	/* bit 6 */
#define P47OE     	OEP4bits.P47OE      	/* bit 7 */

// ----- PUP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P40PU:1;
		unsigned char P41PU:1;
		unsigned char P42PU:1;
		unsigned char P43PU:1;
		unsigned char P44PU:1;
		unsigned char P45PU:1;
		unsigned char P46PU:1;
		unsigned char P47PU:1;
	};
} __PUP4bits_t;
extern volatile __PUP4bits_t __at(PUP4_ADDR) PUP4bits;

#define P40PU     	PUP4bits.P40PU      	/* bit 0 */
#define P41PU     	PUP4bits.P41PU      	/* bit 1 */
#define P42PU     	PUP4bits.P42PU      	/* bit 2 */
#define P43PU     	PUP4bits.P43PU      	/* bit 3 */
#define P44PU     	PUP4bits.P44PU      	/* bit 4 */
#define P45PU     	PUP4bits.P45PU      	/* bit 5 */
#define P46PU     	PUP4bits.P46PU      	/* bit 6 */
#define P47PU     	PUP4bits.P47PU      	/* bit 7 */

// ----- LCDIOSP4 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDIOSP40:1;
		unsigned char LCDIOSP41:1;
		unsigned char LCDIOSP42:1;
		unsigned char LCDIOSP43:1;
		unsigned char LCDIOSP44:1;
		unsigned char LCDIOSP45:1;
		unsigned char LCDIOSP46:1;
		unsigned char LCDIOSP47:1;
	};
} __LCDIOSP4bits_t;
extern volatile __LCDIOSP4bits_t __at(LCDIOSP4_ADDR) LCDIOSP4bits;

#define LCDIOSP40 	LCDIOSP4bits.LCDIOSP40	/* bit 0 */
#define LCDIOSP41 	LCDIOSP4bits.LCDIOSP41	/* bit 1 */
#define LCDIOSP42 	LCDIOSP4bits.LCDIOSP42	/* bit 2 */
#define LCDIOSP43 	LCDIOSP4bits.LCDIOSP43	/* bit 3 */
#define LCDIOSP44 	LCDIOSP4bits.LCDIOSP44	/* bit 4 */
#define LCDIOSP45 	LCDIOSP4bits.LCDIOSP45	/* bit 5 */
#define LCDIOSP46 	LCDIOSP4bits.LCDIOSP46	/* bit 6 */
#define LCDIOSP47 	LCDIOSP4bits.LCDIOSP47	/* bit 7 */

// ----- IOP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P50D:1;
		unsigned char P51D:1;
		unsigned char P52D:1;
		unsigned char P53D:1;
		unsigned char P54D:1;
		unsigned char P55D:1;
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
#define P55D      	IOP5bits.P55D       	/* bit 5 */

// ----- OEP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P50OE:1;
		unsigned char P51OE:1;
		unsigned char P52OE:1;
		unsigned char P53OE:1;
		unsigned char P54OE:1;
		unsigned char P55OE:1;
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
#define P55OE     	OEP5bits.P55OE      	/* bit 5 */

// ----- PUP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char P50PU:1;
		unsigned char P51PU:1;
		unsigned char P52PU:1;
		unsigned char P53PU:1;
		unsigned char :1;
		unsigned char P55PU:1;
		unsigned char :1;
		unsigned char :1;
	};
} __PUP5bits_t;
extern volatile __PUP5bits_t __at(PUP5_ADDR) PUP5bits;

#define P50PU     	PUP5bits.P50PU      	/* bit 0 */
#define P51PU     	PUP5bits.P51PU      	/* bit 1 */
#define P52PU     	PUP5bits.P52PU      	/* bit 2 */
#define P53PU     	PUP5bits.P53PU      	/* bit 3 */
#define P55PU     	PUP5bits.P55PU      	/* bit 5 */

// ----- LCDIOSP5 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDIOSP50:1;
		unsigned char LCDIOSP51:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDIOSP5bits_t;
extern volatile __LCDIOSP5bits_t __at(LCDIOSP5_ADDR) LCDIOSP5bits;

#define LCDIOSP50 	LCDIOSP5bits.LCDIOSP50	/* bit 0 */
#define LCDIOSP51 	LCDIOSP5bits.LCDIOSP51	/* bit 1 */

// ----- T0CR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0PR0:1;
		unsigned char T0PR1:1;
		unsigned char T0PR2:1;
		unsigned char T0PTS0:1;
		unsigned char T0PTS1:1;
		unsigned char T0MOD0:1;
		unsigned char T0MOD1:1;
		unsigned char TC0EN:1;
	};
} __T0CR0bits_t;
extern volatile __T0CR0bits_t __at(T0CR0_ADDR) T0CR0bits;

#define T0PR0     	T0CR0bits.T0PR0     	/* bit 0 */
#define T0PR1     	T0CR0bits.T0PR1     	/* bit 1 */
#define T0PR2     	T0CR0bits.T0PR2     	/* bit 2 */
#define T0PTS0    	T0CR0bits.T0PTS0    	/* bit 3 */
#define T0PTS1    	T0CR0bits.T0PTS1    	/* bit 4 */
#define T0MOD0    	T0CR0bits.T0MOD0    	/* bit 5 */
#define T0MOD1    	T0CR0bits.T0MOD1    	/* bit 6 */
#define TC0EN     	T0CR0bits.TC0EN     	/* bit 7 */

// ----- T0CR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FPWMB0:1;
		unsigned char FPWMB1:1;
		unsigned char FPWMA0:1;
		unsigned char FPWMA1:1;
		unsigned char FPWMS:1;
		unsigned char :1;
		unsigned char PWMEN:1;
		unsigned char FPWMEN:1;
	};
} __T0CR1bits_t;
extern volatile __T0CR1bits_t __at(T0CR1_ADDR) T0CR1bits;

#define FPWMB0    	T0CR1bits.FPWMB0    	/* bit 0 */
#define FPWMB1    	T0CR1bits.FPWMB1    	/* bit 1 */
#define FPWMA0    	T0CR1bits.FPWMA0    	/* bit 2 */
#define FPWMA1    	T0CR1bits.FPWMA1    	/* bit 3 */
#define FPWMS     	T0CR1bits.FPWMS     	/* bit 4 */
#define PWMEN     	T0CR1bits.PWMEN     	/* bit 6 */
#define FPWMEN    	T0CR1bits.FPWMEN    	/* bit 7 */

// ----- T0LOADL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LOADL0:1;
		unsigned char T0LOADL1:1;
		unsigned char T0LOADL2:1;
		unsigned char T0LOADL3:1;
		unsigned char T0LOADL4:1;
		unsigned char T0LOADL5:1;
		unsigned char T0LOADL6:1;
		unsigned char T0LOADL7:1;
	};
} __T0LOADLbits_t;
extern volatile __T0LOADLbits_t __at(T0LOADL_ADDR) T0LOADLbits;

#define T0LOADL0  	T0LOADLbits.T0LOADL0	/* bit 0 */
#define T0LOADL1  	T0LOADLbits.T0LOADL1	/* bit 1 */
#define T0LOADL2  	T0LOADLbits.T0LOADL2	/* bit 2 */
#define T0LOADL3  	T0LOADLbits.T0LOADL3	/* bit 3 */
#define T0LOADL4  	T0LOADLbits.T0LOADL4	/* bit 4 */
#define T0LOADL5  	T0LOADLbits.T0LOADL5	/* bit 5 */
#define T0LOADL6  	T0LOADLbits.T0LOADL6	/* bit 6 */
#define T0LOADL7  	T0LOADLbits.T0LOADL7	/* bit 7 */

// ----- T0DATAH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0DATAH0:1;
		unsigned char T0DATAH1:1;
		unsigned char T0DATAH2:1;
		unsigned char T0DATAH3:1;
		unsigned char T0DATAH4:1;
		unsigned char T0DATAH5:1;
		unsigned char T0DATAH6:1;
		unsigned char T0DATAH7:1;
	};
} __T0DATAHbits_t;
extern volatile __T0DATAHbits_t __at(T0DATAH_ADDR) T0DATAHbits;

#define T0DATAH0  	T0DATAHbits.T0DATAH0	/* bit 0 */
#define T0DATAH1  	T0DATAHbits.T0DATAH1	/* bit 1 */
#define T0DATAH2  	T0DATAHbits.T0DATAH2	/* bit 2 */
#define T0DATAH3  	T0DATAHbits.T0DATAH3	/* bit 3 */
#define T0DATAH4  	T0DATAHbits.T0DATAH4	/* bit 4 */
#define T0DATAH5  	T0DATAHbits.T0DATAH5	/* bit 5 */
#define T0DATAH6  	T0DATAHbits.T0DATAH6	/* bit 6 */
#define T0DATAH7  	T0DATAHbits.T0DATAH7	/* bit 7 */

// ----- T0DATAL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0DATAL0:1;
		unsigned char T0DATAL1:1;
		unsigned char T0DATAL2:1;
		unsigned char T0DATAL3:1;
		unsigned char T0DATAL4:1;
		unsigned char T0DATAL5:1;
		unsigned char T0DATAL6:1;
		unsigned char T0DATAL7:1;
	};
} __T0DATALbits_t;
extern volatile __T0DATALbits_t __at(T0DATAL_ADDR) T0DATALbits;

#define T0DATAL0  	T0DATALbits.T0DATAL0	/* bit 0 */
#define T0DATAL1  	T0DATALbits.T0DATAL1	/* bit 1 */
#define T0DATAL2  	T0DATALbits.T0DATAL2	/* bit 2 */
#define T0DATAL3  	T0DATALbits.T0DATAL3	/* bit 3 */
#define T0DATAL4  	T0DATALbits.T0DATAL4	/* bit 4 */
#define T0DATAL5  	T0DATALbits.T0DATAL5	/* bit 5 */
#define T0DATAL6  	T0DATALbits.T0DATAL6	/* bit 6 */
#define T0DATAL7  	T0DATALbits.T0DATAL7	/* bit 7 */

// ----- T0LATRH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LATRH0:1;
		unsigned char T0LATRH1:1;
		unsigned char T0LATRH2:1;
		unsigned char T0LATRH3:1;
		unsigned char T0LATRH4:1;
		unsigned char T0LATRH5:1;
		unsigned char T0LATRH6:1;
		unsigned char T0LATRH7:1;
	};
} __T0LATRHbits_t;
extern volatile __T0LATRHbits_t __at(T0LATRH_ADDR) T0LATRHbits;

#define T0LATRH0  	T0LATRHbits.T0LATRH0	/* bit 0 */
#define T0LATRH1  	T0LATRHbits.T0LATRH1	/* bit 1 */
#define T0LATRH2  	T0LATRHbits.T0LATRH2	/* bit 2 */
#define T0LATRH3  	T0LATRHbits.T0LATRH3	/* bit 3 */
#define T0LATRH4  	T0LATRHbits.T0LATRH4	/* bit 4 */
#define T0LATRH5  	T0LATRHbits.T0LATRH5	/* bit 5 */
#define T0LATRH6  	T0LATRHbits.T0LATRH6	/* bit 6 */
#define T0LATRH7  	T0LATRHbits.T0LATRH7	/* bit 7 */

// ----- T0LATRL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LATRL0:1;
		unsigned char T0LATRL1:1;
		unsigned char T0LATRL2:1;
		unsigned char T0LATRL3:1;
		unsigned char T0LATRL4:1;
		unsigned char T0LATRL5:1;
		unsigned char T0LATRL6:1;
		unsigned char T0LATRL7:1;
	};
} __T0LATRLbits_t;
extern volatile __T0LATRLbits_t __at(T0LATRL_ADDR) T0LATRLbits;

#define T0LATRL0  	T0LATRLbits.T0LATRL0	/* bit 0 */
#define T0LATRL1  	T0LATRLbits.T0LATRL1	/* bit 1 */
#define T0LATRL2  	T0LATRLbits.T0LATRL2	/* bit 2 */
#define T0LATRL3  	T0LATRLbits.T0LATRL3	/* bit 3 */
#define T0LATRL4  	T0LATRLbits.T0LATRL4	/* bit 4 */
#define T0LATRL5  	T0LATRLbits.T0LATRL5	/* bit 5 */
#define T0LATRL6  	T0LATRLbits.T0LATRL6	/* bit 6 */
#define T0LATRL7  	T0LATRLbits.T0LATRL7	/* bit 7 */

// ----- T0LATFH Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LATFH0:1;
		unsigned char T0LATFH1:1;
		unsigned char T0LATFH2:1;
		unsigned char T0LATFH3:1;
		unsigned char T0LATFH4:1;
		unsigned char T0LATFH5:1;
		unsigned char T0LATFH6:1;
		unsigned char T0LATFH7:1;
	};
} __T0LATFHbits_t;
extern volatile __T0LATFHbits_t __at(T0LATFH_ADDR) T0LATFHbits;

#define T0LATFH0  	T0LATFHbits.T0LATFH0	/* bit 0 */
#define T0LATFH1  	T0LATFHbits.T0LATFH1	/* bit 1 */
#define T0LATFH2  	T0LATFHbits.T0LATFH2	/* bit 2 */
#define T0LATFH3  	T0LATFHbits.T0LATFH3	/* bit 3 */
#define T0LATFH4  	T0LATFHbits.T0LATFH4	/* bit 4 */
#define T0LATFH5  	T0LATFHbits.T0LATFH5	/* bit 5 */
#define T0LATFH6  	T0LATFHbits.T0LATFH6	/* bit 6 */
#define T0LATFH7  	T0LATFHbits.T0LATFH7	/* bit 7 */

// ----- T0LATFL Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T0LATFL0:1;
		unsigned char T0LATFL1:1;
		unsigned char T0LATFL2:1;
		unsigned char T0LATFL3:1;
		unsigned char T0LATFL4:1;
		unsigned char T0LATFL5:1;
		unsigned char T0LATFL6:1;
		unsigned char T0LATFL7:1;
	};
} __T0LATFLbits_t;
extern volatile __T0LATFLbits_t __at(T0LATFL_ADDR) T0LATFLbits;

#define T0LATFL0  	T0LATFLbits.T0LATFL0	/* bit 0 */
#define T0LATFL1  	T0LATFLbits.T0LATFL1	/* bit 1 */
#define T0LATFL2  	T0LATFLbits.T0LATFL2	/* bit 2 */
#define T0LATFL3  	T0LATFLbits.T0LATFL3	/* bit 3 */
#define T0LATFL4  	T0LATFLbits.T0LATFL4	/* bit 4 */
#define T0LATFL5  	T0LATFLbits.T0LATFL5	/* bit 5 */
#define T0LATFL6  	T0LATFLbits.T0LATFL6	/* bit 6 */
#define T0LATFL7  	T0LATFLbits.T0LATFL7	/* bit 7 */

// ----- T1CR Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char T1PR0:1;
		unsigned char T1PR1:1;
		unsigned char T1PR2:1;
		unsigned char T1PTS0:1;
		unsigned char T1PTS1:1;
		unsigned char T1MOD0:1;
		unsigned char T1MOD1:1;
		unsigned char TC1EN:1;
	};
} __T1CRbits_t;
extern volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;

#define T1PR0     	T1CRbits.T1PR0      	/* bit 0 */
#define T1PR1     	T1CRbits.T1PR1      	/* bit 1 */
#define T1PR2     	T1CRbits.T1PR2      	/* bit 2 */
#define T1PTS0    	T1CRbits.T1PTS0     	/* bit 3 */
#define T1PTS1    	T1CRbits.T1PTS1     	/* bit 4 */
#define T1MOD0    	T1CRbits.T1MOD0     	/* bit 5 */
#define T1MOD1    	T1CRbits.T1MOD1     	/* bit 6 */
#define TC1EN     	T1CRbits.TC1EN      	/* bit 7 */

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

#define T1DATA0   	T1DATAbits.T1DATA0  	/* bit 0 */
#define T1DATA1   	T1DATAbits.T1DATA1  	/* bit 1 */
#define T1DATA2   	T1DATAbits.T1DATA2  	/* bit 2 */
#define T1DATA3   	T1DATAbits.T1DATA3  	/* bit 3 */
#define T1DATA4   	T1DATAbits.T1DATA4  	/* bit 4 */
#define T1DATA5   	T1DATAbits.T1DATA5  	/* bit 5 */
#define T1DATA6   	T1DATAbits.T1DATA6  	/* bit 6 */
#define T1DATA7   	T1DATAbits.T1DATA7  	/* bit 7 */

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

#define T1LOAD0   	T1LOADbits.T1LOAD0  	/* bit 0 */
#define T1LOAD1   	T1LOADbits.T1LOAD1  	/* bit 1 */
#define T1LOAD2   	T1LOADbits.T1LOAD2  	/* bit 2 */
#define T1LOAD3   	T1LOADbits.T1LOAD3  	/* bit 3 */
#define T1LOAD4   	T1LOADbits.T1LOAD4  	/* bit 4 */
#define T1LOAD5   	T1LOADbits.T1LOAD5  	/* bit 5 */
#define T1LOAD6   	T1LOADbits.T1LOAD6  	/* bit 6 */
#define T1LOAD7   	T1LOADbits.T1LOAD7  	/* bit 7 */

// ----- ADCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char ADON:1;
		unsigned char ADEOC:1;
		unsigned char ADCKS0:1;
		unsigned char ADCKS1:1;
		unsigned char ADCHS0:1;
		unsigned char ADCHS1:1;
		unsigned char ADCHS2:1;
		unsigned char ADCHS3:1;
	};
} __ADCR0bits_t;
extern volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;

#define ADON      	ADCR0bits.ADON      	/* bit 0 */
#define ADEOC     	ADCR0bits.ADEOC     	/* bit 1 */
#define ADCKS0    	ADCR0bits.ADCKS0    	/* bit 2 */
#define ADCKS1    	ADCR0bits.ADCKS1    	/* bit 3 */
#define ADCHS0    	ADCR0bits.ADCHS0    	/* bit 4 */
#define ADCHS1    	ADCR0bits.ADCHS1    	/* bit 5 */
#define ADCHS2    	ADCR0bits.ADCHS2    	/* bit 6 */
#define ADCHS3    	ADCR0bits.ADCHS3    	/* bit 7 */

// ----- ADCR1 Bits --------------------------------------------
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
} __ADCR1bits_t;
extern volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;

#define ADIOS0    	ADCR1bits.ADIOS0    	/* bit 0 */
#define ADIOS1    	ADCR1bits.ADIOS1    	/* bit 1 */
#define ADIOS2    	ADCR1bits.ADIOS2    	/* bit 2 */
#define ADIOS3    	ADCR1bits.ADIOS3    	/* bit 3 */
#define ADIOS4    	ADCR1bits.ADIOS4    	/* bit 4 */
#define ADIOS5    	ADCR1bits.ADIOS5    	/* bit 5 */
#define ADIOS6    	ADCR1bits.ADIOS6    	/* bit 6 */
#define ADIOS7    	ADCR1bits.ADIOS7    	/* bit 7 */

// ----- ADCR2 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char VREXT:1;
		unsigned char VREFRES:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __ADCR2bits_t;
extern volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;

#define VREXT     	ADCR2bits.VREXT     	/* bit 0 */
#define VREFRES   	ADCR2bits.VREFRES   	/* bit 1 */

// ----- OPCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char OPFC0:1;
		unsigned char OPFC1:1;
		unsigned char OPFC2:1;
		unsigned char OPFC3:1;
		unsigned char OPFC4:1;
		unsigned char OPFC5:1;
		unsigned char OPAM:1;
		unsigned char OPAE:1;
	};
} __OPCR0bits_t;
extern volatile __OPCR0bits_t __at(OPCR0_ADDR) OPCR0bits;

#define OPFC0     	OPCR0bits.OPFC0     	/* bit 0 */
#define OPFC1     	OPCR0bits.OPFC1     	/* bit 1 */
#define OPFC2     	OPCR0bits.OPFC2     	/* bit 2 */
#define OPFC3     	OPCR0bits.OPFC3     	/* bit 3 */
#define OPFC4     	OPCR0bits.OPFC4     	/* bit 4 */
#define OPFC5     	OPCR0bits.OPFC5     	/* bit 5 */
#define OPAM      	OPCR0bits.OPAM      	/* bit 6 */
#define OPAE      	OPCR0bits.OPAE      	/* bit 7 */

// ----- OPCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char CSEL0:1;
		unsigned char CSEL1:1;
		unsigned char FSEL0:1;
		unsigned char FSEL1:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char VSEL:1;
		unsigned char IRIN:1;
	};
} __OPCR1bits_t;
extern volatile __OPCR1bits_t __at(OPCR1_ADDR) OPCR1bits;

#define CSEL0     	OPCR1bits.CSEL0     	/* bit 0 */
#define CSEL1     	OPCR1bits.CSEL1     	/* bit 1 */
#define FSEL0     	OPCR1bits.FSEL0     	/* bit 2 */
#define FSEL1     	OPCR1bits.FSEL1     	/* bit 3 */
#define VSEL      	OPCR1bits.VSEL      	/* bit 6 */
#define IRIN      	OPCR1bits.IRIN      	/* bit 7 */

// ----- LCDCR0 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDRS0:1;
		unsigned char LCDRS1:1;
		unsigned char LCDSPEED:1;
		unsigned char VLCDS:1;
		unsigned char LCDDUTY:1;
		unsigned char LCDSP0:1;
		unsigned char LCDSP1:1;
		unsigned char LCDEN:1;
	};
} __LCDCR0bits_t;
extern volatile __LCDCR0bits_t __at(LCDCR0_ADDR) LCDCR0bits;

#define LCDRS0    	LCDCR0bits.LCDRS0   	/* bit 0 */
#define LCDRS1    	LCDCR0bits.LCDRS1   	/* bit 1 */
#define LCDSPEED  	LCDCR0bits.LCDSPEED 	/* bit 2 */
#define VLCDS     	LCDCR0bits.VLCDS    	/* bit 3 */
#define LCDDUTY   	LCDCR0bits.LCDDUTY  	/* bit 4 */
#define LCDSP0    	LCDCR0bits.LCDSP0   	/* bit 5 */
#define LCDSP1    	LCDCR0bits.LCDSP1   	/* bit 6 */
#define LCDEN     	LCDCR0bits.LCDEN    	/* bit 7 */

// ----- LCDCR1 Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char FLCD0:1;
		unsigned char FLCD1:1;
		unsigned char LCDCKS:1;
		unsigned char LCDM:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDCR1bits_t;
extern volatile __LCDCR1bits_t __at(LCDCR1_ADDR) LCDCR1bits;

#define FLCD0     	LCDCR1bits.FLCD0    	/* bit 0 */
#define FLCD1     	LCDCR1bits.FLCD1    	/* bit 1 */
#define LCDCKS    	LCDCR1bits.LCDCKS   	/* bit 2 */
#define LCDM      	LCDCR1bits.LCDM     	/* bit 3 */

// ----- DKW Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char DSELEN:1;
		unsigned char DRVS:1;
		unsigned char RSEL:1;
		unsigned char WSEL0:1;
		unsigned char WSEL1:1;
		unsigned char IROT:1;
		unsigned char IROS:1;
		unsigned char DKWE:1;
	};
} __DKWbits_t;
extern volatile __DKWbits_t __at(DKW_ADDR) DKWbits;

#define DSELEN    	DKWbits.DSELEN      	/* bit 0 */
#define DRVS      	DKWbits.DRVS        	/* bit 1 */
#define RSEL      	DKWbits.RSEL        	/* bit 2 */
#define WSEL0     	DKWbits.WSEL0       	/* bit 3 */
#define WSEL1     	DKWbits.WSEL1       	/* bit 4 */
#define IROT      	DKWbits.IROT        	/* bit 5 */
#define IROS      	DKWbits.IROS        	/* bit 6 */
#define DKWE      	DKWbits.DKWE        	/* bit 7 */

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
		unsigned char KBCR7:1;
	};
} __KBCRbits_t;
extern volatile __KBCRbits_t __at(KBCR_ADDR) KBCRbits;

#define KBCR0     	KBCRbits.KBCR0      	/* bit 0 */
#define KBCR1     	KBCRbits.KBCR1      	/* bit 1 */
#define KBCR2     	KBCRbits.KBCR2      	/* bit 2 */
#define KBCR3     	KBCRbits.KBCR3      	/* bit 3 */
#define KBCR4     	KBCRbits.KBCR4      	/* bit 4 */
#define KBCR5     	KBCRbits.KBCR5      	/* bit 5 */
#define KBCR6     	KBCRbits.KBCR6      	/* bit 6 */
#define KBCR7     	KBCRbits.KBCR7      	/* bit 7 */

// ----- LCDDRV Bits --------------------------------------------
typedef union {
	 struct {
		unsigned char LCDDRVP06:1;
		unsigned char LCDDRVP22:1;
		unsigned char LCDDRVP23:1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
		unsigned char :1;
	};
} __LCDDRVbits_t;
extern volatile __LCDDRVbits_t __at(LCDDRV_ADDR) LCDDRVbits;

#define LCDDRVP06 	LCDDRVbits.LCDDRVP06	/* bit 0 */
#define LCDDRVP22 	LCDDRVbits.LCDDRVP22	/* bit 1 */
#define LCDDRVP23 	LCDDRVbits.LCDDRVP23	/* bit 2 */

#endif
