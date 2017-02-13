// REMAINDER, write_to_address, read_from_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

    #ifdef TESTING_CLI
    PRINT("REMAINDER: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 3;
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
    PRINT("REMAINDER: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

if(READ_FROM_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 2)

    #ifdef TESTING_CLI
    PRINT("REMAINDER: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(SOURCE_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("REMAINDER: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)));
}

if(MATH_FAILSAFE_AT(head_index) && (DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)) == 0))
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef TESTING_CLI
  PRINT("REMAINDER: %s \n",error_titles[DIVISION_BY_ZERO-3],0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

*a %= *b;

#ifdef TESTING_CLI
PRINT("REMAINDER, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *a )
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
