// ADD , address1 , address2
if(AT_HEAD_OFFSET(1) >= data[destination_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,1)
  HEAD_AT(head_index) += 3;
  goto next_instruction;
}

if(AT_HEAD_OFFSET(2) >= data[source_array].capacity)
{
  SET_FLAG(DATA_ACCESS_FAILED,2)
  goto next_instruction;
}

SET_FLAG(OVERFLOW, ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) )
                    >
                    ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) += DATA_AT(source_array, AT_HEAD_OFFSET(2))))

#ifdef TESTING_CLI
  PRINT("ADD, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
