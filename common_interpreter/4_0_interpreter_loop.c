void* instruction_table[] = {
#define NAME_MODE
#define TURN_TO_LABEL
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

PRINT("\n",0,0,0)

argument_index = 0;

PRINT("Checking arguments\n",0,0,0)
#include "check_and_set_arguments.c"

PRINT("*temp[0] = %u\n",*temp[0],0,0)
PRINT("*instruction_table[%u] \n",AT_HEAD_OFFSET(0),0,0)

if(AT_HEAD_OFFSET(0) < NUMBER_OF_CORE_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef CLIT
PRINT("Invalid program code.\n",0,0,0);
#endif

//When there's no valid code, the interpreter will execute the next label under this comment, which should be EMPTY
#define IMPLEMENTATION_MODE
#include "core_programs.c"

out:
