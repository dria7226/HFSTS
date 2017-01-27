//PROGRAMS
// program memory has a maximum capacity depending on the DATA_TYPE size (4 GB for 32 bits)
// program memory is organized in a 2d array, forming a list of program chunks (resizable array of unresizable arrays with the constant size of PROGRAM_CHUNK_SIZE)

//DATA
//  - all data is global
//  - resizable

// Everything is in units of 32 bits ( unsigned int )

#include "2_0_interpreter_definitions.c"

struct ARRAY**   memory;

DATA_TYPE        program_capacity;
DATA_TYPE        data_capacity;

DATA_TYPE  head_index;
DATA_TYPE  granularity_counter;

#include "2_1_interpreter_default_arrays.c"

#include "2_2_memory.c"
