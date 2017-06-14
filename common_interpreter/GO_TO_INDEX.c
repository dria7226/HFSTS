//GO_TO_INDEX, read_from_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GO_TO_INDEX:

INDEX_AT(head_index) = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

goto next_instruction;
#endif

#ifdef NAME_MODE
GO_TO_INDEX
#endif

#ifdef LABEL_MODE
&&GO_TO_INDEX
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
