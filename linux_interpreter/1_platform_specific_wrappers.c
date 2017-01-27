#define ALLOCATE_MEMORY(length) mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
#define DEALLOCATE_MEMORY(address,length) munmap(address,length);

#define MEMORY_ALLOCATION_FAILED MAP_FAILED
