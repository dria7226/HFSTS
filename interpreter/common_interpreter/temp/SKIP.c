#define NAME SKIP
#define ARGUMENTS 1

#define IMPLEMENTATION_1				\
INDEX_AT(head_index) += *temp[0];		\
						\
goto next_instruction;

#include "../instruction_template.c"
