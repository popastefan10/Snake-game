#include "../Headers/help_menu.h"

/// loads the help page

void loadHelp() {
  int helpMinY = 2;
  int legendMinY = 4;
  int foodColoursMinY = 4;
  int crtY = 0;

  gotoXY(helpMinY, crtY);
  printf("<- Press Esc to go back");

  crtY += 2;
  gotoXY(helpMinY, crtY);
  printf("How to play:");

  crtY += 2;
  gotoXY(helpMinY, crtY);
  printf("You are controlling the snake with the keyboard arrows.");
  crtY++;
  gotoXY(helpMinY, crtY);
  printf("Also, you can press Esc to pause the game.");
  crtY++;
  gotoXY(helpMinY, crtY);
  printf("The snake can not hit any of the walls or go through its tail.");
  crtY++;
  gotoXY(helpMinY, crtY);
  printf("The main purpose of the game is to eat food in order to gain as much score as possible.");

  crtY += 2;
  gotoXY(helpMinY, crtY);
  printf("What each in-game character means:");

  crtY++;
  gotoXY(legendMinY, crtY);
  printf("# -> wall");
  crtY++;
  gotoXY(legendMinY, crtY);
  printf("O -> snake body");
  crtY++;
  gotoXY(legendMinY, crtY);
  printf("* -> food");


  crtY += 2;
  gotoXY(helpMinY, crtY);
  printf("Each food that appears on the screen will give a different amount of points when eaten.");
  crtY++;
  gotoXY(helpMinY, crtY);
  printf("Food with different scores will have different colours as follows:");

  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, RED,    1,  40);
  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, GREEN,  2,  25);
  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, BLUE,   3,  15);
  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, PURPLE, 5,  9);
  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, YELLOW, 7,  6);
  crtY++;
  drawFoodColourInfo(foodColoursMinY, crtY, CYAN,   10, 5);


  /// check is esc was pressed
  while(true) {
    hideCursor();
    if(GetAsyncKeyState(ESC) & MSB)
      return;
  }
}

/// draws the score and spawn chance for a given colour

inline void drawFoodColourInfo(int x, int y, WORD colour, int score, int spawnChance) {
  gotoXY(x, y);
  setTextColour(colour);
  printf("*");
  setTextColour(WHITE);
  printf(" gives %d point(s) and has a spawn chance of %d percent.", score, spawnChance);
}
