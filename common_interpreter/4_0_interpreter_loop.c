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

DATA_TYPE number_of_consecutive_head_failures;
if(number_of_consecutive_failures == CAPACITY_AT(HEADS)/NUMBER_OF_HEAD_ELEMENTS) goto out;
if(ARRAY_AT(head_index) > capacity
   ||
   INDEX_AT(head_index) > CAPACITY_AT(ARRAY_AT(head_index)))
{
  number_of_consecutive_failures++;
  head_index *= ++head_index < (CAPACITY_AT(HEADS)/NUMBER_OF_HEAD_ELEMENTS);
  goto next_instruction;
}

number_of_consecutive_failures = 0;

#ifdef CLIT
CHECK_FOR_LIMIT
PRINT("%u:%u: ", ARRAY_AT(head_index), INDEX_AT(head_index),0);
#endif

argument_index = 0;

FLAG_AT(FLAG_SET) = 0;

if(AT_HEAD_OFFSET(0) < NUMBER_OF_CORE_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef CLIT
PRINT("Invalid program code.\n",0,0,0);
#endif

//When there's no valid code, the interpreter will execute the next label under this comment, which should be EMPTY
#define INTERPRETER_MODE
#include "core_programs.c"

out:
