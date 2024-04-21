#include "../Headers/weight.h"
#include <stdio.h>

int floodPlayerMap[BOARD_SIZE][BOARD_SIZE];



void displayFloodMap() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%d ", floodPlayerMap[y][x]);
        }
        printf("\n");
    }
}

void floodMap(int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int t = 1; t <= 5; t++) {
            floodPlayerMap[y + (dy[i] * t)][x + (dx[i] * t)] += 1;
        }
    }
}