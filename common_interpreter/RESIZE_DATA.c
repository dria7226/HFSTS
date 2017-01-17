// RESIZE_DATA, capacity
SET_FLAG(DATA_RESIZE_FAILED, resize_data(AT_HEAD_OFFSET(1)))

#ifdef TESTING_CLI
if(FLAG_AT(DATA_RESIZE_FAILED) == 1)
{
  PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: invalid capacity %u\n",AT_HEAD_OFFSET(1),0,0);
}

if(FLAG_AT(DATA_RESIZE_FAILED) == 2)
{
  PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: can't allocate memory",0,0,0);
}
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;

#ifdef TESTING_CLI
  PRINT("RESIZE_DATA, %u\n",AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
