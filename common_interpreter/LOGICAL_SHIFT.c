//LOGICAL_SHIFT, write_to_address, amount, direction
#ifdef INTERPRETER_MODE
LOGICAL_SHIFT:

argument_index = 0;

#define CHECK_ARRAY
#define CHECK_INDEX
#include "check_arguments.c"

if(AT_HEAD_OFFSET(2))
  *temp[0] <<= *temp[1];
else
  *temp[0] >>= *temp[1];

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
LOGICAL_SHIFT
#endif

#ifdef LABEL_MODE
&&LOGICAL_SHIFT
#endif

#ifdef ARGUMENTS_MODE
3
#endif

#ifdef ENUMERATE
,
#endif