// SET_FAILSAFE_TYPE, read_from_address
#ifdef INTERPRETER_MODE
SET_FAILSAFE_TYPE:
#ifdef CLIT
PRINT("SET_FAILSAFE_TYPE, %u ",AT_HEAD_OFFSET(1),0,0)
#endif
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

FAILSAFE_AT(head_index) = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_FAILSAFE_TYPE
#endif

#ifdef LABEL_MODE
&&SET_FAILSAFE_TYPE
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
