// GET_MEMORY_CAPACITY, write_to_address
#ifdef INTERPRETER_MODE
GET_MEMORY_CAPACITY:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[0] = capacity;

#ifdef CLIT
PRINT("GET_MEMORY_CAPACITY, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_MEMORY_CAPACITY
#endif

#ifdef LABEL_MODE
&&GET_MEMORY_CAPACITY
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif