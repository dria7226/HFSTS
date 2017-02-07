// SET_TRANSFER_TYPE, 0xdeadbeef
TRANSFER_TYPE_AT(head_index) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
PRINT("SET_TRANSFER_TYPE, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;
