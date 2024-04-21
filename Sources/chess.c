#include "../Headers/chess.h"
#include <stdio.h>
#include <stdlib.h>

void displayChess(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch (chess->board[y][x])
            {
            case EMPTY: printf(". "); break;
            case BLACK: printf("X "); break;
            case WHITE: printf("O "); break;
            case BANNED: printf("@ "); break;
            }
        }
        printf("\n");
    }
};

Chess* newChess() {
    Chess *chess = (Chess*)malloc(sizeof(Chess));

    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            chess->board[y][x] = EMPTY;
        }
    chess->cord = NULL;
    chess->size = 0;

    return chess;
}

bool putCell(Chess* chess, Point point, Cell cell) {
    if (cell == BLACK && chess->board[point.Y][point.X] == BANNED)
        return false;
    // update cord
    if (cell == BLACK || cell == WHITE) {
        chess->cord = (Coordinate*)realloc(chess->cord, (chess->size + 1) * sizeof(Coordinate));
        chess->cord[chess->size].x = point.X;
        chess->cord[chess->size].y = point.Y;
        chess->cord[chess->size].player = cell;
        chess->size++;
    }

    // put cell
    chess->board[point.Y][point.X] = cell;

    return true;
}

bool checkWin(Chess* chess, Point point, Cell Player) {
    return false;
}