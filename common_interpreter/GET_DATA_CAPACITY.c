// GET_DATA_CAPACITY, write_to_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("GET_DATA_CAPACITY: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 2;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > CAPACITY_AT(DESTINATION_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("GET_DATA_CAPACITY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1 + FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 2;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

*a = data_capacity;

#ifdef TESTING_CLI
PRINT("GET_DATA_CAPACITY, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
