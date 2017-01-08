// RESIZE_DATA, capacity

resize_data(AT_HEAD_OFFSET(1));

#ifdef TESTING
  PRINT("RESIZE_DATA, %u\n",AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
