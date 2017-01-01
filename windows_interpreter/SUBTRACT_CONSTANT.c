// SUBTRACT_CONSTANT , address1 , 0xdeadbeef
FLAG_AT(UNDERFLOW) = ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) )
                      <
                     ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) -= AT_HEAD_OFFSET(2) );

#ifdef TESTING
  printf("SUBTRACT_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  if( FLAG_AT(UNDERFLOW) ) printf("The subtraction underflowed.\n");
#endif

// advance head
heads[head_index] += 3;

goto next_instruction;
