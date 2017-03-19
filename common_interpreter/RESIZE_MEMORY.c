// RESIZE_MEMORY, capacity
#ifdef INTERPRETER_MODE
RESIZE_MEMORY:
*temp[0] = resize_memory(AT_HEAD_OFFSET(1));

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(MEMORY_RESIZE_FAILED, *temp[0])

  #ifdef TESTING_CLI
  if(FLAG_AT(MEMORY_RESIZE_FAILED) == 0)
  {
    PRINT("RESIZE_MEMORY, %u\n",AT_HEAD_OFFSET(1),0,0)
  }
  else
  PRINT("RESIZE_MEMORY, %s: %s\n",error_titles[MEMORY_RESIZE_FAILED-3],error_messages[FLAG_AT(MEMORY_RESIZE_FAILED)-1],0)
  #endif
}

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
RESIZE_MEMORY
#endif

#ifdef LABEL_MODE
&&RESIZE_MEMORY
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif

