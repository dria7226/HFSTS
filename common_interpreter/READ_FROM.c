// READ_FROM, 0xdeadbeef
if(AT_HEAD_OFFSET(1))
  TRANSFER_TYPE_AT(head_index) |= 1; // set 1st bit to 1
else
  TRANSFER_TYPE_AT(head_index) &= 0xFFFFFFFE;

#ifdef TESTING_CLI
PRINT("READ_FROM, %u = %u\n",AT_HEAD_OFFSET(1),TRANSFER_TYPE_AT(head_index),0)
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;
