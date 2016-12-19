// SUBTRACT_CONSTANT , address1 , 0xdeadbeef
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) -= AT_HEAD_OFFSET(2);

REGISTER_AT(UNDERFLOW) = 0;

// advance head
head += 3;

goto next_instruction;
