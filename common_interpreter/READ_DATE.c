//READ_DATE, write_to_address
#ifdef INTERPRETER_MODE
READ_DATE:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

*temp[0] = read_date();

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
READ_DATE
#endif

#ifdef LABEL_MODE
&&READ_DATE
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
