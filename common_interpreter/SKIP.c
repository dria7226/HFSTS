#define NAME SKIP
#define ARGUMENTS 1

#define IMPLEMENTATION				\
INDEX_AT(head_index) += *temp[0];		\
						\
goto next_instruction;

#include "core_program_template.c"
