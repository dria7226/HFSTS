#define NAME RESIZE_ARRAY
#define ARGUMENTS 2

#define IMPLEMENTATION_1				\
*temp[0] = resize_array(*temp[0], *temp[1]);	\
						\
SET_FLAG(ARRAY_RESIZE_FAILED, *temp[0])

#define CLIT_1				       	\
if(FLAG_AT(ARRAY_RESIZE_FAILED))		\
{						\
  PRINT("%s: %s",error_titles[ARRAY_RESIZE_FAILED-3],error_messages[FLAG_AT(ARRAY_RESIZE_FAILED)-1],0)\
}        					\
PRINT("\n",0,0,0)

#include "../instruction_template.c"
