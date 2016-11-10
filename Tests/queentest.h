#ifndef QUEENTEST_H
#define QUEENTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/queenentity.h"

class QueenTest : public BaseTest
{
public:
    QueenTest();
    ~QueenTest();
    void runTests();

private:
    bool patternValidMovementTest();
    bool patternNotValidMovementTest();

    QueenEntity *queen;
};

#endif // QUEENTEST_H
