//load_test_program();
//write_test_program_to_storage();
read_test_program_from_storage();

void* label_table[NUMBER_OF_OPCODES] = {&&MOV, &&SRC, &&DST, &&ADD, &&SUB, &&MUL, &&DIV};
