DATA_TYPE test_program[] = {

  GO_TO_INDEX,IMMEDIATE,6,
  0,
  1,
  MAX_VALUE,
  
  RUN_PERFORMANCE_TEST,

  // MEMORY tests
  #include "MEMORY_tests.c"

  // DECISION tests
  #include "DECISION_tests.c"

  // HEAD tests
  #include "HEAD_tests.c"

  // MATH tests
  #include "MATH_tests.c"

  EXIT
};
