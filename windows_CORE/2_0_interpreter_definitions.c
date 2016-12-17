enum{
//MOVE,
//MOVE_CONSTANT ,
//SET_SOURCE ,
//SET_DESTINATION ,
ADD ,
ADD_CONSTANT ,
//SUBTRACT ,
//SUBTRACT_CONSTANT ,
//MULTIPLY ,
//MULTIPLY_CONSTANT ,
//DIVIDE ,
//DIVIDE_CONSTANT ,
EMPTY
};

#define DATA_TYPE unsigned int

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF
#define PROGRAM_CHUNK_SIZE 1024

struct VECTOR{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

//SHORTCUTS

#define REGISTERS 0
#define THREADS   1

// REGISTERS
#define OVERFLOW 0
#define UNDERFLOW 1
#define REMAINDER 2

#define AT_HEAD_OFFSET(x) program[(head + x)/PROGRAM_CHUNK_SIZE][(head + x)%PROGRAM_CHUNK_SIZE]
#define PROGRAM_AT(x)     program[x/PROGRAM_CHUNK_SIZE][x%PROGRAM_CHUNK_SIZE]
#define DATA_AT(x,y)      data[x].data[y]
#define THREAD_AT(x)      DATA_AT(THREADS,x)
#define REGISTER_AT(x)    DATA_AT(REGISTERS,x)