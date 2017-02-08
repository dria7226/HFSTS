// RESIZE_PROGRAM, capacity
a =&(resize_program(AT_HEAD_OFFSET(1)));

if(MEMORY_FAILSAFE_AT(head_index))
{
SET_FLAG(PROGRAM_RESIZE_FAILED, *a)

#ifdef TESTING_CLI
if(FLAG_AT 
if(FLAG_AT(PROGRAM_RESIZE_FAILED) == 1)
{
  PRINT("RESIZE_PROGRAM: PROGRAM_RESIZE_FAILED: Invalid capacity: %u\n",AT_HEAD_OFFSET(1),0,0)

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

if(FLAG_AT(PROGRAM_RESIZE_FAILED) == 2)
{
  PRINT("RESIZE_PROGRAM: PROGRAM_RESIZE_FAILED: Can't allocate memory\n",0,0,0)

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#endif
}

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
