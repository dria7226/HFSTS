// GET_ARRAY_CAPACITY, array, write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GET_ARRAY_CAPACITY:

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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
