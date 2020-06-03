#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define INITIAL_BODY_LENGTH  4

#include <vector>
#include "snakeBody.h"

class snake {

private:
  std::vector <snakeBody> body;
  int direction;
  snakeBody oldTail;

public:
  snake();
  ~snake();

  int getBodyLength();

  void setDirection(int);
  int getDirection();

  snakeBody getCrtBody(int);
  snakeBody getSnakeHead();

  void deleteTail();
  void draw();

  bool collision();

  void moveBody();
  void growTail();

  void printCoords();
};

#endif // SNAKE_H_INCLUDED
