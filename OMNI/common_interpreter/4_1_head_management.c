#ifdef CLIT
if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif

//head_index advance
head_index += (++granularity_counter >= HEAD_GRANULARITY_AT(head_index));
head_index *= (((CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS) > head_index);
granularity_counter *= (HEAD_GRANULARITY_AT(head_index) > granularity_counter);

DATA_TYPE number_of_consecutive_head_failures;

//halt machine if all heads are corrupted
if(number_of_consecutive_head_failures == (CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS)
goto out;

//check if current array is in bounds
if(ARRAY_AT(head_index) > capacity)                          goto array_or_index_failed;
//--------------------------------------------------------------------------------------
//check if current index is in bounds
if(INDEX_AT(head_index) > CAPACITY_AT(ARRAY_AT(head_index))) goto array_or_index_failed;
//--------------------------------------------------------------------------------------
//check if the current program and its arguments fit in bounds
if( INDEX_AT(head_index) + CORE_INSTRUCTIONS_INFO_AT( AT_HEAD_OFFSET(0) * NUMBER_OF_CORE_INSTRUCTIONS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS)
    >
    CAPACITY_AT(head_index) )                                goto array_or_index_failed;
//--------------------------------------------------------------------------------------
if(0)
{
  array_or_index_failed:
  number_of_consecutive_head_failures++;
  head_index *= ++head_index < ((CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS);
  goto next_instruction;
}
number_of_consecutive_head_failures = 0;
