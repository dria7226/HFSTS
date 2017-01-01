// SET_DESTINATION , address1
destination_array = AT_HEAD_OFFSET(1);

#ifdef TESTING
  printf("SET_DESTINATION, %u\n", AT_HEAD_OFFSET(1));
#endif

// advance head
heads[head_index] += 2;

goto next_instruction;
