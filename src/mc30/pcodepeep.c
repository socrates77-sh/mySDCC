/*-------------------------------------------------------------------------

   pcodepeep.c - post code generation
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

#include "pcode.h"
#include "pcodeflow.h"
#include "ralloc.h"

//#define PCODE_DEBUG

#define IS_PCCOMMENT(x) (x && (x->type == PC_COMMENT))

/****************************************************************/
/****************************************************************/
typedef struct DLList
{
  struct DLList *prev;
  struct DLList *next;
  //  void *data;
} DLList;

typedef struct pCodePeepSnippets
{
  DLList dll;
  pCodePeep *peep;
} pCodePeepSnippets;

/****************************************************************/
/*                                                              */
/* mc30_peepSnippets -                                               */
/*                                                              */
/****************************************************************/

static pCodePeepSnippets *mc30_peepSnippets = NULL;

typedef struct pCodeToken
{
  int tt; // token type;
  union {
    char c;  // character
    int n;   // number
    char *s; // string
  } tok;

} pCodeToken;

static pCodeToken mc30_tokArr[50];
static unsigned mc30_tokIdx = 0;

typedef enum {
  PCT_NULL = 0,
  PCT_SPACE = 1,
  PCT_PERCENT,
  PCT_LESSTHAN,
  PCT_GREATERTHAN,
  PCT_COLON,
  PCT_COMMA,
  PCT_COMMENT,
  PCT_STRING,
  PCT_NUMBER

} pCodeTokens;

typedef struct parsedPattern
{
  struct pcPattern *pcp;
  pCodeToken *pct;
} parsedPattern;

#define MAX_PARSEDPATARR 50
static parsedPattern mc30_parsedPatArr[MAX_PARSEDPATARR];

typedef enum {
  PCP_LABEL = 1,
  PCP_NUMBER,
  PCP_STR,
  PCP_WILDVAR,
  PCP_WILDSTR,
  PCP_COMMA,
  PCP_COMMENT
} pCodePatterns;

static char mc30_pcpat_label[] = {PCT_PERCENT, PCT_NUMBER, PCT_COLON, 0};
static char mc30_pcpat_number[] = {PCT_NUMBER, 0};
static char mc30_pcpat_string[] = {PCT_STRING, 0};
static char mc30_pcpat_wildString[] = {PCT_PERCENT, PCT_STRING, 0};
static char mc30_pcpat_wildVar[] = {PCT_PERCENT, PCT_NUMBER, 0};
static char mc30_pcpat_comma[] = {PCT_COMMA, 0};
static char mc30_pcpat_comment[] = {PCT_COMMENT, 0};

typedef struct pcPattern
{
  char pt;      // Pattern type
  char *tokens; // list of tokens that describe the pattern
  void *(*f)(void *, pCodeWildBlock *);
} pcPattern;

static pcPattern mc30_pcpArr[] = {
    {PCP_LABEL, mc30_pcpat_label, NULL},
    {PCP_WILDSTR, mc30_pcpat_wildString, NULL},
    {PCP_STR, mc30_pcpat_string, NULL},
    {PCP_WILDVAR, mc30_pcpat_wildVar, NULL},
    {PCP_COMMA, mc30_pcpat_comma, NULL},
    {PCP_COMMENT, mc30_pcpat_comment, NULL},
    {PCP_NUMBER, mc30_pcpat_number, NULL}};

#define PCPATTERNS (sizeof(mc30_pcpArr) / sizeof(pcPattern))

// Assembly Line Token
typedef enum {
  ALT_LABEL = 1,
  ALT_COMMENT,
  ALT_MNEM0,
  ALT_MNEM0A,
  ALT_MNEM1,
  ALT_MNEM1A,
  ALT_MNEM1B,
  ALT_MNEM2,
  ALT_MNEM2A,
  ALT_MNEM3
} altPatterns;

static char mc30_alt_comment[] = {PCP_COMMENT, 0};
static char mc30_alt_label[] = {PCP_LABEL, 0};
static char mc30_alt_mnem0[] = {PCP_STR, 0};
static char mc30_alt_mnem0a[] = {PCP_WILDVAR, 0};
static char mc30_alt_mnem1[] = {PCP_STR, PCP_STR, 0};
static char mc30_alt_mnem1a[] = {PCP_STR, PCP_WILDVAR, 0};
static char mc30_alt_mnem1b[] = {PCP_STR, PCP_NUMBER, 0};
static char mc30_alt_mnem2[] = {PCP_STR, PCP_STR, PCP_COMMA, PCP_STR, 0};
static char mc30_alt_mnem2a[] = {PCP_STR, PCP_WILDVAR, PCP_COMMA, PCP_STR, 0};
static char mc30_alt_mnem3[] = {PCP_STR, PCP_STR, PCP_COMMA, PCP_NUMBER, 0};

static void *mc30_cvt_altpat_label(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_comment(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem0(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem0a(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem1(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem1a(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem1b(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem2(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem2a(void *pp, pCodeWildBlock *pcwb);
static void *mc30_cvt_altpat_mnem3(void *pp, pCodeWildBlock *pcwb);

static pcPattern mc30_altArr[] = {
    {ALT_LABEL, mc30_alt_label, mc30_cvt_altpat_label},
    {ALT_COMMENT, mc30_alt_comment, mc30_cvt_altpat_comment},
    {ALT_MNEM3, mc30_alt_mnem3, mc30_cvt_altpat_mnem3},
    {ALT_MNEM2A, mc30_alt_mnem2a, mc30_cvt_altpat_mnem2a},
    {ALT_MNEM2, mc30_alt_mnem2, mc30_cvt_altpat_mnem2},
    {ALT_MNEM1B, mc30_alt_mnem1b, mc30_cvt_altpat_mnem1b},
    {ALT_MNEM1A, mc30_alt_mnem1a, mc30_cvt_altpat_mnem1a},
    {ALT_MNEM1, mc30_alt_mnem1, mc30_cvt_altpat_mnem1},
    {ALT_MNEM0A, mc30_alt_mnem0a, mc30_cvt_altpat_mnem0a},
    {ALT_MNEM0, mc30_alt_mnem0, mc30_cvt_altpat_mnem0},

};

#define ALTPATTERNS (sizeof(mc30_altArr) / sizeof(pcPattern))

// forward declarations
static void *mc30_DLL_append(DLList *list, DLList *next);

/*-----------------------------------------------------------------*/
/* mc30_cvt_extract_destination - helper function extracts the register */
/*                           destination from a parsedPattern.     */
/*                                                                 */
/*-----------------------------------------------------------------*/
static int mc30_cvt_extract_destination(parsedPattern *pp)
{

  if (pp->pct[0].tt == PCT_STRING)
  {

    // just check first letter for now

    if (toupper((unsigned char)*pp->pct[0].tok.s) == 'F')
      return 1;
  }
  else if (pp->pct[0].tt == PCT_NUMBER)
  {

    if (pp->pct[0].tok.n)
      return 1;
  }

  return 0;
}

/*-----------------------------------------------------------------*/
/*  pCodeOp *mc30_cvt_extract_status(char *reg, char *bit)              */
/*     if *reg is the "status" register and *bit is one of the     */
/*     status bits, then this function will create a new pCode op  */
/*     containing the status register.                             */
/*-----------------------------------------------------------------*/

static pCodeOp *mc30_cvt_extract_status(char *reg, char *bit)
{
  int len;

  if (STRCASECMP(reg, mc30_pc_status.pcop.name))
    return NULL;

  len = strlen(bit);

  if (len == 1)
  {
    // check C,Z
    if (toupper((unsigned char)*bit) == 'C')
      return PCOP(mc30_popCopyGPR2Bit(PCOP(&mc30_pc_status), PIC_C_BIT));
    if (toupper((unsigned char)*bit) == 'Z')
      return PCOP(mc30_popCopyGPR2Bit(PCOP(&mc30_pc_status), PIC_Z_BIT));
  }

  // Check DC
  if (len == 2 && toupper((unsigned char)bit[0]) == 'D' && toupper((unsigned char)bit[1]) == 'C')
    return PCOP(mc30_popCopyGPR2Bit(PCOP(&mc30_pc_status), PIC_DC_BIT));

  return NULL;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_label - convert assembly line type to a pCode label  */
/* INPUT: pointer to the parsedPattern                             */
/*                                                                 */
/*  pp[0] - label                                                  */
/*                                                                 */
/* label pattern => '%' number ':'                                 */
/* at this point, we wish to extract only the 'number'             */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_label(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;

  DFPRINTF((stderr, "altpat_label with ID = %d\n", p->pct[1].tok.n));
  return mc30_newpCodeLabel(NULL, -p->pct[1].tok.n);
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_comment - convert assembly line type to a comment    */
/* INPUT: pointer to the parsedPattern                             */
/*                                                                 */
/*  pp[0] - comment                                                */
/*                                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_comment(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;

  DFPRINTF((stderr, "altpat_comment  = %s\n", p->pct[0].tok.s));
  return mc30_newpCodeCharP(p->pct[0].tok.s);
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem0  - convert assembly line type to a wild pCode   */
/*                    instruction                                  */
/*                                                                 */
/*  pp[0] - str                                                    */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem0(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;

  pCodeInstruction *pci = NULL;

  DFPRINTF((stderr, "altpat_mnem0 %s\n", p->pct[0].tok.s));

  opcode = mc30_getpCode(p->pct[0].tok.s, 0);

  if (opcode < 0)
  {
    /* look for special command strings like _NOTBITSKIP_ */

    //fprintf(stderr, "Bad mnemonic\n");

    opcode = mc30_getpCodePeepCommand(p->pct[0].tok.s);
    //if(opcode > 0)
    //  fprintf(stderr,"  but valid peep command: %s, key = %d\n",p->pct[0].tok.s,opcode);
    return NULL;
  }

  pci = PCI(mc30_newpCode(opcode, NULL));

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem0a - convert assembly line type to a wild pCode   */
/*                    instruction                                  */
/*                                                                 */
/*  pp[0] - wild var                                               */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem0a(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;

  DFPRINTF((stderr, "altpat_mnem0a wild mnem # %d\n", p[0].pct[1].tok.n));

  /* Save the index of the maximum wildcard mnemonic */
  if (p[0].pct[1].tok.n > pcwb->nwildpCodes)
    pcwb->nwildpCodes = p[0].pct[1].tok.n;

  return mc30_newpCodeWild(p[0].pct[1].tok.n, NULL, NULL);
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem1 - convert assembly line type to a pCode         */
/*                   instruction with 1 operand.                   */
/*                                                                 */
/*  pp[0] - mnem                                                   */
/*  pp[1] - Operand                                                */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem1(void *pp, pCodeWildBlock *pcwb)
{

  parsedPattern *p = pp;
  int opcode;

  pCodeInstruction *pci = NULL;
  pCodeOp *pcosubtype;

  DFPRINTF((stderr, "altpat_mnem1 %s var %s\n", p->pct[0].tok.s, p[1].pct[0].tok.s));

  opcode = mc30_getpCode(p->pct[0].tok.s, 0);
  if (opcode < 0)
  {
    //fprintf(stderr, "Bad mnemonic\n");
    opcode = mc30_getpCodePeepCommand(p->pct[0].tok.s);
    //if(opcode > 0)
    //fprintf(stderr,"  but valid peep command: %s, key = %d\n",p->pct[0].tok.s,opcode);

    return NULL;
  }

  if (mc30_pic14Mnemonics[opcode]->isBitInst)
    pcosubtype = mc30_newpCodeOp(p[1].pct[0].tok.s, PO_BIT);
  else
    pcosubtype = mc30_newpCodeOp(p[1].pct[0].tok.s, PO_GPR_REGISTER);

  pci = PCI(mc30_newpCode(opcode, pcosubtype));

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem1a - convert assembly line type to a pCode        */
/*                    instruction with 1 wild operand.             */
/*                                                                 */
/*  pp[0] - mnem                                                   */
/*  pp[1] - wild var                                               */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem1a(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;

  pCodeInstruction *pci = NULL;
  pCodeOp *pcosubtype;

  DFPRINTF((stderr, "altpat_mnem1a %s var %d\n", p->pct[0].tok.s, p[1].pct[1].tok.n));

  opcode = mc30_getpCode(p->pct[0].tok.s, 0);
  if (opcode < 0)
  {
    int cmd_id = mc30_getpCodePeepCommand(p->pct[0].tok.s);
    pCode *pc = NULL;

    if (cmd_id < 0)
    {
      fprintf(stderr, "Bad mnemonic\n");
      return NULL;
    }

    if (p[0].pct[1].tok.n > pcwb->nwildpCodes)
      pcwb->nwildpCodes = p[0].pct[1].tok.n;

    pc = mc30_newpCodeWild(p[1].pct[1].tok.n, NULL, NULL);

    switch (cmd_id)
    {
    case NOTBITSKIP:
      PCW(pc)->mustNotBeBitSkipInst = 1;
      break;
    case BITSKIP:
      PCW(pc)->mustBeBitSkipInst = 1;
      break;
    case INVERTBITSKIP:
      PCW(pc)->invertBitSkipInst = 1;
    }
    return pc;
  }

  if (mc30_pic14Mnemonics[opcode]->isBitInst)
    pcosubtype = mc30_newpCodeOpBit(NULL, -1, 0);
  else
    pcosubtype = mc30_newpCodeOp(NULL, PO_GPR_REGISTER);

  pci = PCI(mc30_newpCode(opcode,
                     mc30_newpCodeOpWild(p[1].pct[1].tok.n, pcwb, pcosubtype)));

  /* Save the index of the maximum wildcard variable */
  if (p[1].pct[1].tok.n > pcwb->nvars)
    pcwb->nvars = p[1].pct[1].tok.n;

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem1b(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;

  pCodeInstruction *pci = NULL;

  DFPRINTF((stderr, "altpat_mnem1b %s var %d\n", p->pct[0].tok.s, p[1].pct[0].tok.n));

  opcode = mc30_getpCode(p->pct[0].tok.s, 0);
  if (opcode < 0)
  {
    fprintf(stderr, "Bad mnemonic\n");
    return NULL;
  }

  pci = PCI(mc30_newpCode(opcode, mc30_newpCodeOpLit(p[1].pct[0].tok.n)));

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mnem2                                                */
/*                                                                 */
/*  pp[0] - mnem                                                   */
/*  pp[1] - var                                                    */
/*  pp[2] - comma                                                  */
/*  pp[3] - destination                                            */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem2(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;
  int dest;

  pCodeInstruction *pci = NULL;
  pCodeOp *pcosubtype;

  dest = mc30_cvt_extract_destination(&p[3]);

  DFPRINTF((stderr, "altpat_mnem2 %s var %s destination %s(%d)\n",
            p->pct[0].tok.s,
            p[1].pct[0].tok.s,
            p[3].pct[0].tok.s,
            dest));

  opcode = mc30_getpCode(p->pct[0].tok.s, dest);
  if (opcode < 0)
  {
    fprintf(stderr, "Bad mnemonic\n");
    return NULL;
  }

  if (mc30_pic14Mnemonics[opcode]->isBitInst)
  {
    pcosubtype = mc30_cvt_extract_status(p[1].pct[0].tok.s, p[3].pct[0].tok.s);
    if (pcosubtype == NULL)
    {
      fprintf(stderr, "bad operand?\n");
      return NULL;
    }
  }
  else
    pcosubtype = mc30_newpCodeOp(p[1].pct[0].tok.s, PO_GPR_REGISTER);

  pci = PCI(mc30_newpCode(opcode, pcosubtype));

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem2a - convert assembly line type to a pCode        */
/*                    instruction with 1 wild operand and a        */
/*                    destination operand (e.g. w or f)            */
/*                                                                 */
/*  pp[0] - mnem                                                   */
/*  pp[1] - wild var                                               */
/*  pp[2] - comma                                                  */
/*  pp[3] - destination                                            */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem2a(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;
  int dest;

  pCodeInstruction *pci = NULL;
  pCodeOp *pcosubtype;

  if (!pcwb)
  {
    fprintf(stderr, "ERROR %s:%d - can't assemble line\n", __FILE__, __LINE__);
    return NULL;
  }

  dest = mc30_cvt_extract_destination(&p[3]);

  DFPRINTF((stderr, "altpat_mnem2a %s var %d destination %s(%d)\n",
            p->pct[0].tok.s,
            p[1].pct[1].tok.n,
            p[3].pct[0].tok.s,
            dest));

  opcode = mc30_getpCode(p->pct[0].tok.s, dest);
  if (opcode < 0)
  {
    fprintf(stderr, "Bad mnemonic\n");
    return NULL;
  }

  if (mc30_pic14Mnemonics[opcode]->isBitInst)
    pcosubtype = mc30_newpCodeOp(NULL, PO_BIT);
  else
    pcosubtype = mc30_newpCodeOp(NULL, PO_GPR_REGISTER);

  pci = PCI(mc30_newpCode(opcode,
                     mc30_newpCodeOpWild(p[1].pct[1].tok.n, pcwb, pcosubtype)));

  /* Save the index of the maximum wildcard variable */
  if (p[1].pct[1].tok.n > pcwb->nvars)
    pcwb->nvars = p[1].pct[1].tok.n;

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_cvt_altpat_mem3 -  convert assembly line type to a pCode        */
/*                    This rule is for bsf/bcf type instructions   */
/*                                                                 */
/*                                                                 */
/*  pp[0] - mnem                                                   */
/*  pp[1] - register                                               */
/*  pp[2] - comma                                                  */
/*  pp[3] - number                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/
static void *mc30_cvt_altpat_mnem3(void *pp, pCodeWildBlock *pcwb)
{
  parsedPattern *p = pp;
  int opcode;

  pCodeInstruction *pci = NULL;
  pCodeOp *pcosubtype = NULL;

  DFPRINTF((stderr, "altpat_mnem3 %s var %s bit (%d)\n",
            p->pct[0].tok.s,
            p[1].pct[0].tok.s,
            p[3].pct[0].tok.n));

  opcode = mc30_getpCode(p->pct[0].tok.s, 0);
  if (opcode < 0)
  {
    fprintf(stderr, "Bad mnemonic\n");
    return NULL;
  }

  if (mc30_pic14Mnemonics[opcode]->isBitInst)
  {
    //pcosubtype = mc30_cvt_extract_status(p[1].pct[0].tok.s, p[3].pct[0].tok.s);

    //if(pcosubtype == NULL) {
    pcosubtype = mc30_newpCodeOpBit(p[1].pct[0].tok.s, p[3].pct[0].tok.n, 0);
    //}
  }
  else
    pcosubtype = mc30_newpCodeOp(p[1].pct[0].tok.s, PO_GPR_REGISTER);

  if (pcosubtype == NULL)
  {
    fprintf(stderr, "Bad operand\n");
    return NULL;
  }

  pci = PCI(mc30_newpCode(opcode, pcosubtype));

  if (!pci)
    fprintf(stderr, "couldn't find mnemonic\n");

  return pci;
}

/*-----------------------------------------------------------------*/
/* mc30_tokenizeLineNode - Convert a string (of char's) that was parsed */
/*                    by SDCCpeeph.c into a string of tokens.      */
/*                                                                 */
/*                                                                 */
/* The tokenizer is of the classic type. When an item is encounterd*/
/* it is converted into a token. The token is a structure that     */
/* encodes the item's type and it's value (when appropriate).      */
/*                                                                 */
/* Accepted token types:                                           */
/*    SPACE  NUMBER STRING  %  : ,  ;                              */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/

static void mc30_tokenizeLineNode(char *ln)
{
  char *lnstart = ln;
  mc30_tokIdx = 0;              // Starting off at the beginning
  mc30_tokArr[0].tt = PCT_NULL; // and assume invalid character for first token.

  if (!ln || !*ln)
    return;

  while (*ln)
  {

    if (isspace((unsigned char)*ln))
    {
      // add a SPACE token and eat the extra spaces.
      mc30_tokArr[mc30_tokIdx++].tt = PCT_SPACE;
      while (isspace((unsigned char)*ln))
        ln++;
      continue;
    }

    if (isdigit((unsigned char)*ln))
    {

      mc30_tokArr[mc30_tokIdx].tt = PCT_NUMBER;
      mc30_tokArr[mc30_tokIdx++].tok.n = strtol(ln, &ln, 0);

      continue;
    }

    switch (*ln)
    {
    case '%':
      mc30_tokArr[mc30_tokIdx++].tt = PCT_PERCENT;
      break;
    case '<':
      mc30_tokArr[mc30_tokIdx++].tt = PCT_LESSTHAN;
      break;
    case '>':
      mc30_tokArr[mc30_tokIdx++].tt = PCT_GREATERTHAN;
      break;
    case ':':
      mc30_tokArr[mc30_tokIdx++].tt = PCT_COLON;
      break;
    case ';':
      mc30_tokArr[mc30_tokIdx].tok.s = Safe_strdup(ln);
      mc30_tokArr[mc30_tokIdx++].tt = PCT_COMMENT;
      mc30_tokArr[mc30_tokIdx].tt = PCT_NULL;
      return;
    case ',':
      mc30_tokArr[mc30_tokIdx++].tt = PCT_COMMA;
      break;

    default:
      if (isalpha((unsigned char)*ln) || (*ln == '_'))
      {
        char buffer[50];
        int i = 0;

        while ((isalpha((unsigned char)*ln) || isdigit((unsigned char)*ln) || (*ln == '_')) && i < 49)
          buffer[i++] = *ln++;

        ln--;
        buffer[i] = 0;

        mc30_tokArr[mc30_tokIdx].tok.s = Safe_strdup(buffer);
        mc30_tokArr[mc30_tokIdx++].tt = PCT_STRING;
      }
      else
      {
        fprintf(stderr, "Error while parsing peep rules (check peeph.def)\n");
        fprintf(stderr, "Line: %s\n", lnstart);
        fprintf(stderr, "Token: '%c'\n", *ln);
        exit(1);
      }
    }

    /* Advance to next character in input string .
    * Note, if none of the tests passed above, then
    * we effectively ignore the `bad' character.
    * Since the line has already been parsed by SDCCpeeph,
    * chance are that there are no invalid characters... */

    ln++;
  }

  mc30_tokArr[mc30_tokIdx].tt = 0;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static void mc30_dump1Token(pCodeTokens tt)
{

  switch (tt)
  {
  case PCT_SPACE:
    fprintf(stderr, " space ");
    break;
  case PCT_PERCENT:
    fprintf(stderr, " pct %%");
    break;
  case PCT_LESSTHAN:
    fprintf(stderr, " pct <");
    break;
  case PCT_GREATERTHAN:
    fprintf(stderr, " pct >");
    break;
  case PCT_COLON:
    fprintf(stderr, " col :");
    break;
  case PCT_COMMA:
    fprintf(stderr, " comma , ");
    break;
  case PCT_COMMENT:
    fprintf(stderr, " comment ");
    //fprintf(stderr,"%s",mc30_tokArr[i].tok.s);
    break;
  case PCT_STRING:
    fprintf(stderr, " str ");
    //fprintf(stderr,"%s",mc30_tokArr[i].tok.s);
    break;
  case PCT_NUMBER:
    fprintf(stderr, " num ");
    //fprintf(stderr,"%d",mc30_tokArr[i].tok.n);
    break;
  case PCT_NULL:
    fprintf(stderr, " null ");
  }
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static int mc30_pcComparePattern(pCodeToken *pct, char *pat, int max_tokens)
{
  int i = 0;

  if (!pct || !pat || !*pat)
    return 0;

  //DFPRINTF((stderr,"comparing against:\n"));

  while (i < max_tokens)
  {

    if (*pat == 0)
    {
      //DFPRINTF((stderr,"matched\n"));
      return (i + 1);
    }

    //mc30_dump1Token(*pat); DFPRINTF((stderr,"\n"));

    if (pct->tt != *pat)
      return 0;

    pct++;
    pat++;
  }

  return 0;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static int mc30_altComparePattern(char *pct, parsedPattern *pat, int max_tokens)
{
  int i = 0;

  if (!pct || !pat || !*pct)
    return 0;

  while (i < max_tokens)
  {

    if (*pct == 0)
    {
      //DFPRINTF((stderr,"matched\n"));
      return i;
    }

    //mc30_dump1Token(*pat); DFPRINTF((stderr,"\n"));

    if (!pat || !pat->pcp)
      return 0;

    if (pat->pcp->pt != *pct)
      return 0;

    //DFPRINTF((stderr," pct=%d\n",*pct));
    pct++;
    pat++;
    i++;
  }

  return 0;
}
/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

static int mc30_advTokIdx(int *v, int amt)
{

  if ((unsigned)(*v + amt) > mc30_tokIdx)
    return 1;

  *v += amt;
  return 0;
}

/*-----------------------------------------------------------------*/
/* mc30_parseTokens - convert the tokens corresponding to a single line */
/*               of a peep hole assembly into a pCode object.      */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/* This is a simple parser that looks for strings of the type      */
/* allowed in the peep hole definition file. Essentially the format*/
/* is the same as a line of assembly:                              */
/*                                                                 */
/*  label:    mnemonic   op1, op2, op3    ; comment                */
/*                                                                 */
/* Some of these items aren't present. It's the job of the parser  */
/* to determine which are and convert those into the appropriate   */
/* pcode.                                                          */
/*-----------------------------------------------------------------*/

static int mc30_parseTokens(pCodeWildBlock *pcwb, pCode **pcret)
{
  pCode *pc;
  int error = 0;

  if (!mc30_tokIdx)
    return error;

#ifdef PCODE_DEBUG
  {
    unsigned i;
    for (i = 0; i <= mc30_tokIdx; i++)
      mc30_dump1Token(mc30_tokArr[i].tt);
    fputc('\n', stderr);
  }
#endif

  {
    int lparsedPatIdx = 0;
    int lpcpIdx;
    int mc30_ltokIdx = 0;
    int matching = 0;
    int j = 0;
    int k = 0;

    //pCodeOp *pcl   = NULL;       // Storage for a label
    //pCodeOp *pco1  = NULL;       // 1st operand
    //pCodeOp *pco2  = NULL;       // 2nd operand
    //pCode   *pc    = NULL;       // Mnemonic

    typedef enum {
      PS_START,
      PS_HAVE_LABEL,
      PS_HAVE_MNEM,
      PS_HAVE_1OPERAND,
      PS_HAVE_COMMA,
      PS_HAVE_2OPERANDS
    } ParseStates;

    ParseStates state = PS_START;

    do
    {

      lpcpIdx = 0;
      matching = 0;

      if (((mc30_tokArr[mc30_ltokIdx].tt == PCT_SPACE)) && (mc30_advTokIdx(&mc30_ltokIdx, 1))) // eat space
        break;

      do
      {
        j = mc30_pcComparePattern(&mc30_tokArr[mc30_ltokIdx], mc30_pcpArr[lpcpIdx].tokens, mc30_tokIdx + 1);
        if (j)
        {

          switch (mc30_pcpArr[lpcpIdx].pt)
          {
          case PCP_LABEL:
            if (state == PS_START)
            {
              DFPRINTF((stderr, "  label\n"));
              state = PS_HAVE_LABEL;
            }
            else
              DFPRINTF((stderr, "  bad state (%d) for label\n", state));
            break;

          case PCP_STR:
            DFPRINTF((stderr, "  %s is", mc30_tokArr[mc30_ltokIdx].tok.s));
            switch (state)
            {
            case PS_START:
            case PS_HAVE_LABEL:
              DFPRINTF((stderr, "  mnem\n"));
              state = PS_HAVE_MNEM;
              break;
            case PS_HAVE_MNEM:
              DFPRINTF((stderr, "  1st operand\n"));
              //pco1 = mc30_newpCodeOp(NULL,PO_GPR_REGISTER);
              state = PS_HAVE_1OPERAND;
              break;
            case PS_HAVE_1OPERAND:
              DFPRINTF((stderr, "  error expecting comma\n"));
              break;
            case PS_HAVE_COMMA:
              DFPRINTF((stderr, "  2 operands\n"));
              break;
            case PS_HAVE_2OPERANDS:
              break;
            }
            break;

          case PCP_WILDVAR:
            switch (state)
            {
            case PS_START:
            case PS_HAVE_LABEL:
              DFPRINTF((stderr, "  wild mnem\n"));
              state = PS_HAVE_MNEM;
              break;
            case PS_HAVE_MNEM:
              DFPRINTF((stderr, "  1st operand is wild\n"));
              state = PS_HAVE_1OPERAND;
              break;
            case PS_HAVE_1OPERAND:
              DFPRINTF((stderr, "  error expecting comma\n"));
              break;
            case PS_HAVE_COMMA:
              DFPRINTF((stderr, "  2nd operand is wild\n"));
              break;
            case PS_HAVE_2OPERANDS:
              break;
            }
            break;

          case PCP_NUMBER:
            switch (state)
            {
            case PS_START:
            case PS_HAVE_LABEL:
              fprintf(stderr, "  ERROR number\n");
              break;
            case PS_HAVE_MNEM:
              DFPRINTF((stderr, "  1st operand is a number\n"));
              state = PS_HAVE_1OPERAND;
              break;
            case PS_HAVE_1OPERAND:
              fprintf(stderr, "  error expecting comma\n");
              break;
            case PS_HAVE_COMMA:
              DFPRINTF((stderr, "  2nd operand is a number\n"));
              break;
            case PS_HAVE_2OPERANDS:
              break;
            }
            break;

          case PCP_WILDSTR:
            break;
          case PCP_COMMA:
            if (state == PS_HAVE_1OPERAND)
            {
              DFPRINTF((stderr, "  got a comma\n"));
              state = PS_HAVE_COMMA;
            }
            else
              fprintf(stderr, "  unexpected comma\n");
            break;
          }

          matching = 1;
          mc30_parsedPatArr[lparsedPatIdx].pcp = &mc30_pcpArr[lpcpIdx];
          mc30_parsedPatArr[lparsedPatIdx].pct = &mc30_tokArr[mc30_ltokIdx];
          lparsedPatIdx++;

          //mc30_dump1Token(mc30_tokArr[mc30_ltokIdx].tt);

          if (mc30_advTokIdx(&mc30_ltokIdx, strlen(mc30_pcpArr[lpcpIdx].tokens)))
          {
            DFPRINTF((stderr, " reached end \n"));
            matching = 0;
            //return;
          }
        }

      } while ((++lpcpIdx < PCPATTERNS) && !matching);

    } while (matching);

    mc30_parsedPatArr[lparsedPatIdx].pcp = NULL;
    mc30_parsedPatArr[lparsedPatIdx].pct = NULL;

    j = k = 0;
    do
    {
      int c;

      if ((c = mc30_altComparePattern(mc30_altArr[k].tokens, &mc30_parsedPatArr[j], 10)))
      {

        if (mc30_altArr[k].f)
        {
          pc = mc30_altArr[k].f(&mc30_parsedPatArr[j], pcwb);
          //if(pc && pc->print)
          //  pc->print(stderr,pc);
          //if(pc && pc->destruct) pc->destruct(pc); dumps core?

          if (pc)
          {
            if (pcret)
            {
              *pcret = pc;
              return 0; // Only accept one line for now.
            }
            else
              mc30_addpCode2pBlock(pcwb->pb, pc);
          }
          else
            error++;
        }
        j += c;
      }
      k++;
    } while (j <= lparsedPatIdx && k < ALTPATTERNS);

    /*
  DFPRINTF((stderr,"\nConverting parsed line to pCode:\n\n"));

    j = 0;
    do {
    if(mc30_parsedPatArr[j].pcp && mc30_parsedPatArr[j].pcp->f )
    mc30_parsedPatArr[j].pcp->f(&mc30_parsedPatArr[j]);
    DFPRINTF((stderr,"  %d",mc30_parsedPatArr[j].pcp->pt));
    j++;
    }
    while(j<lparsedPatIdx);
  */
    DFPRINTF((stderr, "\n"));
  }

  return error;
}

/*-----------------------------------------------------------------*/
/*                                                                 */
/*-----------------------------------------------------------------*/
static void mc30_peepRuleBlock2pCodeBlock(lineNode *ln, pCodeWildBlock *pcwb)
{

  if (!ln)
    return;

  for (; ln; ln = ln->next)
  {

    //DFPRINTF((stderr,"%s\n",ln->line));

    mc30_tokenizeLineNode(ln->line);

    if (mc30_parseTokens(pcwb, NULL))
    {
      int i;
      fprintf(stderr, "ERROR assembling line:\n%s\n", ln->line);
      fprintf(stderr, "Tokens:\n");
      for (i = 0; i < 5; i++)
        mc30_dump1Token(mc30_tokArr[i].tt);
      fputc('\n', stderr);
      exit(1);
    }
  }
}

/*-----------------------------------------------------------------*/
/* mc30_peepRuleCondition                                               */
/*-----------------------------------------------------------------*/
static void mc30_peepRuleCondition(char *cond, pCodePeep *pcp)
{
  if (!cond || !pcp)
    return;

  //DFPRINTF((stderr,"\nCondition:  %s\n",cond));
  /* brute force compares for now */

  if (STRCASECMP(cond, "NZ") == 0)
  {
    //DFPRINTF((stderr,"found NZ\n"));
    pcp->postFalseCond = PCC_Z;
  }
}

static void mc30_initpCodeWildBlock(pCodeWildBlock *pcwb)
{

  //  pcwb = Safe_calloc(1,sizeof(pCodeWildBlock));

  if (!pcwb)
    return;

  pcwb->vars = NULL;
  pcwb->wildpCodes = NULL;
  pcwb->wildpCodeOps = NULL;

  pcwb->nvars = 0;
  pcwb->nwildpCodes = 0;
  pcwb->nops = 0;
}

static void mc30_postinit_pCodeWildBlock(pCodeWildBlock *pcwb)
{

  if (!pcwb)
    return;

  pcwb->nvars += 2;
  pcwb->nops = pcwb->nvars;

  pcwb->vars = Safe_calloc(pcwb->nvars, sizeof(char *));
  pcwb->wildpCodeOps = Safe_calloc(pcwb->nvars, sizeof(pCodeOp *));

  pcwb->nwildpCodes += 2;
  pcwb->wildpCodes = Safe_calloc(pcwb->nwildpCodes, sizeof(pCode *));
}

static void mc30_initpCodePeep(pCodePeep *pcp)
{

  //  pcwb = Safe_calloc(1,sizeof(pCodeWildBlock));

  if (!pcp)
    return;

  mc30_initpCodeWildBlock(&pcp->target);
  pcp->target.pb = mc30_newpCodeChain(NULL, 'W', NULL);

  mc30_initpCodeWildBlock(&pcp->replace);
  pcp->replace.pb = mc30_newpCodeChain(NULL, 'W', NULL);
}

/*-----------------------------------------------------------------*/
/* mc30_peepRules2pCode - parse the "parsed" peep hole rules to generate*/
/*                   pCode.                                        */
/*                                                                 */
/* SDCCpeeph parses the peep rules file and extracts variables,    */
/* removes white space, and checks the syntax. This function       */
/* extends that processing to produce pCode objects. You can kind  */
/* think of this function as an "assembler", though instead of     */
/* taking raw text to produce machine code, it produces pCode.     */
/*                                                                 */
/*-----------------------------------------------------------------*/
void mc30_peepRules2pCode(peepRule *rules)
{
  peepRule *pr;

  pCodePeep *currentRule;
  pCodePeepSnippets *pcps;

  mc30_initpCodePeepCommands();

  /* The rules are in a linked-list. Each rule has two portions */
  /* There's the `target' and there's the `replace'. The target */
  /* is compared against the SDCC generated code and if it      */
  /* matches, it gets replaced by the `replace' block of code.  */
  /*                                                            */
  /* Here we loop through each rule and convert the target's and*/
  /* replace's into pCode target and replace blocks             */

  for (pr = rules; pr; pr = pr->next)
  {

    //DFPRINTF((stderr,"\nRule:\n\n"));

    // zwr 2.0.0
    pcps = Safe_alloc(sizeof(pCodePeepSnippets));
    // pcps = Safe_calloc(1, sizeof(pCodePeepSnippets));
    mc30_peepSnippets = mc30_DLL_append((DLList *)mc30_peepSnippets, (DLList *)pcps);

    // zwr 2.0.0
    currentRule = pcps->peep = Safe_alloc(sizeof(pCodePeep));
    // currentRule = pcps->peep = Safe_calloc(1, sizeof(pCodePeep));
    mc30_initpCodePeep(currentRule);

    /* Convert the target block */
    mc30_peepRuleBlock2pCodeBlock(pr->match, &currentRule->target);

    //DFPRINTF((stderr,"finished target, here it is in pcode form:\n"));
    //mc30_printpBlock(stderr, currentRule->target.pb);

    mc30_pBlockMergeLabels(currentRule->target.pb);
    //mc30_printpBlock(stderr, currentRule->replace.pb);

    /* Convert the replace block */
    mc30_peepRuleBlock2pCodeBlock(pr->replace, &currentRule->replace);

    //DFPRINTF((stderr,"replace with labels merged:\n"));

    mc30_pBlockMergeLabels(currentRule->replace.pb);
    //mc30_printpBlock(stderr, currentRule->replace.pb);

    mc30_peepRuleCondition(pr->cond, currentRule);

    /* The rule has been converted to pCode. Now allocate
    * space for the wildcards */

    mc30_postinit_pCodeWildBlock(&currentRule->target);
    mc30_postinit_pCodeWildBlock(&currentRule->replace);

    //return; // debug ... don't want to go through all the rules yet
  }

  if (0)
  {
    pCodePeep *peepBlock;
    DLList *peeprules;

    peeprules = (DLList *)mc30_peepSnippets;
    fprintf(stderr, "target rules\n");
    while (peeprules)
    {
      fprintf(stderr, "   rule:\n");
      peepBlock = ((pCodePeepSnippets *)peeprules)->peep;
      mc30_printpBlock(stderr, peepBlock->target.pb);
      peeprules = peeprules->next;
    } // while
    fprintf(stderr, " ... done\n");
  } // if
}

/*-----------------------------------------------------------------*/
/* DLList * mc30_DLL_append                                             */
/*                                                                 */
/*  Append a DLList object to the end of a DLList (doubly linked   */
/* list). If The list to which we want to append is non-existant   */
/* then one is created. Other wise, the end of the list is sought  */
/* out and a new DLList object is appended to it. In either case,  */
/* the void *data is added to the newly created DLL object.        */
/*-----------------------------------------------------------------*/

static void *mc30_DLL_append(DLList *list, DLList *next)
{
  DLList *b;

  /* If there's no list, then create one: */
  if (!list)
  {
    next->next = next->prev = NULL;
    return next;
  }

  /* Search for the end of the list. */
  b = list;
  while (b->next)
    b = b->next;

  /* Now append the new DLL object */
  b->next = next;
  b->next->prev = b;
  b = b->next;
  b->next = NULL;

  return list;
}

/*-----------------------------------------------------------------

  pCode peephole optimization


    The pCode "peep hole" optimization is not too unlike the peep hole
    optimization in SDCCpeeph.c. The major difference is that here we
    use pCode's whereas there we use ASCII strings. The advantage with
    pCode's is that we can ascertain flow information in the instructions
    being optimized.


      <FIX ME> - elaborate...

-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
/* mc30_pCodeSearchCondition - Search a pCode chain for a 'condition'   */
/*                                                                 */
/* return conditions                                               */
/*  1 - The Condition was found for a pCode's input                */
/*  0 - No matching condition was found for the whole chain        */
/* -1 - The Condition was found for a pCode's output               */
/*                                                                 */
/*-----------------------------------------------------------------*/
int mc30_pCodeSearchCondition(pCode *pc, unsigned int cond, int contIfSkip)
{
  while (pc)
  {

    /* If we reach a function end (presumably an end since we most
  probably began the search in the middle of a function), then
    the condition was not found. */
    if (pc->type == PC_FUNCTION)
      return 0;

    if (pc->type == PC_OPCODE)
    {
      if (PCI(pc)->inCond & cond)
      {
        if (contIfSkip)
        {
          /* If previous instruction is a skip then continue search as condiction is not certain */
          pCode *pcp = mc30_findPrevInstruction(pc->prev);
          if (pcp && !isPCI_SKIP(pcp))
          {
            return 1;
          }
        }
        else
        {
          return 1;
        }
      }
      if (PCI(pc)->outCond & cond)
      {
        if (contIfSkip)
        {
          /* If previous instruction is a skip then continue search as condiction is not certain */
          pCode *pcp = mc30_findPrevInstruction(pc->prev);
          if (pcp && !isPCI_SKIP(pcp))
          {
            return -1;
          }
        }
        else
        {
          return -1;
        }
      }
    }

    pc = pc->next;
  }

  return 0;
}

/*-----------------------------------------------------------------
* int mc30_pCodeOpCompare(pCodeOp *pcops, pCodeOp *pcopd)
*
* Compare two pCodeOp's and return 1 if they're the same
*-----------------------------------------------------------------*/
static int mc30_pCodeOpCompare(pCodeOp *pcops, pCodeOp *pcopd)
{
  char b[50], *n2;

  if (!pcops || !pcopd)
    return 0;
  /*
    fprintf(stderr," Comparing operands %s",
    mc30_get_op( pcops,NULL,0));

      fprintf(stderr," to %s\n",
      mc30_get_op( pcopd,NULL,0));
  */

  if (pcops->type != pcopd->type)
  {
    //fprintf(stderr,"  - fail - diff types\n");
    return 0; // different types
  }

  if (pcops->type == PO_LITERAL)
  {

    if ((PCOL(pcops)->lit >= 0) && (PCOL(pcops)->lit == PCOL(pcopd)->lit))
      return 1;

    return 0;
  }

  b[0] = 0;
  mc30_get_op(pcops, b, 50);

  n2 = mc30_get_op(pcopd, NULL, 0);

  if (!n2 || strcmp(b, n2))
  {
    //fprintf(stderr,"  - fail - diff names: %s, len=%d,  %s, len=%d\n",b,strlen(b), n2, strlen(n2) );
    return 0; // different names
  }

  switch (pcops->type)
  {
  case PO_DIR:
    if (PCOR(pcops)->instance != PCOR(pcopd)->instance)
    {
      //fprintf(stderr, "  - fail different instances\n");
      return 0;
    }
    break;
  default:
    break;
  }

  //fprintf(stderr,"  - pass\n");

  return 1;
}

static int mc30_pCodePeepMatchLabels(pCodePeep *peepBlock, pCode *pcs, pCode *pcd)
{
  int labindex;

  /* Check for a label associated with this wild pCode */
  // If the wild card has a label, make sure the source code does too.
  if (PCI(pcd)->label)
  {
    pCode *pcl = PCI(pcd)->label->pc;

#ifdef PCODE_DEBUG
    int li = -PCL(pcl)->key;

    if (peepBlock->target.vars[li] == NULL)
    {
      if (PCI(pcs)->label)
      {
        DFPRINTF((stderr, "first time for a label: %d %s\n", li, PCL(PCI(pcs)->label->pc)->label));
      }
    }
    else
    {
      // DFPRINTF((stderr,"label id = %d \n",PCL(PCI(pcd)->label->pc)->key));
      DFPRINTF((stderr, " label id: %d %s\n", li, peepBlock->target.vars[li]));
      if (PCI(pcs)->label)
      {
        DFPRINTF((stderr, " src %s\n", PCL(PCI(pcs)->label->pc)->label));
      }
    }
#endif

    if (!PCI(pcs)->label)
      return 0;

    labindex = -PCL(pcl)->key;
    if (peepBlock->target.vars[labindex] == NULL)
    {
      // First time to encounter this label
      peepBlock->target.vars[labindex] = PCL(PCI(pcs)->label->pc)->label;
      DFPRINTF((stderr, "first time for a label: %d %s\n", labindex, PCL(PCI(pcs)->label->pc)->label));
    }
    else
    {
      if (strcmp(peepBlock->target.vars[labindex], PCL(PCI(pcs)->label->pc)->label) != 0)
      {
        DFPRINTF((stderr, "labels don't match dest %s != src %s\n", peepBlock->target.vars[labindex], PCL(PCI(pcs)->label->pc)->label));
        return 0;
      }
      DFPRINTF((stderr, "matched a label %d %s -hey\n", labindex, peepBlock->target.vars[labindex]));
    }
  }
  else
  {
    //DFPRINTF((stderr,"destination doesn't have a label\n"));

    if (PCI(pcs)->label)
      return 0;

    //DFPRINTF((stderr,"neither src nor dest have labels\n"));
  }

  return 1;
}

/*-----------------------------------------------------------------*/
/* mc30_pCodePeepMatchLine - Compare source and destination pCodes to   */
/*                      see they're the same.                      */
/*                                                                 */
/* In this context, "source" refers to the coded generated by gen.c*/
/* and "destination" refers to a pcode in a peep rule. If the dest-*/
/* ination has no wild cards, then MatchLine will compare the two  */
/* pcodes (src and dest) for a one-to-one match. If the destination*/
/* has wildcards, then those get expanded. When a wild card is     */
/* encountered for the first time it autmatically is considered a  */
/* match and the object that matches it is referenced in the       */
/* variables or opcodes array (depending on the type of match).    */
/*                                                                 */
/*                                                                 */
/* Inputs:                                                         */
/*  *peepBlock - A pointer to the peepBlock that contains the      */
/*               entire rule to which the destination pcode belongs*/
/*  *pcs - a pointer to the source pcode                           */
/*  *pcd - a pointer to the destination pcode                      */
/*                                                                 */
/* Returns:                                                        */
/*  1 - pcodes match                                               */
/*  0 - pcodes don't match                                         */
/*                                                                 */
/*                                                                 */
/*-----------------------------------------------------------------*/

static int mc30_pCodePeepMatchLine(pCodePeep *peepBlock, pCode *pcs, pCode *pcd)
{
  int index; // index into wild card arrays

  /* one-for-one match. Here the source and destination opcodes
  * are not wild. However, there may be a label or a wild operand */

  if (pcs)
  {
    if (PCI(pcs)->label)
    {
      DFPRINTF((stderr, "Match line source label: %s\n", PCL(PCI(pcs)->label->pc)->label));
    }
  }

  if (pcs->type == pcd->type)
  {

    if (pcs->type == PC_OPCODE)
    {

      /* If the opcodes don't match then the line doesn't match */
      if (PCI(pcs)->op != PCI(pcd)->op)
        return 0;

#ifdef PCODE_DEBUG
      DFPRINTF((stderr, "%s comparing\n", __FUNCTION__));
      pcs->print(stderr, pcs);
      pcd->print(stderr, pcd);
#endif

      if (!mc30_pCodePeepMatchLabels(peepBlock, pcs, pcd))
        return 0;

      /* Compare the operands */
      if (PCI(pcd)->pcop)
      {
        // Volatile types should not be deleted or modified, these include SFR, externs and publics
        // They can be used as a matched, however if a match is found then the optimiser intends
        // to change some aspect of a block of code, which is most likely a critcal one. As this
        // method of optimisation does not allow a means to distiguishing what may change, it is
        // best to just negate any match.
        if (PCI(pcs)->pcop)
        {
          struct reg_info *r;
          pCodeOp *pcop = PCI(pcs)->pcop;
          switch (pcop->type)
          {
          case PO_W:
          case PO_STATUS:
          case PO_FSR:
          case PO_INDF:
          case PO_INTCON:
          case PO_PCL:
          case PO_PCLATH:
          case PO_SFR_REGISTER:
            return 0; // SFR - do not modify
          case PO_DIR:
          case PO_GPR_REGISTER:
          case PO_GPR_BIT:
          case PO_GPR_TEMP:
          case PO_GPR_POINTER:
            r = PCOR(pcop)->r;
            if (r->isPublic || r->isExtern || r->isFixed) // Changes to these types of registers should not be changed as they may be used else where
              return 0;
          default:
            break;
          }
        }
        if (PCI(pcd)->pcop->type == PO_WILD)
        {
          char *n;
          index = PCOW(PCI(pcd)->pcop)->id;
//DFPRINTF((stderr,"destination is wild\n"));
#ifdef DEBUG_PCODEPEEP
          if (index > peepBlock->nops)
          {
            DFPRINTF((stderr, "%s - variables exceeded\n", __FUNCTION__));
            exit(1);
          }
#endif
          n = PCI(pcs)->pcop->name;
          if (peepBlock->target.vars[index])
          {
            if ((!n) || (strcmp(peepBlock->target.vars[index], n) != 0))
              return 0; // variable is different
          }
          else
          {
            DFPRINTF((stderr, "first time for a variable: %d, %s\n", index, n));
            peepBlock->target.vars[index] = n;
          }

          PCOW(PCI(pcd)->pcop)->matched = PCI(pcs)->pcop;
          if (!peepBlock->target.wildpCodeOps[index])
          {
            peepBlock->target.wildpCodeOps[index] = PCI(pcs)->pcop;

            //fprintf(stderr, "first time for wild opcode #%d\n",index);
            return 1;
          }
          else
          {
            /*
          pcs->print(stderr,pcs);
          pcd->print(stderr,pcd);
          fprintf(stderr, "comparing operands of these instructions, result %d\n",
          mc30_pCodeOpCompare(PCI(pcs)->pcop, peepBlock->target.wildpCodeOps[index])
          );
          */

            return mc30_pCodeOpCompare(PCI(pcs)->pcop, peepBlock->target.wildpCodeOps[index]);
          }
          /*
          {
            char *n;

            switch(PCI(pcs)->pcop->type) {
            case PO_GPR_TEMP:
            case PO_FSR:
            //case PO_INDF:
              //n = PCOR(PCI(pcs)->pcop)->r->name;
              n = PCI(pcs)->pcop->name;

            break;
            default:
              n = PCI(pcs)->pcop->name;
            }

            if(peepBlock->target.vars[index])
              return  (strcmp(peepBlock->target.vars[index],n) == 0);
            else {
              DFPRINTF((stderr,"first time for a variable: %d, %s\n",index,n));
              peepBlock->target.vars[index] = n;
              return 1;
            }
          }
          */
        }
        else if (PCI(pcd)->pcop->type == PO_LITERAL)
        {
          /*
        pcs->print(stderr,pcs);
        pcd->print(stderr,pcd);

        fprintf(stderr, "comparing literal operands of these instructions, result %d\n",
        mc30_pCodeOpCompare(PCI(pcs)->pcop, PCI(pcd)->pcop));
        */
          return mc30_pCodeOpCompare(PCI(pcs)->pcop, PCI(pcd)->pcop);
        }
        else
        {
          /* FIXME - need an else to check the case when the destination
            * isn't a wild card */
          /*
          fprintf(stderr, "Destination is not wild: operand compare =%d\n",
          mc30_pCodeOpCompare(PCI(pcs)->pcop, PCI(pcd)->pcop));
          */
          return mc30_pCodeOpCompare(PCI(pcs)->pcop, PCI(pcd)->pcop);
        }
      }
      else
        /* The pcd has no operand. Lines match if pcs has no operand either*/
        return (PCI(pcs)->pcop == NULL);
    }
  }

  /* Compare a wild instruction to a regular one. */

  if ((pcd->type == PC_WILD) && (pcs->type == PC_OPCODE))
  {

    index = PCW(pcd)->id;
#ifdef PCODE_DEBUG
    DFPRINTF((stderr, "%s comparing wild cards\n", __FUNCTION__));
    pcs->print(stderr, pcs);
    pcd->print(stderr, pcd);
#endif
    peepBlock->target.wildpCodes[PCW(pcd)->id] = pcs;

    if (!mc30_pCodePeepMatchLabels(peepBlock, pcs, pcd))
    {
      DFPRINTF((stderr, " Failing because labels don't match\n"));
      return 0;
    }

    if (PCW(pcd)->mustBeBitSkipInst & !(PCI(pcs)->isBitInst && PCI(pcs)->isSkip))
    {
      // doesn't match because the wild pcode must be a bit skip
      DFPRINTF((stderr, " Failing match because bit skip is req\n"));
      //pcd->print(stderr,pcd);
      //pcs->print(stderr,pcs);
      return 0;
    }

    if (PCW(pcd)->mustNotBeBitSkipInst & (PCI(pcs)->isBitInst && PCI(pcs)->isSkip))
    {
      // doesn't match because the wild pcode must *not* be a bit skip
      DFPRINTF((stderr, " Failing match because shouldn't be bit skip\n"));
      //pcd->print(stderr,pcd);
      //pcs->print(stderr,pcs);
      return 0;
    }

    if (PCW(pcd)->operand)
    {
      PCOW(PCI(pcd)->pcop)->matched = PCI(pcs)->pcop;
      if (peepBlock->target.vars[index])
      {
        int i = (strcmp(peepBlock->target.vars[index], PCI(pcs)->pcop->name) == 0);
#ifdef PCODE_DEBUG

        if (i)
          DFPRINTF((stderr, " (matched)\n"));
        else
        {
          DFPRINTF((stderr, " (no match: wild card operand mismatch\n"));
          DFPRINTF((stderr, "  peepblock= %s,  pcodeop= %s\n",
                    peepBlock->target.vars[index],
                    PCI(pcs)->pcop->name));
        }
#endif
        return i;
      }
      else
      {
        DFPRINTF((stderr, " (matched %s\n", PCI(pcs)->pcop->name));
        peepBlock->target.vars[index] = PCI(pcs)->pcop->name;
        return 1;
      }
    }

    pcs = mc30_findNextInstruction(pcs->next);
    if (pcs)
    {
      //DFPRINTF((stderr," (next to match)\n"));
      //pcs->print(stderr,pcs);
    }
    else if (pcd->next)
    {
      /* oops, we ran out of code, but there's more to the rule */
      return 0;
    }

    return 1; /*  wild card matches */
  }

  return 0;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
static void mc30_pCodePeepClrVars(pCodePeep *pcp)
{

  int i;
  if (!pcp)
    return;
  /*
  DFPRINTF((stderr," Clearing peep rule vars\n"));
  DFPRINTF((stderr," %d %d %d  %d %d %d\n",
  pcp->target.nvars,pcp->target.nops,pcp->target.nwildpCodes,
  pcp->replace.nvars,pcp->replace.nops,pcp->replace.nwildpCodes));
  */
  for (i = 0; i < pcp->target.nvars; i++)
    pcp->target.vars[i] = NULL;
  for (i = 0; i < pcp->target.nops; i++)
    pcp->target.wildpCodeOps[i] = NULL;
  for (i = 0; i < pcp->target.nwildpCodes; i++)
    pcp->target.wildpCodes[i] = NULL;

  for (i = 0; i < pcp->replace.nvars; i++)
    pcp->replace.vars[i] = NULL;
  for (i = 0; i < pcp->replace.nops; i++)
    pcp->replace.wildpCodeOps[i] = NULL;
  for (i = 0; i < pcp->replace.nwildpCodes; i++)
    pcp->replace.wildpCodes[i] = NULL;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
int mc30_pCodePeepMatchRule(pCode *pc)
{
  pCodePeep *peepBlock;
  pCode *pct, *pcin;
  pCodeCSource *pc_cline = NULL;
  DLList *peeprules;
  int matched;

  peeprules = (DLList *)mc30_peepSnippets;

  while (peeprules)
  {
    peepBlock = ((pCodePeepSnippets *)peeprules)->peep;

    if (!peepBlock || /*!peepBlock->target ||*/ !peepBlock->target.pb->pcHead)
    {
      fprintf(stderr, "skipping rule because target pb is NULL\n");
      goto next_rule;
    }

    mc30_pCodePeepClrVars(peepBlock);
    /*
    pcin = pc;
    if(IS_PCCOMMENT(pcin))
    pc = pcin = mc30_findNextInstruction(pcin->next);
    */
    pcin = pc = mc30_findNextInstruction(pc);

    pct = peepBlock->target.pb->pcHead;
#ifdef PCODE_DEBUG
    {
      pCode *pcr = peepBlock->replace.pb->pcHead;
      if (pcr)
        pct->print(stderr, pcr);
    }
#endif
    matched = 0;
    while (pct && pcin)
    {

      if (!(matched = mc30_pCodePeepMatchLine(peepBlock, pcin, pct)))
        break;

      pcin = mc30_findNextInstruction(pcin->next);
      pct = pct->next;
      //debug:
      //DFPRINTF((stderr,"    matched\n"));

      if (!pcin && pct)
      {
        DFPRINTF((stderr, " partial match... no more code\n"));
        matched = 0;
      }
      if (!pct)
      {
        DFPRINTF((stderr, " end of rule\n"));
      }
    }

    if (matched && pcin)
    {

      /* So far we matched the rule up to the point of the conditions .
    * In other words, all of the opcodes match. Now we need to see
    * if the post conditions are satisfied.
    * First we check the 'postFalseCond'. This means that we check
    * to see if any of the subsequent pCode's in the pCode chain
    * following the point just past where we have matched depend on
    * the `postFalseCond' as input then we abort the match
    */
      DFPRINTF((stderr, "    matched rule so far, now checking conditions\n"));
      //pcin->print(stderr,pcin);

      if (pcin && peepBlock->postFalseCond &&
          (mc30_pCodeSearchCondition(pcin, peepBlock->postFalseCond, 0) > 0))
        matched = 0;

      //fprintf(stderr," condition results = %d\n",mc30_pCodeSearchCondition(pcin,peepBlock->postFalseCond));

      //if(!matched) fprintf(stderr,"failed on conditions\n");
    }

    if (matched)
    {

      pCode *pcprev;
      pCode *pcr, *pcout;

/* We matched a rule! Now we have to go through and remove the
      inefficient code with the optimized version */
#ifdef PCODE_DEBUG
      DFPRINTF((stderr, "Found a pcode peep match:\nRule:\n"));
      //printpCodeString(stderr,peepBlock->target.pb->pcHead,10);
      DFPRINTF((stderr, "first thing matched\n"));
      pc->print(stderr, pc);
      if (pcin)
      {
        DFPRINTF((stderr, "last thing matched\n"));
        pcin->print(stderr, pcin);
      }
#endif

      /* Unlink the original code */
      pcout = pc;
      pcprev = pc->prev;
      pcprev->next = pcin;
      if (pcin)
        pcin->prev = pc->prev;

#if 0
      {
        /*     DEBUG    */
        /* Converted the deleted pCodes into comments */

        char buf[256];
        pCodeCSource *pc_cline2=NULL;

        buf[0] = ';';
        buf[1] = '#';

        while(pc &&  pc!=pcin) {

          if(pc->type == PC_OPCODE && PCI(pc)->cline) {
            if(pc_cline) {
              pc_cline2->pc.next = PCODE(PCI(pc)->cline);
              pc_cline2 = PCCS(pc_cline2->pc.next);
            } else {
              pc_cline = pc_cline2 = PCI(pc)->cline;
              pc_cline->pc.seq = pc->seq;
            }
          }

          mc30_pCode2str(&buf[2], 254, pc);
          mc30_pCodeInsertAfter(pcprev, mc30_newpCodeCharP(buf));
          pcprev = pcprev->next;
          pc = pc->next;

        }
        if(pc_cline2)
          pc_cline2->pc.next = NULL;
      }
#endif

      if (pcin)
        mc30_pCodeDeleteChain(pc, pcin);

      /* Generate the replacement code */
      pc = pcprev;
      pcr = peepBlock->replace.pb->pcHead; // This is the replacement code
      while (pcr)
      {
        pCodeOp *pcop = NULL;

        /* If the replace pcode is an instruction with an operand, */
        /* then duplicate the operand (and expand wild cards in the process). */
        if (pcr->type == PC_OPCODE)
        {
          if (PCI(pcr)->pcop)
          {
            /* The replacing instruction has an operand.
            * Is it wild? */
            if (PCI(pcr)->pcop->type == PO_WILD)
            {
              int index = PCOW(PCI(pcr)->pcop)->id;
              //DFPRINTF((stderr,"copying wildopcode\n"));
              if (peepBlock->target.wildpCodeOps[index])
                pcop = mc30_pCodeOpCopy(peepBlock->target.wildpCodeOps[index]);
              else
                DFPRINTF((stderr, "error, wildopcode in replace but not source?\n"));
            }
            else
              pcop = mc30_pCodeOpCopy(PCI(pcr)->pcop);
          }
          //DFPRINTF((stderr,"inserting pCode\n"));
          mc30_pCodeInsertAfter(pc, mc30_newpCode(PCI(pcr)->op, pcop));
        }
        else if (pcr->type == PC_WILD)
        {
          if (PCW(pcr)->invertBitSkipInst)
            DFPRINTF((stderr, "We need to invert the bit skip instruction\n"));
          mc30_pCodeInsertAfter(pc,
                           mc30_pCodeInstructionCopy(PCI(peepBlock->target.wildpCodes[PCW(pcr)->id]),
                                                PCW(pcr)->invertBitSkipInst));
        }
        else if (pcr->type == PC_COMMENT)
        {
          mc30_pCodeInsertAfter(pc, mc30_newpCodeCharP(((pCodeComment *)(pcr))->comment));
        }

        pc = pc->next;
#ifdef PCODE_DEBUG
        DFPRINTF((stderr, "  NEW Code:"));
        if (pc)
          pc->print(stderr, pc);
#endif
        pcr = pcr->next;
      }

      /* We have just replaced the inefficient code with the rule.
      * Now, we need to re-add the C-source symbols if there are any */
      pc = pcprev;
      while (pc && pc_cline)
      {

        pc = mc30_findNextInstruction(pc->next);
        if (!pc)
          break;
        PCI(pc)->cline = pc_cline;
        pc_cline = PCCS(pc_cline->pc.next);
      }

      /* Copy C code comments to new code. */
      pc = pcprev->next;
      if (pc)
      {
        for (; pc && pcout != pcin; pcout = pcout->next)
        {
          if (pcout->type == PC_OPCODE && PCI(pcout)->cline)
          {
            while (pc->type != PC_OPCODE || PCI(pc)->cline)
            {
              pc = pc->next;
              if (!pc)
                break;
            }
            if (!pc)
              break;
            PCI(pc)->cline = PCI(pcout)->cline;
          }
        }
      }

      return 1;
    }
  next_rule:
    peeprules = peeprules->next;
  }
  DFPRINTF((stderr, " no rule matched\n"));

  return 0;
}
