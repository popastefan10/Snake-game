#ifndef OPTIONS_MENU_H_INCLUDED
#define OPTIONS_MENU_H_INCLUDED

#include "../Headers/functii.h"

class Options{
public:
  static const int minSpeed;
  static const int maxSpeed;
  static int snakeSpeed;
  static void loadOptions();
};


#endif
