#ifndef GAME_H
#define GAME_H

#include "chess.h"
#include "weight.h"

typedef struct
{
    Chess* chess;
    Cell ME, ENEMY;
} Game;

Game* newGame(Cell me, Cell enemy);

void startGame(Game* game);

void endGame(Game* game);

#endif /* GAME_H */