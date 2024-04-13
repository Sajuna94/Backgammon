#include "../Headers/chess.h"
#include <stdio.h>

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

bool putCell(Chess* chess, int x, int y, Cell cell) {
    if (cell == BLACK && chess->board[y][x] == BANNED)
        return false;
    
    // update cord
    if (cell == BLACK || cell == WHITE) {
        chess->cord[chess->size].x = x;
        chess->cord[chess->size].y = y;
        chess->cord[chess->size].player = cell;
        chess->size++;
    }

    // put cell
    chess->board[y][x] = cell;

    return true;
}