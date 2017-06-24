#define NAME NOT
#define ARGUMENTS 1

#define IMPLEMENTATION				\
  *temp[0] = ~*temp[0];				

#define CLIT_1				       	\
PRINT("= %u\n",*temp[0],0,0)

#include "core_program_template.c"
