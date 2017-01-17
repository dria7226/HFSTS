// MULTIPLY_CONSTANT , destination_address , 0xdeadbeef
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED, 1)

  #ifdef TESTING_CLI
    PRINT("MULTIPLY_CONSTANT: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0);
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) *= AT_HEAD_OFFSET(2);

SET_FLAG(OVERFLOW,0) // ???

#ifdef TESTING_CLI
  PRINT("MULTIPLY_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  PRINT("!!! OVERFLOW FLAG NEEDS TO BE IMPLEMENTED !!!\n",0,0,0);
  ENTER_TO_CONTINUE
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
