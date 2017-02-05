// SET_MATH_FAILSAFE, 0xdeadbeef

FLAG_AT(MATH_FAILSAFE) = AT_HEAD_OFFSET(1);

#ifdef TESTING_CLI
PRINT("SET_MATH_FAILSAFE, %u\n",AT_HEAD_OFFSET(1),0,0)
#endif

HEAD_AT(head_index) += 2;
goto next_instruction;
