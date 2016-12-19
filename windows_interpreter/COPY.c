// COPY , address1 , address2

DATA_AT(destination,AT_HEAD_OFFSET(2)) = DATA_AT(source, AT_HEAD_OFFSET(1));

// advance head
head += 3;

goto next_instruction;
