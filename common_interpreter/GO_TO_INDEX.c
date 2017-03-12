//GO_TO_INDEX, read_from_address
#ifdef INTERPRETER_MODE
GO_TO_INDEX: 
#define CHECK_ARRAY
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

INDEX_AT(head_index) = *temp[0];
#endif

#ifdef NAME_MODE
GO_TO_INDEX
#endif

#ifdef LABEL_MODE
&&GO_TO_INDEX
#endif

#ifdef ARGUMENT_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
