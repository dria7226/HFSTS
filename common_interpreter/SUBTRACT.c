// SUBTRACT, destination_address , source_address
if(AT_HEAD_OFFSET(1) >= data[DESTINATION_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)

  #ifdef TESTING_CLI
    PRINT("SUBTRACT: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= data[SOURCE_AT(head_index)].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)

  #ifdef TESTING_CLI
    PRINT("SUBTRACT: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

SET_FLAG(UNDERFLOW, ( DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
                      <
                     ( DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) -= DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)) ))

#ifdef TESTING_CLI
  PRINT("SUBTRACT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)) )
  if( FLAG_AT(UNDERFLOW) ) PRINT("The subtraction underflowed.\n",0,0,0)
#endif

// advance head
HEAD_AT(head_index) +=3;

goto next_instruction;
