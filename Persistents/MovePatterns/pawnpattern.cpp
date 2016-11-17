#include "pawnpattern.h"

PawnPattern::PawnPattern(bool headedUp) : BasePattern(headedUp)
{
}

PawnPattern::~PawnPattern()
{

}

/**
 * @brief A pawn shall only move forward, by one game cell (position + 1)
 *          it can capture only in diagonals
 * @param start
 * @param end
 * @return
 */
bool PawnPattern::checkPattern(Position start, Position end, bool isOccupatedByEnemy)
{
    bool isValid = false;
    int direction = getDirection();

    if ((((end.y - start.y) == (1 * direction)) && (end.x - start.x) == 0 && !isOccupatedByEnemy) ||
            (isOccupatedByEnemy && ((end.y - start.y == end.x - start.x) || (end.y - start.y + end.x - start.x) == 0) && (end.y - start.y == 1 * direction))) {
        isValid = true;
    }

    return isValid;
}

