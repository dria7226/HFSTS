// GET_HEAD, write_to_address
#ifdef INTERPRETER_MODE
GET_HEAD:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[0] = head_index;

#ifdef CLIT
PRINT("GET_HEAD, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_HEAD
#endif

#ifdef LABEL_MODE
&&GET_HEAD
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
