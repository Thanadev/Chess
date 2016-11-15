#ifndef ROOKENTITY_H
#define ROOKENTITY_H

#include "pieceentity.h"
#include "../MovePatterns/rookpattern.h"

class RookEntity : public PieceEntity
{
public:
    RookEntity(Position position, bool isWhite);
    ~RookEntity();
    RookPattern* getPattern();
    QString getName();
};

#endif // ROOKENTITY_H
