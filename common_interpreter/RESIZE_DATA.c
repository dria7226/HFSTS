// RESIZE_DATA, capacity
SET_FLAG(DATA_RESIZE_FAILED, resize_data(AT_HEAD_OFFSET(1)))

#ifdef TESTING_CLI
if(FLAG_AT(DATA_RESIZE_FAILED) == 1)
{
  PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: Invalid capacity: %u\n",AT_HEAD_OFFSET(1),0,0)

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

if(FLAG_AT(DATA_RESIZE_FAILED) == 2)
{
  PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: Can't allocate memory\n",0,0,0)

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

PRINT("RESIZE_DATA, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
