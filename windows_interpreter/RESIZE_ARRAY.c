// RESIZE_ARRAY, address1, capacity

resize_array(data[AT_HEAD_OFFSET(1)],AT_HEAD_OFFSET(2));

#ifdef TESTING
  PRINT("RESIZE_ARRAY, %u, \n",AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2));
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
