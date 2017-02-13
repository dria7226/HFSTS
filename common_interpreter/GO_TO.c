// GO_TO, address
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > (program_capacity+1) * PROGRAM_CHUNK_SIZE))
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
  PRINT("GO_TO: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
PRINT("GO_TO, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

HEAD_AT(head_index) = AT_HEAD_OFFSET(1);

goto next_instruction;
