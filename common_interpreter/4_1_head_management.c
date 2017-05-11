#ifdef CLIT
if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif

//head_index advance
head_index += (++granularity_counter >= HEAD_GRANULARITY_AT(head_index));
head_index *= (((CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS) > head_index);
granularity_counter *= (HEAD_GRANULARITY_AT(head_index) > granularity_counter);

//array and index check
DATA_TYPE number_of_consecutive_head_failures;

if(number_of_consecutive_head_failures == (CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS) goto out;

if(ARRAY_AT(head_index) > capacity
   ||
   INDEX_AT(head_index) > CAPACITY_AT(ARRAY_AT(head_index))
   ||
   INDEX_AT(head_index) + CORE_PROGRAMS_INFO [ AT_HEAD_OFFSET(0) * NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS + NUMBER_OF_ARGUMENTS ] > CAPACITY_AT(head_index))
{
  number_of_consecutive_head_failures++;
  head_index *= ++head_index < ((CAPACITY_AT(HEADS)+1) / NUMBER_OF_HEAD_ELEMENTS);
  goto next_instruction;
}

number_of_consecutive_head_failures = 0;
