//LOGICAL_SHIFT, write_to_address, amount, direction
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
LOGICAL_SHIFT:

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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
