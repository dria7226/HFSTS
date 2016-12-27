#include "test_program.c"

void load_test_program()
{
  if(!(program && data)) return;

  DATA_TYPE loop = 0;

  //load program
  resize_program(sizeof(test_program)/PROGRAM_CHUNK_SIZE);
  for(; loop < sizeof(test_program); loop++)
  {
    printf("program: %u\n", program);
    program[loop / PROGRAM_CHUNK_SIZE][loop % PROGRAM_CHUNK_SIZE] = 0;

    printf("%u: ",loop);
    program[loop / PROGRAM_CHUNK_SIZE][loop % PROGRAM_CHUNK_SIZE] = test_program[loop];
    printf("program[%u][%u] = %u\n",loop / PROGRAM_CHUNK_SIZE, loop % PROGRAM_CHUNK_SIZE, program[loop/PROGRAM_CHUNK_SIZE][loop%PROGRAM_CHUNK_SIZE]);
  }

  // load data
  loop = 0;

  resize_data(sizeof(test_data));
  for(; loop < sizeof(test_data); loop++)
  {
    resize_vector(&(data[loop]), sizeof(test_data[loop]));
    data[loop].capacity = sizeof(test_data[loop]);
    DATA_TYPE inner_loop;
    for(inner_loop = 0; inner_loop < data[loop].capacity; inner_loop++)
      data[loop].data[inner_loop] = test_data[loop][inner_loop];
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
