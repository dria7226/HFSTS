#define ALLOCATE_MEMORY(length) mmap(NULL, (unsigned long long)length + 1, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
#define ALLOCATE_RANDOM_MEMORY(length) mmap(NULL, (unsigned long long)length + 1, PROT_READ | PROT_WRITE, MAP_PRIVATE,-1,0);
#define DEALLOCATE_MEMORY(address,length) munmap(address, (unsigned long long)length +1);

#define MEMORY_ALLOCATION_FAILED MAP_FAILED
