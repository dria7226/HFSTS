//EMPTY
#ifdef INTERPRETER_MODE
EMPTY:
HEAD_AT(head_index)++;
goto next_instruction;
#endif

#ifdef NAME_MODE
EMPTY
#endif

#ifdef LABEL_MODE
&&EMPTY
#endif

#ifdef ARGUMENTS_MODE
0
#endif

#ifdef ENUMERATE
,
#endif
