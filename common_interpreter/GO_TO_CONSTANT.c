// GO_TO_CONSTANT, address1
if(AT_HEAD_OFFSET(1) >= program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("GO_TO_CONSTANT, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

HEAD_AT(head_index) = AT_HEAD_OFFSET(1);

goto next_instruction;
