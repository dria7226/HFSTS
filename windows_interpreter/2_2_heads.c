void start_head_at(DATA_TYPE address)
{
  if(head_capacity == MAX_VALUE) return;

  if(address >= program_capacity) return;

  DATA_TYPE** new_heads = (DATA_TYPE**) VirtualAlloc(NULL, sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_heads = (DATA_TYPE*) VirtualAlloc(NULL, (head_capacity + 1) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;
  for(;loop < head_capacity; loop++)
    (*new_heads)[loop] = heads[loop];

  VirtualFree(heads, 0, MEM_RELEASE);

  heads = *new_heads;
  head_capacity++;

  heads[head_capacity] = address;
}

void end_head(DATA_TYPE target)
{
  if(head_capacity < target || target == 0) return;

  DATA_TYPE** new_heads = (DATA_TYPE**) VirtualAlloc(NULL, sizeof(DATA_TYPE*), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  *new_heads = (DATA_TYPE*) VirtualAlloc(NULL, (head_capacity - 1) * sizeof(DATA_TYPE), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);

  DATA_TYPE loop = 0;
  for(;loop < target-1; loop++)
    (*new_heads)[loop] = heads[loop];
  loop++;
  for(;loop < head_capacity; loop++)
    *(new_heads)[loop] = heads[loop];

  VirtualFree(heads, 0, MEM_RELEASE);

  heads = *new_heads;
  head_capacity--;
}
