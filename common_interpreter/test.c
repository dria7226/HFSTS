#ifdef TESTING_CLI

DATA_TYPE loop = 0;

PRINT("Checking memory allocation\n\n",0,0,0)

// check program
CHECK_FOR_SKIP( "memory check",
PRINT("capacity: %u\n",capacity,0,0)

for(; loop <= capacity; loop++)
{
  if( memory[loop].data == MEMORY_ALLOCATION_FAILED)
  {
    PRINT("ERROR: no memory allocated for 'memory[%u].data'\n", loop, 0,0)
    CHECK_FOR_LIMIT
  }
  else
  {
    DATA_TYPE inner_loop = 0;

    PRINT("memory[%u].capacity = %u\n", loop, memory[loop].capacity,0)
    CHECK_FOR_LIMIT

    for(; inner_loop <= memory[loop].capacity; inner_loop++)
    {
      PRINT("memory[%u].data[%u] = %u \n",loop,inner_loop, memory[loop].data[inner_loop])
      CHECK_FOR_LIMIT
    }
    ENTER_TO_CONTINUE
  }
}

ENTER_TO_CONTINUE
) // CHECK FOR SKIP

#endif
