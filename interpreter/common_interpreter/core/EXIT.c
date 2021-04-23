#define NAME EXIT
#define ARGUMENTS 0

#ifdef IMPLEMENTATION_MODE
#define REDEF_IMPLEMENTATION_MODE
#undef IMPLEMENTATION_MODE
#endif

#include "../instruction_template.c"

#ifdef REDEF_IMPLEMENTATION_MODE
#define IMPLEMENTATION_MODE
#endif
