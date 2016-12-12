void allocate_memory()
{
  //allocate to memory[2][256][256]

  program_capacity = 32 * (DEFAULT_SIZE > MAX_VALUE) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);

  data_capacity = 32 * (DEFAULT_SIZE > MAX_VALUE) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);

  thread_capacity = 1;

  //PROGRAM
  program = (struct VECTOR*) VirtualAlloc(NULL, program_capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
     program[loop].capacity = DEFAULT_SIZE;
     program[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, program[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

     loop++;
  }

  //DATA
  data = (struct VECTOR*) VirtualAlloc(NULL, data_capacity * sizeof(struct VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  loop = 0;

  while(loop < data_capacity)
  {
     data[loop].capacity = DEFAULT_SIZE;
     data[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, data[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

     loop++;
  }

  //THREADS
  threads = (HANDLE*) VirtualAlloc(NULL, thread_capacity * sizeof(HANDLE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

}

void free_memory()
{
  //loop program
  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
    VirtualFree(program[loop].data, 0, MEM_RELEASE);
    loop++;
  }

  VirtualFree(&program, 0, MEM_RELEASE);

  loop = 0;
  while(loop < data_capacity)
  {
    VirtualFree(data[loop].data, 0, MEM_RELEASE);
    loop++;
  }

  VirtualFree(&data, 0, MEM_RELEASE);

  VirtualFree(&threads, 0, MEM_RELEASE);
}
