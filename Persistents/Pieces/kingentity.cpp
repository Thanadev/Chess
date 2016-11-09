#include "kingentity.h"

KingEntity::KingEntity(Position position, bool isWhite) : PieceEntity(position, isWhite)
{
    // isWhite = isHeadedUp as the white will be on the bottom of the board
    pattern = new KingPattern(isWhite);
}

KingEntity::~KingEntity()
{

}

KingPattern* KingEntity::getPattern()
{
    return dynamic_cast<KingPattern*>(pattern);
}
