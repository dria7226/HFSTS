// GET_ARRAY_CAPACITY, type, array, write_to_address
#ifdef INTERPRETER_MODE
GET_ARRAY_CAPACITY:
#define CHECK_ALL_VARIABLES
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[2] = CAPACITY_AT(*temp[0], *temp[1]);

#ifdef TESTING_CLI
PRINT("GET_ARRAY_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_ARRAY_CAPACITY
#endif

#ifdef LABEL_MODE
&&GET_ARRAY_CAPACITY
#endif

#ifdef ARGUMENTS_MODE
3
#endif

#ifdef ENUMERATE
,
#endif
