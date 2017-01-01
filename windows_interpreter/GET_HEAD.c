// GET_HEAD, address1

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = head_index;

#ifdef TESTING
  printf("GET_HEAD, %u = %u\n", AT_HEAD_OFFSET(1), head_index);
#endif

// advance head
heads[head_index] += 2;

goto next_instruction;
