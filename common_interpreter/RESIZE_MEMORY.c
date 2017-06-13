// RESIZE_MEMORY, capacity
#ifdef INTERPRETER_MODE
RESIZE_MEMORY:
*temp[1] = resize_memory(*temp[0]);

SET_FLAG(MEMORY_RESIZE_FAILED, *temp[1])

#ifdef CLIT
PRINT("RESIZE_MEMORY, %u ",AT_HEAD_OFFSET(2),0,0)
if(FLAG_AT(MEMORY_RESIZE_FAILED))
{
  PRINT("%s: %s",error_titles[MEMORY_RESIZE_FAILED-3],error_messages[FLAG_AT(MEMORY_RESIZE_FAILED)-1],0)
}
PRINT("\n",0,0,0)
#endif

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
