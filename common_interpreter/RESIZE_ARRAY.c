// RESIZE_ARRAY, array, capacity
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
RESIZE_ARRAY:

*temp[0] = resize_array(*temp[0], *temp[1]);

SET_FLAG(ARRAY_RESIZE_FAILED, *temp[0])

#ifdef CLIT
if(FLAG_AT(ARRAY_RESIZE_FAILED))
{
  PRINT("%s: %s",error_titles[ARRAY_RESIZE_FAILED-3],error_messages[FLAG_AT(ARRAY_RESIZE_FAILED)-1],0)
}
PRINT("\n",0,0,0)
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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
