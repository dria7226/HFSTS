// SET_HEAD, index
#ifdef INTERPRETER_MODE
SET_HEAD:
if(*temp[0] >= CAPACITY_AT(HEADS) / NUMBER_OF_HEAD_ELEMENTS)
{
  SET_FLAG(SET_HEAD_FAILED, 1)

  #ifdef CLIT
  PRINT("SET_HEAD_FAILED, %u\n",FLAG_AT(SET_HEAD_FAILED),0,0)
  #endif
    
  ADVANCE_HEAD
}

head_index = *temp[0];

#ifdef CLIT
PRINT("SET_HEAD, %u\n",head_index,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_HEAD
#endif

#ifdef LABEL_MODE
&&SET_HEAD
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
