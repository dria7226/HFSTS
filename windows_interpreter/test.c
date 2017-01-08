#ifdef TESTING
#define ENTER_TO_CONTINUE printf("Press Enter to continue...\n");while(getchar() != '\n'); no_of_messages = 0;
#define SCREEN_LIMIT 20
#define PRINT(x,y,z,w) printf(x,y,z); no_of_messages++;
#define CHECK_FOR_LIMIT if(no_of_messages > SCREEN_LIMIT) { ENTER_TO_CONTINUE }
#define CHECK_FOR_SKIP(message, code) printf("Skip %s?(y/n)\n", message); if(getchar() == 'n' && getchar() == '\n'){code}

DATA_TYPE no_of_messages = 0;
DATA_TYPE loop = 0;

////////////////////////////////////////////////////////
PRINT("Checking memory allocation\n\n",0,0,0)

// check program
CHECK_FOR_SKIP( "program memory check",
PRINT("program_capacity: %u\n",program_capacity,0,0)

if( program == NULL )
{
  PRINT("ERROR: no memory allocated for 'program'\n",0,0,0)
  ENTER_TO_CONTINUE
}
else
for(; loop < program_capacity*SETTING_AT(PROGRAM_CHUNK_SIZE); loop++)
{
  if( program[loop/SETTING_AT(PROGRAM_CHUNK_SIZE)] == NULL)
  {
    PRINT("ERROR: no memory allocated for 'program[%u]'\n", loop, 0,0)
    CHECK_FOR_LIMIT
  }
  else
  {
    PRINT("program[%u][%u] = %u \n", loop/SETTING_AT(PROGRAM_CHUNK_SIZE), loop%SETTING_AT(PROGRAM_CHUNK_SIZE), PROGRAM_AT(loop))
    CHECK_FOR_LIMIT
  }
}
ENTER_TO_CONTINUE
) // CHECK FOR SKIP

// check data
CHECK_FOR_SKIP( "data memory check",
PRINT("data_capacity: %u\n",data_capacity,0,0)

if( data == NULL )
{
  PRINT("ERROR: no memory allocated for 'data'\n",0,0,0)
  ENTER_TO_CONTINUE
}
else
{
  loop = 0;
  for(; loop < data_capacity; loop++)
  {

    if( data[loop].data == NULL )
    {
      PRINT("ERROR: no memory allocated for 'data[%u]'\n", loop,0,0)
      ENTER_TO_CONTINUE
    }
    else
    {
    DATA_TYPE inner_loop = 0;

    PRINT("data[%u].capacity = %u\n", loop, data[loop].capacity,0)
    CHECK_FOR_LIMIT

    for(; inner_loop < data[loop].capacity; inner_loop++)
      PRINT("data[%u].data[%u] = %u \n",loop,inner_loop,data[loop].data[inner_loop])
    ENTER_TO_CONTINUE
    }
  }
}
ENTER_TO_CONTINUE
) //CHECK FOR SKIP

////////////////////////////////////////////////////////
PRINT("Checking preprocessor definitions\n\n",0,0,0)

PRINT("AT_HEAD_OFFSET(0): %u\n",AT_HEAD_OFFSET(0),0,0)
PRINT("PROGRAM_AT(0): %u\n",PROGRAM_AT(0),0,0)
PRINT("DATA_AT(0,0): %u\n\n",DATA_AT(0,0),0,0)
PRINT("FLAG_AT(OVERFLOW): %u\n",FLAG_AT(OVERFLOW),0,0)
PRINT("FLAG_AT(UNDERFLOW): %u\n",FLAG_AT(UNDERFLOW),0,0)
PRINT("FLAG_AT(PROGRAM_RESIZE_FAILED): %u\n",FLAG_AT(PROGRAM_RESIZE_FAILED),0,0)
ENTER_TO_CONTINUE

// check helper functions
CHECK_FOR_SKIP( "helper functions check",


ENTER_TO_CONTINUE
) // CHECK FOR SKIP

//check core programs
//
#endif
