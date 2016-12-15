#define DATA_TYPE unsigned int

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF
#define PROGRAM_CHUNK 1024

struct VECTOR{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

//SHORTCUTS

#define REGISTERS 0
#define THREADS   1

#define OVERFLOW_REGISTER 0
#define UNDERFLOW_REGISTER 1

#define AT_HEAD_OFFSET(x) program[(head + x)/PROGRAM_CHUNK][(head + x)%PROGRAM_CHUNK]
#define PROGRAM_AT(x)     program[x/PROGRAM_CHUNK][x%PROGRAM_CHUNK]
#define DATA_AT(x,y)      data[x].data[y]
#define THREAD_AT(x)      DATA_AT(THREADS,x)
#define REGISTER_AT(x)    DATA_AT(REGISTERS,x)
