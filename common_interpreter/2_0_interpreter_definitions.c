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

GET_HEAD,
GET_GRANULARITY_COUNTER,
SET_SOURCE,
SET_DESTINATION,
SET_TRANSFER_TYPE,
SET_FAILSAFE_TYPE,

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
  PERFORMANCE_INFO,
  
  NUMBER_OF_DEFAULT_ARRAYS
};

//HEAD STRUCTURE
enum{
  ADDRESS,
  GRANULARITY,
  SOURCE_ARRAY,
  DESTINATION_ARRAY,
  TRANSFER_TYPE,
  FAILSAFE_TYPE,

  NUMBER_OF_HEAD_COMPONENTS
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

#include "2_0_shortcuts.c"

#ifdef TESTING_CLI
DATA_TYPE no_of_messages = 0;
#define ENTER_TO_CONTINUE {printf("Press Enter to continue...\n");while(getchar() != '\n'); no_of_messages = 0;}
#define SCREEN_LIMIT 45
#define PRINT(x,y,z,w) {printf(x,y,z,w); no_of_messages++;}
#define CHECK_FOR_LIMIT if(no_of_messages > SCREEN_LIMIT) { ENTER_TO_CONTINUE }
#define CHECK_FOR_SKIP(message, code) printf("Skip %s?(y/n)\n", message); if(getchar() == 'n' && getchar() == '\n'){code}
#endif
