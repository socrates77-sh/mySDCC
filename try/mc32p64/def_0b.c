#include <mc30p011.h>

void main(void)
{
	char c_a;
	volatile char c_b;

	c_a = 0x80;
	c_b = 0b00001111;

	c_a = MCR;
	c_a = DDR1;

	c_b = MCR;
	c_b = DDR1;

	P0 = c_a + c_b;
	P1 = c_a - c_b;

	if (c_a > 0) P0 = c_b;
	
	if (c_a > -3) P0 = c_b;

	while(1);
}
