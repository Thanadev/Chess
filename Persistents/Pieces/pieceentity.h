#ifndef PIECEENTITY_H
#define PIECEENTITY_H

#include "../Utils/position.h"
#include "../MovePatterns/basepattern.h"

/**
 * @brief Base class of all chess pieces
 */
class PieceEntity
{
public:
    PieceEntity(Position position, bool isWhite);
    ~PieceEntity();
    Position getPosition();
    bool getIsWhite();
    virtual bool move(Position position, PieceEntity *occupant);

protected:
    BasePattern *pattern;
    Position position;
    bool isWhite;
};

#endif // PIECEENTITY_H
