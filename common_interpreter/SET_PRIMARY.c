// SET_PRIMARY , array
#ifdef INTERPRETER_MODE
SET_PRIMARY:
#ifdef CLIT
PRINT("SET_PRIMARY, %u ",AT_HEAD_OFFSET(2),0,0)
#endif

PRIMARY_AT(head_index) = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
SET_PRIMARY
#endif

#ifdef LABEL_MODE
&&SET_PRIMARY
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
