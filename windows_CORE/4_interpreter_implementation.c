/*
FUNCTIONS
  - a function node is a graph composed of user made or core functions
  - resizable
  - functions are groups of core functions

DATA
  - all data is global
  - resizable

  Everything is in units of 32 bits (unsigned int)

  memory[PROGRAM][*][*] - is program memory
  memory[PROGRAM][0-NUMBER_OF_CORE_FUNCTIONS][NULL] - are the core functions

  memory[DATA][*][*] - is data memory
  memory[DATA][0][*] - is memory for single variables
  memory[DATA][1-oo] - is array memory
*/

#define DATA_TYPE unsigned int

struct VECTOR{
  DATA_TYPE* data;
  DATA_TYPE capacity;
};

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF

struct VECTOR*  program_memory;
DATA_TYPE       program_capacity;

struct VECTOR*  data_memory;
DATA_TYPE       data_capacity;


void alloc_memory()
{
  //allocate to memory[2][256][256]

  memory[PROGRAM] = (DATA_TYPE**) VirtualAlloc(NULL, DEFAULT_SIZE * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);



}

void free_memory()
{
  VirtualFree(address, size, MEM_RELEASE);
}

void resize_array()
{

}
