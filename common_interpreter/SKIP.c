// SKIP, read_from_address
#ifdef INTERPRETER_MODE
SKIP:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

#ifdef TESTING_CLI
PRINT("SKIP, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

INDEX_AT(head_index) += *temp[0];

goto next_instruction;
#endif

#ifdef NAME_MODE
SKIP
#endif

#ifdef LABEL_MODE
&&SKIP
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
