#ifndef PLAYER_H
#define PLAYER_H

#include <QList>
#include "Pieces/pieceentity.h"

class Player
{
public:
    Player(bool isWhite);
    ~Player();
    void setCanPlay(bool canPlay);
    bool getIsWhite();
    void addPiece(PieceEntity *piece);
    bool removePiece(PieceEntity *piece);
    QList<PieceEntity *>* getPieces();
private:
    bool isWhite;
    bool canPlay;
    QList<PieceEntity *> *pieces;
};

#endif // PLAYER_H
