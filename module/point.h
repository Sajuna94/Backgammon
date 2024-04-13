#ifndef POINT_H
#define POINT_H

typedef struct {
    int X, Y;
} Point;

Point newPoint(int x, int y) {
    Point point;

    point.X = x;
    point.Y = y;
    
    return point;
};

#endif /* POINT_H */