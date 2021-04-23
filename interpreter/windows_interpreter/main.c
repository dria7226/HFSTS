#include <stdio.h>

enum{EMPTY, ADD, EXIT};

int main(int argc, char** argv)
{
  int head = 0;

  void* instructions[] = {&&EMPTY, &&ADD, &&EXIT};

  int no_of_args[] = {0,2,0};

  int program[] = {EMPTY, ADD, 3,4, ADD,1,2, EMPTY};

  next_instruction:
  printf("program[%u]: %u\n", head, program[head]);
  goto *instructions[program[head]];

  EMPTY:
  printf("EMPTY\n");
  goto advance_head;

  ADD:
  printf("ADD: %u, %u", program[head+1], program[head+2]);
  program[head+1] += program[head+2];
  printf(" = %u\n", program[head+1]);
  goto advance_head;

  advance_head:
  head += 1 + no_of_args[program[head]];
  goto next_instruction;

  EXIT:
  printf("EXIT\n");
}
