// COPY_CONSTANT , address1 , 0xdeadbeef

DATA_AT(destination_array, AT_HEAD_OFFSET(1)) = AT_HEAD_OFFSET(2);

// advance head
heads[head_index] += 3;

goto next_instruction;