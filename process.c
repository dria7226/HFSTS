#include "includes.c"

char* cmd_line;

void create_process()
{
  if(!cmd_line) return;
  
  #ifdef _WIN32
    CreateProcess( NULL, cmd_line, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL );
  #elif __linux__
    fork();
    execl("gcc/gcc", "gcc", (char*) 0);
  #elif __APPLE__
    
  #endif
}

int main(int argc, char* argv)
{
  create_process();
}
