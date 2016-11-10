#include "knightpattern.h"

KnightPattern::KnightPattern(bool headedUp) : BasePattern(headedUp)
{

}

KnightPattern::~KnightPattern()
{

}

/**
 * @brief A bishop can move on diagonals
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
