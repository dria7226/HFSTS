// GET_ARRAY_CAPACITY, address1, address2

DATA_AT(destination_array, AT_HEAD_OFFSET(2)) = data[AT_HEAD_OFFSET(1)].capacity;

#ifdef TESTING
  PRINT("GET_ARRAY_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
