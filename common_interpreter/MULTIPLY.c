// MULTIPLY, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
MULTIPLY:
#ifdef CLIT
PRINT("MULTIPLY, %u, %u ", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif
#define CHECK_ALL_ARGUMENTS
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[2] = *temp[0] * *temp[1];

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, ( *temp[1] != 0 && *temp[2] / *temp[1] != *temp[0] ))
}

*temp[1] = *temp[2];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
MULTIPLY
#endif

#ifdef LABEL_MODE
&&MULTIPLY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
