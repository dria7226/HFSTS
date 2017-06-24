#define NAME GET_GRANULARITY_COUNTER
#define ARGUMENTS 1

#define IMPLEMENTATION				\
*temp[0] = granularity_counter;

#define CLIT_1					\
PRINT("\n",0,0,0)

#include "core_program_template.c"
