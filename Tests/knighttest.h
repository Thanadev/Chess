#ifndef KNIGHTTEST_H
#define KNIGHTTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/knightentity.h"

class KnightTest : public BaseTest
{
public:
    KnightTest();
    ~KnightTest();
    void runTests();
private:
    bool patternMovementValidTest();
    bool patternMovementNotValidTest();

    KnightEntity *knight;
};

#endif // KNIGHTTEST_H
