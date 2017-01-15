// GET_PROGRAM_CAPACITY, address1
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = program_capacity;

#ifdef TESTING_CLI
  PRINT("GET_PROGRAM_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
