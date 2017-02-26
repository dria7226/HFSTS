//MACHINE INFO
DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = ALLOCATE_MEMORY( memory[DATA][MACHINE_INFO].capacity, DATA_TYPE )

  if(machine_info == MEMORY_ALLOCATION_FAILED)
  {
    return MEMORY_ALLOCATION_FAILED;
  }

  machine_info[0] = MAX_VALUE;

  machine_info[PLATFORM] = CURRENT_PLATFORM;

  return machine_info;
}

//CORE_PROGRAMS INFO
DATA_TYPE* load_core_programs_info()
{
  DATA_TYPE* core_programs_info = ALLOCATE_MEMORY( memory[DATA][CORE_PROGRAMS_INFO].capacity, DATA_TYPE )

  if(core_programs_info == MEMORY_ALLOCATION_FAILED)
  {
    return MEMORY_ALLOCATION_FAILED;
  }

  #define ARGUMENTS_MODE
  
  #undef ARGUMENTS_MODE
  
  return core_programs_info;
}

