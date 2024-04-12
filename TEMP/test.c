#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define PLAYER_A 0
#define PLAYER_B 1

// 棋盤大小
#define BOARD_SIZE 15

typedef enum square { EMPTY = -1, BLACK = 0, WHITE = 1, BAN } Square;

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

// CHESS
void displayChess(Chess* chess);
Chess* newChess();
Point getNextMove(Chess* chess);
bool setXY(Chess* chess, int x, int y, Square player);

// WEIGHT
void displayWeight(Point *points, int length);
Point* getWeightPoints(Chess* chess, int* length);
int comparePoint(const void* a, const void* b);
int calculateWeight(Chess* chess, int x, int y);

// ==================================================================================================================================================
// FILE
// ==================================================================================================================================================

void printChess(Chess* chess) {
    for (int i = 0; i < chess->cordSize; i++) {
        printf("(%d, %d, %d) ", chess->cord[i].x, chess->cord[i].y, chess->cord[i].player);
    }
    printf("size=%d\n", chess->cordSize);
}

// ==================================================================================================================================================
// CHESS
// ==================================================================================================================================================

// 依據權重下棋 -> (如果是黑方)自動更新禁點 

void displayChess(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("%2d ", y);
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
}

Chess* newChess() {
    Chess *chess = (Chess*)malloc(sizeof(Chess));

    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            chess->board[y][x] = EMPTY;
        }
    chess->cord = NULL;
    chess->cordSize = 0;

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
// CHECK
// ==================================================================================================================================================

Square checkWinner(Chess* chess, int x, int y) {
    Square player = chess->board[y][x];

    // if player.... == 5 return player

    return EMPTY;
}

bool isBannedCell(Chess* chess, int x, int y) {
    if (chess->board[y][x] != EMPTY)
        return false;
    
    // if rule 1... return true

    return false;
}

void updateBannedCell(Chess* chess) {
    for (int y = 0; y < BOARD_SIZE; y++)
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            if (isBannedCell(chess, x, y))
                chess->board[y][x] = BAN;
        }
}

// ==================================================================================================================================================
// WEIGHT
// ==================================================================================================================================================

// 計算權重 (不用考慮該格狀態)
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
    Point *points = (Point*)malloc((BOARD_SIZE * BOARD_SIZE) * sizeof(Point));

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

Square swapPlayer(Square player) {
    if (player == BLACK)
        return WHITE;
    return BLACK;
}

void oneTurn() {
    // ...
}

int main(void) {
    Chess *chess = newChess();

    chess->board[0][1] = WHITE;
    chess->board[0][2] = WHITE;
    chess->board[0][3] = WHITE;
    chess->board[0][4] = WHITE;
    chess->board[0][5] = WHITE;

    Square winner = checkWinner(chess, 0, 1);
    if (winner != EMPTY)
        printf("Winner is player: %d", winner);

    int length = 0;
    Point *weightPoints = getWeightPoints(chess, &length);

    // 顯示數據
    displayWeight(weightPoints, length);
    displayChess(chess);
    printChess(chess);

    // 釋放記憶體
    free(weightPoints);
    free(chess);
}