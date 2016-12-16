if(program[program[0]+2] == 0)
{
  program[0] = program[program[program[0]+1]];
  goto next_instruction;
}
else
{
  program[program[program[0]+2]] = program[program[program[0]+1]];
  program[0] += 2;
}
