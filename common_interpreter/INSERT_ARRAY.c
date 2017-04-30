// INSERT_ARRAY, read_from_array, write_to_array
#ifdef INTERPRETER_MODE
INSERT_ARRAY:
#ifdef CLIT
PRINT("INSERT_ARRAY, %u, %u ",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#include "check_arguments.c"

insert_array(AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2));

#ifdef CLIT
PRINT("\n",0,0,0)
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
