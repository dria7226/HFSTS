// SET_DESTINATION , array
#ifdef INTERPRETER_MODE
SET_DESTINATION:
#define CHECK_ARRAY
#define CHECK_INDEX
#include "check_arguments.c"

DESTINATION_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
PRINT("SET_DESTINATION, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_DESTINATION
#endif

#ifdef LABEL_MODE
&&SET_DESTINATION
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
