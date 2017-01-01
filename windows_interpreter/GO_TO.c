// GO_TO , address1

#ifdef TESTING
  printf("GO_TO, %u\n", AT_HEAD_OFFSET(1));
#endif

heads[head_index] = AT_HEAD_OFFSET(1);

goto next_instruction;
