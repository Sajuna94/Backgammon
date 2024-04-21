#ifndef POINT_H
#define POINT_H

typedef struct {
    int X, Y;
} Point;

Point newPoint(int x, int y);

Point addPoint(Point pointA, Point pointB);

#endif /* POINT_H */