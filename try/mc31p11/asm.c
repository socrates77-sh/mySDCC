#include <mc30p011.h>

char c_a;
const char c_b = 100;

void main(void)
{
	c_a = MCR;
	//c_b = KBIM;

	P0 = c_a + c_b;
	P1 = c_a - c_b;

	__asm
		movai 100
		movra P1
	__endasm;

	__asm__("stop");

	Nop();
	ClrWdt();
	Stop();

	while(1);
}
