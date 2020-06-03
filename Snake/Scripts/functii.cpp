#include "../Headers/functii.h"

/// sets new coordinates for the console cursor
void gotoXY(int x, int y) {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coord;

  coord.X = x;
  coord.Y = y;

  SetConsoleCursorPosition(hOut, coord);
}

/// makes the cursor disappear from the console screen
void hideCursor() {
  CONSOLE_CURSOR_INFO conCurInf;
  conCurInf.bVisible = FALSE;
  conCurInf.dwSize = 100;

  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &conCurInf);
}

/** ----- drawing functions ----- **/

/// draws a coloured character at specified coordinates
void drawCh(int x, int y, WORD newColour, char ch) {
  gotoXY(x, y);

  /// get the current text colour
  int crtTextColour = getCurrentTextColour();

  /// update the text colour
  setTextColour(newColour);
  printf("%c", ch);

  ///restore the old text colour
  setTextColour(crtTextColour);
}

/// draws the game borders
void drawBorders() {
  for(int i = 0; i < TABLE_LENGTH; i++) {
    gotoXY(i, 0);
    printf("#");

    gotoXY(i, TABLE_WIDTH - 1);
    printf("#");
  }

  for(int i = 1; i < TABLE_WIDTH - 1; i++) {
    gotoXY(0, i);
    printf("#");

    gotoXY(TABLE_LENGTH - 1, i);
    printf("#");
  }
}

/** ----- text colour managing ----- **/

/// returns the current console text colour
WORD getCurrentTextColour() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO conScrBuffInf;
  GetConsoleScreenBufferInfo(hOut, &conScrBuffInf);

  return conScrBuffInf.wAttributes;
}

/// sets a new console text colour
void setTextColour(WORD colour) {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hOut, colour);
}

/** ----- moving direction ----- **/

/// checks if the new direction is not the opposite of the current direction
bool validDirections(int dir1, int dir2) {
  return (dir1 % 2) != (dir2 % 2);
  /// 0 and 2 are not valid, as well as 1 and 3
}

/// returns a new direction, based on keyboard input
int getNewDirection() {
  if(GetAsyncKeyState(VK_UP) & MSB)
    return 0;
  if(GetAsyncKeyState(VK_RIGHT) & MSB)
    return 1;
  if(GetAsyncKeyState(VK_DOWN) & MSB)
    return 2;
  if(GetAsyncKeyState(VK_LEFT) & MSB)
    return 3;
  return -1;
}

/** ----- menu functions ----- **/

/// the 2 parameters will det the length and width of the console screen buffer (csb)
void getConsoleScreenBufferSize(int &csbLength, int &csbWidth) {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbInfo;

  GetConsoleScreenBufferInfo(hOut, &csbInfo);
  SMALL_RECT sr = csbInfo.srWindow;

  csbLength = sr.Right - sr.Left;
  csbWidth  = sr.Bottom - sr.Top;
}

/// updates the selected button, based on keyboard input
void updateSelected(int &selected, int buttonsCount) {
  if(GetAsyncKeyState(VK_DOWN) & MSB)
    selected = (selected + 1) % buttonsCount;
  if(GetAsyncKeyState(VK_UP) & MSB)
    selected = (selected + buttonsCount - 1) % buttonsCount;
//  if(GetAsyncKeyState(VK_DOWN) & MSB)
//    selected = std::min(selected + 1, buttonsCount - 1);
//  if(GetAsyncKeyState(VK_UP) & MSB)
//    selected = std::max(selected - 1, 0);
}

/// draws a menu button, which is actually a string, at specified coordinates
/// the button will be coloured if useColour is true
void drawMenuButton(int x, int y, char *msg, bool useColour) {
  gotoXY(x, y);
  if(useColour)
    setTextColour(SELECTED_COLOUR);
  printf("%s", msg);
  setTextColour(WHITE);
}
