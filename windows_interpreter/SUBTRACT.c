// SUBTRACT, address1 , address2
DATA_AT(destination, AT_HEAD_OFFSET(1)) -= DATA_AT(source, AT_HEAD_OFFSET(2));

REGISTER_AT(UNDERFLOW) = 0;

// advance head
head +=2;