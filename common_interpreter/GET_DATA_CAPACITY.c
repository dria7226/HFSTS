// GET_DATA_CAPACITY, address1
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = data_capacity;

#ifdef TESTING_CLI
  PRINT("GET_DATA_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
