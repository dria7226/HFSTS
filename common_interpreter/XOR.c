// OR, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
XOR:
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_ARGUMENTS
#include "check_arguments.c"

*temp[1] ^= *temp[0];

#ifdef TESTING_CLI
PRINT("XOR, %u, %u = %u\n",AT_HEAD_OFFSET(0), AT_HEAD_OFFSET(1),*temp[1])
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
XOR
#endif

#ifdef LABEL_MODE
&&XOR
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
