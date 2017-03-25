// COPY , read_from_address , write_to_address
#ifdef INTERPRETER_MODE
COPY:
#define CHECK_ALL_ARGUMENTS
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[1] = *temp[0];

#ifdef TESTING_CLI
PRINT("COPY, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
COPY
#endif

#ifdef LABEL_MODE
&&COPY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
