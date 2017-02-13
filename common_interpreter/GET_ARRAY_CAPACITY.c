// GET_ARRAY_CAPACITY, array, write_to_address
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > data_capacity))
{
  SET_FLAG(DATA_ACCESS_FAILED,3)

  #ifdef TESTING_CLI
  PRINT("GET_ARRAY_CAPACITY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(WRITE_TO_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && AT_HEAD_OFFSET(2) > HIGHEST_PROGRAM_INDEX)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("GET_ARRAY_CAPACITY: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(DESTINATION_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("GET_ARRAY_CAPACITY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(2)));
}

*a = CAPACITY_AT(AT_HEAD_OFFSET(1));

#ifdef TESTING_CLI
PRINT("GET_ARRAY_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
