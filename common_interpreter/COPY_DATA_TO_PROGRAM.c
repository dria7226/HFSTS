// COPY_DATA_TO_PROGRAM , source_address , address
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("COPY_DATA_TO_PROGRAM: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(1),0,0);
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("COPY_DATA_TO_PROGRAM: PROGRAM_ACCESS_FAILED: invalid program address %u\n",AT_HEAD_OFFSET(2),0,0);
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

PROGRAM_AT(AT_HEAD_OFFSET(2)) = DATA_AT(source_array, AT_HEAD_OFFSET(1));

#ifdef TESTING_CLI
  PRINT("COPY_DATA_TO_PROGRAM, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
