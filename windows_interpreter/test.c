#ifdef TESTING
#define ENTER_TO_CONTINUE printf("Press Enter to continue...\n");while(getchar() != '\n');
#define SCREEN_LIMIT 20

DATA_TYPE loop = 0;

////////////////////////////////////////////////////////
printf("Checking preprocessor definitions\n\n");

printf("AT_HEAD_OFFSET(0): %u\n",AT_HEAD_OFFSET(0));
printf("PROGRAM_AT(0): %u\n",PROGRAM_AT(0));
printf("DATA_AT(0,0): %u\n\n",DATA_AT(0,0));
printf("FLAG_AT(OVERFLOW): %u\n",FLAG_AT(OVERFLOW));
printf("FLAG_AT(UNDERFLOW): %u\n",FLAG_AT(UNDERFLOW));
printf("FLAG_AT(PROGRAM_RESIZE_FAILED): %u\n",FLAG_AT(PROGRAM_RESIZE_FAILED));
ENTER_TO_CONTINUE

////////////////////////////////////////////////////////
printf("Checking memory allocation\n\n");

printf("Showing program\n");
printf("program_capacity: %u\n",program_capacity);
ENTER_TO_CONTINUE

for(; loop < program_capacity*DATA_AT(SETTINGS, PROGRAM_CHUNK_SIZE); loop++)
{
  printf("program[%u][%u] = %u \n",loop/DATA_AT(SETTINGS, PROGRAM_CHUNK_SIZE),loop % DATA_AT(SETTINGS, PROGRAM_CHUNK_SIZE),PROGRAM_AT(loop));
}
ENTER_TO_CONTINUE

printf("Showing data\n");
printf("data_capacity: %u\n",data_capacity);
ENTER_TO_CONTINUE

loop = 0;
for(; loop < data_capacity; loop++)
{
  DATA_TYPE inner_loop = 0;
  for(; inner_loop < data[loop].capacity; inner_loop++)
  printf("data[%u].data[%u] = %u \n",loop,inner_loop,data[loop].data[inner_loop]);
  ENTER_TO_CONTINUE
}
ENTER_TO_CONTINUE

//check core programs
//
#endif
