// DIVIDE , write_to_address, read_from_address
#ifdef INTERPRETER_MODE
DIVIDE:
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_ARGUMENTS
#include "check_arguments.c"

*temp[1] /= *temp[0];

#ifdef TESTING_CLI
PRINT("DIVIDE, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *temp[1])
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
DIVIDE
#endif

#ifdef LABEL_MODE
&&DIVIDE
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
