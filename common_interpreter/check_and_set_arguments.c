#define CURRENT_ARRAY HEAD_ELEMENT_AT(head_index, ARRAY)

while(argument_index < MEMORY_AT(CORE_PROGRAMS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
{
  switch(AT_HEAD_OFFSET(argument_index*2 + 1))
  {
    case IMMEDIATE:
    {
      #include "check_and_set_IMMEDIATE.c"
    }
    
    case DIRECT:
    {
      #include "check_and_set_DIRECT.c"
    }

    case POSITIVE_RELATIVE:
    {
      #include "check_and_set_POSITIVE_RELATIVE.c"
    }

    case NEGATIVE_RELATIVE:
    {
      #include "check_and_set_NEGATIVE_RELATIVE.c"
    }
  }
   
  argument_index++;
}
