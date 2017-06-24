#define NAME SET_HEAD
#define ARGUMENTS 1

#define IMPLEMENTATION						\
if(*temp[0] >= CAPACITY_AT(HEADS) / NUMBER_OF_HEAD_ELEMENTS)	\
{								\
  SET_FLAG(SET_HEAD_FAILED, 1)

#define CLIT_1							\
  PRINT("SET_HEAD_FAILED, %u\n",FLAG_AT(SET_HEAD_FAILED),0,0)

#define IMPLEMENTATION_2					\
  ADVANCE_HEAD  						\
}								\
								\
head_index = *temp[0];

#define CLIT_2                					\
PRINT(", %u\n",head_index,0,0)

#include "core_program_template.c"
