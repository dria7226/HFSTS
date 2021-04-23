//MACHINE INFO
DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = ALLOCATE_MEMORY( memory[MACHINE_INFO].capacity, DATA_TYPE )

  if(machine_info == MEMORY_ALLOCATION_FAILED)
  {
    return MEMORY_ALLOCATION_FAILED;
  }

  machine_info[0] = MAX_VALUE;

  machine_info[PLATFORM] = CURRENT_PLATFORM;

  return machine_info;
}

//CORE_INSTRUCTIONS INFO
DATA_TYPE* load_core_instructions_info()
{
  DATA_TYPE* core_instructions_info = ALLOCATE_MEMORY( memory[CORE_INSTRUCTIONS_INFO].capacity, DATA_TYPE )

  if(core_instructions_info == MEMORY_ALLOCATION_FAILED)
  {
    return MEMORY_ALLOCATION_FAILED;
  }

  DATA_TYPE loop = 0;

  while(loop < NUMBER_OF_CORE_INSTRUCTIONS)
  {    
    core_instructions_info[loop*NUMBER_OF_CORE_INSTRUCTIONS_INFO_ELEMENTS+NUMBER_OF_ARGUMENTS] = core_instructions_arguments[loop];

    core_instructions_arguments[loop] *= NUMBER_OF_DATA_PER_ARGUMENT;
    
    loop++;
  }
  
  return core_instructions_info;
}

