#include "kingentity.h"

KingEntity::KingEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new KingPattern(isWhite);
    iconPath += "king-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

KingEntity::~KingEntity()
{

}

KingPattern* KingEntity::getPattern()
{
    return dynamic_cast<KingPattern*>(pattern);
}

QString KingEntity::getName()
{
    return "king";
}
