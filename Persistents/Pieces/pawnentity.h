#ifndef PAWNENTITY_H
#define PAWNENTITY_H
#include <QPushButton>
#include "pieceentity.h"
#include "../MovePatterns/pawnpattern.h"

class PawnEntity : public PieceEntity
{
public:
    PawnEntity(Position position, bool isWhite);
    ~PawnEntity();
    PawnPattern* getPattern();
    QString getName();
    bool move(Position position, PieceEntity *occupant);
};

#endif // PAWNENTITY_H
