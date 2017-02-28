enum{
#define NAME_MODE
#define ENUMERATE
#include "core_programs.c"
  
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
  PROGRAM,
  DATA,
  CONSTANT
};

enum{
  HEADS,
  FLAGS,
  MACHINE_INFO,
  CORE_PROGRAMS_INFO,
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
  SOURCE_ARRAY,
  DESTINATION_ARRAY,
  TRANSFER_TYPE,
  FAILSAFE_TYPE,

  NUMBER_OF_HEAD_ELEMENTS
};

enum{
  WRITE_TO,
  READ_FROM
};

// FLAGS
enum{
  FLAG_SET,

  OVERFLOW,
  UNDERFLOW,
  DIVISION_BY_ZERO,

  ARRAY_RESIZE_FAILED,
  MEMORY_RESIZE_FAILED,

  MEMORY_ACCESS_FAILED,

  CONSTANT_TRANSFER_TYPE_NOT_APPLICABLE,
  
  NUMBER_OF_FLAGS
};

// MACHINE_INFO
enum{
  //MAX_VALUE,
  PLATFORM = 1,

  NUMBER_OF_MACHINE_INFO_ELEMENTS
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

//CORE_PROGRAMS_INFO
enum{
  PERFORMANCE,
  NUMBER_OF_ARGUMENTS,

  NUMBER_OF_CORE_PROGRAMS_INFO_ELEMENTS
};

#define NUMBER_OF_KEYBOARD_STATES 256
#define NUMBER_OF_MOUSE_STATES 6
#define NUMBER_OF_JOYSTICK_STATES 18

#include "2_0_shortcuts.c"
