// MULTIPLY_CONSTANT , addres1 , 0xdeadbeef
DATA_AT(destination, AT_HEAD_OFFSET(1)) *= AT_HEAD_OFFSET(2);

REGISTER_AT(OVERFLOW) = 0;

// advance head
head += 2;