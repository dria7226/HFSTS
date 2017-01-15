//SETTINGS
#define DEFAULT_GRANULARITY 8

DATA_TYPE* load_settings()
{
  DATA_TYPE* settings = (DATA_TYPE*) mmap(NULL, NUMBER_OF_SETTINGS * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  //open file
  // FILE f = fopen();

  settings[0] = PROGRAM_CHUNK_SIZE;

  settings[HEAD_GRANULARITY] = DEFAULT_GRANULARITY;

  //close file
  // fclose(f);

  return settings;
}

// MACHINE_INFO
DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = (DATA_TYPE*)mmap(NULL, data[MACHINE_INFO].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);

  machine_info[0] = MAX_VALUE;
  machine_info[PLATFORM] = WINDOWS_PLATFORM;

  return machine_info;
}

// PERFORMANCE_INFO
DATA_TYPE* load_performance_info()
{
  DATA_TYPE* performance_info = (DATA_TYPE*)mmap(NULL, data[PERFORMANCE_INFO].capacity * sizeof(DATA_TYPE), PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1 ,0);



  return performance_info;
}
