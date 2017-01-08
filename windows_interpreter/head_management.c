head_index += (++granularity_counter == SETTING_AT(HEAD_GRANULARITY));
head_index *= (data[HEADS].capacity > head_index);
granularity_counter *= (SETTING_AT(HEAD_GRANULARITY) > granularity_counter);

#ifdef TESTING
  if(granularity_counter == 0) PRINT("HEAD: %u\n",head_index,0,0)
#endif
