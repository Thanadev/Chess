#include "knightpattern.h"

KnightPattern::KnightPattern(bool headedUp) : BasePattern(headedUp)
{

}

KnightPattern::~KnightPattern()
{

}

/**
 * @brief A knight can move drawing "L" (one horizontally and two vertically or inverse)
 * @param start
 * @param end
 * @return true if the pattern is valid
 */
bool KnightPattern::checkPattern(Position start, Position end)
{
    bool isValid = false;

    if (((end.x - start.x == 1 || end.x - start.x == -1) && (end.y - start.y == 2 || end.y - start.y == -2)) ||
            ((end.x - start.x == 2 || end.x - start.x == -2) && (end.y - start.y == 1 || end.y - start.y == -1))) {
        isValid = true;
    }

    return isValid;
}
