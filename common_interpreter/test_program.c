#define PROGRAM_CODE 1
#define SOURCE_VECTOR 7
#define DESTINATION_VECTOR 31
#define DATA_VECTOR 30

#define RESIZE_TEST 0
#define COPY_TEST RESIZE_TEST + 4
#define LOOP_START COPY_TEST + 13
#define LOOP_END COPY_TEST + 37
#define VECTOR_ITER LOOP_START + 11

DATA_TYPE test_program[] = {

  // RESIZE_ARRAY, 8,
  // COPY_CONSTANT, COPY_TEST, 0,
  // COPY_CONSTANT, 6, 1,
  // COPY_CONSTANT, RESIZE_TEST, 4,
  // COPY_CONSTANT, 2, 4 + 1,

//-------------------------------------

  RESIZE_PROGRAM, 2,

  RESIZE_ARRAY, 4,

//-------------------------------------
  SET_DESTINATION, DATA_VECTOR,
  GET_ARRAY_CAPACITY, 7, 1,
  SUBTRACT_CONSTANT, 1, 1,

  SET_SOURCE, DATA_VECTOR,
  COPY, 1, 2,

//loop start

  WRITE_TO, PROGRAM,
  COPY, 2, VECTOR_ITER,
  COPY, 2, VECTOR_ITER+1,

  WRITE_TO, DATA,
  SET_DESTINATION, DESTINATION_VECTOR,
  SET_SOURCE, SOURCE_VECTOR,
  COPY, 0, 0,

  SET_DESTINATION, DATA_VECTOR,
  SUBTRACT_CONSTANT, 2, 5,

  //decide to loop back or jump out

  SET_SOURCE, DATA_VECTOR,
  GO_IF, LOOP_END, UNDERFLOW,
  GO_TO, LOOP_START,

  EXIT
};
