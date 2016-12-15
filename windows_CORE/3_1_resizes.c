void resize_vector(struct VECTOR* vector, DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE) capacity = MAX_VALUE;

  if(capacity == vector->capacity) return;

  struct VECTOR* new = (struct VECTOR*) VirtualAlloc(NULL, sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  new->data = (DATA_TYPE*) VirtualAlloc(NULL, capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
  new->capacity = capacity;

  VirtualCopy(new, vector, vector->capacity*(vector->capacity < capacity) + capacity*(vector->capacity > capacity), PAGE_READWRITE);

  VirtualFree(vector, 0, MEM_RELEASE);

  vector = new;
}

void resize_program(DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE/PROGRAM_CHUNK) capacity = (DATA_TYPE) MAX_VALUE / PROGRAM_CHUNK;

  if(capacity == program_capacity) return;

  DATA_TYPE*** new = (DATA_TYPE***) VirtualAlloc(NULL, sizeof(DATA_TYPE**), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new = (DATA_TYPE**) VirtualAlloc(NULL, capacity * sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new, program, program_capacity*(program_capacity < capacity) + capacity*(program_capacity > capacity), PAGE_READWRITE);

  VirtualFree(program, 0, MEM_RELEASE);

  //allocate mem for new pointers if capacity increased
  if(capacity > program_capacity)
  {
    DATA_TYPE loop;
    for(loop = program_capacity; loop < capacity; loop++)
    {
      (*new)[loop] = (DATA_TYPE*) VirtualAlloc(NULL, PROGRAM_CHUNK * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    }
  }

  program = *new;
  program_capacity = capacity;
}

void resize_data(DATA_TYPE capacity)
{
  if(capacity > MAX_VALUE) capacity = (DATA_TYPE) MAX_VALUE;

  if(capacity == data_capacity) return;

  struct VECTOR** new = (struct VECTOR**) VirtualAlloc(NULL, sizeof(struct VECTOR*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new = (struct VECTOR*) VirtualAlloc(NULL, capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new, program, data_capacity*(data_capacity < capacity) + capacity*(data_capacity > capacity), PAGE_READWRITE);

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
