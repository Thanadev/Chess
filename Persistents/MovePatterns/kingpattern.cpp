#include "kingpattern.h"

KingPattern::KingPattern(bool headedUp) : BasePattern(headedUp)
{
}

KingPattern::~KingPattern()
{

}

/**
 * @brief A king can move into the four basic direction
 * @param start
 * @param end
 * @return true if the pattern is valid
 */
bool KingPattern::checkPattern(Position start, Position end)
{
    bool isValid = false;

    if (((end.x - start.x == 1 || end.x - start.x == -1) ||
            (end.y - start.y == 1 || end.y - start.y == -1)) &&
            (end.y - start.y != end.x - start.x) && ((end.y - start.y) + (end.x - start.x) != 0)) {
        isValid = true;
    }

    return isValid;
}
