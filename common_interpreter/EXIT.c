//EXIT
#ifdef INTERPRETER_MODE
EXIT:
goto out;
#endif

#ifdef NAME_MODE
EXIT
#endif

#ifdef LABEL_MODE
&&EXIT
#endif

#ifdef ARGUMENTS_MODE
0
#endif

#ifdef ENUMERATE
,
#endif
