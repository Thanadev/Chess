#ifndef QUEENENTITY_H
#define QUEENENTITY_H

#include "../MovePatterns/queenpattern.h"
#include "pieceentity.h"

class QueenEntity : public PieceEntity
{
public:
    QueenEntity(Position position, bool isWhite);
    ~QueenEntity();
    QueenPattern* getPattern();
    QString getName();
};

#endif // QUEENENTITY_H
