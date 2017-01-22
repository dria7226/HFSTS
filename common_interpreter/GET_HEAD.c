// GET_HEAD, destination_address
if(AT_HEAD_OFFSET(1) >= data[DESTINATION_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("GET_HEAD: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) = head_index;

#ifdef TESTING_CLI
  PRINT("GET_HEAD, %u = %u\n", AT_HEAD_OFFSET(1), head_index,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
