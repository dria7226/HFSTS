// RESIZE_PROGRAM, capacity

resize_program(AT_HEAD_OFFSET(1));

#ifdef TESTING
  PRINT("RESIZE_PROGRAM, %u\n",AT_HEAD_OFFSET(1));
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
