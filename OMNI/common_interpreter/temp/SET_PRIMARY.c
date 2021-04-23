#define NAME SET_PRIMARY
#define ARGUMENTS 1

#define IMPLEMENTATION_1			        \
PRIMARY_AT(head_index) = *temp[0];	       	

#define CLIT_1				       	\
PRINT("\n",0,0,0)

#include "../instruction_template.c"
