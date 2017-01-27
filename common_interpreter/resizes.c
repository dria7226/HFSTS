unsigned int resize_array(DATA_TYPE target, DATA_TYPE capacity)
{
  if(capacity == memory[DATA][target].capacity) return 0;
  if(capacity == 0) return 1;

  DATA_TYPE* new = (DATA_TYPE*) ALLOCATE_MEMORY( capacity * sizeof(DATA_TYPE) )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 1;

  DATA_TYPE loop = 0;
  DATA_TYPE length = memory[DATA][target].capacity*(memory[DATA][target].capacity < capacity) + capacity*(memory[DATA][target].capacity > capacity);
  for(;loop < length; loop++)
  {
    new[loop] = memory[DATA][target].data[loop];
  }

  DEALLOCATE_MEMORY( memory[DATA][target].data, memory[DATA][target].capacity);

  memory[DATA][target].data = new;
  memory[DATA][target].capacity = capacity;

  return 0;
}

unsigned int resize_program(DATA_TYPE capacity)
{
  if(capacity == program_capacity) return 0;

  if(capacity > MAX_VALUE/PROGRAM_CHUNK_SIZE) capacity = (DATA_TYPE) MAX_VALUE / PROGRAM_CHUNK_SIZE;

  struct ARRAY* new = (struct ARRAY*) ALLOCATE_MEMORY( capacity * sizeof(struct ARRAY) )

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
      new[loop].data = (DATA_TYPE*) ALLOCATE_MEMORY( new[loop].capacity * sizeof(DATA_TYPE) )

      if(new[loop].data == MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory[PROGRAM] = new;
  program_capacity = capacity;

  return 0;
}

unsigned int resize_data(DATA_TYPE capacity)
{
  if(capacity == data_capacity ) return 0;
  if(capacity < 2) return 1;

  struct ARRAY* new = (struct ARRAY*) ALLOCATE_MEMORY( capacity * sizeof(struct ARRAY) )

  if(new == MEMORY_ALLOCATION_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = data_capacity*(data_capacity < capacity) + capacity*(data_capacity > capacity);
  for(;loop < length; loop++)
  {
    new[loop] = memory[DATA][loop];
  }

  DEALLOCATE_MEMORY(memory[DATA], data_capacity);

  //allocate mem for new pointers if capacity increased
  if(capacity > data_capacity)
  {
    DATA_TYPE loop;
    for(loop = data_capacity; loop < capacity; loop++)
    {
      new[loop].capacity = DEFAULT_SIZE;
      new[loop].data = (DATA_TYPE*) ALLOCATE_MEMORY( new[loop].capacity * sizeof(DATA_TYPE) )

      if(new[loop].data = MEMORY_ALLOCATION_FAILED)
       return 2;
    }
  }

  memory[DATA] = new;
  data_capacity = capacity;

  return 0;
}
