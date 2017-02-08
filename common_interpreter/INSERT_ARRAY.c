// INSERT_ARRAY, write_to_address, read_from_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if(CAPACITY_AT(SOURCE_AT(head_index))/PROGRAM_CHUNK_SIZE+1 > program_capacity) //???
  {}
}
else
{

}

if(READ_FROM_VALUE_AT(head_index))
{

}
else
{

}

#ifdef TESTING_CLI
PRINT("INSERT_ARRAY, %u, %u\n",AT_HEAD_OFFSET(1),AT_HEAD_OFFSET(2),0)
#endif

// advance head
HEAD_AT(head_index) += 3;
goto next_instruction;
