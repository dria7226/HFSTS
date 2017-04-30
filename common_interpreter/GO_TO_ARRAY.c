//GO_TO_ARRAY, array, index
#ifdef INTERPRETER_MODE
GO_TO_ARRAY:
#define CHECK_ARRAY
#include "check_arguments.c"

#define CHECK_INDEX
#include "check_arguments.c"

ARRAY_AT(head_index) = AT_HEAD_OFFSET(1);
INDEX_AT(head_index) = AT_HEAD_OFFSET(2);

#ifdef CLIT
PRINT("GO_TO_ARRAY, %u, %u\n",ARRAY_AT(head_index),INDEX_AT(head_index),0)
#endif

goto next_instruction;
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
