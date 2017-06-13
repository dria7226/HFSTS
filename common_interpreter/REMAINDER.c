// REMAINDER, read_from_address, write_to_address
#ifdef INTERPRETER_MODE
REMAINDER:
#ifdef CLIT
PRINT("REMAINDER, %u, %u ", AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(4),0)
#endif

if(MATH_FAILSAFE_AT(head_index) && (*temp[0] == 0))
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef CLIT
  PRINT("REMAINDER: %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)
  #endif

  ADVANCE_HEAD
}

*temp[1] %= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
REMAINDER
#endif

#ifdef LABEL_MODE
&&REMAINDER
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
