// SKIP, amount
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
SKIP:

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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
