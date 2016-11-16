#include "pawnentity.h"

PawnEntity::PawnEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new PawnPattern(isWhite);
    iconPath += "pawn-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

bool PawnEntity::move(Position position, PieceEntity *occupant)
{
    bool isOccupatedByEnemy = false;
    bool isValid = true;

    if (occupant != NULL) {
        if (occupant->getIsWhite() != isWhite) {
            isOccupatedByEnemy = true;
        } else if (occupant->getIsWhite() == this->isWhite) {
            isValid = false;
        }
    }

    PawnPattern *castPattern = dynamic_cast<PawnPattern *>(pattern);

    if (castPattern != NULL) {
        isValid = isValid && castPattern->checkPattern(this->position, position, isOccupatedByEnemy);
    }

    if (isValid) {
        this->position = position;
    }

    return isValid;
}

PawnEntity::~PawnEntity()
{
    delete pattern;
}

PawnPattern* PawnEntity::getPattern()
{
    return dynamic_cast<PawnPattern*>(pattern);
}

QString PawnEntity::getName()
{
    return "pawn";
}
