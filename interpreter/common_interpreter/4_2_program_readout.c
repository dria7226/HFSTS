CHECK_FOR_LIMIT
PRINT("%u:%u: ", ARRAY_AT(head_index), INDEX_AT(head_index),0);

PRINT("%s, ",core_instructions_text[AT_HEAD_OFFSET(0)],0,0)

argument_index = 0;
while(argument_index < core_instructions_arguments[AT_HEAD_OFFSET(0)]/NUMBER_OF_DATA_PER_ARGUMENT)
{
  #define ARGUMENT_TYPE AT_HEAD_OFFSET(1 + argument_index*NUMBER_OF_DATA_PER_ARGUMENT)
  if(ARGUMENT_TYPE >= NUMBER_OF_INDEX_TYPES)
  {
    PRINT("%u, ", ARGUMENT_TYPE,0,0)
  }
  else
  {
    PRINT("%s, ", index_type_text[ARGUMENT_TYPE],0,0)
  }

  PRINT("%u, ", AT_HEAD_OFFSET((argument_index + 1)*NUMBER_OF_DATA_PER_ARGUMENT),0,0)

  argument_index++;
}

PRINT("\n",0,0,0)
