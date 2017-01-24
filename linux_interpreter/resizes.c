unsigned int resize_array(DATA_TYPE target, DATA_TYPE capacity)
{
  if(capacity == data[target].capacity) return 0;
  if(capacity == 0) return 1;

  DATA_TYPE* new = (DATA_TYPE*) mmap(NULL, capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1 ,0);

  if(new == MAP_FAILED)
   return 1;

  DATA_TYPE loop = 0;
  DATA_TYPE length = data[target].capacity*(data[target].capacity < capacity) + capacity*(data[target].capacity > capacity);
  for(;loop < length; loop++)
  {
    new[loop] = data[target].data[loop];
  }

  munmap(data[target].data, data[target].capacity);

  data[target].data = new;
  data[target].capacity = capacity;

  return 0;
}

unsigned int resize_program(DATA_TYPE capacity)
{
  if(capacity == program_capacity) return 0;

  if(capacity > MAX_VALUE/PROGRAM_CHUNK_SIZE) capacity = (DATA_TYPE) MAX_VALUE / PROGRAM_CHUNK_SIZE;

  DATA_TYPE** new = (DATA_TYPE**) mmap(NULL, capacity * sizeof(DATA_TYPE*), PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1 ,0);

  if(new == MAP_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = program_capacity*(program_capacity < capacity) + capacity*(program_capacity > capacity);

  for(loop = 0; loop < length; loop++)
  {
    new[loop] = program[loop];
  }

  munmap(program, program_capacity);

  //allocate mem for new pointers if capacity increased
  if(capacity > program_capacity)
  {
    for(loop = program_capacity; loop < capacity; loop++)
    {
      new[loop] = (DATA_TYPE*) mmap(NULL, PROGRAM_CHUNK_SIZE * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

      if(new[loop] == NULL)
       return 2;
    }
  }

  program = new;
  program_capacity = capacity;

  return 0;
}

unsigned int resize_data(DATA_TYPE capacity)
{
  if(capacity == data_capacity ) return 0;
  if(capacity < 2) return 1;

  struct ARRAY* new = (struct ARRAY*) mmap(NULL, capacity * sizeof(struct ARRAY), PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1 ,0);

  if(new == MAP_FAILED)
   return 2;

  DATA_TYPE loop = 0;
  DATA_TYPE length = data_capacity*(data_capacity < capacity) + capacity*(data_capacity > capacity);
  for(;loop < length; loop++)
  {
    new[loop] = data[loop];
  }

  munmap(data,data_capacity);

  //allocate mem for new pointers if capacity increased
  if(capacity > data_capacity)
  {
    DATA_TYPE loop;
    for(loop = data_capacity; loop < capacity; loop++)
    {
      new[loop].capacity = DEFAULT_SIZE;
      new[loop].data = (DATA_TYPE*) mmap(NULL, new[loop].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1 ,0);

      if(new[loop].data = MAP_FAILED)
       return 2;
    }
  }

  data = new;
  data_capacity = capacity;

  return 0;
}
