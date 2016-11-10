#include "bishopentity.h"

BishopEntity::BishopEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new BishopPattern(isWhite);
    iconPath += "bishop-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

BishopEntity::~BishopEntity()
{

}


BishopPattern* BishopEntity::getPattern()
{
    return dynamic_cast<BishopPattern*>(pattern);
}
