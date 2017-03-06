// GET_ARRAY_CAPACITY, array, write_to_address
#ifdef INTERPRETER_MODE
GET_ARRAY_CAPACITY:
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > data_capacity))
{
  SET_FLAG(DATA_ACCESS_FAILED,3)

  #ifdef TESTING_CLI
  PRINT("GET_ARRAY_CAPACITY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

argument_index = 1;
#define CHECK_ARRAY
#define CHECK_INDEX
#include "check_arguments.c"

*temp[1] = CAPACITY_AT(AT_HEAD_OFFSET(1));

#ifdef TESTING_CLI
PRINT("GET_ARRAY_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_ARRAY_CAPACITY
#endif

#ifdef LABEL_MODE
&&GET_ARRAY_CAPACITY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
