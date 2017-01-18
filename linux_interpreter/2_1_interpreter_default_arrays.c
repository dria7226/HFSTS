//MACHINE INFO
#define DEFAULT_GRANULARITY 8

DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = (DATA_TYPE*)mmap(NULL, data[MACHINE_INFO].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  machine_info[0] = MAX_VALUE;
  machine_info[1] = DEFAULT_GRANULARITY;

  machine_info[PLATFORM] = LINUX_PLATFORM;

  return machine_info;
}

// PERFORMANCE_INFO
DATA_TYPE* load_performance_info()
{
  DATA_TYPE* performance_info = (DATA_TYPE*)mmap(NULL, data[PERFORMANCE_INFO].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);



  return performance_info;
}
