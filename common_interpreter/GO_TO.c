// GO_TO, address
if(AT_HEAD_OFFSET(1) >= program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("GO_TO: PROGRAM_ACCESS_FAILED: invalid program address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("GO_TO, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

HEAD_AT(head_index) = AT_HEAD_OFFSET(1);

goto next_instruction;
