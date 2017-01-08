#include "label_table.c"

#ifdef TESTING
  no_of_messages = 0;
#endif

next_instruction:

#include "head_management.c"

#ifdef TESTING
  CHECK_FOR_LIMIT
  printf("%u: ", HEAD_AT(head_index));
#endif

if(AT_HEAD_OFFSET(0) < NUMBER_OF_PROGRAMS)
  goto *label_table[AT_HEAD_OFFSET(0)];

HEAD_AT(head_index)++;
goto next_instruction;

COPY:
#include "COPY.c"

COPY_CONSTANT:
#include "COPY_CONSTANT.c"

COPY_PROGRAM_TO_DATA:
#include "COPY_PROGRAM_TO_DATA.c"

COPY_DATA_TO_PROGRAM:
#include "COPY_DATA_TO_PROGRAM.c"

GO_TO:
#include "GO_TO.c"

RESIZE_DATA:
#include "RESIZE_DATA.c"

RESIZE_ARRAY:
#include "RESIZE_ARRAY.c"

RESIZE_PROGRAM:
#include "RESIZE_PROGRAM.c"

GET_DATA_CAPACITY:
#include "GET_DATA_CAPACITY.c"

GET_ARRAY_CAPACITY:
#include "GET_ARRAY_CAPACITY.c"

GET_PROGRAM_CAPACITY:
#include "GET_PROGRAM_CAPACITY.c"

SET_SOURCE:
#include "SET_SOURCE.c"

SET_DESTINATION:
#include "SET_DESTINATION.c"

ADD:
#include "ADD.c"

ADD_CONSTANT:
#include "ADD_CONSTANT.c"

SUBTRACT:
#include "SUBTRACT.c"

SUBTRACT_CONSTANT:
#include "SUBTRACT_CONSTANT.c"

MULTIPLY:
#include "MULTIPLY.c"

MULTIPLY_CONSTANT:
#include "MULTIPLY_CONSTANT.c"

DIVIDE:
#include "DIVIDE.c"

DIVIDE_CONSTANT:
#include "DIVIDE_CONSTANT.c"

REMAINDER:
#include "REMAINDER.c"

REMAINDER_CONSTANT:
#include "REMAINDER_CONSTANT.c"

GET_HEAD:
#include "GET_HEAD.c"

out:
return;
