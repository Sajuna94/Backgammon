#ifndef CHESS_H
#define CHESS_H

#include <stdbool.h>

#define BOARD_SIZE 15

// 定義棋盤格子狀態
typedef enum { EMPTY, BLACK, WHITE, BANNED } Cell;

typedef struct {
    int x;
    int y;
    Cell player;
} Coordinate;

typedef struct
{
    Coordinate *cord;
    int size;

    Cell board[BOARD_SIZE][BOARD_SIZE];
} Chess;

void displayChess(Chess* chess);

bool putCell(Chess* chess, int x, int y);

#endif /* CHESS_H */