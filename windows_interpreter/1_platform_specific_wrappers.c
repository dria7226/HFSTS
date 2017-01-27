#define ALLOCATE_MEMORY(length) VirtualAlloc(NULL, length, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#define DEALLOCATE_MEMORY(address,length) VirtualFree(address, 0, MEM_RELEASE);

#define MEMORY_ALLOCATION_FAILED NULL
