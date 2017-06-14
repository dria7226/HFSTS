// GET_HEAD, write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GET_HEAD:

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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
