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
argument_index = 0;
while(argument_index < DATA_AT(CORE_PROGRAMS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
{
#endif

#ifdef INDEX_CHECK
#define ARRAY_CHECK
#endif
  
#ifdef ARRAY_CHECK
// check failsafe first!
if(AT_HEAD_OFFSET(1+argument_index) > capacity[(TRANSFER_TYPE_AT(head_index) >> (2*argument_index)) & 0x3])
{
  //SET_FLAG(MEMORY_ACCESS_FAILED, ?)

  #ifdef TESTING_CLI
  PRINT("MEMORY_ACCESS_FAILED.\n",0,0,0)
  #endif
    
  ADVANCE_HEAD
}
#endif
 
#ifdef INDEX_CHECK
// check failsafe first!
if(AT_HEAD_OFFSET(1+argument_index) > CAPACITY_AT(/*type*/, SOURCE_AT(head_index)))
{
  //SET_FLAG(MEMORY_ACCESS_FAILED, ?)

  #ifdef TESTING_CLI
  PRINT("MEMORY_ACCESS_FAILED.\n",0,0,0)
  #endif

  ADVANCE_HEAD
}
#endif

#ifdef CHECK_ALL_ARGUMENTS
  //set temporary variable
  temp[argument_index] = &();
}
#endif

#undef EXCLUDE_CONSTANTS
#undef ARRAY_CHECK
#undef INDEX_CHECK
#undef CHECK_ALL_ARGUMENTS
