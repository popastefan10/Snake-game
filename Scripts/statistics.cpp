#include "../Headers/statistics.h"
#include "../Headers/functii.h"

bool drawStatistics(statistics stats) {
  int statsMinX = 2;
  int crtY = 2;

  gotoXY(statsMinX, crtY);
  setTextColour(RED);
  printf(">");
  setTextColour(WHITE);
  drawMenuButton(statsMinX + 2, crtY, "Continue", true);
  Sleep(100);

  if(GetAsyncKeyState(ENTER) & MSB)
    return false;
  return true;
}
