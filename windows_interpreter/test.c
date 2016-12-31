DATA_TYPE loop = 0;

printf("Showing program\n");
for(; loop < program_capacity*PROGRAM_CHUNK_SIZE; loop++)
{
  printf("program[%u][%u] = %u \n",loop/PROGRAM_CHUNK_SIZE,loop % PROGRAM_CHUNK_SIZE,program[loop/PROGRAM_CHUNK_SIZE][loop%PROGRAM_CHUNK_SIZE]);
}

printf("Showing data\n");
loop = 0;
for(; loop < data_capacity; loop++)
{
  DATA_TYPE inner_loop = 0;
  for(; inner_loop < data[loop].capacity; inner_loop++)
  printf("data[%u].data[%u] = %u \n",loop,inner_loop,data[loop].data[inner_loop]);
}
