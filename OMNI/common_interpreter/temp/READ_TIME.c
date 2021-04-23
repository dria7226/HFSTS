//READ_TIME, write_to_address
#ifdef INTERPRETER_MODE
READ_TIME:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

READ_TIME(*temp[0])

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
READ_TIME
#endif

#ifdef LABEL_MODE
&&READ_TIME
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
