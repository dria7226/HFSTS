#include "resizes.c"

DATA_TYPE insert_array(DATA_TYPE insert_to_address, DATA_TYPE insert_from_address)
{
  if(insert_to_address < NUMBER_OF_DEFAULT_ARRAYS ) return 1;
  if(insert_to_address == insert_from_address) return 0;

  struct ARRAY target_array = memory[insert_from_address];

  DATA_TYPE step = 1*(insert_to_address > insert_from_address) + -1*(insert_from_address > insert_to_address);

  DATA_TYPE loop;
  
  for(loop = insert_from_address; loop != insert_to_address; loop += step )
    memory[loop] = memory[loop + step];

  memory[insert_to_address] = target_array;

  return 0;
}

DATA_TYPE allocate_memory()
{  
  capacity = DEFAULT_CAPACITY*(DEFAULT_CAPACITY >= NUMBER_OF_DEFAULT_ARRAYS) + NUMBER_OF_DEFAULT_ARRAYS*(DEFAULT_CAPACITY < NUMBER_OF_DEFAULT_ARRAYS);
  
  //MEMORY
  memory = ALLOCATE_MEMORY( capacity, struct ARRAY )

  if(memory == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory to 'memory'.\n",0,0,0)
    #endif
    return 1;
  }

  //HEADS
  memory[HEADS].capacity = NUMBER_OF_HEAD_ELEMENTS - 1;
  memory[HEADS].data = ALLOCATE_MEMORY( memory[HEADS].capacity, DATA_TYPE )

  if(memory[HEADS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[HEADS].data'.\n",0,0,0)
    #endif
    return 1;
  }

  ARRAY_AT(0) = NUMBER_OF_DEFAULT_ARRAYS;
  PRIMARY_AT(0) = NUMBER_OF_DEFAULT_ARRAYS;
  SECONDARY_AT(0) = NUMBER_OF_DEFAULT_ARRAYS;
  HEAD_GRANULARITY_AT(0) = MAX_VALUE;
  FAILSAFE_AT(0) = MAX_VALUE;
  
  // FLAGS array
  memory[FLAGS].capacity = NUMBER_OF_FLAGS - 1;
  memory[FLAGS].data = ALLOCATE_MEMORY( memory[FLAGS].capacity, DATA_TYPE )

  if(memory[FLAGS].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[FLAGS].data'.\n",0,0,0)
    #endif
    return 1;
  }

  // MACHINE_INFO array
  memory[MACHINE_INFO].capacity = NUMBER_OF_MACHINE_INFO_ELEMENTS - 1;
  memory[MACHINE_INFO].data = load_machine_info();

  if(memory[MACHINE_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[MACHINE_INFO].data'.\n",0,0,0)
    #endif
    return 1;
  }
  
  // CORE_PROGRAMS_INFO array
  memory[CORE_PROGRAMS_INFO].capacity = (NUMBER_OF_CORE_PROGRAMS - 1) * NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS;
  memory[CORE_PROGRAMS_INFO].data = load_core_programs_info();

  if(memory[CORE_PROGRAMS_INFO].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[CORE_PROGRAMS_INFO].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // KEYBOARD_STATE
  memory[KEYBOARD_STATE].capacity = NUMBER_OF_KEYBOARD_STATES - 1;
  memory[KEYBOARD_STATE].data = ALLOCATE_MEMORY( memory[KEYBOARD_STATE].capacity, DATA_TYPE );

  if(memory[KEYBOARD_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[KEYBOARD_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // MOUSE_STATE
  memory[MOUSE_STATE].capacity = NUMBER_OF_MOUSE_STATES - 1;
  memory[MOUSE_STATE].data = ALLOCATE_MEMORY( memory[MOUSE_STATE].capacity, DATA_TYPE );

  if(memory[MOUSE_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[MOUSE_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // JOYSTICK_STATE
  memory[JOYSTICK_STATE].capacity = NUMBER_OF_JOYSTICK_STATES - 1;
  memory[JOYSTICK_STATE].data = ALLOCATE_MEMORY( memory[JOYSTICK_STATE].capacity, DATA_TYPE );

  if(memory[JOYSTICK_STATE].data == MEMORY_ALLOCATION_FAILED)
  {
    #ifdef CLIT
    PRINT("Couldn't allocate memory for 'memory[JOYSTICK_STATE].data.\n'",0,0,0)
    #endif
    return 1;
  }

  // the rest of memory
  DATA_TYPE loop = NUMBER_OF_DEFAULT_ARRAYS;

  while(loop <= capacity)
  {
     memory[loop].capacity = DEFAULT_CAPACITY;
     memory[loop].data = ALLOCATE_MEMORY( memory[loop].capacity, DATA_TYPE )

     if(memory[loop].data == MEMORY_ALLOCATION_FAILED)
     {
        #ifdef CLIT
        PRINT("Couldn't allocate memory for 'memory[%u].data'.\n",loop,0,0)
        #endif
        return 1;
     }

     loop++;
  }

  return 0;
}

void free_memory()
{
  DATA_TYPE loop = 0;

  if(memory != MEMORY_ALLOCATION_FAILED)
  {
    while(loop <= capacity)
    {
      if(memory[loop].data != MEMORY_ALLOCATION_FAILED) DEALLOCATE_MEMORY(memory[loop].data, memory[loop].capacity);
      loop++;
    }

    DEALLOCATE_MEMORY(memory, capacity);
  }
}
