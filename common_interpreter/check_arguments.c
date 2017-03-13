#ifdef EXCLUDE_CONSTANTS
if(TRANSFER_TYPE_AT(head_index, WRITE_TO) == CONSTANT || TRANSFER_TYPE_AT(head_index, READ_FROM) == CONSTANT)
{
  SET_FLAG(CONSTANT_TRANFSER_TYPE_NOT_APPLICABLE, 1)
  
  #ifdef TESTING_CLI
  PRINT("CONSTANT_TRANSFER_TYPE_NOT_APPLICABLE.\n",0,0,0)
  #endif
  
  ADVANCE_HEAD
}
#endif

#ifdef CHECK_ALL_ARGUMENTS
while(argument_index < DATA_AT(CORE_PROGRAMS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) ){
#endif
if(MEMORY_FAILSAFE_AT(head_index))
{
  #ifdef CHECK_ARRAY
  if(AT_HEAD_OFFSET(1+argument_index) > capacity[TRANSFER_TYPE_AT(head_index, argument_index)])
  {
    //SET_FLAG(MEMORY_ACCESS_FAILED, ?)

    #ifdef TESTING_CLI
    PRINT("MEMORY_ACCESS_FAILED.\n",0,0,0)
    #endif
    
    ADVANCE_HEAD
  }
  #endif
 
  #ifdef CHECK_INDEX
  if(AT_HEAD_OFFSET(1+argument_index) > CAPACITY_AT(TRANSFER_TYPE_AT(head_index, argument_index), HEAD_ELEMENT_AT
(head_index, SOURCE_ARRAY + argument_index)))
  {
    //SET_FLAG(MEMORY_ACCESS_FAILED, TRANSFER_TYPE_AT(head_index, argument_index))

    #ifdef TESTING_CLI
    PRINT("MEMORY_ACCESS_FAILED.\n",0,0,0)
    #endif

    ADVANCE_HEAD
  }
  #endif
}

//set temporary variable
#ifdef SET_VARIABLES
#ifndef EXCLUDE_CONSTANTS
if(TRANSFER_TYPE_AT(head_index, argument_index) == CONSTANT)
  temp[argument_index] = &(MEMORY_AT(PROGRAM, ARRAY_AT(head_index), INDEX_AT(head_index) + 1 + argument_index));
else
#endif
  temp[argument_index] = &(MEMORY_AT(TRANSFER_TYPE_AT(head_index, argument_index), HEAD_ELEMENT_AT(head_index, SOURCE_ARRAY + argument_index), AT_HEAD_OFFSET(1 + argument_index)));
#endif

#ifdef CHECK_ALL_ARGUMENTS
argument_index++;
}
#endif

#undef EXCLUDE_CONSTANTS
#undef CHECK_ARRAY
#undef CHECK_INDEX
#undef CHECK_ALL_ARGUMENTS
#undef SET_VARIABLES
