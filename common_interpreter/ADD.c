// ADD , destination_address , source_address
if( (WRITE_TO_VALUE_AT(head_index) == DATA) && AT_HEAD_OFFSET(1) >= CAPACITY_AT(DESTINATION_AT(head_index)))
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("ADD: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if( (WRITE_TO_VALUE_AT(head_index) == PROGRAM) && AT_HEAD_OFFSET(1) >= program_capacity*PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("ADD: PROGRAM_ACCESS_FAILED: invalid address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if( (READ_FROM_VALUE_AT(head_index) == DATA) && AT_HEAD_OFFSET(2) >= CAPACITY_AT(SOURCE_AT(head_index)))
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("ADD: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if( (READ_FROM_VALUE_AT(head_index) == PROGRAM) && AT_HEAD_OFFSET(2) >= program_capacity*PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("ADD: PROGRAM_ACCESS_FAILED: invalid address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

SET_FLAG(OVERFLOW, ( MEMORY_AT(WRITE_TO_VALUE_AT(head_index), DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
                    >
	 ( MEMORY_AT(WRITE_TO_VALUE_AT(head_index), DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) += MEMORY_AT(READ_FROM_VALUE_AT(head_index), SOURCE_AT(head_index), AT_HEAD_OFFSET(2))))

#ifdef TESTING_CLI
  PRINT("ADD, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
  if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0)
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
