#include <mc30p011.h>

int c_a, c_b;
uint uc_a, uc_b;

void main(void)
{
	volatile int re;
	c_a = MCR;
	c_b = KBIM;
	uc_a = MCR;
	uc_b = KBIM;

	P0 = c_a + c_b;
	P0 = uc_a + uc_b;
	P1 = c_a - c_b;
	P1 = uc_a - uc_b;

	if (c_a > 0) re = c_b;
	if (uc_a > 0) re = uc_b;
	
	if (c_a > -3) re = c_b;
	if (uc_a > -3) re = uc_b;

	while(1);
}
