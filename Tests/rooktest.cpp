#include "rooktest.h"

RookTest::RookTest()
{
    rook = new RookEntity(Position(0,0), true);
}

RookTest::~RookTest()
{
    delete rook;
}

void RookTest::runTests()
{
    qDebug() << "Rook tests";
    Q_ASSERT_X(patternValidMovementTest(), "patternValidMovementTest", "");
    Q_ASSERT_X(patternNotValidMovementTest(), "patternNotValidMovementTest", "");
}

bool RookTest::patternValidMovementTest()
{
    bool isValid = false;

    // check if the rook can go in straight lines on four sides, obstacle test is in bishoptest and chesstabtest
    if (rook->getPattern()->checkPattern(Position(4, 4), Position(4, 7)) &&
            rook->getPattern()->checkPattern(Position(4, 4), Position(7, 4)) &&
            rook->getPattern()->checkPattern(Position(4, 4), Position(4, 0)) &&
            rook->getPattern()->checkPattern(Position(4, 4), Position(0, 4))) {
        isValid = true;
    }

    return isValid;
}

bool RookTest::patternNotValidMovementTest()
{
    bool isValid = false;

    // check if the rook can't go in diagonals or in knight move ("L" ; see knight pattern)
    if (!rook->getPattern()->checkPattern(Position(4, 4), Position(7, 7)) &&
            !rook->getPattern()->checkPattern(Position(4, 4), Position(5, 5)) &&
            !rook->getPattern()->checkPattern(Position(4, 4), Position(0, 0)) &&
            !rook->getPattern()->checkPattern(Position(4, 4), Position(6, 5))) {
        isValid = true;
    }

    return isValid;
}
