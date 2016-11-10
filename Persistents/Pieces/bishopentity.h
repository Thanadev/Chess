#ifndef BISHOPENTITY_H
#define BISHOPENTITY_H

#include "pieceentity.h"
#include "../MovePatterns/bishoppattern.h"

class BishopEntity : public PieceEntity
{
public:
    BishopEntity(Position position, bool isWhite);
    ~BishopEntity();
    BishopPattern* getPattern();
};

#endif // BISHOPENTITY_H
