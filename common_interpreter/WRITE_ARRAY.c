//WRITE_ARRAY, array, address_buffer_index
#ifdef INTERPRETER_MODE
WRITE_ARRAY:
#define CHECK_ARRAY
#define SET_VARIABLES
#include "check_arguments.c"

argument_index++;
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[2] = write_array(*temp[0], *temp[1]);

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
WRITE_ARRAY
#endif

#ifdef LABEL_MODE
&&WRITE_ARRAY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
