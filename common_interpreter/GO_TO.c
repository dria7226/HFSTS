// GO_TO, address1
if(AT_HEAD_OFFSET(1) >= data[source_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

if(DATA_AT(source_array, AT_HEAD_OFFSET(1)) >= program_capacity * PROGRAM_CHUNK_SIZE)
{
  SET_FLAG(PROGRAM_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 2;
  goto next_instruction;
}

#ifdef TESTING_CLI
  PRINT("GO_TO, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

HEAD_AT(head_index) = DATA_AT(source_array, AT_HEAD_OFFSET(1));

goto next_instruction;
