#ifndef KNIGHTENTITY_H
#define KNIGHTENTITY_H

#include "pieceentity.h"
#include "../MovePatterns/knightpattern.h"

class KnightEntity : public PieceEntity
{
public:
    KnightEntity(Position position, bool isWhite);
    ~KnightEntity();
    KnightPattern* getPattern();
};

#endif // KNIGHTENTITY_H
