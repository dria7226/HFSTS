#ifdef _WIN32
  #include <windows.h>
#endif

char* cmd_line;

void create_process()
{
  if(!cmd_line) return;
  
  #ifdef _WIN32
  CreateProcess( NULL, cmd_line, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL );
  #endif
}

int main(int argc, char* argv)
{
  create_process();
}
