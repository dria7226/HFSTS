DATA_TYPE resize_array(DATA_TYPE target, DATA_TYPE new_capacity)
{
  if(new_capacity == memory[target].capacity) return 0;

  // Question: What happens when the array downsizes itself past the current index?
  // Answer: It goes with the standard procedure for overflown indices in the interpreter loop.
  
  if(target < NUMBER_OF_DEFAULT_ARRAYS && target != HEADS) return 1;
  if(target == HEADS && new_capacity < NUMBER_OF_HEAD_ELEMENTS - 1) return 3;
  
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

  // Question: What happens when the array downsizes the memory past itself?
  // Answer: It goes wit the standard procedure for overflown array indices in the interpreter loop.
  
  if(new_capacity < NUMBER_OF_DEFAULT_ARRAYS) return 1;
  
  struct ARRAY* new = ALLOCATE_MEMORY( new_capacity, struct ARRAY )

  if(new == MEMORY_ALLOCATION_FAILED) return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = capacity * (capacity < new_capacity) + new_capacity * (capacity > new_capacity);

  for(loop = 0; loop <= length; loop++)
  {
    new[loop].data = memory[loop].data;
    new[loop].capacity = memory[loop].capacity;
  }

  DEALLOCATE_MEMORY(memory, capacity);

  //allocate memory for new pointers if capacity increased
  if(new_capacity > capacity)
  {
    for(loop = capacity; loop <= new_capacity; loop++)
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
