#include "queenentity.h"

QueenEntity::QueenEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new QueenPattern(isWhite);
    iconPath += "queen-";

    if (isWhite) {
        iconPath += "white";
    } else {
        iconPath += "black";
    }

    icon = QIcon(iconPath);
}

QueenEntity::~QueenEntity()
{

}

QueenPattern* QueenEntity::getPattern()
{
    return dynamic_cast<QueenPattern *>(pattern);
}
