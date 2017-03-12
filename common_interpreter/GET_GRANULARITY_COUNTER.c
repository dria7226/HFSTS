// GET_GRANULARITY_COUNTER, write_to_address
#ifdef INTERPRETER_MODE
GET_GRANULARITY_COUNTER:
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[0] = granularity_counter;

#ifdef TESTING_CLI
PRINT("GET_GRANULARITY_COUNTER, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_GRANULARITY_COUNTER
#endif

#ifdef LABEL_MODE
&&GET_GRANULARITY_COUNTER
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
