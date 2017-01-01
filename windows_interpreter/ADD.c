// ADD , address1 , address2
FLAG_AT(OVERFLOW) = ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) )
                    >
                    ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) += DATA_AT(source_array, AT_HEAD_OFFSET(2)));

#ifdef TESTING
  printf("ADD, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  if( FLAG_AT(OVERFLOW) ) printf("The addition overflowed.\n");
#endif

// advance head
heads[head_index] += 3;

goto next_instruction;
