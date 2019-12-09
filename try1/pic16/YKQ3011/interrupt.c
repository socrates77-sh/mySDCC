#include <mc30p011.h>
#include "externVar.H"
#include "CONST.H"

extern void IROffKeySbr(void);
extern void IRSbr(void);
void int_isr(void) __interrupt
{
	//;键盘中断---------------------------------------------------
	if (KBIF)
	{
	KBIF = 1;
	if (!pIR)
		{
		FStop = 0;
		IRSbr();
		}
	}
	else IRTmr = 0;
	//;定时器0中断子程序------------------------------------------
	if (T0IF)
		{
		T0IF = 0;
		T0CNT = CT0;
		++Mode2Cnt2;
		++TRedCnt;
		if (TRedCnt >= TRed) pRed = 0;
		if (TRedCnt >= TBlue) pBlue = 0;
		if (TRedCnt >= TGreen) pGreen = 0;
		if (TRedCnt >= 242) 
			{
			TRedCnt = 0;
			pBlue = 1;
			pGreen = 1;
			pRed = 1;
			}
		FDouble = !FDouble;
		if (FDouble)
			{
			if (++IRTmr >= 254) --IRTmr;
			}
		}
	//;定时器1中断子程序------------------------------------------
	if (T1IF) {T1IF = 0;F4ms = 1;}
}

	
	
