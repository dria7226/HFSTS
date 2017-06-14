// OR, read_from_address, write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
OR:

*temp[1] |= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif


ADVANCE_HEAD
#endif

#ifdef NAME_MODE
OR
#endif

#ifdef LABEL_MODE
&&OR
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
