#include "pawnentity.h"

PawnEntity::PawnEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new PawnPattern(isWhite);
}

PawnEntity::~PawnEntity()
{
    delete pattern;
}

bool PawnEntity::move(Position position)
{
    bool isValid = pattern->checkPattern(this->position, position);

    if (isValid) {
        this->position = position;
    }

    return isValid;
}

PawnPattern* PawnEntity::getPattern()
{
    return pattern;
}
