#ifndef CHESS_H
#define CHESS_H

#include "../module/point.h"
#include <stdbool.h>

#define BOARD_SIZE 15

// L-R, U-D, LU-RD, RU-LD
static const int dx[] = { -1, 1,   0,  0,   -1,  1,    1, -1  };
static const int dy[] = {  0, 0,   1, -1,   -1,  1,   -1,  1  };

// 定義棋盤格子狀態
typedef enum { EMPTY, BLACK, WHITE, BANNED } Cell;

typedef struct {
    int x, y;
    Cell player;
} Coordinate;

typedef struct
{
    Coordinate *cord;
    int size;

    Cell board[BOARD_SIZE][BOARD_SIZE];
} Chess;

void displayChess(Chess* chess);

Chess* newChess();

bool putCell(Chess* chess, Point point, Cell cell);

bool checkWin(Chess* chess, Point point, Cell Player);

#endif /* CHESS_H */