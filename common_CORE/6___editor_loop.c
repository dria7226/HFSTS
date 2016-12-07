next_instruction:

//editor step
heatmap[program[0]]++;//needs more work - scale for overflow
draw_cell(program[0]);
refresh();
sleep(1);

draw_cell(0);

draw_header();

if(program[program[0]] < NUMBER_OF_OPCODES)
  goto *label_table[program[program[0]]];

goto advance_head;

MOV:
 #include "MOV.c"
draw_cell(program[program[0]+1]);
draw_cell(program[program[0]+2]);
goto advance_head;

SRC:
 #include "SRC.c"
goto advance_head;

DST:
 #include "DST.c"
goto advance_head;

ADD:
 #include "ADD.c"
draw_cell(1);
draw_cell(2);
draw_cell(3);
goto advance_head;

SUB:
 #include "SUB.c"
draw_cell(1);
draw_cell(2);
draw_cell(3);
goto advance_head;

MUL:
 #include "MUL.c"
draw_cell(1);
draw_cell(2);
draw_cell(3);
goto advance_head;

DIV:
 #include "DIV.c"
draw_cell(1);
draw_cell(2);
draw_cell(3);
goto advance_head;

advance_head:
if(program[0] == 255) goto out;
else program[0]++;

goto next_instruction;

out:
