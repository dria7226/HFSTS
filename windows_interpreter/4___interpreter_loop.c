#include "label_table.c"

next_instruction:

#include "head_management.c"

if(AT_HEAD_OFFSET(0) < EMPTY)
  goto *label_table[AT_HEAD_OFFSET(0)];

heads[head_index]++; //???
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

out:
return;
