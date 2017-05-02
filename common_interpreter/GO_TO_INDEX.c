//GO_TO_INDEX, read_from_address
#ifdef INTERPRETER_MODE
GO_TO_INDEX:
#ifdef CLIT
PRINT("GO_TO_INDEX, %u ",INDEX_AT(head_index),0,0)
#endif
#define CHECK_INDEX
#include "check_arguments.c"

INDEX_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

goto next_instruction;
#endif

#ifdef NAME_MODE
GO_TO_INDEX
#endif

#ifdef LABEL_MODE
&&GO_TO_INDEX
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
