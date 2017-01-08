// ADD_CONSTANT , address1 , 0xdeadbeef
FLAG_AT(OVERFLOW) = ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) )
                    >
                    ( DATA_AT(destination_array, AT_HEAD_OFFSET(1)) += AT_HEAD_OFFSET(2) );

#ifdef TESTING
  PRINT("ADD_CONSTANT, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), DATA_AT(destination_array, AT_HEAD_OFFSET(1)));
  if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0);
#endif

// advance head
HEAD_AT(head_index) += 3;

goto next_instruction;
