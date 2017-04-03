//EMPTY
#ifdef INTERPRETER_MODE
EMPTY:

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

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
