#define NAME GO_TO_ARRAY
#define ARGUMENTS 2

#define IMPLEMENTATION_1				\
ARRAY_AT(head_index) = *temp[0];		\
INDEX_AT(head_index) = *temp[1];

#define CLIT_1					\
PRINT("\n",0,0,0)

#define IMPLEMENTATION_2			\
goto next_instruction;

#include "../instruction_template.c"
