#include <mc30p011.h>
#include "externVar.H"
#include "CONST.H"

extern void IROffKeySbr(void);
extern void IRSbr(void);
void int_isr(void) __interrupt
{
	//;�����ж�---------------------------------------------------
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
	//;��ʱ��0�ж��ӳ���------------------------------------------
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
	//;��ʱ��1�ж��ӳ���------------------------------------------
	if (T1IF) {T1IF = 0;F4ms = 1;}
}

	
	
