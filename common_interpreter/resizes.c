DATA_TYPE resize_array(DATA_TYPE type, DATA_TYPE target, DATA_TYPE capacity)
{
  if(capacity == memory[DATA][target].capacity) return 0;

  DATA_TYPE* new = ALLOCATE_MEMORY( capacity, DATA_TYPE )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = memory[DATA][target].capacity*(memory[DATA][target].capacity < capacity) + capacity*(memory[DATA][target].capacity > capacity);
  for(;loop <= length; loop++)
  {
    new[loop] = memory[DATA][target].data[loop];
  }

  DEALLOCATE_MEMORY( memory[DATA][target].data, memory[DATA][target].capacity);

  memory[DATA][target].data = new;
  memory[DATA][target].capacity = capacity;

  return 0;
}

DATA_TYPE resize_memory(DATA_TYPE capacity)
{
  if(capacity == program_capacity) return 0;

  if(capacity > MAX_VALUE/(PROGRAM_CHUNK_SIZE+1)) capacity = (DATA_TYPE) MAX_VALUE /(PROGRAM_CHUNK_SIZE+1);

  //account for default arrays in DATA
  
  struct ARRAY* new = ALLOCATE_MEMORY( capacity, struct ARRAY )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = program_capacity*(program_capacity < capacity) + capacity*(program_capacity > capacity);

  for(loop = 0; loop < length; loop++)
  {
    new[loop] = memory[PROGRAM][loop];
  }

  DEALLOCATE_MEMORY(memory[PROGRAM], program_capacity);

  //allocate memory for new pointers if capacity increased
  if(capacity > program_capacity)
  {
    for(loop = program_capacity; loop < capacity; loop++)
    {
      new[loop].capacity = PROGRAM_CHUNK_SIZE;
      new[loop].data = ALLOCATE_MEMORY( new[loop].capacity, DATA_TYPE )

      if(new[loop].data == MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory[PROGRAM] = new;
  program_capacity = capacity;

  //recalculate traversal tree for PROGRAM
  
  
  return 0;
}
