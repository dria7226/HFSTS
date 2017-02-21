DATA_TYPE resize_array(DATA_TYPE type, DATA_TYPE target, DATA_TYPE capacity)
{
  if(capacity == memory[type][target].capacity) return 0;

  DATA_TYPE* new = ALLOCATE_MEMORY( capacity, DATA_TYPE )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = memory[type][target].capacity * (memory[type][target].capacity < capacity) + capacity * (memory[type][target].capacity > capacity);
  for(;loop <= length; loop++)
  {
    new[loop] = memory[type][target].data[loop];
  }

  DEALLOCATE_MEMORY( memory[type][target].data, memory[type][target].capacity);

  memory[type][target].data = new;
  memory[type][target].capacity = capacity;

  return 0;
}

DATA_TYPE resize_memory(DATA_TYPE type,  DATA_TYPE capacity)
{
  if(capacity == program_capacity) return 0;

  //account for default arrays in DATA
  
  struct ARRAY* new = ALLOCATE_MEMORY( capacity, struct ARRAY )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = program_capacity*(capacity[PROGRAM] < capacity) + capacity*(capacity[PROGRAM] > capacity);

  for(loop = 0; loop < length; loop++)
  {
    new[loop] = memory[PROGRAM][loop];
  }

  DEALLOCATE_MEMORY(memory[PROGRAM], capacity[PROGRAM]);

  //allocate memory for new pointers if capacity increased
  if(capacity > capacity[PROGRAM])
  {
    for(loop = capacity[PROGRAM]; loop < capacity; loop++)
    {
      new[loop].capacity = PROGRAM_CHUNK_SIZE;
      new[loop].data = ALLOCATE_MEMORY( new[loop].capacity, DATA_TYPE )

      if(new[loop].data == MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory[PROGRAM] = new;
  capacity[PROGRAM] = capacity;
  
  return 0;
}
