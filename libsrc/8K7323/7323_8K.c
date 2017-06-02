#include <7323_8K.h>

__sfr __at (INDF_ADDR)     	INDF;
__sfr __at (INDF0_ADDR)    	INDF0;
__sfr __at (INDF1_ADDR)    	INDF1;
__sfr __at (INDF2_ADDR)    	INDF2;
__sfr __at (HIBYTE_ADDR)   	HIBYTE;
__sfr __at (FSR_ADDR)      	FSR;
__sfr __at (FSR0_ADDR)     	FSR0;
__sfr __at (FSR1_ADDR)     	FSR1;
__sfr __at (PCL_ADDR)      	PCL;
__sfr __at (STATUS_ADDR)   	STATUS;
__sfr __at (PFLAG_ADDR)    	PFLAG;
__sfr __at (MCR_ADDR)      	MCR;
__sfr __at (INDF3_ADDR)    	INDF3;
__sfr __at (INTE_ADDR)     	INTE;
__sfr __at (INTF_ADDR)     	INTF;
__sfr __at (OSCM_ADDR)     	OSCM;
__sfr __at (IOP0_ADDR)     	IOP0;
__sfr __at (OEP0_ADDR)     	OEP0;
__sfr __at (PUP0_ADDR)     	PUP0;
__sfr __at (IOP1_ADDR)     	IOP1;
__sfr __at (OEP1_ADDR)     	OEP1;
__sfr __at (PUP1_ADDR)     	PUP1;
__sfr __at (IOP2_ADDR)     	IOP2;
__sfr __at (OEP2_ADDR)     	OEP2;
__sfr __at (PUP2_ADDR)     	PUP2;
__sfr __at (T0CR_ADDR)     	T0CR;
__sfr __at (T0CNT_ADDR)    	T0CNT;
__sfr __at (T0LOAD_ADDR)   	T0LOAD;
__sfr __at (T0DATA_ADDR)   	T0DATA;
__sfr __at (T1CR_ADDR)     	T1CR;
__sfr __at (T1CNT_ADDR)    	T1CNT;
__sfr __at (T1LOAD_ADDR)   	T1LOAD;
__sfr __at (T1DATA_ADDR)   	T1DATA;
__sfr __at (T2CR_ADDR)     	T2CR;
__sfr __at (T2CNT_ADDR)    	T2CNT;
__sfr __at (T2LOAD_ADDR)   	T2LOAD;
__sfr __at (T2DATA_ADDR)   	T2DATA;
__sfr __at (T3CR_ADDR)     	T3CR;
__sfr __at (T3CNT_ADDR)    	T3CNT;
__sfr __at (T3LOAD_ADDR)   	T3LOAD;
__sfr __at (PWM0DE_ADDR)   	PWM0DE;
__sfr __at (PWM1DE_ADDR)   	PWM1DE;
__sfr __at (PWM2DE_ADDR)   	PWM2DE;
__sfr __at (PWMCR0_ADDR)   	PWMCR0;
__sfr __at (PWMCR1_ADDR)   	PWMCR1;
__sfr __at (ADCR0_ADDR)    	ADCR0;
__sfr __at (ADCR1_ADDR)    	ADCR1;
__sfr __at (ADRH_ADDR)     	ADRH;
__sfr __at (ADRL_ADDR)     	ADRL;
__sfr __at (ANSEL_ADDR)    	ANSEL;
__sfr __at (LEDCR0_ADDR)   	LEDCR0;
__sfr __at (LEDCR1_ADDR)   	LEDCR1;
__sfr __at (LCDCR0_ADDR)   	LCDCR0;
__sfr __at (LCDCR1_ADDR)   	LCDCR1;
__sfr __at (LCDIOS0_ADDR)  	LCDIOS0;
__sfr __at (LCDIOS1_ADDR)  	LCDIOS1;
__sfr __at (LCDIOS2_ADDR)  	LCDIOS2;

volatile __PFLAGbits_t __at(PFLAG_ADDR) PFLAGbits;
volatile __MCRbits_t __at(MCR_ADDR) MCRbits;
volatile __INTEbits_t __at(INTE_ADDR) INTEbits;
volatile __INTFbits_t __at(INTF_ADDR) INTFbits;
volatile __OSCMbits_t __at(OSCM_ADDR) OSCMbits;
volatile __IOP0bits_t __at(IOP0_ADDR) IOP0bits;
volatile __OEP0bits_t __at(OEP0_ADDR) OEP0bits;
volatile __PUP0bits_t __at(PUP0_ADDR) PUP0bits;
volatile __IOP1bits_t __at(IOP1_ADDR) IOP1bits;
volatile __OEP1bits_t __at(OEP1_ADDR) OEP1bits;
volatile __PUP1bits_t __at(PUP1_ADDR) PUP1bits;
volatile __IOP2bits_t __at(IOP2_ADDR) IOP2bits;
volatile __OEP2bits_t __at(OEP2_ADDR) OEP2bits;
volatile __PUP2bits_t __at(PUP2_ADDR) PUP2bits;
volatile __T0CRbits_t __at(T0CR_ADDR) T0CRbits;
volatile __T1CRbits_t __at(T1CR_ADDR) T1CRbits;
volatile __T2CRbits_t __at(T2CR_ADDR) T2CRbits;
volatile __T3CRbits_t __at(T3CR_ADDR) T3CRbits;
volatile __PWMCR0bits_t __at(PWMCR0_ADDR) PWMCR0bits;
volatile __PWMCR1bits_t __at(PWMCR1_ADDR) PWMCR1bits;
volatile __ADCR0bits_t __at(ADCR0_ADDR) ADCR0bits;
volatile __ADCR1bits_t __at(ADCR1_ADDR) ADCR1bits;
volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;
volatile __LEDCR0bits_t __at(LEDCR0_ADDR) LEDCR0bits;
volatile __LEDCR1bits_t __at(LEDCR1_ADDR) LEDCR1bits;
volatile __LCDCR0bits_t __at(LCDCR0_ADDR) LCDCR0bits;
volatile __LCDCR1bits_t __at(LCDCR1_ADDR) LCDCR1bits;
volatile __LCDIOS0bits_t __at(LCDIOS0_ADDR) LCDIOS0bits;
volatile __LCDIOS1bits_t __at(LCDIOS1_ADDR) LCDIOS1bits;
volatile __LCDIOS2bits_t __at(LCDIOS2_ADDR) LCDIOS2bits;
