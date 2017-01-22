// RESIZE_PROGRAM, capacity
SET_FLAG(PROGRAM_RESIZE_FAILED,resize_program(AT_HEAD_OFFSET(1)))

#ifdef TESTING_CLI
if(FLAG_AT(PROGRAM_RESIZE_FAILED) == 1)
{
  PRINT("RESIZE_PROGRAM: PROGRAM_RESIZE_FAILED: invalid capacity %u\n",AT_HEAD_OFFSET(1),0,0)
}

if(FLAG_AT(PROGRAM_RESIZE_FAILED) == 2)
{
  PRINT("RESIZE_PROGRAM: PROGRAM_RESIZE_FAILED: can't allocate memory",0,0,0)
}
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;

#ifdef TESTING_CLI
  PRINT("RESIZE_PROGRAM, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
