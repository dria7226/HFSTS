// GET_HEAD, address1
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = head_index;

#ifdef TESTING_CLI
  PRINT("GET_HEAD, %u = %u\n", AT_HEAD_OFFSET(1), head_index,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
