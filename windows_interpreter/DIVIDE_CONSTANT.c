// DIVIDE_CONSTANT , address1 , 0xdeadbeef
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) /= AT_HEAD_OFFSET(2);

#ifdef TESTING
  PRINT("DIVIDE_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
