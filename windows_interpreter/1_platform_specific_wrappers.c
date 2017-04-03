//MEMORY
#define ALLOCATE_MEMORY(length, type) (type *) VirtualAlloc(NULL, (unsigned long long)(length + 1) * sizeof(type), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#define ALLOCATE_RANDOM_MEMORY(length, type) RANDOM MEMORY ALLOCATION NOT IMPLEMENTED
#define DEALLOCATE_MEMORY(address,length) VirtualFree(address, 0, MEM_RELEASE);

#define MEMORY_ALLOCATION_FAILED NULL

//IO
#define IO_TYPE FILE
#define READ_ARRAY(index, amount) fsetpos(file, 0, (fpos_t *)index); fread(memory[DESTINATION_AT(head_index)].data + index, sizeof(DATA_TYPE), amount, file);
#define WRITE_ARRAY(index, amount) fsetpos(file, 0, (fpos_t *)index); fwrite(memory[DESTINATION_AT(head_index)].data + index, sizeof(DATA_TYPE), amount, file);
#define GET_FILE_SIZE(destination_index) fseek(file, 0, SEEK_END); MEMORY_AT(DESTINATION_AT(head_index), destination_index) = ftell(file);

//TIME
#include <time.h>
#define READ_TIME(destination_index) MEMORY_AT(DESTINATION_AT(head_index), destination_index) = clock();
#define READ_DATE(destination_index) MEMORY_AT(DESTINATION_AT(head_index), destination_index) = time(NULL);
