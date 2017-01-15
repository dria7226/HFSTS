// RESIZE_ARRAY, capacity
if(resize_array(destination_array, AT_HEAD_OFFSET(1)))
{
 SET_FLAG(ARRAY_RESIZE_FAILED,1)
 HEAD_AT(head_index) += 2;
 goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("RESIZE_ARRAY, %u \n",AT_HEAD_OFFSET(1), 0,0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
