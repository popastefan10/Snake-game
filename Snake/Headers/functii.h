#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#include <windows.h>
#include <cstdio>
#include <iostream>

#define MSB 0x8000
#define ESC char(27)
#define ENTER char(13)

#define TABLE_LENGTH 72
#define TABLE_WIDTH  20

#define BLUE   FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define GREEN  FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define RED    FOREGROUND_RED | FOREGROUND_INTENSITY
#define YELLOW GREEN | RED
#define PURPLE RED | BLUE
#define CYAN   BLUE | GREEN
#define WHITE  RED | BLUE | GREEN

#define SELECTED_COLOUR RED

void gotoXY(int, int);
void hideCursor();

void drawCh(int, int, WORD, char);
void drawBorders();

WORD getCurrentTextColour();
void setTextColour(WORD);

bool validDirections(int, int);
int getNewDirection();

void getConsoleScreenBufferSize(int &, int &);
void updateSelected(int&, int);
void drawMenuButton(int, int, char *, bool);

#endif // FUNCTII_H_INCLUDED
