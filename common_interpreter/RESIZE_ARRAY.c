// RESIZE_ARRAY, capacity
SET_FLAG(ARRAY_RESIZE_FAILED,resize_array(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)))

#ifdef TESTING_CLI
if(FLAG_AT(ARRAY_RESIZE_FAILED) == 1)
{
 PRINT("RESIZE_ARRAY: ARRAY_RESIZE_FAILED: invalid capacity %u\n",AT_HEAD_OFFSET(1),0,0)
}

if(FLAG_AT(ARRAY_RESIZE_FAILED) == 2)
{
 PRINT("RESIZE_ARRAY: ARRAY_RESIZE_FAILED: can't allocate memory",0,0,0)
}
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;

#ifdef TESTING_CLI
  PRINT("RESIZE_ARRAY, %u \n",AT_HEAD_OFFSET(1), 0,0)
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
