// RESIZE_ARRAY, array_index, capacity
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > data_capacity))
{
  SET_FLAG(DATA_ACCESS_FAILED, 3)

  #ifdef TESTING_CLI
  PRINT("RESIZE_ARRAY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

a = &(resize_array(AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2));

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(ARRAY_RESIZE_FAILED, *a)

  #ifdef TESTING_CLI
  if(FLAG_AT(ARRAY_RESIZE_FAILED) == 0)
  {
    PRINT("RESIZE_ARRAY, %u, %u \n",AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0)
  }
  else
  PRINT("RESIZE_ARRAY: %s: %s\n",error_titles[ARRAY_RESIZE_FAILED-3],error_messages[FLAG_AT(ARRAY_RESIZE_FAILED)-1],0)
  #endif
}

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
