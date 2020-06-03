#include "../Headers/pause_menu.h"
#include "../Headers/functii.h"

/// draws the pause menu

void drawPauseMenu(int selected) {
  int csbLength, csbWidth;
  getConsoleScreenBufferSize(csbLength, csbWidth);

  drawMenuButton(csbLength / 2, csbWidth / 2 - 1, "Continue", (selected == 0));
  drawMenuButton(csbLength / 2, csbWidth / 2 + 1, "Quit", (selected == 1));

  gotoXY(csbLength / 2 - 2, csbWidth / 2 - 1 + selected * 2);
  setTextColour(SELECTED_COLOUR);
  printf(">");
  setTextColour(WHITE);
}

/// draws a pause menu if esc was pressed in game

bool Pause() {
  int selected = 0;

  system("cls");
  while(true) {
    system("cls");
    drawPauseMenu(selected);
    hideCursor();

    if(GetAsyncKeyState(ENTER) & MSB) {

      if(selected == 0)
        return true;
      else
        return false;
    }

    updateSelected(selected, 2);
    Sleep(10);
  }
}
