//NOT, read_from_address
#ifdef INTERPRETER_MODE
NOT:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

~*temp[0];

#ifdef CLIT
PRINT("NOT, %u,\n",AT_HEAD_OFFSET(1),0,0)
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
