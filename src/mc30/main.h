#ifndef MAIN_INCLUDE
#define MAIN_INCLUDE

typedef struct {
  unsigned int isLibrarySource:1;
  int disable_df;
  // zwr 2.0.0
  int no_ext_instr;
  int no_warn_non_free;
} mc30_options_t;

extern mc30_options_t mc30_options;
extern int mc30_debug_verbose;

// zwr 1.1.0
extern int mc30_fl_mode;
extern int mc30_start_addr;  

#endif

