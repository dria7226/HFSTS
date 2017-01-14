// SET_DESTINATION , address1
if(data[AT_HEAD_OFFSET(1)] < data_capacity)
  destination_array = AT_HEAD_OFFSET(1);
else
  //FLAG_AT() = 1;

#ifdef TESTING
  PRINT("SET_DESTINATION, %u\n", AT_HEAD_OFFSET(1),0,0);
#endif

// advance head
HEAD_AT(head_index) += 2;

goto next_instruction;
