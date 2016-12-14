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
#define PROGRAM_CHUNK 1024

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

#include "3_3_memory.c"
