// COPY_CONSTANT , 0xdeadbeef , address1
if(AT_HEAD_OFFSET(2) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

DATA_AT(destination_array, AT_HEAD_OFFSET(2)) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
  PRINT("COPY_CONSTANT, %u, %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2),0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
