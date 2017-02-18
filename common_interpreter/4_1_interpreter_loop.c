#include "4_0_instruction_table.c"

DATA_TYPE* a = &(MEMORY_AT(DATA, FLAGS, 1));
DATA_TYPE* b = &(MEMORY_AT(DATA, FLAGS, 2));

#ifdef TESTING_CLI
  no_of_messages = 0;
#endif

next_instruction:

#include "4_2_head_management.c"

#ifdef TESTING_CLI
  CHECK_FOR_LIMIT
  PRINT("%u: ", HEAD_AT(head_index),0,0);
#endif

FLAG_AT(FLAG_SET) = 0;

if(HEAD_AT(head_index) >= program_capacity * PROGRAM_CHUNK_SIZE - 2)
  goto out;

if(AT_HEAD_OFFSET(0) < NUMBER_OF_PROGRAMS)
  goto *instruction_table[AT_HEAD_OFFSET(0)];

#ifdef TESTING_CLI
PRINT("Invalid program code\n",0,0,0);
#endif

EMPTY:
HEAD_AT(head_index)++;
goto next_instruction;

COPY:
#include "COPY.c"

INSERT_ARRAY:
#include "INSERT_ARRAY.c"

GO_TO:
#include "GO_TO.c"

GO_IF:
#include "GO_IF.c"

SKIP:
#include "SKIP.c"

SKIP_IF:
#include "SKIP_IF.c"

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

GET_HEAD:
#include "GET_HEAD.c"

GET_GRANULARITY_COUNTER:
#include "GET_GRANULARITY_COUNTER.c"

SET_SOURCE:
#include "SET_SOURCE.c"

SET_DESTINATION:
#include "SET_DESTINATION.c"

SET_TRANSFER_TYPE:
#include "SET_TRANSFER_TYPE.c"

SET_FAILSAFE_TYPE:
#include "SET_FAILSAFE_TYPE.c"

ADD:
#include "ADD.c"

SUBTRACT:
#include "SUBTRACT.c"

DATA_TYPE product;

MULTIPLY:
#include "MULTIPLY.c"

DIVIDE:
#include "DIVIDE.c"

REMAINDER:
#include "REMAINDER.c"

EXIT:
#include "EXIT.c"

out:
