//GO_TO_ARRAY, read_from_address
#ifdef INTERPRETER_MODE
GO_TO_ARRAY: 
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

ARRAY_AT(head_index) = *temp[0];
INDEX_AT(head_index) = 0;
#endif

#ifdef NAME_MODE
GO_TO_ARRAY
#endif

#ifdef LABEL_MODE
&&GO_TO_ARRAY
#endif

#ifdef ARGUMENT_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
