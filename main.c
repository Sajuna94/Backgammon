#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 15

typedef enum { EMPTY = -1, BLACK = 0, WHITE = 1 } Square;

typedef struct
{
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chess;

typedef struct
{
    int X, Y;
    int value;
} Point;

// WEIGHT
void displayWeight(Point *points, int length);
Point* getWeightPoints(Chess* chess, int* length);
int comparePoint(const void* a, const void* b);
int calculateWeight(Chess* chess, int x, int y);

// CHESS
void displayChess(Chess* chess);
void newChess();
bool autoSetMove(Chess* chess);

// ==================================================================================================================================================
// CHESS
// ==================================================================================================================================================

void displayChess(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch (chess->board[y][x])
            {
            case EMPTY: printf(". "); break;
            case BLACK: printf("X "); break;
            case WHITE: printf("O "); break;
            }
        }
        printf("\n");
    }
}

void newChess() {
    Chess *chess = (chess*)malloc(sizeof(Chess));

    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            chess.board[y][x] = EMPTY;
        }

    return chess;
}

// 自動根據權重下棋 (沒寫完)
bool autoSetMove(Chess* chess, Square stoneColor) {
    int length;
    Point *weightPoints = getWeightPoints(chess, &length);

    Point targetPoint = weightPoints[length - 1];


    chess->board[targetPoint.Y][targetPoint.X] = stoneColor;

    return true;
}

// ==================================================================================================================================================
// WEIGHT
// ==================================================================================================================================================

// 計算權重
int calculateWeight(Chess* chess, int x, int y) {
    if (chess->board[y][x] != EMPTY)
        return 0;
    return 333;
}

int comparePoint(const void* a, const void* b) {
    const Point pointA = *(const Point*)a; 
    const Point pointB = *(const Point*)b;

    return pointA.value - pointB.value;
}

// 取得權重座標陣列 (Sorted)
Point* getWeightPoints(Chess* chess, int* length) {
    Point *points = (Point*)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(Point));

    int count = 0;
    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++) 
        {
            if (chess->board[y][x] != EMPTY)
                continue;

            points[count].X = x;
            points[count].Y = y;
            points[count].value = calculateWeight(chess, x, y);

            count++;
        }
    *length = count;
    
    points = (Point*)realloc(points, count * sizeof(points[0]));
    qsort(points, count, sizeof(Point), comparePoint);

    return points;
}

void displayWeight(Point *points, int length) {
    int weightMap[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < length; i++) {
        weightMap[points[i].Y][points[i].X] = points[i].value;
    }
    
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%d ", weightMap[y][x]);
        }
        printf("\n");
    }
}

// ==================================================================================================================================================
// MAIN
// ==================================================================================================================================================

int main(void) {
    Chess chess = newChess();

    int length = 0;
    Point *weightPoints = getWeightPoints(&chess, &length);

    displayWeight(weightPoints, length);
    displayChess(&chess);

    free(weightPoints);
    free(chess);
}