#ifdef TESTING_CLI
if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif

head_index += (++granularity_counter >= HEAD_GRANULARITY_AT(head_index));
head_index *= ((CAPACITY_AT(HEADS) / NUMBER_OF_HEAD_COMPONENTS) > head_index);
granularity_counter *= (HEAD_GRANULARITY_AT(head_index) > granularity_counter);