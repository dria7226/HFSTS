// GET_GRANULARITY_COUNTER, write_to_address
#ifdef INTERPRETER_MODE
GET_GRANULARITY_COUNTER:
#ifdef CLIT
PRINT("GET_GRANULARITY_COUNTER, %u ",AT_HEAD_OFFSET(2),0,0)
#endif

*temp[0] = granularity_counter;

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_GRANULARITY_COUNTER
#endif

#ifdef LABEL_MODE
&&GET_GRANULARITY_COUNTER
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
