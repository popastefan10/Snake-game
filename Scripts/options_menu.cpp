#include "../Headers/options_menu.h"

using namespace std;

const int Options::minSpeed = 5;
const int Options::maxSpeed = 10;
int Options::snakeSpeed = Options::maxSpeed;/// se masoara in secunde, este convertit * 1000 in ms

void Options::loadOptions() {
  int crtY = 0;
  gotoXY(1, crtY);
  printf("<- Press Esc to go back");
  crtY+=2;
  gotoXY(1, crtY);
  printf("Press Right/Left arrow keys to change the speed value (the speed is measured in blocks per second):");
  crtY+=2;

  int speedUnit = 1;
  while(true) {
    hideCursor();
    if(GetAsyncKeyState(ESC) & MSB)
      break;

    setTextColour(SELECTED_COLOUR);

    if(Options::snakeSpeed != Options::minSpeed) {
      gotoXY(18,crtY);
      printf("<");
    }
    else {
      gotoXY(18,crtY);
      printf(" ");
    }

    if(Options::snakeSpeed != Options::maxSpeed){
      gotoXY(22,crtY);
      printf(">");
    }
    else {
      gotoXY(22,crtY);
      printf(" ");
    }

    gotoXY(20,crtY);
    printf("%d ",Options::snakeSpeed);

    setTextColour(WHITE);
    if(GetAsyncKeyState(VK_RIGHT) & MSB)
      Options::snakeSpeed = min(Options::maxSpeed,Options::snakeSpeed + speedUnit);
    if(GetAsyncKeyState(VK_LEFT) & MSB)
      Options::snakeSpeed = max(Options::minSpeed,Options::snakeSpeed - speedUnit);

    Sleep(200);

  }
}


