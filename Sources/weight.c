#include "../Headers/weight.h"



int testLiveHelperFunc(Chess* chess, Piece piece, Point position) {
    bool DIE_3 = false, DIE_4 = false;
    bool LIVE_3 = false, LIVE_4 = false;

    for (int i = 0; i < 8; i+=2) {
        LiveHelper liveA = { .length = 0, .IS_LIVE = false };
        LiveHelper liveB = { .length = 0, .IS_LIVE = false };

        LiveDFS(chess, piece, dirPts[i], position.X + dirPts[i].X, position.Y + dirPts[i].Y, &liveA);
        LiveDFS(chess, piece, dirPts[i + 1], position.X + dirPts[i + 1].X, position.Y + dirPts[i + 1].Y, &liveB);

        LiveHelper liveResult = { .length = liveA.length + liveB.length, .IS_LIVE = liveA.IS_LIVE && liveB.IS_LIVE };

        if (liveResult.length >= 4) {
            if (liveResult.IS_LIVE)
                LIVE_4 = true;
            else
                DIE_4 = true;
        } else if (liveResult.length == 3) {
            if (liveResult.IS_LIVE)
                LIVE_3 = true;
            else
                DIE_3 = true;
        }
    }

    if (LIVE_4) {
        return 40;
    }
    if (LIVE_3) {
        return 35;
    }
    if (DIE_4) {
        return 20;
    }
    if (DIE_3) {
    }
    return 10;
}

LiveHelper* LiveDFS(Chess* chess, Piece piece, Point dirPt, int x, int y, LiveHelper* liveHelper) {
    if (!isSafe(x, y))
        return liveHelper;
    if (chess->board[y][x] != piece) {
        if (chess->board[y][x] == EMPTY)
            liveHelper->IS_LIVE = true;
        return liveHelper;
    }
    liveHelper->length++;

    return LiveDFS(chess, piece, dirPt, x + dirPt.X, y + dirPt.Y, liveHelper);
}