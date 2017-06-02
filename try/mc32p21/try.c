#include <mc32p21.h>
//uchar a = 0x78;
void main(void)
{
	OEP0 = 0xff;
	IOP0 = 0xff;
	while(1)
	{
		IOP0 = ~IOP0;
	}
}
