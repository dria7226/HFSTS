if(allocate_memory()) { free_memory(); return 0; }

#ifndef CLIT // Command Line Interface Testing
read_program_at_address(argc, argv);
#else
read_test_program();
#endif

//write_program();

#include "test.c"
