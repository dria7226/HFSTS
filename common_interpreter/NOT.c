//NOT, read_from_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
NOT:

*temp[0] = ~*temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[0],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
NOT
#endif

#ifdef LABEL_MODE
&&NOT
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
