#include "pawntest.h"

PawnTest::PawnTest()
{
    Position pos;
    pos.x = 0;
    pos.y = 1;
    pawn = new PawnEntity(pos, true);
}

PawnTest::~PawnTest()
{
    delete pawn;
}

void PawnTest::runTests()
{
    qDebug() << "Pawn Tests";
    Q_ASSERT_X(patternValidForwardTest(), "PatternValidForwardTest", "");
    Q_ASSERT_X(patternNonValidBackwardTest(), "PatternValidForwardTest", "");
}

bool PawnTest::patternValidForwardTest()
{
    Position destination = pawn->getPosition();
    destination.y++;

    return pawn->getPattern()->checkPattern(pawn->getPosition(), destination);
}

bool PawnTest::patternNonValidBackwardTest()
{
    Position destination = pawn->getPosition();
    destination.y--;

    return !pawn->getPattern()->checkPattern(pawn->getPosition(), destination);
}
