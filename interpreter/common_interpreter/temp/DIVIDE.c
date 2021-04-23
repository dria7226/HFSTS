#define NAME DIVIDE
#define ARGUMENTS 2

#define IMPLEMENTATION_1					\
if(*temp[0] == 0)	\
{							\
  SET_FLAG(DIVISION_BY_ZERO,1)

#define CLIT_1						\
  PRINT(" %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)

#define IMPLEMENTATION_2			        \
  ADVANCE_HEAD                                          \
}							\
							\
*temp[1] /= *temp[0];

#define CLIT_2					        \
PRINT("= %u\n",*temp[1],0,0)

#include "../instruction_template.c"
