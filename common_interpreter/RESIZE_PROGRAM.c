// RESIZE_PROGRAM, capacity
SET_FLAG(PROGRAM_RESIZE_FAILED,resize_program(AT_HEAD_OFFSET(1)))

#ifdef TESTING_CLI
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

PRINT("RESIZE_PROGRAM, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
