enum{
EMPTY,
COPY,
COPY_CONSTANT,
INSERT_ARRAY,

GO_TO,
GO_IF,
SKIP,
SKIP_IF,

RESIZE_DATA,
RESIZE_ARRAY,
RESIZE_PROGRAM,

GET_DATA_CAPACITY,
GET_ARRAY_CAPACITY,
GET_PROGRAM_CAPACITY,

READ_FROM,
WRITE_TO,
SET_SOURCE,
SET_DESTINATION,

SET_MEMORY_FAILSAFE,
SET_MATH_FAILSAGE,

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
GET_GRANULARITY_COUNTER,

EXIT,

NUMBER_OF_PROGRAMS
};

#define DATA_TYPE unsigned int

#define DEFAULT_SIZE  32
#define MAX_VALUE     0xFFFFFFFF

#define PROGRAM_CHUNK_SIZE 128

struct ARRAY{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

//SHORTCUTS
enum{
  DATA,
  PROGRAM
};

enum{
  HEADS,
  FLAGS,
  MACHINE_INFO,

  NUMBER_OF_DEFAULT_ARRAYS
};

//HEAD STRUCTURE
enum{
  ADDRESS,
  GRANULARITY,
  SOURCE_ARRAY,
  DESTINATION_ARRAY,
  TRANSFER_TYPE,

  NUMBER_OF_HEAD_COMPONENTS
};

// FLAGS
enum{
  FLAG_SET,

  MATH_FAILSAFE,
  OVERFLOW,
  UNDERFLOW,
  DIVISION_BY_ZERO,

  MEMORY_FAILSAFE,
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
  PLATFORM = 2,

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

#define MEMORY_AT(x,y,z)           memory[x][y].data[z]
#define DATA_AT(x,y)               MEMORY_AT(DATA,x,y)
#define CAPACITY_AT(x)             memory[DATA][x].capacity - 1
#define HEAD_AT(index)             MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + ADDRESS)
#define HEAD_GRANULARITY_AT(index) MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + GRANULARITY)
#define SOURCE_AT(index)           MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + SOURCE_ARRAY)
#define DESTINATION_AT(index)      MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + DESTINATION_ARRAY)
#define TRANSFER_TYPE_AT(index)    MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + TRANSFER_TYPE)
#define READ_FROM_VALUE_AT(index)  TRANSFER_TYPE_AT(index)%2
#define WRITE_TO_VALUE_AT(index)   TRANSFER_TYPE_AT(index)/2
#define FLAG_AT(name)              MEMORY_AT(DATA, FLAGS, name)
#define SET_FLAG(name, value)      if((FLAG_AT(name) = value) != 0) FLAG_AT(FLAG_SET) = name;
#define MACHINE_INFO_AT(name)      MEMORY_AT(DATA, MACHINE_INFO, name)
#define AT_HEAD_OFFSET(x)          MEMORY_AT(PROGRAM, (HEAD_AT(head_index) + x)/PROGRAM_CHUNK_SIZE, (HEAD_AT(head_index) + x)%PROGRAM_CHUNK_SIZE )
#define PROGRAM_AT(x)              MEMORY_AT(PROGRAM, x/PROGRAM_CHUNK_SIZE, x%PROGRAM_CHUNK_SIZE)

#ifdef TESTING_CLI
DATA_TYPE no_of_messages = 0;
#define ENTER_TO_CONTINUE {printf("Press Enter to continue...\n");while(getchar() != '\n'); no_of_messages = 0;}
#define SCREEN_LIMIT 45
#define PRINT(x,y,z,w) {printf(x,y,z,w); no_of_messages++;}
#define CHECK_FOR_LIMIT if(no_of_messages > SCREEN_LIMIT) { ENTER_TO_CONTINUE }
#define CHECK_FOR_SKIP(message, code) printf("Skip %s?(y/n)\n", message); if(getchar() == 'n' && getchar() == '\n'){code}
#endif
