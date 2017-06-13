// ADD , read_from__address , write_to_address
#ifdef INTERPRETER_MODE
ADD:
#ifdef CLIT
PRINT("ADD, %u, %u ", AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(4),0)
#endif

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, *temp[1] > (*temp[1] + *temp[0]))
}

*temp[1] += *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
if(FLAG_AT(OVERFLOW))
{
  PRINT("The addition overflowed.\n",0,0,0)
}
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
ADD
#endif

#ifdef LABEL_MODE
&&ADD
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
