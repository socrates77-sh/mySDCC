/*-------------------------------------------------------------------------

	pcode.c - post code generation
	Written By -  Scott Dattalo scott@dattalo.com

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2, or (at your option) any
	later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-------------------------------------------------------------------------*/

#include "device.h"
#include "gen.h"
#include "pcode.h"
#include "pcodeflow.h"
#include "ralloc.h"

/****************************************************************/
/****************************************************************/

// Eventually this will go into device dependent files:
// zwr 1.1.0
pCodeOpReg mc32_pc_status = {{PO_STATUS, "PFLAG"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_fsr = {{PO_FSR, "FSR"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_fsr0l = {{PO_FSR, "FSR0L"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_fsr0h = {{PO_FSR, "FSR0H"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_indf_ = {{PO_INDF, "INDF"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_indf0 = {{PO_INDF, "INDF0"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_intcon = {{PO_INTCON, "INTCON"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_pcl = {{PO_PCL, "PCL"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_pclath = {{PO_PCLATH, "PCLATH"}, -1, NULL, 0, NULL};

pCodeOpReg *mc32_pc_indf = &mc32_pc_indf_;

pCodeOpReg mc32_pc_wsave = {{PO_GPR_REGISTER, "WSAVE"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_ssave = {{PO_GPR_REGISTER, "SSAVE"}, -1, NULL, 0, NULL};
pCodeOpReg mc32_pc_psave = {{PO_GPR_REGISTER, "PSAVE"}, -1, NULL, 0, NULL};

pFile *mc32_the_pFile = NULL;

#define SET_BANK_BIT (1 << 16)
#define CLR_BANK_BIT 0

static peepCommand mc32_peepCommands[] = {

	{NOTBITSKIP, "_NOTBITSKIP_"},
	{BITSKIP, "_BITSKIP_"},
	{INVERTBITSKIP, "_INVERTBITSKIP_"},

	{-1, NULL}};

static int mc32_mnemonics_initialized = 0;

static hTab *mc32_pic14MnemonicsHash = NULL;
static hTab *mc32_pCodePeepCommandsHash = NULL;

static pBlock *mc32_pb_dead_pcodes = NULL;

/* Hardcoded flags to change the behavior of the PIC port */
static int mc32_functionInlining = 1; /* inline functions if nonzero */

// static int GpCodeSequenceNumber = 1;
static int mc32_GpcFlowSeq = 1;

/* statistics (code size estimation) */
static unsigned int mc32_pcode_insns = 0;
static unsigned int mc32_pcode_doubles = 0;

static unsigned mc32_peakIdx = 0; /* This keeps track of the peak register index for call tree register reuse */

/****************************************************************/
/*                      Forward declarations                    */
/****************************************************************/

static void mc32_genericDestruct(pCode *pc);
static void mc32_genericPrint(FILE *of, pCode *pc);

static void mc32_pBlockStats(FILE *of, pBlock *pb);
static pCode *mc32_findFunction(char *fname);
static void mc32_pCodePrintLabel(FILE *of, pCode *pc);
static void mc32_pCodePrintFunction(FILE *of, pCode *pc);
static void mc32_pCodeOpPrint(FILE *of, pCodeOp *pcop);
static char *mc32_get_op_from_instruction(pCodeInstruction *pcc);
static pBlock *mc32_newpBlock(void);

/****************************************************************/
/*                    PIC Instructions                          */
/****************************************************************/
// zwr 1.0.0
static pCodeInstruction mc32_pciADDWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ADDWF,
	"ADDRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER),					// inCond
	(PCC_REGISTER | PCC_C | PCC_DC | PCC_Z) // outCond
};

static pCodeInstruction mc32_pciADDFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ADDFW,
	"ADDAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER),			 // inCond
	(PCC_W | PCC_C | PCC_DC | PCC_Z) // outCond
};

static pCodeInstruction mc32_pciADDLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ADDLW,
	"ADDAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_W | PCC_LITERAL),			 // inCond
	(PCC_W | PCC_Z | PCC_C | PCC_DC) // outCond
};

static pCodeInstruction mc32_pciANDLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ANDLW,
	"ANDAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_W | PCC_LITERAL), // inCond
	(PCC_W | PCC_Z)		   // outCond
};

static pCodeInstruction mc32_pciANDWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ANDWF,
	"ANDRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_REGISTER | PCC_Z)  // outCond
};

static pCodeInstruction mc32_pciANDFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_ANDFW,
	"ANDAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_W | PCC_Z)			// outCond
};

static pCodeInstruction mc32_pciBCF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_BCF,
	"BCLR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	2,	// num ops
	1,
	1, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_BSF,
	(PCC_REGISTER | PCC_EXAMINE_PCOP), // inCond
	(PCC_REGISTER | PCC_EXAMINE_PCOP)  // outCond
};

static pCodeInstruction mc32_pciBSF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_BSF,
	"BSET",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	2,	// num ops
	1,
	1, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_BCF,
	(PCC_REGISTER | PCC_EXAMINE_PCOP), // inCond
	(PCC_REGISTER | PCC_EXAMINE_PCOP)  // outCond
};

static pCodeInstruction mc32_pciBTFSC = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_BTFSC,
	"JBCLR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	2,	// num ops
	0,
	1, // dest, bit instruction
	1,
	1, // branch, skip
	0, // literal operand
	POC_BTFSS,
	(PCC_REGISTER | PCC_EXAMINE_PCOP), // inCond
	PCC_NONE						   // outCond
};

static pCodeInstruction mc32_pciBTFSS = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_BTFSS,
	"JBSET",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	2,	// num ops
	0,
	1, // dest, bit instruction
	1,
	1, // branch, skip
	0, // literal operand
	POC_BTFSC,
	(PCC_REGISTER | PCC_EXAMINE_PCOP), // inCond
	PCC_NONE						   // outCond
};

static pCodeInstruction mc32_pciCALL = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_CALL,
	"CALL",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_NONE | PCC_W),							// inCond, reads argument from WREG
	(PCC_NONE | PCC_W | PCC_C | PCC_DC | PCC_Z) // outCond, flags are destroyed by called function
};


// zwr 1.1.0
static pCodeInstruction mc32_pciLCALL = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_CALL,
	"LCALL",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_NONE | PCC_W),							// inCond, reads argument from WREG
	(PCC_NONE | PCC_W | PCC_C | PCC_DC | PCC_Z) // outCond, flags are destroyed by called function
};

static pCodeInstruction mc32_pciCOMF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_COMF,
	"COMR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER,		 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciCOMFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_COMFW,
	"COMAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER, // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciCLRF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_CLRF,
	"CLRR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE,			 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciCLRW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_CLRW,
	"CLRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	0,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE,	 // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciCLRWDT = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_CLRWDT,
	"CLRWDT",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	0,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};

static pCodeInstruction mc32_pciDECF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_DECF,
	"DECR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER,		 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciDECFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_DECFW,
	"DECAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER, // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciDECFSZ = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_DECFSZ,
	"DJZR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	1,
	1,					 // branch, skip
	0,					 // literal operand
	POC_DECF,			 // followed by BTFSC STATUS, Z --> also kills STATUS
	PCC_REGISTER,		 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciDECFSZW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_DECFSZW,
	"DJZAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	1,			  // branch, skip
	0,			  // literal operand
	POC_DECFW,	// followed by BTFSC STATUS, Z --> also kills STATUS
	PCC_REGISTER, // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciGOTO = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_GOTO,
	"GOTO",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};


// zwr 1.1.0
static pCodeInstruction mc32_pciLGOTO = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_GOTO,
	"LGOTO",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};

static pCodeInstruction mc32_pciINCF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_INCF,
	"INCR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER,		 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciINCFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_INCFW,
	"INCAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER, // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciINCFSZ = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_INCFSZ,
	"JZR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	1,
	1,					 // branch, skip
	0,					 // literal operand
	POC_INCF,			 // followed by BTFSC STATUS, Z --> also kills STATUS
	PCC_REGISTER,		 // inCond
	PCC_REGISTER | PCC_Z // outCond
};

static pCodeInstruction mc32_pciINCFSZW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_INCFSZW,
	"JZAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	1,			  // branch, skip
	0,			  // literal operand
	POC_INCFW,	// followed by BTFSC STATUS, Z --> also kills STATUS
	PCC_REGISTER, // inCond
	PCC_W | PCC_Z // outCond
};

static pCodeInstruction mc32_pciIORWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_IORWF,
	"ORRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_REGISTER | PCC_Z)  // outCond
};

static pCodeInstruction mc32_pciIORFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_IORFW,
	"ORAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_W | PCC_Z)			// outCond
};

static pCodeInstruction mc32_pciIORLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_IORLW,
	"ORAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_W | PCC_LITERAL), // inCond
	(PCC_W | PCC_Z)		   // outCond
};

static pCodeInstruction mc32_pciMOVF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_MOVF,
	"MOVR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER, // inCond
	PCC_Z		  // outCond
};

static pCodeInstruction mc32_pciMOVFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_MOVFW,
	"MOVAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_REGISTER,   // inCond
	(PCC_W | PCC_Z) // outCond
};

static pCodeInstruction mc32_pciMOVWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_MOVWF,
	"MOVRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_W,		 // inCond
	PCC_REGISTER // outCond
};

static pCodeInstruction mc32_pciMOVLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_MOVLW,
	"MOVAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_NONE | PCC_LITERAL), // inCond
	PCC_W					  // outCond
};

static pCodeInstruction mc32_pciNOP = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_NOP,
	"NOP",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	0,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};

static pCodeInstruction mc32_pciRETFIE = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RETFIE,
	"RETIE",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	0,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE,							// inCond
	(PCC_NONE | PCC_C | PCC_DC | PCC_Z) // outCond (not true... affects the GIE bit too), STATUS bit are retored
};

static pCodeInstruction mc32_pciRETLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RETLW,
	"RETAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	PCC_LITERAL,					 // inCond
	(PCC_W | PCC_C | PCC_DC | PCC_Z) // outCond, STATUS bits are irrelevant after RETLW
};

static pCodeInstruction mc32_pciRETURN = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RETURN,
	"RETURN",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	0,	// num ops
	0,
	0, // dest, bit instruction
	1,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE | PCC_W,					// inCond, return value is possibly present in W
	(PCC_NONE | PCC_C | PCC_DC | PCC_Z) // outCond, STATUS bits are irrelevant after RETURN
};

static pCodeInstruction mc32_pciRLF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RLF,
	"RLR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_C | PCC_REGISTER), // inCond
	(PCC_REGISTER | PCC_C)  // outCond
};

static pCodeInstruction mc32_pciRLFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RLFW,
	"RLAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_C | PCC_REGISTER), // inCond
	(PCC_W | PCC_C)			// outCond
};

static pCodeInstruction mc32_pciRRF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RRF,
	"RRR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_C | PCC_REGISTER), // inCond
	(PCC_REGISTER | PCC_C)  // outCond
};

static pCodeInstruction mc32_pciRRFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_RRFW,
	"RRAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_C | PCC_REGISTER), // inCond
	(PCC_W | PCC_C)			// outCond
};

static pCodeInstruction mc32_pciSUBWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_SUBWF,
	"RSUBRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER),					// inCond
	(PCC_REGISTER | PCC_C | PCC_DC | PCC_Z) // outCond
};

static pCodeInstruction mc32_pciSUBFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_SUBFW,
	"RSUBAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER),			 // inCond
	(PCC_W | PCC_C | PCC_DC | PCC_Z) // outCond
};

static pCodeInstruction mc32_pciSUBLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_SUBLW,
	"ISUBAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_W | PCC_LITERAL),			 // inCond
	(PCC_W | PCC_Z | PCC_C | PCC_DC) // outCond
};

static pCodeInstruction mc32_pciSWAPF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_SWAPF,
	"SWAPR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_REGISTER), // inCond
	(PCC_REGISTER)  // outCond
};

static pCodeInstruction mc32_pciSWAPFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_SWAPFW,
	"SWAPAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_REGISTER), // inCond
	(PCC_W)			// outCond
};

static pCodeInstruction mc32_pciTRIS = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_TRIS,
	"TRIS",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE,	// inCond /* FIXME: what's TRIS doing? */
	PCC_REGISTER // outCond	/* FIXME: what's TRIS doing */
};

static pCodeInstruction mc32_pciXORWF = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_XORWF,
	"XORRA",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	1,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_REGISTER | PCC_Z)  // outCond
};

static pCodeInstruction mc32_pciXORFW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_XORFW,
	"XORAR",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	(PCC_W | PCC_REGISTER), // inCond
	(PCC_W | PCC_Z)			// outCond
};

static pCodeInstruction mc32_pciXORLW = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_XORLW,
	"XORAI",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	1, // literal operand
	POC_NOP,
	(PCC_W | PCC_LITERAL), // inCond
	(PCC_W | PCC_Z)		   // outCond
};

static pCodeInstruction mc32_pciBANKSEL = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_BANKSEL,
	"BANKSEL",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};

static pCodeInstruction mc32_pciPAGESEL = {
	{PC_OPCODE, NULL, NULL, 0, 0, NULL,
	 mc32_genericDestruct,
	 mc32_genericPrint},
	POC_PAGESEL,
	"PAGESEL",
	NULL, // from branch
	NULL, // to branch
	NULL, // label
	NULL, // operand
	NULL, // flow block
	NULL, // C source
	1,	// num ops
	0,
	0, // dest, bit instruction
	0,
	0, // branch, skip
	0, // literal operand
	POC_NOP,
	PCC_NONE, // inCond
	PCC_NONE  // outCond
};

pCodeInstruction *mc32_pic14Mnemonics[MAX_PIC14MNEMONICS];

/*-----------------------------------------------------------------*/
/* return a unique ID number to assist pCodes debuging             */
/*-----------------------------------------------------------------*/
static unsigned PCodeID(void)
{
	static unsigned int pcodeId = 1; /* unique ID number to be assigned to all pCodes */
	/*
	static unsigned int stop;
	if (pcodeId == 1448)
		stop++; // Place break point here
	*/
	return pcodeId++;
}

void mc32_pCodeInitRegisters(void)
{
	static int initialized = 0;
	int shareBankAddress, stkSize, haveShared;
	MC32_device *pic;

	if (initialized)
		return;
	initialized = 1;

	pic = mc32_init_pic(port->processor);
	haveShared = mc32_getSharedStack(NULL, &shareBankAddress, &stkSize);
	/* Set pseudo stack size to SHAREBANKSIZE - 3.
	 * On multi memory bank ICs this leaves room for WSAVE/SSAVE/PSAVE
	 * (used for interrupts) to fit into the shared portion of the
	 * memory bank. */
	stkSize = stkSize - 3;
	assert(stkSize >= 0);
	mc32_initStack(shareBankAddress, stkSize, haveShared);

	/* TODO: Read aliases for SFRs from regmap lines in device description. */
	// zwr 1.1.0
	mc32_pc_status.r = mc32_allocProcessorRegister(IDX_STATUS, "PFLAG", PO_STATUS, 0xf80);
	mc32_pc_pcl.r = mc32_allocProcessorRegister(IDX_PCL, "PCL", PO_PCL, 0xf80);
	mc32_pc_pclath.r = mc32_allocProcessorRegister(IDX_PCLATH, "PCLATH", PO_PCLATH, 0xf80);
	mc32_pc_indf_.r = mc32_allocProcessorRegister(IDX_INDF, "INDF", PO_INDF, 0xf80);
	mc32_pc_indf0.r = mc32_allocProcessorRegister(IDX_INDF0, "INDF0", PO_INDF, 0xf80);
	mc32_pc_fsr.r = mc32_allocProcessorRegister(IDX_FSR, "FSR", PO_FSR, 0xf80);
	mc32_pc_fsr0l.r = mc32_allocProcessorRegister(IDX_FSR0L, "FSR0L", PO_FSR, 0xf80);
	mc32_pc_fsr0h.r = mc32_allocProcessorRegister(IDX_FSR0H, "FSR0H", PO_FSR, 0xf80);
	mc32_pc_intcon.r = mc32_allocProcessorRegister(IDX_INTCON, "INTCON", PO_INTCON, 0xf80);

	mc32_pc_status.rIdx = IDX_STATUS;
	mc32_pc_fsr.rIdx = IDX_FSR;
	mc32_pc_fsr0l.rIdx = IDX_FSR0L;
	mc32_pc_fsr0h.rIdx = IDX_FSR0H;
	mc32_pc_indf_.rIdx = IDX_INDF;
	mc32_pc_indf0.rIdx = IDX_INDF0;
	mc32_pc_intcon.rIdx = IDX_INTCON;
	mc32_pc_pcl.rIdx = IDX_PCL;
	mc32_pc_pclath.rIdx = IDX_PCLATH;

	/* Interrupt storage for working register - must be same address in all banks ie section SHAREBANK. */
	mc32_pc_wsave.r = mc32_allocInternalRegister(IDX_WSAVE, mc32_pc_wsave.pcop.name, mc32_pc_wsave.pcop.type, pic ? pic->bankMask : 0xf80);
	/* Interrupt storage for status register. */
	mc32_pc_ssave.r = mc32_allocInternalRegister(IDX_SSAVE, mc32_pc_ssave.pcop.name, mc32_pc_ssave.pcop.type, (pic && haveShared) ? pic->bankMask : 0);
	/* Interrupt storage for pclath register. */
	mc32_pc_psave.r = mc32_allocInternalRegister(IDX_PSAVE, mc32_pc_psave.pcop.name, mc32_pc_psave.pcop.type, (pic && haveShared) ? pic->bankMask : 0);

	mc32_pc_wsave.rIdx = mc32_pc_wsave.r->rIdx;
	mc32_pc_ssave.rIdx = mc32_pc_ssave.r->rIdx;
	mc32_pc_psave.rIdx = mc32_pc_psave.r->rIdx;

	mc32_pc_wsave.r->isFixed = 1; /* Some PIC ICs do not have a sharebank - this register needs to be reserved across all banks. */
	mc32_pc_wsave.r->address = shareBankAddress - stkSize;
	mc32_pc_ssave.r->isFixed = 1; /* This register must be in the first bank. */
	mc32_pc_ssave.r->address = shareBankAddress - stkSize - 1;
	mc32_pc_psave.r->isFixed = 1; /* This register must be in the first bank. */
	mc32_pc_psave.r->address = shareBankAddress - stkSize - 2;

	/* probably should put this in a separate initialization routine */
	mc32_pb_dead_pcodes = mc32_newpBlock();
}

/*-----------------------------------------------------------------*/
/*  mnem2key - convert a pic mnemonic into a hash key              */
/*   (BTW - this spreads the mnemonics quite well)                 */
/*                                                                 */
/*-----------------------------------------------------------------*/

static int mnem2key(unsigned char const *mnem)
{
	int key = 0;

	if (!mnem)
		return 0;

	while (*mnem)
	{

		key += toupper(*mnem++) + 1;
	}

	return (key & 0x1f);
}

static void pic14initMnemonics(void)
{
	int i = 0;
	int key;
	//  char *str;
	pCodeInstruction *pci;

	if (mc32_mnemonics_initialized)
		return;

	//FIXME - probably should NULL out the array before making the assignments
	//since we check the array contents below this initialization.

	mc32_pic14Mnemonics[POC_ADDLW] = &mc32_pciADDLW;
	mc32_pic14Mnemonics[POC_ADDWF] = &mc32_pciADDWF;
	mc32_pic14Mnemonics[POC_ADDFW] = &mc32_pciADDFW;
	mc32_pic14Mnemonics[POC_ANDLW] = &mc32_pciANDLW;
	mc32_pic14Mnemonics[POC_ANDWF] = &mc32_pciANDWF;
	mc32_pic14Mnemonics[POC_ANDFW] = &mc32_pciANDFW;
	mc32_pic14Mnemonics[POC_BCF] = &mc32_pciBCF;
	mc32_pic14Mnemonics[POC_BSF] = &mc32_pciBSF;
	mc32_pic14Mnemonics[POC_BTFSC] = &mc32_pciBTFSC;
	mc32_pic14Mnemonics[POC_BTFSS] = &mc32_pciBTFSS;

	// zwr 1.1.0
	if (!mc32_long_call)
	{
		mc32_pic14Mnemonics[POC_CALL] = &mc32_pciCALL;
		mc32_pic14Mnemonics[POC_GOTO] = &mc32_pciGOTO;
	}
	else
	{
		mc32_pic14Mnemonics[POC_CALL] = &mc32_pciLCALL;
		mc32_pic14Mnemonics[POC_GOTO] = &mc32_pciLGOTO;
	}

	mc32_pic14Mnemonics[POC_COMF] = &mc32_pciCOMF;
	mc32_pic14Mnemonics[POC_COMFW] = &mc32_pciCOMFW;
	mc32_pic14Mnemonics[POC_CLRF] = &mc32_pciCLRF;
	mc32_pic14Mnemonics[POC_CLRW] = &mc32_pciCLRW;
	mc32_pic14Mnemonics[POC_CLRWDT] = &mc32_pciCLRWDT;
	mc32_pic14Mnemonics[POC_DECF] = &mc32_pciDECF;
	mc32_pic14Mnemonics[POC_DECFW] = &mc32_pciDECFW;
	mc32_pic14Mnemonics[POC_DECFSZ] = &mc32_pciDECFSZ;
	mc32_pic14Mnemonics[POC_DECFSZW] = &mc32_pciDECFSZW;
	
	mc32_pic14Mnemonics[POC_INCF] = &mc32_pciINCF;
	mc32_pic14Mnemonics[POC_INCFW] = &mc32_pciINCFW;
	mc32_pic14Mnemonics[POC_INCFSZ] = &mc32_pciINCFSZ;
	mc32_pic14Mnemonics[POC_INCFSZW] = &mc32_pciINCFSZW;
	mc32_pic14Mnemonics[POC_IORLW] = &mc32_pciIORLW;
	mc32_pic14Mnemonics[POC_IORWF] = &mc32_pciIORWF;
	mc32_pic14Mnemonics[POC_IORFW] = &mc32_pciIORFW;
	mc32_pic14Mnemonics[POC_MOVF] = &mc32_pciMOVF;
	mc32_pic14Mnemonics[POC_MOVFW] = &mc32_pciMOVFW;
	mc32_pic14Mnemonics[POC_MOVLW] = &mc32_pciMOVLW;
	mc32_pic14Mnemonics[POC_MOVWF] = &mc32_pciMOVWF;
	mc32_pic14Mnemonics[POC_NOP] = &mc32_pciNOP;
	mc32_pic14Mnemonics[POC_RETFIE] = &mc32_pciRETFIE;
	mc32_pic14Mnemonics[POC_RETLW] = &mc32_pciRETLW;
	mc32_pic14Mnemonics[POC_RETURN] = &mc32_pciRETURN;
	mc32_pic14Mnemonics[POC_RLF] = &mc32_pciRLF;
	mc32_pic14Mnemonics[POC_RLFW] = &mc32_pciRLFW;
	mc32_pic14Mnemonics[POC_RRF] = &mc32_pciRRF;
	mc32_pic14Mnemonics[POC_RRFW] = &mc32_pciRRFW;
	mc32_pic14Mnemonics[POC_SUBLW] = &mc32_pciSUBLW;
	mc32_pic14Mnemonics[POC_SUBWF] = &mc32_pciSUBWF;
	mc32_pic14Mnemonics[POC_SUBFW] = &mc32_pciSUBFW;
	mc32_pic14Mnemonics[POC_SWAPF] = &mc32_pciSWAPF;
	mc32_pic14Mnemonics[POC_SWAPFW] = &mc32_pciSWAPFW;
	mc32_pic14Mnemonics[POC_TRIS] = &mc32_pciTRIS;
	mc32_pic14Mnemonics[POC_XORLW] = &mc32_pciXORLW;
	mc32_pic14Mnemonics[POC_XORWF] = &mc32_pciXORWF;
	mc32_pic14Mnemonics[POC_XORFW] = &mc32_pciXORFW;
	mc32_pic14Mnemonics[POC_BANKSEL] = &mc32_pciBANKSEL;
	mc32_pic14Mnemonics[POC_PAGESEL] = &mc32_pciPAGESEL;

	for (i = 0; i < MAX_PIC14MNEMONICS; i++)
		if (mc32_pic14Mnemonics[i])
			hTabAddItem(&mc32_pic14MnemonicsHash, mnem2key((unsigned char *)mc32_pic14Mnemonics[i]->mnemonic), mc32_pic14Mnemonics[i]);
	pci = hTabFirstItem(mc32_pic14MnemonicsHash, &key);

	while (pci)
	{
		DFPRINTF((stderr, "element %d key %d, mnem %s\n", i++, key, pci->mnemonic));
		pci = hTabNextItem(mc32_pic14MnemonicsHash, &key);
	}

	mc32_mnemonics_initialized = 1;
}

int mc32_getpCode(char *mnem, unsigned dest)
{

	pCodeInstruction *pci;
	int key = mnem2key((unsigned char *)mnem);

	if (!mc32_mnemonics_initialized)
		pic14initMnemonics();

	pci = hTabFirstItemWK(mc32_pic14MnemonicsHash, key);

	while (pci)
	{

		if (STRCASECMP(pci->mnemonic, mnem) == 0)
		{
			if ((pci->num_ops <= 1) || (pci->isModReg == dest) || (pci->isBitInst))
				return (pci->op);
		}

		pci = hTabNextItemWK(mc32_pic14MnemonicsHash);
	}

	return -1;
}

/*-----------------------------------------------------------------*
* mc32_initpCodePeepCommands
*
*-----------------------------------------------------------------*/
void mc32_initpCodePeepCommands(void)
{

	int key, i;
	peepCommand *pcmd;

	i = 0;
	do
	{
		hTabAddItem(&mc32_pCodePeepCommandsHash,
					mnem2key((unsigned char *)mc32_peepCommands[i].cmd), &mc32_peepCommands[i]);
		i++;
	} while (mc32_peepCommands[i].cmd);

	pcmd = hTabFirstItem(mc32_pCodePeepCommandsHash, &key);

	while (pcmd)
	{
		//fprintf(stderr, "peep command %s  key %d\n",pcmd->cmd,pcmd->id);
		pcmd = hTabNextItem(mc32_pCodePeepCommandsHash, &key);
	}
}

/*-----------------------------------------------------------------
*
*
*-----------------------------------------------------------------*/

int mc32_getpCodePeepCommand(char *cmd)
{

	peepCommand *pcmd;
	int key = mnem2key((unsigned char *)cmd);

	pcmd = hTabFirstItemWK(mc32_pCodePeepCommandsHash, key);

	while (pcmd)
	{
		// fprintf(stderr," comparing %s to %s\n",pcmd->cmd,cmd);
		if (STRCASECMP(pcmd->cmd, cmd) == 0)
		{
			return pcmd->id;
		}

		pcmd = hTabNextItemWK(mc32_pCodePeepCommandsHash);
	}

	return -1;
}

static char mc32_getpBlock_dbName(pBlock *pb)
{
	if (!pb)
		return 0;

	if (pb->cmemmap)
		return pb->cmemmap->dbName;

	return pb->dbName;
}

void mc32_pBlockConvert2ISR(pBlock *pb)
{
	if (!pb)
		return;

	if (pb->cmemmap)
		pb->cmemmap = NULL;

	pb->dbName = 'I';
}

/*-----------------------------------------------------------------*/
/* mc32_movepBlock2Head - given the dbname of a pBlock, move all        */
/*                   instances to the front of the doubly linked   */
/*                   list of pBlocks                               */
/*-----------------------------------------------------------------*/

void mc32_movepBlock2Head(char dbName)
{
	pBlock *pb;

	if (!mc32_the_pFile)
		return;

	pb = mc32_the_pFile->pbHead;

	while (pb)
	{

		if (mc32_getpBlock_dbName(pb) == dbName)
		{
			pBlock *pbn = pb->next;
			pb->next = mc32_the_pFile->pbHead;
			mc32_the_pFile->pbHead->prev = pb;
			mc32_the_pFile->pbHead = pb;

			if (pb->prev)
				pb->prev->next = pbn;

			// If the pBlock that we just moved was the last
			// one in the link of all of the pBlocks, then we
			// need to point the tail to the block just before
			// the one we moved.
			// Note: if pb->next is NULL, then pb must have
			// been the last pBlock in the chain.

			if (pbn)
				pbn->prev = pb->prev;
			else
				mc32_the_pFile->pbTail = pb->prev;

			pb = pbn;
		}
		else
			pb = pb->next;
	}
}

void mc32_copypCode(FILE *of, char dbName)
{
	pBlock *pb;

	if (!of || !mc32_the_pFile)
		return;

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	{
		if (mc32_getpBlock_dbName(pb) == dbName)
		{
			mc32_pBlockStats(of, pb);
			mc32_printpBlock(of, pb);
			fprintf(of, "\n");
		}
	}
}

void mc32_resetpCodeStatistics(void)
{
	mc32_pcode_insns = mc32_pcode_doubles = 0;
}

void mc32_dumppCodeStatistics(FILE *of)
{
	/* dump statistics */
	fprintf(of, "\n");
	fprintf(of, ";\tcode size estimation:\n");
	fprintf(of, ";\t%5u+%5u = %5u instructions (%5u byte)\n", mc32_pcode_insns, mc32_pcode_doubles, mc32_pcode_insns + mc32_pcode_doubles, 2 * (mc32_pcode_insns + 2 * mc32_pcode_doubles));
	fprintf(of, "\n");
}

void mc32_pcode_test(void)
{

	DFPRINTF((stderr, "pcode is alive!\n"));

	//initMnemonics();

	if (mc32_the_pFile)
	{

		pBlock *pb;
		FILE *pFile;
		char buffer[100];

		/* create the file name */
		strcpy(buffer, dstFileName);
		strcat(buffer, ".p");

		if (!(pFile = fopen(buffer, "w")))
		{
			werror(E_FILE_OPEN_ERR, buffer);
			exit(1);
		}

		fprintf(pFile, "pcode dump\n\n");

		for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		{
			fprintf(pFile, "\n\tNew pBlock\n\n");
			if (pb->cmemmap)
				fprintf(pFile, "%s", pb->cmemmap->sname);
			else
				fprintf(pFile, "internal pblock");

			fprintf(pFile, ", dbName =%c\n", mc32_getpBlock_dbName(pb));
			mc32_printpBlock(pFile, pb);
		}
	}
}

/*-----------------------------------------------------------------*/
/* int mc32_RegCond(pCodeOp *pcop) - if pcop points to the STATUS reg-  */
/*      ister, mc32_RegCond will return the bit being referenced.       */
/*                                                                 */
/* fixme - why not just OR in the pcop bit field                   */
/*-----------------------------------------------------------------*/

static int mc32_RegCond(pCodeOp *pcop)
{

	if (!pcop)
		return 0;

	if (pcop->type == PO_GPR_BIT)
	{
		char *name = pcop->name;
		if (!name)
			name = PCOR(pcop)->r->name;
		if (strcmp(name, mc32_pc_status.pcop.name) == 0)
		{
			switch (PCORB(pcop)->bit)
			{
			case PIC_C_BIT:
				return PCC_C;
			case PIC_DC_BIT:
				return PCC_DC;
			case PIC_Z_BIT:
				return PCC_Z;
			}
		}
	}

	return 0;
}

/*-----------------------------------------------------------------*/
/* mc32_newpCode - create and return a newly initialized pCode          */
/*                                                                 */
/*  fixme - rename this                                            */
/*                                                                 */
/* The purpose of this routine is to create a new Instruction      */
/* pCode. This is called by gen.c while the assembly code is being */
/* generated.                                                      */
/*                                                                 */
/* Inouts:                                                         */
/*  PIC_OPCODE op - the assembly instruction we wish to create.    */
/*                  (note that the op is analogous to but not the  */
/*                  same thing as the opcode of the instruction.)  */
/*  pCdoeOp *pcop - pointer to the operand of the instruction.     */
/*                                                                 */
/* Outputs:                                                        */
/*  a pointer to the new malloc'd pCode is returned.               */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/
pCode *mc32_newpCode(PIC_OPCODE op, pCodeOp *pcop)
{
	pCodeInstruction *pci;

	if (!mc32_mnemonics_initialized)
		pic14initMnemonics();

	pci = Safe_calloc(1, sizeof(pCodeInstruction));

	if ((op >= 0) && (op < MAX_PIC14MNEMONICS) && mc32_pic14Mnemonics[op])
	{
		memcpy(pci, mc32_pic14Mnemonics[op], sizeof(pCodeInstruction));
		pci->pc.id = PCodeID();
		pci->pcop = pcop;

		if (pci->inCond & PCC_EXAMINE_PCOP)
			pci->inCond |= mc32_RegCond(pcop);

		if (pci->outCond & PCC_EXAMINE_PCOP)
			pci->outCond |= mc32_RegCond(pcop);

		pci->pc.prev = pci->pc.next = NULL;
		return (pCode *)pci;
	}

	fprintf(stderr, "pCode mnemonic error %s,%d\n", __FUNCTION__, __LINE__);
	exit(1);

	return NULL;
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeWild - create a "wild" as in wild card pCode            */
/*                                                                 */
/* Wild pcodes are used during the peep hole optimizer to serve    */
/* as place holders for any instruction. When a snippet of code is */
/* compared to a peep hole rule, the wild card opcode will match   */
/* any instruction. However, the optional operand and label are    */
/* additional qualifiers that must also be matched before the      */
/* line (of assembly code) is declared matched. Note that the      */
/* operand may be wild too.                                        */
/*                                                                 */
/*   Note, a wild instruction is specified just like a wild var:   */
/*      %4     ; A wild instruction,                               */
/*  See the peeph.def file for additional examples                 */
/*                                                                 */
/*-----------------------------------------------------------------*/

pCode *mc32_newpCodeWild(int pCodeID, pCodeOp *optional_operand, pCodeOp *optional_label)
{

	pCodeWild *pcw;

	pcw = Safe_calloc(1, sizeof(pCodeWild));

	pcw->pci.pc.type = PC_WILD;
	pcw->pci.pc.prev = pcw->pci.pc.next = NULL;
	pcw->id = PCodeID();
	pcw->pci.from = pcw->pci.to = pcw->pci.label = NULL;
	pcw->pci.pc.pb = NULL;

	pcw->pci.pc.destruct = mc32_genericDestruct;
	pcw->pci.pc.print = mc32_genericPrint;

	pcw->id = pCodeID; // this is the 'n' in %n
	pcw->operand = optional_operand;
	pcw->label = optional_label;

	pcw->mustBeBitSkipInst = 0;
	pcw->mustNotBeBitSkipInst = 0;
	pcw->invertBitSkipInst = 0;

	return ((pCode *)pcw);
}

/*-----------------------------------------------------------------*/
/* newPcodeCharP - create a new pCode from a char string           */
/*-----------------------------------------------------------------*/

pCode *mc32_newpCodeCharP(char *cP)
{

	pCodeComment *pcc;

	pcc = Safe_calloc(1, sizeof(pCodeComment));

	pcc->pc.type = PC_COMMENT;
	pcc->pc.prev = pcc->pc.next = NULL;
	pcc->pc.id = PCodeID();
	//pcc->pc.from = pcc->pc.to = pcc->pc.label = NULL;
	pcc->pc.pb = NULL;

	pcc->pc.destruct = mc32_genericDestruct;
	pcc->pc.print = mc32_genericPrint;

	if (cP)
		pcc->comment = Safe_strdup(cP);
	else
		pcc->comment = NULL;

	return ((pCode *)pcc);
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeFunction -                                              */
/*-----------------------------------------------------------------*/

pCode *mc32_newpCodeFunction(char *mod, char *f, int isPublic)
{
	pCodeFunction *pcf;

	pcf = Safe_calloc(1, sizeof(pCodeFunction));
	//_ALLOC(pcf,sizeof(pCodeFunction));

	pcf->pc.type = PC_FUNCTION;
	pcf->pc.prev = pcf->pc.next = NULL;
	pcf->pc.id = PCodeID();
	//pcf->pc.from = pcf->pc.to = pcf->pc.label = NULL;
	pcf->pc.pb = NULL;

	pcf->pc.destruct = mc32_genericDestruct;
	pcf->pc.print = mc32_pCodePrintFunction;

	pcf->ncalled = 0;

	if (mod)
	{
		//_ALLOC_ATOMIC(pcf->modname,strlen(mod)+1);
		pcf->modname = Safe_calloc(1, strlen(mod) + 1);
		strcpy(pcf->modname, mod);
	}
	else
		pcf->modname = NULL;

	if (f)
	{
		//_ALLOC_ATOMIC(pcf->fname,strlen(f)+1);
		pcf->fname = Safe_calloc(1, strlen(f) + 1);
		strcpy(pcf->fname, f);
	}
	else
		pcf->fname = NULL;

	pcf->isPublic = (unsigned)isPublic;

	return ((pCode *)pcf);
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeFlow                                                    */
/*-----------------------------------------------------------------*/
static void mc32_destructpCodeFlow(pCode *pc)
{
	if (!pc || !isPCFL(pc))
		return;

	/*
		if(PCFL(pc)->from)
		if(PCFL(pc)->to)
	*/
	mc32_unlinkpCode(pc);

	deleteSet(&PCFL(pc)->registers);
	deleteSet(&PCFL(pc)->from);
	deleteSet(&PCFL(pc)->to);
	free(pc);
}

static pCode *mc32_newpCodeFlow(void)
{
	pCodeFlow *pcflow;

	//_ALLOC(pcflow,sizeof(pCodeFlow));
	pcflow = Safe_calloc(1, sizeof(pCodeFlow));

	pcflow->pc.type = PC_FLOW;
	pcflow->pc.prev = pcflow->pc.next = NULL;
	pcflow->pc.pb = NULL;

	pcflow->pc.destruct = mc32_destructpCodeFlow;
	pcflow->pc.print = mc32_genericPrint;

	pcflow->pc.seq = mc32_GpcFlowSeq++;

	pcflow->from = pcflow->to = NULL;

	pcflow->inCond = PCC_NONE;
	pcflow->outCond = PCC_NONE;

	pcflow->firstBank = 'U'; /* Undetermined */
	pcflow->lastBank = 'U';  /* Undetermined */

	pcflow->FromConflicts = 0;
	pcflow->ToConflicts = 0;

	pcflow->end = NULL;

	pcflow->registers = newSet();

	return ((pCode *)pcflow);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static pCodeFlowLink *mc32_newpCodeFlowLink(pCodeFlow *pcflow)
{
	pCodeFlowLink *pcflowLink;

	pcflowLink = Safe_calloc(1, sizeof(pCodeFlowLink));

	pcflowLink->pcflow = pcflow;
	pcflowLink->bank_conflict = 0;

	return pcflowLink;
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeCSource - create a new pCode Source Symbol              */
/*-----------------------------------------------------------------*/

pCode *mc32_newpCodeCSource(int ln, char *f, const char *l)
{

	pCodeCSource *pccs;

	pccs = Safe_calloc(1, sizeof(pCodeCSource));

	pccs->pc.type = PC_CSOURCE;
	pccs->pc.prev = pccs->pc.next = NULL;
	pccs->pc.id = PCodeID();
	pccs->pc.pb = NULL;

	pccs->pc.destruct = mc32_genericDestruct;
	pccs->pc.print = mc32_genericPrint;

	pccs->line_number = ln;
	if (l)
		pccs->line = Safe_strdup(l);
	else
		pccs->line = NULL;

	if (f)
		pccs->file_name = Safe_strdup(f);
	else
		pccs->file_name = NULL;

	return ((pCode *)pccs);
}

/*******************************************************************/
/* pic16_newpCodeAsmDir - create a new pCode Assembler Directive   */
/*                        added by VR 6-Jun-2003                   */
/*******************************************************************/

pCode *mc32_newpCodeAsmDir(char *asdir, char *argfmt, ...)
{
	pCodeAsmDir *pcad;
	va_list ap;
	char buffer[512];
	char *lbp = buffer;

	pcad = Safe_calloc(1, sizeof(pCodeAsmDir));
	pcad->pci.pc.type = PC_ASMDIR;
	pcad->pci.pc.prev = pcad->pci.pc.next = NULL;
	pcad->pci.pc.pb = NULL;
	pcad->pci.pc.destruct = mc32_genericDestruct;
	pcad->pci.pc.print = mc32_genericPrint;

	if (asdir && *asdir)
	{

		while (isspace((unsigned char)*asdir))
			asdir++; // strip any white space from the beginning

		pcad->directive = Safe_strdup(asdir);
	}

	va_start(ap, argfmt);

	memset(buffer, 0, sizeof(buffer));
	if (argfmt && *argfmt)
		vsprintf(buffer, argfmt, ap);

	va_end(ap);

	while (isspace((unsigned char)*lbp))
		lbp++;

	if (lbp && *lbp)
		pcad->arg = Safe_strdup(lbp);

	return ((pCode *)pcad);
}

/*-----------------------------------------------------------------*/
/* mc32_pCodeLabelDestruct - free memory used by a label.               */
/*-----------------------------------------------------------------*/
static void mc32_pCodeLabelDestruct(pCode *pc)
{

	if (!pc)
		return;

	if ((pc->type == PC_LABEL) && PCL(pc)->label)
		free(PCL(pc)->label);

	free(pc);
}

pCode *mc32_newpCodeLabel(char *name, int key)
{

	char *s = buffer;
	pCodeLabel *pcl;

	pcl = Safe_calloc(1, sizeof(pCodeLabel));

	pcl->pc.type = PC_LABEL;
	pcl->pc.prev = pcl->pc.next = NULL;
	pcl->pc.id = PCodeID();
	//pcl->pc.from = pcl->pc.to = pcl->pc.label = NULL;
	pcl->pc.pb = NULL;

	pcl->pc.destruct = mc32_pCodeLabelDestruct;
	pcl->pc.print = mc32_pCodePrintLabel;

	pcl->key = key;

	pcl->label = NULL;
	if (key > 0)
	{
		sprintf(s, "_%05d_DS_", key);
	}
	else
		s = name;

	if (s)
		pcl->label = Safe_strdup(s);

	//fprintf(stderr,"mc32_newpCodeLabel: key=%d, name=%s\n",key, ((s)?s:""));
	return ((pCode *)pcl);
}

/*-----------------------------------------------------------------*/
/* mc32_newpBlock - create and return a pointer to a new pBlock         */
/*-----------------------------------------------------------------*/
static pBlock *mc32_newpBlock(void)
{

	pBlock *PpB;

	PpB = Safe_calloc(1, sizeof(pBlock));
	PpB->next = PpB->prev = NULL;

	PpB->function_entries = PpB->function_exits = PpB->function_calls = NULL;
	PpB->tregisters = NULL;
	PpB->visited = 0;
	PpB->FlowTree = NULL;

	return PpB;
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeChain - create a new chain of pCodes                    */
/*-----------------------------------------------------------------*
*
*  This function will create a new pBlock and the pointer to the
*  pCode that is passed in will be the first pCode in the block.
*-----------------------------------------------------------------*/

pBlock *mc32_newpCodeChain(memmap *cm, char c, pCode *pc)
{

	pBlock *pB = mc32_newpBlock();

	pB->pcHead = pB->pcTail = pc;
	pB->cmemmap = cm;
	pB->dbName = c;

	return pB;
}

/*-----------------------------------------------------------------*/
/* mc32_newpCodeOpLabel - Create a new label given the key              */
/*  Note, a negative key means that the label is part of wild card */
/*  (and hence a wild card label) used in the pCodePeep            */
/*   optimizations).                                               */
/*-----------------------------------------------------------------*/

pCodeOp *mc32_newpCodeOpLabel(char *name, int key)
{
	char *s = NULL;
	static int label_key = -1;

	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpLabel));
	pcop->type = PO_LABEL;

	pcop->name = NULL;

	if (key > 0)
		sprintf(s = buffer, "_%05d_DS_", key);
	else
		s = name, key = label_key--;

	PCOLAB(pcop)->offset = 0;
	if (s)
		pcop->name = Safe_strdup(s);

	((pCodeOpLabel *)pcop)->key = key;

	//fprintf(stderr,"mc32_newpCodeOpLabel: key=%d, name=%s\n",key,((s)?s:""));
	return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
pCodeOp *mc32_newpCodeOpLit(int lit)
{
	char *s = buffer;
	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpLit));
	pcop->type = PO_LITERAL;

	pcop->name = NULL;
	if (lit >= 0)
	{
		sprintf(s, "0x%02x", (unsigned char)lit);
		if (s)
			pcop->name = Safe_strdup(s);
	}

	((pCodeOpLit *)pcop)->lit = (unsigned char)lit;

	return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
pCodeOp *mc32_newpCodeOpImmd(char *name, int offset, int index, int code_space, int is_func)
{
	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpImmd));
	pcop->type = PO_IMMEDIATE;
	if (name)
	{
		reg_info *r = NULL;
		pcop->name = Safe_strdup(name);

		if (!is_func)
			r = mc32_dirregWithName(name);

		PCOI(pcop)->r = r;
		if (r)
		{
			//fprintf(stderr, " mc32_newpCodeOpImmd reg %s exists\n",name);
			PCOI(pcop)->rIdx = r->rIdx;
		}
		else
		{
			//fprintf(stderr, " mc32_newpCodeOpImmd reg %s doesn't exist\n",name);
			PCOI(pcop)->rIdx = -1;
		}
		//fprintf(stderr,"%s %s %d\n",__FUNCTION__,name,offset);
	}
	else
	{
		pcop->name = NULL;
	}

	PCOI(pcop)->index = index;
	PCOI(pcop)->offset = offset;
	PCOI(pcop)->_const = code_space;
	PCOI(pcop)->_function = is_func;

	return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
pCodeOp *mc32_newpCodeOpWild(int id, pCodeWildBlock *pcwb, pCodeOp *subtype)
{
	char *s = buffer;
	pCodeOp *pcop;

	if (!pcwb || !subtype)
	{
		fprintf(stderr, "Wild opcode declaration error: %s-%d\n", __FILE__, __LINE__);
		exit(1);
	}

	pcop = Safe_calloc(1, sizeof(pCodeOpWild));
	pcop->type = PO_WILD;
	sprintf(s, "%%%d", id);
	pcop->name = Safe_strdup(s);

	PCOW(pcop)->id = id;
	PCOW(pcop)->pcwb = pcwb;
	PCOW(pcop)->subtype = subtype;
	PCOW(pcop)->matched = NULL;

	return pcop;
}
/*-----------------------------------------------------------------*/
/* Find a symbol with matching name                                */
/*-----------------------------------------------------------------*/
static symbol *mc32_symFindWithName(memmap *map, const char *name)
{
	symbol *sym;

	for (sym = setFirstItem(map->syms); sym; sym = setNextItem(map->syms))
	{
		if (sym->rname && (strcmp(sym->rname, name) == 0))
			return sym;
	}
	return 0;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
pCodeOp *mc32_newpCodeOpBit(char *name, int ibit, int inBitSpace)
{
	pCodeOp *pcop;
	struct reg_info *r = 0;

	pcop = Safe_calloc(1, sizeof(pCodeOpRegBit));
	pcop->type = PO_GPR_BIT;

	PCORB(pcop)->bit = ibit;
	PCORB(pcop)->inBitSpace = inBitSpace;

	if (name)
		r = mc32_regFindWithName(name);
	if (name && !r)
	{
		// Register has not been allocated - check for symbol information
		symbol *sym;
		sym = mc32_symFindWithName(bit, name);
		if (!sym)
			sym = mc32_symFindWithName(sfrbit, name);
		if (!sym)
			sym = mc32_symFindWithName(sfr, name);
		if (!sym)
			sym = mc32_symFindWithName(reg, name);
		// Hack to fix accesses to _INTCON_bits (e.g. GIE=0), see #1579535.
		// XXX: This ignores nesting levels, but works for globals...
		if (!sym)
			sym = findSym(SymbolTab, NULL, name);
		if (!sym && name && name[0] == '_')
			sym = findSym(SymbolTab, NULL, &name[1]);
		if (sym)
		{
			r = mc32_allocNewDirReg(sym->etype, name);
		}
	}
	if (r)
	{
		pcop->name = NULL;
		PCOR(pcop)->r = r;
		PCOR(pcop)->rIdx = r->rIdx;
	}
	else if (name)
	{
		pcop->name = Safe_strdup(name);
		PCOR(pcop)->r = NULL;
		PCOR(pcop)->rIdx = 0;
	}
	else
	{
		//fprintf(stderr, "Unnamed register duplicated for bit-access?!? Hope for the best ...\n");
	}
	return pcop;
}

/*-----------------------------------------------------------------*
* pCodeOp *mc32_newpCodeOpReg(int rIdx) - allocate a new register
*
* If rIdx >=0 then a specific register from the set of registers
* will be selected. If rIdx <0, then a new register will be searched
* for.
*-----------------------------------------------------------------*/

static pCodeOp *mc32_newpCodeOpReg(int rIdx)
{
	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpReg));

	pcop->name = NULL;

	if (rIdx >= 0)
	{
		PCOR(pcop)->rIdx = rIdx;
		PCOR(pcop)->r = mc32_pic14_regWithIdx(rIdx);
	}
	else
	{
		PCOR(pcop)->r = mc32_findFreeReg(REG_GPR);

		if (PCOR(pcop)->r)
			PCOR(pcop)->rIdx = PCOR(pcop)->r->rIdx;
	}

	if (PCOR(pcop)->r)
		pcop->type = PCOR(pcop)->r->pc_type;

	return pcop;
}

pCodeOp *mc32_newpCodeOpRegFromStr(char *name)
{
	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpReg));
	PCOR(pcop)->r = mc32_allocRegByName(name, 1);
	PCOR(pcop)->rIdx = PCOR(pcop)->r->rIdx;
	pcop->type = PCOR(pcop)->r->pc_type;
	pcop->name = PCOR(pcop)->r->name;

	return pcop;
}

static pCodeOp *mc32_newpCodeOpStr(char *name)
{
	pCodeOp *pcop;

	pcop = Safe_calloc(1, sizeof(pCodeOpStr));
	pcop->type = PO_STR;
	pcop->name = Safe_strdup(name);

	PCOS(pcop)->isPublic = 0;

	return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

pCodeOp *mc32_newpCodeOp(char *name, PIC_OPTYPE type)
{
	pCodeOp *pcop;

	switch (type)
	{
	case PO_BIT:
	case PO_GPR_BIT:
		pcop = mc32_newpCodeOpBit(name, -1, 0);
		break;

	case PO_LITERAL:
		pcop = mc32_newpCodeOpLit(-1);
		break;

	case PO_LABEL:
		pcop = mc32_newpCodeOpLabel(NULL, -1);
		break;

	case PO_GPR_TEMP:
		pcop = mc32_newpCodeOpReg(-1);
		break;

	case PO_GPR_POINTER:
	case PO_GPR_REGISTER:
		if (name)
			pcop = mc32_newpCodeOpRegFromStr(name);
		else
			pcop = mc32_newpCodeOpReg(-1);
		break;

	case PO_STR:
		pcop = mc32_newpCodeOpStr(name);
		break;

	default:
		pcop = Safe_calloc(1, sizeof(pCodeOp));
		pcop->type = type;
		if (name)
			pcop->name = Safe_strdup(name);
		else
			pcop->name = NULL;
	}

	return pcop;
}

/*-----------------------------------------------------------------*/
/* mc32_addpCode2pBlock - place the pCode into the pBlock linked list   */
/*-----------------------------------------------------------------*/
void mc32_addpCode2pBlock(pBlock *pb, pCode *pc)
{

	if (!pb || !pc)
		return;

	if (!pb->pcHead)
	{
		/* If this is the first pcode to be added to a block that
	* was initialized with a NULL pcode, then go ahead and
		* make this pcode the head and tail */
		pb->pcHead = pb->pcTail = pc;
	}
	else
	{
		//    if(pb->pcTail)
		pb->pcTail->next = pc;

		pc->prev = pb->pcTail;
		pc->pb = pb;

		pb->pcTail = pc;
	}
}

/*-----------------------------------------------------------------*/
/* mc32_addpBlock - place a pBlock into the pFile                       */
/*-----------------------------------------------------------------*/
void mc32_addpBlock(pBlock *pb)
{
	// fprintf(stderr," Adding pBlock: dbName =%c\n",mc32_getpBlock_dbName(pb));

	if (!mc32_the_pFile)
	{
		/* First time called, we'll pass through here. */
		//_ALLOC(mc32_the_pFile,sizeof(pFile));
		mc32_the_pFile = Safe_calloc(1, sizeof(pFile));
		mc32_the_pFile->pbHead = mc32_the_pFile->pbTail = pb;
		mc32_the_pFile->functions = NULL;
		return;
	}

	mc32_the_pFile->pbTail->next = pb;
	pb->prev = mc32_the_pFile->pbTail;
	pb->next = NULL;
	mc32_the_pFile->pbTail = pb;
}

/*-----------------------------------------------------------------*/
/* mc32_removepBlock - remove a pBlock from the pFile                   */
/*-----------------------------------------------------------------*/
static void mc32_removepBlock(pBlock *pb)
{
	pBlock *pbs;

	if (!mc32_the_pFile)
		return;

	//fprintf(stderr," Removing pBlock: dbName =%c\n",mc32_getpBlock_dbName(pb));

	for (pbs = mc32_the_pFile->pbHead; pbs; pbs = pbs->next)
	{
		if (pbs == pb)
		{

			if (pbs == mc32_the_pFile->pbHead)
				mc32_the_pFile->pbHead = pbs->next;

			if (pbs == mc32_the_pFile->pbTail)
				mc32_the_pFile->pbTail = pbs->prev;

			if (pbs->next)
				pbs->next->prev = pbs->prev;

			if (pbs->prev)
				pbs->prev->next = pbs->next;

			return;
		}
	}

	fprintf(stderr, "Warning: call to %s:%s didn't find pBlock\n", __FILE__, __FUNCTION__);
}

/*-----------------------------------------------------------------*/
/* mc32_printpCode - write the contents of a pCode to a file            */
/*-----------------------------------------------------------------*/
void mc32_printpCode(FILE *of, pCode *pc)
{

	if (!pc || !of)
		return;

	if (pc->print)
	{
		pc->print(of, pc);
		return;
	}

	fprintf(of, "warning - unable to print pCode\n");
}

/*-----------------------------------------------------------------*/
/* mc32_printpBlock - write the contents of a pBlock to a file          */
/*-----------------------------------------------------------------*/
void mc32_printpBlock(FILE *of, pBlock *pb)
{
	pCode *pc;

	if (!pb)
		return;

	if (!of)
		of = stderr;

	for (pc = pb->pcHead; pc; pc = pc->next)
	{
		mc32_printpCode(of, pc);

		if (isPCI(pc))
		{
			if (isPCI(pc) && (PCI(pc)->op == POC_PAGESEL || PCI(pc)->op == POC_BANKSEL))
			{
				mc32_pcode_doubles++;
			}
			else
			{
				mc32_pcode_insns++;
			}
		}
	} // for
}

/*-----------------------------------------------------------------*/
/*                                                                 */
/*       pCode processing                                          */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/

void mc32_unlinkpCode(pCode *pc)
{

	if (pc)
	{
#ifdef PCODE_DEBUG
		fprintf(stderr, "Unlinking: ");
		mc32_printpCode(stderr, pc);
#endif
		if (pc->prev)
			pc->prev->next = pc->next;
		if (pc->next)
			pc->next->prev = pc->prev;

#if 0
		/* RN: I believe this should be right here, but this did not
		 *     cure the bug I was hunting... */
		/* must keep labels -- attach to following instruction */
		if (isPCI(pc) && PCI(pc)->label && pc->next)
		{
		  pCodeInstruction *pcnext = PCI(mc32_findNextInstruction (pc->next));
		  if (pcnext)
		  {
		    mc32_pBranchAppend (pcnext->label, PCI(pc)->label);
		  }
		}
#endif
		pc->prev = pc->next = NULL;
	}
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static void mc32_genericDestruct(pCode *pc)
{

	mc32_unlinkpCode(pc);

	if (isPCI(pc))
	{
		/* For instructions, tell the register (if there's one used)
		* that it's no longer needed */
		reg_info *reg = mc32_getRegFromInstruction(pc);
		if (reg)
			deleteSetItem(&(reg->reglives.usedpCodes), pc);
	}

	/* Instead of deleting the memory used by this pCode, mark
	* the object as bad so that if there's a pointer to this pCode
	* dangling around somewhere then (hopefully) when the type is
	* checked we'll catch it.
	*/

	pc->type = PC_BAD;

	mc32_addpCode2pBlock(mc32_pb_dead_pcodes, pc);

	//free(pc);
}

/*-----------------------------------------------------------------*/
/*  Copies the pCodeInstruction flow pointer from source pCode     */
/*-----------------------------------------------------------------*/
static void mc32_CopyFlow(pCodeInstruction *pcd, pCode *pcs)
{
	pCode *p;
	pCodeFlow *pcflow = 0;
	for (p = pcs; p; p = p->prev)
	{
		if (isPCI(p))
		{
			pcflow = PCI(p)->pcflow;
			break;
		}
		if (isPCF(p))
		{
			pcflow = (pCodeFlow *)p;
			break;
		}
	}
	PCI(pcd)->pcflow = pcflow;
}

/*-----------------------------------------------------------------*/
/*  mc32_pCodeInsertAfter - splice in the pCode chain starting with pc2 */
/*                     into the pCode chain containing pc1         */
/*-----------------------------------------------------------------*/
void mc32_pCodeInsertAfter(pCode *pc1, pCode *pc2)
{

	if (!pc1 || !pc2)
		return;

	pc2->next = pc1->next;
	if (pc1->next)
		pc1->next->prev = pc2;

	pc2->pb = pc1->pb;
	pc2->prev = pc1;
	pc1->next = pc2;

	/* If this is an instrution type propogate the flow */
	if (isPCI(pc2))
		mc32_CopyFlow(PCI(pc2), pc1);
}

/*------------------------------------------------------------------*/
/*  mc32_pCodeInsertBefore - splice in the pCode chain starting with pc2 */
/*                      into the pCode chain containing pc1         */
/*------------------------------------------------------------------*/
void mc32_pCodeInsertBefore(pCode *pc1, pCode *pc2)
{

	if (!pc1 || !pc2)
		return;

	pc2->prev = pc1->prev;
	if (pc1->prev)
		pc1->prev->next = pc2;

	pc2->pb = pc1->pb;
	pc2->next = pc1;
	pc1->prev = pc2;

	/* If this is an instrution type propogate the flow */
	if (isPCI(pc2))
		mc32_CopyFlow(PCI(pc2), pc1);
}

/*-----------------------------------------------------------------*/
/* mc32_pCodeOpCopy - copy a pcode operator                             */
/*-----------------------------------------------------------------*/
pCodeOp *mc32_pCodeOpCopy(pCodeOp *pcop)
{
	pCodeOp *pcopnew = NULL;

	if (!pcop)
		return NULL;

	switch (pcop->type)
	{
	case PO_NONE:
	case PO_STR:
		pcopnew = Safe_calloc(1, sizeof(pCodeOp));
		memcpy(pcopnew, pcop, sizeof(pCodeOp));
		break;

	case PO_W:
	case PO_STATUS:
	case PO_FSR:
	case PO_INDF:
	case PO_INTCON:
	case PO_GPR_REGISTER:
	case PO_GPR_TEMP:
	case PO_GPR_POINTER:
	case PO_SFR_REGISTER:
	case PO_PCL:
	case PO_PCLATH:
	case PO_DIR:
		//DFPRINTF((stderr,"mc32_pCodeOpCopy GPR register\n"));
		pcopnew = Safe_calloc(1, sizeof(pCodeOpReg));
		memcpy(pcopnew, pcop, sizeof(pCodeOpReg));
		DFPRINTF((stderr, " register index %d\n", PCOR(pcop)->r->rIdx));
		break;

	case PO_LITERAL:
		//DFPRINTF((stderr,"mc32_pCodeOpCopy lit\n"));
		pcopnew = Safe_calloc(1, sizeof(pCodeOpLit));
		memcpy(pcopnew, pcop, sizeof(pCodeOpLit));
		break;

	case PO_IMMEDIATE:
		pcopnew = Safe_calloc(1, sizeof(pCodeOpImmd));
		memcpy(pcopnew, pcop, sizeof(pCodeOpImmd));
		break;

	case PO_GPR_BIT:
	case PO_CRY:
	case PO_BIT:
		//DFPRINTF((stderr,"mc32_pCodeOpCopy bit\n"));
		pcopnew = Safe_calloc(1, sizeof(pCodeOpRegBit));
		memcpy(pcopnew, pcop, sizeof(pCodeOpRegBit));
		break;

	case PO_LABEL:
		//DFPRINTF((stderr,"mc32_pCodeOpCopy label\n"));
		pcopnew = Safe_calloc(1, sizeof(pCodeOpLabel));
		memcpy(pcopnew, pcop, sizeof(pCodeOpLabel));
		break;

	case PO_WILD:
		/* Here we expand the wild card into the appropriate type: */
		/* By recursively calling mc32_pCodeOpCopy */
		//DFPRINTF((stderr,"mc32_pCodeOpCopy wild\n"));
		if (PCOW(pcop)->matched)
			pcopnew = mc32_pCodeOpCopy(PCOW(pcop)->matched);
		else
		{
			// Probably a label
			pcopnew = mc32_pCodeOpCopy(PCOW(pcop)->subtype);
			pcopnew->name = Safe_strdup(PCOW(pcop)->pcwb->vars[PCOW(pcop)->id]);
			//DFPRINTF((stderr,"copied a wild op named %s\n",pcopnew->name));
		}

		return pcopnew;
		break;

	default:
		assert(!"unhandled pCodeOp type copied");
		break;
	} // switch

	if (pcop->name)
		pcopnew->name = Safe_strdup(pcop->name);
	else
		pcopnew->name = NULL;

	return pcopnew;
}

/*-----------------------------------------------------------------*/
/* mc32_popCopyReg - copy a pcode operator                              */
/*-----------------------------------------------------------------*/
pCodeOp *mc32_popCopyReg(pCodeOpReg *pc)
{
	pCodeOpReg *pcor;

	pcor = Safe_calloc(1, sizeof(pCodeOpReg));
	pcor->pcop.type = pc->pcop.type;
	if (pc->pcop.name)
	{
		if (!(pcor->pcop.name = Safe_strdup(pc->pcop.name)))
			fprintf(stderr, "oops %s %d", __FILE__, __LINE__);
	}
	else
		pcor->pcop.name = NULL;

	if (pcor->pcop.type == PO_IMMEDIATE)
	{
		PCOL(pcor)->lit = PCOL(pc)->lit;
	}
	else
	{
		pcor->r = pc->r;
		pcor->rIdx = pc->rIdx;
		if (pcor->r)
			pcor->r->wasUsed = 1;
	}
	//DEBUGmc32_pic14_emitcode ("; ***","%s  , copying %s, rIdx=%d",__FUNCTION__,pc->pcop.name,pc->rIdx);

	return PCOP(pcor);
}

/*-----------------------------------------------------------------*/
/* mc32_pCodeInstructionCopy - copy a mc32_pCodeInstructionCopy              */
/*-----------------------------------------------------------------*/
pCode *mc32_pCodeInstructionCopy(pCodeInstruction *pci, int invert)
{
	pCodeInstruction *new_pci;

	if (invert)
		new_pci = PCI(mc32_newpCode(pci->inverted_op, pci->pcop));
	else
		new_pci = PCI(mc32_newpCode(pci->op, pci->pcop));

	new_pci->pc.pb = pci->pc.pb;
	new_pci->from = pci->from;
	new_pci->to = pci->to;
	new_pci->label = pci->label;
	new_pci->pcflow = pci->pcflow;

	return PCODE(new_pci);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
void mc32_pCodeDeleteChain(pCode *f, pCode *t)
{
	pCode *pc;

	while (f && f != t)
	{
		DFPRINTF((stderr, "delete pCode:\n"));
		pc = f->next;
		//f->print(stderr,f);
		//f->delete(f);  this dumps core...
		f = pc;
	}
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
char *mc32_get_op(pCodeOp *pcop, char *buffer, size_t size)
{
	reg_info *r;
	static char b[50];
	char *s;
	int use_buffer = 1; // copy the string to the passed buffer pointer

	if (!buffer)
	{
		buffer = b;
		size = sizeof(b);
		use_buffer = 0; // Don't bother copying the string to the buffer.
	}

	if (pcop)
	{
		switch (pcop->type)
		{
		case PO_INDF:
		case PO_FSR:
			if (use_buffer)
			{
				SNPRINTF(buffer, size, "%s", PCOR(pcop)->r->name);
				return buffer;
			}
			return pcop->name;
			break;
		case PO_GPR_TEMP:
			if (PCOR(pcop)->r->type == REG_STK)
				r = mc32_typeRegWithIdx(PCOR(pcop)->r->rIdx, REG_STK, 1);
			else
				r = mc32_pic14_regWithIdx(PCOR(pcop)->r->rIdx);

			if (use_buffer)
			{
				SNPRINTF(buffer, size, "%s", r->name);
				return buffer;
			}

			return r->name;
			break;

		case PO_IMMEDIATE:
			s = buffer;
			if (PCOI(pcop)->_const)
			{

				if (PCOI(pcop)->offset >= 0 && PCOI(pcop)->offset < 4)
				{
					switch (PCOI(pcop)->offset)
					{
					case 0:
						SNPRINTF(s, size, "low (%s+%d)", pcop->name, PCOI(pcop)->index);
						break;
					case 1:
						SNPRINTF(s, size, "high (%s+%d)", pcop->name, PCOI(pcop)->index);
						break;
					case 2:
						SNPRINTF(s, size, "0x%02x", PCOI(pcop)->_const ? GPTRTAG_CODE : GPTRTAG_DATA);
						break;
					default:
						fprintf(stderr, "PO_IMMEDIATE/_const/offset=%d\n", PCOI(pcop)->offset);
						assert(!"offset too large");
						SNPRINTF(s, size, "(((%s+%d) >> %d)&0xff)",
								 pcop->name,
								 PCOI(pcop)->index,
								 8 * PCOI(pcop)->offset);
					}
				}
				else
					SNPRINTF(s, size, "LOW (%s+%d)", pcop->name, PCOI(pcop)->index);
			}
			else
			{
				if (!PCOI(pcop)->offset)
				{ // && PCOI(pcc->pcop)->offset<4)
					SNPRINTF(s, size, "(%s + %d)",
							 pcop->name,
							 PCOI(pcop)->index);
				}
				else
				{
					switch (PCOI(pcop)->offset)
					{
					case 0:
						SNPRINTF(s, size, "(%s + %d)", pcop->name, PCOI(pcop)->index);
						break;
					case 1:
						SNPRINTF(s, size, "high (%s + %d)", pcop->name, PCOI(pcop)->index);
						break;
					case 2:
						SNPRINTF(s, size, "0x%02x", PCOI(pcop)->_const ? GPTRTAG_CODE : GPTRTAG_DATA);
						break;
					default:
						fprintf(stderr, "PO_IMMEDIATE/mutable/offset=%d\n", PCOI(pcop)->offset);
						assert(!"offset too large");
						SNPRINTF(s, size, "((%s + %d) >> %d)&0xff", pcop->name, PCOI(pcop)->index, 8 * PCOI(pcop)->offset);
						break;
					}
				}
			}
			return buffer;
			break;

		case PO_DIR:
			s = buffer;
			if (PCOR(pcop)->instance)
			{
				SNPRINTF(s, size, "(%s + %d)",
						 pcop->name,
						 PCOR(pcop)->instance);
			}
			else
				SNPRINTF(s, size, "%s", pcop->name);
			return buffer;
			break;

		case PO_LABEL:
			s = buffer;
			if (pcop->name)
			{
				if (PCOLAB(pcop)->offset == 1)
					SNPRINTF(s, size, "HIGH(%s)", pcop->name);
				else
					SNPRINTF(s, size, "%s", pcop->name);
			}
			return buffer;
			break;

		case PO_GPR_BIT:
			if (PCOR(pcop)->r)
			{
				if (use_buffer)
				{
					SNPRINTF(buffer, size, "%s", PCOR(pcop)->r->name);
					return buffer;
				}
				return PCOR(pcop)->r->name;
			}
		/* fall through to the default case */

		default:
			if (pcop->name)
			{
				if (use_buffer)
				{
					SNPRINTF(buffer, size, "%s", pcop->name);
					return buffer;
				}
				return pcop->name;
			}
		}
	}

	printf("PIC port internal warning: (%s:%d(%s)) %s not found\n",
		   __FILE__, __LINE__, __FUNCTION__,
		   mc32_pCodeOpType(pcop));

	return "NO operand";
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static char *mc32_get_op_from_instruction(pCodeInstruction *pcc)
{

	if (pcc)
		return mc32_get_op(pcc->pcop, NULL, 0);

	return ("ERROR Null: mc32_get_op_from_instruction");
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_pCodeOpPrint(FILE *of, pCodeOp *pcop)
{
	fprintf(of, "pcodeopprint- not implemented\n");
}

/*-----------------------------------------------------------------*/
/* mc32_pCode2str - convert a pCode instruction to string               */
/*-----------------------------------------------------------------*/
char *mc32_pCode2str(char *str, size_t size, pCode *pc)
{
	char *s = str;

	switch (pc->type)
	{

	case PC_OPCODE:

		SNPRINTF(s, size, "\t%s\t", PCI(pc)->mnemonic);
		size -= strlen(s);
		s += strlen(s);

		if ((PCI(pc)->num_ops >= 1) && (PCI(pc)->pcop))
		{
			if (PCI(pc)->isBitInst)
			{
				if (PCI(pc)->pcop->type == PO_GPR_BIT)
				{
					char *name = PCI(pc)->pcop->name;
					if (!name)
						name = PCOR(PCI(pc)->pcop)->r->name;
					if ((((pCodeOpRegBit *)(PCI(pc)->pcop))->inBitSpace))
						SNPRINTF(s, size, "(%s >> 3), (%s & 7)", name, name);
					else
						SNPRINTF(s, size, "%s,%d", name, (((pCodeOpRegBit *)(PCI(pc)->pcop))->bit) & 7);
				}
				else if (PCI(pc)->pcop->type == PO_GPR_BIT)
				{
					SNPRINTF(s, size, "%s,%d", mc32_get_op_from_instruction(PCI(pc)), PCORB(PCI(pc)->pcop)->bit);
				}
				else
					SNPRINTF(s, size, "%s,0 ; ?bug", mc32_get_op_from_instruction(PCI(pc)));
			}
			else
			{
				if (PCI(pc)->pcop->type == PO_GPR_BIT)
				{
					if (PCI(pc)->num_ops == 2)
						SNPRINTF(s, size, "(%s >> 3),%c", mc32_get_op_from_instruction(PCI(pc)), ((PCI(pc)->isModReg) ? 'F' : 'W'));
					else
						SNPRINTF(s, size, "(1 << (%s & 7))", mc32_get_op_from_instruction(PCI(pc)));
				}
				else
				{
					SNPRINTF(s, size, "%s", mc32_get_op_from_instruction(PCI(pc)));
					size -= strlen(s);
					s += strlen(s);
					if (PCI(pc)->num_ops == 2)
						SNPRINTF(s, size, ",%c", ((PCI(pc)->isModReg) ? 'F' : 'W'));
				}
			}
		}
		break;

	case PC_COMMENT:
		/* assuming that comment ends with a \n */
		SNPRINTF(s, size, ";%s", ((pCodeComment *)pc)->comment);
		break;

	case PC_INLINE:
		/* assuming that inline code ends with a \n */
		SNPRINTF(s, size, "%s", ((pCodeComment *)pc)->comment);
		break;

	case PC_LABEL:
		SNPRINTF(s, size, ";label=%s, key=%d\n", PCL(pc)->label, PCL(pc)->key);
		break;
	case PC_FUNCTION:
		SNPRINTF(s, size, ";modname=%s,function=%s: id=%d\n", PCF(pc)->modname, PCF(pc)->fname);
		break;
	case PC_WILD:
		SNPRINTF(s, size, ";\tWild opcode: id=%d\n", PCW(pc)->id);
		break;
	case PC_FLOW:
		SNPRINTF(s, size, ";\t--FLOW change\n");
		break;
	case PC_CSOURCE:
		SNPRINTF(s, size, "%s\t.line\t%d; \"%s\"\t%s\n", (options.debug ? "" : ";"), PCCS(pc)->line_number, PCCS(pc)->file_name, PCCS(pc)->line);
		break;
	case PC_ASMDIR:
		if (PCAD(pc)->directive)
		{
			SNPRINTF(s, size, "\t%s%s%s\n", PCAD(pc)->directive, PCAD(pc)->arg ? "\t" : "", PCAD(pc)->arg ? PCAD(pc)->arg : "");
		}
		else if (PCAD(pc)->arg)
		{
			/* special case to handle inline labels without a tab */
			SNPRINTF(s, size, "%s\n", PCAD(pc)->arg);
		}
		break;

	case PC_BAD:
		SNPRINTF(s, size, ";A bad pCode is being used\n");
	}

	return str;
}

/*-----------------------------------------------------------------*/
/* mc32_genericPrint - the contents of a pCode to a file                */
/*-----------------------------------------------------------------*/
static void mc32_genericPrint(FILE *of, pCode *pc)
{
	if (!pc || !of)
		return;

	switch (pc->type)
	{
	case PC_COMMENT:
		fprintf(of, ";%s\n", ((pCodeComment *)pc)->comment);
		break;

	case PC_INLINE:
		fprintf(of, "%s\n", ((pCodeComment *)pc)->comment);
		break;

	case PC_OPCODE:
		// If the opcode has a label, print that first
		{
			char str[256];
			pCodeInstruction *pci = PCI(pc);
			pBranch *pbl = pci->label;
			while (pbl && pbl->pc)
			{
				if (pbl->pc->type == PC_LABEL)
					mc32_pCodePrintLabel(of, pbl->pc);
				pbl = pbl->next;
			}

			if (pci->cline)
				mc32_genericPrint(of, PCODE(pci->cline));

			mc32_pCode2str(str, 256, pc);

			fprintf(of, "%s", str);

			/* Debug */
			if (mc32_debug_verbose)
			{
				pCodeOpReg *pcor = PCOR(pci->pcop);
				fprintf(of, "\t;id=%u,key=%03x,inCond:%x,outCond:%x", pc->id, pc->seq, pci->inCond, pci->outCond);
				if (pci->pcflow)
					fprintf(of, ",flow seq=%03x", pci->pcflow->pc.seq);
				if (pcor && pcor->pcop.type == PO_GPR_TEMP && !pcor->r->isFixed)
					fprintf(of, ",rIdx=r0x%X", pcor->rIdx);
			}
		}
		fprintf(of, "\n");
		break;

	case PC_WILD:
		fprintf(of, ";\tWild opcode: id=%d\n", PCW(pc)->id);
		if (PCW(pc)->pci.label)
			mc32_pCodePrintLabel(of, PCW(pc)->pci.label->pc);

		if (PCW(pc)->operand)
		{
			fprintf(of, ";\toperand  ");
			mc32_pCodeOpPrint(of, PCW(pc)->operand);
		}
		break;

	case PC_FLOW:
		if (mc32_debug_verbose)
		{
			fprintf(of, ";<>Start of new flow, seq=0x%x", pc->seq);
			if (PCFL(pc)->ancestor)
				fprintf(of, " ancestor = 0x%x", PCODE(PCFL(pc)->ancestor)->seq);
			fprintf(of, "\n");
			fprintf(of, ";  from: ");
			{
				pCodeFlowLink *link;
				for (link = setFirstItem(PCFL(pc)->from); link; link = setNextItem(PCFL(pc)->from))
				{
					fprintf(of, "%03x ", link->pcflow->pc.seq);
				}
			}
			fprintf(of, "; to: ");
			{
				pCodeFlowLink *link;
				for (link = setFirstItem(PCFL(pc)->to); link; link = setNextItem(PCFL(pc)->to))
				{
					fprintf(of, "%03x ", link->pcflow->pc.seq);
				}
			}
			fprintf(of, "\n");
		}
		break;

	case PC_CSOURCE:
		fprintf(of, "%s\t.line\t%d; \"%s\"\t%s\n", (options.debug ? "" : ";"), PCCS(pc)->line_number, PCCS(pc)->file_name, PCCS(pc)->line);
		break;

	case PC_ASMDIR:
	{
		pBranch *pbl = PCAD(pc)->pci.label;
		while (pbl && pbl->pc)
		{
			if (pbl->pc->type == PC_LABEL)
				mc32_pCodePrintLabel(of, pbl->pc);
			pbl = pbl->next;
		}
	}
		// zwr 1.0.0
		if (PCAD(pc)->pci.cline)
			mc32_genericPrint(of, PCODE(PCAD(pc)->pci.cline));

		if (PCAD(pc)->directive)
		{
			fprintf(of, "\t%s%s%s\n", PCAD(pc)->directive, PCAD(pc)->arg ? "\t" : "", PCAD(pc)->arg ? PCAD(pc)->arg : "");
		}
		else if (PCAD(pc)->arg)
		{
			/* special case to handle inline labels without tab */
			fprintf(of, "%s\n", PCAD(pc)->arg);
		}
		break;

	case PC_LABEL:
	default:
		fprintf(of, "unknown pCode type %d\n", pc->type);
	}
}

/*-----------------------------------------------------------------*/
/* mc32_pCodePrintFunction - prints function begin/end                  */
/*-----------------------------------------------------------------*/

static void mc32_pCodePrintFunction(FILE *of, pCode *pc)
{

	if (!pc || !of)
		return;

	if (((pCodeFunction *)pc)->modname)
		fprintf(of, "F_%s", ((pCodeFunction *)pc)->modname);

	if (PCF(pc)->fname)
	{
		pBranch *exits = PCF(pc)->to;
		int i = 0;
		fprintf(of, "%s\t;Function start\n", PCF(pc)->fname);
		while (exits)
		{
			i++;
			exits = exits->next;
		}
		//if(i) i--;
		fprintf(of, "; %d exit point%c\n", i, ((i == 1) ? ' ' : 's'));
	}
	else
	{
		if ((PCF(pc)->from &&
			 PCF(pc)->from->pc->type == PC_FUNCTION &&
			 PCF(PCF(pc)->from->pc)->fname))
			fprintf(of, "; exit point of %s\n", PCF(PCF(pc)->from->pc)->fname);
		else
			fprintf(of, "; exit point [can't find entry point]\n");
	}
}

/*-----------------------------------------------------------------*/
/* mc32_pCodePrintLabel - prints label                                  */
/*-----------------------------------------------------------------*/

static void mc32_pCodePrintLabel(FILE *of, pCode *pc)
{

	if (!pc || !of)
		return;

	if (PCL(pc)->label)
		fprintf(of, "%s\n", PCL(pc)->label);
	else if (PCL(pc)->key >= 0)
		fprintf(of, "_%05d_DS_:\n", PCL(pc)->key);
	else
		fprintf(of, ";wild card label: id=%d\n", -PCL(pc)->key);
}

/*-----------------------------------------------------------------*/
/* mc32_unlinkpCodeFromBranch - Search for a label in a pBranch and     */
/*                         remove it if it is found.               */
/*-----------------------------------------------------------------*/
static void mc32_unlinkpCodeFromBranch(pCode *pcl, pCode *pc)
{
	pBranch *b, *bprev;

	bprev = NULL;

	if (pcl->type == PC_OPCODE || pcl->type == PC_INLINE || pcl->type == PC_ASMDIR)
		b = PCI(pcl)->label;
	else
	{
		fprintf(stderr, "LINE %d. can't unlink from non opcode\n", __LINE__);
		exit(1);
	}

	//fprintf (stderr, "%s \n",__FUNCTION__);
	//pcl->print(stderr,pcl);
	//pc->print(stderr,pc);
	while (b)
	{
		if (b->pc == pc)
		{
			//fprintf (stderr, "found label\n");

			/* Found a label */
			if (bprev)
			{
				bprev->next = b->next; /* Not first pCode in chain */
				free(b);
			}
			else
			{
				pc->destruct(pc);
				PCI(pcl)->label = b->next; /* First pCode in chain */
				free(b);
			}
			return; /* A label can't occur more than once */
		}
		bprev = b;
		b = b->next;
	}
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
pBranch *mc32_pBranchAppend(pBranch *h, pBranch *n)
{
	pBranch *b;

	if (!h)
		return n;

	if (h == n)
		return n;

	b = h;
	while (b->next)
		b = b->next;

	b->next = n;

	return h;
}

/*-----------------------------------------------------------------*/
/* mc32_pBranchLink - given two pcodes, this function will link them    */
/*               together through their pBranches                  */
/*-----------------------------------------------------------------*/
static void mc32_pBranchLink(pCodeFunction *f, pCodeFunction *t)
{
	pBranch *b;

	// Declare a new branch object for the 'from' pCode.

	//_ALLOC(b,sizeof(pBranch));
	b = Safe_calloc(1, sizeof(pBranch));
	b->pc = PCODE(t); // The link to the 'to' pCode.
	b->next = NULL;

	f->to = mc32_pBranchAppend(f->to, b);

	// Now do the same for the 'to' pCode.

	//_ALLOC(b,sizeof(pBranch));
	b = Safe_calloc(1, sizeof(pBranch));
	b->pc = PCODE(f);
	b->next = NULL;

	t->from = mc32_pBranchAppend(t->from, b);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_compareLabel(pCode *pc, pCodeOpLabel *pcop_label)
{
	pBranch *pbr;

	if (pc->type == PC_LABEL)
	{
		if (((pCodeLabel *)pc)->key == pcop_label->key)
			return TRUE;
	}
	if (pc->type == PC_OPCODE || pc->type == PC_ASMDIR)
	{
		pbr = PCI(pc)->label;
		while (pbr)
		{
			if (pbr->pc->type == PC_LABEL)
			{
				if (((pCodeLabel *)(pbr->pc))->key == pcop_label->key)
					return TRUE;
			}
			pbr = pbr->next;
		}
	}

	return FALSE;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_checkLabel(pCode *pc)
{
	pBranch *pbr;

	if (pc && isPCI(pc))
	{
		pbr = PCI(pc)->label;
		while (pbr)
		{
			if (isPCL(pbr->pc) && (PCL(pbr->pc)->key >= 0))
				return TRUE;

			pbr = pbr->next;
		}
	}

	return FALSE;
}

/*-----------------------------------------------------------------*/
/* mc32_findLabelinpBlock - Search the pCode for a particular label     */
/*-----------------------------------------------------------------*/
static pCode *mc32_findLabelinpBlock(pBlock *pb, pCodeOpLabel *pcop_label)
{
	pCode *pc;

	if (!pb)
		return NULL;

	for (pc = pb->pcHead; pc; pc = pc->next)
		if (mc32_compareLabel(pc, pcop_label))
			return pc;

	return NULL;
}

/*-----------------------------------------------------------------*/
/* mc32_findNextpCode - given a pCode, find the next of type 'pct'      */
/*                 in the linked list                              */
/*-----------------------------------------------------------------*/
pCode *mc32_findNextpCode(pCode *pc, PC_TYPE pct)
{

	while (pc)
	{
		if (pc->type == pct)
			return pc;

		pc = pc->next;
	}

	return NULL;
}

#if 0
/*-----------------------------------------------------------------*/
/* findPrevpCode - given a pCode, find the previous of type 'pct'  */
/*                 in the linked list                              */
/*-----------------------------------------------------------------*/
static pCode * findPrevpCode(pCode *pc, PC_TYPE pct)
{
	
	while(pc) {
		if(pc->type == pct) {
			/*
			static unsigned int stop;
			if (pc->id == 524)
				stop++; // Place break point here
			*/
			return pc;
		}
		
		pc = pc->prev;
	}
	
	return NULL;
}
#endif

/*-----------------------------------------------------------------*/
/* mc32_findNextInstruction - given a pCode, find the next instruction  */
/*                       in the linked list                        */
/*-----------------------------------------------------------------*/
pCode *mc32_findNextInstruction(pCode *pci)
{
	pCode *pc = pci;

	while (pc)
	{
		if ((pc->type == PC_OPCODE) || (pc->type == PC_WILD) || (pc->type == PC_ASMDIR))
			return pc;

#ifdef PCODE_DEBUG
		fprintf(stderr, "mc32_findNextInstruction:  ");
		mc32_printpCode(stderr, pc);
#endif
		pc = pc->next;
	}

	//fprintf(stderr,"Couldn't find instruction\n");
	return NULL;
}

/*-----------------------------------------------------------------*/
/* mc32_findNextInstruction - given a pCode, find the next instruction  */
/*                       in the linked list                        */
/*-----------------------------------------------------------------*/
pCode *mc32_findPrevInstruction(pCode *pci)
{
	pCode *pc = pci;

	while (pc)
	{

		if ((pc->type == PC_OPCODE) || (pc->type == PC_WILD) || (pc->type == PC_ASMDIR))
			return pc;

#ifdef PCODE_DEBUG
		fprintf(stderr, "pic16_mc32_findPrevInstruction:  ");
		mc32_printpCode(stderr, pc);
#endif
		pc = pc->prev;
	}

	//fprintf(stderr,"Couldn't find instruction\n");
	return NULL;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
reg_info *mc32_getRegFromInstruction(pCode *pc)
{
	reg_info *r;
	if (!pc ||
		!isPCI(pc) ||
		!PCI(pc)->pcop ||
		PCI(pc)->num_ops == 0)
		return NULL;

	switch (PCI(pc)->pcop->type)
	{
	case PO_STATUS:
	case PO_FSR:
	case PO_INDF:
	case PO_INTCON:
	case PO_BIT:
	case PO_GPR_TEMP:
	case PO_SFR_REGISTER:
	case PO_PCL:
	case PO_PCLATH:
		return PCOR(PCI(pc)->pcop)->r;

	case PO_GPR_REGISTER:
	case PO_GPR_BIT:
	case PO_DIR:
		r = PCOR(PCI(pc)->pcop)->r;
		if (r)
			return r;
		return mc32_dirregWithName(PCI(pc)->pcop->name);

	case PO_LITERAL:
		break;

	case PO_IMMEDIATE:
		r = PCOI(PCI(pc)->pcop)->r;
		if (r)
			return r;
		return mc32_dirregWithName(PCI(pc)->pcop->name);

	default:
		break;
	}

	return NULL;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static void mc32_AnalyzepBlock(pBlock *pb)
{
	pCode *pc;

	if (!pb)
		return;

	/* Find all of the registers used in this pBlock 
		* by looking at each instruction and examining it's
		* operands
	*/
	for (pc = pb->pcHead; pc; pc = pc->next)
	{

		/* Is this an instruction with operands? */
		if (pc->type == PC_OPCODE && PCI(pc)->pcop)
		{

			if ((PCI(pc)->pcop->type == PO_GPR_TEMP) || ((PCI(pc)->pcop->type == PO_GPR_BIT) && PCOR(PCI(pc)->pcop)->r && (PCOR(PCI(pc)->pcop)->r->pc_type == PO_GPR_TEMP)))
			{

				/* Loop through all of the registers declared so far in
				this block and see if we find this one there */

				reg_info *r = setFirstItem(pb->tregisters);

				while (r)
				{
					if ((r->rIdx == PCOR(PCI(pc)->pcop)->r->rIdx) && (r->type == PCOR(PCI(pc)->pcop)->r->type))
					{
						PCOR(PCI(pc)->pcop)->r = r;
						break;
					}
					r = setNextItem(pb->tregisters);
				}

				if (!r)
				{
					/* register wasn't found */
					//r = Safe_calloc(1, sizeof(regs));
					//memcpy(r,PCOR(PCI(pc)->pcop)->r, sizeof(regs));
					//addSet(&pb->tregisters, r);
					addSet(&pb->tregisters, PCOR(PCI(pc)->pcop)->r);
					//PCOR(PCI(pc)->pcop)->r = r;
					//fprintf(stderr,"added register to pblock: reg %d\n",r->rIdx);
				} /* else 
					 fprintf(stderr,"found register in pblock: reg %d\n",r->rIdx);
				*/
			}
			if (PCI(pc)->pcop->type == PO_GPR_REGISTER)
			{
				if (PCOR(PCI(pc)->pcop)->r)
				{
					mc32_allocWithIdx(PCOR(PCI(pc)->pcop)->r->rIdx);
					DFPRINTF((stderr, "found register in pblock: reg 0x%x\n", PCOR(PCI(pc)->pcop)->r->rIdx));
				}
				else
				{
					if (PCI(pc)->pcop->name)
						fprintf(stderr, "ERROR: %s is a NULL register\n", PCI(pc)->pcop->name);
					else
						fprintf(stderr, "ERROR: NULL register\n");
				}
			}
		}
	}
}

/*-----------------------------------------------------------------*/
/* */
/*-----------------------------------------------------------------*/
static void mc32_InsertpFlow(pCode *pc, pCode **pflow)
{
	if (*pflow)
		PCFL(*pflow)->end = pc;

	if (!pc || !pc->next)
		return;

	*pflow = mc32_newpCodeFlow();
	mc32_pCodeInsertAfter(pc, *pflow);
}

/*-----------------------------------------------------------------*/
/* mc32_BuildFlow(pBlock *pb) - examine the code in a pBlock and build  */
/*                         the flow blocks.                        */
/*
* mc32_BuildFlow inserts pCodeFlow objects into the pCode chain at each
* point the instruction flow changes. 
*/
/*-----------------------------------------------------------------*/
static void mc32_BuildFlow(pBlock *pb)
{
	pCode *pc;
	pCode *last_pci = NULL;
	pCode *pflow = NULL;
	int seq = 0;

	if (!pb)
		return;

	//fprintf (stderr,"build flow start seq %d  ",mc32_GpcFlowSeq);
	/* Insert a pCodeFlow object at the beginning of a pBlock */

	mc32_InsertpFlow(pb->pcHead, &pflow);

	//pflow = mc32_newpCodeFlow();    /* Create a new Flow object */
	//pflow->next = pb->pcHead;  /* Make the current head the next object */
	//pb->pcHead->prev = pflow;  /* let the current head point back to the flow object */
	//pb->pcHead = pflow;        /* Make the Flow object the head */
	//pflow->pb = pb;

	for (pc = mc32_findNextInstruction(pb->pcHead);
		 pc != NULL;
		 pc = mc32_findNextInstruction(pc))
	{

		pc->seq = seq++;
		PCI(pc)->pcflow = PCFL(pflow);

		//fprintf(stderr," build: ");
		//pc->print(stderr, pc);
		//pflow->print(stderr,pflow);

		if (mc32_checkLabel(pc))
		{

			/* This instruction marks the beginning of a
			* new flow segment */

			pc->seq = 0;
			seq = 1;

			/* If the previous pCode is not a flow object, then 
			* insert a new flow object. (This check prevents 
			* two consecutive flow objects from being insert in
			* the case where a skip instruction preceeds an
			* instruction containing a label.) */

			last_pci = mc32_findPrevInstruction(pc->prev);

			if (last_pci && (PCI(last_pci)->pcflow == PCFL(pflow)))
				mc32_InsertpFlow(last_pci, &pflow);

			PCI(pc)->pcflow = PCFL(pflow);
		}

		if (isPCI_SKIP(pc))
		{

			/* The two instructions immediately following this one 
			* mark the beginning of a new flow segment */

			while (pc && isPCI_SKIP(pc))
			{

				PCI(pc)->pcflow = PCFL(pflow);
				pc->seq = seq - 1;
				seq = 1;

				mc32_InsertpFlow(pc, &pflow);
				pc = mc32_findNextInstruction(pc->next);
			}

			seq = 0;

			if (!pc)
				break;

			PCI(pc)->pcflow = PCFL(pflow);
			pc->seq = 0;
			mc32_InsertpFlow(pc, &pflow);
		}
		else if (isPCI_BRANCH(pc) && !mc32_checkLabel(mc32_findNextInstruction(pc->next)))
		{

			mc32_InsertpFlow(pc, &pflow);
			seq = 0;
		}

		last_pci = pc;
		pc = pc->next;
	}

	//fprintf (stderr,",end seq %d",mc32_GpcFlowSeq);
	if (pflow)
		PCFL(pflow)->end = pb->pcTail;
}

/*-------------------------------------------------------------------*/
/* mc32_unBuildFlow(pBlock *pb) - examine the code in a pBlock and build  */
/*                           the flow blocks.                        */
/*
* mc32_unBuildFlow removes pCodeFlow objects from a pCode chain
*/
/*-----------------------------------------------------------------*/
static void mc32_unBuildFlow(pBlock *pb)
{
	pCode *pc, *pcnext;

	if (!pb)
		return;

	pc = pb->pcHead;

	while (pc)
	{
		pcnext = pc->next;

		if (isPCI(pc))
		{

			pc->seq = 0;
			if (PCI(pc)->pcflow)
			{
				//free(PCI(pc)->pcflow);
				PCI(pc)->pcflow = NULL;
			}
		}
		else if (isPCFL(pc))
			pc->destruct(pc);

		pc = pcnext;
	}
}

#if 0
/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void dumpCond(int cond)
{
	
	static char *pcc_str[] = {
		//"PCC_NONE",
		"PCC_REGISTER",
			"PCC_C",
			"PCC_Z",
			"PCC_DC",
			"PCC_W",
			"PCC_EXAMINE_PCOP",
			"PCC_REG_BANK0",
			"PCC_REG_BANK1",
			"PCC_REG_BANK2",
			"PCC_REG_BANK3"
	};
	
	int ncond = sizeof(pcc_str) / sizeof(char *);
	int i,j;
	
	fprintf(stderr, "0x%04X\n",cond);
	
	for(i=0,j=1; i<ncond; i++, j<<=1)
		if(cond & j)
			fprintf(stderr, "  %s\n",pcc_str[i]);
		
}
#endif

#if 0
/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void FlowStats(pCodeFlow *pcflow)
{
	
	pCode *pc;
	
	if(!isPCFL(pcflow))
		return;
	
	fprintf(stderr, " FlowStats - flow block (seq=%d)\n", pcflow->pc.seq);
	
	pc = mc32_findNextpCode(PCODE(pcflow), PC_OPCODE); 
	
	if(!pc) {
		fprintf(stderr, " FlowStats - empty flow (seq=%d)\n", pcflow->pc.seq);
		return;
	}
	
	
	fprintf(stderr, "  FlowStats inCond: ");
	dumpCond(pcflow->inCond);
	fprintf(stderr, "  FlowStats outCond: ");
	dumpCond(pcflow->outCond);
	
}
#endif

/*-----------------------------------------------------------------*
* int isBankInstruction(pCode *pc) - examine the pCode *pc to determine
*    if it affects the banking bits. 
* 
* return: -1 == Banking bits are unaffected by this pCode.
*
* return: > 0 == Banking bits are affected.
*
*  If the banking bits are affected, then the returned value describes
* which bits are affected and how they're affected. The lower half
* of the integer maps to the bits that are affected, the upper half
* to whether they're set or cleared.
*
*-----------------------------------------------------------------*/
/*
static int isBankInstruction(pCode *pc)
{
	regs *reg;
	int bank = -1;
	
	if(!isPCI(pc))
		return -1;
	
	if( ( (reg = mc32_getRegFromInstruction(pc)) != NULL) && isSTATUS_REG(reg)) {
		
		// Check to see if the register banks are changing
		if(PCI(pc)->isModReg) {
			
			pCodeOp *pcop = PCI(pc)->pcop;
			switch(PCI(pc)->op) {
				
			case POC_BSF:
				if(PCORB(pcop)->bit == PIC_RP0_BIT) {
					//fprintf(stderr, "  isBankInstruction - Set RP0\n");
					return  SET_BANK_BIT | PIC_RP0_BIT;
				}
				
				if(PCORB(pcop)->bit == PIC_RP1_BIT) {
					//fprintf(stderr, "  isBankInstruction - Set RP1\n");
					return  CLR_BANK_BIT | PIC_RP0_BIT;
				}
				break;
				
			case POC_BCF:
				if(PCORB(pcop)->bit == PIC_RP0_BIT) {
					//fprintf(stderr, "  isBankInstruction - Clr RP0\n");
					return  CLR_BANK_BIT | PIC_RP1_BIT;
				}
				if(PCORB(pcop)->bit == PIC_RP1_BIT) {
					//fprintf(stderr, "  isBankInstruction - Clr RP1\n");
					return  CLR_BANK_BIT | PIC_RP1_BIT;
				}
				break;
			default:
				//fprintf(stderr, "  isBankInstruction - Status register is getting Modified by:\n");
				//mc32_genericPrint(stderr, pc);
				;
			}
		}
		
				}
				
	return bank;
}
*/

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
/*
static void FillFlow(pCodeFlow *pcflow)
{
	pCode *pc;
	int cur_bank;
	
	if(!isPCFL(pcflow))
		return;
	
	//  fprintf(stderr, " FillFlow - flow block (seq=%d)\n", pcflow->pc.seq);
	
	pc = mc32_findNextpCode(PCODE(pcflow), PC_OPCODE); 
	
	if(!pc) {
		//fprintf(stderr, " FillFlow - empty flow (seq=%d)\n", pcflow->pc.seq);
		return;
	}
	
	cur_bank = -1;
	
	do {
		isBankInstruction(pc);
		pc = pc->next;
	} while (pc && (pc != pcflow->end) && !isPCFL(pc));
	/ *
		if(!pc ) {
			fprintf(stderr, "  FillFlow - Bad end of flow\n");
		} else {
			fprintf(stderr, "  FillFlow - Ending flow with\n  ");
			pc->print(stderr,pc);
		}
		
		fprintf(stderr, "  FillFlow inCond: ");
		dumpCond(pcflow->inCond);
		fprintf(stderr, "  FillFlow outCond: ");
		dumpCond(pcflow->outCond);
		* /
}
*/

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_LinkFlow_pCode(pCodeInstruction *from, pCodeInstruction *to)
{
	pCodeFlowLink *fromLink, *toLink;
#if 0
	fprintf(stderr, "%s: linking ", __FUNCTION__ );
	if (from) from->pc.print(stderr, &from->pc);
	else fprintf(stderr, "(null)");
	fprintf(stderr, " -(%u)-> with -(%u)-> ",
		from && from->pcflow ? from->pcflow->pc.seq : 0,
		to && to->pcflow ? to->pcflow->pc.seq : 0);
	if (to) to->pc.print(stderr, &to->pc);
	else fprintf(stderr, "(null)");
#endif

	if (!from || !to || !to->pcflow || !from->pcflow)
		return;

	fromLink = mc32_newpCodeFlowLink(from->pcflow);
	toLink = mc32_newpCodeFlowLink(to->pcflow);

	addSetIfnotP(&(from->pcflow->to), toLink);   //to->pcflow);
	addSetIfnotP(&(to->pcflow->from), fromLink); //from->pcflow);
}

/*-----------------------------------------------------------------*
* void mc32_LinkFlow(pBlock *pb)
*
* In mc32_BuildFlow, the PIC code has been partitioned into contiguous
* non-branching segments. In mc32_LinkFlow, we determine the execution
* order of these segments. For example, if one of the segments ends
* with a skip, then we know that there are two possible flow segments
* to which control may be passed.
*-----------------------------------------------------------------*/
static void mc32_LinkFlow(pBlock *pb)
{
	pCode *pc = NULL;
	pCode *pcflow;
	pCode *pct;

	//fprintf(stderr,"linkflow \n");

	if (!pb)
		return;

	for (pcflow = mc32_findNextpCode(pb->pcHead, PC_FLOW);
		 pcflow != NULL;
		 pcflow = mc32_findNextpCode(pcflow->next, PC_FLOW))
	{

		if (!isPCFL(pcflow))
			fprintf(stderr, "mc32_LinkFlow - pcflow is not a flow object ");

		//fprintf(stderr," link: ");
		//pcflow->print(stderr,pcflow);

		//FillFlow(PCFL(pcflow));

		/* find last instruction in flow */
		pc = mc32_findPrevInstruction(PCFL(pcflow)->end);
		if (!pc)
		{
			fprintf(stderr, "%s: flow without end (%u)?\n",
					__FUNCTION__, pcflow->seq);
			continue;
		}

		//fprintf(stderr, "mc32_LinkFlow - flow block (seq=%d) ", pcflow->seq);
		//pc->print(stderr, pc);
		if (isPCI_SKIP(pc))
		{
			//fprintf(stderr, "ends with skip\n");
			//pc->print(stderr,pc);
			pct = mc32_findNextInstruction(pc->next);
			mc32_LinkFlow_pCode(PCI(pc), PCI(pct));
			pct = mc32_findNextInstruction(pct->next);
			mc32_LinkFlow_pCode(PCI(pc), PCI(pct));
			continue;
		}

		if (isPCI_BRANCH(pc))
		{
			pCodeOpLabel *pcol = PCOLAB(PCI(pc)->pcop);

			//fprintf(stderr, "ends with branch\n  ");
			//pc->print(stderr,pc);

			if (!(pcol && isPCOLAB(pcol)))
			{
				if ((PCI(pc)->op != POC_RETLW) && (PCI(pc)->op != POC_RETURN) && (PCI(pc)->op != POC_CALL) && (PCI(pc)->op != POC_RETFIE))
				{
					pc->print(stderr, pc);
					fprintf(stderr, "ERROR: %s, branch instruction doesn't have label\n", __FUNCTION__);
				}
			}
			else
			{

				if ((pct = mc32_findLabelinpBlock(pb, pcol)) != NULL)
					mc32_LinkFlow_pCode(PCI(pc), PCI(pct));
				else
					fprintf(stderr, "ERROR: %s, couldn't find label. key=%d,lab=%s\n",
							__FUNCTION__, pcol->key, ((PCOP(pcol)->name) ? PCOP(pcol)->name : "-"));
				//fprintf(stderr,"mc32_newpCodeOpLabel: key=%d, name=%s\n",key,((s)?s:""));
			}
			/* link CALLs to next instruction */
			if (PCI(pc)->op != POC_CALL)
				continue;
		}

		if (isPCI(pc))
		{
			//fprintf(stderr, "ends with non-branching instruction:\n");
			//pc->print(stderr,pc);

			mc32_LinkFlow_pCode(PCI(pc), PCI(mc32_findNextInstruction(pc->next)));

			continue;
		}

		if (pc)
		{
			//fprintf(stderr, "ends with unknown\n");
			//pc->print(stderr,pc);
			continue;
		}

		fprintf(stderr, "ends with nothing: ERROR\n");
	}
}

static void mc32_pCodeReplace(pCode *old, pCode *new)
{
	mc32_pCodeInsertAfter(old, new);

	/* special handling for pCodeInstructions */
	if (isPCI(new) && isPCI(old))
	{
		//assert (!PCI(new)->from && !PCI(new)->to && !PCI(new)->label && /*!PCI(new)->pcflow && */!PCI(new)->cline);
		PCI(new)->from = PCI(old)->from;
		PCI(new)->to = PCI(old)->to;
		PCI(new)->label = PCI(old)->label;
		PCI(new)->pcflow = PCI(old)->pcflow;
		PCI(new)->cline = PCI(old)->cline;
	} // if

	old->destruct(old);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_addpCodeComment(pCode *pc, const char *fmt, ...)
{
	va_list ap;
	char buffer[4096];
	pCode *newpc;

	va_start(ap, fmt);
	if (options.verbose || mc32_debug_verbose)
	{
		buffer[0] = ';';
		buffer[1] = ' ';
		vsprintf(&buffer[2], fmt, ap);

		newpc = mc32_newpCodeCharP(&buffer[0]); // strdup's the string
		mc32_pCodeInsertAfter(pc, newpc);
	}
	va_end(ap);
}

/*-----------------------------------------------------------------*/
/* Inserts a new pCodeInstruction before an existing one           */
/*-----------------------------------------------------------------*/
static void mc32_insertPCodeInstruction(pCodeInstruction *pci, pCodeInstruction *new_pci)
{
	pCode *pcprev;

	pcprev = mc32_findPrevInstruction(pci->pc.prev);

	mc32_pCodeInsertAfter(pci->pc.prev, &new_pci->pc);

	/* Move the label, if there is one */

	if (pci->label)
	{
		new_pci->label = pci->label;
		pci->label = NULL;
	}

	/* Move the C code comment, if there is one */

	if (pci->cline)
	{
		new_pci->cline = pci->cline;
		pci->cline = NULL;
	}

	/* The new instruction has the same pcflow block */
	new_pci->pcflow = pci->pcflow;

	/* Arrrrg: is pci's previous instruction is a skip, we need to
	 * change that into a jump (over pci and the new instruction) ... */
	if (pcprev && isPCI_SKIP(pcprev))
	{
		symbol *lbl = newiTempLabel(NULL);
		pCode *label = mc32_newpCodeLabel(NULL, lbl->key);
		pCode *jump = mc32_newpCode(POC_GOTO, mc32_newpCodeOpLabel(NULL, lbl->key));

		mc32_pCodeInsertAfter(pcprev, jump);

		// Yuck: Cannot simply replace INCFSZ/INCFSZW/DECFSZ/DECFSZW
		// We replace them with INCF/INCFW/DECF/DECFW followed by 'BTFSS STATUS, Z'
		switch (PCI(pcprev)->op)
		{
		case POC_INCFSZ:
		case POC_INCFSZW:
		case POC_DECFSZ:
		case POC_DECFSZW:
			// These are turned into non-skipping instructions, so
			// insert 'BTFSC STATUS, Z' after pcprev
			mc32_pCodeInsertAfter(jump->prev, mc32_newpCode(POC_BTFSC, mc32_popCopyGPR2Bit(PCOP(&mc32_pc_status), PIC_Z_BIT)));
			break;
		default:
			// no special actions required
			break;
		}
		mc32_pCodeReplace(pcprev, mc32_pCodeInstructionCopy(PCI(pcprev), 1));
		pcprev = NULL;
		mc32_pCodeInsertAfter((pCode *)pci, label);
		mc32_pBlockMergeLabels(pci->pc.pb);
	}
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_insertBankSel(pCodeInstruction *pci, const char *name)
{
	pCode *new_pc;

	pCodeOp *pcop;

	// Never BANKSEL STATUS, this breaks all kinds of code (e.g., interrupt handlers).
	if (!strcmp("STATUS", name) || !strcmp("_STATUS", name))
		return 0;

	pcop = mc32_popCopyReg(PCOR(pci->pcop));
	pcop->type = PO_GPR_REGISTER; // Sometimes the type is set to legacy 8051 - so override it
	if (pcop->name == 0)
		pcop->name = strdup(name);
	new_pc = mc32_newpCode(POC_BANKSEL, pcop);

	mc32_insertPCodeInstruction(pci, PCI(new_pc));
	return 1;
}

/*
 * mc32_isValidIdChar - check if c may be present in an identifier
 */
static int mc32_isValidIdChar(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 1;
	if (c >= '0' && c <= '9')
		return 1;
	if (c == '_')
		return 1;
	return 0;
}

/*
 * bankcompare - check if two operand string refer to the same register
 * This functions handles NAME and (NAME + x) in both operands.
 * Returns 1 on same register, 0 on different (or unknown) registers.
 */
static int mc32_bankCompare(const char *op1, const char *op2)
{
	int i;

	if (!op1 && !op2)
		return 0; // both unknown, might be different though!
	if (!op1 || !op2)
		return 0;

	// find start of operand name
	while (op1[0] == '(' || op1[0] == ' ')
		op1++;
	while (op2[0] == '(' || op2[0] == ' ')
		op2++;

	// compare till first non-identifier character
	for (i = 0; (op1[i] == op2[i]) && mc32_isValidIdChar(op1[i]); i++)
		;
	if (!mc32_isValidIdChar(op1[i]) && !mc32_isValidIdChar(op2[i]))
		return 1;

	// play safe---assume different operands
	return 0;
}

/*
 * Interface to BANKSEL generation.
 * This function should return != 0 iff str1 and str2 denote operands that
 * are known to be allocated into the same bank. Consequently, there will
 * be no BANKSEL mc32_emitted if str2 is accessed while str1 has been used to
 * select the current bank just previously.
 *
 * If in doubt, return 0.
 */
static int
mc32_operandsAllocatedInSameBank(const char *str1, const char *str2)
{
	// see glue.c(mc32_printLocals)

	if (getenv("SDCC_PIC14_SPLIT_LOCALS"))
	{
		// no clustering applied, each register resides in its own bank
	}
	else
	{
		// check whether BOTH names are local registers
		// XXX: This is some kind of shortcut, should be safe...
		// In this model, all r0xXXXX are allocated into a single section
		// per file, so no BANKSEL required if accessing a r0xXXXX after a
		// (different) r0xXXXX. Works great for multi-byte operands.
		if (str1 && str2 && str1[0] == 'r' && str2[0] == 'r')
			return (1);
	} // if

	// assume operands in different banks
	return (0);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_sameBank(reg_info *reg, reg_info *previous_reg, const char *new_bank, const char *cur_bank, unsigned max_mask)
{
	if (!cur_bank)
		return 0;

	if (previous_reg && reg && previous_reg->isFixed && reg->isFixed && ((previous_reg->address & max_mask) == (reg->address & max_mask))) // only if exists
		return 1;																														   // if we have address info, we use it for banksel optimization

	// regard '(regname + X)' and '(regname + Y)' as equal
	if (reg && reg->name && mc32_bankCompare(reg->name, cur_bank))
		return 1;
	if (new_bank && mc32_bankCompare(new_bank, cur_bank))
		return 1;

	// check allocation policy from glue.c
	if (reg && reg->name && mc32_operandsAllocatedInSameBank(reg->name, cur_bank))
		return 1;
	if (new_bank && mc32_operandsAllocatedInSameBank(new_bank, cur_bank))
		return 1;

	// seems to be a different operand--might be a different bank
	//printf ("BANKSEL from %s to %s/%s\n", cur_bank, reg->name, new_bank);
	return 0;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_FixRegisterBanking(pBlock *pb)
{
	pCode *pc;
	pCodeInstruction *pci;
	reg_info *reg;
	reg_info *previous_reg; // contains the previous variable access info
	const char *cur_bank, *new_bank;
	unsigned cur_mask, new_mask, max_mask;
	int allRAMmshared;

	if (!pb)
		return;

	max_mask = mc32_getPIC()->bankMask;
	cur_mask = max_mask;
	cur_bank = NULL;
	previous_reg = NULL;

	allRAMmshared = mc32_allRAMShared();

	for (pc = pb->pcHead; pc; pc = pc->next)
	{
		// this one has a label---might check bank at all jumps here...
		if (isPCI(pc) && (PCI(pc)->label || PCI(pc)->op == POC_CALL))
		{
			mc32_addpCodeComment(pc->prev, "BANKOPT3 drop assumptions: PCI with label or call found");
			previous_reg = NULL;
			cur_bank = NULL; // start new flow
			cur_mask = max_mask;
		}

		// this one is/might be a label or BANKSEL---assume nothing
		if (isPCL(pc) || isPCASMDIR(pc))
		{
			mc32_addpCodeComment(pc->prev, "BANKOPT4 drop assumptions: label or ASMDIR found");
			previous_reg = NULL;
			cur_bank = NULL;
			cur_mask = max_mask;
		}

		// this one modifies STATUS
		// XXX: this should be checked, but usually BANKSELs are not done this way in generated code

		if (isPCI(pc))
		{
			pci = PCI(pc);
			if ((pci->inCond | pci->outCond) & PCC_REGISTER)
			{
				// might need a BANKSEL
				reg = mc32_getRegFromInstruction(pc);

				if (reg)
				{
					new_bank = reg->name;
					// reg->alias == 0: reg is in only one bank, we do not know which (may be any bank)
					// reg->alias != 0: reg is in 2/4/8/2**N banks, we select one of them
					new_mask = reg->alias;
				}
				else if (pci->pcop && pci->pcop->name)
				{
					new_bank = pci->pcop->name;
					new_mask = 0; // unknown, assume worst case
				}
				else
				{
					assert(!"Could not get register from instruction.");
					new_bank = "UNKNOWN";
					new_mask = 0; // unknown, assume worst case
				}

				// optimizations...
				// XXX: add switch to disable these
				if (1)
				{
					// reg present in all banks possibly selected?
					if (new_mask == max_mask || (cur_mask && ((new_mask & cur_mask) == cur_mask)))
					{
						// no BANKSEL required
						mc32_addpCodeComment(pc->prev, "BANKOPT1 BANKSEL dropped; %s present in all of %s's banks", new_bank, cur_bank);
						continue;
					}

					// only one bank of memory and no SFR accessed?
					// XXX: We can do better with fixed registers.
					if (allRAMmshared && reg && (reg->type != REG_SFR) && (!reg->isFixed))
					{
						// no BANKSEL required
						mc32_addpCodeComment(pc->prev, "BANKOPT1b BANKSEL dropped; %s present in all (of %s's) banks", new_bank, cur_bank);
						continue;
					}

					if (mc32_sameBank(reg, previous_reg, new_bank, cur_bank, max_mask))
					{
						// no BANKSEL required
						mc32_addpCodeComment(pc->prev, "BANKOPT2 BANKSEL dropped; %s present in same bank as %s", new_bank, cur_bank);
						continue;
					}
				} // if

				if (mc32_insertBankSel(pci, new_bank))
				{
					cur_mask = new_mask;
					cur_bank = new_bank;
					previous_reg = reg;
				} // if
			}	 // if
		}		  // if
	}			  // for
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_OptimizepBlock(pBlock *pb)
{
	pCode *pc, *pcprev;
	int matches = 0;

	if (!pb || options.nopeep)
		return 0;

	DFPRINTF((stderr, " Optimizing pBlock: %c\n", mc32_getpBlock_dbName(pb)));
	/*
	for(pc = pb->pcHead; pc; pc = pc->next)
	matches += mc32_pCodePeepMatchRule(pc);
	*/

	pc = mc32_findNextInstruction(pb->pcHead);
	if (!pc)
		return 0;

	pcprev = pc->prev;
	do
	{

		if (mc32_pCodePeepMatchRule(pc))
		{

			matches++;

			if (pcprev)
				pc = mc32_findNextInstruction(pcprev->next);
			else
				pc = mc32_findNextInstruction(pb->pcHead);
		}
		else
			pc = mc32_findNextInstruction(pc->next);
	} while (pc);

	if (matches)
		DFPRINTF((stderr, " Optimizing pBlock: %c - matches=%d\n", mc32_getpBlock_dbName(pb), matches));
	return matches;
}

/*-----------------------------------------------------------------*/
/* mc32_pBlockRemoveUnusedLabels - remove the pCode labels from the     */
/*-----------------------------------------------------------------*/
static pCode *mc32_findInstructionUsingLabel(pCodeLabel *pcl, pCode *pcs)
{
	pCode *pc;

	for (pc = pcs; pc; pc = pc->next)
	{

		if (((pc->type == PC_OPCODE) || (pc->type == PC_INLINE) || (pc->type == PC_ASMDIR)) &&
			(PCI(pc)->pcop) &&
			(PCI(pc)->pcop->type == PO_LABEL) &&
			(PCOLAB(PCI(pc)->pcop)->key == pcl->key))
			return pc;
	}

	return NULL;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_exchangeLabels(pCodeLabel *pcl, pCode *pc)
{

	char *s = NULL;

	if (isPCI(pc) &&
		(PCI(pc)->pcop) &&
		(PCI(pc)->pcop->type == PO_LABEL))
	{

		pCodeOpLabel *pcol = PCOLAB(PCI(pc)->pcop);

		//fprintf(stderr,"changing label key from %d to %d\n",pcol->key, pcl->key);
		if (pcol->pcop.name)
			free(pcol->pcop.name);

		/* If the key is negative, then we (probably) have a label to
		* a function and the name is already defined */

		if (pcl->key > 0)
			sprintf(s = buffer, "_%05d_DS_", pcl->key);
		else
			s = pcl->label;

		//sprintf(buffer,"_%05d_DS_",pcl->key);
		if (!s)
		{
			fprintf(stderr, "ERROR %s:%d function label is null\n", __FUNCTION__, __LINE__);
		}
		pcol->pcop.name = Safe_strdup(s);
		pcol->key = pcl->key;
		//pc->print(stderr,pc);
	}
}

/*-----------------------------------------------------------------*/
/* mc32_pBlockRemoveUnusedLabels - remove the pCode labels from the     */
/*                            pCode chain if they're not used.     */
/*-----------------------------------------------------------------*/
static void mc32_pBlockRemoveUnusedLabels(pBlock *pb)
{
	pCode *pc;
	pCodeLabel *pcl;

	if (!pb || !pb->pcHead)
		return;

	for (pc = pb->pcHead; (pc = mc32_findNextInstruction(pc->next)) != NULL;)
	{

		pBranch *pbr = PCI(pc)->label;
		if (pbr && pbr->next)
		{
			pCode *pcd = pb->pcHead;

			//fprintf(stderr, "multiple labels\n");
			//pc->print(stderr,pc);

			pbr = pbr->next;
			while (pbr)
			{

				while ((pcd = mc32_findInstructionUsingLabel(PCL(PCI(pc)->label->pc), pcd)) != NULL)
				{
					//fprintf(stderr,"Used by:\n");
					//pcd->print(stderr,pcd);

					mc32_exchangeLabels(PCL(pbr->pc), pcd);

					pcd = pcd->next;
				}
				pbr = pbr->next;
			}
		}
	}

	for (pc = pb->pcHead; pc; pc = pc->next)
	{

		if (isPCL(pc)) // Label pcode
			pcl = PCL(pc);
		else if (isPCI(pc) && PCI(pc)->label) // pcode instruction with a label
			pcl = PCL(PCI(pc)->label->pc);
		else
			continue;

		//fprintf(stderr," found  A LABEL !!! key = %d, %s\n", pcl->key,pcl->label);

		/* This pCode is a label, so search the pBlock to see if anyone
		* refers to it */

		if ((pcl->key > 0) && (!mc32_findInstructionUsingLabel(pcl, pb->pcHead)))
		{
			/* Couldn't find an instruction that refers to this label
			* So, unlink the pCode label from it's pCode chain
			* and destroy the label */
			//fprintf(stderr," removed  A LABEL !!! key = %d, %s\n", pcl->key,pcl->label);

			DFPRINTF((stderr, " !!! REMOVED A LABEL !!! key = %d, %s\n", pcl->key, pcl->label));
			if (pc->type == PC_LABEL)
			{
				mc32_unlinkpCode(pc);
				mc32_pCodeLabelDestruct(pc);
			}
			else
			{
				mc32_unlinkpCodeFromBranch(pc, PCODE(pcl));
				/*if(pc->label->next == NULL && pc->label->pc == NULL) {
				free(pc->label);
			}*/
			}
		}
	}
}

/*-----------------------------------------------------------------*/
/* mc32_pBlockMergeLabels - remove the pCode labels from the pCode      */
/*                     chain and put them into pBranches that are  */
/*                     associated with the appropriate pCode       */
/*                     instructions.                               */
/*-----------------------------------------------------------------*/
void mc32_pBlockMergeLabels(pBlock *pb)
{
	pBranch *pbr;
	pCode *pc, *pcnext = NULL;

	if (!pb)
		return;

	/* First, Try to remove any unused labels */
	//mc32_pBlockRemoveUnusedLabels(pb);

	/* Now loop through the pBlock and merge the labels with the opcodes */

	pc = pb->pcHead;

	while (pc)
	{
		pCode *pcn = pc->next;

		if (pc->type == PC_LABEL)
		{

			//fprintf(stderr," checking merging label %s\n",PCL(pc)->label);
			//fprintf(stderr,"Checking label key = %d\n",PCL(pc)->key);
			if ((pcnext = mc32_findNextInstruction(pc)))
			{

				// Unlink the pCode label from it's pCode chain
				mc32_unlinkpCode(pc);

				//fprintf(stderr,"Merged label key = %d\n",PCL(pc)->key);
				// And link it into the instruction's pBranch labels. (Note, since
				// it's possible to have multiple labels associated with one instruction
				// we must provide a means to accomodate the additional labels. Thus
				// the labels are placed into the singly-linked list "label" as
				// opposed to being a single member of the pCodeInstruction.)

				//_ALLOC(pbr,sizeof(pBranch));
				pbr = Safe_calloc(1, sizeof(pBranch));
				pbr->pc = pc;
				pbr->next = NULL;

				PCI(pcnext)->label = mc32_pBranchAppend(PCI(pcnext)->label, pbr);
			}
			else
			{
				fprintf(stderr, "WARNING: couldn't associate label %s with an instruction\n", PCL(pc)->label);
			}
		}
		else if (pc->type == PC_CSOURCE)
		{

			/* merge the source line symbolic info into the next instruction */
			if ((pcnext = mc32_findNextInstruction(pc)))
			{

				// Unlink the pCode label from it's pCode chain
				mc32_unlinkpCode(pc);
				PCI(pcnext)->cline = PCCS(pc);
				//fprintf(stderr, "merging CSRC\n");
				//mc32_genericPrint(stderr,pcnext);
			}
		}
		pc = pcn;
	}
	mc32_pBlockRemoveUnusedLabels(pb);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static int mc32_OptimizepCode(char dbName)
{
#define MAX_PASSES 4

	int matches = 0;
	int passes = 0;
	pBlock *pb;

	if (!mc32_the_pFile)
		return 0;

	DFPRINTF((stderr, " Optimizing pCode\n"));

	do
	{
		matches = 0;
		for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		{
			if ('*' == dbName || mc32_getpBlock_dbName(pb) == dbName)
				matches += mc32_OptimizepBlock(pb);
		}
	} while (matches && ++passes < MAX_PASSES);

	return matches;
}

/*-----------------------------------------------------------------*/
/* mc32_popCopyGPR2Bit - copy a pcode operator                          */
/*-----------------------------------------------------------------*/

pCodeOp *mc32_popCopyGPR2Bit(pCodeOp *pc, int bitval)
{
	pCodeOp *pcop;

	pcop = mc32_newpCodeOpBit(pc->name, bitval, 0);

	if (!((pcop->type == PO_LABEL) ||
		  (pcop->type == PO_LITERAL) ||
		  (pcop->type == PO_STR)))
		PCOR(pcop)->r = PCOR(pc)->r; /* This is dangerous... */

	return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc32_pBlockDestruct(pBlock *pb)
{

	if (!pb)
		return;

	free(pb);
}

/*-----------------------------------------------------------------*/
/* void mc32_mergepBlocks(char dbName) - Search for all pBlocks with the*/
/*                                  name dbName and combine them   */
/*                                  into one block                 */
/*-----------------------------------------------------------------*/
static void mc32_mergepBlocks(char dbName)
{

	pBlock *pb, *pbmerged = NULL, *pbn;

	pb = mc32_the_pFile->pbHead;

	//fprintf(stderr," merging blocks named %c\n",dbName);
	while (pb)
	{

		pbn = pb->next;
		//fprintf(stderr,"looking at %c\n",mc32_getpBlock_dbName(pb));
		if (mc32_getpBlock_dbName(pb) == dbName)
		{

			//fprintf(stderr," merged block %c\n",dbName);

			if (!pbmerged)
			{
				pbmerged = pb;
			}
			else
			{
				mc32_addpCode2pBlock(pbmerged, pb->pcHead);
				/* mc32_addpCode2pBlock doesn't handle the tail: */
				pbmerged->pcTail = pb->pcTail;

				pb->prev->next = pbn;
				if (pbn)
					pbn->prev = pb->prev;

				mc32_pBlockDestruct(pb);
			}
			//mc32_printpBlock(stderr, pbmerged);
		}
		pb = pbn;
	}
}

/*-----------------------------------------------------------------*/
/* mc32_AnalyzeFlow - Examine the flow of the code and optimize         */
/*                                                                 */
/* level 0 == minimal optimization                                 */
/*   optimize registers that are used only by two instructions     */
/* level 1 == maximal optimization                                 */
/*   optimize by looking at pairs of instructions that use the     */
/*   register.                                                     */
/*-----------------------------------------------------------------*/

static void mc32_AnalyzeFlow(int level)
{
	static int times_called = 0;

	pBlock *pb;

	if (!mc32_the_pFile)
		return;

	/* if this is not the first time this function has been called,
       then clean up old flow information */
	if (times_called++)
	{
		for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
			mc32_unBuildFlow(pb);

		mc32_RegsUnMapLiveRanges();
	}

	mc32_GpcFlowSeq = 1;

	/* Phase 2 - Flow Analysis - Register Banking
     *
     * In this phase, the individual flow blocks are examined
     * and register banking is fixed.
     */

	//for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	//mc32_FixRegisterBanking(pb);

	/* Phase 2 - Flow Analysis
     *
     * In this phase, the pCode is partition into pCodeFlow
     * blocks. The flow blocks mark the points where a continuous
     * stream of instructions changes flow (e.g. because of
     * a call or goto or whatever).
     */

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		mc32_BuildFlow(pb);

	/* Phase 2 - Flow Analysis - linking flow blocks
     *
     * In this phase, the individual flow blocks are examined
     * to determine their order of excution.
     */

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		mc32_LinkFlow(pb);

	/* Phase 3 - Flow Analysis - Flow Tree
     *
     * In this phase, the individual flow blocks are examined
     * to determine their order of excution.
     */

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		mc32_BuildFlowTree(pb);

	/* Phase x - Flow Analysis - Used Banks
     *
     * In this phase, the individual flow blocks are examined
     * to determine the Register Banks they use
     */

	//  for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	//      FixBankFlow(pb);

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		mc32_pCodeRegMapLiveRanges(pb);

	mc32_RemoveUnusedRegisters();

	//  for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	mc32_pCodeRegOptimizeRegUsage(level);

	mc32_OptimizepCode('*');

	/*
        for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
        DumpFlow(pb);
     */
	/* debug stuff */
	/*
    for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next) {
        pCode *pcflow;
        for( pcflow = mc32_findNextpCode(pb->pcHead, PC_FLOW);
            (pcflow = mc32_findNextpCode(pcflow, PC_FLOW)) != NULL;
            pcflow = pcflow->next) {

                FillFlow(PCFL(pcflow));
            }
        }
     */
	/*
    for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next) {
        pCode *pcflow;
        for( pcflow = mc32_findNextpCode(pb->pcHead, PC_FLOW);
            (pcflow = mc32_findNextpCode(pcflow, PC_FLOW)) != NULL;
            pcflow = pcflow->next) {

                FlowStats(PCFL(pcflow));
            }
        }
     */
}

/*-----------------------------------------------------------------*/
/* mc32_AnalyzeBanking - Called after the memory addresses have been    */
/*                  assigned to the registers.                     */
/*                                                                 */
/*-----------------------------------------------------------------*/

void mc32_AnalyzeBanking(void)
{
	pBlock *pb;

	if (!mc32_picIsInitialized())
	{
		werror(E_FILE_OPEN_ERR, "no memory size is known for this processor");
		exit(1);
	}

	if (!mc32_the_pFile)
		return;

	/* Phase x - Flow Analysis - Used Banks
	*
	* In this phase, the individual flow blocks are examined
	* to determine the Register Banks they use
	*/

	mc32_AnalyzeFlow(0);
	mc32_AnalyzeFlow(1);

	// zwr 1.0.0
	// for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	// 	mc32_FixRegisterBanking(pb);

	mc32_AnalyzeFlow(0);
	mc32_AnalyzeFlow(1);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static DEFSETFUNC(resetrIdx)
{
	reg_info *r = (reg_info *)item;
	if (!r->isFixed)
	{
		r->rIdx = 0;
	}

	return 0;
}

/*-----------------------------------------------------------------*/
/* InitRegReuse - Initialises variables for code analyzer          */
/*-----------------------------------------------------------------*/
static void mc32_InitReuseReg(void)
{
	/* Find end of statically allocated variables for start idx */
	/* Start from begining of GPR. Note may not be 0x20 on some PICs */
	/* XXX: Avoid clashes with fixed registers, start late. */
	unsigned maxIdx = 0x1000;
	reg_info *r;
	for (r = setFirstItem(mc32_dynDirectRegs); r; r = setNextItem(mc32_dynDirectRegs))
	{
		if (r->type != REG_SFR)
		{
			maxIdx += r->size; /* Increment for all statically allocated variables */
		}
	}
	mc32_peakIdx = maxIdx;
	applyToSet(mc32_dynAllocRegs, resetrIdx); /* Reset all rIdx to zero. */
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static unsigned
mc32_register_reassign(pBlock *pb, unsigned startIdx, unsigned level)
{
	pCode *pc;
	unsigned temp;
	unsigned idx = startIdx;

	/* check recursion */
	pc = setFirstItem(pb->function_entries);
	if (!pc)
		return idx;

	if (pb->visited)
	{
		set *regset;
		/* TODO: Recursion detection missing, should emit a warning as recursive code will fail. */

		//  Find the highest rIdx used by this function for return.
		regset = pb->tregisters;
		idx = 0;
		while (regset)
		{
			temp = ((reg_info *)regset->item)->rIdx;
			if (temp > idx)
				idx = temp;
			regset = regset->next;
		} // while
		DFPRINTF((stderr,
				  "%*s(%u) function \"%s\" already visited: max idx = %04x\n",
				  4 * level, "", level, PCF(pc)->fname, idx));
		return idx + 1;
	} // if

	/*
   * We now traverse the call tree depth first, assigning indices > startIdx
   * to the registers of all called functions before assigning indices to
   * the registers of the calling function, starting with one greater than
   * the max. index used by any child function.
   * This approach guarantees that, if f calls g, all registers of f have
   * greater indices than those of g (also holds transitively).
   *
   * XXX: If a function f calls a function g in a different module,
   *      we should handle the case that g could call a function h
   *      in f's module.
   *      The consequence of this is that even though f and h might
   *      share registers (they do not call each other locally) when
   *      looking only at f's module, they actually must not do so!
   *
   *      For a non-static function f, let ES(f) be the set of functions
   *      (including f) that can only be reached via f in the module-local
   *      call graph (ES(f) will hence be a subgraph).
   *      Let further REG(ES(f)) be the set of registers assigned to
   *      functions in ES(f).
   *      Then we should make sure that REG(ES(f)) and REG(ES(g)) are
   *      disjoint for all non-static functions f and g.
   *
   *      Unfortunately, determining the sets ES(f) is non-trivial,
   *      so we ignore this problem and declare all modules non-reentrant.
   *      This is a bug.
   */
	pb->visited = 1;

	DFPRINTF((stderr,
			  "%*s(%u) reassigning registers for functions called by \"%s\":base idx = %04x\n",
			  4 * level, "", level, PCF(pc)->fname, startIdx));

	for (pc = setFirstItem(pb->function_calls); pc; pc = setNextItem(pb->function_calls))
	{
		if (pc->type == PC_OPCODE && PCI(pc)->op == POC_CALL)
		{
			char *dest = mc32_get_op_from_instruction(PCI(pc));
			pCode *pcn = mc32_findFunction(dest);

			if (pcn)
			{
				/*
               * Reassign the registers of all called functions and record
               * the max. index I used by any child function --> I+1 will be
               * the first index available to this function.
               * (Problem shown with regression test src/regression/sub2.c)
               */
				unsigned childsMaxIdx;
				childsMaxIdx = mc32_register_reassign(pcn->pb, startIdx, level + 1);
				if (childsMaxIdx > idx)
					idx = childsMaxIdx;
			} // if
		}	 // if
	}		  // for

	pc = setFirstItem(pb->function_entries);
	DFPRINTF((stderr,
			  "%*s(%u) reassigning registers for function \"%s\":idx = %04x\n",
			  4 * level, "", level, PCF(pc)->fname, idx));

	if (pb->tregisters)
	{
		reg_info *r;
		for (r = setFirstItem(pb->tregisters); r; r = setNextItem(pb->tregisters))
		{
			if ((r->type == REG_GPR) && (!r->isFixed) && (r->rIdx < (int)idx))
			{
				char s[20];
				set *regset;
				/*
               * Make sure, idx is not yet used in this routine ...
               * XXX: This should no longer be required, as all functions
               *      are reassigned at most once ...
               */
				do
				{
					regset = pb->tregisters;
					// do not touch s->curr ==> outer loop!
					while (regset && ((reg_info *)regset->item)->rIdx != idx)
						regset = regset->next;
					if (regset)
						idx++;
				} while (regset);
				r->rIdx = idx++;
				if (mc32_peakIdx < idx)
					mc32_peakIdx = idx;
				sprintf(s, "r0x%02X", r->rIdx);
				DFPRINTF((stderr,
						  "%*s(%u) reassigning register %p \"%s\" to \"%s\"\n",
						  4 * level, "", level, r, r->name, s));
				free(r->name);
				r->name = Safe_strdup(s);
			} // if
		}	 // for
	}		  // if

	/* return lowest index available for caller's registers */
	return idx;
}

/*------------------------------------------------------------------*/
/* mc32_ReuseReg were call tree permits                                  */
/*                                                                  */
/*  Re-allocate the GPR for optimum reuse for a given pblock        */
/*  eg  if a function m() calls function f1() and f2(), where f1    */
/*  allocates a local variable vf1 and f2 allocates a local         */
/*  variable vf2. Then providing f1 and f2 do not call each other   */
/*  they may share the same general purpose registers for vf1 and   */
/*  vf2.                                                            */
/*  This is done by first setting the the regs rIdx to start after  */
/*  all the global variables, then walking through the call tree    */
/*  renaming the registers to match their new idx and incrementng   */
/*  it as it goes. If a function has already been called it will    */
/*  only rename the registers if it has already used up those       */
/*  registers ie rIdx of the function's registers is lower than the */
/*  current rIdx. That way the register will not be reused while    */
/*  still being used by an eariler function call.                   */
/*                                                                  */
/*  Note for this to work the functions need to be declared static. */
/*                                                                  */
/*------------------------------------------------------------------*/
void mc32_ReuseReg(void)
{
	pBlock *pb;

	if (options.noOverlay || !mc32_the_pFile)
		return;

	mc32_InitReuseReg();

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	{
		/* Non static functions can be called from other modules,
       * so their registers must reassign */
		if (pb->function_entries && (PCF(setFirstItem(pb->function_entries))->isPublic || !pb->visited))
		{
			mc32_register_reassign(pb, mc32_peakIdx, 0);
		} // if
	}	 // for
}

/*-----------------------------------------------------------------*/
/* mc32_buildCallTree - look at the flow and extract all of the calls   */
/*                                                                 */
/*-----------------------------------------------------------------*/

static void mc32_buildCallTree(void)
{
	pBranch *pbr;
	pBlock *pb;
	pCode *pc;

	if (!mc32_the_pFile)
		return;

	/* Now build the call tree.
           First we examine all of the pCodes for functions.
           Keep in mind that the function boundaries coincide
           with pBlock boundaries.

           The algorithm goes something like this:
           We have two nested loops. The outer loop iterates
           through all of the pBlocks/functions. The inner
           loop iterates through all of the pCodes for
           a given pBlock. When we begin iterating through
           a pBlock, the variable pc_fstart, pCode of the start
           of a function, is cleared. We then search for pCodes
           of type PC_FUNCTION. When one is encountered, we
           initialize pc_fstart to this and at the same time
           associate a new pBranch object that signifies a
           branch entry. If a return is found, then this signifies
           a function exit point. We'll link the pCodes of these
           returns to the matching pc_fstart.

           When we're done, a doubly linked list of pBranches
           will exist. The head of this list is stored in
           `mc32_the_pFile', which is the meta structure for all
           of the pCode. Look at the printCallTree function
           on how the pBranches are linked together.
         */

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	{
		pCode *pc_fstart = NULL;
		for (pc = pb->pcHead; pc; pc = pc->next)
		{
			if (isPCF(pc))
			{
				pCodeFunction *pcf = PCF(pc);
				if (pcf->fname)
				{

					if (STRCASECMP(pcf->fname, "_main") == 0)
					{
						//fprintf(stderr," found main \n");
						pb->cmemmap = NULL; /* FIXME do we need to free ? */
						pb->dbName = 'M';
					}

					pbr = Safe_calloc(1, sizeof(pBranch));
					pbr->pc = pc_fstart = pc;
					pbr->next = NULL;

					mc32_the_pFile->functions = mc32_pBranchAppend(mc32_the_pFile->functions, pbr);

					// Here's a better way of doing the same:
					addSet(&pb->function_entries, pc);
				}
				else
				{
					// Found an exit point in a function, e.g. return
					// (Note, there may be more than one return per function)
					if (pc_fstart)
						mc32_pBranchLink(PCF(pc_fstart), pcf);

					addSet(&pb->function_exits, pc);
				}
			}
			else if (isCALL(pc))
			{
				addSet(&pb->function_calls, pc);
			}
		}
	}
}

/*-----------------------------------------------------------------*/
/* mc32_AnalyzepCode - parse the pCode that has been generated and form */
/*                all of the logical connections.                  */
/*                                                                 */
/* Essentially what's done here is that the pCode flow is          */
/* determined.                                                     */
/*-----------------------------------------------------------------*/

void mc32_AnalyzepCode(char dbName)
{
	pBlock *pb;
	int i, changes;

	if (!mc32_the_pFile)
		return;

	mc32_mergepBlocks('D');

	/* Phase 1 - Register allocation and peep hole optimization
	*
	* The first part of the analysis is to determine the registers
	* that are used in the pCode. Once that is done, the peep rules
	* are applied to the code. We continue to loop until no more
	* peep rule optimizations are found (or until we exceed the
	* MAX_PASSES threshold). 
	*
	* When done, the required registers will be determined.
	*
	*/
	i = 0;
	do
	{

		DFPRINTF((stderr, " Analyzing pCode: PASS #%d\n", i + 1));

		/* First, merge the labels with the instructions */
		for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		{
			if ('*' == dbName || mc32_getpBlock_dbName(pb) == dbName)
			{

				DFPRINTF((stderr, " analyze and merging block %c\n", dbName));
				mc32_pBlockMergeLabels(pb);
				mc32_AnalyzepBlock(pb);
			}
			else
			{
				DFPRINTF((stderr, " skipping block analysis dbName=%c blockname=%c\n", dbName, mc32_getpBlock_dbName(pb)));
			}
		}

		changes = mc32_OptimizepCode(dbName);

	} while (changes && (i++ < MAX_PASSES));

	mc32_buildCallTree();
}

/*-----------------------------------------------------------------*/
/* mc32_findFunction - Search for a function by name (given the name)   */
/*                in the set of all functions that are in a pBlock */
/* (note - I expect this to change because I'm planning to limit   */
/*  pBlock's to just one function declaration                      */
/*-----------------------------------------------------------------*/
static pCode *mc32_findFunction(char *fname)
{
	pBlock *pb;
	pCode *pc;
	if (!fname)
		return NULL;

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	{

		pc = setFirstItem(pb->function_entries);
		while (pc)
		{

			if ((pc->type == PC_FUNCTION) &&
				(PCF(pc)->fname) &&
				(strcmp(fname, PCF(pc)->fname) == 0))
				return pc;

			pc = setNextItem(pb->function_entries);
		}
	}
	return NULL;
}

static void mc32_pBlockStats(FILE *of, pBlock *pb)
{

	pCode *pc;
	reg_info *r;

	fprintf(of, ";***\n;  pBlock Stats: dbName = %c\n;***\n", mc32_getpBlock_dbName(pb));

	// for now just print the first element of each set
	pc = setFirstItem(pb->function_entries);
	if (pc)
	{
		fprintf(of, ";entry:  ");
		pc->print(of, pc);
	}
	pc = setFirstItem(pb->function_exits);
	if (pc)
	{
		fprintf(of, ";has an exit\n");
		//pc->print(of,pc);
	}

	pc = setFirstItem(pb->function_calls);
	if (pc)
	{
		fprintf(of, ";functions called:\n");

		while (pc)
		{
			if (pc->type == PC_OPCODE && PCI(pc)->op == POC_CALL)
			{
				fprintf(of, ";   %s\n", mc32_get_op_from_instruction(PCI(pc)));
			}
			pc = setNextItem(pb->function_calls);
		}
	}

	r = setFirstItem(pb->tregisters);
	if (r)
	{
		int n = elementsInSet(pb->tregisters);

		fprintf(of, ";%d compiler assigned register%c:\n", n, ((n != 1) ? 's' : ' '));

		while (r)
		{
			fprintf(of, ";   %s\n", r->name);
			r = setNextItem(pb->tregisters);
		}
	}
}

#if 0
/*-----------------------------------------------------------------*/
/* printCallTree - writes the call tree to a file                  */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void pct2(FILE *of,pBlock *pb,int indent)
{
	pCode *pc,*pcn;
	int i;
	//  set *registersInCallPath = NULL;
	
	if(!of)
		return;
	
	if(indent > 10)
		return; //recursion ?
	
	pc = setFirstItem(pb->function_entries);
	
	if(!pc)
		return;
	
	pb->visited = 0;
	
	for(i=0;i<indent;i++)   // Indentation
		fputc(' ',of);
	
	if(pc->type == PC_FUNCTION)
		fprintf(of,"%s\n",PCF(pc)->fname);
	else
		return;  // ???
	
	
	pc = setFirstItem(pb->function_calls);
	for( ; pc; pc = setNextItem(pb->function_calls)) {
		
		if(pc->type == PC_OPCODE && PCI(pc)->op == POC_CALL) {
			char *dest = mc32_get_op_from_instruction(PCI(pc));
			
			pcn = mc32_findFunction(dest);
			if(pcn) 
				pct2(of,pcn->pb,indent+1);
		} else
			fprintf(of,"BUG? pCode isn't a POC_CALL %d\n",__LINE__);
		
	}
	
	
}
#endif

#if 0
/*-----------------------------------------------------------------*/
/* ispCodeFunction - returns true if *pc is the pCode of a         */
/*                   function                                      */
/*-----------------------------------------------------------------*/
static bool ispCodeFunction(pCode *pc)
{

	if(pc && pc->type == PC_FUNCTION && PCF(pc)->fname)
		return 1;

	return 0;
}

/*-----------------------------------------------------------------*/
/* printCallTree - writes the call tree to a file                  */
/*                                                                 */
/*-----------------------------------------------------------------*/

static void printCallTree(FILE *of)
{
	pBranch *pbr;
	pBlock  *pb;
	pCode   *pc;
	
	if(!mc32_the_pFile)
		return;
	
	if(!of)
		of = stderr;
	
	fprintf(of, "\npBlock statistics\n");
	for(pb = mc32_the_pFile->pbHead; pb;  pb = pb->next )
		mc32_pBlockStats(of,pb);
	
	
	
	fprintf(of,"Call Tree\n");
	pbr = mc32_the_pFile->functions;
	while(pbr) {
		if(pbr->pc) {
			pc = pbr->pc;
			if(!ispCodeFunction(pc))
				fprintf(of,"bug in call tree");
			
			
			fprintf(of,"Function: %s\n", PCF(pc)->fname);
			
			while(pc->next && !ispCodeFunction(pc->next)) {
				pc = pc->next;
				if(pc->type == PC_OPCODE && PCI(pc)->op == POC_CALL)
					fprintf(of,"\t%s\n",mc32_get_op_from_instruction(PCI(pc)));
			}
		}
		
		pbr = pbr->next;
	}
	
	
	fprintf(of,"\n**************\n\na better call tree\n");
	for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next) {
		if(pb->visited)
			pct2(of,pb,0);
	}
	
	for(pb = mc32_the_pFile->pbHead; pb; pb = pb->next) {
		fprintf(of,"block dbname: %c\n", mc32_getpBlock_dbName(pb));
	}
}
#endif

/*-----------------------------------------------------------------*/
/*                                                                 */
/*-----------------------------------------------------------------*/

static void mc32_InlineFunction(pBlock *pb)
{
	pCode *pc;
	pCode *pc_call;

	if (!pb)
		return;

	pc = setFirstItem(pb->function_calls);

	for (; pc; pc = setNextItem(pb->function_calls))
	{

		if (isCALL(pc))
		{
			pCode *pcn = mc32_findFunction(mc32_get_op_from_instruction(PCI(pc)));
			pCode *pcp = pc->prev;
			pCode *pct;
			pCode *pce;

			pBranch *pbr;

			if (pcn && isPCF(pcn) && (PCF(pcn)->ncalled == 1) && !PCF(pcn)->isPublic && (pcp && (isPCI_BITSKIP(pcp) || !isPCI_SKIP(pcp))))
			{ /* Bit skips can be inverted other skips can not */

				mc32_InlineFunction(pcn->pb);

				/*
				At this point, *pc points to a CALL mnemonic, and
				*pcn points to the function that is being called.
				
				  To in-line this call, we need to remove the CALL
				  and RETURN(s), and link the function pCode in with
				  the CALLee pCode.
				  
				*/

				pc_call = pc;

				/* Check if previous instruction was a bit skip */
				if (isPCI_BITSKIP(pcp))
				{
					pCodeLabel *pcl;
					/* Invert skip instruction and add a goto */
					PCI(pcp)->op = (PCI(pcp)->op == POC_BTFSS) ? POC_BTFSC : POC_BTFSS;

					if (isPCL(pc_call->next))
					{ // Label pcode
						pcl = PCL(pc_call->next);
					}
					else if (isPCI(pc_call->next) && PCI(pc_call->next)->label)
					{ // pcode instruction with a label
						pcl = PCL(PCI(pc_call->next)->label->pc);
					}
					else
					{
						pcl = PCL(mc32_newpCodeLabel(NULL, newiTempLabel(NULL)->key + 100));
						PCI(pc_call->next)->label->pc = (struct pCode *)pcl;
					}
					mc32_pCodeInsertAfter(pcp, mc32_newpCode(POC_GOTO, mc32_newpCodeOp(pcl->label, PO_STR)));
				}

				/* remove callee pBlock from the pBlock linked list */
				mc32_removepBlock(pcn->pb);

				pce = pcn;
				while (pce)
				{
					pce->pb = pb;
					pce = pce->next;
				}

				/* Remove the Function pCode */
				pct = mc32_findNextInstruction(pcn->next);

				/* Link the function with the callee */
				if (pcp)
					pcp->next = pcn->next;
				pcn->next->prev = pcp;

				/* Convert the function name into a label */

				pbr = Safe_calloc(1, sizeof(pBranch));
				pbr->pc = mc32_newpCodeLabel(PCF(pcn)->fname, -1);
				pbr->next = NULL;
				PCI(pct)->label = mc32_pBranchAppend(PCI(pct)->label, pbr);
				PCI(pct)->label = mc32_pBranchAppend(PCI(pct)->label, PCI(pc_call)->label);

				/* turn all of the return's except the last into goto's */
				/* check case for 2 instruction pBlocks */
				pce = mc32_findNextInstruction(pcn->next);
				while (pce)
				{
					pCode *pce_next = mc32_findNextInstruction(pce->next);

					if (pce_next == NULL)
					{
						/* found the last return */
						pCode *pc_call_next = mc32_findNextInstruction(pc_call->next);

						//fprintf(stderr,"found last return\n");
						//pce->print(stderr,pce);
						pce->prev->next = pc_call->next;
						pc_call->next->prev = pce->prev;
						PCI(pc_call_next)->label = mc32_pBranchAppend(PCI(pc_call_next)->label,
																 PCI(pce)->label);
					}

					pce = pce_next;
				}
			}
		}
		else
			fprintf(stderr, "BUG? pCode isn't a POC_CALL %d\n", __LINE__);
	}
}

/*-----------------------------------------------------------------*/
/*                                                                 */
/*-----------------------------------------------------------------*/

void mc32_InlinepCode(void)
{

	pBlock *pb;
	pCode *pc;

	if (!mc32_the_pFile)
		return;

	if (!mc32_functionInlining)
		return;

	/* Loop through all of the function definitions and count the
	* number of times each one is called */
	//fprintf(stderr,"inlining %d\n",__LINE__);

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
	{

		pc = setFirstItem(pb->function_calls);

		for (; pc; pc = setNextItem(pb->function_calls))
		{

			if (isCALL(pc))
			{
				pCode *pcn = mc32_findFunction(mc32_get_op_from_instruction(PCI(pc)));
				if (pcn && isPCF(pcn))
				{
					PCF(pcn)->ncalled++;
				}
			}
			else
				fprintf(stderr, "BUG? pCode isn't a POC_CALL %d\n", __LINE__);
		}
	}

	//fprintf(stderr,"inlining %d\n",__LINE__);

	/* Now, Loop through the function definitions again, but this
	* time inline those functions that have only been called once. */

	mc32_InlineFunction(mc32_the_pFile->pbHead);
	//fprintf(stderr,"inlining %d\n",__LINE__);

	for (pb = mc32_the_pFile->pbHead; pb; pb = pb->next)
		mc32_unBuildFlow(pb);
}
