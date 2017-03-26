// INSERT_ARRAY, read_from_array, write_to_array
#ifdef INTERPRETER_MODE
INSERT_ARRAY:
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#define SET_VARIABLES
#include "check_arguments.c"

insert_array(*temp[0], *temp[1]);

#ifdef CLIT
PRINT("INSERT_ARRAY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
INSERT_ARRAY
#endif

#ifdef LABEL_MODE
&&INSERT_ARRAY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
