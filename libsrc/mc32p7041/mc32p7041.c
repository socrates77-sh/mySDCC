#include <mc32p7041.h>

__sfr __at (HIBYTE_ADDR)   	HIBYTE;
__sfr __at (FSR_ADDR)      	FSR;
__sfr __at (FSR0_ADDR)     	FSR0;
__sfr __at (FSR1_ADDR)     	FSR1;
__sfr __at (STATUS_ADDR)   	STATUS;
__sfr __at (PFLAG_ADDR)    	PFLAG;
__sfr __at (ZEROTR_ADDR)   	ZEROTR;
__sfr __at (OSCCAL_ADDR)   	OSCCAL;
__sfr __at (WKCR0_ADDR)    	WKCR0;
__sfr __at (WKCR5_ADDR)    	WKCR5;
__sfr __at (ADIOS0_ADDR)   	ADIOS0;
__sfr __at (ADIOS1_ADDR)   	ADIOS1;
__sfr __at (ADIOS2_ADDR)   	ADIOS2;
__sfr __at (ADCR0_ADDR)    	ADCR0;
__sfr __at (ADCR1_ADDR)    	ADCR1;
__sfr __at (ADRH_ADDR)     	ADRH;
__sfr __at (ADRL_ADDR)     	ADRL;
__sfr __at (ADCR2_ADDR)    	ADCR2;
__sfr __at (OEP0_ADDR)     	OEP0;
__sfr __at (EINTCR_ADDR)   	EINTCR;
__sfr __at (OEP4_ADDR)     	OEP4;
__sfr __at (OEP5_ADDR)     	OEP5;
__sfr __at (INTF_ADDR)     	INTF;
__sfr __at (INTE_ADDR)     	INTE;
__sfr __at (OSCM_ADDR)     	OSCM;
__sfr __at (WDTCR_ADDR)    	WDTCR;
__sfr __at (T1LDR_ADDR)    	T1LDR;
__sfr __at (PCL_ADDR)      	PCL;
__sfr __at (PCH_ADDR)      	PCH;
__sfr __at (IOP0_ADDR)     	IOP0;
__sfr __at (IOP4_ADDR)     	IOP4;
__sfr __at (IOP5_ADDR)     	IOP5;
__sfr __at (T0CR_ADDR)     	T0CR;
__sfr __at (T0CNT_ADDR)    	T0CNT;
__sfr __at (T1CR_ADDR)     	T1CR;
__sfr __at (T1CNT_ADDR)    	T1CNT;
__sfr __at (BUZCR_ADDR)    	BUZCR;
__sfr __at (MCR_ADDR)      	MCR;
__sfr __at (PUP0_ADDR)     	PUP0;
__sfr __at (PUP4_ADDR)     	PUP4;
__sfr __at (PUP5_ADDR)     	PUP5;
__sfr __at (INDF_ADDR)     	INDF;
__sfr __at (PWMCR0_ADDR)   	PWMCR0;
__sfr __at (PWMCR1_ADDR)   	PWMCR1;
__sfr __at (PWMCNT_ADDR)   	PWMCNT;
__sfr __at (PWMADT_ADDR)   	PWMADT;
__sfr __at (PWMBDT_ADDR)   	PWMBDT;
__sfr __at (PWMCDT_ADDR)   	PWMCDT;
__sfr __at (PWMPD_ADDR)    	PWMPD;
__sfr __at (STKR0L_ADDR)   	STKR0L;
__sfr __at (STKR0H_ADDR)   	STKR0H;
__sfr __at (STKR1L_ADDR)   	STKR1L;
__sfr __at (STKR1H_ADDR)   	STKR1H;
__sfr __at (STKR2L_ADDR)   	STKR2L;
__sfr __at (STKR2H_ADDR)   	STKR2H;
__sfr __at (STKR3L_ADDR)   	STKR3L;
__sfr __at (STKR3H_ADDR)   	STKR3H;
__sfr __at (STKR4L_ADDR)   	STKR4L;
__sfr __at (STKR4H_ADDR)   	STKR4H;
__sfr __at (STKR5L_ADDR)   	STKR5L;
__sfr __at (STKR5H_ADDR)   	STKR5H;
__sfr __at (STKR6L_ADDR)   	STKR6L;
__sfr __at (STKR6H_ADDR)   	STKR6H;
__sfr __at (STKR7L_ADDR)   	STKR7L;
__sfr __at (STKR7H_ADDR)   	STKR7H;

volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;
volatile __ZEROTRbits_t __at(ZEROTR_ADDR) ZEROTRbits;
volatile __OSCCALbits_t __at(OSCCAL_ADDR) OSCCALbits;
volatile __WKCR0bits_t __at(WKCR0_ADDR) WKCR0bits;
volatile __WKCR5bits_t __at(WKCR5_ADDR) WKCR5bits;
volatile __ADIOS0bits_t __at(ADIOS0_ADDR) ADIOS0bits;
volatile __ADIOS1bits_t __at(ADIOS1_ADDR) ADIOS1bits;
volatile __ADIOS2bits_t __at(ADIOS2_ADDR) ADIOS2bits;
volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;
volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;
volatile __ADCR2bits_t __at(ADCR2_ADDR) ADCR2bits;
volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;
volatile __EINTCRbits_t __at(EINTCR_ADDR) EINTCRbits;
volatile __OEP4bits_t __at(OEP4_ADDR) OEP4bits;
volatile __OEP5bits_t __at(OEP5_ADDR) OEP5bits;
volatile __INTFbits_t __at(INTF_ADDR) INTFbits;
volatile __INTEbits_t __at(INTE_ADDR) INTEbits;
volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;
volatile __WDTCRbits_t __at(WDTCR_ADDR) WDTCRbits;
volatile __T1LDRbits_t __at(T1LDR_ADDR) T1LDRbits;
volatile __PCLbits_t __at(PCL_ADDR) PCLbits;
volatile __PCHbits_t __at(PCH_ADDR) PCHbits;
volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;
volatile __IOP4bits_t __at(IOP4_ADDR) IOP4bits;
volatile __IOP5bits_t __at(IOP5_ADDR) IOP5bits;
volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;
volatile __T0CNTbits_t __at(T0CNT_ADDR) T0CNTbits;
volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;
volatile __T1CNTbits_t __at(T1CNT_ADDR) T1CNTbits;
volatile __BUZCRbits_t __at(BUZCR_ADDR) BUZCRbits;
volatile __MCRbits_t __at(MCR_ADDR) MCRbits;
volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;
volatile __PUP4bits_t __at(PUP4_ADDR) PUP4bits;
volatile __PUP5bits_t __at(PUP5_ADDR) PUP5bits;
volatile __INDFbits_t __at(INDF_ADDR) INDFbits;
volatile __PWMCR0bits_t __at(PWMCR0_ADDR) PWMCR0bits;
volatile __PWMCR1bits_t __at(PWMCR1_ADDR) PWMCR1bits;
volatile __PWMCNTbits_t __at(PWMCNT_ADDR) PWMCNTbits;
volatile __PWMADTbits_t __at(PWMADT_ADDR) PWMADTbits;
volatile __PWMBDTbits_t __at(PWMBDT_ADDR) PWMBDTbits;
volatile __PWMCDTbits_t __at(PWMCDT_ADDR) PWMCDTbits;
volatile __PWMPDbits_t __at(PWMPD_ADDR) PWMPDbits;
