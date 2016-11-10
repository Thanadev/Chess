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

PawnEntity::~PawnEntity()
{
    delete pattern;
}

PawnPattern* PawnEntity::getPattern()
{
    return dynamic_cast<PawnPattern*>(pattern);
}
