#include <stdio.h>
#include "../Headers/game.h"

void displayChess(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch (chess->board[y][x])
            {
            case EMPTY: printf(". "); break;
            case BLACK: printf("X "); break;
            case WHITE: printf("O "); break;
            case BAN: printf("@ "); break;
            }
        }
        printf("\n");
    }
};

Chess newChess() {
    Chess chess;

    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++) {
            chess.board[y][x] = EMPTY;
            chess.distanceMaps[BLACK][y][x] = 5;
            chess.distanceMaps[WHITE][y][x] = 5;
        }
    return chess;
}

void displayDistance(Chess* chess, Piece piece) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%d ", chess->distanceMaps[piece][y][x]);
        }
        printf("\n");
    }
}

bool isSafe(int x, int y) {
    if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE)
        return false;
    return true;
}

int countPieceLength(Chess* chess, Piece piece, Point dirPt, int x, int y) {
    // if (!isSafe(x, y))
    //     return 0;
    // if (chess->board[y][x] != piece)
    //     return 0;
    
    // return countPieceLength(chess, piece, dirPt, x + dirPt.X, y + dirPt.Y) + 1;
}

int calcDistance(Chess* chess, Piece piece, Point position) {
    // int maxTotal = 0;
    // for (int i = 0; i < 4; i++) {
    //     Point dirPtLeft = newPoint(dx[(i * 2)], dy[(i * 2)]);
    //     Point dirPtRight = newPoint(dx[(i * 2) + 1], dy[(i * 2) + 1]);

    //     int total = 
    //         countPieceLength(chess, piece, dirPtLeft, position.X + dirPtLeft.X, position.Y + dirPtLeft.Y) +
    //         countPieceLength(chess, piece, dirPtRight, position.X + dirPtRight.X, position.Y + dirPtRight.Y);
    //     printf("%d\n", total);
    //     maxTotal = ((total) > maxTotal) ? (total) : maxTotal;
    // }
    // return maxTotal;
}

void updateDistance(Chess* chess, Piece piece, Point position) {
    // for (int y = 0; y < BOARD_SIZE; y++) {
    //     for (int x = 0; x < BOARD_SIZE; x++) {
    //         if (chess->board[y][x] != EMPTY)
    //             continue;
    //         chess->distanceMaps[piece][position.Y][position.X] = calcDistance(chess, piece, newPoint(position.X, position.Y));
    //     }
    // }
}

bool checkWin(Chess* chess, Piece piece, Point position) {
    Piece currentPiece = chess->board[position.Y][position.X];
    
    if (chess->distanceMaps[currentPiece][position.Y][position.X] == 1)
        return true;
    return false;
}

void setChessPiece(Chess* chess, Piece piece, Point position) {
    chess->board[position.Y][position.X] = piece;

    // updateDistance(chess, piece, position);
}
