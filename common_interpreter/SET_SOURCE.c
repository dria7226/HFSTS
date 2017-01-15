// SET_SOURCE , address1
if(AT_HEAD_OFFSET(1) >= data_capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,3)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

source_array = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
  PRINT("SET_SOURCE, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
