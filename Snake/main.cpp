#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib> /// rand(), srand()
#include <cmath> /// fmod()
#include "Headers/food.h"
#include "Headers/snake.h"
#include "Headers/start_menu.h"
#include "Headers/options_menu.h"
#include "Headers/pause_menu.h"
#include "Headers/statistics.h"

using namespace std;

bool foodSnakeCollision(food&, snake);
void spawnNewFood(food&, snake);
bool ateFood(food, snake);
void drawData(int);

int score = 0;
int foodEaten = 0;

clock_t startTime;

/** ----- main ----- **/

int main() {

  /** ----- start menu ----- **/

  while(startMenu()) {
    startTime = clock();

    system("cls");

    /** ----- the game ----- **/

    drawBorders();
    drawData(INITIAL_BODY_LENGTH);

    snake playerSnake;
    food Food;
    Food.generateColourRange();
    bool noFood = true;
    bool quitPause = false;

    statistics stats;

    /** ----- the game cycle ----- **/

    while(!playerSnake.collision()) {
      playerSnake.draw();
      hideCursor();
      drawData(playerSnake.getBodyLength());

      /// check for pause
      if(GetAsyncKeyState(ESC) & MSB) {
        if(!Pause()) {
          quitPause = true;
          break;
        }
        else { /// draw the game again
          system("cls");

          drawBorders();
          hideCursor();

          playerSnake.draw();
          Food.draw();
          drawData(playerSnake.getBodyLength());
        }
      }

      if(ateFood(Food, playerSnake) || noFood) {
        if(!noFood) {
          playerSnake.growTail();
          score += Food.getFoodScore();
          foodEaten++;
        }

        spawnNewFood(Food, playerSnake);
        Food.draw();
        noFood = false;
      }
      else
        playerSnake.deleteTail();

      int newDirection = getNewDirection();

      if(newDirection != -1 && validDirections(newDirection, playerSnake.getDirection()))
        playerSnake.setDirection(newDirection);

      playerSnake.moveBody();

      Sleep((DWORD) 150);
    }

    if(!quitPause) {
      stats.snakeLength = playerSnake.getBodyLength();
      stats.totalTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

      system("cls");
      while(drawStatistics(stats)) {
        int csbLength, csbWidth;
        getConsoleScreenBufferSize(csbLength, csbWidth);

        gotoXY(csbLength / 2, 0);
        setTextColour(RED);
        printf("GAME OVER!");
        system("cls");
      }

      Sleep(1000 / Options::snakeSpeed);
    }
  }

  return 0;
}

/** ----- util functions ----- **/

/// this is used to prevent spawning the food on the snake's body
/// it has a different purpose than "ateFood" function

bool foodSnakeCollision(food &Food, snake Snake) {
  for(int i = 0; i < Snake.getBodyLength(); i++) {
    int SX = Snake.getCrtBody(i).getX();
    int SY = Snake.getCrtBody(i).getY();
    int FX = Food.getX();
    int FY = Food.getY();

    if(SX == FX && SY == FY)
      return true;
  }

  return false;
}

/// sets new coordinates for the food

void spawnNewFood(food &Food, snake Snake) {
  do {
    srand(time(NULL));

    int newX = rand() % (TABLE_LENGTH - 4) + 2;
    int newY = rand() % (TABLE_WIDTH - 4) + 2;

    Food.setX(newX);
    Food.setY(newY);
  } while(foodSnakeCollision(Food, Snake));
}

/// returns true if the food has been eaten, false otherwise

bool ateFood(food Food, snake Snake) {
  int HX = Snake.getSnakeHead().getX();
  int HY = Snake.getSnakeHead().getY();
  int FX = Food.getX();
  int FY = Food.getY();

  return (HX == FX) && (HY == FY);
}

/// draws player score, the snake's body length
/// and how many food has been eaten

void drawData(int snakeLength) {
  WORD crtTextColour = getCurrentTextColour();
  setTextColour(GREEN);

  gotoXY(TABLE_LENGTH + 10, TABLE_WIDTH / 2);
  printf("Score: %d", score);
  gotoXY(TABLE_LENGTH + 10, TABLE_WIDTH / 2 + 1);
  printf("Snake's length: %d", snakeLength);
  gotoXY(TABLE_LENGTH + 10, TABLE_WIDTH / 2 + 2);
  printf("Food eaten: %d", foodEaten);

  gotoXY(TABLE_LENGTH + 10, TABLE_WIDTH / 2 + 3);
  double timeElapsed = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  printf("Time elapsed: %d min %.1f s    ", (int)(timeElapsed / 60.0), fmod(timeElapsed, 60.0));

  setTextColour(crtTextColour);
}
