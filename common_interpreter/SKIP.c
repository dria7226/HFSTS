// SKIP, amount
#ifdef INTERPRETER_MODE
SKIP:
#ifdef CLIT
PRINT("SKIP, %u\n", AT_HEAD_OFFSET(2),0,0)
#endif

INDEX_AT(head_index) += *temp[0];

goto next_instruction;
#endif

#ifdef NAME_MODE
SKIP
#endif

#ifdef LABEL_MODE
&&SKIP
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
