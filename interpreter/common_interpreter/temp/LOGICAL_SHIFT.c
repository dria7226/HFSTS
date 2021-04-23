#define NAME LOGICAL_SHIFT
#define ARGUMENTS 3

#define IMPLEMENTATION_1				\
if(*temp[2])					\
  *temp[0] <<= *temp[1];			\
else						\
  *temp[0] >>= *temp[1];

#define CLIT_1					\
PRINT("= %u\n",*temp[0],0,0)

#include "../instruction_template.c"
