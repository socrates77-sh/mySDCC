#include <mc32p21.h>

void InitialRAM()
{
	__asm
		clrr FSR0
	InitialRAM0:
		clrr INDF0
		movai 0x7f
		rsubar FSR0
		jbset STATUS, 0
		goto InitialRAM0
	__endasm;
	T1IE = 1;
}

void main(void)
{
	unsigned char a, b, c;

	InitialRAM();

	IOP0 = 0x01;
	KBIM = OEP1 & 0x55;
	KBIM = OEP1 | 0x66;
	KBIM = OEP1 ^ 0x66;
	KBIE = 1;

	a = 1;
	b = 2;
	while(a==3)
	{
		a++;
		b = b + 2;
		c = a + b;
	}

}
