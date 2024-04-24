#include "../Headers/game.h"

Game* newGame(Piece myPiece, Piece enemyPiece) {
    Game* game = (Game*)malloc(sizeof(Game));

    game->me = myPiece;
    game->enemy = enemyPiece;

    game->chess = newChess();
    game->cord = NULL;
    game->size = 0;

    return game;
}

void swapPlayer(Piece* player) {
    *player = (*player == BLACK) ? WHITE : BLACK;
}

bool tryPutPiece(Game* game, Piece player, Point position) {
    Chess* chess = &game->chess;

    if (player == BLACK && chess->board[position.Y][position.X] == BAN)
        return false;
    
    setChessPiece(chess, player, position);   

    // TODO: update weight
    // TODO: update banned 

    // update cord
    game->cord = realloc(game->cord, (game->size + 1) * sizeof(Coordinate));
    game->cord[game->size].x = position.X;
    game->cord[game->size].y = position.Y;
    game->cord[game->size].player = player;
    game->size++;

    return true;
}

Point getNextMove(Game* game) {
    // TODO: 取得下棋位置
    return newPoint(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
}

Piece startGame(Game* game) {
    srand(time(NULL));
    int maxMoves = BOARD_SIZE * BOARD_SIZE, moveCount = 0;

    Piece currentPlayer = BLACK;

    while (moveCount < maxMoves)
    {
        Point move = newPoint(0, 0); // 要下棋的位置

        if (currentPlayer == game->enemy) {
            // TODO: 取得對方下棋位置
            // move = newPoint(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
        }
        else if (currentPlayer == game->me) {
            move = getNextMove(game);
        }

        if (!tryPutPiece(game, currentPlayer, move)) {
            // TODO: 下棋失敗處理 (可能不用做)
            continue;
        }

        // if (checkWin(&game->chess, currentPlayer, move)) {
        //     return currentPlayer;
        // }

        swapPlayer(&currentPlayer);
        moveCount++;
    }

    return EMPTY;
}