#include "pieceentity.h"

PieceEntity::PieceEntity(Position position, bool isWhite)
{
    this->position = position;
    this->isWhite = isWhite;
    pattern = new BasePattern(isWhite);
    iconPath = QCoreApplication::applicationDirPath() + "/Resources/icons/";
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

QIcon PieceEntity::getIcon()
{
    return icon;
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

void PieceEntity::setPosition(Position pos)
{
    position = pos;
}

QString PieceEntity::getName() {
    return "Piece";
}
