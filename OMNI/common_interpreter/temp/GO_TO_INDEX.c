#define NAME GO_TO_INDEX
#define ARGUMENTS 1

#define IMPLEMENTATION_1				\
INDEX_AT(head_index) = *temp[0];

#define CLIT_1					\
PRINT("\n",0,0,0)

#define IMPLEMENTATION_2			\
goto next_instruction;

#include "../instruction_template.c"
