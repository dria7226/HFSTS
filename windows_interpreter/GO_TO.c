// GO_TO, address1

#ifdef TESTING
  PRINT("GO_TO, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

HEAD_AT(head_index) = DATA_AT(source_array, AT_HEAD_OFFSET(1));

goto next_instruction;
