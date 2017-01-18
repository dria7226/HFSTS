enum{
COPY,
COPY_CONSTANT,
COPY_PROGRAM_TO_DATA,
COPY_DATA_TO_PROGRAM,

GO_TO,
GO_IF,

RESIZE_DATA,
RESIZE_ARRAY,
RESIZE_PROGRAM,

GET_DATA_CAPACITY,
GET_ARRAY_CAPACITY,
GET_PROGRAM_CAPACITY,

SET_SOURCE,
SET_DESTINATION,

ADD,
ADD_CONSTANT,
SUBTRACT,
SUBTRACT_CONSTANT,
MULTIPLY,
MULTIPLY_CONSTANT,
DIVIDE,
DIVIDE_CONSTANT,
REMAINDER,
REMAINDER_CONSTANT,

GET_HEAD,

EXIT,

NUMBER_OF_PROGRAMS
};

#define DATA_TYPE unsigned int

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF

#define PROGRAM_CHUNK_SIZE 1024

struct ARRAY{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

//SHORTCUTS

enum{
  HEADS,
  FLAGS,
  MACHINE_INFO,
  PERFORMANCE_INFO,

  NUMBER_OF_DEFAULT_ARRAYS
};

// FLAGS
enum{
  FLAG_SET,

  OVERFLOW,
  UNDERFLOW,
  DIVISION_BY_ZERO,

  ARRAY_RESIZE_FAILED,
  DATA_RESIZE_FAILED,
  PROGRAM_RESIZE_FAILED,

  DATA_ACCESS_FAILED,
  PROGRAM_ACCESS_FAILED,

  NUMBER_OF_FLAGS
};

// MACHINE_INFO
enum{
  //MAX_VALUE,
  //PROGRAM_CHUNK_SIZE,
  HEAD_GRANULARITY = 2,
  PLATFORM,

  NUMBER_OF_INFO_ELEMENTS
};

enum{
  WINDOWS_PLATFORM,
  OSX_PLATFORM,
  LINUX_PLATFORM,
  IOS_PLATFORM,
  ANDROID_PLATFORM,
  WINDOWS_PHONE_PLATFORM,
  XBOX_PLATFORM,
  PLAYSTATION_PLATFORM,

  NUMBER_OF_SUPPORTED_PLATFORMS
};

#define DATA_AT(x,y)      data[x].data[y]
#define HEAD_AT(index)    data[HEADS].data[index]
#define FLAG_AT(name)     data[FLAGS].data[name]
#define SET_FLAG(name, value) FLAG_AT(name) = value; FLAG_AT(FLAG_SET) = name;
#define MACHINE_INFO_AT(name)  data[MACHINE_INFO].data[name]
#define PERFORMANCE_INFO_AT(name)  data[PERFORMANCE_INFO].data[name]
#define AT_HEAD_OFFSET(x) program[(HEAD_AT(head_index) + x)/PROGRAM_CHUNK_SIZE][(HEAD_AT(head_index) + x)%PROGRAM_CHUNK_SIZE]
#define PROGRAM_AT(x)     program[x/PROGRAM_CHUNK_SIZE][x%PROGRAM_CHUNK_SIZE]
