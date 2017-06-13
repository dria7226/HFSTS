#define MEMORY_AT(x,y)             memory[x].data[y]
#define CAPACITY_AT(x)             memory[x].capacity

#define HEAD_ELEMENT_AT(index, offset) MEMORY_AT(HEADS, index*NUMBER_OF_HEAD_ELEMENTS + offset)
#define ARRAY_AT(index)            HEAD_ELEMENT_AT(index, ARRAY)
#define INDEX_AT(index)            HEAD_ELEMENT_AT(index, INDEX)
#define HEAD_GRANULARITY_AT(index) HEAD_ELEMENT_AT(index, GRANULARITY)
#define PRIMARY_AT(index)          HEAD_ELEMENT_AT(index, PRIMARY_ARRAY)
#define SECONDARY_AT(index)        HEAD_ELEMENT_AT(index, SECONDARY_ARRAY)

#define FAILSAFE_AT(index)         MEMORY_AT(HEADS, index*NUMBER_OF_HEAD_ELEMENTS + FAILSAFE_TYPE)
#define MEMORY_FAILSAFE_AT(index)  FAILSAFE_AT(index) & 0x1
#define MATH_FAILSAFE_AT(index)    FAILSAFE_AT(index) & 0x2

#define FLAG_AT(name)              MEMORY_AT(FLAGS, name)
#define SET_FLAG(name, value)      if((FLAG_AT(name) = value) != 0) FLAG_AT(FLAG_SET) = name;

#define MACHINE_INFO_AT(name)      MEMORY_AT(MACHINE_INFO, name)

#define CORE_PROGRAMS_INFO_AT(name)MEMORY_AT(CORE_PROGRAMS_INFO, name)

#define AT_HEAD_OFFSET(x)          MEMORY_AT(ARRAY_AT(head_index), INDEX_AT(head_index) + x)
#define ADVANCE_HEAD               INDEX_AT(head_index) += 1 + core_programs_arguments[AT_HEAD_OFFSET(0)]; goto next_instruction;
