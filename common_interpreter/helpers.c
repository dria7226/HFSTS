#include "tests/test_program.c"

void read_test_program()
{
  if(memory == MEMORY_ALLOCATION_FAILED) return;

  #define PROGRAM_LENGTH sizeof(test_program)/sizeof(DATA_TYPE)

  //load program
  resize_memory(NUMBER_OF_DEFAULT_ARRAYS);
  resize_array(NUMBER_OF_DEFAULT_ARRAYS, PROGRAM_LENGTH);
  
  DATA_TYPE loop = 0;

  for(; loop < PROGRAM_LENGTH; loop++)
  {
    MEMORY_AT(NUMBER_OF_DEFAULT_ARRAYS, loop) = test_program[loop];
  }
}

void write_program()
{
  FILE* file;
  file = OPEN("main_array", "wb")
  WRITE_ARRAY(0, NUMBER_OF_DEFAULT_ARRAYS, CAPACITY_AT(NUMBER_OF_DEFAULT_ARRAYS))
  CLOSE(file)
}

DATA_TYPE read_program_at_address(int argc, char** argv)
{
  // check if there are any arguments
  if(argc <= 1) return 1;

  FILE* file = fopen(argv[1], "rb");

  fseek(file, 0, SEEK_END);
  unsigned long length = ftell(file);
  rewind(file);

  if(!length) return 1;

  if( fread(memory[NUMBER_OF_DEFAULT_ARRAYS].data, sizeof(DATA_TYPE), length, file) != length ) return 1;
  fclose(file);
}
