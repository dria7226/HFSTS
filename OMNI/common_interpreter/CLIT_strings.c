DATA_TYPE no_of_messages = 0;
#define ENTER_TO_CONTINUE {printf("Press Enter to continue...\n");while(getchar() != '\n'); no_of_messages = 0;}
#define SCREEN_LIMIT 45
#define PRINT(x,y,z,w) {printf(x,y,z,w); no_of_messages++;}
#define CHECK_FOR_LIMIT if(no_of_messages > SCREEN_LIMIT) { ENTER_TO_CONTINUE }
#define CHECK_FOR_SKIP(message, code) printf("Skip %s?(y/n)\n", message); if(getchar() == 'n' && getchar() == '\n'){code}

char* error_titles[] = {"DIVISION_BY_ZERO","ARRAY_RESIZE_FAILED","DATA_RESIZE_FAILED","PROGRAM_RESIZE_FAILED","DATA_ACCESS_FAILED","PROGRAM_ACCESS_FAILED"};

char* error_messages[] = {"Invalid capacity","Can't allocate memory",
                          "Invalid secondary address","Invalid PRIMARY address","Invalid array index",
                          "Invalid address"};

char* index_type_text[] = {
  "IMMEDIATE",
  "DIRECT",
  "NEGATIVE_RELATIVE",
  "POSITIVE_RELATIVE"
};

char* core_instructions_text[] = {
  #define TURN_TO_STRING
  #define NAME_MODE
  #define ENUMERATE
  #include "core/instructions.c"
};
