#include "../Headers/start_menu.h"
#include "../Headers/options_menu.h"

using namespace std;

/// this is the main function that manages all the components of the start menu
/// it returns true  if the user chooses "Start new game" button
/// it returns false if the user chooses "Quit" button

bool startMenu() {
  int selected = 0;
  bool pressStart, pressOptions, pressHelp;
  pressStart = pressOptions = pressHelp = false;

  while(!pressStart) {
    system("cls");
    hideCursor();
    drawStartMenu(selected);

    if(GetAsyncKeyState(ENTER) & MSB) {

      if(selected == 0) /// Start
        return true;
      else if(selected == 1) { /// Options
        system("cls");
        Options::loadOptions();
      }
      else if(selected == 2) { /// Help
        system("cls");
        loadHelp();
      }
      else if(selected == 3) /// Quit
        return false;
    }

    updateSelected(selected, 4);
    Sleep(50);
  }

  return true; /// the game will start
}

/// draws the buttons of the start menu

void drawStartMenu(int selected) {
  int csbLength, csbWidth;
  getConsoleScreenBufferSize(csbLength, csbWidth);

  drawMenuButton(csbLength / 2, csbWidth / 2 - 3, "Start new game", (selected == 0));
  drawMenuButton(csbLength / 2, csbWidth / 2 - 1, "Options", (selected == 1));
  drawMenuButton(csbLength / 2, csbWidth / 2 + 1, "Help", (selected == 2));
  drawMenuButton(csbLength / 2, csbWidth / 2 + 3, "Quit", (selected == 3));

  gotoXY(csbLength / 2 - 2, csbWidth / 2 - 3 + selected * 2);
  setTextColour(SELECTED_COLOUR);
  printf(">");
  setTextColour(WHITE);
}

