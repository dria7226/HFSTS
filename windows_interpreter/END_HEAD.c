// END_HEAD , address1
end_head(AT_HEAD_OFFSET(1));

#ifdef TESTING
  PRINT("END_HEAD, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
heads[head_index] += 2;

goto next_instruction;
