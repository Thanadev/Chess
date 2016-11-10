#include "knighttest.h"

KnightTest::KnightTest()
{
    knight = new KnightEntity(Position(0,0), true);
}

KnightTest::~KnightTest()
{
    delete knight;
}

void KnightTest::runTests()
{
    qDebug() << "Knight tests";
    Q_ASSERT_X(patternMovementValidTest(), "patternMovementValidTest", "");
    Q_ASSERT_X(patternMovementNotValidTest(), "patternMovementNotValidTest", "");
}

bool KnightTest::patternMovementValidTest()
{
    bool isValid = false;

    if (knight->getPattern()->checkPattern(Position(4,4), Position(5, 6)) &&
            knight->getPattern()->checkPattern(Position(4,4), Position(3, 6)) &&
            knight->getPattern()->checkPattern(Position(4,4), Position(5, 2)) &&
            knight->getPattern()->checkPattern(Position(4,4), Position(6, 5)) &&
            knight->getPattern()->checkPattern(Position(4,4), Position(6, 3))) {
        isValid = true;
    }

    return isValid;
}

bool KnightTest::patternMovementNotValidTest()
{
    bool isValid = false;

    if (!knight->getPattern()->checkPattern(Position(4,4), Position(2, 2)) &&
            !knight->getPattern()->checkPattern(Position(4,4), Position(4, 4)) &&
            !knight->getPattern()->checkPattern(Position(4,4), Position(4, 8)) &&
            !knight->getPattern()->checkPattern(Position(4,4), Position(2, 8))) {
        isValid = true;
    }

    return isValid;
}
