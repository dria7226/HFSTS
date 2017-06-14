// INSERT_ARRAY, read_from_array, write_to_array
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
INSERT_ARRAY:

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

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
