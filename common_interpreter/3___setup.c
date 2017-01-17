allocate_memory();

#ifdef TESTING_CLI
load_test_program();
#else
load_program_at_address(argc, argv)
#endif

#ifdef TESTING_CLI
DATA_TYPE no_of_messages = 0;
DATA_TYPE loop = 0;
#endif
#include "test.c"
