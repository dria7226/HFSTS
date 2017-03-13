// MULTIPLY, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
MULTIPLY:
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_ARGUMENTS
#include "check_arguments.c"

*temp[2] = *temp[0] * *temp[1];

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, ( *temp[1] != 0 && *temp[2] / *temp[1] != *temp[0] ))
}

*temp[1] = *temp[2];

#ifdef TESTING_CLI
PRINT("MULTIPLY, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *temp[1])
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
