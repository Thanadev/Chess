#include "bishoppattern.h"

BishopPattern::BishopPattern(bool headedUp) : BasePattern(headedUp)
{

}

BishopPattern::~BishopPattern()
{

}

/**
 * @brief A bishop can move on diagonals
 * @param start
 * @param end
 * @return true if the pattern is valid
 */
bool BishopPattern::checkPattern(Position start, Position end)
{
    bool isValid = false;

    if (((end.x - start.x > 0 || end.x - start.x < 0) &&
            (end.y - start.y > 0 || end.y - start.y < 0)) &&
            ((end.y - start.y == end.x - start.x) || (end.y - start.y + end.x - start.x) == 0)) {
        isValid = true;
    }

    return isValid;
}
