// SET_FAILSAFE_TYPE, 0xdeadbeef
#ifdef INTERPRETER_MODE
SET_FAILSAFE_TYPE:
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

FAILSAFE_AT(head_index) = *temp[0];

#ifdef TESTING_CLI
PRINT("SET_FAILSAFE_TYPE, %u\n",AT_HEAD_OFFSET(1),0,0)
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
