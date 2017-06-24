#define NAME SET_SECONDARY
#define ARGUMENTS 1

#define IMPLEMENTATION	       			\
SECONDARY_AT(head_index) = *temp[0];

#define CLIT_1					\
PRINT("\n",0,0,0)

#include "core_program_template.c"
