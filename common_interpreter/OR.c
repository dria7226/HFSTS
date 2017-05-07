// OR, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
OR:
#ifdef CLIT
PRINT("OR, %u, %u ",AT_HEAD_OFFSET(0), AT_HEAD_OFFSET(1),0)
#endif
#define CHECK_ALL_ARGUMENTS
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[1] |= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif


ADVANCE_HEAD
#endif

#ifdef NAME_MODE
OR
#endif

#ifdef LABEL_MODE
&&OR
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
