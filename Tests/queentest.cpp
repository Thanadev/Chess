#include "queentest.h"

QueenTest::QueenTest()
{
    queen = new QueenEntity(Position(0,0), true);
}

QueenTest::~QueenTest()
{
    delete queen;
}

void QueenTest::runTests()
{
    qDebug() << "Queen tests";
    Q_ASSERT_X(patternValidMovementTest(), "patternValidMovementTest", "");
    Q_ASSERT_X(patternNotValidMovementTest(), "patternNotValidMovementTest", "");
}

bool QueenTest::patternValidMovementTest()
{
    bool isValid = false;

    // Check multidirectionnal movement
    if (queen->getPattern()->checkPattern(Position(4,4), Position(0,0)) &&
            queen->getPattern()->checkPattern(Position(4,4), Position(7,7)) &&
            queen->getPattern()->checkPattern(Position(4,4), Position(7,4)) &&
            queen->getPattern()->checkPattern(Position(4,4), Position(4,7)) &&
            queen->getPattern()->checkPattern(Position(4,4), Position(0,4))) {
        isValid = true;
    }

    return isValid;
}

bool QueenTest::patternNotValidMovementTest()
{
    bool isValid = false;

    // Check that we can't move like a knight ("L" ; see knightpattern)
    if (!queen->getPattern()->checkPattern(Position(4,4), Position(6,5)) &&
            !queen->getPattern()->checkPattern(Position(4,4), Position(5,2))) {
        isValid = true;
    }

    return isValid;
}
