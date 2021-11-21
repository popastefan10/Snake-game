#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED

struct statistics {
  double totalTime;
  int score;
  int snakeLength;
  int foodQty;
  int foodColourQty[10];
  int dirChanges;

  statistics() {
    totalTime = 0;
    score = 0;
    snakeLength = 0;
    foodQty = 0;
    for(int i = 0; i < 10; i++)
      foodColourQty[i] = 0;
    dirChanges = 0;
  }
};

bool drawStatistics(statistics);

#endif // STATISTICS_H_INCLUDED
