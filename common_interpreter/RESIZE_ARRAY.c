// RESIZE_ARRAY, type, array_index, capacity
#ifdef INTERPRETER_MODE
RESIZE_ARRAY:
#define CHECK_ARRAY
#define SET_VARIABLES
#include "check_arguments.c"

*temp[3] = resize_array(*temp[0], *temp[1], *temp[2]);

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(ARRAY_RESIZE_FAILED, *temp[3])

  #ifdef TESTING_CLI
  if(FLAG_AT(ARRAY_RESIZE_FAILED) == 0)
  {
    PRINT("RESIZE_ARRAY, %u, %u \n",AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
  }
  else
  PRINT("RESIZE_ARRAY: %s: %s\n",error_titles[ARRAY_RESIZE_FAILED-3],error_messages[FLAG_AT(ARRAY_RESIZE_FAILED)-1],0)
  #endif
}

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
RESIZE_ARRAY
#endif

#ifdef LABEL_MODE
&&RESIZE_ARRAY
#endif

#ifdef ARGUMENTS_MODE
3
#endif

#ifdef ENUMERATE
,
#endif
