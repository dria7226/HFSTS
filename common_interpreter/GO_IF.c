//GO_IF, address, flag_index
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
{
  SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

  #ifdef TESTING_CLI
  PRINT("GO_IF: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(READ_FROM_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 2)

    #ifdef TESTING_CLI
    PRINT("GO_IF: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(SOURCE_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED, 2)

    #ifdef TESTING_CLI
    PRINT("GO_IF: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)));
}

#ifdef TESTING_CLI
PRINT("GO_IF, %u, %u\n", AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

if(*a)
  HEAD_AT(head_index) = AT_HEAD_OFFSET(1);
else
  HEAD_AT(head_index) += 3;

goto next_instruction;
