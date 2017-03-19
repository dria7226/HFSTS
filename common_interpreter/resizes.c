DATA_TYPE resize_array(DATA_TYPE target, DATA_TYPE new_capacity)
{
  if(new_capacity == memory[target].capacity) return 0;

  // what happens when the array downsizes itself past the current index?
  
  if(target < NUMBER_OF_DEFAULT_ARRAYS) return 1;
  
  DATA_TYPE* new = ALLOCATE_MEMORY( new_capacity, DATA_TYPE )

  if(new == MEMORY_ALLOCATION_FAILED) return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = memory[target].capacity * (memory[target].capacity < new_capacity) + new_capacity * (memory[target].capacity > new_capacity);
  for(;loop <= length; loop++)
  {
    new[loop] = MEMORY_AT(target, loop);
  }

  DEALLOCATE_MEMORY( memory[target].data, memory[target].capacity);

  memory[target].data = new;
  memory[target].capacity = new_capacity;

  return 0;
}

DATA_TYPE resize_memory(DATA_TYPE new_capacity)
{
  if(new_capacity == capacity) return 0;

  // what happens when the array downsizes the memory past itself?
  
  if(capacity <= NUMBER_OF_DEFAULT_ARRAYS) return 1;
  
  struct ARRAY* new = ALLOCATE_MEMORY( new_capacity, struct ARRAY )

  if(new == MEMORY_ALLOCATION_FAILED) return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = capacity * (capacity < new_capacity) + new_capacity * (capacity > new_capacity);

  for(loop = 0; loop < length; loop++)
  {
    new[loop] = memory[loop];
  }

  DEALLOCATE_MEMORY(memory, capacity);

  //allocate memory for new pointers if capacity increased
  if(new_capacity > capacity)
  {
    for(loop = capacity; loop < new_capacity; loop++)
    {
      new[loop].capacity = DEFAULT_CAPACITY;
      new[loop].data = ALLOCATE_MEMORY( new[loop].capacity, DATA_TYPE )

      if(new[loop].data == MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory = new;
  capacity = new_capacity;
  
  return 0;
}
