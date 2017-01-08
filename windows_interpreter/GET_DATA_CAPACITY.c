// GET_DATA_CAPACITY, address1

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = data_capacity;

#ifdef TESTING
  PRINT("GET_DATA_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
