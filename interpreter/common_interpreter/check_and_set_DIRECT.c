if(argument_index > 1)
  target_array = CURRENT_ARRAY;
 else
  target_array = HEAD_ELEMENT_AT(head_index, PRIMARY_ARRAY + argument_index);

target_index = AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 2);

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

temp[argument_index] = &MEMORY_AT(target_array, target_index);
