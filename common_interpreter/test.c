#ifdef TESTING_CLI

DATA_TYPE loop = 0;

PRINT("Checking memory allocation\n\n",0,0,0)

// check program
CHECK_FOR_SKIP( "program memory check",
PRINT("capacity[PROGRAM]: %u\n",capacity[PROGRAM],0,0)

for(; loop <= capacity[PROGRAM]; loop++)
{
  if( memory[PROGRAM][loop].data == MEMORY_ALLOCATION_FAILED)
  {
    PRINT("ERROR: no memory allocated for 'program[%u]'\n", loop, 0,0)
    CHECK_FOR_LIMIT
  }
  else
  {
    DATA_TYPE inner_loop = 0;

    PRINT("program[%u].capacity = %u\n", loop, memory[PROGRAM][loop].capacity,0)
    CHECK_FOR_LIMIT

    for(; inner_loop <= memory[PROGRAM][loop].capacity; inner_loop++)
    {
      PRINT("program[%u].data[%u] = %u \n",loop,inner_loop, memory[PROGRAM][loop].data[inner_loop])
      CHECK_FOR_LIMIT
    }
    ENTER_TO_CONTINUE
  }
}

ENTER_TO_CONTINUE
) // CHECK FOR SKIP

// check data
CHECK_FOR_SKIP( "data memory check",
PRINT("capacity[DATA]: %u\n",capacity[DATA],0,0)

for(loop = 0; loop <= capacity[DATA]; loop++)
{
  if( memory[DATA][loop].data == MEMORY_ALLOCATION_FAILED )
  {
    PRINT("ERROR: no memory allocated for 'data[%u]'\n", loop,0,0)
    ENTER_TO_CONTINUE
  }
  else
  {
    DATA_TYPE inner_loop = 0;

    PRINT("data[%u].capacity = %u\n", loop, memory[DATA][loop].capacity,0)
    CHECK_FOR_LIMIT

    for(; inner_loop <= memory[DATA][loop].capacity; inner_loop++)
    {
      PRINT("data[%u].data[%u] = %u \n",loop,inner_loop, memory[DATA][loop].data[inner_loop])
      CHECK_FOR_LIMIT
    }
    ENTER_TO_CONTINUE
  }
}

) //CHECK FOR SKIP

#endif
