// AND, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
AND:
#ifdef CLIT
PRINT("AND, %u, %u ",AT_HEAD_OFFSET(2),AT_HEAD_OFFSET(4),0)
#endif

*temp[1] &= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
AND
#endif

#ifdef LABEL_MODE
&&AND
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
