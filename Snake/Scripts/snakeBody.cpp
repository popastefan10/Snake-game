#include "../Headers/snakeBody.h"

snakeBody::snakeBody(int cx, int cy, char cch, WORD cBodyColour) {
  x = cx;
  y = cy;
  ch = cch;
  bodyColour = cBodyColour;
}

snakeBody::~snakeBody() {

}

/** ----- accessors (set) and mutators (get) ----- **/

/// X & Y

void snakeBody::setCoords(int cx, int cy) {
  x = cx;
  y = cy;
}

int snakeBody::getX() {
  return x;
}

int snakeBody::getY() {
  return y;
}

/// Ch

void snakeBody::setCh(char cch) {
  ch = cch;
}

char snakeBody::getCh() {
  return ch;
}

/// bodyColour

void snakeBody::setBodyColour(WORD newColour) {
  bodyColour = newColour;
}

WORD snakeBody::getBodyColour() {
  return bodyColour;
}
