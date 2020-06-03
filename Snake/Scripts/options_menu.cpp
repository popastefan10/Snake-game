#include "../Headers/options_menu.h"

using namespace std;

int Options::snakeSpeed = 1;/// se masoara in secunde, este convertit * 1000 in ms
const int Options::minSpeed = 1;
const int Options::maxSpeed = 5;

void Options::loadOptions(){
  int indentare = 0;
  gotoXY(1, indentare);
  printf("<- Press Esc to go back");
  indentare+=2;
  gotoXY(1, indentare);
  printf("Press Right/Left arrow keys to change the speed value");
  indentare+=2;

  int aduna = 1;
  while(true) {
    hideCursor();
    if(GetAsyncKeyState(ESC) & MSB)
      break;

    setTextColour(SELECTED_COLOUR);
    if(Options::snakeSpeed != Options::minSpeed){
      gotoXY(18,indentare);
      printf("<");
    }else{
      gotoXY(18,indentare);
      printf(" ");
    }
    if(Options::snakeSpeed != Options::maxSpeed){
      gotoXY(22,indentare);
      printf(">");
    }else{
      gotoXY(22,indentare);
      printf(" ");
    }

    gotoXY(20,indentare);
    printf("%d",Options::snakeSpeed);

    setTextColour(WHITE);
    if(GetAsyncKeyState(VK_RIGHT) & MSB){
      Options::snakeSpeed = min(Options::maxSpeed,Options::snakeSpeed + aduna);
    }
    if(GetAsyncKeyState(VK_LEFT) & MSB){
      Options::snakeSpeed = max(Options::minSpeed,Options::snakeSpeed - aduna);
    }

    Sleep(200);

  }
}


