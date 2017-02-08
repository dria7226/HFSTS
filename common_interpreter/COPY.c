// COPY , write_to_address , read_from_address
if(WRITE_TO_VALUE_AT(head_index) )
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

    #ifdef TESTING_CLI
    PRINT("COPY: PROGRAM_ACCESS_FAILED: Invalid address: %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > CAPACITY_AT(SOURCE_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("COPY: DATA_ACCESS_FAILED: Invalid source address: %u\n", AT_HEAD_OFFSET(1), 0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

if(MEMORY_FAILSAFE_AT(head_index) && (READ_FROM_VALUE_AT(head_index)))
{
  if(AT_HEAD_OFFSET(2) > program_capacity * PROGRAM_CHUNK_SIZE)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 2)

    #ifdef TESTING_CLI
    PRINT("COPY: PROGRAM_ACCESS_FAILED: Invalid address: %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(DESTINATION_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("COPY: DATA_ACCESS_FAILED: Invalid destination address: %u\n", AT_HEAD_OFFSET(2), 0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)));
}

*a = *b;

#ifdef TESTING_CLI
PRINT("COPY, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
