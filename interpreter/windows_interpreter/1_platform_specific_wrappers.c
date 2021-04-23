//MEMORY
#define ALLOCATE_MEMORY(length, type) (type *) VirtualAlloc(NULL, (unsigned long long)(length + 1) * sizeof(type), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#define ALLOCATE_RANDOM_MEMORY(length, type) RANDOM MEMORY ALLOCATION NOT IMPLEMENTED
#define DEALLOCATE_MEMORY(address,length) VirtualFree(address, 0, MEM_RELEASE);

#define MEMORY_ALLOCATION_FAILED NULL

//IO
#define IO_TYPE FILE
#define OPEN(index, type) fopen(index, type);
#define READ_ARRAY(index, array, amount) fsetpos(file, (fpos_t *)index); fread(memory[array].data + index, sizeof(DATA_TYPE), amount , file);
#define WRITE_ARRAY(index, array, amount) fsetpos(file, (fpos_t *)index); fwrite(memory[array].data + index, sizeof(DATA_TYPE), amount, file);
#define GET_FILE_SIZE(secondary_index) fseek(file, 0, SEEK_END); MEMORY_AT(SECONDARY_AT(head_index), secondary_index) = ftell(file);
#define CLOSE(f) fclose(f);

//TIME
#include <time.h>
#define READ_TIME(secondary_index) MEMORY_AT(SECONDARY_AT(head_index), secondary_index) = clock();
#define READ_DATE(secondary_index) MEMORY_AT(SECONDARY_AT(head_index), secondary_index) = time(NULL);
