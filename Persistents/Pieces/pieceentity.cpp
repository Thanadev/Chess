#include "pieceentity.h"

PieceEntity::PieceEntity(Position position, bool isWhite)
{
    this->position = position;
    this->isWhite = isWhite;
    pattern = new BasePattern(isWhite);
}

PieceEntity::~PieceEntity()
{

}

bool PieceEntity::getIsWhite()
{
    return isWhite;
}

Position PieceEntity::getPosition()
{
    return position;
}

bool PieceEntity::move(Position position, PieceEntity *occupant)
{
    bool isValid = pattern->checkPattern(this->position, position);

    if (occupant != NULL) {
        if (occupant->getIsWhite() == this->isWhite) {
            isValid = false;
        }
    }

    if (isValid) {
        this->position = position;
    }

    return isValid;
}
