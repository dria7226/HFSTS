//GO_TO_ARRAY, array, index
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
GO_TO_ARRAY:

ARRAY_AT(head_index) = *temp[0];
INDEX_AT(head_index) = *temp[1];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

goto next_instruction;
#endif

#ifdef NAME_MODE
GO_TO_ARRAY
#endif

#ifdef LABEL_MODE
&&GO_TO_ARRAY
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
