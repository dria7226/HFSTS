// MULTIPLY_CONSTANT , address1 , 0xdeadbeef
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) *= AT_HEAD_OFFSET(2);

FLAG_AT(OVERFLOW) = 0; // ???

#ifdef TESTING
  printf("MULTIPLY_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  printf("!!! OVERFLOW FLAG NEEDS TO BE IMPLEMENTED !!!\n");
#endif

// advance head
heads[head_index] += 3;

goto next_instruction;
