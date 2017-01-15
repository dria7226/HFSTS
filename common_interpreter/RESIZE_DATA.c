// RESIZE_DATA, capacity
if(resize_data(AT_HEAD_OFFSET(1)))
{
  SET_FLAG(DATA_RESIZE_FAILED, 1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("RESIZE_DATA, %u\n",AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
