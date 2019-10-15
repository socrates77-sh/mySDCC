#ifndef MAIN_INCLUDE
#define MAIN_INCLUDE

typedef struct {
  unsigned int isLibrarySource:1;
  int disable_df;
  // zwr 2.0.0
  int no_ext_instr;
  int no_warn_non_free;
} mc32_options_t;

extern mc32_options_t mc32_options;
extern int mc32_debug_verbose;
extern int mc32_long_call;        // zwr 1.1.0

#endif

