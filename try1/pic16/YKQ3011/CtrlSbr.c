#include <mc30p011.h>
#include "externVAR.h"
#include "CONST.H"

const  char  BlueTbl[ ] =  {255,255,14,252,247,38,255,174,214,35,214,117};
const  char  GreenTbl[ ] = {255,14,255,139,24,247,38,31,38,88,247,221};
const  char  RedTbl[ ] =   {14,255,255,26,160,227,0,174,49,227,39,174};

//;----------------------------------------------------------------	
//;单色模式
void ColorSbr()
{
	TRed = RedTbl[Color];
	TGreen = GreenTbl[Color];
	TBlue = BlueTbl[Color];
}

//;----------------------------------------------------------------	
//;变色模式
void MColorSbr()
{
	if (++delay >= 4) 
		{
		delay = 0;
		if (--Mode1Cnt == 0)
			{
			TGreen = TColor;
			TRed = TColor;
			TBlue = TColor;
			if (++Step > 5) Step = 0;
			Mode1Cnt = TSteplengh;
			}
		if (Step == 0) {++TGreen;--TBlue;return;}
		if (Step == 1) {--TGreen;++TBlue;return;}
		if (Step == 2) {++TRed;--TBlue;return;}
		if (Step == 3) {--TRed;++TBlue;return;}
		if (Step == 4) {++TRed;--TGreen;return;}
		if (Step == 5) {--TRed;++TGreen;return;}
/*
		switch(Step)
			{
			case 0:
				++TGreen;
				--TBlue;
				break;
			case 1:
				++TBlue;
				--TGreen;
				break;
			case 2:
				++TRed;
				--TBlue;
				break;
			case 3:
				--TRed;
				++TBlue;
				break;
			case 4:
				++TRed;
				--TGreen;
				break;
			default:
				--TRed;
				++TGreen;
				break;
			}
*/
		}
}

//;----------------------------------------------------------------	
//;烛光模式
void Mode2Sbr()
{
	if (Mode2Cnt2 >= Mode2Cnt3)
		{
		pBlueC = 1;
		pRedC = 1;
		pGreenC = 1;
		if (Mode2Cnt2 > 50) Mode2Cnt2 = 0;
		}
	else
		{
		pBlueC = 0;
		pRedC = 0;
		pGreenC = 0;
		}
}	

