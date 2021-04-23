#define NAME GET_ARRAY_CAPACITY
#define ARGUMENTS 2

#define IMPLEMENTATION_1				\
  *temp[1] = CAPACITY_AT(*temp[0]);

#define CLIT_1					\
PRINT("\n",0,0,0)

#include "../instruction_template.c"
