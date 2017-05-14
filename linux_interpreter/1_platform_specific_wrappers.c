 // MEMORY
#define ALLOCATE_MEMORY(length, type) (type *) mmap(NULL, (unsigned long long)(length + 1) * sizeof(type), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
#define ALLOCATE_RANDOM_MEMORY(length, type) (type *) mmap(NULL, (unsigned long long)(length + 1) * sizeof(type), PROT_READ | PROT_WRITE, MAP_PRIVATE,-1,0);
#define DEALLOCATE_MEMORY(address,length) munmap(address, (unsigned long long)length + 1);

#define MEMORY_ALLOCATION_FAILED MAP_FAILED

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
