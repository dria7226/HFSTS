//LOGICAL_SHIFT, write_to_address, amount, direction
#ifdef INTERPRETER_MODE
LOGICAL_SHIFT:
#ifdef CLIT
PRINT("LOGICAL_SHIFT, %u, %u, %u ",AT_HEAD_OFFSET(2),AT_HEAD_OFFSET(4),AT_HEAD_OFFSET(6))
#endif

if(*temp[2])
  *temp[0] <<= *temp[1];
else
  *temp[0] >>= *temp[1];

#ifdef CLIT
PRINT("= %u\n",*temp[0],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
LOGICAL_SHIFT
#endif

#ifdef LABEL_MODE
&&LOGICAL_SHIFT
#endif

#ifdef ARGUMENTS_MODE
3
#endif

#ifdef ENUMERATE
,
#endif
