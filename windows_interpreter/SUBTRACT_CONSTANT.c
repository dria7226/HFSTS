// SUBTRACT_CONSTANT , address1 , 0xdeadbeef
DATA_AT(destination, AT_HEAD_OFFSET(1)) -= AT_HEAD_OFFSET(2);

REGISTER_AT(UNDERFLOW) = 0;

// advance head
head += 2;