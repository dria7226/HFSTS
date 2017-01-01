// START_HEAD_AT , address1
start_head_at(AT_HEAD_OFFSET(1));

#ifdef TESTING
  printf("START_HEAD_AT, %u\n", AT_HEAD_OFFSET(1));
#endif

// advance head
heads[head_index] += 2;

goto next_instruction;
