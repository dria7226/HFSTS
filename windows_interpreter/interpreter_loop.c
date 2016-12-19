void* label_table[EMPTY] = {
&&MOVE,
&&MOVE_CONSTANT,
&&GO_TO,
&&SET_SOURCE,
&&SET_DESTINATION,
&&ADD,
&&ADD_CONSTANT,
&&SUBTRACT,
&&SUBTRACT_CONSTANT,
&&MULTIPLY,
&&MULTIPLY_CONSTANT,
&&DIVIDE,
&&DIVIDE_CONSTANT
};

DATA_TYPE head = 0;
DATA_TYPE source_array = 0;
DATA_TYPE destination_array = 0;

next_instruction:

if(AT_HEAD_OFFSET(0) < EMPTY)
  goto *label_table[AT_HEAD_OFFSET(0)];

head++; //???
goto next_instruction;

MOVE:
#include "MOVE.c"

MOVE_CONSTANT:
#include "MOVE_CONSTANT.c"

GO_TO:
#include "GO_TO.c"

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

goto next_instruction;

out:
return;
