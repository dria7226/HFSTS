// MULTIPLY, destination_address, source_address
if(AT_HEAD_OFFSET(1) >= CAPACITY_AT(DESTINATION_AT(head_index)))
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("MULTIPLY: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= CAPACITY_AT(SOURCE_AT(head_index)))
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("MULTIPLY: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

product = DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) * DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2));

SET_FLAG(OVERFLOW, ( DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) != 0 && product / DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) != DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)) ))

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) = product;

#ifdef TESTING_CLI
  PRINT("MULTIPLY, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
