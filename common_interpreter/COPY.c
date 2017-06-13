// COPY , read_from_address , write_to_address
#ifdef INTERPRETER_MODE
COPY:
#ifdef CLIT
PRINT("COPY, %u, %u ",AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(4),0)
#endif

*temp[1] = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
COPY
#endif

#ifdef LABEL_MODE
&&COPY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
