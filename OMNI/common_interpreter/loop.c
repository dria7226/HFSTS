# 1 "4_0_interpreter_loop.c"
void* instruction_table[] = {



# 1 "core/instructions.c" 1
# 1 "core/EMPTY.c" 1
# 9 "core/EMPTY.c"
# 1 "core/../instruction_template.c" 1
# 51 "core/../instruction_template.c"
&&EMPTY







,
# 10 "core/EMPTY.c" 2
# 2 "core/instructions.c" 2
# 1 "core/EXIT.c" 1
# 9 "core/EXIT.c"
# 1 "core/../instruction_template.c" 1
# 51 "core/../instruction_template.c"
&&EXIT







,
# 10 "core/EXIT.c" 2
# 3 "core/instructions.c" 2
# 1 "core/RUN_PERFORMANCE_TEST.c" 1






# 1 "core/../instruction_template.c" 1
# 51 "core/../instruction_template.c"
&&RUN_PERFORMANCE_TEST







,
# 8 "core/RUN_PERFORMANCE_TEST.c" 2
# 4 "core/instructions.c" 2
# 27 "core/instructions.c"
# 1 "core/ADD.c" 1
# 16 "core/ADD.c"
# 1 "core/../instruction_template.c" 1
# 51 "core/../instruction_template.c"
&&ADD







,
# 17 "core/ADD.c" 2
# 28 "core/instructions.c" 2
# 6 "4_0_interpreter_loop.c" 2
};


DATA_TYPE* temp[4];
DATA_TYPE  instruction, argument_index;
DATA_TYPE  target_array, target_index;







next_instruction:


head_index = 0;





argument_index = 0;

# 1 "check_and_set_arguments.c" 1


while(argument_index < MEMORY_AT(CORE_INSTRUCTIONS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_INSTRUCTIONS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
{
  PRINT("Verifying argument %u\n",argument_index,0,0)

  if(AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 1) >= NUMBER_OF_INDEX_TYPES) { ADVANCE_HEAD }

  switch(AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 1))
  {
    case IMMEDIATE:
    {
      PRINT("IMMEDIATE check.\n",0,0,0)
# 1 "check_and_set_IMMEDIATE.c" 1
temp[argument_index] = &MEMORY_AT(HEAD_ELEMENT_AT(head_index, ARRAY), AT_HEAD_OFFSET(NUMBER_OF_DATA_PER_ARGUMENT*argument_index + 2));
# 15 "check_and_set_arguments.c" 2
      break;
    }

    case DIRECT:
    {
      PRINT("DIRECT check.\n",0,0,0)
# 1 "check_and_set_DIRECT.c" 1
if(argument_index > 1)
  target_array = HEAD_ELEMENT_AT(head_index, ARRAY);
 else
  target_array = HEAD_ELEMENT_AT(head_index, PRIMARY_ARRAY + argument_index);

target_index = AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 2);

if(target_array > capacity)
{
  SET_FLAG(ARRAY_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

if(target_index > CAPACITY_AT(target_array))
{
  SET_FLAG(INDEX_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

temp[argument_index] = &MEMORY_AT(target_array, target_index);
# 22 "check_and_set_arguments.c" 2
      break;
    }

    case POSITIVE_RELATIVE:
    {
      PRINT("P_RELATIVE check.\n",0,0,0)
# 1 "check_and_set_POSITIVE_RELATIVE.c" 1
target_array = HEAD_ELEMENT_AT(head_index, ARRAY);

target_index = INDEX_AT(head_index) + AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 2);

if(target_array > capacity)
{
  SET_FLAG(ARRAY_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

if(target_index > CAPACITY_AT(target_array))
{
  SET_FLAG(INDEX_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

if(target_index > CAPACITY_AT(target_array) || target_index < INDEX_AT(head_index))
{
  SET_FLAG(OVERFLOW, argument_index + 1)





  ADVANCE_HEAD
  }

temp[argument_index] = &MEMORY_AT(target_array, target_index);
# 29 "check_and_set_arguments.c" 2
      break;
    }

    case NEGATIVE_RELATIVE:
    {
      PRINT("N_RELATIVE check.\n",0,0,0)
# 1 "check_and_set_NEGATIVE_RELATIVE.c" 1
target_array = HEAD_ELEMENT_AT(head_index, ARRAY);

target_index = INDEX_AT(head_index) - AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 2);

if(target_array > capacity)
{
  SET_FLAG(ARRAY_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

if(target_index > CAPACITY_AT(target_array))
{
  SET_FLAG(INDEX_ACCESS_FAILED, argument_index + 1)





  ADVANCE_HEAD
}

if(target_index > INDEX_AT(head_index))
{
  SET_FLAG(UNDERFLOW,argument_index+1)





  ADVANCE_HEAD
}

temp[argument_index] = &MEMORY_AT(target_array, target_index);
# 36 "check_and_set_arguments.c" 2
      break;
    }
  }

  argument_index++;
}
# 31 "4_0_interpreter_loop.c" 2

PRINT("  *instruction_table[%u]\n",AT_HEAD_OFFSET(0),0,0)

instruction = AT_HEAD_OFFSET(0);
instruction *= instruction < NUMBER_OF_CORE_INSTRUCTIONS;
goto *instruction_table[instruction];







# 1 "core/instructions.c" 1
# 1 "core/EMPTY.c" 1
# 9 "core/EMPTY.c"
# 1 "core/../instruction_template.c" 1

EMPTY :
# 34 "core/../instruction_template.c"
goto advance_head;
# 10 "core/EMPTY.c" 2
# 2 "core/instructions.c" 2
# 1 "core/EXIT.c" 1
# 9 "core/EXIT.c"
# 1 "core/../instruction_template.c" 1
# 10 "core/EXIT.c" 2
# 3 "core/instructions.c" 2
# 1 "core/RUN_PERFORMANCE_TEST.c" 1






# 1 "core/../instruction_template.c" 1

RUN_PERFORMANCE_TEST :
# 34 "core/../instruction_template.c"
goto advance_head;
# 8 "core/RUN_PERFORMANCE_TEST.c" 2
# 4 "core/instructions.c" 2
# 27 "core/instructions.c"
# 1 "core/ADD.c" 1
# 16 "core/ADD.c"
# 1 "core/../instruction_template.c" 1

ADD :


SET_FLAG(OVERFLOW, *temp[1] > (*temp[1] + *temp[0])) *temp[1] += *temp[0];
# 34 "core/../instruction_template.c"
goto advance_head;
# 17 "core/ADD.c" 2
# 28 "core/instructions.c" 2
# 45 "4_0_interpreter_loop.c" 2

advance_head:
ADVANCE_HEAD
goto next_instruction;

EXIT:
