//PROGRAMS
//  - a program node is a graph composed of user made or core programs
//  - resizable
//  - programs are groups of other programs and/or core programs

// program memory has a maximum capacity depending on the DATA_TYPE size (4 GB for 32 bits)
// program memory is organized in a 2d array, forming a list of program chunks (resizable array of unresizable arrays with the constant size of PROGRAM_CHUNK_SIZE)

//DATA
//  - all data is global
//  - resizable

  // Everything is in units of 32 bits ( unsigned int )

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
