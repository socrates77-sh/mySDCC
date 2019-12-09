#include <mc30p011.h>
#include "externVAR.h"
#include "CONST.H"

extern void IROffKeySbr(void);

void T1sSbr()
{
	if (--T1s != 0) return;
	T1s = 250;

	if (!FOn)
		{
		if (--TStop == 0) IROffKeySbr();
		return;
		}
	if (!FTmr) return;
	if (--Tmr == 0) IROffKeySbr();
}


