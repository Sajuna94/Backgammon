#include <stdlib.h>
#include <stdio.h>
#include "../Headers/game.h"

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

void startGame(Game* game) {
    
    Cell currentPlayer = BLACK;
        displayChess(game->chess);
    
    int count = 0;
    while (count < 50)
    {
        // 棋子落點
        Point currentPoint;

        // 取得棋子落點
        if (currentPlayer == game->ENEMY) {
            // TODO: 取得敵方落點
            // currentPoint = 敵方落點();
            currentPoint = newPoint(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
        }
        else if (currentPlayer == game->ME) {
            // TODO: 計算我方落點
            // currentPoint = 我的落點();
            currentPoint = newPoint(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
        }
        // 下棋
        
        // (1) 下棋
        if (!putCell(game->chess, currentPoint, currentPlayer)) {
            // TODO: 下棋失敗處理 (可能不用做)
        }

        // (2) 更新禁點
        // updateBanned(game->chess);

        // (3) 判定勝方
        if (checkWin(game->chess, currentPoint, currentPlayer)) {
            // TODO: 某方獲勝的事件處理 (好像是不用做啦)
            break;
        }

        // 輪到下一個玩家
        swapPlayer(&currentPlayer);

        // test print
        count++;
        displayChess(game->chess);
        printf("===================================\n");
    }
}

void endGame(Game* game) {
    // free
    free(game->chess);
    free(game);
}