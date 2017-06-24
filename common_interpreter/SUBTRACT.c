#define NAME SUBTRACT
#define ARGUMENTS 2

#define IMPLEMENTATION				\
if(MATH_FAILSAFE_AT(head_index))     	      	\
{								\
  SET_FLAG(UNDERFLOW, (*temp[1] < (*temp[1] - *temp[0])) )	\
}       							\
								\
*temp[1] -= *temp[0];

#define CLIT_1				       			\
PRINT("= %u\n",*temp[1],0,0)					\
if( FLAG_AT(UNDERFLOW) ) {PRINT("The subtraction underflowed.\n",0,0,0)}

#include "core_program_template.c"
