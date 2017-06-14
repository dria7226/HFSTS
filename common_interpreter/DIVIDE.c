// DIVIDE , write_to_address, read_from_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
DIVIDE:

if(MATH_FAILSAFE_AT(head_index) && (*temp[0] == 0))
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef CLIT
  PRINT("DIVIDE: %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)
  #endif

  ADVANCE_HEAD
}

*temp[1] /= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
DIVIDE
#endif

#ifdef LABEL_MODE
&&DIVIDE
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
