enum{
EMPTY,
COPY,
INSERT_ARRAY,

IF,
GO_TO_ARRAY,
GO_TO_INDEX,
SKIP,

RESIZE_MEMORY,
RESIZE_ARRAY,

GET_MEMORY_CAPACITY,
GET_ARRAY_CAPACITY,

GET_HEAD,
GET_GRANULARITY_COUNTER,
SET_SOURCE,
SET_DESTINATION,
SET_TRANSFER_TYPE,
SET_FAILSAFE_TYPE,

ADD,
SUBTRACT,
MULTIPLY,
DIVIDE,
REMAINDER,
AND,
OR,
XOR,
LOGICAL_SHIFT,

EXIT,

NUMBER_OF_PROGRAMS
};

#define DATA_TYPE unsigned long

#define DEFAULT_CAPACITY  31
#define MAX_VALUE     0xFFFFFFFF

struct ARRAY{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

enum{
  DATA,
  PROGRAM,
  CONSTANT
};

enum{
  HEADS,
  FLAGS,
  MACHINE_INFO,
  PERFORMANCE_INFO,
  KEYBOARD_STATE,
  MOUSE_STATE,
  JOYSTICK_STATE,

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
  PLATFORM = 1,

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

#define NUMBER_OF_KEYBOARD_STATES 256
#define NUMBER_OF_MOUSE_STATES 6
#define NUMBER_OF_JOYSTICK_STATES 18

#include "2_0_shortcuts.c"
