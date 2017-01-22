//COPY_PROGRAM_TO_DATA , address , destination_address
if(AT_HEAD_OFFSET(1) >= program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("COPY_PROGRAM_TO_DATA: PROGRAM_ACCESS_FAILED: invalid program address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= data[DESTINATION_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("COPY_PROGRAM_TO_DATA: DATA_ACCESS_FAILED: invalid data address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(2)) = PROGRAM_AT(AT_HEAD_OFFSET(1));

#ifdef TESTING_CLI
  PRINT("COPY_PROGRAM_TO_DATA, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
