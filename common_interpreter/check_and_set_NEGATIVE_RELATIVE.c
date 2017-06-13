target_array = CURRENT_ARRAY;

target_index = INDEX_AT(head_index) - AT_HEAD_OFFSET(argument_index*2 + 2);

if(MEMORY_FAILSAFE_AT(head_index))
{
  if(target_array > capacity)
  {
    SET_FLAG(ARRAY_ACCESS_FAILED, argument_index + 1)
    
    #ifdef CLIT
    PRINT("ARRAY_ACCESS_FAILED: %u\n",FLAG_AT(ARRAY_ACCESS_FAILED),0,0)
    #endif

    ADVANCE_HEAD
  }

  if(target_index > CAPACITY_AT(target_array))
  {
    SET_FLAG(INDEX_ACCESS_FAILED, argument_index + 1)
    
    #ifdef CLIT
    PRINT("INDEX_ACCESS_FAILED: %u\n",FLAG_AT(INDEX_ACCESS_FAILED),0,0)
    #endif

    ADVANCE_HEAD
  }
  
  if(target_index > INDEX_AT(head_index))
  {
    SET_FLAG(UNDERFLOW,argument_index+1)

    #ifdef CLIT
    PRINT("The subtraction underflowed.\n",0,0,0)
    #endif

    ADVANCE_HEAD
  }
}

temp[argument_index] = &MEMORY_AT(target_array, target_index);
