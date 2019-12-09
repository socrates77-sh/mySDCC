/******************************************************************
;6122码遥控器解码

;******************************************************************/
#include <mc30p011.h>
#include  "VAR.H"
#include  "CONST.H"
extern void InitialSys();
extern void InitalRAM();
extern void Mode2Sbr();
extern void MColorSbr();
extern void T1sSbr();

void main ()
{
	GIE = 0;    
	ClrWdt();
	InitialSys();
	InitalRAM();
	FMultiColor = 1;
	FOn = 1;
	pIR = 1;
	KBIE = 1;
	KBIM3 = 1;
	GIE = 1;
	while(1)
		{
		if (FStop)
			{
			T1IF = 0;
			T0IF = 0;
			Nop();
			Nop();
			Nop();
			Stop();
			Nop();
			Nop();
			Nop();
			}
		if ((delay05ms != 0)||(!FOn))
			{
			pRedC = 1;
			pGreenC = 1;
			pBlueC = 1;
			}
		else 
			{
			if (FMultiColor)
				{
				pRedC = 0;
				pGreenC = 0;
				pBlueC = 0;
				}
			else
				{
				if (FCandle) Mode2Sbr();
				}
			}
		if (F4ms)
			{
			F4ms = 0;
			ClrWdt();
			if (delay05ms == 0)
				{
				if (FOn)
					{
					if (FMultiColor) MColorSbr();
					else
						{
						if (FCandle)
							{
							//;烛光模式---------------------------------------
							if (++T40ms > 10)
								{
								T40ms = 0;
								if (FDirection)
									{
									if (++Mode2Cnt3 > 50) FDirection = 0;
									}
								else
									{
									if (--Mode2Cnt3 < 10) FDirection = 1;
									}								
								}
							}
						}
					}
				}
			else --delay05ms;
			T1sSbr();
			}
		}
}

