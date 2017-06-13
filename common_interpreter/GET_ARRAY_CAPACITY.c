// GET_ARRAY_CAPACITY, array, write_to_address
#ifdef INTERPRETER_MODE
GET_ARRAY_CAPACITY:
#ifdef CLIT
PRINT("GET_ARRAY_CAPACITY, %u, %u ",AT_HEAD_OFFSET(2),AT_HEAD_OFFSET(4),0)
#endif

*temp[1] = CAPACITY_AT(*temp[0]);

#ifdef CLIT
PRINT("\n",0,0,0)
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
