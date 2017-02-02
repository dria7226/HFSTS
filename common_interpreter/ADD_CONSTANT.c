// ADD_CONSTANT , write_to_address, 0xdeadbeef
if(WRITE_TO_VALUE_AT(head_index))
{
  if( AT_HEAD_OFFSET(1) >= program_capacity * PROGRAM_CHUNK_SIZE )
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("ADD_CONSTANT: PROGRAM_ACCESS_FAILED: invalid address %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT( AT_HEAD_OFFSET(1)));
}
else
{
  if( AT_HEAD_OFFSET(1) >= CAPACITY_AT(DESTINATION_AT(head_index)) )
  {
    SET_FLAG(DATA_ACCESS_FAILED, 1)

    #ifdef TESTING_CLI
    PRINT("ADD_CONSTANT: DATA_ACCESS_FAILED: invalid destination address %u\n", AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

SET_FLAG(OVERFLOW, *a > (*a += AT_HEAD_OFFSET(2)))

#ifdef TESTING_CLI
PRINT("ADD_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *a)
if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0)
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
