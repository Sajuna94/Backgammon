#include "../Headers/ban.h"

// L-R, U-D, LU-RD, RU-LD
const int dx[] = { -1, 1,   0,  0,   -1,  1,    1, -1  };
const int dy[] = {  0, 0,   1, -1,   -1,  1,   -1,  1  };

bool isBannedCell(Chess* chess, int x, int y) {

    CellStatePoint cellStatePointA;
    CellStatePoint cellStatePointB;

}

void testFunc(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (chess->board[y][x] == EMPTY) {
                for (int i = 0; i < 8; i += 2) {
                    CellStatePoint cellStatePointA = getStatePoint(chess, x + dx[i], y + dy[i]);
                    CellStatePoint cellStatePointB = getStatePoint(chess, x + dx[i + 1], y + dy[i + 1]);
                }
            }
        }
    }
}

CellStatePoint getStatePoint(Chess* chess, int x, int y) {
    Cell cell = chess->board[y][x];

    
}


void updateCellState() {

}



