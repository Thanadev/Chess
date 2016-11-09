#include "chesscell.h"

ChessCell::ChessCell(int x, int y)
{
    position = Position(x, y);
    currentPiece = NULL;
}

ChessCell::ChessCell(Position pos)
{
    position = pos;
}

ChessCell::~ChessCell()
{
}

void ChessCell::setPiece(PieceEntity *piece)
{
    currentPiece = piece;
}

PieceEntity* ChessCell::getCurrentPiece()
{
    return currentPiece;
}

Position ChessCell::getPosition()
{
    return position;
}
