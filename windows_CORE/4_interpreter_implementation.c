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

enum {PROGRAM,DATA}
DATA_TYPE** memory[2];

void init_memory()
{
  //initialize to memory[2][256][256]


}

void resize_array()
{
  
}
