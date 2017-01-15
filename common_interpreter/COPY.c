// COPY , source_address , destination_address
if(AT_HEAD_OFFSET(1) >= data[source_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)
  printf("COPY, %u, %u failed. Invalid source address: %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(1));
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)
  printf("COPY, %u, %u failed. Invalid destination address: %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), AT_HEAD_OFFSET(2));
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

DATA_AT(destination_array,AT_HEAD_OFFSET(2)) = DATA_AT(source_array, AT_HEAD_OFFSET(1));

#ifdef TESTING_CLI
  PRINT("COPY, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
