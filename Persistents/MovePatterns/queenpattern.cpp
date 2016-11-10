#include "queenpattern.h"

QueenPattern::QueenPattern(bool headedUp) : BasePattern(headedUp)
{
}

QueenPattern::~QueenPattern()
{

}

bool QueenPattern::checkPattern(Position start, Position end) {
    bool isValid = false;

    if (((end.y - start.y == end.x - start.x) || (end.y - start.y + end.x - start.x) == 0) ||
            (end.x - start.x == 0 ^ end.y - start.y == 0)) {
        isValid = true;
    }

    return isValid;
}
