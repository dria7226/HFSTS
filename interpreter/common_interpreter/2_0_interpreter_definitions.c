enum{
#define NAME_MODE
#define ENUMERATE
#include "core/instructions.c"
  
NUMBER_OF_CORE_INSTRUCTIONS
};

#define DATA_TYPE unsigned long

DATA_TYPE core_instructions_arguments[] = {
  #define ARGUMENTS_MODE
  #define ENUMERATE
  #include "core/instructions.c"
};

#define DEFAULT_CAPACITY  31
#define MAX_VALUE     0xFFFFFFFF

struct ARRAY{
  DATA_TYPE* data;
  DATA_TYPE  capacity;
};

#define NUMBER_OF_DATA_PER_ARGUMENT 2
enum{
  IMMEDIATE,
  DIRECT,
  
  NEGATIVE_RELATIVE,
  POSITIVE_RELATIVE,

  NUMBER_OF_INDEX_TYPES
};

enum{
  HEADS,
  FLAGS,
  MACHINE_INFO,
  CORE_INSTRUCTIONS_INFO,
  KEYBOARD_STATE,
  MOUSE_STATE,
  JOYSTICK_STATE,

  NUMBER_OF_DEFAULT_ARRAYS
};

//HEAD STRUCTURE
enum{
  ARRAY,
  INDEX,
  GRANULARITY,
  PRIMARY_ARRAY,
  SECONDARY_ARRAY,
  FAILSAFE_TYPE,

  NUMBER_OF_HEAD_ELEMENTS
};

enum{
  WRITE_TO,
  READ_FROM
};
enum{
  LEFT,
  RIGHT
};

// FLAGS
enum{
  FLAG_SET,

  OVERFLOW,
  UNDERFLOW,
  DIVISION_BY_ZERO,

  ARRAY_RESIZE_FAILED,
  MEMORY_RESIZE_FAILED,

  ARRAY_ACCESS_FAILED,
  INDEX_ACCESS_FAILED,

  SET_HEAD_FAILED,
  
  NUMBER_OF_FLAGS
};

// MACHINE_INFO
enum{
  //MAX_VALUE,
  PLATFORM = 1,

  NUMBER_OF_MACHINE_INFO_ELEMENTS
};

enum{
  HFSTS_PLATFORM,
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

//CORE_INSTRUCTIONS_INFO
enum{
  PERFORMANCE,
  NUMBER_OF_ARGUMENTS,

  NUMBER_OF_CORE_INSTRUCTIONS_INFO_ELEMENTS
};

#define NUMBER_OF_KEYBOARD_STATES 256
#define NUMBER_OF_MOUSE_STATES 6
#define NUMBER_OF_JOYSTICK_STATES 18

#include "2_0_shortcuts.c"
