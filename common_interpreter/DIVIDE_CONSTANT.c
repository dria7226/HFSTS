// DIVIDE_CONSTANT , write_to_address , 0xdeadbeef
if(MATH_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) == 0))
{
  SET_FLAG(DIVISION_BY_ZERO,1)

  #ifdef TESTING_CLI
    PRINT("DIVIDE_CONSTANT: DIVISION_BY_ZERO \n",0,0,0)
  #endif

  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(WRITE_TO_VALUE_AT(head_index))
{
  if(MATH_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("DIVIDE_CONSTANT: PROGRAM_ACCESS_FAILED: Invalid address: %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if(MATH_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > CAPACITY_AT(DESTINATION_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("DIVIDE_CONSTANT: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

*a /= AT_HEAD_OFFSET(2);

#ifdef TESTING_CLI
PRINT("DIVIDE_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *a)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
