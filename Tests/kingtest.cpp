#include "kingtest.h"

KingTest::KingTest()
{
    king = new KingEntity(Position(4,4), true);
}

KingTest::~KingTest()
{
    delete king;
}

void KingTest::runTests()
{
    qDebug() << "King tests";
    Q_ASSERT_X(patternForwardValidTest(), "patternForwardValidTest", "");
    Q_ASSERT_X(patternBackValidTest(), "patternBackValidTest", "");
    Q_ASSERT_X(patternLeftValidTest(), "patternLeftValidTest", "");
    Q_ASSERT_X(patternRightValidTest(), "patternRightValidTest", "");
    Q_ASSERT_X(patternDiagonalNotValidTest(), "patternDiagonalNotValidTest", "");
}

bool KingTest::patternForwardValidTest()
{
    return king->getPattern()->checkPattern(Position(4,4), Position(4,5));
}

bool KingTest::patternBackValidTest()
{
    return king->getPattern()->checkPattern(Position(4,4), Position(4,3));;
}

bool KingTest::patternLeftValidTest()
{
    return king->getPattern()->checkPattern(Position(4,4), Position(3,4));;
}

bool KingTest::patternRightValidTest()
{
    return king->getPattern()->checkPattern(Position(4,4), Position(5,4));;
}

bool KingTest::patternDiagonalNotValidTest()
{
    return !(king->getPattern()->checkPattern(Position(4,4), Position(5,5)) ||
             king->getPattern()->checkPattern(Position(4,4), Position(3,3)) ||
             king->getPattern()->checkPattern(Position(4,4), Position(5,3)) ||
             king->getPattern()->checkPattern(Position(4,4), Position(3,5)));
}
