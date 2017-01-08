void resize_array(struct ARRAY* array, DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE) capacity = MAX_VALUE;

  if(capacity == array->capacity) return;

  struct ARRAY* new = (struct ARRAY*) VirtualAlloc(NULL, sizeof(struct ARRAY), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  new->data = (DATA_TYPE*) VirtualAlloc(NULL, capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
  new->capacity = capacity;

  DATA_TYPE loop = 0;
  DATA_TYPE length = array->capacity*(array->capacity < capacity) + capacity*(array->capacity > capacity);
  for(;loop < length; loop++)
  {
    new->data[loop] = ARRAY->data[loop];
  }

  VirtualFree(ARRAY, 0, MEM_RELEASE);

  array = new;
}

void resize_program(DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE/SETTING_AT(PROGRAM_CHUNK_SIZE)) capacity = (DATA_TYPE) MAX_VALUE / SETTING_AT(PROGRAM_CHUNK_SIZE);

  if(capacity == program_capacity) return;

  DATA_TYPE** new = (DATA_TYPE**) VirtualAlloc(NULL, capacity * sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;
  DATA_TYPE length = program_capacity*(program_capacity < capacity) + capacity*(program_capacity > capacity);

  for(; loop < length; loop++)
    new[loop / SETTING_AT(PROGRAM_CHUNK_SIZE)] = (DATA_TYPE*) VirtualAlloc(NULL, SETTING_AT(PROGRAM_CHUNK_SIZE) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  for(loop = 0; loop < length*SETTING_AT(PROGRAM_CHUNK_SIZE); loop++)
  {
    new[loop / SETTING_AT(PROGRAM_CHUNK_SIZE)][loop % SETTING_AT(PROGRAM_CHUNK_SIZE)] = program[loop / SETTING_AT(PROGRAM_CHUNK_SIZE)][loop % SETTING_AT(PROGRAM_CHUNK_SIZE)];
  }

  VirtualFree(program, 0, MEM_RELEASE);

  //allocate mem for new pointers if capacity increased
  if(capacity > program_capacity)
  {
    DATA_TYPE loop;
    for(loop = program_capacity; loop < capacity; loop++)
    {
      new[loop] = (DATA_TYPE*) VirtualAlloc(NULL, SETTING_AT(PROGRAM_CHUNK_SIZE) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    }
  }

  program = new;
  program_capacity = capacity;
}

void resize_data(DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE) capacity = (DATA_TYPE) MAX_VALUE;

  if(capacity == data_capacity) return;

  struct ARRAY** new = (struct ARRAY**) VirtualAlloc(NULL, sizeof(struct ARRAY*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new = (struct ARRAY*) VirtualAlloc(NULL, capacity * sizeof(struct ARRAY), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;
  DATA_TYPE length = data_capacity*(data_capacity < capacity) + capacity*(data_capacity > capacity);
  for(;loop < length; loop++)
  {
    (*new)[loop] = data[loop];
  }

  VirtualFree(data, 0, MEM_RELEASE);

  //allocate mem for new pointers if capacity increased
  if(capacity > data_capacity)
  {
    DATA_TYPE loop;
    for(loop = data_capacity; loop < capacity; loop++)
    {
      (*new)[loop].capacity = DEFAULT_SIZE;
      (*new)[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, (*new)[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    }
  }

  data = *new;
  data_capacity = capacity;
}
