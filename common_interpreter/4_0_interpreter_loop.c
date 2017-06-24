void* instruction_table[] = {
#define TURN_TO_LABEL
#define NAME_MODE
#define ENUMERATE
#include "core_programs.c" 
};

//working variables
DATA_TYPE* temp[4];
DATA_TYPE  argument_index;
DATA_TYPE  target_array, target_index;

//IO_TYPE* file;

#ifdef CLIT
no_of_messages = 0;
#endif

next_instruction:

#include "4_1_head_management.c"

#ifdef CLIT
#include "4_2_program_readout.c"
#endif

argument_index = 0;

#include "check_and_set_arguments.c"

if(AT_HEAD_OFFSET(0) < NUMBER_OF_CORE_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef CLIT
PRINT("Invalid program code.\n",0,0,0);
#endif

//When there's no valid code, the interpreter will execute the next label under this comment, which should be EMPTY
#define IMPLEMENTATION_MODE
#include "core_programs.c"

out:
