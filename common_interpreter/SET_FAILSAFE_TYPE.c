// SET_FAILSAFE_TYPE, read_from_address
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
SET_FAILSAFE_TYPE:

FAILSAFE_AT(head_index) = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_FAILSAFE_TYPE
#endif

#ifdef LABEL_MODE
&&SET_FAILSAFE_TYPE
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
