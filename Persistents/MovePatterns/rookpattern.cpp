#include "rookpattern.h"

RookPattern::RookPattern(bool headedUp) : BasePattern(headedUp)
{
}

RookPattern::~RookPattern()
{
}

/**
 * @brief A rook can move on sides until it's stopped
 * @param start
 * @param end
 * @return true if the pattern is valid
 */
bool RookPattern::checkPattern(Position start, Position end)
{
    bool isValid = false;

    if (end.x - start.x == 0 ^ end.y - start.y == 0) {
        isValid = true;
    }

    return isValid;
}
