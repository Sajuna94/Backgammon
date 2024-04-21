#include "../module/point.h"

Point newPoint(int x, int y) {
    Point point;

    point.X = x;
    point.Y = y;

    return point;
}

Point addPoint(Point pointA, Point pointB) {
    return newPoint(pointA.X + pointB.X, pointA.Y + pointB.Y);
}