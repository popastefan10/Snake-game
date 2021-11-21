#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include <windows.h>
#include "functii.h"

class food {

private:
  int x;
  int y;
  char ch;
  int colourIndex;

public:
  food(int = 1, int = 1);
  ~food();

  /// accesori

  void setX(int);
  int getX();

  void setY(int);
  int getY();

  void setCh(char);
  char getCh();

  void setColourIndex(int);
  int getColourIndex();

  WORD getFoodColour();

  int getColourScore();

  int getFoodScore();

  /// colour score util functions

  void generateColourRange();
  int getRandomColourIndex();

  /// draw food

  void draw();
  void setNewFoodColour();
};

#endif // FOOD_H_INCLUDED
