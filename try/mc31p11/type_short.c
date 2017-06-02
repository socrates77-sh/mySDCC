#include <mc30p011.h>

short c_a, c_b;
ushort uc_a, uc_b;

void main(void)
{
	c_a = MCR;
	c_b = KBIM;
	uc_a = MCR;
	uc_b = KBIM;

	P0 = c_a + c_b;
	P0 = uc_a + uc_b;
	P1 = c_a - c_b;
	P1 = uc_a - uc_b;

	if (c_a > 0) P0 = c_b;
	if (uc_a > 0) P0 = uc_b;
	
	if (c_a > -3) P0 = c_b;
	if (uc_a > -3) P0 = uc_b;

	while(1);
}
