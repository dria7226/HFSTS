// OR, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
OR:
#define CHECK_ALL_ARGUMENTS
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[1] |= *temp[0];

#ifdef TESTING_CLI
PRINT("OR, %u, %u = %u\n",AT_HEAD_OFFSET(0), AT_HEAD_OFFSET(1),*temp[1])
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
