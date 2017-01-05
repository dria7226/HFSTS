#include "test_program.c"

void load_test_program()
{
  if(!(program && data)) return;

  #define PROGRAM_LENGTH sizeof(test_program)/sizeof(DATA_TYPE)
  #define DATA_LENGTH sizeof(test_data)/sizeof(DATA_TYPE*)

  //load program
  resize_program(PROGRAM_LENGTH/SETTING_AT(PROGRAM_CHUNK_SIZE) + 1);

  DATA_TYPE loop = 0;

  for(; loop < PROGRAM_LENGTH; loop++)
  {
    PROGRAM_AT(loop) = test_program[loop];
  }
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
