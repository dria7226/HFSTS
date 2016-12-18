// ADD , address1 , address2
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) += DATA_AT(source_array, AT_HEAD_OFFSET(2));

REGISTER_AT(OVERFLOW_REGISTER) = 0; //more work needed - overflow

// advance head
head += 2;