extern unsigned char i,j,n;
extern const char table[];
extern void i2cint();
extern void i2cout();


main ()
{
	i2cint();     
	while(1)
	{
		for(i=0x00;i<=127;++i)
		{ 
			j=table[i]; 
			i2cout(); 
		}
	}
}
