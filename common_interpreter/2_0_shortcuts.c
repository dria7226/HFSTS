#define MEMORY_AT(x,y,z)           memory[x][y].data[z]
#define CAPACITY_AT(x,y)           memory[x][y].capacity

#define DATA_AT(x,y)               memory[DATA][x].data[y]

#define HEAD_ELEMENT_AT(index, offset) DATA_AT(HEADS, index*NUMBER_OF_HEAD_ELEMENTS + offset)
#define ARRAY_AT(index)            HEAD_ELEMENT_AT(index, ARRAY)
#define INDEX_AT(index)            HEAD_ELEMENT_AT(index, INDEX)
#define HEAD_GRANULARITY_AT(index) HEAD_ELEMENT_AT(index, GRANULARITY)
#define SOURCE_AT(index)           HEAD_ELEMENT_AT(index, SOURCE_ARRAY)
#define DESTINATION_AT(index)      HEAD_ELEMENT_AT(index, DESTINATION_ARRAY)
#define TRANSFER_TYPE_AT(index,side) (DATA_AT(HEADS, index*NUMBER_OF_HEAD_ELEMENTS + TRANSFER_TYPE) >> (2*side) ) & 0x3

#define FAILSAFE_AT(index)         DATA_AT(HEADS, index*NUMBER_OF_HEAD_ELEMENTS + FAILSAFE_TYPE)
#define MEMORY_FAILSAFE_AT(index)  FAILSAFE_AT(index) & 0x1
#define MATH_FAILSAFE_AT(index)    FAILSAFE_AT(index) & 0x2

#define FLAG_AT(name)              DATA_AT(FLAGS, name)
#define SET_FLAG(name, value)      if((FLAG_AT(name) = value) != 0) FLAG_AT(FLAG_SET) = name;

#define MACHINE_INFO_AT(name)      DATA_AT(MACHINE_INFO, name)

#define CORE_PROGRAMS_INFO_AT(name)DATA_AT(CORE_PROGRAMS_INFO, name)

#define PROGRAM_AT(x,y)            MEMORY_AT(PROGRAM, x, y)
#define AT_HEAD_OFFSET(x)          PROGRAM_AT(ARRAY_AT(head_index), INDEX_AT(head_index) + x)
#define ADVANCE_HEAD               INDEX_AT(head_index) += 1 + core_programs_arguments[AT_HEAD_OFFSET(0)]; goto next_instruction;
