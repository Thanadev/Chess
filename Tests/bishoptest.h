#ifndef BISHOPTEST_H
#define BISHOPTEST_H

#include "basetest.h"
#include "../Persistents/Pieces/bishopentity.h"
#include "../Persistents/chesstab.h"

class BishopTest : public BaseTest
{
public:
    BishopTest();
    ~BishopTest();
    void runTests();
private:
    bool patternDiagonalValidTest();
    bool patternSidesNotValidTest();

    BishopEntity *bishop;
    ChessTab *tab;
};

#endif // BISHOPTEST_H
