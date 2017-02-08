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
  PRINT("RESIZE_DATA, %s: %s\n",error_titles[DATA_RESIZE_FAILED-3],error_messages[FLAG_AT(DATA_RESIZE_FAILED)-1],0)
  #endif
}

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
