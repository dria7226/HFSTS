void* label_table[EMPTY] = {/*&&MOV, &&SRC, &&DST,*/ &&ADD/*, &&SUB, &&MUL, &&DIV*/};

DATA_TYPE head = 0;
DATA_TYPE source_array = 0;
DATA_TYPE destination_array = 0;

next_instruction:

// if(AT_HEAD < EMPTY)
//   goto *label_table[AT_HEAD];
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

ADD:
 #include "ADD.c"
goto advance_head;
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

advance_head:
head++;

goto next_instruction;

// out:
//
// return;
