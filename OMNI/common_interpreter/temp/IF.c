#define NAME IF
#define ARGUMENTS 1

#define IMPLEMENTATION_2		       	\
if(*temp[0])					\
{	       					\
  ADVANCE_HEAD  				\
}        					\
else						\
{					       	\
 INDEX_AT(head_index) += 1 + core_instructions_arguments[AT_HEAD_OFFSET(0)]; /*ADVANCE_HEAD once, but don't execute*/\
 ADVANCE_HEAD								\
}

#define CLIT_1					\
PRINT("\n",0,0,0)
  
#include "../instruction_template.c"
