enum{
  HEAD_GRANULARITY,
  PROGRAM_CHUNK_SIZE,

  NO_OF_SETTINGS
};

//DEFAULTS
#define DEFAULT_GRANULARITY 8
#define DEFAULT_CHUNK_SIZE 1024

DATA_TYPE* load_settings()
{
  DATA_TYPE* settings = (DATA_TYPE*) VirtualAlloc(NULL, NO_OF_SETTINGS * sizeof(DATA_TYPE), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

  //open file
  // FILE f = fopen();

  settings[HEAD_GRANULARITY] = DEFAULT_GRANULARITY;

  settings[PROGRAM_CHUNK_SIZE] = DEFAULT_CHUNK_SIZE;

  //close file
  // fclose(f);

  return settings;
}
