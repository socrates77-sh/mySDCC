#ifndef MAIN_INCLUDE
#define MAIN_INCLUDE

typedef struct {
  unsigned int isLibrarySource:1;
  int disable_df;
} mc35_options_t;

extern mc35_options_t mc35_options;
extern int debug_verbose;

#endif

