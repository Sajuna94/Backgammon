#ifndef WEIGHT_H
#define WEIGHT_H

#include "chess.h"

typedef struct
{
    int X, Y;
    int weight;
} WeightedPoint;

int calculateWeight(Chess* chess, int x, int y);

WeightedPoint* getWeightPoints(Chess* chess, int* length);

void displayWeight(WeightedPoint *weightPoints, int pointsLength);



#endif /* WEIGHT_H */