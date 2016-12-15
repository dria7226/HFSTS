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

#include "3_0_interpreter_definitions.c"

DATA_TYPE**      program;
DATA_TYPE        program_capacity;

struct VECTOR*   data;
DATA_TYPE        data_capacity;

HANDLE*          threads;
DATA_TYPE        thread_capacity;

#include "3_1_resizes.c"

DWORD WINAPI interpret(LPVOID lpParam)
{
  #include "interpreter_loop.c"
}

#include "3_2_threads.c"

#include "3_3_memory.c"
