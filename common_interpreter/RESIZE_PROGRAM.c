// RESIZE_PROGRAM, capacity
a =&(resize_program(AT_HEAD_OFFSET(1)));

if(MEMORY_FAILSAFE_AT(head_index))
{
  SET_FLAG(PROGRAM_RESIZE_FAILED, *a)

  #ifdef TESTING_CLI
  if(FLAG_AT(PROGRAM_RESIZE_FAILED) == 0)
  {
    PRINT("RESIZE_PROGRAM, %u\n",AT_HEAD_OFFSET(1),0,0)
  }
  else
  PRINT("RESIZE_PROGRAM: %s: %s\n",error_titles[PROGRAM_RESIZE_FAILED-3],error_messages[FLAG_AT(PROGRAM_RESIZE_FAILED)-1],0)
  #endif
}

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
