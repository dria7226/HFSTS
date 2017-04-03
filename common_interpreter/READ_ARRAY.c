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

file = fopen((char*)(memory[SOURCE_AT(head_index)].data + *temp[0]),"rb");
READ_ARRAY(*temp[1], AT_HEAD_OFFSET(3))
fclose(file);

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
