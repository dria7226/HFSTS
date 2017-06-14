// GET_GRANULARITY_COUNTER, write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GET_GRANULARITY_COUNTER:

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

#ifdef
"
#endif

#ifdef ENUMERATE
,
#endif
