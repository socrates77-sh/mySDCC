#ifndef MAIN_INCLUDE
#define MAIN_INCLUDE

typedef struct {
  unsigned int isLibrarySource:1;
  int disable_df;
  // zwr 2.0.0
  int no_ext_instr;
  int no_warn_non_free;
} mc35_options_t;

extern mc35_options_t mc35_options;
extern int mc35_debug_verbose;

#endif

