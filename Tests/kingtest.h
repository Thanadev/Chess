#ifndef KINGTEST_H
#define KINGTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/kingentity.h"

class KingTest : public BaseTest
{
public:
    KingTest();
    ~KingTest();
    void runTests();
protected:
    bool patternForwardValidTest();
    bool patternBackValidTest();
    bool patternLeftValidTest();
    bool patternRightValidTest();
    bool patternDiagonalNotValidTest();

    KingEntity *king;
};

#endif // KINGTEST_H
