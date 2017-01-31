// ADD , destination_address , source_address
if(WRITE_TO_VALUE_AT(head_index))
{
  if( AT_HEAD_OFFSET(1) >= program_capacity*PROGRAM_CHUNK_SIZE )
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("ADD: PROGRAM_ACCESS_FAILED: invalid address %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }
}
else
{
  if(AT_HEAD_OFFSET(1) >= CAPACITY_AT(DESTINATION_AT(head_index)) )
  {
    SET_FLAG(DATA_ACCESS_FAILED,1)

    #ifdef TESTING_CLI
    PRINT("ADD: DATA_ACCESS_FAILED: invalid destination address %u\n",AT_HEAD_OFFSET(1),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }
}

if(READ_FROM_VALUE_AT(head_index))
{
  if( AT_HEAD_OFFSET(2) >= program_capacity*PROGRAM_CHUNK_SIZE )
  {
    SET_FLAG(PROGRAM_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("ADD: PROGRAM_ACCESS_FAILED: invalid address %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }
}
else
{
  if( AT_HEAD_OFFSET(2) >= CAPACITY_AT(SOURCE_AT(head_index)) )
  {
    SET_FLAG(DATA_ACCESS_FAILED,2)

    #ifdef TESTING_CLI
    PRINT("ADD: DATA_ACCESS_FAILED: invalid source address %u\n",AT_HEAD_OFFSET(2),0,0)
    #endif

    HEAD_AT(head_index) += 3;
    goto next_instruction;
  }
}

#define SHORT_ADD(x,y) SET_FLAG(OVERFLOW, x > (x + y)) goto ADD_advance_head;

void* ADD_table[2][2] = {
  {
   &&ADD_DATA_DATA,
   &&ADD_DATA_PROGRAM
  },
  {
   &&ADD_PROGRAM_DATA,
   &&ADD_PROGRAM_PROGRAM
  }
};

goto ADD_table[WRITE_TO_VALUE_AT(head_index)][READ_FROM_VALUE_AT(head_index)];

ADD_DATA_DATA:
SHORT_ADD(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)),
          DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2))

ADD_DATA_PROGRAM:
SHORT_ADD(DATA_AT(DESTINATION_AT(head_index), AT_HEAD_OFFSET(1)),
          PROGRAM_AT(AT_HEAD_OFFSET(2)))

ADD_PROGRAM_DATA:
SHORT_ADD(PROGRAM_AT(AT_HEAD_OFFSET(1)),
          DATA_AT(SOURCE_AT(head_index), AT_HEAD_OFFSET(2)))

ADD_PROGRAM_PROGRAM:
SHORT_ADD(PROGRAM_AT(AT_HEAD_OFFSET(1)),
          PROGRAM_AT(AT_HEAD_OFFSET(2)))

#ifdef TESTING_CLI
  PRINT("ADD, %u, %u = %u\n", AT_HEAD_OFFSET(1), AT_HEAD_OFFSET(2), 0)
  if( FLAG_AT(OVERFLOW) ) PRINT("The addition overflowed.\n",0,0,0)
#endif

// advance head
ADD_advance_head:
HEAD_AT(head_index) += 3;

goto next_instruction;
