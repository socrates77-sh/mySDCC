/*-------------------------------------------------------------------------

  SDCCralloc.h - header file register allocation

                Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)
    PIC port   - T. Scott Dattalo scott@dattalo.com (2000)

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
   
   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!  
-------------------------------------------------------------------------*/

#ifndef SDCCRALLOC_H
#define SDCCRALLOC_H 1

#include "common.h"

#include "pcoderegs.h"

enum
{
  REG_PTR = 1,
  REG_GPR,
  REG_CND,
  REG_SFR,
  REG_STK,
  REG_TMP
};

/* definition for the registers */
typedef struct reg_info
{
  short type;    /* can have value 
                * REG_GPR, REG_PTR or REG_CND 
                * This like the "meta-type" */
  short pc_type; /* pcode type */
  short rIdx;    /* index into register table */
  char *name;    /* name */

  unsigned isFree : 1;        /* is currently unassigned  */
  unsigned wasUsed : 1;       /* becomes true if register has been used */
  unsigned isFixed : 1;       /* True if address can't change */
  unsigned isMapped : 1;      /* The Register's address has been mapped to physical RAM */
  unsigned isBitField : 1;    /* True if reg is type bit OR is holder for several bits */
  unsigned isEmitted : 1;     /* True if the reg has been written to a .asm file */
  unsigned isPublic : 1;      /* True if the reg is not static and can be modified in another module (ie a another c or asm file) */
  unsigned isExtern : 1;      /* True if the reg is in another module */
  unsigned address;           /* reg's address if isFixed | isMapped is true */
  unsigned size;              /* 0 for byte, 1 for int, 4 for long */
  unsigned alias;             /* Alias mask if register appears in multiple banks */
  struct reg_info *reg_alias; /* If more than one register share the same address 
                               * then they'll point to each other. (primarily for bits)*/
  pCodeRegLives reglives;     /* live range mapping */
} reg_info;
extern reg_info regspic14[];
extern int mc35_Gstack_base_addr;

/*
  As registers are created, they're added to a set (based on the
  register type). Here are the sets of registers that are supported
  in the PIC port:
*/
extern set *mc35_dynAllocRegs;
extern set *mc35_dynStackRegs;
extern set *mc35_dynProcessorRegs;
extern set *mc35_dynDirectRegs;
extern set *mc35_dynDirectBitRegs;
extern set *mc35_dynInternalRegs;

//zwr 1.0.0
typedef struct Q_ValList
{
  char *funname;
  symbol *firstval;
  symbol *val;
  set *next;
  set *firstItem;
} Q_ValList;

void mc35_initStack(int base_address, int size, int shared);
reg_info *mc35_pic14_regWithIdx(int);
reg_info *mc35_dirregWithName(char *name);
void mc35_assignRegisters(ebbIndex *ebbi);
reg_info *mc35_findFreeReg(short type);
reg_info *mc35_allocWithIdx(int idx);
reg_info *mc35_typeRegWithIdx(int idx, int type, int fixed);
reg_info *mc35_regFindWithName(const char *name);

void mc35_debugLogClose(void);
void mc35_writeUsedRegs(FILE *of);

reg_info *mc35_allocDirReg(operand *op);
reg_info *mc35_allocInternalRegister(int rIdx, char *name, PIC_OPTYPE po_type, int alias);
reg_info *mc35_allocProcessorRegister(int rIdx, char *name, short po_type, int alias);
reg_info *mc35_allocRegByName(char *name, int size);
reg_info *mc35_allocNewDirReg(sym_link *symlnk, const char *name);

/* Define register address that are constant across PIC family */
#define IDX_INDF 0
#define IDX_INDF0 0
#define IDX_TMR0 1
#define IDX_PCL 2
#define IDX_STATUS 3
#define IDX_FSR 4
#define IDX_FSR0L 4
#define IDX_FSR0H 5
#define IDX_PCLATH 0x0a
#define IDX_INTCON 0x0b

#define IDX_KZ 0x7fff /* Known zero - actually just a general purpose reg. */
#define IDX_WSAVE 0x7ffe
#define IDX_SSAVE 0x7ffd
#define IDX_PSAVE 0x7ffc

#define pic14_nRegs 128

#endif