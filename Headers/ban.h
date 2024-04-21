#ifndef BAN_H
#define BAN_H

#include <stdbool.h>
#include "../module/point.h"
#include "chess.h"

typedef enum { LIVE3, DIE3, LIVE4, DIE4 } BanType;


typedef struct {
    int x, y;

    // bool DIE_FLAG;
    // int connectCount;

    // bool LIVE3_FLAG;
    // bool DIE3_FLAG;
    // bool LIVE4_FLAG;
    // bool DIE4_FLAG;
} CellStatePoint;

bool isBannedCell(Chess* chess, Point point);

void updateBanned(Chess* chess);

#endif /* BAN_H */
