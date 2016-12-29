#include "test_program.c"

void load_test_program()
{
  if(!(program && data)) return;

  DATA_TYPE loop = 0;

  #define PROGRAM_LENGTH sizeof(test_program)/sizeof(DATA_TYPE)
  #define DATA_LENGTH sizeof(test_data)/sizeof(DATA_TYPE*)

  //load program
  resize_program(PROGRAM_LENGTH/PROGRAM_CHUNK_SIZE + 1);

  for(; loop < PROGRAM_LENGTH; loop++)
  {
    program[loop / PROGRAM_CHUNK_SIZE][loop % PROGRAM_CHUNK_SIZE] = 0;
    program[loop / PROGRAM_CHUNK_SIZE][loop % PROGRAM_CHUNK_SIZE] = test_program[loop];
  }

  // load data
  // loop = 0;
  //
  // printf("now data \n");
  // resize_data(DATA_LENGTH + DATA_LENGTH>0);
  // for(; loop < DATA_LENGTH; loop++)
  // {
  //   resize_vector(&(data[loop]), sizeof(test_data[loop]));
  //   data[loop].capacity = sizeof(test_data[loop]);
  //   DATA_TYPE inner_loop = 0;
  //   for(; inner_loop < data[loop].capacity; inner_loop++)
  //     data[loop].data[inner_loop] = test_data[loop][inner_loop];
  // }
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
