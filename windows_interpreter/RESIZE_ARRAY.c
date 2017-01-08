// RESIZE_ARRAY, capacity

resize_array(destination_array, AT_HEAD_OFFSET(1));

#ifdef TESTING
  PRINT("RESIZE_ARRAY, %u \n",AT_HEAD_OFFSET(1), 0,0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
