//GO_TO_ARRAY, array, index
#ifdef INTERPRETER_MODE
GO_TO_ARRAY:
#ifdef CLIT
PRINT("GO_TO_ARRAY, %u, %u ",AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(4),0)
#endif

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

#ifdef ENUMERATE
,
#endif
