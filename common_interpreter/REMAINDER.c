// REMAINDER, destination_address, source_address
if(AT_HEAD_OFFSET(1) >= data[DESTINATION_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("REMAINDER: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= data[SOURCE_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("REMAINDER: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)) == 0)
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef TESTING_CLI
    PRINT("REMAINDER: DIVISION_BY_ZERO \n",0,0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) %= DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2));

#ifdef TESTING_CLI
  PRINT("REMAINDER, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
