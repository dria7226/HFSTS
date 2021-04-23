void* instruction_table[] = {
#define NAME_MODE
#define TURN_TO_LABEL
#define ENUMERATE
#include "core/instructions.c"
};

//Working variables
DATA_TYPE* temp[4];
DATA_TYPE  instruction, argument_index;
DATA_TYPE  target_array, target_index;

//IO_TYPE* file;

#ifdef CLIT
no_of_messages = 0;
#endif

next_instruction:

//#include "4_1_head_management.c"

#ifdef CLIT
#include "4_2_program_readout.c"
#endif

argument_index = 0;

#include "check_and_set_arguments.c"

PRINT("  *instruction_table[%u]\n",AT_HEAD_OFFSET(0),0,0)

instruction = AT_HEAD_OFFSET(0);
instruction *= instruction < NUMBER_OF_CORE_INSTRUCTIONS;
goto *instruction_table[instruction];

//When there's no valid code, the interpreter will execute the next label under this comment, which should be EMPTY
#ifdef CLIT
PRINT("Invalid program code.\n",0,0,0);
#endif

#define IMPLEMENTATION_MODE
#include "core/instructions.c"

advance_head:
ADVANCE_HEAD
goto next_instruction;

EXIT:
