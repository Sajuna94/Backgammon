#include <stdio.h>
#include "../Headers/game.h"

int main() {
    Cell me = BLACK, enemy = WHITE;

    Game *game = newGame(me, enemy);
    startGame(game);
}

// gcc -o main Sources/ban.c Sources/chess.c Sources/game.c Sources/weight.c

// "c": "cd $dir ; gcc -o $fileNameWithoutExt *.c ; start cmd \"/k $fileNameWithoutExt & pause & exit\""
// gcc *.c -o main ; Start-Process -FilePath "cmd" -ArgumentList "/k .\main & pause & exit"