/** @file main.c
    pic14 specific general functions.

    Note that mlh prepended _pic14_ on the static functions.  Makes
    it easier to set a breakpoint using the debugger.
*/
#include "common.h"
#include "dbuf_string.h"
#include "SDCCmacro.h"

#include "device.h"
#include "gen.h"
#include "glue.h"
#include "main.h"
#include "pcode.h"
#include "ralloc.h"

/*
 * Imports
 */
extern set *dataDirsSet;
extern set *includeDirsSet;
extern set *libDirsSet;
extern set *libPathsSet;
extern set *linkOptionsSet;

mc30_options_t mc30_options;
int mc30_debug_verbose = 0;

#define OPTION_STACK_SIZE "--stack-size"

// zwr 1.1.0
#define FL_MODE "--fl-mode"
int mc30_fl_mode = 0;

#define START_ADDR "--start-addr"
int mc30_start_addr = 0;

static char _mc30_defaultRules[] =
    {
#include "peeph.rul"
};

static OPTION _mc30_poptions[] =
    {
        {0, "--debug-xtra", &mc30_debug_verbose, "show more debug info in assembly output"},
        {0, "--no-pcode-opt", &mc30_options.disable_df, "disable (slightly faulty) optimization on pCode"},
        // zwr 1.1.0
        {0, FL_MODE, &mc30_fl_mode, "enable feeling mode"},
        {0, START_ADDR, &mc30_start_addr, "sets the start address (default: 0)", CLAT_INTEGER},
        {0, OPTION_STACK_SIZE, &options.stack_size, "sets the size if the argument passing stack (default: 16, minimum: 4)", CLAT_INTEGER},
        // zwr 2.0.0
        {0, "--no-extended-instructions", &mc30_options.no_ext_instr, "forbid use of the extended instruction set (e.g., ADDFSR)"},
        {0, "--no-warn-non-free", &mc30_options.no_warn_non_free, "suppress warning on absent --use-non-free option"},
        {0, NULL, NULL, NULL}};

/* list of key words used by pic14 */
static char *_mc30_keywords[] =
    {
      // zwr 2.0.0
        "at",
        //"bit",
        "code",
        "critical",
        "data",
        "far",
        "idata",
        "interrupt",
        "naked",
        "near",
        // "pdata",
        "reentrant",
        "sfr",
        //"sbit",
        "using",
        "xdata",
        // "_data",
        // "_code",
        // "_generic",
        // "_near",
        // "_xdata",
        // "_pdata",
        // "_idata",
        NULL};

static int mc30_regParmFlg = 0; /* determine if we can register a parameter */

/** $1 is always the basename.
    $2 is always the output file.
    $3 varies
    $l is the list of extra options that should be there somewhere...
    MUST be terminated with a NULL.
*/
/*
static const char *_linkCmd[] =
{
  "gplink", "$l", "-w", "-r", "-o \"$2\"", "\"$1\"", "$3", NULL
};
*/

static const char *_mc30_asmCmd[] =
    {
        "gpasm", "$l", "$3", "-o", "\"$2\"", "-c", "\"$1.asm\"", NULL};

static void
_mc30_init(void)
{
  asm_addTree(&asm_asxxxx_mapping);
  memset(&mc30_options, 0, sizeof(mc30_options));
}

// zwr 2.0.0
static void
_mc30_reset_regparm(struct sym_link *funcType)
// static void
// _mc30_reset_regparm(void)
{
  mc30_regParmFlg = 0;
}

static int
_mc30_regparm(sym_link *l, bool reentrant)
{
  /* for this processor it is simple
  can pass only the first parameter in a register */
  //if (mc30_regParmFlg)
  //  return 0;

  mc30_regParmFlg++; // = 1;
  return 1;
}

static bool
_mc30_parseOptions(int *pargc, char **argv, int *i)
{
  /* TODO: allow port-specific command line options to specify
    * segment names here.
    */
  return FALSE;
}

static void
_mc30_finaliseOptions(void)
{
  struct dbuf_s dbuf;

  mc30_pCodeInitRegisters();

  port->mem.default_local_map = data;
  port->mem.default_globl_map = data;

  dbuf_init(&dbuf, 512);
  dbuf_printf(&dbuf, "-D__SDCC_PROCESSOR=\"%s\"", port->processor);
  addSet(&preArgvSet, Safe_strdup(dbuf_detach_c_str(&dbuf)));

  /*
 * deprecated in sdcc 3.2.0
 * TODO: should be obsoleted in sdcc 3.3.0 or later
  if (options.std_sdcc)
 */
  {
    dbuf_set_length(&dbuf, 0);
    dbuf_printf(&dbuf, "-DSDCC_PROCESSOR=\"%s\"", port->processor);
    addSet(&preArgvSet, dbuf_detach_c_str(&dbuf));
  }

  {
    char *upperProc, *p1, *p2;
    int len;

    dbuf_set_length(&dbuf, 0);
    len = strlen(port->processor);
    upperProc = Safe_malloc(len);
    for (p1 = port->processor, p2 = upperProc; *p1; ++p1, ++p2)
    {
      *p2 = toupper(*p1);
    }
    dbuf_append(&dbuf, "-D__SDCC_MC", sizeof("-D__SDCC_MC") - 1); // zwr 1.0.0
    dbuf_append(&dbuf, upperProc, len);
    addSet(&preArgvSet, dbuf_detach_c_str(&dbuf));
  }
}

static void
_mc30_setDefaultOptions(void)
{
}

static const char *
_mc30_getRegName(const struct reg_info *reg)
{
  if (reg)
    return reg->name;
  return "err";
}

static void
_mc30_genAssemblerPreamble(FILE *of)
{
  char *name = mc30_processor_base_name();

  if (!name)
  {

    name = "16f877";
    fprintf(stderr, "WARNING: No Pic has been selected, defaulting to %s\n", name);
  }

  fprintf(of, "\tlist\tp=%s\n", name);
  fprintf(of, "\tradix dec\n");
  fprintf(of, "\tinclude \"%s.inc\"\n", name); // zwr 1.0.0
}

/* Generate interrupt vector table. */
static int
_mc30_genIVT(struct dbuf_s *oBuf, symbol **interrupts, int maxInterrupts)
{
  /* Let the default code handle it. */
  return FALSE;
}

static bool
_mc30_hasNativeMulFor(iCode *ic, sym_link *left, sym_link *right)
{
  if (ic->op != '*')
  {
    return FALSE;
  }

  /* multiply chars in-place */
  if (getSize(left) == 1 && getSize(right) == 1)
    return TRUE;

  /* use library functions for more complex maths */
  return FALSE;
}

/* Indicate which extended bit operations this port supports */
static bool
mc30_hasExtBitOp(int op, int size)
{
  if (op == RRC || op == RLC || op == GETABIT
      /* || op == GETHBIT */ /* GETHBIT doesn't look complete for PIC */
      )
    return TRUE;
  else
    return FALSE;
}

/* Indicate the expense of an access to an output storage class */
static int
mc30_oclsExpense(struct memmap *oclass)
{
  /* The IN_FARSPACE test is compatible with historical behaviour, */
  /* but I don't think it is applicable to PIC. If so, please feel */
  /* free to remove this test -- EEP */
  if (IN_FARSPACE(oclass))
    return 1;

  return 0;
}

static void
_mc30_do_link(void)
{
  /*
   * link command format:
   * {linker} {incdirs} {lflags} -o {outfile} {spec_ofiles} {ofiles} {libs}
   *
   */
// zwr 1.0.0
#define LFRM "{linker} {incdirs} {sysincdirs} {lflags} -w -r -m -o {outfile} {user_ofile} {spec_ofiles} {ofiles} {libs}"
// #define LFRM "{linker} {incdirs} {sysincdirs} {lflags} -w -r -o {outfile} {user_ofile} {spec_ofiles} {ofiles} {libs}"
  hTab *linkValues = NULL;
  char *lcmd;
  set *tSet = NULL;
  int ret;
  char *procName;

  shash_add(&linkValues, "linker", "gplink");

  /* LIBRARY SEARCH DIRS */
  mergeSets(&tSet, libPathsSet);
  mergeSets(&tSet, libDirsSet);
  shash_add(&linkValues, "incdirs", joinStrSet(processStrSet(tSet, "-I", NULL, shell_escape)));

  joinStrSet(processStrSet(libDirsSet, "-I", NULL, shell_escape));
  shash_add(&linkValues, "sysincdirs", joinStrSet(processStrSet(libDirsSet, "-I", NULL, shell_escape)));

  shash_add(&linkValues, "lflags", joinStrSet(linkOptionsSet));

  {
    char *s = shell_escape(fullDstFileName ? fullDstFileName : dstFileName);

    shash_add(&linkValues, "outfile", s);
    Safe_free(s);
  }

  if (fullSrcFileName)
  {
    struct dbuf_s dbuf;
    char *s;

    dbuf_init(&dbuf, 128);

    dbuf_append_str(&dbuf, fullDstFileName ? fullDstFileName : dstFileName);
    dbuf_append(&dbuf, ".o", 2);
    s = shell_escape(dbuf_c_str(&dbuf));
    dbuf_destroy(&dbuf);
    shash_add(&linkValues, "user_ofile", s);
    Safe_free(s);
  }

  shash_add(&linkValues, "ofiles", joinStrSet(processStrSet(relFilesSet, NULL, NULL, shell_escape)));

  /* LIBRARIES */
  procName = mc30_processor_base_name();
  if (!procName)
    procName = "16f877";

  addSet(&libFilesSet, Safe_strdup(mc30_getPIC()->isEnhancedCore ? "libsdcce.lib" : "libsdcc.lib"));

  {
    struct dbuf_s dbuf;

    dbuf_init(&dbuf, 128);
    dbuf_append(&dbuf, "pic", sizeof("pic") - 1);
    // zwr 1.0.0
    // dbuf_append_str(&dbuf, procName);
    dbuf_append(&dbuf, ".lib", sizeof(".lib") - 1);
    addSet(&libFilesSet, dbuf_detach_c_str(&dbuf));
  }

  shash_add(&linkValues, "libs", joinStrSet(processStrSet(libFilesSet, NULL, NULL, shell_escape)));

  lcmd = msprintf(linkValues, LFRM);
  ret = sdcc_system(lcmd);
  Safe_free(lcmd);

  if (ret)
    exit(1);
}

// static void
// _mc30_do_link(void)
// {
//   hTab *linkValues = NULL;
//   char lfrm[256];
//   char *lcmd;
//   char temp[PATH_MAX];
//   set *tSet = NULL;
//   int ret;
//   char *procName;

//   /*
//    * link command format:
//    * {linker} {incdirs} {lflags} -o {outfile} {spec_ofiles} {ofiles} {libs}
//    *
//    */

//   // zwr 1.0.0
//   // sprintf(lfrm, "{linker} {incdirs} {sysincdirs} {lflags} -w -r -o \"{outfile}\" \"{user_ofile}\" {spec_ofiles} {ofiles} {libs}");
//   sprintf(lfrm, "{linker} {incdirs} {sysincdirs} {lflags} -w -r -m -o \"{outfile}\" \"{user_ofile}\" {spec_ofiles} {ofiles} {libs}");

//   shash_add(&linkValues, "linker", "gplink");

//   /* LIBRARY SEARCH DIRS */
//   mergeSets(&tSet, libPathsSet);
//   mergeSets(&tSet, libDirsSet);
//   shash_add(&linkValues, "incdirs", joinStrSet(appendStrSet(tSet, "-I\"", "\"")));

//   joinStrSet(appendStrSet(libDirsSet, "-I\"", "\""));
//   shash_add(&linkValues, "sysincdirs", joinStrSet(appendStrSet(libDirsSet, "-I\"", "\"")));

//   shash_add(&linkValues, "lflags", joinStrSet(linkOptionsSet));

//   shash_add(&linkValues, "outfile", fullDstFileName ? fullDstFileName : dstFileName);

//   if (fullSrcFileName)
//   {
//     SNPRINTF(temp, sizeof(temp), "%s.o", fullDstFileName ? fullDstFileName : dstFileName);
//     shash_add(&linkValues, "user_ofile", temp);
//   }

//   shash_add(&linkValues, "ofiles", joinStrSet(appendStrSet(relFilesSet, "\"", "\"")));

//   /* LIBRARIES */
//   procName = mc30_processor_base_name();
//   if (!procName)
//   {
//     procName = "16f877";
//   }

//   if (mc30_getPIC()->isEnhancedCore)
//   {
//     addSet(&libFilesSet, Safe_strdup("libsdcce.lib"));
//   }
//   else
//   {
//     addSet(&libFilesSet, Safe_strdup("libsdcc.lib"));
//   }
//   SNPRINTF(temp, sizeof(temp), "%s.lib", procName); // zwr 1.0.0
//   addSet(&libFilesSet, Safe_strdup(temp));
//   shash_add(&linkValues, "libs", joinStrSet(appendStrSet(libFilesSet, "\"", "\"")));

//   lcmd = msprintf(linkValues, lfrm);

//   ret = sdcc_system(lcmd);

//   Safe_free(lcmd);

//   if (ret)
//     exit(1);
// }

/* Globals */
PORT mc30_port =
    {
        TARGET_ID_PIC14,
        "mc30",              // zwr 1.1.0
        "SinoMCU mc30", /* Target name */
        "",                  /* Processor */
        {
            mc30_picglue,
            TRUE, /* Emit glue around main */
            NO_MODEL,
            NO_MODEL,
            NULL, /* model == target */
        },
        {
            _mc30_asmCmd,
            NULL,
            "-g", /* options with --debug */
            NULL, /* options without --debug */
            //"-plosgffc",  /* Options with debug */
            //"-plosgff",   /* Options without debug */
            0,
            ".asm",
            NULL /* no do_assemble function */
        },
        {NULL,
         NULL,
         _mc30_do_link, /* own do link function */
         ".o",
         0},
        {/* Peephole optimizer */
         _mc30_defaultRules},
        {
            /* Sizes: char, short, int, long, long long, near ptr, far ptr, gptr, func ptr, banked func ptr, bit, float */
            1, 2, 2, 4, 8, 2, 2, 3, 2, 3, 1, 4
            /* TSD - I changed the size of gptr from 3 to 1. However, it should be
       2 so that we can accomodate the PIC's with 4 register banks (like the
       16f877)
     */
        },
        /* tags for generic pointers */
        {0x00, 0x00, 0x00, 0x80}, /* far, near, xstack, code */
        {
            "XSEG    (XDATA)",
            "STACK   (DATA)",
            "code",
            "DSEG    (DATA)",
            "ISEG    (DATA)",
            NULL, /* pdata */
            "XSEG    (XDATA)",
            "BSEG    (BIT)",
            "RSEG    (DATA)",
            "GSINIT  (CODE)",
            "udata_ovr",
            "GSFINAL (CODE)",
            "HOME        (CODE)",
            NULL,                  // xidata
            NULL,                  // xinit
            "CONST   (CODE)",      // const_name - const data (code or not)
            "CABS    (ABS,CODE)",  // cabs_name - const absolute data (code or not)
            "XABS    (ABS,XDATA)", // xabs_name - absolute xdata
            "IABS    (ABS,DATA)",  // iabs_name - absolute data
            NULL,
            NULL,
            NULL,
            NULL,
            1, // code is read only
            1  // No fancy alignments supported.
        },
        {NULL, NULL},
        {+1, 1, 4, 1, 1, 0, 0},
        /* pic14 has an 8 bit mul */
        {
            1, FALSE},
        {mc30_emitDebuggerSymbol},
        {
            255 / 3, /* maxCount */
            3,       /* sizeofElement */
            /* The rest of these costs are bogus. They approximate */
            /* the behavior of src/SDCCicode.c 1.207 and earlier.  */
            {4, 4, 4}, /* sizeofMatchJump[] */
            {0, 0, 0}, /* sizeofRangeCompare[] */
            0,         /* sizeofSubtract */
            3,         /* sizeofDispatch */
        },
        "_",
        _mc30_init,
        _mc30_parseOptions,
        _mc30_poptions,
        NULL,
        _mc30_finaliseOptions,
        _mc30_setDefaultOptions,
        mc30_assignRegisters,
        _mc30_getRegName,
        0,
        NULL,
        _mc30_keywords,
        _mc30_genAssemblerPreamble,
        NULL, /* no genAssemblerEnd */
        _mc30_genIVT,
        NULL, // _pic14_genXINIT
        NULL, /* genInitStartup */
        _mc30_reset_regparm,
        _mc30_regparm,
        NULL, /* process a pragma */
        NULL,
        _mc30_hasNativeMulFor,
        mc30_hasExtBitOp, /* mc30_hasExtBitOp */
        mc30_oclsExpense, /* mc30_oclsExpense */
        FALSE,
        //  TRUE,       /* little endian */
        FALSE,    /* little endian - PIC code enumlates big endian */
        0,        /* leave lt */
        0,        /* leave gt */
        1,        /* transform <= to ! > */
        1,        /* transform >= to ! < */
        1,        /* transform != to !(a == b) */
        0,        /* leave == */
        FALSE,    /* No array initializer support. */
        0,        /* no CSE cost estimation yet */
        NULL,     /* no builtin functions */
        GPOINTER, /* treat unqualified pointers as "generic" pointers */
        1,        /* reset labelKey to 1 */
        1,        /* globals & local static allowed */
        0,        /* Number of registers handled in the tree-decomposition-based register allocator in SDCCralloc.hpp */
        PORT_MAGIC};
