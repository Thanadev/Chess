#include "bishoptest.h"

BishopTest::BishopTest()
{
    bishop = new BishopEntity(Position(), true);
    tab = new ChessTab();
    tab->createTab();
    tab->populateTab();
}

BishopTest::~BishopTest()
{
    delete bishop;
}

void BishopTest::runTests()
{
    qDebug() << "BishopTests";
    Q_ASSERT_X(patternDiagonalValidTest(), "patternDiagonalValidTest", "");
    Q_ASSERT_X(patternSidesNotValidTest(), "patternSidesNotValidTest", "");
}

bool BishopTest::patternDiagonalValidTest()
{
    bool isValid = false;

    // check diagonals with pattern AND check that no one is in the way
    if (bishop->getPattern()->checkPattern(Position(4,4), Position(5,5)) &&
            bishop->getPattern()->checkPattern(Position(4,4), Position(3,3)) &&
            bishop->getPattern()->checkPattern(Position(4,4), Position(3,5)) &&
            bishop->getPattern()->checkPattern(Position(4,4), Position(5,3)) &&
            !bishop->getPattern()->checkPattern(Position(4,4), Position(5,6)) &&
            tab->isSomeoneInWay(Position(4,4), Position(0,0))) {
        isValid = true;
    }

    return isValid;
}

bool BishopTest::patternSidesNotValidTest()
{
    bool isValid = false;

    // check that a bishop can't move to the sides
    if (!bishop->getPattern()->checkPattern(Position(4,4), Position(4,5)) &&
            !bishop->getPattern()->checkPattern(Position(4,4), Position(4,3)) &&
            !bishop->getPattern()->checkPattern(Position(4,4), Position(3,4)) &&
            !bishop->getPattern()->checkPattern(Position(4,4), Position(5,4))) {
        isValid = true;
    }

    return isValid;
}
