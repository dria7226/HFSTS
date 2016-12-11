//FUNCTIONS
//  - a function node is a graph composed of user made or core functions
//  - resizable
//  - functions are groups of core functions

//DATA
//  - all data is global
//  - resizable

  // Everything is in units of 32 bits (unsigned int)

  // memory[PROGRAM][*][*] - is program memory
  // memory[PROGRAM][0-NUMBER_OF_CORE_FUNCTIONS][NULL] - are the core functions

  // memory[DATA][*][*] - is data memory
  // memory[DATA][0][*] - is memory for single variables
  // memory[DATA][1-oo] - is array memory

#define DATA_TYPE unsigned int

struct VECTOR{
  DATA_TYPE* data;
  DATA_TYPE capacity;
};

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF

struct VECTOR*  program;
DATA_TYPE       program_capacity;

struct VECTOR*  data;
DATA_TYPE       data_capacity;


void allocate_memory()
{
  //allocate to memory[2][256][256]

  program_capacity = 32 * (DEFAULT_SIZE > MAX) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);
  
  data_capacity = 32 * (DEFAULT_SIZE > MAX) + DEFAULT_SIZE * (DEFAULT_SIZE <= MAX_VALUE);

  program = (VECTOR*) VirtualAlloc(NULL, program_capacity * sizeof(VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;

  while(loop < program_capacity)
  {
     program[loop].capacity = DEFAULT_SIZE;
     program[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, program[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
     
     loop++;
  }

   data = (VECTOR*) VirtualAlloc(NULL, data_capacity * sizeof(VECTOR), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  loop = 0;

  while(loop < data_capacity)
  {
     data[loop].capacity = DEFAULT_SIZE;
     data[loop].data = (DATA_TYPE*) VirtualAlloc(NULL, data[loop].capacity * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
     
     loop++;
  }

}

void free_memory()
{
  //loop program

  VirtualFree(&program, program_capacity, MEM_RELEASE);

  //loop data
  VirtualFree(&data, data_capacity, MEM_RELEASE);
  
}

void resize_array()
{

}
