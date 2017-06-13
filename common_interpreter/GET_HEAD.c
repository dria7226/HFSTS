// GET_HEAD, write_to_address
#ifdef INTERPRETER_MODE
GET_HEAD:
#ifdef CLIT
PRINT("GET_HEAD, %u ",AT_HEAD_OFFSET(2),0,0)
#endif

*temp[0] = head_index;

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_HEAD
#endif

#ifdef LABEL_MODE
&&GET_HEAD
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
