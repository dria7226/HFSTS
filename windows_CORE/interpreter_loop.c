// DATA_TYPE head = 0;
// DATA_TYPE current = 0;
//
// next_instruction:
//
// sleep(1);
//
// if(program[current]->data[head] < NUMBER_OF_OPCODES)
//   goto *label_table[program[head]];
//
// goto advance_head;
//
// MOV:
//  #include "MOV.c"
// goto advance_head;
//
// SRC:
//  #include "SRC.c"
// goto advance_head;
//
// DST:
//  #include "DST.c"
// goto advance_head;
//
// ADD:
//  #include "ADD.c"
// goto advance_head;
//
// SUB:
//  #include "SUB.c"
// goto advance_head;
//
// MUL:
//  #include "MUL.c"
// goto advance_head;
//
// DIV:
//  #include "DIV.c"
// goto advance_head;
//
// advance_head:
// if(program[0] == AVAILABLE_MEMORY - 1) goto out;
// else program[0]++;
//
// goto next_instruction;
//
// out:
