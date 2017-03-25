//LOGICAL_SHIFT, write_to_address, amount, direction
#ifdef INTERPRETER_MODE
LOGICAL_SHIFT:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

if(AT_HEAD_OFFSET(3))
  *temp[0] <<= AT_HEAD_OFFSET(2);
else
  *temp[0] >>= AT_HEAD_OFFSET(2);

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
