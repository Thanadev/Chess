#ifndef CHESSCELL_H
#define CHESSCELL_H

#include "Pieces/pieceentity.h"

class ChessCell
{
public:
    ChessCell(int x, int y);
    ChessCell(Position pos);
    ~ChessCell();
    PieceEntity* getCurrentPiece();
    void setPiece(PieceEntity *piece);
    Position getPosition();
private:
    PieceEntity *currentPiece;
    Position position;
};

#endif // CHESSCELL_H
