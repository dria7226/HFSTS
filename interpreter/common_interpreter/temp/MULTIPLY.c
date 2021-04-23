#define NAME MULTIPLY
#define ARGUMENTS 2

#define IMPLEMENTATION_1				\
*temp[2] = *temp[0] * *temp[1];  		\
\
SET_FLAG(OVERFLOW, ( *temp[1] != 0 && *temp[2] / *temp[1] != *temp[0] )) \
\
*temp[1] = *temp[2];

#define CLIT_1								\
PRINT("= %u\n",*temp[1],0,0)

#include "../instruction_template.c"
