// REMAINDER, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
REMAINDER:
#define CHECK_ALL_ARGUMENTS
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

if(MATH_FAILSAFE_AT(head_index) && (*temp[0] == 0))
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef TESTING_CLI
  PRINT("REMAINDER: %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)
  #endif

  ADVANCE_HEAD
}

*temp[1] %= *temp[0];

#ifdef TESTING_CLI
PRINT("REMAINDER, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *temp[1])
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
REMAINDER
#endif

#ifdef LABEL_MODE
&&REMAINDER
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
