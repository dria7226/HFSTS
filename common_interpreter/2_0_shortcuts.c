#define MEMORY_AT(x,y,z)           memory[x][y].data[z]

#define DATA_AT(x,y)               MEMORY_AT(DATA,x,y)
#define CAPACITY_AT(x)             memory[DATA][x].capacity

#define HEAD_AT(index)             MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + ADDRESS)
#define HEAD_GRANULARITY_AT(index) MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + GRANULARITY)
#define SOURCE_AT(index)           MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + SOURCE_ARRAY)
#define DESTINATION_AT(index)      MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + DESTINATION_ARRAY)
#define TRANSFER_TYPE_AT(index)    MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + TRANSFER_TYPE)

#define READ_FROM_VALUE_AT(index)  TRANSFER_TYPE_AT(index) & 0x1
#define WRITE_TO_VALUE_AT(index)   TRANSFER_TYPE_AT(index) & 0x2

#define FAILSAFE_AT(index)         MEMORY_AT(DATA, HEADS, index*NUMBER_OF_HEAD_COMPONENTS + FAILSAFE_TYPE)
#define MEMORY_FAILSAFE_AT(index)  FAILSAFE_AT(index) & 0x1
#define MATH_FAILSAFE_AT(index)    FAILSAFE_AT(index) & 0x2

#define FLAG_AT(name)              MEMORY_AT(DATA, FLAGS, name)
#define SET_FLAG(name, value)      if((FLAG_AT(name) = value) != 0) FLAG_AT(FLAG_SET) = name;

#define MACHINE_INFO_AT(name)      MEMORY_AT(DATA, MACHINE_INFO, name)

#define PERFORMANCE_INFO_AT(name)  MEMORY_AT(DATA, PERFORMANCE_INFO, name)

#define AT_HEAD_OFFSET(x)          MEMORY_AT(PROGRAM, (HEAD_AT(head_index) + x)/PROGRAM_CHUNK_SIZE, (HEAD_AT(head_index) + x)%PROGRAM_CHUNK_SIZE )
#define PROGRAM_AT(x)              MEMORY_AT(PROGRAM, x/PROGRAM_CHUNK_SIZE, x%PROGRAM_CHUNK_SIZE)

#define HIGHEST_PROGRAM_INDEX      ((program_capacity+1)/(PROGRAM_CHUNK_SIZE+1)-1)
