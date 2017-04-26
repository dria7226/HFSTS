//GO_TO_ARRAY, array, index
#ifdef INTERPRETER_MODE
GO_TO_ARRAY:
#define CHECK_ARRAY
#define SET_VARIABLES
#include "check_arguments.c"

ARRAY_AT(head_index) = *temp[0];
INDEX_AT(head_index) = *temp[1];
#endif

#ifdef NAME_MODE
GO_TO_ARRAY
#endif

#ifdef LABEL_MODE
&&GO_TO_ARRAY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
