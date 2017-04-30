void* instruction_table[] = {
#define LABEL_MODE
#define ENUMERATE
#include "core_programs.c" 
};

//working variables
DATA_TYPE* temp[4];
DATA_TYPE  argument_index;
IO_TYPE* file;

#ifdef CLIT
no_of_messages = 0;
#endif

next_instruction:

#include "4_1_head_management.c"

#ifdef CLIT
CHECK_FOR_LIMIT
PRINT("%u:%u: ", ARRAY_AT(head_index), INDEX_AT(head_index),0);
#endif

argument_index = 0;

if(AT_HEAD_OFFSET(0) < NUMBER_OF_CORE_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef CLIT
PRINT("Invalid program code.\n",0,0,0);
#endif

//When there's no valid code, the interpreter will execute the next label under this comment, which should be EMPTY
#define INTERPRETER_MODE
#include "core_programs.c"

out:
