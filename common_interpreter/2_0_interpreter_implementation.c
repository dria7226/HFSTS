//PROGRAMS
// program memory has a maximum capacity depending on the DATA_TYPE size (4 GB for 32 bits)
// program memory is organized in a 2d array, forming a list of ARRAYs

//DATA
//  - all data is global
//  - list of ARRAYs

// Everything is in units of 32 bits ( unsigned long int )

#include "2_0_interpreter_definitions.c"

//CLIT messages
#ifdef CLIT
#include "testing_messages.c"

char ** index_type_text[] = {
  "IMMEDIATE",
  "DIRECT",
  "NEGATIVE_RELATIVE",
  "POSITIVE_RELATIVE"
};

char** core_programs_text[] = {
  #define NAME_MODE
  #define STRINGIFY
  #define ENUMERATE
  #include "core_programs.c"
};
#endif

struct ARRAY* memory;

DATA_TYPE  capacity;

DATA_TYPE  head_index;
DATA_TYPE  granularity_counter;

#include "2_1_interpreter_default_arrays.c"

#include "2_2_memory.c"
