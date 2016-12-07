//test program

#include "test_program.c"

void load_test_program()
{
  if(sizeof(test_program) < AVAILABLE_MEMORY)
  {
    unsigned char i;
    for(i = 0; i < sizeof(test_program); i++)
      program[i] = test_program[i];
  }
}

void write_test_program_to_storage()
{
  FILE* f = fopen("./program/test_program","wb");

  if(f == NULL) return;
  
  unsigned char i;
  for(i = 0; i < sizeof(test_program); i++)
  {
    fputc(test_program[i],f);
  }

  fclose(f);
}

void read_test_program_from_storage()
{
  FILE* f = fopen("./program/test_program","rb");

  if(f == NULL) return;
  
  unsigned char i = 0;
  while((program[i++] = (unsigned char)fgetc(f)) == EOF);

  fclose(f);
}

//graphics

#define WIDTH 170
#define HEIGHT 50

unsigned char previous_x, previous_y;
unsigned char heatmap[AVAILABLE_MEMORY];

  //types
enum{MODE, POSITION, NUMBER_SYSTEM, STRIDE, SPACERS, DETECT_FUNCTIONS, NUMBER_OF_VARIABLES};

unsigned char editor_variables[NUMBER_OF_VARIABLES];

unsigned char LONGEST_STRING = 14;
char*         editor_variables_titles[NUMBER_OF_VARIABLES] = {"MODE", "POSITION", "NUMBER_SYSTEM", "STRIDE", "SPACERS", "DETECT_FUNCTIONS"};
char*         editor_variables_text[NUMBER_OF_VARIABLES][3] = {{"HEAT","-","-"},{"LEFT","CENTER","RIGHT"},{"HEX","DEC","-"},
							       {"-","-","-"},{"NO","YES","-"},{"NO","YES","-"}};

  //values
enum{BLACK, GREY, GREEN, RED1, RED2, RED3, RED4, ORANGE};
enum{NO, YES};
enum{LEFT, CENTER, RIGHT};
enum{HEAT};
enum{HEX, DEC};

void editor_setup()
{
  init_color(BLACK, 1, 1, 1);
  init_color(GREY, 400, 400, 400);
  init_color(GREEN, 0, 750, 0);
  init_color(RED1,  250, 0, 0);
  init_color(RED2,  500, 0, 0);
  init_color(RED3,  750, 0, 0);
  init_color(RED4,  1000, 0 ,0);
  init_color(ORANGE,1000, 600, 0);

  //          FORE   BACK
  init_pair(1,GREEN, BLACK);
  init_pair(2,GREY,  BLACK);
  init_pair(3,BLACK, GREY);
  init_pair(4,BLACK, RED1);
  init_pair(5,BLACK, RED2);
  init_pair(6,BLACK, RED3);
  init_pair(7,BLACK, RED4);
  init_pair(8,BLACK, ORANGE);
}

void draw(unsigned char x, unsigned char y, char * format, unsigned char text)
{
  mvprintw(y,x,format,text);
}

void draw_header()
{
  unsigned char x = WIDTH/4*(editor_variables[POSITION]+1) //ORIGIN
                    +
                    (program[0] % editor_variables[STRIDE]) //ADDRESS
                    *
                    (
		     (editor_variables[NUMBER_SYSTEM]==DEC || editor_variables[DETECT_FUNCTIONS]) // 1 more for DEC or DETECT_FUNCTIONS
		     + //SIZE
		     3 //smallest size - 2 for HEX + 1 on each side + 1 for spacer
		    )
                    -
    editor_variables[STRIDE]/2*((editor_variables[NUMBER_SYSTEM]==DEC || editor_variables[DETECT_FUNCTIONS]) + 3); //CENTERING
  
  unsigned char y = HEIGHT/2 //ORIGIN
                    +
                    program[0] / editor_variables[STRIDE] * 2 //ADDRESS
                    -
                    AVAILABLE_MEMORY / editor_variables[STRIDE]; //CENTERING
  
  attron(COLOR_PAIR(2));
  draw(previous_x+1,previous_y-1," ",0);

  attron(COLOR_PAIR(8));
  draw(x+1,y-1,"V",0);
    
  previous_x = x;
  previous_y = y;
}

void draw_ui()
{
  unsigned char i;
  for(i=0; i<NUMBER_OF_VARIABLES; i++)
  {
    unsigned char x = WIDTH/2 - (LONGEST_STRING+1)*(NUMBER_OF_VARIABLES/2 - i) + 1;
    unsigned char y = 2;
    //title
    attron(COLOR_PAIR(1));
    draw(x,y-1,editor_variables_titles[i], 0);
    draw(x-1, y-1, "|", 0);
    draw(x-1, y  , "|", 0);
    //value
    attron(COLOR_PAIR(2));
    if(i != STRIDE)
    {
      if(i == HEAT) attron(COLOR_PAIR(6));
      draw(x, y, editor_variables_text[i][editor_variables[i]], 0);
    }
    else
    {
      draw(x, y, "%u", editor_variables[i]);
    }
  }
}

void draw_cell(unsigned char address)
{
  attron(COLOR_PAIR(1));
  
  if(editor_variables[MODE] == HEAT)
  attron(COLOR_PAIR(3 +
		    (heatmap[address] > 0  ) +
		    (heatmap[address] > 64 ) +
		    (heatmap[address] > 128) +
		    (heatmap[address] > 192)));
  
  unsigned char x = WIDTH/4*(editor_variables[POSITION]+1) //ORIGIN
                    +
                    (address % editor_variables[STRIDE]) //ADDRESS
                    *
                    (
		     (editor_variables[NUMBER_SYSTEM]==DEC || editor_variables[DETECT_FUNCTIONS]) // 1 more for DEC or DETECT_FUNCTIONS
		     + //SIZE
		     3 //smallest size - 2 for HEX + 1 on each side + 1 for spacer
		    )
                    -
    editor_variables[STRIDE]/2*((editor_variables[NUMBER_SYSTEM]==DEC || editor_variables[DETECT_FUNCTIONS]) + 3); //CENTERING
  
  unsigned char y = HEIGHT/2 //ORIGIN
                    +
                    address / editor_variables[STRIDE] * 2 //ADDRESS
                    -
                    AVAILABLE_MEMORY / editor_variables[STRIDE]; //CENTERING

  unsigned char* format = "%x";

  if(editor_variables[NUMBER_SYSTEM] == DEC) format = "%u";

  if(editor_variables[DETECT_FUNCTIONS] &&
     heatmap[address] > 0 &&
     program[address] < NUMBER_OF_OPCODES)
    
    format = instruction_strings[program[address]];

  //clear and draw
  draw(x,y,"   ",0);
  draw(x,y, format, program[address]);

  //draw optional spacers
  if(editor_variables[SPACERS])
  {
    attron(COLOR_PAIR(1));
    
    //bottom spacers
    if(address < AVAILABLE_MEMORY - editor_variables[STRIDE])
    {
      draw(x,   y+1, "-", 0);
      draw(x+1, y+1, "-", 0);
      if(editor_variables[NUMBER_SYSTEM] == DEC || editor_variables[DETECT_FUNCTIONS]) draw(x+2, y+1, "-", 0);
    }
    
    //right spacers
    if(address % editor_variables[STRIDE] != 15)
    {
      draw(x + (editor_variables[NUMBER_SYSTEM] == DEC || editor_variables[DETECT_FUNCTIONS]) + 2, y, "|", 0);
    }
  }
}

void draw_grid()
{
  //draw cells and spacers
  unsigned int i;
  for(i = 0; i < AVAILABLE_MEMORY; i++)
  {
    draw_cell(i);
  }
}
