#include "resizes.c"

void allocate_memory()
{
  program_capacity = DEFAULT_SIZE;

  data_capacity = DEFAULT_SIZE;

  head_capacity = 1;

  printf("program: %u\n",program);
  //PROGRAM
  program = (DATA_TYPE**) VirtualAlloc(NULL, program_capacity * sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
  printf("program: %u\n", program);
  
  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
     program[loop] = (DATA_TYPE*) VirtualAlloc(NULL, PROGRAM_CHUNK_SIZE * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

     loop++;
  }

  //DATA
  data = (struct VECTOR*) VirtualAlloc(NULL, data_capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  loop = 0;

  while(loop < data_capacity)
  {
     data[loop].capacity = DEFAULT_SIZE;
     data[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, data[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

     loop++;
  }

  //HEADS
  heads = (DATA_TYPE*) VirtualAlloc(NULL, head_capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
}

void free_memory()
{
  //loop program
  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
    VirtualFree(program[loop], 0, MEM_RELEASE);
    loop++;
  }

  VirtualFree(&program, 0, MEM_RELEASE);

  loop = 0;
  while(loop < data_capacity)
  {
    VirtualFree(data[loop].data, 0, MEM_RELEASE);
    loop++;
  }

  VirtualFree(&data, 0, MEM_RELEASE);

  VirtualFree(&heads, 0, MEM_RELEASE);
}
