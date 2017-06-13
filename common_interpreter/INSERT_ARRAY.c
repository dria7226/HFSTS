// INSERT_ARRAY, read_from_array, write_to_array
#ifdef INTERPRETER_MODE
INSERT_ARRAY:
#ifdef CLIT
PRINT("INSERT_ARRAY, %u, %u",AT_HEAD_OFFSET(2),AT_HEAD_OFFSET(4),0)
#endif

insert_array(*temp[0], *temp[1]);

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
INSERT_ARRAY
#endif

#ifdef LABEL_MODE
&&INSERT_ARRAY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
