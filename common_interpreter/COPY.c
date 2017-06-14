// COPY , read_from_address , write_to_address
#ifdef INTERPRETER_MODE
COPY:
#ifdef CLIT
PRINT("COPY, %s, %u ", index_type_text[AT_HEAD_OFFSET(1)], AT_HEAD_OFFSET(1*NUMBER_OF_DATA_PER_ARGUMENT),0)
PRINT(" %s, %u", index_type_text[AT_HEAD_OFFSET(2*NUMBER_OF_DATA_PER_ARGUMENT - 1)], AT_HEAD_OFFSET(2*NUMBER_OF_DATA_PER_ARGUMENT),0)
#endif

*temp[1] = *temp[0];

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
COPY
#endif

#ifdef LABEL_MODE
&&COPY
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
