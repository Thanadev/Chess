#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "basetest.h"
#include "../Persistents/player.h"
#include "../Persistents/Pieces/pawnentity.h"

class PlayerTest : public BaseTest
{
public:
    PlayerTest();
    ~PlayerTest();
    void runTests();
private:
    bool removePieceTest();
    bool getPiecesTest();

    Player *player;
    PawnEntity *pawn, *pawn2;
};

#endif // PLAYERTEST_H
