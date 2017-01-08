// GET_PROGRAM_CAPACITY, address1, address2

DATA_AT(destination, AT_HEAD_OFFSET(2)) = program_capacity;

#ifdef TESTING
  PRINT("GET_PROGRAM_CAPACITY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
