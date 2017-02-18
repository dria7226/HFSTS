void* instruction_table[NUMBER_OF_PROGRAMS] = {
&&EMPTY,
&&COPY,
&&INSERT_ARRAY,

&&GO_TO,
&&GO_IF,
&&SKIP,
&&SKIP_IF,

&&RESIZE_DATA,
&&RESIZE_ARRAY,
&&RESIZE_PROGRAM,

&&GET_DATA_CAPACITY,
&&GET_ARRAY_CAPACITY,
&&GET_PROGRAM_CAPACITY,

&&GET_HEAD,
&&GET_GRANULARITY_COUNTER,
&&SET_SOURCE,
&&SET_DESTINATION,
&&SET_TRANSFER_TYPE,
&&SET_FAILSAFE_TYPE,

&&ADD,
&&SUBTRACT,
&&MULTIPLY,
&&DIVIDE,
&&REMAINDER,

&&EXIT,
};
