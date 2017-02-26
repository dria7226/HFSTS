void* instruction_table[NUMBER_OF_PROGRAMS] = {
#define LABEL_MODE
#define ENUMERATE
#include "core_programs.c" 
};

DATA_TYPE* a = &(MEMORY_AT(DATA, FLAGS, 1));
DATA_TYPE* b = &(MEMORY_AT(DATA, FLAGS, 2));

#ifdef TESTING_CLI
  no_of_messages = 0;
#endif

next_instruction:

#include "4_1_head_management.c"

#ifdef TESTING_CLI
CHECK_FOR_LIMIT
PRINT("%u: ", HEAD_AT(head_index),0,0);
#endif

FLAG_AT(FLAG_SET) = 0;

if(HEAD_AT(head_index) >= program_capacity * PROGRAM_CHUNK_SIZE - 2)
  goto out;

if(AT_HEAD_OFFSET(0) < NUMBER_OF_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef TESTING_CLI
PRINT("Invalid program code\n",0,0,0);
#endif

#define INTERPRETER_MODE
#include "core_programs.c"

out:
