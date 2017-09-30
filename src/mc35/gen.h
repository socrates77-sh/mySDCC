/*-------------------------------------------------------------------------
  SDCCgen51.h - header file for code generation for 8051

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

#ifndef SDCCGENPIC14_H
#define SDCCGENPIC14_H

#include "common.h"

#include "main.h"
#include "pcode.h"
#include "ralloc.h"

#define FENTRY                                                                             \
        do                                                                                 \
        {                                                                                  \
                /*fprintf (stderr, "%s:%u:%s: *{*\n", __FILE__, __LINE__, __FUNCTION__);*/ \
                if (options.debug || debug_verbose)                                        \
                {                                                                          \
                        mc35_emitpComment("; %s:%u:%s *{*", __FILE__, __LINE__, __FUNCTION__);  \
                }                                                                          \
        } while (0)
#define FEXIT                                                                              \
        do                                                                                 \
        {                                                                                  \
                /*fprintf (stderr, "%s:%u:%s: *}*\n", __FILE__, __LINE__, __FUNCTION__);*/ \
                if (options.debug || debug.verbose)                                        \
                {                                                                          \
                        mc35_emitpComment("; %s:%u:%s *}*", __FILE__, __LINE__, __FUNCTION__);  \
                }                                                                          \
        } while (0)

enum
{
        AOP_LIT = 1,
        AOP_REG,
        AOP_DIR,
        AOP_STK,
        AOP_IMMD,
        AOP_STR,
        AOP_CRY,
        AOP_PCODE

};

/* type asmop : a homogenised type for
   all the different spaces an operand can be
   in */
typedef struct asmop
{

        short type;         /* can have values
                  AOP_LIT    -  operand is a literal value
                  AOP_REG    -  is in registers
                  AOP_DIR    -  direct just a name
                  AOP_STK    -  should be pushed on stack this
                  can happen only for the result
                  AOP_IMMD   -  immediate value for eg. remateriazable
                  AOP_CRY    -  carry contains the value of this
                  AOP_STR    -  array of strings
               */
        short coff;         /* current offset */
        short size;         /* total size */
        unsigned code : 1;  /* is in Code space */
        unsigned paged : 1; /* in paged memory  */
        unsigned freed : 1; /* already freed    */
        union {
                value *aop_lit;       /* if literal */
                reg_info *aop_reg[4]; /* array of registers */
                char *aop_dir;        /* if direct  */
                reg_info *aop_ptr;    /* either -> to r0 or r1 */
                char *aop_immd;       /* if immediate others are implied */
                int aop_stk;          /* stack offset when AOP_STK */
                char *aop_str[4];     /* just a string array containing the location */
                pCodeOp *pcop;
        } aopu;
} asmop;

extern unsigned mc35_fReturnSizePic;

#define AOP(op) op->aop
#define AOP_TYPE(op) AOP(op)->type
#define AOP_SIZE(op) AOP(op)->size

#define AOP_NEEDSACC(x) (AOP(x) && (AOP_TYPE(x) == AOP_CRY || AOP(x)->paged))

#define RESULTONSTACK(x)                      \
        (IC_RESULT(x) && IC_RESULT(x)->aop && \
         IC_RESULT(x)->aop->type == AOP_STK)

#define MOVA(x)                                 \
        if (strcmp(x, "a") && strcmp(x, "acc")) \
                mc35_pic14_emitcode(";XXX mov", "a,%s  %s,%d", x, __FILE__, __LINE__);
#define CLRC mc35_pic14_emitcode(";XXX clr", "c %s,%d", __FILE__, __LINE__);

#define LSB 0
#define MSB16 1
#define MSB24 2
#define MSB32 3

/*-----------------------------------------------------------------*/
/* Macros for emitting skip instructions                           */
/*-----------------------------------------------------------------*/

#define mc35_emitSKPC mc35_emitpcode(POC_BTFSS, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_C_BIT))
#define mc35_emitSKPNC mc35_emitpcode(POC_BTFSC, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_C_BIT))
#define mc35_emitSKPZ mc35_emitpcode(POC_BTFSS, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_Z_BIT))
#define mc35_emitSKPNZ mc35_emitpcode(POC_BTFSC, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_Z_BIT))
#define mc35_emitSKPDC mc35_emitpcode(POC_BTFSS, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_DC_BIT))
#define mc35_emitSKPNDC mc35_emitpcode(POC_BTFSC, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_DC_BIT))
#define mc35_emitCLRZ mc35_emitpcode(POC_BCF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_Z_BIT))
#define mc35_emitCLRC mc35_emitpcode(POC_BCF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_C_BIT))
#define mc35_emitCLRDC mc35_emitpcode(POC_BCF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_DC_BIT))
#define mc35_emitCLRIRP mc35_emitpcode(POC_BCF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_IRP_BIT))
#define mc35_emitSETZ mc35_emitpcode(POC_BSF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_Z_BIT))
#define mc35_emitSETC mc35_emitpcode(POC_BSF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_C_BIT))
#define mc35_emitSETDC mc35_emitpcode(POC_BSF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_DC_BIT))
#define mc35_emitSETIRP mc35_emitpcode(POC_BSF, mc35_popCopyGPR2Bit(PCOP(&mc35_pc_status), PIC_IRP_BIT))

// zwr 1.0.0
void mc35_emitpcodeNULLop(PIC_OPCODE poc);
int mc35_getDataSize(operand *op);
void mc35_emitpcode_real(PIC_OPCODE poc, pCodeOp *pcop);
#define mc35_emitpcode(poc, pcop)                                                             \
        do                                                                               \
        {                                                                                \
                if (options.debug || debug_verbose)                                      \
                {                                                                        \
                        mc35_emitpComment(" >>> %s:%d:%s", __FILE__, __LINE__, __FUNCTION__); \
                }                                                                        \
                mc35_emitpcode_real(poc, pcop);                                               \
        } while (0)
void mc35_emitpComment(const char *fmt, ...);
void mc35_emitpLabel(int key);
void mc35_pic14_emitcode(char *inst, char *fmt, ...);
void DEBUGmc35_pic14_emitcode(char *inst, char *fmt, ...);
void mc35_emitDebuggerSymbol(const char *);
bool mc35_sameRegs(asmop *aop1, asmop *aop2);
char *mc35_aopGet(asmop *aop, int offset, bool bit16, bool dname);
void DEBUGmc35_mc35_AopType(int line_no, operand *left, operand *right, operand *result);
void mc35_genpic14Code(iCode *lic);

pCodeOp *mc35_popGet(asmop *aop, int offset); //, bool bit16, bool dname);
pCodeOp *mc35_popGetAddr(asmop *aop, int offset, int index);
pCodeOp *mc35_popGetExternal(char *str, int isReg);
pCodeOp *mc35_popGetLabel(unsigned int key);
pCodeOp *mc35_popGetLit(unsigned int lit);

void mc35_aopPut(asmop *aop, char *s, int offset);
void mc35_outAcc(operand *result);
void mc35_aopOp(operand *op, iCode *ic, bool result);
void mc35_freeAsmop(operand *op, asmop *aaop, iCode *ic, bool pop);
void mc35_mov2w(asmop *aop, int offset);
int mc35_op_isLitLike(operand *op);

/*
 * From genarith.c:
 */
const char *mc35_AopType(short type);
const char *mc35_pCodeOpType(pCodeOp *pcop);
void mc35_genPlus(iCode *ic);
void mc35_addSign(operand *result, int offset, int sign);
void mc35_genMinus(iCode *ic);

#endif
