void start_thread()
{
  if(thread_capacity == MAX_VALUE) return;

  HANDLE** new_threads = (HANDLE**) VirtualAlloc(NULL, sizeof(HANDLE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_threads = (HANDLE*) VirtualAlloc(NULL, (thread_capacity + 1) * sizeof(HANDLE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new_threads, threads, thread_capacity, PAGE_READWRITE);

  VirtualFree(threads, 0, MEM_RELEASE);

  threads = *new_threads;
  thread_capacity++;

  threads[thread_capacity] = CreateThread(NULL, 0, interpret, NULL, 0, NULL);
}

void end_thread(DATA_TYPE target)
{
  if(thread_capacity < target || target == 0) return;

  HANDLE** new_threads = (HANDLE**) VirtualAlloc(NULL, sizeof(HANDLE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_threads = (HANDLE*) VirtualAlloc(NULL, (thread_capacity - 1) * sizeof(HANDLE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new_threads, threads, target - 1, PAGE_READWRITE);
  VirtualCopy(*new_threads[target], threads[target + 1], thread_capacity - target, PAGE_READWRITE);

  VirtualFree(threads, 0, MEM_RELEASE);

  threads = *new_threads;
  thread_capacity--;
}
