// MULTIPLY_CONSTANT , address1 , 0xdeadbeef
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) *= AT_HEAD_OFFSET(2);

FLAG_AT(OVERFLOW) = 0; // ???

#ifdef TESTING
  PRINT("MULTIPLY_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  PRINT("!!! OVERFLOW FLAG NEEDS TO BE IMPLEMENTED !!!\n",0,0,0);
  ENTER_TO_CONTINUE
#endif

// advance head
heads[head_index] += 3;

goto next_instruction;
