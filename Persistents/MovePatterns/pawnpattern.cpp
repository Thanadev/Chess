#include "pawnpattern.h"

PawnPattern::PawnPattern(bool headedUp) : BasePattern(headedUp)
{
}

PawnPattern::~PawnPattern()
{

}

/**
 * @brief A pawn shall only move forward, by one game cell (position + 1)
 * @param start
 * @param end
 * @return
 */
bool PawnPattern::checkPattern(Position start, Position end)
{
    bool isValid = false;
    int direction = 0;

    if (headedUp) {
        direction = 1;
    } else {
        direction = -1;
    }

    if (((end.y - start.y) == (1 * direction)) && (end.x - start.x) == 0) {
        isValid = true;
    }

    return isValid;
}

