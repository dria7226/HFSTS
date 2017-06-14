// GET_MEMORY_CAPACITY, write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GET_MEMORY_CAPACITY:

*temp[0] = capacity;

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_MEMORY_CAPACITY
#endif

#ifdef LABEL_MODE
&&GET_MEMORY_CAPACITY
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
