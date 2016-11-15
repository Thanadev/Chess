#include "player.h"

Player::Player(bool isWhite)
{
    this->pieces = new QList<PieceEntity *>();
    this->isWhite = isWhite;
    this->canPlay = false;
}

Player::~Player()
{
    delete pieces;
}

void Player::setCanPlay(bool canPlay)
{
    this->canPlay = canPlay;
}

bool Player::getIsWhite()
{
    return isWhite;
}

void Player::addPiece(PieceEntity *piece)
{
    pieces->append(piece);
}

bool Player::removePiece(PieceEntity *piece)
{
    return pieces->removeOne(piece);
}

QList<PieceEntity *>* Player::getPieces()
{
    return pieces;
}
