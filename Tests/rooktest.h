#ifndef ROOKTEST_H
#define ROOKTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/rookentity.h"

class RookTest : public BaseTest
{
public:
    RookTest();
    ~RookTest();
    void runTests();
private:
    bool patternValidMovementTest();
    bool patternNotValidMovementTest();

    RookEntity *rook;
};

#endif // ROOKTEST_H
