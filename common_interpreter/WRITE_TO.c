// WRITE_TO, 0xdeadbeef (left hand side)
if(AT_HEAD_OFFSET(1))
  TRANSFER_TYPE_AT(head_index) |= 2; // set 2nd bit to 1
else
  TRANSFER_TYPE_AT(head_index) &= 0xFFFFFFFD; // set 2nd bit to 0 

#ifdef TESTING_CLI
PRINT("WRITE_TO, %u = %u\n",AT_HEAD_OFFSET(1),TRANSFER_TYPE_AT(head_index),0)
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;
