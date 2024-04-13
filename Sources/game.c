#include "../Headers/game.h"

#include <stdlib.h>

Game* newGame(Cell me, Cell enemy) {
    Game* game = (Game*)malloc(sizeof(Game));

    game->chess = newChess();
    game->ME = me;
    game->ENEMY = enemy;

    return game;
}

void swapPlayer(Cell *player) {
    if (*player == BLACK)
        *player = WHITE;
    else
        *player = BLACK;
}

void autoPutCell(Chess* chess, Cell cell) {
    int length = 0;
    WeightedPoint *weightPoints = getWeightPoints(chess, &length);

    WeightedPoint targetPoint = weightPoints[length - 1];

    putCell(chess, targetPoint.X, targetPoint.Y, cell); 
}

void startGame(Game* game) {

    Cell currentPlayer = BLACK;
    
    if (currentPlayer == game->ENEMY) {
        // 接收敵人旗子落點
        int x, y;
        putCell(game->chess, x, y, game->ENEMY);
    }
    else {
        // 下棋
        autoPutCell(game->chess, game->ME);
    }

    swapPlayer(&currentPlayer);
}

void endGame(Game* game) {
    // free
    free(game->chess);
    free(game);
}