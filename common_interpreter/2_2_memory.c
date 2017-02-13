#include "resizes.c"

DATA_TYPE insert_array(DATA_TYPE write_to_address, DATA_TYPE read_from_address)
{
  
  
  return 0;
}

DATA_TYPE allocate_memory()
{
  program_capacity = 0;
  
  data_capacity = DEFAULT_SIZE*(DEFAULT_SIZE >= (NUMBER_OF_DEFAULT_ARRAYS - 1)) + (NUMBER_OF_DEFAULT_ARRAYS-1)*(DEFAULT_SIZE < (NUMBER_OF_DEFAULT_ARRAYS-1));

  //MEMORY
  memory = ALLOCATE_MEMORY( 1, struct ARRAY* )

  if(memory == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'memory'.\n",0,0,0)
    #endif
    return 1;
  }

  //DATA
  memory[DATA] = ALLOCATE_MEMORY( data_capacity, struct ARRAY )

  if(memory[DATA] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'memory[DATA]'.\n",0,0,0)
    #endif
    return 1;
  }

  //HEADS
  memory[DATA][HEADS].capacity = NUMBER_OF_HEAD_COMPONENTS - 1;
  memory[DATA][HEADS].data = ALLOCATE_MEMORY( memory[DATA][HEADS].capacity, DATA_TYPE )

  if(memory[DATA][HEADS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][HEADS].data'.\n",0,0,0)
    #endif
    return 1;
  }

  HEAD_GRANULARITY_AT(0) = MAX_VALUE;

  // FLAGS array
  memory[DATA][FLAGS].capacity = NUMBER_OF_FLAGS - 1;
  memory[DATA][FLAGS].data = ALLOCATE_MEMORY( memory[DATA][FLAGS].capacity, DATA_TYPE )

  if(memory[DATA][FLAGS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][FLAGS].data'.\n",0,0,0)
    #endif
    return 1;
  }

  // MACHINE_INFO array
  memory[DATA][MACHINE_INFO].capacity = NUMBER_OF_INFO_ELEMENTS - 1;
  memory[DATA][MACHINE_INFO].data = load_machine_info();

  if(memory[DATA][MACHINE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][MACHINE_INFO].data'.\n",0,0,0)
    #endif
    return 1;
  }

  // PERFORMANCE_INFO array
  memory[DATA][PERFORMANCE_INFO].capacity = NUMBER_OF_PROGRAMS - 1;
  memory[DATA][PERFORMANCE_INFO].data = load_performance_info();

  if(memory[DATA][PERFORMANCE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][PERFORMANCE_INFO].data.\n'",0,0,0)
    #endif
    return 1;
  }
  
  DATA_TYPE loop = NUMBER_OF_DEFAULT_ARRAYS;

  while(loop <= data_capacity)
  {
     memory[DATA][loop].capacity = DEFAULT_SIZE;
     memory[DATA][loop].data = ALLOCATE_MEMORY( memory[DATA][loop].capacity, DATA_TYPE )

     if(memory[DATA][loop].data == MEMORY_ALLOCATION_FAILED)
     {
        #ifdef TESTING_CLI
        PRINT("Couldn't allocate memory for 'memory[DATA][%u].data'.\n",loop,0,0)
        #endif
        return 1;
     }

     loop++;
  }
  
  //PROGRAM
  memory[PROGRAM] = ALLOCATE_MEMORY( program_capacity, struct ARRAY )

  if(memory[PROGRAM] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Coulnd't allocate memory for 'memory[PROGRAM]'.\n",0,0,0)
    #endif
    return 1;
  }
  
  loop = 0;

  while(loop <= program_capacity)
  {
     memory[PROGRAM][loop].capacity = PROGRAM_CHUNK_SIZE;
     memory[PROGRAM][loop].data = ALLOCATE_MEMORY( memory[PROGRAM][loop].capacity, DATA_TYPE )

     if(memory[PROGRAM][loop].data == MEMORY_ALLOCATION_FAILED)
     {
       #ifdef TESTING_CLI
       PRINT("Couldn't allocate memory for 'memory[PROGRAM][%u]'.\n",loop,0,0)
       #endif
       return 1;
     }

     loop++;
  }

  return 0;
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
