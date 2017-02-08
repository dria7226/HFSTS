// MULTIPLY, write_to_address, read_from_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > program_capacity * PROGRAM_CHUNK_SIZE))
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

    #ifdef TESTING_CLI
    PRINT("MULTIPLY: PROGRAM_ACCESS_FAILED: Invalid address: %u\n", AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > CAPACITY_AT(DESTINATION_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("MULTIPLY: DATA_ACCESS_FAILED: Invalid destination address: %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a =&(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(1)));
}

if(READ_FROM_VALUE_AT(head_index))
{

}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(SOURCE_AT(head_index))))
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("MULTIPLY: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2));
}

product = *a * *b;

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, ( *a != 0 && product / *a != *b ))
}

*a = product;

#ifdef TESTING_CLI
PRINT("MULTIPLY, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *a)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
