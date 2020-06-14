#include <cstdlib>
#include <time.h>
#include "../Headers/food.h"

const int foodCount = 6;
const int colourRangeSize = 100;

WORD foodColours[foodCount] = {RED, GREEN, BLUE, YELLOW, PURPLE, CYAN};
int colourScore[foodCount] = {1, 2, 3, 5, 7, 10};
int colourSpawnChance[foodCount] = {40, 25, 15, 9, 6, 5};
int colourRange[colourRangeSize];


food::food(int cx, int cy) {
  x = cx;
  y = cy;
  ch = '*';
}

food::~food() {

}

/** ----- accessors (set) and mutators (get) ----- **/

/// X

void food::setX(int newX) {
  x = newX;
}

int food::getX() {
  return x;
}

/// Y

void food::setY(int newY) {
  y = newY;
}

int food::getY() {
  return y;
}

/// Ch

void food::setCh(char newCh) {
  ch = newCh;
}

char food::getCh() {
  return ch;
}

/// ColourIndex

void food::setColourIndex(int newColourIndex) {
  colourIndex = newColourIndex;
}

int food::getColourIndex() {
  return colourIndex;
}

/// foodColour

WORD food::getFoodColour() {
  return foodColours[colourIndex];
}

/// colourScore

int food::getColourScore() {
  return colourScore[colourIndex];
}

/// foodScore

int food::getFoodScore() {
  return colourScore[colourIndex];
}

/** ----- food colour util functions ----- **/

void food::generateColourRange() {
  int top = 0;

  for(int i = 0; i < foodCount; i++) {
    for(int j = 0; j < colourSpawnChance[i]; j++)
      colourRange[top + j] = i;

    top += colourSpawnChance[i];
  }
}

int food::getRandomColourIndex() {
  srand(time(NULL));
  return colourRange[rand() % 100];
}

/** ----- draw food ----- **/

void food::draw() {
  WORD foodColour = getFoodColour();
  drawCh(x, y, foodColour, ch);
}

void food::setNewFoodColour() {
  colourIndex = getRandomColourIndex();
}
