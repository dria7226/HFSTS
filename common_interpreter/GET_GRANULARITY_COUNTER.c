//GET_GRANULARITY_COUNTER, destination_address
if(AT_HEAD_OFFSET(1) >= CAPACITY_AT([DESTINATION_AT(head_index)]))
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("GET_GRANULARITY_COUNTER: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) = granularity_counter;

#ifdef TESTING_CLI
  PRINT("GET_GRANULARITY_COUNTER, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
