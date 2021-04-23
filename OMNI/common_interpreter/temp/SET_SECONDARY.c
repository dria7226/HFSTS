#define NAME SET_SECONDARY
#define ARGUMENTS 1

#define IMPLEMENTATION_1	       			\
SECONDARY_AT(head_index) = *temp[0];

#define CLIT_1					\
PRINT("\n",0,0,0)

#include "../instruction_template.c"
