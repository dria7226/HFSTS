#include "test_program.c"

void load_test_program()
{
  if(memory == MEMORY_ALLOCATION_FAILED) return;

  #define PROGRAM_LENGTH sizeof(test_program)/sizeof(DATA_TYPE)
  #define DATA_LENGTH sizeof(test_data)/sizeof(DATA_TYPE*)
  
  //load program
  resize_array(NUMBER_OF_DEFAULT_ARRAYS, PROGRAM_LENGTH);
  
  DATA_TYPE loop = 0;

  for(; loop < PROGRAM_LENGTH; loop++)
  {
    MEMORY_AT(NUMBER_OF_DEFAULT_ARRAYS, loop) = test_program[loop];
  }
}

void load_program_at_address(int argc, char* argv)
{
  // check argv for validity
}

// void write_test_program_to_storage()
// {
//   FILE* f = fopen("./program/test_program","wb");
//
//   if(f == NULL) return;
//
//   unsigned char i;
//   for(i = 0; i < sizeof(test_program); i++)
//   {
//     fputc(test_program[i],f);
//   }
//
//   fclose(f);
// }
//
// void read_test_program_from_storage()
// {
//   FILE* f = fopen("./program/test_program","rb");
//
//   if(f == NULL) return;
//
//   unsigned char i = 0;
//   while((program[i++] = (unsigned char)fgetc(f)) == EOF);
//
//   fclose(f);
// }
