/*-------------------------------------------------------------------------
  genarith.c - source file for code generation - arithmetic 
  
  Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)
         and -  Jean-Louis VERN.jlvern@writeme.com (1999)
  Bug Fixes  -  Wojciech Stryjewski  wstryj1@tiger.lsu.edu (1999 v2.1.9a)
  PIC port   -  Scott Dattalo scott@dattalo.com (2000)
  
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
  
  Notes:
  000123 mlh  Moved aopLiteral to SDCCglue.c to help the split
      Made everything static
-------------------------------------------------------------------------*/

#if defined(_MSC_VER) && (_MSC_VER < 1300)
#define __FUNCTION__ __FILE__
#endif

#include "common.h"
#include "newalloc.h"
//#include "SDCCglobl.h"
//#include "SDCCpeeph.h"

#include "gen.h"
#include "pcode.h"
#include "ralloc.h"

#define BYTEofLONG(l, b) ((l >> (b << 3)) & 0xff)

const char *mc35_AopType(short type)
{
        switch (type)
        {
        case AOP_LIT:
                return "AOP_LIT";
                break;
        case AOP_REG:
                return "AOP_REG";
                break;
        case AOP_DIR:
                return "AOP_DIR";
                break;
        case AOP_STK:
                return "AOP_STK";
                break;
        case AOP_IMMD:
                return "AOP_IMMD";
                break;
        case AOP_STR:
                return "AOP_STR";
                break;
        case AOP_CRY:
                return "AOP_CRY";
                break;
        case AOP_PCODE:
                return "AOP_PCODE";
                break;
        }

        return "BAD TYPE";
}

const char *mc35_pCodeOpType(pCodeOp *pcop)
{

        if (pcop)
        {

                switch (pcop->type)
                {

                case PO_NONE:
                        return "PO_NONE";
                case PO_W:
                        return "PO_W";
                case PO_STATUS:
                        return "PO_STATUS";
                case PO_FSR:
                        return "PO_FSR";
                case PO_INDF:
                        return "PO_INDF";
                case PO_INTCON:
                        return "PO_INTCON";
                case PO_GPR_REGISTER:
                        return "PO_GPR_REGISTER";
                case PO_GPR_POINTER:
                        return "PO_GPR_POINTER";
                case PO_GPR_BIT:
                        return "PO_GPR_BIT";
                case PO_GPR_TEMP:
                        return "PO_GPR_TEMP";
                case PO_SFR_REGISTER:
                        return "PO_SFR_REGISTER";
                case PO_PCL:
                        return "PO_PCL";
                case PO_PCLATH:
                        return "PO_PCLATH";
                case PO_LITERAL:
                        return "PO_LITERAL";
                case PO_IMMEDIATE:
                        return "PO_IMMEDIATE";
                case PO_DIR:
                        return "PO_DIR";
                case PO_CRY:
                        return "PO_CRY";
                case PO_BIT:
                        return "PO_BIT";
                case PO_STR:
                        return "PO_STR";
                case PO_LABEL:
                        return "PO_LABEL";
                case PO_WILD:
                        return "PO_WILD";
                }
        }

        return "BAD PO_TYPE";
}

/*-----------------------------------------------------------------*/
/* mc35_genPlusIncr :- does addition with increment if possible         */
/*-----------------------------------------------------------------*/
static bool mc35_genPlusIncr(iCode *ic)
{
        unsigned int icount;
        unsigned int size = mc35_getDataSize(IC_RESULT(ic));
        FENTRY;

        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
        DEBUGmc35_pic14_emitcode("; ", "result %s, left %s, right %s",
                                 mc35_AopType(AOP_TYPE(IC_RESULT(ic))),
                                 mc35_AopType(AOP_TYPE(IC_LEFT(ic))),
                                 mc35_AopType(AOP_TYPE(IC_RIGHT(ic))));

        /* will try to generate an increment */
        /* if the right side is not a literal 
        we cannot */
        if (AOP_TYPE(IC_RIGHT(ic)) != AOP_LIT)
                return FALSE;

        DEBUGmc35_pic14_emitcode("; ", "%s  %d", __FUNCTION__, __LINE__);
        /* if the literal value of the right hand side
        is greater than 1 then it is faster to add */
        if ((icount = (unsigned int)ulFromVal(AOP(IC_RIGHT(ic))->aopu.aop_lit)) > 2)
                return FALSE;

        /* if increment 16 bits in register */
        if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))) &&
            (icount == 1))
        {

                int offset = MSB16;

                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), LSB));
                //mc35_pic14_emitcode("incf","%s,f",mc35_aopGet(AOP(IC_RESULT(ic)),LSB,FALSE,FALSE));

                while (--size)
                {
                        mc35_emitSKPNZ;
                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), offset++));
                        //mc35_pic14_emitcode(" incf","%s,f",mc35_aopGet(AOP(IC_RESULT(ic)),offset++,FALSE,FALSE));
                }

                return TRUE;
        }

        DEBUGmc35_pic14_emitcode("; ", "%s  %d", __FUNCTION__, __LINE__);
        /* if left is in accumulator  - probably a bit operation*/
        if (strcmp(mc35_aopGet(AOP(IC_LEFT(ic)), 0, FALSE, FALSE), "a") &&
            (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY))
        {

                mc35_emitpcode(POC_BCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                mc35_pic14_emitcode("bcf", "(%s >> 3), (%s & 7)",
                                    AOP(IC_RESULT(ic))->aopu.aop_dir,
                                    AOP(IC_RESULT(ic))->aopu.aop_dir);
                if (icount)
                        mc35_emitpcode(POC_XORLW, mc35_popGetLit(1));
                //mc35_pic14_emitcode("xorlw","1");
                else
                        mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1));
                //mc35_pic14_emitcode("andlw","1");

                mc35_emitSKPZ;
                mc35_emitpcode(POC_BSF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                mc35_pic14_emitcode("bsf", "(%s >> 3), (%s & 7)",
                                    AOP(IC_RESULT(ic))->aopu.aop_dir,
                                    AOP(IC_RESULT(ic))->aopu.aop_dir);

                return TRUE;
        }

        /* if the sizes are greater than 1 then we cannot */
        if (AOP_SIZE(IC_RESULT(ic)) > 1 ||
            AOP_SIZE(IC_LEFT(ic)) > 1)
                return FALSE;

        /* If we are incrementing the same register by two: */

        if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
        {

                while (icount--)
                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                //mc35_pic14_emitcode("incf","%s,f",mc35_aopGet(AOP(IC_RESULT(ic)),0,FALSE,FALSE));

                return TRUE;
        }

        DEBUGmc35_pic14_emitcode("; ", "couldn't increment ");

        return FALSE;
}

/*-----------------------------------------------------------------*/
/* genAddlit - generates code for addition                         */
/*-----------------------------------------------------------------*/
static void mc35_genAddLit2byte(operand *result, int offr, int lit)
{
        FENTRY;

        switch (lit & 0xff)
        {
        case 0:
                break;
        case 1:
                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), offr));
                break;
        case 0xff:
                mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), offr));
                break;
        default:
                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offr));
        }
}

static void mc35_emitMOVWF(operand *reg, int offset)
{
        FENTRY;
        if (!reg)
                return;

        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(reg), offset));
}

static void mc35_genAddLit(iCode *ic, int lit)
{
        int size, same;
        int lo;

        operand *result;
        operand *left;

        FENTRY;
        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

        left = IC_LEFT(ic);
        result = IC_RESULT(ic);
        same = mc35_sameRegs(AOP(left), AOP(result));
        size = mc35_getDataSize(result);
        if (size > mc35_getDataSize(left))
                size = mc35_getDataSize(left);

        /*
         * Fix accessing libsdcc/<*>/idata.c:_cinit in __code space.
         */
        if (AOP_PCODE == AOP_TYPE(IC_LEFT(ic)))
        {
                int u;
                if (mc35_debug_verbose)
                {
                        printf("%s:%u: CHECK: using address of '%s' instead of contents\n",
                               ic->filename, ic->lineno,
                               mc35_popGetAddr(AOP(IC_LEFT(ic)), 0, lit & 0xff)->name);
                } // if
                for (u = 0; u < size; ++u)
                {
                        mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(IC_LEFT(ic)), u, lit));
                        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), u));
                } // for

                if (size < mc35_getDataSize(result))
                {
                        for (u = size; u < mc35_getDataSize(result); ++u)
                        {
                                /* XXX: Might fail for u >= size?!? */
                                mc35_emitpcode(POC_MOVLW, mc35_popGetAddr(AOP(IC_LEFT(ic)), u, lit));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), u));
                        } // for
                }         // if

                goto out;
        } // if

        if (same)
        {

                /* Handle special cases first */
                if (size == 1)
                        mc35_genAddLit2byte(result, 0, lit);

                else if (size == 2)
                {
                        int hi = 0xff & (lit >> 8);
                        lo = lit & 0xff;

                        switch (hi)
                        {
                        case 0:

                                /* lit = 0x00LL */
                                DEBUGmc35_pic14_emitcode("; hi = 0", "%s  %d", __FUNCTION__, __LINE__);
                                switch (lo)
                                {
                                case 0:
                                        break;
                                case 1:
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
                                        mc35_emitSKPNZ;
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                case 0xff:
                                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));

                                        break;
                                default:
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), 0));
                                        mc35_emitSKPNC;
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                }
                                break;

                        case 1:
                                /* lit = 0x01LL */
                                DEBUGmc35_pic14_emitcode("; hi = 1", "%s  %d", __FUNCTION__, __LINE__);
                                switch (lo)
                                {
                                case 0: /* 0x0100 */
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                case 1: /* 0x0101  */
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), 0));
                                        mc35_emitSKPNZ;
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                case 0xff: /* 0x01ff */
                                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                // zwr 2.0.0
                                        break;  
                                default:
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), 0));
                                        mc35_emitSKPNC;
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                }
                                break;

                        case 0xff:
                                DEBUGmc35_pic14_emitcode("; hi = ff", "%s  %d", __FUNCTION__, __LINE__);
                                /* lit = 0xffLL */
                                switch (lo)
                                {
                                case 0: /* 0xff00 */
                                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                case 1: /*0xff01 */
                                        mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                default:
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), 0));
                                        mc35_emitSKPC;
                                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                }

                                break;

                        default:
                                DEBUGmc35_pic14_emitcode("; hi is generic", "%d   %s  %d", hi, __FUNCTION__, __LINE__);

                                /* lit = 0xHHLL */
                                switch (lo)
                                {
                                case 0: /* 0xHH00 */
                                        mc35_genAddLit2byte(result, MSB16, hi);
                                        break;
                                case 1: /* 0xHH01 */
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit((hi + 1) & 0xff));
                                        mc35_emitpcode(POC_INCFSZ, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(hi));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                default: /* 0xHHLL */
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), 0));
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit(hi));
                                        mc35_emitSKPNC;
                                        mc35_emitpcode(POC_MOVLW, mc35_popGetLit((hi + 1) & 0xff));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), MSB16));
                                        break;
                                }
                                break;
                        }
                }
                else
                {
                        int carry_info = 0;
                        int offset = 0;
                        /* size > 2 */
                        DEBUGmc35_pic14_emitcode(";  add lit to long", "%s  %d", __FUNCTION__, __LINE__);

                        while (size--)
                        {
                                lo = BYTEofLONG(lit, 0);

                                if (carry_info)
                                {
                                        switch (lo)
                                        {
                                        case 0:
                                                switch (carry_info)
                                                {
                                                case 1:
                                                        mc35_emitSKPNZ;
                                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), offset));
                                                        break;
                                                case 2:
                                                        mc35_emitpcode(POC_RLFW, mc35_popGet(AOP(result), offset));
                                                        mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1));
                                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                                        break;
                                                default: /* carry_info = 3  */
                                                        mc35_emitSKPNC;
                                                        mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), offset));
                                                        carry_info = 1;
                                                        break;
                                                }
                                                break;
                                        case 0xff:
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                                if (carry_info == 1)
                                                        mc35_emitSKPZ;
                                                else
                                                        mc35_emitSKPC;
                                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                                break;
                                        default:
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                                if (carry_info == 1)
                                                        mc35_emitSKPNZ;
                                                else
                                                        mc35_emitSKPNC;
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo + 1));
                                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                                carry_info = 2;
                                                break;
                                        }
                                }
                                else
                                {
                                        /* no carry info from previous step */
                                        /* this means this is the first time to add */
                                        switch (lo)
                                        {
                                        case 0:
                                                break;
                                        case 1:
                                                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(result), offset));
                                                carry_info = 1;
                                                break;
                                        default:
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lo));
                                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                                if (lit < 0x100)
                                                        carry_info = 3; /* Were adding only one byte and propogating the carry */
                                                else
                                                        carry_info = 2;
                                                break;
                                        }
                                }
                                offset++;
                                lit >>= 8;
                        }
                }
        }
        else
        {
                int offset = 1;
                DEBUGmc35_pic14_emitcode(";  left and result aren't same", "%s  %d", __FUNCTION__, __LINE__);

                if (size == 1)
                {

                        /* left addend is in a register */
                        switch (lit & 0xff)
                        {
                        case 0:
                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), 0));
                                mc35_emitMOVWF(result, 0);
                                break;
                        case 1:
                                mc35_emitpcode(POC_INCFW, mc35_popGet(AOP(left), 0));
                                mc35_emitMOVWF(result, 0);
                                break;
                        case 0xff:
                                mc35_emitpcode(POC_DECFW, mc35_popGet(AOP(left), 0));
                                // zwr 1.1.8
                                mc35_emitMOVWF(left, 0);
                                
                                mc35_emitMOVWF(result, 0);
                                break;
                        default:
                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                mc35_emitpcode(POC_ADDFW, mc35_popGet(AOP(left), 0));
                                mc35_emitMOVWF(result, 0);
                        }
                }
                else
                {
                        int clear_carry = 0;

                        /* left is not the accumulator */
                        if (lit & 0xff)
                        {
                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                mc35_emitpcode(POC_ADDFW, mc35_popGet(AOP(left), 0));
                        }
                        else
                        {
                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), 0));
                                /* We don't know the state of the carry bit at this point */
                                clear_carry = 1;
                        }
                        mc35_emitMOVWF(result, 0);
                        while (--size)
                        {

                                lit >>= 8;
                                if (lit & 0xff)
                                {
                                        if (clear_carry)
                                        {
                                                /* The ls byte of the lit must've been zero - that 
                                                means we don't have to deal with carry */

                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                                mc35_emitpcode(POC_ADDFW, mc35_popGet(AOP(left), offset));
                                                // zwr 2.0.0
                                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset));
                                                // mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(left), offset));

                                                clear_carry = 0;
                                        }
                                        else
                                        {
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                                mc35_emitMOVWF(result, offset);
                                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
                                                mc35_emitSKPNC;
                                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(left), offset));
                                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                        }
                                }
                                else
                                {
                                        mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
                                        mc35_emitpcode(POC_RLF, mc35_popGet(AOP(result), offset));
                                        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(left), offset));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(result), offset));
                                }
                                offset++;
                        }
                }
        }

out:
        size = mc35_getDataSize(result);
        if (size > mc35_getDataSize(left))
                size = mc35_getDataSize(left);
        mc35_addSign(result, size, 0);
}

/*-----------------------------------------------------------------*/
/* mc35_genPlus - generates code for addition                           */
/*-----------------------------------------------------------------*/
void mc35_genPlus(iCode *ic)
{
        int size, offset = 0;

        /* special cases :- */
        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
        FENTRY;

        mc35_aopOp(IC_LEFT(ic), ic, FALSE);
        mc35_aopOp(IC_RIGHT(ic), ic, FALSE);
        mc35_aopOp(IC_RESULT(ic), ic, TRUE);

        DEBUGmc35_pic14_AopType(__LINE__, IC_LEFT(ic), IC_RIGHT(ic), IC_RESULT(ic));

        /* if literal, literal on the right or
        if left requires ACC or right is already
        in ACC */

        if (AOP_TYPE(IC_LEFT(ic)) == AOP_LIT)
        {
                operand *t = IC_RIGHT(ic);
                IC_RIGHT(ic) = IC_LEFT(ic);
                IC_LEFT(ic) = t;
        }

        /* if left in bit space & right literal */
        if (AOP_TYPE(IC_LEFT(ic)) == AOP_CRY &&
            AOP_TYPE(IC_RIGHT(ic)) == AOP_LIT)
        {
                /* if result in bit space */
                if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY)
                {
                        if (ulFromVal(AOP(IC_RIGHT(ic))->aopu.aop_lit) != 0L)
                        {
                                mc35_emitpcode(POC_MOVLW, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                                if (!mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
                                        mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(IC_LEFT(ic)), 0));
                                mc35_emitpcode(POC_XORWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                        }
                }
                else
                {
                        size = mc35_getDataSize(IC_RESULT(ic));
                        while (size--)
                        {
                                MOVA(mc35_aopGet(AOP(IC_RIGHT(ic)), offset, FALSE, FALSE));
                                mc35_pic14_emitcode("addc", "a,#00  ;%d", __LINE__);
                                mc35_aopPut(AOP(IC_RESULT(ic)), "a", offset++);
                        }
                }
                goto release;
        }

        /* if I can do an increment instead
        of add then GOOD for ME */
        if (mc35_genPlusIncr(ic) == TRUE)
                goto release;

        size = mc35_getDataSize(IC_RESULT(ic));

        if (AOP(IC_RIGHT(ic))->type == AOP_LIT)
        {
                /* Add a literal to something else */
                unsigned lit = (unsigned)ulFromVal(AOP(IC_RIGHT(ic))->aopu.aop_lit);
                DEBUGmc35_pic14_emitcode(";", "adding lit to something. size %d", size);

                mc35_genAddLit(ic, lit);
                goto release;
        }
        else if (AOP_TYPE(IC_RIGHT(ic)) == AOP_CRY)
        {

                mc35_pic14_emitcode(";bitadd", "right is bit: %s", mc35_aopGet(AOP(IC_RIGHT(ic)), 0, FALSE, FALSE));
                mc35_pic14_emitcode(";bitadd", "left is bit: %s", mc35_aopGet(AOP(IC_LEFT(ic)), 0, FALSE, FALSE));
                mc35_pic14_emitcode(";bitadd", "result is bit: %s", mc35_aopGet(AOP(IC_RESULT(ic)), 0, FALSE, FALSE));

                /* here we are adding a bit to a char or int */
                if (size == 1)
                {
                        if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
                        {
                                mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(IC_RIGHT(ic)), 0));
                                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                        }
                        else
                        {

                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_LEFT(ic)), 0));
                                mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(IC_RIGHT(ic)), 0));
                                mc35_emitpcode(POC_INCFW, mc35_popGet(AOP(IC_LEFT(ic)), 0));

                                if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY)
                                {
                                        mc35_emitpcode(POC_ANDLW, mc35_popGetLit(1));
                                        mc35_emitpcode(POC_BCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                                        mc35_emitSKPZ;
                                        mc35_emitpcode(POC_BSF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                                }
                                else
                                {
                                        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                                }
                        }
                }
                else
                {
                        int offset = 1;
                        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
                        if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
                        {
                                mc35_emitCLRZ;
                                mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(IC_RIGHT(ic)), 0));
                                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                        }
                        else
                        {

                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_LEFT(ic)), 0));
                                mc35_emitpcode(POC_BTFSC, mc35_popGet(AOP(IC_RIGHT(ic)), 0));
                                mc35_emitpcode(POC_INCFW, mc35_popGet(AOP(IC_LEFT(ic)), 0));
                                mc35_emitMOVWF(IC_RIGHT(ic), 0);
                        }

                        while (--size)
                        {
                                mc35_emitSKPZ;
                                mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)), offset++));
                        }
                }
        }
        else
        {
                DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);

                /* Add the first bytes */

                if (strcmp(mc35_aopGet(AOP(IC_LEFT(ic)), 0, FALSE, FALSE), "a") == 0)
                {
                        mc35_emitpcode(POC_ADDFW, mc35_popGet(AOP(IC_RIGHT(ic)), 0));
                        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                }
                else
                {

                        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_RIGHT(ic)), 0));

                        if (mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(IC_LEFT(ic)), 0));
                        else
                        {
                                PIC_OPCODE poc = POC_ADDFW;

                                if (mc35_op_isLitLike(IC_LEFT(ic)))
                                        poc = POC_ADDLW;
                                mc35_emitpcode(poc, mc35_popGetAddr(AOP(IC_LEFT(ic)), 0, 0));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), 0));
                        }
                }

                size = min(AOP_SIZE(IC_RESULT(ic)), AOP_SIZE(IC_RIGHT(ic))) - 1;
                offset = 1;

                if (size)
                {
                        if (mc35_sameRegs(AOP(IC_RIGHT(ic)), AOP(IC_RESULT(ic))))
                        {
                                if (mc35_op_isLitLike(IC_LEFT(ic)))
                                {
                                        while (size--)
                                        {
                                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_RIGHT(ic)), offset));
                                                mc35_emitSKPNC;
                                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(IC_RIGHT(ic)), offset));
                                                mc35_emitpcode(POC_ADDLW, mc35_popGetAddr(AOP(IC_LEFT(ic)), offset, 0));
                                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                                                offset++;
                                        }
                                }
                                else
                                {
                                        while (size--)
                                        {
                                                mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_LEFT(ic)), offset));
                                                mc35_emitSKPNC;
                                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(IC_LEFT(ic)), offset));
                                                mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                                                offset++;
                                        }
                                }
                        }
                        else
                        {
                                PIC_OPCODE poc = POC_MOVFW;
                                if (mc35_op_isLitLike(IC_LEFT(ic)))
                                        poc = POC_MOVLW;
                                while (size--)
                                {
                                        if (!mc35_sameRegs(AOP(IC_LEFT(ic)), AOP(IC_RESULT(ic))))
                                        {
                                                mc35_emitpcode(poc, mc35_popGetAddr(AOP(IC_LEFT(ic)), offset, 0));
                                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                                        }
                                        mc35_emitpcode(POC_MOVFW, mc35_popGet(AOP(IC_RIGHT(ic)), offset));
                                        mc35_emitSKPNC;
                                        mc35_emitpcode(POC_INCFSZW, mc35_popGet(AOP(IC_RIGHT(ic)), offset));
                                        mc35_emitpcode(POC_ADDWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                                        offset++;
                                }
                        }
                }
        }

        if (AOP_SIZE(IC_RESULT(ic)) > AOP_SIZE(IC_RIGHT(ic)))
        {
                int sign = !(SPEC_USIGN(getSpec(operandType(IC_LEFT(ic)))) |
                             SPEC_USIGN(getSpec(operandType(IC_RIGHT(ic)))));

                /* Need to extend result to higher bytes */
                size = AOP_SIZE(IC_RESULT(ic)) - AOP_SIZE(IC_RIGHT(ic)) - 1;

                /* First grab the carry from the lower bytes */
                if (AOP_SIZE(IC_LEFT(ic)) > AOP_SIZE(IC_RIGHT(ic)))
                {
                        int leftsize = AOP_SIZE(IC_LEFT(ic)) - AOP_SIZE(IC_RIGHT(ic));
                        PIC_OPCODE poc = POC_MOVFW;
                        if (mc35_op_isLitLike(IC_LEFT(ic)))
                                poc = POC_MOVLW;
                        while (leftsize-- > 0)
                        {
                                mc35_emitpcode(poc, mc35_popGetAddr(AOP(IC_LEFT(ic)), offset, 0));
                                mc35_emitSKPNC;
                                mc35_emitpcode(POC_ADDLW, mc35_popGetLit(0x01));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                                //mc35_emitSKPNC;
                                //mc35_emitpcode(POC_INCF, mc35_popGet(AOP(IC_RESULT(ic)),offset)); /* INCF does not update Carry! */
                                offset++;
                                if (size)
                                        size--;
                                else
                                        break;
                        }
                }
                else
                {
                        mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                        mc35_emitpcode(POC_RLF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                }

                if (sign && offset > 0 && offset < AOP_SIZE(IC_RESULT(ic)))
                {
                        /* Now this is really horrid. Gotta check the sign of the addends and propogate
                        * to the result */

                        mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(IC_LEFT(ic)), offset - 1, FALSE, FALSE), 7, 0));
                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                        mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(IC_RIGHT(ic)), offset - 1, FALSE, FALSE), 7, 0));
                        mc35_emitpcode(POC_DECF, mc35_popGet(AOP(IC_RESULT(ic)), offset));

                        /* if chars or ints or being signed extended to longs: */
                        if (size)
                        {
                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
                                mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(IC_RESULT(ic)), offset, FALSE, FALSE), 7, 0));
                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
                        }
                }

                offset++;
                while (size--)
                {

                        if (sign)
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(IC_RESULT(ic)), offset));
                        else
                                mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(IC_RESULT(ic)), offset));

                        offset++;
                }
        }

        //adjustArithmeticResult(ic);

release:
        mc35_freeAsmop(IC_LEFT(ic), NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
        mc35_freeAsmop(IC_RIGHT(ic), NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
        mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
}

/*-----------------------------------------------------------------*/
/* mc35_addSign - propogate sign bit to higher bytes                    */
/*-----------------------------------------------------------------*/
void mc35_addSign(operand *result, int offset, int sign)
{
        int size = (mc35_getDataSize(result) - offset);
        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
        FENTRY;

        if (size > 0)
        {
                if (sign && offset)
                {

                        if (size == 1)
                        {
                                mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset));
                                mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), offset - 1, FALSE, FALSE), 7, 0));
                                mc35_emitpcode(POC_DECF, mc35_popGet(AOP(result), offset));
                        }
                        else
                        {

                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0));
                                mc35_emitpcode(POC_BTFSC, mc35_newpCodeOpBit(mc35_aopGet(AOP(result), offset - 1, FALSE, FALSE), 7, 0));
                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(0xff));
                                while (size--)
                                        mc35_emitpcode(POC_MOVWF, mc35_popGet(AOP(result), offset + size));
                        }
                }
                else
                        while (size--)
                                mc35_emitpcode(POC_CLRF, mc35_popGet(AOP(result), offset++));
        }
}

/*-----------------------------------------------------------------*/
/* mc35_genMinus - generates code for subtraction                       */
/*-----------------------------------------------------------------*/
void mc35_genMinus(iCode *ic)
{
        int size, offset = 0, same = 0;
        unsigned long lit = 0L;
        int isLit;
        symbol *lbl_comm, *lbl_next;
        asmop *left, *right, *result;

        FENTRY;
        DEBUGmc35_pic14_emitcode("; ***", "%s  %d", __FUNCTION__, __LINE__);
        mc35_aopOp(IC_LEFT(ic), ic, FALSE);
        mc35_aopOp(IC_RIGHT(ic), ic, FALSE);
        mc35_aopOp(IC_RESULT(ic), ic, TRUE);

        if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY &&
            AOP_TYPE(IC_RIGHT(ic)) == AOP_LIT)
        {
                operand *t = IC_RIGHT(ic);
                IC_RIGHT(ic) = IC_LEFT(ic);
                IC_LEFT(ic) = t;
        }

        DEBUGmc35_pic14_emitcode("; ", "result %s, left %s, right %s",
                                 mc35_AopType(AOP_TYPE(IC_RESULT(ic))),
                                 mc35_AopType(AOP_TYPE(IC_LEFT(ic))),
                                 mc35_AopType(AOP_TYPE(IC_RIGHT(ic))));

        left = AOP(IC_LEFT(ic));
        right = AOP(IC_RIGHT(ic));
        result = AOP(IC_RESULT(ic));

        size = mc35_getDataSize(IC_RESULT(ic));
        same = mc35_sameRegs(right, result);

        if ((AOP_TYPE(IC_LEFT(ic)) != AOP_LIT) && (mc35_getDataSize(IC_LEFT(ic)) < size))
        {
                fprintf(stderr, "%s:%d(%s):WARNING: left operand too short for result\n",
                        ic->filename, ic->lineno, __FUNCTION__);
        } // if
        if ((AOP_TYPE(IC_RIGHT(ic)) != AOP_LIT) && (mc35_getDataSize(IC_RIGHT(ic)) < size))
        {
                fprintf(stderr, "%s:%d(%s):WARNING: right operand too short for result\n",
                        ic->filename, ic->lineno, __FUNCTION__);
        } // if

        if (AOP_TYPE(IC_RIGHT(ic)) == AOP_LIT)
        {
                /* Add a literal to something else */

                lit = ulFromVal(right->aopu.aop_lit);
                lit = -(long)lit;

                mc35_genAddLit(ic, lit);
        }
        else if (AOP_TYPE(IC_RIGHT(ic)) == AOP_CRY)
        {
                // bit subtraction

                mc35_pic14_emitcode(";bitsub", "right is bit: %s", mc35_aopGet(right, 0, FALSE, FALSE));
                mc35_pic14_emitcode(";bitsub", "left is bit: %s", mc35_aopGet(left, 0, FALSE, FALSE));
                mc35_pic14_emitcode(";bitsub", "result is bit: %s", mc35_aopGet(result, 0, FALSE, FALSE));

                /* here we are subtracting a bit from a char or int */
                if (size == 1)
                {
                        if (mc35_sameRegs(left, result))
                        {

                                mc35_emitpcode(POC_BTFSC, mc35_popGet(right, 0));
                                mc35_emitpcode(POC_DECF, mc35_popGet(result, 0));
                        }
                        else
                        {

                                if ((AOP_TYPE(IC_LEFT(ic)) == AOP_IMMD) ||
                                    (AOP_TYPE(IC_LEFT(ic)) == AOP_LIT))
                                {
                                        /*
                                         * result = literal - bit
                                         *
                                         * XXX: probably fails for AOP_IMMDs!
                                         */

                                        lit = ulFromVal(left->aopu.aop_lit);

                                        if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY)
                                        {
                                                if (mc35_sameRegs(right, result))
                                                {
                                                        if (lit & 1)
                                                        {
                                                                mc35_emitpcode(POC_MOVLW, mc35_popGet(right, 0));
                                                                mc35_emitpcode(POC_XORWF, mc35_popGet(result, 0));
                                                        }
                                                }
                                                else
                                                {
                                                        mc35_emitpcode(POC_BCF, mc35_popGet(result, 0));
                                                        if (lit & 1)
                                                                mc35_emitpcode(POC_BTFSS, mc35_popGet(right, 0));
                                                        else
                                                                mc35_emitpcode(POC_BTFSC, mc35_popGet(right, 0));
                                                        mc35_emitpcode(POC_BSF, mc35_popGet(result, 0));
                                                }
                                                goto release;
                                        }
                                        else
                                        {
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit(lit & 0xff));
                                                mc35_emitpcode(POC_BTFSC, mc35_popGet(right, 0));
                                                mc35_emitpcode(POC_MOVLW, mc35_popGetLit((lit - 1) & 0xff));
                                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, 0));
                                        }
                                }
                                else
                                {
                                        // result = register - bit
                                        // XXX: Fails for lit-like left operands
                                        mc35_emitpcode(POC_MOVFW, mc35_popGet(left, 0));
                                        mc35_emitpcode(POC_BTFSC, mc35_popGet(right, 0));
                                        mc35_emitpcode(POC_DECFW, mc35_popGet(left, 0));
                                        mc35_emitpcode(POC_MOVWF, mc35_popGet(result, 0));
                                }
                        }
                }
                else
                {
                        fprintf(stderr, "WARNING: subtracting bit from multi-byte operands is incomplete.\n");
                        //exit(EXIT_FAILURE);
                } // if
        }
        else
        {
                /*
                 * RIGHT is not a literal and not a bit operand,
                 * LEFT is unknown (register, literal, bit, ...)
                 */
                lit = 0;
                isLit = 0;

                if (AOP_TYPE(IC_LEFT(ic)) == AOP_LIT)
                {
                        lit = ulFromVal(left->aopu.aop_lit);
                        isLit = 1;
                        DEBUGmc35_pic14_emitcode("; left is lit", "line %d result %s, left %s, right %s", __LINE__,
                                                 mc35_AopType(AOP_TYPE(IC_RESULT(ic))),
                                                 mc35_AopType(AOP_TYPE(IC_LEFT(ic))),
                                                 mc35_AopType(AOP_TYPE(IC_RIGHT(ic))));
                } // if

                /*
                 * First byte, no carry-in.
                 * Any optimizations that are longer than 2 instructions are
                 * useless.
                 */
                if (same && isLit && ((lit & 0xff) == 0xff))
                {
                        // right === res = 0xFF - right = ~right
                        mc35_emitpcode(POC_COMF, mc35_popGet(right, 0));
                        if (size > 1)
                        {
                                // setup CARRY/#BORROW
                                mc35_emitSETC;
                        } // if
                }
                else if ((size == 1) && isLit && ((lit & 0xff) == 0xff))
                {
                        // res = 0xFF - right = ~right
                        mc35_emitpcode(POC_COMFW, mc35_popGet(right, 0));
                        mc35_emitpcode(POC_MOVWF, mc35_popGet(result, 0));
                        // CARRY/#BORROW is not setup correctly
                }
                else if ((size == 1) && same && isLit && ((lit & 0xff) == 0))
                {
                        // right === res = 0 - right = ~right + 1
                        mc35_emitpcode(POC_COMF, mc35_popGet(right, 0));
                        mc35_emitpcode(POC_INCF, mc35_popGet(right, 0));
                        // CARRY/#BORROW is not setup correctly
                }
                else
                {
                        // general case, should always work
                        mc35_mov2w(right, 0);
                        if (mc35_sameRegs(left, result))
                        {
                                // result === left = left - right (in place)
                                mc35_emitpcode(POC_SUBWF, mc35_popGet(result, 0));
                        }
                        else
                        {
                                // works always: result = left - right
                                mc35_emitpcode(mc35_op_isLitLike(IC_LEFT(ic))
                                                   ? POC_SUBLW
                                                   : POC_SUBFW,
                                               mc35_popGetAddr(left, 0, 0));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, 0));
                        } // if
                }         // if

                /*
                 * Now for the remaining bytes with carry-in (and carry-out).
                 */
                offset = 0;
                while (--size)
                {
                        lit >>= 8;
                        offset++;

                        /*
                         * The following code generation templates are ordered
                         * according to increasing length; the first template
                         * that matches will thus be the shortest and produce
                         * the best code possible with thees templates.
                         */

                        if (mc35_sameRegs(left, right))
                        {
                                /*
                             * This case should not occur; however, the
                             * template works if LEFT, RIGHT, and RESULT are
                             * register operands and LEFT and RIGHT are the
                             * same register(s) and at least as long as the
                             * result.
                             *
                             *   CLRF   result
                             *
                             * 1 cycle
                             */
                                mc35_emitpcode(POC_CLRF, mc35_popGet(result, offset));
                        }
                        else if (mc35_sameRegs(left, result))
                        {
                                /*
                             * This template works if LEFT, RIGHT, and
                             * RESULT are register operands and LEFT and
                             * RESULT are the same register(s).
                             *
                             *   MOVF   right, W    ; W := right
                             *   BTFSS  STATUS, C
                             *   INCFSZ right, W    ; W := right + BORROW
                             *   SUBWF  result, F   ; res === left := left - (right + BORROW)
                             *
                             * The SUBWF *must* be skipped if we have a
                             * BORROW bit and right == 0xFF in order to
                             * keep the BORROW bit intact!
                             *
                             * 4 cycles
                             */
                                mc35_mov2w(right, offset);
                                mc35_emitSKPC;
                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(right, offset));
                                mc35_emitpcode(POC_SUBWF, mc35_popGet(result, offset));
                        }
                        else if ((size == 1) && isLit && ((lit & 0xff) == 0xff))
                        {
                                /*
                             * This template works for the last byte (MSB) of
                             * the subtraction and ignores correct propagation
                             * of the outgoing BORROW bit. RIGHT and RESULT
                             * must be register operands, LEFT must be the
                             * literal 0xFF.
                             *
                             * (The case LEFT === RESULT is optimized above.)
                             *
                             * 0xFF - right - BORROW = ~right - BORROW
                             *
                             *   COMF   right, W    ; W := 0xff - right
                             *   BTFSS  STATUS, C
                             *   ADDLW  0xFF        ; W := 0xff - right - BORROW
                             *   MOVWF  result
                             *
                             * 4 cycles
                             */
                                mc35_emitpcode(POC_COMFW, mc35_popGet(right, offset));
                                mc35_emitSKPC;
                                mc35_emitpcode(POC_ADDLW, mc35_popGetLit(0xff));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, offset));
                        }
                        else if (size == 1)
                        {
                                /*
                             * This template works for the last byte (MSB) of
                             * the subtraction and ignores correct propagation
                             * of the outgoing BORROW bit. RIGHT and RESULT
                             * must be register operands, LEFT can be a
                             * register or a literal operand.
                             *
                             * (The case LEFT === RESULT is optimized above.)
                             *
                             *   MOVF   right, W    ; W := right
                             *   BTFSS  STATUS, C
                             *   INCF   right, W    ; W := right + BORROW
                             *   SUBxW  left, W     ; W := left - right - BORROW
                             *   MOVWF  result
                             *
                             * 5 cycles
                             */
                                mc35_mov2w(right, offset);
                                mc35_emitSKPC;
                                mc35_emitpcode(POC_INCFW, mc35_popGet(right, offset));
                                mc35_emitpcode(mc35_op_isLitLike(IC_LEFT(ic))
                                                   ? POC_SUBLW
                                                   : POC_SUBFW,
                                               mc35_popGetAddr(left, offset, 0));
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, offset));
                        }
                        else if (IS_ITEMP(IC_RESULT(ic)) && !mc35_sameRegs(right, result))
                        {
                                /*
                             * This code template works if RIGHT and RESULT
                             * are different register operands and RESULT
                             * is not volatile/an SFR (written twice).
                             *
                             * #########################################
                             * Since we cannot determine that for sure,
                             * we approximate via IS_ITEMP() for now.
                             * #########################################
                             *
                             *   MOVxW  left, W     ; copy left to result
                             *   MOVWF  result
                             *   MOVF   right, W    ; W := right
                             *   BTFSS  STATUS, C
                             *   INCFSZ right, W    ; W := right + BORROW
                             *   SUBWF  result, F   ; res === left := left - (right + BORROW)
                             *
                             * 6 cycles, but fails for SFR RESULT operands
                             */
                                mc35_mov2w(left, offset);
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, offset));
                                mc35_mov2w(right, offset);
                                mc35_emitSKPC;
                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(right, offset));
                                mc35_emitpcode(POC_SUBWF, mc35_popGet(result, offset));
                        }
                        else if (!optimize.codeSize && isLit && ((lit & 0xff) != 0))
                        {
                                /*
                             * This template works if RIGHT and RESULT are
                             * register operands and LEFT is a literal
                             * operand != 0.
                             *
                             *   MOVxW  right, W
                             *   BTFSC  STATUS, C
                             *   GOTO   next
                             *   SUBLW  left-1
                             *   GOTO   common
                             * next:
                             *   SUBLW  left
                             * common:
                             *   MOVWF  result
                             *
                             * 6 cycles, 7 iff BORROW
                             * (9 instructions)
                             */
                                lbl_comm = newiTempLabel(NULL);
                                lbl_next = newiTempLabel(NULL);

                                mc35_mov2w(right, offset);
                                mc35_emitSKPNC;
                                mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl_next->key));
                                mc35_emitpcode(POC_SUBLW, mc35_popGetLit((lit - 1) & 0xff));
                                mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl_comm->key));
                                mc35_emitpLabel(lbl_next->key);
                                mc35_emitpcode(POC_SUBLW, mc35_popGetLit(lit & 0xff));
                                mc35_emitpLabel(lbl_comm->key);
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, offset));
                        }
                        else
                        {
                                /*
                             * This code template works if RIGHT and RESULT
                             * are register operands.
                             *
                             *   MOVF   right, W    ; W := right
                             *   BTFSS  STATUS, C
                             *   INCFSZ right, W    ; W := right + BORROW
                             *   GOTO   common
                             *   MOVxW  left        ; if we subtract 0x100 = 0xFF + 1, ...
                             *   GOTO   next        ; res := left, but keep BORROW intact
                             * common:
                             *   SUBxW  left, W     ; W := left - (right + BORROW)
                             * next:
                             *   MOVW   result      ; res := left - (right + BORROW)
                             *
                             * 7 cycles, 8 iff BORROW and (right == 0xFF)
                             * (8 instructions)
                             *
                             *
                             *
                             * Alternative approach using -x = ~x + 1 ==> ~x = -x - 1 = -(x + 1)
                             *
                             *   COMFW  right, W    ; W := -right - (assumed BORROW)
                             *   BTFSC  STATUS, C   ; SKIP if we have a BORROW
                             *   ADDLW  1           ; W := -right (no BORROW)
                             *   BTFSC  STATUS, C   ; (***)
                             *   MOVLW  left        ; (***)
                             *   BTFSS  STATUS, C   ; (***)
                             *   ADDFW  left, W     ; W := left - right - BORROW (if any)
                             *   MOVWF  result      ; result := left - right - BORROW (if any)
                             *
                             * 8 cycles
                             *
                             * Case A: C=0 (BORROW)
                             * r=0x00, W=0xFF, W=left+0xFF, C iff left>0x00
                             * r=0x01, W=0xFE, W=left+0xFE, C iff left>0x01
                             * r=0xFE, W=0x01, W=left+0x01, C iff left>0xFE
                             * r=0xFF, W=0x00, W=left+0x00, C iff left>0xFF
                             *
                             * Case B: C=1 (no BORROW)
                             * r=0x00, W=0xFF, W=0x00/C=1, W=left+0x00, C iff left>=0x100 (***)
                             * r=0x01, W=0xFE, W=0xFF/C=0, W=left+0xFF, C iff left>=0x01
                             * r=0xFE, W=0x01, W=0x02/C=0, W=left+0x02, C iff left>=0xFE
                             * r=0xFF, W=0x00, W=0x01/C=0, W=left+0x01, C iff left>=0xFF
                             */
                                lbl_comm = newiTempLabel(NULL);
                                lbl_next = newiTempLabel(NULL);

                                mc35_mov2w(right, offset);
                                mc35_emitSKPC;
                                mc35_emitpcode(POC_INCFSZW, mc35_popGet(right, offset));
                                mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl_comm->key));
                                mc35_mov2w(left, offset);
                                mc35_emitpcode(POC_GOTO, mc35_popGetLabel(lbl_next->key));
                                mc35_emitpLabel(lbl_comm->key);
                                mc35_emitpcode(mc35_op_isLitLike(IC_LEFT(ic))
                                                   ? POC_SUBLW
                                                   : POC_SUBFW,
                                               mc35_popGetAddr(left, offset, 0));
                                mc35_emitpLabel(lbl_next->key);
                                mc35_emitpcode(POC_MOVWF, mc35_popGet(result, offset));
                        } // if
                }         // while
        }                 // if

        if (AOP_TYPE(IC_RESULT(ic)) == AOP_CRY)
        {
                fprintf(stderr, "WARNING: AOP_CRY (bit-) results are probably broken. Please report this with source code as a bug.\n");
                mc35_mov2w(result, 0); // load Z flag
                mc35_emitpcode(POC_BCF, mc35_popGet(result, 0));
                mc35_emitSKPZ;
                mc35_emitpcode(POC_BSF, mc35_popGet(result, 0));
        } // if

        //    adjustArithmeticResult(ic);

release:
        mc35_freeAsmop(IC_LEFT(ic), NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
        mc35_freeAsmop(IC_RIGHT(ic), NULL, ic, (RESULTONSTACK(ic) ? FALSE : TRUE));
        mc35_freeAsmop(IC_RESULT(ic), NULL, ic, TRUE);
}
