#include <mc32p64.h>

void main(void)
{
	OEP0 = 0xff;
	IOP0 = 0xff;
	while(1)
	{
		IOP0 = ~IOP0;
	}
}
