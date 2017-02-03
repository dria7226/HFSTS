// GET_GRANULARITY_COUNTER, write_to_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(AT_HEAD_OFFSET(1) >= program_capacity * PROGRAM_CHUNK_SIZE)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("GET_GRANULARITY_COUNTER: PROGRAM_ACCESS_FAILED: Invalid address: %u\n", AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 2;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if(AT_HEAD_OFFSET(1) >= CAPACITY_AT(DESTINATION_AT(head_index)))
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("GET_GRANULARITY_COUNTER: DATA_ACCESS_FAILED: Invalid destination address: %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 2;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

*a = granularity_counter;

#ifdef TESTING_CLI
PRINT("GET_GRANULARITY_COUNTER, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
