void create_head(DATA_TYPE address)
{
  if(head_capacity == MAX_VALUE) return;

  DATA_TYPE** new_heads = (DATA_TYPE**) VirtualAlloc(NULL, sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_heads = (DATA_TYPE*) VirtualAlloc(NULL, (head_capacity + 1) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new_heads, heads, head_capacity, PAGE_READWRITE);

  VirtualFree(heads, 0, MEM_RELEASE);

  heads = *new_heads;
  head_capacity++;

  heads[head_capacity] = address;
}

void end_thread(DATA_TYPE target)
{
  if(head_capacity < target || target == 0) return;

  DATA_TYPE** new_heads = (DATA_TYPE**) VirtualAlloc(NULL, sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_heads = (DATA_TYPE*) VirtualAlloc(NULL, (head_capacity - 1) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  VirtualCopy(*new_heads, heads, target - 1, PAGE_READWRITE);
  VirtualCopy(*new_heads[target], heads[target + 1], head_capacity - target, PAGE_READWRITE);

  VirtualFree(heads, 0, MEM_RELEASE);

  heads = *new_heads;
  head_capacity--;
}
