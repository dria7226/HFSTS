#include "resizes.c"

void allocate_memory()
{
  program_capacity = DEFAULT_SIZE;

  data_capacity = DEFAULT_SIZE*(DEFAULT_SIZE > NUMBER_OF_DEFAULT_ARRAYS) + NUMBER_OF_DEFAULT_ARRAYS*(DEFAULT_SIZE < NUMBER_OF_DEFAULT_ARRAYS);

  //DATA
  data = (struct ARRAY*) mmap(NULL, data_capacity * sizeof(struct ARRAY), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  if(data == NULL)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'data'.\n",0,0,0)
    #endif
    return 0;
  }

  //HEADS
  data[HEADS].capacity = 4;
  data[HEADS].data = (DATA_TYPE*)mmap(NULL, data[HEADS].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  if(data[HEADS].data == NULL)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'data[HEADS].data'.\n",0,0,0)
    #endif
    return 0;
  }

  HEAD_GRANULARITY_AT(0) = MAX_VALUE;

  // FLAGS array
  data[FLAGS].capacity = NUMBER_OF_FLAGS;
  data[FLAGS].data = (DATA_TYPE*)mmap(NULL, data[FLAGS].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  if(data[FLAGS].data == NULL)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'data[FLAGS].data'.\n",0,0,0)
    #endif
    return 0;
  }

  // MACHINE_INFO array
  data[MACHINE_INFO].capacity = NUMBER_OF_INFO_ELEMENTS;
  data[MACHINE_INFO].data = load_machine_info();

  if(data[MACHINE_INFO].data == NULL)
  {
    #ifdef TESTING_CLI
      PRINT("Couldn't allocate memory for 'data[MACHINE_INFO].data'.\n",0,0,0)
    #endif
    return 0;
  }

  // PERFORMANCE_INFO array
  data[PERFORMANCE_INFO].capacity = NUMBER_OF_PROGRAMS;
  data[PERFORMANCE_INFO].data = load_performance_info();

  if(data[PERFORMANCE_INFO].data == NULL)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'data[PERFORMANCE_INFO].data'.\n",0,0,0)
    #endif
    return 0;
  }

  DATA_TYPE loop = NUMBER_OF_DEFAULT_ARRAYS;

  while(loop < data_capacity)
  {
     data[loop].capacity = DEFAULT_SIZE;
     data[loop].data = (DATA_TYPE*) mmap(NULL, data[loop].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

     if(data[loop].data == NULL)
     {
        #ifdef TESTING_CLI
          PRINT("Couldn't allocate memory for 'data[%u].data'",loop,0,0)
        #endif
        return 0;
     }

     loop++;
  }

  //PROGRAM
  program = (DATA_TYPE**) mmap(NULL, program_capacity * sizeof(DATA_TYPE*), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  if(program == NULL)
  {
    #ifdef TESTING_CLI
      PRINT("Coulnd't allocate memory for 'program'.\n",0,0,0)
    #endif
    return 0;
  }

  loop = 0;

  while(loop < program_capacity)
  {
     program[loop] = (DATA_TYPE*) mmap(NULL, PROGRAM_CHUNK_SIZE * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

     if(program[loop] == NULL)
     {
       #ifdef TESTING_CLI
         PRINT("Couldn't allocate memory for 'program[%u]',\n",loop,0,0)
       #endif
       return 0;
     }

     loop++;
  }
}

void free_memory()
{
  //loop program
  DATA_TYPE loop = 0;

  if(program)
  {
    while(loop < program_capacity)
    {
      if(program[loop]) munmap(program[loop], PROGRAM_CHUNK_SIZE);
      loop++;
    }

    munmap(program, data_capacity);
  }

  loop = 0;
  
  if(data)
  {
    while(loop < data_capacity)
    {
      if(data[loop].data) munmap(data[loop].data, data[loop].capacity);
      loop++;
    }

    munmap(data, data_capacity);
  }
}
