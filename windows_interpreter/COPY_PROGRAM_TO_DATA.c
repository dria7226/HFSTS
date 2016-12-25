//COPY_PROGRAM_TO_DATA , address1 , address2

PROGRAM_AT(AT_HEAD_OFFSET(1)) = DATA_AT(destination_array, AT_HEAD_OFFSET(2));

//advance head
heads[head_index] += 3;

goto next_instruction;
