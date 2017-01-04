// COPY_DATA_TO_PROGRAM , address1 , address2

DATA_AT(source_array, AT_HEAD_OFFSET(1)) = PROGRAM_AT(AT_HEAD_OFFSET(2));

#ifdef TESTING
  PRINT("COPY_DATA_TO_PROGRAM, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0);
#endif

// advance head
heads[head_index] += 3;

goto next_instruction;
