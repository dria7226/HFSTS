// GET_ARRAY_CAPACITY, array, write_to_address
#ifdef INTERPRETER_MODE
GET_ARRAY_CAPACITY:
#ifdef CLIT
PRINT("GET_ARRAY_CAPACITY, %u, %u ",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif
#define CHECK_ARRAY
#include "check_arguments.c"

argument_index++;
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[1] = CAPACITY_AT(AT_HEAD_OFFSET(1));

#ifdef CLIT
PRINT("\n",0,0,0)
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
2
#endif

#ifdef ENUMERATE
,
#endif
