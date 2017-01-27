// COPY_CONSTANT , 0xdeadbeef , destination_address
if(AT_HEAD_OFFSET(2) >= CAPACITY_AT([DESTINATION_AT(head_index)]))
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("COPY_CONSTANT: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(2)) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
  PRINT("COPY_CONSTANT, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
