#include "knightentity.h"

KnightEntity::KnightEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new KnightPattern(isWhite);
    iconPath += "knight-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

KnightEntity::~KnightEntity()
{

}

KnightPattern* KnightEntity::getPattern()
{
    return dynamic_cast<KnightPattern *>(pattern);
}

