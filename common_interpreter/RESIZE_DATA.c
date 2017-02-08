// RESIZE_DATA, capacity
a = &(resize_data(AT_HEAD_OFFSET(1)));

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(DATA_RESIZE_FAILED, *a)

  #ifdef TESTING_CLI
  if(FLAG_AT(DATA_RESIZE_FAILED) == 0)
  {
    PRINT("RESIZE_DATA, %u\n",AT_HEAD_OFFSET(1),0,0)
  }
  else
  {
    if(FLAG_AT(DATA_RESIZE_FAILED) == 1)
    {
      PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: Invalid capacity: %u\n",AT_HEAD_OFFSET(1),0,0)

      HEAD_AT(head_index) += 2;
      goto next_instruction;
    }
    else
    //if(FLAG_AT(DATA_RESIZE_FAILED) == 2)
    {
      PRINT("RESIZE_DATA: DATA_RESIZE_FAILED: Can't allocate memory\n",0,0,0)

      HEAD_AT(head_index) += 2;
      goto next_instruction;
    }
}
#endif
}

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
