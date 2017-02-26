DATA_TYPE resize_array(DATA_TYPE type, DATA_TYPE target, DATA_TYPE new_capacity)
{
  if(new_capacity == memory[type][target].capacity) return 0;

  DATA_TYPE* new = ALLOCATE_MEMORY( capacity, DATA_TYPE )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = memory[type][target].capacity * (memory[type][target].capacity < new_capacity) + new_capacity * (memory[type][target].capacity > new_capacity);
  for(;loop <= length; loop++)
  {
    new[loop] = memory[type][target].data[loop];
  }

  DEALLOCATE_MEMORY( memory[type][target].data, memory[type][target].capacity);

  memory[type][target].data = new;
  memory[type][target].capacity = new_capacity;

  return 0;
}

DATA_TYPE resize_memory(DATA_TYPE type,  DATA_TYPE new_capacity)
{
  if(new_capacity == capacity[type]) return 0;

  //account for default arrays in DATA
  if(type == DATA && capacity <= NUMBER_OF_DEFAULT_ARRAYS) return 1;
  
  struct ARRAY* new = ALLOCATE_MEMORY( new_capacity, struct ARRAY )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = capacity[type] * (capacity[type] < new_capacity) + new_capacity * (capacity[type] > new_capacity);

  for(loop = 0; loop < length; loop++)
  {
    new[loop] = memory[type][loop];
  }

  DEALLOCATE_MEMORY(memory[type], capacity[type]);

  //allocate memory for new pointers if capacity increased
  if(new_capacity > capacity[type])
  {
    for(loop = capacity[type]; loop < new_capacity; loop++)
    {
      new[loop].capacity = DEFAULT_SIZE;
      new[loop].data = ALLOCATE_MEMORY( new[loop].capacity, DATA_TYPE )

      if(new[loop].data == MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory[type] = new;
  capacity[type] = new_capacity;
  
  return 0;
}
