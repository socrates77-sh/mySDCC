#include <mc30p011.h>

void main(void)
{
	static char c_a;
	char c_b;
	c_a = MCR;
	c_b = KBIM;

	P0 = c_a + c_b;
	P1 = c_a - c_b;

	if (c_a > 0) P0 = c_b;
	
	if (c_a > -3) P0 = c_b;

	while(1);
}
