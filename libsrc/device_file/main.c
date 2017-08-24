#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reg_def.h"

#ifndef DEVICE_NAME
#define DEVICE_NAME "xxx"
#endif

FILE *hInc;
FILE *hH;
FILE *hC;

void inc_header()
{
	fprintf(hInc, "\t\tLIST\n");
	fprintf(hInc, ";%s.inc    Standard Header File, Version 1.00 by Sinomcu\n", DEVICE_NAME);
	fprintf(hInc, "\t\tNOLIST\n\n");
}

void inc_tail()
{
	fprintf(hInc, "\n\t\tLIST\n");
}

void verify_processor()
{
	char sTmp[16];
	strcpy(sTmp, DEVICE_NAME);
	sTmp[4] = 'P';

	fprintf(hInc, ";==========================================================================\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";\tVerify Processor\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";==========================================================================\n\n");
	fprintf(hInc, "\tIFNDEF __%s\n", &sTmp[2]);
	fprintf(hInc, "\t\tMESSG \"Processor-header file mismatch.  Verify selected processor.\"\n");
	fprintf(hInc, "\tENDIF\n\n");
}

void register_files()
{
	int i;

	fprintf(hInc, ";==========================================================================\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";\tRegister Definitions\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";==========================================================================\n\n");
	fprintf(hInc, ";----- Register Files ---------------------------------------------------\n\n");
	
	for(i=0; i < num_reg; i++)
	{
		fprintf(hInc, "%-10s\t\tEQU\t\tH'%04X'\n", all_reg[i].name, all_reg[i].address);
	}
}

void bit_define()
{
	int i, j;
	
	for(i = 0; i < num_reg; i++)
	{
		if(all_reg[i].bBit)
		{
			fprintf(hInc, "\n;----- %s Bits ---------------------------------------------------\n\n", all_reg[i].name);
			for(j = 0; j <8; j++)
			{
				if(all_reg[i].bit[j].n == 1)
					fprintf(hInc, "%-10s\t\tEQU\t\tH'%04X'\n", all_reg[i].bit[j].name, j);
			}
		}
	}
}

void ram_define()
{
	int i = 0;
	fprintf(hInc, "\n;==========================================================================\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";\tRAM Definition\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";==========================================================================\n\n");
	fprintf(hInc, "\t__MAXRAM H'%X'\n", maxram);

//	if (badram[0][0] != -1) fprintf(hInc, "\t__BADRAM ");

	while (badram[i][0] != -1)
	{
		if(badram[i][0] == badram[i][1])
			fprintf(hInc, "\t__BADRAM H'%X'\n", badram[i][1]);
		else
			fprintf(hInc, "\t__BADRAM H'%X'-H'%X'\n", badram[i][0], badram[i][1]);
		i++;
	}
	fprintf(hInc, "\n\n");
}

void config_bit()
{
	int i;
	fprintf(hInc, ";==========================================================================\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";\tConfiguration Bits\n");
	fprintf(hInc, ";\n");
	fprintf(hInc, ";==========================================================================\n\n");

	fprintf(hInc, "%-10s\t\tEQU\t\tH'%04X'\n", "_CONFIG1", config1_addr);
	fprintf(hInc, "%-10s\t\tEQU\t\tH'%04X'\n", "_CONFIG0", config0_addr);
	fprintf(hInc, "\n");

	fprintf(hInc, ";OPBIT1\n");
	for(i = 0; i < num_config1; i++)
	{
		fprintf(hInc, "%-16s\tEQU\t\tH'%04X'\n", config1[i].name, config1[i].n);
	}

	fprintf(hInc, "\n;OPBIT0\n");
	for(i = 0; i < num_config0; i++)
	{
		fprintf(hInc, "%-16s\tEQU\t\tH'%04X'\n", config0[i].name, config0[i].n);
	}
}

void inc_file()
{
	char sIncName[128];
	sprintf(sIncName, "%s.inc", DEVICE_NAME);

	hInc = fopen(sIncName, "w");
	if (hInc == NULL)
	{
		printf("Cannot open file %s!\n", sIncName);
		exit(1);
	}

	inc_header();
	verify_processor();
	register_files();
	bit_define();
	ram_define();
	config_bit();
	inc_tail();
}

void h_header()
{
	char sTmp[16];
	strcpy(sTmp, DEVICE_NAME);
	sTmp[0] = 'M';
	sTmp[1] = 'C';
	sTmp[4] = 'P';

	fprintf(hH, "#ifndef %s_H\n", sTmp);
	fprintf(hH, "#define %s_H\n\n", sTmp);
	fprintf(hH, "#include <mc3x-common.h>\n\n");
}

void h_reg_address()
{
	int i;
	char sTmp[16];

	fprintf(hH, "//\n");
	fprintf(hH, "// Register addresses.\n");
	fprintf(hH, "//\n");

	for(i = 0; i < num_reg; i++)
	{
		sprintf(sTmp, "%s_ADDR", all_reg[i].name);
		fprintf(hH, "#define %-16s\t0x%04X\n", sTmp, all_reg[i].address);
	}
}

void h_reg_file()
{
	int i;
	char sTmp[16];

	fprintf(hH, "\n//----- Register Files -----------------------------------------------------\n\n");

	for(i = 0; i < num_reg; i++)
	{
		sprintf(sTmp, "(%s_ADDR)", all_reg[i].name);
		fprintf(hH, "extern __sfr __at %-16s\t%s;\n", sTmp, all_reg[i].name);
	}
}

void h_config()
{
	int i;

	fprintf(hH, "\n//==========================================================================\n");
	fprintf(hH, "//\n");
	fprintf(hH, "//\tConfiguration Bits\n");
	fprintf(hH, "//\n");
	fprintf(hH, "//==========================================================================\n\n");

	fprintf(hH, "//OPBIT1\n");
	for(i = 0; i < num_config1; i++)
	{
		fprintf(hH, "#define %-16s\t0x%04X\n", config1[i].name, config1[i].n);
	}

	fprintf(hH, "\n//OPBIT0\n");
	for(i = 0; i < num_config0; i++)
	{
		fprintf(hH, "#define %-16s\t0x%04X\n", config0[i].name, config0[i].n);
	}
}

void h_bit_def()
{
	int i, j;
	char sTmp[32];
	
	for(i = 0; i < num_reg; i++)
	{
		if(all_reg[i].bBit)
		{
			fprintf(hH, "\n// ----- %s Bits --------------------------------------------\n", all_reg[i].name);
			fprintf(hH, "typedef union {\n");
			fprintf(hH, "\t struct {\n");

			for(j = 0; j <8; j++)
			{
				if(all_reg[i].bit[j].n >= 1)
					fprintf(hH, "\t\tunsigned char %s:%d;\n", all_reg[i].bit[j].name, all_reg[i].bit[j].n);
				else if(all_reg[i].bit[j].n == 0)
					fprintf(hH, "\t\tunsigned char :1;\n");
			}

			fprintf(hH, "\t};\n");
			fprintf(hH, "} __%sbits_t;\n", all_reg[i].name);
			fprintf(hH, "extern volatile __%sbits_t __at(%s_ADDR) %sbits;\n\n", all_reg[i].name, all_reg[i].name, all_reg[i].name);

			for(j = 0; j <8; j++)
			{
				if(all_reg[i].bit[j].n == 1)
				{
					sprintf(sTmp, "%sbits.%s", all_reg[i].name, all_reg[i].bit[j].name);
					fprintf(hH, "#define %-10s\t%-20s\t/* bit %d */\n", all_reg[i].bit[j].name, sTmp, j);
				}
				else if(all_reg[i].bit[j].n > 1)
				{
					sprintf(sTmp, "%sbits.%s", all_reg[i].name, all_reg[i].bit[j].name);
					fprintf(hH, "#define %-10s\t%-20s\t/* bit %d-%d */\n", all_reg[i].bit[j].name, sTmp, j+all_reg[i].bit[j].n-1, j);
				}
			}
		}
	}
}

void h_tail()
{
	fprintf(hH, "\n#endif\n");
}

void h_file()
{
	char sHName[128];
	sprintf(sHName, "%s.h", DEVICE_NAME);

	hH = fopen(sHName, "w");
	if (hH == NULL)
	{
		printf("Cannot open file %s!\n", sHName);
		exit(1);
	}

	h_header();
	h_reg_address();
	h_reg_file();
	h_config();
	h_bit_def();
	h_tail();
}

void c_file()
{
	int i;
	char sTmp[32];
	char sCName[128];
	sprintf(sCName, "%s.c", DEVICE_NAME);

	hC = fopen(sCName, "w");
	if (hC == NULL)
	{
		printf("Cannot open file %s!\n", sCName);
		exit(1);
	}
	
	fprintf(hC, "#include <%s.h>\n\n", DEVICE_NAME);

	for(i = 0; i < num_reg; i++)
	{
		sprintf(sTmp, "(%s_ADDR)", all_reg[i].name);
		fprintf(hC, "__sfr __at %-16s\t%s;\n", sTmp, all_reg[i].name);
	}

	fprintf(hC, "\n");
	for(i = 0; i < num_reg; i++)
	{
		if(all_reg[i].bBit == 1)
		{
			sprintf(sTmp, "%s", all_reg[i].name);
			fprintf(hC, "volatile __%sbits_t __at(%s_ADDR) %sbits;\n", sTmp, sTmp, sTmp);
		}
	}
}

int main()
{
	inc_file();
	h_file();
	c_file();

	return 1;
}
