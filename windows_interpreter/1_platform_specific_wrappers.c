//MEMORY
#define ALLOCATE_MEMORY(length, type) (type *) VirtualAlloc(NULL, (unsigned long long)(length + 1) * sizeof(type), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#define ALLOCATE_RANDOM_MEMORY(length, type) RANDOM MEMORY ALLOCATION NOT IMPLEMENTED
#define DEALLOCATE_MEMORY(address,length) VirtualFree(address, 0, MEM_RELEASE);

#define MEMORY_ALLOCATION_FAILED NULL

//IO
#define READ_ARRAY()
#define WRITE_ARRAY()
