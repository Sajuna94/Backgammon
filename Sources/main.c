#include "../Headers/game.h"

int main(void) {
    Game* game = newGame(BLACK, WHITE);
    Chess* chess = &game->chess;
    setChessPiece(&game->chess, BLACK, newPoint(0, 0));

    Piece winner = startGame(game);
    
    // displayChess(&game->chess);
    // printf("=====================================\n");
    // displayDistance(chess, BLACK);

    // printf("\nWINNER: %d\n", winner);
}