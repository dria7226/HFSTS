// INSERT_ARRAY, write_to_address, read_from_address
#ifdef INTERPRETER_MODE
INSER_ARRAY:
#define EXCLUDE_CONSTANTS
#define CHECK_ALL_ARGUMENTS
#define CHECK_ARRAY
#include "check_arguments.c"



#ifdef TESTING_CLI
PRINT("INSERT_ARRAY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
PRINT("IMPLEMENT INSERT_ARRAY!!!\n",0,0,0)
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
