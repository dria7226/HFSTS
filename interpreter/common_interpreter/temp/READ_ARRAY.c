//READ_ARRAY, buffer_index, index, amount
#ifdef INTERPRETER_MODE
READ_ARRAY:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

argument_index++;
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

file = OPEN((char*)(memory[PRIMARY_AT(head_index)].data + *temp[0]), "rb")
READ_ARRAY(*temp[1], SECONDARY_AT(head_index), AT_HEAD_OFFSET(3))
CLOSE(file)

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
READ_ARRAY
#endif

#ifdef LABEL_MODE
&&READ_ARRAY
#endif

#ifdef ARGUMENTS_MODE
3
#endif

#ifdef ENUMERATE
,
#endif
