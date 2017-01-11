// GO_TO_CONSTANT, address1

#ifdef TESTING
  PRINT("GO_TO_CONSTANT, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

HEAD_AT(head_index) = AT_HEAD_OFFSET(1);

goto next_instruction;
