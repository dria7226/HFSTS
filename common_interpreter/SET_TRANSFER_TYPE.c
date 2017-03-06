// SET_TRANSFER_TYPE, 0xdeadbeef
#ifdef INTERPRETER_MODE
SET_TRANSFER_TYPE:
#define CHECK_ARRAY
#define CHECK_INDEX
#include "check_arguments"

HEAD_ELEMENT_AT(head_index, TRANSFER_TYPE) = *temp[0];

#ifdef TESTING_CLI
PRINT("SET_TRANSFER_TYPE, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_TRANSFER_TYPE
#endif

#ifdef LABEL_MODE
&&SET_TRANSFER_TYPE
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
