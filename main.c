#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 15

typedef enum { EMPTY = -1, BLACK = 0, WHITE = 1 } Square;

typedef struct {
    int x;
    int y;
    Square player;
} Coordinate;

typedef struct
{
    Coordinate* cord;
    int cordSize;

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
Chess* newChess();
Point getNextMove(Chess* chess);
bool setXY(Chess* chess, int x, int y, Square player);

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

Chess* newChess() {
    Chess *chess = (Chess*)malloc(sizeof(Chess));

    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            chess->board[y][x] = EMPTY;
        }

    return chess;
}

Point getNextMove(Chess* chess) {
    int length;
    Point *weightPoints = getWeightPoints(chess, &length);

    return weightPoints[length - 1];
}

bool setXY(Chess* chess, int x, int y, Square player) {
    if (chess->board[y][x] != EMPTY)
        return false;

    // update cord
    chess->cord = (Coordinate*)realloc(chess->cord, (chess->cordSize + 1) * sizeof(Coordinate));
    chess->cord[chess->cordSize].x = x;
    chess->cord[chess->cordSize].y = y;
    chess->cord[chess->cordSize].player = player;
    chess->cordSize++;

    // update board
    chess->board[y][x] = player;

    return true;
}

// ==================================================================================================================================================
// WEIGHT
// ==================================================================================================================================================

// 計算權重
int calculateWeight(Chess* chess, int x, int y) {
    return rand() % 100; // 0 ~ 99
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
    int weightMap[BOARD_SIZE][BOARD_SIZE] = { 0 };
    Point point = points[length - 1];

    for (int i = 0; i < length; i++) {
        weightMap[points[i].Y][points[i].X] = points[i].value;
    }
    
    for (int i = 0; i < BOARD_SIZE * 7; i++) printf("="); printf("\n");

    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%4d | ", weightMap[y][x]);
        }
        printf("\n");
    }

    for (int i = 0; i < BOARD_SIZE * 7; i++) printf("="); printf("\n");
    printf("Max Point(%d, %d), Value: %d\n", point.X, point.Y, point.value);
    for (int i = 0; i < BOARD_SIZE * 7; i++) printf("="); printf("\n");
}

// ==================================================================================================================================================
// MAIN
// ==================================================================================================================================================

int main(void) {
    Chess *chess = newChess();

    for (int i = 0; i < BOARD_SIZE; i++)
        chess->board[2][i] = BLACK;
    for (int i = 0; i < BOARD_SIZE; i++)
        chess->board[i][i] = WHITE;

    int length = 0;
    Point *weightPoints = getWeightPoints(chess, &length);

    displayWeight(weightPoints, length);
    displayChess(chess);

    free(weightPoints);
    free(chess);
}