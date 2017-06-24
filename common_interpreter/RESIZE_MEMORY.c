#define NAME RESIZE_MEMORY
#define ARGUMENTS 1

#define IMPLEMENTATION				\
*temp[1] = resize_memory(*temp[0]);		\
						\
SET_FLAG(MEMORY_RESIZE_FAILED, *temp[1])

#define CLIT_1					\
if(FLAG_AT(MEMORY_RESIZE_FAILED))		\
{						\
  PRINT("%s: %s",error_titles[MEMORY_RESIZE_FAILED-3],error_messages[FLAG_AT(MEMORY_RESIZE_FAILED)-1],0) \
}        					\
PRINT("\n",0,0,0)

#include "core_program_template.c"
