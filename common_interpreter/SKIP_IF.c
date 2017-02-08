// SKIP_IF, 0xdeadbeef, flag_index
if(HEAD_AT(head_index) + AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
  PRINT("SKIP_IF: PROGRAM_ACCESS_FAILED: Invalid program address: %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(READ_FROM_VALUE_AT(head_index))
{
  if(AT_HEAD_OFFSET(2) > program_capacity * PROGRAM_CHUNK_SIZE)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 2)

    #ifdef TESTING_CLI
    PRINT("SKIP_IF: PROGRAM_ACCESS_FAILED: Invalid address: %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(AT_HEAD_OFFSET(2) > CAPACITY_AT(SOURCE_AT(head_index)))
  {
    SET_FLAG(DATA_ACCESS_FAILED, 2);

    #ifdef TESTING_CLI
    PRINT("SKIP_IF: DATA_ACCESS_FAILED: Invalid source address: %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)));
}

#ifdef TESTING_CLI
PRINT("SKIP_IF, %u, %u\n", AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

if(*a)
  HEAD_AT(head_index) += AT_HEAD_OFFSET(1);
else
  HEAD_AT(head_index) += 3;

goto next_instruction;
