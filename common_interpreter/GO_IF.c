//GO_IF, address, flag_index
if(AT_HEAD_OFFSET(1) >= program_capacity*PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

  #ifdef TESTING_CLI
    PRINT("GO_IF: PROGRAM_ACCESS_FAILED: invalid program address %u\n",AT_HEAD_OFFSET(1),0,0);
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= NUMBER_OF_FLAGS)
{
  SET_FLAG(DATA_ACCESS_FAILED, 2);

  #ifdef TESTING_CLI
    PRINT("GO_IF: DATA_ACCESS_FAILED: invalid flag index %u\n",AT_HEAD_OFFSET(2),0,0);
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("GO_IF, %u, %u\n", AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

if(FLAG_AT(AT_HEAD_OFFSET(2)))
  HEAD_AT(head_index) = AT_HEAD_OFFSET(1);

//advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
