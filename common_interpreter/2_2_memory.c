#include "resizes.c"

DATA_TYPE insert_array(DATA_TYPE insert_to_address, DATA_TYPE insert_from_address)
{
  DATA_TYPE write_to = TRANSFER_TYPE_AT(head_index, WRITE_TO);
  DATA_TYPE read_from = TRANSFER_TYPE_AT(head_index, READ_FROM);

  if(write_to == CONSTANT || read_from == CONSTANT) return 1;
  
  DATA_TYPE loop;
  
  if(write_to != read_from)
  {
    capacity[write_to]++;
    capacity[read_from]--;

    struct ARRAY* new_write_to = ALLOCATE_MEMORY(capacity[write_to], struct ARRAY)
    if(new_write_to == MEMORY_ALLOCATION_FAILED)
    {
      #ifdef TESTING_CLI
      PRINT("Couldn't allocate memory to 'new_write_to'.\n",0,0,0)
      #endif
      return 2;
    }

    struct ARRAY* new_read_from = ALLOCATE_MEMORY(capacity[read_from], struct ARRAY)
    if(new_read_from == MEMORY_ALLOCATION_FAILED)
    {
      #ifdef TESTING_CLI
      PRINT("Couldn't allocate memory to 'new_read_from'.\n",0,0,0)
      #endif
      return 2;
    }

    //the insertion
    new_write_to[insert_to_address] = memory[read_from][insert_from_address];

    //--------------------------------------------
    for(loop = 0; loop < insert_to_address; loop++)
      new_write_to[loop] = memory[write_to][loop];

    for(loop++; loop < capacity[write_to]; loop++)
      new_write_to[loop] = memory[write_to][loop-1];

    DEALLOCATE_MEMORY(memory[write_to], capacity[write_to])

    memory[write_to] = new_write_to;

    //---------------------------------------------
    for(loop = 0; loop < insert_from_address; loop++)
      new_read_from[loop] = memory[read_from][loop];

    for(; loop < capacity[read_from]; loop++)
      new_read_from[loop] = memory[read_from][loop+1];

    DEALLOCATE_MEMORY(memory[read_from], capacity[read_from])

    memory[read_from] = new_read_from;
  }
  else
  {
    if(insert_to_address = insert_from_address) return 0;

    struct ARRAY* target_array = memory[read_from][insert_from_address];
    
    DATA_TYPE step = 1*(insert_to_address > insert_from_address) + -1*(insert_from_address > insert_to_address);
    
    for(loop = insert_from_address; loop != insert_to_address; loop += step )
      memory[write_to][loop + step] = memory[read_from][loop];

    memory[write_to][insert_to_address] = target_array;
  }  

  return 0;
}

DATA_TYPE allocate_memory()
{
  capacity[PROGRAM] = 0;
  
  capacity[DATA] = DEFAULT_CAPACITY*(DEFAULT_CAPACITY >= (NUMBER_OF_DEFAULT_ARRAYS - 1)) + (NUMBER_OF_DEFAULT_ARRAYS-1)*(DEFAULT_CAPACITY < (NUMBER_OF_DEFAULT_ARRAYS-1));

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
  memory[DATA] = ALLOCATE_MEMORY( capacity[DATA], struct ARRAY )

  if(memory[DATA] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory to 'memory[DATA]'.\n",0,0,0)
    #endif
    return 1;
  }

  //HEADS
  memory[DATA][HEADS].capacity = NUMBER_OF_HEAD_ELEMENTS - 1;
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
  memory[DATA][MACHINE_INFO].capacity = NUMBER_OF_MACHINE_INFO_ELEMENTS - 1;
  memory[DATA][MACHINE_INFO].data = load_machine_info();

  if(memory[DATA][MACHINE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][MACHINE_INFO].data'.\n",0,0,0)
    #endif
    return 1;
  }
  
  // CORE_PROGRAMS_INFO array
  memory[DATA][CORE_PROGRAMS_INFO].capacity = (NUMBER_OF_CORE_PROGRAMS - 1) * NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS;
  memory[DATA][CORE_PROGRAMS_INFO].data = load_core_programs_info();

  if(memory[DATA][CORE_PROGRAMS_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][CORE_PROGRAMS_INFO].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // KEYBOARD_STATE
  memory[DATA][KEYBOARD_STATE].capacity = NUMBER_OF_KEYBOARD_STATES - 1;
  memory[DATA][KEYBOARD_STATE].data = ALLOCATE_MEMORY( memory[DATA][KEYBOARD_STATE].capacity, DATA_TYPE );

  if(memory[DATA][KEYBOARD_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][KEYBOARD_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // MOUSE_STATE
  memory[DATA][MOUSE_STATE].capacity = NUMBER_OF_MOUSE_STATES - 1;
  memory[DATA][MOUSE_STATE].data = ALLOCATE_MEMORY( memory[DATA][MOUSE_STATE].capacity, DATA_TYPE );

  if(memory[DATA][MOUSE_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][MOUSE_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // JOYSTICK_STATE
  memory[DATA][JOYSTICK_STATE].capacity = NUMBER_OF_JOYSTICK_STATES - 1;
  memory[DATA][JOYSTICK_STATE].data = ALLOCATE_MEMORY( memory[DATA][JOYSTICK_STATE].capacity, DATA_TYPE );

  if(memory[DATA][JOYSTICK_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Couldn't allocate memory for 'memory[DATA][JOYSTICK_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // the rest of data
  DATA_TYPE loop = NUMBER_OF_DEFAULT_ARRAYS;

  while(loop <= capacity[DATA])
  {
     memory[DATA][loop].capacity = DEFAULT_CAPACITY;
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
  memory[PROGRAM] = ALLOCATE_MEMORY( capacity[PROGRAM], struct ARRAY )

  if(memory[PROGRAM] == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef TESTING_CLI
    PRINT("Coulnd't allocate memory for 'memory[PROGRAM]'.\n",0,0,0)
    #endif
    return 1;
  }
  
  loop = 0;

  while(loop <= capacity[PROGRAM])
  {
     memory[PROGRAM][loop].capacity = DEFAULT_CAPACITY;
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
    while(loop <= capacity[PROGRAM])
    {
      if(memory[PROGRAM][loop].data != MEMORY_ALLOCATION_FAILED) DEALLOCATE_MEMORY(memory[PROGRAM][loop].data, memory[PROGRAM][loop].capacity);
      loop++;
    }

    DEALLOCATE_MEMORY(memory[PROGRAM], capacity[PROGRAM]);
  }

  loop = 0;

  if(memory[DATA] != MEMORY_ALLOCATION_FAILED)
  {
    while(loop <= capacity[DATA])
    {
      if(memory[DATA][loop].data != MEMORY_ALLOCATION_FAILED) DEALLOCATE_MEMORY(memory[DATA][loop].data, memory[DATA][loop].capacity);
      loop++;
    }

    DEALLOCATE_MEMORY(memory[DATA], capacity[PROGRAM]);
  }
}
