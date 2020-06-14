#include <iostream>
#include <cstdio>
#include "../Headers/snake.h"

/// 0 -> up, 1 -> right, 2 -> down, 3 -> left
int incX[4] = {0, 1, 0, -1};
int incY[4] = {-1, 0, 1, 0};

snake::snake(Harta h) {
//  int x = TABLE_LENGTH / 2;
//  int y = TABLE_WIDTH / 2;
  harta = h;
  int x = h.length / 2;
  int y = h.width / 2;

  for(int i = 0; i < INITIAL_BODY_LENGTH; i++)
    body.push_back(snakeBody(x + i, y));

  direction = 3;

  oldTail.setCoords(1, 1);
}

snake::~snake() {

}

/** ----- accessors (set) and mutators (get) ----- **/

/// bodyLength

int snake::getBodyLength() {
  return body.size();
}

/// direction

void snake::setDirection(int dir) {
  direction = dir;
}

int snake::getDirection() {
  return direction;
}

/// body parts

snakeBody snake::getCrtBody(int pos) {
  return body[pos];
}

snakeBody snake::getSnakeHead() {
  return body[0];
}

/** draw / delete ----- **/

void snake::deleteTail() {
  gotoXY(oldTail.getX(), oldTail.getY());
  printf(" ");
}

void snake::draw() {
  for(snakeBody crtBody: body)
    drawCh(crtBody.getX(), crtBody.getY(), crtBody.getBodyColour(), crtBody.getCh());
}

/** collision detection ----- **/

bool snake::collision() {
  int headX = body[0].getX();
  int headY = body[0].getY();

  if(headX == 0 || headX == harta.length - 1 || headY == 0 || headY == harta.width - 1 || harta.estePerete(headX,headY))
    return true;

  int bodyLength = getBodyLength();
  for(int i = 1; i < bodyLength; i++)
    if(body[i].getX() == headX && body[i].getY() == headY)
      return true;

  return false;
}

/** move / modify the body ----- **/

void snake::moveBody() {
  oldTail.setCoords(body.back().getX(), body.back().getY());

  int bodyLength = getBodyLength();
  for(int i = bodyLength - 1; i > 0; i--)
    body[i].setCoords(body[i - 1].getX(), body[i - 1].getY());

  int headX = body[0].getX();
  int headY = body[0].getY();
  body[0].setCoords(headX + incX[direction], headY + incY[direction]);
}

void snake::growTail() {
  body.push_back(oldTail);
}

/** for debugging ----- **/

void snake::printCoords() {
  gotoXY(TABLE_LENGTH + 1, 0);
  for(snakeBody crtBody: body)
    printf("x: %d y: %d || ", crtBody.getX(), crtBody.getY());
}
