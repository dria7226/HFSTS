//FUNCTIONS
//  - a function node is a graph composed of user made or core functions
//  - resizable
//  - functions are groups of core functions

//DATA
//  - all data is global
//  - resizable

  // Everything is in units of 32 bits (unsigned int)

  // memory[PROGRAM][*][*] - is program memory
  // memory[PROGRAM][0-NUMBER_OF_CORE_FUNCTIONS][NULL] - are the core functions

  // memory[DATA][*][*] - is data memory
  // memory[DATA][0][*] - is memory for single variables
  // memory[DATA][1-oo] - is array memory

#define DATA_TYPE unsigned int

struct VECTOR{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF

struct VECTOR*   program;
DATA_TYPE        program_capacity;

struct VECTOR*   data;
DATA_TYPE        data_capacity;

struct HANDLE*   threads;
DATA_TYPE        thread_capacity;

#include "3_1_resizes.c"

//void* label_table[NUMBER_OF_OPCODES] = {&&MOV, &&SRC, &&DST, &&ADD, &&SUB, &&MUL, &&DIV};

void interpret()
{
  #include "interpreter_loop.c"
}

#include "3_2_threads.c"

void allocate_memory()
{
  //allocate to memory[2][256][256]

  program_capacity = 32 * (DEFAULT_SIZE > MAX_VALUE) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);

  data_capacity = 32 * (DEFAULT_SIZE > MAX_VALUE) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);

  thread_capacity = 1;

  //PROGRAM
  program = (struct VECTOR*) VirtualAlloc(NULL, program_capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
     program[loop].capacity = DEFAULT_SIZE;
     program[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, program[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

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

  //THREADS
  threads = (HANDLE*) VirtualAlloc(NULL, thread_capacity * sizeof(HANDLE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

}

void free_memory()
{
  //loop program
  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
    VirtualFree(program[loop].data, 0, MEM_RELEASE);
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

  VirtualFree(&threads, 0, MEM_RELEASE);
}
