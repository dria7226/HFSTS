0,
1,
//GET_CURRENT_INDEX

  
//OPERATION
OPERATION, EMPTY, EMPTY, EMPTY, EMPTY,

//ADVANCE MODES
SUBTRACT, NEGATIVE_RELATIVE,4, CONSTANT,NUMBER_OF_INDEX_MODES,
SET_SOURCE,FLAGS,
IF,UNDERFLOW,5,
SET_SOURCE,NUMBER_OF_DEFAULT_ARRAYS,
GO_TO_INDEX, POSITIVE_RELATIVE,6,
ADD, NEGATIVE_RELATIVE,4, CONSTANT,1,
  
SUBTRACT, NEGATIVE_RELATIVE,10, CONSTANT, NUMBER_OF_INDEX_NODES,
SET_SOURCE, FLAGS,
IF,UNDERFLOW,5,
SET_SOURCE, NUMBER_OF_DEFAULT_ARRAYS,
GO_TO_INDEX,POSITIVE_RELATIVE,6,
ADD, NEGATIVE_RELATIVE,2, CONSTANT,1,
  
GO_TO_INDEX, NEGATIVE_RELATIVE, EMPTY ,
