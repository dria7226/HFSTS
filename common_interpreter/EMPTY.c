//EMPTY
#ifdef INTERPRETER_MODE
EMPTY:
ADVANCE_HEAD
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
