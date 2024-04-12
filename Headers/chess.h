#ifndef CHESS_H
#define CHESS_H

#define BOARD_SIZE 15

// 定義棋盤格子狀態
typedef enum { EMPTY, BLACK, WHITE } Cell;

typedef struct
{
    Cell board[BOARD_SIZE][BOARD_SIZE];
} Chess;

void displayChess(Chess* chess);

#endif /* CHESS_H */