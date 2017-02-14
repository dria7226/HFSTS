// INSERT_ARRAY, write_to_address, read_from_address

// check for constant to constant

if(MEMORY_FAILSAFE_AT(head_index))
{
  if(WRITE_TO_VALUE_AT(head_index))
  {
    if(AT_HEAD_OFFSET(1) > program_capacity)
    {
      SET_FLAG(PROGRAM_ACCESS_FAILED, 1)

      #ifdef TESTING_CLI
      PRINT("INSERT_ARRAY: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3], error_messages[5], AT_HEAD_OFFSET(1))
      #endif

      HEAD_AT(head_index) += 3;
      goto next_instruction;
    }
    
  }
  else
  {
    if(AT_HEAD_OFFSET(1) > data_capacity)
    {
      SET_FLAG(DATA_ACCESS_FAILED, 1)

      #ifdef TESTING_CLI
      PRINT("INSERT_ARRAY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
      #endif

      HEAD_AT(head_index) += 3;
      goto next_instruction;
    }
  }

  if(READ_FROM_VALUE_AT(head_index))
  {
    if(AT_HEAD_OFFSET(2) > program_capacity)
    {
      SET_FLAG(PROGRAM_ACCESS_FAILED, 2)

      #ifdef TESTING_CLI
      PRINT("INSERT_ARRAY: %s: %s: %u\n",error_titles[PROGRAM_ACCESS_FAILED-3], error_messages[5], AT_HEAD_OFFSET(2))
      #endif

      HEAD_AT(head_index) += 3;
      goto next_instruction;
    }
    
  }
  else
  {
    if(AT_HEAD_OFFSET(2) > data_capacity)
    {
      SET_FLAG(DATA_ACCESS_FAILED, 2)

      #ifdef TESTING_CLI
      PRINT("INSERT_ARRAY: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(2))
      #endif

      HEAD_AT(head_index) += 3;
      goto next_instruction;
    }
  }
}

*a = insert_array(AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2));

if(*a && MEMORY_FAILSAFE_AT(head_index))
{
  
}

#ifdef TESTING_CLI
PRINT("INSERT_ARRAY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
PRINT("IMPLEMENT INSERT_ARRAY!!!\n",0,0,0)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
