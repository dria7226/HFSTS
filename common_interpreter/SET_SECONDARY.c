// SET_SECONDARY , array
#ifdef INTERPRETER_MODE
SET_SECONDARY:
#ifdef CLIT
PRINT("SET_SECONDARY, %u ", AT_HEAD_OFFSET(1),0,0)
#endif
#define CHECK_ARRAY
#include "check_arguments.c"

SECONDARY_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_SECONDARY
#endif

#ifdef LABEL_MODE
&&SET_SECONDARY
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif