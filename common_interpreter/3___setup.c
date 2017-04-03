if(allocate_memory()) { free_memory(); return 0; }

//#ifndef CLIT // Command Line Interface Testing
load_program_at_address(argc, argv);
//#else
//load_test_program();
//#endif

#include "test.c"
