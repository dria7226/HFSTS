// MULTIPLY, address1, address2
DATA_AT(destination_array, AT_HEAD_OFFSET(1)) *= DATA_AT(source_array, AT_HEAD_OFFSET(2));

REGISTER_AT(OVERFLOW) = 0;

// advance head
heads[head_index] += 3;

goto next_instruction;
