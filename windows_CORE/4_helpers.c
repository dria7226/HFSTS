//test program

#include "test_program.c"

void load_test_program()
{
  if(sizeof(test_program) < AVAILABLE_MEMORY)
  {
    unsigned char i;
    for(i = 0; i < sizeof(test_program); i++)
      program[i] = test_program[i];
  }
}

void write_test_program_to_storage()
{
  FILE* f = fopen("./program/test_program","wb");

  if(f == NULL) return;
  
  unsigned char i;
  for(i = 0; i < sizeof(test_program); i++)
  {
    fputc(test_program[i],f);
  }

  fclose(f);
}

void read_test_program_from_storage()
{
  FILE* f = fopen("./program/test_program","rb");

  if(f == NULL) return;
  
  unsigned char i = 0;
  while((program[i++] = (unsigned char)fgetc(f)) == EOF);

  fclose(f);
}
