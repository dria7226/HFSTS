target_array = CURRENT_ARRAY;

target_index = AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 2);

if((CAPACITY_AT(target_array) - INDEX_AT(head_index)) < target_index)
{
  SET_FLAG(INDEX_ACCESS_FAILED, argument_index + 1)

  #ifdef CLIT
  PRINT("INDEX_ACCESS_FAILED: %u\n",FLAG_AT(INDEX_ACCESS_FAILED),0,0)
  #endif

  ADVANCE_HEAD
}

target_index = INDEX_AT(head_index) + target_index;

temp[argument_index] = &MEMORY_AT(target_array, target_index);
