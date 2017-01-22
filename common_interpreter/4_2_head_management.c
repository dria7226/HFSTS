#ifdef TESTING_CLI
  if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif

head_index += (++granularity_counter == HEAD_GRANULARITY_AT(head_index));
head_index *= ((data[HEADS].capacity / 2) > head_index);
granularity_counter *= (HEAD_GRANULARITY_AT(head_index) > granularity_counter);
