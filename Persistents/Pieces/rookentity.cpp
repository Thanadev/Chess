#include "rookentity.h"

RookEntity::RookEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new RookPattern(isWhite);
    iconPath += "rok-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

RookEntity::~RookEntity()
{

}

RookPattern* RookEntity::getPattern()
{
    return dynamic_cast<RookPattern *>(pattern);
}
