// OR, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
XOR:
#ifdef CLIT
PRINT("XOR, %u, %u ",AT_HEAD_OFFSET(0), AT_HEAD_OFFSET(1),0)
#endif

*temp[1] ^= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
XOR
#endif

#ifdef LABEL_MODE
&&XOR
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
