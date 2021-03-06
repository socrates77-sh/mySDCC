/*-------------------------------------------------------------------------
  gen.c - source file for code generation for pic

  Copyright (C) 1998, Sandeep Dutta . sandeep.dutta@usa.net
  Copyright (C) 1999, Jean-Louis VERN.jlvern@writeme.com
  Bug Fixes  -  Wojciech Stryjewski  wstryj1@tiger.lsu.edu (1999 v2.1.9a)
  PIC port:
  Copyright (C) 2000, Scott Dattalo scott@dattalo.com
  Copyright (C) 2005, Raphael Neider <rneider AT web.de>

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
/*
  Notes:
  000123 mlh  Moved aopLiteral to SDCCglue.c to help the split
              Made everything static
*/

/*
 * This is the down and dirty file with all kinds of
 * kludgy & hacky stuff. This is what it is all about
 * CODE GENERATION for a specific MCU . some of the
 * routines may be reusable, will have to see.
 */

#include "device.h"
#include "gen.h"
#include "glue.h"
#include "dbuf_string.h"
#include "ralloc.h" // zwr 1.0.0

/*
 * Imports
 */
extern struct dbuf_s *codeOutBuf;
extern set *externs;

// zwr 2.0.0
static MC35_device *mc35_pic = NULL;

// zwr 1.0.0
extern struct QValList *mc35_ValList;
extern struct dbuf_s *ValLog;
extern void SaveAllocInfo(symbol *, QValList *);

// zwr 2.0.0
static pCodeOp *mc35_popGetImmd(const char *name, unsigned int offset, int index, int is_func);
static pCodeOp *mc35_popRegFromString(const char *str, int size, int offset);
// static pCodeOp *mc35_popGetImmd(char *name, unsigned int offset, int index, int is_func);
// static pCodeOp *mc35_popRegFromString(char *str, int size, int offset);
static int mc35_aop_isLitLike(asmop *aop);
static void mc35_genCritical(iCode *ic);
static void mc35_genEndCritical(iCode *ic);

/* The PIC port(s) need not differentiate between POINTER and FPOINTER. */
#define PIC_IS_DATA_PTR(x) (IS_DATA_PTR(x) || IS_FARPTR(x))

/*
 * mc35_max_key keeps track of the largest label number used in
 * a function. This is then used to adjust the label offset
 * for the next function.
 */
static int mc35_max_key = 0;
static int mc35_labelOffset = 0;
// zwr 2.0.0
static int mc35_GpseudoStkPtr = 0;
// static int mc35_GpsuedoStkPtr = 0;
static int mc35_inISR = 0;

static char *zero = "0x00";
static char *one = "0x01";
static char *spname = "sp";

unsigned mc35_fReturnSizePic = 4; /* shared with ralloc.c */
static char *mc35_fReturnpic14[] = {"temp1", "temp2", "temp3", "temp4"};

static char **mc35_fReturn = mc35_fReturnpic14;

static struct
{
  short accInUse;
  short nRegsSaved;
  set *sendSet;
} _G;

/*
 * Resolved ifx structure. This structure stores information
 * about an iCode ifx that makes it easier to generate code.
 */
typedef struct resolvedIfx
{
  symbol *lbl;   /* pointer to a label */
  int condition; /* true or false ifx */
  int generated; /* set true when the code associated with the ifx
                                 * is generated */
} resolvedIfx;

static pBlock *pb;

/*-----------------------------------------------------------------*/
/*  mc35_my_powof2(n) - If `n' is an integaer power of 2, then the      */
/*                 exponent of 2 is returned, otherwise -1 is      */
/*                 returned.                                       */
/* note that this is similar to the function `powof2' in SDCCsymt  */
/* if(n == 2^y)                                                    */
/*   return y;                                                     */
/* return -1;                                                      */
/*-----------------------------------------------------------------*/
static int
mc35_my_powof2(unsigned long num)
{
  if (num)
  {
    if ((num & (num - 1)) == 0)
    {
      int nshifts = -1;
      while (num)
      {
        num >>= 1;
        nshifts++;
      }
      return nshifts;
    }
  }

  return -1;
}

void DEBUGmc35_pic14_AopType(int line_no, operand *left, operand *right, operand *result)
{

  DEBUGmc35_pic14_emitcode("; ", "line = %d result %s=%s, size=%d, left %s=%s, size=%d, right %s=%s, size=%d",
                           line_no,
                           ((result) ? mc35_AopType(AOP_TYPE(result)) : "-"),
                           ((result) ? mc35_aopGet(AOP(result), 0, TRUE, FALSE) : "-"),
                           ((result) ? AOP_SIZE(result) : 0),
                           ((left) ? mc35_AopType(AOP_TYPE(left)) : "-"),
                           ((left) ? mc35_aopGet(AOP(left), 0, TRUE, FALSE) : "-"),
                           ((left) ? AOP_SIZE(left) : 0),
                           ((right) ? mc35_AopType(AOP_TYPE(right)) : "-"),
                           ((right) ? mc35_aopGet(AOP(right), 0, FALSE, FALSE) : "-"), ((right) ? AOP_SIZE(right) : 0));
}

static void
DEBUGmc35_pic14_AopTypeSign(int line_no, operand *left, operand *right, operand *result)
{

  DEBUGmc35_pic14_emitcode("; ", "line = %d, signs: result %s=%c, left %s=%c, right %s=%c",
                           line_no,
                           ((result) ? mc35_AopType(AOP_TYPE(result)) : "-"),
                           ((result) ? (SPEC_USIGN(operandType(result)) ? 'u' : 's') : '-'),
                           ((left) ? mc35_AopType(AOP_TYPE(left)) : "-"),
                           ((left) ? (SPEC_USIGN(operandType(left)) ? 'u' : 's') : '-'),
                           ((right) ? mc35_AopType(AOP_TYPE(right)) : "-"),
                           ((right) ? (SPEC_USIGN(operandType(right)) ? 'u' : 's') : '-'));
}

// zwr 2.0.0
void DEBUGmc35_pic14_emitcode(const char *inst, const char *fmt, ...)
// void DEBUGmc35_pic14_emitcode(char *inst, char *fmt, ...)
{
  va_list ap;

  if (!mc35_debug_verbose && !options.debug)
    return;

  va_start(ap, fmt);
  va_emitcode(inst, fmt, ap);
  va_end(ap);

  mc35_addpCode2pBlock(pb, mc35_newpCodeCharP(genLine.lineCurr->line));
}

void mc35_emitpComment(const char *fmt, ...)
{
  va_list ap;
  struct dbuf_s dbuf;
  const char *line;

  dbuf_init(&dbuf, INITIAL_INLINEASM);

  dbuf_append_char(&dbuf, ';');
  va_start(ap, fmt);
  dbuf_vprintf(&dbuf, fmt, ap);
  va_end(ap);

  line = dbuf_detach_c_str(&dbuf);
  emit_raw(line);
  dbuf_free(line);

  mc35_addpCode2pBlock(pb, mc35_newpCodeCharP(genLine.lineCurr->line));
}

void mc35_emitpLabel(int key)
{
  mc35_addpCode2pBlock(pb, mc35_newpCodeLabel(NULL, labelKey2num(key + mc35_labelOffset)));
}

/* gen.h defines a macro mc35_emitpcode that should be used to call mc35_emitpcode
 * as this allows for easy debugging (ever asked the question: where was
 * this instruction geenrated? Here is the answer... */
void mc35_emitpcode_real(PIC_OPCODE poc, pCodeOp *pcop)
{
  if (pcop)
    mc35_addpCode2pBlock(pb, mc35_newpCode(poc, pcop));
  else
  {
    static int has_warned = FALSE;

    DEBUGmc35_pic14_emitcode(";", "%s  ignoring NULL pcop", __FUNCTION__);
    if (!has_warned)
    {
      has_warned = TRUE;
      fprintf(stderr, "WARNING: encountered NULL pcop--this is probably a compiler bug...\n");
    }
  }
}

// static void
// mc35_emitpcodeNULLop(PIC_OPCODE poc)
void mc35_emitpcodeNULLop(PIC_OPCODE poc)
{
  mc35_addpCode2pBlock(pb, mc35_newpCode(poc, NULL));
}

/*-----------------------------------------------------------------*/
/* mc35_pic14_emitcode - writes the code into a file : for now it is simple    */
/*-----------------------------------------------------------------*/
// zwr 2.0.0
void mc35_pic14_emitcode(const char *inst, const char *fmt, ...)
// void mc35_pic14_emitcode(char *inst, char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  va_emitcode(inst, fmt, ap);
  va_end(ap);

  if (mc35_debug_verbose)
    mc35_addpCode2pBlock(pb, mc35_newpCodeCharP(genLine.lineCurr->line));
}

/*-----------------------------------------------------------------*/
/* mc35_emitDebuggerSymbol - associate the current code location  */
/*   with a debugger symbol                                        */
/*-----------------------------------------------------------------*/
void mc35_emitDebuggerSymbol(const char *debugSym)
{
  genLine.lineElement.isDebug = TRUE;
  mc35_pic14_emitcode("", ";%s ==.", debugSym);
  genLine.lineElement.isDebug = FALSE;
}

/*-----------------------------------------------------------------*/
/* newAsmop - creates a new asmOp                                  */
/*-----------------------------------------------------------------*/
static asmop *
newAsmop(short type)
{
  asmop *aop;

  aop = Safe_calloc(1, sizeof(asmop));
  aop->type = type;
  return aop;
}

/*-----------------------------------------------------------------*/
/* resolveIfx - converts an iCode ifx into a form more useful for  */
/*              generating code                                    */
/*-----------------------------------------------------------------*/
static void
resolveIfx(resolvedIfx *resIfx, iCode *ifx)
{
  if (!resIfx)
    return;

  //  DEBUGmc35_pic14_emitcode("; ***","%s %d",__FUNCTION__,__LINE__);

  resIfx->condition = TRUE;  /* assume that the ifx is true */
  resIfx->generated = FALSE; /* indicate that the ifx has not been used */

  if (!ifx)
  {
    resIfx->lbl = NULL; /* this is wrong: newiTempLabel(NULL);  / * oops, there is no ifx. so create a label */
  }
  else
  {
    if (IC_TRUE(ifx))
    {
      resIfx->lbl = IC_TRUE(ifx);
    }
    else
    {
      resIfx->lbl = IC_FALSE(ifx);
      resIfx->condition = FALSE;
    }
  }

  //  DEBUGmc35_pic14_emitcode("; ***","%s lbl->key=%d, (lab offset=%d)",__FUNCTION__,resIfx->lbl->key,mc35_labelOffset);
}

/*-----------------------------------------------------------------*/
/* aopForSym - for a true symbol                                   */
/*-----------------------------------------------------------------*/
static asmop *
aopForSym(iCode *ic, symbol *sym, bool result)
{
  asmop *aop;
  memmap *space = SPEC_OCLS(sym->etype);

  DEBUGmc35_pic14_emitcode("; ***", "%s %d", __FUNCTION__, __LINE__);
  /* if already has one */
  if (sym->aop)
    return sym->aop;

  //DEBUGmc35_pic14_emitcode(";","%d",__LINE__);
  /* if it is in direct space */
  if (IN_DIRSPACE(space))
  {
    sym->aop = aop = newAsmop(AOP_DIR);
    aop->aopu.aop_dir = sym->rname;
    aop->size = getSize(sym->type);
    DEBUGmc35_pic14_emitcode(";", "%d sym->rname = %s, size = %d", __LINE__, sym->rname, aop->size);
    return aop;
  }

  /* special case for a function */
  if (IS_FUNC(sym->type))
  {

    sym->aop = aop = newAsmop(AOP_PCODE);
    aop->aopu.pcop = mc35_popGetImmd(sym->rname, 0, 0, 1);
    PCOI(aop->aopu.pcop)->_const = IN_CODESPACE(space);
    PCOI(aop->aopu.pcop)->_function = TRUE;
    PCOI(aop->aopu.pcop)->index = 0;
    aop->size = FARPTRSIZE;
    DEBUGmc35_pic14_emitcode(";", "%d size = %d, name =%s", __LINE__, aop->size, sym->rname);
    return aop;
  }

  if (IS_ARRAY(sym->type))
  {
    sym->aop = aop = newAsmop(AOP_PCODE);
    aop->aopu.pcop = mc35_popGetImmd(sym->rname, 0, 0, 1);
    PCOI(aop->aopu.pcop)->_const = IN_CODESPACE(space);
    PCOI(aop->aopu.pcop)->_function = FALSE;
    PCOI(aop->aopu.pcop)->index = 0;
    aop->size = getSize(sym->etype) * DCL_ELEM(sym->type);

    DEBUGmc35_pic14_emitcode(";", "%d size = %d, name =%s", __LINE__, aop->size, sym->rname);
    return aop;
  }

  /* only remaining is far space */
  /* in which case DPTR gets the address */
  sym->aop = aop = newAsmop(AOP_PCODE);

  aop->aopu.pcop = mc35_popGetImmd(sym->rname, 0, 0, 0);
  PCOI(aop->aopu.pcop)->_const = IN_CODESPACE(space);
  PCOI(aop->aopu.pcop)->index = 0;

  DEBUGmc35_pic14_emitcode(";", "%d: rname %s, val %d, const = %d", __LINE__, sym->rname, 0, PCOI(aop->aopu.pcop)->_const);

  mc35_allocDirReg(IC_LEFT(ic));

  aop->size = FARPTRSIZE;

  /* if it is in code space */
  if (IN_CODESPACE(space))
    aop->code = TRUE;

  return aop;
}

/*-----------------------------------------------------------------*/
/* aopForRemat - rematerialzes an object                           */
/*-----------------------------------------------------------------*/
static asmop *
aopForRemat(operand *op) // x symbol *sym)
{
  symbol *sym = OP_SYMBOL(op);
  iCode *ic = NULL;
  asmop *aop = newAsmop(AOP_PCODE);
  int val = 0;

  ic = sym->rematiCode;

  DEBUGmc35_pic14_emitcode(";", "%s %d", __FUNCTION__, __LINE__);
  if (IS_OP_POINTER(op))
  {
    DEBUGmc35_pic14_emitcode(";", "%s %d IS_OP_POINTER", __FUNCTION__, __LINE__);
  }
  for (;;)
  {
    if (ic->op == '+')
    {
      val += (int)operandLitValue(IC_RIGHT(ic));
    }
    else if (ic->op == '-')
    {
      val -= (int)operandLitValue(IC_RIGHT(ic));
    }
    else
      break;

    ic = OP_SYMBOL(IC_LEFT(ic))->rematiCode;
  }

  aop->aopu.pcop = mc35_popGetImmd(OP_SYMBOL(IC_LEFT(ic))->rname, 0, val, 0);
  PCOI(aop->aopu.pcop)->_const = IS_PTR_CONST(operandType(op));
  PCOI(aop->aopu.pcop)->index = val;

  DEBUGmc35_pic14_emitcode(";", "%d: rname %s, val %d, const = %d",
                           __LINE__, OP_SYMBOL(IC_LEFT(ic))->rname, val, IS_PTR_CONST(operandType(op)));

  //  DEBUGmc35_pic14_emitcode(";","aop type  %s",mc35_AopType(AOP_TYPE(IC_LEFT(ic))));

  mc35_allocDirReg(IC_LEFT(ic));

  return aop;
}

static int
aopIdx(asmop *aop, int offset)
{
  if (!aop)
    return -1;

  if (aop->type != AOP_REG)
    return -2;

  return aop->aopu.aop_reg[offset]->rIdx;
}

/*-----------------------------------------------------------------*/
/* regsInCommon - two operands have some registers in common       */
/*-----------------------------------------------------------------*/
static bool
regsInCommon(operand *op1, operand *op2)
{
  symbol *sym1, *sym2;
  int i;

  /* if they have registers in common */
  if (!IS_SYMOP(op1) || !IS_SYMOP(op2))
    return FALSE;

  sym1 = OP_SYMBOL(op1);
  sym2 = OP_SYMBOL(op2);

  if (sym1->nRegs == 0 || sym2->nRegs == 0)
    return FALSE;

  for (i = 0; i < sym1->nRegs; i++)
  {
    int j;
    if (!sym1->regs[i])
      continue;

    for (j = 0; j < sym2->nRegs; j++)
    {
      if (!sym2->regs[j])
        continue;

      if (sym2->regs[j] == sym1->regs[i])
        return TRUE;
    }
  }

  return FALSE;
}

/*-----------------------------------------------------------------*/
/* operandsEqu - equivalent                                        */
/*-----------------------------------------------------------------*/
static bool
operandsEqu(operand *op1, operand *op2)
{
  symbol *sym1, *sym2;

  /* if they not symbols */
  if (!IS_SYMOP(op1) || !IS_SYMOP(op2))
    return FALSE;

  sym1 = OP_SYMBOL(op1);
  sym2 = OP_SYMBOL(op2);

  /* if both are itemps & one is spilt
     and the other is not then false */
  if (IS_ITEMP(op1) && IS_ITEMP(op2) && sym1->isspilt != sym2->isspilt)
    return FALSE;

  /* if they are the same */
  if (sym1 == sym2)
    return TRUE;

  if (sym1->rname[0] && sym2->rname[0] && strcmp(sym1->rname, sym2->rname) == 0)
    return TRUE;

  /* if left is a tmp & right is not */
  if (IS_ITEMP(op1) && !IS_ITEMP(op2) && sym1->isspilt && (sym1->usl.spillLoc == sym2))
    return TRUE;

  if (IS_ITEMP(op2) && !IS_ITEMP(op1) && sym2->isspilt && sym1->level > 0 && (sym2->usl.spillLoc == sym1))
    return TRUE;

  return FALSE;
}

/*-----------------------------------------------------------------*/
/* mc35_sameRegs - two asmops have the same registers             */
/*-----------------------------------------------------------------*/
bool mc35_sameRegs(asmop *aop1, asmop *aop2)
{
  int i;

  if (aop1 == aop2)
    return TRUE;

  if (aop1->type != AOP_REG || aop2->type != AOP_REG)
    return FALSE;

  if (aop1->size != aop2->size)
    return FALSE;

  for (i = 0; i < aop1->size; i++)
    if (aop1->aopu.aop_reg[i] != aop2->aopu.aop_reg[i])
      return FALSE;

  return TRUE;
}

/*-----------------------------------------------------------------*/
/* mc35_aopOp - allocates an asmop for an operand  :                    */
/*-----------------------------------------------------------------*/
void mc35_aopOp(operand *op, iCode *ic, bool result)
{
  asmop *aop;
  symbol *sym;
  int i;

  if (!op)
    return;

  /* if this a literal */
  if (IS_OP_LITERAL(op))
  {
    op->aop = aop = newAsmop(AOP_LIT);
    aop->aopu.aop_lit = OP_VALUE(op);
    aop->size = getSize(operandType(op));
    return;
  }

  {
    sym_link *type = operandType(op);
    if (IS_PTR_CONST(type))
      DEBUGmc35_pic14_emitcode(";", "%d aop type is const pointer", __LINE__);
  }

  /* if already has a asmop then continue */
  if (op->aop)
    return;

  /* if the underlying symbol has a aop */
  if (IS_SYMOP(op) && OP_SYMBOL(op)->aop)
  {
    DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
    op->aop = OP_SYMBOL(op)->aop;
    return;
  }

  /* if this is a true symbol */
  if (IS_TRUE_SYMOP(op))
  {
    //DEBUGmc35_pic14_emitcode(";","%d - true symop",__LINE__);
    op->aop = aopForSym(ic, OP_SYMBOL(op), result);
    return;
  }

  /* this is a temporary : this has
     only four choices :
     a) register
     b) spillocation
     c) rematerialize
     d) conditional
     e) can be a return use only */

  sym = OP_SYMBOL(op);

  /* if the type is a conditional */
  if (sym->regType == REG_CND)
  {
    aop = op->aop = sym->aop = newAsmop(AOP_CRY);
    aop->size = 0;
    return;
  }

  /* if it is spilt then two situations
     a) is rematerialize
     b) has a spill location */
  if (sym->isspilt || sym->nRegs == 0)
  {

    DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
    /* rematerialize it NOW */
    if (sym->remat)
    {

      sym->aop = op->aop = aop = aopForRemat(op);
      aop->size = getSize(sym->type);
      //DEBUGmc35_pic14_emitcode(";"," %d: size %d, %s\n",__LINE__,aop->size,aop->aopu.aop_immd);
      return;
    }

    if (sym->ruonly)
    {
      if (sym->isptr) // && sym->uptr
      {
        aop = op->aop = sym->aop = newAsmop(AOP_PCODE);
        aop->aopu.pcop = mc35_newpCodeOp(NULL, PO_GPR_POINTER); //mc35_popCopyReg(&mc35_pc_fsr);

        //PCOI(aop->aopu.pcop)->_const = 0;
        //PCOI(aop->aopu.pcop)->index = 0;
        /*
                 DEBUGmc35_pic14_emitcode(";","%d: rname %s, val %d, const = %d",
                 __LINE__,sym->rname, 0, PCOI(aop->aopu.pcop)->_const);
               */
        //mc35_allocDirReg (IC_LEFT(ic));

        aop->size = getSize(sym->type);
        DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
        return;
      }
      else
      {

        unsigned i;

        aop = op->aop = sym->aop = newAsmop(AOP_STR);
        aop->size = getSize(sym->type);
        for (i = 0; i < mc35_fReturnSizePic; i++)
          aop->aopu.aop_str[i] = mc35_fReturn[i];

        DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
        return;
      }
    }

    /* else spill location  */
    // zwr 2.0.0
    if (sym->isspilt && sym->usl.spillLoc)
    // if (sym->usl.spillLoc)
    {
      asmop *oldAsmOp = NULL;

      if (getSize(sym->type) != getSize(sym->usl.spillLoc->type))
      {
        /* force a new aop if sizes differ */
        oldAsmOp = sym->usl.spillLoc->aop;
        sym->usl.spillLoc->aop = NULL;
      }
      DEBUGmc35_pic14_emitcode(";", "%s %d %s sym->rname = %s, offset %d",
                               __FUNCTION__, __LINE__, sym->usl.spillLoc->rname, sym->rname, sym->usl.spillLoc->offset);

      sym->aop = op->aop = aop = newAsmop(AOP_PCODE);
      if (getSize(sym->type) != getSize(sym->usl.spillLoc->type))
      {
        /* Don't reuse the new aop, go with the last one */
        sym->usl.spillLoc->aop = oldAsmOp;
      }
      //aop->aopu.pcop = mc35_popGetImmd(sym->usl.spillLoc->rname,0,sym->usl.spillLoc->offset);
      aop->aopu.pcop = mc35_popRegFromString(sym->usl.spillLoc->rname, getSize(sym->type), sym->usl.spillLoc->offset);
      aop->size = getSize(sym->type);

      return;
    }
  }

  {
    sym_link *type = operandType(op);
    if (IS_PTR_CONST(type))
      DEBUGmc35_pic14_emitcode(";", "%d aop type is const pointer", __LINE__);
  }

  /* must be in a register */
  DEBUGmc35_pic14_emitcode(";", "%d register type nRegs=%d", __LINE__, sym->nRegs);
  sym->aop = op->aop = aop = newAsmop(AOP_REG);
  aop->size = sym->nRegs;
  for (i = 0; i < sym->nRegs; i++)
    aop->aopu.aop_reg[i] = sym->regs[i];
}

/*-----------------------------------------------------------------*/
/* mc35_freeAsmop - free up the asmop given to an operand               */
/*----------------------------------------------------------------*/
void mc35_freeAsmop(operand *op, asmop *aaop, iCode *ic, bool pop)
{
  asmop *aop;

  if (!op)
    aop = aaop;
  else
    aop = op->aop;

  if (!aop)
    return;

  aop->freed = TRUE;

  /* all other cases just dealloc */
  if (op)
  {
    op->aop = NULL;
    if (IS_SYMOP(op))
    {
      OP_SYMBOL(op)->aop = NULL;
      /* if the symbol has a spill */
      if (SPIL_LOC(op))
        SPIL_LOC(op)->aop = NULL;
    }
  }
}

/*-----------------------------------------------------------------*/
/* pic14aopLiteral - string from a literal value                   */
/*-----------------------------------------------------------------*/
static unsigned int
pic14aopLiteral(value *val, int offset)
{
  union {
    float f;
    unsigned char c[4];
  } fl;

  /* if it is a float then it gets tricky */
  /* otherwise it is fairly simple */
  if (!IS_FLOAT(val->type))
  {
    unsigned long v = ulFromVal(val);

    return ((v >> (offset * 8)) & 0xff);
  }

  /* it is type float */
  fl.f = (float)floatFromVal(val);
#ifdef WORDS_BIGENDIAN
  return fl.c[3 - offset];
#else
  return fl.c[offset];
#endif
}

/*-----------------------------------------------------------------*/
/* mc35_aopGet - for fetching value of the aop                          */
/*-----------------------------------------------------------------*/
char *
mc35_aopGet(asmop *aop, int offset, bool bit16, bool dname)
{
  // zwr 2.0.0
  // char *s = buffer;
  // char *rs;

  //DEBUGmc35_pic14_emitcode ("; ***","%s  %d",__FUNCTION__,__LINE__);
  /* offset is greater than
     size then zero */
  assert(aop);
  if (offset > (aop->size - 1) && aop->type != AOP_LIT)
    return zero;

  /* depending on type */
  switch (aop->type)
  {
    // zwr 2.0.0
  case AOP_IMMD:
    if (bit16)
      SNPRINTF(buffer, sizeof(buffer), "%s", aop->aopu.aop_immd);
    else if (offset)
      SNPRINTF(buffer, sizeof(buffer), "(%s >> %d)", aop->aopu.aop_immd, offset * 8);
    else
      SNPRINTF(buffer, sizeof(buffer), "%s", aop->aopu.aop_immd);
    DEBUGmc35_pic14_emitcode(";", "%d immd %s", __LINE__, buffer);
    return Safe_strdup(buffer);

  // case AOP_IMMD:
  //   if (bit16)
  //     sprintf(s, "%s", aop->aopu.aop_immd);
  //   else if (offset)
  //     sprintf(s, "(%s >> %d)", aop->aopu.aop_immd, offset * 8);
  //   else
  //     sprintf(s, "%s", aop->aopu.aop_immd);
  //   DEBUGmc35_pic14_emitcode(";", "%d immd %s", __LINE__, s);
  //   rs = Safe_calloc(1, strlen(s) + 1);
  //   strcpy(rs, s);
  //   return rs;

  // zwr 2.0.0
  case AOP_DIR:
    if (offset)
    {
      SNPRINTF(buffer, sizeof(buffer), "(%s + %d)", aop->aopu.aop_dir, offset);
      DEBUGmc35_pic14_emitcode(";", "oops AOP_DIR did this %s\n", buffer);
    }
    else
      SNPRINTF(buffer, sizeof(buffer), "%s", aop->aopu.aop_dir);
    return Safe_strdup(buffer);

    // case AOP_DIR:
    //   if (offset)
    //   {
    //     sprintf(s, "(%s + %d)", aop->aopu.aop_dir, offset);
    //     DEBUGmc35_pic14_emitcode(";", "oops AOP_DIR did this %s\n", s);
    //   }
    //   else
    //     sprintf(s, "%s", aop->aopu.aop_dir);
    //   rs = Safe_calloc(1, strlen(s) + 1);
    //   strcpy(rs, s);
    //   return rs;

  case AOP_REG:
    //if (dname)
    //    return aop->aopu.aop_reg[offset]->dname;
    //else
    return aop->aopu.aop_reg[offset]->name;

  case AOP_CRY:
    //mc35_pic14_emitcode(";","%d",__LINE__);
    return aop->aopu.aop_dir;

  // zwr 2.0.0
  case AOP_LIT:
    SNPRINTF(buffer, sizeof(buffer), "0x%02x", pic14aopLiteral(aop->aopu.aop_lit, offset));
    return Safe_strdup(buffer);

    // case AOP_LIT:
    //   sprintf(s, "0x%02x", pic14aopLiteral(aop->aopu.aop_lit, offset));
    //   rs = Safe_strdup(s);
    //   return rs;

  case AOP_STR:
    aop->coff = offset;
    if (strcmp(aop->aopu.aop_str[offset], "a") == 0 && dname)
      return "acc";
    DEBUGmc35_pic14_emitcode(";", "%d - %s", __LINE__, aop->aopu.aop_str[offset]);

    return aop->aopu.aop_str[offset];

  case AOP_PCODE:
  {
    pCodeOp *pcop = aop->aopu.pcop;
    DEBUGmc35_pic14_emitcode(";", "%d: mc35_aopGet AOP_PCODE type %s", __LINE__, mc35_pCodeOpType(pcop));
    if (pcop->name)
    {
      if (pcop->type == PO_IMMEDIATE)
      {
        offset += PCOI(pcop)->index;
      }
      if (offset)
      {
        DEBUGmc35_pic14_emitcode(";", "%s offset %d", pcop->name, offset);
        // zwr 2.0.0
        SNPRINTF(buffer, sizeof(buffer), "(%s+%d)", pcop->name, offset);
        // sprintf(s, "(%s+%d)", pcop->name, offset);
      }
      else
      {
        DEBUGmc35_pic14_emitcode(";", "%s", pcop->name);
        // zwr 2.0.0
        SNPRINTF(buffer, sizeof(buffer), "%s", pcop->name);
        // sprintf(s, "%s", pcop->name);
      }
    }
    else
      // zwr 2.0.0
      SNPRINTF(buffer, sizeof(buffer), "0x%02x", PCOI(aop->aopu.pcop)->offset);
    // sprintf(s, "0x%02x", PCOI(aop->aopu.pcop)->offset);
  }
    // zwr 2.0.0
    return Safe_strdup(buffer);

    // rs = Safe_calloc(1, strlen(s) + 1);
    // strcpy(rs, s);
    // return rs;
  }

  werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "aopget got unsupported aop->type");
  exit(0);
}

/*-----------------------------------------------------------------*/
/* mc35_popGetTempReg - create a new temporary pCodeOp                  */
/*-----------------------------------------------------------------*/
static pCodeOp *
mc35_popGetTempReg(void)
{

  pCodeOp *pcop;

  pcop = mc35_newpCodeOp(NULL, PO_GPR_TEMP);
  if (pcop && pcop->type == PO_GPR_TEMP && PCOR(pcop)->r)
  {
    PCOR(pcop)->r->wasUsed = TRUE;
    PCOR(pcop)->r->isFree = FALSE;
  }

  return pcop;
}

/*-----------------------------------------------------------------*/
/* popReleaseTempReg - create a new temporary pCodeOp                  */
/*-----------------------------------------------------------------*/
static void
popReleaseTempReg(pCodeOp *pcop)
{

  if (pcop && pcop->type == PO_GPR_TEMP && PCOR(pcop)->r)
    PCOR(pcop)->r->isFree = TRUE;
}

/*-----------------------------------------------------------------*/
/* mc35_popGetLabel - create a new pCodeOp of type PO_LABEL             */
/*-----------------------------------------------------------------*/

pCodeOp *
mc35_popGetLabel(unsigned int key)
{

  DEBUGmc35_pic14_emitcode("; ***", "%s  key=%d, label offset %d", __FUNCTION__, key, mc35_labelOffset);

  if (key > (unsigned int)mc35_max_key)
    mc35_max_key = key;

  return mc35_newpCodeOpLabel(NULL, labelKey2num(key + mc35_labelOffset));
}

/*-------------------------------------------------------------------*/
/* mc35_popGetHighLabel - create a new pCodeOp of type PO_LABEL with offset=1 */
/*-------------------------------------------------------------------*/
static pCodeOp *
mc35_popGetHighLabel(unsigned int key)
{
  pCodeOp *pcop;
  pcop = mc35_popGetLabel(key);
  PCOLAB(pcop)->offset = 1;
  return pcop;
}

/*-----------------------------------------------------------------*/
/* mc35_popGetLit - asm operator to pcode operator conversion               */
/*-----------------------------------------------------------------*/
pCodeOp *
mc35_popGetLit(unsigned int lit)
{

  return mc35_newpCodeOpLit((unsigned char)lit);
}

/*-----------------------------------------------------------------*/
/* mc35_popGetImmd - asm operator to pcode immediate conversion         */
/*-----------------------------------------------------------------*/
// zwr 2.0.0
static pCodeOp *
mc35_popGetImmd(const char *name, unsigned int offset, int index, int is_func)
// static pCodeOp *
// mc35_popGetImmd(char *name, unsigned int offset, int index, int is_func)
{

  return mc35_newpCodeOpImmd(name, offset, index, 0, is_func);
}

/*-----------------------------------------------------------------*/
/* mc35_popGetWithString - asm operator to pcode operator conversion            */
/*-----------------------------------------------------------------*/
// zwr 2.0.0
static pCodeOp *
mc35_popGetWithString(const char *str, int isExtern)
// static pCodeOp *
// mc35_popGetWithString(char *str, int isExtern)
{
  pCodeOp *pcop;

  if (!str)
  {
    fprintf(stderr, "NULL string %s %d\n", __FILE__, __LINE__);
    exit(1);
  }

  pcop = mc35_newpCodeOp(str, PO_STR);
  PCOS(pcop)->isPublic = isExtern ? 1 : 0;

  return pcop;
}

// zwr 2.0.0
pCodeOp *
mc35_popGetExternal(const char *str, int isReg)
// pCodeOp *
// mc35_popGetExternal(char *str, int isReg)
{
  pCodeOp *pcop;

  if (isReg)
  {
    pcop = mc35_newpCodeOpRegFromStr(str);
  }
  else
  {
    pcop = mc35_popGetWithString(str, 1);
  }

  if (str)
  {
    symbol *sym;

    for (sym = setFirstItem(externs); sym; sym = setNextItem(externs))
    {
      if (!strcmp(str, sym->rname))
        break;
    }

    if (!sym)
    {
      sym = newSymbol(str, 0);
      strncpy(sym->rname, str, SDCC_NAME_MAX);
      addSet(&externs, sym);
    } // if
    sym->used++;
  }
  return pcop;
}

/*-----------------------------------------------------------------*/
/* mc35_popRegFromString -                                              */
/*-----------------------------------------------------------------*/
// zwr 2.0.0
static pCodeOp *
mc35_popRegFromString(const char *str, int size, int offset)
// static pCodeOp *
// mc35_popRegFromString(char *str, int size, int offset)
{

  pCodeOp *pcop = Safe_calloc(1, sizeof(pCodeOpReg));
  pcop->type = PO_DIR;

  DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);

  if (!str)
    str = "BAD_STRING";

  // zwr 2.0.0
  pcop->name = Safe_strdup(str);
  // pcop->name = Safe_calloc(1, strlen(str) + 1);
  // strcpy(pcop->name, str);

  //pcop->name = Safe_strdup( ( (str) ? str : "BAD STRING"));

  PCOR(pcop)->r = mc35_dirregWithName(pcop->name);
  if (PCOR(pcop)->r == NULL)
  {
    //fprintf(stderr,"%d - couldn't find %s in allocated registers, size =%d\n",__LINE__,aop->aopu.aop_dir,aop->size);
    PCOR(pcop)->r = mc35_allocRegByName(pcop->name, size);
    DEBUGmc35_pic14_emitcode(";", "%d  %s   offset=%d - had to alloc by reg name", __LINE__, pcop->name, offset);
  }
  else
  {
    DEBUGmc35_pic14_emitcode(";", "%d  %s   offset=%d", __LINE__, pcop->name, offset);
  }
  PCOR(pcop)->instance = offset;

  return pcop;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static pCodeOp *
popRegFromIdx(int rIdx)
{
  pCodeOp *pcop;

  DEBUGmc35_pic14_emitcode("; ***", "%s,%d  , rIdx=0x%x", __FUNCTION__, __LINE__, rIdx);

  // zwr 2.0.0
  pcop = Safe_alloc(sizeof(pCodeOpReg));
  // pcop = Safe_calloc(1, sizeof(pCodeOpReg));

  PCOR(pcop)->rIdx = rIdx;
  PCOR(pcop)->r = mc35_typeRegWithIdx(rIdx, REG_STK, 1);
  PCOR(pcop)->r->isFree = FALSE;
  PCOR(pcop)->r->wasUsed = TRUE;

  pcop->type = PCOR(pcop)->r->pc_type;

  return pcop;
}

/*-----------------------------------------------------------------*/
/* mc35_popGet - asm operator to pcode operator conversion              */
/*-----------------------------------------------------------------*/
pCodeOp *
mc35_popGet(asmop *aop, int offset) //, bool bit16, bool dname)
{
  //char *s = buffer ;
  //char *rs;

  pCodeOp *pcop;

  //DEBUGmc35_pic14_emitcode ("; ***","%s  %d",__FUNCTION__,__LINE__);
  /* offset is greater than
     size then zero */

  assert(aop);

  /* XXX: still needed for BIT operands (AOP_CRY) */
  // zwr 2.0.0
  if ((offset >= aop->size) && (aop->type != AOP_LIT) && (aop->type != AOP_PCODE))
  {
    printf("%s: (offset[%d] >= AOP_SIZE(op)[%d]) && (AOP_TYPE(op)[%d] != { AOP_LIT, AOP_PCODE })\n",
           __FUNCTION__, offset, aop->size, aop->type);
    return NULL; //zero;
  }
  // if (offset > (aop->size - 1) && aop->type != AOP_LIT && aop->type != AOP_PCODE)
  // {
  //   printf("%s: (offset[%d] > AOP_SIZE(op)[%d]-1) && AOP_TYPE(op) != AOP_LIT)\n", __FUNCTION__, offset, aop->size);
  //   return NULL; //zero;
  // }

  /* depending on type */
  switch (aop->type)
  {

  case AOP_IMMD:
    DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
    return mc35_popGetImmd(aop->aopu.aop_immd, offset, 0, 0);

  case AOP_DIR:
    return mc35_popRegFromString(aop->aopu.aop_dir, aop->size, offset);

  case AOP_REG:
  {
    int rIdx;
    assert(offset < aop->size);
    rIdx = aop->aopu.aop_reg[offset]->rIdx;

    pcop = Safe_calloc(1, sizeof(pCodeOpReg));
    PCOR(pcop)->rIdx = rIdx;
    PCOR(pcop)->r = mc35_pic14_regWithIdx(rIdx);
    PCOR(pcop)->r->wasUsed = TRUE;
    PCOR(pcop)->r->isFree = FALSE;

    PCOR(pcop)->instance = offset;
    pcop->type = PCOR(pcop)->r->pc_type;
    //rs = aop->aopu.aop_reg[offset]->name;
    DEBUGmc35_pic14_emitcode(";", "%d rIdx = r0x%X ", __LINE__, rIdx);
    return pcop;
  }

  case AOP_CRY:
    pcop = mc35_newpCodeOpBit(aop->aopu.aop_dir, -1, 1);
    PCOR(pcop)->r = mc35_dirregWithName(aop->aopu.aop_dir);
    //if(PCOR(pcop)->r == NULL)
    //fprintf(stderr,"%d - couldn't find %s in allocated registers\n",__LINE__,aop->aopu.aop_dir);
    return pcop;

  case AOP_LIT:
    return mc35_newpCodeOpLit(pic14aopLiteral(aop->aopu.aop_lit, offset));

  case AOP_STR:
    DEBUGmc35_pic14_emitcode(";", "%d  %s", __LINE__, aop->aopu.aop_str[offset]);
    return mc35_newpCodeOpRegFromStr(aop->aopu.aop_str[offset]);

  case AOP_PCODE:
    pcop = NULL;
    DEBUGmc35_pic14_emitcode(";", "mc35_popGet AOP_PCODE (%s + %i) %d %s", mc35_pCodeOpType(aop->aopu.pcop), offset,
                             __LINE__, ((aop->aopu.pcop->name) ? (aop->aopu.pcop->name) : "no name"));
    //mc35_emitpComment ("mc35_popGet; name %s, offset: %i, pcop-type: %s\n", aop->aopu.pcop->name, offset, mc35_pCodeOpType (aop->aopu.pcop));
    switch (aop->aopu.pcop->type)
    {
    case PO_IMMEDIATE:
      pcop = mc35_pCodeOpCopy(aop->aopu.pcop);
      /* usually we want to access the memory at "<symbol> + offset" (using ->index),
           * but sometimes we want to access the high byte of the symbol's address (using ->offset) */
      PCOI(pcop)->index += offset;
      //PCOI(pcop)->offset = 0;
      break;
    case PO_DIR:
      pcop = mc35_pCodeOpCopy(aop->aopu.pcop);
      PCOR(pcop)->instance = offset;
      break;
    default:
      assert(!"unhandled pCode type");
      break;
    } // switch
    return pcop;
  }

  werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "mc35_popGet got unsupported aop->type");
  exit(0);
}

/*-----------------------------------------------------------------*/
/* mc35_popGetAddr - access the low/high word of a symbol (immediate)   */
/*              (for non-PO_IMMEDIATEs this is the same as mc35_popGet) */
/*-----------------------------------------------------------------*/
pCodeOp *
mc35_popGetAddr(asmop *aop, int offset, int index)
{
  if (aop->type == AOP_PCODE && aop->aopu.pcop->type == PO_IMMEDIATE)
  {
    pCodeOp *pcop = aop->aopu.pcop;
    assert(offset <= GPTRSIZE);

    /* special case: index >= 2 should return GPOINTER-style values */
    if (offset == 2)
    {
      pcop = mc35_popGetLit(aop->code ? GPTRTAG_CODE : GPTRTAG_DATA);
      return pcop;
    }

    pcop = mc35_pCodeOpCopy(pcop);
    /* usually we want to access the memory at "<symbol> + offset" (using ->index),
       * but sometimes we want to access the high byte of the symbol's address (using ->offset) */
    PCOI(pcop)->offset += offset;
    PCOI(pcop)->index += index;
    //fprintf (stderr, "is PO_IMMEDIATE: %s+o%d+i%d (new o%d,i%d)\n", pcop->name,PCOI(pcop)->offset,PCOI(pcop)->index, offset, index);
    return pcop;
  }
  else
  {
    return mc35_popGet(aop, offset + index);
  }
}

/*-----------------------------------------------------------------*/
/* mc35_aopPut - puts a string for a aop                                */
/*-----------------------------------------------------------------*/
// zwr 2.0.0
void mc35_aopPut(asmop *aop, const char *s, int offset)
// void mc35_aopPut(asmop *aop, char *s, int offset)
{
  // char *d = buffer;
  symbol *lbl;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (aop->size && offset > (aop->size - 1))
  {
    werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "mc35_aopPut got offset > aop->size");
    exit(0);
  }

  /* will assign value to value */
  /* depending on where it is ofcourse */
  switch (aop->type)
  {
  case AOP_DIR:
    if (offset)
    {
      // zwr 2.0.0
      SNPRINTF(buffer, sizeof(buffer), "(%s + %d)", aop->aopu.aop_dir, offset);
      // sprintf(d, "(%s + %d)", aop->aopu.aop_dir, offset);
      fprintf(stderr, "oops mc35_aopPut:AOP_DIR did this %s\n", s);
    }
    else
      // zwr 2.0.0
      SNPRINTF(buffer, sizeof(buffer), "%s", aop->aopu.aop_dir);
    // sprintf(d, "%s", aop->aopu.aop_dir);

    if (strcmp(buffer, s))
    {
      DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
      if (strcmp(s, "W"))
        mc35_pic14_emitcode("movf", "%s,w", s);

      mc35_pic14_emitcode("movwf", "%s", buffer);

      if (strcmp(s, "W"))
      {
        mc35_pic14_emitcode(";BUG!? should have this:movf", "%s,w   %d", s, __LINE__);
        if (offset >= aop->size)
        {
          mc35_emitpcode(POC_CLRF, mc35_popGet(aop, offset));
          break;
        }
        else
        {
          mc35_emitpcode(POC_MOVFW, mc35_popGetImmd(s, 0, offset, 0));
        }
      }
      mc35_emitpcode(POC_MOVWF, mc35_popGet(aop, offset));
    }
    break;

  case AOP_REG:
    if (strcmp(aop->aopu.aop_reg[offset]->name, s) != 0)
    {
      if (strcmp(s, "W") == 0)
        mc35_pic14_emitcode("movf", "%s,w  ; %d", s, __LINE__);

      mc35_pic14_emitcode("movwf", "%s", aop->aopu.aop_reg[offset]->name);

      if (strcmp(s, zero) == 0)
      {
        mc35_emitpcode(POC_CLRF, mc35_popGet(aop, offset));
      }
      else if (strcmp(s, "W") == 0)
      {
        // zwr 2.0.0
        pCodeOp *pcop = Safe_alloc(sizeof(pCodeOpReg));
        // pCodeOp *pcop = Safe_calloc(1, sizeof(pCodeOpReg));
        pcop->type = PO_GPR_REGISTER;

        PCOR(pcop)->rIdx = -1;
        PCOR(pcop)->r = NULL;

        DEBUGmc35_pic14_emitcode(";", "%d", __LINE__);
        pcop->name = Safe_strdup(s);
        mc35_emitpcode(POC_MOVFW, pcop);
        mc35_emitpcode(POC_MOVWF, mc35_popGet(aop, offset));
      }
      else if (strcmp(s, one) == 0)
      {
        // zwr 1.0.0 inst incr #1
        // mc35_emitpcode(POC_CLRF, mc35_popGet(aop, offset));
        // mc35_emitpcode(POC_INCF, mc35_popGet(aop, offset));
        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(aop, offset));
      }
      else
      {
        mc35_emitpcode(POC_MOVWF, mc35_popGet(aop, offset));
      }
    }
    break;

  case AOP_STK:
    if (strcmp(s, "a") == 0)
      mc35_pic14_emitcode("push", "acc");
    else
      mc35_pic14_emitcode("push", "%s", s);

    break;

  case AOP_CRY:
    /* if bit variable */
    if (!aop->aopu.aop_dir)
    {
      mc35_pic14_emitcode("clr", "a");
      mc35_pic14_emitcode("rlc", "a");
    }
    else
    {
      if (s == zero)
        mc35_pic14_emitcode("clr", "%s", aop->aopu.aop_dir);
      else if (s == one)
        mc35_pic14_emitcode("setb", "%s", aop->aopu.aop_dir);
      else if (!strcmp(s, "c"))
        mc35_pic14_emitcode("mov", "%s,c", aop->aopu.aop_dir);
      else
      {
        lbl = newiTempLabel(NULL);

        if (strcmp(s, "a"))
        {
          MOVA(s);
        }
        mc35_pic14_emitcode("clr", "c");
        mc35_pic14_emitcode("jz", "%05d_DS_", labelKey2num(lbl->key));
        mc35_pic14_emitcode("cpl", "c");
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(lbl->key));
        mc35_pic14_emitcode("mov", "%s,c", aop->aopu.aop_dir);
      }
    }
    break;

  case AOP_STR:
    aop->coff = offset;
    if (strcmp(aop->aopu.aop_str[offset], s))
      mc35_pic14_emitcode("mov", "%s,%s ; %d", aop->aopu.aop_str[offset], s, __LINE__);
    break;

  default:
    werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "mc35_aopPut got unsupported aop->type");
    exit(0);
  }
}

/*-----------------------------------------------------------------*/
/* mc35_mov2w_op - generate either a MOVLW or MOVFW based operand type  */
/*-----------------------------------------------------------------*/
static void
mc35_mov2w_op(operand *op, int offset)
{
  assert(op);
  FENTRY;

  /* for PO_IMMEDIATEs: use address or value? */
  if (mc35_op_isLitLike(op))
  {
    /* access address of op */
    if (AOP_TYPE(op) != AOP_LIT)
    {
      assert(offset < 3);
    }
    if (IS_SYMOP(op) && IS_GENPTR(OP_SYM_TYPE(op)) && AOP_SIZE(op) < offset)
    {
      if (offset == GPTRSIZE - 1)
        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(GPTRTAG_DATA));
      else
        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
    }
    else
      mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(op), offset, 0));
  }
  else
  {
    /* access value stored in op */
    mc35_mov2w(AOP(op), offset);
  }
}

/*-----------------------------------------------------------------*/
/* mc35_mov2w - generate either a MOVLW or MOVFW based operand type     */
/*-----------------------------------------------------------------*/
void mc35_mov2w(asmop *aop, int offset)
{

  if (!aop)
    return;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d  offset=%d", __FUNCTION__, __LINE__, offset);

  if (mc35_aop_isLitLike(aop))
    mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(aop, offset, 0));
  else
    mc35_emitpcode(POC_MOVFW, mc35_popGet(aop, offset));
}

static void
movwf(asmop *op, int offset)
{
  mc35_emitpcode(POC_MOVWF, mc35_popGet(op, offset));
}

static pCodeOp *
get_argument_pcop(int idx)
{
  assert(idx > 0 && "the 0th (first) argument is passed via WREG");
  return popRegFromIdx(mc35_Gstack_base_addr - (idx - 1));
}

static pCodeOp *
get_return_val_pcop(int offset)
{
  assert(offset > 0 && "the most significant byte is returned via WREG");
  return popRegFromIdx(mc35_Gstack_base_addr - (offset - 1));
}

static void
pass_argument(operand *op, int offset, int idx)
{
  if (op)
    mc35_mov2w_op(op, offset);
  if (idx != 0)
    mc35_emitpcode(POC_MOVWF, get_argument_pcop(idx));
}

static void
get_returnvalue(operand *op, int offset, int idx)
{
  if (idx != 0)
    mc35_emitpcode(POC_MOVFW, get_return_val_pcop(idx));
  movwf(AOP(op), offset);
}

static void
call_libraryfunc(char *name)
{
  symbol *sym;

  // zwr 1.0.0
  /* library code might reside in different page... */
  //mc35_emitpcode(POC_PAGESEL, mc35_popGetWithString(name, 1));
  /* call the library function */
  mc35_emitpcode(POC_CALL, mc35_popGetExternal(name, 0));
  /* might return from different page... */
  //mc35_emitpcode(POC_PAGESEL, mc35_popGetWithString("$", 0));

  /* create symbol, mark it as `extern' */
  sym = findSym(SymbolTab, NULL, name);
  if (!sym)
  {
    sym = newSymbol(name, 0);
    strncpy(sym->rname, name, SDCC_NAME_MAX);
    addSym(SymbolTab, sym, sym->rname, 0, 0, 0);
    addSet(&externs, sym);
  } // if
  sym->used++;
}

/*-----------------------------------------------------------------*/
/* mc35_getDataSize - get the operand data size                   */
/*-----------------------------------------------------------------*/
int mc35_getDataSize(operand *op)
{
  int size;

  size = AOP_SIZE(op);
  return size;
}

/*-----------------------------------------------------------------*/
/* mc35_outAcc - output Acc                                       */
/*-----------------------------------------------------------------*/
void mc35_outAcc(operand *result)
{
  int size, offset;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d - ", __FUNCTION__, __LINE__);
  DEBUGmc35_pic14_AopType(__LINE__, NULL, NULL, result);

  size = mc35_getDataSize(result);
  if (size)
  {
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));
    size--;
    offset = 1;
    /* unsigned or positive */
    while (size--)
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset++));
  }
}

/*-----------------------------------------------------------------*/
/* pic14_outBitC - output a bit C                                  */
/*-----------------------------------------------------------------*/
static void
pic14_outBitC(operand *result)
{

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* if the result is bit */
  if (AOP_TYPE(result) == AOP_CRY)
    mc35_aopPut(AOP(result), "c", 0);
  else
  {
    mc35_pic14_emitcode("clr", "a  ; %d", __LINE__);
    mc35_pic14_emitcode("rlc", "a");
    mc35_outAcc(result);
  }
}

/*-----------------------------------------------------------------*/
/* pic14_toBoolean - emit code for orl a,operator(sizeop)          */
/*-----------------------------------------------------------------*/
static void
pic14_toBoolean(operand *oper)
{
  int size = AOP_SIZE(oper);
  int offset = 0;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  assert(size > 0);

  if (size == 1)
  {
    /* MOVFW does not load the flags... */
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
    offset = 0;
  }
  else
  {
    mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(oper), 0));
    offset = 1;
  }

  while (offset < size)
  {
    mc35_emitpcode(POC_IORFW, mc35_popGet(AOP(oper), offset++));
  }
  /* Z is set iff (oper == 0) */
}

/*-----------------------------------------------------------------*/
/* genNot - generate code for ! operation                          */
/*-----------------------------------------------------------------*/
static void
genNot(iCode *ic)
{
  //symbol *tlbl;
  int size;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* assign asmOps to operand & result */
  mc35_aopOp(IC_LEFT(ic), ic, FALSE);
  mc35_aopOp(IC_RESULT(ic), ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, IC_LEFT(ic), NULL, IC_RESULT(ic));
  /* if in bit space then a special case */
  if (AOP_TYPE(IC_LEFT(ic)) == AOP_CRY)
  {
    if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY)
    {
      mc35_emitpcode(POC_MOVLW, mc35_popGet(AOP(IC_LEFT(ic)), 0));
      mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
    }
    else
    {
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
      mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(IC_LEFT(ic)), 0));
      // zwr 1.0.0 inst #2
      // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
      mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(IC_RESULT(ic)), 0));
      mc35_emitpcodeNULLop(POC_NOP);
    }
    goto release;
  }

  size = AOP_SIZE(IC_LEFT(ic));
  mc35_mov2w(AOP(IC_LEFT(ic)), 0);
  while (--size > 0)
  {
    if (mc35_op_isLitLike(IC_LEFT(ic)))
      mc35_emitpcode(POC_IORLW, mc35_popGetAddr(AOP(IC_LEFT(ic)), size, 0));
    else
      mc35_emitpcode(POC_IORFW, mc35_popGet(AOP(IC_LEFT(ic)), size));
  }
  mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
  mc35_emitSKPNZ;
  mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
  movwf(AOP(IC_RESULT(ic)), 0);

  for (size = 1; size < AOP_SIZE(IC_RESULT(ic)); size++)
  {
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(IC_RESULT(ic)), size));
  }
  goto release;

release:
  /* release the aops */
  mc35_freeAsmop(IC_LEFT(ic), NULL, ic, (RESULTONSTACK(ic) ? 0 : 1));
  mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genCpl - generate code for complement                           */
/*-----------------------------------------------------------------*/
static void
genCpl(iCode *ic)
{
  operand *left, *result;
  int size, offset = 0;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  /* if both are in bit space then
     a special case */
  if (AOP_TYPE(result) == AOP_CRY && AOP_TYPE(left) == AOP_CRY)
  {

    mc35_pic14_emitcode("mov", "c,%s", left->aop->aopu.aop_dir);
    mc35_pic14_emitcode("cpl", "c");
    mc35_pic14_emitcode("mov", "%s,c", result->aop->aopu.aop_dir);
    goto release;
  }

  size = AOP_SIZE(result);
  if (AOP_SIZE(left) < size)
    size = AOP_SIZE(left);
  while (size--)
  {
    // zwr 1.0.0 inst comar #1
    // mc35_emitpcode(POC_COMFW, mc35_popGet(AOP(left), offset));
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
    mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(left), offset));

    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    offset++;
  }
  mc35_addSign(result, AOP_SIZE(left), !SPEC_USIGN(operandType(result)));

release:
  /* release the aops */
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? 0 : 1));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genUminusFloat - unary minus for floating points                */
/*-----------------------------------------------------------------*/
static void
genUminusFloat(operand *op, operand *result)
{
  int size;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* for this we just need to flip the
     first it then copy the rest in place */
  size = AOP_SIZE(op) - 1;

  mc35_mov2w_op(op, size);
  mc35_emitpcode(POC_XORLW, mc35_popGetLit(0x80));
  movwf(AOP(result), size);

  while (size--)
  {
    mc35_mov2w_op(op, size);
    movwf(AOP(result), size);
  } // while
}

/*-----------------------------------------------------------------*/
/* genUminus - unary minus code generation                         */
/*-----------------------------------------------------------------*/
static void
genUminus(iCode *ic)
{
  int size, i;
  sym_link *optype;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* assign asmops */
  mc35_aopOp(IC_LEFT(ic), ic, FALSE);
  mc35_aopOp(IC_RESULT(ic), ic, TRUE);

  /* if both in bit space then special
     case */
  if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY && AOP_TYPE(IC_LEFT(ic)) == AOP_CRY)
  {

    mc35_emitpcode(POC_BCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
    mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(IC_LEFT(ic)), 0));
    mc35_emitpcode(POC_BSF, mc35_popGet(AOP(IC_RESULT(ic)), 0));

    goto release;
  }

  optype = operandType(IC_LEFT(ic));

  /* if float then do float stuff */
  if (IS_FLOAT(optype))
  {
    genUminusFloat(IC_LEFT(ic), IC_RESULT(ic));
    goto release;
  }

  /* otherwise subtract from zero by taking the 2's complement */
  size = AOP_SIZE(IC_LEFT(ic));

  for (i = 0; i < size; i++)
  {
    if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
    {
      // zwr 1.0.0 inst comr #1
      // mc35_emitpcode(POC_COMF, mc35_popGet(AOP(IC_LEFT(ic)), i));
      mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
      mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(IC_LEFT(ic)), i));
    }
    else
    {
      // zwr 1.0.0 inst comar #1
      // mc35_emitpcode(POC_COMFW, mc35_popGet(AOP(IC_LEFT(ic)), i));
      mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
      mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(IC_LEFT(ic)), i));

      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), i));
    }
  }

  // zwr 1.0.0 inst incr #3
  // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
  // for (i = 1; i < size; i++)
  // {
  //   mc35_emitSKPNZ;
  //   mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), i));
  // }
  mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
  mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
  for (i = 1; i < size; i++)
  {
    mc35_emitSKPNZ;
    mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(IC_RESULT(ic)), i));
  }

release:
  /* release the aops */
  mc35_freeAsmop(IC_LEFT(ic), NULL, ic, (RESULTONSTACK(ic) ? 0 : 1));
  mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* saverbank - saves an entire register bank on the stack          */
/*-----------------------------------------------------------------*/
static void
saverbank(int bank, iCode *ic, bool pushPsw)
{
  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d - WARNING no code generated", __FUNCTION__, __LINE__);
#if 0
  int i;
  asmop *aop;
  regs *r = NULL;

  DEBUGmc35_pic14_emitcode ("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (options.useXstack)
    {

      aop = newAsmop (0);
      r = getFreePtr (ic, &aop, FALSE);
      mc35_pic14_emitcode ("mov", "%s,_spx", r->name);

    }

  for (i = 0; i < pic14_nRegs; i++)
    {
      if (options.useXstack)
        {
          mc35_pic14_emitcode ("inc", "%s", r->name);
          //mc35_pic14_emitcode("mov","a,(%s+%d)",
          //       regspic14[i].base,8*bank+regspic14[i].offset);
          mc35_pic14_emitcode ("movx", "@%s,a", r->name);
        }
      else
        mc35_pic14_emitcode ("push", "");    // "(%s+%d)",
      //regspic14[i].base,8*bank+regspic14[i].offset);
    }

  if (pushPsw)
    {
      if (options.useXstack)
        {
          mc35_pic14_emitcode ("mov", "a,psw");
          mc35_pic14_emitcode ("movx", "@%s,a", r->name);
          mc35_pic14_emitcode ("inc", "%s", r->name);
          mc35_pic14_emitcode ("mov", "_spx,%s", r->name);
          mc35_freeAsmop (NULL, aop, ic, TRUE);

        }
      else
        mc35_pic14_emitcode ("push", "psw");

      mc35_pic14_emitcode ("mov", "psw,#0x%02x", (bank << 3) & 0x00ff);
    }
  ic->bankSaved = 1;
#endif
}

/*-----------------------------------------------------------------*/
/* saveRegisters - will look for a call and save the registers     */
/*-----------------------------------------------------------------*/
static void
saveRegisters(iCode *lic)
{
  iCode *ic;
  sym_link *dtype;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  /* look for call */
  for (ic = lic; ic; ic = ic->next)
    if (ic->op == CALL || ic->op == PCALL)
      break;

  if (!ic)
  {
    fprintf(stderr, "found parameter push with no function call\n");
    return;
  }

  /* if the registers have been saved already then do nothing */
  if (ic->regsSaved || IFFUNC_CALLEESAVES(OP_SYMBOL(IC_LEFT(ic))->type))
    return;

  /* find the registers in use at this time
     and push them away to safety */
  bitVectCplAnd(bitVectCopy(ic->rMask), ic->rUsed);

  ic->regsSaved = 1;

  //fprintf(stderr, "ERROR: saveRegisters did not do anything to save registers, please report this as a bug.\n");

  dtype = operandType(IC_LEFT(ic));
  if (currFunc && dtype &&
      (FUNC_REGBANK(currFunc->type) != FUNC_REGBANK(dtype)) && IFFUNC_ISISR(currFunc->type) && !ic->bankSaved)
  {
    saverbank(FUNC_REGBANK(dtype), ic, TRUE);
  }
}

/*-----------------------------------------------------------------*/
/* unsaveRegisters - pop the pushed registers                      */
/*-----------------------------------------------------------------*/
static void
unsaveRegisters(iCode *ic)
{
  int i;
  bitVect *rsave;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* find the registers in use at this time
     and push them away to safety */
  rsave = bitVectCplAnd(bitVectCopy(ic->rMask), ic->rUsed);

  if (options.useXstack)
  {
    mc35_pic14_emitcode("mov", "r0,%s", spname);
    for (i = pic14_nRegs; i >= 0; i--)
    {
      if (bitVectBitValue(rsave, i))
      {
        mc35_pic14_emitcode("dec", "r0");
        mc35_pic14_emitcode("movx", "a,@r0");
        mc35_pic14_emitcode("mov", "%s,a", mc35_pic14_regWithIdx(i)->name);
      }
    }
    mc35_pic14_emitcode("mov", "%s,r0", spname);
  } //else
  //for (i =  pic14_nRegs ; i >= 0 ; i--) {
  //  if (bitVectBitValue(rsave,i))
  //  mc35_pic14_emitcode("pop","%s",mc35_pic14_regWithIdx(i)->dname);
  //}
}

/*-----------------------------------------------------------------*/
/* pushSide -                */
/*-----------------------------------------------------------------*/
static void
pushSide(operand *oper, int size)
{
#if 0
  int offset = 0;
  DEBUGmc35_pic14_emitcode ("; ***", "%s  %d", __FUNCTION__, __LINE__);
  while (size--)
    {
      char *l = mc35_aopGet (AOP (oper), offset++, FALSE, TRUE);
      if (AOP_TYPE (oper) != AOP_REG && AOP_TYPE (oper) != AOP_DIR && strcmp (l, "a"))
        {
          mc35_pic14_emitcode ("mov", "a,%s", l);
          mc35_pic14_emitcode ("push", "acc");
        }
      else
        mc35_pic14_emitcode ("push", "%s", l);
    }
#endif
}

/*-----------------------------------------------------------------*/
/* assignResultValue -               */
/*-----------------------------------------------------------------*/
static void
assignResultValue(operand *oper)
{
  int size = AOP_SIZE(oper);
  int offset = 0;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  DEBUGmc35_pic14_AopType(__LINE__, oper, NULL, NULL);

  /* assign MSB first (passed via WREG) */
  while (size--)
  {
    get_returnvalue(oper, size, offset + mc35_GpseudoStkPtr);
    mc35_GpseudoStkPtr++;
  }
}

/*-----------------------------------------------------------------*/
/* genIpush - genrate code for pushing this gets a little complex  */
/*-----------------------------------------------------------------*/
static void
genIpush(iCode *ic)
{
  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d - WARNING no code generated", __FUNCTION__, __LINE__);
#if 0
  int size, offset = 0;
  char *l;


  /* if this is not a parm push : ie. it is spill push
     and spill push is always done on the local stack */
  if (!ic->parmPush)
    {

      /* and the item is spilt then do nothing */
      if (OP_SYMBOL (IC_LEFT (ic))->isspilt)
        return;

      mc35_aopOp (IC_LEFT (ic), ic, FALSE);
      size = AOP_SIZE (IC_LEFT (ic));
      /* push it on the stack */
      while (size--)
        {
          l = mc35_aopGet (AOP (IC_LEFT (ic)), offset++, FALSE, TRUE);
          if (*l == '#')
            {
              MOVA (l);
              l = "acc";
            }
          mc35_pic14_emitcode ("push", "%s", l);
        }
      return;
    }

  /* this is a paramter push: in this case we call
     the routine to find the call and save those
     registers that need to be saved */
  saveRegisters (ic);

  /* then do the push */
  mc35_aopOp (IC_LEFT (ic), ic, FALSE);


  // pushSide(IC_LEFT(ic), AOP_SIZE(IC_LEFT(ic)));
  size = AOP_SIZE (IC_LEFT (ic));

  while (size--)
    {
      l = mc35_aopGet (AOP (IC_LEFT (ic)), offset++, FALSE, TRUE);
      if (AOP_TYPE (IC_LEFT (ic)) != AOP_REG && AOP_TYPE (IC_LEFT (ic)) != AOP_DIR && strcmp (l, "a"))
        {
          mc35_pic14_emitcode ("mov", "a,%s", l);
          mc35_pic14_emitcode ("push", "acc");
        }
      else
        mc35_pic14_emitcode ("push", "%s", l);
    }

  mc35_freeAsmop (IC_LEFT (ic), NULL, ic, TRUE);
#endif
}

/*-----------------------------------------------------------------*/
/* genIpop - recover the registers: can happen only for spilling   */
/*-----------------------------------------------------------------*/
static void
genIpop(iCode *ic)
{
  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d - WARNING no code generated", __FUNCTION__, __LINE__);
  assert(!"genIpop -- unimplemented");
#if 0
  int size, offset;


  /* if the temp was not pushed then */
  if (OP_SYMBOL (IC_LEFT (ic))->isspilt)
    return;

  mc35_aopOp (IC_LEFT (ic), ic, FALSE);
  size = AOP_SIZE (IC_LEFT (ic));
  offset = (size - 1);
  while (size--)
    mc35_pic14_emitcode ("pop", "%s", mc35_aopGet (AOP (IC_LEFT (ic)), offset--, FALSE, TRUE));

  mc35_freeAsmop (IC_LEFT (ic), NULL, ic, TRUE);
#endif
}

/*-----------------------------------------------------------------*/
/* unsaverbank - restores the resgister bank from stack            */
/*-----------------------------------------------------------------*/
static void
unsaverbank(int bank, iCode *ic, bool popPsw)
{
  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d - WARNING no code generated", __FUNCTION__, __LINE__);
#if 0
  int i;
  asmop *aop;
  regs *r = NULL;

  DEBUGmc35_pic14_emitcode ("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (popPsw)
    {
      if (options.useXstack)
        {
          aop = newAsmop (0);
          r = getFreePtr (ic, &aop, FALSE);


          mc35_pic14_emitcode ("mov", "%s,_spx", r->name);
          mc35_pic14_emitcode ("movx", "a,@%s", r->name);
          mc35_pic14_emitcode ("mov", "psw,a");
          mc35_pic14_emitcode ("dec", "%s", r->name);

        }
      else
        mc35_pic14_emitcode ("pop", "psw");
    }

  for (i = (pic14_nRegs - 1); i >= 0; i--)
    {
      if (options.useXstack)
        {
          mc35_pic14_emitcode ("movx", "a,@%s", r->name);
          //mc35_pic14_emitcode("mov","(%s+%d),a",
          //     regspic14[i].base,8*bank+regspic14[i].offset);
          mc35_pic14_emitcode ("dec", "%s", r->name);

        }
      else
        mc35_pic14_emitcode ("pop", "");     //"(%s+%d)",
      //regspic14[i].base,8*bank); //+regspic14[i].offset);
    }

  if (options.useXstack)
    {

      mc35_pic14_emitcode ("mov", "_spx,%s", r->name);
      mc35_freeAsmop (NULL, aop, ic, TRUE);

    }
#endif
}

/*-----------------------------------------------------------------*/
/* genCall - generates a call statement                            */
/*-----------------------------------------------------------------*/
static void
genCall(iCode *ic)
{
  sym_link *dtype;
  symbol *sym;
  char *name;
  int isExtern;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  /* if caller saves & we have not saved then */
  if (!ic->regsSaved)
    saveRegisters(ic);

  /* if we are calling a function that is not using
     the same register bank then we need to save the
     destination registers on the stack */
  dtype = operandType(IC_LEFT(ic));
  if (currFunc && dtype &&
      (FUNC_REGBANK(currFunc->type) != FUNC_REGBANK(dtype)) && IFFUNC_ISISR(currFunc->type) && !ic->bankSaved)

    saverbank(FUNC_REGBANK(dtype), ic, TRUE);

  /* if send set is not empty the assign */
  if (_G.sendSet)
  {
    iCode *sic;
    /* For the Pic port, there is no data stack.
       * So parameters passed to functions are stored
       * in registers. (The pCode optimizer will get
       * rid of most of these :).
       */
    int pseudoStkPtr = -1;
    int firstTimeThruLoop = 1;

    _G.sendSet = reverseSet(_G.sendSet);

    /* First figure how many parameters are getting passed */
    for (sic = setFirstItem(_G.sendSet); sic; sic = setNextItem(_G.sendSet))
    {

      mc35_aopOp(IC_LEFT(sic), sic, FALSE);
      pseudoStkPtr += AOP_SIZE(IC_LEFT(sic));
      mc35_freeAsmop(IC_LEFT(sic), NULL, sic, FALSE);
    }

    for (sic = setFirstItem(_G.sendSet); sic; sic = setNextItem(_G.sendSet))
    {
      int size, offset = 0;

      mc35_aopOp(IC_LEFT(sic), sic, FALSE);
      size = AOP_SIZE(IC_LEFT(sic));

      while (size--)
      {
        DEBUGmc35_pic14_emitcode("; ", "%d left %s", __LINE__, mc35_AopType(AOP_TYPE(IC_LEFT(sic))));

        if (!firstTimeThruLoop)
        {
          /* If this is not the first time we've been through the loop
                   * then we need to save the parameter in a temporary
                   * register. The last byte of the last parameter is
                   * passed in W. */
          mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - --pseudoStkPtr));
        }
        firstTimeThruLoop = 0;

        mc35_mov2w_op(IC_LEFT(sic), offset);
        offset++;
      }
      mc35_freeAsmop(IC_LEFT(sic), NULL, sic, TRUE);
    }
    _G.sendSet = NULL;
  }
  /* make the call */
  sym = OP_SYMBOL(IC_LEFT(ic));
  name = sym->rname[0] ? sym->rname : sym->name;
  /*
   * As SDCC emits code as soon as it reaches the end of each
   * function's definition, prototyped functions that are implemented
   * after the current one are always considered EXTERN, which
   * introduces many unneccessary PAGESEL instructions.
   * XXX: Use a post pass to iterate over all `CALL _name' statements
   * and insert `PAGESEL _name' and `PAGESEL $' around the CALL
   * only iff there is no definition of the function in the whole
   * file (might include this in the PAGESEL pass).
   */
  isExtern = IS_EXTERN(sym->etype) || mc35_inISR;

  if (isExtern)
  {
    /* Extern functions and ISRs maybe on a different page;
       * must call pagesel */
    //mc35_emitpcode(POC_PAGESEL, mc35_popGetWithString(name, 1));    // zwr 1.0.0
  }
  mc35_emitpcode(POC_CALL, mc35_popGetWithString(name, isExtern));
  if (isExtern)
  {
    /* May have returned from a different page;
       * must use pagesel to restore PCLATH before next
       * goto or call instruction */
    //mc35_emitpcode(POC_PAGESEL, mc35_popGetWithString("$", 0));   // zwr 1.0.0
  }
  mc35_GpseudoStkPtr = 0;
  /* if we need assign a result value */
  if ((IS_ITEMP(IC_RESULT(ic)) &&
       (OP_SYMBOL(IC_RESULT(ic))->nRegs || OP_SYMBOL(IC_RESULT(ic))->spildir)) ||
      IS_TRUE_SYMOP(IC_RESULT(ic)))
  {

    _G.accInUse++;
    mc35_aopOp(IC_RESULT(ic), ic, FALSE);
    _G.accInUse--;

    assignResultValue(IC_RESULT(ic));

    DEBUGmc35_pic14_emitcode("; ", "%d left %s", __LINE__, mc35_AopType(AOP_TYPE(IC_RESULT(ic))));

    mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
  }

  /* if register bank was saved then pop them */
  if (ic->bankSaved)
    unsaverbank(FUNC_REGBANK(dtype), ic, TRUE);

  /* if we hade saved some registers then unsave them */
  if (ic->regsSaved && !IFFUNC_CALLEESAVES(dtype))
    unsaveRegisters(ic);
}

/*-----------------------------------------------------------------*/
/* genPcall - generates a call by pointer statement                */
/*-----------------------------------------------------------------*/
static void
genPcall(iCode *ic)
{
  sym_link *dtype;
  symbol *albl = newiTempLabel(NULL);
  symbol *blbl = newiTempLabel(NULL);
  PIC_OPCODE poc;
  pCodeOp *pcop;
  operand *left;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* if caller saves & we have not saved then */
  if (!ic->regsSaved)
    saveRegisters(ic);

  /* if we are calling a function that is not using
     the same register bank then we need to save the
     destination registers on the stack */
  dtype = operandType(IC_LEFT(ic));
  if (currFunc && dtype && IFFUNC_ISISR(currFunc->type) && (FUNC_REGBANK(currFunc->type) != FUNC_REGBANK(dtype)))
    saverbank(FUNC_REGBANK(dtype), ic, TRUE);

  left = IC_LEFT(ic);
  mc35_aopOp(left, ic, FALSE);
  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, NULL);

  poc = (mc35_op_isLitLike(IC_LEFT(ic)) ? POC_MOVLW : POC_MOVFW);

  pushSide(IC_LEFT(ic), FARPTRSIZE);

  /* if send set is not empty, assign parameters */
  if (_G.sendSet)
  {

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d - WARNING arg-passing to indirect call not supported", __FUNCTION__, __LINE__);
    /* no way to pass args - W always gets used to make the call */
  }
  /* first idea - factor out a common helper function and call it.
     But don't know how to get it generated only once in its own block

     if(AOP_TYPE(IC_LEFT(ic)) == AOP_DIR) {
     char *rname;
     char *buffer;
     rname = IC_LEFT(ic)->aop->aopu.aop_dir;
     DEBUGmc35_pic14_emitcode ("; ***","%s  %d AOP_DIR %s",__FUNCTION__,__LINE__,rname);
     buffer = Safe_calloc(1,strlen(rname)+16);
     sprintf(buffer, "%s_goto_helper", rname);
     mc35_addpCode2pBlock(pb,mc35_newpCode(POC_CALL,mc35_newpCodeOp(buffer,PO_STR)));
     free(buffer);
     }
   */
  mc35_emitpcode(POC_CALL, mc35_popGetLabel(albl->key));
  pcop = mc35_popGetLabel(blbl->key);
  mc35_emitpcode(POC_PAGESEL, pcop); /* Must restore PCLATH before goto, without destroying W */
  mc35_emitpcode(POC_GOTO, pcop);
  mc35_emitpLabel(albl->key);

  mc35_emitpcode(poc, mc35_popGetAddr(AOP(left), 1, 0));
  mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_pclath));
  mc35_emitpcode(poc, mc35_popGetAddr(AOP(left), 0, 0));
  mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_pcl));

  mc35_emitpLabel(blbl->key);

  mc35_freeAsmop(IC_LEFT(ic), NULL, ic, TRUE);

  /* if we need to assign a result value */
  if ((IS_ITEMP(IC_RESULT(ic)) &&
       (OP_SYMBOL(IC_RESULT(ic))->nRegs || OP_SYMBOL(IC_RESULT(ic))->spildir)) ||
      IS_TRUE_SYMOP(IC_RESULT(ic)))
  {

    _G.accInUse++;
    mc35_aopOp(IC_RESULT(ic), ic, FALSE);
    _G.accInUse--;

    mc35_GpseudoStkPtr = 0;

    assignResultValue(IC_RESULT(ic));

    mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
  }

  /* if register bank was saved then unsave them */
  if (currFunc && dtype && (FUNC_REGBANK(currFunc->type) != FUNC_REGBANK(dtype)))
    unsaverbank(FUNC_REGBANK(dtype), ic, TRUE);

  /* if we hade saved some registers then
     unsave them */
  if (ic->regsSaved)
    unsaveRegisters(ic);
}

/*-----------------------------------------------------------------*/
/* resultRemat - result  is rematerializable                       */
/*-----------------------------------------------------------------*/
static int
resultRemat(iCode *ic)
{
  //  DEBUGmc35_pic14_emitcode ("; ***","%s  %d",__FUNCTION__,__LINE__);
  FENTRY;

  if (SKIP_IC(ic) || ic->op == IFX)
    return 0;

  if (IC_RESULT(ic) && IS_ITEMP(IC_RESULT(ic)))
  {
    symbol *sym = OP_SYMBOL(IC_RESULT(ic));
    if (sym->remat && !POINTER_SET(ic))
      return 1;
  }

  return 0;
}

/*-----------------------------------------------------------------*/
/* genFunction - generated code for function entry                 */
/*-----------------------------------------------------------------*/
static void
genFunction(iCode *ic)
{
  symbol *sym;
  sym_link *ftype;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d curr label offset=%dprevious mc35_max_key=%d ", __FUNCTION__, __LINE__, mc35_labelOffset,
                           mc35_max_key);

  mc35_labelOffset += (mc35_max_key + 4);
  mc35_max_key = 0;
  mc35_GpseudoStkPtr = 0;
  _G.nRegsSaved = 0;
  /* create the function header */
  mc35_pic14_emitcode(";", "-----------------------------------------");
  mc35_pic14_emitcode(";", " function %s", (sym = OP_SYMBOL(IC_LEFT(ic)))->name);
  mc35_pic14_emitcode(";", "-----------------------------------------");

  /* prevent this symbol from being mc35_emitted as 'extern' */
  mc35_stringInSet(sym->rname, &mc35_localFunctions, 1);

  mc35_pic14_emitcode("", "%s:", sym->rname);
  // zwr 2.0.0
  mc35_addpCode2pBlock(pb, mc35_newpCodeFunction(moduleName, sym->rname, !IS_STATIC(sym->etype), IFFUNC_ISISR(sym->type)));
  // mc35_addpCode2pBlock(pb, mc35_newpCodeFunction(NULL, sym->rname, !IS_STATIC(sym->etype)));

  /* mark symbol as NOT extern (even if it was declared so previously) */
  assert(IS_SPEC(sym->etype));
  SPEC_EXTR(sym->etype) = 0;
  sym->cdef = 0;
  if (!SPEC_OCLS(sym->etype))
    SPEC_OCLS(sym->etype) = code;
  addSetIfnotP(&SPEC_OCLS(sym->etype)->syms, sym);

  ftype = operandType(IC_LEFT(ic));

/* here we need to generate the equates for the
     register bank if required */
#if 0
  if (FUNC_REGBANK (ftype) != rbank)
    {
      int i;

      rbank = FUNC_REGBANK (ftype);
      for (i = 0; i < pic14_nRegs; i++)
        {
          if (strcmp (regspic14[i].base, "0") == 0)
            mc35_pic14_emitcode ("", "%s = 0x%02x", regspic14[i].dname, 8 * rbank + regspic14[i].offset);
          else
            mc35_pic14_emitcode ("", "%s = %s + 0x%02x", regspic14[i].dname, regspic14[i].base, 8 * rbank + regspic14[i].offset);
        }
    }
#endif

  /* if this is an interrupt service routine */
  mc35_inISR = 0;
  if (IFFUNC_ISISR(sym->type))
  {
    mc35_inISR = 1;
    // zwr 2.0.0
    if (!IFFUNC_ISNAKED(sym->type))
    {
      if (mc35_pic->isEnhancedCore)
      // if (mc35_getPIC()->isEnhancedCore)
      {
        /*
            * Enhanced CPUs have automatic context saving for W,
            * STATUS, BSR, FSRx, and PCLATH in shadow registers.
            */
        mc35_emitpcode(POC_CLRF, mc35_popCopyReg(&mc35_pc_pclath));
      }
      else
      {
        // zwr 1.0.0
        // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_wsave));
        // mc35_emitpcode(POC_SWAPFW, mc35_popCopyReg(&mc35_pc_status));
        // /* XXX: Why? Does this assume that ssave and psave reside
        //      * in a shared bank or bank0? We cannot guarantee the
        //      * latter...
        //      */
        // mc35_emitpcode(POC_CLRF, mc35_popCopyReg(&mc35_pc_status));
        // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_ssave));
        // //mc35_emitpcode(POC_MOVWF,  mc35_popGetExternal("___sdcc_saved_status",1 ));
        // mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(&mc35_pc_pclath));
        // /* during an interrupt PCLATH must be cleared before a goto or call statement */
        // mc35_emitpcode(POC_CLRF, mc35_popCopyReg(&mc35_pc_pclath));
        // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_psave));
        // //mc35_emitpcode(POC_MOVWF,  mc35_popGetExternal("___sdcc_saved_pclath", 1));
        // mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(&mc35_pc_fsr));
        // mc35_emitpcode(POC_MOVWF, mc35_popGetExternal("___sdcc_saved_fsr", 1));
      } // if
    }

    mc35_pBlockConvert2ISR(pb);
    mc35_hasInterrupt = 1;
  }
  else
  {
    /* if callee-save to be used for this function
         then save the registers being used in this function */
    if (IFFUNC_CALLEESAVES(sym->type))
    {
      int i;

      /* if any registers used */
      if (sym->regsUsed)
      {
        /* save the registers used */
        for (i = 0; i < sym->regsUsed->size; i++)
        {
          if (bitVectBitValue(sym->regsUsed, i))
          {
            //mc35_pic14_emitcode("push","%s",mc35_pic14_regWithIdx(i)->dname);
            _G.nRegsSaved++;
          }
        }
      }
    }
  }

  /* if critical function then turn interrupts off */
  if (IFFUNC_ISCRITICAL(ftype))
  {
    mc35_genCritical(NULL);
    if (IFFUNC_ARGS(sym->type))
    {
      // zwr 1.0.0
      fprintf(stderr, "MC35: Functions with __critical (%s) must not have arguments for now.\n", sym->name);
      exit(1);
    } // if
  }   // if

  /* set the register bank to the desired value */
  if (FUNC_REGBANK(sym->type) || FUNC_ISISR(sym->type))
  {
    mc35_pic14_emitcode("push", "psw");
    mc35_pic14_emitcode("mov", "psw,#0x%02x", (FUNC_REGBANK(sym->type) << 3) & 0x00ff);
  }

  if (IFFUNC_ISREENT(sym->type) || options.stackAuto)
  {

    if (options.useXstack)
    {
      mc35_pic14_emitcode("mov", "r0,%s", spname);
      mc35_pic14_emitcode("mov", "a,_bp");
      mc35_pic14_emitcode("movx", "@r0,a");
      mc35_pic14_emitcode("inc", "%s", spname);
    }
    else
    {
      /* set up the stack */
      mc35_pic14_emitcode("push", "_bp"); /* save the callers stack  */
    }
    mc35_pic14_emitcode("mov", "_bp,%s", spname);
  }

  /* adjust the stack for the function */
  if (sym->stack)
  {

    int i = sym->stack;
    if (i > 256)
      werror(W_STACK_OVERFLOW, sym->name);

    if (i > 3 && sym->recvSize < 4)
    {

      mc35_pic14_emitcode("mov", "a,sp");
      mc35_pic14_emitcode("add", "a,#0x%02x", ((char)sym->stack & 0xff));
      mc35_pic14_emitcode("mov", "sp,a");
    }
    else
      while (i--)
        mc35_pic14_emitcode("inc", "sp");
  }

  if (sym->xstack)
  {

    mc35_pic14_emitcode("mov", "a,_spx");
    mc35_pic14_emitcode("add", "a,#0x%02x", ((char)sym->xstack & 0xff));
    mc35_pic14_emitcode("mov", "_spx,a");
  }
}

/*-----------------------------------------------------------------*/
/* genEndFunction - generates epilogue for functions               */
/*-----------------------------------------------------------------*/
static void
genEndFunction(iCode *ic)
{
  symbol *sym = OP_SYMBOL(IC_LEFT(ic));

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (IFFUNC_ISREENT(sym->type) || options.stackAuto)
  {
    mc35_pic14_emitcode("mov", "%s,_bp", spname);
  }

  /* if use external stack but some variables were
     added to the local stack then decrement the
     local stack */
  if (options.useXstack && sym->stack)
  {
    mc35_pic14_emitcode("mov", "a,sp");
    mc35_pic14_emitcode("add", "a,#0x%02x", ((char)-sym->stack) & 0xff);
    mc35_pic14_emitcode("mov", "sp,a");
  }

  if ((IFFUNC_ISREENT(sym->type) || options.stackAuto))
  {
    if (options.useXstack)
    {
      mc35_pic14_emitcode("mov", "r0,%s", spname);
      mc35_pic14_emitcode("movx", "a,@r0");
      mc35_pic14_emitcode("mov", "_bp,a");
      mc35_pic14_emitcode("dec", "%s", spname);
    }
    else
    {
      mc35_pic14_emitcode("pop", "_bp");
    }
  }

  /* restore the register bank    */
  if (FUNC_REGBANK(sym->type) || FUNC_ISISR(sym->type))
    mc35_pic14_emitcode("pop", "psw");

  /* if critical function then turn interrupts off */
  if (IFFUNC_ISCRITICAL(sym->type))
  {
    mc35_genEndCritical(NULL);
  } // if

  if (IFFUNC_ISISR(sym->type))
  {

    /* now we need to restore the registers */
    /* if this isr has no bank i.e. is going to
         run with bank 0 , then we need to save more
         registers :-) */
    if (!FUNC_REGBANK(sym->type))
    {

      /* if this function does not call any other
             function then we can be economical and
             save only those registers that are used */
      if (!IFFUNC_HASFCALL(sym->type))
      {
        int i;

        /* if any registers used */
        if (sym->regsUsed)
        {
          /* save the registers used */
          for (i = sym->regsUsed->size; i >= 0; i--)
          {
            if (bitVectBitValue(sym->regsUsed, i))
            {
              mc35_pic14_emitcode("pop", "junk"); //"%s",mc35_pic14_regWithIdx(i)->dname);
            }
          }
        }
      }
      else
      {
        /* this function has a function call; cannot
                 determines register usage so we will have the
                 entire bank */
        unsaverbank(0, ic, FALSE);
      }
    }

    /* if debug then send end of function */
    if (options.debug && debugFile && currFunc)
    {
      debugFile->writeEndFunction(currFunc, ic, 1);
    }

    // zwr 2.0.0
    if (!mc35_pic->isEnhancedCore && !IFFUNC_ISNAKED(sym->type))
    // if (mc35_getPIC()->isEnhancedCore)
    // {
    //   /* Nothing to do. */
    // }
    // else
    {
      // zwr 1.0.0
      // mc35_emitpcode(POC_MOVFW, mc35_popGetExternal("___sdcc_saved_fsr", 1));
      // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr));
      // //mc35_emitpcode(POC_MOVFW,  mc35_popGetExternal("___sdcc_saved_pclath", 1));
      // mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(&mc35_pc_psave));
      // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_pclath));
      // mc35_emitpcode(POC_CLRF, mc35_popCopyReg(&mc35_pc_status)); // see genFunction
      // //mc35_emitpcode(POC_SWAPFW, mc35_popGetExternal("___sdcc_saved_status", 1));
      // mc35_emitpcode(POC_SWAPFW, mc35_popCopyReg(&mc35_pc_ssave));
      // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_status));
      // mc35_emitpcode(POC_SWAPF, mc35_popCopyReg(&mc35_pc_wsave));
      // mc35_emitpcode(POC_SWAPFW, mc35_popCopyReg(&mc35_pc_wsave));
    } // if
    mc35_addpCode2pBlock(pb, mc35_newpCodeLabel("END_OF_INTERRUPT", -1));
    mc35_emitpcodeNULLop(POC_RETFIE);
  }
  else
  {
    if (IFFUNC_ISCRITICAL(sym->type))
      mc35_pic14_emitcode("setb", "ea");

    if (IFFUNC_CALLEESAVES(sym->type))
    {
      int i;

      /* if any registers used */
      if (sym->regsUsed)
      {
        /* save the registers used */
        for (i = sym->regsUsed->size; i >= 0; i--)
        {
          if (bitVectBitValue(sym->regsUsed, i))
          {
            mc35_pic14_emitcode("pop", "junk"); //"%s",mc35_pic14_regWithIdx(i)->dname);
          }
        }
      }
    }

    /* if debug then send end of function */
    if (options.debug && debugFile && currFunc)
    {
      debugFile->writeEndFunction(currFunc, ic, 1);
    }

    mc35_pic14_emitcode("return", "");
    mc35_emitpcodeNULLop(POC_RETURN);

    /* Mark the end of a function */
    // zwr 2.0.0
    mc35_addpCode2pBlock(pb, mc35_newpCodeFunction(moduleName, NULL, 0, 0));
    // mc35_addpCode2pBlock(pb, mc35_newpCodeFunction(NULL, NULL, 0));
  }
}

/*-----------------------------------------------------------------*/
/* genRet - generate code for return statement                     */
/*-----------------------------------------------------------------*/
static void
genRet(iCode *ic)
{
  int size, offset = 0;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* if we have no return value then
     just generate the "ret" */
  if (!IC_LEFT(ic))
    goto jumpret;

  /* we have something to return then
     move the return value into place */
  mc35_aopOp(IC_LEFT(ic), ic, FALSE);
  size = AOP_SIZE(IC_LEFT(ic));

  for (offset = 0; offset < size; offset++)
  {
    pass_argument(IC_LEFT(ic), offset, size - 1 - offset);
  }

  mc35_freeAsmop(IC_LEFT(ic), NULL, ic, TRUE);

jumpret:
  /* generate a jump to the return label
     if the next is not the return statement */
  if (!(ic->next && ic->next->op == LABEL && IC_LABEL(ic->next) == returnLabel))
  {

    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(returnLabel->key));
  }
}

static set *critical_temps = NULL;

static void
mc35_genCritical(iCode *ic)
{
  pCodeOp *saved_intcon;

  (void)ic;

  if (!critical_temps)
    critical_temps = newSet();

  saved_intcon = mc35_popGetTempReg();
  addSetHead(&critical_temps, saved_intcon);

  /* This order saves one BANKSEL back to INTCON. */
  mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(&mc35_pc_intcon));
  mc35_emitpcode(POC_BCF, mc35_popCopyGPR2Bit(mc35_popCopyReg(&mc35_pc_intcon), 7));
  mc35_emitpcode(POC_MOVWF, mc35_pCodeOpCopy(saved_intcon));
}

static void
mc35_genEndCritical(iCode *ic)
{
  pCodeOp *saved_intcon = NULL;

  (void)ic;

  saved_intcon = getSet(&critical_temps);
  if (!saved_intcon)
  {
    fprintf(stderr, "Critical section left, but none entered -- ignoring for now.\n");
    return;
  } // if

  mc35_emitpcode(POC_BTFSC, mc35_popCopyGPR2Bit(mc35_pCodeOpCopy(saved_intcon), 7));
  mc35_emitpcode(POC_BSF, mc35_popCopyGPR2Bit(mc35_popCopyReg(&mc35_pc_intcon), 7));
  popReleaseTempReg(saved_intcon);
}

/*-----------------------------------------------------------------*/
/* genLabel - generates a label                                    */
/*-----------------------------------------------------------------*/
static void
genLabel(iCode *ic)
{
  FENTRY;

  /* special case never generate */
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (IC_LABEL(ic) == entryLabel)
    return;

  mc35_emitpLabel(IC_LABEL(ic)->key);
  mc35_pic14_emitcode("", "_%05d_DS_:", labelKey2num(IC_LABEL(ic)->key + mc35_labelOffset));
}

/*-----------------------------------------------------------------*/
/* genGoto - generates a goto                                      */
/*-----------------------------------------------------------------*/
//tsd
static void
genGoto(iCode *ic)
{
  FENTRY;

  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_LABEL(ic)->key));
  mc35_pic14_emitcode("goto", "_%05d_DS_", labelKey2num(IC_LABEL(ic)->key + mc35_labelOffset));
}

/*-----------------------------------------------------------------*/
/* genMultbits :- multiplication of bits                           */
/*-----------------------------------------------------------------*/
static void
genMultbits(operand *left, operand *right, operand *result)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (!mc35_sameRegs(AOP(result), AOP(right)))
    mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));

  mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(right), 0));
  mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(left), 0));
  mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));
}

/*-----------------------------------------------------------------*/
/* genMultOneByte : 8 bit multiplication & division                */
/*-----------------------------------------------------------------*/
static void
genMultOneByte(operand *left, operand *right, operand *result)
{
  char *func[] = {NULL, "__mulchar", "__mulint", NULL, "__mullong"};

  // symbol *lbl ;
  int size, offset, i;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);
  DEBUGmc35_pic14_AopTypeSign(__LINE__, left, right, result);

  /* (if two literals, the value is computed before) */
  /* if one literal, literal on the right */
  if (AOP_TYPE(left) == AOP_LIT)
  {
    operand *t = right;
    right = left;
    left = t;
  }

  assert(AOP_SIZE(left) == AOP_SIZE(right));

  size = min(AOP_SIZE(result), AOP_SIZE(left));
  offset = mc35_Gstack_base_addr - (2 * size - 1);

  /* pass right operand as argument */
  for (i = 0; i < size; i++)
  {
    mc35_mov2w(AOP(right), i);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(++offset));
  } // for

  /* pass left operand as argument */
  for (i = 0; i < size; i++)
  {
    mc35_mov2w(AOP(left), i);
    if (i != size - 1)
      mc35_emitpcode(POC_MOVWF, popRegFromIdx(++offset));
  } // for
  assert(offset == mc35_Gstack_base_addr);

  /* call library routine */
  assert(size > 0 && size <= 4);
  call_libraryfunc(func[size]);

  /* assign result */
  movwf(AOP(result), size - 1);
  for (i = 0; i < size - 1; i++)
  {
    mc35_emitpcode(POC_MOVFW, popRegFromIdx(mc35_Gstack_base_addr - i));
    movwf(AOP(result), size - 2 - i);
  } // for

  /* now (zero-/sign) extend the result to its size */
  mc35_addSign(result, AOP_SIZE(left), !SPEC_USIGN(operandType(result)));
}

/*-----------------------------------------------------------------*/
/* genMult - generates code for multiplication                     */
/*-----------------------------------------------------------------*/
static void
genMult(iCode *ic)
{
  operand *left = IC_LEFT(ic);
  operand *right = IC_RIGHT(ic);
  operand *result = IC_RESULT(ic);

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* assign the amsops */
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  /* special cases first */
  /* both are bits */
  if (AOP_TYPE(left) == AOP_CRY && AOP_TYPE(right) == AOP_CRY)
  {
    genMultbits(left, right, result);
    goto release;
  }

  /* if both are of size == 1 */
  if (AOP_SIZE(left) == 1 && AOP_SIZE(right) == 1)
  {
    genMultOneByte(left, right, result);
    goto release;
  }

  /* should have been converted to function call */
  assert(0);

release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genDivbits :- division of bits                                  */
/*-----------------------------------------------------------------*/
static void
genDivbits(operand *left, operand *right, operand *result)
{

  char *l;

  FENTRY;

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* the result must be bit */
  mc35_pic14_emitcode("mov", "b,%s", mc35_aopGet(AOP(right), 0, FALSE, FALSE));
  l = mc35_aopGet(AOP(left), 0, FALSE, FALSE);

  MOVA(l);

  mc35_pic14_emitcode("div", "ab");
  mc35_pic14_emitcode("rrc", "a");
  mc35_aopPut(AOP(result), "c", 0);
}

/*-----------------------------------------------------------------*/
/* genDivOneByte : 8 bit division                                  */
/*-----------------------------------------------------------------*/
static void
genDivOneByte(operand *left, operand *right, operand *result)
{
  int sign;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  assert(AOP_SIZE(right) == 1);
  assert(AOP_SIZE(left) == 1);

  sign = !(SPEC_USIGN(operandType(left)) && SPEC_USIGN(operandType(right)));

  if (AOP_TYPE(right) == AOP_LIT)
  {
    /* XXX: might add specialized code */
  }

  if (!sign)
  {
/* unsigned division */
#if 1
    mc35_mov2w(AOP(right), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(left), 0);
    call_libraryfunc("__divuchar");
    movwf(AOP(result), 0);
#else
    pCodeOp *temp;
    symbol *lbl;

    temp = mc35_popGetTempReg();
    lbl = newiTempLabel(NULL);

    /* XXX: improve this naive approach:
         [result] = [a] / [b]
         ::= [result] = 0; while ([a] > [b]) do [a] -= [b]; [result]++ done

         In PIC assembler:
         movf  left,W
         movwf temp       // temp <-- left
         movf  right,W    // W <-- right
         clrf  result
         label1:
         incf  result
         subwf temp,F     // temp <-- temp - W
         skipNC       // subwf clears CARRY (i.e. sets BORROW) if temp < W
         goto  label1
         decf result      // we just subtract once too often
       */

    /* XXX: This loops endlessly on DIVIDE BY ZERO */
    /* We need 1..128 iterations of the loop body (`4 / 5' .. `255 / 2'). */

    mc35_mov2w(AOP(left), 0);
    mc35_emitpcode(POC_MOVWF, temp);
    mc35_mov2w(AOP(right), 0);
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), 0));

    mc35_emitpLabel(lbl->key);
    mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
    mc35_emitpcode(POC_SUBWF, temp);
    mc35_emitSKPNC;
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl->key));
    mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), 0));
    popReleaseTempReg(temp);
#endif
  }
  else
  {
    /* signed division */
    mc35_mov2w(AOP(right), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(left), 0);
    call_libraryfunc("__divschar");
    movwf(AOP(result), 0);
  }

  /* now performed the signed/unsigned division -- extend result */
  mc35_addSign(result, 1, sign);
}

/*-----------------------------------------------------------------*/
/* genDiv - generates code for division                */
/*-----------------------------------------------------------------*/
static void
genDiv(iCode *ic)
{
  operand *left = IC_LEFT(ic);
  operand *right = IC_RIGHT(ic);
  operand *result = IC_RESULT(ic);

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* assign the amsops */
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  /* special cases first */
  /* both are bits */
  if (AOP_TYPE(left) == AOP_CRY && AOP_TYPE(right) == AOP_CRY)
  {
    genDivbits(left, right, result);
    goto release;
  }

  /* if both are of size == 1 */
  if (AOP_SIZE(left) == 1 && AOP_SIZE(right) == 1)
  {
    genDivOneByte(left, right, result);
    goto release;
  }

  /* should have been converted to function call */
  assert(0);
release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genModOneByte : 8 bit modulus                                   */
/*-----------------------------------------------------------------*/
static void
genModOneByte(operand *left, operand *right, operand *result)
{
  int sign;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  assert(AOP_SIZE(right) == 1);
  assert(AOP_SIZE(left) == 1);

  sign = !(SPEC_USIGN(operandType(left)) && SPEC_USIGN(operandType(right)));

  if (AOP_TYPE(right) == AOP_LIT)
  {
    /* XXX: might add specialized code */
  }

  if (!sign)
  {
/* unsigned division */
#if 1
    mc35_mov2w(AOP(right), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(left), 0);
    call_libraryfunc("__moduchar");
    movwf(AOP(result), 0);
#else
    pCodeOp *temp;
    symbol *lbl;

    lbl = newiTempLabel(NULL);

    assert(!mc35_sameRegs(AOP(right), AOP(result)));

    /* XXX: improve this naive approach:
         [result] = [a] % [b]
         ::= [result] = [a]; while ([result] > [b]) do [result] -= [b]; done

         In PIC assembler:
         movf  left,W
         movwf result     // result <-- left
         movf  right,W    // W <-- right
         label1:
         subwf result,F   // result <-- result - W
         skipNC       // subwf clears CARRY (i.e. sets BORROW) if result < W
         goto  label1
         addwf result, F  // we just subtract once too often
       */

    /* XXX: This loops endlessly on DIVIDE BY ZERO */
    /* We need 1..128 iterations of the loop body (`4 % 5' .. `255 % 2'). */

    if (!mc35_sameRegs(AOP(left), AOP(result)))
    {
      mc35_mov2w(AOP(left), 0);
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));
    }
    mc35_mov2w(AOP(right), 0);

    mc35_emitpLabel(lbl->key);
    mc35_emitpcode(POC_SUBWF, mc35_popGet(AOP(result), 0));
    mc35_emitSKPNC;
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl->key));
    mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), 0));
#endif
  }
  else
  {
    /* signed division */
    mc35_mov2w(AOP(right), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(left), 0);
    call_libraryfunc("__modschar");
    movwf(AOP(result), 0);
  }

  /* now we performed the signed/unsigned modulus -- extend result */
  mc35_addSign(result, 1, sign);
}

/*-----------------------------------------------------------------*/
/* genMod - generates code for division                            */
/*-----------------------------------------------------------------*/
static void
genMod(iCode *ic)
{
  operand *left = IC_LEFT(ic);
  operand *right = IC_RIGHT(ic);
  operand *result = IC_RESULT(ic);

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* assign the amsops */
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  /* if both are of size == 1 */
  if (AOP_SIZE(left) == 1 && AOP_SIZE(right) == 1)
  {
    genModOneByte(left, right, result);
    goto release;
  }

  /* should have been converted to function call */
  assert(0);

release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genIfxJump :- will create a jump depending on the ifx           */
/*-----------------------------------------------------------------*/
/*
note: May need to add parameter to indicate when a variable is in bit space.
*/
static void
genIfxJump(iCode *ic, char *jval)
{

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* if true label then we jump if condition
     supplied is true */
  if (IC_TRUE(ic))
  {

    if (strcmp(jval, "a") == 0)
      mc35_emitSKPZ;
    else if (strcmp(jval, "c") == 0)
      mc35_emitSKPC;
    else
    {
      DEBUGmc35_pic14_emitcode("; ***", "%d - assuming %s is in bit space", __LINE__, jval);
      mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(jval, -1, 1));
    }

    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_TRUE(ic)->key));
    mc35_pic14_emitcode(" goto", "_%05d_DS_", labelKey2num(IC_TRUE(ic)->key + mc35_labelOffset));
  }
  else
  {
    /* false label is present */
    if (strcmp(jval, "a") == 0)
      mc35_emitSKPNZ;
    else if (strcmp(jval, "c") == 0)
      mc35_emitSKPNC;
    else
    {
      DEBUGmc35_pic14_emitcode("; ***", "%d - assuming %s is in bit space", __LINE__, jval);
      mc35_emitpcode(POC_BTFSS, mc35_newpCodeOpBit(jval, -1, 1));
    }

    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_FALSE(ic)->key));
    mc35_pic14_emitcode(" goto", "_%05d_DS_", labelKey2num(IC_FALSE(ic)->key + mc35_labelOffset));
  }

  /* mark the icode as generated */
  ic->generated = TRUE;
}

/*-----------------------------------------------------------------*/
/* genSkipc                                                        */
/*-----------------------------------------------------------------*/
static void
genSkipc(resolvedIfx *rifx)
{
  FENTRY;
  if (!rifx)
    return;

  if (rifx->condition)
    mc35_emitSKPNC;
  else
    mc35_emitSKPC;

  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rifx->lbl->key));
  mc35_emitpComment("%s:%u: created from rifx:%p", __FUNCTION__, __LINE__, rifx);
  rifx->generated = TRUE;
}

#define isAOP_REGlike(x) (AOP_TYPE(x) == AOP_REG || AOP_TYPE(x) == AOP_DIR || AOP_TYPE(x) == AOP_PCODE)
#define isAOP_LIT(x) (AOP_TYPE(x) == AOP_LIT)
#define DEBUGpc mc35_emitpComment

/*-----------------------------------------------------------------*/
/* mov2w_regOrLit :- move to WREG either the offset's byte from    */
/*                  aop (if it's NOT a literal) or from lit (if    */
/*                  aop is a literal)                              */
/*-----------------------------------------------------------------*/
static void
mc35_mov2w_regOrLit(asmop *aop, unsigned long lit, int offset)
{
  if (aop->type == AOP_LIT)
  {
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit((lit >> (offset * 8)) & 0x00FF));
  }
  else
  {
    mc35_emitpcode(POC_MOVFW, mc35_popGet(aop, offset));
  }
}

/* genCmp performs a left < right comparison, stores
 * the outcome in result (if != NULL) and generates
 * control flow code for the ifx (if != NULL).
 *
 * This version leaves in sequences like
 * "B[CS]F STATUS,0; BTFS[CS] STATUS,0"
 * which should be optmized by the peephole
 * optimizer - RN 2005-01-01 */
static void
genCmp(operand *left, operand *right, operand *result, iCode *ifx, int sign)
{
  resolvedIfx rIfx;
  int size;
  int offs;
  symbol *templbl;
  operand *dummy;
  unsigned long lit;
  unsigned long mask;
  int performedLt;
  int invert_result = 0;

  FENTRY;

  assert(AOP_SIZE(left) == AOP_SIZE(right));
  assert(left && right);

  size = AOP_SIZE(right) - 1;
  mask = (0x100UL << (size * 8)) - 1;
  // in the end CARRY holds "left < right" (performedLt == 1) or "left >= right" (performedLt == 0)
  performedLt = 1;
  templbl = NULL;
  lit = 0;

  resolveIfx(&rIfx, ifx);

/**********************************************************************
   * handle bits - bit compares are promoted to int compares seemingly! *
   **********************************************************************/
#if 0
  // THIS IS COMPLETELY UNTESTED!
  if (AOP_TYPE (left) == AOP_CRY && AOP_TYPE (right) == AOP_CRY)
    {
      pCodeOp *pcleft = pic16_mc35_popGet (AOP (left), 0);
      pCodeOp *pcright = pic16_mc35_popGet (AOP (right), 0);
      assert (pcleft->type == PO_GPR_BIT && pcright->type == PO_GPR_BIT);

      mc35_emitSETC;
      // 1 < {0,1} is false --> clear C by skipping the next instruction
      //pic16_mc35_emitpcode (POC_BTFSS, pic16_popCopyGPR2Bit (AOP (left),0), PCORB (pcleft)->bit);
      pic16_mc35_emitpcode (POC_BTFSS, pic16_mc35_popGet (AOP (left), 0));
      // {0,1} < 0 is false --> clear C by NOT skipping the next instruction
      pic16_mc35_emitpcode (POC_BTFSS, pic16_popCopyGPR2Bit (pic16_mc35_popGet (AOP (right), 0), PCORB (pcright)->bit));
      mc35_emitCLRC;                 // only skipped for left=0 && right=1

      goto correct_result_in_carry;
    }                           // if
#endif

  /*************************************************
   * make sure that left is register (or the like) *
   *************************************************/
  if (!isAOP_REGlike(left))
  {
    DEBUGpc("swapping arguments (AOP_TYPEs %d/%d)", AOP_TYPE(left), AOP_TYPE(right));
    assert(isAOP_LIT(left));
    assert(isAOP_REGlike(right));
    // swap left and right
    // left < right <==> right > left <==> (right >= left + 1)
    lit = ulFromVal(AOP(left)->aopu.aop_lit);

    if ((!sign && (lit & mask) == mask) || (sign && (lit & mask) == (mask >> 1)))
    {
      // MAXVALUE < right? always false
      if (performedLt)
        mc35_emitCLRC;
      else
        mc35_emitSETC;
      goto correct_result_in_carry;
    } // if

    // This fails for lit = 0xFF (unsigned) AND lit = 0x7F (signed),
    // that's why we handled it above.
    lit++;

    dummy = left;
    left = right;
    right = dummy;

    performedLt ^= 1; // instead of "left < right" we check for "right >= left+1, i.e. "right < left+1"
  }
  else if (isAOP_LIT(right))
  {
    lit = ulFromVal(AOP(right)->aopu.aop_lit);
  } // if

  assert(isAOP_REGlike(left));                      // left must be register or the like
  assert(isAOP_REGlike(right) || isAOP_LIT(right)); // right may be register-like or a literal

  /*************************************************
   * special cases go here                         *
   *************************************************/

  if (isAOP_LIT(right))
  {
    if (!sign)
    {
      // unsigned comparison to a literal
      DEBUGpc("unsigned compare: left %s lit(0x%X=%lu), size=%d", performedLt ? "<" : ">=", lit, lit, size + 1);
      if (lit == 0)
      {
        // unsigned left < 0? always false
        if (performedLt)
          mc35_emitCLRC;
        else
          mc35_emitSETC;
        goto correct_result_in_carry;
      }
    }
    else
    {
      // signed comparison to a literal
      DEBUGpc("signed compare: left %s lit(0x%X=%ld), size=%d, mask=%x", performedLt ? "<" : ">=", lit, lit, size + 1,
              mask);
      if ((lit & mask) == ((0x80 << (size * 8)) & mask))
      {
        // signed left < 0x80000000? always false
        if (performedLt)
          mc35_emitCLRC;
        else
          mc35_emitSETC;
        goto correct_result_in_carry;
      }
      else if (lit == 0)
      {
        // compare left < 0; set CARRY if SIGNBIT(left) is set
        if (performedLt)
          mc35_emitSETC;
        else
          mc35_emitCLRC;
        mc35_emitpcode(POC_BTFSS, mc35_newpCodeOpBit(mc35_aopGet(AOP(left), size, FALSE, FALSE), 7, 0));
        if (performedLt)
          mc35_emitCLRC;
        else
          mc35_emitSETC;
        goto correct_result_in_carry;
      }
    } // if (!sign)
  }   // right is literal

  /*************************************************
   * perform a general case comparison             *
   * make sure we get CARRY==1 <==> left >= right  *
   *************************************************/
  // compare most significant bytes
  //DEBUGpc ("comparing bytes at offset %d", size);
  if (!sign)
  {
    // unsigned comparison
    mc35_mov2w_regOrLit(AOP(right), lit, size);
    // zwr 1.0.0 inst rsubar #1
    // mc35_emitpcode(POC_SUBFW, mc35_popGet(AOP(left), size));
    mc35_emitpcode(POC_XCH, mc35_popGet(AOP(left), size));
    mc35_emitpcode(POC_SUBWF, mc35_popGet(AOP(left), size));
    mc35_emitpcode(POC_XCH, mc35_popGet(AOP(left), size));
  }
  else
  {
    // signed comparison
    // (add 2^n to both operands then perform an unsigned comparison)
    if (isAOP_LIT(right))
    {
      // left >= LIT <-> LIT-left <= 0 <-> LIT-left == 0 OR !(LIT-left >= 0)
      unsigned char litbyte = (lit >> (8 * size)) & 0xFF;

      if (litbyte == 0x80)
      {
        // left >= 0x80 -- always true, but more bytes to come
        mc35_mov2w(AOP(left), size);
        mc35_emitpcode(POC_XORLW, mc35_popGetLit(0x80)); // set ZERO flag
        mc35_emitSETC;
      }
      else
      {
        // left >= LIT <-> left + (-LIT) >= 0 <-> left + (0x100-LIT) >= 0x100
        mc35_mov2w(AOP(left), size);
        mc35_emitpcode(POC_ADDLW, mc35_popGetLit(0x80));
        mc35_emitpcode(POC_ADDLW, mc35_popGetLit((0x100 - (litbyte + 0x80)) & 0x00FF));
      } // if
    }
    else
    {
      pCodeOp *pctemp = mc35_popGetTempReg();
      mc35_mov2w(AOP(left), size);
      mc35_emitpcode(POC_ADDLW, mc35_popGetLit(0x80));
      mc35_emitpcode(POC_MOVWF, pctemp);
      mc35_mov2w(AOP(right), size);
      mc35_emitpcode(POC_ADDLW, mc35_popGetLit(0x80));
      // zwr 1.0.0 inst rsubar #1
      // mc35_emitpcode(POC_SUBFW, pctemp);
      mc35_emitpcode(POC_XCH, pctemp);
      mc35_emitpcode(POC_SUBWF, pctemp);
      mc35_emitpcode(POC_XCH, pctemp);
      popReleaseTempReg(pctemp);
    }
  } // if (!sign)

  // compare remaining bytes (treat as unsigned case from above)
  templbl = newiTempLabel(NULL);
  offs = size;
  while (offs--)
  {
    //DEBUGpc ("comparing bytes at offset %d", offs);
    mc35_emitSKPZ;
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(templbl->key));
    mc35_mov2w_regOrLit(AOP(right), lit, offs);
    // zwr 1.0.0 inst rsubar #1
    // mc35_emitpcode(POC_SUBFW, mc35_popGet(AOP(left), offs));
    mc35_emitpcode(POC_XCH, mc35_popGet(AOP(left), offs));
    mc35_emitpcode(POC_SUBWF, mc35_popGet(AOP(left), offs));
    mc35_emitpcode(POC_XCH, mc35_popGet(AOP(left), offs));
  } // while (offs)
  mc35_emitpLabel(templbl->key);
  goto result_in_carry;

result_in_carry:

  /****************************************************
   * now CARRY contains the result of the comparison: *
   * SUBWF sets CARRY iff                             *
   * F-W >= 0 <==> F >= W <==> !(F < W)               *
   * (F=left, W=right)                                *
   ****************************************************/

  if (performedLt)
  {
    invert_result = 1;
    // value will be used in the following genSkipc ()
    rIfx.condition ^= TRUE;
  } // if

correct_result_in_carry:

  // assign result to variable (if neccessary), but keep CARRY intact to be used below
  if (result && AOP_TYPE(result) != AOP_CRY)
  {
    //DEBUGpc ("assign result");
    size = AOP_SIZE(result);
    while (size--)
    {
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), size));
    } // while
    if (invert_result)
    {
      mc35_emitSKPC;
      mc35_emitpcode(POC_BSF, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 0, FALSE, FALSE), 0, 0));
    }
    else
    {
      mc35_emitpcode(POC_RLF, mc35_popGet(AOP(result), 0));
      if (ifx)
      {
        /* Result is expected to be in CARRY by genSkipc () below. */
        mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(result), 0));
      } // if
    }   // if
  }     // if (result)

  // perform conditional jump
  if (ifx)
  {
    //DEBUGpc ("generate control flow");
    genSkipc(&rIfx);
    ifx->generated = TRUE;
  } // if
}

/*-----------------------------------------------------------------*/
/* genCmpGt :- greater than comparison                             */
/*-----------------------------------------------------------------*/
static void
genCmpGt(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  sym_link *letype, *retype;
  int sign;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  left = IC_LEFT(ic);
  right = IC_RIGHT(ic);
  result = IC_RESULT(ic);

  sign = 0;
  if (IS_SPEC(operandType(left)) && IS_SPEC(operandType(right)))
  {
    letype = getSpec(operandType(left));
    retype = getSpec(operandType(right));
    sign = !(SPEC_USIGN(letype) | SPEC_USIGN(retype));
  }

  /* assign the amsops */
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  genCmp(right, left, result, ifx, sign);

  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genCmpLt - less than comparisons                                */
/*-----------------------------------------------------------------*/
static void
genCmpLt(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  sym_link *letype, *retype;
  int sign;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  left = IC_LEFT(ic);
  right = IC_RIGHT(ic);
  result = IC_RESULT(ic);

  sign = 0;
  if (IS_SPEC(operandType(left)) && IS_SPEC(operandType(right)))
  {
    letype = getSpec(operandType(left));
    retype = getSpec(operandType(right));
    sign = !(SPEC_USIGN(letype) | SPEC_USIGN(retype));
  }

  /* assign the amsops */
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  genCmp(left, right, result, ifx, sign);

  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genCmpEq - generates code for equal to                          */
/*-----------------------------------------------------------------*/
static void
genCmpEq(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  int size;
  symbol *false_label;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (ifx)
    DEBUGmc35_pic14_emitcode("; ifx is non-null", "");
  else
    DEBUGmc35_pic14_emitcode("; ifx is null", "");

  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  /* if literal, move literal to right */
  if (mc35_op_isLitLike(IC_LEFT(ic)))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  false_label = NULL;
  if (ifx && !IC_TRUE(ifx))
  {
    assert(IC_FALSE(ifx));
    false_label = IC_FALSE(ifx);
  }

  size = min(AOP_SIZE(left), AOP_SIZE(right));
  assert(!mc35_sameRegs(AOP(result), AOP(left)));
  assert(!mc35_sameRegs(AOP(result), AOP(right)));

  /* assume left != right */
  {
    int i;
    for (i = 0; i < AOP_SIZE(result); i++)
    {
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), i));
    }
  }

  if (AOP_TYPE(right) == AOP_LIT)
  {
    unsigned long lit = ulFromVal(AOP(right)->aopu.aop_lit);
    int i;
    size = AOP_SIZE(left);
    assert(!mc35_op_isLitLike(left));

    switch (lit)
    {
    case 0:
      mc35_mov2w(AOP(left), 0);
      for (i = 1; i < size; i++)
        mc35_emitpcode(POC_IORFW, mc35_popGet(AOP(left), i));
      /* now Z is set iff `left == right' */
      mc35_emitSKPZ;
      if (!false_label)
        false_label = newiTempLabel(NULL);
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(false_label->key));
      break;

    default:
      for (i = 0; i < size; i++)
      {
        mc35_mov2w(AOP(left), i);
        mc35_emitpcode(POC_XORLW, mc35_popGetLit(lit >> (8 * i)));
        /* now Z is cleared if `left != right' */
        mc35_emitSKPZ;
        if (!false_label)
          false_label = newiTempLabel(NULL);
        mc35_emitpcode(POC_GOTO, mc35_popGetLabel(false_label->key));
      } // for i
      break;
    } // switch (lit)
  }
  else
  {
    /* right is no literal */
    int i;

    for (i = 0; i < size; i++)
    {
      mc35_mov2w(AOP(right), i);
      mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(left), i));
      /* now Z is cleared if `left != right' */
      mc35_emitSKPZ;
      if (!false_label)
        false_label = newiTempLabel(NULL);
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(false_label->key));
    } // for i
  }

  /* if we reach here, left == right */

  if (AOP_SIZE(result) > 0)
  {
    // zwr 1.0.0 inst incr #2
    // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
    mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
    mc35_emitpcodeNULLop(POC_NOP);
  }

  if (ifx && IC_TRUE(ifx))
  {
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_TRUE(ifx)->key));
  }

  if (false_label && (!ifx || IC_TRUE(ifx)))
    mc35_emitpLabel(false_label->key);

  if (ifx)
    ifx->generated = TRUE;

  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genAndOp - for && operation                                     */
/*-----------------------------------------------------------------*/
static void
genAndOp(iCode *ic)
{
  operand *left, *right, *result;
  /*     symbol *tlbl; */

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* note here that && operations that are in an
     if statement are taken away by backPatchLabels
     only those used in arthmetic operations remain */
  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), 0));
  mc35_emitpcode(POC_ANDFW, mc35_popGet(AOP(right), 0));
  mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));

  /* if both are bit variables */
  /*     if (AOP_TYPE(left) == AOP_CRY && */
  /*         AOP_TYPE(right) == AOP_CRY ) { */
  /*         mc35_pic14_emitcode("mov","c,%s",AOP(left)->aopu.aop_dir); */
  /*         mc35_pic14_emitcode("anl","c,%s",AOP(right)->aopu.aop_dir); */
  /*         pic14_outBitC(result); */
  /*     } else { */
  /*         tlbl = newiTempLabel(NULL); */
  /*         pic14_toBoolean(left);     */
  /*         mc35_pic14_emitcode("jz","%05d_DS_",labelKey2num (tlbl->key)); */
  /*         pic14_toBoolean(right); */
  /*         mc35_pic14_emitcode("","%05d_DS_:",labelKey2num (tlbl->key)); */
  /*         pic14_outBitAcc(result); */
  /*     } */

  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genOrOp - for || operation                                      */
/*-----------------------------------------------------------------*/
/*
tsd pic port -
modified this code, but it doesn't appear to ever get called
*/

static void
genOrOp(iCode *ic)
{
  operand *left, *right, *result;
  symbol *tlbl;
  int i;

  /* note here that || operations that are in an
     if statement are taken away by backPatchLabels
     only those used in arthmetic operations remain */
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  for (i = 0; i < AOP_SIZE(result); i++)
  {
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), i));
  } // for i

  tlbl = newiTempLabel(NULL);
  pic14_toBoolean(left);
  mc35_emitSKPZ;
  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(tlbl->key));
  pic14_toBoolean(right);
  mc35_emitpLabel(tlbl->key);
  /* here Z is clear IFF `left || right' */
  mc35_emitSKPZ;
  // zwr 1.0.0 inst incr #2
  // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
  mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
  mc35_emitpcodeNULLop(POC_NOP);

  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* isLiteralBit - test if lit == 2^n                               */
/*-----------------------------------------------------------------*/
static int
isLiteralBit(unsigned long lit)
{
  unsigned long pw[32] = {1L, 2L, 4L, 8L, 16L, 32L, 64L, 128L,
                          0x100L, 0x200L, 0x400L, 0x800L,
                          0x1000L, 0x2000L, 0x4000L, 0x8000L,
                          0x10000L, 0x20000L, 0x40000L, 0x80000L,
                          0x100000L, 0x200000L, 0x400000L, 0x800000L,
                          0x1000000L, 0x2000000L, 0x4000000L, 0x8000000L,
                          0x10000000L, 0x20000000L, 0x40000000L, 0x80000000L};
  int idx;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  for (idx = 0; idx < 32; idx++)
    if (lit == pw[idx])
      return idx + 1;
  return 0;
}

/*-----------------------------------------------------------------*/
/* continueIfTrue -                                                */
/*-----------------------------------------------------------------*/
static void
continueIfTrue(iCode *ic)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (IC_TRUE(ic))
  {
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(labelKey2num(IC_TRUE(ic)->key)));
    mc35_pic14_emitcode("ljmp", "%05d_DS_", labelKey2num(IC_FALSE(ic)->key));
  }
  ic->generated = TRUE;
}

/*-----------------------------------------------------------------*/
/* jmpIfTrue -                                                     */
/*-----------------------------------------------------------------*/
static void
jumpIfTrue(iCode *ic)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (!IC_TRUE(ic))
  {
    mc35_emitpcode(POC_GOTO, labelKey2num(mc35_popGetLabel(IC_TRUE(ic)->key)));
    mc35_pic14_emitcode("ljmp", "%05d_DS_", labelKey2num(IC_FALSE(ic)->key));
  }
  ic->generated = TRUE;
}

/*-----------------------------------------------------------------*/
/* jmpTrueOrFalse -                                                */
/*-----------------------------------------------------------------*/
static void
jmpTrueOrFalse(iCode *ic, symbol *tlbl)
{
  FENTRY;
  // ugly but optimized by peephole
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (IC_TRUE(ic))
  {
    symbol *nlbl = newiTempLabel(NULL);
    mc35_pic14_emitcode("sjmp", "%05d_DS_", labelKey2num(nlbl->key));
    mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
    mc35_pic14_emitcode("ljmp", "%05d_DS_", labelKey2num(IC_TRUE(ic)->key));
    mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(nlbl->key));
  }
  else
  {
    mc35_pic14_emitcode("ljmp", "%05d_DS_", labelKey2num(IC_FALSE(ic)->key));
    mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
  }
  ic->generated = TRUE;
}

/*-----------------------------------------------------------------*/
/* genAnd  - code for and                                          */
/*-----------------------------------------------------------------*/
static void
genAnd(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  int size, offset = 0;
  unsigned long lit = 0L;
  int bytelit = 0;
  resolvedIfx rIfx;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  resolveIfx(&rIfx, ifx);

  /* if left is a literal & right is not then exchange them */
  if ((AOP_TYPE(left) == AOP_LIT && AOP_TYPE(right) != AOP_LIT) || AOP_NEEDSACC(left))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if result = right then exchange them */
  if (mc35_sameRegs(AOP(result), AOP(right)))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if right is bit then exchange them */
  if (AOP_TYPE(right) == AOP_CRY && AOP_TYPE(left) != AOP_CRY)
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }
  if (AOP_TYPE(right) == AOP_LIT)
    lit = ulFromVal(AOP(right)->aopu.aop_lit);

  size = AOP_SIZE(result);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  // if(bit & yy)
  // result = bit & yy;
  if (AOP_TYPE(left) == AOP_CRY)
  {
    // c = bit & literal;
    if (AOP_TYPE(right) == AOP_LIT)
    {
      if (lit & 1)
      {
        if (size && mc35_sameRegs(AOP(result), AOP(left)))
          // no change
          goto release;
        mc35_pic14_emitcode("mov", "c,%s", AOP(left)->aopu.aop_dir);
      }
      else
      {
        // bit(result) = 0;
        if (size && (AOP_TYPE(result) == AOP_CRY))
        {
          mc35_pic14_emitcode("clr", "%s", AOP(result)->aopu.aop_dir);
          goto release;
        }
        if ((AOP_TYPE(result) == AOP_CRY) && ifx)
        {
          jumpIfTrue(ifx);
          goto release;
        }
        mc35_pic14_emitcode("clr", "c");
      }
    }
    else
    {
      if (AOP_TYPE(right) == AOP_CRY)
      {
        // c = bit & bit;
        mc35_pic14_emitcode("mov", "c,%s", AOP(right)->aopu.aop_dir);
        mc35_pic14_emitcode("anl", "c,%s", AOP(left)->aopu.aop_dir);
      }
      else
      {
        // c = bit & val;
        MOVA(mc35_aopGet(AOP(right), 0, FALSE, FALSE));
        // c = lsb
        mc35_pic14_emitcode("rrc", "a");
        mc35_pic14_emitcode("anl", "c,%s", AOP(left)->aopu.aop_dir);
      }
    }
    // bit = c
    // val = c
    if (size)
      pic14_outBitC(result);
    // if(bit & ...)
    else if ((AOP_TYPE(result) == AOP_CRY) && ifx)
      genIfxJump(ifx, "c");
    goto release;
  }

  // if(val & 0xZZ)       - size = 0, ifx != FALSE  -
  // bit = val & 0xZZ     - size = 1, ifx = FALSE -
  if ((AOP_TYPE(right) == AOP_LIT) && (AOP_TYPE(result) == AOP_CRY) && (AOP_TYPE(left) != AOP_CRY))
  {
    int posbit = isLiteralBit(lit);
    /* left &  2^n */
    if (posbit)
    {
      posbit--;
      //MOVA(mc35_aopGet(AOP(left),posbit>>3,FALSE,FALSE));
      // bit = left & 2^n
      if (size)
        mc35_pic14_emitcode("mov", "c,acc.%d", posbit & 0x07);
      // if(left &  2^n)
      else
      {
        if (ifx)
        {
          int offset = 0;
          while (posbit > 7)
          {
            posbit -= 8;
            offset++;
          }
          mc35_emitpcode(((rIfx.condition) ? POC_BTFSC : POC_BTFSS),
                         mc35_newpCodeOpBit(mc35_aopGet(AOP(left), offset, FALSE, FALSE), posbit, 0));
          mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rIfx.lbl->key));

          ifx->generated = TRUE;
        }
        goto release;
      }
    }
    else
    {
      symbol *tlbl = newiTempLabel(NULL);
      int sizel = AOP_SIZE(left);
      if (size)
        mc35_pic14_emitcode("setb", "c");
      // zwr 2.0.0
      while (sizel--)
      {
        if ((bytelit = ((lit >> (offset * 8)) & 0x0FFL)) != 0x0L)
        {
          // byte ==  2^n ?
          if ((posbit = isLiteralBit(bytelit)) != 0)
          {
            mc35_emitpcode(POC_BTFSC,
                           mc35_newpCodeOpBit(mc35_aopGet(AOP(left), offset, FALSE, FALSE), posbit - 1, 0));
          }
          else
          {
            mc35_mov2w(AOP(left), offset);
            mc35_emitpcode(POC_ANDLW, mc35_newpCodeOpLit(bytelit & 0x0ff));
            mc35_emitSKPZ;
          }
          mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rIfx.condition ? rIfx.lbl->key : tlbl->key));
        }
        offset++;
      }
      if (!rIfx.condition)
      {
        mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rIfx.lbl->key));
      }
      mc35_emitpLabel(tlbl->key);
      ifx->generated = TRUE;
      // while (sizel--)
      // {
      //   if ((bytelit = ((lit >> (offset * 8)) & 0x0FFL)) != 0x0L)
      //   {
      //     mc35_mov2w(AOP(left), offset);
      //     // byte ==  2^n ?
      //     if ((posbit = isLiteralBit(bytelit)) != 0)
      //     {
      //       mc35_emitpcode(rIfx.condition ? POC_BTFSC : POC_BTFSS, // XXX: or the other way round?
      //                 mc35_newpCodeOpBit(mc35_aopGet(AOP(left), offset, FALSE, FALSE), posbit - 1, 0));
      //       mc35_pic14_emitcode("jb", "acc.%d,%05d_DS_", (posbit - 1) & 0x07, labelKey2num(tlbl->key));
      //     }
      //     else
      //     {
      //       mc35_emitpcode(POC_ANDLW, mc35_newpCodeOpLit(bytelit & 0x0ff));
      //       if (rIfx.condition)
      //         mc35_emitSKPZ;
      //       else
      //         mc35_emitSKPNZ;

      //       if (bytelit != 0x0FFL)
      //       {
      //         mc35_pic14_emitcode("anl", "a,%s", mc35_aopGet(AOP(right), offset, FALSE, TRUE));
      //       }
      //       mc35_pic14_emitcode("jnz", "%05d_DS_", labelKey2num(tlbl->key));
      //     }

      //     mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rIfx.lbl->key));
      //     ifx->generated = 1;
      //   }
      //   offset++;
      // }
      // bit = left & literal
      if (size)
      {
        mc35_pic14_emitcode("clr", "c");
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
      }
      // if(left & literal)
      else
      {
        if (ifx)
          jmpTrueOrFalse(ifx, tlbl);
        goto release;
      }
    }
    pic14_outBitC(result);
    goto release;
  }

  /* if left is same as result */
  if (mc35_sameRegs(AOP(result), AOP(left)))
  {
    int know_W = -1;
    for (; size--; offset++, lit >>= 8)
    {
      if (AOP_TYPE(right) == AOP_LIT)
      {
        switch (lit & 0xff)
        {
        case 0x00:
          /*  and'ing with 0 has clears the result */
          mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
          break;
        case 0xff:
          /* and'ing with 0xff is a nop when the result and left are the same */
          break;

        default:
        {
          int p = mc35_my_powof2((~lit) & 0xff);
          if (p >= 0)
          {
            /* only one bit is set in the literal, so use a bcf instruction */
            mc35_emitpcode(POC_BCF, mc35_newpCodeOpBit(mc35_aopGet(AOP(left), offset, FALSE, FALSE), p, 0));
          }
          else
          {
            if (know_W != (int)(lit & 0xff))
              mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
            know_W = lit & 0xff;
            mc35_emitpcode(POC_ANDWF, mc35_popGet(AOP(left), offset));
          }
        }
        }
      }
      else
      {
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_ANDWF, mc35_popGet(AOP(left), offset));
      }
    }
  }
  else
  {
    // left & result in different registers
    if (AOP_TYPE(result) == AOP_CRY)
    {
      // result = bit
      // if(size), result in bit
      // if(!size && ifx), conditional oper: if(left & right)
      symbol *tlbl = newiTempLabel(NULL);
      int sizer = min(AOP_SIZE(left), AOP_SIZE(right));
      if (size)
        mc35_pic14_emitcode("setb", "c");
      while (sizer--)
      {
        MOVA(mc35_aopGet(AOP(right), offset, FALSE, FALSE));
        mc35_pic14_emitcode("anl", "a,%s", mc35_aopGet(AOP(left), offset, FALSE, FALSE));
        mc35_pic14_emitcode("jnz", "%05d_DS_", labelKey2num(tlbl->key));
        offset++;
      }
      if (size)
      {
        CLRC;
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
        pic14_outBitC(result);
      }
      else if (ifx)
        jmpTrueOrFalse(ifx, tlbl);
    }
    else
    {
      for (; (size--); offset++)
      {
        // normal case
        // result = left & right
        if (AOP_TYPE(right) == AOP_LIT)
        {
          int t = (lit >> (offset * 8)) & 0x0FFL;
          switch (t)
          {
          case 0x00:
            mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
            break;
          case 0xff:
            mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
            break;
          default:
            mc35_emitpcode(POC_MOVLW, mc35_popGetLit(t));
            mc35_emitpcode(POC_ANDFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
          }
          continue;
        }

        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_ANDFW, mc35_popGet(AOP(left), offset));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }
    }
  }

release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genOr  - code for or                                            */
/*-----------------------------------------------------------------*/
static void
genOr(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  int size, offset = 0;
  unsigned long lit = 0L;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  /* if left is a literal & right is not then exchange them */
  if ((AOP_TYPE(left) == AOP_LIT && AOP_TYPE(right) != AOP_LIT) || AOP_NEEDSACC(left))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if result = right then exchange them */
  if (mc35_sameRegs(AOP(result), AOP(right)))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if right is bit then exchange them */
  if (AOP_TYPE(right) == AOP_CRY && AOP_TYPE(left) != AOP_CRY)
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);

  if (AOP_TYPE(right) == AOP_LIT)
    lit = ulFromVal(AOP(right)->aopu.aop_lit);

  size = AOP_SIZE(result);

  // if(bit | yy)
  // xx = bit | yy;
  if (AOP_TYPE(left) == AOP_CRY)
  {
    if (AOP_TYPE(right) == AOP_LIT)
    {
      // c = bit & literal;
      if (lit)
      {
        // lit != 0 => result = 1
        if (AOP_TYPE(result) == AOP_CRY)
        {
          if (size)
            mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));
          //mc35_pic14_emitcode("bsf","(%s >> 3), (%s & 7)",
          //   AOP(result)->aopu.aop_dir,
          //   AOP(result)->aopu.aop_dir);
          else if (ifx)
            continueIfTrue(ifx);
          goto release;
        }
      }
      else
      {
        // lit == 0 => result = left
        if (size && mc35_sameRegs(AOP(result), AOP(left)))
          goto release;
        mc35_pic14_emitcode(";XXX mov", "c,%s  %s,%d", AOP(left)->aopu.aop_dir, __FILE__, __LINE__);
      }
    }
    else
    {
      if (AOP_TYPE(right) == AOP_CRY)
      {
        if (mc35_sameRegs(AOP(result), AOP(left)))
        {
          // c = bit | bit;
          mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));
          mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(right), 0));
          mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));

          mc35_pic14_emitcode("bcf", "(%s >> 3), (%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
          mc35_pic14_emitcode("btfsc", "(%s >> 3), (%s & 7)", AOP(right)->aopu.aop_dir, AOP(right)->aopu.aop_dir);
          mc35_pic14_emitcode("bsf", "(%s >> 3), (%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
        }
        else
        {
          mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));
          mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(right), 0));
          mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(left), 0));
          mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));
        }
      }
      else
      {
        // c = bit | val;
        symbol *tlbl = newiTempLabel(NULL);
        mc35_pic14_emitcode(";XXX ", " %s,%d", __FILE__, __LINE__);

        mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));

        if (!((AOP_TYPE(result) == AOP_CRY) && ifx))
          mc35_pic14_emitcode(";XXX setb", "c");
        mc35_pic14_emitcode(";XXX jb", "%s,%05d_DS_", AOP(left)->aopu.aop_dir, labelKey2num(tlbl->key));
        pic14_toBoolean(right);
        mc35_pic14_emitcode(";XXX jnz", "%05d_DS_", labelKey2num(tlbl->key));
        if ((AOP_TYPE(result) == AOP_CRY) && ifx)
        {
          jmpTrueOrFalse(ifx, tlbl);
          goto release;
        }
        else
        {
          CLRC;
          mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
        }
      }
    }
    // bit = c
    // val = c
    if (size)
      pic14_outBitC(result);
    // if(bit | ...)
    else if ((AOP_TYPE(result) == AOP_CRY) && ifx)
      genIfxJump(ifx, "c");
    goto release;
  }

  // if(val | 0xZZ)       - size = 0, ifx != FALSE  -
  // bit = val | 0xZZ     - size = 1, ifx = FALSE -
  if ((AOP_TYPE(right) == AOP_LIT) && (AOP_TYPE(result) == AOP_CRY) && (AOP_TYPE(left) != AOP_CRY))
  {
    if (lit)
    {
      mc35_pic14_emitcode(";XXX ", " %s,%d", __FILE__, __LINE__);
      // result = 1
      if (size)
        mc35_pic14_emitcode(";XXX setb", "%s", AOP(result)->aopu.aop_dir);
      else
        continueIfTrue(ifx);
      goto release;
    }
    else
    {
      mc35_pic14_emitcode(";XXX ", " %s,%d", __FILE__, __LINE__);
      // lit = 0, result = boolean(left)
      if (size)
        mc35_pic14_emitcode(";XXX setb", "c");
      pic14_toBoolean(right);
      if (size)
      {
        symbol *tlbl = newiTempLabel(NULL);
        mc35_pic14_emitcode(";XXX jnz", "%05d_DS_", labelKey2num(tlbl->key));
        CLRC;
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
      }
      else
      {
        genIfxJump(ifx, "a");
        goto release;
      }
    }
    pic14_outBitC(result);
    goto release;
  }

  /* if left is same as result */
  if (mc35_sameRegs(AOP(result), AOP(left)))
  {
    int know_W = -1;
    for (; size--; offset++, lit >>= 8)
    {
      if (AOP_TYPE(right) == AOP_LIT)
      {
        if ((lit & 0xff) == 0)
          /*  or'ing with 0 has no effect */
          continue;
        else
        {
          int p = mc35_my_powof2(lit & 0xff);
          if (p >= 0)
          {
            /* only one bit is set in the literal, so use a bsf instruction */
            mc35_emitpcode(POC_BSF, mc35_newpCodeOpBit(mc35_aopGet(AOP(left), offset, FALSE, FALSE), p, 0));
          }
          else
          {
            if (know_W != (int)(lit & 0xff))
              mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
            know_W = lit & 0xff;
            mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(left), offset));
          }
        }
      }
      else
      {
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(left), offset));
      }
    }
  }
  else
  {
    // left & result in different registers
    if (AOP_TYPE(result) == AOP_CRY)
    {
      // result = bit
      // if(size), result in bit
      // if(!size && ifx), conditional oper: if(left | right)
      symbol *tlbl = newiTempLabel(NULL);
      int sizer = max(AOP_SIZE(left), AOP_SIZE(right));
      mc35_pic14_emitcode(";XXX ", " %s,%d", __FILE__, __LINE__);

      if (size)
        mc35_pic14_emitcode(";XXX setb", "c");
      while (sizer--)
      {
        MOVA(mc35_aopGet(AOP(right), offset, FALSE, FALSE));
        mc35_pic14_emitcode(";XXX orl", "a,%s", mc35_aopGet(AOP(left), offset, FALSE, FALSE));
        mc35_pic14_emitcode(";XXX jnz", "%05d_DS_", labelKey2num(tlbl->key));
        offset++;
      }
      if (size)
      {
        CLRC;
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
        pic14_outBitC(result);
      }
      else if (ifx)
        jmpTrueOrFalse(ifx, tlbl);
    }
    else
      for (; (size--); offset++)
      {
        // normal case
        // result = left | right
        if (AOP_TYPE(right) == AOP_LIT)
        {
          int t = (lit >> (offset * 8)) & 0x0FFL;
          switch (t)
          {
          case 0x00:
            mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));

            break;
          default:
            mc35_emitpcode(POC_MOVLW, mc35_popGetLit(t));
            mc35_emitpcode(POC_IORFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
          }
          continue;
        }

        // faster than result <- left, anl result,right
        // and better if result is SFR
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_IORFW, mc35_popGet(AOP(left), offset));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }
  }

release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genXor - code for xclusive or                                   */
/*-----------------------------------------------------------------*/
static void
genXor(iCode *ic, iCode *ifx)
{
  operand *left, *right, *result;
  int size, offset = 0;
  unsigned long lit = 0L;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  /* if left is a literal & right is not ||
     if left needs acc & right does not */
  if ((AOP_TYPE(left) == AOP_LIT && AOP_TYPE(right) != AOP_LIT) || (AOP_NEEDSACC(left) && !AOP_NEEDSACC(right)))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if result = right then exchange them */
  if (mc35_sameRegs(AOP(result), AOP(right)))
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }

  /* if right is bit then exchange them */
  if (AOP_TYPE(right) == AOP_CRY && AOP_TYPE(left) != AOP_CRY)
  {
    operand *tmp = right;
    right = left;
    left = tmp;
  }
  if (AOP_TYPE(right) == AOP_LIT)
    lit = ulFromVal(AOP(right)->aopu.aop_lit);

  size = AOP_SIZE(result);

  // if(bit ^ yy)
  // xx = bit ^ yy;
  if (AOP_TYPE(left) == AOP_CRY)
  {
    if (AOP_TYPE(right) == AOP_LIT)
    {
      // c = bit & literal;
      if (lit >> 1)
      {
        // lit>>1  != 0 => result = 1
        if (AOP_TYPE(result) == AOP_CRY)
        {
          if (size)
          {
            mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), offset));
            mc35_pic14_emitcode("setb", "%s", AOP(result)->aopu.aop_dir);
          }
          else if (ifx)
            continueIfTrue(ifx);
          goto release;
        }
        mc35_pic14_emitcode("setb", "c");
      }
      else
      {
        // lit == (0 or 1)
        if (lit == 0)
        {
          // lit == 0, result = left
          if (size && mc35_sameRegs(AOP(result), AOP(left)))
            goto release;
          mc35_pic14_emitcode("mov", "c,%s", AOP(left)->aopu.aop_dir);
        }
        else
        {
          // lit == 1, result = not(left)
          if (size && mc35_sameRegs(AOP(result), AOP(left)))
          {
            mc35_emitpcode(POC_MOVLW, mc35_popGet(AOP(result), offset));
            mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(result), offset));
            mc35_pic14_emitcode("cpl", "%s", AOP(result)->aopu.aop_dir);
            goto release;
          }
          else
          {
            assert(!"incomplete genXor");
            mc35_pic14_emitcode("mov", "c,%s", AOP(left)->aopu.aop_dir);
            mc35_pic14_emitcode("cpl", "c");
          }
        }
      }
    }
    else
    {
      // right != literal
      symbol *tlbl = newiTempLabel(NULL);
      if (AOP_TYPE(right) == AOP_CRY)
      {
        // c = bit ^ bit;
        mc35_pic14_emitcode("mov", "c,%s", AOP(right)->aopu.aop_dir);
      }
      else
      {
        int sizer = AOP_SIZE(right);
        // c = bit ^ val
        // if val>>1 != 0, result = 1
        mc35_pic14_emitcode("setb", "c");
        while (sizer)
        {
          MOVA(mc35_aopGet(AOP(right), sizer - 1, FALSE, FALSE));
          if (sizer == 1)
            // test the msb of the lsb
            mc35_pic14_emitcode("anl", "a,#0xfe");
          mc35_pic14_emitcode("jnz", "%05d_DS_", labelKey2num(tlbl->key));
          sizer--;
        }
        // val = (0,1)
        mc35_pic14_emitcode("rrc", "a");
      }
      mc35_pic14_emitcode("jnb", "%s,%05d_DS_", AOP(left)->aopu.aop_dir, (labelKey2num(tlbl->key)));
      mc35_pic14_emitcode("cpl", "c");
      mc35_pic14_emitcode("", "%05d_DS_:", (labelKey2num(tlbl->key)));
    }
    // bit = c
    // val = c
    if (size)
      pic14_outBitC(result);
    // if(bit | ...)
    else if ((AOP_TYPE(result) == AOP_CRY) && ifx)
      genIfxJump(ifx, "c");
    goto release;
  }

  if (mc35_sameRegs(AOP(result), AOP(left)))
  {
    /* if left is same as result */
    for (; size--; offset++)
    {
      if (AOP_TYPE(right) == AOP_LIT)
      {
        int t = (lit >> (offset * 8)) & 0x0FFL;
        if (t == 0x00L)
          continue;
        else
        {
          mc35_emitpcode(POC_MOVLW, mc35_popGetLit(t));
          mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(left), offset));
        }
      }
      else
      {
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(left), offset));
      }
    }
  }
  else
  {
    // left & result in different registers
    if (AOP_TYPE(result) == AOP_CRY)
    {
      // result = bit
      // if(size), result in bit
      // if(!size && ifx), conditional oper: if(left ^ right)
      symbol *tlbl = newiTempLabel(NULL);
      int sizer = max(AOP_SIZE(left), AOP_SIZE(right));
      if (size)
        mc35_pic14_emitcode("setb", "c");
      while (sizer--)
      {
        if ((AOP_TYPE(right) == AOP_LIT) && (((lit >> (offset * 8)) & 0x0FFL) == 0x00L))
        {
          MOVA(mc35_aopGet(AOP(left), offset, FALSE, FALSE));
        }
        else
        {
          MOVA(mc35_aopGet(AOP(right), offset, FALSE, FALSE));
          mc35_pic14_emitcode("xrl", "a,%s", mc35_aopGet(AOP(left), offset, FALSE, FALSE));
        }
        mc35_pic14_emitcode("jnz", "%05d_DS_", labelKey2num(tlbl->key));
        offset++;
      }
      if (size)
      {
        CLRC;
        mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(tlbl->key));
        pic14_outBitC(result);
      }
      else if (ifx)
        jmpTrueOrFalse(ifx, tlbl);
    }
    else
      for (; (size--); offset++)
      {
        // normal case
        // result = left & right
        if (AOP_TYPE(right) == AOP_LIT)
        {
          int t = (lit >> (offset * 8)) & 0x0FFL;
          switch (t)
          {
          case 0x00:
            mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
            break;
          case 0xff:
            // zwr 1.0.0 inst comar #1
            // mc35_emitpcode(POC_COMFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
            mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(left), offset));

            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
            break;
          default:
            mc35_emitpcode(POC_MOVLW, mc35_popGetLit(t));
            mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(left), offset));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
          }
          continue;
        }

        // faster than result <- left, anl result,right
        // and better if result is SFR
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_XORFW, mc35_popGet(AOP(left), offset));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }
  }

release:
  mc35_freeAsmop(left, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(right, NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genInline - write the inline code out                           */
/*-----------------------------------------------------------------*/
static void
pic14_genInline(iCode *ic)
{
  char *buffer, *bp, *bp1;
  bool inComment = FALSE;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  genLine.lineElement.isInline += (!options.asmpeep);

  buffer = bp = bp1 = Safe_strdup(IC_INLINE(ic));

  while (*bp)
  {
    switch (*bp)
    {
    case ';':
      inComment = TRUE;
      ++bp;
      break;

    case '\x87':
    case '\n':
      inComment = FALSE;
      *bp++ = '\0';
      if (*bp1)
        mc35_addpCode2pBlock(pb, mc35_newpCodeAsmDir(bp1, NULL)); // inline directly, no process
      bp1 = bp;
      break;

    default:
      /* Add \n for labels, not dirs such as c:\mydir */
      if (!inComment && (*bp == ':') && (isspace((unsigned char)bp[1])))
      {
        ++bp;
        *bp = '\0';
        ++bp;
        /* print label, use this special format with NULL directive
               * to denote that the argument should not be indented with tab */
        mc35_addpCode2pBlock(pb, mc35_newpCodeAsmDir(NULL, bp1)); // inline directly, no process
        bp1 = bp;
      }
      else
        ++bp;
      break;
    }
  }
  if ((bp1 != bp) && *bp1)
    mc35_addpCode2pBlock(pb, mc35_newpCodeAsmDir(bp1, NULL)); // inline directly, no process

  Safe_free(buffer);

  /* consumed; we can free it here */
  dbuf_free(IC_INLINE(ic));

  genLine.lineElement.isInline -= (!options.asmpeep);
}

/*-----------------------------------------------------------------*/
/* genRRC - rotate right with carry                                */
/*-----------------------------------------------------------------*/
static void
genRRC(iCode *ic)
{
  operand *left, *result;
  int size, offset = 0, same;

  FENTRY;
  /* rotate right with carry */
  left = IC_LEFT(ic);
  result = IC_RESULT(ic);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, result);

  same = mc35_sameRegs(AOP(result), AOP(left));

  size = AOP_SIZE(result);

  /* get the lsb and put it into the carry */
  mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(left), size - 1));

  offset = 0;

  while (size--)
  {

    if (same)
    {
      mc35_emitpcode(POC_RRF, mc35_popGet(AOP(left), offset));
    }
    else
    {
      mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(left), offset));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    }

    offset++;
  }

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genRLC - generate code for rotate left with carry               */
/*-----------------------------------------------------------------*/
static void
genRLC(iCode *ic)
{
  operand *left, *result;
  int size, offset = 0;
  int same;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* rotate right with carry */
  left = IC_LEFT(ic);
  result = IC_RESULT(ic);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, result);

  same = mc35_sameRegs(AOP(result), AOP(left));

  /* move it to the result */
  size = AOP_SIZE(result);

  /* get the msb and put it into the carry */
  mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(left), size - 1));

  offset = 0;

  while (size--)
  {

    if (same)
    {
      mc35_emitpcode(POC_RLF, mc35_popGet(AOP(left), offset));
    }
    else
    {
      mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(left), offset));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    }

    offset++;
  }

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

static void
genGetABit(iCode *ic)
{
  operand *left, *right, *result;
  int shCount;
  int offset;
  int i;

  left = IC_LEFT(ic);
  right = IC_RIGHT(ic);
  result = IC_RESULT(ic);

  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  shCount = (int)ulFromVal(AOP(right)->aopu.aop_lit);
  offset = shCount / 8;
  shCount %= 8;

  /* load and mask the source byte */
  mc35_mov2w(AOP(left), offset);
  mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1 << shCount));

  /* move selected bit to bit 0 */
  switch (shCount)
  {
  case 0:
    /* nothing more to do */
    break;
  default:
    /* keep W==0, force W=0x01 otherwise */
    mc35_emitSKPZ;
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
    break;
  } // switch

  /* write result */
  mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));

  for (i = 1; i < AOP_SIZE(result); ++i)
  {
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), i));
  } // for

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genGetHbit - generates code get highest order bit               */
/*-----------------------------------------------------------------*/
static void
genGetHbit(iCode *ic)
{
  operand *left, *result;
  left = IC_LEFT(ic);
  result = IC_RESULT(ic);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* get the highest order byte into a */
  MOVA(mc35_aopGet(AOP(left), AOP_SIZE(left) - 1, FALSE, FALSE));
  if (AOP_TYPE(result) == AOP_CRY)
  {
    mc35_pic14_emitcode("rlc", "a");
    pic14_outBitC(result);
  }
  else
  {
    mc35_pic14_emitcode("rl", "a");
    mc35_pic14_emitcode("anl", "a,#0x01");
    mc35_outAcc(result);
  }

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* AccLsh - shift left accumulator by known count                  */
/* MARK: pic14 always rotates through CARRY!                       */
/*-----------------------------------------------------------------*/
static void
AccLsh(pCodeOp *pcop, int shCount)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  shCount &= 0x0007; // shCount : 0..7
  switch (shCount)
  {
  case 0:
    return;
    break;
  case 1:
    mc35_emitCLRC;
    mc35_emitpcode(POC_RLF, pcop);
    return;
    break;
  case 2:
    mc35_emitpcode(POC_RLF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    break;
  case 3:
    mc35_emitpcode(POC_RLF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    break;
  case 4:
    mc35_emitpcode(POC_SWAPF, pcop);
    break;
  case 5:
    mc35_emitpcode(POC_SWAPF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    break;
  case 6:
    mc35_emitpcode(POC_SWAPF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    mc35_emitpcode(POC_RLF, pcop);
    break;
  case 7:
    mc35_emitpcode(POC_RRFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    break;
  }
  /* clear invalid bits */
  mc35_emitpcode(POC_MOVLW, mc35_popGetLit((unsigned char)(~((1UL << shCount) - 1))));
  mc35_emitpcode(POC_ANDWF, pcop);
}

/*-----------------------------------------------------------------*/
/* AccRsh - shift right accumulator by known count                 */
/* MARK: pic14 always rotates through CARRY!                       */
/* maskmode - 0: leave invalid bits undefined (caller should mask) */
/*            1: mask out invalid bits (zero-extend)               */
/*            2: sign-extend result (pretty slow)                  */
/*-----------------------------------------------------------------*/
static void
AccRsh(pCodeOp *pcop, int shCount, int mask_mode)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  shCount &= 0x0007; // shCount : 0..7
  switch (shCount)
  {
  case 0:
    return;
    break;
  case 1:
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    else if (mask_mode == 1)
      mc35_emitCLRC;
    mc35_emitpcode(POC_RRF, pcop);
    return;
    break;
  case 2:
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    if (mask_mode == 2)
      return;
    break;
  case 3:
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    /* load sign if needed */
    if (mask_mode == 2)
      mc35_emitpcode(POC_RLFW, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    if (mask_mode == 2)
      return;
    break;
  case 4:
    mc35_emitpcode(POC_SWAPF, pcop);
    break;
  case 5:
    mc35_emitpcode(POC_SWAPF, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    break;
  case 6:
    mc35_emitpcode(POC_SWAPF, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    mc35_emitpcode(POC_RRF, pcop);
    break;
  case 7:
    if (mask_mode == 2)
    {
      /* load sign */
      mc35_emitpcode(POC_RLFW, pcop);
      mc35_emitpcode(POC_CLRF, pcop);
      // zwr 1.0.0 inst comr #2
      // mc35_emitSKPNC;
      // mc35_emitpcode(POC_COMF, pcop);
      mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
      mc35_emitSKPNC;
      mc35_emitpcode(POC_XORWF, pcop);
      return;
    }
    else
    {
      mc35_emitpcode(POC_RLFW, pcop);
      mc35_emitpcode(POC_RLF, pcop);
    }
    break;
  }

  if (mask_mode == 0)
  {
    /* leave invalid bits undefined */
    return;
  }

  /* clear invalid bits -- zero-extend */
  mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0x00ff >> shCount));
  mc35_emitpcode(POC_ANDWF, pcop);

  if (mask_mode == 2)
  {
    /* sign-extend */
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0x00ff << (8 - shCount)));
    mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_get_op(pcop, NULL, 0), 7 - shCount, 0));
    mc35_emitpcode(POC_IORWF, pcop);
  }
}

/*-----------------------------------------------------------------*/
/* movLeft2Result - move byte from left to result                  */
/*-----------------------------------------------------------------*/
static void
movLeft2Result(operand *left, int offl, operand *result, int offr)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  if (!mc35_sameRegs(AOP(left), AOP(result)) || (offl != offr))
  {
    mc35_aopGet(AOP(left), offl, FALSE, FALSE);

    mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offl));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offr));
  }
}

/*-----------------------------------------------------------------*/
/* shiftLeft_Left2ResultLit - shift left by known count            */
/*-----------------------------------------------------------------*/

static void
shiftLeft_Left2ResultLit(operand *left, operand *result, int shCount)
{
  int size, same, offr, i;

  size = AOP_SIZE(left);
  if (AOP_SIZE(result) < size)
    size = AOP_SIZE(result);

  same = mc35_sameRegs(AOP(left), AOP(result));

  offr = shCount / 8;
  shCount = shCount & 0x07;

  size -= offr;

  switch (shCount)
  {
  case 0: /* takes 0 or 2N cycles (for offr==0) */
    if (!same || offr)
    {
      for (i = size - 1; i >= 0; i--)
        movLeft2Result(left, i, result, offr + i);
    } // if
    break;

  case 1: /* takes 1N+1 or 2N+1 cycles (or offr==0) */
    if (same && offr)
    {
      shiftLeft_Left2ResultLit(left, result, 8 * offr);
      shiftLeft_Left2ResultLit(result, result, shCount);
      return; /* prevent clearing result again */
    }
    else
    {
      mc35_emitCLRC;
      for (i = 0; i < size; i++)
      {
        if (same && !offr)
        {
          mc35_emitpcode(POC_RLF, mc35_popGet(AOP(left), i));
        }
        else
        {
          mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(left), i));
          mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), i + offr));
        } // if
      }   // for
    }     // if (offr)
    break;

  case 4: /* takes 3+5(N-1) = 5N-2 cycles (for offr==0) */
    /* works in-place/with offr as well */
    mc35_emitpcode(POC_SWAPFW, mc35_popGet(AOP(left), size - 1));
    mc35_emitpcode(POC_ANDLW, mc35_popGetLit(0xF0));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), size - 1 + offr));

    for (i = size - 2; i >= 0; i--)
    {
      mc35_emitpcode(POC_SWAPFW, mc35_popGet(AOP(left), i));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), i + offr));
      mc35_emitpcode(POC_ANDLW, mc35_popGetLit(0x0F));
      mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(result), i + offr + 1));
      mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(result), i + offr));
    } // for i
    break;

  case 7: /* takes 2(N-1)+3 = 2N+1 cycles */
    /* works in-place/with offr as well */
    mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(left), size - 1));
    for (i = size - 2; i >= 0; i--)
    {
      mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(left), i));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offr + i + 1));
    } // for i
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offr));
    mc35_emitpcode(POC_RRF, mc35_popGet(AOP(result), offr));
    break;

  default:
    shiftLeft_Left2ResultLit(left, result, offr * 8 + shCount - 1);
    shiftLeft_Left2ResultLit(result, result, 1);
    return; /* prevent clearing result again */
    break;
  } // switch

  while (0 < offr--)
  {
    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offr));
  } // while
}

/*-----------------------------------------------------------------*/
/* shiftRight_Left2ResultLit - shift right by known count          */
/*-----------------------------------------------------------------*/

static void
shiftRight_Left2ResultLit(operand *left, operand *result, int shCount, int sign)
{
  int size, same, offr, i;

  size = AOP_SIZE(left);
  if (AOP_SIZE(result) < size)
    size = AOP_SIZE(result);

  same = mc35_sameRegs(AOP(left), AOP(result));

  offr = shCount / 8;
  shCount = shCount & 0x07;

  size -= offr;

  if (size)
  {
    switch (shCount)
    {
    case 0: /* takes 0 or 2N cycles (for offr==0) */
      if (!same || offr)
      {
        for (i = 0; i < size; i++)
          movLeft2Result(left, i + offr, result, i);
      } // if
      break;

    case 1: /* takes 1N+1(3) or 2N+1(3) cycles (or offr==0) */
      mc35_emitpComment("%s:%d: shCount=%d, size=%d, sign=%d, same=%d, offr=%d", __FUNCTION__, __LINE__, shCount, size, sign,
                        same, offr);
      if (same && offr)
      {
        shiftRight_Left2ResultLit(left, result, 8 * offr, sign);
        shiftRight_Left2ResultLit(result, result, shCount, sign);
        return; /* prevent sign-extending result again */
      }
      else
      {
        mc35_emitCLRC;
        if (sign)
        {
          mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(left), AOP_SIZE(left) - 1, FALSE, FALSE), 7, 0));
          mc35_emitSETC;
        }
        for (i = size - 1; i >= 0; i--)
        {
          if (same && !offr)
          {
            mc35_emitpcode(POC_RRF, mc35_popGet(AOP(left), i));
          }
          else
          {
            mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(left), i + offr));
            mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), i));
          }
        } // for i
      }   // if (offr)
      break;

    case 4: /* takes 3(6)+5(N-1) = 5N-2(+1) cycles (for offr==0) */
      /* works in-place/with offr as well */
      mc35_emitpcode(POC_SWAPFW, mc35_popGet(AOP(left), offr));
      mc35_emitpcode(POC_ANDLW, mc35_popGetLit(0x0F));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));

      for (i = 1; i < size; i++)
      {
        mc35_emitpcode(POC_SWAPFW, mc35_popGet(AOP(left), i + offr));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), i));
        mc35_emitpcode(POC_ANDLW, mc35_popGetLit(0xF0));
        mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(result), i - 1));
        mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(result), i));
      } // for i

      if (sign)
      {
        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xF0));
        mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), size - 1, FALSE, FALSE), 3, 0));
        mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(result), size - 1));
      } // if
      break;

    case 7: /* takes 2(N-1)+3(4) = 2N+1(2) cycles */
      /* works in-place/with offr as well */
      mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(left), offr));
      for (i = 0; i < size - 1; i++)
      {
        mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(left), offr + i + 1));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), i));
      } // for i
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), size - 1));
      if (!sign)
      {
        mc35_emitpcode(POC_RLF, mc35_popGet(AOP(result), size - 1));
      }
      else
      {
        mc35_emitSKPNC;
        // zwr 1.0.0 inst decr #1
        // mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), size - 1));
        mc35_emitpcode(POC_DECFSZ, mc35_popGet(AOP(result), size - 1));
        mc35_emitpcodeNULLop(POC_NOP);
      }
      break;

    default:
      shiftRight_Left2ResultLit(left, result, offr * 8 + shCount - 1, sign);
      shiftRight_Left2ResultLit(result, result, 1, sign);
      return; /* prevent sign extending result again */
      break;
    } // switch
  }   // if

  mc35_addSign(result, size, sign);
}

/*-----------------------------------------------------------------*
* genMultiAsm - repeat assembly instruction for size of register.
* if endian == 1, then the high byte (i.e base address + size of
* register) is used first else the low byte is used first;
*-----------------------------------------------------------------*/
static void
genMultiAsm(PIC_OPCODE poc, operand *reg, int size, int endian)
{

  int offset = 0;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (!reg)
    return;

  if (!endian)
  {
    endian = 1;
  }
  else
  {
    endian = -1;
    offset = size - 1;
  }

  while (size--)
  {
    mc35_emitpcode(poc, mc35_popGet(AOP(reg), offset));
    offset += endian;
  }
}

/*-----------------------------------------------------------------*/
/* loadSignToC - load the operand's sign bit into CARRY            */
/*-----------------------------------------------------------------*/

static void
loadSignToC(operand *op)
{
  FENTRY;
  assert(op && AOP(op) && AOP_SIZE(op));

  mc35_emitCLRC;
  mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(op), AOP_SIZE(op) - 1, FALSE, FALSE), 7, 0));
  mc35_emitSETC;
}

/*-----------------------------------------------------------------*/
/* genRightShift - generate code for right shifting                */
/*-----------------------------------------------------------------*/
static void
genGenericShift(iCode *ic, int shiftRight)
{
  operand *right, *left, *result;
  int size;
  symbol *tlbl, *tlbl1, *inverselbl;

  FENTRY;
  /* if signed then we do it the hard way preserve the
     sign bit moving it inwards */
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  /* signed & unsigned types are treated the same : i.e. the
     signed is NOT propagated inwards : quoting from the
     ANSI - standard : "for E1 >> E2, is equivalent to division
     by 2**E2 if unsigned or if it has a non-negative value,
     otherwise the result is implementation defined ", MY definition
     is that the sign does not get propagated */

  right = IC_RIGHT(ic);
  left = IC_LEFT(ic);
  result = IC_RESULT(ic);

  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  /* if the shift count is known then do it
     as efficiently as possible */
  if (AOP_TYPE(right) == AOP_LIT)
  {
    int lit = (int)ulFromVal(AOP(right)->aopu.aop_lit);
    if (lit < 0)
    {
      lit = -lit;
      shiftRight = !shiftRight;
    }

    if (shiftRight)
      shiftRight_Left2ResultLit(left, result, lit, !SPEC_USIGN(operandType(left)));
    else
      shiftLeft_Left2ResultLit(left, result, lit);
    //genRightShiftLiteral (left,right,result,ic, 0);
    return;
  }

  /* shift count is unknown then we have to form
     a loop get the loop count in B : Note: we take
     only the lower order byte since shifting
     more that 32 bits make no sense anyway, ( the
     largest size of an object can be only 32 bits ) */

  /* we must not overwrite the shift counter */
  assert(!mc35_sameRegs(AOP(right), AOP(result)));

  /* now move the left to the result if they are not the
     same */
  if (!mc35_sameRegs(AOP(left), AOP(result)))
  {
    size = min(AOP_SIZE(result), AOP_SIZE(left));
    while (size--)
    {
      mc35_mov2w(AOP(left), size);
      movwf(AOP(result), size);
    }
    mc35_addSign(result, AOP_SIZE(left), !SPEC_USIGN(operandType(left)));
  }

  tlbl = newiTempLabel(NULL);
  tlbl1 = newiTempLabel(NULL);
  inverselbl = NULL;
  size = AOP_SIZE(result);

  mc35_mov2w(AOP(right), 0);
  if (!SPEC_USIGN(operandType(right)))
  {
    inverselbl = newiTempLabel(NULL);
    /* signed shift count -- invert shift direction for c<0 */
    mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(right), 0, FALSE, FALSE), 7, 0));
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(inverselbl->key));
  }                                             // if

  // zwr 1.0.0 inst isubai #2
  // mc35_emitpcode(POC_SUBLW, mc35_popGetLit(0));
  mc35_emitpcode(POC_XORLW, mc35_popGetLit(0xff));
  mc35_emitpcode(POC_ADDLW, mc35_popGetLit(1)); 
  
  /* -count in WREG, 0-x > 0 --> BORROW = !CARRY --> CARRY is clear! */
  
  /* check for `a = b >> c' with `-c == 0' */
  mc35_emitSKPNZ;
  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(tlbl1->key));
  mc35_emitpLabel(tlbl->key);
  /* propagate the sign bit inwards for SIGNED result */
  if (shiftRight && !SPEC_USIGN(operandType(result)))
    loadSignToC(result);
  genMultiAsm(shiftRight ? POC_RRF : POC_RLF, result, size, shiftRight);
  mc35_emitpcode(POC_ADDLW, mc35_popGetLit(1)); /* clears CARRY (unless W==0 afterwards) */
  mc35_emitSKPC;
  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(tlbl->key));

  if (!SPEC_USIGN(operandType(right)))
  {
    symbol *inv_loop = newiTempLabel(NULL);

    shiftRight = !shiftRight; /* invert shift direction */

    /* we came here from the code above -- we are done */
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(tlbl1->key));

    /* emit code for shifting N<0 steps, count is already in W */
    mc35_emitpLabel(inverselbl->key);
    if (!shiftRight || SPEC_USIGN(operandType(result)))
      mc35_emitCLRC;
    mc35_emitpLabel(inv_loop->key);
    /* propagate the sign bit inwards for SIGNED result */
    if (shiftRight && !SPEC_USIGN(operandType(result)))
      loadSignToC(result);
    genMultiAsm(shiftRight ? POC_RRF : POC_RLF, result, size, shiftRight);
    mc35_emitpcode(POC_ADDLW, mc35_popGetLit(1));
    mc35_emitSKPC;
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(inv_loop->key));
  } // if

  mc35_emitpLabel(tlbl1->key);

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

static void
genRightShift(iCode *ic)
{
  genGenericShift(ic, 1);
}

static void
genLeftShift(iCode *ic)
{
  genGenericShift(ic, 0);
}

/*-----------------------------------------------------------------*/
/* SetIrp - Set IRP bit                                            */
/*-----------------------------------------------------------------*/
static void
SetIrp(operand *result)
{
  FENTRY;
  if (AOP_TYPE(result) == AOP_LIT)
  {
    unsigned lit = (unsigned)double2ul(operandLitValue(result));
    if (lit & 0x100)
      mc35_emitSETIRP;
    else
      mc35_emitCLRIRP;
  }

  // zwr 2.0.0
  else if ((AOP_TYPE(result) == AOP_PCODE) && (AOP(result)->aopu.pcop->type == PO_LITERAL))
  {
    int addrs = PCOL(AOP(result)->aopu.pcop)->lit;
    if (addrs & 0x100)
      mc35_emitSETIRP;
    else
      mc35_emitCLRIRP;
  }
  else if ((AOP_TYPE(result) == AOP_PCODE) && (AOP(result)->aopu.pcop->type == PO_IMMEDIATE))
  {
    mc35_emitCLRIRP; /* always ensure this is clear as it may have previously been set */
    mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(result), 1, 0));
    mc35_emitpcode(POC_ANDLW, mc35_popGetLit(0x01));
    mc35_emitSKPZ;
    mc35_emitSETIRP;
  }
  else
  {
    mc35_emitCLRIRP; /* always ensure this is clear as it may have previouly been set */
    if (AOP_SIZE(result) > 1)
    {
      mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 1, FALSE, FALSE), 0, 0));
      mc35_emitSETIRP;
    }
  }
}

static void
setup_fsr(operand *ptr)
{
  // zwr 1.1.3
  mc35_mov2w_op(ptr, 0);
  mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr0l));
  mc35_mov2w_op(ptr, 1);
  mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr0h));
  // if (mc35_getPIC()->isEnhancedCore)
  // {
  //   mc35_mov2w_op(ptr, 0);
  //   mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr0l));
  //   mc35_mov2w_op(ptr, 1);
  //   mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr0h));
  // }
  // else
  // {
  //   mc35_mov2w_op(ptr, 0);
  //   mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr));

  //   /* also setup-up IRP */
  //   SetIrp(ptr);
  // }
}

static void
inc_fsr(int delta)
{
  if (0 == delta)
  {
    /* Nothing to do. */
    return;
  } // if

  if (mc35_getPIC()->isEnhancedCore)
  {
    assert(delta >= -32);
    assert(delta < 32);
    /* Hack: Turn this into a PCI (not that easy due to the argument structure). */
    mc35_addpCode2pBlock(pb, mc35_newpCodeAsmDir("ADDFSR", "FSR0, %d", delta));
  }
  else
  {
    switch (delta)
    {
    case 1:
      // zwr 1.0.0 inst incr #2
      // mc35_emitpcode(POC_INCF, mc35_popCopyReg(&mc35_pc_fsr));
      // mc35_emitpcode(POC_INCFSZ, mc35_popCopyReg(&mc35_pc_fsr));
      // mc35_emitpcodeNULLop(POC_NOP);
      // zwr 1.1.4
      mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
      mc35_emitpcode(POC_ADDWF, mc35_popCopyReg(&mc35_pc_fsr0l));
      mc35_emitSKPNZ;
      mc35_emitpcode(POC_ADDWF, mc35_popCopyReg(&mc35_pc_fsr0h));
    case -1:
      // zwr 1.0.0 inst decr #2
      // mc35_emitpcode(POC_DECF, mc35_popCopyReg(&mc35_pc_fsr));
      // mc35_emitpcode(POC_DECFSZ, mc35_popCopyReg(&mc35_pc_fsr));
      // mc35_emitpcodeNULLop(POC_NOP);
      // zwr 1.1.4
      mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(&mc35_pc_fsr0l));
      mc35_emitpcode(POC_SUBLW, mc35_popGetLit(1));
      mc35_emitSKPC;
      mc35_emitpcode(POC_DECFSZ, mc35_popCopyReg(&mc35_pc_fsr0h));
      mc35_emitpcodeNULLop(POC_NOP);
      mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_fsr0l));
      break;
    case 0:
      break;
    default:
      while (delta > 0)
      {
        inc_fsr(1);
        --delta;
      }
      while (delta < 0)
      {
        inc_fsr(-1);
        ++delta;
      }
      break;
    } // switch
  }   // if
}

/*-----------------------------------------------------------------*/
/* emitPtrByteGet - emits code to get a byte into WREG from an     */
/*                  arbitrary pointer (__code, __data, generic)    */
/*-----------------------------------------------------------------*/
static void
emitPtrByteGet(operand *src, int p_type, bool alreadyAddressed)
{
  FENTRY;
  switch (p_type)
  {
  case POINTER:
  case FPOINTER:
    if (!alreadyAddressed)
      setup_fsr(src);
    mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(mc35_pc_indf));
    break;

  case CPOINTER:
    assert(AOP_SIZE(src) == 2);
    mc35_mov2w_op(src, 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w_op(src, 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(GPTRTAG_CODE)); /* GPOINTER tag for __code space */
    call_libraryfunc("__gptrget1");
    break;

  case GPOINTER:
    assert(AOP_SIZE(src) == 3);
    mc35_mov2w_op(src, 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w_op(src, 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w_op(src, 2);
    call_libraryfunc("__gptrget1");
    break;

  default:
    assert(!"unhandled pointer type");
    break;
  }
}

/*-----------------------------------------------------------------*/
/* emitPtrByteSet - emits code to set a byte from src through a    */
/* pointer register INDF (legacy 8051 uses R0, R1, or DPTR).       */
/*-----------------------------------------------------------------*/
static void
emitPtrByteSet(operand *dst, int p_type, bool alreadyAddressed)
{
  FENTRY;
  switch (p_type)
  {
  case POINTER:
  case FPOINTER:
    if (!alreadyAddressed)
      setup_fsr(dst);
    mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(mc35_pc_indf));
    break;

  case CPOINTER:
    assert(!"trying to assign to __code pointer");
    break;

  case GPOINTER:
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 2));
    mc35_mov2w_op(dst, 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w_op(dst, 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w_op(dst, 2);
    call_libraryfunc("__gptrput1");
    break;

  default:
    assert(!"unhandled pointer type");
    break;
  }
}

/*-----------------------------------------------------------------*/
/* genUnpackBits - generates code for unpacking bits               */
/*-----------------------------------------------------------------*/
static void
genUnpackBits(operand *result, operand *left, int ptype, iCode *ifx)
{
  sym_link *etype; /* bitfield type information */
  unsigned blen;   /* bitfield length */
  unsigned bstr;   /* bitfield starting bit within byte */

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  etype = getSpec(operandType(result));
  blen = SPEC_BLEN(etype);
  bstr = SPEC_BSTR(etype);

  /* single bit field case */
  if (blen == 1)
  {
    if (ifx)
    {
      /* that is for an if statement */
      pCodeOp *pcop;
      resolvedIfx rIfx;

      resolveIfx(&rIfx, ifx);
      if (ptype == -1) /* direct */
        pcop = mc35_newpCodeOpBit(mc35_aopGet(AOP(left), 0, FALSE, FALSE), bstr, 0);
      else
      {
        setup_fsr(left);
        pcop = mc35_newpCodeOpBit(mc35_pc_indf->pcop.name, bstr, 0);
      }
      mc35_emitpcode((rIfx.condition) ? POC_BTFSC : POC_BTFSS, pcop);
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(rIfx.lbl->key));
      ifx->generated = TRUE;
    }
    else
    {
      // zwr 2.0.0
      /*
           * In case of a volatile bitfield read such as
           * (void)PORTCbits.RC3;
           * we end up having no result ...
           */
      int haveResult = !!AOP_SIZE(result);

      if (haveResult)
      {
        assert(!mc35_sameRegs(AOP(result), AOP(left)));
        mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), 0));
      } // if

      // int i;

      // assert(!mc35_sameRegs(AOP(result), AOP(left)));
      // for (i = 0; i < AOP_SIZE(result); i++)
      //   mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), i));

      switch (ptype)
      {
      case -1:
        mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(left), 0, FALSE, FALSE), bstr, 0));
        /* adjust result below */
        if (!haveResult)
        {
          /* Dummy instruction to allow bit-test above (volatile dummy bitfield read). */
          mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
        } // if
        break;

      case POINTER:
      case FPOINTER:
      case GPOINTER:
      case CPOINTER:
        emitPtrByteGet(left, ptype, FALSE);
        // zwr 2.0.0
        {
          mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1UL << bstr));
          mc35_emitSKPZ;
          /* adjust result below */
        } // if
        // mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1UL << bstr));
        // mc35_emitSKPZ;
        /* adjust result below */
        break;

      default:
        assert(!"unhandled pointer type");
      } // switch

      /* move sign-/zero extended bit to result */
      // zwr 2.0.0
      if (haveResult)
      {
        if (SPEC_USIGN(OP_SYM_ETYPE(left)))
        {
          // zwr 1.0.0 inst incr #2
          // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
          mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
          mc35_emitpcodeNULLop(POC_NOP);
        }
        else
        {
          // zwr 1.0.0 inst decr #1
          // mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), 0));
          mc35_emitpcode(POC_DECFSZ, mc35_popGet(AOP(result), 0));
          mc35_emitpcodeNULLop(POC_NOP);
        }
        mc35_addSign(result, 1, !SPEC_USIGN(OP_SYM_ETYPE(left)));
      }
    }
    return;
  }
  else if (blen <= 8 && ((blen + bstr) <= 8))
  {
    /* blen > 1 */
    int i;

    for (i = 0; i < AOP_SIZE(result); i++)
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), i));

    switch (ptype)
    {
    case -1:
      mc35_mov2w(AOP(left), 0);
      break;

    case POINTER:
    case FPOINTER:
    case GPOINTER:
    case CPOINTER:
      emitPtrByteGet(left, ptype, FALSE);
      break;

    default:
      assert(!"unhandled pointer type");
    } // switch

    if (blen < 8)
      mc35_emitpcode(POC_ANDLW, mc35_popGetLit((((1UL << blen) - 1) << bstr) & 0x00ff));
    movwf(AOP(result), 0);
    AccRsh(mc35_popGet(AOP(result), 0), bstr, 1); /* zero extend the bitfield */

    if (!SPEC_USIGN(OP_SYM_ETYPE(left)) && (bstr + blen != 8))
    {
      /* signed bitfield */
      assert(bstr + blen > 0);
      mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0x00ff << (bstr + blen)));
      mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 0, FALSE, FALSE), bstr + blen - 1, 0));
      mc35_emitpcode(POC_IORWF, mc35_popGet(AOP(result), 0));
    }
    mc35_addSign(result, 1, !SPEC_USIGN(OP_SYM_ETYPE(left)));
    return;
  }

  assert(!"bitfields larger than 8 bits or crossing byte boundaries are not yet supported");
}

#if 1
/*-----------------------------------------------------------------*/
/* genDataPointerGet - generates code when ptr offset is known     */
/*-----------------------------------------------------------------*/
static void
genDataPointerGet(operand *left, operand *result, iCode *ic)
{
  unsigned int size;
  int offset = 0;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  /* optimization - most of the time, left and result are the same
   * address, but different types. for the pic code, we could omit
   * the following
   */
  mc35_aopOp(result, ic, TRUE);

  if (mc35_sameRegs(AOP(left), AOP(result)))
    return;

  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, result);

  //mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left),0));

  size = AOP_SIZE(result);
  if (size > getSize(OP_SYM_ETYPE(left)))
    size = getSize(OP_SYM_ETYPE(left));

  offset = 0;
  while (size--)
  {
    mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    offset++;
  }

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}
#endif

/*-----------------------------------------------------------------*/
/* genNearPointerGet - mc35_pic14_emitcode for near pointer fetch       */
/*-----------------------------------------------------------------*/
static void
genNearPointerGet(operand *left, operand *result, iCode *ic)
{
  asmop *aop = NULL;
  sym_link *ltype = operandType(left);
  sym_link *rtype = operandType(result);
  sym_link *retype = getSpec(rtype); /* bitfield type information */
  int direct = 0;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  mc35_aopOp(left, ic, FALSE);

  /* if left is rematerialisable and
     result is not bit variable type and
     the left is pointer to data space i.e
     lower 128 bytes of space */
  if (AOP_TYPE(left) == AOP_PCODE && //AOP_TYPE(left) == AOP_IMMD &&
      !IS_BITVAR(retype) && PIC_IS_DATA_PTR(ltype))
  {
    genDataPointerGet(left, result, ic);
    return;
  }

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(result, ic, FALSE);

  /* Check if can access directly instead of via a pointer */
  // zwr 2.0.0
  if ((AOP_TYPE(left) == AOP_PCODE) && (AOP(left)->aopu.pcop->type == PO_IMMEDIATE) && (AOP_SIZE(result) <= 1))
  // if ((AOP_TYPE(left) == AOP_PCODE) && (AOP(left)->aopu.pcop->type == PO_IMMEDIATE) && (AOP_SIZE(result) == 1))
  {
    direct = 1;
  }

  if (IS_BITFIELD(getSpec(operandType(result))))
  {
    genUnpackBits(result, left, direct ? -1 : POINTER, ifxForOp(IC_RESULT(ic), ic));
    goto release;
  }

  /* If the pointer value is not in a the FSR then need to put it in */
  /* Must set/reset IRP bit for use with FSR. */
  if (!direct)
    setup_fsr(left);

  //  sym_link *etype;
  /* if bitfield then unpack the bits */
  {
    /* we have can just get the values */
    int size = AOP_SIZE(result);
    int offset = 0;

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

    while (size--)
    {
      if (direct)
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(left), 0));
      else
        mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(mc35_pc_indf));
      if (AOP_TYPE(result) == AOP_LIT)
      {
        mc35_emitpcode(POC_MOVLW, mc35_popGet(AOP(result), offset));
      }
      else
      {
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }
      if (size && !direct)
      {
        inc_fsr(1);
      }
      offset++;
    }
  }

  /* now some housekeeping stuff */
  if (aop)
  {
    /* we had to allocate for this iCode */
    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    mc35_freeAsmop(NULL, aop, ic, TRUE);
  }
  else if (!direct)
  {
    /* nothing to do */
  }
  else
  {
    /* we did not allocate which means left
         already in a pointer register, then
         if size > 0 && this could be used again
         we have to point it back to where it
         belongs */
    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    if (AOP_SIZE(result) > 1 && !OP_SYMBOL(left)->remat && (OP_SYMBOL(left)->liveTo > ic->seq || ic->depth))
    {
      int size = AOP_SIZE(result) - 1;
      inc_fsr(-size);
    }
  }

release:
  /* done */
  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genGenPointerGet - gget value from generic pointer space        */
/*-----------------------------------------------------------------*/
static void
genGenPointerGet(operand *left, operand *result, iCode *ic)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, result);

  if (IS_BITFIELD(getSpec(operandType(result))))
  {
    genUnpackBits(result, left, GPOINTER, ifxForOp(IC_RESULT(ic), ic));
    return;
  }

  {
    /* emit call to __gptrget */
    char *func[] = {NULL, "__gptrget1", "__gptrget2", "__gptrget3", "__gptrget4"};
    int size = AOP_SIZE(result);
    int idx = 0;

    assert(size > 0 && size <= 4);

    /* pass arguments */
    assert(AOP_SIZE(left) == 3);
    mc35_mov2w(AOP(left), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w(AOP(left), 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(left), 2);
    call_libraryfunc(func[size]);

    /* save result */
    movwf(AOP(result), --size);
    while (size--)
    {
      mc35_emitpcode(POC_MOVFW, popRegFromIdx(mc35_Gstack_base_addr - idx++));
      movwf(AOP(result), size);
    } // while
  }

  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genConstPointerGet - get value from const generic pointer space */
/*-----------------------------------------------------------------*/
static void
genConstPointerGet(operand *left, operand *result, iCode *ic)
{
//sym_link *retype = getSpec(operandType(result));
#if 0
  symbol *albl, *blbl;          //, *clbl;
  pCodeOp *pcop;
#endif
  int i, lit;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(left, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, left, NULL, result);

  DEBUGmc35_pic14_emitcode("; ", " %d getting const pointer", __LINE__);

  lit = mc35_op_isLitLike(left);

  if (IS_BITFIELD(getSpec(operandType(result))))
  {
    genUnpackBits(result, left, lit ? -1 : CPOINTER, ifxForOp(IC_RESULT(ic), ic));
    goto release;
  }

  {
    char *func[] = {NULL, "__gptrget1", "__gptrget2", "__gptrget3", "__gptrget4"};
    // zwr 2.0.0
    int size = AOP_SIZE(result);
    // int size = min((int)getSize(OP_SYM_ETYPE(left)), AOP_SIZE(result));
    assert(size > 0 && size <= 4);

    mc35_mov2w_op(left, 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w_op(left, 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(GPTRTAG_CODE)); /* GPOINTER tag for __code space */
    call_libraryfunc(func[size]);

    movwf(AOP(result), size - 1);
    for (i = 1; i < size; i++)
    {
      mc35_emitpcode(POC_MOVFW, popRegFromIdx(mc35_Gstack_base_addr + 1 - i));
      movwf(AOP(result), size - 1 - i);
    } // for
  }

release:
  mc35_freeAsmop(left, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genPointerGet - generate code for pointer get                   */
/*-----------------------------------------------------------------*/
static void
genPointerGet(iCode *ic)
{
  operand *left, *result;
  sym_link *type, *etype;
  int p_type = -1;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  left = IC_LEFT(ic);
  result = IC_RESULT(ic);

  /* depending on the type of pointer we need to
     move it to the correct pointer register */
  type = operandType(left);
  etype = getSpec(type);

  if (IS_PTR_CONST(type))
    DEBUGmc35_pic14_emitcode("; ***", "%d - const pointer", __LINE__);

  /* if left is of type of pointer then it is simple */
  if (IS_PTR(type) && !IS_FUNC(type->next))
    p_type = DCL_TYPE(type);
  else
  {
    /* we have to go by the storage class */
    p_type = PTR_TYPE(SPEC_OCLS(etype));

    DEBUGmc35_pic14_emitcode("; ***", "%d - resolve pointer by storage class", __LINE__);

    if (SPEC_OCLS(etype)->codesp)
    {
      DEBUGmc35_pic14_emitcode("; ***", "%d - cpointer", __LINE__);
      //p_type = CPOINTER ;
    }
    else if (SPEC_OCLS(etype)->fmap && !SPEC_OCLS(etype)->paged)
      DEBUGmc35_pic14_emitcode("; ***", "%d - fpointer", __LINE__);
    /*p_type = FPOINTER ; */
    else if (SPEC_OCLS(etype)->fmap && SPEC_OCLS(etype)->paged)
      DEBUGmc35_pic14_emitcode("; ***", "%d - ppointer", __LINE__);
    /*        p_type = PPOINTER; */
    else if (SPEC_OCLS(etype) == idata)
      DEBUGmc35_pic14_emitcode("; ***", "%d - ipointer", __LINE__);
    /*      p_type = IPOINTER; */
    else
      DEBUGmc35_pic14_emitcode("; ***", "%d - pointer", __LINE__);
    /*      p_type = POINTER ; */
  }

  /* now that we have the pointer type we assign
     the pointer values */
  switch (p_type)
  {

  case POINTER:
  case FPOINTER:
    //case IPOINTER:
    genNearPointerGet(left, result, ic);
    break;
  /*
         case PPOINTER:
         genPagedPointerGet(left,result,ic);
         break;

         case FPOINTER:
         genFarPointerGet (left,result,ic);
         break;
       */
  case CPOINTER:
    genConstPointerGet(left, result, ic);
    break;

  case GPOINTER:
    genGenPointerGet(left, result, ic);
    break;
  default:
    assert(!"unhandled pointer type");
    break;
  }
}

/*-----------------------------------------------------------------*/
/* genPackBits - generates code for packed bit storage             */
/*-----------------------------------------------------------------*/
static void
genPackBits(sym_link *etype, operand *result, operand *right, int p_type)
{
  unsigned blen;           /* bitfield length */
  unsigned bstr;           /* bitfield starting bit within byte */
  int litval;         /* source literal value (if AOP_LIT) */
  unsigned char mask; /* bitmask within current byte */

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  blen = SPEC_BLEN(etype);
  bstr = SPEC_BSTR(etype);

  /* If the bitfield length is less than a byte and does not cross byte boundaries */
  if ((blen <= 8) && ((bstr + blen) <= 8))
  {
    mask = ((unsigned char)(0xFF << (blen + bstr)) | (unsigned char)(0xFF >> (8 - bstr)));

    if (AOP_TYPE(right) == AOP_LIT)
    {
      /* Case with a bitfield length <8 and literal source */
      int lit = (int)ulFromVal(AOP(right)->aopu.aop_lit);
      if (blen == 1)
      {
        pCodeOp *pcop;

        switch (p_type)
        {
        case -1:
          if (AOP(result)->type == AOP_PCODE)
            pcop = mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 0, FALSE, FALSE), bstr, 0);
          else
            pcop = mc35_popGet(AOP(result), 0);
          mc35_emitpcode(lit ? POC_BSF : POC_BCF, pcop);
          break;

        case POINTER:
        case FPOINTER:
          setup_fsr(result);
          mc35_emitpcode(lit ? POC_BSF : POC_BCF, mc35_newpCodeOpBit(PCOP(mc35_pc_indf)->name, bstr, 0));
          break;

        case CPOINTER:
          assert(!"trying to assign to bitfield via pointer to __code space");
          break;

        case GPOINTER:
          emitPtrByteGet(result, p_type, FALSE);
          if (lit)
          {
            mc35_emitpcode(POC_IORLW, mc35_newpCodeOpLit(1UL << bstr));
          }
          else
          {
            mc35_emitpcode(POC_ANDLW, mc35_newpCodeOpLit((~(1UL << bstr)) & 0x0ff));
          }
          emitPtrByteSet(result, p_type, TRUE);
          break;

        default:
          assert(!"unhandled pointer type");
          break;
        } // switch (p_type)
      }
      else
      {
        /* blen > 1 */
        litval = lit << bstr;
        litval &= (~mask) & 0x00ff;

        switch (p_type)
        {
        case -1:
          mc35_mov2w(AOP(result), 0);
          if ((litval | mask) != 0x00ff)
            mc35_emitpcode(POC_ANDLW, mc35_popGetLit(mask));
          if (litval != 0x00)
            mc35_emitpcode(POC_IORLW, mc35_popGetLit(litval));
          movwf(AOP(result), 0);
          break;

        case POINTER:
        case FPOINTER:
        case GPOINTER:
          emitPtrByteGet(result, p_type, FALSE);
          if ((litval | mask) != 0x00ff)
            mc35_emitpcode(POC_ANDLW, mc35_popGetLit(mask));
          if (litval != 0x00)
            mc35_emitpcode(POC_IORLW, mc35_popGetLit(litval));
          emitPtrByteSet(result, p_type, TRUE);
          break;

        case CPOINTER:
          assert(!"trying to assign to bitfield via pointer to __code space");
          break;

        default:
          assert(!"unhandled pointer type");
          break;
        } // switch
      }   // if (blen > 1)
    }
    else
    {
      /* right is no literal */
      if (blen == 1)
      {
        switch (p_type)
        {
        case -1:
          /* Note more efficient code, of pre clearing bit then only setting it if required,
                   * can only be done if it is known that the result is not a SFR */
          mc35_emitpcode(POC_RRFW, mc35_popGet(AOP(right), 0));
          mc35_emitSKPC;
          mc35_emitpcode(POC_BCF, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 0, FALSE, FALSE), bstr, 0));
          mc35_emitSKPNC;
          mc35_emitpcode(POC_BSF, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), 0, FALSE, FALSE), bstr, 0));
          break;

        case POINTER:
        case FPOINTER:
        case GPOINTER:
          emitPtrByteGet(result, p_type, FALSE);
          mc35_emitpcode(POC_BTFSS, mc35_newpCodeOpBit(mc35_aopGet(AOP(right), 0, FALSE, FALSE), bstr, 0));
          mc35_emitpcode(POC_ANDLW, mc35_newpCodeOpLit(~(1UL << bstr) & 0x0ff));
          mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(right), 0, FALSE, FALSE), bstr, 0));
          mc35_emitpcode(POC_IORLW, mc35_newpCodeOpLit((1UL << bstr) & 0x0ff));
          emitPtrByteSet(result, p_type, TRUE);
          break;

        case CPOINTER:
          assert(!"trying to assign to bitfield via pointer to __code space");
          break;

        default:
          assert(!"unhandled pointer type");
          break;
        } // switch
        return;
      }
      else
      {
        /* Case with a bitfield 1 < length <= 8 and arbitrary source */
        pCodeOp *temp = mc35_popGetTempReg();

        mc35_mov2w(AOP(right), 0);
        if (blen < 8)
        {
          mc35_emitpcode(POC_ANDLW, mc35_popGetLit((1UL << blen) - 1));
        }
        mc35_emitpcode(POC_MOVWF, temp);
        if (bstr)
        {
          AccLsh(temp, bstr);
        }

        switch (p_type)
        {
        case -1:
          mc35_mov2w(AOP(result), 0);
          mc35_emitpcode(POC_ANDLW, mc35_popGetLit(mask));
          mc35_emitpcode(POC_IORFW, temp);
          movwf(AOP(result), 0);
          break;

        case POINTER:
        case FPOINTER:
        case GPOINTER:
          emitPtrByteGet(result, p_type, FALSE);
          mc35_emitpcode(POC_ANDLW, mc35_popGetLit(mask));
          mc35_emitpcode(POC_IORFW, temp);
          emitPtrByteSet(result, p_type, TRUE);
          break;

        case CPOINTER:
          assert(!"trying to assign to bitfield via pointer to __code space");
          break;

        default:
          assert(!"unhandled pointer type");
          break;
        } // switch

        popReleaseTempReg(temp);
      } // if (blen > 1)
    }   // if (AOP(right)->type != AOP_LIT)
    return;
  } // if (blen <= 8 && ((blen + bstr) <= 8))

  assert(!"bitfields larger than 8 bits or crossing byte boundaries are not yet supported");
}

/*-----------------------------------------------------------------*/
/* genDataPointerSet - remat pointer to data space                 */
/*-----------------------------------------------------------------*/
static void
genDataPointerSet(operand *right, operand *result, iCode *ic)
{
  int size = 0;
  int offset = 0;
  // zwr 2.0.0
  sym_link *rtype = operandType(right);
  // int ressize;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  assert(IS_SYMOP(result));
  assert(IS_PTR(OP_SYM_TYPE(result)));

  /*
   * Determine size from right operand (not result):
   * The result might be a rematerialized pointer to (the first field in) a struct,
   * which then assumes the type (and size) of the struct rather than the first field.
   */
  // if (IS_SYMOP(right))
  //   size = getSize(OP_SYM_ETYPE(right));
  // else if (IS_VALOP(right))
  //   size = getSize(OP_VALUE(right)->type);
  // else
  //   assert(!"Invalid operand.");

  // ressize = getSize(OP_SYM_ETYPE(result));

  //assert( !"what's going on here?" );

  /*
     if ( AOP_TYPE(result) == AOP_PCODE) {
     fprintf(stderr,"genDataPointerSet   %s, %d\n",
     AOP(result)->aopu.pcop->name,
     PCOI(AOP(result)->aopu.pcop)->offset);
     }
   */

  // tsd, was l+1 - the underline `_' prefix was being stripped

  // zwr 2.0.0
  size = AOP_SIZE(right);

  /*test the right operand has a pointer value*/
  if ((AOP_TYPE(right) == AOP_PCODE) && PIC_IS_DATA_PTR(rtype))
  {
    while (size--)
    {
      mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(right), size, 0));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), size));
    }
  }
  else
  {
    // tsd, was l+1 - the underline `_' prefix was being stripped
    while (size--)
    {
      // zwr 2.0.0
      mc35_emitpComment("%s:%u: size=%d, offset=%d, AOP_TYPE(res)=%d", __FILE__, __LINE__, size, offset,
                   AOP_TYPE(result));
      // mc35_emitpComment("%s:%u: size=%d/%d, offset=%d, AOP_TYPE(res)=%d", __FILE__, __LINE__, size, ressize, offset,
      //                   AOP_TYPE(result));

      if (AOP_TYPE(right) == AOP_LIT)
      {
        unsigned int lit = pic14aopLiteral(AOP(IC_RIGHT(ic))->aopu.aop_lit, offset);
        //fprintf (stderr, "%s:%u: lit %d 0x%x\n", __FUNCTION__,__LINE__, lit, lit);
        if (lit & 0xff)
        {
          mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
          mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
        }
        else
        {
          mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
        }
      }
      else
      {
        //fprintf (stderr, "%s:%u: no lit\n", __FUNCTION__,__LINE__);
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }

      offset++;
    }
  }

  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genNearPointerSet - mc35_pic14_emitcode for near pointer put         */
/*-----------------------------------------------------------------*/
static void
genNearPointerSet(operand *right, operand *result, iCode *ic)
{
  asmop *aop = NULL;
  sym_link *ptype = operandType(result);
  sym_link *retype = getSpec(operandType(right));
  sym_link *letype = getSpec(ptype);
  int direct = 0;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(result, ic, FALSE);

#if 1
  /* if the result is rematerializable &
     in data space & not a bit variable */
  //if (AOP_TYPE(result) == AOP_IMMD &&
  if (AOP_TYPE(result) == AOP_PCODE && PIC_IS_DATA_PTR(ptype) && !IS_BITVAR(retype) && !IS_BITVAR(letype))
  {
    genDataPointerSet(right, result, ic);
    mc35_freeAsmop(result, NULL, ic, TRUE);
    return;
  }
#endif

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(right, ic, FALSE);
  DEBUGmc35_pic14_AopType(__LINE__, NULL, right, result);

  /* Check if can access directly instead of via a pointer */
  if ((AOP_TYPE(result) == AOP_PCODE) && (AOP(result)->aopu.pcop->type == PO_IMMEDIATE) && (AOP_SIZE(right) == 1))
  {
    direct = 1;
  }

  if (IS_BITFIELD(letype))
  {
    genPackBits(letype, result, right, direct ? -1 : POINTER);
    return;
  }

  /* If the pointer value is not in a the FSR then need to put it in */
  /* Must set/reset IRP bit for use with FSR. */
  /* Note only do this once - assuming that never need to cross a bank boundary at address 0x100. */
  if (!direct)
    setup_fsr(result);

  {
    /* we have can just get the values */
    int size = AOP_SIZE(right);
    int offset = 0;

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    while (size--)
    {
      char *l = mc35_aopGet(AOP(right), offset, FALSE, TRUE);
      if (*l == '@')
      {
        mc35_emitpcode(POC_MOVFW, mc35_popCopyReg(mc35_pc_indf));
      }
      else
      {
        if (AOP_TYPE(right) == AOP_LIT)
        {
          mc35_emitpcode(POC_MOVLW, mc35_popGet(AOP(right), offset));
        }
        else
        {
          mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        }
        if (direct)
          mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));
        else
          mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(mc35_pc_indf));
      }
      if (size && !direct)
        inc_fsr(1);
      offset++;
    }
  }

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* now some housekeeping stuff */
  if (aop)
  {
    /* we had to allocate for this iCode */
    mc35_freeAsmop(NULL, aop, ic, TRUE);
  }
  else if (!direct)
  {
    /* nothing to do */
  }
  else
  {
    /* we did not allocate which means left
         already in a pointer register, then
         if size > 0 && this could be used again
         we have to point it back to where it
         belongs */
    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    if (AOP_SIZE(right) > 1 && !OP_SYMBOL(result)->remat && (OP_SYMBOL(result)->liveTo > ic->seq || ic->depth))
    {
      int size = AOP_SIZE(right) - 1;
      inc_fsr(-size);
    }
  }

  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* done */

  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genGenPointerSet - set value from generic pointer space         */
/*-----------------------------------------------------------------*/
static void
genGenPointerSet(operand *right, operand *result, iCode *ic)
{
  sym_link *retype = getSpec(operandType(result));

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, right, NULL, result);

  if (IS_BITFIELD(retype))
  {
    genPackBits(retype, result, right, GPOINTER);
    return;
  }

  {
    /* emit call to __gptrput */
    char *func[] = {NULL, "__gptrput1", "__gptrput2", "__gptrput3", "__gptrput4"};
    int size = AOP_SIZE(right);
    int idx = 0;

    /* The following assertion fails for
     *   struct foo { char a; char b; } bar;
     *   void demo(struct foo *dst, char c) { dst->b = c; }
     * as size will be 1 (sizeof(c)), whereas dst->b will be accessed
     * using (((char *)dst)+1), whose OP_SYM_ETYPE still is struct foo
     * of size 2.
     * The frontend seems to guarantee that IC_LEFT has the correct size,
     * it works fine both for larger and smaller types of `char c'.
     * */
    //assert (size == getSize(OP_SYM_ETYPE(result)));
    assert(size > 0 && size <= 4);

    /* pass arguments */
    /* - value (MSB in mc35_Gstack_base_addr-2, growing downwards) */
    {
      int off = size;
      idx = 2;
      while (off--)
      {
        mc35_mov2w_op(right, off);
        mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - idx++));
      }
      idx = 0;
    }
    /* - address */
    assert(AOP_SIZE(result) == 3);
    mc35_mov2w(AOP(result), 0);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr - 1));
    mc35_mov2w(AOP(result), 1);
    mc35_emitpcode(POC_MOVWF, popRegFromIdx(mc35_Gstack_base_addr));
    mc35_mov2w(AOP(result), 2);
    call_libraryfunc(func[size]);
  }

  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genPointerSet - stores the value into a pointer location        */
/*-----------------------------------------------------------------*/
static void
genPointerSet(iCode *ic)
{
  operand *right, *result;
  sym_link *type, *etype;
  int p_type;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  right = IC_RIGHT(ic);
  result = IC_RESULT(ic);

  /* depending on the type of pointer we need to
     move it to the correct pointer register */
  type = operandType(result);
  etype = getSpec(type);
  /* if left is of type of pointer then it is simple */
  if (IS_PTR(type) && !IS_FUNC(type->next))
  {
    p_type = DCL_TYPE(type);
  }
  else
  {
    /* we have to go by the storage class */
    p_type = PTR_TYPE(SPEC_OCLS(etype));

    /*  if (SPEC_OCLS(etype)->codesp ) { */
    /*      p_type = CPOINTER ;  */
    /*  } */
    /*  else */
    /*      if (SPEC_OCLS(etype)->fmap && !SPEC_OCLS(etype)->paged) */
    /*    p_type = FPOINTER ; */
    /*      else */
    /*    if (SPEC_OCLS(etype)->fmap && SPEC_OCLS(etype)->paged) */
    /*        p_type = PPOINTER ; */
    /*    else */
    /*        if (SPEC_OCLS(etype) == idata ) */
    /*      p_type = IPOINTER ; */
    /*        else */
    /*      p_type = POINTER ; */
  }

  /* now that we have the pointer type we assign
     the pointer values */
  switch (p_type)
  {

  case POINTER:
  case FPOINTER:
    //case IPOINTER:
    genNearPointerSet(right, result, ic);
    break;
  /*
         case PPOINTER:
         genPagedPointerSet (right,result,ic);
         break;

         case FPOINTER:
         genFarPointerSet (right,result,ic);
         break;
       */
  case GPOINTER:
    genGenPointerSet(right, result, ic);
    break;

  default:
    werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "genPointerSet: illegal pointer type");
  }
}

/*-----------------------------------------------------------------*/
/* genIfx - generate code for Ifx statement                        */
/*-----------------------------------------------------------------*/
static void
genIfx(iCode *ic, iCode *popIc)
{
  operand *cond = IC_COND(ic);
  int isbit = 0;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  mc35_aopOp(cond, ic, FALSE);

  /* get the value into acc */
  if (AOP_TYPE(cond) != AOP_CRY)
    pic14_toBoolean(cond);
  else
    isbit = 1;

  /* if there was something to be popped then do it */
  if (popIc)
    genIpop(popIc);

  if (isbit)
  {
    /* This assumes that CARRY is set iff cond is true */
    if (IC_TRUE(ic))
    {
      assert(!IC_FALSE(ic));
      mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(cond), 0));
      //mc35_emitSKPNC;
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_TRUE(ic)->key));
    }
    else
    {
      assert(IC_FALSE(ic));
      mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(cond), 0));
      //mc35_emitSKPC;
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_FALSE(ic)->key));
    }
    if (0)
    {
      static int hasWarned = 0;
      if (!hasWarned)
      {
        fprintf(stderr, "WARNING: using untested code for %s:%u -- please check the .asm output and report bugs.\n",
                ic->filename, ic->lineno);
        hasWarned = 1;
      }
    }
  }
  else
  {
    /* now Z is set iff !cond */
    if (IC_TRUE(ic))
    {
      assert(!IC_FALSE(ic));
      mc35_emitSKPZ;
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_TRUE(ic)->key));
    }
    else
    {
      mc35_emitSKPNZ;
      mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_FALSE(ic)->key));
    }
  }

  ic->generated = TRUE;

  /* the result is now in the accumulator */
  mc35_freeAsmop(cond, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genAddrOf - generates code for address of                       */
/*-----------------------------------------------------------------*/
static void
genAddrOf(iCode *ic)
{
  operand *right, *result, *left;
  int size, offset;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  //mc35_aopOp(IC_RESULT(ic),ic,FALSE);

  mc35_aopOp((left = IC_LEFT(ic)), ic, FALSE);
  mc35_aopOp((right = IC_RIGHT(ic)), ic, FALSE);
  mc35_aopOp((result = IC_RESULT(ic)), ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, left, right, result);
  assert(IS_SYMOP(left));

/* sanity check: generic pointers to code space are not yet supported,
   * pionters to codespace must not be assigned addresses of __data values. */
#if 0
  fprintf (stderr, "result: %s, left: %s\n", OP_SYMBOL (result)->name, OP_SYMBOL (left)->name);
  fprintf (stderr, "result->type : ");
  printTypeChain (OP_SYM_TYPE (result), stderr);
  fprintf (stderr, ", codesp:%d, codeptr:%d, constptr:%d\n", IN_CODESPACE (SPEC_OCLS (getSpec (OP_SYM_TYPE (result)))),
           IS_CODEPTR (OP_SYM_TYPE (result)), IS_PTR_CONST (OP_SYM_TYPE (result)));
  fprintf (stderr, "result->etype: ");
  printTypeChain (OP_SYM_ETYPE (result), stderr);
  fprintf (stderr, ", codesp:%d, codeptr:%d, constptr:%d\n", IN_CODESPACE (SPEC_OCLS (getSpec (OP_SYM_ETYPE (result)))),
           IS_CODEPTR (OP_SYM_ETYPE (result)), IS_PTR_CONST (OP_SYM_ETYPE (result)));
  fprintf (stderr, "left->type   : ");
  printTypeChain (OP_SYM_TYPE (left), stderr);
  fprintf (stderr, ", codesp:%d, codeptr:%d, constptr:%d\n", IN_CODESPACE (SPEC_OCLS (getSpec (OP_SYM_TYPE (left)))),
           IS_CODEPTR (OP_SYM_TYPE (left)), IS_PTR_CONST (OP_SYM_TYPE (left)));
  fprintf (stderr, "left->etype  : ");
  printTypeChain (OP_SYM_ETYPE (left), stderr);
  fprintf (stderr, ", codesp:%d, codeptr:%d, constptr:%d\n", IN_CODESPACE (SPEC_OCLS (getSpec (OP_SYM_ETYPE (left)))),
           IS_CODEPTR (OP_SYM_ETYPE (left)), IS_PTR_CONST (OP_SYM_ETYPE (left)));
#endif

  if (IS_SYMOP(result) && IS_CODEPTR(OP_SYM_TYPE(result)) && !IN_CODESPACE(SPEC_OCLS(getSpec(OP_SYM_TYPE(left)))))
  {
    fprintf(stderr, "trying to assign __code pointer (%s) an address in __data space (&%s) -- expect trouble\n",
            IS_SYMOP(result) ? OP_SYMBOL(result)->name : "unknown", OP_SYMBOL(left)->name);
  }
  else if (IS_SYMOP(result) && !IS_CODEPTR(OP_SYM_TYPE(result)) && IN_CODESPACE(SPEC_OCLS(getSpec(OP_SYM_TYPE(left)))))
  {
    fprintf(stderr, "trying to assign __data pointer (%s) an address in __code space (&%s) -- expect trouble\n",
            IS_SYMOP(result) ? OP_SYMBOL(result)->name : "unknown", OP_SYMBOL(left)->name);
  }

  size = AOP_SIZE(IC_RESULT(ic));
  if (IS_SYMOP(result) && IS_GENPTR(OP_SYM_TYPE(result)))
  {
    /* strip tag */
    if (size > GPTRSIZE - 1)
      size = GPTRSIZE - 1;
  }
  offset = 0;

  while (size--)
  {
    /* fixing bug #863624, reported from (errolv) */
    mc35_emitpcode(POC_MOVLW, mc35_popGetImmd(OP_SYMBOL(left)->rname, offset, 0, IS_FUNC(OP_SYM_TYPE(left))));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));

#if 0
      mc35_emitpcode (POC_MOVLW, mc35_popGet (AOP (left), offset));
      mc35_emitpcode (POC_MOVWF, mc35_popGet (AOP (result), offset));
#endif
    offset++;
  }

  if (IS_SYMOP(result) && IS_GENPTR(OP_SYM_TYPE(result)))
  {
    /* provide correct tag */
    int isCode = IN_CODESPACE(SPEC_OCLS(getSpec(OP_SYM_TYPE(left))));
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(isCode ? GPTRTAG_CODE : GPTRTAG_DATA));
    movwf(AOP(result), 2);
  }

  mc35_freeAsmop(left, NULL, ic, FALSE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genAssign - generate code for assignment                        */
/*-----------------------------------------------------------------*/
static void
genAssign(iCode *ic)
{
  operand *result, *right;
  int size, offset, know_W;
  unsigned long lit = 0L;

  result = IC_RESULT(ic);
  right = IC_RIGHT(ic);

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  /* if they are the same */
  if (operandsEqu(IC_RESULT(ic), IC_RIGHT(ic)))
    return;

  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, TRUE);

  DEBUGmc35_pic14_AopType(__LINE__, NULL, right, result);

  /* if they are the same registers */
  if (mc35_sameRegs(AOP(right), AOP(result)))
    goto release;

  /* special case: assign from __code */
  if (!IS_ITEMP(right)                   /* --> iTemps never reside in __code */
      && IS_SYMOP(right)                 /* --> must be an immediate (otherwise we would be in genConstPointerGet) */
      && !IS_FUNC(OP_SYM_TYPE(right))    /* --> we would want its address instead of the first instruction */
      && !IS_CODEPTR(OP_SYM_TYPE(right)) /* --> get symbols address instread */
      && IN_CODESPACE(SPEC_OCLS(getSpec(OP_SYM_TYPE(right)))))
  {
    mc35_emitpComment("genAssign from CODESPACE");
    genConstPointerGet(right, result, ic);
    goto release;
  }

  /* just for symmetry reasons... */
  if (!IS_ITEMP(result) && IS_SYMOP(result) && IN_CODESPACE(SPEC_OCLS(getSpec(OP_SYM_TYPE(result)))))
  {
    assert(!"cannot write to CODESPACE");
  }

  /* if the result is a bit */
  if (AOP_TYPE(result) == AOP_CRY)
  {

    /* if the right size is a literal then
         we know what the value is */
    if (AOP_TYPE(right) == AOP_LIT)
    {

      mc35_emitpcode((((int)operandLitValue(right)) ? POC_BSF : POC_BCF), mc35_popGet(AOP(result), 0));

      if (((int)operandLitValue(right)))
        mc35_pic14_emitcode("bsf", "(%s >> 3),(%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
      else
        mc35_pic14_emitcode("bcf", "(%s >> 3),(%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
      goto release;
    }

    /* the right is also a bit variable */
    if (AOP_TYPE(right) == AOP_CRY)
    {
      mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));
      mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(right), 0));
      mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));

      mc35_pic14_emitcode("bcf", "(%s >> 3),(%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
      mc35_pic14_emitcode("btfsc", "(%s >> 3),(%s & 7)", AOP(right)->aopu.aop_dir, AOP(right)->aopu.aop_dir);
      mc35_pic14_emitcode("bsf", "(%s >> 3),(%s & 7)", AOP(result)->aopu.aop_dir, AOP(result)->aopu.aop_dir);
      goto release;
    }

    /* we need to or */
    mc35_emitpcode(POC_BCF, mc35_popGet(AOP(result), 0));
    pic14_toBoolean(right);
    mc35_emitSKPZ;
    mc35_emitpcode(POC_BSF, mc35_popGet(AOP(result), 0));
    //mc35_aopPut(AOP(result),"a",0);
    goto release;
  }

  /* bit variables done */
  /* general case */
  size = AOP_SIZE(result);
  offset = 0;
  if (AOP_TYPE(right) == AOP_DIR && (AOP_TYPE(result) == AOP_REG) && size == 1)
  {
    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    if (aopIdx(AOP(result), 0) == 4)
    {
      DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
      mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      goto release;
    }
    else
      DEBUGmc35_pic14_emitcode("; WARNING", "%s  %d ignoring register storage", __FUNCTION__, __LINE__);
  }

  know_W = -1;
  while (size--)
  {

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    if (AOP_TYPE(right) == AOP_LIT)
    {
      lit = (unsigned long)pic14aopLiteral(AOP(right)->aopu.aop_lit, offset) & 0x0ff;
      if (lit & 0xff)
      {
        if (know_W != (int)(lit & 0xff))
          mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
        know_W = lit & 0xff;
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
      }
      else
        mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
    }
    else if (AOP_TYPE(right) == AOP_CRY)
    {
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
      if (offset == 0)
      {
        mc35_emitpcode(POC_BTFSS, mc35_popGet(AOP(right), 0));
        // zwr 1.0.0 inst incr #2
        // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
        mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
        mc35_emitpcodeNULLop(POC_NOP);
      }
    }
    else
    {
      mc35_mov2w_op(right, offset);
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    }

    offset++;
  }

release:
  mc35_freeAsmop(right, NULL, ic, FALSE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genJumpTab - genrates code for jump table                       */
/*-----------------------------------------------------------------*/
static void
genJumpTab(iCode *ic)
{
  symbol *jtab;
  char *l;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  mc35_aopOp(IC_JTCOND(ic), ic, FALSE);
  /* get the condition into accumulator */
  l = mc35_aopGet(AOP(IC_JTCOND(ic)), 0, FALSE, FALSE);
  MOVA(l);
  /* multiply by three */
  mc35_pic14_emitcode("add", "a,acc");
  mc35_pic14_emitcode("add", "a,%s", mc35_aopGet(AOP(IC_JTCOND(ic)), 0, FALSE, FALSE));

  jtab = newiTempLabel(NULL);
  mc35_pic14_emitcode("mov", "dptr,#%05d_DS_", labelKey2num(jtab->key));
  mc35_pic14_emitcode("jmp", "@a+dptr");
  mc35_pic14_emitcode("", "%05d_DS_:", labelKey2num(jtab->key));

  // zwr 1.0.0, revise for switch

  // //mc35_emitpcode(POC_MOVLW, mc35_popGetHighLabel(jtab->key));
  // //mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_pclath));
  // mc35_emitpcode(POC_MOVLW, mc35_popGetLabel(jtab->key));
  // mc35_emitpcode(POC_ADDFW, mc35_popGet(AOP(IC_JTCOND(ic)), 0));
  // //mc35_emitSKPNC;
  // //mc35_emitpcode(POC_INCF, mc35_popCopyReg(&mc35_pc_pclath));
  // mc35_emitpcode(POC_MOVWF, mc35_popCopyReg(&mc35_pc_pcl));

  mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_JTCOND(ic)), 0));
  mc35_emitpcode(POC_ADDWF, mc35_popCopyReg(&mc35_pc_pcl));

  mc35_emitpLabel(jtab->key);

  mc35_freeAsmop(IC_JTCOND(ic), NULL, ic, TRUE);

  /* now generate the jump labels */
  for (jtab = setFirstItem(IC_JTLABELS(ic)); jtab; jtab = setNextItem(IC_JTLABELS(ic)))
  {
    mc35_pic14_emitcode("ljmp", "%05d_DS_", labelKey2num(jtab->key));
    mc35_emitpcode(POC_GOTO, mc35_popGetLabel(jtab->key));
  }
}

/*-----------------------------------------------------------------*/
/* genCast - gen code for casting                                  */
/*-----------------------------------------------------------------*/
static void
genCast(iCode *ic)
{
  operand *result = IC_RESULT(ic);
  sym_link *restype = operandType(result);
  sym_link *rtype = operandType(IC_RIGHT(ic));
  operand *right = IC_RIGHT(ic);
  int size, offset;

  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
  /* if they are equivalent then do nothing */
  if (operandsEqu(IC_RESULT(ic), IC_RIGHT(ic)))
    return;

  mc35_aopOp(right, ic, FALSE);
  mc35_aopOp(result, ic, FALSE);

  DEBUGmc35_pic14_AopType(__LINE__, NULL, right, result);

  /* if the result is a bit */
  if (AOP_TYPE(result) == AOP_CRY)
  {
    assert(!"assigning to bit variables is not supported");
  }

  if ((AOP_TYPE(right) == AOP_CRY) && (AOP_TYPE(result) == AOP_REG))
  {
    int offset = 1;
    size = AOP_SIZE(result);

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

    mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), 0));
    mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(right), 0));
    // zwr 1.0.0 inst incr #2
    // mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
    mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
    mc35_emitpcodeNULLop(POC_NOP);

    while (size--)
      mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset++));

    goto release;
  }

  if (IS_BOOL(operandType(result)))
  {
    pic14_toBoolean(right);
    mc35_emitSKPNZ;
    mc35_emitpcode(POC_MOVLW, mc35_popGetLit(1));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));
    goto release;
  }

  if (IS_PTR(restype))
  {
    operand *result = IC_RESULT(ic);
    //operand *left = IC_LEFT(ic);
    operand *right = IC_RIGHT(ic);
    int tag = 0xff;

    /* copy common part */
    int max, size = AOP_SIZE(result);
    if (size > AOP_SIZE(right))
      size = AOP_SIZE(right);
    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

    /* warn if we discard generic opinter tag */
    if (!IS_GENPTR(restype) && IS_GENPTR(rtype) && (AOP_SIZE(result) < AOP_SIZE(right)))
    {
      //fprintf (stderr, "%s:%u: discarding generic pointer type tag\n", __FUNCTION__, __LINE__);
    } // if

    max = size;
    while (size--)
    {
      mc35_mov2w_op(right, size);
      movwf(AOP(result), size);
    } // while

    /* upcast into generic pointer type? */
    if (IS_GENPTR(restype) && (size < AOP_SIZE(result)) && (!IS_GENPTR(rtype) || AOP_SIZE(right) < GPTRSIZE))
    {
      //fprintf (stderr, "%s:%u: must determine pointer type\n", __FUNCTION__, __LINE__);
      if (IS_PTR(rtype))
      {
        switch (DCL_TYPE(rtype))
        {
        case POINTER:  /* __data */
        case FPOINTER: /* __data */
          assert(AOP_SIZE(right) == 2);
          tag = GPTRTAG_DATA;
          break;

        case CPOINTER: /* __code */
          assert(AOP_SIZE(right) == 2);
          tag = GPTRTAG_CODE;
          break;

        case GPOINTER: /* unknown destination, __data or __code */
          /* assume __data space (address of immediate) */
          assert(AOP_TYPE(right) == AOP_PCODE && AOP(right)->aopu.pcop->type == PO_IMMEDIATE);
          if (AOP(right)->code)
            tag = GPTRTAG_CODE;
          else
            tag = GPTRTAG_DATA;
          break;

        default:
          assert(!"unhandled pointer type");
        } // switch
      }
      else
      {
        /* convert other values into pointers to __data space */
        tag = GPTRTAG_DATA;
      }

      assert(AOP_SIZE(result) == 3);
      if (tag == 0)
      {
        mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), 2));
      }
      else
      {
        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(tag));
        movwf(AOP(result), 2);
      }
    }
    else
    {
      mc35_addSign(result, max, 0);
    } // if
    goto release;
  }

  /* if they are the same size : or less */
  if (AOP_SIZE(result) <= AOP_SIZE(right))
  {

    /* if they are in the same place */
    if (mc35_sameRegs(AOP(right), AOP(result)))
      goto release;

    DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
    if (IS_PTR_CONST(rtype))
      DEBUGmc35_pic14_emitcode("; ***", "%d - right is const pointer", __LINE__);
    if (IS_PTR_CONST(operandType(IC_RESULT(ic))))
      DEBUGmc35_pic14_emitcode("; ***", "%d - result is const pointer", __LINE__);

    if ((AOP_TYPE(right) == AOP_PCODE) && AOP(right)->aopu.pcop->type == PO_IMMEDIATE)
    {
      mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(right), 0, 0));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 0));
      mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(right), 1, 0));
      mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), 1));
      if (AOP_SIZE(result) < 2)
        fprintf(stderr, "%d -- result is not big enough to hold a ptr\n", __LINE__);
    }
    else
    {

      /* if they in different places then copy */
      size = AOP_SIZE(result);
      offset = 0;
      while (size--)
      {
        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));

        //mc35_aopPut(AOP(result),
        // mc35_aopGet(AOP(right),offset,FALSE,FALSE),
        // offset);

        offset++;
      }
    }
    goto release;
  }

  /* so we now know that the size of destination is greater
     than the size of the source. */

  /* we move to result for the size of source */
  size = AOP_SIZE(right);
  offset = 0;
  while (size--)
  {
    mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(right), offset));
    mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
    offset++;
  }

  mc35_addSign(result, AOP_SIZE(right), !SPEC_USIGN(rtype));

release:
  mc35_freeAsmop(right, NULL, ic, TRUE);
  mc35_freeAsmop(result, NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genDjnz - generate decrement & jump if not zero instrucion      */
/*-----------------------------------------------------------------*/
static int
genDjnz(iCode *ic, iCode *ifx)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (!ifx)
    return 0;

  /* if the if condition has a false label
     then we cannot save */
  if (IC_FALSE(ifx))
    return 0;

  /* if the minus is not of the form
     a = a - 1 */
  if (!isOperandEqual(IC_RESULT(ic), IC_LEFT(ic)) || !IS_OP_LITERAL(IC_RIGHT(ic)))
    return 0;

  if (operandLitValue(IC_RIGHT(ic)) != 1)
    return 0;

  /* if the size of this greater than one then no
     saving */
  if (getSize(operandType(IC_RESULT(ic))) > 1)
    return 0;

  /* otherwise we can save BIG */
  mc35_aopOp(IC_RESULT(ic), ic, FALSE);

  mc35_emitpcode(POC_DECFSZ, mc35_popGet(AOP(IC_RESULT(ic)), 0));
  mc35_emitpcode(POC_GOTO, mc35_popGetLabel(IC_TRUE(ifx)->key));

  mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
  ifx->generated = TRUE;
  return 1;
}

/*-----------------------------------------------------------------*/
/* genReceive - generate code for a receive iCode                  */
/*-----------------------------------------------------------------*/
static void
genReceive(iCode *ic)
{
  FENTRY;
  DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

  if (isOperandInFarSpace(IC_RESULT(ic)) && (OP_SYMBOL(IC_RESULT(ic))->isspilt || IS_TRUE_SYMOP(IC_RESULT(ic))))
  {

    int size = getSize(operandType(IC_RESULT(ic)));
    int offset = mc35_fReturnSizePic - size;
    while (size--)
    {
      mc35_pic14_emitcode("push", "%s", (strcmp(mc35_fReturn[mc35_fReturnSizePic - offset - 1], "a") ? mc35_fReturn[mc35_fReturnSizePic - offset - 1] : "acc"));
      offset++;
    }
    mc35_aopOp(IC_RESULT(ic), ic, FALSE);
    size = AOP_SIZE(IC_RESULT(ic));
    offset = 0;
    while (size--)
    {
      mc35_pic14_emitcode("pop", "acc");
      mc35_aopPut(AOP(IC_RESULT(ic)), "a", offset++);
    }
  }
  else
  {
    _G.accInUse++;
    mc35_aopOp(IC_RESULT(ic), ic, FALSE);
    _G.accInUse--;
    mc35_GpseudoStkPtr = ic->parmBytes; // address used arg on stack
    assignResultValue(IC_RESULT(ic));
  }

  mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* genDummyRead - generate code for dummy read of volatiles        */
/*-----------------------------------------------------------------*/
static void
genDummyRead(iCode *ic)
{
  FENTRY;
  mc35_pic14_emitcode("; genDummyRead", "");
  mc35_pic14_emitcode("; not implemented", "");

  ic = ic;
}

// zwr 1.0.0
void mc35_newVal()
{
  QValList *tempval;

  tempval = (struct QValList *)malloc(sizeof(struct QValList));
  tempval->firstval = NULL;
  tempval->val = NULL;
  tempval->next = NULL;

  if (!mc35_ValList)
  {
    mc35_ValList = tempval;
    mc35_ValList->firstItem = mc35_ValList;
    mc35_ValList->next = NULL;
  }
  else
  {
    tempval->firstItem = mc35_ValList->firstItem;
    mc35_ValList->next = tempval;
    mc35_ValList = tempval;
  }
  tempval->funname = (char *)malloc(50);
  strcpy(tempval->funname, currFunc->name);
}

/*-----------------------------------------------------------------*/
/* mc35_genpic14Code - generate code for pic14 based controllers        */
/*-----------------------------------------------------------------*/
/*
* At this point, ralloc.c has gone through the iCode and attempted
* to optimize in a way suitable for a PIC. Now we've got to generate
* PIC instructions that correspond to the iCode.
*
* Once the instructions are generated, we'll pass through both the
* peep hole optimizer and the pCode optimizer.
*-----------------------------------------------------------------*/

void mc35_genpic14Code(iCode *lic)
{
  iCode *ic;
  int cln = 0;
  const char *cline;

  // zwr 1.0.0
  /* print the allocation information */
  if (currFunc)
  {
    if (!ValLog)
    {
      ValLog = dbuf_new(102400);
    }
    mc35_newVal();
    SaveAllocInfo(currFunc, mc35_ValList);
    //printAllocInfo(currFunc,ValLog);
  }

  FENTRY;

  // zwr 2.0.0
  mc35_pic = mc35_getPIC();

  pb = mc35_newpCodeChain(GcurMemmap, 0, mc35_newpCodeCharP("; Starting pCode block"));
  mc35_addpBlock(pb);

  /* if debug information required */
  if (options.debug && debugFile && currFunc)
  {
    debugFile->writeFunction(currFunc, lic);
  }

  for (ic = lic; ic; ic = ic->next)
  {
    initGenLineElement();

    //DEBUGmc35_pic14_emitcode(";ic","");
    //fprintf (stderr, "in ic loop\n");
    //mc35_pic14_emitcode ("", ";\t%s:%d: %s", ic->filename,
    //ic->lineno, printCLine(ic->filename, ic->lineno));

    if (!options.noCcodeInAsm && (cln != ic->lineno))
    {
      cln = ic->lineno;
      //fprintf (stderr, "%s\n", printCLine (ic->filename, ic->lineno));
      cline = printCLine(ic->filename, ic->lineno);
      if (!cline || strlen(cline) == 0)
        cline = printCLine(ic->filename, ic->lineno);
      mc35_addpCode2pBlock(pb, mc35_newpCodeCSource(ic->lineno, ic->filename, cline));
      //mc35_emitpComment ("[C-SRC] %s:%d: %s", ic->filename, cln, cline);
    }

    if (options.iCodeInAsm)
    {
      const char *iLine = printILine(ic);
      mc35_emitpComment("[ICODE] %s:%d: %s", ic->filename, ic->lineno, printILine(ic));
      dbuf_free(iLine);
    }
    /* if the result is marked as
         spilt and rematerializable or code for
         this has already been generated then
         do nothing */
    if (resultRemat(ic) || ic->generated)
      continue;

    /* depending on the operation */
    switch (ic->op)
    {
    case '!':
      genNot(ic);
      break;

    case '~':
      genCpl(ic);
      break;

    case UNARYMINUS:
      genUminus(ic);
      break;

    case IPUSH:
      genIpush(ic);
      break;

    case IPOP:
      /* IPOP happens only when trying to restore a
             spilt live range, if there is an ifx statement
             following this pop then the if statement might
             be using some of the registers being popped which
             would destory the contents of the register so
             we need to check for this condition and handle it */
      if (ic->next && ic->next->op == IFX && regsInCommon(IC_LEFT(ic), IC_COND(ic->next)))
        genIfx(ic->next, ic);
      else
        genIpop(ic);
      break;

    case CALL:
      genCall(ic);
      break;

    case PCALL:
      genPcall(ic);
      break;

    case FUNCTION:
      genFunction(ic);
      break;

    case ENDFUNCTION:
      genEndFunction(ic);
      break;

    case RETURN:
      genRet(ic);
      break;

    case LABEL:
      genLabel(ic);
      break;

    case GOTO:
      genGoto(ic);
      break;

    case '+':
      mc35_genPlus(ic);
      break;

    case '-':
      if (!genDjnz(ic, ifxForOp(IC_RESULT(ic), ic)))
        mc35_genMinus(ic);
      break;

    case '*':
      genMult(ic);
      break;

    case '/':
      genDiv(ic);
      break;

    case '%':
      genMod(ic);
      break;

    case '>':
      genCmpGt(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case '<':
      genCmpLt(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case LE_OP:
    case GE_OP:
    case NE_OP:

      /* note these two are xlated by algebraic equivalence
             during parsing SDCC.y */
      werror(E_INTERNAL_ERROR, __FILE__, __LINE__, "got '>=' or '<=' shouldn't have come here");
      break;

    case EQ_OP:
      genCmpEq(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case AND_OP:
      genAndOp(ic);
      break;

    case OR_OP:
      genOrOp(ic);
      break;

    case '^':
      genXor(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case '|':
      genOr(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case BITWISEAND:
      genAnd(ic, ifxForOp(IC_RESULT(ic), ic));
      break;

    case INLINEASM:
      pic14_genInline(ic);
      break;

    case RRC:
      genRRC(ic);
      break;

    case RLC:
      genRLC(ic);
      break;

    case GETABIT:
      genGetABit(ic);
      break;

    case GETHBIT:
      genGetHbit(ic);
      break;

    case LEFT_OP:
      genLeftShift(ic);
      break;

    case RIGHT_OP:
      genRightShift(ic);
      break;

    case GET_VALUE_AT_ADDRESS:
      genPointerGet(ic);
      break;

    case '=':
      if (POINTER_SET(ic))
        genPointerSet(ic);
      else
        genAssign(ic);
      break;

    case IFX:
      genIfx(ic, NULL);
      break;

    case ADDRESS_OF:
      genAddrOf(ic);
      break;

    case JUMPTABLE:
      genJumpTab(ic);
      break;

    case CAST:
      genCast(ic);
      break;

    case RECEIVE:
      genReceive(ic);
      break;

    case SEND:
      addSet(&_G.sendSet, ic);
      break;

    case DUMMY_READ_VOLATILE:
      genDummyRead(ic);
      break;

    case CRITICAL:
      mc35_genCritical(ic);
      break;

    case ENDCRITICAL:
      mc35_genEndCritical(ic);
      break;

    default:
      fprintf(stderr, "UNHANDLED iCode: ");
      piCode(ic, stderr);
      ic = ic;
      break;
    }
  }

  /* now we are ready to call the
     peep hole optimizer */
  if (!options.nopeep)
  {
    peepHole(&genLine.lineHead);
  }
  /* now do the actual printing */
  printLine(genLine.lineHead, codeOutBuf);

#ifdef PCODE_DEBUG
  DFPRINTF((stderr, "printing pBlock\n\n"));
  mc35_printpBlock(stdout, pb);
#endif

  /* destroy the line list */
  destroy_line_list();
}

/* This is not safe, as a AOP_PCODE/PO_IMMEDIATE might be used both as literal
 * (meaning: representing its own address) or not (referencing its contents).
 * This can only be decided based on the operand's type. */
static int
mc35_aop_isLitLike(asmop *aop)
{
  assert(aop);
  if (aop->type == AOP_LIT)
    return TRUE;
  if (aop->type == AOP_IMMD)
    return TRUE;
  // zwr 2.0.0
  if ((aop->type == AOP_PCODE) &&
      ((aop->aopu.pcop->type == PO_LITERAL) ||
       (aop->aopu.pcop->type == PO_IMMEDIATE)))
  // if ((aop->type == AOP_PCODE) && ((aop->aopu.pcop->type == PO_LITERAL)))
  {
    /* this should be treated like a literal/immediate (use MOVLW/ADDLW/SUBLW
       * instead of MOVFW/ADDFW/SUBFW, use mc35_popGetAddr instead of mc35_popGet) */
    return TRUE;
  }
  return FALSE;
}

int mc35_op_isLitLike(operand *op)
{
  assert(op);
  if (mc35_aop_isLitLike(AOP(op)))
    return TRUE;
  if (IS_SYMOP(op) && IS_FUNC(OP_SYM_TYPE(op)))
    return TRUE;

  // zwr 1.1.6
  // if (IS_SYMOP(op) && IS_PTR(OP_SYM_TYPE(op)) && (AOP_TYPE(op) == AOP_PCODE) && (AOP(op)->aopu.pcop->type == PO_IMMEDIATE))
  if (IS_SYMOP(op) && (AOP_TYPE(op) == AOP_PCODE) && (AOP(op)->aopu.pcop->type == PO_IMMEDIATE))
  {
    return TRUE;
  }

  return FALSE;
}
