//GO_TO_INDEX, read_from_address
#ifdef INTERPRETER_MODE
GO_TO_INDEX:
#ifdef CLIT
PRINT("GO_TO_INDEX, %u ",AT_HEAD_OFFSET(2),0,0)
#endif

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

#ifdef ENUMERATE
,
#endif
