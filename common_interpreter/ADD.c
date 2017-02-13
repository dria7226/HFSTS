// ADD , write_to__address , read_from_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) && AT_HEAD_OFFSET(1) > HIGHEST_PROGRAM_INDEX)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("ADD: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(PROGRAM_AT(AT_HEAD_OFFSET(1)));
}
else
{
  if( MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > CAPACITY_AT(DESTINATION_AT(head_index))) )
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("ADD: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  a = &(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)));
}

if(READ_FROM_VALUE_AT(head_index))
{
  if(MEMORY_FAILSAFE_AT(head_index) &&  AT_HEAD_OFFSET(2) > HIGHEST_PROGRAM_INDEX)
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("ADD: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3],error_messages[5],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(PROGRAM_AT(AT_HEAD_OFFSET(2)));
}
else
{
  if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(2) > CAPACITY_AT(SOURCE_AT(head_index))) )
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("ADD: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(2))
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }

  b = &(DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)));
}

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, *a > (*a + *b))
}

*a += *b;

#ifdef TESTING_CLI
PRINT("ADD, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), *a)
if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
