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
  if(capacity > MAX_VALUE) capacity = MAX_VALUE;

  if(capacity == program_capacity) return;

  struct VECTOR** new = (struct VECTOR**) VirtualAlloc(NULL, sizeof(struct VECTOR*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new = (struct VECTOR*) VirtualAlloc(NULL, capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new, program, program_capacity*(program_capacity < capacity) + capacity*(program_capacity > capacity), PAGE_READWRITE);

  VirtualFree(program, 0, MEM_RELEASE);

  program = *new;
  program_capacity = capacity;
}

void resize_data(DATA_TYPE capacity)
{

}
