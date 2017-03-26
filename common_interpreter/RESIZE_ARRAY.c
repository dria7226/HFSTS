// RESIZE_ARRAY, array, capacity
#ifdef INTERPRETER_MODE
RESIZE_ARRAY:
#define CHECK_ARRAY
#define SET_VARIABLES
#include "check_arguments.c"

*temp[2] = resize_array(*temp[0], AT_HEAD_OFFSET(2));

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(ARRAY_RESIZE_FAILED, *temp[2])

  #ifdef CLIT
  {
    PRINT("RESIZE_ARRAY: %s: %s\n",error_titles[ARRAY_RESIZE_FAILED-3],error_messages[FLAG_AT(ARRAY_RESIZE_FAILED)-1],0)
  }
  #endif

  ADVANCE_HEAD
}

#ifdef CLIT
PRINT("RESIZE_ARRAY, %u, %u \n",AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
RESIZE_ARRAY
#endif

#ifdef LABEL_MODE
&&RESIZE_ARRAY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
