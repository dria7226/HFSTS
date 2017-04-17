#ifdef CLIT
if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif

//head_index advance
head_index += (++granularity_counter >= HEAD_GRANULARITY_AT(head_index));
head_index *= ((CAPACITY_AT(HEADS) / NUMBER_OF_HEAD_ELEMENTS) > head_index);
granularity_counter *= (HEAD_GRANULARITY_AT(head_index) > granularity_counter);

//array and index check
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