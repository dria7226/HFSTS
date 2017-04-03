//GET_FILE_SIZE, buffer_index, destination_index
#ifdef INTERPRETER_MODE
GET_FILE_SIZE:
#define CHECK_ALL_ARGUMENTS
#define SET_VARIABLES
#include "check_arguments.c"

file = fopen((char*)(memory[SOURCE_AT(head_index)].data + *temp[0]), "rb");
GET_FILE_SIZE(*temp[1])
fclose(file);

ADVANCE_HEAD
#endif

#ifdef NAME_MODE
GET_FILE_SIZE
#endif

#ifdef LABEL_MODE
&&GET_FILE_SIZE
#endif

#ifdef ARGUMENTS_MODE
2
#endif

#ifdef ENUMERATE
,
#endif
