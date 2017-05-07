//NOT, read_from_address
#ifdef INTERPRETER_MODE
NOT:
#ifdef CLIT
PRINT("NOT, %u ",AT_HEAD_OFFSET(1),0,0)
#endif
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[0] = ~*temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[0],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
NOT
#endif

#ifdef LABEL_MODE
&&NOT
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
