if(allocate_memory()) { free_memory(); return 0; }

#ifdef CLIT // Command Line Interface Testing
load_test_program();
#else
load_program_at_address(argc, argv);
#endif

#include "test.c"
