//SETTINGS
#define DEFAULT_GRANULARITY 8
#define DEFAULT_CHUNK_SIZE 1024

DATA_TYPE* load_settings()
{
  DATA_TYPE* settings = (DATA_TYPE*) VirtualAlloc(NULL, NUMBER_OF_SETTINGS * sizeof(DATA_TYPE), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

  //open file
  // FILE f = fopen();

  settings[HEAD_GRANULARITY] = DEFAULT_GRANULARITY;

  settings[PROGRAM_CHUNK_SIZE] = DEFAULT_CHUNK_SIZE;

  //close file
  // fclose(f);

  return settings;
}

// MACHINE_INFO
DATA_TYPE* load_machine_info()
{
  DATA_TYPE* machine_info = (DATA_TYPE*)VirtualAlloc(NULL, data[MACHINE_INFO].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  machine_info[0] = MAX_VALUE;
  machine_info[PLATFORM] = WINDOWS_PLATFORM;

  return machine_info;
}

// PERFORMANCE_INFO
DATA_TYPE* load_performance_info()
{
  DATA_TYPE* performance_info = (DATA_TYPE*)VirtualAlloc(NULL, data[PERFORMANCE_INFO].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  

  return performance_info;
}
