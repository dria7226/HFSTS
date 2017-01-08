// GET_HEAD, address1

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = head_index;

#ifdef TESTING
  PRINT("GET_HEAD, %u = %u\n", AT_HEAD_OFFSET(1), head_index,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
