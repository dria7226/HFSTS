// SET_SOURCE , array
#ifdef INTERPRETER_MODE
SET_SOURCE:
#define CHECK_ARRAY
#define CHECK_INDEX
#include "check_arguments"

SOURCE_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
PRINT("SET_SOURCE, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_SOURCE
#endif

#ifdef LABEL_MODE
&&SET_SOURCE
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
