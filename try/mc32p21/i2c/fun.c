 #include <mc30p011.h> 

const  char  table[ ] = {	
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XF5,0XF2,0XEF,0XEC,0XE9,0XE5,0XE1,0XDD,
	0XD8,0XD4,0XCF,0XCA,0XC5,0XBF,0XBA,0XB4,
	0XAE,0XA8,0XA2,0X9C,0X96,0X90,0X89,0X83,
	0X80,0X79,0X72,0X6C,0X66,0X60,0X5A,0X55,
	0X4E,0X48,0X43,0X3D,0X38,0X33,0X2E,0X29,
	0X25,0X20,0X1C,0X18,0X15,0X11,0X0E,0X0B,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C,
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XF5,0XF2,0XEF,0XEC,0XE9,0XE5,0XE1,0XDD,
	0XD8,0XD4,0XCF,0XCA,0XC5,0XBF,0XBA,0XB4,
	0XAE,0XA8,0XA2,0X9C,0X96,0X90,0X89,0X83,
	0X80,0X79,0X72,0X6C,0X66,0X60,0X5A,0X55,
	0X4E,0X48,0X43,0X3D,0X38,0X33,0X2E,0X29,
	0X25,0X20,0X1C,0X18,0X15,0X11,0X0E,0X0B,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C,
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XF5,0XF2,0XEF,0XEC,0XE9,0XE5,0XE1,0XDD,
	0XD8,0XD4,0XCF,0XCA,0XC5,0XBF,0XBA,0XB4,
	0XAE,0XA8,0XA2,0X9C,0X96,0X90,0X89,0X83,
	0X80,0X79,0X72,0X6C,0X66,0X60,0X5A,0X55,
	0X4E,0X48,0X43,0X3D,0X38,0X33,0X2E,0X29,
	0X25,0X20,0X1C,0X18,0X15,0X11,0X0E,0X0B,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C,
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XF5,0XF2,0XEF,0XEC,0XE9,0XE5,0XE1,0XDD,
	0XD8,0XD4,0XCF,0XCA,0XC5,0XBF,0XBA,0XB4,
	0XAE,0XA8,0XA2,0X9C,0X96,0X90,0X89,0X83,
	0X80,0X79,0X72,0X6C,0X66,0X60,0X5A,0X55,
	0X4E,0X48,0X43,0X3D,0X38,0X33,0X2E,0X29,
	0X25,0X20,0X1C,0X18,0X15,0X11,0X0E,0X0B,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C,
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XF5,0XF2,0XEF,0XEC,0XE9,0XE5,0XE1,0XDD,
	0XD8,0XD4,0XCF,0XCA,0XC5,0XBF,0XBA,0XB4,
	0XAE,0XA8,0XA2,0X9C,0X96,0X90,0X89,0X83,
	0X80,0X79,0X72,0X6C,0X66,0X60,0X5A,0X55,
	0X4E,0X48,0X43,0X3D,0X38,0X33,0X2E,0X29,
	0X25,0X20,0X1C,0X18,0X15,0X11,0X0E,0X0B,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C,
	0X80,0X86,0X8D,0X93,0X99,0X9F,0XA5,0XAB,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0XF6,0XF8,0XFA,0XFC,0XFD,0XFF,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFD,0XFB,0XF9,0XF7,
	0XB1,0XB7,0XBC,0XC2,0XC7,0XCC,0XD1,0XD6,
	0XDA,0XDF,0XE3,0XE7,0XEA,0XEE,0XF1,0XF4,
	0X09,0X07,0X05,0X03,0X02,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0X02,0X04,0X06,0X08,
	0X0A,0X0D,0X10,0X13,0X16,0X1A,0X1E,0X22,
	0X27,0X2B,0X30,0X35,0X3A,0X40,0X45,0X4C,
	0X51,0X57,0X5D,0X63,0X69,0X6F,0X76,0X7C};

unsigned   char  i;
unsigned   char  j;
unsigned   char  n;

void  i2cint()
{
	DDR0 = 0X08;
	P00 = 1;
	P00 = 0;
}

void  i2cout()
{
	GIE = 1;
	for(n=0x02;--n;) continue;
	do 
	{
  		P00=1; 
 	}while(P01==0);  
	P00=0;
	P0=0x58;
	do
	{
  		;
	}while(P01==0);
	P01=0; 
	P0=0X01;
	do 
	{
		;
	}while(P01==0); 
	P01=0;  
	P02=j;   
	do 
	{
		;
	}while(P01==0);
	P01=0;   
	P00=1;    
	do 
	{
		;
 	}while(P01==0); 
	P01=0;    
}
