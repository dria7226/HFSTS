# 1 "new_ADD.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "new_ADD.c"


ADD:





# 1 "check_arguments.c" 1
# 14 "check_arguments.c"
argument_index = 0;


while(argument_index < DATA_AT(CORE_PROGRAMS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
{


if(MEMORY_FAILSAFE_AT(head_index))
{
# 49 "check_arguments.c"
}



  temp[argument_index] = &(MEMORY_AT(TRANSFER_TYPE_AT(head_index, argument_index), HEAD_ELEMENT_AT(head_index, SOURCE_ARRAY + argument_index), AT_HEAD_OFFSET(argument_index));

  argument_index++;
}
# 10 "new_ADD.c" 2

if(MATH_FAILSAFE_AT(head_index))
{
  SET_FLAG(OVERFLOW, *a > (*a + *b))
}

*a += *b;







HEAD_AT(head_index) += 3;
goto next_instruction;
