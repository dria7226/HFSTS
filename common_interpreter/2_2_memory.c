#include "resizes.c"

DATA_TYPE allocate_memory()
{
  program_capacity = 0;

  data_capacity = DEFAULT_SIZE*(DEFAULT_SIZE >= (NUMBER_OF_DEFAULT_ARRAYS - 1)) + (NUMBER_OF_DEFAULT_ARRAYS-1)*(DEFAULT_SIZE < (NUMBER_OF_DEFAULT_ARRAYS-1));

  //MEMORY
  memory = (struct ARRAY**) ALLOCATE_MEMORY( 1 * sizeof(struct ARRAY*) )

  if(memory == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'memory'.\n",0,0,0)
    #endif
    return 0;
  }

  //DATA
  memory[DATA] = (struct ARRAY*) ALLOCATE_MEMORY( data_capacity * sizeof(struct ARRAY) )

  if(memory[DATA] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'memory[DATA]'.\n",0,0,0)
    #endif
    return 0;
  }

  //HEADS
  memory[DATA][HEADS].capacity = NUMBER_OF_HEAD_COMPONENTS - 1;
  memory[DATA][HEADS].data = (DATA_TYPE*) ALLOCATE_MEMORY( memory[DATA][HEADS].capacity * sizeof(DATA_TYPE) )

  if(memory[DATA][HEADS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][HEADS].data'.\n",0,0,0)
    #endif
    return 0;
  }

  HEAD_GRANULARITY_AT(0) = MAX_VALUE;

  // FLAGS array
  memory[DATA][FLAGS].capacity = NUMBER_OF_FLAGS - 1;
  memory[DATA][FLAGS].data = (DATA_TYPE*) ALLOCATE_MEMORY( memory[DATA][FLAGS].capacity * sizeof(DATA_TYPE) )

  if(memory[DATA][FLAGS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][FLAGS].data'.\n",0,0,0)
    #endif
    return 0;
  }

  // MACHINE_INFO array
  memory[DATA][MACHINE_INFO].capacity = NUMBER_OF_INFO_ELEMENTS - 1;
  memory[DATA][MACHINE_INFO].data = load_machine_info();

  if(memory[DATA][MACHINE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][MACHINE_INFO].data'.\n",0,0,0)
    #endif
    return 0;
  }

  // PERFORMANCE_INFO array
  memory[DATA][PERFORMANCE_INFO].capacity = NUMBER_OF_PROGRAMS - 1;
  memory[DATA][PERFORMANCE_INFO].data = load_performance_info();

  if(memory[DATA][PERFORMANCE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][PERFORMANCE_INFO].data.\n'",0,0,0)
    #endif
    return 0;
  }
  
  DATA_TYPE loop = NUMBER_OF_DEFAULT_ARRAYS;

  while(loop <= data_capacity)
  {
     memory[DATA][loop].capacity = DEFAULT_SIZE;
     memory[DATA][loop].data = (DATA_TYPE*) ALLOCATE_MEMORY( memory[DATA][loop].capacity * sizeof(DATA_TYPE) )

     if(memory[DATA][loop].data == MEMORY_ALLOCATION_FAILED)
     {
        #ifdef TESTING_CLI
        PRINT("Couldn't allocate memory for 'memory[DATA][%u].data'.\n",loop,0,0)
        #endif
        return 0;
     }

     loop++;
  }

  //PROGRAM
  memory[PROGRAM] = (struct ARRAY*) ALLOCATE_MEMORY( program_capacity * sizeof(struct ARRAY) )

  if(memory[PROGRAM] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Coulnd't allocate memory for 'memory[PROGRAM]'.\n",0,0,0)
    #endif
    return 0;
  }

  loop = 0;

  while(loop <= program_capacity)
  {
     memory[PROGRAM][loop].capacity = PROGRAM_CHUNK_SIZE;
     memory[PROGRAM][loop].data = (DATA_TYPE*) ALLOCATE_MEMORY( memory[PROGRAM][loop].capacity * sizeof(DATA_TYPE) )

     if(memory[PROGRAM][loop].data == MEMORY_ALLOCATION_FAILED)
     {
       #ifdef TESTING_CLI
       PRINT("Couldn't allocate memory for 'memory[PROGRAM][%u]'.\n",loop,0,0)
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

  if(memory[PROGRAM] != MEMORY_ALLOCATION_FAILED)
  {
    while(loop <= program_capacity)
    {
      if(memory[PROGRAM][loop].data != MEMORY_ALLOCATION_FAILED) DEALLOCATE_MEMORY(memory[PROGRAM][loop].data, PROGRAM_CHUNK_SIZE);
      loop++;
    }

    DEALLOCATE_MEMORY(memory[PROGRAM], data_capacity);
  }

  loop = 0;

  if(memory[DATA] != MEMORY_ALLOCATION_FAILED)
  {
    while(loop <= data_capacity)
    {
      if(memory[DATA][loop].data != MEMORY_ALLOCATION_FAILED) DEALLOCATE_MEMORY(memory[DATA][loop].data, memory[DATA][loop].capacity);
      loop++;
    }

    DEALLOCATE_MEMORY(memory[DATA], data_capacity);
  }
}
