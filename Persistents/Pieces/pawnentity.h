#ifndef PAWNENTITY_H
#define PAWNENTITY_H

#include "pieceentity.h"
#include "../MovePatterns/pawnpattern.h"

class PawnEntity : public PieceEntity
{
public:
    PawnEntity(Position position, bool isWhite);
    ~PawnEntity();
    PawnPattern* getPattern();
    virtual bool move(Position position);
protected:
    PawnPattern *pattern;
};

#endif // PAWNENTITY_H
