// MACHINE_INFO
DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = (DATA_TYPE*)VirtualAlloc(NULL, data[MACHINE_INFO].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  machine_info[0] = MAX_VALUE;
  machine_info[1] = PROGRAM_CHUNK_SIZE;

  machine_info[PLATFORM] = WINDOWS_PLATFORM;

  return machine_info;
}

// PERFORMANCE_INFO
DATA_TYPE* load_performance_info()
{
  DATA_TYPE* performance_info = (DATA_TYPE*)VirtualAlloc(NULL, data[PERFORMANCE_INFO].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);



  return performance_info;
}
