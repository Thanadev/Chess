#ifndef CHESSTABTEST_H
#define CHESSTABTEST_H

#include "../Persistents/chesstab.h"
#include "basetest.h"

class ChesstabTest : public BaseTest
{
public:
    ChesstabTest();
    ~ChesstabTest();
    virtual void runTests();
private:
    bool createChessTabTest();
    bool populateChessTabTest();
    bool selectEmptyCellTest();
    bool selectOccupatedCellTest();
    bool movePieceToEmptyValidLocationTest();
    bool movePieceToNotEmptyNotValidLocationTest();

    ChessTab *chesstab;
};

#endif // CHESSTABTEST_H
