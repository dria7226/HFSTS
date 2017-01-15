allocate_memory();

#ifdef TESTING_CLI
load_test_program();
#else
load_program_at_address(argc, argv)
#endif

#include "test.c"
