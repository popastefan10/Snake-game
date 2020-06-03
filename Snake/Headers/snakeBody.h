#ifndef SNAKEBODY_H_INCLUDED
#define SNAKEBODY_H_INCLUDED

#define SNAKE_BODY_COLOUR RED

#include <windows.h>
#include "functii.h"

class snakeBody {

private:
  int x;
  int y;
  char ch;
  WORD bodyColour;

public:
  snakeBody(int = 0, int = 0, char = 'O', WORD = SNAKE_BODY_COLOUR);
  ~snakeBody();

  void setCoords(int, int);
  int getX();
  int getY();

  void setCh(char);
  char getCh();

  void setBodyColour(WORD);
  WORD getBodyColour();
};

#endif // SNAKEBODY_H_INCLUDED
