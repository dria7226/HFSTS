// IF, source_index
#ifdef INTERPRETER_MODE
IF:
#define CHECK_INDEX
#define SET_VARIABLES
#include "check_arguments.c"

if(*temp[0])
{
  ADVANCE_HEAD
}
else
{
  INDEX_AT(head_index) += 2; //ADVANCE_HEAD once, but don't execute
  ADVANCE_HEAD
}
#endif

#ifdef NAME_MODE
IF
#endif

#ifdef LABEL_MODE
&&IF
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef ENUMERATE
,
#endif
