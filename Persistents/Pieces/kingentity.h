#ifndef KINGENTITY_H
#define KINGENTITY_H

#include "pieceentity.h"
#include "../MovePatterns/kingpattern.h"

class KingEntity : public PieceEntity
{
public:
    KingEntity(Position position, bool isWhite);
    ~KingEntity();
    KingPattern* getPattern();
    QString getName();
protected:
};

#endif // KINGENTITY_H
