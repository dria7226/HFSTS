// SKIP, 0xdeadbeef
if(MEMORY_FAILSAFE_AT(head_index) && (HEAD_AT(head_index) + AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
  PRINT("SKIP: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
PRINT("SKIP, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

HEAD_AT(head_index) += AT_HEAD_OFFSET(1);

goto next_instruction;