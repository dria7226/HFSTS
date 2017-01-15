// GET_ARRAY_CAPACITY, array, destination_array
if(AT_HEAD_OFFSET(2) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(1) >= data_capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,3)
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}


DATA_AT(destination_array, AT_HEAD_OFFSET(2)) = data[AT_HEAD_OFFSET(1)].capacity;

#ifdef TESTING_CLI
  PRINT("GET_ARRAY_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
