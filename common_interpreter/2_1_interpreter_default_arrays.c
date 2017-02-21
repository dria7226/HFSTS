
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

DATA_TYPE* load_performance_info()
{
  DATA_TYPE* performance_info = ALLOCATE_MEMORY( memory[DATA][PERFORMANCE_INFO].capacity, DATA_TYPE )

  if(performance_info == MEMORY_ALLOCATION_FAILED)
  {
    return MEMORY_ALLOCATION_FAILED;
  }

  return performance_info;
}

