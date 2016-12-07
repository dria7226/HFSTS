#define TESTING

#ifdef TESTING
//load_test_program();
//write_test_program_to_storage();
read_test_program_from_storage();
#elif
  //load program from folder
#endif

void* label_table[NUMBER_OF_OPCODES] = {&&MOV, &&SRC, &&DST, &&ADD, &&SUB, &&MUL, &&DIV};

//graphics setup
initscr();
start_color();
noecho();
curs_set(FALSE);
clear();

//setup editor
editor_setup();

editor_variables[STRIDE] = 16;
editor_variables[MODE] = HEAT;
editor_variables[POSITION] = CENTER;
editor_variables[NUMBER_SYSTEM] = HEX;
editor_variables[SPACERS] = NO;
editor_variables[DETECT_FUNCTIONS] = YES;

//draw first frame

draw_ui();

draw_grid();

refresh();
