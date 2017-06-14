// SUBTRACT, read_from_address , write_to_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
SUBTRACT:

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(UNDERFLOW, (*temp[1] < (*temp[1] - *temp[0])) )
}

*temp[1] -= *temp[0];

#ifdef CLIT
PRINT("= %u\n",*temp[1],0,0)
if( FLAG_AT(UNDERFLOW) ) PRINT("The subtraction underflowed.\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SUBTRACT
#endif

#ifdef LABEL_MODE
&&SUBTRACT
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
