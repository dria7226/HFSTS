// SET_DESTINATION , array_index
if(MEMORY_FAILSAFE_AT(head_index) && (AT_HEAD_OFFSET(1) > data_capacity))
{
  SET_FLAG(DATA_ACCESS_FAILED,3)

  #ifdef TESTING_CLI
  PRINT("SET_DESTINATION: %s: %s: %u\n",error_titles[DATA_ACCESS_FAILED-3],error_messages[1+FLAG_AT(DATA_ACCESS_FAILED)],AT_HEAD_OFFSET(1))
  #endif

  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

DESTINATION_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
PRINT("SET_DESTINATION, %u\n", AT_HEAD_OFFSET(1),0,0)
#endif

// advance head
HEAD_AT(head_index) += 2;
goto next_instruction;
