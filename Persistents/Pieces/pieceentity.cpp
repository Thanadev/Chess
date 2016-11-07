#include "pieceentity.h"

PieceEntity::PieceEntity(Position position, bool isWhite)
{
    this->position = position;
    this->isWhite = isWhite;
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
