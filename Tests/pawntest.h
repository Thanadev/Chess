#ifndef PAWNTEST_H
#define PAWNTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/pawnentity.h"

class PawnTest : public BaseTest
{
public:
    PawnTest();
    ~PawnTest();
    virtual void runTests();

private:
    bool patternValidForwardTest();
    bool patternNonValidBackwardTest();
    bool pawnValidMoveTest();
    bool pawnNonValidMoveTest();

    PawnEntity *pawn;
};

#endif // PAWNTEST_H
