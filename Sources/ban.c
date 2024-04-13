#include "../Headers/ban.h"
#include "../module/point.h"

// 沒想法 看不懂禁點 :)

// L-R, U-D, LU-RD, RU-LD
const int dx[] = { -1, 1,   0,  0,   -1,  1,    1, -1  };
const int dy[] = {  0, 0,   1, -1,   -1,  1,   -1,  1  };

bool isBannedCell(Chess* chess, int x, int y) {

}

void testFunc(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (chess->board[y][x] == EMPTY) {
                for (int i = 0; i < 8; i ++) {
                    CellStatePoint cellStatePointA = getStatePoint(chess, newPoint(x, y), newPoint(dx[i], dy[i]));
                }
            }
        }
    }
}

CellStatePoint getStatePoint(Chess* chess, Point pos, Point dir) {
    Cell cellA = chess->board[pos.Y + dir.Y][pos.X + dir.X];
}

void updateCellState() {

}



