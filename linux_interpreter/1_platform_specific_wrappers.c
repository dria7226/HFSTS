// MEMORY
#define ALLOCATE_MEMORY(length, type) (type *) mmap(NULL, (unsigned long long)(length + 1) * sizeof(type), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
#define ALLOCATE_RANDOM_MEMORY(length, type) (type *) mmap(NULL, (unsigned long long)(length + 1) * sizeof(type), PROT_READ | PROT_WRITE, MAP_PRIVATE,-1,0);
#define DEALLOCATE_MEMORY(address,length) munmap(address, (unsigned long long)length + 1);

#define MEMORY_ALLOCATION_FAILED MAP_FAILED

//IO
#define READ_ARRAY()
#define WRITE_ARRAY()
