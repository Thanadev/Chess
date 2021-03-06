#ifndef PIECEENTITY_H
#define PIECEENTITY_H

#include <QIcon>
#include <QCoreApplication>

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
    QIcon getIcon();
    void setPosition(Position pos);
    virtual bool move(Position position, PieceEntity *occupant);
    virtual QString getName();

protected:
    BasePattern *pattern;
    Position position;
    bool isWhite;
    QIcon icon;
    QString iconPath;
};

#endif // PIECEENTITY_H
