#define CURRENT_ARRAY HEAD_ELEMENT_AT(head_index, ARRAY)

if(MEMORY_FAILSAFE_AT(head_index))
{
  #ifdef CHECK_ALL_ARGUMENTS
  while(argument_index < MEMORY_AT(CORE_PROGRAMS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
  {
  #endif

    #ifdef CHECK_ARRAY
    if(AT_HEAD_OFFSET(1+argument_index) > capacity)
    {
      SET_FLAG(ARRAY_ACCESS_FAILED, 1 + argument_index)
    
      #ifdef CLIT
      PRINT("ARRAY_ACCESS_FAILED : %u\n",FLAG_AT(ARRAY_ACCESS_FAILED),0,0)
      #endif
      
      ADVANCE_HEAD
    }
    #endif
 
    #ifdef CHECK_INDEX
    //ARRAY checking and setting
    if(AT_HEAD_OFFSET(2*argument_index + 1) < NEGATIVE_RELATIVE)
    {
      target_array = HEAD_ELEMENT_AT(head_index, SOURCE_ARRAY + argument_index);
      
      if(target_array > capacity)
      {
        SET_FLAG(ARRAY_ACCESS_FAILED, 1 + argument_index)

        #ifdef CLIT
        PRINT("ARRAY_ACCESS_FAILED : %u\n",FLAG_AT(ARRAY_ACCESS_FAILED),0,0)
        #endif

        ADVANCE_HEAD
      }
    }
    else
    {
       target_array = CURRENT_ARRAY;
    }

    //INDEX checking and setting
    if(AT_HEAD_OFFSET(1+argument_index) > CAPACITY_AT(HEAD_ELEMENT_AT(head_index, SOURCE_ARRAY + argument_index)))
    {
      SET_FLAG(INDEX_ACCESS_FAILED, 1 + argument_index)
      
      #ifdef CLIT
      PRINT("INDEX_ACCESS_FAILED : %u\n",FLAG_AT(INDEX_ACCESS_FAILED),0,0)
      #endif
      
      ADVANCE_HEAD
    }

    #ifdef SET_VARIABLES
    //set temporary variable
    temp[argument_index] = &(MEMORY_AT( HEAD_ELEMENT_AT(head_index, SOURCE_ARRAY + argument_index), AT_HEAD_OFFSET(1 + argument_index)));
    temp[argument_index] = &(MEMORY_AT( array, index));
    #endif
    
    #endif
    
    #ifdef CHECK_ALL_ARGUMENTS
    argument_index++;
    }
    #endif
}

#undef CHECK_ARRAY
#undef CHECK_INDEX
#undef CHECK_ALL_ARGUMENTS
#undef SET_VARIABLES
