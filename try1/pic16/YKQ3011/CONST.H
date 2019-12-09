
/****************************************************************
;	Function : Define const
;*****************************************************************/
#ifndef _CONST_H_
#define _CONST_H_


#define	CT0	256-16
#define	CT1	125
/*****************************************************************
;端口定义
;*****************************************************************/
#define	pRed		P10
#define	pGreen		P11
#define	pBlue		P12
#define	pIR			P13
#define	pRedC		DDR10
#define	pGreenC		DDR11
#define	pBlueC		DDR12
//;常数定义-------------------------------------
#define	CIDCode		0x00//;0x80
#define	CIRTMR		2
#define	CIDCode		0x00//;0x80
#define	CIRON		0x45//;0x12	CH-
#define	CIROFF		0x46//;0x1A	CH
#define	CIRMODE		0x47//;0x1E	CH+
#define	CIR4H		0x44//;0x01	PREV
#define	CIR8H		0x40//;0x02	NEXT
#define	CIRMCOLR	0x43//;0x03	PLAY
#define	CIRCOLR1	0x16//;0x04
#define	CIRCOLR2	0x19//;0x05
#define	CIRCOLR3	0x0D//;0x06
#define	CIRCOLR4	0x0C//;0x07
#define	CIRCOLR5	0x18//;0x08
#define	CIRCOLR6	0x5E//;0x09
#define	CIRCOLR7	0x08//;0x0A
#define	CIRCOLR8	0x1C//;0x1B
#define	CIRCOLR9	0x5A//;0x1F
#define	CIRCOLRA	0x42//;0x0C
#define	CIRCOLRB	0x52//;0x0D
#define	CIRCOLRC	0x4A//;0x0E

#define	CHEAD		70//;0x87
#define	CCode0		8	//;0x12
#define	CCode1		26	//;0x33
#define	CCodeR		CHEAD/2

#define	CMCandle	2
#define	CMMColor	0
#define	CMSColor	1

#define	TColor		127
#define	TSteplengh	127
#endif


