#define NAME REMAINDER
#define ARGUMENTS 2

#define IMPLEMENTATION					\
if(MATH_FAILSAFE_AT(head_index) && (*temp[0] == 0))	\
{							\
 SET_FLAG(DIVISION_BY_ZERO,1)

#define CLIT_1						\
PRINT(" %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)

#define IMPLEMENTATION_2				\
  ADVANCE_HEAD						\
}							\
*temp[1] %= *temp[0];			       		

#define CLIT_2						\
PRINT("= %u\n",*temp[1],0,0)				

#include "core_program_template.c"
