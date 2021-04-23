#define NAME OR
#define ARGUMENTS 2

#define IMPLEMENTATION_1				\
*temp[1] |= *temp[0];

#define CLIT_1				       	\
PRINT("= %u\n",*temp[1],0,0)

#include "../instruction_template.c"
