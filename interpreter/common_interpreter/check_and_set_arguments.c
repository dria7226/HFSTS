#define CURRENT_ARRAY HEAD_ELEMENT_AT(head_index, ARRAY)

while(argument_index < MEMORY_AT(CORE_INSTRUCTIONS_INFO, AT_HEAD_OFFSET(0)*NUMBER_OF_CORE_INSTRUCTIONS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS) )
{
  PRINT("Verifying argument %u\n",argument_index,0,0)

  if(AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 1) >= NUMBER_OF_INDEX_TYPES) { ADVANCE_HEAD }

  switch(AT_HEAD_OFFSET(argument_index*NUMBER_OF_DATA_PER_ARGUMENT + 1))
  {
    case IMMEDIATE:
    {
      PRINT("IMMEDIATE check.\n",0,0,0)
      #include "check_and_set_IMMEDIATE.c"
      break;
    }

    case DIRECT:
    {
      PRINT("DIRECT check.\n",0,0,0)
      #include "check_and_set_DIRECT.c"
      break;
    }

    case POSITIVE_RELATIVE:
    {
      PRINT("P_RELATIVE check.\n",0,0,0)
      #include "check_and_set_POSITIVE_RELATIVE.c"
      break;
    }

    case NEGATIVE_RELATIVE:
    {
      PRINT("N_RELATIVE check.\n",0,0,0)
      #include "check_and_set_NEGATIVE_RELATIVE.c"
      break;
    }
  }

  argument_index++;
}
